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
**                                                                            **
**   $FILENAME   : SafeWdgExtCic.c $                                          **
**                                                                            **
**   $CC VERSION : \main\38 $                                                 **
**                                                                            **
**   $DATE       : 2016-04-01 $                                               **
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
**                 - functionality of SafeWdg ExtCic driver                   **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Includes                                              *
******************************************************************************/
#include "SafeWdgIf.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* CIC_BUF_SIZE Must be 5. It determines size of
 * CIC61508 transmit and receive buffer
 */
#define CIC_BUF_SIZE                        (5U)
/* Count size of user buffer should be either 2 or 4 in SecSPI mode*/
#define CIC_SECSPI_CNTSIZE2                 (2U) 
#define CIC_SECSPI_CNTSIZE4                 (4U) 
/* CIC61508 generic write commands 
 * These are used for sending signature
 */
#define CIC_WR_OPC0                         (0x0080U)
#define CIC_WR_OPC1                         (0x0081U)
#define CIC_WR_OPC2                         (0x0082U)
#define CIC_WR_OPC3                         (0x0083U)

/* CIC61508 read commands */
#define CIC_RD_OPCSEQ                       (0x0006U)
#define CIC_RD_STATE                        (0x0007U)
#define CIC_RD_ERRCNT                       (0x0008U)
#define CIC_RD_VLTMACNT                     (0x0009U)
#define CIC_RD_SUM0                         (0x0010U)
#define CIC_RD_SUM1                         (0x0011U)
#define CIC_RD_INTERR                       (0x0012U)
#define CIC_RD_SVERS                        (0x002CU)
#define CIC_RD_WUP_PRESCALE                 (0x001EU)
#define CIC_RD_WUP_RELOAD                   (0x001FU)

/* CIC61508 write mode command */
#define CIC_RDBACK_SPI_RESET                (0x93A9U)

/* SPI reset command */
#define CIC_WR_MODE_SPI_RESET               (0xA993U)
/* Cic GO request */
#define CIC_WR_MODE_GO_REQUEST              (0x8A93U)

/* Cmd to move cic from active to trip state */
#define CIC_WR_MODE_TRIP                    (0x8593U)
/* Cmd to move into secure mode */
#define CIC_WR_SECURE                       (0x9493U)



/* CIC61508 dedicated wakeup reset commands */
#define CIC_WR_WUP_PRESCALE                 (0x809FU)
#define CIC_WR_WUP_RELOAD                   (0xFF9EU)

/* CIC61508 dedicated read back values indicates CIC states */
#define CIC_RDBACK_STATE_RESET              (0x0769U)   
#define CIC_RDBACK_STATE_RESETREQ           (0x070FU) 
#define CIC_RDBACK_STATE_NREADY             (0x0778U)
#define CIC_RDBACK_STATE_READY              (0x073CU)
#define CIC_RDBACK_STATE_ACTIVE             (0x071EU)
#define CIC_RDBACK_STATE_TRIP1              (0x0796U)
#define CIC_RDBACK_STATE_TRIP2              (0x07B4U)
#define CIC_RDBACK_STATE_TRIP3              (0x07A5U)
#define CIC_RDBACK_STATE_DISABLED           (0x072DU)

/* returned from CIC61508 on SPI comm error */
#define CIC_RD_RXERR0                       (0xAAAAU)
 /* returned from CIC61508 on SPI comm error */ 
#define CIC_RD_RXERR1                       (0x5555U)
/* "returned" from SPI during BIST */
#define CIC_RD_BIST                         (0xFFFFU)
/* Used to Check if Zero UR selected */
#define CIC_ZERO_UR                         (0x0U)   

/* Cic masks */
#define CIC_TXCMD_MASK                      (0x00FFU)
#define CIC_TXDATA_MASK                     (0xFF00U)
#define CIC_RXCMD_MASK                      (0xFF00U)
#define CIC_RXDATA_MASK                     (0x00FFU)
#define CIC_SEED_MASK                       (0x000FU)
#define CIC_TXCNT_FIVE                      (0x5U)
#define CIC_SHFTEIG                         (0x8U)
#define CIC_SHFTDATA                        (0x8U)
#define CIC_OPC3_MASK                       (0x000000FFU)
#define CIC_OPC2_MASK                       (0x0000FF00U)
#define CIC_OPC1_MASK                       (0x00FF0000U)
#define CIC_OPC0_MASK                       (0xFF000000U)
#define CIC_SHFTTEN                         (0x10U)
#define CIC_SHFTEIGH                        (0x18U)

/* CIC61508 related limits */
/* number reset trials send to CIC61508 */
#define CIC_MAX_RESET_ATTEMPT               (3U)
/* number of sync read requests during BIST */
#define CIC_MAX_SYNC                        (100U)

/******   SafeWdgExtCic_Data.JobState *******/
#define CIC_INIT_JOB                        (1U)
#define CIC_ACTIVATE_JOB                    (2U)
#define CIC_SERVICE_JOB                     (3U)
#define CIC_GETINFO_JOB                     (4U)
#define CIC_USERREQ_JOB                     (5U)
#define CIC_IDLE                            (6U)
#define CIC_DEINIT_JOB                      (7U)  

/*number of "quiet" cycles after Reset Request has been sent*/
#define SAFEWDGEXTCIC_RESET_DELAY           (5U)


/*******************************************************************************
**                      Debug Purpose Definitions                             **
*******************************************************************************/
/* debug data only */
#if ( SAFEWDGEXTCIC_DEBUG_EN == TRUE )

  #pragma message("#### ~~~~ Debug version is being compiled! ~~~~ ####")

    typedef struct SafeWdgExtCic_DbgType
    {  
        /* counts calls to service wdt  */
        uint32 WdtServiceCnt;           
       /* counts calls to seed request */
        uint32 WdtSeedReqCnt;           
       /* counts wrong signatures      */
        uint32 WdtWrngSigCnt;           
        /* remember current signatures  */
        uint32 WdtCurrSignature[SAFEWDG_MAXNBR_SEED];
        /* calculated Xor response to CIC */
        uint32 WdtNewXorResponse[SAFEWDG_MAXNBR_SEED];     
    } SafeWdgExtCic_DbgType;

#define IFX_SWDG_START_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

    static SafeWdgExtCic_DbgType SafeWdgExtCic_Dbg;

#define IFX_SWDG_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_SWDG_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"

    /* Barcelona Table */
    uint32 SafeWdgExtCic_Barcelona [SAFEWDG_MAXNBR_SEED] = 
    {   
      /* Expected signatures for seed 0 to 15 */
        0xF80DE974U, 
        0xB742A63BU, 
        0xEE1BFF62U, 
        0xA154B02DU, 
        0x728763FEU, 
        0x3DC82CB1U, 
        0x649175E8U, 
        0x2BDE3AA7U, 
        0xD520C459U, 
        0x9A6F8B16U, 
        0xC336D24FU, 
        0x8C799D00U, 
        0x5FAA4ED3U, 
        0x10E5019CU, 
        0x49BC58C5U, 
        0x06F3178Au  
    };

#define IFX_SWDG_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"    
    
  #define SafeWdgExtCic_lDbgServIncr()     SafeWdgExtCic_Dbg.WdtServiceCnt++;
  #define SafeWdgExtCic_lDbgSeedIncr()     SafeWdgExtCic_Dbg.WdtSeedReqCnt++;
  #define SafeWdgExtCic_lDbgSigCnt()       SafeWdgExtCic_Dbg.WdtWrngSigCnt++;
  #define SafeWdgExtCic_lDbgStrSign(a,b)   SafeWdgExtCic_Dbg.WdtCurrSignature[(a)] = (b);
  #define SafeWdgExtCic_lDbgStrRespo(a,b)  SafeWdgExtCic_Dbg.WdtNewXorResponse[(a)] = (b);
  #define SafeWdgExtCic_lDbgCicRespo(a)    SafeWdgExtCic_Barcelona[(a)]

