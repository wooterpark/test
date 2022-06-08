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
**  $FILENAME   : TstHandler.c $                                             **
**                                                                            **
**  $CC VERSION : \main\72 $                                                 **
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
**  DESCRIPTION  : This file contains functionality of Test Handler           **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Includes                                              *
******************************************************************************/
#include "Mcal.h"
#include "TstHandler.h"
#include "IfxScu_reg.h"
#include "IfxCpu_reg.h"
#include "Sl_Ipc.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define TH_CORRECT_VALUE (0xFFFFFFFFU)

/* CPU core id mask                                                           */
#define TH_CPU_CORE_ID_MASK   ( (uint8)0x3U )

/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/******************************************************************************
**                        Imported declarations                              **
******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define IFX_TSTHANDLER_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
static Sl_TstPhaseType Th_lGetPhase(void);  
static void Th_lSetPhase(Sl_TstPhaseType Phase);
static Std_ReturnType Th_lExecTests
(
 const uint8 TstSeed ,
 Sl_TstPhaseType Sl_Phase,
 const Sl_TstGroupType TstGroupIndex,
 uint32* const TstSignaturePtr,
 Sl_TstRsltType* const TstResultPtr
);

static Std_ReturnType Th_lExecuteRunTest
(
  const uint8 TstSeed,
  Sl_TstIndexType TstIdx,
  Sl_ParamSetType ParamSetIndex,
  uint8 AlarmPos,
  uint32* const TstSignaturePtr, 
  Sl_TstRsltType* const TstResultPtr
);
#define IFX_TSTHANDLER_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define IFX_TSTHANDLER_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"
static Sl_TstPhaseType Th_Phase = SL_INVALID;
static Sl_TstPhaseType Th_PhaseBackup = SL_INVALID;
/* Initially traps are "restored" */
/* Note: 3 cores assumed. It would work for any one core, any two cores also */
static uint32 Sl_BtvRestored[3] = {1U, 1U, 1U};
#define IFX_TSTHANDLER_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_TSTHANDLER_START_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
static const Sl_ConfigType*  Th_kConfigPtr[MCAL_NO_OF_CORES] ;
static const Sl_ConfigType*  Th_kConfigPtrBackup[MCAL_NO_OF_CORES] ;
#define IFX_TSTHANDLER_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define IFX_TSTHANDLER_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : static Sl_TstPhaseType Th_lGetPhase()                   **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Sl_TstPhaseType                                         **
**                    The Current Phase is Returned                           **
**                                                                            **
** Description      :                                                         **
** - This function is used to Retrieve the Current Phase after validation with**
**   the back up of the Phase stored (Redundant Check)                        **
** - This function is local to the driver module                              **
**                                                                            **
*******************************************************************************/
static Sl_TstPhaseType Th_lGetPhase()
{
  Sl_TstPhaseType Phase = Th_Phase;
  if ((Th_PhaseBackup ^ Phase)!= TH_CORRECT_VALUE)
  {
    Phase = SL_INVALID;
  }
  return Phase;
}

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : static void Th_lSetPhase(Sl_TstPhaseType Phase)         **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : Phase : The current Phase                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :                                                         **
** - This function is used to Store the Current Phase and also update the     **
**   the back up of the Phase (Redundant Store)                               **
** - This function is local to the driver module                              **
**                                                                            **
*******************************************************************************/
static void Th_lSetPhase(Sl_TstPhaseType Phase)
{
  Th_Phase = Phase;
  Th_PhaseBackup = (~Phase);
  return;
}

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : static Std_ReturnType Th_lExecTests                     **
**                    (                                                       **
**                    const uint8 TstSeed ,                                   **
**                    Sl_TstPhaseType Sl_Phase,                               **
**                    const Sl_TstGroupType TstGroupIndex,                    **
**                    uint32* const TstSignaturePtr,                          **
**                    Sl_TstRsltType* const TstResultPtr)                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : TstSeed : The Test Seed used for Signature generation   **
**                    Sl_Phase : The phase of the SafeTlib                    **
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
** - This function is used to execute tests for Early Pre Run , Pre Run       **
**   and Post Run Phase                                                       **
** - This function is local to the driver module                              **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Th_lExecTests
(
  const uint8 TstSeed ,
  Sl_TstPhaseType Sl_Phase,
  const Sl_TstGroupType TstGroupIndex,
  uint32* const TstSignaturePtr,
  Sl_TstRsltType* const TstResultPtr 
)
{
  uint32 TestExecutedCount = 0U ;
  uint32 TestFailCount = 0U ;
  const Th_TestlibTestSetType* TestGroupPtr = NULL_PTR;
  Std_ReturnType Result = E_NOT_OK;
  const Th_TestLibFuncPtrType* Th_TestLibFuncPtr ;
  uint8 MaxTests = 0U ;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & TH_CPU_CORE_ID_MASK);

  if( (Th_lGetPhase() == Sl_Phase) && 
      (((uint32)Th_kConfigPtr[CoreId] ^ (uint32)Th_kConfigPtrBackup[CoreId]) == TH_CORRECT_VALUE))
  {
    switch(Sl_Phase)
    {
      case SL_EARLY_PRERUN:
        MaxTests = SL_MAX_TESTS_EARLY_PRE_RUN_GRP ;
        TestGroupPtr = Th_kConfigPtr[CoreId]->TestGroupEarlyPreRunPtr ;
        Result = E_OK;
        break;

      case SL_PRERUN:
        MaxTests = SL_MAX_TESTS_PRE_RUN_GRP ;
        TestGroupPtr = Th_kConfigPtr[CoreId]->TestGroupPreRunPtr ;
        Result = E_OK;
        break;

      case SL_POSTRUN:
        MaxTests = SL_MAX_TESTS_POST_RUN_GRP;
        TestGroupPtr = Th_kConfigPtr[CoreId]->TestGroupPostRunPtr ;
        Result = E_OK;
        break;
        
      default :
        Result = E_NOT_OK;
        break;
    }

    Th_TestLibFuncPtr = Th_kConfigPtr[CoreId]->Th_TestLibFuncPtr ;

    if(E_OK == Result)
    {
      uint32 LoopCount ;
      Result = E_NOT_OK;
      TestGroupPtr += (TstGroupIndex * MaxTests) ;
      
      for (LoopCount=0U;LoopCount< MaxTests; LoopCount++)
      {
        Sl_ParamSetType ParamSetIdx;
        Sl_TstIndexType TstIdx;
        const Th_TestlibTestSetType* TestGroupPtrFinal;
        
        TestGroupPtrFinal = TestGroupPtr + LoopCount ;
        
        TstIdx = TestGroupPtrFinal->TstIdx;
        ParamSetIdx = TestGroupPtrFinal->ParamSetIdx;
        
        if (TH_INVALID_TEST_ID != TstIdx)
        {
          Sl_TstRsltType TstResult;
          uint32 Signature;
          TstResult = Th_TestLibFuncPtr[TstIdx](ParamSetIdx, TstSeed, &Signature);
          *(TstSignaturePtr + TstIdx ) = Signature;
          *(TstResultPtr + TstIdx ) = TstResult;
          
          TestExecutedCount++ ;
          
          if(!SL_SUCCESS(TstResult))
          {
            TestFailCount++ ;
          }          
        }

      } /* for */
        
      /* 
        Return E_OK if 
          - test group is empty (i.e. group that has all invalid test ids)
          - at least one test is executed and there is no failure 
      */
      if((TestExecutedCount == 0U) || (TestFailCount == 0U))
      {
        Result = E_OK ;
      }
      
    }
  }
  return Result;
}


