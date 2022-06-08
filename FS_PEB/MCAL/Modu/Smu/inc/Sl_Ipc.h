#ifndef SL_IPC_H
#define SL_IPC_H

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
**  $FILENAME   : Sl_Ipc.h $                                                 **
**                                                                           **
**  $CC VERSION : \main\30 $                                                 **
**                                                                           **
**  $DATE       : 2015-07-08 $                                               **
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
**                 - Mcal library declarations                                **
**                                                                            **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h  */
#include "Std_Types.h"
#include "Mcal.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Define the Spinlock IDs here. 
 * Ensure it is not for the entire AlarmGroup unless test uses the entire group
 */

typedef enum
{
/* 00 */   SL_SMUALRMGRP3_SPNLCK_ID,
/* 01 */   SL_LMU_SPNLCK_ID,
/* 02 */   SL_DMA_SPNLCK_ID,
/* 03 */   SL_FCE_SPNLCK_ID,
/* 04 */   SL_SMUDRIVER_SPNLCK_ID,
/* 05 */   SL_SMUALRMGRP3_BIT30_SPNLCK_ID,
/* 06 */   SL_SMUALRMGRP5_ALM0_SPNLCK_ID,
/* 07 */   SL_SMUALRMGRP5_ALM1_SPNLCK_ID,
/* 08 */   SL_SMUALRMGRP5_ALM2_SPNLCK_ID,
/* 09 */   SL_SMUALRMGRP5_ALM3_SPNLCK_ID,

  /* Number of Spinlocks used */
  SL_SPINLOCK_CNT
}SlSpnlockId;





/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

void Sl_SpinLockInit(void);
Std_ReturnType Sl_GetSpinLock(const SlSpnlockId SpinLckID,uint32 Timeout);
void Sl_ReleaseSpinLock(SlSpnlockId SpinLckID);


#endif /* SL_IPC_H */

