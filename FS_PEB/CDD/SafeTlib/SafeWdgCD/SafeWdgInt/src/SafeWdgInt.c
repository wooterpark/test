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
**   $FILENAME   : SafeWdgInt.c $                                             **
**                                                                            **
**   $CC VERSION : \main\32 $                                                 **
**                                                                            **
**   $DATE       : 2017-01-27 $                                               **
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


/******************************************************************************
**                      Includes                                              *
******************************************************************************/
#include "SafeWdgInt.h"
#include "IfxScu_reg.h"
#include "SafeWdgIf.h"
#include "Sl_Timeout.h"


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* Max. number of input frequency settings */
#define SAFEWDGINT_INPUTFREQ_MAX            ( 2u )

#define SAFEWDGINT_RANDOMMASKVAL            ( 32719u )
#define SAFEWDGINT_RANDOMOFFSETVAL          ( 3u )
#define SAFEWDGINT_RANDOMMODVAL            ( 32749u )
/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/* local data for control of safeWdg flow */
typedef struct SafeWdgInt_DataType
{
    /* current state of watchdog */
    SafeWdgInt_StateType             State;             
    /* current watchdog timer reload value */    
    uint32                          ReloadCurr;         
    /* next seed to be used */
    uint32                          NextSeed;           
    /* pointer to configuration data */
    const SafeWdgInt_ConfigType*    CfgPtr;             
    /* calculated Crc for data set */
    uint32                          Crc;                
} SafeWdgInt_DataType;






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

#define IFX_SWDG_START_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* used redundant variables */
static SafeWdgInt_DataType SafeWdgIntData;

#define IFX_SWDG_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"


#define IFX_SWDG_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"

static uint32 SafeWdgInt_Random = 1u;

#define IFX_SWDG_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"



/*******************************************************************************
**                      Debug Purpose Definitions                             **
*******************************************************************************/
/* debug data only */
#if (SAFEWDG_INT_DEBUG == TRUE )

  #pragma message("#### ~~~~ Debug version is being compiled! ~~~~ ####")

    typedef struct SafeWdgInt_DbgType
    {
        /* counts calls to service wdt  */
        uint32 WdtServiceCnt;           
        /* counts calls to seed request */
        uint32 WdtSeedReqCnt;           
        /* counts WDT overflow errors   */
        uint32 WdtFailOfwCnt;           
        /* counts WDT access errors     */
        uint32 WdtFailAccCnt;           
        /* counts wrong signatures      */
        uint32 WdtWrngSigCnt;           
        /* count generated seed values  */
        uint32 WdtSeedDistribution[SAFEWDG_MAXNBR_SEED];    
        /* remember current signatures  */
        uint32 WdtCurrSignature[SAFEWDG_MAXNBR_SEED];       
    } SafeWdgInt_DbgType;

    #define IFX_SWDG_START_SEC_VAR_UNSPECIFIED_ASIL_B
    #include "Ifx_MemMap.h"

    SafeWdgInt_DbgType SafeWdgInt_Dbg; 

    #define IFX_SWDG_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
    #include "Ifx_MemMap.h"

    #define SWDT_ACCEPT_WRONG_SIGN  (TRUE)
    
    #define SafeWdgInt_lDbgWdgServIncr()       SafeWdgInt_Dbg.WdtServiceCnt++;
    #define SafeWdgInt_lDbgWdgSeedReqIncr()    SafeWdgInt_Dbg.WdtSeedReqCnt++;
    #define SafeWdgInt_lDbgWdgFailOfwIncr()    SafeWdgInt_Dbg.WdtFailOfwCnt++;
    #define SafeWdgInt_lDbgWdgFailAccIncr()    SafeWdgInt_Dbg.WdtFailAccCnt++;
    #define SafeWdgInt_lDbgWdgWrongSigCnt()    SafeWdgInt_Dbg.WdtWrngSigCnt++;
    #define SafeWdgInt_lDbgWdgCntSeed(a)       SafeWdgInt_Dbg.WdtSeedDistribution[(a)]++;
    #define SafeWdgInt_lDbgWdgStoreSign(a,b)   SafeWdgInt_Dbg.WdtCurrSignature[(a)] = (b);

