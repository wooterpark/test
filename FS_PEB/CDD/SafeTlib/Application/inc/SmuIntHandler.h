#ifndef SMU_INT_HANDLER_H
#define SMU_INT_HANDLER_H
/*******************************************************************************
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**  $FILENAME   : SmuIntHandler.h $                                          **
**                                                                            **
**  $CC VERSION : \main\8 $                                                  **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of SMU interrupt handling                  **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Mcal_Compiler.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/\
#define SMU_INT_SERVICE_FALSE  ((uint32)(0U))
#define SMU_INT_SERVICE_TRUE   ((uint32)(1U))

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#define IFX_APPL_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
extern volatile uint32 SmuInt0Service;
extern volatile uint32 SmuInt1Service;
extern volatile uint32 SmuInt2Service;
#define IFX_APPL_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
extern void SMU_Setupinterrupt(void);
#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif /* SMU_INT_HANDLER_H */