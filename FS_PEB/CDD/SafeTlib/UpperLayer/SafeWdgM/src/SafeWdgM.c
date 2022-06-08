/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                                                              **
**   $FILENAME   : SafeWdgM.c $                                               **
**                                                                                                              **
**   $CC VERSION : \main\32 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                **     
**                                                                            **
**  PLATFORM  : Infineon AURIX                                           **     
**                                                                            **
**  COMPILER  : Tasking                                                  **     
**                                                                            **
**  AUTHOR    : SafeTlib Team                                             **    
**                                                                            **
**  VENDOR    : Infineon Technologies                                     **    
**                                                                            **
**  TRACEABILITY: 
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - Functionality of Safe Watchdog Manager                   **
**                                                                            **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/


/******************************************************************************
**                      Includes                                              *
******************************************************************************/

#include "Mcal.h"

#include "SafeWdgIf.h"

#include "SafeWdgM.h"
#include "TstM.h"
#include "AppCbk.h"
#include "Test_Time.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

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

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

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

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
** Traceability     :                                                                                       
**                                                                                                              
** Syntax           : SafeWdgIf_ResultType SafeWdgM_Init(uint8 ConfigIdx)                      
** [/cover]                                                                                                  
**                                                                                                              
** Service ID       : none                                                                                  
**                                                                                                              
** Sync/Async       : Synchronous                                                                     
**                                                                                                              
** Reentrancy       : Non-reentrant                                                                     
**                                                                                                              
** Parameters (in)  : ConfigIdx - watchdog Configuration index to be used for initialization      
**                                                                                                              
** Parameters (out) : None                                                                              
**                                                                                                             
** Return value     : SWDG_JOB_SUCCESS, if initialization is successful.                                
**                         SWDG_JOB_FAILED, if error occurs                                              
**                                                                                                              
**                                                                                                              
** Description      : Initialise and activates underlying watchdog hardware by using SafeWdgIf  
**            interface.Can be used by application software to Initialize SafeWdg Stack.  
**                                                                                                           
**                                                                                                              
*******************************************************************************/
void SafeWdgM_Init(uint8 ConfigIdx)
{
  SafeWdgIf_ResultType InitResult = SWDG_JOB_FAILED;

  if (ConfigIdx < SAFEWDGIF_CFG_COUNT)
  {         

      /* Initialise watchdog interface*/
        InitResult = SafeWdgIf_Init(&SafeWdgIf_ConfigRoot[ConfigIdx]);


  }


  /* Call error handler hook if watchdog init is not successful*/
  if((InitResult != SWDG_JOB_SUCCESS) && (InitResult != SWDG_JOB_ACCEPTED))
  {
     AppCbk_ErrorHandler(APLCBK_SWDGIF_INIT_FAIL);
  }

}

/*******************************************************************************
** Traceability     :                                                                                       
**                                                                                                              
** Syntax           : void SafeWdgM_DeInit(void)                                                  
** [/cover]                                                                                                  
**                                                                                                              
** Service ID       : none                                                                                 
**                                                                                                             
** Sync/Async       : Synchronous                                                  
**                                                                                                              
** Reentrancy       : Non-reentrant                                                                     
**                                                                                                              
** Parameters (in)  : None                                                                                
**                                                                                                              
** Parameters (out) : None                                                                               
**                                                                                                             
** Return value     : None                                                                               
**                                                                                                             
**                                                                                                              
** Description      : Deinitalize configured watchdog.
** -None                                                                                                      
**                                                                                                              
*******************************************************************************/

void SafeWdgM_DeInit(void)
{

    SafeWdgIf_ResultType DeInitResult = SWDG_JOB_FAILED;

    /* Deinitize configurd Watchdog */
    DeInitResult = SafeWdgIf_DeInit();    

    /*Check if Deinit is succesful Else call error hook */
    if((DeInitResult != SWDG_JOB_SUCCESS) && (DeInitResult != SWDG_JOB_ACCEPTED))
    {
      AppCbk_ErrorHandler(APLCBK_SWDGIF_ACT_FAIL);
    }


}

/*******************************************************************************
** Traceability     :                                                                                       
**                                                                                                              
** Syntax           : void SafeWdgM_Activate(void)                                                  
** [/cover]                                                                                                  
**                                                                                                              
** Service ID       : none                                                                                 
**                                                                                                             
** Sync/Async       : Synchronous                                                  
**                                                                                                              
** Reentrancy       : Non-reentrant                                                                     
**                                                                                                              
** Parameters (in)  : None                                                                                
**                                                                                                              
** Parameters (out) : None                                                                               
**                                                                                                             
** Return value     : None                                                                               
**                                                                                                             
**                                                                                                              
** Description      : Activates underlying watchdog hardware by using SafeWdgIf             
**               interface.Can be used by application software to activate SafeWdg Stack.  
**              After activation applicaiton has to serviced periodically according to Wdg    
**              configuration.This interface is not recomended to activate CIC as it needs   
**              a special sequence.
** -None                                                                                                      
**                                                                                                              
*******************************************************************************/

