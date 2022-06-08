/*******************************************************************************
 **                                                                           **
 ** Copyright (C) Infineon Technologies (2014)                                **
 **                                                                           **
 ** All rights reserved.                                                      **
 **                                                                           **
 ** This document contains proprietary information belonging to Infineon      **
 ** Technologies. Passing on and copying of this document, and communication  **
 ** of its contents is not permitted without prior written authorization.     **
 **                                                                           **
 ********************************************************************************
 **                                                                           **
 **  $FILENAME   : TstM.c $                                                   **
 **                                                                           **
 **  $CC VERSION : \main\64 $                                                 **
 **                                                                           **
 **  $DATE       : 2018-02-22 $                                               **
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
 **  DESCRIPTION  : This file contains                                        **
 **                 - Functionality of Test Manager :                         **
 **					-> This software module is                                        **  
 **                     the caller of the Test Handler to execute the tests   **
 **					-> It performs application level checks and                       ** 
 **					  consolidates the results of the internal                        **
 **					  program flow monitoring                                         **          
 **					-> It invokes the SMU for triggering the safe state               **
 **					  and error handling                                              ** 
 **                                                                           **
 **  MAY BE CHANGED BY USER [Yes/No]: Yes                                     **
 **                                                                           **
 ******************************************************************************/

/*******************************************************************************
 **                      Includes                                             **
 ******************************************************************************/
#include "Mcal.h"
#include "TstM.h"
#if(SL_RUNTIME_TESTS == TRUE)
#include "SafeWdgM.h"
#endif
#include "AppCbk.h"
#include "IfxCpu_reg.h"
#include "ChipId.h"

/*******************************************************************************
 **                      Private Macro Definitions                            **
 ******************************************************************************/
/* Configuration Required */
#define TSTM_ALM_GROUP              (5)
#define TSTM_ALM_POS                (6)
#define TSTM_PRERUN_SEED            (5)
#define TSTM_EARLY_PRERUN_SEED      (5U)
#if(SL_RUNTIME_TESTS == FALSE)
#define SAFEWDG_SEED_NOTVALID        (255U)
#endif

/*******************************************************************************
 **                   Function like macro definitions                         **
 ******************************************************************************/

/*******************************************************************************
 **                      Private Type Definitions                             **
 ******************************************************************************/

/******************************************************************************
**                        Imported declarations                              **
******************************************************************************/
extern uint8 RA_CoreId2CfgSetIdx[MCAL_NO_OF_CORES];
extern void RA_Stop(void);

/*******************************************************************************
 **                      Private Function Declarations                        **
 ******************************************************************************/
#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#if ((SL_IGNORE_SIGNATUREVALIDATE == FALSE) || (SL_RUNTIME_TESTS == TRUE))
static void TstM_lConsolidateSigCoreX(void);
#endif
#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
 **                      Global Constant Definitions                          **
 ******************************************************************************/

/*******************************************************************************
 **                      Global Variable Definitions                          **
 ******************************************************************************/

#define IFX_APPL_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
 
/* Buffer for consolidated signatures */
static uint32 TstM_ConsolidatedSignCoreX[MCAL_NO_OF_CORES];

/* Test results buffer used for all SafeTlib phases */
static Sl_TstRsltType TstM_TestResults[MCAL_NO_OF_CORES][TH_TOTAL_TESTS];

/* Test signature buffer used for all SafeTlib phases */
static uint32 TstM_TestSignatures[MCAL_NO_OF_CORES][TH_TOTAL_TESTS];


#define IFX_APPL_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/**************************************************************************/

/*******************************************************************************
 **                      Private Constant Definitions                         **
 ******************************************************************************/

/*******************************************************************************
 **                      Private Variable Definitions                         **
 ******************************************************************************/
#define IFX_APPL_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"
 
/* Pre-run test result */
static Sl_TstRsltType TstM_PreRunTstResult[3] = {TEST_PASS, TEST_PASS, TEST_PASS};

/* Expected overall signatures for early pre-run phase for each core
 * This is just example as per default configuration (tests per core)
 * This should be adapted and changed according to customer's configuration
 */
