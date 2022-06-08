/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : IRTst_IRTab.c $                                            **
**                                                                            **
**  $CC VERSION : \main\14 $                                                 **
**                                                                            **
**  $DATE       : 2016-02-16 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains the IR table used for the IR test       **
**                                                                            **
**  REFERENCE(S) : Aurix_SafeTlib_DS_IRTest                                   **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
#include "IRTst.h"
/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/******************************************************************************
**                        Exported object definitions                         *
******************************************************************************/

/******************************************************************************
**                        Local object definitions                            *
******************************************************************************/

/******************************************************************************
**                        Imported function declarations                      *
******************************************************************************/

/******************************************************************************
**                        Local function prototypes                           *
******************************************************************************/

/******************************************************************************
**                    Local inline function definitions                       *
******************************************************************************/

/******************************************************************************
**                    Configuration error checking                            *
******************************************************************************/

/******************************************************************************
**                         Function definitions                               *
******************************************************************************/
#define IFX_IRTST_START_SEC_IVT_CODE_ASIL_B
#include "Ifx_MemMap.h"

 /*******************************************************************************
 ** Syntax : void IRTst_inttab(void)                                           **
 **                                                                            **
 ** Service ID:  0                                                             **
 **                                                                            **
 ** Sync/Async:  Synchronous                                                   **
 **                                                                            **
 ** Reentrancy:  Non reentrant                                                 **
 **                                                                            **
 ** Parameters (in) :  None                                                    **
 **                                                                            **
 ** Parameters (out):  None                                                    **
 **                                                                            **
 ** Return value    :  None                                                    **
 **                                                                            **
 ** Description     : Interrupt vector address for IR Test                     **
 **                                                                            **
 *******************************************************************************/

#ifdef __TASKING__
/* Special interrupt table used during the Interrupt Router test:             */
void IRTst_inttab (void)
{
  /* Interrupt tables must be aligned on 2048byte boundary                    */
  __asm (".align 2048");

  /* Duplicate source lines sequence 256 times                                */
  __asm (".DUP 256 \n"
         ".align 8 \n\t"

         /* Return from interrupt                                             */
         "rfe \n\t"
         ".ENDM");
}
#endif /* __TASKING__ */

#ifdef __GNUC__
/* ; Special interrupt table used during the Interrupt Router test:           */
void IRTst_inttab (void)
{
  /* Interrupt tables must be aligned on (2^11)2048byte boundary              */
  __asm (".align 11");

  /* Duplicate source lines sequence 256 times                                */
  __asm (".rept 256 \n"
         ".align 3 \n\t"

         /* Return from interrupt                                             */
         "rfe \n\t"
         ".endr");
}
#endif /* __GNUC__ */

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
void IRTst_inttab (void)
{
  /* Interrupt tables must be aligned on (2^11)2048byte boundary              */
  __asm (".align 11");

  /* 256 interrupt vector entries. Each entry is 8 byte aligned               */
  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

  __asm (".align 3");
  __asm ("rfe");

}
#endif /*_DIABDATA_C_TRICORE_ == 1 */
#endif /*_DIABDATA_C_TRICORE_*/


#define IFX_IRTST_STOP_SEC_IVT_CODE_ASIL_B
#include "Ifx_MemMap.h"