#else
    #define SWDT_ACCEPT_WRONG_SIGN  (FALSE)
    

    #define SafeWdgInt_lDbgWdgServIncr()   
    #define SafeWdgInt_lDbgWdgSeedReqIncr()   
    #define SafeWdgInt_lDbgWdgFailOfwIncr()   
    #define SafeWdgInt_lDbgWdgFailAccIncr()   
    #define SafeWdgInt_lDbgWdgWrongSigCnt()   
    #define SafeWdgInt_lDbgWdgCntSeed(a)    
    #define SafeWdgInt_lDbgWdgStoreSign(a,b)  
#endif

#define IFX_SWDG_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
LOCAL_INLINE uint32   SafeWdgInt_lRandom      (uint32 limit_above);

static  Std_ReturnType  SafeWdgInt_CheckDataCrc (void);
static  void            SafeWdgInt_SetDataCrc   (void);
/*******************************************************************************
 **                       Function Definitions                                **
 ******************************************************************************/

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgInt_Init                                    **
**                    (const SafeWdgInt_ConfigType* const ConfigPtr)          **
**                                                                            **
** Description :    Initializes the local data from configuration             **
**                  Disables the watchdog and setup state                     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) :  ConfigPtr: pointer to configuration                     **
** Parameters (out):  None                                                    **
** Return value    :    SWDG_JOB_SUCCESS :	Operation successfully performed.
                        SWDG_JOB_INV_PARAM: Job failed due to invalid parameter.
                        SWDG_JOB_INV_STATE: 	Job failed because job is requested from a forbidden state.
                                          **
**                                                                            **
*******************************************************************************/
                                                                             
SafeWdgIf_ResultType SafeWdgInt_Init 
(
 const SafeWdgInt_ConfigType* const ConfigPtr
)
{
    SafeWdgIf_ResultType Result = SWDG_JOB_INV_PARAM;

    if (ConfigPtr != NULL_PTR)
    {
      /* check valid configuration */
      if ( ConfigPtr->SwdtInputFreq <= SAFEWDGINT_INPUTFREQ_MAX )
      {
          Ifx_SCU_WDTS_CON1 con1tmp;
          uint32 InitPassword;

          /* Store configuration pointer locally */
          SafeWdgIntData.CfgPtr = ConfigPtr;
          /* get old value */
          con1tmp.U       = SCU_WDTSCON1.U;                              
          /* set frequency bits */            
          con1tmp.B.IR0   = ConfigPtr->SwdtInputFreq & 0x1u;             
          con1tmp.B.IR1   = (ConfigPtr->SwdtInputFreq & 0x2u)>>1u;
          /* disable watchdog service */
          con1tmp.B.DR    = 1u;                                           
          /* enable automatic password service */
          con1tmp.B.PAR   = 1u;                                           

          /* configure safety watchdog */
          Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
          /* set value for Frequency and disable SWDT */
          SCU_WDTSCON1.U  = con1tmp.U;                                    
          Mcal_SetSafetyENDINIT_Timed();

          /* get initial password to be set for initial seed = 0 */
          InitPassword = ConfigPtr->SwdtSignTable.SigPair[0u].BaseValue;

          /* set initial password and timer reload value */
          Mcal_SafetyModifyAccess 
                       (InitPassword , (uint32) ConfigPtr->SwdtTimerReload);

          /* store current reload value*/
          SafeWdgIntData.ReloadCurr = ConfigPtr->SwdtTimerReload;


          /* initialise */
          SafeWdgIntData.NextSeed = 0u;

          /*Check if watchodog is disabled */
          if( SCU_WDTSSR.B.DS != 1u)
          {
              /*Watchdog in wrong state.*/
              SafeWdgIntData.State = SAFEWDGINT_UNKNOWN;
              Result = SWDG_JOB_INV_STATE;
          }
          else
          {
            Result = SWDG_JOB_SUCCESS;
            /* initialise state */
            SafeWdgIntData.State = SAFEWDGINT_INIT;
            /* initialise crc for current data set */
            SafeWdgInt_SetDataCrc();
          }
          
      }
        
    }

    return (Result);
}


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void SafeWdgInt_DeInit (void)                                     **
**                                                                            **
** Description :    Reset watchdog to reset state                             **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) :   None                                                   **
** Parameters (out):   None                                                   **
** Return value    :   None                                                   **
**                                                                            **
*******************************************************************************/