/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : static Std_ReturnType Th_lExecuteRunTest                **
**                    (                                                       **
**                    const uint8 TstSeed,                                    **
**                    Sl_TstIndexType TstIdx,                                 **
**                    Sl_ParamSetType ParamSetIndex,                          **
**                    uint8 AlarmPos,                                         **
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
**                    TstId : The Test Id of the test to be executed          **
**                    ParamSetIndex : Parameter Set for the Test              **
**                    AlarmPos : SMU Alarm Position                           **
**                    TstSignaturePtr: Pointer to test signatures buffer      **
**                    TstResultPtr: Pointer to test results buffer            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                    E_OK : If Test is executed successfully                 **
**                    E_NOT_OK : Execution failed because of invalid          **
**                    parameters etc.                                         **
**                                                                            **
** Description      :                                                         **
** - This function is used to execute test for Run Phase                      **
** - This function is local to the driver module                              **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Th_lExecuteRunTest
(
  const uint8 TstSeed,
  Sl_TstIndexType TstIdx,
  Sl_ParamSetType ParamSetIndex,
  uint8 AlarmPos,
  uint32* const TstSignaturePtr, 
  Sl_TstRsltType* const TstResultPtr
)
{
  Std_ReturnType Result = E_NOT_OK;
  Sl_TstRsltType TstResult;
  uint32 Signature;
  const Th_TestLibFuncPtrType* Th_TestLibFuncPtr ;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & TH_CPU_CORE_ID_MASK);

  if(((uint32)Th_kConfigPtr[CoreId] ^ (uint32)Th_kConfigPtrBackup[CoreId]) == TH_CORRECT_VALUE)
  {
    Th_TestLibFuncPtr = Th_kConfigPtr[CoreId]->Th_TestLibFuncPtr ;

    /* A valid TstId is ensured already by caller – no integrity check for TstId required */
    TstResult = Th_TestLibFuncPtr[TstIdx](ParamSetIndex, TstSeed, &Signature);

    /* Update test signature */
    *(TstSignaturePtr + TstIdx ) = Signature;
    
    /* Update test result */
    *(TstResultPtr + TstIdx ) = TstResult;      

    if (!(SL_SUCCESS(TstResult)))
    {
      Std_ReturnType SmuResult;
      /* Raise SMU alarm to indicate that the MTL test failed */
      SmuResult = Smu_SetAlarmStatus(SMU_SW_ALARM_GROUP, AlarmPos);
      
      /* 
        Ignore the return value of above API call. We are reporting failure, in any case.
        Without this statement, compiler eliminates above API call.
      */
      UNUSED_PARAMETER(SmuResult)
     
      /* Report the failure */
      Result = E_NOT_OK ; 
    }
    else
    {
      Result = E_OK;
    }
  }
  return Result ;
}

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Std_ReturnType Sl_PreInit(Sl_ConfigType* ConfigPtr)     **
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
Std_ReturnType Sl_PreInit(const Sl_ConfigType* const ConfigPtr)
{
  Std_ReturnType Result = E_NOT_OK;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & TH_CPU_CORE_ID_MASK);
  
  if(NULL_PTR != (const void *)ConfigPtr)
  {
    if(ConfigPtr->CoreId == CoreId)
    {  
      if (Th_Phase == SL_INVALID)
      {
        Sl_SpinLockInit();
        Th_kConfigPtr[CoreId] =  ConfigPtr;
        Th_kConfigPtrBackup[CoreId] = (Sl_ConfigType *)(~(uint32)ConfigPtr);
        
        if (SL_MASTER_CORE_ID == CoreId)
        {
          Result = Smu_Init(Th_kConfigPtr[CoreId]->SmuConfigAddrPrerun);
        
          if(E_OK == Result)
          {
            Th_lSetPhase(SL_EARLY_PRERUN);
          }
        }
        else  /* Slave core - return E_OK */
        {
          Result = E_OK ;
        }        
      }
    }
  }
  
  return Result;
}


