#ifndef DMATST_H
#define DMATST_H
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
**   $FILENAME   : DmaTst.h $                                                 **
**                                                                            **
**   $CC VERSION : \main\14 $                                                 **
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
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_DMA_Test, v1.0                        **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Sl_ErrorCodes.h"
#include "DmaTst_Cfg.h"
#include "Mcal_Compiler.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/


/* Type defintion for DmaTst Configuration */
typedef struct DmaTst_ConfigType
{
  uint32  DmaChTx1;
  uint32  DmaChTx2;

}DmaTst_ConfigType;


/* Storage for backup of the DMA test */

typedef struct DmaTst_BackupDataType
{
  uint32  DMA_RDCRCR1; 
  uint32  DMA_SDCRCR1;
  uint32  DMA_CHCFGR1;
  uint32  DMA_CH_ADICR1;
  uint32  DMA_SADR1;
  uint32  DMA_DADR1;
  uint32  DMA_SHADR1;
  uint32  SRC_DMAERR1;

  uint32  DMA_RDCRCR2;
  uint32  DMA_SDCRCR2;
  uint32  DMA_CHCFGR2;
  uint32  DMA_CH_ADICR2;
  uint32  DMA_SADR2;
  uint32  DMA_DADR2;
  uint32  DMA_ENABLE;
}DmaTst_BackupDataType;

typedef struct TransactionSetType
{
  uint32 RDCRC;
  uint32 SDCRC;
  uint32 SADR;
  uint32 DADR;
  uint32 ADICR;
  uint32 CHCFGR;
  struct TransactionSetType* SHADR;
  uint32 CHCSR;
}TransactionSetType;  

#define IFX_DMATST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
extern const DmaTst_ConfigType DmaTstConfigSet[DMATST_CFG_PARAM_COUNT];
#define IFX_DMATST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#define IFX_DMATST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Function Prototypes                            **
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
**                                                        **
**ParamSetIndex -Identifies the parameter set to be used for test execution   **
**TstSeed - Seed to be used for generating the signature                 **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
** Return value :                                                             **
**DMA_SUCCESS    Test succeeded                        **
**DMA_INVPARAMERR  Test failed because an invalid parameter was supplied    **
**DMA_RESOURCE_TIMEOUT_ERROR  DMA resource timeout                          **
**DMA_SDCRC_FAIL_MEx  SDCRC did not match with expected CRC for Move Enginex**
**DMA_RDCRC_FAIL_MEx  RDCRC did not match with expected CRC for Move Enginex**
*******************************************************************************/

extern Sl_TstRsltType DmaTst_CRCTst
(

   const Sl_ParamSetType ParamSetIndex,
   const uint8 TstSeed, 
   uint32* const TstSignature
);


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
**destination addresses.                                      **
**The Timestamp test checks the Timestamp functionality on both               **
**move engines i.e. parallel transactions are started on 2 DMA                **
**channels so that both the move engines are being used.                      **
**An increment in the timestamp values should be noticed                      **
**when multiple transactions are executed. The timestamp                      **
**increment should be consistent with the order of completion                 **
**of the DMA transactions. If timestamp on one particular channel             **
is not showing incremental trend on two consecutive transactions,             **
**test will report failure.                                      **
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
**DMA_SUCCESS  Test succeeded                                              **
**DMA_INVPARAMERR  Test failed because an invalid parameter was supplied     **
**DMA_RESOURCE_TIMEOUT_ERROR  DMA resource timeout                          **
**DMA_TIMESTAMP_FAIL_MEx  Error in Timestamp appendage on Move Engine x     **
*******************************************************************************/
extern Sl_TstRsltType DmaTst_TimestampTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed, 
  uint32* const TstSignature
);
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
**from the pointer provided in shadow register.                      **
**New transaction starts only if SDCRC in new transaction control set         **
**contains valid SDCRC calculated by previous DMA transfer                    **
**The test checks for:                                                        **
**Next transaction from linked list complete successfully if parameter        **
**ErrorInjection pointed by ParamSetIndex is FALSE                            **
**Next transaction from linked list fails if parameter ErrorInjection         **
**pointed by ParamSetIndex is TRUE                                            **
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
**DMA_SUCCESS  Test succeeded                                              **
**DMA_INVPARAMERR  Test failed because an invalid parameter was supplied     **
**DMA_RESOURCE_TIMEOUT_ERROR  DMA resource timeout                          **
**DMA_SAFE_LINKEDLIST_SDCRC_MISMATCHERR                                        **
**2nd DMA transfer should fail while first should pass. If second transaction **
**does not fail, this error is reported.                                      **
*******************************************************************************/

extern Sl_TstRsltType DmaTst_SafeLinkedListTst
(
   const Sl_ParamSetType ParamSetIndex,
   const uint8 TstSeed, 
   uint32* const TstSignature
);
#define IFX_DMATST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* DMATST_H */