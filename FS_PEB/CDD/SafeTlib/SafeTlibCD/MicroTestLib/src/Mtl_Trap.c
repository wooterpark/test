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
**   $FILENAME   : Mtl_Trap.c $                                               **
**                                                                            **
**   $CC VERSION : \main\33 $                                                 **
**                                                                            **
**   $DATE       : 2016-02-16 $                                               **
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
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

/****************************************************************************************/
/* INCLUDE FILES                                                                        */
/****************************************************************************************/
#include "Mtl_Trap.h"
#include "Compiler_Cfg.h"
#include "IfxCpu_reg.h"
#include "Mcal.h"
#include "ChipId.h"


/****************************************************************************************/
/* LOCAL DEFINES                                                                        */
/****************************************************************************************/


#define INVOKE_APPL_TRAP_HANDLER(VECTOR, TRAP_ID)                                       \
            INVOKE_APPL_TRAP_HANDLER1(VECTOR);                                  \
            INVOKE_APPL_TRAP_HANDLER2(TRAP_ID);                                   \


#ifdef __TASKING__
#define INVOKE_APPL_TRAP_HANDLER1(VECTOR)                                       \
    __asm("mov.a a12,%0" : : "d"(VECTOR));

#define INVOKE_APPL_TRAP_HANDLER2(TRAP_ID)                                       \
    __asm("mov d15,%0" : : "d"(TRAP_ID));    /* Restore TIN to D15                   */ \
    __asm("rslcx");                          /* Restore Lower Context                */ \
    __asm("ji16 a12")                        /* Jump to the applications Trap Vector */
#endif

#ifdef __GNUC__
#define INVOKE_APPL_TRAP_HANDLER1(VECTOR)                                       \
    __asm("mov.a %%a12,%0" : : "d"(VECTOR));
#define INVOKE_APPL_TRAP_HANDLER2(TRAP_ID)                                       \
    __asm("mov %%d15,%0" : : "d"(TRAP_ID));    /* Restore TIN to D15                   */ \
    __asm("rslcx");                          /* Restore Lower Context                */ \
    __asm("ji %a12")                        /* Jump to the applications Trap Vector */
#endif

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
asm volatile void INVOKE_APPL_TRAP_HANDLER1(void *VectorAddress)
{
% reg VectorAddress
  mov.aa %a12, VectorAddress
}

asm volatile void INVOKE_APPL_TRAP_HANDLER2(uint32 TrapId)
{
% reg TrapId
! "%d15"
  mov %d15,TrapId   /* Copy TIN to D15          */  
  rslcx             /* Restore Lower Context    */   
  ji %a12           /* Jump to the applications */
}
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif


#define TRAP_CLASS_COUNT_TOTAL            ( 8 )

#define TRAP_ID3                          ( 3U )

/****************************************************************************************/
/* LOCAL DATA TYPES                                                                     */
/****************************************************************************************/

/* Module Status of the STL's Trap Driver:                                              */
typedef enum
{
    TMS_UNINIT = 0,
    TMS_READY
} TRAP_ModuleStatus;

typedef volatile struct
{
    uint32    Pcxi;
    uint32    A11;
    uint32    A2;
    uint32    A3;
    uint32    D0;
    uint32    D1;
    uint32    D2;
    uint32    D3;
    uint32    A4;
    uint32    A5;
    uint32    A6;
    uint32    A7;
    uint32    D4;
    uint32    D5;
    uint32    D6;
    uint32    D7;
} StlTrap_LowerContext;


/****************************************************************************************/
/* LOCAL CONSTANTS                                                                      */
/****************************************************************************************/



/****************************************************************************************/
/* LOCAL TABLES                                                                         */
/****************************************************************************************/


#define IFX_GNRTRAPHANDLER_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

static volatile TRAP_TrapHandlerCbk  trap_TrapHandlers[MCAL_NO_OF_CORES][TRAP_CLASS_COUNT_TOTAL] = { {0} };
static void*                trap_BtvBackup[MCAL_NO_OF_CORES] = {NULL_PTR};
static TRAP_ModuleStatus    trap_ModuleStatus[MCAL_NO_OF_CORES] = {TMS_UNINIT};

