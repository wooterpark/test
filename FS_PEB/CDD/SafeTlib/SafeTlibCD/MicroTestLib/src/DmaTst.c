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
**   $FILENAME   : DmaTst.c $                                                 **
**                                                                            **
**   $CC VERSION : \main\52 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file provides latent fault metric test routines for   **
**                 the DMA Test.                                              **
**                                                                            **
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_DMA_Test, v1.1                        **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h" 
#include "DmaTst.h"
#include "Sl_Ipc.h"
#include "IfxDma_reg.h"
#include "IfxSrc_reg.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

#define ADDRESS_OFFSET                           (0x00000020U)
/* Timeout for enabling the DMA clock. As there is no information available
 * about how much time is required to enable the DMA clock, this value was
 * arbitrarily chosen to a relatively high value:
 */
#define DMA_ENABLE_TIMEOUT                       (0x100U)
/*timeout value is kept sufficient for timestamp to rollover and restart from 0*/
#define DMA_TIMESTAMP_WAITTIMEOUT                (0x100U)
/*11us is required transfer to complete,this value is chosen to a 
    relatively high value*/
#define DMA_TRANSFER_WAITTIMEOUT                 (0x100U)
#define DMA_CH_CHCFGR_BLK_MOVE                   (0x004A0001U)
#define DMA_CHCFGR_SINGLE_MOVE                   (0x00400001U)
#define DMA_CH_ADICR                             (0x00000088U)
#define START_DMA_TX                             (0x80000000U)
#define DMA_ADD_TIMESTAMP                        (0x00400080U)
#define DMA_SAFELINKEDLIST_MODE                  (0x000E0088U)
#define DMA_MIN_TIMESTAMP                        (0xFFFFFE0BU)
#define DMA_LLCOUNT                              (3U)
#define SRC_DMAERR_CLRR_MASK                     ((unsigned_int)0x02000000U)
#define SRC_DMAERR_CLR_RESERVED_BIT              ((unsigned_int)0x7FFFFFFFU)
/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/*******************************************************************************
**                        Exported object definitions                         **
*******************************************************************************/

/*******************************************************************************
**                        Local object definitions                            **
*******************************************************************************/
#define IFX_DMATST_START_SEC_VAR_32BYTEALIGN_ASIL_B
#include "Ifx_MemMap.h"

/* 32 byte alignment mandatory for following structure for 
safe linked list test*/

static TransactionSetType DmaTst_transactionSet[DMA_LLCOUNT]; 
 
#define IFX_DMATST_STOP_SEC_VAR_32BYTEALIGN_ASIL_B
#include "Ifx_MemMap.h" 

#define IFX_DMATST_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

static  volatile uint32      DmaTst_DestAddress1[2];
static  volatile uint32      DmaTst_DestAddress2[2];

#define IFX_DMATST_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                        Imported function declarations                      **
*******************************************************************************/
#define IFX_DMATST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                        Local function prototypes                           **
*******************************************************************************/

static void DmaTst_lInit ( DmaTst_BackupDataType* const DmaTst_BackupData, 
                           Sl_ParamSetType  ParamSetIndex);
static void DmaTst_lRestore (const DmaTst_BackupDataType* DmaTst_BackupData, 
                             Sl_ParamSetType  ParamSetIndex);
static Sl_TstRsltType DmaTst_lGetTimeStamps(const Sl_ParamSetType ParamSetIndex,
                      uint32* TimeStamp_ME0, uint32* TimeStamp_ME1);

/*******************************************************************************
**                    Local inline function definitions                        *
*******************************************************************************/

/*******************************************************************************
**                    Configuration error checking                             *
*******************************************************************************/

/*******************************************************************************
**                         Function definitions                                *
*******************************************************************************/



