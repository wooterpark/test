/*******************************************************************************
** Copyright (C) Infineon Technologies (2013)                                 
**                                                                            
** All rights reserved.                                                        
**                                                                           
** This document contains proprietary information belonging to Infineon        
** Technologies. Passing on and copying of this document, and communication
** of its contents is not permitted without prior written authorization.
**                                                                            
********************************************************************************
**   $FILENAME   : SafeWdgQspi.c $                                            **
**                                                                            
**   $CC VERSION : \main\46 $                                                 **
**                                                                         
**   $DATE       : 2018-02-22 $                                               **
**                                                                       
**  VARIANT    : VariantPB                                     
**                                                                       
**  PLATFORM  : Infineon AURIX                           
**                                                                       
**  COMPILER  : Tasking                                       
**                                                                       
**  AUTHOR    : SafeTlib Team                               
**                                                                       
**  VENDOR    : Infineon Technologies                    
**                                                                       
**  TRACEABILITY:                                               
**                                                                       
**  DESCRIPTION   : This file contains   QSPI driver routines                       
**                                                                       
**  SPECIFICATION(S) :                                       
**                                                                       
**  MAY BE CHANGED BY USER [Yes/No]: No          
**                                                                       
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Compiler_Cfg.h"
#include "SafeWdgIf.h"
#include "IfxCpu_reg.h"
#include "IfxDma_reg.h"
#include "IfxQspi_reg.h"
#include "IfxScu_reg.h"
#include "Mcal_TcLib.h"
#include "Mcal_WdgLib.h"
#include "ChipId.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/* QSPIx_CLC bits: */
#define SAFEWDGQSPI_CLCDISRBIT                  ( (uint32)0x00000001U )
#define SAFEWDGQSPI_CLCDISSBIT                  ( (uint32)0x00000002U )

/* QSPIx_POSEL bits: */
#define SAFEWDGQSPI_PISELMRIS_MASK              ( (uint32)0x00000007U )

/* QSPIx_GLOBALCON bits: */
#define SAFEWDGQSPI_GLOBCON_TQMASK              ( (uint32)0x000000FFU )
#define SAFEWDGQSPI_GLOBCON_SRFBIT              ( (uint32)0x00200000U )
#define SAFEWDGQSPI_GLOBCON_ENBIT               ( (uint32)0x01000000U )


/* QSPIx_ECONz bits: */
#define SAFEWDGQSPI_ECON_QMASK                  ( (uint32)0x0000003FU )
#define SAFEWDGQSPI_ECON_AMASK                  ( (uint32)0x000000C0U )
#define SAFEWDGQSPI_ECON_APOS                   ( 6U )
#define SAFEWDGQSPI_ECON_BMASK                  ( (uint32)0x00000300U )
#define SAFEWDGQSPI_ECON_BPOS                   ( 8U )
#define SAFEWDGQSPI_ECON_CMASK                  ( (uint32)0x00000C00U )
#define SAFEWDGQSPI_ECON_CPOS                   ( 10U )
#define SAFEWDGQSPI_ECON_CPHMASK                ( (uint32)0x00001000U )
#define SAFEWDGQSPI_ECON_CPHPOS                 ( 12U )
#define SAFEWDGQSPI_ECON_CPOLMASK               ( (uint32)0x00002000U )
#define SAFEWDGQSPI_ECON_CPOLPOS                ( 13U )
#define SAFEWDGQSPI_ECON_PARENMASK              ( (uint32)0x00004000U )
#define SAFEWDGQSPI_ECON_PARENPOS               ( 14U )

/* QSPIx_BACON bits: */

/*Reset value of the bit*/
#define SAFEWDGQSPI_BACON_LASTBIT               ( (uint32)0x00000001U )
#define SAFEWDGQSPI_BACON_IPREPOS               ( 1U )
#define SAFEWDGQSPI_BACON_IPREMASK              ( (uint32)0x0000000EU )
#define SAFEWDGQSPI_BACON_IDLEPOS               ( 4U )
#define SAFEWDGQSPI_BACON_IDLEMASK              ( (uint32)0x00000070U )
#define SAFEWDGQSPI_BACON_LPREPOS               ( 7U )
#define SAFEWDGQSPI_BACON_LPREMASK              ( (uint32)0x00000380U )
#define SAFEWDGQSPI_BACON_LEADPOS               ( 10U )
#define SAFEWDGQSPI_BACON_LEADMASK              ( (uint32)0x00001C00U )
#define SAFEWDGQSPI_BACON_TPREPOS               ( 13U )
#define SAFEWDGQSPI_BACON_TPREMASK              ( (uint32)0x0000E000U )
#define SAFEWDGQSPI_BACON_TRAILPOS              ( 16U )
#define SAFEWDGQSPI_BACON_TRAILMASK             ( (uint32)0x00070000U )
#define SAFEWDGQSPI_BACON_PARTYPPOS             ( 19U )
#define SAFEWDGQSPI_BACON_PARTYPMASK            ( (uint32)0x00080000U )
#define SAFEWDGQSPI_BACON_MSBPOS                ( 21U )
#define SAFEWDGQSPI_BACON_MSBMASK               ( (uint32)0x00200000U )
#define SAFEWDGQSPI_BACON_DLPOS                 ( 23U )
#define SAFEWDGQSPI_BACON_DLMASK                ( (uint32)0x0F800000U )
#define SAFEWDGQSPI_BACON_CSPOS                 ( 28U )
#define SAFEWDGQSPI_BACON_CSMASK                ( (uint32)0xF0000000U )

/* QSPIx SSOC bits: */
#define SAFEWDGQSPI_SSOC_OENPOS                 ( 16U )


/* QSPIx FLAGSCLEAR bits: */
#define SAFEWDGQSPI_FLGCL_ERRMASK               ( (uint32)0x000001FFU )
#define SAFEWDGQSPI_FLGCL_RXCBIT                ( (uint32)0x00000400U )

/* QSPIx_STATUS bits: */

#define SAFEWDGQSPI_STAT_ERRFLGMASK             ( (uint32)0x000001FFU )

/* QSPIx SFR reset values: */
#define SAFEWDGQSPI_PISEL_RESVAL               ( (uint32)0x00000000U )
#define SAFEWDGQSPI_GLOBCON_RESVAL             ( (uint32)0x000F30FFU )
#define SAFEWDGQSPI_GLOBCON1_RESVAL            ( (uint32)0x00050000U )
#define SAFEWDGQSPI_ECON_RESVAL                ( (uint32)0x00001450U )
#define SAFEWDGQSPI_SSOC_RESVAL                ( (uint32)0x00000000U )

