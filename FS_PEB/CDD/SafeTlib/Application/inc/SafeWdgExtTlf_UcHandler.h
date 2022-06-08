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
**   $FILENAME   : SafeWdgExtTlf_UcHandler.h $                                **
**                                                                            **
**   $CC VERSION : \main\1 $                                                  **
**                                                                            **
**   $DATE       : 2016-01-14 $                                               **
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
**                 - Declarations for the TLF35584 use case handler           **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

#ifndef SAFEWDGEXTTLF_UCHANDLER_H
#define SAFEWDGEXTTLF_UCHANDLER_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "SafeWdgIf.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#if defined (SWDG_EXT_TLF_WDG_ONLY) || \
    defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)

/* Temporal sequencer test is enabled */
#define SWDG_EXT_TLF_SEQTEST_ENABLED        (TRUE)

/* Configure to execute state check for TLF */
#define SWDG_EXT_TLF_STATE_CHECK_ENABLED    (TRUE)

#endif /* defined (SWDG_EXT_TLF_WDG_ONLY) || \
          defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG) */

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

#if defined (SWDG_EXT_TLF_WDG_ONLY) || \
    defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)

extern void     SafeWdgExtTlf_UcHandler_GetTlfInfo(void);
extern void     SafeWdgExtTlf_UcHandler_SetTlfInfo(void);

#if (SWDG_EXT_TLF_SEQTEST_ENABLED == TRUE)
extern void     SafeWdgExtTlf_UcHandler_TempSeqTest(void);
#endif /* (SWDG_EXT_TLF_SEQTEST_ENABLED == TRUE) */

#if (SWDG_EXT_TLF_STATE_CHECK_ENABLED == TRUE)
extern boolean  SafeWdgExtTlf_UcHandler_Abist(void);

extern boolean  SafeWdgExtTlf_UcHandler_ErrInject(boolean DoErrInject,
                                                  boolean* WdgServiceReq);
#endif /* (SWDG_EXT_TLF_STATE_CHECK_ENABLED == TRUE) */

#endif /* defined (SWDG_EXT_TLF_WDG_ONLY) || \
          defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG) */

#endif /* SAFEWDGEXTTLF_UCHANDLER_H */
