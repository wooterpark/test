#ifndef IRTEST_H_INCLUDED
#define IRTEST_H_INCLUDED

/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : IRTst.h $                                                  **
**                                                                            **
**   $CC VERSION : \main\18 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - interfaces for IRTst MTL                                **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h"
#include "Platform_Types.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"
#include "Compiler_Cfg.h"
#include "IRTst_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef struct IRTst_ParamSet
{
  /* DMA Selection                                                            */
  uint32                   DmaSelect;

  /* DMA channel number                                                       */
  uint32                   DmaChannel;

}IRTst_ConfigType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define IFX_IRTST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/* Exported IR test configuration                                             */
extern const IRTst_ConfigType IRTst_ConfigRoot[IRTST_CFG_PARAM_COUNT];
#define IFX_IRTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"  
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define IFX_IRTST_START_SEC_IVT_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
** Syntax : void IRTst_inttab(void)                                           **
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description     : Interrupt vector address for IR Test                     **
**                                                                            **
*******************************************************************************/
extern void IRTst_inttab
(
  void
);
#define IFX_IRTST_STOP_SEC_IVT_CODE_ASIL_B
#include "Ifx_MemMap.h"
#define IFX_IRTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType IRTst_IRTst                              **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      const uint8 TstSeed,                                  **
**                      uint32* const TstSignature                            **
                      )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : ParamSetIndex : Identifies the parameter set to be      **
**                                    used for test execution                 **
**                    TstSeed : Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : IRTST_SUCCESS - Test succeeded                          **
**                    IRTST_NOTEXECUTED - This error should never be returned.**
**                    If it is returned anyhow, this indicates a severe       **
**                    malfunction of program execution.                       **
**                    IRTST_INVPARAM - Test failed because an invalid         **
**                    parameter was supplied.                                 **
**                    IRTST_SMU_CLRALMSTSERR - Clear SMU alarm status failed. **
**                    IRTST_SMU_GETALMSTSERR - The test failed because getting**
**                    the alarm status failed                                 **
**                    IRTST_SMU_GETALMACTIONERR - The test failed because     **
**                    getting an SMU alarm action failed.                     **
**                    IRTST_SMU_SETALMACTIONERR - The test failed because     **
**                    setting an SMU alarm action failed.                     **
**                    IRTST_SMU_ALMSTSERR - The test failed because there is  **
**                    already an SMU alarm present.                           **
**                    IRTST_SMU_STATEERR - The test failed because SMU is     **
**                    not in run state.                                       **
**                    IRTST_NO_SMUALRM - Test failed because a integrity error**
**                    not singled to SMU.                                     **
**                    IRTST_ERROR_ICU - Test failed due to error in interrupt **
**                    processing.                                             **
**                                                                            **
** Description      : IRTst_IRTest is the only API provided by the test. It   **
**                    calls the test initialization function for setting up a **
**                    dedicated BIV, then triggers interrupts with and without**
**                    fault of ECC field to test ECC checker mechanism.       **
**                    Finally restores the BIV by calling the test restoration**
**                    function.                                               **
*******************************************************************************/
extern Sl_TstRsltType IRTst_IRTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
);
#define IFX_IRTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

#endif /* IRTEST_H_INCLUDED */