void SafeWdgM_Activate(void)
{

    SafeWdgIf_ResultType ActivateResult = SWDG_JOB_FAILED;

    /*Perform non CIC specific SafeWDG CD activation*/
    ActivateResult = SafeWdgIf_Activate();    

    /*Check if WD is succesfully activated. Else call error hook */
    if((ActivateResult != SWDG_JOB_SUCCESS) && (ActivateResult != SWDG_JOB_ACCEPTED))
    {
      AppCbk_ErrorHandler(APLCBK_SWDGIF_ACT_FAIL);
    }


}

/*******************************************************************************
** Traceability     :                                                                                       
**                                                                                                              
** Syntax           : SafeWdgIf_ResultType SafeWdgM_GetSeed(uint8* TstSeed)                  
** [/cover]                                                                                                   
**                                                                                                              
** Service ID       : none                                                                                
**                                                                                                              
** Sync/Async       : Synchronous                                                                     
**                                                                                                              
** Reentrancy       : Non-reentrant                                                                     
**                                                                                                              
** Parameters (in)  : None                                                                                
**                                                                                                              
** Parameters (out) : Seed extracted from SafeWdg stack.                                                 
**                                                                                                           
** Return value     : SWDG_JOB_SUCCESS, if seed extraction is successful.                           
**                    SWDG_JOB_FAILED, if error occurs                                              
**                                                                                                             
** Description      : Get Seed from underlying watchdog using SafeWdgIf interface.This seed    
**              will be used in upcomming DTI.                                      
** -None                                                                                                      
**                                                                                                              
*******************************************************************************/

void SafeWdgM_GetSeed(uint8* TstSeed)
{
  SafeWdgIf_ResultType Result_GetSeed = SWDG_JOB_FAILED;
  
  uint8 NewSeed = SAFEWDG_SEED_NOTVALID;

  Result_GetSeed = SafeWdgIf_GetSeed(&NewSeed);

  if (Result_GetSeed != SWDG_JOB_SUCCESS)
  {
    AppCbk_ErrorHandler(APLCBK_SWDGIF_GTSED_FAIL);
  }
  else
  {
    /*Check if received seed is valid*/
    if (NewSeed != SAFEWDG_SEED_NOTVALID )
    {
      *TstSeed = NewSeed;
    }
  }
  
}

/*******************************************************************************
** Traceability     :                                                                                        
**                                                                                                              
** Syntax           : SafeWdgIf_ResultType SafeWdgM_Service(void)                                
** [/cover]                                                                                                   
**                                                                                                              
** Service ID       : none                                                                                
**                                                                                                              
** Sync/Async       : ASynchronous                                                                     
**                                                                                                              
** Reentrancy       : Non-reentrant                                                                     
**                                                                                                              
** Parameters (in)  : None                                                                                  
**                                                                                                              
** Parameters (out) : None                                                                              
**                                                                                                              
** Return value    :    SWDG_JOB_SUCCESS, Watchdog serviced successfuly.                     
**                   SWDG_JOB_ACCEPTED Service job accepted and ongoing                   
**                      SWDG_JOB_FAILED: Servicing failed                                            
** Description      :     Services the Watchdog with final signature.                                
*******************************************************************************/
void SafeWdgM_Service(void)
{
  uint32 ConsolidatedSignature;
  SafeWdgIf_ResultType  ServiceResult;

  /* Obtain overall consolidated signature from Test Manager*/
  ConsolidatedSignature = TstM_GetConsolidatedSignature();

  /* Service SafeWD*/
  ServiceResult = SafeWdgIf_Service(ConsolidatedSignature);

  /*Call Error hook if job result is not success / accepted*/
  if( (ServiceResult != SWDG_JOB_SUCCESS) && (ServiceResult != SWDG_JOB_ACCEPTED) )
  {
    AppCbk_ErrorHandler(APLCBK_WDGIF_SERV_FAIL);
  }

  /*Invalidate seed and signature, used in current DTI. */
  TstM_InvalidateData();  

}

#ifndef SWDG_INT_WDG_ONLY
/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : SafeWdgIf_ResultType SafeWdgM_UserRequest               **
** [/cover]                                     (SafeWdgIf_CmdType* UserCmd)) **
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
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Send user request to selected External Watchdog         **
** -None              Size should be four                                     **
**                                                                            **
*******************************************************************************/
void SafeWdgM_UserRequest(SafeWdgIf_CmdType* UserCmd, uint8 size)
{

  SafeWdgIf_ResultType URResult = SWDG_JOB_FAILED;

    /* Send User request */
  URResult = SafeWdgIf_UserRequest(UserCmd, size );

  if (URResult != SWDG_JOB_ACCEPTED)
  {
     AppCbk_ErrorHandler(APLCBK_SWDGIF_GTSED_FAIL);
  }  


} /* SafeWdgIf_ResultType SafeWdgM_UserRequest(SafeWdgIf_CmdType* UserCmd) */


