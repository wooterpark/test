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
**   $FILENAME   : SafeWdgAscLin.c $                                          **
**                                                                            **
**   $CC VERSION : \main\46 $                                                 **
**                                                                            **
**   $DATE       : 2016-02-29 $                                               **
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
**                 - driver for ASCLIN to be used for ext CIC watchdog        **
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

#include "IfxAsclin_reg.h"
#include "IfxSrc_reg.h"
#include "IfxDma_reg.h"
#include "SafeWdgIf.h"
#include "SafeWdgAscLin.h"

/*******************************************************************************
 **                      Private Macro Definitions                            **
 ******************************************************************************/

/*******************************************************************************
 **                   Function like macro definitions                         **
 ******************************************************************************/

/* Used to update RFL flag */
#define SAFEWDGASCLIN_CLEAR_RFLFLAG     (0x1U)

/* Used for register configurations */
#define SAFEWDGASCLIN_REG_RESET         (0x00000000U)
#define SAFEWDGASCLIN_CLR_FLAGS         (0xDFFFE06FU)
#define SAFEWDGASCLIN_RESET_CNT         (0x0U)
#define SAFEWDGASCLIN_NO_CLK            (0x0U)
#define SAFEWDGASCLIN_EMPTY_FIFO        (0x1U)
#define SAFEWDGASCLIN_WDTH_TWO          (0x2U)
#define SAFEWDGASCLIN_LEVEL_ZERO        (0x0U)
#define SAFEWDGASCLIN_RXFIFO_LEVEL      (0x1U)
#define SAFEWDGASCLIN_TRASMIT_EN        (0x1U)
#define SAFEWDGASCLIN_SPI_MODE          (0x2U)
#define SAFEWDGASCLIN_SM_ZERO           (0x0U)
#define SAFEWDGASCLIN_DATLEN            (0x0FU)
#define SAFEWDGASCLIN_CLC_CLK           (0x01U)
#define SAFEWDGASCLIN_DISABLE           (0x1U)
#define SAFEWDGASCLIN_INIT_ZERO         (0x0U)
#define SAFEWDGASCLIN_WAITOVER          (0x1U)
#define SAFEWDGASCLIN_RXFIFO_CHK        (0x2U)
#define SAFEWDGASCLIN_TXDONE            (0xFF)
#define SAFEWDGASCLIN_TXNOTDONE         (0x01)
#define SAFEWDGASCLIN_CPOL_IDLELOW      (0x0U)
#define SAFEWDGASCLIN_LB_DISABLE        (0x0U) 
#define SAFEWDGASCLIN_BUFMODE_ZERO      (0x0U)
#define SAFEWDGASCLIN_PEN_DISABLE       (0x0U)

/* DMA Configuration */
#define SAFEWDGASCLIN_DMACFG_TREL       (0U)
#define SAFEWDGASCLIN_DMACFG_BLKM       (16U)
#define SAFEWDGASCLIN_DMACFG_RROAT      (19U)
#define SAFEWDGASCLIN_DMACFG_CHMODE     (20U)
#define SAFEWDGASCLIN_DMACFG_CHDW       (21U)
#define SAFEWDGASCLIN_DMACFG_PATSEL     (24U)
#define SAFEWDGASCLIN_DMACFG_PRSEL      (28U)
#define SAFEWDGASCLIN_DMACFG_DMAPRIO    (30U)
#define SAFEWDGASCLIN_DMACFG_HIGHPRIO   (3UL)
#define SAFEWDGASCLIN_DMACFG_TRELCNT    (5UL)
#define SAFEWDGASCLIN_DMACFG_SMF        (0U)
#define SAFEWDGASCLIN_DMACFG_INCS       (3U)
#define SAFEWDGASCLIN_DMACFG_DMF        (4U)
#define SAFEWDGASCLIN_DMACFG_INCD       (7U)
#define SAFEWDGASCLIN_DMACFG_CBLS       (8U)
#define SAFEWDGASCLIN_DMACFG_CBLD       (12U)
#define SAFEWDGASCLIN_DMACFG_SHCT       (16U)
#define SAFEWDGASCLIN_DMACFG_SHWEN      (18U)
#define SAFEWDGASCLIN_DMACFG_SCBE       (20U)
#define SAFEWDGASCLIN_DMACFG_DCBE       (21U)
#define SAFEWDGASCLIN_DMACFG_WRPSE      (24U)
#define SAFEWDGASCLIN_DMACFG_WRPDE      (25U)
#define SAFEWDGASCLIN_DMACFG_INTCT      (26U)
#define SAFEWDGASCLIN_DMACFG_IRDV       (28U)
#define SAFEWDGASCLIN_DMACFG_SADRSIZE   (8UL)
#define SAFEWDGASCLIN_DMA_EN_HTR        (0x00010000U)
#define SAFEWDGASCLIN_DMA_DIS_HTR       (0x00020000U)
#define SAFEWDGASCLIN_DMA_CH_STOP       (0x00000001U)