void SafeWdgInt_DeInit 
(
 void
)
{
    /* disable safety watchdog */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
    SCU_WDTSCON1.B.DR = 1u;
    Mcal_SetSafetyENDINIT_Timed();

    /* initialise state */
    SafeWdgIntData.State = SAFEWDGINT_UNKNOWN;
    SafeWdgIntData.Crc ^= ~(0u);
}


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgInt_Activate (void)                         **
**                                                                            **
** Description :   Enable watchdog with slow interval settings and set initial**
**                 password                                                   **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) :  None                                                    **
** Parameters (out):  None                                                    **
** Return value    :    SWDG_JOB_SUCCESS :	Operation successfully performed.
                        SWDG_JOB_FAILED_CRC: 	Job failed due to driver internal data checksum failure.
                        SWDG_JOB_INV_STATE: 	Job failed because job is requested from a forbidden state.

**                                                                            **
*******************************************************************************/

SafeWdgIf_ResultType SafeWdgInt_Activate (void)
{
    SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;

    if (SafeWdgInt_CheckDataCrc() == E_OK)
    {
        Result = SWDG_JOB_INV_STATE;                         
        /* now assume wrong state */
        if ( SafeWdgIntData.State == SAFEWDGINT_INIT )
        {
            /* enable safety watchdog */
            Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
            /* enable SWDT */
            SCU_WDTSCON1.B.DR  = 0u;                    
            Mcal_SetSafetyENDINIT_Timed();

            /* initialise next used seed */
            SafeWdgIntData.NextSeed     = 0u;
            /*Check if watchodog is disabled */
            if( SCU_WDTSSR.B.DS != 0u)
            { 
                /*Watchdog in wrong state.*/
                SafeWdgIntData.State = SAFEWDGINT_UNKNOWN;
                Result = SWDG_JOB_INV_STATE;
            }
            else
            {
              /* set state to activated */
              SafeWdgIntData.State        = SAFEWDGINT_ACTIVE;
              /* everything okay */
              Result = SWDG_JOB_SUCCESS;              
            } 
            /* update crc for current data set */
            SafeWdgInt_SetDataCrc();
                              
        }
    }

    return (Result);
}


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgInt_Service                                 **
**                     (const uint32 Signature)         **
**                                                                            **
** Description :    check given signature and service watchdog                **
**                  calculate next seed                                       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) :  UsedSeed:   used seed for this signature                **
**                    Signature:  the signature to be used for watchdog       **
**                                service                                     **
** Parameters (out):  None                                                    **
** Return value    :    SWDG_JOB_SUCCESS	Operation successfully performed.
                        SWDG_JOB_FAILED_CRC 	Job failed due to driver internal data checksum failure.
                        SWDG_JOB_INV_STATE 	Job failed because job is requested from a forbidden state.
                        SWDG_JOB_FAILED_SERVICE	Job failed due to service failure.

*******************************************************************************/

