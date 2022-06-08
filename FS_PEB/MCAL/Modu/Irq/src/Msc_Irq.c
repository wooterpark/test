/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Msc_Irq.c $                                                **
**                                                                           **
**  $CC VERSION : \main\9 $                                                  **
**                                                                           **
**  $DATE       : 2016-06-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the interrupt handlers for MSC. This    **
**                 file is given for evaluation purpose only                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

  /* Inclusion of controller sfr file */
#include "IfxSrc_reg.h"
  /* Inclusion of Msc sfr file */
#include "IfxMsc_reg.h"

/* Include Irq Module */
#include "Irq.h"

/* MCAL header file containing global macros, type definitions and functions 
  needed by all MCAL drivers. */
#include "Mcal.h"

/* MSC driver header file*/
#include "Msc.h"
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
** Syntax : void MSC0SR0_ISR (void)                                          **
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
** Description : Service for MSC0 Service request 0                          **
**               for handling Tx/Rx frames                                   **
**                                                                           **
*****************************************************************************/
#if((IRQ_MSC0_SR0_PRIO > 0) || (IRQ_MSC0_SR0_CAT == IRQ_CAT23))
#if((IRQ_MSC0_SR0_PRIO > 0) && (IRQ_MSC0_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(MSC0SR0_ISR, 0, IRQ_MSC0_SR0_PRIO)
#elif IRQ_MSC0_SR0_CAT == IRQ_CAT23
ISR(MSC0SR0_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_MSC0_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();    
#endif
  /* Parameters are MSC Module Number and Service Request Number*/
  Msc_InterruptHandler(0,0);
}
#endif

/******************************************************************************
** Syntax : void MSC0SR1_ISR (void)                                          **
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
** Description : Service for MSC0 Service request 1                          **
**               for handling Tx/Rx Frames                                   **
**                                                                           **
*****************************************************************************/

#if((IRQ_MSC0_SR1_PRIO > 0) || (IRQ_MSC0_SR1_CAT == IRQ_CAT23))
#if((IRQ_MSC0_SR1_PRIO > 0) && (IRQ_MSC0_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(MSC0SR1_ISR, 0, IRQ_MSC0_SR1_PRIO)
#elif IRQ_MSC0_SR1_CAT == IRQ_CAT23
ISR(MSC0SR1_ISR)
#endif
{
      
  /* Enable Global Interrupts */
#if (IRQ_MSC0_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();    
#endif
  /* Parameters are MSC Module Number and Service Request Number*/
  Msc_InterruptHandler(0,1);
}
#endif

/******************************************************************************
** Syntax : void MSC0SR2_ISR(void)                                           **
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
** Description : Service for MSC0 Service request 2                          **
**               for handling Tx/Rx Frames                                   **
**                                                                           **
*****************************************************************************/

#if((IRQ_MSC0_SR2_PRIO > 0) || (IRQ_MSC0_SR2_CAT == IRQ_CAT23))
#if((IRQ_MSC0_SR2_PRIO > 0) && (IRQ_MSC0_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(MSC0SR2_ISR, 0, IRQ_MSC0_SR2_PRIO)
#elif IRQ_MSC0_SR2_CAT == IRQ_CAT23
ISR(MSC0SR2_ISR)
#endif
{
      
  /* Enable Global Interrupts */
#if (IRQ_MSC0_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();    
#endif
  /* Parameters are MSC Module Number and Service Request Number*/
  Msc_InterruptHandler(0,2);
}
#endif

/******************************************************************************
** Syntax : void MSC0SR3_ISR (void)                                          **
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
** Description : Service for MSC0 Service request 3                          **
**               for handling Tx/Rx Frames                                   **
**                                                                           **
*****************************************************************************/

