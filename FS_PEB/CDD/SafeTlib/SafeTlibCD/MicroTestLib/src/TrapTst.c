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
**                                                                            **
**  $FILENAME   : TrapTst.c $                                                **
**                                                                            **
**  $CC VERSION : \main\71 $                                                 **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains the trap system test                    **
**                                                                            **
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_TrapTest                              **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "TrapTst.h"
#include "IfxScu_reg.h"
#include "IfxSmu_reg.h"
#include "Mtl_Trap.h"
#include "Mcal.h"
#include "IfxCpu_reg.h"
#include "Sl_Ipc.h"
#include "SmuInt.h"
#include "IfxCpu_bf.h"
#include "IfxXbar_reg.h"
#include "IfxSrc_reg.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/
#ifdef __TASKING__
  __asm("PSW .equ 0xFE04");
#endif /* __TASKING__ */

/* Address for unaligned data access:                                         */
#if (defined __TASKING__)  || (defined __GNUC__)
  #define TRT_UNALIGNED_ADDRESS                   ( (uint32)0xA0000123U )
#elif defined _DIABDATA_C_TRICORE_  
  #if (_DIABDATA_C_TRICORE_ == 1U)
    #define TRT_UNALIGNED_ADDRESS                   ( 0xA0000123 )    
  #endif /*  _DIABDATA_C_TRICORE_ == 1U 	*/  
#endif /* __TASKING__ OR __GNUC__	*/

/* Unmapped SRI-Address for generating a trap of class 4                      */
#define SRI_UNMAPPED_ADDR                       ((uint32)0xF8000400U )

/* Trap test does not support any configuration                               */
#define TRAPTST_CFG_PARAM_COUNT                 ( (uint32)(0))

/* Shared Resource Interconnect, bus error SMU alarm                          */
#define SMU_SRIBUS_ERR_ALM                      ( (uint32)1U << SMU_ALARM_30 )

/* Disable all NMI traps                                                      */
#define DISABLE_ALL_NMI_TRAPS                   ( 0x0000FFFFU )

/* Protocol error from default salve status in Arbiter Interrupt Status 
   Register                                                                   */
#define CLEAR_XBAR_INTSAT_PRSCID                ( (uint32)1U << 31U )

/* Clear SRI service request bit                                              */
#define TRAPTST_XBARSRC_MASK            ((unsigned_int)0x293F1CFFU)
#define TRAPTST_XBARSRC_CLEAR_BITS      ((unsigned_int)0x02000000U)

/* Clear interrupt acknowledge arbiter                                        */
#define CLEAR_XBAR_ARBCOND_INTACK       ((unsigned_int)( 0x10U ))

/* Expected trap classes and identification numbers:                          */
#define TRAP_TST_TRAP_CLASS_NONE                ( (uint32)0U )
#define TRAP_TST_TRAP_CLASS1                    ( (uint32)1U )
#define TRAP_TST_TRAP_CLASS2                    ( (uint32)2U )
#define TRAP_TST_TRAP_CLASS3                    ( (uint32)3U )
#define TRAP_TST_TRAP_CLASS4                    ( (uint32)4U )
#define TRAP_TST_TRAP_CLASS5                    ( (uint32)5U )
#define TRAP_TST_TRAP_CLASS6                    ( (uint32)6U )
#define TRAP_TST_TRAP_CLASS7                    ( (uint32)7U )
#define TRAP_TST_TRAP_ID_NONE                   ( (uint32)0U )
#define TRAP_TST_TRAP_ID1                       ( (uint32)1U )
#define TRAP_TST_TRAP_ID2                       ( (uint32)2U )
#define TRAP_TST_TRAP_ID3                       ( (uint32)3U )
#define TRAP_TST_TRAP_ID4                       ( (uint32)4U )
#define TRAP_TST_TRAP_ID6                       ( (uint32)6U )

/* Nr. of trap classes checked by the trap test:                              */
#define TRAP_TST_TRAP_CLASS_COUNT               ( (uint8)6U )


/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

typedef struct TrapTst_TrapCounters
{
  volatile uint8    Class1MpnTrap;
  volatile uint8    Class2AlnTrap;
  volatile uint8    Class3CduTrap;
  volatile uint8    Class4DseTrap;
  volatile uint8    Class5OvfTrap;
  volatile uint8    Class6SysTrap;
  volatile uint32   Crc;
} TrapTst_TrapCountersType;



/******************************************************************************
**                        Exported object definitions                         *
******************************************************************************/

/******************************************************************************
**                        Local object definitions                            *
******************************************************************************/
#define IFX_TRAPTST_START_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

static TrapTst_TrapCountersType TrapTst_lTrapCounters[MCAL_NO_OF_CORES];

#define IFX_TRAPTST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_TRAPTST_START_SEC_VAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"

static Smu_AlarmActionType SmuAlmAction_Ag3Alm30[MCAL_NO_OF_CORES];

#define IFX_TRAPTST_STOP_SEC_VAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"


#define IFX_TRAPTST_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

static uint32 TrapTst_lExpectedTrapClass[MCAL_NO_OF_CORES];
static uint32 TrapTst_lExpectedTrapId[MCAL_NO_OF_CORES];
static uint32 TrapTst_lTrapDisBackup;
static uint32 TrapTst_lRegisteredTrapClasses;

#define IFX_TRAPTST_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/******************************************************************************
**                        Imported function declarations                      *
******************************************************************************/

/******************************************************************************
**                        Local function prototypes                           *
******************************************************************************/
#define IFX_TRAPTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

static Sl_TstRsltType TrapTst_lInit
(
  void
);

static Sl_TstRsltType TrapTst_lRestore
(
  void
);

static Sl_TstRsltType TrapTst_lExecuteTest
(
  uint32* const TstSignature
);

static uint32 TrapTst_lCalcCounterCrc
(
  void
);

static boolean TrapTst_lClass1TrapHandler
(
  const uint32 TrapId
);

static boolean TrapTst_lClass2TrapHandler
(
  const uint32 TrapId
);

static boolean TrapTst_lClass3TrapHandler
(
  const uint32 TrapId
);

static boolean TrapTst_lClass4TrapHandler
(
  const uint32 TrapId
);

static boolean TrapTst_lClass5TrapHandler
(
  const uint32 TrapId
);

static boolean TrapTst_lClass6TrapHandler
(
  const uint32 TrapId
);

static void TrapTst_lClass1MpnTrap
(
  void
);

static void TrapTst_lClass2AlnTrap
(
  void
);
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
static void TrapTst_lClass2AlnTrapAsm
(
  void
);
#endif /*_DIABDATA_C_TRICORE_ == 1 	*/
#endif /*_DIABDATA_C_TRICORE_  		*/

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
/* if this test is inlined then it will not work with windriver, maybe optimization problem */
static void TrapTst_lClass3CduTrap (void) __attribute__((noinline));
#endif /*_DIABDATA_C_TRICORE_ == 1 	*/
#else
static void TrapTst_lClass3CduTrap
(
  void
);
#endif /*_DIABDATA_C_TRICORE_  		*/

static void TrapTst_lClass4DseTrap
(
  void
);

static void TrapTst_lClass5OvfTrap
(
  void
);

static void TrapTst_lClass6SysTrap
(
  void
);
#define IFX_TRAPTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/******************************************************************************
**                        Local object definitions                            *
******************************************************************************/

/* List of trap handlers; must be defined after forward declaration of the
 * trap handlers:
 */
#define IFX_TRAPTST_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
static const TRAP_TrapHandlerCbk
       TrapTst_kTrapHandlers[TRAP_TST_TRAP_CLASS_COUNT] =
{
  &TrapTst_lClass1TrapHandler,
  &TrapTst_lClass2TrapHandler,
  &TrapTst_lClass3TrapHandler,
  &TrapTst_lClass4TrapHandler,
  &TrapTst_lClass5TrapHandler,
  &TrapTst_lClass6TrapHandler
};
#define IFX_TRAPTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/******************************************************************************
**                    Local inline function definitions                       *
******************************************************************************/

/******************************************************************************
**                    Configuration error checking                            *
******************************************************************************/

/******************************************************************************
**                         Function definitions                               *
******************************************************************************/
#define IFX_TRAPTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType TrapTst_lInit                     **
**                    (void)                                                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function initializes global (file-scope) data      **
**                    used by the trap test and switches the BTV to a trap    **
**                    table dedicated to the trap test.                       **
*******************************************************************************/
static Sl_TstRsltType TrapTst_lInit
(void)
{
  Sl_TstRsltType  Result = TRAPTST_NOTEXECUTED;
  Sl_TstRsltType  TrapResult;
  uint8           CoreId;
  uint8           i;
  uint32          InitCrc;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* No trap expected, yet. Initialize expected trap class and ID:            */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS_NONE;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID_NONE;

  /* No trap handlers registered, yet: */
  TrapTst_lRegisteredTrapClasses = 0U;

  /* Initialize trap counters and Crc with zero                               */
  TrapTst_lTrapCounters[CoreId].Class1MpnTrap = 0U;
  TrapTst_lTrapCounters[CoreId].Class2AlnTrap = 0U;
  TrapTst_lTrapCounters[CoreId].Class3CduTrap = 0U;
  TrapTst_lTrapCounters[CoreId].Class4DseTrap = 0U;
  TrapTst_lTrapCounters[CoreId].Class5OvfTrap = 0U;
  TrapTst_lTrapCounters[CoreId].Class6SysTrap = 0U;
  TrapTst_lTrapCounters[CoreId].Crc = 0U;

  /* Update trap counter CRC protection                                       */
  TrapTst_lTrapCounters[CoreId].Crc = TrapTst_lCalcCounterCrc();

  /* Backup NMI trap disable register                                         */
  TrapTst_lTrapDisBackup = (uint32)SCU_TRAPDIS.U;

  Mcal_ResetENDINIT();

  /* Disable all NMI traps                                                    */
  SCU_TRAPDIS.U = DISABLE_ALL_NMI_TRAPS;

  Mcal_SetENDINIT();

  /* Register trap handlers for trap classes 1 to 6:                          */
  for (i = (uint8)0U; i < TRAP_TST_TRAP_CLASS_COUNT; i++)
  {
    TrapTst_lRegisteredTrapClasses = TRAP_TST_TRAP_CLASS1 + (uint32)i;
    TrapResult = TRAP_RegisterTrapHandler((uint8)TrapTst_lRegisteredTrapClasses,
                                          TrapTst_kTrapHandlers[i]);
    if (TRAP_E_SUCCESS != TrapResult)
    {
      TrapTst_lRegisteredTrapClasses--;
      Result = TRAPTST_TRAP_FAILURE;
      break;
    }
  }

  /* Check that trap counter CRC is correct                                   */
  if(TRAPTST_NOTEXECUTED == Result)
  {
    InitCrc = TrapTst_lTrapCounters[CoreId].Crc;
    if( TrapTst_lCalcCounterCrc() != InitCrc)
    {
      Result = TRAPTST_CRCMISMATCH;
    }
    else
    {
      Result = TRAPTST_SUCCESS;
    }
  }

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static uint32 TrapTst_lCalcCounterCrc                   **
**                    (void)                                                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Calculated counter CRC value (32bit value)              **
**                                                                            **
** Description      : TrapTst_lCalcCounterCrc calculates the CRC32 checksum   **
**                    over the first six data members of the global           **
**                    (file-scope) data structure TrapTst_lTrapCounters       **
**                    [CoreId].                                               **
**                    The result of this function corresponds to the          **
**                    expected value of TrapTst_lTrapCounters[CoreId].Crc.    **
*******************************************************************************/
static uint32 TrapTst_lCalcCounterCrc
(void)
{
  uint32 Crc = 0U;
  uint8 CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Calculate the CRC value over the TrapCounter members                     */

  Crc = (uint32)CRC32(     (uint32)TrapTst_lTrapCounters[CoreId].Class1MpnTrap,\
                           (uint32)TrapTst_lTrapCounters[CoreId].Class2AlnTrap);
  Crc = (uint32)CRC32(Crc, (uint32)TrapTst_lTrapCounters[CoreId].Class3CduTrap);
  Crc = (uint32)CRC32(Crc, (uint32)TrapTst_lTrapCounters[CoreId].Class4DseTrap);
  Crc = (uint32)CRC32(Crc, (uint32)TrapTst_lTrapCounters[CoreId].Class5OvfTrap);
  Crc = (uint32)CRC32(Crc, (uint32)TrapTst_lTrapCounters[CoreId].Class6SysTrap);

  return Crc;
}



/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType TrapTst_lRestore                  **
**                    (void)                                                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : TrapTst_lRestore restores the trap table to the         **
**                    original one before the trap test was called.           **
*******************************************************************************/
static Sl_TstRsltType TrapTst_lRestore
(void)
{
  Sl_TstRsltType  Result = TRAPTST_NOTEXECUTED;
  Sl_TstRsltType  TrapResult;
  uint8           i;

  /* Unregister all trap handlers registered in Init function:                */
  for (i = (uint8)TrapTst_lRegisteredTrapClasses; i > (uint8)0U; i--)
  {
    TrapResult = TRAP_UnregisterTrapHandler(i);
    if (TRAP_E_SUCCESS != TrapResult)
    {
      Result = TRAPTST_TRAP_FAILURE;
    }
  }

  Mcal_ResetENDINIT();

  /* Restore NMI trap disable register                                      */
  SCU_TRAPDIS.U = TrapTst_lTrapDisBackup;

  Mcal_SetENDINIT();

  /* clear Protocol error from default salve status in Arbiter Interrupt 
  Status Register                                                          */
  XBAR_INTSAT.U = CLEAR_XBAR_INTSAT_PRSCID;

  if (TRAPTST_NOTEXECUTED == Result)
  {
    Result = TRAPTST_SUCCESS;
  }

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static boolean TrapTst_lClass1TrapHandler               **
**                    (const uint32 TrapId)                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : TrapId: Trap identification number (TIN) of the trap    **
**                            that is to be processed.                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : TRUE, if trap was expected and handled, FALSE otherwise **
**                                                                            **
** Description      : In case of an expected class 1 trap (i.e. TIN = 6),     **
**                    TrapTst_lClass1TrapHandler increments                   **
**                    TrapTst_lTrapCounters.Class1MpnTrap unless it has       **
**                    reached its maximum value of 0xFF and integrity of      **
**                    expected traps is reflected in the trap counters.       **
**                    If indeed the trap is unexpected, an unhandled trap is  **
**                    indicated via return value.                             **
**                    The trap status is cleared. Finally updates the CRC of  **
**                    the trap counters.                                      **
**                                                                            **
*******************************************************************************/
static boolean TrapTst_lClass1TrapHandler
(
  const uint32 TrapId
)
{
  uint8   CoreId;
  boolean TrapExpected = (boolean)FALSE;
  uint32  InitCrc;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Check whether TIN = 6 and this trap is currently expected:               */
  if((TrapId == TRAP_TST_TRAP_ID6) &&
     (TrapTst_lExpectedTrapClass[CoreId] == TRAP_TST_TRAP_CLASS1) &&
     (TrapTst_lExpectedTrapId[CoreId] == TRAP_TST_TRAP_ID6))
  {
    TrapExpected = (boolean)TRUE;

    /* Clear expected trap class and ID:                                      */
    TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS_NONE;
    TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID_NONE;

    InitCrc = TrapTst_lTrapCounters[CoreId].Crc;
    if( TrapTst_lCalcCounterCrc() == InitCrc)
    {
      /* Prevents overflow to 0 which might lead to a wrong status            */
      if(TrapTst_lTrapCounters[CoreId].Class1MpnTrap < (uint8)0xFFU)
      {
        TrapTst_lTrapCounters[CoreId].Class1MpnTrap++;
        TrapTst_lTrapCounters[CoreId].Crc = TrapTst_lCalcCounterCrc();
      }
    }

    /* Clear DSTR. clears by a write independent of data value.               */
    MTCR(CPU_DSTR, 0x0U);
  }

  return TrapExpected;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static boolean TrapTst_lClass2TrapHandler               **
**                    (const uint32 TrapId)                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : TrapId: Trap identification number (TIN) of the trap    **
**                            that is to be processed.                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : TRUE, if trap was expected and handled, FALSE otherwise **
**                                                                            **
** Description      : In case of an expected class 2 trap (i.e. TIN = 4),     **
**                    TrapTst_lClass2TrapHandler increments                   **
**                    TrapTst_lTrapCounters.Class2AlnTrap unless it has       **
**                    reached its maximum value of 0xFF and integrity of      **
**                    expected traps is reflected in the trap counters.       **
**                    If indeed the trap is unexpected, an unhandled trap is  **
**                    indicated via return value. The trap status is cleared. **
**                    Finally updates the CRC of the trap counters.           **
**                                                                            **
*******************************************************************************/
static boolean TrapTst_lClass2TrapHandler
(
  const uint32 TrapId
)
{
  uint8   CoreId;
  boolean TrapExpected = (boolean)FALSE;
  uint32  InitCrc;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Check whether TIN = 4 and this trap is currently expected:               */
  if((TrapId == TRAP_TST_TRAP_ID4) &&
     (TrapTst_lExpectedTrapClass[CoreId] == TRAP_TST_TRAP_CLASS2) &&
     (TrapTst_lExpectedTrapId[CoreId] == TRAP_TST_TRAP_ID4))
  {
    TrapExpected = (boolean)TRUE;

    /* Clear expected trap class and ID:                                      */
    TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS_NONE;
    TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID_NONE;

    InitCrc = TrapTst_lTrapCounters[CoreId].Crc;
    if( TrapTst_lCalcCounterCrc() == InitCrc)
    {
      /* Prevents overflow to 0 which might lead to a wrong status            */
      if(TrapTst_lTrapCounters[CoreId].Class2AlnTrap < (uint8)0xFFU)
      {
        TrapTst_lTrapCounters[CoreId].Class2AlnTrap++;
        TrapTst_lTrapCounters[CoreId].Crc = TrapTst_lCalcCounterCrc();
      }
    }

    /* Clear DSTR. clears by a write independent of data value.               */
    MTCR(CPU_DSTR, 0x0U);
  }

  return TrapExpected;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static boolean TrapTst_lClass3TrapHandler               **
**                    (const uint32 TrapId)                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : TrapId: Trap identification number (TIN) of the trap    **
**                            that is to be processed.                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : TRUE, if trap was expected and handled, FALSE otherwise **
**                                                                            **
** Description      : In case of an expected class 3 trap (i.e. TIN = 3),     **
**                    TrapTst_lClass3TrapHandler increments                   **
**                    TrapTst_lTrapCounters.Class3CduTrap unless it has       **
**                    reached its maximum value of 0xFF and integrity of      **
**                    expected traps is reflected in the trap counters.       **
**                    If indeed the trap is unexpected,                       **
**                    TrapTst_lClass3TrapHandler indicates an unhandled trap  **
**                    via return value. Finally updates the CRC of the trap   **
**                    counters. A call depth underflow does not necessarily   **
**                    reflect a software error in the currently executing     **
**                    task.                                                   **
**                                                                            **
*******************************************************************************/
static boolean TrapTst_lClass3TrapHandler
(
  const uint32 TrapId
)
{
  uint8   CoreId;
  boolean TrapExpected = (boolean)FALSE;
  uint32   InitCrc;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Check whether TIN = 3 and this trap is currently expected:               */
  if((TrapId == TRAP_TST_TRAP_ID3) &&
     (TrapTst_lExpectedTrapClass[CoreId] == TRAP_TST_TRAP_CLASS3) &&
     (TrapTst_lExpectedTrapId[CoreId] == TRAP_TST_TRAP_ID3))
  {
    TrapExpected = (boolean)TRUE;

    /* Clear expected trap class and ID:                                      */
    TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS_NONE;
    TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID_NONE;

    InitCrc = TrapTst_lTrapCounters[CoreId].Crc;
    if( TrapTst_lCalcCounterCrc() == InitCrc)
    {
      /* Prevents overflow to 0 which might lead to a wrong status            */
      if(TrapTst_lTrapCounters[CoreId].Class3CduTrap < (uint8)0xFFU)
      {
        TrapTst_lTrapCounters[CoreId].Class3CduTrap++;
        TrapTst_lTrapCounters[CoreId].Crc = TrapTst_lCalcCounterCrc();
      }
    }
  }

  return TrapExpected;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static boolean TrapTst_lClass4TrapHandler               **
**                    (const uint32 TrapId)                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : TrapId: Trap identification number (TIN) of the trap    **
**                            that is to be processed.                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : TRUE, if trap was expected and handled, FALSE otherwise **
**                                                                            **
** Description      : In case of an expected class 4 trap (i.e. TIN = 2),     **
**                    TrapTst_lClass4TrapHandler increments                   **
**                    TrapTst_lTrapCounters.Class4DseTrap unless it has       **
**                    reached its maximum value of 0xFF and integrity of      **
**                    expected traps is reflected in the trap counters.       **
**                    The trap status is cleared. Finally updates the CRC of  **
**                    the trap counters and returns from the trap. The        **
**                    reserved address 0xF8000400 is used to for HW Data      **
**                    Access Synchronous Error trap.                          **
**                                                                            **
*******************************************************************************/
static boolean TrapTst_lClass4TrapHandler
(
  const uint32 TrapId
)
{
  uint8   CoreId;
  boolean TrapExpected = (boolean)FALSE;
  uint32   InitCrc;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Check whether TIN = 2 and this trap is currently expected:               */
  if((TrapId == TRAP_TST_TRAP_ID2) &&
     (TrapTst_lExpectedTrapClass[CoreId] == TRAP_TST_TRAP_CLASS4) &&
     (TrapTst_lExpectedTrapId[CoreId] == TRAP_TST_TRAP_ID2))
  {
    TrapExpected = (boolean)TRUE;

    /* Clear expected trap class and ID:                                      */
    TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS_NONE;
    TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID_NONE;

    InitCrc = TrapTst_lTrapCounters[CoreId].Crc;
    if( TrapTst_lCalcCounterCrc() == InitCrc)
    {
      /* Prevents overflow to 0 which might lead to a wrong status            */
      if(TrapTst_lTrapCounters[CoreId].Class4DseTrap < (uint8)0xFFU)
      {
        TrapTst_lTrapCounters[CoreId].Class4DseTrap++;
        TrapTst_lTrapCounters[CoreId].Crc = TrapTst_lCalcCounterCrc();
      }
    }

    /* Clear DSTR. clears by a write independent of data value.               */
    MTCR(CPU_DSTR, 0x0U);
    
    /* Clear SRI service request                                              */
    SRC_XBARSRC.U = ((SRC_XBARSRC.U & TRAPTST_XBARSRC_MASK) | (TRAPTST_XBARSRC_CLEAR_BITS));

    /* Clear interrupt acknowledge arbiter                                    */
    XBAR_ARBCOND.U |= CLEAR_XBAR_ARBCOND_INTACK;
  }

  return TrapExpected;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static boolean TrapTst_lClass5TrapHandler               **
**                    (const uint32 TrapId)                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : TrapId: Trap identification number (TIN) of the trap    **
**                            that is to be processed.                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : TRUE, if trap was expected and handled, FALSE otherwise **
**                                                                            **
** Description      : In case of an expected class 5 trap (i.e. TIN = 1),     **
**                    TrapTst_lClass5TrapHandler increments                   **
**                    TrapTst_lTrapCounters.Class5OvfTrap unless it has       **
**                    reached its maximum value of 0xFF and integrity of      **
**                    expected traps is reflected in the trap counters. If    **
**                    indeed the trap is unexpected,                          **
**                    TrapTst_lClass5TrapHandler indicates an unhandled trap  **
**                    via return value.                                       **
**                                                                            **
*******************************************************************************/
static boolean TrapTst_lClass5TrapHandler
(
  const uint32 TrapId
)
{
  uint8   CoreId;
  boolean TrapExpected = (boolean)FALSE;
  uint32   InitCrc;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Check whether TIN = 1 and this trap is currently expected:               */
  if((TrapId == TRAP_TST_TRAP_ID1) &&
     (TrapTst_lExpectedTrapClass[CoreId] == TRAP_TST_TRAP_CLASS5) &&
     (TrapTst_lExpectedTrapId[CoreId] == TRAP_TST_TRAP_ID1))
  {
    TrapExpected = (boolean)TRUE;

    /* Clear expected trap class and ID:                                      */
    TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS_NONE;
    TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID_NONE;

    InitCrc = TrapTst_lTrapCounters[CoreId].Crc;
    if( TrapTst_lCalcCounterCrc() == InitCrc)
    {
      /* Prevents overflow to 0 which might lead to a wrong status            */
      if(TrapTst_lTrapCounters[CoreId].Class5OvfTrap < (uint8)0xFFU)
      {
        TrapTst_lTrapCounters[CoreId].Class5OvfTrap++;
        TrapTst_lTrapCounters[CoreId].Crc = TrapTst_lCalcCounterCrc();
      }
    }
  }

  return TrapExpected;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static boolean TrapTst_lClass6TrapHandler               **
**                    (const uint32 TrapId)                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : TrapId: Trap identification number (TIN) of the trap    **
**                            that is to be processed.                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : TRUE, if trap was expected and handled, FALSE otherwise **
**                                                                            **
** Description      : In case of an expected class 6 trap (i.e. TIN = 1),     **
**                    TrapTst_lClass6TrapHandler increments                   **
**                    TrapTst_lTrapCounters.Class6SysTrap unless it has       **
**                    reached its maximum value of 0xFF and integrity of      **
**                    expected traps is reflected in the trap counters. If    **
**                    indeed the trap is unexpected,                          **
**                    TrapTst_lClass6TrapHandler indicates an unhandled trap  **
**                    via return value.                                       **
**                                                                            **
*******************************************************************************/
static boolean TrapTst_lClass6TrapHandler
(
  const uint32 TrapId
)
{
  uint8   CoreId;
  boolean TrapExpected = (boolean)FALSE;
  uint32   InitCrc;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Check whether TIN = 1 and this trap is currently expected:               */
  if((TrapId == TRAP_TST_TRAP_ID1) &&
     (TrapTst_lExpectedTrapClass[CoreId] == TRAP_TST_TRAP_CLASS6) &&
     (TrapTst_lExpectedTrapId[CoreId] == TRAP_TST_TRAP_ID1))
  {
    TrapExpected = (boolean)TRUE;

    /* Clear expected trap class and ID:                                      */
    TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS_NONE;
    TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID_NONE;

    InitCrc = TrapTst_lTrapCounters[CoreId].Crc;
    if( TrapTst_lCalcCounterCrc() == InitCrc)
    {
      /* Prevents overflow to 0 which might lead to a wrong status            */
      if(TrapTst_lTrapCounters[CoreId].Class6SysTrap < (uint8)0xFFU)
      {
        TrapTst_lTrapCounters[CoreId].Class6SysTrap++;
        TrapTst_lTrapCounters[CoreId].Crc = TrapTst_lCalcCounterCrc();
      }
    }
  }

  return TrapExpected;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void TrapTst_lClass1MpnTrap                      **
**                    (void)                                                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : TrapTst_lClass1MpnTrap provokes a class 1, Memory       **
**                    Protection Null Address trap by trying to load a 32bit  **
**                    word from effective address zero.                       **
*******************************************************************************/
static void TrapTst_lClass1MpnTrap
(void)
{
  /* Attention: Must be volatile because otherwise it will be removed due to
     optimization                                                             */
  volatile uint32 dummy = 0U;
  const uint32*   ptr_Address = 0U;
  uint8           CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Set expected trap class and ID: */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS1;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID6;

  /* Read from effective address zero                                         */
  dummy = *ptr_Address;
  /* Required to avoid compiler warning                                       */
  UNUSED_PARAMETER(dummy)
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void TrapTst_lClass2AlnTrap                      **
**                    (void)                                                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : TrapTst_lClass2AlnTrap provokes a class 2, Data Address **
**                    Alignment trap by trying to load a 32bit word from an   **
**                    address aligned to an odd address using a               **
**                    LD.W instruction.                                       **
*******************************************************************************/
#ifdef __TASKING__
static void TrapTst_lClass2AlnTrap
(void)
{
  uint8 CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Set expected trap class and ID: */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS2;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID4;

  {
    __asm(" ld.w    d15,[%0] \n"
          : : "a"(TRT_UNALIGNED_ADDRESS) : "d15");  /* make memory access    */
  }
}  
#endif /* __TASKING__ */

#ifdef __GNUC__
static void TrapTst_lClass2AlnTrap
(void)
{
  uint8           CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Set expected trap class and ID: */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS2;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID4;

  {
    __asm(" ld.w    %%d15,[%0] \n"
          : : "a"(TRT_UNALIGNED_ADDRESS) : "d15");  /* make memory access    */
  }
}
#endif/* __GNU__ */

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
void TrapTst_lClass2AlnTrap(void)
{
  uint8           CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Set expected trap class and ID: */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS2;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID4;

  TrapTst_lClass2AlnTrapAsm();
}
asm void TrapTst_lClass2AlnTrapAsm(void)
{
$$bp
! "%a15", "%d15"
  movh.a %a15,TRT_UNALIGNED_ADDRESS@ha
  lea    %a15,[%a15]TRT_UNALIGNED_ADDRESS@l
  ld.w   %d15,[%a15]
$$ep
}
#endif /*_DIABDATA_C_TRICORE_ == 1 	*/
#endif /* _DIABDATA_C_TRICORE_ 		*/

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void TrapTst_lClass3CduTrap                      **
**                    (void)                                                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : TrapTst_lClass3CduTrap provokes a class 3, Call Depth   **
**                    Underflow trap by setting PSW.CDC to zero and trying to **
**                    execute a return instruction afterwards.                **
*******************************************************************************/
#ifdef __TASKING__
static void TrapTst_lClass3CduTrap
(void)
{
  uint8           CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Set expected trap class and ID: */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS3;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID3;

  {
    __asm(" mfcr       d15, #PSW  \n"    /* Backup PSW to d15                 */
          " mov        d9, d15    \n"    /* Copy PSW to d9                    */

          " mov        d8, #0x80  \n"    /* d8 = 0x00000080                   */
          " or         d9, d9, d8 \n"    /* Set CDE = 1;                      */
          " mtcr       #PSW, d9   \n"    /* Store updated CDE to PSW          */
          " isync                 \n"

          " mov        d9, d15    \n"    /* Copy PSW to d9                    */

          " mov        d8, #0x7F  \n"    /* d8 = 0x0000007F                   */
          " not        d8         \n"    /* d8 = 0xFFFFFF80                   */
          " and        d9, d9, d8 \n"    /* Set CDC = 0 (6-bit counter;       */
                                         /* CDC.COUNT = 0)                    */
          " mtcr       #PSW, d9   \n"    /* Store updated CDC to PSW          */
          " isync                 \n"

          " ret                   \n"    /* This instruction will trap        */
                                         /* because CDC = 0                   */

          /* The trap handler will continue execution at the instruction      */
          /* following the one that raised the trap:                          */

          " mtcr    #PSW, d15     \n"    /* Restore original PSW content      */
          " isync                 \n"
          : : : "d8", "d9", "d15");
  }
}
#endif /* __TASKING__ */

#ifdef __GNUC__
static void TrapTst_lClass3CduTrap
(void)
{
  uint8           CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Set expected trap class and ID: */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS3;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID3;

  {
    __asm(" mfcr       %%d15, $psw     \n"    /* Backup PSW to d15            */
          " mov        %%d9, %%d15    \n"     /* Copy PSW to d9               */

          " mov        %%d8, 0x80  \n"        /* d8 = 0x00000080              */
          " or         %%d9, %%d9, %%d8 \n"   /* Set CDE = 1;                 */

          " mtcr       $psw, %%d9   \n"       /* Store updated CDE to PSW     */
          " isync                 \n"

          " mov        %%d9, %%d15    \n"     /* Copy PSW to d9               */

          " mov        %%d8, 0x7F  \n"        /* d8 = 0x0000007F              */
          " not        %%d8         \n"       /* d8 = 0xFFFFFF80              */
          " and        %%d9, %%d9, %%d8 \n"   /* Set CDC = 0 (6-bit counter;  */
                                              /* CDC.COUNT = 0)               */
          " mtcr       $psw, %%d9   \n"       /* Store updated CDC to PSW     */
          " isync                 \n"

          " ret                   \n"         /* This instruction will trap   */
                                              /*  because CDC = 0             */

          /* The trap handler will continue execution at the instruction      */
          /* following the one that raised the trap:                          */

          " mtcr    $psw, %%d15     \n"    /* Restore original PSW content    */
          " isync                 \n"
          : : : "d8", "d9", "d15");
  }
}
#endif /* __GNUC__ */

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
static void TrapTst_lClass3CduTrap(void)
{
  uint8           CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Set expected trap class and ID: */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS3;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID3;

  {    
    __asm("mfcr    %d15, $psw");
    __asm("mov     %d9, %d15");
    __asm("mov     %d8, 0x80");
    __asm("or      %d9, %d9, %d8");
    __asm("mtcr    $psw, %d9");
    __asm("isync");
    __asm("mov     %d9, %d15");
    __asm("mov     %d8, 0x7F");
    __asm("not     %d8");
    __asm("and     %d9, %d9, %d8");
    __asm("mtcr    $psw, %d9");
    __asm("isync");
    __asm("ret");         /* This instruction will trap     */
                          /*  because CDC = 0               */
    __asm("mtcr   $psw, %d15");
    __asm("isync");
    __asm("ret");
  }
}
#endif /* _DIABDATA_C_TRICORE_ == 1	*/
#endif /* _DIABDATA_C_TRICORE_ 		*/


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void TrapTst_lClass4DseTrap                      **
**                    (void)                                                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : TrapTst_lClass4DseTrap provokes a class 4, Data Access  **
**                    Synchronous Error trap by performing a read access to   **
**                    an unmapped address via the SRI bus.                    **
*******************************************************************************/

static void TrapTst_lClass4DseTrap
(void)
{
  volatile uint32*    pTestAddr32;
  volatile uint32     testData = (uint32)0U;
  uint8               CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Set expected trap class and ID: */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS4;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID2;

  /* Make read access to an unmapped SRI address:                       */
  pTestAddr32 = (volatile uint32*)SRI_UNMAPPED_ADDR;
  testData = (uint32)*pTestAddr32;

  /* Required to avoid compiler warning                                 */
  UNUSED_PARAMETER(testData)

}


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void TrapTst_lClass5OvfTrap                      **
**                    (void)                                                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : TrapTst_lClass5OvfTrap provokes a class 5, Arithmetic   **
**                    Overflow trap by setting the PSW.V bit and executing a  **
**                    Trap On Overflow (TRAPV) instruction.                   **
*******************************************************************************/
#ifdef __TASKING__
static void TrapTst_lClass5OvfTrap
(void)
{
  uint8           CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Set expected trap class and ID: */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS5;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID1;

  {
    __asm(" mfcr    d15, #PSW            \n"    /* Load PSW                   */
          " insert  d15, d15, #1, #30, #1\n"    /* Set PSW.V bit              */
          " mtcr    #PSW, d15            \n"
          " isync                        \n"
          " trapv                        \n"    /* Trap on Overflow           */
          : : : "d15");
  }
}
#endif /* __TASKING__ */

#ifdef __GNUC__
static void TrapTst_lClass5OvfTrap
(void)
{
  uint8           CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Set expected trap class and ID: */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS5;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID1;

  {
    __asm(" mfcr    %%d15, $psw           \n"
          " insert  %%d15, %%d15, 1, 30, 1\n"    /* Set $psw.V bit            */
          " mtcr    $psw, %%d15           \n"
          " isync                         \n"
          " trapv                         \n"   /* Trap on Overflow           */
          : : : "d15");
  }
}
#endif /* __GNUC__ */

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
static void TrapTst_lClass5OvfTrap
(void)
{
  uint8           CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Set expected trap class and ID: */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS5;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID1;

  {
    __asm(" mfcr    %d15, $psw           \n"
          " insert  %d15, %d15, 1, 30, 1 \n"   /* Set $psw.V bit              */
          " mtcr    $psw, %d15           \n"
          " isync                        \n"
          " trapv                        \n"   /* Trap on Overflow            */
          /*: : : "d15" */);
  }
}
#endif /* _DIABDATA_C_TRICORE_ == 1 */
#endif /* _DIABDATA_C_TRICORE_ 		*/


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void TrapTst_lClass6SysTrap                      **
**                    (void)                                                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : TrapTst_lClass6SysTrap provokes a class 6, System Call  **
**                    trap by executing a SYSCALL instruction.                **
*******************************************************************************/
static void TrapTst_lClass6SysTrap
(void)
{
  uint8           CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Set expected trap class and ID: */
  TrapTst_lExpectedTrapClass[CoreId] = TRAP_TST_TRAP_CLASS6;
  TrapTst_lExpectedTrapId[CoreId] = TRAP_TST_TRAP_ID1;

  SYSCALL(1);
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType TrapTst_TrapTst                   **
**                                      (const Sl_ParamSetType ParamSetIndex, **
**                                       uint32* const TstSignature);         **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in) :  ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution.                                **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value     : TRAPTST_SUCCESS - Test succeeded                        **
**                    TRAPTST_INVPARAM - Test failed because an invalid       **
**                    parameter was supplied.                                 **
**                    TRAPTST_CRCMISMATCH - The data of the global trap       **
**                    counter structure is inconsistent.                      **
**                    TRAPTST_SMU_STATEERR - Test failed because SMU is not   **
**                    in RUN state.                                           **
**                    TRAPTST_ERROR_CLASS1 - Test failed due to an unexpected **
**                    number of class 1, Memory Protection Null Address traps **
**                    encountered during the test                             **
**                    TRAPTST_ERROR_CLASS2 Test failed due to an unexpected   **
**                    number of class 2, Data Address Alignment traps         **
**                    encountered during the test                             **
**                    TRAPTST_ERROR_CLASS3 - Test failed due to an unexpected **
**                    number of class 3, Call Depth Counter Underflow traps   **
**                    encountered during the test                             **
**                    TRAPTST_ERROR_CLASS4 - Test failed due to an unexpected **
**                    number of class 4, Data Access Synchronous Error traps  **
**                    encountered during the test                             **
**                    TRAPTST_ERROR_CLASS5 Test failed due to an unexpected   **
**                    number of class 5, Arithmetic Overflow traps            **
**                    encountered during the test                             **
**                    TRAPTST_ERROR_CLASS6 - Test failed due to an unexpected **
**                    number of class 6, System Call (TIN = 1) traps          **
**                    encountered during the test                             **
**                    TRAPTST_TRAP_FAILURE - Registering or unregistering a   **
**                    trap handler failed                                     **
**                    TRAPTST_NOTEXECUTED - This error should never be        **
**                    returned. If it is returned anyhow, this indicates a    **
**                    severe malfunction of program execution.                **
**                    TRAPTST_TIMEOUT_RESOURCE - Acquiring exclusive access to**
**                    a shared resource timed out.                            **
**                    TRAPTST_SMU_GETALMACTIONERR - The test failed because   **
**                    setting an SMU alarm action failed.                     **
**                    TRAPTST_SMU_GETALMSTSERR - The test failed because      **
**                    getting the alarm status failed.                        **
**                    TRAPTST_SMU_SETALMACTIONERR - The test failed because   **
**                    setting an SMU alarm action failed.                     **
**                    TRAPTST_SMU_ALMSTSERR - The test failed because there is**
**                    already an SMU alarm present.                           **
**                    TRAPTST_SMU_CLRALMSTSERR - The test failed because      **
**                    clearing the SMU alarm failed.                          **
**                                                                            **
** Description      : TrapTst_TrapTest is the one and only API provided by    **
**                    the trap test. It calls the test initialization         **
**                    function for setting up a dedicated BTV, then triggers  **
**                    one trap out of each trap class that is to be tested,   **
**                    checks that each expected trap was generated exactly    **
**                    once and finally restores the BTV by calling the test   **
**                    restoration function.                                   **
*******************************************************************************/
Sl_TstRsltType TrapTst_TrapTst(const Sl_ParamSetType ParamSetIndex,
                               const uint8 TstSeed,
                               uint32* const TstSignature)

{
  Sl_TstRsltType      Result    = TRAPTST_NOTEXECUTED;
  Sl_TstRsltType      ResultInitExecute = TRAPTST_NOTEXECUTED;
  Sl_TstRsltType      ResultRestore = TRAPTST_NOTEXECUTED;

  /* Disable Interrupts                                                       */
  Mcal_SuspendAllInterrupts();

  /* Initialize Test Signature:                                               */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_TRAP_TST, (uint32)TstSeed);

    /* Validate the configuration parameter */
  if(ParamSetIndex > TRAPTST_CFG_PARAM_COUNT)
  {
    Result = TRAPTST_INVPARAM;
  }
  else /* Valid configuration parameter */
  {
    /* Check if the SMU is in RUN state. Otherwise report failure  */
    if (SMU_RUN_STATE == Smu_GetSmuState())
    {
      /* Clear DSTR. clears by a write independent of data value.             */
      MTCR(CPU_DSTR, 0x0U);

      /* Test initialization:                                                 */
      ResultInitExecute = TrapTst_lInit();

      if(TRAPTST_SUCCESS == ResultInitExecute)
      {/* Test execution                                                      */
        ResultInitExecute = TrapTst_lExecuteTest(TstSignature);
      }
      /* Test restore                                                         */
      ResultRestore = TrapTst_lRestore();

      if(TRAPTST_SUCCESS == ResultInitExecute)
      {
        if(TRAPTST_SUCCESS == ResultRestore)
        {
          Result = TRAPTST_SUCCESS;
        }
        else
        {
          Result = ResultRestore ;
        }
      }
      else
      {
        Result = ResultInitExecute ;
      }
    }
    else
    {
      Result = TRAPTST_SMU_STATEERR;
    }
  }

  *TstSignature = (uint32)CRC32(*TstSignature, Result);

  Mcal_ResumeAllInterrupts();

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType TrapTst_lExecuteTest              **
**                                       uint32* const TstSignature);         **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in) :  ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution.                                **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value     : TRAPTST_SUCCESS - Test succeeded                        **
**                    TRAPTST_ERROR_CLASS1 - Test failed due to an unexpected **
**                    number of class 1, Memory Protection Null Address traps **
**                    encountered during the test                             **
**                    TRAPTST_ERROR_CLASS2 Test failed due to an unexpected   **
**                    number of class 2, Data Address Alignment traps         **
**                    encountered during the test                             **
**                    TRAPTST_ERROR_CLASS3 - Test failed due to an unexpected **
**                    number of class 3, Call Depth Counter Underflow traps   **
**                    encountered during the test                             **
**                    TRAPTST_ERROR_CLASS4 - Test failed due to an unexpected **
**                    number of class 4, Data Access Synchronous Error traps  **
**                    encountered during the test                             **
**                    TRAPTST_ERROR_CLASS5 Test failed due to an unexpected   **
**                    number of class 5, Arithmetic Overflow traps            **
**                    encountered during the test                             **
**                    TRAPTST_ERROR_CLASS6 - Test failed due to an unexpected **
**                    number of class 6, System Call (TIN = 1) traps          **
**                    encountered during the test                             **
**                    TRAPTST_NOTEXECUTED - This error should never be        **
**                    returned. If it is returned anyhow, this indicates a    **
**                    severe malfunction of program execution.                **
**                    TRAPTST_TIMEOUT_RESOURCE - Acquiring exclusive access to**
**                    a shared resource timed out.                            **
**                    TRAPTST_SMU_GETALMACTIONERR - The test failed because   **
**                    setting an SMU alarm action failed.                     **
**                    TRAPTST_SMU_GETALMSTSERR - The test failed because      **
**                    getting the alarm status failed.                        **
**                    TRAPTST_SMU_SETALMACTIONERR - The test failed because   **
**                    setting an SMU alarm action failed.                     **
**                    TRAPTST_SMU_ALMSTSERR - The test failed because there is**
**                    already an SMU alarm present.                           **
**                    TRAPTST_SMU_CLRALMSTSERR - The test failed because      **
**                    clearing the SMU alarm failed.                          **
**                                                                            **
** Description      : TrapTst_lExecuteTest triggers one trap out of each trap **
**                    class that is to be tested and checks that each expected**
**                    trap was generated exactly once.                        **
**                    If SMU alarm (Group 3 Alarm 30) is already set the test **
**                    will fail and error is reported.                        **
*******************************************************************************/

static Sl_TstRsltType TrapTst_lExecuteTest
(
  uint32* const TstSignature
)
{
  Sl_TstRsltType      Result = TRAPTST_NOTEXECUTED;
  Sl_TstRsltType      SmuResult = TRAPTST_NOTEXECUTED;
  uint32 AlarmStatus[MCAL_NO_OF_CORES] = {0U};
  /* Fsp action will not be overwritten and hence doesn't need to be saved    */
  Smu_FSPActionType FspDummy;
  uint8 CoreId;
  uint32 InitCrc;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  TrapTst_lClass1MpnTrap();
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)TrapTst_lTrapCounters[CoreId].Class1MpnTrap);
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)TrapTst_lTrapCounters[CoreId].Crc);
  if(TrapTst_lTrapCounters[CoreId].Class1MpnTrap != 1U)
  {
    Result = TRAPTST_ERROR_CLASS1;
  }
  else
  {
    TrapTst_lClass2AlnTrap();
    *TstSignature = (uint32)CRC32(*TstSignature, (uint32)TrapTst_lTrapCounters[CoreId].Class2AlnTrap);
    *TstSignature = (uint32)CRC32(*TstSignature, (uint32)TrapTst_lTrapCounters[CoreId].Crc);
    if(TrapTst_lTrapCounters[CoreId].Class2AlnTrap != 1U)
    {
      Result = TRAPTST_ERROR_CLASS2;
    }
    else
    { /* A call depth underflow does not necessarily reflect a software error
       * in the currently executing task. An OS should maintain software
       * counter for the current task on each call underflow trap. A program
       * error would be indicated based on the software counter.              */

      TrapTst_lClass3CduTrap();
      *TstSignature = (uint32)CRC32(*TstSignature, (uint32)TrapTst_lTrapCounters[CoreId].Class3CduTrap);
      *TstSignature = (uint32)CRC32(*TstSignature, (uint32)TrapTst_lTrapCounters[CoreId].Crc);
      if(TrapTst_lTrapCounters[CoreId].Class3CduTrap != 1U)
      {
        Result = TRAPTST_ERROR_CLASS3;
      }
      else
      {
        if(E_OK == Sl_GetSpinLock(SL_SMUALRMGRP3_BIT30_SPNLCK_ID, SL_SMUALRMGRP3_BIT30_TIMEOUT))
        {
          /* Back up of SMU alarms action which is used for TrapTst AG3[30]           */
          if(E_OK != (Smu_GetAlarmAction(
                        SMU_ALARM_GROUP3, SMU_ALARM_30,\
                        &SmuAlmAction_Ag3Alm30[CoreId], \
                        &FspDummy  \
                    ))
            )
          {
            SmuResult = TRAPTST_SMU_GETALMACTIONERR;
          }
          else
          {
            /* Check Shared Resource Interconnect, bus error SMU alarm already set    */
            if(E_OK != (Smu_GetAlarmStatus(SMU_ALARM_GROUP3, &AlarmStatus[CoreId])))
            {
              SmuResult = TRAPTST_SMU_GETALMSTSERR;
            }
            else
            {
              if((AlarmStatus[CoreId] & SMU_SRIBUS_ERR_ALM) == 0U)
              {
                if(E_OK != (Smu_SetAlarmAction(SMU_ALARM_GROUP3, SMU_ALARM_30,\
                    SMU_ALARM_ACTION_NONE)))

                {
                  SmuResult = TRAPTST_SMU_SETALMACTIONERR;
                }
                else
                {
                  /*
                  * Reserved address 0xF8000400 is used to for HW Data Access
                  * Synchronous Error trap(Trap class 4, TIN 2).            */
                  TrapTst_lClass4DseTrap();
                }
              }
              else
              {
                SmuResult = TRAPTST_SMU_ALMSTSERR;
              }
            }
          }

          if(E_OK != (Smu_ClearAlarmStatus(SMU_ALARM_GROUP3, SMU_ALARM_30)))
          {
             SmuResult = TRAPTST_SMU_CLRALMSTSERR;
          }
          else
          {
            if(E_OK != Smu_SetAlarmAction(SMU_ALARM_GROUP3, SMU_ALARM_30,
                   SmuAlmAction_Ag3Alm30[CoreId]))
            {
              SmuResult = TRAPTST_SMU_SETALMACTIONERR;
            }
          }

          /* Release spinlock for SMU alarms                                        */
          Sl_ReleaseSpinLock(SL_SMUALRMGRP3_BIT30_SPNLCK_ID);
        }
        else
        {
          Result = TRAPTST_TIMEOUT_RESOURCE;
        }

        if(TRAPTST_NOTEXECUTED == SmuResult)
        {
          if(TRAPTST_NOTEXECUTED == Result)
          {
            *TstSignature = (uint32)CRC32(*TstSignature,(uint32) TrapTst_lTrapCounters[CoreId].Class4DseTrap);
            *TstSignature = (uint32)CRC32(*TstSignature, (uint32)TrapTst_lTrapCounters[CoreId].Crc);
            if(TrapTst_lTrapCounters[CoreId].Class4DseTrap != 1U)
            {
              Result = TRAPTST_ERROR_CLASS4;
            }
            else
            {
              TrapTst_lClass5OvfTrap();
              *TstSignature = (uint32)CRC32(*TstSignature,(uint32)TrapTst_lTrapCounters[CoreId].Class5OvfTrap);
              *TstSignature = (uint32)CRC32(*TstSignature, (uint32)TrapTst_lTrapCounters[CoreId].Crc);
              if(TrapTst_lTrapCounters[CoreId].Class5OvfTrap != 1U)
              {
                Result = TRAPTST_ERROR_CLASS5;
              }
              else
              {
                TrapTst_lClass6SysTrap();
                *TstSignature = (uint32)CRC32(*TstSignature,(uint32)TrapTst_lTrapCounters[CoreId].Class6SysTrap);
                *TstSignature = (uint32)CRC32(*TstSignature, (uint32)TrapTst_lTrapCounters[CoreId].Crc);
                if(TrapTst_lTrapCounters[CoreId].Class6SysTrap != 1U)
                {
                  Result = TRAPTST_ERROR_CLASS6;
                }
                else
                {
                  InitCrc = TrapTst_lTrapCounters[CoreId].Crc;
                  if( TrapTst_lCalcCounterCrc() != InitCrc)
                  {
                    Result = TRAPTST_CRCMISMATCH;
                  }
                  else
                  {
                    Result = TRAPTST_SUCCESS;
                  }
                } /* Class 6 Traps */
              } /* Class 5 Traps */
            } /* Class 4 Traps */
          }
        }
        else
        {
          Result = SmuResult;
        }
      } /* Class 3 Traps */
    } /* Class 2 Traps */
  }/* Class 1 Traps */

  *TstSignature = (uint32)CRC32(*TstSignature, Result);
  return Result;
}

#define IFX_TRAPTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