/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Std_ReturnType Sl_ExecCriticalPreRunTst                 **
**                    (                                                       **
**                    const uint8 TstSeed ,                                   **
**                    const Sl_TstGroupType TstGroupIndex,                    **
**                    uint32* const TstSignaturePtr,                          **
**                    Sl_TstRsltType* const TstResultPtr)                     **
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
Std_ReturnType Sl_ExecCriticalPreRunTst
(
const uint8 TstSeed,
const Sl_TstGroupType TstGroupIndex, 
uint32* const TstSignaturePtr, 
Sl_TstRsltType* const TstResultPtr
)
{
  Std_ReturnType Result = E_NOT_OK;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & TH_CPU_CORE_ID_MASK);
  
  if(((uint32)Th_kConfigPtr[CoreId] ^ (uint32)Th_kConfigPtrBackup[CoreId]) == TH_CORRECT_VALUE)
  {
    if (TstGroupIndex < Th_kConfigPtr[CoreId]->GroupCountEarlyPreRun)
    {
      if (TstSeed <= MAX_TEST_SEED)
      {
        if ((TstSignaturePtr != NULL_PTR) && (TstResultPtr != NULL_PTR))
        {
          Result = Th_lExecTests(TstSeed,
          SL_EARLY_PRERUN,TstGroupIndex,TstSignaturePtr,TstResultPtr) ;
        }
      }
    }
  }
  return Result;
}


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
** Parameters (in)  : None                                                    **
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
Std_ReturnType Sl_Init(const Sl_ConfigType* const ConfigPtr)
{
  Std_ReturnType Result = E_NOT_OK;
  TRAP_ErrorType TrapResult = TRAP_E_INIT;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & TH_CPU_CORE_ID_MASK);

  if(NULL_PTR != (const void *)ConfigPtr)
  {
    if(ConfigPtr->CoreId == CoreId)
    {  
      Th_kConfigPtr[CoreId] = ConfigPtr;
      Th_kConfigPtrBackup[CoreId] = (Sl_ConfigType *)(~(uint32)ConfigPtr) ;

      TrapResult = TRAP_Init();
      if(TrapResult == TRAP_E_SUCCESS)
      {
        TrapResult = TRAP_StartHandleTraps();
        if(TrapResult == TRAP_E_SUCCESS)
        {
          /* Switch trap handling to SafeTLib */
          Sl_BtvRestored[CoreId] = 0x0u;
          if (SL_MASTER_CORE_ID == CoreId)
          {
            Smu_StateType SmuState = Smu_GetSmuState();
            
            switch (SmuState)
            {
              case SMU_START_STATE:
              {                
                Result = Smu_ReleaseFSP();
                if(Result != E_NOT_OK)
                {
                  /* move to run state directly */
                  Result = Smu_ActivateRunState(SMU_RUN_COMMAND);
                }
                break;
              }
              case SMU_FAULT_STATE:
              {
                /* move from Fault to run state */
                Result = Smu_ReleaseFSP();
                break;
              }
              case SMU_RUN_STATE:
              {
                /* everything okay, just keep run state */
                Result = E_OK;
                break;
              }
              default:
                /* unexpected SMU state */
                break;
            }
            
            if(E_OK == Result)
            {
              Th_lSetPhase(SL_PRERUN);
            }
          }
          else
          {
            Result = E_OK ;
          }
        }
      }
    }
  }

  return Result;
}


