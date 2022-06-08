/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : I2c_Irq.c $                                                **
**                                                                            **
**  $CC VERSION : \main\3 $                                                  **
**                                                                            **
**  $DATE       : 2016-06-27 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                - ISRs of I2C Handler driver.                               **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

/* MCAL driver utility functions for setting interrupt priority initialization 
    and interrupt category */
#include "Irq.h"
/* Global functions like Set/Reset END INIT protection bit, 
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"
/* Own header file, this includes own configuration file also */
#include "I2c.h"
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
/*******************************************************************************
** Syntax          : void I2C0BREQ_ISR(void)                                  **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : reentrant                                                **
**                                                                            **
** Parameters (in) : none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description     : Service for BREQ interrupt of I2Cx                       **
**                                                                            **
*******************************************************************************/
#if ((IRQ_I2C0_EXIST == ON))
#if ((IRQ_I2C0_BREQ_PRIO > 0) || (IRQ_I2C0_BREQ_CAT == IRQ_CAT23))
#if ((IRQ_I2C0_BREQ_PRIO > 0) && (IRQ_I2C0_BREQ_CAT == IRQ_CAT1))
IFX_INTERRUPT(I2C0BREQ_ISR, 0, IRQ_I2C0_BREQ_PRIO)
#elif IRQ_I2C0_BREQ_CAT == IRQ_CAT23
ISR(I2C0BREQ_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_I2C0_BREQ_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call BREQ interrupt funtion */                                              
}
#endif
#endif

#if ((IRQ_I2C1_EXIST == ON))
#if ((IRQ_I2C1_BREQ_PRIO > 0) || (IRQ_I2C1_BREQ_CAT == IRQ_CAT23))
#if ((IRQ_I2C1_BREQ_PRIO > 0) && (IRQ_I2C1_BREQ_CAT == IRQ_CAT1))
IFX_INTERRUPT(I2C1BREQ_ISR, 0, IRQ_I2C1_BREQ_PRIO)
#elif IRQ_I2C1_BREQ_CAT == IRQ_CAT23
ISR(I2C1BREQ_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_I2C1_BREQ_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call BREQ interrupt funtion */                                              
}
#endif
#endif

/*******************************************************************************
** Syntax          : void I2C0LBREQ_ISR(void)                                 **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : reentrant                                                **
**                                                                            **
** Parameters (in) : none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description     : Service for LBREQ interrupt of I2Cx                      **
**                                                                            **
*******************************************************************************/
#if ((IRQ_I2C0_EXIST == ON))
#if ((IRQ_I2C0_LBREQ_PRIO > 0) || (IRQ_I2C0_LBREQ_CAT == IRQ_CAT23))
#if ((IRQ_I2C0_LBREQ_PRIO > 0) && (IRQ_I2C0_LBREQ_CAT == IRQ_CAT1))
IFX_INTERRUPT(I2C0LBREQ_ISR, 0, IRQ_I2C0_LBREQ_PRIO)
#elif IRQ_I2C0_LBREQ_CAT == IRQ_CAT23
ISR(I2C0LBREQ_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_I2C0_LBREQ_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call LBREQ interrupt funtion */                                              
}
#endif
#endif

#if ((IRQ_I2C1_EXIST == ON))
#if ((IRQ_I2C1_LBREQ_PRIO > 0) || (IRQ_I2C1_LBREQ_CAT == IRQ_CAT23))
#if ((IRQ_I2C1_LBREQ_PRIO > 0) && (IRQ_I2C1_LBREQ_CAT == IRQ_CAT1))
IFX_INTERRUPT(I2C1LBREQ_ISR, 0, IRQ_I2C1_LBREQ_PRIO)
#elif IRQ_I2C1_LBREQ_CAT == IRQ_CAT23
ISR(I2C1LBREQ_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_I2C1_LBREQ_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call LBREQ interrupt funtion */                                              
}
#endif
#endif

/*******************************************************************************
** Syntax          : void I2C0SREQ_ISR(void)                                  **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : reentrant                                                **
**                                                                            **
** Parameters (in) : none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description     : Service for SREQ interrupt of I2Cx                       **
**                                                                            **
*******************************************************************************/
#if ((IRQ_I2C0_EXIST == ON))
#if ((IRQ_I2C0_SREQ_PRIO > 0) || (IRQ_I2C0_SREQ_CAT == IRQ_CAT23))
#if ((IRQ_I2C0_SREQ_PRIO > 0) && (IRQ_I2C0_SREQ_CAT == IRQ_CAT1))
IFX_INTERRUPT(I2C0SREQ_ISR, 0, IRQ_I2C0_SREQ_PRIO)
#elif IRQ_I2C0_SREQ_CAT == IRQ_CAT23
ISR(I2C0SREQ_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_I2C0_SREQ_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call SREQ interrupt funtion */                                              
}
#endif
#endif

#if ((IRQ_I2C1_EXIST == ON))
#if ((IRQ_I2C1_SREQ_PRIO > 0) || (IRQ_I2C1_SREQ_CAT == IRQ_CAT23))
#if ((IRQ_I2C1_SREQ_PRIO > 0) && (IRQ_I2C1_SREQ_CAT == IRQ_CAT1))
IFX_INTERRUPT(I2C1SREQ_ISR, 0, IRQ_I2C1_SREQ_PRIO)
#elif IRQ_I2C1_SREQ_CAT == IRQ_CAT23
ISR(I2C1SREQ_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_I2C1_SREQ_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call LBREQ interrupt funtion */                                              
}
#endif
#endif