/*******************************************************************************
** Traceability     :
**
** Syntax           : SafeWdgIf_ResultType SafeWdgM_GetJobResult()
** [/cover]
**
** Service ID       : none
**
** Sync/Async       : Synchronous
**
** Reentrancy       : Non-reentrant
**
** Parameters (in)  : None
**
** Parameters (out) : None
**
** Return value     : SWDG_JOB_SUCCESS: Operation successfully performed
**                    SWDG_JOB_ACCEPTED: Accepted Job still ongoing
**                    SWDG_JOB_FAILED: Operation failed
**
** Description      : Application software can use this  API to get the status of the job requested
**              asynchronously                                                                
**            This interface is available only if CIC / TLF external Wdg is used          
*******************************************************************************/

SafeWdgIf_ResultType SafeWdgM_GetJobResult(void)
{
  SafeWdgIf_ResultType RetVal;
  
  RetVal = SafeWdgIf_GetJobResult();
  return(RetVal);
}

/*******************************************************************************
** Traceability     :                                                                                       
**                                                                                                              
** Syntax           : SafeWdgIf_ResultType SafeWdgM_GetErrCntr(uint8* ErrCtr)                  
** [/cover]                                                                                                   
**                                                                                                              
** Service ID       : none                                                                                
**                                                                                                              
** Sync/Async       : Synchronous                                                                     
**                                                                                                              
** Reentrancy       : Non-reentrant                                                                     
**                                                                                                              
** Parameters (in)  : None                                                                                
**                                                                                                              
** Parameters (out) : ErrCtr- Error counter of external watchdog.                        
**                                                                                                              
** Return value     : SWDG_JOB_SUCCESS: Error counter obtained successfully               
**                      SWDG_JOB_FAILED: Operation failed                                        
**                                                                            
** Description      : Application can use this interface to get error count caused due to error in  
**            servicing watchdog.This interface can also used to read error count for fault
**            injection testing.
**            This interface is available only if CIC / TLF external Wdg is used          

**                                                                                                              
*******************************************************************************/

void SafeWdgM_GetErrCntr(uint8* const ErrCtr)
{
  SafeWdgIf_ResultType Result = SWDG_JOB_FAILED;
  uint8 NewErrCtr = 0;

  /*Get error counter using SafeWdgIf */
  Result = SafeWdgIf_GetErrCntr(&NewErrCtr);

  if (Result != SWDG_JOB_SUCCESS)
  {
     AppCbk_ErrorHandler(APLCBK_ERR_INJ_FAIL);

  }
  else
  {
    /* updated new error counter value */
    *ErrCtr = NewErrCtr;
  }
    
}

#endif
/*******************************************************************************
** Traceability     :                                                                                     
**                                                                            
** Syntax           : SafeWdgIf_ResultType SafeWdgM_GetJobResult()            
** [/cover]                                                                   
**                                                                            
** Service ID       : none                                                    
**                                                                            
** Sync/Async       : Synchronous                              
**                                                                            
** Reentrancy       : Non-reentrant                             
**                                                                            
** Parameters (in)  : None                                         
**                                                                            
** Parameters (out) : None                                        
**                                                                            
** Return value     : SWDG_JOB_SUCCESS: Error counter obtained successfully               
**                      SWDG_JOB_FAILED: Operation failed                                        
**                                                                            
** Description      : Application can use this interface to get actual state of external watchdog.
**              (if external watchdog is active / Init / failure  state etc..)
**              This interface is available only if CIC / TLF external Wdg is used          
**                                                                            
*******************************************************************************/
SafeWdgIf_StateType SafeWdgM_GetState(void)
{
  SafeWdgIf_StateType RetVal;

  RetVal =  SafeWdgIf_GetState();

  return(RetVal);
}


#ifndef SWDG_INT_WDG_ONLY
/*******************************************************************************
** Traceability     :                                                                                     
**                                                                            
** Syntax           : SafeWdgIf_ResultType SafeWdgM_Info()            
** [/cover]                                                                   
**                                                                            
** Service ID       : none                                                    
**                                                                            
** Sync/Async       : Synchronous                              
**                                                                            
** Reentrancy       : Non-reentrant                             
**                                                                            
** Parameters (in)  : None                                         
**                                                                            
** Parameters (out) : None                                        
**                                                                            
** Return value     : SWDG_JOB_SUCCESS: Error counter obtained successfully               
**                      SWDG_JOB_FAILED: Operation failed                                        
**                                                                            
** Description      : Application can use this interface to get actual state of external watchdog.
**              (if external watchdog is active / Init / failure  state etc..)
**              This interface is available only if CIC / TLF external Wdg is used          
**                                                                            
*******************************************************************************/
void SafeWdgM_GetWdgInfo(void)
{  
  SafeWdgIf_ResultType Result = SWDG_JOB_FAILED;

  Result = (uint8) SafeWdgIf_GetWdgInfo();
  
  if (Result != SWDG_JOB_ACCEPTED)
  {
         AppCbk_ErrorHandler(APLCBK_CIC_GETINFO_FAIL);
    }

}

#endif

#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

