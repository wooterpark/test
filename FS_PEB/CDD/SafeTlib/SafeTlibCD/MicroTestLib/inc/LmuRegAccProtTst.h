#ifndef LMUREGACCPROTTST_H
#define LMUREGACCPROTTST_H

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
**   $FILENAME   : LmuRegAccProtTst.h $                                       **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
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
**                 the LMU Register Access Protection.                        **
**                                                                            **
**  SPECIFICATION(S) : Aurix_SafeTlib_DS_LMU_RegAcc_Prot_Test.docm            **
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
** Syntax :       Sl_TstRsltType LmuRegAccProtTst_LmuRegAccProtTst            **
**                (                                                           **
**                 const Sl_ParamSetType ParamSetIndex,                       **
**                 const uint8 TstSeed,                                       **
**                 uint32* const TstSignature                                 **
**                )                                                           **            
**                                                                            **
**                                                                            **
** Description : This test checks that the register protection scheme for LMU **
                 does work as expected. To verify this, the following         **
         actions are being executed:                                          **            
**               • Allow all masters access to the protected registers        **
**               • Use different masters (Current CPU’s DMI safe and non-safe **
**                 master) and alter a protected register. Check that the     **
**                 register contents actually got changed.                    **
**               • Deny all masters, except CPU.DMI, to access                **
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
** Return value : LMUREGACC_SUCCESS     - Test succeeded                      **
**                                                                            **
**                LMUREGACC_NOTEXECUTED - The test has not been executed or at**
**                least was interrupted before a valid result could be        **
**                generated                                                   **
**                                                                            **
**                LMUREGACC_SMU_STATEERR - The test cannot be executed because**
**                the SMU is in the wrong state                               **
**                                                                            **
**                LMUREGACC_SMU_GETALMSTSERR - Test failed because getting the**
**                SMU alarm status failed                                     **
**                                                                            **
**                LMUREGACC_SMU_CLRALMSTSERR -The test failed because clearing**
**                the SMU alarm failed.                                       **
**                                                                            **
**                LMUREGACC_ SMU_ALMSTSERR - Test failed because there is     **
**                already a watchdog alarm present within the SMU.            **
**                                                                            **
**                LMUREGACC_SMU_SETALMACTIONERR - Test failed because setting **
**                SMU alarm action failed.                                    **
**                                                                            **
**                LMUREGACC_SMU_GETALMACTIONERR - Test failed because getting **
**                SMU alarm action failed.                                    **
**                                                                            **
**                LMUREGACC_DENY_NOSMUALRM - Test failed because no SMU alarm **
**                was generated also a not allowed master tried to write to a **
**                protected register.                                         **
**                                                                            **
**                LMUREGACC_STUCKATFAULT - Test failed because there seems to **
**                a stuck-at fault within the CPU’s ACCENA register           **
**                                                                            **
**                LMUREGACC_ACCBLOCKED - The test failed because an attempt to**
**                write to a protected register with a master that is allowed **
**                got anyway blocked                                          **
**                                                                            **
**                LMUREGACC_ACCNOTBLOCKED - The test failed because an attempt**
**                to write to a protected register with a master that is not  **
**                allowed  got not blocked                                    **
**                                                                            **
**                LMUREGACC_TRAPERROR - Test failed because expected number   ** 
**                of traps did not occur                                      **
**                                                                            **
**                LMUREGACC_RESOURCE_TIMEOUT - Test failed because acquiring  **
**                exclusive access to a shared resource timed out             **
*******************************************************************************/

#define IFX_LMUREGACCPROTTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
extern Sl_TstRsltType LmuRegAccProtTst_LmuRegAccProtTst
(
 const Sl_ParamSetType ParamSetIndex,
 const uint8 TstSeed,
 uint32* const TstSignature
);
#define IFX_LMUREGACCPROTTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* LMUREGACCPROTTST_H */