/* Time-out for enabling the QSPI clock: */
#define SAFEWDGQSPI_CLK_ENTIMEOUT              ( (uint32)0x00000100U )


/*SRC bits*/
#define SAFEWDGQSPI_SRC_SRE_POS               ( 10U )
#define SAFEWDGQSPI_SRC_TOS_POS               ( 11U )

/* DMA_TSRz register: DCH,ECH,RST bit positions */
#define SAFEWDGQSPI_DMA_TSR_DCH_POS               ( (uint32)17U )
#define SAFEWDGQSPI_DMA_TSR_RST_POS               ( (uint32)0U )
#define SAFEWDGQSPI_DMA_TSR_ECH_POS               ( (uint32)16U )
#define SAFEWDGQSPI_DMA_TSR_MASK                  ( (uint32)0x0107030FU )
#define SAFEWDGQSPI_DMA_TSR_RST_TIMEOUT           ( (uint32)50U ) 

/*TC21,22 and 23x has one core and to choose TOS as DMA, TOS bit shoult be
  set to 1. For others, TOS should be set to 3*/
#if ((CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U) )
  #define SAFEWDGQSPI_DMA_SER                   ( 1U )
#else
  #define SAFEWDGQSPI_DMA_SER                   ( 3U )
#endif


/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/* Type definition SafeWdgQspi_DataType - local data of the QSPI driver:  */
typedef struct SafeWdgQspi_DataType
{
    /* Stores error flag status */
    uint32                                    ErrorFlags;
    /* Stores SPI timing details */
    uint32                                    Bacon;
    /* Pointer to configuration container for QSPI channel */ 
    const SafeWdgQspi_ChannelConfigType*      CfgPtr;
    /* Qspi module pointer */
    volatile Ifx_QSPI*                         QspiModptr;
    /*Service request register for Tx & Rx Interrupts*/
    volatile Ifx_SRC_SRCR*                    TxSrcReg;
    volatile Ifx_SRC_SRCR*                    RxSrcReg;  
    /* Store Tx and Rx buffer pointer */  
    uint32*                                   TxBufPtr;
    uint32*                                   RxBufPtr;  
    /* Store DMA Tx and Rx channel */  
    uint8                                     TxDmaChannel;    
    uint8                                     RxDmaChannel;
    /* Store no of transfers request required */    
    uint8                                     Count;
    /* Store receive count */
    uint8                                     DataCount;
    /* function pointer used by SafeWdgQspi_CustTxRx */
    SafeWdgQspi_UserCallbackFuncType          CallbackFunc;
} SafeWdgQspi_DataType;


/*******************************************************************************
**                        Exported object definitions                         **
*******************************************************************************/



/*******************************************************************************
**                        Local object definitions                            **
*******************************************************************************/

#define IFX_SWDG_START_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"


/* QSPI working data: */
static SafeWdgQspi_DataType             SafeWdgQspi_Data;


#define IFX_SWDG_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_SWDG_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                        Local function prototypes                           **
*******************************************************************************/

static Std_ReturnType SafeWdgQspi_lEnableQspiClock
(
  void
);
#ifdef SAFEWDGQSPI_DMAUSED
static void SafeWdgQspi_lDMAChRst_QspiRxFIFOClear
(
  void
);
#endif
/*******************************************************************************
**                         Function definitions                               **
*******************************************************************************/