/*******************************************************************************
 **                      Private Type Definitions                             **
 ******************************************************************************/

/* Local working data for AscLin driver */
typedef struct SafeWdgAscLin_DataType
{
    /* Stores configured configuration pointer for AscLin */
    const SafeWdgAscLin_ConfigType*  CfgPtr;
    /* Stores ptr for the selected module */
    volatile Ifx_ASCLIN*            AscLinModptr;
    /* Store buffer pointer for transmit buffer */
    uint16*                          TxBufPtr;
    /* Stores buffer pointer for receive buffer */
    uint16*                          RxBufPtr;
    /* Stores no of count of data to be transferred to Cic*/
    uint8                            Count;
} SafeWdgAscLin_DataType;

/*******************************************************************************
 **                      Global Constant Definitions                          **
 ******************************************************************************/

/*******************************************************************************
 **                      Global Variable Definitions                          **
 ******************************************************************************/

/*******************************************************************************
 **                      Private Constant Definitions                         **
 ******************************************************************************/

/*******************************************************************************
 **                      Private Variable Definitions                         **
 ******************************************************************************/

#define IFX_SWDG_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Initialize Local working data for AscLin driver */  
static SafeWdgAscLin_DataType SafeWdgAscLin_Data = {
                                                     NULL_PTR,
                                                     NULL_PTR,
                                                     NULL_PTR,
                                                     NULL_PTR,
                                                           0U
                                                    };   

#define IFX_SWDG_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"



#define IFX_SWDG_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
 **                      Private Function Declarations                        **
 ******************************************************************************/
 
/* Local function to initialize selected DMA channel */
static void SafeWdgAscLin_lInitDMACh
(
  void
);

/*******************************************************************************
 **                       Function Definitions                                **
 ******************************************************************************/

/*******************************************************************************
 ** Traceability: [cover parentID= <id_1>, <id_2>]                            **
 **                                                                           **
 ** Syntax : SafeWdgIf_ResultType SafeWdgASCLIN_Init                          **
 **                          (const SafeWdgAscLin_ConfigType* const ConfigPtr)**
 **                                                                           **
 ** Description :    Initializes the ASCLIN from configuration                **
 **                                                                           **
 ** [/cover]                                                                  **
 **                                                                           **
 ** Service ID: None                                                          **
 **                                                                           **
 ** Sync/Async: Synchronous                                                   **
 **                                                                           **
 ** Reentrancy: Non reentrant                                                 **
 **                                                                           **
 ** Parameters (in) :  ConfigPtr: pointer to configuration                    **
 ** Parameters (out):  None                                                   **
 ** Return value    :  SWDG_JOB_SUCCESS, if no error occurred                 **
 **                    SWDG_JOB_INV_PARAM,  failures due to Null Pointer      **
 ******************************************************************************/