/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType DmaTst_CRCTst                                      **
**          (                                                                 **
**             const  Sl_ParamSetIndex ParamSetIndex,                         **
**             const  uint8 TstSeed,                                          **
**             uint32* const TstSignature                                     **
**          )                                                                 **
**                                                                            **
** Description : This Test reads the value of Source and Destination          **
**Address checksum and received data checksum from The DMA                    **
**channel SDCRC and RDCRC registers and compares it to                        **
**calculated/expected checksum. If checksum matches, then                     **
**the test is PASS if it does not match, then the test is FAIL.               **
**The test reports SDCRC and RDCRC failures. To ensure                        **
**that both Move engines get tested, parallel DMA transaction                 **
**is initiated on 2 DMA channels so that both move engines get used           **
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
**                                                                            **
**ParamSetIndex -Identifies the parameter set to be used for test execution   **
**TstSeed - Seed to be used for generating the signature                      **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
** Return value :                                                             **
**DMA_SUCCESS    Test succeeded                                               **
**DMA_INVPARAMERR  Test failed because an invalid parameter was supplied      **
**DMA_RESOURCE_TIMEOUT_ERROR  DMA resource timeout                            **
**DMA_SDCRC_FAIL_MEx  SDCRC did not match with expected CRC for Move Enginex  **
**DMA_RDCRC_FAIL_MEx  RDCRC did not match with expected CRC for Move Enginex  **
*******************************************************************************/
Sl_TstRsltType DmaTst_CRCTst
  (
  
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,  
  uint32* const TstSignature
  ) 
{
  Sl_TstRsltType          Result = DMA_CRC_TEST_NOTEXECUTED;
  uint32                  CalculatedSDCRC_ch1 = 0U;
  uint32                  CalculatedSDCRC_ch2 =  0U; 
  uint32                  CalculatedRxDataCRC_ch1 = 0U;
  uint32                  CalculatedRxDataCRC_ch2 = 0U;
  DmaTst_BackupDataType   DmaTst_BackupData = \
                    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
  uint8                   Count;
  /* the values at source and destination addresses is arbitrarily chosen. 
  The contents do not matter */
  static uint32                  SourceAddress1[4] = {10U,20U,30U,40U};
  static uint32                  DestAddress1[4] = {0U,0U,0U,0U};
  static uint32                  SourceAddress2[4] = {1U,2U,3U,4U};
  static uint32                  DestAddress2[4] = {0U,0U,0U,0U};
  uint32                  Sdcrc_me0;
  uint32                  Sdcrc_me1;
  uint32                  Rdcrc_me0;
  uint32                  Rdcrc_me1;  
  uint32                  DmaICH1 = 0U; 
  uint32                  DmaICH2 = 0U;
  uint32                  Timeout = DMA_TRANSFER_WAITTIMEOUT;
  
  /* Initialize Test Signature:   */
  *TstSignature =  (uint32)CRC32((uint32)TEST_ID_DMA_CRC_TST,(uint32)TstSeed );

  if(
    (ParamSetIndex < DMATST_CFG_PARAM_COUNT)&&
    (DmaTstConfigSet[ParamSetIndex].DmaChTx1 < DMA_CHANNELS)&&
    (DmaTstConfigSet[ParamSetIndex].DmaChTx2 < DMA_CHANNELS)
    )
  {
    if(E_OK == Sl_GetSpinLock(SL_DMA_SPNLCK_ID, SL_DMA_TIMEOUT)) 
    {
        /*Backup Registers that will be modified*/
        DmaTst_lInit(&DmaTst_BackupData, ParamSetIndex);
 
        if(DMA_CLC.B.DISS == 0U)
        {

          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].CHCFGR.U = 
                                                         DMA_CH_CHCFGR_BLK_MOVE;                                                      
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].ADICR.U = 
                                                                   DMA_CH_ADICR;
                                                                   
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].SADR.U = 
                                                         (uint32)SourceAddress1;
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].DADR.U = 
                                                           (uint32)DestAddress1;
                                                           
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].SDCRCR.U = 
                                                                     (uint32)0U;
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].RDCRCR.U = 
                                                                     (uint32)0U; 
                                                                     
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].CHCFGR.U = 
                                                         DMA_CH_CHCFGR_BLK_MOVE;
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].ADICR.U = 
                                                                   DMA_CH_ADICR;
                                                                   
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].SADR.U = 
                                                         (uint32)SourceAddress2;
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].DADR.U = 
                                                           (uint32)DestAddress2;
                                                           
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].SDCRCR.U = 
                                                                     (uint32)0U;
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].RDCRCR.U = 
                                                                     (uint32)0U;  

          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].CHCSR.U = 
                                                                   START_DMA_TX; 
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].CHCSR.U = 
                                                                   START_DMA_TX;
                                                                   
          while ( ((DmaICH1  == 0U)||(DmaICH2 == 0U)) && (0U < Timeout))
          {
            Timeout = Timeout - 1U;
            /* wait until DMA transfer complete */
            DmaICH1 = (uint32)(MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].
                                                     DmaChTx1].CHCSR.B.ICH);
            DmaICH2 = (uint32)(MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].
                                                   DmaChTx2].CHCSR.B.ICH);  
          }
  
          if((DmaICH1 == 0U) || (DmaICH2 == 0U))           
          {
            Result = DMA_CRC_RESOURCE_TIMEOUT_ERROR;
          }    
          else
          {     
            for(Count = 0U; Count< 4U; Count++)
            {
              CalculatedSDCRC_ch1 = (uint32)CRC32(CalculatedSDCRC_ch1,(uint32)
                                                      (&SourceAddress1[Count]));
              CalculatedSDCRC_ch1 = (uint32)CRC32(CalculatedSDCRC_ch1, (uint32)
                                                        (&DestAddress1[Count]));  
              CalculatedSDCRC_ch2 = (uint32)CRC32(CalculatedSDCRC_ch2, (uint32)
                                                      (&SourceAddress2[Count]));
              CalculatedSDCRC_ch2 = (uint32)CRC32(CalculatedSDCRC_ch2, (uint32)
                                                        (&DestAddress2[Count]));  
              CalculatedRxDataCRC_ch1 = (uint32)CRC32(CalculatedRxDataCRC_ch1, 
                                                           DestAddress1[Count]);
              CalculatedRxDataCRC_ch2 = (uint32)CRC32(CalculatedRxDataCRC_ch2, 
                                                           DestAddress2[Count]);
            }
            Sdcrc_me0 = MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].SDCRCR.U;
            Sdcrc_me1 = MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].SDCRCR.U;
            Rdcrc_me0 = MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].RDCRCR.U;
            Rdcrc_me1 = MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].RDCRCR.U;

            Result = 0U;
            if((CalculatedSDCRC_ch1!= Sdcrc_me0)&&
                (CalculatedSDCRC_ch2 != Sdcrc_me0))
            {
              Result =   DMA_CRC_SDCRC_FAIL;   
            }
            if((Sdcrc_me1 != CalculatedSDCRC_ch1)&&
                (Sdcrc_me1 != CalculatedSDCRC_ch2))
            {
              Result =   DMA_CRC_SDCRC_FAIL;         
            }
            if((CalculatedRxDataCRC_ch1!= Rdcrc_me0)&&
                (CalculatedRxDataCRC_ch2 != Rdcrc_me0))
            {
              Result|=   DMA_CRC_RDCRC_FAIL;    
            }
            if((CalculatedRxDataCRC_ch1!= Rdcrc_me1)&&
                (CalculatedRxDataCRC_ch2 != Rdcrc_me1))
            {
              Result|=   DMA_CRC_RDCRC_FAIL;  
            }
            if(Result == 0U)
            {
              Result = DMA_CRC_SUCCESS;
            }
          }
        }
        else
        {
          Result = DMA_CRC_RESOURCE_TIMEOUT_ERROR;          
        }
        /*Restore DMA configurations          */
        DmaTst_lRestore(&DmaTst_BackupData, ParamSetIndex);
      
      /* Release spinlock for SMU alarms */
      Sl_ReleaseSpinLock(SL_DMA_SPNLCK_ID);  
    }
    else
    {
      Result = DMA_CRC_RESOURCE_TIMEOUT_ERROR;
    }
  }
  else
  {
    Result = DMA_CRC_INVALID_PARAMETER;
  }
  /* Calculate final test signature */
  *TstSignature = (uint32)CRC32(*TstSignature,Result);
  return(Result);

}
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType DmaTst_TimestampTst                                **
**          (                                                                 **
**             const  Sl_ParamSetIndex ParamSetIndex,                         **
**             const  uint8 TstSeed,                                          **
**             uint32* const TstSignature                                     **
**          )                                                                 **
**  Description :                                                             **
**Appendage of timestamps to the end of DMA transactions                      **
**supports flow control. Relative count value of the timestamp                **
**(i.e.an increment in the timestamp) when multiple transactions              **
**are executed signifies the sequence of DMA writes to different              **
**destination addresses.                                                      **
**The Timestamp test checks the Timestamp functionality on both               **
**move engines i.e. parallel transactions are started on 2 DMA                **
**channels so that both the move engines are being used.                      **
**An increment in the timestamp values should be noticed                      **
**when multiple transactions are executed. The timestamp                      **
**increment should be consistent with the order of completion                 **
**of the DMA transactions. If timestamp on one particular channel             **
**is not showing incremental trend on two consecutive transactions,           **
**test will report failure.                                                   **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                   Note: This parameter is ignored because no configuration **
**                   is required for this test. It is only defined for        **
**                   reasons of compatibility with APIs of other MTL tests.   **
**                                                                            **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**                                                                            **
**DMA_SUCCESS  Test succeeded                                                 **
**DMA_INVPARAMERR  Test failed because an invalid parameter was supplied      **
**DMA_RESOURCE_TIMEOUT_ERROR  DMA resource timeout                            **
**DMA_TIMESTAMP_FAIL_MEx  Error in Timestamp appendage on Move Engine x       **
*******************************************************************************/

