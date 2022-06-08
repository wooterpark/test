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
**  $FILENAME   : Eth_Irq.c $                                                **
**                                                                           **
**  $CC VERSION : \main\13 $                                                 **
**                                                                           **
**  $DATE       : 2016-06-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the interrupt handlers for ETH. This    **
**                 file is given for evaluation purpose only                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Tasking sfr file */


/*Include Irq Module*/
#include "Irq.h"

/* Include Mcal.h to import the library functions */ 
#include "Mcal.h"

/* Include Eth header file Eth.h */
#include "Eth_17_EthMac.h"
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
** Syntax : void ETHSR_ISR(void)                                             **
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
** Description : Service for ETH TX and RX                                   **
**                                                                           **
*****************************************************************************/
#if (IRQ_ETH_EXIST == STD_ON)

#if((IRQ_ETH_SR_PRIO > 0) || (IRQ_ETH_SR_CAT == IRQ_CAT23))
#if((IRQ_ETH_SR_PRIO > 0) && (IRQ_ETH_SR_CAT == IRQ_CAT1))
IFX_INTERRUPT(ETHSR_ISR, 0, IRQ_ETH_SR_PRIO)
#elif IRQ_ETH_SR_CAT == IRQ_CAT23
ISR(ETHSR_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_ETH_SR_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  
  /* Parameter is Channel Number */
  Eth_17_EthMac_TxRxIrqHandler();
}
#endif

#endif /*IRQ_ETH_EXIST == STD_ON */

#define IRQ_STOP_SEC_CODE
#include "MemMap.h"