SafeWdgIf_ResultType SafeWdgAscLin_Init
(
  const SafeWdgAscLin_ConfigType* const ConfigPtr
)
{

  SafeWdgIf_ResultType Result = SWDG_JOB_INV_PARAM;
  volatile uint32 dummy;

  /* check pointer to cfg data */
  if (ConfigPtr != NULL_PTR)
  {
        
      /* Read the selected module number */
      volatile Ifx_ASCLIN* const AscLinModPtr = ConfigPtr->AscLinModule;

      /* Initialization of the ASCLIN interface */
      Mcal_ResetENDINIT();
      /* disable module control */
      AscLinModPtr->CLC.U = SAFEWDGASCLIN_REG_RESET;
      /* read back */
      dummy = AscLinModPtr->CLC.U;  
      Mcal_SetENDINIT();
      
      /* Required to avoid compiler warning */
      UNUSED_PARAMETER(dummy)

      /* clk source, no clk */
      AscLinModPtr->CSR.U = SAFEWDGASCLIN_NO_CLK;

      AscLinModPtr->IOCR.B.SPOL = ConfigPtr->CsPolarity;
      AscLinModPtr->IOCR.B.ALTI = ConfigPtr->RxInputSelect;
      AscLinModPtr->IOCR.B.CPOL = SAFEWDGASCLIN_CPOL_IDLELOW;
      AscLinModPtr->IOCR.B.LB   = SAFEWDGASCLIN_LB_DISABLE;
      
      /*  init TXFIFO, not configurable */
      AscLinModPtr->TXFIFOCON.B.FLUSH    = SAFEWDGASCLIN_EMPTY_FIFO;
      AscLinModPtr->TXFIFOCON.B.INW      = SAFEWDGASCLIN_WDTH_TWO;      
      AscLinModPtr->TXFIFOCON.B.INTLEVEL = SAFEWDGASCLIN_LEVEL_ZERO;
      AscLinModPtr->TXFIFOCON.B.ENO      = SAFEWDGASCLIN_TRASMIT_EN;

      /*  init RXFIFO, not configurable */
      AscLinModPtr->RXFIFOCON.B.FLUSH    = SAFEWDGASCLIN_EMPTY_FIFO;
      AscLinModPtr->RXFIFOCON.B.OUTW     = SAFEWDGASCLIN_WDTH_TWO;
      AscLinModPtr->RXFIFOCON.B.INTLEVEL = SAFEWDGASCLIN_RXFIFO_LEVEL;
      AscLinModPtr->RXFIFOCON.B.ENI      = SAFEWDGASCLIN_TRASMIT_EN;
      AscLinModPtr->RXFIFOCON.B.BUF      = SAFEWDGASCLIN_BUFMODE_ZERO;

      AscLinModPtr->BITCON.B.OVERSAMPLING = ConfigPtr->BConOversample;
      AscLinModPtr->BITCON.B.SAMPLEPOINT  = ConfigPtr->BConSamplePoint;
      AscLinModPtr->BITCON.B.PRESCALER    = ConfigPtr->BConPreScaler;
      /* fixed */
      AscLinModPtr->BITCON.B.SM           = SAFEWDGASCLIN_SM_ZERO;

      AscLinModPtr->FRAMECON.B.IDLE = ConfigPtr->FConIdleCnt;
      AscLinModPtr->FRAMECON.B.STOP = ConfigPtr->FConTrailCnt;
      AscLinModPtr->FRAMECON.B.LEAD = ConfigPtr->FConLeadCnt;
      AscLinModPtr->FRAMECON.B.PEN  =  SAFEWDGASCLIN_PEN_DISABLE;     

      /* SPI mode, fixed */
      AscLinModPtr->FRAMECON.B.MODE = SAFEWDGASCLIN_SPI_MODE;
      AscLinModPtr->FRAMECON.B.MSB  = ConfigPtr->FConMsb;

      /* 16 Data Bits, fixed */
      AscLinModPtr->DATCON.B.DATLEN = SAFEWDGASCLIN_DATLEN;

      AscLinModPtr->BRG.B.DENOMINATOR = ConfigPtr->BrgDenominator;
      AscLinModPtr->BRG.B.NUMERATOR   = ConfigPtr->BrgNumerator;

      /* Clear all Flags */
      AscLinModPtr->FLAGSCLEAR.U = SAFEWDGASCLIN_CLR_FLAGS;

      /* clk source CLC */
      AscLinModPtr->CSR.U = SAFEWDGASCLIN_CLC_CLK;
    
      /* local data initialize */
      SafeWdgAscLin_Data.CfgPtr       = ConfigPtr;
      SafeWdgAscLin_Data.AscLinModptr = AscLinModPtr;
      SafeWdgAscLin_Data.Count        = SAFEWDGASCLIN_RESET_CNT;
      SafeWdgAscLin_Data.RxBufPtr     = NULL_PTR;
      SafeWdgAscLin_Data.TxBufPtr     = NULL_PTR;

      SafeWdgAscLin_lInitDMACh();

      Result = SWDG_JOB_SUCCESS;
        
  }
  
  return (Result);
  
}
/*******************************************************************************
 ** Traceability: [cover parentID= <id_1>, <id_2>]                            **
 **                                                                           **
 ** Syntax : void SafeWdgAscLin_lInitDMACh(void)                              **
 **                                                                           **
 **                                                                           **
 ** Description :    Initializes the ASCLIN from configuration                **
 **                                                                           **
 ** [/cover]                                                                  **
 **                                                                           **
 ** Service ID: None                                                          **
 **                                                                           **
 ** Sync/Async: Synchronous                                                   **
 **                                                                           **
 ** Reentrancy: Non reentrant                                                 **
 **                                                                           **
 ** Parameters (in) :  None                                                   **
 ** Parameters (out):  None                                                   **
 ** Return value    :  None                                                   **
 **                                                                           **
 **                                                                           **
 **                                                                           **
 ******************************************************************************/