#define IFX_GNRTRAPHANDLER_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"


/****************************************************************************************/
/* LOCAL VARIABLES                                                                      */
/****************************************************************************************/



/****************************************************************************************/
/* LOCAL FUNCTION PROTOTYPES                                                            */
/****************************************************************************************/

/*void Stl_TrapHandler(uint32 trapClass, uint32 trapID) __attribute__((noreturn));*/



/****************************************************************************************/
/* LOCAL CONFIGURATION ERRORS                                                           */
/****************************************************************************************/



/****************************************************************************************/
/* EXTERNAL (PUBLIC) IMPLEMENTATION                                                     */
/****************************************************************************************/
#define IFX_GNRTRAPHANDLER_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/****************************************************************************************/
/*  Function:           TRAP_Init                                                       */
/****************************************************************************************/
/*  Description:        Initialize the STL's Trap Driver.                               */
/*                                                                                      */
/*  Arguments (In):     <none>                                                          */
/*  Arguments (Out):    <none>                                                          */
/*  Arguments (InOut):  <none>                                                          */
/*  Return Value:       -TRAP_E_SUCCESS     : Trap Driver initialized successfully      */
/*                      -TRAP_E_INIT        : The Trap Driver has already been          */
/*                                              initialized before                      */
/*  Note(s):            <none>                                                          */
/*  Pre-Condition(s):   The Trap Driver must not have been initialized before.          */
/*  Post-Condition(s):  The Trap Driver is initialized and ready for being used.        */
/*                                                                                      */
/****************************************************************************************/
TRAP_ErrorType TRAP_Init(void)
{
  sint32            i;
  TRAP_ErrorType    result = TRAP_E_SUCCESS;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & (uint8)0x3U);

  /* Check for prior module initialization:                                           */
  if (TMS_UNINIT != trap_ModuleStatus[CoreId])
  {
    result = TRAP_E_INIT;
  }
  else
  {
    for (i = 0; i < TRAP_CLASS_COUNT_TOTAL; i++)
    {
      trap_TrapHandlers[CoreId][i] = NULL_PTR;
    }
    trap_BtvBackup[CoreId] = NULL_PTR;

    trap_ModuleStatus[CoreId] = TMS_READY;
  }
  return result;
}

/****************************************************************************************/
/*  Function:           TRAP_RegisterTrapHandlerAllCores                                */
/****************************************************************************************/
/*  Description:        Registers a caller supplied Trap Handler for traps of a given   */
/*                      Trap Class for all cores available.                             */
/*                                                                                      */
/*  Arguments (In):     -trapclass            : Trap Class for which to register a Trap */
/*                                              Handler routine                         */
/*                      -handler              : Trap Handler function pointer that is to*/
/*                                              be called for traps of the given Trap   */
/*                                              Class                                   */
/*  Arguments (Out):    <none>                                                          */
/*  Arguments (InOut):  <none>                                                          */
/*  Return Value:       -TRAP_E_SUCCESS       : Trap Handler successfully registered    */
/*                      -TRAP_E_UNINIT        : The Trap Driver has not yet been        */
/*                                              initialized                             */
/*                      -TRAP_E_PARAM         : Invalid parameter supplied              */
/*                      -TRAP_E_EXISTS        : Another Trap Handler has already been   */
/*                                              registered for the given Trap Class     */
/*  Note(s):            <none>                                                          */
/*  Pre-Condition(s):   1) The Trap Driver must have been initialized before for        */
/*                         available running cores used by the user.                    */
/*                      2) No Trap Handler must currenly be associated with the         */
/*                      given Trap Class for available running cores.                   */
/*                      3) No plausiblity check done for other cores other than         */
/*                         executing core since other cores may not be activated/used.  */
/*  Post-Condition(s):  The given Trap Handler routine might be called upon the arise   */
/*                      of traps of the given Trap Class or may be un-registered by     */
/*                      calling TRAP_UnregisterTrapHandler.                             */
/*                                                                                      */
/****************************************************************************************/
TRAP_ErrorType TRAP_RegisterTrapHandlerAllCores(const uint8 trapclass, 
                                          const TRAP_TrapHandlerCbk handler)
{
  TRAP_ErrorType    result = TRAP_E_SUCCESS;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & (uint8)0x3U);

  /* Plausibility check done only for executing core */

  /* Check module initialization:   */
  if (TMS_READY != trap_ModuleStatus[CoreId])
  {
    result = TRAP_E_UNINIT;
  }
  /* Parameter check:       */
  else if (trapclass >= (uint8)TRAP_CLASS_COUNT_TOTAL)
  {
    result = TRAP_E_PARAM;
  }
  else if (NULL_PTR == handler)
  {
    result = TRAP_E_PARAM;
  }
  else if (NULL_PTR != trap_TrapHandlers[CoreId][trapclass])
  {
    /* Existing Trap Handler associated with the given Trap Class:    */
    result = TRAP_E_EXISTS;
  }
  else
  {  
    #if (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
    for (CoreId = 0U;(CoreId < MCAL_NO_OF_CORES); CoreId++)
    #endif
    {
        /* Store the given Trap Handler to the local list:  */
        trap_TrapHandlers[CoreId][trapclass] = handler;
    }/* end of for for CoreId */
  }
  return result;
}

