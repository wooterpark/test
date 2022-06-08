/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Fls_17_Pmu_Local.h $                                       **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2017-12-01 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file exports funtionality of Flash driver            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
   Traceability:
******************************************************************************/

#ifndef FLS_17_PMU_LOCAL_H
#define FLS_17_PMU_LOCAL_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

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

#define FLS_17_PMU_START_SEC_CODE
#include "MemMap.h"

extern IFX_INLINE void Fls_lDemReportError_Erase(void);
extern IFX_INLINE void Fls_lDemReportError_Read(void);
extern IFX_INLINE void Fls_lDemReportError_Write(void);
extern IFX_INLINE void Fls_lDemReportError_Compare(void);
extern IFX_INLINE void Fls_lDemReportError_SpndResme(void);
extern IFX_INLINE void Fls_lDemReportError_VerifyErase(void);
extern IFX_INLINE void Fls_lSchMEnter_Init(void);
extern IFX_INLINE void Fls_lSchMExit_Init(void);

extern IFX_INLINE void Fls_lSchMEnter_Erase(void);
extern IFX_INLINE void Fls_lSchMExit_Erase(void);

extern IFX_INLINE void Fls_lSchMEnter_Write(void);
extern IFX_INLINE void Fls_lSchMExit_Write(void);

extern IFX_INLINE void Fls_lSchMEnter_ResumeErase(void);
extern IFX_INLINE void Fls_lSchMExit_ResumeErase(void);

extern IFX_INLINE void Fls_lSchMEnter_Main(void);
extern IFX_INLINE void Fls_lSchMExit_Main(void);

extern IFX_INLINE MemIf_ModeType Fls_lSetDefaultMode(void);

#define FLS_17_PMU_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif /* #ifndef FLS_17_PMU_LOCAL_H */

