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
**   $FILENAME   : SafeWdgM.h $                                               **
**                                                                            **
**   $CC VERSION : \main\18 $                                                 **
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
**  TRACEABILITY:                                                             **
**  DESCRIPTION  : This file contains                                         **
**                 - Declarations for TstHandler driver.                      **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/


#ifndef SAFEWDGM_H
#define SAFEWDGM_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "SafeWdgIf.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

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

extern void SafeWdgM_Init(uint8 ConfigIdx);
extern void SafeWdgM_DeInit(void);
extern void SafeWdgM_GetSeed(uint8* TstSeed);
extern void SafeWdgM_Activate(void);
extern void SafeWdgM_Service(void);
extern SafeWdgIf_StateType  SafeWdgM_GetState(void);
#ifndef SWDG_INT_WDG_ONLY
extern void SafeWdgM_UserRequest(SafeWdgIf_CmdType* UserCmd, uint8 size);
extern SafeWdgIf_ResultType SafeWdgM_GetJobResult(void);
extern void SafeWdgM_GetErrCntr(uint8* const ErrCtr);
extern void SafeWdgM_GetWdgInfo(void);
#endif

#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/* Checksum protected Post-Run Delta Table */
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/


/* Checksum protected Pre-Run Delta Table  */

/* Checksum protected Post-Run Delta Table */


#endif
