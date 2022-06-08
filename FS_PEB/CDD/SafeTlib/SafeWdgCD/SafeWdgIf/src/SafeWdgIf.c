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
**   $FILENAME   : SafeWdgIf.c $                                              **
**                                                                            **
**   $CC VERSION : \main\46 $                                                 **
**                                                                            **
**   $DATE       : 2017-10-07 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of SafeWdg Interface driver                **
**                                                                            **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                               *
*******************************************************************************/
#include "Mcal.h"
#include "SafeWdgIf.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define SAFEWDGIF_INVALIDATE_CRC           (0x0U)

/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef enum WdgMode_Type
{
  /* No Watchdog is configured */
  WDGNOT_CFG = 0u,
  /* External CIC61508 watchdog is configured. */
  CIC_WDG, 
  /* External TLF watchdog is configured. */  
  TLF_WDG, 
  /* Internal watchdog alone configured. */  
  INT_WDG,
  /* External TLF + Internal watchdog mode is configured. */  
  TLFINT_WDG   
}WdgMode_Type; 


/* used module local safe variables */
typedef struct SafeWdgIf_DataType
{ 
    /* current configuration pointer */
    const SafeWdgIf_ConfigType*     ConfigPtr;         
    /* CRC for this safety relevant data set */
    uint32                          Crc;       
    /* Store the configured watchdog. Volatile keyword is added to avoid
       compiler optimization    */
    volatile WdgMode_Type           WdgMode;    
    
} SafeWdgIf_DataType;

   

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


#define IFX_SWDG_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

static SafeWdgIf_DataType SafeWdgIfData        = { NULL_PTR, 0U, WDGNOT_CFG};

#define IFX_SWDG_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"


#define IFX_SWDG_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

static Std_ReturnType SafeWdgIf_lCheckDataCrc
(
  void
);
static void           SafeWdgIf_lSetDataCrc
(
  void
);

/*******************************************************************************
 **                       Function Definitions                                **
 ******************************************************************************/
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgIf_Init                               **
**                     (const SafeWdgIf_ConfigType* const ConfigPtr)          **
**                                                                            **
** Description : Initialize Safe watchdog  Interface                          **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) :    ConfigPtr: pointer to configuration                   **
** Parameters (out):    None                                                  **
** Return value    :    SWDG_JOB_SUCCESS: No error occurred                   **
**                      SWDG_JOB_ACCEPTED: Init Job accepted and ongoing      **
**                      SWDG_JOB_INV_PARAM:Job failed due to invalid parameter**
**                      SWDG_JOB_INV_STATE:Job failed because job is requested** 
**                                         from a forbidden state             **
**                      SWDG_JOB_COM_ERR: Job failed due to SPI module        **
**                                        initialization failure              **
**                                                                            **
*******************************************************************************/