/****************************************************************************************/
/*  Function:           TRAP_UnregisterTrapHandlerAllCores                              */
/****************************************************************************************/
/*  Description:        Un-registers a previously registered Trap Handler for traps of  */
/*                      a given Trap Class.                                             */
/*                                                                                      */
/*  Arguments (In):     -trapclass   : Trap Class for which to un-register the          */
/*                                     Trap Handler routine                             */
/*  Arguments (Out):    <none>                                                          */
/*  Arguments (InOut):  <none>                                                          */
/*  Return Value:       -TRAP_E_SUCCESS      : Trap Handler successfully un-registered  */
/*                      -TRAP_E_UNINIT       : The Trap Driver has not yet been         */
/*                                             initialized                              */
/*                      -TRAP_E_PARAM        : Invalid parameter supplied               */
/*                      -TRAP_E_NOT_EXISTS   : No Trap Handler was registered for the   */
/*                                             given Trap Class                         */
/*  Note(s):            <none>                                                          */
/*  Pre-Condition(s):   The Trap Driver must have been initialized before.              */
/*                        with the given Trap Class.                                    */
/*  Pre-Condition(s):   1) The Trap Driver must have been initialized before for        */
/*                         available running cores used by the user.                    */
/*                      2) A Trap Handler must have been associated with the            */
/*                         given Trap Class for available running cores.                */
/*                      3) No plausiblity check done for other cores other than         */
/*                         executing core since other cores may not be activated/used.  */
/*  Post-Condition(s):  The given Trap Handler routine will no longer be called         */
/*                      upon the arise of traps of the given Trap Class and a new       */
/*                      Trap Handler may be registered by calling                       */
/*                      TRAP_RegisterTrapHandler.                                       */
/*                                                                                      */
/****************************************************************************************/
TRAP_ErrorType TRAP_UnregisterTrapHandlerAllCores(const uint8 trapclass)
{
  TRAP_ErrorType    result = TRAP_E_SUCCESS;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & (uint8)0x3U);

  /* Plausibility check done only for executing core */

  /* Check module initialization:   */
  if (TMS_READY != trap_ModuleStatus[CoreId])
  {
    result = TRAP_E_UNINIT;
  }
  /* Parameter check:    */
  else if (trapclass >= (uint8)TRAP_CLASS_COUNT_TOTAL)
  {
    result = TRAP_E_PARAM;
  }
  else if (NULL_PTR == trap_TrapHandlers[CoreId][trapclass])
  {
    /* There is no Trap Handler associated with the given Trap Class: */
    result = TRAP_E_NOT_EXISTS;
  }
  else
  {
    #if (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
    for (CoreId = 0U;(CoreId < MCAL_NO_OF_CORES); CoreId++)
    #endif
    {
      /* Delete the given Trap Handler from the local list:   */
      trap_TrapHandlers[CoreId][trapclass] = NULL_PTR;
    }
  }
  
  return result;
}

