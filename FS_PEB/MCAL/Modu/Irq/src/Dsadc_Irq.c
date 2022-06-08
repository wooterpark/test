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
**  $FILENAME   : Dsadc_Irq.c $                                              **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2014-06-25 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the interrupt frames for the            **
**                                                            DSADC Module.  **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
#include "Irq.h"
#include "Mcal.h"
#include "Dsadc.h"


/*******************************************************************************
**                      Private Macros Definitions                            **
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
extern void RdcNotification();

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define IRQ_START_SEC_CODE
#include "MemMap.h"
/******************************************************************************
** Syntax :          void DSADCSRM0_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRM0_PRIO > 0) || (IRQ_DSADC_SRM0_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRM0_PRIO > 0) && (IRQ_DSADC_SRM0_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRM0_ISR, 0, IRQ_DSADC_SRM0_PRIO)
#elif IRQ_DSADC_SRM0_CAT == IRQ_CAT23
ISR(DSADCSRM0_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRA0_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRA0_PRIO > 0) || (IRQ_DSADC_SRA0_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRA0_PRIO > 0) && (IRQ_DSADC_SRA0_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRA0_ISR, 0, IRQ_DSADC_SRA0_PRIO)
#elif IRQ_DSADC_SRA0_CAT == IRQ_CAT23
ISR(DSADCSRA0_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRM1_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRM1_PRIO > 0) || (IRQ_DSADC_SRM1_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRM1_PRIO > 0) && (IRQ_DSADC_SRM1_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRM1_ISR, 0, IRQ_DSADC_SRM1_PRIO)
#elif IRQ_DSADC_SRM1_CAT == IRQ_CAT23
ISR(DSADCSRM1_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRA1_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRA1_PRIO > 0) || (IRQ_DSADC_SRA1_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRA1_PRIO > 0) && (IRQ_DSADC_SRA1_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRA1_ISR, 0, IRQ_DSADC_SRA1_PRIO)
#elif IRQ_DSADC_SRA1_CAT == IRQ_CAT23
ISR(DSADCSRA1_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRM2_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRM2_PRIO > 0) || (IRQ_DSADC_SRM2_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRM2_PRIO > 0) && (IRQ_DSADC_SRM2_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRM2_ISR, 0, IRQ_DSADC_SRM2_PRIO)
#elif IRQ_DSADC_SRM2_CAT == IRQ_CAT23
ISR(DSADCSRM2_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRA2_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRA2_PRIO > 0) || (IRQ_DSADC_SRA2_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRA2_PRIO > 0) && (IRQ_DSADC_SRA2_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRA2_ISR, 0, IRQ_DSADC_SRA2_PRIO)
#elif IRQ_DSADC_SRA2_CAT == IRQ_CAT23
ISR(DSADCSRA2_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRM3_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRM3_PRIO > 0) || (IRQ_DSADC_SRM3_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRM3_PRIO > 0) && (IRQ_DSADC_SRM3_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRM3_ISR, 0, IRQ_DSADC_SRM3_PRIO)
#elif IRQ_DSADC_SRM3_CAT == IRQ_CAT23
ISR(DSADCSRM3_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRA3_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRA3_PRIO > 0) || (IRQ_DSADC_SRA3_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRA3_PRIO > 0) && (IRQ_DSADC_SRA3_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRA3_ISR, 0, IRQ_DSADC_SRA3_PRIO)
#elif IRQ_DSADC_SRA3_CAT == IRQ_CAT23
ISR(DSADCSRA3_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif


/******************************************************************************
** Syntax :          void DSADCSRM4_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRM4_PRIO > 0) || (IRQ_DSADC_SRM4_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRM4_PRIO > 0) && (IRQ_DSADC_SRM4_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRM4_ISR, 0, IRQ_DSADC_SRM4_PRIO)
#elif IRQ_DSADC_SRM4_CAT == IRQ_CAT23
ISR(DSADCSRM4_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();

  RdcNotification( );/*Rdc Notification*/

 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRA4_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRA4_PRIO > 0) || (IRQ_DSADC_SRA4_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRA4_PRIO > 0) && (IRQ_DSADC_SRA4_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRA4_ISR, 0, IRQ_DSADC_SRA4_PRIO)