/*******************************************************************************
** Traceability       : [cover parentID=]        [/cover]                      
**                                                                            
** Syntax            : SafeWdgIf_ResultType SafeWdgQspi_Init                     
**                        (const SafeWdgQspi_ChannelConfigType* const ConfigPtr)        
**                                                                            
** Service ID        : none                                                    
**                                                                            
** Sync/Async        : Synchronous                               
**                                                                            
** Reentrancy        : Non Re-entrant                                            
**                                                                           
** Parameters(in)    : ConfigPtr - Pointer to the QSPI configuration structure 
                        to use for initialization.                  
**                                                                            
** Parameters (out) : none                                                    
**                                                                            
** Return value      : SWDG_JOB_SUCCESS  - Initialization succeeded.             
**                     SWDG_JOB_FAILED - Initialization failed.   
**                                                                            
** Description      : Initializes the QSPI driver using a given configuration.
*******************************************************************************/
SafeWdgIf_ResultType  SafeWdgQspi_Init
(
  const SafeWdgQspi_ChannelConfigType* const ConfigPtr
)
{
  SafeWdgIf_ResultType  Result = SWDG_JOB_FAILED;
  uint32 tempSlsoActiveLevel   = 0U;
  uint32 tempQspiChannel       = 0U;
  uint32 tempSbcPos            = 0U;
  uint32 tempGlobalCon         = 0u;
  uint32 tempGlobcon_Enbit     = 0U;
  uint32 tempRcvInputSel       = 0U;
  uint32 tempSsoc              = 0U;
   uint32 tempChTimeQuantum    = 0U;
  uint32 tempBitSeg1           = 0U;
  uint32 tempBitSeg2           = 0U;
  uint32 tempBitSeg3           = 0U;
  uint32 tempClockPhase        = 0U;
  uint32 tempClockPol          = 0U;
  uint32 tempParityEn          = 0U;
  uint32 tempEcon              = 0U;
	uint32 tempActiveLevelPos    = 0U;
  uint32 tempShiftedSbcPos     = 0U;
  #ifdef SAFEWDGQSPI_DMAUSED
  uint32 TxSrc_Sre             = 0U;
  uint32 TxSrc_Tos             = 0U;
  uint32 TxSrc_Pri             = 0U;
  uint32 RxSrc_Sre             = 0U;
  uint32 RxSrc_Tos             = 0U;
  uint32 RxSrc_Pri             = 0U;
  uint32 TxSrcRegVal           = 0U;
  uint32 RxSrcRegVal           = 0U;
  #endif
  /* Check given configuration: */
  if (ConfigPtr != NULL_PTR)
  {
      /* Initialize internal data: */
      SafeWdgQspi_Data.CfgPtr      = ConfigPtr;
      SafeWdgQspi_Data.QspiModptr  = SafeWdgQspi_ModuleConfigRoot.QspiModule;
      SafeWdgQspi_Data.TxDmaChannel= SafeWdgQspi_ModuleConfigRoot.TxDmaChannel;
      SafeWdgQspi_Data.RxDmaChannel= SafeWdgQspi_ModuleConfigRoot.RxDmaChannel;
      SafeWdgQspi_Data.TxSrcReg    = SafeWdgQspi_ModuleConfigRoot.SrcTxRegister;
      SafeWdgQspi_Data.RxSrcReg    = SafeWdgQspi_ModuleConfigRoot.SrcRxRegister;
      SafeWdgQspi_Data.TxBufPtr    = NULL_PTR;
      SafeWdgQspi_Data.RxBufPtr    = NULL_PTR;
      SafeWdgQspi_Data.ErrorFlags  = 0U;
      SafeWdgQspi_Data.Count       = 0U;
      SafeWdgQspi_Data.DataCount     = 0U; 
      SafeWdgQspi_Data.Bacon       = 0U;
      SafeWdgQspi_Data.CallbackFunc= NULL_PTR;

      /* Enable QSPI module clock: */
      if (E_OK == SafeWdgQspi_lEnableQspiClock())
      {
        /* Setup QSPI: */
        /* -Input selection: */
        tempRcvInputSel = (uint32)SafeWdgQspi_ModuleConfigRoot.RcvInputSel;
        tempRcvInputSel =  tempRcvInputSel & SAFEWDGQSPI_PISELMRIS_MASK;
        SafeWdgQspi_Data.QspiModptr->PISEL.U     = (uint32) tempRcvInputSel;
        /* -Global configuration: */
        tempGlobalCon = (SAFEWDGQSPI_GLOBCON_TQMASK |SAFEWDGQSPI_GLOBCON_SRFBIT);
        tempGlobalCon &= (uint32)SafeWdgQspi_ModuleConfigRoot.ModTimeQuantum;
        SafeWdgQspi_Data.QspiModptr->GLOBALCON.U = tempGlobalCon;

        #ifdef SAFEWDGQSPI_DMAUSED
          SafeWdgQspi_Data.QspiModptr->GLOBALCON1.B.RXFIFOINT  = 0U;
          SafeWdgQspi_Data.QspiModptr->GLOBALCON1.B.TXFIFOINT  = 0U;
          SafeWdgQspi_Data.QspiModptr->GLOBALCON1.B.TXFM       = 1U;
          SafeWdgQspi_Data.QspiModptr->GLOBALCON1.B.RXFM       = 1U;
          SafeWdgQspi_Data.QspiModptr->GLOBALCON1.B.TXEN       = 1U;
          SafeWdgQspi_Data.QspiModptr->GLOBALCON1.B.RXEN       = 1U;
        #else
          SafeWdgQspi_Data.QspiModptr->GLOBALCON1.B.RXFIFOINT  = 0U;
          SafeWdgQspi_Data.QspiModptr->GLOBALCON1.B.TXFIFOINT  = 0U;  
          SafeWdgQspi_Data.QspiModptr->GLOBALCON1.B.TXFM       = 0U;
          SafeWdgQspi_Data.QspiModptr->GLOBALCON1.B.RXFM       = 0U; 
          SafeWdgQspi_Data.QspiModptr->GLOBALCON1.B.TXEN       = 0U; 
          SafeWdgQspi_Data.QspiModptr->GLOBALCON1.B.RXEN       = 1U; 
        #endif
        /* -Channel configuration: */
        tempChTimeQuantum = ((uint32)(ConfigPtr->ChTimeQuantum)  & SAFEWDGQSPI_ECON_QMASK );
        tempBitSeg1       = (( (uint32)(ConfigPtr->BitSeg1)   << SAFEWDGQSPI_ECON_APOS)     & SAFEWDGQSPI_ECON_AMASK) ;
        tempBitSeg2       = (( (uint32)(ConfigPtr->BitSeg2)   << SAFEWDGQSPI_ECON_BPOS)     & SAFEWDGQSPI_ECON_BMASK) ;
        tempBitSeg3       = (( (uint32)(ConfigPtr->BitSeg3)   << SAFEWDGQSPI_ECON_CPOS)     & SAFEWDGQSPI_ECON_CMASK) ;
        tempClockPhase    = (((uint32)(ConfigPtr->ClockPhase) << SAFEWDGQSPI_ECON_CPHPOS)   & SAFEWDGQSPI_ECON_CPHMASK);
        tempClockPol      =  (((uint32)(ConfigPtr->ClockPol)  << SAFEWDGQSPI_ECON_CPOLPOS)  & SAFEWDGQSPI_ECON_CPOLMASK);
        tempParityEn      =  (((uint32)(ConfigPtr->ParityEn)  << SAFEWDGQSPI_ECON_PARENPOS) & SAFEWDGQSPI_ECON_PARENMASK);
        tempEcon          = (tempChTimeQuantum | tempBitSeg1 | tempBitSeg2 |tempBitSeg3 | tempClockPhase | tempClockPol | tempParityEn);
        SafeWdgQspi_Data.QspiModptr->ECON[(ConfigPtr->Channel % 8U)].U =  tempEcon;

        /* -Slave select output configuration: */
        tempSlsoActiveLevel = ((uint32)ConfigPtr->SlsoActiveLevel & 1U);
        tempQspiChannel     = (uint32)(ConfigPtr->Channel);
        tempSbcPos          = (tempQspiChannel + SAFEWDGQSPI_SSOC_OENPOS);
        tempShiftedSbcPos   = (uint32)((uint32)1U << tempSbcPos);
        tempActiveLevelPos  = (uint32)(tempSlsoActiveLevel <<  tempQspiChannel);
        tempSsoc            = (uint32)(tempActiveLevelPos| tempShiftedSbcPos);
        SafeWdgQspi_Data.QspiModptr->SSOC.U = tempSsoc;


        /* -Pre-calculate BACON value: */
        SafeWdgQspi_Data.Bacon =
        SAFEWDGQSPI_BACON_LASTBIT     |
        ((((uint32)ConfigPtr->IdlePrescaler) << SAFEWDGQSPI_BACON_IPREPOS)  &
        SAFEWDGQSPI_BACON_IPREMASK)   |
        ((((uint32)ConfigPtr->IdleDelay) << SAFEWDGQSPI_BACON_IDLEPOS)      &
        SAFEWDGQSPI_BACON_IDLEMASK)   |
        ((((uint32)ConfigPtr->LeadPrescaler) << SAFEWDGQSPI_BACON_LPREPOS)  &
        SAFEWDGQSPI_BACON_LPREMASK)   |
        ((((uint32)ConfigPtr->LeadDelay) << SAFEWDGQSPI_BACON_LEADPOS)      &
        SAFEWDGQSPI_BACON_LEADMASK)   |
        ((((uint32)ConfigPtr->TrailPrescaler) << SAFEWDGQSPI_BACON_TPREPOS) &
        SAFEWDGQSPI_BACON_TPREMASK)   |
        ((((uint32)ConfigPtr->TrailDelay) << SAFEWDGQSPI_BACON_TRAILPOS)    &
        SAFEWDGQSPI_BACON_TRAILMASK)  |
        ((((uint32)ConfigPtr->ParityType) << SAFEWDGQSPI_BACON_PARTYPPOS)   &
        SAFEWDGQSPI_BACON_PARTYPMASK) |        
        ((((uint32)ConfigPtr->MsbFirst) << SAFEWDGQSPI_BACON_MSBPOS)        &
        SAFEWDGQSPI_BACON_MSBMASK)    |
        ((((uint32)ConfigPtr->DataLength) << SAFEWDGQSPI_BACON_DLPOS)       & 
        SAFEWDGQSPI_BACON_DLMASK)     |
        ((((uint32)ConfigPtr->Channel) << SAFEWDGQSPI_BACON_CSPOS) & SAFEWDGQSPI_BACON_CSMASK);
       
        /* Put QSPI0 module into RUN mode: */
        tempGlobalCon = SafeWdgQspi_Data.QspiModptr->GLOBALCON.U;
        tempGlobcon_Enbit = SAFEWDGQSPI_GLOBCON_ENBIT | tempGlobalCon;
        SafeWdgQspi_Data.QspiModptr->GLOBALCON.U = tempGlobcon_Enbit;       

        #ifdef SAFEWDGQSPI_DMAUSED
	  
           /*DMA init*/
           /*Tx Channel*/
           /*Channel width is set to 32 bit 
            One DMA transfer will move 1 move
            Channel mode to Single Mode operation
            Reset Request Only After Transaction not set
            Peripheral Request Select set to hardware request
            DMA priority set to high
            */
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].CHCFGR.B.CHDW    = 2U;        
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].CHCFGR.B.BLKM    = 0U;    
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].CHCFGR.B.CHMODE  = 0U;  
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].CHCFGR.B.RROAT   = 0U;   
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].CHCFGR.B.PRSEL   = 0U; 
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].CHCFGR.B.DMAPRIO = 3U;  
           /*
            Source Address Modification Factor set to 0
            Increment of Source Address set to addition of 1 offset
            Circular Buffer is disabled
            destination address is not changed
            Source address set to the drivers Tx buffer
            Destination address set to TxFIFO of selected Qspi module
           */
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].ADICR.B.SMF    = 0U;  
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].ADICR.B.INCS   = 1U; 
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].ADICR.B.CBLS   = 0U; 
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].ADICR.B.SCBE   = 0U; 
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].ADICR.B.DMF    = 0U;  
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].ADICR.B.INCD   = 0U; 
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].ADICR.B.CBLD   = 0U; 
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].ADICR.B.DCBE   = 1U; 
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].ADICR.B.INTCT  = 2U;
           MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].ADICR.B.IRDV   = 0U;            
           /*Rx Channel*/
           /*Channel width is set to 32 bit 
            One DMA transfer will move 1 move
            Channel mode to Single Mode operation
            Reset Request Only After Transaction not set
            Peripheral Request Select set to hardware request
            DMA priority set to high
           */
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].CHCFGR.B.CHDW    = 2U;  
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].CHCFGR.B.BLKM    = 0U;  
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].CHCFGR.B.CHMODE  = 0U;
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].CHCFGR.B.RROAT   = 0U; 
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].CHCFGR.B.PRSEL   = 0U; 
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].CHCFGR.B.DMAPRIO = 3U;
           /*
            Destination Address Modification Factor set to 0
            Increment of destination Address set to addition of 1 offset
            Circular Buffer is disabled
            Source address is not changed
            Source address set to the drivers RxFIFO of selected Qspi modulebuffer
            Destination address set to Rx buffer of the driver.
           */
           
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].ADICR.B.DMF     = 0U;  
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].ADICR.B.INCD    = 1U;
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].ADICR.B.CBLD    = 0U;
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].ADICR.B.DCBE    = 0U;
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].ADICR.B.SMF     = 0U; 
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].ADICR.B.INCS    = 0U;
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].ADICR.B.CBLS    = 0U;
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].ADICR.B.SCBE    = 1U;
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].ADICR.B.INTCT   = 2U; 
           MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].ADICR.B.IRDV    = 0U; 
                                           
           /*Set up Qspi interrupt for DMA channels*/
           /*Enable service request , set type of service to DMA and set the
             priority to the DMA Channel used.*/
           TxSrc_Sre    = (uint32)((uint32)1U << SAFEWDGQSPI_SRC_SRE_POS);
           TxSrc_Tos    = (uint32)((uint32)SAFEWDGQSPI_DMA_SER << SAFEWDGQSPI_SRC_TOS_POS);             
           TxSrc_Pri    =  (uint32)SafeWdgQspi_Data.TxDmaChannel;  
           TxSrcRegVal  =  (TxSrc_Sre | TxSrc_Tos | TxSrc_Pri);
           SafeWdgQspi_Data.TxSrcReg->U = (uint32)TxSrcRegVal;

          
           RxSrc_Sre    = (uint32)((uint32)1U << SAFEWDGQSPI_SRC_SRE_POS);
           RxSrc_Tos    = (uint32)((uint32)SAFEWDGQSPI_DMA_SER << SAFEWDGQSPI_SRC_TOS_POS);             
           RxSrc_Pri    =  (uint32)SafeWdgQspi_Data.RxDmaChannel;             
           RxSrcRegVal  =  (RxSrc_Sre | RxSrc_Tos | RxSrc_Pri);
           SafeWdgQspi_Data.RxSrcReg->U = (uint32)RxSrcRegVal;

           #endif
           Result = SWDG_JOB_SUCCESS;
      } /* if (E_OK == SafeWdgQspi_lEnableQspiClock()) */
  } /* if (ConfigPtr != NULL_PTR) */
  return Result;
} /* SafeWdgQspi_Init */