Sl_TstRsltType DmaTst_TimestampTst
  (
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed, 
  uint32* const TstSignature
  )

{
  Sl_TstRsltType                Result = DMA_TIMESTAMP_TEST_NOTEXECUTED;
  uint32                        Timeout   = DMA_ENABLE_TIMEOUT;
  uint32                        TimeStamp1_ME0 = 0U;
  uint32                        TimeStamp2_ME0 = 0U; 
  uint32                        TimeStamp1_ME1 = 0U;
  uint32                        TimeStamp2_ME1 = 0U;
  DmaTst_BackupDataType         DmaTst_BackupData = \
                    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  /* Initialize Test Signature:   */
  *TstSignature = 
              (uint32)CRC32((uint32)TEST_ID_DMA_TIMESTAMP_TST, (uint32)TstSeed);

  if(
    (ParamSetIndex < DMATST_CFG_PARAM_COUNT)&&
    (DmaTstConfigSet[ParamSetIndex].DmaChTx1 < DMA_CHANNELS)&&
    (DmaTstConfigSet[ParamSetIndex].DmaChTx2 < DMA_CHANNELS)
    )
  {

    if(E_OK == Sl_GetSpinLock(SL_DMA_SPNLCK_ID, SL_DMA_TIMEOUT))
    {
      /*Backup Registers that will be modified*/
      DmaTst_lInit(&DmaTst_BackupData, ParamSetIndex);
 
      if(DMA_CLC.B.DISS == 0U)
      {
        Timeout = DMA_TIMESTAMP_WAITTIMEOUT;
        if(DMA_TIME.U >= DMA_MIN_TIMESTAMP)
        {
          while ((DMA_TIME.U >= DMA_MIN_TIMESTAMP) && (0U < Timeout))
          {
            Timeout = Timeout - 1U;
            /* wait until module is enabled */
          } 
        }  
        if(DMA_TIME.U < DMA_MIN_TIMESTAMP)
        {

          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].CHCFGR.U = 
                                                         DMA_CHCFGR_SINGLE_MOVE;
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].ADICR.U  = 
                                                              DMA_ADD_TIMESTAMP;
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].CHCFGR.U = 
                                                         DMA_CHCFGR_SINGLE_MOVE;
          MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].ADICR.U  = 
                                                              DMA_ADD_TIMESTAMP;


          Result = DmaTst_lGetTimeStamps(ParamSetIndex, &TimeStamp1_ME0, 
                                               &TimeStamp1_ME1);
          if(Result == DMA_TIMESTAMP_TEST_NOTEXECUTED)
          {
            Result= DmaTst_lGetTimeStamps(ParamSetIndex, &TimeStamp2_ME0, 
                                               &TimeStamp2_ME1);  
          }
          if(Result == DMA_TIMESTAMP_TEST_NOTEXECUTED)
          {        
            if((TimeStamp1_ME0 > TimeStamp2_ME0) || 
              (TimeStamp1_ME1 > TimeStamp2_ME1))
            {
              Result =   DMA_TIMESTAMP_FAIL;
            }
            else
            {
              Result =   DMA_TIMESTAMP_SUCCESS;   
            }
          }
        }
        else
        {
          Result = DMA_TIMESTAMP_RESOURCE_TIMEOUT_ERROR;          
        }        

       }
       else
       {
        Result = DMA_TIMESTAMP_RESOURCE_TIMEOUT_ERROR;           
       }
       /*Restore DMA configurations          */
      DmaTst_lRestore(&DmaTst_BackupData, ParamSetIndex);
      /* Release spinlock for SMU alarms */
      Sl_ReleaseSpinLock(SL_DMA_SPNLCK_ID);  
    }
    else
    {
      Result = DMA_TIMESTAMP_RESOURCE_TIMEOUT_ERROR;
    }
  }
  else
  {
    Result = DMA_TIMESTAMP_INVALID_PARAMETER;
  }
  /* Calculate final test signature */
  *TstSignature = (uint32)CRC32(*TstSignature,Result);

  return(Result);

}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType DmaTst_SafeLinkedListTst                           **
**          (                                                                 **
**             const  Sl_ParamSetIndex ParamSetIndex,                         **
**             const  uint8 TstSeed,                                          **
**             uint32* const TstSignature                                     **
**          )                                                                 **
**Description :                                                               **
**In Safe Linked List mode, shadow register is address pointer to read 32-byte**
**transaction control set from anywhere in memory. After a transaction gets   **
**over, current transaction control set in DMARAM is overwritten by new one   **
**from the pointer provided in shadow register.                               **
**New transaction starts only if SDCRC in new transaction control set         **
**contains valid SDCRC calculated by previous DMA transfer                    **
**The test checks for:                                                        **
**Next transaction from linked list fails bacause value if expected CRC is    **
**wrong                                                                       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                                                                            **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**DMA_SUCCESS  Test succeeded                                                 **
**DMA_INVPARAMERR  Test failed because an invalid parameter was supplied      **
**DMA_RESOURCE_TIMEOUT_ERROR  DMA resource timeout                            **
**DMA_SAFE_LINKEDLIST_SDCRC_MISMATCHERR                                       **
**2nd DMA transfer should fail while first should pass. If second transaction **
**does not fail, this error is reported.                                      **
*******************************************************************************/