#elif IRQ_DSADC_SRA4_CAT == IRQ_CAT23
ISR(DSADCSRA4_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRM5_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRM5_PRIO > 0) || (IRQ_DSADC_SRM5_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRM5_PRIO > 0) && (IRQ_DSADC_SRM5_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRM5_ISR, 0, IRQ_DSADC_SRM5_PRIO)
#elif IRQ_DSADC_SRM5_CAT == IRQ_CAT23
ISR(DSADCSRM5_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRA5_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRA5_PRIO > 0) || (IRQ_DSADC_SRA5_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRA5_PRIO > 0) && (IRQ_DSADC_SRA5_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRA5_ISR, 0, IRQ_DSADC_SRA5_PRIO)
#elif IRQ_DSADC_SRA5_CAT == IRQ_CAT23
ISR(DSADCSRA5_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRM6_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRM6_PRIO > 0) || (IRQ_DSADC_SRM6_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRM6_PRIO > 0) && (IRQ_DSADC_SRM6_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRM6_ISR, 0, IRQ_DSADC_SRM6_PRIO)
#elif IRQ_DSADC_SRM6_CAT == IRQ_CAT23
ISR(DSADCSRM6_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRA6_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRA6_PRIO > 0) || (IRQ_DSADC_SRA6_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRA6_PRIO > 0) && (IRQ_DSADC_SRA6_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRA6_ISR, 0, IRQ_DSADC_SRA6_PRIO)
#elif IRQ_DSADC_SRA6_CAT == IRQ_CAT23
ISR(DSADCSRA6_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRM7_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRM7_PRIO > 0) || (IRQ_DSADC_SRM7_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRM7_PRIO > 0) && (IRQ_DSADC_SRM7_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRM7_ISR, 0, IRQ_DSADC_SRM7_PRIO)
#elif IRQ_DSADC_SRM7_CAT == IRQ_CAT23
ISR(DSADCSRM7_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRA7_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRA7_PRIO > 0) || (IRQ_DSADC_SRA7_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRA7_PRIO > 0) && (IRQ_DSADC_SRA7_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRA7_ISR, 0, IRQ_DSADC_SRA7_PRIO)
#elif IRQ_DSADC_SRA7_CAT == IRQ_CAT23
ISR(DSADCSRA7_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRM8_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRM8_PRIO > 0) || (IRQ_DSADC_SRM8_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRM8_PRIO > 0) && (IRQ_DSADC_SRM8_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRM8_ISR, 0, IRQ_DSADC_SRM8_PRIO)
#elif IRQ_DSADC_SRM8_CAT == IRQ_CAT23
ISR(DSADCSRM8_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRA8_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRA8_PRIO > 0) || (IRQ_DSADC_SRA8_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRA8_PRIO > 0) && (IRQ_DSADC_SRA8_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRA8_ISR, 0, IRQ_DSADC_SRA8_PRIO)
#elif IRQ_DSADC_SRA8_CAT == IRQ_CAT23
ISR(DSADCSRA8_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRM9_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRM9_PRIO > 0) || (IRQ_DSADC_SRM9_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRM9_PRIO > 0) && (IRQ_DSADC_SRM9_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRM9_ISR, 0, IRQ_DSADC_SRM9_PRIO)
#elif IRQ_DSADC_SRM9_CAT == IRQ_CAT23
ISR(DSADCSRM9_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif
/******************************************************************************
** Syntax :          void DSADCSRA9_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on DSADC Request source conversion complete     **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_DSADC_SRA9_PRIO > 0) || (IRQ_DSADC_SRA9_CAT == IRQ_CAT23))
#if((IRQ_DSADC_SRA9_PRIO > 0) && (IRQ_DSADC_SRA9_CAT == IRQ_CAT1))
IFX_INTERRUPT(DSADCSRA9_ISR, 0, IRQ_DSADC_SRA9_PRIO)
#elif IRQ_DSADC_SRA9_CAT == IRQ_CAT23
ISR(DSADCSRA9_ISR)
#endif
{
  /* Enable Global Interrupts */
  EnableAllInterrupts();
 /* user code here*/
}
#endif

#define IRQ_STOP_SEC_CODE
#include "MemMap.h"