/*******************************************************************************
** Traceability       : [cover parentID=]        [/cover]                      
**                                                                            
** Syntax            : void SafeWdgQspi_DeInit(void)                            
**                                                                            
** Service ID        : none                                                    
**                                                                            
** Sync/Async        : Synchronous                                              
**                                                                            
** Reentrancy        : Non Reentrant                                            
**                                                                            
** Parameters(in)    : none                                                    
**                                                                            
** Parameters (out) : none                                                    
**                                                                            
**                                                                            
** Description      : De-initializes the QSPI driver and resets QSPI module  
**                    configuration                                           
**                                                                         
*******************************************************************************/
void SafeWdgQspi_DeInit
(
  void
)
{
  volatile uint32  Dummy;
  
  volatile Ifx_QSPI*  QspiModPtr                  = SafeWdgQspi_Data.QspiModptr;
  const SafeWdgQspi_ChannelConfigType* ConfigPtr  = SafeWdgQspi_Data.CfgPtr;
  volatile Ifx_SRC_SRCR* TxSrcReg                 = SafeWdgQspi_Data.TxSrcReg;
  volatile Ifx_SRC_SRCR* RxSrcReg                 = SafeWdgQspi_Data.RxSrcReg;

  /* Reset QSPI module configuration: */
  SafeWdgQspi_Data.QspiModptr->PISEL.U            = SAFEWDGQSPI_PISEL_RESVAL;
  SafeWdgQspi_Data.QspiModptr->GLOBALCON.U        = SAFEWDGQSPI_GLOBCON_RESVAL;
  SafeWdgQspi_Data.QspiModptr->GLOBALCON1.U       = SAFEWDGQSPI_GLOBCON1_RESVAL;
  SafeWdgQspi_Data.QspiModptr->ECON[ConfigPtr->Channel % 8U].U
                                                  = SAFEWDGQSPI_ECON_RESVAL;
  SafeWdgQspi_Data.QspiModptr->SSOC.U             = SAFEWDGQSPI_SSOC_RESVAL;
  SafeWdgQspi_Data.DataCount                      = 0U;
  SafeWdgQspi_Data.Count                          = 0U;
  /* Disable module clock: */
  Mcal_ResetENDINIT();
  
  QspiModPtr->CLC.B.DISR = 1U;
  Dummy = QspiModPtr->CLC.U;    /* Read back */
  Mcal_SetENDINIT();
  /*To avoid compiler warning in gnu.*/
  Dummy = Dummy;
  
  /* Disable interrupts: */
  TxSrcReg->U = 0U;
  RxSrcReg->U = 0U;
  
  /*If DMA is configured, disable DMA channels too*/
  #ifdef SAFEWDGQSPI_DMAUSED
  /*Tx Channel*/
  /*disable DMA channel hardware requests and reset DMA channel to make it de initialized. */
  
  
  
  MODULE_DMA.TSR[SafeWdgQspi_Data.TxDmaChannel].U = (unsigned_int)((MODULE_DMA.TSR[SafeWdgQspi_Data.TxDmaChannel].U & SAFEWDGQSPI_DMA_TSR_MASK) | (((uint32)1U << SAFEWDGQSPI_DMA_TSR_DCH_POS) | ((uint32)1U << SAFEWDGQSPI_DMA_TSR_RST_POS)));  
  MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].SADR.U   = 0U;
  MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].DADR.U   = 0U;
  MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].ADICR.U  = 0U;
  MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].CHCFGR.U = 0U;
 
  /*Rx Channel*/
  MODULE_DMA.TSR[SafeWdgQspi_Data.RxDmaChannel].U = (unsigned_int)((MODULE_DMA.TSR[SafeWdgQspi_Data.RxDmaChannel].U & SAFEWDGQSPI_DMA_TSR_MASK) | (((uint32)1U << SAFEWDGQSPI_DMA_TSR_DCH_POS) | ((uint32)1U << SAFEWDGQSPI_DMA_TSR_RST_POS)));
  MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].SADR.U   = 0U;
  MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].DADR.U   = 0U;
  MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].ADICR.U  = 0U;
  MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].CHCFGR.U = 0U;
  #endif
  
} /* SafeWdgQspi_DeInit */