#else    

 /* function like macros used to map debug functions on request, 
    for release version always map to empty replacement */
  #define SafeWdgExtCic_lDbgServIncr()         
  #define SafeWdgExtCic_lDbgSeedIncr()         
  #define SafeWdgExtCic_lDbgSigCnt()           
  #define SafeWdgExtCic_lDbgStrSign(a,b)       
  #define SafeWdgExtCic_lDbgStrRespo(a,b)      
  #define SafeWdgExtCic_lDbgCicRespo(a)        

#endif

#if (SAFEWDGEXTCIC_TRC_EN == TRUE)
 /* trace function prototype */
 static void    SafeWdgExtCic_DbgTrace 
 (
   void
 );

 /* size of trace buffer */
 #define CIC_TRC_SIZE                             (256U) 

 #define IFX_SWDG_START_SEC_VAR_16BIT_ASIL_B
 #include "Ifx_MemMap.h"

  /* local trace buffer for communication with CIC61508 */
  static uint16 SafeWdgExtCic_TrcIdx;
  /* Logs data when tracing enabled */
  static uint16 SafeWdgExtCic_DbgTrc[CIC_TRC_SIZE][12];

#define IFX_SWDG_STOP_SEC_VAR_16BIT_ASIL_B
 #include "Ifx_MemMap.h"
#endif


/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/* local data */
typedef struct SafeWdgExtCic_DataType
{
    /* calculated Crc for data set */
    uint32                              Crc;
    /* Store UR buffer address and No of Ur requests */
    SafeWdgIf_CmdType*                  Request;
    /* used configuration */
    const SafeWdgExtCic_ConfigType*     ConfigPtr;
    /* Checks CIC61508 job state  */
    SafeWdgIf_ResultType                JobResult;
    /* Checks CIC61508 job state  */
    uint8                               JobState;
    /* latest seed value */
    uint8                               LastSeed;
    /* latest CIC61508 state */
    uint8                               LastState;
    /* latest error count */
    uint8                               LastErrCnt;
    /* number of reads while BIST */
    uint8                               SyncCnt;
    /* reset count for init reset request */
    uint8                               ResetCnt;
    /* delay cycle counter after reset request */
    uint8                               ResetDelayCnt;
    /* Stores number of UR count */
    uint8                               ReqCnt;
    /* secure mode Check */
    boolean                             SecureMode;      

} SafeWdgExtCic_DataType;
                  
              
/* Job result Type for ExtCIC */
typedef uint8 SafeWdgExtCic_ResultType;


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

/* Local working data for CIC61508 driver */
static SafeWdgExtCic_DataType SafeWdgExtCic_Data;        

#define IFX_SWDG_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"


#define IFX_SWDG_START_SEC_VAR_16BIT_ASIL_B
#include "Ifx_MemMap.h"
/* NOTE: CIC_BUF_SIZE should be fixed to 5. 
 *       Only four user requests are allowed per call  
 */
 
/* transmit buffer */    
static uint16    SafeWdgExtCic_TxBuffer[CIC_BUF_SIZE];    
/* receive buffer */
static uint16    SafeWdgExtCic_RxBuffer[CIC_BUF_SIZE];   
              
#define IFX_SWDG_STOP_SEC_VAR_16BIT_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define IFX_SWDG_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/* Local function for CIC61508 initialization */
static SafeWdgIf_ResultType SafeWdgExtCic_lInit
( 
   boolean TxRxDone
);
/* Local function for processing user request */
static void                 SafeWdgExtCic_lProcessUsrReq 
( 
   void
);
/* Local function to validate received data */
static boolean              SafeWdgExtCic_lCheckRxData   
(
    void
);
/* Local function to transmit data to Cic61508*/
static void                SafeWdgExtCic_lTransmit      
(
   uint16* const TxBuf
 );
/* Local function to check transmission status */
static boolean              SafeWdgExtCic_lTxRxDone      
(
   void
);
/* Local functions to update CIC61508 status */
static void                 SafeWdgExtCic_lUpdateStatus   
(
   void
);
/* Local functions to check Crc */
static  Std_ReturnType      SafeWdgExtCic_lCheckDataCrc 
( 
   void
 );
/* Local functions to set Crc */
static  void               SafeWdgExtCic_lSetDataCrc   
(
   void
);
/* Local function to check Secure SPI mode is requested */
static boolean             SafeWdgExtCic_lChkSecSpiRequested
(
  uint8 Count,
  boolean * SecModeFmtCICStateChkPtr
);
/* Local function to check UserBuffer Count in Secure SPI mode */
static SafeWdgIf_ResultType      SafeWdgExtCic_lChkCountinSecSpi
(
   uint8 Count
);

/*******************************************************************************
**                       Function Definitions                                 **
*******************************************************************************/

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgExtCic_Init                           **
**                    (const SafeWdgExtCic_ConfigType* const ConfigPtr)       **
**                                                                            **
** Description :    Initializes the local data from configuration             **
**                                                                            **
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
** Return value    :  SWDG_JOB_ACCEPTED: Job accepted and in progress         **
**                    SWDG_JOB_INV_PARAM: Job failed due to invalid parameter **
**                                                                            ** 
*******************************************************************************/

SafeWdgIf_ResultType SafeWdgExtCic_Init 
(
   const SafeWdgExtCic_ConfigType* const ConfigPtr
)
{
    
  SafeWdgIf_ResultType Result           = SWDG_JOB_INV_PARAM;  
  SafeWdgIf_ResultType AscLinInitResult = SWDG_JOB_INV_PARAM;
  /* JobState   */
  SafeWdgExtCic_Data.JobState           = CIC_IDLE;             
  /* Last Seed  */
  SafeWdgExtCic_Data.LastSeed           = SAFEWDG_SEED_NOTVALID; 
  /* Last state */
  SafeWdgExtCic_Data.LastState          = SAFEWDG_CIC_UNKNOWN;  
  /* Last ErrCnt*/
  SafeWdgExtCic_Data.LastErrCnt         = 0U;                   
  /* Sync Cnt   */
  SafeWdgExtCic_Data.SyncCnt            = 0U;                   
  /* Reset Cnt  */
  SafeWdgExtCic_Data.ResetCnt           = 0U;                   
  /* Reset delay cnt  */
  SafeWdgExtCic_Data.ResetDelayCnt      = 0U;                   
  /* UR count   */
  SafeWdgExtCic_Data.ReqCnt             = 0U;                   
  /* Stores pointer to UserRequest buffer     */
  SafeWdgExtCic_Data.Request            = NULL_PTR;             
  /* Cic config */
  SafeWdgExtCic_Data.ConfigPtr          = NULL_PTR;             
  /* Secure mode not Active */
  SafeWdgExtCic_Data.SecureMode         = FALSE;    
                        
     
  /* Check for null ptr */
  if (ConfigPtr != NULL_PTR)
  {
    
      /* Get Configuration pointer */
       SafeWdgExtCic_Data.ConfigPtr  = ConfigPtr;
      
      AscLinInitResult = SafeWdgAscLin_Init(ConfigPtr->AscLinCfgPtr);
       
      /*  Initialize configured AscLin channel and DMA channel 
      *  for communication with CIC */       
       if (AscLinInitResult == SWDG_JOB_SUCCESS)
       {   
      
           /* Start Init Job for CIC 
            * call lInit to chk Cic present status  
            * Cic response is read when MainFunction is called */
      
             SafeWdgExtCic_lInit(FALSE);                
      
             /* set Cic job status */
             SafeWdgExtCic_Data.JobState = CIC_INIT_JOB;
             /* Updated Job result */
             Result = SWDG_JOB_ACCEPTED;                
       }
       
    }
        
    /* Store job result */
    SafeWdgExtCic_Data.JobResult = Result;

    SafeWdgExtCic_lSetDataCrc();

    return (Result);
} 

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgExtCic_lInit(boolean TxRxDone)        **
**                                                                            **
** Description :    Initializes the local data from configuration             **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) :  TxRxDone: Flag to indicate if response is received from **
                                CIC61508                                      **
