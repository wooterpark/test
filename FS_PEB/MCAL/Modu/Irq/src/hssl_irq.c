/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : hssl_irq.c $                                               **
**                                                                           **
**  $CC VERSION : \main\9 $                                                  **
**                                                                           **
**  $DATE       : 2016-06-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the ISRs for HSSL drivers               **
**                This file is given for evaluation purpose only             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
/* Inclusion of Tasking sfr file */
/* MCAL driver utility functions for setting interrupt priority initialization 
    and interrupt category */
#include "Irq.h"
/* Global functions like Set/Reset END INIT protection bit, 
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"
/* Own header file, this includes own configuration file also */
#include "hssl.h"
/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define IRQ_START_SEC_CODE
#include "MemMap.h"
/******************************************************************************
** Syntax : void HSSL0COK_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for COK interrupt of HSSL0                          **
**                                                                           **
*****************************************************************************/
/* This node is for HSSLx_COK */
#if((IRQ_HSSL0_COK_PRIO > 0) || (IRQ_HSSL0_COK_CAT == IRQ_CAT23))
#if((IRQ_HSSL0_COK_PRIO > 0) && (IRQ_HSSL0_COK_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL0COK_ISR, 0, IRQ_HSSL0_COK_PRIO)
#elif IRQ_HSSL0_COK_CAT == IRQ_CAT23
ISR(HSSL0COK_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL0_COK_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Channel OK Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL1COK_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for COK interrupt of HSSL1                          **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL1_COK_PRIO > 0) || (IRQ_HSSL1_COK_CAT == IRQ_CAT23))
#if((IRQ_HSSL1_COK_PRIO > 0) && (IRQ_HSSL1_COK_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL1COK_ISR, 0, IRQ_HSSL1_COK_PRIO)
#elif IRQ_HSSL1_COK_CAT == IRQ_CAT23
ISR(HSSL1COK_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL1_COK_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Channel OK Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL2COK_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for COK interrupt of HSSL2                          **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL2_COK_PRIO > 0) || (IRQ_HSSL2_COK_CAT == IRQ_CAT23))
#if((IRQ_HSSL2_COK_PRIO > 0) && (IRQ_HSSL2_COK_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL2COK_ISR, 0, IRQ_HSSL2_COK_PRIO)
#elif IRQ_HSSL2_COK_CAT == IRQ_CAT23
ISR(HSSL2COK_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL2_COK_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Channel OK Interrupt funtion*/                                              
}
#endif
/******************************************************************************
** Syntax : void HSSL3COK_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for COK interrupt of HSSL3                          **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL3_COK_PRIO > 0) || (IRQ_HSSL3_COK_CAT == IRQ_CAT23))
#if((IRQ_HSSL3_COK_PRIO > 0) && (IRQ_HSSL3_COK_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL3COK_ISR, 0, IRQ_HSSL3_COK_PRIO)
#elif IRQ_HSSL3_COK_CAT == IRQ_CAT23
ISR(HSSL3COK_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL3_COK_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Channel OK Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL0RDI_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Read Data interrupt of HSSL0                    **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL0_RDI_PRIO > 0) || (IRQ_HSSL0_RDI_CAT == IRQ_CAT23))
#if((IRQ_HSSL0_RDI_PRIO > 0) && (IRQ_HSSL0_RDI_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL0RDI_ISR, 0, IRQ_HSSL0_RDI_PRIO)
#elif IRQ_HSSL0_RDI_CAT == IRQ_CAT23
ISR(HSSL0RDI_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL0_RDI_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Read Data Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL1RDI_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Read Data interrupt of HSSL1                    **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL1_RDI_PRIO > 0) || (IRQ_HSSL1_RDI_CAT == IRQ_CAT23))
#if((IRQ_HSSL1_RDI_PRIO > 0) && (IRQ_HSSL1_RDI_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL1RDI_ISR, 0, IRQ_HSSL1_RDI_PRIO)
#elif IRQ_HSSL1_RDI_CAT == IRQ_CAT23
ISR(HSSL1RDI_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL1_RDI_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Read Data Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL2RDI_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Read Data interrupt of HSSL2                    **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL2_RDI_PRIO > 0) || (IRQ_HSSL2_RDI_CAT == IRQ_CAT23))
#if((IRQ_HSSL2_RDI_PRIO > 0) && (IRQ_HSSL2_RDI_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL2RDI_ISR, 0, IRQ_HSSL2_RDI_PRIO)
#elif IRQ_HSSL2_RDI_CAT == IRQ_CAT23
ISR(HSSL2RDI_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL2_RDI_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Read Data Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL3RDI_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Read Data interrupt of HSSL3                    **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL3_RDI_PRIO > 0) || (IRQ_HSSL3_RDI_CAT == IRQ_CAT23))
#if((IRQ_HSSL3_RDI_PRIO > 0) && (IRQ_HSSL3_RDI_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL3RDI_ISR, 0, IRQ_HSSL3_RDI_PRIO)
#elif IRQ_HSSL3_RDI_CAT == IRQ_CAT23
ISR(HSSL3RDI_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL3_RDI_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Read Data Interrupt funtion*/                                              
}
#endif


