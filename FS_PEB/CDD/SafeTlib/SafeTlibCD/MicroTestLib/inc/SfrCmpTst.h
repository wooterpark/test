#ifndef SFRCMPTST_H
#define SFRCMPTST_H

/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : SfrCmpTst.h $                                              **
**                                                                            **
**   $CC VERSION : \main\12 $                                                 **
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
**  DESCRIPTION  : SfrCmp test read the values of configured SFR register,    **
** apply a mask value and then comapre them to an expected configuration value**
**    This file contains the single point fault metric SFR                    **
**                 Compare test                                               **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "SfrTst_Cfg.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"

#define IFX_SFRTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType SfrTst_SfrCmpTst                                   **
**          (const Sl_ParamSetType ParamSetIndex, const uint8 TstSeed,        **
**           uint32* const TstSignature)                                      **
**                                                                            **
** Description : This test checks the SFRs for unintended configuration       **
**               changes. To detect those changes the Sfr Cmp test does read  **
**               the contents of the configured registers, does apply a mask  **
**               to those values, which allows to ignore certain bits and     **
**               compares the masked values to the also configured expected   **
**               values. In case both values do not match, the test fails as  **
**               the actual configuration differs from the expected one.      **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Reentrant                                                      **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : SFR_CMP_SUCCESS       - Test succeeded                      **
**            SFR_CMP_INVPARAMERR   - Test failed because an invalid parameter**
**                                    was supplied                            **
**            SFR_CMP_RESGRx_REGyDM - Test failed because register given by   **
**                                    error doesn't contain the expected value**
**            SFR_CMP_OVERLOAD      - Test did not start because there are    **
**                                    too many registers defined. This test   **
**                                    can handle 112 registers at most        **
**                                                                            **
*******************************************************************************/

extern Sl_TstRsltType SfrTst_SfrCmpTst
(
 const Sl_ParamSetType ParamSetIndex,
 const uint8 TstSeed,
 uint32* const TstSignature
);

/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/
#define IFX_SFRTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

#endif /* SFRCMPTST_H */