Sl_TstRsltType DmaTst_SafeLinkedListTst
  (
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed, 
  uint32* const TstSignature
  )

{
  Sl_TstRsltType          Result = DMA_SAFELINKLST_TEST_NOTEXECUTED;
  DmaTst_BackupDataType   DmaTst_BackupData =  \
                   {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
  uint32                  CalculatedSDCRC_ch = 0U;
  /* the values at source and destination addresses is arbitrarily chosen. 
     The contents do not matter */
  volatile static uint32         SourceAddressTx[4] = {50U,60U,70U,80U};
  volatile static uint32         DestAddressTx[4] = {0U,0U,0U,0U};
  volatile static uint32         SourceAddress[4] = {100U,200U,300U,400U};
  volatile static uint32         DestAddress[4] = {0U,0U,0U,0U};
  uint32                  Err0;
  uint32                  Err1;
  uint32                  DmaICH1 = 0U;
  uint32                  Timeout = DMA_TRANSFER_WAITTIMEOUT;

  /* Initialize Test Signature:   */
  *TstSignature = 
        (uint32)CRC32((uint32)TEST_ID_DMA_SAFELINKEDLIST_TST, (uint32)TstSeed );

  if(
    (ParamSetIndex < DMATST_CFG_PARAM_COUNT)&&
    (DmaTstConfigSet[ParamSetIndex].DmaChTx1 < DMA_CHANNELS)&&
    (DmaTstConfigSet[ParamSetIndex].DmaChTx2 < DMA_CHANNELS)
    )
  {
    if(E_OK == Sl_GetSpinLock(SL_DMA_SPNLCK_ID, SL_DMA_TIMEOUT))
    {
      /*Backup Registers that will be modified*/
      DmaTst_lInit(&DmaTst_BackupData, ParamSetIndex);

      if(DMA_CLC.B.DISS == 0U)
      {
        DmaTst_transactionSet[1].RDCRC = 0U;
        DmaTst_transactionSet[1].SDCRC = CalculatedSDCRC_ch; 
        DmaTst_transactionSet[1].SADR = (uint32)(SourceAddressTx);
        DmaTst_transactionSet[1].DADR = (uint32)(DestAddressTx);                         
        DmaTst_transactionSet[1].ADICR = DMA_SAFELINKEDLIST_MODE; 
        DmaTst_transactionSet[1].CHCFGR = DMA_CH_CHCFGR_BLK_MOVE;            
        DmaTst_transactionSet[1].SHADR = &DmaTst_transactionSet[2U];
        DmaTst_transactionSet[1].CHCSR = START_DMA_TX;
        
        DmaTst_transactionSet[0].RDCRC =0U;
        DmaTst_transactionSet[0].SDCRC = 0U; 
        DmaTst_transactionSet[0].SADR = (uint32)(SourceAddress);
        DmaTst_transactionSet[0].DADR = (uint32)(DestAddress);                        
        DmaTst_transactionSet[0].ADICR = DMA_SAFELINKEDLIST_MODE; 
        DmaTst_transactionSet[0].CHCFGR = DMA_CH_CHCFGR_BLK_MOVE; 
        DmaTst_transactionSet[0].SHADR = &DmaTst_transactionSet[1U];
        DmaTst_transactionSet[0].CHCSR = START_DMA_TX;

        DmaTst_transactionSet[2].RDCRC = 0U;
        DmaTst_transactionSet[2].SDCRC = 0U;
        DmaTst_transactionSet[2].SADR  = 0U;
        DmaTst_transactionSet[2].DADR = 0U;                       
        DmaTst_transactionSet[2].ADICR = 0U;  
        DmaTst_transactionSet[2].CHCFGR = 0U; 
        DmaTst_transactionSet[2].SHADR = NULL_PTR;
        DmaTst_transactionSet[2].CHCSR = 0U;        

         
        MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].RDCRCR.U = 
                                       (uint32)(DmaTst_transactionSet[0].RDCRC); 
        MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].SDCRCR.U = 
                                       (uint32)(DmaTst_transactionSet[0].SDCRC);             
        MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].SADR.U   =
                                                  DmaTst_transactionSet[0].SADR;
        MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].DADR.U   = 
                                                  DmaTst_transactionSet[0].DADR;   
        MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].CHCFGR.U = 
                                                DmaTst_transactionSet[0].CHCFGR; 
        MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].ADICR.U  = 
                                                 DmaTst_transactionSet[0].ADICR;             
        MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].SHADR.U  = 
                                         (uint32)DmaTst_transactionSet[0].SHADR;
      
        MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].CHCSR.U  = 
                                                 DmaTst_transactionSet[0].CHCSR;
                                                 
        while ((DmaICH1 == 0U) && (0U < Timeout))
        {
           Timeout = Timeout - 1U;
           /* wait until DMA transfer complete */
           DmaICH1 = (uint32)(MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].
                                                     DmaChTx1].CHCSR.B.ICH);
        }
    
        if(DmaICH1 == 0U)
        {
           Result = DMA_SAFELINKLSTRESOURCE_TIMEOUT_ERROR;              
        }
        /*read DMA_ERRSRx to find which error occured*/
        else
        {
          Err0 = (uint32)DMA_ERRSR0.B.SLLER;
          Err1 = (uint32)DMA_ERRSR1.B.SLLER;
          if( (Err0 != 0U) || (Err1 != 0U))
          {
            if(Err0)
            {
              DMA_CLRE0.B.CSLLER = 1U;
            }
            else
            {
              DMA_CLRE1.B.CSLLER = 1U;            
            }
            Result = DMA_SAFELINKLST_SUCCESS ; 
          }
          else
          {
            Result = DMA_SAFELINKLST_SDCRC;  
          }
        }
      }
      else
      {
        Result = DMA_SAFELINKLSTRESOURCE_TIMEOUT_ERROR;
      }
      /*DMA_SHADRz restored here because ADICR.SCHT is required to be set before 
                     writing to DMA_SHADRz*/
      MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].SHADR.U = 
                                                   DmaTst_BackupData.DMA_SHADR1;
      /*Clear the Service Request Flag */
      SRC_DMAERR.U = (((unsigned_int)DmaTst_BackupData.SRC_DMAERR1 & 
                            SRC_DMAERR_CLR_RESERVED_BIT) | SRC_DMAERR_CLRR_MASK);
      /*Restore DMA configurations          */
      DmaTst_lRestore(&DmaTst_BackupData, ParamSetIndex);
        /* Release spinlock for SMU alarms */
      Sl_ReleaseSpinLock(SL_DMA_SPNLCK_ID);
    }
    else
    {
      Result = DMA_SAFELINKLSTRESOURCE_TIMEOUT_ERROR;
    }
  }
  else
  {
    Result = DMA_SAFELINKLST_INVALID_PARAMETER;
  }
  /* Calculate final test signature */
  *TstSignature = (uint32)CRC32(*TstSignature,Result);

  return(Result);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : DmaTst_lInit (Sl_ParamSetType  ParamSetIndex, uint32 channels)    **