** Parameters (out):  None                                                    **
** Return value    :    SWDG_JOB_ACCEPTED, Job accepted and in progress       **
**                      SWDG_JOB_SUCCESS:  The operation is complete          **
**                            else if any of these failures occurred:         **
**                      SWDG_JOB_INIT_FAIL                                    **
**                         - Init Operation failed after several attempts     **
**                                                                            **
*******************************************************************************/
static SafeWdgIf_ResultType SafeWdgExtCic_lInit
(
    boolean TxRxDone
)
{
    SafeWdgIf_ResultType JobResult = SWDG_JOB_ACCEPTED;

   /* Update transmit buffer to get the CIC state 
    * Read Cic status and CIC version */
  
    SafeWdgExtCic_TxBuffer[0] = CIC_RD_OPCSEQ;
    SafeWdgExtCic_TxBuffer[1] = CIC_RD_ERRCNT;
    SafeWdgExtCic_TxBuffer[2] = CIC_RD_STATE;
    SafeWdgExtCic_TxBuffer[3] = CIC_RD_SVERS;
    SafeWdgExtCic_TxBuffer[4] = CIC_RD_SVERS;

  
   /* Enter if Cic response received */
   
    if (TxRxDone == TRUE)
    {
      
        /* Read Cic status */
        uint16 CicStatus = SafeWdgExtCic_RxBuffer[3];
    
        switch (CicStatus)
        {
    
            case CIC_RDBACK_STATE_NREADY:
            {  
               /* CIC found in Not Ready state, Check, whether an SPI reset  
                * has been sent already? */
                    
               uint16 CicSpiResReq = SafeWdgExtCic_RxBuffer[4];
             
               if (CicSpiResReq != CIC_RDBACK_SPI_RESET)
               {
                    /* Reset request not yet sent, send SPI reset now
                       expect answer in next cycle in RxBuffer[2] */
                    SafeWdgExtCic_TxBuffer[3] = CIC_WR_MODE_SPI_RESET;          
               }
               else
               {
        
                    /* SPI reset was sent and expected state found, 
                    *  initialization is finished                   
                    * clear sync and reset counters */
                    
                    SafeWdgExtCic_Data.SyncCnt       = 0U;
                    SafeWdgExtCic_Data.ResetCnt      = 0U;
                    SafeWdgExtCic_Data.ResetDelayCnt = 0U;

                    /* Read Cic status: seed, Error counter and status 
                    * and set up Crc */
                    
                    SafeWdgExtCic_lUpdateStatus();
          
                    /* Updated Job result */
                    JobResult = SWDG_JOB_SUCCESS;
                }
                break;
            }

            case CIC_RDBACK_STATE_READY:
            case CIC_RDBACK_STATE_ACTIVE:
            case CIC_RDBACK_STATE_TRIP1:
            case CIC_RDBACK_STATE_TRIP2:
            case CIC_RDBACK_STATE_TRIP3:
            case CIC_RDBACK_STATE_DISABLED:
            {  
      
              /*
               * Neither in NR nor Bist is running
               * other CIC state results in requesting a CIC reset 
               */
              if (SafeWdgExtCic_Data.ResetCnt < CIC_MAX_RESET_ATTEMPT)
              {
              
                  if (SafeWdgExtCic_Data.ResetDelayCnt > 0U)
                  {
                      SafeWdgExtCic_Data.ResetDelayCnt = 0U;
                  }
                  else
                  {
                   /* now send wakeup reset */
                   SafeWdgExtCic_TxBuffer[3]  = CIC_WR_WUP_PRESCALE;
                   SafeWdgExtCic_TxBuffer[4]  = CIC_WR_WUP_RELOAD;
                   /* Update Bist chk count */
                   SafeWdgExtCic_Data.SyncCnt = 0U;
                   SafeWdgExtCic_Data.ResetDelayCnt = SAFEWDGEXTCIC_RESET_DELAY;
                   /* Update reset attempt count */
                   SafeWdgExtCic_Data.ResetCnt++;
                  }
              }
              else
              { 
        
                    /*
                     * Cic Reset failed after configured Maximum attempt          
                     */
                     JobResult = SWDG_JOB_INIT_FAIL;               
              }
              break;
            }
            default:
            {
                /* assume CIC in BIST state, check Bist failure */
                SafeWdgExtCic_Data.SyncCnt++;
                if (SafeWdgExtCic_Data.SyncCnt > CIC_MAX_SYNC)
                {
                    /* Bist failed */
                     JobResult = SWDG_JOB_INIT_FAIL;               
                }
              break;
            }
        }
    }
  
   /*  Cic init job in progress */      
    
    if (JobResult == SWDG_JOB_ACCEPTED) 
    {
  
        /* Transmit command to get updated Cic status */
        SafeWdgExtCic_lTransmit(SafeWdgExtCic_TxBuffer);
    }

    return (JobResult);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgExtCic_DeInit (void)                  **
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
** Return value    :   SWDG_JOB_BUSY: Job failed because driver is            **
**                                    busy processing the earlier job request **
**                     SWDG_JOB_ACCEPTED : Job Accepted and is in progress    **
**                      SWDG_JOB_INV_STATE: Job failed because job is         **
**                                          requested from a forbidden state. **
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgExtCic_DeInit 
(
  void
)
{

  SafeWdgIf_ResultType Result = SWDG_JOB_BUSY;
    
  if(SafeWdgExtCic_Data.JobState == CIC_IDLE) 
  {
    
    if(SafeWdgExtCic_Data.SecureMode == FALSE )
    {
      
      /* Update job status */
      SafeWdgExtCic_Data.JobState = CIC_DEINIT_JOB; 
      
      /* Update Tx Buffer to CIC status */
      SafeWdgExtCic_TxBuffer[0] = CIC_RD_ERRCNT;
      SafeWdgExtCic_TxBuffer[1] = CIC_RD_SVERS;
      SafeWdgExtCic_TxBuffer[2] = CIC_RD_ERRCNT;
      SafeWdgExtCic_TxBuffer[3] = CIC_WR_WUP_PRESCALE;
      SafeWdgExtCic_TxBuffer[4] = CIC_WR_WUP_RELOAD;   
            
      /* Send command to move cic to NotReady state */           
      SafeWdgExtCic_lTransmit(SafeWdgExtCic_TxBuffer);                 
      Result = SWDG_JOB_ACCEPTED; 
    }
    else
    {
       Result = SWDG_JOB_INV_STATE;
    }    
        
  }        
   
   /* Update Job result */
   SafeWdgExtCic_Data.JobResult = Result; 

   /* Update Crc data */    
   SafeWdgExtCic_lSetDataCrc();  
 
   return (Result);
}
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgExtCic_Activate (void)                **
**                                                                            **
** Description :  Issues GoRequest to set the CIC61508 in Active state.       **
**                The CIC should be in Ready state before sending GoRequest.  **
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
** Return value    :  SWDG_JOB_ACCEPTED: Job accepted and ongoing             **
**                    SWDG_JOB_FAILED_CRC: Job failed due to driver internal  ** 
**                                         data checksum failure.             **
**                    SWDG_JOB_BUSY: Job failed because driver is busy        **
**                                   processing the earlier job request.      **
**                    SWDG_JOB_INV_STATE: Job failed because job is           **
**                                        requested from a forbidden state.   **
*******************************************************************************/

SafeWdgIf_ResultType SafeWdgExtCic_Activate 
(
  void
)
{

  SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;
  
  /* Chk Crc data status */
  if(SafeWdgExtCic_lCheckDataCrc() == E_OK)
  {
  
      /* Chk job status and CIC status */       
       if(SafeWdgExtCic_Data.JobState == CIC_IDLE) 
       {
       
          if((SafeWdgExtCic_Data.LastState ==  SAFEWDG_CIC_READY) && 
                              (SafeWdgExtCic_Data.SecureMode == FALSE ))
          {
              /* Update job status */
              SafeWdgExtCic_Data.JobState = CIC_ACTIVATE_JOB;
              
              /* Update Tx Buffer to CIC status */
              SafeWdgExtCic_TxBuffer[0] = CIC_RD_OPCSEQ;
              SafeWdgExtCic_TxBuffer[1] = CIC_RD_ERRCNT;
              SafeWdgExtCic_TxBuffer[2] = CIC_RD_STATE;
              SafeWdgExtCic_TxBuffer[3] = CIC_WR_MODE_GO_REQUEST;
              SafeWdgExtCic_TxBuffer[4] = CIC_RD_SVERS;   
              
              /* Send GO command to activate cic */           
              SafeWdgExtCic_lTransmit(SafeWdgExtCic_TxBuffer);          
              
              /* Update result */
              Result = SWDG_JOB_ACCEPTED;
          }
          else
          {
              Result = SWDG_JOB_INV_STATE;
          }          
      
        }
        else
        {
            Result = SWDG_JOB_BUSY;
        }
   
   }  
   
    /* Update Job result */ 
    SafeWdgExtCic_Data.JobResult = Result;
    
    /* Update Crc data */ 
    SafeWdgExtCic_lSetDataCrc();

    return (Result);
} 

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgExtCic_Service(const uint32 Signature)**
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
** Parameters (in) :                                                          **
**                    Signature:the signature to be used for watchdog service **
** Parameters (out):  None                                                    **
** Return value    :  SWDG_JOB_ACCEPTED: Job accepted and ongoing.            **
**                    SWDG_JOB_FAILED_CRC: Job failed due to driver internal  **
**                                         data checksum failure.             ** 
**                    SWDG_JOB_BUSY: Job failed because driver is busy        **
**                                   processing the earlier job request.      **
**                    SWDG_JOB_INV_STATE: Job failed because job is requested **
**                                        from a forbidden state              **
**                                                                            **
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgExtCic_Service 
(
    const uint32 Signature
)
{

    SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;
    uint32 NewResponse;
    
    /* Chk Crc status */
    if(SafeWdgExtCic_lCheckDataCrc() == E_OK)
    {
  
      /* Chk Job status */
      if (SafeWdgExtCic_Data.JobState == CIC_IDLE)
      {
    
        /* Read seed */
        uint8 UsedSeed = SafeWdgExtCic_Data.LastSeed;
        
        /* Only for debug purpose
         * Update counter to service call if debug enabled  */      
        
        SafeWdgExtCic_lDbgServIncr()          
    
       /* Chk Cic is not in unknown state, CIC can be serviced in other states 
       * including disable state */
       if ((SafeWdgExtCic_Data.LastState != SAFEWDG_CIC_UNKNOWN) &&
                                     (SafeWdgExtCic_Data.SecureMode == FALSE ))
       {           

         /* Update job state */
         SafeWdgExtCic_Data.JobState = CIC_SERVICE_JOB;
         
#if ( SAFEWDGEXTCIC_DEBUG_EN == TRUE )
         /* store the current signature  */
         SafeWdgExtCic_lDbgStrSign(UsedSeed,Signature)
         /* calculate the required XorResponse  */
         SafeWdgExtCic_lDbgStrRespo(UsedSeed,(Signature ^ 
                                       SafeWdgExtCic_lDbgCicRespo(UsedSeed)))
         
        /* Chk expected signature given */
        if (Signature ==
        SafeWdgExtCic_Data.ConfigPtr->SwdtSignTable.SigPair[UsedSeed].
                                                                    ExptdTstSig)
        {
          /* Build response to ext. watchdog */
          NewResponse = Signature ^
          SafeWdgExtCic_Data.ConfigPtr->SwdtSignTable.
                                                  SigPair[UsedSeed].XorResponse;
        }
        else
        {      
            /*
             * Expected signature not found 
             * only debug purpose: count wrong signatures 
             */
             SafeWdgExtCic_lDbgSigCnt()
             /* use wrong or proper response (in debug case) */
             NewResponse = SafeWdgExtCic_lDbgCicRespo(UsedSeed);        
         }
#else
      /* Normal Service mode */      
      /* signature Received, build response to ext. watchdog */
      NewResponse = Signature ^
      SafeWdgExtCic_Data.ConfigPtr->SwdtSignTable.SigPair[UsedSeed].XorResponse;
#endif
         /* store response in Tx buffer */
         SafeWdgExtCic_TxBuffer[0] = 
          (uint16)(CIC_WR_OPC3 | 
              (( NewResponse & CIC_OPC3_MASK) << CIC_SHFTDATA));
         SafeWdgExtCic_TxBuffer[1] =
          (uint16)(CIC_WR_OPC2 | 
              (((NewResponse & CIC_OPC2_MASK)>> CIC_SHFTDATA) << CIC_SHFTDATA));
         SafeWdgExtCic_TxBuffer[2] =
          (uint16)(CIC_WR_OPC1 | 
              (((NewResponse & CIC_OPC1_MASK)>>CIC_SHFTTEN) << CIC_SHFTDATA));
         SafeWdgExtCic_TxBuffer[3] =
          (uint16)(CIC_WR_OPC0 | 
              (((NewResponse & CIC_OPC0_MASK)>>CIC_SHFTEIGH) << CIC_SHFTDATA));
         SafeWdgExtCic_TxBuffer[4] = (uint16)(CIC_RD_SVERS);
         
         /* Reset the seed */
         SafeWdgExtCic_Data.LastSeed = SAFEWDG_SEED_NOTVALID;
     
         /* Send signature to cic */
         SafeWdgExtCic_lTransmit(SafeWdgExtCic_TxBuffer);   
               
         /* Update job result */
         Result = SWDG_JOB_ACCEPTED;
    
        } /* Chk Cic is not in unknown state and in disabled state */ 
        else
        {        
          Result = SWDG_JOB_INV_STATE;
        }         
              
      } /* Chk Job status */
      else
      {
         Result = SWDG_JOB_BUSY;
      }

  } /* Chk Crc */

  /* Update job result  */
  SafeWdgExtCic_Data.JobResult = Result;

  SafeWdgExtCic_lSetDataCrc();

  return (Result);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgExtCic_GetErrCntr                     **
                                                    (uint8* const ErrCtrPtr)  **
**                                                                            **
** Description :    read back the current error counter                       **
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
** Parameters (out): ErrCtrPtr - Returns Cic Pass Sequence counter value      **
** Return value    :                                                          **
**                   SWDG_JOB_SUCCESS: Operation successfully performed       **
**                   SWDG_JOB_FAILED_CRC: Job failed due to driver internal   **
**                                        data checksum failure               **
**                   SWDG_JOB_INV_STATE: Job failed because job is requested  **
**                                       from a forbidden state               **
**                   SWDG_JOB_INV_PARAM: Job failed due to invalid parameter  **
*******************************************************************************/

SafeWdgIf_ResultType  SafeWdgExtCic_GetErrCntr 
(
   uint8* const ErrCtrPtr
)
{
   SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;
    
   /* Check Crc result */
   if(SafeWdgExtCic_lCheckDataCrc() == E_OK)
   {
     
   /* Chk for Null ptr */
     if(ErrCtrPtr != NULL_PTR)
     {
       /* Chk Cic status */
        if ((SafeWdgExtCic_Data.LastState != SAFEWDG_CIC_UNKNOWN) &&
                                      (SafeWdgExtCic_Data.SecureMode == FALSE ))        
        {
                 
            /* Read current Error Counter status */
            *ErrCtrPtr = SafeWdgExtCic_Data.LastErrCnt;
            /* Update result */
            Result  = SWDG_JOB_SUCCESS;
      
         } /* Chk Cic status */ 
         else
         {
            Result  = SWDG_JOB_INV_STATE;
         }         
    
     } /* Chk for Null ptr */
     else
     {
        Result = SWDG_JOB_INV_PARAM;
     }
   
    } /* Check Crc result */

   return (Result);
} 

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgExt_StateType SafeWdgExtCic_GetState (void)                **
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
** Return value    : Returns the current state of the cic                     **
**                                                                            **
*******************************************************************************/

SafeWdgExt_StateType SafeWdgExtCic_GetState 
(
    void
)
{
    SafeWdgExt_StateType State = SAFEWDG_CIC_UNKNOWN;  
   
   /* Chk Crc status*/
   if(SafeWdgExtCic_lCheckDataCrc() == E_OK)
   {   
      if(SafeWdgExtCic_Data.SecureMode == FALSE )   
      {
          /* State is available from CIC, read current CIC state */
          State = SafeWdgExtCic_Data.LastState; 
      }      
   }
    
     
    return (State);
} 

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgExtCic_GetSeed                        **
**                                               (uint8* const NextSeedPtr)   **
**                                                                            **
** Description :    return next seed value to be used                         **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: reentrant                                                      **
**                                                                            **
** Parameters (in) :                                                          **
** Parameters (out):    *NextSeedPtr:  returned new seed value                **
** Return value    :    SWDG_JOB_SUCCESS: Operation successfully performed    **
**                      SWDG_JOB_FAILED_CRC: Job failed due to driver internal**
**                                           data checksum failure.           **
**                      SWDG_JOB_INV_STATE: Job failed because job is         **
**                                          requested from a forbidden state. ** 
**                      SWDG_JOB_INV_PARAM: Job failed due to invalid         **
**                                          parameter.                        **
**                      SWDG_JOB_INVALID_SEED: Job failed due to invalid seed.**                   
*******************************************************************************/

SafeWdgIf_ResultType SafeWdgExtCic_GetSeed 
(
    uint8* const NextSeedPtr
)
{
   SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;
   
   /* Only if in debug mode, counts call to get seed  */
    SafeWdgExtCic_lDbgSeedIncr()
  
    /* Chk Crc check */
    if(SafeWdgExtCic_lCheckDataCrc() == E_OK)
    {  
   
      /* Chk for Null Ptr*/
      if (NextSeedPtr != NULL_PTR)
      {
        /* Chk Cic status */
        if ((SafeWdgExtCic_Data.LastState != SAFEWDG_CIC_UNKNOWN) && 
                                     (SafeWdgExtCic_Data.SecureMode == FALSE ))
        {          
        
              if(SafeWdgExtCic_Data.LastSeed != SAFEWDG_SEED_NOTVALID)
              {
                /* return latest seed */
                *NextSeedPtr = (uint8)SafeWdgExtCic_Data.LastSeed;
                Result = SWDG_JOB_SUCCESS;
              }
              else
              {
                Result = SWDG_JOB_INVALID_SEED;  
              }
        }       
        else
        {
          Result  = SWDG_JOB_INV_STATE;
        }
      
     }  /* Chk for Null Ptr*/
     else
     {
        Result = SWDG_JOB_INV_PARAM;
     }

   } /* Chk Crc check */  

   return (Result);
} 


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgExtCic_UserRequest                    **
**                          ( SafeWdgIf_CmdType* const UserCmdPtr,uint8 Count)**
**                                                                            **
** Description : Manage user request to read/set additional commands to ext   ** 
**                                                               watchdog     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) :  UserCmdPtr: Pointer to command structure                **
**                    Count: Total user request to be send to CIC61508        **
** Parameters (out):  None                                                    **
**                    - UserCmdPtr buffer is updated with  values/answer      ** 
**                      returned from CIC61508 by SafeWdgExtCic_MainFunction  ** 
**                      after job is completed successfully                   **
** Return value    :  SWDG_JOB_ACCEPTED: Init Job accepted and ongoing        **  
**                    SWDG_JOB_FAILED_CRC: Job failed due to driver internal  **
**                                         data checksum failure.             **
**                    SWDG_JOB_BUSY: Job failed because driver is busy        **
**                                   processing the earlier job request.      ** 
**                    SWDG_JOB_INV_PARAM: Job failed due to invalid parameter **
*******************************************************************************/

SafeWdgIf_ResultType  SafeWdgExtCic_UserRequest 
(
  SafeWdgIf_CmdType* const UserCmdPtr, 
  uint8 Count
)
{
   
  SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;
  SafeWdgIf_ResultType SecSPIResult = SWDG_JOB_SUCCESS;
  boolean isSecModeFmtCICStateOk = FALSE;
  
  
  if(SafeWdgExtCic_lCheckDataCrc() == E_OK)
  {
  
    /*
     * Chk for Null Ptr and Number of UR request
     * Max four user request are allowed at a time
     */
     
    if((UserCmdPtr != NULL_PTR) && (Count < CIC_BUF_SIZE) && (Count > CIC_ZERO_UR))
    {
    
      /* Chk job status */
      if (SafeWdgExtCic_Data.JobState == CIC_IDLE)
      {
      
        /* Set counter */      
        uint8 TxBufIndex;
        /* Update job state */
        SafeWdgExtCic_Data.JobState = CIC_USERREQ_JOB;  
        /* Store UR buffer address and No of Ur requests */
        SafeWdgExtCic_Data.Request = UserCmdPtr;
        /* Add dummy count for verification */
        SafeWdgExtCic_Data.ReqCnt  = Count;  
      
        for (TxBufIndex = 0U; TxBufIndex < CIC_BUF_SIZE; TxBufIndex++)
        {
            /* Update transmit buffer with UR request data */
            if (TxBufIndex < Count)
            {
                SafeWdgExtCic_TxBuffer[TxBufIndex]  = 
                     ((uint16)((uint16)UserCmdPtr[TxBufIndex].UserData) << CIC_SHFTDATA);
                SafeWdgExtCic_TxBuffer[TxBufIndex] |= 
                     (uint16) ((uint16) UserCmdPtr[TxBufIndex].ReqCmd);
            }
            else
            {
                /* fill rest with read version */
                SafeWdgExtCic_TxBuffer[TxBufIndex] = CIC_RD_SVERS;  
            }
        }
        
       
        
    
           
         /* Chk if secure SPI mode is requested 
            when driver is in non-sec spi mode ?*/
        if(SafeWdgExtCic_Data.SecureMode == FALSE)
        {
        
            /* Chk if Entry to SecureSPI is requested and if UserBuffer  is
             * filled as expcted and Size of user Buffer is also as expected
             * and CIC is in expcted state (NotReady or Disable)
             */
            if(SafeWdgExtCic_lChkSecSpiRequested(Count, &isSecModeFmtCICStateOk)
                                                                    == TRUE)
            {
                
               /* Securemode is requested, format is as expected */ 
               if( isSecModeFmtCICStateOk == TRUE ) 
               {
                 SafeWdgExtCic_Data.SecureMode = TRUE;
               }
               else
               {
                 /* Securemode is requested, but format is 
                    not as expected */
                 SecSPIResult = SWDG_JOB_INV_PARAM;
               }            
               
            }
             
        }
            
           
        /* When in SecSPI mode, check Count value is as expected */            
        if(SafeWdgExtCic_Data.SecureMode == TRUE)
        {
        
            SecSPIResult = SafeWdgExtCic_lChkCountinSecSpi(Count);
          
        }

        
        if(SecSPIResult != SWDG_JOB_INV_PARAM)
        {
          /* Transmit data via AscLin driver */
          SafeWdgExtCic_lTransmit(SafeWdgExtCic_TxBuffer);
        
          /* Update result */
          Result = SWDG_JOB_ACCEPTED;
        }
        else
        {
          Result = SecSPIResult;
        }            
    
      }
      else
      {
        Result  = SWDG_JOB_BUSY;        
      }
    
    }
    else
    {
           Result = SWDG_JOB_INV_PARAM;
    }
    
  } 

    /* Update job result */
    SafeWdgExtCic_Data.JobResult = Result;
   
    SafeWdgExtCic_lSetDataCrc();
    
  return (Result);
} 

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : boolean SafeWdgExtCic_lChkSecSpiRequested               **  
**                          (uint8 Count, boolean *SecModeFmtCICStateChkPtr)  **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : Count: No of UserRequest                                **
**                                                                            **
** Parameters (out) : SecModeFmtCICStateChkPtr: Chk format and CIC61508 status**
**                                                                            **
** Return value     : TRUE/FALSE                                              **
**                    TRUE: SecSPI Entry is requested                         **
**                    FALSE: SecSPI Entry Not requested                       **
** Description      : Checks if Entry to SecureSPI Mode is requested          **
*******************************************************************************/

static boolean SafeWdgExtCic_lChkSecSpiRequested
(
   uint8 Count, 
   boolean *SecModeFmtCICStateChkPtr
)
{
    boolean SecSPIResult = FALSE;
    boolean index = 0U;
   
    /* secure mode requested ? */     

    for (index = 0U; index < Count; index++)
    {
        /* secure mode requested ? */
        if ((SafeWdgExtCic_TxBuffer[index] == CIC_WR_SECURE))
        {
		      /* Secure SPI requested */               
          SecSPIResult = TRUE;             
          break;
        }
    }     
    
    if ( SecSPIResult == TRUE )
    {
	      /* Check Count and Index */
        if ((Count == CIC_SECSPI_CNTSIZE2) && (index == 0x01U))
        { 
  
          /* Secure mode can be entered if CIC61508 is in NotReady or 
           * Disabled state
           */
           if ((SafeWdgExtCic_Data.LastState == SAFEWDG_CIC_NR ) || 
                  (SafeWdgExtCic_Data.LastState == SAFEWDG_CIC_DISABLED ))
           {   
		            /* Buffer is as expected & CIC is in either NotReady or Disabled
                 * state
                 */
                 *SecModeFmtCICStateChkPtr = TRUE;  
                 
           }
           
        }   
        
    }
  
   return SecSPIResult;
        
}

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : boolean SafeWdgExtCic_lChkCountinSecSpi(uint8 Count)    **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : Count: No of UserRequest                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     :                                                         **
**                    SWDG_JOB_SUCCESS: Count is as exptected                 **
**                    SWDG_JOB_INV_PARAM: Count is not as exptected           **
*******************************************************************************/

static SafeWdgIf_ResultType SafeWdgExtCic_lChkCountinSecSpi
(
  uint8 Count
)
{

    SafeWdgIf_ResultType SecSPICountIsCorrect = SWDG_JOB_SUCCESS;
    
    /* When in secure SPI mode, User Buffer Count 
     * should be either two or four only
     */
     
    if ((Count != CIC_SECSPI_CNTSIZE2) && (Count != CIC_SECSPI_CNTSIZE4))
    {
      /* Count is not as expected */
      SecSPICountIsCorrect = SWDG_JOB_INV_PARAM; 
    }    
  
    return SecSPICountIsCorrect;
        
}
/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : static boolean SafeWdgExtCic_lTxRxDone(void)            **
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
** Return value     : TRUE/FALSE                                              **
**                    TRUE: Transmission is complete                          **
**                                                                            **
** Description      : return TRUE, if TxRx is done successfully               **
** -None                                                                      **
**                                                                            **
*******************************************************************************/
static boolean SafeWdgExtCic_lTxRxDone
(
    void
)
{
    boolean TxDone = FALSE;
    uint32 Error = 0U;  

    if (SafeWdgExtCic_Data.ResetDelayCnt > 1U)
    {
        /*  in case a Reset request has been sent before, delay the 
            availability of answer in order to delay the next send request */
        SafeWdgExtCic_Data.ResetDelayCnt--;        
        /* last decrement to zero happens after answer is 
            evaluated in SafeWdgExtCic_lInit */
    }
    else
    {
    /* Chk transmission status, if complete, stores response in Rx Buffer*/  
    TxDone = SafeWdgAscLin_RxDone(&Error);

#if (SAFEWDGEXTCIC_TRC_EN == TRUE)
    /* Log communication data to trace buffer */ 
    SafeWdgExtCic_DbgTrace();
#endif

   }
   
   return (TxDone);
   
}


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : boolean SafeWdgExtCic_lCheckRxData (void)                         **
**                                                                            **
** Description : Check received Data for plausibility                         **
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
** Return value    :  TRUE/FALSE                                              **
**                    TRUE: Error not found in received response              **
*******************************************************************************/

static boolean SafeWdgExtCic_lCheckRxData
(  
   void
)
{
   uint8 index;
  
   /* assume error free reception */
   boolean result = TRUE;   
   
   if (SafeWdgExtCic_Data.SecureMode == FALSE)
   { 
      /* Verify received response */ 
      for (index = 0U; index < (CIC_BUF_SIZE-1U); index++)
      {
      
          if ( (SafeWdgExtCic_TxBuffer[index] & CIC_TXCMD_MASK) !=
                ((SafeWdgExtCic_RxBuffer[index+1U] & CIC_RXCMD_MASK) >> CIC_SHFTEIG))
          {
                /* received answer is wrong */
                result = FALSE;
          }
        
      }
    }  
  
   return (result);
} 

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void SafeWdgExtCic_lProcessUsrReq(void)                           **
**                                                                            **
**                                                                            **
** Description : process pending user requests                                **
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
** Return value    :  None                                                    **
**                                                                            **
*******************************************************************************/
static void SafeWdgExtCic_lProcessUsrReq
(
   void
)
{
    /* Get UR buffer */
    SafeWdgIf_CmdType* ThisRequest = SafeWdgExtCic_Data.Request;
    uint8 index = 0U;  
    
    if(SafeWdgExtCic_Data.SecureMode == TRUE )
    {
     for (index = 0U; index < (SafeWdgExtCic_Data.ReqCnt); index++)
     {
      /* Update UR buffer with the received response in Secure SPI mode */ 
      ThisRequest[index].UserData = 
                                 (uint8)(SafeWdgExtCic_RxBuffer[index]>>0x08U);   
      ThisRequest[index].ReqCmd = (uint8)(SafeWdgExtCic_RxBuffer[index]);        
     }
    }   
    else
    {
      /* Read Received data except dummy count*/
      for (index=0U; index < (SafeWdgExtCic_Data.ReqCnt); index++)
      {  
        /* Update UR buffer with the received response when not in Secure SPI 
         * mode */
        ThisRequest[index].UserData = (uint8)(SafeWdgExtCic_RxBuffer[index+1u]);
      }
    }    
} 
 

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void SafeWdgExtCic_MainFunction(void)                             **
**                                                                            **
** Description :   Periodically executed. Monitors and Initiates the          **
** next sequence of activities of the driver                                  **
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
**                                                                            **
*******************************************************************************/

void SafeWdgExtCic_MainFunction 
(
    void
)
{

  SafeWdgIf_ResultType Result = SWDG_JOB_SUCCESS;
  boolean  VerifySPIFrame = TRUE;
  
  if(SafeWdgExtCic_lCheckDataCrc() == E_OK)
  {
  
    /* Chk job state */
    if (SafeWdgExtCic_Data.JobState != CIC_IDLE)
    {
       /* Assume Job failed */
       SafeWdgIf_ResultType JobResult = SWDG_JOB_COM_ERR;
      /* Check if Transmission is complete
       * If complete, store received response 
       */   
       boolean  TransmitDone = SafeWdgExtCic_lTxRxDone();     
     
       /* Chk if transmission is complete */
       if(TransmitDone == TRUE)
       {
         /* Verify received response */
          VerifySPIFrame = SafeWdgExtCic_lCheckRxData();
       }    

       switch (SafeWdgExtCic_Data.JobState)
       {
            case CIC_INIT_JOB:
               /* Chk Data transmission status */
               if (TransmitDone == TRUE) 
               { 
                  /*
                   * When BIST is running, CIC will send 
                   * 0xFFFF. So, received data check is not   
                   * required.
                   */ 
         
                  /*
                   * Update Initialization status and take further
                   * action based on response received          
                   */           
                   JobResult = SafeWdgExtCic_lInit(TransmitDone);
        
                   /* Initialization requires multiple attempts based on 
                   CIC state. The Job result is updated only when
                   initialization is complete */
                   if (JobResult != SWDG_JOB_ACCEPTED)
                   {           
                      
                     /* Update Initialization result */
                     SafeWdgExtCic_Data.JobResult = JobResult;          
                     /*  JobResult != success, initialization failed */
                     if((JobResult != SWDG_JOB_SUCCESS) 
                                                  && (VerifySPIFrame != TRUE))
                     {
                         /* init Job failed, no communication possible */
                         SafeWdgExtCic_Data.JobResult =  SWDG_JOB_COM_ERR;  
                     }                     
                     /* Initialization is complete */
                     SafeWdgExtCic_Data.JobState = CIC_IDLE;
           
                   }                              
                 }           
                 break;
         
            case CIC_ACTIVATE_JOB:
                /* Chk Data transmission status */
                if (TransmitDone == TRUE) 
                {       
                  /* Update Cic state */
                  SafeWdgExtCic_lUpdateStatus();
                  /* Update job result */
                  SafeWdgExtCic_Data.JobResult = Result;
                  /* Chk verification result */
                  if (VerifySPIFrame == FALSE)
                  {
                     /* Incorrect frame received, Update result */
                     SafeWdgExtCic_Data.JobResult = SWDG_JOB_COM_ERR;  
                  }                  
                  /* Update job state */
                  SafeWdgExtCic_Data.JobState = CIC_IDLE;
          
                } 
                break;

            case CIC_SERVICE_JOB:
                /* Chk Data transmission status */
                if (TransmitDone == TRUE)
                {
                  /* Update job result */
                  SafeWdgExtCic_Data.JobResult = Result;
                  /* Chk verification result */
                  if (VerifySPIFrame == FALSE)
                  {
                    /* Incorrect frame received, Update result */
                    SafeWdgExtCic_Data.JobResult = SWDG_JOB_COM_ERR;     
                  }                  
                  /* Update job state */
                  SafeWdgExtCic_Data.JobState = CIC_IDLE;
          
                }                                
                break;

            case CIC_USERREQ_JOB:
                /* Chk Data transmission status */
                if (TransmitDone == TRUE) 
                {         
                  /* User request is finished. Process received data  */
                  SafeWdgExtCic_lProcessUsrReq();
                  /* Update job result */
                  SafeWdgExtCic_Data.JobResult = Result;                 
                  /* Chk verification result */
                  if (VerifySPIFrame == FALSE)
                  {
                    /* Incorrect frame received, Update result */
                    SafeWdgExtCic_Data.JobResult = SWDG_JOB_COM_ERR;    
                  }                  
                  /* Update job state */
                  SafeWdgExtCic_Data.JobState  = CIC_IDLE;
                  
          
                }                
                break;

            case CIC_GETINFO_JOB:
                /* Chk Data transmission status */
                if (TransmitDone == TRUE) 
                {
                    /* Update Cic status */
                    SafeWdgExtCic_lUpdateStatus();
                    /* Update job result */
                    SafeWdgExtCic_Data.JobResult = Result;       
                    /* Chk verification result */
                    if (VerifySPIFrame == FALSE)
                    {
                      /* Incorrect frame received, Update result */  
                      SafeWdgExtCic_Data.JobResult = SWDG_JOB_COM_ERR;      
                    }                    
                    /* Update job state */
                    SafeWdgExtCic_Data.JobState  = CIC_IDLE;
          
                }                
                break;
      
            case CIC_DEINIT_JOB:
      
                if (TransmitDone == TRUE) 
                 {
                    /* De-initialize ASCLIN handler */
                    SafeWdgAscLin_DeInit();
                    /* Change state of this driver */
                    SafeWdgExtCic_Data.LastState = SAFEWDG_CIC_UNKNOWN;  
                    /* Update Cic job result */
                    SafeWdgExtCic_Data.JobResult = SWDG_JOB_SUCCESS;                    
                    /* Update job state */
                    SafeWdgExtCic_Data.JobState  = CIC_IDLE; 
                }                     
                break;
                
            default:
                /* unknown Job, Update job state */        
                SafeWdgExtCic_Data.JobState  = CIC_IDLE;
                break;
        }

     }
     
    SafeWdgExtCic_lSetDataCrc();
  }
  else
  {
     SafeWdgExtCic_Data.JobResult = SWDG_JOB_FAILED_CRC;  
  }
  
  
   
} 

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgExtCic_Info(void)                     **
**                                                                            **
** Description :   Initiates the read of CIC61508 status registers            **
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
** Return value    : SWDG_JOB_ACCEPTED: Job accepted and ongoing              **
**                   SWDG_JOB_FAILED_CRC: Job failed due to driver internal   **
**                                        data checksum failure.              **
**                   SWDG_JOB_BUSY: Job failed because driver is busy         **
**                                  processing the earlier job request.       **
**                   SWDG_JOB_INV_STATE: Job failed because job is            **
**                                          requested from a forbidden state. ** 
*******************************************************************************/

SafeWdgIf_ResultType  SafeWdgExtCic_GetWdgInfo 
(
    void
)
{   
    SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;
  
    /* Chk Crc check */
    if(SafeWdgExtCic_lCheckDataCrc() == E_OK)
    {
     /* Chk job state */ 
     if (SafeWdgExtCic_Data.JobState == CIC_IDLE) 
     {
       
        if (SafeWdgExtCic_Data.SecureMode == FALSE )
        {
            /* Update job status */
            SafeWdgExtCic_Data.JobState = CIC_GETINFO_JOB;
            /* Update Tx Buffer to CIC status */
            SafeWdgExtCic_TxBuffer[0] = CIC_RD_OPCSEQ;
            SafeWdgExtCic_TxBuffer[1] = CIC_RD_ERRCNT;
            SafeWdgExtCic_TxBuffer[2] = CIC_RD_STATE;
            SafeWdgExtCic_TxBuffer[3] = CIC_RD_SVERS;
            SafeWdgExtCic_TxBuffer[4] = CIC_RD_SVERS;
        
            /* Transmit data to get Cic status*/
            SafeWdgExtCic_lTransmit(SafeWdgExtCic_TxBuffer);
            
            Result = SWDG_JOB_ACCEPTED;
        } 
		else
		{
		   Result  = SWDG_JOB_INV_STATE;
		}
    
     } /* Chk job state */ 
     else
     {
         Result = SWDG_JOB_BUSY;
     }
   
   } /* Chk Crc check */

   /* Update job result */
   SafeWdgExtCic_Data.JobResult = Result;
   
   /* update crc */
   SafeWdgExtCic_lSetDataCrc();

    return (Result);
} 

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static void SafeWdgExtCic_lTransmit(uint16* const TxBuf)          **
**                                                                            **
** Description :   Initiates the sending of any request/data/cmd to CIC61508  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TxBuf Pointer to transmit data                           **
** Parameters (out): None                                                     **
** Return value    : None                                                     **
**                                                                            **
**  Attention: Always sends exactly five commands to CIC                      **
*******************************************************************************/

static void SafeWdgExtCic_lTransmit
(   
    uint16* const TxBuf
)
{ 
  
    /* set up counter */
    uint8 index = 0U;
    /* Set No of Transmit Count Value */ 
    uint8 Count = CIC_TXCNT_FIVE;
    /* Reset reeive buffer */
    for (index = 0U; index<CIC_BUF_SIZE; index++)
    {
         /* clear Rx Buffer */
         SafeWdgExtCic_RxBuffer[index] = 0U;
    }
    
    if (SafeWdgExtCic_Data.SecureMode == TRUE)
    {
        Count = SafeWdgExtCic_Data.ReqCnt;                    
    }
    /* send data using ASCLIN driver*/
    SafeWdgAscLin_TxRx(TxBuf, SafeWdgExtCic_RxBuffer, Count);    
  
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static void SafeWdgExtCic_lUpdateStatus (void)                    **
**                                                                            **
** Description :   Update local status variables from Receive buffer          **
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

static void SafeWdgExtCic_lUpdateStatus
(
    void
)
{  
  /* Update seed */     
  SafeWdgExtCic_Data.LastSeed   = 
                          ((uint8)(SafeWdgExtCic_RxBuffer[1] & CIC_SEED_MASK));
  /* Update Error Counter */ 
  SafeWdgExtCic_Data.LastErrCnt = 
                        ((uint8)(SafeWdgExtCic_RxBuffer[2] & CIC_RXDATA_MASK));
  /* Updated Cic state*/  
  SafeWdgExtCic_Data.LastState  = 
                        ((uint8)(SafeWdgExtCic_RxBuffer[3] & CIC_RXDATA_MASK));
}

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : SafeWdgIf_ResultType SafeWdgExtCic_GetJobResult(void)   **
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
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Return Job Result                      .                **
** -None                                                                      **
**                                                                            **
*******************************************************************************/

SafeWdgIf_ResultType SafeWdgExtCic_GetJobResult
(
   void
)
{
  /* Chk Crc check */
  if(SafeWdgExtCic_lCheckDataCrc() != E_OK)
  {
    SafeWdgExtCic_Data.JobResult = SWDG_JOB_FAILED_CRC;
  }
  /* Return job result */
  return(SafeWdgExtCic_Data.JobResult);

} 
/*******************************************************************************
**                      Debug Purpose Definitions                             **
*******************************************************************************/

#if (SAFEWDGEXTCIC_TRC_EN == TRUE)
/*******************************************************************************
 ** Traceability: [cover parentID= <id_1>, <id_2>]                            **
 **                                                                           **
 ** Syntax : void    SafeWdgExtCic_DbgTrace(void)                             **
 **                                                                           **
 ** Description :  Log communication data to trace buffer                     **
 **                                                                           **
 ** [/cover]                                                                  **
 **                                                                           **
 ** Service ID: None                                                          **
 **                                                                           **
 ** Sync/Async: Synchronous                                                   **
 **                                                                           **
 ** Reentrancy: Non reentrant                                                 **
 **                                                                           **
 ** Parameters (in) :   None                                                  **
 ** Parameters (out):   None                                                  **
 ** Return value    :   None                                                  **
 **                                                                           **
 ******************************************************************************/

static void SafeWdgExtCic_DbgTrace
(
    void
)
{
    uint16 Idx = SafeWdgExtCic_TrcIdx  % ((uint16) CIC_TRC_SIZE);

    if ((SafeWdgExtCic_TrcIdx <  CIC_TRC_SIZE) 
                                         || (SAFEWDGEXTCIC_TRCFREEZE == FALSE))
    {
        /*Store trace index */
        SafeWdgExtCic_DbgTrc[Idx][0]  = SafeWdgExtCic_TrcIdx;
        /* Store job state */
        SafeWdgExtCic_DbgTrc[Idx][1]  = (uint16) SafeWdgExtCic_Data.JobState;
        /* Log the TxRx data */
        SafeWdgExtCic_DbgTrc[Idx][2]  = SafeWdgExtCic_TxBuffer[0];
        SafeWdgExtCic_DbgTrc[Idx][3]  = SafeWdgExtCic_RxBuffer[0];
        SafeWdgExtCic_DbgTrc[Idx][4]  = SafeWdgExtCic_TxBuffer[1];
        SafeWdgExtCic_DbgTrc[Idx][5]  = SafeWdgExtCic_RxBuffer[1];
        SafeWdgExtCic_DbgTrc[Idx][6]  = SafeWdgExtCic_TxBuffer[2];
        SafeWdgExtCic_DbgTrc[Idx][7]  = SafeWdgExtCic_RxBuffer[2];
        SafeWdgExtCic_DbgTrc[Idx][8]  = SafeWdgExtCic_TxBuffer[3];
        SafeWdgExtCic_DbgTrc[Idx][9]  = SafeWdgExtCic_RxBuffer[3];
        SafeWdgExtCic_DbgTrc[Idx][10] = SafeWdgExtCic_TxBuffer[4];
        SafeWdgExtCic_DbgTrc[Idx][11] = SafeWdgExtCic_RxBuffer[4];
        /* Increment trace index */
        SafeWdgExtCic_TrcIdx++;
    }
}
#endif

/*******************************************************************************
**                      CRC Functios                                          **
*******************************************************************************/

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Std_ReturnType SafeWdgExtCic_CheckDataCrc(void)                   **
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
*******************************************************************************/

static Std_ReturnType SafeWdgExtCic_lCheckDataCrc
(
    void
)
{
    uint32 CurrCrc          = 0U;
    
    /* Chk Crc */ 
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.JobState);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.LastSeed);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.LastState);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.LastErrCnt);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.SyncCnt);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.ResetDelayCnt);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.ResetCnt);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.ReqCnt);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.Request);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.SecureMode);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.ConfigPtr);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.JobResult);

    return ((CurrCrc == SafeWdgExtCic_Data.Crc) ? E_OK : E_NOT_OK);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void SafeWdgExtCic_lSetDataCrc(void)                              **
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
*******************************************************************************/

static void SafeWdgExtCic_lSetDataCrc
(
    void
)
{
    uint32 CurrCrc          = 0U;
  
    /* Update Crc */
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.JobState);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.LastSeed);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.LastState);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.LastErrCnt);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.SyncCnt);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.ResetDelayCnt);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.ResetCnt);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.ReqCnt);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.Request);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.SecureMode);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.ConfigPtr);
    CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtCic_Data.JobResult);
    SafeWdgExtCic_Data.Crc = CurrCrc;
}
#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