/******************************************************************************
** Syntax : void HSSL0TRG_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Trigger interrupt of HSSL0                      **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL0_TRG_PRIO > 0) || (IRQ_HSSL0_TRG_CAT == IRQ_CAT23))
#if((IRQ_HSSL0_TRG_PRIO > 0) && (IRQ_HSSL0_TRG_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL0TRG_ISR, 0, IRQ_HSSL0_TRG_PRIO)
#elif IRQ_HSSL0_TRG_CAT == IRQ_CAT23
ISR(HSSL0TRG_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL0_TRG_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Trigger Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL1TRG_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Trigger interrupt of HSSL1                      **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL1_TRG_PRIO > 0) || (IRQ_HSSL1_TRG_CAT == IRQ_CAT23))
#if((IRQ_HSSL1_TRG_PRIO > 0) && (IRQ_HSSL1_TRG_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL1TRG_ISR, 0, IRQ_HSSL1_TRG_PRIO)
#elif IRQ_HSSL1_TRG_CAT == IRQ_CAT23
ISR(HSSL1TRG_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL1_TRG_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Trigger Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL2TRG_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Trigger interrupt of HSSL2                      **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL2_TRG_PRIO > 0) || (IRQ_HSSL2_TRG_CAT == IRQ_CAT23))
#if((IRQ_HSSL2_TRG_PRIO > 0) && (IRQ_HSSL2_TRG_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL2TRG_ISR, 0, IRQ_HSSL2_TRG_PRIO)
#elif IRQ_HSSL2_TRG_CAT == IRQ_CAT23
ISR(HSSL2TRG_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL2_TRG_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Trigger Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL3TRG_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Trigger interrupt of HSSL3                      **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL3_TRG_PRIO > 0) || (IRQ_HSSL3_TRG_CAT == IRQ_CAT23))
#if((IRQ_HSSL3_TRG_PRIO > 0) && (IRQ_HSSL3_TRG_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL3TRG_ISR, 0, IRQ_HSSL3_TRG_PRIO)
#elif IRQ_HSSL3_TRG_CAT == IRQ_CAT23
ISR(HSSL3TRG_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL3_TRG_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Trigger Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL0ERR_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Error interrupt of HSSL0                        **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL0_ERR_PRIO > 0) || (IRQ_HSSL0_ERR_CAT == IRQ_CAT23))
#if((IRQ_HSSL0_ERR_PRIO > 0) && (IRQ_HSSL0_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL0ERR_ISR, 0, IRQ_HSSL0_ERR_PRIO)
#elif IRQ_HSSL0_ERR_CAT == IRQ_CAT23
ISR(HSSL0ERR_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL0_ERR_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Error Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL1ERR_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Error interrupt of HSSL1                        **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL1_ERR_PRIO > 0) || (IRQ_HSSL1_ERR_CAT == IRQ_CAT23))
#if((IRQ_HSSL1_ERR_PRIO > 0) && (IRQ_HSSL1_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL1ERR_ISR, 0, IRQ_HSSL1_ERR_PRIO)
#elif IRQ_HSSL1_ERR_CAT == IRQ_CAT23
ISR(HSSL1ERR_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL1_ERR_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Error Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL2ERR_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Error interrupt of HSSL2                        **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL2_ERR_PRIO > 0) || (IRQ_HSSL2_ERR_CAT == IRQ_CAT23))
#if((IRQ_HSSL2_ERR_PRIO > 0) && (IRQ_HSSL2_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL2ERR_ISR, 0, IRQ_HSSL2_ERR_PRIO)
#elif IRQ_HSSL2_ERR_CAT == IRQ_CAT23
ISR(HSSL2ERR_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL2_ERR_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Error Interrupt funtion*/                                              
}
#endif

/******************************************************************************
** Syntax : void HSSL3ERR_ISR(void)                                          **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Error interrupt of HSSL3                        **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL3_ERR_PRIO > 0) || (IRQ_HSSL3_ERR_CAT == IRQ_CAT23))
#if((IRQ_HSSL3_ERR_PRIO > 0) && (IRQ_HSSL3_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSL3ERR_ISR, 0, IRQ_HSSL3_ERR_PRIO)
#elif IRQ_HSSL3_ERR_CAT == IRQ_CAT23
ISR(HSSL3ERR_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL3_ERR_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Error Interrupt funtion*/                                              
}
#endif


/******************************************************************************
** Syntax : void HSSLEXI_ISR(void)                                           **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Exception interrupt of HSSL                     **
**                                                                           **
*****************************************************************************/
#if((IRQ_HSSL_EXI_PRIO > 0) || (IRQ_HSSL_EXI_CAT == IRQ_CAT23))
#if((IRQ_HSSL_EXI_PRIO > 0) && (IRQ_HSSL_EXI_CAT == IRQ_CAT1))
IFX_INTERRUPT(HSSLEXI_ISR, 0, IRQ_HSSL_EXI_PRIO)
#elif IRQ_HSSL_EXI_CAT == IRQ_CAT23
ISR(HSSLEXI_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_HSSL_EXI_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call Exception Interrupt funtion*/                                              
}
#endif

#define IRQ_STOP_SEC_CODE
#include "MemMap.h"

