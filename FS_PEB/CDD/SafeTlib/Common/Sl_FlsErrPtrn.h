#ifndef SL_FLS_ERR_PTRN_H
#define SL_FLS_ERR_PTRN_H

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
**                                                                            **
**   $FILENAME   : Sl_FlsErrPtrn.h $                                          **
**                                                                            **
**   $CC VERSION : \main\8 $                                                  **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
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
** Description      : This file contains                                      **
**                 - Support routines for programming erroneous FLASH pages   **
**                   to be used for the PMU EDC ECC test.                     **
**                                                                            **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h  */
#include "Std_Types.h"

/* Inclusion of PMU ECC EDC test header: */
#include "PmuEccEdcTst.h"

/* Inclusion of PFlash Monitor test header: */
#include "PflashMonTst.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/*******************************************************************************
** Aurix internal timeout values                                              **
*******************************************************************************/

/* Timeout when waiting for the FLASH to enter page mode.
 * Typically the page mode is entered within very less numbers of cycles.
 * The below value represents a loop counter, usually two loop iterations taking
 * already enough cycles to enter page mode.
 * With a given safe margin of 5, the timeout shall not be lower than 10u.
 */
#define SLFLS_PAGE_MODE_TIMEOUT         ( 10U )

/* Flash programming result values: */
#define SL_PROG_FAIL_PF0                ( (Sl_FlsPrgRsltType)0x00U )
#define SL_PROG_FAIL_PF1                ( (Sl_FlsPrgRsltType)0x01U )
#define SL_PROG_FAIL_PF2                ( (Sl_FlsPrgRsltType)0x02U )
#define SL_PROG_FAIL_PF3                ( (Sl_FlsPrgRsltType)0x03U )
#define SL_CHECK_FAIL_PF0               ( (Sl_FlsPrgRsltType)0x04U )
#define SL_CHECK_FAIL_PF1               ( (Sl_FlsPrgRsltType)0x05U )
#define SL_CHECK_FAIL_PF2               ( (Sl_FlsPrgRsltType)0x06U )
#define SL_CHECK_FAIL_PF3               ( (Sl_FlsPrgRsltType)0x07U )
#define SL_CORRUPTION_ERR               ( (Sl_FlsPrgRsltType)0x08U )
#define SL_PROG_DONE                    ( (Sl_FlsPrgRsltType)0xFFU )


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/* Flash programming result type: */
typedef uint32  Sl_FlsPrgRsltType;


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define IFX_PMU_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
extern Sl_FlsPrgRsltType Sl_ChkProgErrorPattern
(
  void
);
#define IFX_PMU_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif /* SL_FLS_ERR_PTRN_H */