/*******************************************************************************
** Traceability       : [cover parentID=]        [/cover]                      
**                                                                            
** Syntax            : void  SafeWdgQspi_TxRx (uint32* TxBuf,uint32* RxBuf, 
                                                uint8 Count)                                    
**                                                                           
** Service ID        : none                                           
**                                                                           
** Sync/Async        : ASynchronous                           
**                                                                           
** Reentrancy        : Non Reentrant                             
**                                                                           
** Parameters(in)    : TxBuf - TX data to be sent                              
**                     Count - Number of data words to transfer                
**                                                                            
** Parameters (out) :  RxBuf - Gets filled with the RX data                    
**                                                                            
**                                                                            
** Description      : Transfers a given number of data words over SPI. Once the 
                      transfer is started control is immediately   returned to 
                      the caller. SafeWdgQspi_RxDone() has to    
**                    be used to poll the status of the data transfer.        
**                                        
**                    Note: Asynchronous data transfer must only be used if    
**                    interrupts /DMA channels are enabled.                     
**                                                                            
*******************************************************************************/
void SafeWdgQspi_TxRx 
(
  uint32* TxBuf,
  uint32* RxBuf,
  uint8 Count
)
{
  /*Init data structure required for Async communication*/
  SafeWdgQspi_Data.TxBufPtr   = TxBuf;
  SafeWdgQspi_Data.RxBufPtr   = RxBuf;
  SafeWdgQspi_Data.ErrorFlags = 0U;
  SafeWdgQspi_Data.DataCount  = 0U;
  SafeWdgQspi_Data.Count      = Count;

  /* Restore the BACON value. BACON might have been changed by _CustTxRx API*/
  SafeWdgQspi_Data.QspiModptr->BACONENTRY.U = SafeWdgQspi_Data.Bacon;
  
  /*This API will be called only by TLF driver and it doenn't rely on callback*/
  SafeWdgQspi_Data.CallbackFunc = NULL_PTR;

  /* Clear QSPI error flags: */
  SafeWdgQspi_Data.QspiModptr->FLAGSCLEAR.U = SAFEWDGQSPI_FLGCL_ERRMASK;
  
  #ifdef SAFEWDGQSPI_DMAUSED
  /* This function Resets the DMA Tx and Rx channels and
                      clears the QSPi Rx FIFO */
  SafeWdgQspi_lDMAChRst_QspiRxFIFOClear();  
  /*Set source ,destination address and transfer count of Tx DMA channel*/
  MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].SADR.U        = 
                                           (uint32) SafeWdgQspi_Data.TxBufPtr;
  MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].DADR.U         = 
                   (uint32) & (SafeWdgQspi_Data.QspiModptr->MIXENTRY.U);
  
  MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].CHCFGR.B.TREL = Count;
  
  /*Set source ,destination address and transfer count of Rx DMA channel*/
  MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].SADR.U = 
                       (uint32) & (SafeWdgQspi_Data.QspiModptr->RXEXIT.U);
  MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].DADR.U        = 
                                           (uint32) SafeWdgQspi_Data.RxBufPtr;
  MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].CHCFGR.B.TREL = Count;
  /* Start transmission: */
  MODULE_DMA.TSR[SafeWdgQspi_Data.TxDmaChannel].U = (unsigned_int)((MODULE_DMA.TSR[SafeWdgQspi_Data.TxDmaChannel].U & SAFEWDGQSPI_DMA_TSR_MASK) | ((uint32)1U << SAFEWDGQSPI_DMA_TSR_ECH_POS));

  MODULE_DMA.TSR[SafeWdgQspi_Data.RxDmaChannel].U = (unsigned_int)((MODULE_DMA.TSR[SafeWdgQspi_Data.RxDmaChannel].U & SAFEWDGQSPI_DMA_TSR_MASK) | ((uint32)1U << SAFEWDGQSPI_DMA_TSR_ECH_POS));    
 
  SafeWdgQspi_Data.TxSrcReg->B.SETR = 1U;
    
  #else
  /* Start transmission:Push first data to Tx FIFO */ 
  SafeWdgQspi_Data.QspiModptr->DATAENTRY[0].U =
                            SafeWdgQspi_Data.TxBufPtr[0];
  #endif
} /* SafeWdgQspi_TxRx */