/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Std_ReturnType Sl_ExecPreRunTst                         **
**                    (                                                       **
**                    const uint8 TstSeed ,                                   **
**                    const Sl_TstGroupType TstGroupIndex,                    **
**                    uint32* const TstSignaturePtr,                          **
**                    Sl_TstRsltType* const TstResultPtr)                     **
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
Std_ReturnType Sl_ExecPreRunTst
(
const uint8 TstSeed,
const Sl_TstGroupType TstGroupIndex, 
uint32* const TstSignaturePtr, 
Sl_TstRsltType* const TstResultPtr
 )
{
  Std_ReturnType Result = E_NOT_OK;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & TH_CPU_CORE_ID_MASK);
  
  if(((uint32)Th_kConfigPtr[CoreId] ^ (uint32)Th_kConfigPtrBackup[CoreId]) == TH_CORRECT_VALUE)
  {
    if (TstGroupIndex < Th_kConfigPtr[CoreId]->GroupCountPreRun)
    {
      if (TstSeed <= MAX_TEST_SEED)
      {
        if ((TstSignaturePtr != NULL_PTR) && (TstResultPtr != NULL_PTR))
        {
          Result = Th_lExecTests(TstSeed,
          SL_PRERUN, TstGroupIndex, TstSignaturePtr, TstResultPtr) ;
        }
      }
    }
  }
  return Result;
}


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

