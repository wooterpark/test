#ifndef IOMTST_H
#define IOMTST_H
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
**  $FILENAME   : IomTst.h $                                                 **
**                                                                            **
**  $CC VERSION : \main\13 $                                                 **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
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
**                 IOM Input/Output monitor test.                             **
**                                                                            **
**  REFERENCE(S) : Aurix_SafeTlib_DS_Iom_Test.docm                            **
**                                                                            **
*  MAY BE CHANGED BY USER : no                                                **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "IomTst_Cfg.h"
#include "Platform_Types.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"
#include "Mcal_Compiler.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/
/* IomTst module configuration type - post-build configuration */
typedef struct IomTst_ConfigType
{
  uint8 IomFpcMonBlockIndex;
  uint8 IomFpcMonPortIndex;
  uint8 IomFpcMonPortCtrlRegIndex;
  uint8 IomFpcMonPortCtrlBitsOff;
  uint8 IomLamBlockIndex[IOMTST_LAM_BLOCKS_TO_TEST];
  /* Dummy variable to ensure even address alignment */
  uint32 Reserved;
}IomTst_ConfigType;

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#define IFX_IOMTST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
extern const IomTst_ConfigType IomTst_ConfigRoot[IOMTST_CFG_PARAM_COUNT];
#define IFX_IOMTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
#define IFX_IOMTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Sl_TstRsltType IomTst_IomTst                            **
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
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : ParamSetIndex - Identifies the parameter set to be      **
**                      used for test execution.                              **
**                    TstSeed - Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : IOMTST_SUCCESS - Test succeeded                         **
**                    IOMTST_NOTEXECUTED - This error is never intentionally  **
**                      returned; if it is returned anyway, something         **
**                      very serious must be wrong                            **
**                    IOMTST_INVPARAM - Invalid parameter is sent as an       **
**                      paramter to API                                       **
**                    IOMTST_ALARMNOTSETERR - Test failed as an expected      **
**                      alarm has not occured.                                **
**                    IOMTST_SMU_STATEERR - Test initialization failed due to **
**                      an invalid run state of the SMU                       **
**                    IOMTST_SMU_ALMSTSERR - Test failed due to a SMU alarm   **
**                      which is expected to be set is already set            **
**                    IOMTST_SMU_GETALMSTSERR - Test failed because           **
**                      Smu_GetAlarmStatus returned an error                  **
**                    IOMTST_SMU_CLRALMSTSERR - Test restoration failed due to**
**                       Smu_ClearAlarmStatus returning an error              **
**                    IOMTST_SMU_GETALMACTIONERR - Test failed because        **
**                      Smu_GetAlarmAction returned an error                  **
**                    IOMTST_SMU_SETALMACTIONERR - Test failed due to         **
**                      Smu_SetAlarmAction returning an error                 **
**                                                                            **
** Description      : IomTst_IomTst is the API which is responsible for IOM   **
**                    test preparation execution and restoration. It considers**
**                    a signal(Monitor signal) for monitoring.                **
**                    For any edge on this signal, an alarm (ALM2[26] is      **
**                    expected.. Alarm occurrence is validated for all the    **
**                    configured LAM blocks.                                  **
*******************************************************************************/
extern Sl_TstRsltType IomTst_IomTst (const Sl_ParamSetType ParamSetIndex,
                                     const uint8 TstSeed,
                                     uint32* const TstSignature);
#define IFX_IOMTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* IOMTST_H */