**                                                                            **
** Description : Does a backup of the DMA registers that will be overwritten  **
**                by this test in structure Dma_backup                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for taking backup                        **
**                                                                            **
** Parameters (out): DmaTst_BackupData-                                       **
**          Stores backup of registers modified by the test                   **
** Return value :     None                                                    **
**                                                                            **
*******************************************************************************/
static void DmaTst_lInit ( DmaTst_BackupDataType* const DmaTst_BackupData, Sl_ParamSetType  ParamSetIndex)
{
  volatile uint32 Dummy = 0U;

  UNUSED_PARAMETER(Dummy)  
  
  DmaTst_BackupData->DMA_ENABLE  =   (uint8)(DMA_CLC.B.DISS);  
  DmaTst_BackupData->DMA_CHCFGR1 =   MODULE_DMA.CH[DmaTstConfigSet
                                             [ParamSetIndex].DmaChTx1].CHCFGR.U;
  DmaTst_BackupData->DMA_SADR1   =   MODULE_DMA.CH[DmaTstConfigSet
                                               [ParamSetIndex].DmaChTx1].SADR.U;
  DmaTst_BackupData->DMA_DADR1   =   MODULE_DMA.CH[DmaTstConfigSet
                                               [ParamSetIndex].DmaChTx1].DADR.U;

  DmaTst_BackupData->DMA_CHCFGR2 =   MODULE_DMA.CH[DmaTstConfigSet
                                            [ParamSetIndex].DmaChTx2].CHCFGR.U ;
  DmaTst_BackupData->DMA_SADR2   =   MODULE_DMA.CH[DmaTstConfigSet
                                               [ParamSetIndex].DmaChTx2].SADR.U;
  DmaTst_BackupData->DMA_DADR2   =   MODULE_DMA.CH[DmaTstConfigSet
                                                [ParamSetIndex].DmaChTx2].DADR.U;

  DmaTst_BackupData->DMA_SDCRCR1 =   MODULE_DMA.CH[DmaTstConfigSet
                                             [ParamSetIndex].DmaChTx1].SDCRCR.U;
  DmaTst_BackupData->DMA_SDCRCR2 =   MODULE_DMA.CH[DmaTstConfigSet
                                             [ParamSetIndex].DmaChTx2].SDCRCR.U;
  DmaTst_BackupData->DMA_RDCRCR1 =   MODULE_DMA.CH[DmaTstConfigSet
                                             [ParamSetIndex].DmaChTx1].RDCRCR.U;
  DmaTst_BackupData->DMA_RDCRCR2 =   MODULE_DMA.CH[DmaTstConfigSet
                                             [ParamSetIndex].DmaChTx2].RDCRCR.U;

  DmaTst_BackupData->DMA_CH_ADICR1 = MODULE_DMA.CH[DmaTstConfigSet
                                              [ParamSetIndex].DmaChTx1].ADICR.U;
  DmaTst_BackupData->DMA_CH_ADICR2 = MODULE_DMA.CH[DmaTstConfigSet
                                              [ParamSetIndex].DmaChTx2].ADICR.U;
                                              
  DmaTst_BackupData->DMA_SHADR1   = MODULE_DMA.CH[DmaTstConfigSet
                                              [ParamSetIndex].DmaChTx1].SHADR.U;
                                              
  DmaTst_BackupData->SRC_DMAERR1   = SRC_DMAERR.U;
  
  /* Check if DMA module is enabled. If not enable it. */
  if (DMA_CLC.B.DISS != 0U)
  {
    Mcal_ResetENDINIT();
    /* DMA clock control register.        */
    DMA_CLC.B.DISR   = 0x0U;
    Mcal_SetENDINIT();
    Dummy = DMA_CLC.U;
  }  
  
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : DmaTst_lRestore (Sl_ParamSetType  ParamSetIndex , uint32 channels)**
** Description : Restores DMA registers overwritten by this test from         **
**               structure Dma_backup                                         **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for taking backup                        **
**                                                                            **
** Parameters (out): DmaTst_BackupData-                                       **
**      Stores backup of registers modified by the test                       **
** Return value :                                                             **
*******************************************************************************/
static void DmaTst_lRestore (const DmaTst_BackupDataType* DmaTst_BackupData, Sl_ParamSetType  ParamSetIndex)
{                                            

  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].CHCFGR.U =    
                                                 DmaTst_BackupData->DMA_CHCFGR1;
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].SADR.U   =    
                                                   DmaTst_BackupData->DMA_SADR1;
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].DADR.U   =    
                                                   DmaTst_BackupData->DMA_DADR1;

  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].CHCFGR.U =    
                                                 DmaTst_BackupData->DMA_CHCFGR2;
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].SADR.U   =    
                                                   DmaTst_BackupData->DMA_SADR2;
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].DADR.U   =    
                                                   DmaTst_BackupData->DMA_DADR2;

  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].SDCRCR.U =    
                                                 DmaTst_BackupData->DMA_SDCRCR1;
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].SDCRCR.U =    
                                                 DmaTst_BackupData->DMA_SDCRCR2;
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].RDCRCR.U =    
                                                 DmaTst_BackupData->DMA_RDCRCR1;
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].RDCRCR.U =    
                                                DmaTst_BackupData->DMA_RDCRCR2 ;

  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].ADICR.U  =   
                                               DmaTst_BackupData->DMA_CH_ADICR1;
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].ADICR.U  =    
                                              DmaTst_BackupData->DMA_CH_ADICR2 ;
  
  /* Clear inactive DMA channel interrupt ICH bit */
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].CHCSR.B.CICH = 1U;
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].CHCSR.B.CICH = 1U; 
  
  Mcal_ResetENDINIT();
                                          
  DMA_CLC.B.DISR = (uint8)(DmaTst_BackupData->DMA_ENABLE);
  
  Mcal_SetENDINIT();
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax :      DmaTst_lGetTimeStamps (Sl_ParamSetType  ParamSetIndex ,      **
**                               uint32* TimeStamp_ME0, uint32* TimeStamp_ME1)**
** Description : gets timestamps of transactions for both move engines        **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for taking backup                        **
**                                                                            **
** Parameters (out): TimeStamp_ME0 , TimeStamp_ME1   -                        **
**      Stores time stamp of ME0, ME1 resp                                    **
** Return value :                                                             **
**DMA_TEST_NOTEXECUTED  No error in DMA tx. This is initial value             **
**DMA_RESOURCE_TIMEOUT_ERROR  DMA resource timeout                            **
*******************************************************************************/