static void SafeWdgAscLin_lInitDMACh
(
    void
)
{
    
    /* Read DMA channel number */
    volatile Ifx_DMA_CH* ThisDmaCh =
                        &MODULE_DMA.CH[SafeWdgAscLin_Data.CfgPtr->DmaTxChannel];
    

/******************************************************************************/
/* - DMA Channel Configuration:                                               */
/* - DMA Channel is used to copy the TX buffer to the ASCLIN                  */
/*   module.                                                                  */
/******************************************************************************/

    ThisDmaCh->CHCFGR.U =
           /* TREL    = 5: 5 transfers per transaction  */ 
          (SAFEWDGASCLIN_DMACFG_TRELCNT <<  SAFEWDGASCLIN_DMACFG_TREL) |  
           /* BLKM    = 0: 1 move per DMA transfer  */
          (0UL << SAFEWDGASCLIN_DMACFG_BLKM) |   
          /* RROAT   = 0: 1 request starts transfer */
          (0UL << SAFEWDGASCLIN_DMACFG_RROAT) |   
          /* CHMODE  = 0: Single mode operation */
          (0UL << SAFEWDGASCLIN_DMACFG_CHMODE) |   
          /* CHDW    = 1: 16 bit data width  */
          (1UL << SAFEWDGASCLIN_DMACFG_CHDW) |   
          /* PATSEL  = 0: Pattern detection logic disabled */
          (0UL << SAFEWDGASCLIN_DMACFG_PATSEL) |   
          /* PRSEL   = 0: Hardware trigger is selected */
          (0UL << SAFEWDGASCLIN_DMACFG_PRSEL) |   
          /* DMAPRIO = 1: High DMA request priority */
          (SAFEWDGASCLIN_DMACFG_HIGHPRIO << SAFEWDGASCLIN_DMACFG_DMAPRIO);


    ThisDmaCh->ADICR.U =       
          /* SMF = 0: Source address offset is 1 x CHCR00.CHDW*/
          (0UL <<  SAFEWDGASCLIN_DMACFG_SMF) |  
          /* INCS = 1: Source address offset will be added */
          (1UL <<  SAFEWDGASCLIN_DMACFG_INCS) |  
          /* DMF = 0: Destination address offset is 1 x CHCR00.CHDW*/
          (0UL <<  SAFEWDGASCLIN_DMACFG_DMF) |  
          /* INCD = 0: Destination address remain constant */
          (0UL <<  SAFEWDGASCLIN_DMACFG_INCD) |
          /* CBLS = 5: Source circular buffer length = 32byte  (2^n)*/
          (SAFEWDGASCLIN_DMACFG_SADRSIZE <<  SAFEWDGASCLIN_DMACFG_CBLS) |
          /* CBLD = 0: Destination circular buffer length = 0       */
          (0UL << SAFEWDGASCLIN_DMACFG_CBLD) |  
           /* SHCT = 0: Shadow address register not used    */
          (0UL << SAFEWDGASCLIN_DMACFG_SHCT) |  
          /* SHWEN = 0: Shadow address register is read-only*/
          (0UL << SAFEWDGASCLIN_DMACFG_SHWEN) |  
          /* SCBE  = 0  */
          (0UL << SAFEWDGASCLIN_DMACFG_SCBE) |  
          /* DCBE  = 1  */
          (1UL << SAFEWDGASCLIN_DMACFG_DCBE) |  
          /* WRPSE = 1: Wrap source buffer interrupt enabled*/
          (0UL << SAFEWDGASCLIN_DMACFG_WRPSE) |  
          /* WRPDE = 0: Wrap destination buffer interrupt disabled      */
          (0UL << SAFEWDGASCLIN_DMACFG_WRPDE) |  
          /* INTCT = 0: No interrupt generated on changing TCOUNT value */
          (0UL << SAFEWDGASCLIN_DMACFG_INTCT) |  
          /* IRDV  = 0: TCOUNT interrupt threshold = 0 (not used!)      */
          (0UL << SAFEWDGASCLIN_DMACFG_IRDV);

       
    
}
/*******************************************************************************
 ** Traceability: [cover parentID= <id_1>, <id_2>]                            **
 **                                                                           **
 ** Syntax : void SafeWdgAscLin_DeInit (void)                                 **
 **                                                                           **
 ** Description :                                                             **
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
void SafeWdgAscLin_DeInit
(
    void
)
{

    volatile uint32 dummy;
    /* Read the AscLin module number */
    volatile Ifx_ASCLIN* AscLinModPtr = SafeWdgAscLin_Data.AscLinModptr; 
    /* De-Initialize DMA channels also */
     
    volatile Ifx_DMA_TSR* ThisDmaTsr = 
                     &MODULE_DMA.TSR[SafeWdgAscLin_Data.CfgPtr->DmaTxChannel];  
    volatile Ifx_DMA_CH* ThisDmaCh =
                        &MODULE_DMA.CH[SafeWdgAscLin_Data.CfgPtr->DmaTxChannel];
    /* reset the ASCLIN interface */

    /* reset asclin sfrs */
    AscLinModPtr->CSR.U         = SAFEWDGASCLIN_REG_RESET;
    AscLinModPtr->IOCR.U        = SAFEWDGASCLIN_REG_RESET;
    AscLinModPtr->TXFIFOCON.U   = SAFEWDGASCLIN_REG_RESET;
    AscLinModPtr->RXFIFOCON.U   = SAFEWDGASCLIN_REG_RESET;
    AscLinModPtr->BITCON.U      = SAFEWDGASCLIN_REG_RESET;
    AscLinModPtr->FRAMECON.U    = SAFEWDGASCLIN_REG_RESET;
    AscLinModPtr->DATCON.U      = SAFEWDGASCLIN_REG_RESET;
    AscLinModPtr->BRG.U         = SAFEWDGASCLIN_REG_RESET;

    /* Clear all Flags */
    AscLinModPtr->FLAGSCLEAR.U  = SAFEWDGASCLIN_CLR_FLAGS;

    /* disable all flags */
    AscLinModPtr->FLAGSENABLE.U = SAFEWDGASCLIN_REG_RESET;

    Mcal_ResetENDINIT();
    /* disable module control */
    AscLinModPtr->CLC.B.DISR    = SAFEWDGASCLIN_DISABLE;
    /* read back */
    dummy = AscLinModPtr->CLC.U; 
    /* do not switch off DMA module */
    Mcal_SetENDINIT();    
    /* Required to avoid compiler warning */
    UNUSED_PARAMETER(dummy)    
    
    /* DeInit DMA channel used to transmit data */
    ThisDmaTsr->U |= SAFEWDGASCLIN_DMA_DIS_HTR;
    ThisDmaTsr->U |= SAFEWDGASCLIN_DMA_CH_STOP; 
    ThisDmaCh->CHCFGR.U = 0U;
    ThisDmaCh->ADICR.U =  0U;
    /* Channel source address */
    ThisDmaCh->SADR.U = 0U;
    /* Channel destination address */
    ThisDmaCh->DADR.U = 0U;                 
    
}
/*******************************************************************************
 ** Traceability: [cover parentID= <id_1>, <id_2>]                            **
 **                                                                           **
 ** Syntax : void SafeWdgAscLin_TxRx (uint16* TxBuf, uint16* RxBuf,           **
 **                                                            uint8 Count)   **
 ** Description :  Send the given buffer to SPI via ASCLIN and setup receiv...**
 **                buffer                                                     **
 **                                                                           **
 ** [/cover]                                                                  **
 **                                                                           **
 ** Service ID: None                                                          **
 **                                                                           **
 ** Sync/Async: Synchronous                                                   **
 **                                                                           **
 ** Reentrancy: Non reentrant                                                 **
 **                                                                           **
 ** Parameters (in) :   uint16* TxBuf: Pointer to transmit buffer,            **
 **                     uint16* RxBuf: Pointer to receive buffer,             **
 **                     uint8   Count: No of data to be transmitted           **
 ** Parameters (out):   None                                                  **
 ** Return value    :   None                                                  **
 **                                                                           **
 ******************************************************************************/