SafeWdgIf_ResultType SafeWdgInt_Service (const uint32 Signature)
{
    SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;
    SafeWdgInt_lDbgWdgServIncr()          /* only debug purpose */

    /* config pointer and state value are (still) valid? */
    if ( SafeWdgInt_CheckDataCrc() == E_OK )
    {
        /* get current Config Pointer */
        SafeWdgInt_ConfigType* CurrConfigPtr =  
                     (SafeWdgInt_ConfigType*) (void*)SafeWdgIntData.CfgPtr;

        /* now assume wrong state */
        Result = SWDG_JOB_INV_STATE;                                                  
        if ( SafeWdgIntData.State == SAFEWDGINT_ACTIVE )
        {
             /* provide next seed */
             /* get random seed value */
            uint32 nextSeed = SafeWdgInt_lRandom(SAFEWDG_MAXNBR_SEED);    
            uint8 UsedSeed  = (uint8)SafeWdgIntData.NextSeed;

            /* check whether password sequence calculation might already
                be done externally */
            /* use base value to calculate next check password */
            uint32 CheckPassword  = 
                   CurrConfigPtr->SwdtSignTable.SigPair[UsedSeed].BaseValue;
            /* remember the delivered signatures  */
            SafeWdgInt_lDbgWdgStoreSign(UsedSeed,Signature)                    

            /* does signature match to the expected one? */
            /* assume okay */
            Result = SWDG_JOB_SUCCESS;                                            
            if (Signature != 
                 CurrConfigPtr->SwdtSignTable.SigPair[UsedSeed].ExptdTstSig)
            {
                /* only debug purpose: count wrong signatures */
                SafeWdgInt_lDbgWdgWrongSigCnt()                       

#if (SWDT_ACCEPT_WRONG_SIGN == FALSE)
                /* use inverted password, if signature does not match */
                CheckPassword = ~CheckPassword;     
                Result = SWDG_JOB_FAILED_SERVICE;
#endif
            }

            /* do transformation of base value to proper password */
            CheckPassword = Mcal_SafetyPwSequence(CheckPassword);

            /* check whether watch dog overflow happened - should already 
               have generated an SMU alarm, but if not... */
            if (SCU_WDTSSR.B.OE != 0u)
            {
                Result = SWDG_JOB_FAILED_SERVICE;
                /* only debug purpose: count overflow */
                SafeWdgInt_lDbgWdgFailOfwIncr()              
            }

            /* service watchdog with check access */
            Mcal_SafetyCheckAccess (CheckPassword, MCAL_WDT_RELOAD_IGNORE);

            /* check watch dog access status - should already have generated 
               an SMU alarm, but if not... */
            if (SCU_WDTSSR.B.AE != 0u)
            {
                /* watchdog access failed, set state to failed */
                Result = SWDG_JOB_FAILED_SERVICE;
                /* only debug purpose: count access errors */
                SafeWdgInt_lDbgWdgFailAccIncr()              
            }

            /* check watch dog failures */
            if (Result != SWDG_JOB_SUCCESS)
            {
                /* watchdog access failed, set state to failed */
                SafeWdgIntData.State = SAFEWDGINT_FAIL;
            }

            /* get next password to be set */
            CheckPassword  = 
                  CurrConfigPtr->SwdtSignTable.SigPair[nextSeed].BaseValue;

            /* initialise safety watchdog with the new base value according 
               to generated next seed and refresh timer reload to configured 
               time */
            /* this watchdog access will be tried even, if previously errors 
               have been detected */
            Mcal_SafetyModifyAccess 
                                (CheckPassword, SafeWdgIntData.ReloadCurr);

            /* store next seed */
            SafeWdgIntData.NextSeed = nextSeed;

            /* update crc for current data set */
            SafeWdgInt_SetDataCrc();

            /* only debug: count seed usage to validate random generator */
            SafeWdgInt_lDbgWdgCntSeed(nextSeed)

        }
    }
    return (Result);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgInt_StateType SafeWdgInt_GetState (void)                   **
**                                                                            **
** Description :    read back the current state (active / failed)             **
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
** Parameters (out): None                                                     **
** Return value    : SAFEWDGINT_INIT :	Watchdog is initialized and it is in OFF state. 
                     SAFEWDGINT_ACTIVE :	Watchdog is activated and it is in ON state. and requires servicing 
                     SAFEWDGINT_FAIL :	The watchdog is in ON state however the servicing failed i.e.overflow error / access error
                     SAFEWDGINT_UNKNOWN :	The watchdog state is unknown.

**                                                                            **
*******************************************************************************/

SafeWdgInt_StateType SafeWdgInt_GetState (void)
{
    SafeWdgInt_StateType CurrState = SAFEWDGINT_UNKNOWN;
  
    if ( SafeWdgInt_CheckDataCrc() == E_OK)
    {
        CurrState = SafeWdgIntData.State ;
    }
  
    return (CurrState);
}


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgInt_GetSeed (uint8* const nextSeed)         **
**                                                                            **
** Description :    return next seed value to be used                         **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) :  *NextSeedPtr: pointer to report back the new value          **
** Parameters (out):  *NextSeedPtr:  returned new seed value                     **
** Return value    :    SWDG_JOB_SUCCESS:	Operation successfully performed.
                        SWDG_JOB_FAILED_CRC: 	Job failed due to driver internal data checksum failure.
                        SWDG_JOB_INV_STATE: 	Job failed because job is requested from a forbidden state.
                        SWDG_JOB_INV_PARAM :	Job failed due to invalid parameter.