/*******************************************************************************
** Traceability       : [cover parentID=]        [/cover]                      
**                                                                            
** Syntax            : SafeWdgIf_ResultType SafeWdgQspi_CustomerTxRx            
**                       (uint32* TxBuf,  uint32* RxBuf, const uint8 Count, 
                          uint32 BaconRegisterValue  )                          
**                                                                            
** Service ID        : none                                                    
**                                                                           
** Sync/Async        : ASynchronous                                      
**                                                                           
** Reentrancy        : Non Reentrant                                      
**                                                                           
** Parameters(in)    : TxBuf - TX data to be sent                              
**                     Count - Number of data words to transfer                
**                     BACONRegisterValue - Basic configuration register value .
                    This register should contain basic configuration  parameters
                    for the slave select signal used by the   customer module
**                                                                            
** Parameters (out) : RxBuf - Gets filled with the RX data                    
**                                                                            
**                                                                            
** Description      : Transfers a given number of data words over SPI.Once the 
                      transfer is started,control is immediately returned to 
                      the caller. Callback function will be called
**                    from RxISR.From the callback ,SafeWdgQspi_RxDone() has  
**                    to be used to poll the status of the data transfer.     
**                                        
**                    Note: Asynchronous data transfer must only be used if    
**                    interrupts / DMA channels are enabled.                                  
**                                                                            
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgQspi_CustTxRx
(
  uint32* TxBuf,
  uint32* RxBuf,
  uint8 Count,
  uint32 BACONRegisterValue
 )
{
  SafeWdgIf_ResultType  Result  = SWDG_JOB_FAILED;
  /*Get Chip select of customer peripheral and TLF35584*/
  uint32 ChipSelectOfCust  = BACONRegisterValue & SAFEWDGQSPI_BACON_CSMASK;
  uint32 ChipSelectOfTLF   = SafeWdgQspi_Data.Bacon & SAFEWDGQSPI_BACON_CSMASK;
  
  /*Accept the request only if customer peripheral is connected to a different
    chip select signal*/
  if(ChipSelectOfCust != ChipSelectOfTLF)
  {
    /* application should ensure that usage of this API for SPI communication with 
     some other device does not affect timing requirement for communication with 
     TLF Watchodg */

     /* Push user specific configuration into TX FIFO: */
    SafeWdgQspi_Data.QspiModptr->BACONENTRY.U = BACONRegisterValue;
    
    /* Clear QSPI error flags: */
    SafeWdgQspi_Data.QspiModptr->FLAGSCLEAR.U = SAFEWDGQSPI_FLGCL_ERRMASK;

    /* Start asynchronous transmission  */
    SafeWdgQspi_Data.TxBufPtr                 = TxBuf;
    SafeWdgQspi_Data.RxBufPtr                 = RxBuf;
    SafeWdgQspi_Data.ErrorFlags               = 0U;
    SafeWdgQspi_Data.DataCount                = 0U;
    SafeWdgQspi_Data.Count                    = Count;

    /* Check DMA/Interrupt mode selection */
    #ifdef SAFEWDGQSPI_DMAUSED
    /* Start transmission: */
    
    /*Set source ,destination address and transfer count of Tx DMA channel*/
    MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].SADR.U        = 
                                             (uint32) SafeWdgQspi_Data.TxBufPtr;
    MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].DADR.U         = 
                     (uint32) & (SafeWdgQspi_Data.QspiModptr->MIXENTRY.U);
    
    MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].CHCFGR.B.TREL = Count;
    
    /*Set source ,destination address and transfer count of Rx DMA channel*/
    MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].SADR.U = 
                         (uint32) & (SafeWdgQspi_Data.QspiModptr->RXEXIT.U);
    MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].DADR.U        = 
                                             (uint32) SafeWdgQspi_Data.RxBufPtr;
    MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].CHCFGR.B.TREL = Count;
    /* Start transmission: */
    MODULE_DMA.TSR[SafeWdgQspi_Data.TxDmaChannel].U = (unsigned_int)((MODULE_DMA.TSR[SafeWdgQspi_Data.TxDmaChannel].U & SAFEWDGQSPI_DMA_TSR_MASK) | ((uint32)1U << SAFEWDGQSPI_DMA_TSR_ECH_POS));
    MODULE_DMA.TSR[SafeWdgQspi_Data.RxDmaChannel].U = (unsigned_int)((MODULE_DMA.TSR[SafeWdgQspi_Data.RxDmaChannel].U & SAFEWDGQSPI_DMA_TSR_MASK) | ((uint32)1U << SAFEWDGQSPI_DMA_TSR_ECH_POS));    
    SafeWdgQspi_Data.TxSrcReg->B.SETR = 1U;
    #else
    /*This API will be called only by application software and it relies on
    callback only when ISR is used. When DMA is used, this callback function
    will not be used*/
    SafeWdgQspi_Data.CallbackFunc = SafeWdgQspi_ModuleConfigRoot.UserFunc;
    /* Start transmission:Push first data to Tx FIFO */ 
    SafeWdgQspi_Data.QspiModptr->DATAENTRY[0].U =
                            SafeWdgQspi_Data.TxBufPtr[0];
    #endif
    Result = SWDG_JOB_ACCEPTED; 
  }
  return Result;
}

