#ifndef FCETST_H
#define FCETST_H
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
**   $FILENAME   : FceTst.h $                                                 **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantLT                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - MTL functionality for FCE kernel Test                    **
**                                                                            **
**  SPECIFICATION(S):  Aurix-HE_SafeTlib_DS_FCETest.docm                      **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/
 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"
#include "FceTst_Cfg.h"
#include "Mcal_Compiler.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/******************************************************************************
**                      Typedefs                                             **
******************************************************************************/

typedef struct FceTst_ConfigType
{
    /* Fce Kernel Selection 8/16/32 kernel */
    uint32 FceTstKernelSel;
}FceTst_ConfigType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define IFX_FCETST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/* Constant array having the Link time configuration for SMU driver.
 * Can have more than one configuration set.
 */
extern const FceTst_ConfigType FceTst_ConfigRoot[FCE_TST_CFG_PARAM_COUNT];

#define IFX_FCETST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*****************************************************************************
**                      Global Macro Definitions                            **
******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define IFX_FCETST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Sl_TstRsltType FceTst_FceTst                            **
**                                      (const uint8 TstSeed,                 **
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
** Return value     : FCETST_SUCCESS - Test successed                         **
** FCETST_FAILURE - Test Failure, FCETST_NOTEXECUTED - Test Not executed      **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : API provided for the FCE test.                          **
**                    It is responsible for test preparation, test execution  **
**                    and final test restoration.                             **
**                                                                            **
*******************************************************************************/
extern Sl_TstRsltType FceTst_FceTst
(    
    const Sl_ParamSetType ParamSetIndex,
    const uint8 TstSeed,
    uint32* const TstSignature
);

#define IFX_FCETST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/****************************************************************************************/
/* CONFIGURATION ERRORS                                                                 */
/****************************************************************************************/



/****************************************************************************************/
/* MODULE END                                                                           */
/****************************************************************************************/

#endif /* STL_FCE_H_INCLUDED */

