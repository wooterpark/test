/*******************************************************************************
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**  $FILENAME   : Sl_Timeout.h $                                             **
**                                                                            **
**  $CC VERSION : \main\34 $                                                 **
**                                                                            **
**  $DATE       : 2015-06-22 $                                               **
**                                                                            **
**  PLATFORM    : Infineon AURIX                                              **
**                                                                            **
**  AUTHOR      : SafeTlib Team                                               **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  Description : Configuration of time-out values for MTL tests              **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

#ifndef TESTAPI_H_
#define TESTAPI_H_

/* Maximum timeout value to acquire the Safety endinit                       */
/* The timeout is maximum execution time between reset and setting of Safety */
/* endinit mutliplied by a safety factor of 10                               */

#define SL_SAFETY_ENDINT_TIMEOUT ((uint32)22960U)

/* Define the Test specific spin lock Timeouts here                          */
/*The timeout values are calculated based on the WCET values of the APIs     */
/*The WCET values used are based on CPU freq:100 MHz and STM freq:50 MHz     */
/*Safety factor of 6 is used. i.e. if the WCET value of API  is 1000 cycles, */
/* macro value used for corresponding timeout is 1000*6 = 6000 cycles        */

#define SL_SMUALRMGRP3_TIMEOUT        (146280U)
#define SL_SMUALRMGRP5_ALM0_TIMEOUT   (20000U)
#define SL_SMUALRMGRP5_ALM1_TIMEOUT   (20000U)
#define SL_SMUALRMGRP5_ALM2_TIMEOUT   (20000U)
#define SL_SMUALRMGRP5_ALM3_TIMEOUT   (20000U)
#define SL_LMU_TIMEOUT                (20000U)
#define SL_DMA_TIMEOUT                (20000U)
#define SL_FCE_TIMEOUT                (20000U)
#define SL_SMUALRMGRP3_BIT30_TIMEOUT  (30978U)

#endif /* TESTAPI_H_ */