#if((CHIP_ID == 29U) || (CHIP_ID == 26U))
uint32 TstM_ExptdSigEarlyPreRun[3] = {0,0x424A8439,0} ;
#else
uint32 TstM_ExptdSigEarlyPreRun[3] = {0xA21BD298,0,0} ;
#endif
/* Expected overall signatures for  pre-run phase for each group per core
 * This is just example one of the examples configuration (each group per core)
 * This should be adapted and changed according to customer's configuration
 * Customer can write his own method of signature validation
 */
uint32 TstM_ExptdSigPreRun[3][2] = { {0xB159B8F1,0xE8922E00},
                                     {0x84AF0B59,0x3003AA5E},
                                     {0xD585010F,0U}
                                    };

uint32 Application_Check_Results = 0;

#define IFX_APPL_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"
 
#define IFX_APPL_START_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B
#include "Ifx_MemMap.h"
 
Sl_TstGroupType TstGroupIndex = 0;
static uint8 TstM_TstSeed = SAFEWDG_SEED_NOTVALID;


#define IFX_APPL_STOP_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B
#include "Ifx_MemMap.h"
 
#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
 **                      Private Function Definitions                         **
 ******************************************************************************/

/*******************************************************************************
 **                      Global Function Definitions                          **
 ******************************************************************************/

/*******************************************************************************
 **                                                                           **
 ** Syntax           : void TstM_Init(void)                                   **
 **                                                                           **
 ** Service ID       : none                                                   **
 **                                                                           **
 ** Sync/Async       : Synchronous                                            **
 **                                                                           **
 ** Reentrancy       : Non-reentrant                                          **
 **                                                                           **
 ** Parameters (in)  : None                                                   **
 **                                                                           **
 ** Parameters (out) : None                                                   **
 **                                                                           **
 ** Return value     : None                                                   **
 **                                                                           **
 ** Description      : Initialization of the Test Manager global variables    **
 **                    and invoke the initialization of SafeTlib.             **
 **                    Error shall be reported through application callback   **
 **                                                                           **
 ******************************************************************************/
void TstM_Init(void)
{
  Std_ReturnType Result = E_NOT_OK;
  uint8 CoreId;

  CoreId = Mcal_GetCoreId();

  Result = Sl_Init(&Sl_ConfigRoot[RA_CoreId2CfgSetIdx[CoreId]]);
  
  if (Result != E_OK)
  {
    AppCbk_ErrorHandler(APLCBK_TSTM_INIT_FAIL);
  }
}

/*******************************************************************************
 **                                                                           **
 ** Syntax           : void TstM_EarlyPreRunTst(void)                         **
 **                                                                           **
 ** Service ID       : none                                                   **
 **                                                                           **
 ** Sync/Async       : Synchronous                                            **
 **                                                                           **
 ** Reentrancy       : Non-reentrant                                          **
 **                                                                           **
 ** Parameters (in)  : None                                                   **
 **                                                                           **
 ** Parameters (out) : None                                                   **
 **                                                                           **
 ** Return value     : None                                                   **
 **                                                                           **
 ** Description      : Performs early pre-run phase execution                 **
 **                    Error shall be reported through application callback   **
 **                                                                           **
 ******************************************************************************/
void TstM_EarlyPreRunTst(void)
{
  Std_ReturnType Result = E_NOT_OK;
  uint8 TestGroupIndex = 0;
  uint8 CoreId;  

  /* Invalidate seed, test results and test signatures for early pre-run phase */
  TstM_InvalidateData();
  
  CoreId = Mcal_GetCoreId();
  
  /* Early Pre-Run phase tests execution */
  for (TestGroupIndex = 0; TestGroupIndex < Sl_ConfigRoot[SL_MASTER_CORE_ID].GroupCountEarlyPreRun;
        TestGroupIndex++)
  {
    Result = Sl_ExecCriticalPreRunTst(TSTM_EARLY_PRERUN_SEED, TestGroupIndex,
                       TstM_TestSignatures[CoreId], TstM_TestResults[CoreId]);
    if (E_OK != Result)
    {
      AppCbk_ErrorHandler(APLCBK_SL_EARLYPRE_RUN_TST_FAIL);
      break;
    }
  }
        
#if (SL_IGNORE_SIGNATUREVALIDATE == FALSE)  
  /* 
   * This is just an example, this is one of the ways for early pre-run signature validation
   * Consolidate signatures of early pre-run test signatures per core
   */
  TstM_lConsolidateSigCoreX();
  
  if(TstM_ConsolidatedSignCoreX[CoreId] != TstM_ExptdSigEarlyPreRun[CoreId])
  {
    AppCbk_ErrorHandler(APLCBK_SL_EARLYPRE_RUN_TST_FAIL);
  }
#endif
}

