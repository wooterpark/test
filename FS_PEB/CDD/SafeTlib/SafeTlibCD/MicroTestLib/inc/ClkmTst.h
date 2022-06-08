#ifndef CLKTST_H
#define CLKTST_H
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
**   $FILENAME   : ClkmTst.h $                                                **
**                                                                            **
**   $CC VERSION : \main\25 $                                                 **
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
**  DESCRIPTION  : This file contains the Clkm test                           **
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
#include "ChipId.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Clock monitor no fault timeout count */
/* SMU alarm timeout. The value was chosen based on following considerations:
 * The worst case number of SMU cycles before an alarm gets visible is
 * n * 2 + 20 (with n = max. number of simultaneous alarms). With a maximum
 * of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/4 this evaluates to
 * 1872 CPU clock cycles. To avoid the counting the number of instructions per
 * loop cycle, it is assumed that only one instruction is executed per loop
 * cycle and thus the number of CPU clock cycles is directly used as timeout
 * value:
 */
#define CLKM_NO_FAULT_TIMEOUT          (0x2000U)

/* Available clock monitors in TC27x */
#if (CHIP_ID == 27U)
/* Check which step of TC27x is used */
#ifdef STEP_ID
#if (STEP_ID == C_D_STEP)
/* For TC27x D step, ADCLKSEL bit as well as CCUCON9 register are not present */
#define CLKMTST_TEST_PLLERAY_CLOCK     (TRUE)
#define CLKMTST_TEST_ADC_CLOCK         (FALSE)
#endif /*#if(STEP_ID == C_D_STEP) */
#else
/* For rest of the 27x, both the defines are TRUE */
#define CLKMTST_TEST_PLLERAY_CLOCK     (TRUE)
#define CLKMTST_TEST_ADC_CLOCK         (TRUE)
#endif /* #ifdef STEP */
#endif /* #if (CHIP_ID == 27U)*/

/* Available clock monitors in TC26x */
#if (CHIP_ID == 26U)
#define CLKMTST_TEST_PLLERAY_CLOCK     (TRUE)
#define CLKMTST_TEST_ADC_CLOCK         (FALSE)
#endif

/* Available clock monitors in TC29x */
#if (CHIP_ID == 29U)
#define CLKMTST_TEST_PLLERAY_CLOCK     (TRUE)
#define CLKMTST_TEST_ADC_CLOCK         (FALSE)
#endif

/* Available clock monitors in TC23x */
#if (CHIP_ID == 23U)
#define CLKMTST_TEST_PLLERAY_CLOCK     (TRUE)
#define CLKMTST_TEST_ADC_CLOCK         (FALSE)
#endif

/* Available clock monitors in TC22x */
#if (CHIP_ID == 22U)
#define CLKMTST_TEST_PLLERAY_CLOCK     (FALSE)
#define CLKMTST_TEST_ADC_CLOCK         (FALSE)
#endif

/* Available clock monitors in TC21x */
#if (CHIP_ID == 21U)
#define CLKMTST_TEST_PLLERAY_CLOCK     (FALSE)
#define CLKMTST_TEST_ADC_CLOCK         (FALSE)
#endif

/* Available clock monitors in TC24x */
#if (CHIP_ID == 24U)
#define CLKMTST_TEST_PLLERAY_CLOCK     (TRUE)
#define CLKMTST_TEST_ADC_CLOCK         (TRUE)
#endif

#if (CHIP_ID == 27U)
#define CLKM_TC27X_CA_STEP ((uint8)(0x20U))
#define CLKM_TC27X_DB_STEP ((uint8)(0x31U))
#define CLKM_TC27X_BC_STEP ((uint8)(0x13U)) 
#endif

#if (CHIP_ID == 26U)
#define CLKM_TC26X_BB_STEP ((uint8)(0x11U))
#endif

#if (CHIP_ID == 29U)
#define CLKM_TC29X_BB_STEP ((uint8)(0x11U))
#endif

#if ((CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U))
#define CLKM_EPDEVICES_AB_STEP ((uint8)(0x01U))
#endif

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/* Configuration type for CCUCONx register configuration */
typedef uint32 ClkmTst_CCUCONType;
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Sl_TstRsltType ClkmTst_ClkmTst                          **
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
** Return value     : CLKM_SUCCESS - Test successed                           **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : API provided for the clock monitor test.                **
**                    It is responsible for test preparation, test execution  **
**                    and final test restoration.                             **
**                                                                            **
*******************************************************************************/
#define IFX_CLKM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
extern Sl_TstRsltType ClkmTst_ClkmTst
(
    const Sl_ParamSetType ParamSetIndex,
    const uint8 TstSeed,
    uint32* const TstSignature
);
#define IFX_CLKM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/
#endif /* CLKTST_H */