void SafeWdgAscLin_TxRx
(
    uint16* TxBuf, 
    uint16* RxBuf, 
    uint8 Count
)
{
    /*const SafeWdgAscLin_ConfigType* ConfigPtr = SafeWdgAscLin_Data.CfgPtr;*/
    volatile Ifx_ASCLIN* AscLinModPtr = SafeWdgAscLin_Data.AscLinModptr;
    volatile Ifx_DMA_CH*  ThisDmaCh;
    volatile Ifx_DMA_TSR* ThisDmaTsr;
    SafeWdgAscLin_EnIfdTmrChOSM AscLinEnableTOMChOSMFunc;
    AscLinEnableTOMChOSMFunc    = SafeWdgAscLin_Data.CfgPtr->EnableTOMChOSMFunc;

    /* remember send/receive request */
    SafeWdgAscLin_Data.Count    = Count;
    SafeWdgAscLin_Data.RxBufPtr = RxBuf;
    SafeWdgAscLin_Data.TxBufPtr = TxBuf;

    /* setup transmit DMA */
    ThisDmaCh = &MODULE_DMA.CH[SafeWdgAscLin_Data.CfgPtr->DmaTxChannel];

    /* Channel source address = TX buffer */
    ThisDmaCh->SADR.U = (uint32)(SafeWdgAscLin_Data.TxBufPtr);

    /* Channel destination address = ASCLIN3 TX buffer */
    ThisDmaCh->DADR.U = (uint32) (&AscLinModPtr->TXDATA.U);
    
    /* send initial data */
    ThisDmaCh->CHCFGR.B.TREL = (uint8)Count;

    ThisDmaTsr = &MODULE_DMA.TSR[SafeWdgAscLin_Data.CfgPtr->DmaTxChannel];
    
    ThisDmaTsr->U |= SAFEWDGASCLIN_DMA_EN_HTR;

    /* Enable single continuous mode for next transfer */
    AscLinEnableTOMChOSMFunc();

}
/*******************************************************************************
 ** Traceability: [cover parentID= <id_1>, <id_2>]                            **
 **                                                                           **
 ** Syntax : boolean SafeWdgAscLin_RxDone (uint32* Error)                     **
 **                                                                           **
 ** Description :  Check availability of SPI answer and whether               **
 **                 pending request finished                                  **
 **                                                                           **
 ** [/cover]                                                                  **
 **                                                                           **
 ** Service ID: None                                                          **
 **                                                                           **
 ** Sync/Async: Synchronous                                                   **
 **                                                                           **
 ** Reentrancy: Non reentrant                                                 **
 **                                                                           **
 ** Parameters (in) :   Error : Indicates communication error                 **
 ** Parameters (out):   Error                                                 **
 ** Return value    :   TRUE : Request complete.                              **
 **                     FALSE: Request in not complete                        **
 **                                                                           **
 ******************************************************************************/