#if((IRQ_MSC0_SR3_PRIO > 0) || (IRQ_MSC0_SR3_CAT == IRQ_CAT23))
#if((IRQ_MSC0_SR3_PRIO > 0) && (IRQ_MSC0_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(MSC0SR3_ISR, 0, IRQ_MSC0_SR3_PRIO)
#elif IRQ_MSC0_SR3_CAT == IRQ_CAT23
ISR(MSC0SR3_ISR)
#endif
{
      
  /* Enable Global Interrupts */
#if (IRQ_MSC0_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();    
#endif
  /* Parameters are MSC Module Number and Service Request Number*/
  Msc_InterruptHandler(0,3);
}
#endif


/******************************************************************************
** Syntax : void MSC1SR0_ISR (void)                                          **
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
** Description : Service for MSC1 Service request 0                          **
**               for handling Tx/Rx frames                                   **
**                                                                           **
*****************************************************************************/
#if((IRQ_MSC1_SR0_PRIO > 0) || (IRQ_MSC1_SR0_CAT == IRQ_CAT23))
#if((IRQ_MSC1_SR0_PRIO > 0) && (IRQ_MSC1_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(MSC1SR0_ISR, 0, IRQ_MSC1_SR0_PRIO)
#elif IRQ_MSC1_SR0_CAT == IRQ_CAT23
ISR(MSC1SR0_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_MSC1_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();    
#endif
  /* Parameters are MSC Module Number and Service Request Number*/
  Msc_InterruptHandler(1,0);
}
#endif

/******************************************************************************
** Syntax : void MSC1SR1_ISR (void)                                          **
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
** Description : Service for MSC1 Service request 1                          **
**               for handling Tx/Rx Frames                                   **
**                                                                           **
*****************************************************************************/

#if((IRQ_MSC1_SR1_PRIO > 0) || (IRQ_MSC1_SR1_CAT == IRQ_CAT23))
#if((IRQ_MSC1_SR1_PRIO > 0) && (IRQ_MSC1_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(MSC1SR1_ISR, 0, IRQ_MSC1_SR1_PRIO)
#elif IRQ_MSC1_SR1_CAT == IRQ_CAT23
ISR(MSC1SR1_ISR)
#endif
{
      
  /* Enable Global Interrupts */
#if (IRQ_MSC1_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();    
#endif
  /* Parameters are MSC Module Number and Service Request Number*/
  Msc_InterruptHandler(1,1);
}
#endif

/******************************************************************************
** Syntax : void MSC1SR2_ISR (void)                                          **
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
** Description : Service for MSC1 Service request 2                          **
**               for handling Tx/Rx Frames                                   **
**                                                                           **
*****************************************************************************/

#if((IRQ_MSC1_SR2_PRIO > 0) || (IRQ_MSC1_SR2_CAT == IRQ_CAT23))
#if((IRQ_MSC1_SR2_PRIO > 0) && (IRQ_MSC1_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(MSC1SR2_ISR, 0, IRQ_MSC1_SR2_PRIO)
#elif IRQ_MSC1_SR2_CAT == IRQ_CAT23
ISR(MSC1SR2_ISR)
#endif
{
      
  /* Enable Global Interrupts */
#if (IRQ_MSC1_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();    
#endif
  /* Parameters are MSC Module Number and Service Request Number*/
  Msc_InterruptHandler(1,2);
}
#endif

/******************************************************************************
** Syntax : void MSC1SR3_ISR (void)                                          **
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
** Description : Service for MSC1 Service request 3                          **
**               for handling Tx/Rx Frames                                   **
**                                                                           **
*****************************************************************************/

#if((IRQ_MSC1_SR3_PRIO > 0) || (IRQ_MSC1_SR3_CAT == IRQ_CAT23))
#if((IRQ_MSC1_SR3_PRIO > 0) && (IRQ_MSC1_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(MSC1SR3_ISR, 0, IRQ_MSC1_SR3_PRIO)
#elif IRQ_MSC1_SR3_CAT == IRQ_CAT23
ISR(MSC1SR3_ISR)
#endif
{
      
  /* Enable Global Interrupts */
#if (IRQ_MSC1_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();    
#endif
  /* Parameters are MSC Module Number and Service Request Number*/
  Msc_InterruptHandler(1,3);
}
#endif

