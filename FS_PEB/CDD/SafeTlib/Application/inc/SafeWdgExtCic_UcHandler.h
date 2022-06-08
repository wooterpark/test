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
**   $FILENAME   : SafeWdgExtCic_UcHandler.h $                                **
**                                                                            **
**   $CC VERSION : \main\5 $                                                  **
**                                                                            **
**   $DATE       : 2016-02-25 $                                               **
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

#ifndef SAFEWDGEXTCIC_UCHANDLER_H
#define SAFEWDGEXTCIC_UCHANDLER_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "SafeWdgIf.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#ifdef SWDG_EXT_CIC_WDG_ONLY
/* Size of the array */
#define UR_ARRAY_SIZE                       ( 0x4U )
#define WDGH_CIC_SERVICE_COUNT              ( 20u  )

/* Temporal sequencer test is enabled */
#define SWDG_EXT_CIC_SEQTEST_ENABLED

#endif
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




#ifdef SWDG_EXT_CIC_WDG_ONLY

extern SafeWdgIf_ResultType    SafeWdgExtCic_UcHandler_VerifyCICStates (void);
extern void                    SafeWdgExtCic_UcHandler_TempSeqTest     (void);
extern void                    SafeWdgExtCic_UcHandler_URInit1         (void);
extern void                    SafeWdgExtCic_UcHandler_URInit2         (void);
extern void                    SafeWdgExtCic_UcHandler_URRun1          (void);
extern void                    SafeWdgExtCic_UcHandler_URRun2          (void);
extern void                    SafeWdgExtCic_UcHandler_UREntSecCmd1    (void);
extern void                    SafeWdgExtCic_UcHandler_UREntSecCmd2    (void);
extern void                    SafeWdgExtCic_UcHandler_ReadInSecSpi1   (void);
extern void                    SafeWdgExtCic_UcHandler_ReadInSecSpi2   (void);
extern void                    SafeWdgExtCic_UcHandler_URSecSpiExit    (void);
#endif /*  #ifdef SWDG_EXT_CIC_WDG_ONLY  */



#endif /* SAFEWDGEXTCIC_UCHANDLER_H */