/*******************************************************************************
 **                                                                           **
 ** Syntax           : void TstM_PreRunTst(uint8 GroupStartIndex,             **
 **                                                      uint8 GroupEndIndex) **
 **                                                                           **
 ** Service ID       : none                                                   **
 **                                                                           **
 ** Sync/Async       : Synchronous                                            **
 **                                                                           **
 ** Reentrancy       : Non-reentrant                                          **
 **                                                                           **
 ** Parameters (in)  : GroupStartIndex: First group index for test execution  **
 **                    GroupEndIndex: Last group index for test execution     **
 **                                                                           **
 ** Parameters (out) : None                                                   **
 **                                                                           **
 ** Return value     : None                                                   **
 **                                                                           **
 ** Description      : Performs pre-run phase execution                       **
 **                    Error shall be reported through application callback   **
 **                                                                           **
 ******************************************************************************/
void TstM_PreRunTst(uint8 GroupStartIndex, uint8 GroupEndIndex)
{
  Std_ReturnType Result = E_NOT_OK;
  uint8 TestGroupIndex = 0;
  uint8 TstId = 0 ;
  volatile uint8 CoreId;
  uint32 FlagAnyOneTestFailed = 0 ;
  uint8  LastGroupIndex;
  
  TstM_TstSeed = TSTM_PRERUN_SEED;
  CoreId = Mcal_GetCoreId();  

  LastGroupIndex = (GroupEndIndex < Sl_ConfigRoot[RA_CoreId2CfgSetIdx[CoreId]].GroupCountPreRun)? GroupEndIndex : (Sl_ConfigRoot[RA_CoreId2CfgSetIdx[CoreId]].GroupCountPreRun - 1);
  for (TestGroupIndex = GroupStartIndex; TestGroupIndex <= LastGroupIndex;
       TestGroupIndex++)
  {
    Result = Sl_ExecPreRunTst(TstM_TstSeed, TestGroupIndex, TstM_TestSignatures[CoreId], TstM_TestResults[CoreId]);
    if (E_OK != Result)
    {
      FlagAnyOneTestFailed++ ;
    }
  }
  
  if(FlagAnyOneTestFailed > 0)
  {
    AppCbk_ErrorHandler(APLCBK_SL_PRE_RUN_TST_FAIL);
  }

  /* Pre_Run TstM raise alarm on test failure */
  for (TstId = 0; TstId < TH_TOTAL_TESTS; TstId++)
  {
    /* if false: Invalid test Id */
    if(TstM_TestResults[CoreId][TstId] != 0)
    {
      if (!(SL_SUCCESS(TstM_TestResults[CoreId][TstId]))) /* Test(s) in test group fails */
      {
        TstM_PreRunTstResult[CoreId] = TEST_FAIL;
        Result = Smu_SetAlarmStatus(TSTM_ALM_GROUP, TSTM_ALM_POS);
        if (Result != E_OK)
        {
          AppCbk_ErrorHandler(APLCBK_SMU_SET_ALARM_FAIL);
        }
        break;
      }
    }
  }
  
#if (SL_IGNORE_SIGNATUREVALIDATE == FALSE)  
  /* 
   * This is just an example, this is one of the ways for early pre-run signature validation
   * Consolidate signatures of early pre-run test signatures per core
   */
  TstM_lConsolidateSigCoreX();
  
  if(TstM_ConsolidatedSignCoreX[CoreId] != TstM_ExptdSigPreRun[CoreId][GroupEndIndex])
  {
    AppCbk_ErrorHandler(APLCBK_SL_PRE_RUN_TST_FAIL);
  }
#endif
}