/****************************************************************************************/
/*  Function:           TRAP_RegisterTrapHandler                                        */
/****************************************************************************************/
/*  Description:        Registers a caller supplied Trap Handler for traps of a given   */
/*                      Trap Class.                                                     */
/*                                                                                      */
/*  Arguments (In):     -class                : Trap Class for which to register a Trap */
/*                                              Handler routine                         */
/*                      -handler              : Trap Handler function pointer that is to*/
/*                                              be called for traps of the given Trap   */
/*                                              Class                                   */
/*  Arguments (Out):    <none>                                                          */
/*  Arguments (InOut):  <none>                                                          */
/*  Return Value:       -TRAP_E_SUCCESS       : Trap Handler successfully registered    */
/*                      -TRAP_E_UNINIT        : The Trap Driver has not yet been        */
/*                                              initialized                             */
/*                      -TRAP_E_PARAM         : Invalid parameter supplied              */
/*                      -TRAP_E_EXISTS        : Another Trap Handler has already been   */
/*                                              registered for the given Trap Class     */
/*  Note(s):            <none>                                                          */
/*  Pre-Condition(s):   The Trap Driver must have been initialized before.              */
/*                      No Trap Handler must currenly be associated with the given Trap */
/*                      Class.                                                          */
/*  Post-Condition(s):  The given Trap Handler routine might be called upon the arise   */
/*                      of traps of the given Trap Class or may be un-registered by     */
/*                      calling TRAP_UnregisterTrapHandler.                             */
/*                                                                                      */
/****************************************************************************************/
TRAP_ErrorType TRAP_RegisterTrapHandler(const uint8 class, const TRAP_TrapHandlerCbk handler)
{
  TRAP_ErrorType    result = TRAP_E_SUCCESS;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & (uint8)0x3U);

  /* Check module initialization:                                                        */
  if (TMS_READY != trap_ModuleStatus[CoreId])
  {
    result = TRAP_E_UNINIT;
  }
  /* Parameter check:                                                                    */
  else if (class >= (uint8)TRAP_CLASS_COUNT_TOTAL)
  {
    result = TRAP_E_PARAM;
  }
  else if (NULL_PTR == handler)
  {
    result = TRAP_E_PARAM;
  }
  else if (NULL_PTR != trap_TrapHandlers[CoreId][class])
  {
    /* There is already another Trap Handler associated with the given Trap Class:    */
    result = TRAP_E_EXISTS;
  }
  else
  {
    /* Store the given Trap Handler to the local list:                                */
    trap_TrapHandlers[CoreId][class] = handler;
  }

  return result;
}

/****************************************************************************************/
/*  Function:           TRAP_UnregisterTrapHandler                                      */
/****************************************************************************************/
/*  Description:        Un-registers a previously registered Trap Handler for traps of  */
/*                      a given Trap Class.                                             */
/*                                                                                      */
/*  Arguments (In):     -class       : Trap Class for which to un-register the          */
/*                                     Trap Handler routine                             */
/*  Arguments (Out):    <none>                                                          */
/*  Arguments (InOut):  <none>                                                          */
/*  Return Value:       -TRAP_E_SUCCESS      : Trap Handler successfully un-registered  */
/*                      -TRAP_E_UNINIT       : The Trap Driver has not yet been         */
/*                                             initialized                              */
/*                      -TRAP_E_PARAM        : Invalid parameter supplied               */
/*                      -TRAP_E_NOT_EXISTS   : No Trap Handler was registered for the   */
/*                                             given Trap Class                         */
/*  Note(s):            <none>                                                          */
/*  Pre-Condition(s):   The Trap Driver must have been initialized before.              */
/*                       A Trap Handler must have been associated with the given Trap   */
/*                       Class.                                                         */
/*  Post-Condition(s):  The given Trap Handler routine will no longer be called         */
/*                      upon the arise of traps of the given Trap Class and a new       */
/*                      Trap Handler may be registered by calling                       */
/*                      TRAP_RegisterTrapHandler.                                       */
/*                                                                                      */
/****************************************************************************************/
TRAP_ErrorType TRAP_UnregisterTrapHandler(const uint8 class)
{
  TRAP_ErrorType    result = TRAP_E_SUCCESS;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & (uint8)0x3U);

  /* Check module initialization:                                                     */
  if (TMS_READY != trap_ModuleStatus[CoreId])
  {
    result = TRAP_E_UNINIT;
  }
  /* Parameter check:                                                                 */
  else if (class >= (uint8)TRAP_CLASS_COUNT_TOTAL)
  {
    result = TRAP_E_PARAM;
  }
  else if (NULL_PTR == trap_TrapHandlers[CoreId][class])
  {
    /* There is no Trap Handler associated with the given Trap Class:               */
    result = TRAP_E_NOT_EXISTS;
  }
  else
  {
    /* Delete the given Trap Handler from the local list:                           */
    trap_TrapHandlers[CoreId][class] = NULL_PTR;
  }

  return result;
}