/*******************************************************************************
** Syntax          : void I2C0LSREQ_ISR(void)                                 **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : reentrant                                                **
**                                                                            **
** Parameters (in) : none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description     : Service for LSREQ interrupt of I2Cx                      **
**                                                                            **
*******************************************************************************/
#if ((IRQ_I2C0_EXIST == ON))
#if ((IRQ_I2C0_LSREQ_PRIO > 0) || (IRQ_I2C0_LSREQ_CAT == IRQ_CAT23))
#if ((IRQ_I2C0_LSREQ_PRIO > 0) && (IRQ_I2C0_LSREQ_CAT == IRQ_CAT1))
IFX_INTERRUPT(I2C0LSREQ_ISR, 0, IRQ_I2C0_LSREQ_PRIO)
#elif IRQ_I2C0_LSREQ_CAT == IRQ_CAT23
ISR(I2C0LSREQ_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_I2C0_LSREQ_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call LSREQ interrupt funtion */                                              
}
#endif
#endif

#if ((IRQ_I2C1_EXIST == ON))
#if ((IRQ_I2C1_LSREQ_PRIO > 0) || (IRQ_I2C1_LSREQ_CAT == IRQ_CAT23))
#if ((IRQ_I2C1_LSREQ_PRIO > 0) && (IRQ_I2C1_LSREQ_CAT == IRQ_CAT1))
IFX_INTERRUPT(I2C1LSREQ_ISR, 0, IRQ_I2C1_LSREQ_PRIO)
#elif IRQ_I2C1_LSREQ_CAT == IRQ_CAT23
ISR(I2C1LSREQ_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_I2C1_LSREQ_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call LSREQ interrupt funtion */                                              
}
#endif
#endif

/*******************************************************************************
** Syntax          : void I2C0ERR_ISR(void)                                   **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : reentrant                                                **
**                                                                            **
** Parameters (in) : none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description     : Service for ERR interrupt of I2Cx                        **
**                                                                            **
*******************************************************************************/
#if ((IRQ_I2C0_EXIST == ON))
#if ((IRQ_I2C0_ERR_PRIO > 0) || (IRQ_I2C0_ERR_CAT == IRQ_CAT23))
#if ((IRQ_I2C0_ERR_PRIO > 0) && (IRQ_I2C0_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(I2C0ERR_ISR, 0, IRQ_I2C0_ERR_PRIO)
#elif IRQ_I2C0_ERR_CAT == IRQ_CAT23
ISR(I2C0ERR_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_I2C0_ERR_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call ERR interrupt funtion */                                              
}
#endif
#endif

#if ((IRQ_I2C1_EXIST == ON))
#if ((IRQ_I2C1_ERR_PRIO > 0) || (IRQ_I2C1_ERR_CAT == IRQ_CAT23))
#if ((IRQ_I2C1_ERR_PRIO > 0) && (IRQ_I2C1_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(I2C1ERR_ISR, 0, IRQ_I2C1_ERR_PRIO)
#elif IRQ_I2C1_ERR_CAT == IRQ_CAT23
ISR(I2C1ERR_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_I2C1_ERR_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  /* Call ERR interrupt funtion */                                              
}
#endif
#endif

/*******************************************************************************
** Syntax          : void I2C0P_ISR(void)                                     **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : reentrant                                                **
**                                                                            **
** Parameters (in) : none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description     : Service for P interrupt of I2Cx                          **
**                                                                            **
*******************************************************************************/
#if ((IRQ_I2C0_EXIST == ON))
#if ((IRQ_I2C0_P_PRIO > 0) || (IRQ_I2C0_P_CAT == IRQ_CAT23))
#if ((IRQ_I2C0_P_PRIO > 0) && (IRQ_I2C0_P_CAT == IRQ_CAT1))
IFX_INTERRUPT(I2C0P_ISR, 0, IRQ_I2C0_P_PRIO)
#elif IRQ_I2C0_P_CAT == IRQ_CAT23
ISR(I2C0P_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_I2C0_P_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  #if (I2C_ASYNC_READ_WRITE == ON)
  /* Call Protocol interrupt funtion */  
  I2c_IsrI2cProtocol(I2C_ZERO);
  #endif
}
#endif
#endif

#if ((IRQ_I2C1_EXIST == ON))
#if ((IRQ_I2C1_P_PRIO > 0) || (IRQ_I2C1_P_CAT == IRQ_CAT23))
#if ((IRQ_I2C1_P_PRIO > 0) && (IRQ_I2C1_P_CAT == IRQ_CAT1))
IFX_INTERRUPT(I2C1P_ISR, 0, IRQ_I2C1_P_PRIO)
#elif IRQ_I2C1_P_CAT == IRQ_CAT23
ISR(I2C1P_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_I2C1_P_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

  #if (I2C_ASYNC_READ_WRITE == ON)
  /* Call Protocol interrupt funtion */
  I2c_IsrI2cProtocol(I2C_ONE);  
  #endif
}
#endif
#endif

#define IRQ_STOP_SEC_CODE
#include "MemMap.h"