/*******************************************************************************
** Traceability      : [cover parentID=]          [/cover]                        
**                                                                            
** Syntax            : boolean SafeWdgQspi_RxDone(uint32* Error)                        
**                                                                            
** Service ID        : none                                           
**                                                                            
** Sync/Async        : Synchronous                               
**                                                                            
** Reentrancy        : Non Reentrant                              
**                                                                            
** Parameters(in)    : None                                         
**                                                                            
** Parameters (out) : Error - Receives the error flags according to      
**                                 QSPIx_STATUS.ERRORFLAGS bit field            
**                                                                            
** Return value      : FALSE - Asynchronous transmission did not yet complete    
**                         or no asynchronous transmission was started      
**                     TRUE - Asynchronous transmission completed          
**
** Description      : Checks whether a previously started asynchronous   
                      transmission has already completed and the SPI response is
                      available. In case of a complete  transmission ,
                      transmission status is reset and subsequent calls to 
**                    SafeWdgQspi_RxDone will return FALSE unless a new 
**                    transmission is started.
*******************************************************************************/
boolean SafeWdgQspi_RxDone(uint32* Error)
{
    boolean Result = FALSE;

    #ifdef SAFEWDGQSPI_DMAUSED
    /*Read error information*/
    *Error = SafeWdgQspi_Data.QspiModptr->STATUS.U & SAFEWDGQSPI_STAT_ERRFLGMASK;
    #else
    /*ErrorFlags value will be updated in RxISR*/
    *Error = SafeWdgQspi_Data.ErrorFlags;
    #endif
    
   /*Check if any error bits are set*/
   if(*Error == 0u)
   {
      /* No Error */
      #ifdef SAFEWDGQSPI_DMAUSED   
      /* Check the transfer count of DMA channels to know if transfer is 
         complete */
      if(MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].CHCSR.B.ICH == 1U) 
      {
        if(MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].CHCSR.B.ICH == 1U) 
        {
          /*Clear ICH Bit for Tx and Rx channels*/
          MODULE_DMA.CH[SafeWdgQspi_Data.TxDmaChannel].CHCSR.B.CICH = 1U;
          MODULE_DMA.CH[SafeWdgQspi_Data.RxDmaChannel].CHCSR.B.CICH = 1U;
          SafeWdgQspi_Data.DataCount = 0U;
          Result = TRUE;
        }
      }
      #else
      /*Check if transfer is complete */
      if(SafeWdgQspi_Data.DataCount == SafeWdgQspi_Data.Count)
      {
         /* Reset count */
        SafeWdgQspi_Data.DataCount = 0U;
        /* Transfer is complete */
         Result = TRUE;
      }
      #endif
   }  
   else
   {
      /* Error found       
         Cancel pending asynchronous data transfer. SPI communication error
         has occurred or a data transfer timed out. */
      SafeWdgQspi_Data.Count = 0U;
      Result = FALSE;
   }         
   
   return Result;
} /* SafeWdgQspi_RxDone */
#ifndef SAFEWDGQSPI_DMAUSED
/*******************************************************************************
** Traceability      : [cover parentID=]         [/cover]     
**                                                                           
** Syntax            : void SafeWdgQspi_ISRTxRx(void)       
**                                                                           
** Service ID        : none                                           
**                                                                           
** Sync/Async        : Synchronous                              
**                                                                           
** Reentrancy        : Non Reentrant                             
**                                                                           
** Parameters(in)    : None                                        
**                                                                           
** Parameters (out) : None                                       
**                                                                           
** Return value      : None                                          
**                                                                           
** Description      : This function is ISR handler for Rx Interrupt.It empties
                      the RxFIFO and moves the next data (if present) into 
                      TxFIFO.                      
*******************************************************************************/

void SafeWdgQspi_IsrTxRx(void)
{

  volatile Ifx_QSPI* QspiModPtr = SafeWdgQspi_Data.QspiModptr;
  volatile Ifx_SRC_SRCR* RxSrcReg = SafeWdgQspi_Data.RxSrcReg;
  SafeWdgQspi_UserCallbackFuncType CallbackFunction;
  
  /*Check if Rx interrupt has occured.*/
  if (QspiModPtr->STATUS.B.RXF == 1u)
  {
    /*Clear Rx interrupt request bit*/
    RxSrcReg->B.CLRR               = 1U;
  
    /* Clear RX FIFO event: */
    QspiModPtr->FLAGSCLEAR.U       = SAFEWDGQSPI_FLGCL_RXCBIT;
    SafeWdgQspi_Data.RxBufPtr[SafeWdgQspi_Data.DataCount] = 
                                                           QspiModPtr->RXEXIT.U;
          
    SafeWdgQspi_Data.DataCount++;
    
    if(SafeWdgQspi_Data.DataCount < SafeWdgQspi_Data.Count)
    {
        QspiModPtr->DATAENTRY[0].U = 
                            SafeWdgQspi_Data.TxBufPtr[SafeWdgQspi_Data.DataCount];
    }
    /* Update error flags */
    SafeWdgQspi_Data.ErrorFlags   |= 
                             QspiModPtr->STATUS.U & SAFEWDGQSPI_STAT_ERRFLGMASK;
    /*Check if callback function is present. If present, it means that this
      ISR has occurred because of a _CustTxRx API and callback has to be called*/
    if(SafeWdgQspi_Data.CallbackFunc != NULL_PTR)
    {
      /*Call the callback function, if transfer is complete
        or any error has occurred*/
      if(   (SafeWdgQspi_Data.DataCount == SafeWdgQspi_Data.Count)
          || (SafeWdgQspi_Data.ErrorFlags != 0U) 
         )
      {
        /*notify application software that _CustTxRx API is processed.*/
        CallbackFunction = SafeWdgQspi_Data.CallbackFunc;
        CallbackFunction(); 
        /*_CustTxRx is processed. Set the callback to NULL, so that
           it doesn't get called when _TxRx API is processed.*/
        SafeWdgQspi_Data.CallbackFunc = NULL_PTR;
      }
      
    }
  }
}
#endif
/*******************************************************************************
** Traceability      : [cover parentID=]         [/cover]                        
**                                                                            
** Syntax            : Std_ReturnType SafeWdgQspi_lEnableQspiClock(void)        
**                                                                          
** Service ID        : none                                          
**                                                                          
** Sync/Async        : Synchronous                             
**                                                                          
** Reentrancy        : Non Reentrant                            
**                                                                          
** Parameters(in)    : None                                       
**                                                                          
** Parameters (out) : None                                      
**                                                                          
** Return value      : E_OK - QSPI clock enable succeeded                
**                     E_NOT_OK - QSPI clock enable timed out                 
**
** Description      : This function enables clock gating to the QSPI module.  
**                                                                            
*******************************************************************************/
static Std_ReturnType SafeWdgQspi_lEnableQspiClock(void)
{
  Std_ReturnType  Result = E_NOT_OK;
  uint32          Clc;
  uint32          tempClcDisrBit = 0U;
  uint32 tempCLC= 0U;
  boolean LoopBreakFlag = FALSE;
  uint32 Index;

  /* QSPI clock is disabled? */
  if ((SafeWdgQspi_Data.QspiModptr->CLC.U & SAFEWDGQSPI_CLCDISSBIT) > 0U)
  {
    tempClcDisrBit = (uint32)(~SAFEWDGQSPI_CLCDISRBIT);
    /* Enable QSPI clock: */
    Mcal_ResetENDINIT(); 
    tempCLC = SafeWdgQspi_Data.QspiModptr->CLC.U;
    tempCLC = tempCLC & tempClcDisrBit;
    SafeWdgQspi_Data.QspiModptr->CLC.U = (uint32)tempCLC;
    Mcal_SetENDINIT();

    /* Wait for clock enable to become reflected by status bit: */
    for(Index = 0u; ((Index < SAFEWDGQSPI_CLK_ENTIMEOUT) && (LoopBreakFlag == FALSE) ); Index++)
    {
      Clc = SafeWdgQspi_Data.QspiModptr->CLC.U & SAFEWDGQSPI_CLCDISSBIT;
      if(Clc == 0U)
      {
        LoopBreakFlag = TRUE;
      }
    }
    /* QSPI clock is enabled? */
    if ((SafeWdgQspi_Data.QspiModptr->CLC.U & SAFEWDGQSPI_CLCDISSBIT) == 0U)
    {
      Result = E_OK;
    }
    
  } 
  else
  {
      Result = E_OK;
  } 
  return Result;
} 