#ifdef IRQ_MSC2_EXIST
#if (IRQ_MSC2_EXIST == STD_ON)
/******************************************************************************
** Syntax : void MSC2SR0_ISR (void)                                          **
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
** Description : Service for MSC2 Service request 0                          **
**               for handling Tx/Rx frames                                   **
**                                                                           **
*****************************************************************************/
#if((IRQ_MSC2_SR0_PRIO > 0) || (IRQ_MSC2_SR0_CAT == IRQ_CAT23))
#if((IRQ_MSC2_SR0_PRIO > 0) && (IRQ_MSC2_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(MSC2SR0_ISR, 0, IRQ_MSC2_SR0_PRIO)
#elif IRQ_MSC2_SR0_CAT == IRQ_CAT23
ISR(MSC2SR0_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_MSC2_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();    
#endif
  /* Parameters are MSC Module Number and Service Request Number*/
  Msc_InterruptHandler(2,0);
}
#endif

/******************************************************************************
** Syntax : void MSC2SR1_ISR (void)                                          **
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
** Description : Service for MSC2 Service request 1                          **
**               for handling Tx/Rx Frames                                   **
**                                                                           **
*****************************************************************************/

#if((IRQ_MSC2_SR1_PRIO > 0) || (IRQ_MSC2_SR1_CAT == IRQ_CAT23))
#if((IRQ_MSC2_SR1_PRIO > 0) && (IRQ_MSC2_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(MSC2SR1_ISR, 0, IRQ_MSC2_SR1_PRIO)
#elif IRQ_MSC2_SR1_CAT == IRQ_CAT23
ISR(MSC2SR1_ISR)
#endif
{
      
  /* Enable Global Interrupts */
#if (IRQ_MSC2_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();    
#endif
  /* Parameters are MSC Module Number and Service Request Number*/
  Msc_InterruptHandler(2,1);
}
#endif

/******************************************************************************
** Syntax : void MSC2SR2_ISR (void)                                          **
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
** Description : Service for MSC2 Service request 2                          **
**               for handling Tx/Rx Frames                                   **
**                                                                           **
*****************************************************************************/

#if((IRQ_MSC2_SR2_PRIO > 0) || (IRQ_MSC2_SR2_CAT == IRQ_CAT23))
#if((IRQ_MSC2_SR2_PRIO > 0) && (IRQ_MSC2_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(MSC2SR2_ISR, 0, IRQ_MSC2_SR2_PRIO)
#elif IRQ_MSC2_SR2_CAT == IRQ_CAT23
ISR(MSC2SR2_ISR)
#endif
{
      
  /* Enable Global Interrupts */
#if (IRQ_MSC2_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();    
#endif
  /* Parameters are MSC Module Number and Service Request Number*/
  Msc_InterruptHandler(2,2);
}
#endif

/******************************************************************************
** Syntax : void MSC2SR3_ISR (void)                                          **
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
** Description : Service for MSC2 Service request 3                          **
**               for handling Tx/Rx Frames                                   **
**                                                                           **
*****************************************************************************/

#if((IRQ_MSC2_SR3_PRIO > 0) || (IRQ_MSC2_SR3_CAT == IRQ_CAT23))
#if((IRQ_MSC2_SR3_PRIO > 0) && (IRQ_MSC2_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(MSC2SR3_ISR, 0, IRQ_MSC2_SR3_PRIO)
#elif IRQ_MSC2_SR3_CAT == IRQ_CAT23
ISR(MSC2SR3_ISR)
#endif
{
      
  /* Enable Global Interrupts */
#if (IRQ_MSC2_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();    
#endif
  /* Parameters are MSC Module Number and Service Request Number*/
  Msc_InterruptHandler(2,3);
}
#endif

#endif
#endif

#define IRQ_STOP_SEC_CODE
#include "MemMap.h"


