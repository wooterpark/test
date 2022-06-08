/******************************************************************************
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                            **
**   $FILENAME   : Mtl_TrapTab.c $                                            **
**                                                                            **
**   $CC VERSION : \main\19 $                                                 **
**                                                                            **
**   $DATE       : 2016-02-16 $                                               **
**                                                                           **
**  VARIANT   : VariantPB                                                    **
**                                                                           **
**  PLATFORM  : Infineon AURIX                                               **
**                                                                           **
**  COMPILER  : Tasking                                                      **
**                                                                           **
**  AUTHOR    : SafeTlib Team                                                **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  TRACEABILITY:                                                            **
**                                                                           **
**  DESCRIPTION  : This file contains                                        **
**                 - Trap vector table for Trap test                         **
**                                                                           **
**  MAY BE CHANGED BY USER [Yes/No]: No                                      **
**                                                                           **
******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Mcal.h"
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
#define IFX_GNRTRAPHANDLER_START_SEC_TVT_CODE_ASIL_B
#include "Ifx_MemMap.h"

#ifdef __TASKING__

__asm(".extern TRAP_GenericTrapHandler ");
void Stl_TrapVectors(void)
{
  /* Class 0, MMU Traps: */
  __asm(".align 256");
  __asm("svlcx");
  __asm("mov	    D4, #0");  /* trap class */
  __asm("mov	    D5, D15"); /* TIN */
  __asm("j		TRAP_GenericTrapHandler");

  __asm(".align 32");
  /* Class 1, Internal Protection Traps: */
  __asm("svlcx");
  __asm("mov		D4, #1");   /* trap class */
  __asm("mov		D5, D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

  __asm(".align 32");
  /* Class 2, Instruction Error Traps: */
  __asm("svlcx");
  __asm("mov		D4, #2");   /* trap class */
  __asm("mov		D5, D15");		  /* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

__asm(".align 32");
  /* Class 3, Context Management Traps: */
  __asm("svlcx");
  __asm("mov		D4, #3");   /* trap class */
  __asm("mov		D5, D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

__asm(".align 32");
  /* Class 4, System Bus and Peripheral Error Traps: */
  __asm("svlcx");
  __asm("mov		D4, #4");   /* trap class */
  __asm("mov		D5, D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

__asm(".align 32");
  /* Class 5, Assertion Traps: */
  __asm("svlcx");
  __asm("mov		D4, #5");   /* trap class */
  __asm("mov		D5, D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

__asm(".align 32");
    /* Class 6, System Call Trap: */
  __asm("svlcx");
  __asm("mov		D4, #6");   /* trap class */
  __asm("mov		D5, D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

__asm(".align 32");
    /* Class 7, Non Maskable Interrupt Traps: */
  __asm("svlcx");
  __asm("mov		D4, #7");   /* trap class */
  __asm("mov		D5, D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");
}
#endif /* __TASKING__ */

#ifdef __GNUC__

void Stl_TrapVectors(void)
{
  __asm (".align 8");
  /* Class 0, MMU Traps: */
  
  __asm("svlcx");
  __asm("mov	    %D4, 0");   /* trap class */
  __asm("mov	    %D5, %D15");  /* TIN */
  __asm("j		TRAP_GenericTrapHandler");

  /* Class 1, Internal Protection Traps: */
__asm(".align 5");
__asm("svlcx");
__asm("mov		%D4, 1");   /* trap class */
__asm("mov		%D5, %D15");	/* TIN */
__asm("j 		TRAP_GenericTrapHandler");

  /* Class 2, Instruction Error Traps: */
  __asm(".align 5"); 
  __asm("svlcx");
  __asm("mov		%D4, 2");   /* trap class */
  __asm("mov		%D5, %D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

  /* Class 3, Context Management Traps: */
  __asm(".align 5"); 
  __asm("svlcx");
  __asm("mov		%D4, 3");   /* trap class */
  __asm("mov		%D5, %D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

  /* Class 4, System Bus and Peripheral Error Traps: */
  __asm(".align 5"); 
  __asm("svlcx");
  __asm("mov		%D4, 4");   /* trap class */
  __asm("mov		%D5, %D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

  /* Class 5, Assertion Traps: */
  __asm(".align 5"); 
  __asm("svlcx");
  __asm("mov		%D4, 5");   /* trap class */
  __asm("mov		%D5, %D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

  /* Class 6, System Call Trap: */
  __asm(".align 5"); 
  __asm("svlcx");
  __asm("mov		%D4, 6");   /* trap class */
  __asm("mov		%D5, %D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

  /* Class 7, Non Maskable Interrupt Traps: */
  __asm(".align 5"); 
  __asm("svlcx");
  __asm("mov		%D4, 7");   /* trap class */
  __asm("mov		%D5, %D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");
}
#pragma section

#endif /* __GNUC__ */

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
void Stl_TrapVectors(void)
{
  __asm (".align 8");
  /* Class 0, MMU Traps: */
  __asm("svlcx");
  __asm("mov	    %D4, 0");   /* trap class */
  __asm("mov	    %D5, %D15");  /* TIN */
  __asm("j		TRAP_GenericTrapHandler");

  /* Class 1, Internal Protection Traps: */
__asm(".align 5");
__asm("svlcx");
__asm("mov		%D4, 1");   /* trap class */
__asm("mov		%D5, %D15");	/* TIN */
__asm("j 		TRAP_GenericTrapHandler");

  /* Class 2, Instruction Error Traps: */
  __asm(".align 5"); 
  __asm("svlcx");
  __asm("mov		%D4, 2");   /* trap class */
  __asm("mov		%D5, %D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

  /* Class 3, Context Management Traps: */
  __asm(".align 5"); 
  __asm("svlcx");
  __asm("mov		%D4, 3");   /* trap class */
  __asm("mov		%D5, %D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

  /* Class 4, System Bus and Peripheral Error Traps: */
  __asm(".align 5"); 
  __asm("svlcx");
  __asm("mov		%D4, 4");   /* trap class */
  __asm("mov		%D5, %D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

  /* Class 5, Assertion Traps: */
  __asm(".align 5"); 
  __asm("svlcx");
  __asm("mov		%D4, 5");   /* trap class */
  __asm("mov		%D5, %D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

  /* Class 6, System Call Trap: */
  __asm(".align 5"); 
  __asm("svlcx");
  __asm("mov		%D4, 6");   /* trap class */
  __asm("mov		%D5, %D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");

  /* Class 7, Non Maskable Interrupt Traps: */
  __asm(".align 5"); 
  __asm("svlcx");
  __asm("mov		%D4, 7");   /* trap class */
  __asm("mov		%D5, %D15");	/* TIN */
  __asm("j 		TRAP_GenericTrapHandler");
}
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif /* _DIABDATA_C_TRICORE_ */

#define IFX_GNRTRAPHANDLER_STOP_SEC_TVT_CODE_ASIL_B
#include "Ifx_MemMap.h"

