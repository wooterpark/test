#ifndef MTL_TRAP_H_INCLUDED
#define MTL_TRAP_H_INCLUDED
/*******************************************************************************
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
**   $FILENAME   : Mtl_Trap.h $                                               **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
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
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of Trap test                               **
**                                                                            **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


/****************************************************************************************/
/* MODULE START                                                                         */
/****************************************************************************************/









/****************************************************************************************/
/* INCLUDE FILES                                                                        */
/****************************************************************************************/

#include "Platform_Types.h"
#include "Mcal_Compiler.h"

/****************************************************************************************/
/* DEFINES                                                                              */
/****************************************************************************************/

/* STL Trap driver status codes:                                                        */
#define TRAP_E_SUCCESS        ( (TRAP_ErrorType)0x00000000)
#define TRAP_E_SEQUENCE       ( (TRAP_ErrorType)0x00000001)
#define TRAP_E_EXISTS         ( (TRAP_ErrorType)0x00000002)
#define TRAP_E_NOT_EXISTS     ( (TRAP_ErrorType)0x00000003)
#define TRAP_E_PARAM          ( (TRAP_ErrorType)0x00000004)
#define TRAP_E_INIT           ( (TRAP_ErrorType)0x00000005)
#define TRAP_E_UNINIT         ( (TRAP_ErrorType)0x00000006)
#define TRAP_E_FAILED         ( (TRAP_ErrorType)0x00000007)

/* Trap Classes:                                                                        */
#define TRAP_CLASS0            ( (uint8)0)
#define TRAP_CLASS1            ( (uint8)1)
#define TRAP_CLASS2            ( (uint8)2)
#define TRAP_CLASS3            ( (uint8)3)
#define TRAP_CLASS4            ( (uint8)4)
#define TRAP_CLASS5            ( (uint8)5)
#define TRAP_CLASS6            ( (uint8)6)
#define TRAP_CLASS7            ( (uint8)7)


/****************************************************************************************/
/* MACRO's                                                                              */
/****************************************************************************************/



/****************************************************************************************/
/* DATA TYPES                                                                           */
/****************************************************************************************/

/* Definition of a Trap Handler callback function pointer:                                */
typedef boolean (* TRAP_TrapHandlerCbk)(const uint32 trapID);

/* STL Trap driver error type:                                                            */
typedef uint32                TRAP_ErrorType;


/****************************************************************************************/
/* EXTERNAL VARIABLES                                                                   */
/****************************************************************************************/



/****************************************************************************************/
/* EXTERNAL FUNCTION PROTOTYPES                                                         */
/****************************************************************************************/
#define IFX_GNRTRAPHANDLER_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
extern void Stl_TrapVectors(void);

extern TRAP_ErrorType        TRAP_Init(void);

extern TRAP_ErrorType        TRAP_RegisterTrapHandler(const uint8 class, const TRAP_TrapHandlerCbk  handler);
extern TRAP_ErrorType        TRAP_UnregisterTrapHandler(const uint8 class);
extern TRAP_ErrorType        TRAP_RegisterTrapHandlerAllCores(const uint8 trapclass, const TRAP_TrapHandlerCbk  handler);
extern TRAP_ErrorType        TRAP_UnregisterTrapHandlerAllCores(const uint8 trapclass);


extern TRAP_ErrorType        TRAP_StartHandleTraps(void);
extern TRAP_ErrorType        TRAP_StopHandleTraps(void);

extern void*                 TRAP_GenericTrapHandler(uint32 trapClass, uint32 trapID);

#define IFX_GNRTRAPHANDLER_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/****************************************************************************************/
/* CONFIGURATION ERRORS                                                                 */
/****************************************************************************************/



/****************************************************************************************/
/* MODULE END                                                                           */
/****************************************************************************************/

#endif /* MTL_TRAP_H_INCLUDED */