/*******************************************************************************
 **                                                                           **
 ** Syntax           : void TstM_CheckPreRunTestResult(uint32 Result)         **
 **                                                                           **
 ** Service ID       : none                                                   **
 **                                                                           **
 ** Sync/Async       : Synchronous                                            **
 **                                                                           **
 ** Reentrancy       : Non-reentrant                                          **
 **                                                                           **
 ** Parameters (in)  : None                                                   **
 **                                                                           **
 ** Parameters (out) : None                                                   **
 **                                                                           **
 ** Return value     : None                                                   **
 **                                                                           **
 ** Description      : Verifies any test failed in prerun phase               **
 **                    Error shall be reported through application callback   **
 **                                                                           **
 ******************************************************************************/
void TstM_CheckPreRunTestResult(void)
{
  uint8 CoreId;
  
  CoreId = Mcal_GetCoreId();
  
  if(TstM_PreRunTstResult[CoreId] != TEST_PASS)
  {
    AppCbk_ErrorHandler(APLCBK_SL_PRE_RUN_TST_FAIL);
  }
}   

#if(SL_RUNTIME_TESTS == TRUE) 
/*******************************************************************************
 **                                                                           **
 ** Syntax           : void TstM_Run(void)                                    **
 **                                                                           **
 ** Service ID       : none                                                   **
 **                                                                           **
 ** Sync/Async       : Synchronous                                            **
 **                                                                           **
 ** Reentrancy       : Non-reentrant                                          **
 **                                                                           **
 ** Parameters (in)  : None                                                   **
 **                                                                           **
 ** Parameters (out) : None                                                   **
 **                                                                           **
 ** Return value     : None                                                   **
 **                                                                           **
 ** Description      : The purpose of this API is to execute all tests in     **
 **    run-time phase groups for current cycle of diagnostic test interval.   **
 **    Before executing tests, it also invalidates seed, test results and     **
 **    test signatures corresponding last cycle.                              **
 **       Incase of the master core, the following functionality is executed  **
 **    additionally:                                                          **
 **    - During first call to this API, it makes transition to run-time phase.**
 **    - During every call to this API, it gets the seed from SafeWDG Manager.**
 **    - Error shall be reported through application callback                 **
 **                                                                           **
 ******************************************************************************/
void TstM_Run(void)
{
  Std_ReturnType Result = E_NOT_OK;
  uint8 TstGroupIndex = 0;
  volatile uint8 CoreId; 
  /* CoreId is made volatile because tasking compiler gives improper warning
  on line 436 for array Sl_ConfigRoot as access out of bounds */
  /* Invalidate seed, test results and test signatures for current cycle */
  TstM_InvalidateData();
  
  CoreId = Mcal_GetCoreId();

  /* Get seed from watchdog, first core to request, will set it */
//  if (TstM_TstSeed == SAFEWDG_SEED_NOTVALID)
//  {
//     SafeWdgM_GetSeed(&TstM_TstSeed);
//  }
  TstM_TstSeed = 0x1;
  /* Run Tests */
  for (TstGroupIndex = 0; TstGroupIndex < Sl_ConfigRoot[RA_CoreId2CfgSetIdx[CoreId]].GroupCountRuntime ; TstGroupIndex++)
  {
    if(SL_MASTER_CORE_ID == CoreId)
    {
      Result = Sl_ExecRunTst(TstM_TstSeed, TstGroupIndex, TstM_TestSignatures[CoreId], TstM_TestResults[CoreId]);
    }
    else
    {
      Result = Sl_ExecSlaveCoreRunTst(TstM_TstSeed, TstGroupIndex, TstM_TestSignatures[CoreId], TstM_TestResults[CoreId], &Sl_ConfigRoot[RA_CoreId2CfgSetIdx[CoreId]]);
    }
    
    if (Result != E_OK)
    {
      AppCbk_ErrorHandler(APLCBK_SL_RUN_TST_FAIL);
      break;
    }
  }
  TstM_lConsolidateSigCoreX();    /* Signature consolidation */
}