/*******************************************************************************
** Traceability      : [cover parentID=]         [/cover]                        
**                                                                            
** Syntax            : static void SafeWdgQspi_lDMAChRst_QspiRxFIFOClear( void )        
**                                                                          
** Service ID        : none                                          
**                                                                          
** Sync/Async        : Synchronous                             
**                                                                          
** Reentrancy        : Non Reentrant                            
**                                                                          
** Parameters(in)    : None                                       
**                                                                          
** Parameters (out) : None                                      
**                                                                          
** Return value      : None               
**
** Description      : This function Reset the DMA Tx and Rx channels and
                      clears the QSPi Rx FIFO 
**                                                                            
*******************************************************************************/
#ifdef SAFEWDGQSPI_DMAUSED
static void SafeWdgQspi_lDMAChRst_QspiRxFIFOClear( void )
{
  uint32 RstTimeout = 0U;
  uint8 Loop_Count =0U;
  static uint8 Fifo_Level = 0U;
  uint32 Dummy_FIFORead =0U;
  
  /* disable the DMA Tx channel hardware requests by setting TSRz.DCH = 1 */
  MODULE_DMA.TSR[SafeWdgQspi_Data.TxDmaChannel].U = (unsigned_int)((MODULE_DMA.TSR[SafeWdgQspi_Data.TxDmaChannel].U & SAFEWDGQSPI_DMA_TSR_MASK) | ((uint32)1U << SAFEWDGQSPI_DMA_TSR_DCH_POS));
  /* Resetting of Tx channel by Writing a 1 to TSRz.RST */
  MODULE_DMA.TSR[SafeWdgQspi_Data.TxDmaChannel].U = (unsigned_int)((MODULE_DMA.TSR[SafeWdgQspi_Data.TxDmaChannel].U & SAFEWDGQSPI_DMA_TSR_MASK) | ((uint32)1U << SAFEWDGQSPI_DMA_TSR_RST_POS));
  /* Waiting until TSRz.RST = 0 with time-out to indicate reset has completed. */ 
  do
  {
    RstTimeout++; /* Time out condition for channel reset*/
  }while ((MODULE_DMA.TSR[SafeWdgQspi_Data.TxDmaChannel].B.RST != 0U) && (RstTimeout < SAFEWDGQSPI_DMA_TSR_RST_TIMEOUT));

  RstTimeout = 0U;
  /* disable the DMA Tx channel hardware requests by setting TSRz.DCH = 1 */
  MODULE_DMA.TSR[SafeWdgQspi_Data.RxDmaChannel].U = (unsigned_int)((MODULE_DMA.TSR[SafeWdgQspi_Data.RxDmaChannel].U & SAFEWDGQSPI_DMA_TSR_MASK) | ((uint32)1U << SAFEWDGQSPI_DMA_TSR_DCH_POS));
  /* Resetting of Tx channel by Writing a 1 to TSRz.RST */
  MODULE_DMA.TSR[SafeWdgQspi_Data.RxDmaChannel].U = (unsigned_int)((MODULE_DMA.TSR[SafeWdgQspi_Data.RxDmaChannel].U & SAFEWDGQSPI_DMA_TSR_MASK) | ((uint32)1U << SAFEWDGQSPI_DMA_TSR_RST_POS));
  /* Waiting until TSRz.RST = 0 with time-out to indicate reset has completed. */ 
  do
  {
    RstTimeout++; /* Time out condition for channel reset*/
  }while ((MODULE_DMA.TSR[SafeWdgQspi_Data.RxDmaChannel].B.RST != 0U) && (RstTimeout < SAFEWDGQSPI_DMA_TSR_RST_TIMEOUT));
  
  /* QSPI RxFIFO needs to be flushed by reading into the dummy variable */
  Fifo_Level = SafeWdgQspi_Data.QspiModptr->STATUS.B.RXFIFOLEVEL;
  for (Loop_Count =0U; Loop_Count < Fifo_Level; Loop_Count++)
  {
    Dummy_FIFORead = SafeWdgQspi_Data.QspiModptr->RXEXIT.U;
  }
  UNUSED_PARAMETER(Dummy_FIFORead)
}
#endif
#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
