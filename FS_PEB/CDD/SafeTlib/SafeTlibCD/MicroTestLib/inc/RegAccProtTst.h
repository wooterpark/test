#ifndef REGACCPROTTST_H
#define REGACCPROTTST_H

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
**   $FILENAME   : RegAccProtTst.h $                                          **
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
**  DESCRIPTION  : This file provides latent fault metric test routines for   **
**                 the CPU Register Access Protection.                        **
**                                                                            **
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_CPU_RegAcc_Prot_Test, v0.4            **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Platform_Types.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"
#include "SmuInt.h"


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
** Syntax : Sl_TstRsltType RegAccProtTst_RegAccProtTst                        **
**          (                                                                 **
**             const  Sl_ParamSetIndex ParamSetIndex,                         **
**             const  uint8 TstSeed,                                          **
**             uint32* const TstSignature                                     **
**          )                                                                 **
**                                                                            **
** Description : This test checks that the register protection scheme does    **
**               work as expected. To verify this, the following actions are  **
**               being executed:                                              **
**               • Allow all masters access to the protected registers        **
**               • Use different masters (Current CPU’s DMI safe and non-safe **
**                 master) and alter a protected register. Check that the     **
**                 register contents actually got changed.                    **
**               • Deny all masters, except CPU.DMI and Cerberus, to access   **
**                 the protected registers                                    **
**               • Try to alter protected registers with different masters    **
**                 (Current CPU’s DMI safe and non-safe master) and check     **
**                 that each time a SMU alarm is generated.                   **
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
**                   Note: This parameter is ignored and should always be set **
**                   to zero. It is only defined for reasons of compatibility **
**                   with APIs of other MTL tests                             **
**                                                                            **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : REGACC_SUCCESS     - Test succeeded                         **
**                                                                            **
**                REGACC_NOTEXECUTED - The test has not been executed or at   **
**                least was interrupted before a valid result could be        **
**                generated                                                   **
**                                                                            **
**                REGACC_SMU_STATEERR - The test cannot be executed because   **
**                the SMU is in the wrong state                               **
**                                                                            **
**                REGACC_SMU_GETALMSTSERR - Test failed because getting the   **
**                SMU alarm status failed                                     **
**                                                                            **
**                REGACC_SMU_CLRALMSTSERR - The test failed because clearing  **
**                the SMU alarm failed.                                       **
**                                                                            **
**                REGACC_ SMU_ALMSTSERR - Test failed because there is already**
**                a watchdog alarm present within the SMU.                    **
**                                                                            **
**                REGACC_SMU_SETALMACTIONERR - Test failed because setting the**
**                SMU alarm action failed.                                    **
**                                                                            **
**                REGACC_SMU_GETALMACTIONERR - Test failed because getting the**
**                SMU alarm action failed.                                    **
**                                                                            **
**                REGACC_DENY_NOSMUALRM - Test failed because no SMU alarm    **
**                was generated also a not allowed master tried to write to a **
**                protected register.                                         **
**                                                                            **
**                REGACC_STUCKATFAULT - Test failed because there seems to be **
**                a stuck-at fault within the CPU’s ACCENA register           **
**                                                                            **
**                REGACC_ACCBLOCKED - The test failed because an attempt to   **
**                write to a protected register with a master that is allowed **
**                got anyway blocked                                          **
**                                                                            **
**                REGACC_ACCNOTBLOCKED - The test failed because an attempt   **
**                to write to a protected register with a master that is not  **
**                allowed  got not blocked                                    **
*******************************************************************************/
#define IFX_REGACCPROTTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
extern Sl_TstRsltType RegAccProtTst_RegAccProtTst
(
 const Sl_ParamSetType ParamSetIndex,
 const uint8 TstSeed,
 uint32* const TstSignature
);
#define IFX_REGACCPROTTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* REGACCPROTTST_H */