/*******************************************************************************
 **                                                                           **
 ** Syntax           : void TstM_PostRun(void)                                **
 **                                                                           **
 ** Service ID       : none                                                   **
 **                                                                           **
 ** Sync/Async       : Synchronous                                            **
 **                                                                           **
 ** Reentrancy       : Non-reentrant                                          **
 **                                                                           **
 ** Parameters (in)  : None                                                   **
 **                                                                           **
 ** Parameters (out) : None                                                   **
 **                                                                           **
 ** Return value     : None                                                   **
 **                                                                           **
 ** Description      : Performs Post-Run phase execution                      **
 **                                                                           **
 ******************************************************************************/
void TstM_PostRun(void)
{
  Std_ReturnType Result = E_NOT_OK;
  uint32 LoopCount = 0;
  uint8 CoreId;

  /* Invalidate seed, test results and test signatures for post-run phase */
  TstM_InvalidateData();
  
  CoreId = Mcal_GetCoreId();

  if (SL_MASTER_CORE_ID == CoreId)
  {
    Result = Sl_SwitchTstPhase(SL_POSTRUN);
    if (E_OK != Result)
    {
      AppCbk_ErrorHandler(APLCBK_SL_SWITCH_PHASE_FAIL);
    }
  }
  else
  {  
    /* Get seed from watchdog */
//     SafeWdgM_GetSeed(&TstM_TstSeed);
    
    Result = Sl_ExecPostRunTst(TstM_TstSeed, TstGroupIndex,
            TstM_TestSignatures[CoreId], TstM_TestResults[CoreId]);
    if (E_OK == Result)
    {
      /* Post_Run TstM raise alarm on test failure */
      for (LoopCount = 0; LoopCount < TH_TOTAL_TESTS; LoopCount++)
      {
        if (TstM_TestResults[CoreId][LoopCount] != TEST_PASS) /* Test(s) in test group fails */
        {
        Result = Smu_SetAlarmStatus(TSTM_ALM_GROUP, TSTM_ALM_POS);
        if (E_NOT_OK == Result)
        {
          AppCbk_ErrorHandler(APLCBK_SMU_SET_ALARM_FAIL);
        }
        break;
        }
      }
    }
    else
    {
      AppCbk_ErrorHandler(APLCBK_SL_POST_RUN_TST_FAIL);
    }
  }
}
#endif

/*******************************************************************************
 **                                                                           **
 ** Syntax           : uint32 TstM_GetConsolidatedSignature(void)             **
 **                                                                           **
 ** Service ID       : none                                                   **
 **                                                                           **
 ** Sync/Async       : Synchronous                                            **
 **                                                                           **
 ** Reentrancy       : Non-reentrant                                          **
 **                                                                           **
 ** Parameters (in)  : None                                                   **
 **                                                                           **
 ** Parameters (out) : None                                                   **
 **                                                                           **
 ** Return value     : Final overall consolidated signature that would be     **
 **                     service the watchdog.                                 **
 **                                                                           **
 ** Description      : Consolidates signatures for all cores                  **
 **                                                                           **
 ******************************************************************************/
uint32 TstM_GetConsolidatedSignature(void)
{
  uint32 ConsolidatedSignature = 0;

  /* Use consolidated signature of Core 0, if core 0 participates in run-time phase */ 
  if(TstM_ConsolidatedSignCoreX[0] != 0U)
  {
    ConsolidatedSignature = CRC32(ConsolidatedSignature, TstM_ConsolidatedSignCoreX[0]) ;
  }

  #if ( MCAL_NO_OF_CORES > 1U )
  /* Use consolidated signature of Core 1, if core 1 participates in run-time phase */ 
  if(TstM_ConsolidatedSignCoreX[1] != 0U)
  {
    ConsolidatedSignature = CRC32(ConsolidatedSignature, TstM_ConsolidatedSignCoreX[1]) ;
  }
  #if ( MCAL_NO_OF_CORES == 3U )
  /* Use consolidated signature of Core 2, if core 2 participates in run-time phase */ 
  if(TstM_ConsolidatedSignCoreX[2] != 0U)
  {
    ConsolidatedSignature = CRC32(ConsolidatedSignature, TstM_ConsolidatedSignCoreX[2]) ;
  }
  #endif /* ( MCAL_NO_OF_CORES == 3U ) */
  #endif /* ( MCAL_NO_OF_CORES > 1U ) */
  return ConsolidatedSignature;
}

