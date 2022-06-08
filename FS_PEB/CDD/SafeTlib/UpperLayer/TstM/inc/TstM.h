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
**   $FILENAME   : TstM.h $                                                   **
**                                                                            **
**   $CC VERSION : \main\20 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - Declarations for Test Manager.                           **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

#ifndef _TSTM_H
#define _TSTM_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "AppCbk.h"
#include "TstHandler.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Ignore early prerun and prerun signature validation */
#define SL_IGNORE_SIGNATUREVALIDATE (FALSE)
/* Configuration switch to enable or disable runtime tests */
#define SL_RUNTIME_TESTS            (TRUE)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
extern void TstM_Init(void);

extern void TstM_EarlyPreRunTst(void);

extern void TstM_PreRunTst(uint8 GroupStartIndex, uint8 GroupEndIndex);

extern void TstM_CheckPreRunTestResult(void);

#if(SL_RUNTIME_TESTS == TRUE) 
extern void TstM_Run(void);

extern void TstM_PostRun(void);
#endif

extern uint32 TstM_GetConsolidatedSignature(void);

extern void TstM_InvalidateData(void);

#if (SAFETLIB_APPLN_DEBUG == TRUE) 
extern Sl_TstRsltType TstM_GetTstResult(Sl_TstIndexType TstIdx);
#endif
#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif
