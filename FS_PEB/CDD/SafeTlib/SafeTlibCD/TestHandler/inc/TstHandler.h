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
**  $FILENAME   : TstHandler.h $                                             **
**                                                                            **
**  $CC VERSION : \main\29 $                                                 **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - Declarations for TstHandler driver.                      **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

#ifndef TSTHANDLER_H
#define TSTHANDLER_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "Sl_Timeout.h"
#include "TstHandler_Cfg.h"
#include "SmuInt.h"
#include "Mtl_Trap.h"

#include "Sl_ErrorCodes.h"
#include "test.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define TH_INVALID_TEST_ID ((Sl_TstIndexType)0xFFU)

#define MIN_TEST_SEED 0x0U
#define MAX_TEST_SEED 0xFU

#define MIN_GRP_IDX 0x0U
#define MAX_GRP_IDX 0xFFU

#define SL_INVALID      ((Sl_TstPhaseType)0U)
#define SL_EARLY_PRERUN ((Sl_TstPhaseType)1U)
#define SL_PRERUN       ((Sl_TstPhaseType)2U)
#define SL_RUN          ((Sl_TstPhaseType)3U)
#define SL_POSTRUN      ((Sl_TstPhaseType)4U)

#define TH_TST_NOT_EXECUTED ((Sl_TstRsltType)0U)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/* This type defines an identifier for a test */
typedef uint8 Sl_TstIndexType;

/* This type defines SafeTlib Phase */
typedef uint32 Sl_TstPhaseType ;

/* This type defines Test Result and Signature */
typedef struct Sl_TstDataType
{
  Sl_TstRsltType Result;
  uint32 Signature;
}Sl_TstDataType;

/* This type defines test group index */
typedef uint8 Sl_TstGroupType;

/* This type defines a set for SafeTlib test */
typedef struct Th_TestlibTestSetType
{
  Sl_TstIndexType TstIdx;
  Sl_ParamSetType ParamSetIdx;
  uint8 AlarmPos ;
}Th_TestlibTestSetType;

/* Function pointer type that defines an MTL test function */
typedef Sl_TstRsltType (*Th_TestLibFuncPtrType)
(
  Sl_ParamSetType ParamSetIndex,
  uint8 TstSeed,
  uint32* TstSignature
);

/* Type defintion for Test Handler Configuration */
typedef struct Sl_ConfigType
{
  const Th_TestlibTestSetType* TestGroupEarlyPreRunPtr;
  const Th_TestlibTestSetType* TestGroupPreRunPtr;
  const Th_TestlibTestSetType* TestGroupRunPtr;
  const Th_TestlibTestSetType* TestGroupPostRunPtr;
  const Th_TestLibFuncPtrType* Th_TestLibFuncPtr ;
  const Smu_ConfigType* SmuConfigAddrPrerun;
  const Smu_ConfigType* SmuConfigAddrRuntime;
  uint8 GroupCountEarlyPreRun;
  uint8 GroupCountPreRun;
  uint8 GroupCountRuntime;
  uint8 GroupCountPostRun;
  uint8 CoreId;   
}Sl_ConfigType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
extern const Sl_ConfigType Sl_ConfigRoot[SL_CFG_COUNT];

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#define IFX_TSTHANDLER_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Std_ReturnType Sl_PreInit                               **
**                                   (                                        **
**                                   const Sl_ConfigType* const ConfigPtr     **
**                                   )                                        **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : ConfigPtr : Structure containing the entire information **
**                                of the various tests to be performed during **
**                                the entire life cycle of SafeTlib           **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                    E_OK : If Pre_init is executed successfully             **
**                    E_NOT_OK : Execution failed because of Invalid          **
**                    Parameters etc                                          **
**                                                                            **
** Description      :                                                         **
** - This function is used to initailze the sytem to enter Early Pre Run Phase**
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Sl_PreInit(const Sl_ConfigType* const ConfigPtr);


/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Std_ReturnType Sl_ExecCriticalPreRunTst                 **
**                    (                                                       **
**                    const uint8 TstSeed ,                                   **
**                    const Sl_TstGroupType TstGroupIndex,                    **
**                    uint32 const *TstSignaturePtr,                          **
**                    Sl_TstRsltType const *TstResultPtr)                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : TstSeed : The Test Seed used for Signature generation   **
**                    TstGroupIndex : Group Index containing tests            **
**                                                                            **
** Parameters (out) : TstSignaturePtr : Pointer where all tests Signatures    **
**                    of the group will be stored                             **
**                                                                            **
**                    TstResultPtr : Pointer where all tests Results          **
**                    of the group will be stored                             **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                    E_OK : If Tests are executed successfully               **
**                    E_NOT_OK : Execution failed because of Invalid          **
**                    Parameters etc                                          **
**                                                                            **
** Description      :                                                         **
** - This function is used to execute tests for Early Pre Run Phase           **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Sl_ExecCriticalPreRunTst
(
const uint8 TstSeed,
const Sl_TstGroupType TstGroupIndex,
uint32* const TstSignaturePtr,
Sl_TstRsltType* const TstResultPtr
);


/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Std_ReturnType Sl_Init                                  **
**                                   (                                        **
**                                   const Sl_ConfigType* const ConfigPtr     **
**                                   )                                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : ConfigPtr : Pointer to the Test handler configuration   **
**                                structure                                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                    E_OK : If Initialisation is  successful                 **
**                    E_NOT_OK : Initialisation failed because of Invalid     **
**                    Parameters etc                                          **
**                                                                            **
** Description      :                                                         **
** - This function is used to initialise SL for Pre Run Phase                 **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Sl_Init(const Sl_ConfigType* const ConfigPtr);


/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Std_ReturnType Sl_ExecPreRunTst                         **
**                    (                                                       **
**                    const uint8 TstSeed ,                                   **
**                    const Sl_TstGroupType TstGroupIndex,                    **
**                    uint32 const *TstSignaturePtr,                          **
**                    Sl_TstRsltType const *TstResultPtr)                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : TstSeed : The Test Seed used for Signature generation   **
**                    TstGroupIndex : Group Index containing tests            **
**                                                                            **
** Parameters (out) : TstSignaturePtr : Pointer where all tests Signatures    **
**                    of the group will be stored                             **
**                                                                            **
**                    TstResultPtr : Pointer where all tests Results          **
**                    of the group will be stored                             **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                    E_OK : If Tests are executed successfully               **
**                    E_NOT_OK : Execution failed because of Invalid          **
**                    Parameters etc                                          **
**                                                                            **
** Description      :                                                         **
** - This function is used to execute tests for Pre Run Phase                 **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Sl_ExecPreRunTst
(
const uint8 TstSeed,
const Sl_TstGroupType TstGroupIndex,
uint32* const TstSignaturePtr,
Sl_TstRsltType* const TstResultPtr
 );


/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Std_ReturnType Sl_ExecRunTst                            **
**                    (                                                       **
**                    const uint8 TstSeed ,                                   **
**                    const Sl_TstGroupType TstGroupIndex                     **
**                    uint32* const TstSignaturePtr,                          **
**                    Sl_TstRsltType* const TstResultPtr                      **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : TstSeed : The Test Seed used for Signature generation   **
**                    TstGroupIndex : Group Index containing tests            **
**                                                                            **
** Parameters (out) : TstSignaturePtr : Pointer where signatures of all tests **
**                    of the group will be stored                             **
**                                                                            **
**                    TstResultPtr : Pointer where results of all tests       **
**                    of the group will be stored                             **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                    E_OK : If Tests are executed successfully               **
**                    E_NOT_OK : Execution failed because of Invalid          **
**                    Parameters etc                                          **
**                                                                            **
** Description      :                                                         **
** - This function is used to execute tests for Run Phase                     **
**                                                                            **
*******************************************************************************/

extern Std_ReturnType Sl_ExecRunTst
(
const uint8 TstSeed,
const Sl_TstGroupType TstGroupIndex,
uint32* const TstSignaturePtr, 
Sl_TstRsltType* const TstResultPtr
);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           :                                                         **
**                    Std_ReturnType Sl_ExecSlaveCoreRunTst                   **
**                    (                                                       **
**                      const uint8 TstSeed,                                  **
**                      const Sl_TstGroupType TstGroupIndex,                  **
**                      uint32* const TstSignaturePtr,                        **
**                      Sl_TstRsltType* const TstResultPtr,                   **
**                      const Sl_ConfigType* const ConfigPtr                  **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : TstSeed : The Test Seed used for Signature generation   **
**                    TstGroupIndex : Group Index containing tests            **
**                    TstSignaturePtr: Pointer to test signatures buffer      **
**                    TstResultPtr: Pointer to test results buffer            **
**                    ConfigPtr : Structure containing the entire information **
**                                of the various tests to be performed during **
**                                the entire life cycle of SafeTlib           **
**                                                                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                    E_OK : If Tests are executed successfully               **
**                    E_NOT_OK : Execution failed because of Invalid          **
**                    Parameters etc                                          **
**                                                                            **
** Description      :                                                         **
** - This function is used to execute Run Phase tests for slave cores         **
**                                                                            **
*******************************************************************************/

extern Std_ReturnType Sl_ExecSlaveCoreRunTst
(
const uint8 TstSeed,
const Sl_TstGroupType TstGroupIndex,
uint32* const TstSignaturePtr, 
Sl_TstRsltType* const TstResultPtr,
const Sl_ConfigType* const ConfigPtr
);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Std_ReturnType Sl_ExecPostRunTst                        **
**                    (                                                       **
**                    const uint8 TstSeed ,                                   **
**                    const Sl_TstGroupType TstGroupIndex,                    **
**                    uint32 const *TstSignaturePtr,                          **
**                    Sl_TstRsltType const *TstResultPtr)                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : TstSeed : The Test Seed used for Signature generation   **
**                    TstGroupIndex : Group Index containing tests            **
**                                                                            **
** Parameters (out) : TstSignaturePtr : Pointer where all tests Signatures    **
**                    of the group will be stored                             **
**                                                                            **
**                    TstResultPtr : Pointer where all tests Results          **
**                    of the group will be stored                             **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                    E_OK : If Tests are executed successfully               **
**                    E_NOT_OK : Execution failed because of Invalid          **
**                    Parameters etc                                          **
**                                                                            **
** Description      :                                                         **
** - This function is used to execute tests for Post Run Phase                **
**                                                                            **
*******************************************************************************/

extern Std_ReturnType Sl_ExecPostRunTst
(
const uint8 TstSeed,
const Sl_TstGroupType TstGroupIndex,
uint32* const TstSignaturePtr,
Sl_TstRsltType* const TstResultPtr
);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Std_ReturnType Sl_SwitchTstPhase                        **
**                    (const Sl_TstPhaseType TstPhase)                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : TstPhase : The new phase to be switched for SL          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                    E_OK : Master core: Phase is switched successfully.     **
**                    E_OK : Slave core : Trap handling by SafeTlib is        **
**                                          successfully stopped.             **
**                    E_NOT_OK : Master core: Switching of phase failed.      **
**                    E_NOT_OK : Slave core : Attempt to stop trap handling   **
**                                          by SafeTlib failed.               **
**                                                                            **
** Description      :                                                         **
** - If this function is called by slave core with new phase SL_RUN, then     **
**        trap handling by SafeTlib is stopped.                               **
**                                                                            **
** - If this function is called by slave core with new phase SL_POSTRUN, then **
**        it simply returns with E_OK.                                        **
**                                                                            **
** - If this function is called by master core with new phase SL_RUN, then    **
**        - SMU is de-initialized                                             **
**        - SMU is re-initialized with run-time SMU configuration             **
**        - SMU configuration registers are locked                            **
**        - Trap handling by SafeTlib is stopped                              **
**        - SafeTlib phase is switched SL_RUN                                 **
**                                                                            **
** - If this function is called by master core with new phase SL_POSTRUN, then**
**        - SafeTlib phase is switched SL_POSTRUN                             **
**                                                                            **
** - When new phase is SL_RUN, this function should be called first by slave  **
**    cores and then it should be called by master core.                      **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Sl_SwitchTstPhase
(
const Sl_TstPhaseType TstPhase
);
#define IFX_TSTHANDLER_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif

