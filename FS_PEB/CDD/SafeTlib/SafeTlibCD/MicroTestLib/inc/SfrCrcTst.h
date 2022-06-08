#ifndef SFRCRCTST_H
#define SFRCRCTST_H

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
**   $FILENAME   : SfrCrcTst.h $                                              **
**                                                                            **
**   $CC VERSION : \main\11 $                                                 **
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
**  DESCRIPTION  : SfrCrc test read the contents of the configured registers, **
** apply a mask and then calculate a CRC checksum overall of them and compare **
** this checksum to an expected CRC checksum.                                 **
** This file contains the single point fault metric SFR test                  **
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
** Traceability:                                                              **
**                                                                            **
** Syntax : Sl_TstRsltType SfrTst_SfrCrcTst                                   **
** 			(const Sl_ParamSetType ParamSetIndex,const uint8 TstSeed,             **
**          uint32* const TstSignature)                                       **
**                                                                            **
**                                                                            **
** Description : This test checks the SFRs for unintended configuration       **
**               changes. To detect those changes the Sfr Crc test does read  **
**               the contents of the configured registers, does apply a mask  **
**               to those values, which allows to ignore certain bits and     **
**               then does calculate a CRC checksum over all configured       **
**               registers. If the calculated final CRC checksum does not     **
**               match the expected (configured) one, the test fails because  **
**               the actual configuration does not match with the expected    **
**               one.                                                         **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:     Reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : SFR_CRC_SUCCESS           - Test succeeded                  **
**                SFR_CRC_INVPARAMERR       - Test failed because an invalid  **
**                                        parameter was supplied              **
**                                        supplied                            **
**                SFR_CRC_DATAMISSMATCH - Test failed because the calculated  **
**                                        CRC checksum does not match the     **
**                                        expected one. Therefore at least    **
**                                        one monitored SFR must have been    **
**                                        changed.                            **
**                                                                            **
*******************************************************************************/
extern Sl_TstRsltType SfrTst_SfrCrcTst
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

#endif /* SFRCRCTST_H */