/****************************************************************************************/
/*  Function:           TRAP_StartHandleTraps                                           */
/****************************************************************************************/
/*  Description:        Starts the processing of Traps by the STL by changing the Base  */
/*                       Trap Vector Table Pointer to point to a dedicated STL Trap     */
/*                       Vector Table.                                                  */
/*                                                                                      */
/*  Arguments (In):     <none>                                                          */
/*  Arguments (Out):    <none>                                                          */
/*  Arguments (InOut):  <none>                                                          */
/*  Return Value:       -TRAP_E_SUCCESS    : STL Trap Handling successfully enabled     */
/*                      -TRAP_E_UNINIT     : The Trap Driver has not yet been           */
/*                                              initialized                             */
/*                      -TRAP_E_SEQUENCE   : STL Trap Handling has already been turned  */
/*                                              on before                               */
/*  Note(s):            Only Traps for which an Trap Handler has been assigned by the   */
/*                      STL will be handled by the STL. All Traps that have no STL Trap */
/*                      Handler assigned, will be forwarded    to the applications Trap */
/*                      Handler.                                                        */
/*  Pre-Condition(s):   The Trap Driver must have been initialized before.              */
/*                       STL Trap Handling must not already have been activated.        */
/*  Post-Condition(s):  Traps with an Trap Handler registered by the STL will also be   */
/*                       handled by the STL and become invisible to the application.    */
/*                                                                                      */
/****************************************************************************************/
TRAP_ErrorType TRAP_StartHandleTraps(void)
{
  uint32            temp = 0U;
  TRAP_ErrorType    result = TRAP_E_SUCCESS;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & (uint8)0x3U);

  /* Check module initialization:                                                      */
  if (TMS_READY != trap_ModuleStatus[CoreId])
  {
    result = TRAP_E_UNINIT;
  }
  /* Check if the Trap Vector Table has already been switched to the STL's             */
  /* proprietary Trap Vector Table:                                                    */
  else if (NULL_PTR != trap_BtvBackup[CoreId])
  {
    result = TRAP_E_SEQUENCE;
  }
  else
  {
    /* Switch to dedicated Trap Vector Table:                                        */
    temp = (uint32)MFCR(CPU_BTV);
    trap_BtvBackup[CoreId] = (void*)temp;
    Mcal_ResetENDINIT();
    MTCR(CPU_BTV, (uint32)&Stl_TrapVectors);
    Mcal_SetENDINIT();
  }

  return result;
}

/****************************************************************************************/
/*  Function:           TRAP_StopHandleTraps                                            */
/****************************************************************************************/
/*  Description:        Stops Trap Handling by the STL. All future traps will again be  */
/*                      seen by the application.                                        */
/*                                                                                      */
/*  Arguments (In):     <none>                                                          */
/*  Arguments (Out):    <none>                                                          */
/*  Arguments (InOut):  <none>                                                          */
/*  Return Value:       -TRAP_E_SUCCESS     : STL Trap Handling successfully disabled   */
/*                      -TRAP_E_UNINIT      : The Trap Driver has not yet been          */
/*                                            initialized                               */
/*                      -TRAP_E_SEQUENCE    : STL Trap Handling has not been enabled    */
/*                                            before                                    */
/*  Note(s):            <none>                                                          */
/*  Pre-Condition(s):   The Trap Driver must have been initialized before.              */
/*                        STL Trap Handling must have been activated before.            */
/*  Post-Condition(s):  All Traps will again be received by the application.            */
/*                                                                                      */
/****************************************************************************************/
TRAP_ErrorType TRAP_StopHandleTraps(void)
{
  TRAP_ErrorType    result = TRAP_E_SUCCESS;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & (uint8)0x3U);

  /* Check module initialization:                                                     */
  if (TMS_READY != trap_ModuleStatus[CoreId])
  {
    result = TRAP_E_UNINIT;
  }
  /* Check if the Trap Vector Table has been switched to the STL's proprietary Trap   */
  /* Vector Table:                                                                    */
  else if (NULL_PTR == trap_BtvBackup[CoreId])
  {
    result = TRAP_E_SEQUENCE;
  }
  else
  {
    /* Switch back to the applications Trap Vector Table:                           */
    Mcal_ResetENDINIT();
    MTCR(CPU_BTV, (uint32)trap_BtvBackup[CoreId]);
    Mcal_SetENDINIT();
    trap_BtvBackup[CoreId] = NULL_PTR;
  }

  return result;
}

