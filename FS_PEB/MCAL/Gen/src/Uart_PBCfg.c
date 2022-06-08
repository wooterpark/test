/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Uart_PBCfg.c $                                             **
**                                                                            **
**  $CC VERSION : \main\24 $                                                 **
**                                                                            **
**  DATE, TIME: 2021-09-29, 16:08:33                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Uart configuration generated out of ECU configuration      **
**                 file(Uart.bmd/.xdm)                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include UART Module File */
#include "Uart.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
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
/*
               Container: UartConfigSet
*/
#define UART_START_SEC_POSTBUILDCFG
/*
 * To be used for global or static constants (unspecified size)
*/
#include "MemMap.h"
                
/* Uart Channel Initialization Data */

static const Uart_ChannelType  Uart_kChannelConfig0[1] = 
{
  {  /* Notification function pointers for UART Module */
    {
      /* Call-back Notification Function for Write operation */
      NULL_PTR,
      /* Call-back Notification Function for Read operation */
      NULL_PTR,
      /* Call-back Notification Function for AbortWrite operation */
      NULL_PTR,
      /* Call-back Notification Function for AbortRead operation */
      NULL_PTR,
    },
  	/* BaudRate : 1500000 Hz  */
    135U,       /* BRG.NUMERATOR value */
    1000U,     /* BRG.DENOMINATOR value */
    0U,       /* BITCON.PRESCALAR value */
    8U,       /* BITCON.Oversampling value */
    UART_ASCLIN1,    /* HW Unit used */
    1U,      /* Number of Stop Bits*/
    8U,      /* DataLength*/
    0U,      /* UartRxPinSelection */
    0U,      /*Parity Enable*/ 
    0U,      /* Odd or Even Parity */ 
    0U,      /*CTS Enable*/
    0U,      /*RTS/CTS Polarity*/
  },
};

/* Uart Module Initialization Data */

const Uart_ConfigType  Uart_ConfigRoot[1] = 
 {
   {
      Uart_kChannelConfig0,
      1U,
   }  
 };

#define UART_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

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
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