Std_ReturnType Sl_ExecRunTst
(
const uint8 TstSeed,
const Sl_TstGroupType TstGroupIndex,
uint32* const TstSignaturePtr, 
Sl_TstRsltType* const TstResultPtr
)
{ 
  Std_ReturnType ReturnValue = E_NOT_OK;
  uint32 TestFailCount = 0U ;
  uint32 LoopCount = 0U ;
  const Th_TestlibTestSetType* RunTestPtr ;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & TH_CPU_CORE_ID_MASK);
  
  if ((TstSignaturePtr != NULL_PTR) && (TstResultPtr != NULL_PTR))
  {
    if((Th_lGetPhase() == SL_RUN) &&  (TstSeed <= MAX_TEST_SEED))
    {
      if(((uint32)Th_kConfigPtr[CoreId] ^ (uint32)Th_kConfigPtrBackup[CoreId]) == TH_CORRECT_VALUE)
      {
        if(TstGroupIndex < Th_kConfigPtr[CoreId]->GroupCountRuntime )
        {
          RunTestPtr = Th_kConfigPtr[CoreId]->TestGroupRunPtr + (TstGroupIndex * SL_MAX_TESTS_RUN_TIME_GRP) ;
          for (LoopCount=0U; LoopCount < SL_MAX_TESTS_RUN_TIME_GRP; LoopCount++)
          {
            const Th_TestlibTestSetType* RunTestPtrFinal ;
            Sl_TstIndexType TestIdx = 0U;
            Sl_ParamSetType ParamSetIdx = 0U;
            uint8 SmuAlarm = 0U;
            Std_ReturnType Result ;

            RunTestPtrFinal = RunTestPtr + LoopCount ;
            
            TestIdx = RunTestPtrFinal->TstIdx ;
            ParamSetIdx = RunTestPtrFinal->ParamSetIdx ;
            SmuAlarm = RunTestPtrFinal->AlarmPos ;
            
            if(TH_INVALID_TEST_ID != TestIdx)
            {
              Result = Th_lExecuteRunTest(TstSeed, TestIdx, ParamSetIdx, SmuAlarm, TstSignaturePtr, TstResultPtr);
              
              if(E_OK != Result)
              {
                TestFailCount++ ;
              }
            }
          }
          
        /* 
          Return E_OK if test group doesn't contain any failed test cases
        */
          if(TestFailCount == 0U)
          {
            ReturnValue = E_OK ;
          }
        }
      }
    }
  }
  return ReturnValue ;
}

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

Std_ReturnType Sl_ExecSlaveCoreRunTst
(
const uint8 TstSeed,
const Sl_TstGroupType TstGroupIndex,
uint32* const TstSignaturePtr, 
Sl_TstRsltType* const TstResultPtr,
const Sl_ConfigType* const ConfigPtr
)
{ 
  Std_ReturnType ReturnValue = E_NOT_OK;
  Sl_TstRsltType TstResult = E_NOT_OK;
  uint32 TestFailCount = 0U ;
  uint8 LoopCount = 0U ;
  uint32 Signature = 0U ;
  const Th_TestlibTestSetType* RunTestPtr ;
  
  if ((TstSignaturePtr != NULL_PTR) && (TstResultPtr != NULL_PTR))
  {
    if(TstSeed <= MAX_TEST_SEED)
    {
      if(TstGroupIndex < ConfigPtr->GroupCountRuntime )
      {
        RunTestPtr = ConfigPtr->TestGroupRunPtr + (TstGroupIndex * SL_MAX_TESTS_RUN_TIME_GRP) ;
        for (LoopCount=0U; LoopCount < SL_MAX_TESTS_RUN_TIME_GRP; LoopCount++)
        {
          const Th_TestlibTestSetType* RunTestPtrFinal ;
          Sl_TstIndexType TestIdx = 0U;
          Sl_ParamSetType ParamSetIdx = 0U;

          RunTestPtrFinal = RunTestPtr + LoopCount ;
          
          TestIdx = RunTestPtrFinal->TstIdx ;
          ParamSetIdx = RunTestPtrFinal->ParamSetIdx ;
          
          if(TH_INVALID_TEST_ID != TestIdx)
          {
            /* A valid TstId is ensured already by caller – no integrity check for TstId required */
            TstResult = ConfigPtr->Th_TestLibFuncPtr[TestIdx](ParamSetIdx, TstSeed, &Signature);
                        
            /* Update test signature */
            *(TstSignaturePtr + TestIdx ) = Signature;
    
            /* Update test result */
            *(TstResultPtr + TestIdx ) = TstResult;      

            if (!(SL_SUCCESS(TstResult)))
            {
              /* Report the failure */
              TestFailCount++ ;
            } 
          }
        }
        
        /* 
          Return E_OK if test group doesn't contain any failed test cases
        */
        if(TestFailCount == 0U)
        {
          ReturnValue = E_OK ;
        }
      }
    }
  }
  return ReturnValue ;

}


