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
**  $FILENAME   : AppCbk.c $                                                 **
**                                                                            **
**  $CC VERSION : \main\31 $                                                 **
**                                                                            **
**  $DATE       : 2016-03-08 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking, GNU, WINDRIVER                                                        **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains stub for AppCbk_ErrorHandler                                     **
**                                                                            **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

#include "Std_Types.h"
#include "Mcal.h"
#include "AppCbk.h"
#include "TstHandler.h"
#include "IfxCpu_reg.h"
#include "TstM.h"



#if (SAFETLIB_APPLN_DEBUG == TRUE)   
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ CAUTION ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/* This array needs to be updated whenever ApplCbk_ErrorIdType is updated in 
   file ApplCbk.h */   
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ CAUTION ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/* Global array which contains all possible call back error-ID type information */
const char AplCbk_ErrorNames[][50] =
{
"APLCBK_PRERUN_INIT_FAIL",
"APLCBK_SWDGM_INIT_FAIL",
"APLCBK_SWDGIF_SERV_FAIL",
"APLCBK_TSTM_INIT_FAIL",
"APLCBK_POSTRUN_TST_FAIL",
"APLCBK_WDG_SERV_FAIL",
"APLCBK_WDG_DISABLE_STATE",
"APLCBK_TST_MNG_FAIL",
"APLCBK_RUNTIM_DTI_OVRSHOOT",
"APLCBK_TST_SEED_CORPT",
"APLCBK_NEW_SEED_FAIL",
"APLCBK_INV_SEEDSIG_FAIL",
"APLCBK_WDGIF_SERV_FAIL",
"APLCBK_SWDGIF_INIT_FAIL",
"APLCBK_SWDGIF_ACT_FAIL",
"APLCBK_SWDGIF_GTSED_FAIL",
"APLCBK_SMU_SET_ALARM_FAIL",
"APLCBK_SL_INIT_FAIL",
"APLCBK_WDGM_GET_SEED_FAIL",
"APLCBK_SL_PRE_RUN_TST_FAIL",
"APLCBK_SL_SWITCH_PHASE_FAIL",
"APLCBK_TSTM_INV_SEED_SIG_FAIL",
"APLCBK_SL_RUN_TST_FAIL",
"APLCBK_SL_POST_RUN_TST_FAIL",
"APLCBK_TSTM_INVALID_PHASE",
"APLCBK_SWDGIF_GETSTATE_FAIL",
"APLCBK_SL_EARLYPRE_RUN_TST_FAIL",
"APLCBK_SWDGIF_CHMOD_FAIL",
"APLCBK_CIC_USRCMD_FAIL",
"APLCBK_SWDGM_REINIT_FAIL",
"APLCBK_ERR_INJ_FAIL",     
"APLCBK_ERR_SPINLOCK_FAIL",
"APLCBK_ERR_TASK_BUDGET_OVRRUN",   
"APLCBK_CIC_TRIP_FAIL",           
"APLCBK_CIC_CYCLE_FAIL",           
"APLCBK_CIC_MAXJOBS_FAIL",         
"APLCBK_CIC_GETINFO_FAIL",        
"APLCBK_CIC_VERSION_FAIL",        
"APLCBK_WDG_TASK1_FAIL",       
"APLCBK_WDG_TASK2_FAIL",      
"APLCBK_WDG_TASK3_FAIL",          
"APLCBK_WDG_SPIERR_FAIL",
"APLCBK_TLF_MAXJOBS_FAIL",
"APLCBK_TLF_ABIST_FAIL"
};
#endif

extern void RA_Stop(void);

#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void AppCbk_ErrorHandler(ApplCbk_ErrorIdType ErrorId)             **
**                                                                            **
** Description :  This function gives notification to user incase of          **
        test failure at any phase of SafeTlib                                 **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : void                                                        **
*******************************************************************************/
void AppCbk_ErrorHandler(ApplCbk_ErrorIdType ErrorId)
{
  uint8 CoreId;
  CoreId = ((uint8)MFCR(CPU_CORE_ID) & (uint8)0x3U);


  switch(ErrorId)
  {
    /* Print information about tests failed and test result */
    case APLCBK_SL_EARLYPRE_RUN_TST_FAIL:
    case APLCBK_SL_PRE_RUN_TST_FAIL:
    case APLCBK_SL_RUN_TST_FAIL:
    case APLCBK_SL_POST_RUN_TST_FAIL:    
    {
#if (SAFETLIB_APPLN_DEBUG == TRUE)       
      Sl_TstIndexType TstIdx ;
      
      for(TstIdx = 0; TstIdx < TH_TOTAL_TESTS ; TstIdx++)
      {
        if (TstM_GetTstResult(TstIdx) != TH_TST_NOT_EXECUTED)
        {
          if(!SL_SUCCESS(TstM_GetTstResult(TstIdx)))
          {

          } /*End of (SL_FAILURE !=  SL_SUCCESS(TstM_GetTstResult(TstIdx)))*/
        } /* End of (TstM_GetTstResult(TstIdx) != 0)*/
      }
#endif      
    }
    break;
	default:
	break;
  }  
//  RA_Stop();
}

#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