SafeWdgIf_ResultType SafeWdgIf_Init
(
   const SafeWdgIf_ConfigType* const ConfigPtr
)
{

    volatile SafeWdgIf_ResultType Result = SWDG_JOB_INV_PARAM;  
    

    /* Store configuration pointer */
  
    if (ConfigPtr != NULL_PTR)
    {
      
        SafeWdgIfData.ConfigPtr = ConfigPtr;
      
        #ifdef SWDG_INT_WDG_ONLY
          /* Internal watchdog alone configured. */
              SafeWdgIfData.WdgMode = INT_WDG;
        #endif  
              
        #ifdef SWDG_EXT_CIC_WDG_ONLY
            /* External CIC61508 watchdog alone configured. */
              SafeWdgIfData.WdgMode = CIC_WDG;
        #endif
              
        #ifdef SWDG_EXT_TLF_WDG_ONLY
            /* External TLF watchdog alone configured. */
              SafeWdgIfData.WdgMode = TLF_WDG;
        #endif       
        
        #ifdef SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG
            /* External TLF + Internal watchdog alone configured. */
              SafeWdgIfData.WdgMode = TLFINT_WDG;       
        #endif

       /* Update based on configured watchdog */        
       switch(SafeWdgIfData.WdgMode)
       {       
      
         case CIC_WDG:
         case TLF_WDG:
         {
             /*Either CIC / TLF External watchdog alone configured.*/
             if(ConfigPtr->DriverExtConfigPtr != NULL_PTR)
             {          
               
               /*Init External watchdog*/
               Result = SafeWdgIf_CfgExtInitFn(ConfigPtr->DriverExtConfigPtr);

             }    
        
         }
         break;

         case INT_WDG:
         {
           /* Internal watchdog alone configured. Initialize internal 
              watchdog*/
            if ( ConfigPtr->DriverIntConfigPtr != NULL_PTR )
            {  
              
              Result = SafeWdgIf_CfgIntInitFn( ConfigPtr->DriverIntConfigPtr );
           
            } 
         }  
         break;
         
         case TLFINT_WDG:
         {
            
          /* Init is success if both Internal and TLF watchdog is initialized */
            if ( ConfigPtr->DriverIntConfigPtr != NULL_PTR )
            {

               /* Initialize internal watchdog*/
               Result = SafeWdgIf_CfgIntInitFn( ConfigPtr->DriverIntConfigPtr );               
 

               if(Result == SWDG_JOB_SUCCESS)
               {
                 /* Check if IntWdg + TLF mode is selected */
                 if(ConfigPtr->DriverExtConfigPtr != NULL_PTR)
                 {
                   /*Init external Tlf watchdog*/
                    Result = 
                         SafeWdgIf_CfgExtInitFn(ConfigPtr->DriverExtConfigPtr);
                 } /*  if( E_OK == SafeWdgInt_Init
                                          ( ConfigPtr->DriverIntConfigPtr ))*/
                 else
                 {
                     Result = SWDG_JOB_INV_PARAM;
                 
                 }

               } /* if(Result == SWDG_JOB_SUCCESS) */

            }
         }  
         
         break;
         
         default:         
         break; 
            
      }      
      
      SafeWdgIf_lSetDataCrc();
    }

    return (Result);
}


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgIf_DeInit (void)                      **
**                                                                            **
** Description :    Move driver state back to reset state                     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non-Reentrant                                                  **
**                                                                            **
** Parameters (in) :     None                                                 **
** Parameters (out):     None                                                 **
** Return value    :    SWDG_JOB_SUCCESS: DeInit successful                   **
**                      SWDG_JOB_ACCEPTED: Job Accepted only if CIC selected  **
**                      SWDG_JOB_INV_PARAM:Job failed due to invalid parameter**
**                      SWDG_JOB_INV_STATE:Job failed because job is requested** 
**                                         from a forbidden state             **
**                      SWDG_JOB_BUSY: Job failed because driver is           **
**                                     busy processing the earlier job request**
**                                        initialization failure              **
*******************************************************************************/