/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Std_ReturnType Sl_ExecPostRunTst                        **
**                    (                                                       **
**                    const uint8 TstSeed ,                                   **
**                    const Sl_TstGroupType TstGroupIndex,                    **
**                    uint32* const TstSignaturePtr,                          **
**                    Sl_TstRsltType* const TstResultPtr)                     **
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

Std_ReturnType Sl_ExecPostRunTst
(
const uint8 TstSeed,
const Sl_TstGroupType TstGroupIndex, 
uint32* const TstSignaturePtr, 
Sl_TstRsltType* const TstResultPtr
 )
{
  Std_ReturnType Result = E_NOT_OK;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & TH_CPU_CORE_ID_MASK);
  
  if(((uint32)Th_kConfigPtr[CoreId] ^ (uint32)Th_kConfigPtrBackup[CoreId]) == TH_CORRECT_VALUE)
  {
    if (TstGroupIndex < Th_kConfigPtr[CoreId]->GroupCountPostRun)
    {
      if (TstSeed <= MAX_TEST_SEED)
      {
        if ((TstSignaturePtr != NULL_PTR) && (TstResultPtr != NULL_PTR))
        {
          Result = Th_lExecTests(TstSeed,
          SL_POSTRUN,TstGroupIndex,TstSignaturePtr,TstResultPtr) ;
        }
      }
    }
  }
  return Result;
}

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

Std_ReturnType Sl_SwitchTstPhase 
(
const Sl_TstPhaseType TstPhase
)
{
  Std_ReturnType Result = E_NOT_OK;
  TRAP_ErrorType TrapResult = TRAP_E_INIT;
  uint8 CoreId;

  CoreId = ((uint8)MFCR(CPU_CORE_ID) & TH_CPU_CORE_ID_MASK);
  
  if ((TstPhase == SL_RUN) && (Th_lGetPhase() == SL_PRERUN) )
  {
    if (SL_MASTER_CORE_ID == CoreId)
    {
      /* De-initialise the SMU module */
      Result = Smu_DeInit();
      if (E_OK == Result)
      {
        if(((uint32)Th_kConfigPtr[CoreId] ^ (uint32)Th_kConfigPtrBackup[CoreId]) == TH_CORRECT_VALUE)
        {
          /* Initialize SMU with Runtime configuration */
          Result = Smu_Init(Th_kConfigPtr[CoreId]->SmuConfigAddrRuntime);
        }
        else
        {
          Result = E_NOT_OK;
        }

        if (E_OK == Result)
        {
          /* Lock the SMU configuration registers */
          Result = Smu_LockConfigRegs();

          if (E_OK == Result)
          { 
            /* Stops trap handling by the SafeTlib for master core */
            TrapResult  = TRAP_StopHandleTraps();                
            if(TRAP_E_SUCCESS == TrapResult)
            {
              Sl_BtvRestored[CoreId] = 1U ;
            }
            if((1U == Sl_BtvRestored[0]) && (1U == Sl_BtvRestored[1]) && (1U == Sl_BtvRestored[2]))
            { 
              /* BTV restored on all cores. Now switch the phase */
              Th_lSetPhase(TstPhase);
            }
            else
            {
              Result = E_NOT_OK ;
            }
          }
        }
      }
    }
    else
    {
      /* Stops trap handling by the SafeTlib for non-master core */
      TrapResult  = TRAP_StopHandleTraps();
      if(TRAP_E_SUCCESS == TrapResult)
      {
        Sl_BtvRestored[CoreId] = 1U ;
        Result = E_OK ;
      }
    }
  }
  
  if ((TstPhase == SL_POSTRUN) && (Th_lGetPhase() == SL_RUN) )
  {
    if (SL_MASTER_CORE_ID == CoreId)
    {
      Th_lSetPhase(TstPhase);
    }
    Result = E_OK;              
  }
  
  return Result;
}

#define IFX_TSTHANDLER_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
