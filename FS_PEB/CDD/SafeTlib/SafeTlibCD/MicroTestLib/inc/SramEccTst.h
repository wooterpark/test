#ifndef SRAMECCTST_H
#define SRAMECCTST_H
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
**   $FILENAME   : SramEccTst.h $                                             **
**                                                                            **
**   $CC VERSION : \main\19 $                                                 **
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
**  DESCRIPTION  : This file contains exported APIs and types of the SRAM     **
**                 test                                                       **
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
#include "SramEccTst_Cfg.h"
#include "Mcal_Compiler.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                        Imported function declarations                       *
*******************************************************************************/


/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/* Type definition of the SRAM ECC tests configuration structure: */
typedef struct SramEccTst_ConfigType
{
	uint32                    MemorySelect;
	boolean                   BackupMemory;
}SramEccTst_ConfigType;

/* SRAM ECC unexpected alarms already set before test code execution: */
typedef struct SramEccTst_UnexpAlarmType
{
    uint32  Correctable;
    uint32  Uncorrectable;
    uint32  Address;
    uint32  ErrTrkOvf;
    uint32  Crc;
} SramEccTst_UnexpAlarmType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/* Constant array having the Link time configuration for SRAM ECC test driver.
 * Can have more than one configuration set.
 */
#define IFX_SRAM_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
extern const SramEccTst_ConfigType SramEccTst_ConfigRoot[SRAMECC_TST_CFG_PARAM_COUNT];
#define IFX_SRAM_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define IFX_SRAM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Sl_TstRsltType SramEccTst_SramEccTst                    **
**                                      (const Sl_ParamSetType ParamSetIndex, **
**                                       const uint8 TstSeed,                 **
**                                       uint32* const TstSignature);         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : ParamSetIndex : Identifies the parameter set to be      **
**                                    used for test execution                 **
**                    TstSeed : Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : SRAM_SUCCESS - Test successed                           **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : API provided for the SRAM ECC test.               		  **
**                    It is responsible for test preparation, test execution  **
**                    and final test restoration.                             **
**                                                                            **
*******************************************************************************/
extern Sl_TstRsltType SramEccTst_SramEccTst
(
    const Sl_ParamSetType ParamSetIndex,
    const uint8 TstSeed,
    uint32* const TstSignature
);

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SramEccTst_UnexpAlmType*                                          **
**          SramEccTst_GetUnexpEccAlmListPtr(void)                            **
**                                                                            **
** Description : Returns a pointer to a list that contains the number         **
**               of unexpected ECC alarms that have been cleared before a     **
**               test run.                                                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value :   SramEccTst_UnexpAlmType* Pointer to list of unexpected    **
**                                           Ecc alarms cleared before a test **
**                                           run                              **
**                                                                            **
*******************************************************************************/
extern SramEccTst_UnexpAlarmType* SramEccTst_GetUnexpEccAlmListPtr
(
  void
);
#define IFX_SRAM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/
#endif /* SRAMECCTST_H */