boolean SafeWdgAscLin_RxDone
(
    uint32* Error
)
{
       
    boolean Result = FALSE;
  
    /* Read the function to be used to disable the channel*/
    SafeWdgAscLin_DisIfdTmrChOSM AscLinDisableTOMChOSMFunc;
    AscLinDisableTOMChOSMFunc = SafeWdgAscLin_Data.CfgPtr->DisableTOMChFunc;
   
    /* Chk if data transfer is requested */
    if (SafeWdgAscLin_Data.Count > SAFEWDGASCLIN_RESET_CNT)
    {
        /* Read AscLin module number */
        volatile Ifx_ASCLIN* AscLinModPtr = SafeWdgAscLin_Data.AscLinModptr;
    
        /* Chk flag status, whether buffer is full */
        if (AscLinModPtr->FLAGS.B.RFL == SAFEWDGASCLIN_WAITOVER)
        { 
            uint8 TmpCnt;
    
            /* clear receive pending flag (RFL flag)*/
            AscLinModPtr->FLAGSCLEAR.B.RFLC = SAFEWDGASCLIN_CLEAR_RFLFLAG;
        
            /* check FIFO filling level additionally */
            if (AscLinModPtr->RXFIFOCON.B.FILL == 
                          (SAFEWDGASCLIN_RXFIFO_CHK * SafeWdgAscLin_Data.Count))
            {
          
                *Error = (uint32) SAFEWDGASCLIN_TXDONE;
                for (TmpCnt=SAFEWDGASCLIN_INIT_ZERO; 
                                   TmpCnt < SafeWdgAscLin_Data.Count; TmpCnt++)
                {
                    SafeWdgAscLin_Data.RxBufPtr[TmpCnt] = 
                                                (uint16) AscLinModPtr->RXDATA.U;
                }
                
                /* request finished */
                SafeWdgAscLin_Data.Count = SAFEWDGASCLIN_INIT_ZERO;

                /* Update the result */
                Result = TRUE;
                
                /* Disable TOM Channel. This is a callback function */
                AscLinDisableTOMChOSMFunc();
            }
            else
            {
               *Error = (uint32) SAFEWDGASCLIN_TXNOTDONE;
            }      
      
        }
    }
    return (Result);
}


#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