**                                                                            **
******************************************************************************/


SafeWdgIf_ResultType SafeWdgInt_GetSeed (uint8* const NextSeedPtr)
{
    SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;
    SafeWdgInt_lDbgWdgSeedReqIncr()         /* only debug purpose */

    if (SafeWdgInt_CheckDataCrc() == E_OK)
    {  
        Result = SWDG_JOB_INV_PARAM;
        
        if (NextSeedPtr != NULL_PTR)
        {
            if ( SafeWdgIntData.State == SAFEWDGINT_ACTIVE )
            {
              /* get next seed */
              *NextSeedPtr = (uint8)SafeWdgIntData.NextSeed;
               Result = SWDG_JOB_SUCCESS;              
            }
            else
            {
              Result = SWDG_JOB_INV_STATE;
            }  
        }
    }
    return (Result);
}


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Std_ReturnType SafeWdgInt_CheckDataCrc(void)                      **
**                                                                            **
** Description :    check data set integrity by CRC validation                **
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
** Parameters (out): None                                                     **
** Return value    : E_OK, if Crc matches the stored on, data integrity okay  **
**                   E_NOT_OK otherwise                                       **
**                                                                            **
*******************************************************************************/

static Std_ReturnType SafeWdgInt_CheckDataCrc(void)
{
    uint32 CurrCrc          = 0u;

    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgIntData.State);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgIntData.ReloadCurr);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgIntData.NextSeed);
    CurrCrc = (uint32)CRC32(CurrCrc, (uint32)(void*)SafeWdgIntData.CfgPtr);

    return ((CurrCrc == SafeWdgIntData.Crc) ? E_OK : E_NOT_OK);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void SafeWdgInt_SetDataCrc(void)                                  **
**                                                                            **
** Description :    calculate and update crc for data set                     **
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
** Parameters (out): None                                                     **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/

static void SafeWdgInt_SetDataCrc(void)
{
    uint32 CurrCrc          = 0u;

    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgIntData.State);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgIntData.ReloadCurr);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgIntData.NextSeed);
    CurrCrc = (uint32)CRC32(CurrCrc, (uint32)(void*)SafeWdgIntData.CfgPtr);

    SafeWdgIntData.Crc = CurrCrc;
}


/*  helper function to generate random values */
LOCAL_INLINE uint32 SafeWdgInt_lRandom(uint32 limit_above)
{
    SafeWdgInt_Random = ((SafeWdgInt_Random * SAFEWDGINT_RANDOMMASKVAL) 
                              + SAFEWDGINT_RANDOMOFFSETVAL) % SAFEWDGINT_RANDOMMODVAL;
    return ((SafeWdgInt_Random % limit_above));
}

#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"