/*******************************************************************************
 **                                                                           **
 ** Syntax           : void TstM_InvalidateData(void)                         **
 **                                                                           **
 ** Service ID       : none                                                   **
 **                                                                           **
 ** Sync/Async       : Synchronous                                            **
 **                                                                           **
 ** Reentrancy       : Non-reentrant                                          **
 **                                                                           **
 ** Parameters (in)  : None                                                   **
 **                                                                           **
 ** Parameters (out) : None                                                   **
 **                                                                           **
 ** Return value     : None                                                   **
 **                                                                           **
 ** Description      : Invalidates seed, test results and test signatures     **
 **                                                                           **
 ******************************************************************************/
void TstM_InvalidateData(void)
{
  uint8 CoreId;
  Sl_TstIndexType TstIdx;

  CoreId = Mcal_GetCoreId();

  if (SL_MASTER_CORE_ID == CoreId)
  {
    TstM_TstSeed = SAFEWDG_SEED_NOTVALID;
  }
  
  for (TstIdx = 0U; TstIdx < TH_TOTAL_TESTS; TstIdx++)
  {
    TstM_TestResults[CoreId][TstIdx] = TH_TST_NOT_EXECUTED;
    TstM_TestSignatures[CoreId][TstIdx] = (uint32)0U ;
  }
  
  TstM_ConsolidatedSignCoreX[CoreId] = 0x00;
}

/*******************************************************************************
**                                                                            **
** Syntax           : Sl_TstRsltType TstM_GetTstResult(Sl_TstIndexType TstIdx)**
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : TstID : The Test Id for which Result is requested       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Sl_TstRsltType                                          **
**                    TH_TST_NOT_EXECUTED : Test is not executed              **
**                    Non-zero value : Test result                            **
**                                                                            **
** Description      :  This function is used to retrieve the test result      **
**                        for the test index passed                           **
**                                                                            **
*******************************************************************************/

Sl_TstRsltType TstM_GetTstResult(Sl_TstIndexType TstIdx)
{
  uint8 CoreId;
  Sl_TstRsltType Result;
  
  CoreId = Mcal_GetCoreId(); 
  Result = TH_TST_NOT_EXECUTED;
  
  if (TstIdx < TH_TOTAL_TESTS)
  {
    Result = TstM_TestResults[CoreId][TstIdx] ;
  }
  return Result;
}

#if ((SL_IGNORE_SIGNATUREVALIDATE == FALSE) || (SL_RUNTIME_TESTS == TRUE))
/*******************************************************************************
 **                                                                           **
 ** Syntax           : void TstM_lConsolidateSigCoreX(void)                   **
 **                                                                           **
 ** Service ID       : none                                                   **
 **                                                                           **
 ** Sync/Async       : Synchronous                                            **
 **                                                                           **
 ** Reentrancy       : Non-reentrant                                          **
 **                                                                           **
 ** Parameters (in)  : None                                                   **
 **                                                                           **
 ** Parameters (out) : None                                                   **
 **                                                                           **
 ** Return value     : None                                                   **
 **                                                                           **
 ** Description      : Consolidation of signatures for one core               **
 **                                                                           **
 ******************************************************************************/
static void TstM_lConsolidateSigCoreX(void)
{
  uint32 ConsolidatedSignCoreX = 0 ;
  Sl_TstIndexType TstIdx;
  uint8 CoreId;

  CoreId = Mcal_GetCoreId();
  
  /* Consolidation of signatures for one core */
  for (TstIdx = 0; TstIdx < TH_TOTAL_TESTS ; TstIdx++)
  {
    if(TstM_TestSignatures[CoreId][TstIdx] != 0U)
    {
      ConsolidatedSignCoreX = CRC32(ConsolidatedSignCoreX, TstM_TestSignatures[CoreId][TstIdx]);
    }
  }

  if(Application_Check_Results != 0U)
  {
    ConsolidatedSignCoreX = CRC32(ConsolidatedSignCoreX, Application_Check_Results);
  }
  
  TstM_ConsolidatedSignCoreX[CoreId] = ConsolidatedSignCoreX ;
}
#endif

#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
