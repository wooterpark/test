#ifndef PHLSRAMTST_H
#define PHLSRAMTST_H
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
**   $FILENAME   : PhlSramTst.h $                                             **
**                                                                            **
**   $CC VERSION : \main\6 $                                                  **
**                                                                            **
**   $DATE       : 2016-11-23 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains exported APIs and types of the          **
**                 Peripheral SRAM test                                       **
**                                                                            **
**  REFERENCE(S) :                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Platform_Types.h"
#include "Sl_Timeout.h"
#include "Compiler_Cfg.h"
#include "Sl_ErrorCodes.h"
#include "PhlSramTst_Cfg.h"
#include "Mcal_Compiler.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Number of entries of MemorySelect[] configuration array: */
#define PHLSRAMTST_MEMORY_SELECT_DEPTH      ((uint8)2U)

/* Width of a single entry of MemorySelect[] configuration array: */
#define PHLSRAMTST_MEMORY_SELECT_WIDTH      ((uint8)32U)


/*******************************************************************************
**                        Imported function declarations                       *
*******************************************************************************/


/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/* Type definition of the Peripheral SRAM tests configuration structure: */
typedef struct PhlSramTst_ConfigType
{
	uint32                    MemorySelect[PHLSRAMTST_MEMORY_SELECT_DEPTH];
	boolean                   ClearMemory;
} PhlSramTst_ConfigType;

/* Peripheral SRAM unexpected alarms already set before test code execution: */
typedef struct PhlSramTst_UnexpAlarmType
{
    uint32  Correctable;
    uint32  Uncorrectable;
    uint32  Address;
    uint32  ErrTrkOvf;
    uint32  Crc;
} PhlSramTst_UnexpAlarmType;


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define IFX_PHL_SRAM_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/* Constant array having the Link time configuration for the Peripheral SRAM
 * test driver. Can have more than one configuration set.
 */
extern const PhlSramTst_ConfigType PhlSramTst_ConfigRoot[PHLSRAM_TST_CFG_PARAM_COUNT];

#define IFX_PHL_SRAM_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define IFX_PHL_SRAM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_PhlSramTst                    **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      const uint8 TstSeed,                                  **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : ParamSetIndex : Identifies the parameter set to be      **
**                                    used for test execution, valid range    **
**                                    0..PHLSRAM_TST_CFG_PARAM_COUNT,         **
**                                    depending on configuration              **
**                    TstSeed : Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Test succeeded                        **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : API provided for the Peripheral SRAM test.              **
**                    It is responsible for test preparation, test execution  **
**                    and final test restoration.                             **
**                                                                            **
*******************************************************************************/
extern Sl_TstRsltType PhlSramTst_PhlSramTst
(
    const Sl_ParamSetType ParamSetIndex,
    const uint8 TstSeed,
    uint32* const TstSignature
);

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : PhlSramTst_UnexpAlmType*                                **
**                    PhlSramTst_GetUnexpEccAlmListPtr                        **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PhlSramTst_UnexpAlmType* Pointer to list of             **
**                    unexpected Ecc alarms cleared before a test run         **
**                                                                            **
** Description      : Returns a pointer to a list that contains the number    **
**                    of unexpected ECC alarms that have been cleared before  **
**                    a test run.                                             **
**                                                                            **
*******************************************************************************/
extern PhlSramTst_UnexpAlarmType* PhlSramTst_GetUnexpEccAlmListPtr
(
  void
);

/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/
#define IFX_PHL_SRAM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

#endif /* PHLSRAMTST_H */