static Sl_TstRsltType DmaTst_lGetTimeStamps(const Sl_ParamSetType ParamSetIndex, 
                                   uint32* TimeStamp_ME0, uint32* TimeStamp_ME1)
{
  Sl_TstRsltType       Result = DMA_TIMESTAMP_TEST_NOTEXECUTED; 
  static uint32               SourceAddress1 = 10U;
  static uint32               SourceAddress2 = 1U;
  uint32               DmaICH1 = 0U; 
  uint32               DmaICH2 = 0U;
  uint32	           Dma_ME0_WriteStatus = 1U;  
  uint32               Dma_ME1_WriteStatus = 1U;
  uint32               Timeout = DMA_TRANSFER_WAITTIMEOUT;
  
  DmaTst_DestAddress1[0] = 0U;
  DmaTst_DestAddress1[1] = 0U;
  DmaTst_DestAddress2[0] = 0U;
  DmaTst_DestAddress2[1] = 0U;  
  
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].SADR.U   =  
                                                      (uint32)(&SourceAddress1);
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].DADR.U   =  
                                                    (uint32)DmaTst_DestAddress1;
  
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].SADR.U =  
                                                      (uint32)(&SourceAddress2);
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].DADR.U =  
                                                    (uint32)DmaTst_DestAddress2;     
    
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx1].CHCSR.U = START_DMA_TX;
  MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].DmaChTx2].CHCSR.U = START_DMA_TX; 
  
  while ((((DmaICH1 & DmaICH2) == 0U) ||
  ((Dma_ME0_WriteStatus|Dma_ME1_WriteStatus) == 1U )) && (0U < Timeout))
  {
    Timeout = Timeout - 1U;
    /* wait until DMA transfer complete */
    DmaICH1 = (uint32)(MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].
                                             DmaChTx1].CHCSR.B.ICH);
    DmaICH2 = (uint32)(MODULE_DMA.CH[DmaTstConfigSet[ParamSetIndex].
                                             DmaChTx2].CHCSR.B.ICH);
	Dma_ME0_WriteStatus = DMA_ME0SR.B.WS;
	Dma_ME1_WriteStatus = DMA_ME1SR.B.WS;
  }  
   
   if((DmaICH1 == 0U) || (DmaICH2 == 0U) ||  
   (Dma_ME0_WriteStatus == 1U) || (Dma_ME1_WriteStatus == 1U))         
   {
     Result = DMA_TIMESTAMP_RESOURCE_TIMEOUT_ERROR;
   }
   else
   {   
     /* Read TimeStamp Values appended to the Destination Address */
     *TimeStamp_ME0 = DmaTst_DestAddress1[1];
     *TimeStamp_ME1 = DmaTst_DestAddress2[1];
   }
   
   return(Result);
}

#define IFX_DMATST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
