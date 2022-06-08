#ifndef PFLASHMONTST_H
#define PFLASHMONTST_H

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
**   $FILENAME   : PflashMonTst.h $                                           **
**                                                                            **
**   $CC VERSION : \main\17 $                                                 **
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
**                 the PFLASH monitor, i.e. tracking of PFLASH ECC errors     **
**                 to the CBAB / UBAB registers.                              **
**                                                                            **
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_PflashMon.docm, v1.0                  **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
#include "Compiler_Cfg.h"
#include "PflashMonTst_Cfg.h"
#include "PmuEccEdcTst_Cfg.h"
#include "PmuEccEdcTst_PtrnDef.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"
#include "IfxFlash_reg.h"
#include "Mcal_Compiler.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Depth of CBAB and UBAB FIFO buffers: */
#define PFLASH_MON_CBAB_FIFO_DEPTH            ( 10u )
#define PFLASH_MON_UBAB_FIFO_DEPTH            ( 1u )
/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/* Type definition PflashMonTst_ConfigType - test configuration structure: */
typedef struct PflashMonTst_ConfigType
{
  uint32 BankEnable[PFLASH_MON_TST_MAX_FLASHBANKS];
} PflashMonTst_ConfigType;

/* Type definition PflashMonTst_ClearedEntryType - unexpected, cleared CBAB /
 * UBAB entries for a single PFLASH bank:
 */
typedef struct PflashMonTst_ClearedEntryType
{
  Ifx_FLASH_CBAB_TOP  Cbab[PFLASH_MON_CBAB_FIFO_DEPTH];
  Ifx_FLASH_UBAB_TOP  Ubab[PFLASH_MON_UBAB_FIFO_DEPTH];
} PflashMonTst_ClearedEntryType;

/* Type definition PflashMonTst_ClearedErrorType - unexpected, cleared CAB /
 * UBAB entries of all PFLASH banks under test:
 */
typedef struct PflashMonTst_ClearedErrorType
{
  PflashMonTst_ClearedEntryType Bank[PFLASH_MON_TST_MAX_FLASHBANKS];
  uint32                        Crc32;
} PflashMonTst_ClearedErrorType;

/*Type definition PflashMonTst_UnexpAlarmType - unexpected, cleared SMU alarms
 * encountered during test code execution:
 */
typedef struct PflashMonTst_UnexpAlarmType
{
    uint32  Sbe;
    uint32  Dbe;
    uint32  Mbe;
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
    uint32  BufferFullErr;
#endif
    uint32  Crc32;
} PflashMonTst_UnexpAlarmType;


/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#define IFX_PFLASHMON_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
extern const PflashMonTst_ConfigType
             PflashMonTst_ConfigRoot[PFLASH_MON_TST_CFG_PARAM_COUNT];
#define IFX_PFLASHMON_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define IFX_PFLASHMON_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PflashMonTst_PflashMonTst                **
**                    (                                                       **
**                      const Sl_ParamSetIndex ParamSetIndex,                 **
**                      const uint8 TstSeed,                                  **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : ParamSetIndex - Identifies the parameter set to be used **
**                                    for test execution                      **
**                    TstSeed - Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : PFLASHMON_SUCCESS - Test succeeded                      **
**                    PFLASHMON_NOTEXECUTED - Test unexpectedly aborted       **
**                    PFLASHMON_INVPARAMERR - Invalid ParamSetIndex value     **
**                    PFLASHMON_CONFIGERR - Invalid test configuration        **
**                    PFLASHMON_SMU_GETALMACTIONERR - Smu_GetAlarmAction      **
**                                                    failed                  **
**                    PFLASHMON_SMU_SETALMACTIONERR - Smu_SetAlarmAction      **
**                                                    failed                  **
**                    PFLASHMON_SBE_PFx - Single bit error tracking test      **
**                                        failed for PFLASH bank x            **
**                    PFLASHMON_DBE_PFx - Double bit error tracking test      **
**                                        failed for PFLASH bank x            **
**                    PFLASHMON_MBE_PFx - Uncorrectable bit error tracking    **
**                                        test failed for PFLASH bank x       **
**                    PFLASHMON_DATACONSISTENCY - Internal data was corrupted **
**                                                or invalid PFLASH bank      **
**                                                                            **
** Description      : Performs a latent fault metric test of the PFLASH       **
**                    monitor, i.e. correct tracking of correctable and       **
**                    uncorrectable errors to the FLASH_CBAB / FLASH_UBAB     **
**                    registers.                                              **
** Note(s)          : Bit errors in the PFLASH test patterns need to be       **
**                    created one-time before this API is executed. The bit   **
**                    errors could be created by using the                    **
**                    Sl_ErrorPatternProg support API or by any other custom  **
**                    error programming code.                                 **
**                    This test uses the PFLASH test patterns of the          **
**                    PmuEccEdcTst. Therefore this test has some dependencies **
**                    on the PmuEccEdcTst and can also only test error        **
**                    tracking for FLASH banks that are also tested by the    **
**                    PmuEccEdcTst.                                           **
**                                                                            **
*******************************************************************************/
extern Sl_TstRsltType PflashMonTst_PflashMonTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
);

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : PflashMonTst_ClearedErrorType*                          **
**                    PflashMonTst_GetClearedErrListPtr                       **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PflashMonTst_ClearedErrorType* - Pointer to list of     **
**                    cleared CBAB / UBAB registers or NULL_PTR if the        **
**                    cleared error list data was corrupted (i.e. its CRC is  **
**                    invalid)                                                **
**                                                                            **
** Description      : Returns a pointer to a list that contains the values of **
**                    all FLASH_CBAB_TOP and FLASH_UBAB_TOP entries that have **
**                    been cleared before execution of the test.              **
**                    Valid entries can be identified by checking the VLD     **
**                    flag of all entries of the returned list.               **
**                    This list can be used by the application for own        **
**                    diagnostic purpose.                                     **
**                                                                            **
*******************************************************************************/
extern PflashMonTst_ClearedErrorType* PflashMonTst_GetClearedErrListPtr
(
  void
);

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : PflashMonTst_UnexpAlarmType*                            **
**                    PflashMonTst_GetUnexpEccAlmListPtr                      **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PflashMonTst_UnexpAlarmType* - Pointer to list of       **
**                    of unexpected and cleared SMU alarms or NULL_PTR if the **
**                    unexpected alarm list data was corrupted (i.e. its CRC  **
**                    is invalid)                                             **
**                                                                            **
** Description      : Returns a pointer to a list that contains the number of **
**                    unexpected PMU ECC single and double bit error          **
**                    correction and uncorrectable error SMU alarms that were **
**                    already set before or raised during test execution.     **
**                    This list can be used by the application for own        **
**                    diagnostic purpose.                                     **
**                                                                            **
*******************************************************************************/
extern PflashMonTst_UnexpAlarmType* PflashMonTst_GetUnexpEccAlmListPtr
(
  void
);
#define IFX_PFLASHMON_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* PFLASHMONTST_H */