SafeWdgIf_ResultType SafeWdgIf_DeInit 
(
   void 
)
{

  /* Deinit always allowed, call underlying driver based on watchdog 
     configuration*/
       
  SafeWdgIf_ResultType Result = SWDG_JOB_INV_PARAM;

        /* Update based on configured watchdog */     
       switch(SafeWdgIfData.WdgMode)
       {       
      
         case CIC_WDG:
         case TLF_WDG:
         {
            
            /*DeInit external configured watchdog*/
            Result = SafeWdgIf_CfgExtDeInitFn();
         }       
         break;

         case INT_WDG:
         {
            /*DeInit internal watchdog*/
            SafeWdgIf_CfgIntDeInitFn();
            Result = SWDG_JOB_SUCCESS;
       
         }  
         break;
         
         case TLFINT_WDG:
         { 
        
           /*DeInit intenal and external configured watchdog*/
            SafeWdgIf_CfgIntDeInitFn();             
            Result = SafeWdgIf_CfgExtDeInitFn();                              
           
         }  
         
         break;
         
        default:         
        break; 
      }      
    
    if(( Result == SWDG_JOB_SUCCESS) || ( Result == SWDG_JOB_ACCEPTED))
    {
        /* Result is success in case of internal watchdog and Accepted in case
         * of External watchdog */
         
        /* change driver state */
        SafeWdgIfData.ConfigPtr = NULL_PTR;   
        SafeWdgIfData.WdgMode   = WDGNOT_CFG; 
        SafeWdgIfData.Crc      ^= ~(SAFEWDGIF_INVALIDATE_CRC);
    }    
  return (Result);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgIf_Activate ( void )                  **
**                                                                            **
** Description :    Activate the watchdog to require being serviced afterwards**
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non-Reentrant                                                  **
**                                                                            **
** Parameters (in) :    None                                                  **
** Parameters (out):    None                                                  **
** Return value    :    SWDG_JOB_SUCCESS: Underlying watchdog(s)activated.    **
**                      SWDG_JOB_ACCEPTED: Job ongoing                        **
**                      SWDG_JOB_BUSY: Job failed because driver is busy      **
**                                      processing the earlier job request.   ** 
**                      SWDG_JOB_INV_STATE: Job failed because job is         **
**                                          requested from a forbidden state. **
**                      SWDG_JOB_FAILED_CRC: Job failed due to driver         **
**                                           internal data checksum failure   **
**                      SWDG_JOB_INV_PARAM: Job failed due to invalid         ** 
**                                           parameter.                       **
*******************************************************************************/

SafeWdgIf_ResultType SafeWdgIf_Activate 
( 
  void 
)
{

  volatile SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC; 
 

  if( SafeWdgIf_lCheckDataCrc() == E_OK)
  {
      
    
      /* Update based on configured watchdog */     
       switch(SafeWdgIfData.WdgMode)
       {       
      
         case CIC_WDG:
         case TLF_WDG:
         {
            
                /*Activate external watchdog*/
                Result = SafeWdgIf_CfgExtActivateFn();
         }       
         break;

         case INT_WDG:
         {
              /*Activate internal watchdog*/
              Result = SafeWdgIf_CfgIntActivateFn();
       
         }  
         break;
         
         case TLFINT_WDG:
         {
     
              /*Activate internal watchdog*/
              Result = SafeWdgIf_CfgIntActivateFn();
              
              if (Result == SWDG_JOB_SUCCESS)
              {
                /* Activate external TLF watchdog*/               
                Result = SafeWdgIf_CfgExtActivateFn();
                
              }    
           
         }  
         
         break;
         
        default:  
        Result = SWDG_JOB_INV_PARAM; 
        break; 
            
      }           

    
  }
  return (Result);
}


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgIf_Service (const uint32 Signature)   **
**                                                                            **
** Description :     Watchdog service with given signature                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non-Rreentrant                                                 **
**                                                                            **
** Parameters (in) :  Signature: value to be used to service underlying       **
**                    watchdog                                                **
** Parameters (out):  None                                                    **
** Return value    :    SWDG_JOB_SUCCESS, Watchdog serviced successfully.     **
**                      SWDG_JOB_ACCEPTED Service job accepted and ongoing    **
**                      SWDG_JOB_FAILED_SERVICE:                              **
**                                       Job failed due to service failure.   **
**                      SWDG_JOB_INV_STATE: Job failed because job is         **
**                                          requested from a forbidden state. **
**                      SWDG_JOB_FAILED_CRC: Job failed due to driver         **
**                                           internal data checksum failure   **
**                      SWDG_JOB_INV_PARAM: Job failed due to invalid         ** 
**                                           parameter.                       **
*******************************************************************************/


SafeWdgIf_ResultType SafeWdgIf_Service 
(
  const uint32 Signature
)
{

  volatile SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;
  
  if( SafeWdgIf_lCheckDataCrc() == E_OK)
  {


        /* Update based on configured watchdog */     
       switch(SafeWdgIfData.WdgMode)
       {       
      
         case CIC_WDG:
         case TLF_WDG:
         {
            
                /*Service only external watchdog */
                Result = SafeWdgIf_CfgExtServiceFn(Signature);
         }       
         break;

         case INT_WDG:
         {
              /*Service internal watchdog*/
              Result = SafeWdgIf_CfgIntServiceFn(Signature);
       
         }  
         break;
         
         case TLFINT_WDG:
         {
     
             /*Service internal watchdog*/
             Result = SafeWdgIf_CfgIntServiceFn(Signature);
                 
             /* Service external TLF watchdog only if internal watchdog 
                service has passed */
             if (Result == SWDG_JOB_SUCCESS)
             {
              
                /*Service external TLF watchdog */               
                Result = SafeWdgIf_CfgExtServiceFn(Signature);
                
             }    
           
         }           
         break;
         
        default:
        Result = SWDG_JOB_INV_PARAM; 
        break; 
            
      }
   } 


  return (Result);
}


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgIf_GetSeed (uint8* const NextSeedPtr) **
**                                                                            **
** Description :    deliver next seed to be used                              **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non-Reentrant                                                  **
**                                                                            **
** Parameters (in) :    none                                                  **
** Parameters (out):    *NextSeedPtr: updated seed value                      **
** Return value    :    SWDG_JOB_SUCCESS, Seed value updated successfully.    **
**                      SWDG_JOB_FAILED_CRC: Job failed due to driver         **
**                                           internal data checksum failure.  **
**                      SWDG_JOB_INV_PARAM: Job failed due to invalid         ** 
**                                           parameter.                       **
**                      SWDG_JOB_INVALID_SEED: Job failed due to invalid seed.**
**                      SWDG_JOB_INV_STATE: Job failed because job is         **
**                                          requested from a forbidden state  **
**                                                                            **
**                                                                            **
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgIf_GetSeed 
(
  uint8* const NextSeedPtr
 )
{

  SafeWdgIf_ResultType Result = SWDG_JOB_INV_PARAM;
  if (NextSeedPtr != NULL_PTR)
  {
    
    if( SafeWdgIf_lCheckDataCrc() == E_OK)
    {
          /* Update based on configured watchdog */     
         switch(SafeWdgIfData.WdgMode)
         {       
        
           case CIC_WDG:
           case TLF_WDG:
           {
              
                 Result = SafeWdgIf_CfgExtGetSeedFn( NextSeedPtr );
           }       
           break;

           case INT_WDG:
           case TLFINT_WDG:
           {
           
              /* Note: If SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG option is  
              configured, External watchdog used will be TLF configured in
              Window mode. Hence there is no need to get seed from external 
              Watchdog(TLF). Seed got from internal watchdog will be used. */
           
              Result = SafeWdgIf_CfgIntGetSeedFn( NextSeedPtr );
               
           }  
           break;       
         
           
          default:         
          break; 
              
        }
    }
    else
    {
       Result = SWDG_JOB_FAILED_CRC;
    }     
  }
  return (Result);
}


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_StateType SafeWdgIf_GetState ( void )                   **
**                                                                            **
** Description :    read current state of watchdog                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non-Reentrant                                                  **
**                                                                            **
** Parameters (in) :   None                                                   **
** Parameters (out):   None                                                   **
** Return value    :    current state, if no error occurred                   **
**                      SAFEWDG_UNKNOWN on access error when reading current  **
**                      state                                                 **
**                                                                            **
*******************************************************************************/
SafeWdgIf_StateType SafeWdgIf_GetState 
(
  void 
)
{
  SafeWdgIf_StateType WdgState = {SAFEWDGIF_UNKNOWN, SAFEWDGIF_UNKNOWN};
    
    /* Get state from underlying watchdog */
  
  if( SafeWdgIf_lCheckDataCrc() == E_OK)
  {
        /* Update based on configured watchdog */     
       switch(SafeWdgIfData.WdgMode)
       {       
      
         case CIC_WDG:
         case TLF_WDG:
         {
                 /* Get state info from configured external watchdog */
                WdgState.ExtWdgState = SafeWdgIf_CfgExtGetStateFn();     
         }       
         break;

         case INT_WDG:
         {
                /* Get state info from internal watchdog */
                WdgState.IntWdgState = SafeWdgIf_CfgIntGetStateFn();      
         }
         break;
         case TLFINT_WDG:
         {  
         
                /* Note: if both internal and external TLF watchdogs are 
                   used, update both Int as well as Ext driver state 
                */
                       
                /* Get state info from internal watchdog */
                WdgState.IntWdgState = SafeWdgIf_CfgIntGetStateFn(); 
                /* Get state info from configured external watchdog */
                WdgState.ExtWdgState = SafeWdgIf_CfgExtGetStateFn();                 
             
         }           
         break;
         
        default:         
        break; 
            
      }
   }   

  return (WdgState);
}

#ifndef SWDG_INT_WDG_ONLY
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgIf_Info ( void )                      **
**                                                                            **
** Description :    read the status info of the configured watchdog           **
**                  This API is not used in case of internal watchdog         **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non-Rreentrant                                                 **
**                                                                            **
** Parameters (in) :   None                                                   **
** Parameters (out):   None                                                   **
** Return value    :   SWDG_JOB_ACCEPTED: Accepted Job still ongoing          **
**                     SWDG_JOB_FAILED_CRC: Job failed due to driver          **
**                                          internal data checksum failure.   ** 
**                     SWDG_JOB_BUSY: Job failed because driver is busy       **  
**                                    processing the earlier job request.     **
**                     SWDG_JOB_INV_PARAM:Job failed due to invalid           ** 
**                                           parameter.                       **
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgIf_GetWdgInfo 
(
  void
 )
{

   SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;  
   
   if( SafeWdgIf_lCheckDataCrc() == E_OK)
  {      
        /* Update based on configured watchdog */       
       switch(SafeWdgIfData.WdgMode)
       {       
      
         case CIC_WDG:
         case TLF_WDG:
         case TLFINT_WDG:
         {            
               /*Update information about configured external watchdog*/
               Result = SafeWdgIf_CfgExtInfo();
         }       
         break;

                
        default:
          Result = SWDG_JOB_INV_PARAM;        
          break; 
            
      }
   }   
  
  return (Result);
}


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgIf_GetErrCntr(uint8* const ErrCtrPtr) **
**                                                                            **
** Description :    read error counter status of the configured watchdog      **
**                  This API is not used in case of internal watchdog         **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non-Reentrant                                                  **
**                                                                            **
** Parameters (in) :   None                                                   **
** Parameters (out):   ErrCtrPtr: read error counter status                   **
** Return value    :   SWDG_JOB_ACCEPTED: Accepted Job still ongoing          **
**                     SWDG_JOB_FAILED_CRC: Job failed due to driver          **
**                                          internal data checksum failure.   ** 
**                     SWDG_JOB_INV_PARAM: Job failed due to invalid          ** 
**                                           parameter.                       **
**                     SWDG_JOB_INV_STATE: Job failed because job is          **
**                                         requested from a forbidden state   **
**                                                                            **
**                                                                            **
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgIf_GetErrCntr 
(
  uint8* const ErrCtrPtr 
)
{

  SafeWdgIf_ResultType Result = SWDG_JOB_INV_PARAM;

  if (ErrCtrPtr != NULL_PTR)
  {  

    if( SafeWdgIf_lCheckDataCrc() == E_OK)
    { 
     
       /* Update based on configured watchdog */          
       switch(SafeWdgIfData.WdgMode)
       {       
      
         case CIC_WDG:
         case TLF_WDG:
         case TLFINT_WDG:
         {            
               /* get Error count from underlying watchdog */
               Result = SafeWdgIf_CfgExtGetErrCntr(ErrCtrPtr);
         }       
         break;
         
                   
        default:      
          break; 
            
      }
    }
    else
    {
       Result = SWDG_JOB_FAILED_CRC;
    }    

   
  }
  return (Result);
}



/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgIf_UserRequest                        **
**                                   ( SafeWdgIf_CmdType* const UserCmdPtr    **
**                                     uint8 Count )                          **
**                                                                            **
** Description : Manage user request to read/send user commands to ext.       **
**               watchdog. This API is not used in case of internal watchdog  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non-Reentrant                                                  **
**                                                                            **
** Parameters (in) :  Count: No of commends to be send to watchdog            **
**                    UserCmdPtr: user buffer pointer                         **
** Parameters (out):                                                          **
** Return value    :  directly returns result from underlying service         **
**                     SWDG_JOB_FAILED_CRC: Job failed due to driver          **
**                                          internal data checksum failure.   ** 
**                     SWDG_JOB_INV_PARAM: Job failed due to invalid          ** 
**                                           parameter.                       **
**                     SWDG_JOB_INV_STATE: Job failed because job is          **
**                                         requested from a forbidden state   **
**                     SWDG_JOB_BUSY: Job failed because driver is busy       **
**                                      processing the earlier job request.   ** 
**                                                                            **
*******************************************************************************/

SafeWdgIf_ResultType SafeWdgIf_UserRequest
( 
    SafeWdgIf_CmdType* const UserCmdPtr,  
    uint8 Count 
)
{ 

  SafeWdgIf_ResultType Result = SWDG_JOB_INV_PARAM;

  if (UserCmdPtr != NULL_PTR) 
  {
    
    if(Count > 0U)
    {    
   
    
        if( SafeWdgIf_lCheckDataCrc() == E_OK)
        {     
    
              /* Update based on configured watchdog */      
              switch(SafeWdgIfData.WdgMode)
              {       
              
                case CIC_WDG:
                case TLF_WDG:
                case TLFINT_WDG:
                {            
                    /* Forward request to underlying external watchdog driver */
                    Result = SafeWdgIf_CfgExtUserReqFn( UserCmdPtr, Count );
                }       
                break;             
                 
                              
                default:         
                  break; 
                
              }  
        }
        else
        {
              Result = SWDG_JOB_FAILED_CRC;
        }
        
      }
      
  }
  
  return (Result);
}



/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : SafeWdgIf_ResultType SafeWdgIf_GetJobResult (void)      **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SWDG_JOB_SUCCESS: Operation successfully performed      **
**                    SWDG_JOB_ACCEPTED: Accepted Job still ongoing           ** 
**                    SWDG_JOB_FAILED_CRC: Job failed due to driver           **
**                                         internal data checksum failure.    ** 
**                    SWDG_JOB_INV_PARAM: Job failed due to invalid           ** 
**                                        parameter.                          **
**                    SWDG_JOB_INVALID_SEED: Job failed due to invalid seed.  **
**                    SWDG_JOB_INV_STATE: Job failed because job is           **
**                                        requested from a forbidden state    **
**                    SWDG_JOB_BUSY: Job failed because driver is busy        **
**                                      processing the earlier job request.   ** 
**                    SWDG_JOB_COM_ERR: Job failed due to SPI communication   **
**                                      failure.                              **
**                    SWDG_JOB_READBACK_FAIL: Job failed due TLF35584         **  
**                             protected configuration register write failure.**
**                    SWDG_JOB_RD_DATA_FAIL: Job failed due to mismatch in    **
**                              TLF35584 communication data readback.         **
**                    SWDG_JOB_INIT_FAIL: Job failed due to watchdog          ** 
**                                         disable request failure.           **
**                    SWDG_JOB_FAILED_SERVICE: Job failed due to service      **
**                                             failure.                       **
**                                                                            **
** Description      : This API provides the status of the job/operation       **
** requested by the user. This is typically used for asynchronous API         **
**  requests.   This API is not used in case of internal watchdog             **
**                                                                            **
*******************************************************************************/

SafeWdgIf_ResultType SafeWdgIf_GetJobResult
(
  void
)
{

  SafeWdgIf_ResultType RetVal = SWDG_JOB_FAILED_CRC;  
  
  if( SafeWdgIf_lCheckDataCrc() == E_OK)
    {    
 
        /* Update based on configured watchdog */      
       switch(SafeWdgIfData.WdgMode)
       {       
      
         case CIC_WDG:
         case TLF_WDG:
         case TLFINT_WDG:
         {            
            /* Forward request to underlying external watchdog driver */
            RetVal = SafeWdgIf_CfgExtJobResult( );
         }       
         break;
                    
        default:      
          RetVal = SWDG_JOB_INV_PARAM;        
          break; 
            
      }
    }       
  
  return(RetVal);
}

  #endif
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Std_ReturnType static Std_ReturnType SafeWdgIf_lCheckDataCrc()    **
**                                                                (void)      **
**                                                                            **
** Description :    check data set integrity by CRC validation                **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non-Reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
** Parameters (out): None                                                     **
** Return value    : E_OK, if Crc matches the stored on, data integrity okay  **
**                   E_NOT_OK otherwise                                       **
**                                                                            **
*******************************************************************************/

static Std_ReturnType SafeWdgIf_lCheckDataCrc
(
  void
)
{
  uint32 CurrCrc          = 0U;

  CurrCrc = (uint32)CRC32(CurrCrc, (uint32)((void*)SafeWdgIfData.ConfigPtr));
  CurrCrc = (uint32)CRC32(CurrCrc, (uint32)((void*)SafeWdgIfData.WdgMode));

  return ((CurrCrc == SafeWdgIfData.Crc) ? E_OK : E_NOT_OK);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void SafeWdgIf_lSetDataCrc(void)                                  **
**                                                                            **
** Description :    calculate and update crc for data set                     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non-Reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
** Parameters (out): None                                                     **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/

static void SafeWdgIf_lSetDataCrc
(
  void
)
{
  uint32 CurrCrc          = 0U;

  CurrCrc = (uint32)CRC32(CurrCrc, (uint32)(void*)SafeWdgIfData.ConfigPtr);
  CurrCrc = (uint32)CRC32(CurrCrc, (uint32)(void*)SafeWdgIfData.WdgMode);
  SafeWdgIfData.Crc = CurrCrc;
}


#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"