void* TRAP_GenericTrapHandler(uint32 trapClass, uint32 trapID)
{
  uint32                    pApplTrapVector = (uint32)NULL_PTR;
  StlTrap_LowerContext      *pLowerContext;
  uint32                    PCXICopy;
  uint16                    *pReturnAddress;
  uint8 CoreId;
  boolean                   ExpectedTrap;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & (uint8)0x3U);

  /* Jump to the applications Trap Vector, if the STL did not register a Trap Handler   */
  /* for the current Trap Class.                                                        */
  /* All class 3 traps except CDU trap are forwarded to the applications Trap Vector,   */
  /* regardless, whether there is a STL trap handler registered or not. This is done    */
  /* because for some class 3 traps, function calls are no longer possible.             */
  if ((NULL_PTR == trap_TrapHandlers[CoreId][trapClass]) ||
      ((TRAP_CLASS3 == trapClass) && (TRAP_ID3 != trapID)))
  {
    /* Calculate application Trap Vector address:                                     */
    pApplTrapVector = (uint32)trap_BtvBackup[CoreId];
    pApplTrapVector += 32U * trapClass;
    INVOKE_APPL_TRAP_HANDLER((void *)pApplTrapVector, trapID);
  }

  /* Call the STLs Trap Handler:                                                        */
  ExpectedTrap = (trap_TrapHandlers[CoreId][trapClass])(trapID);

  if (ExpectedTrap == (boolean)TRUE)
  {
    /* Patch return address to continue execution at the instruction following the       */
    /* one that raised the trap (only required for synchronous traps except FCD and      */
    /* SYS):                                                                             */
    if ( (0U == trapClass) ||
         (1U == trapClass) ||
         (2U == trapClass) ||
        ((3U == trapClass) && (1U != trapID)) ||
        ((4U == trapClass) && (trapID < 3U)) ||
        ((4U == trapClass) && (5U == trapID)) ||
         (5U == trapClass) )
    {
      /* Get the previous context information register:                                 */
      PCXICopy = (uint32)MFCR(CPU_PCXI);

      /* Get the address of the saved context in the CSA:                               */
      pLowerContext = (StlTrap_LowerContext*) (((PCXICopy & 0x000F0000U) << 12U) +
                                               ((PCXICopy & 0x0000FFFFU) <<  6U));

      /* Check whether the instruction causing the trap was 16 or 32bit and patch       */
      /* the return address to point to the instructions following:                     */
      pReturnAddress = (uint16*)pLowerContext->A11;
      if (((*pReturnAddress) & 0x0001U) == 0x0001U)
      {
        /* 32bit instruction:                                                           */
        pLowerContext->A11 += 4U;
      }
      else
      {
        /* 16bit instruction:                                                           */
        pLowerContext->A11 += 2U;
      }
    }

    /* Restore context and return from exception:                                       */
    {
      __asm("rslcx");
      __asm("rfe");
    }
  }
  else
  {
    /* Calculate application Trap Vector address:                                       */
    pApplTrapVector = (uint32)trap_BtvBackup[CoreId];
    pApplTrapVector += 32U * trapClass;
    INVOKE_APPL_TRAP_HANDLER((void *)pApplTrapVector, trapID);
  }

  return NULL_PTR;
}


#define IFX_GNRTRAPHANDLER_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
