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
**   $FILENAME   : SafeWdgExtCic_MF.h $                                       **
**                                                                            **
**   $CC VERSION : \main\6 $                                                  **
**                                                                            **
**   $DATE       : 2015-08-03 $                                               **
**                                                                            **
**  VARIANT      : VariantPB                                                  **
**                                                                            **
**  PLATFORM     : Infineon AURIX                                             **
**                                                                            **
**  AUTHOR       : SafeTlib Team                                              **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  TRACEABILITY:                                                             **
**  DESCRIPTION  : This file contains                                         **
**                 - Declarations for SafeWdgExtCic driver.                   **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


#ifndef SAFEWDGEXTCIC_MF_H
#define SAFEWDGEXTCIC_MF_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/*******************************************************************************
**                      Enumerations                                          **
*******************************************************************************/


/*******************************************************************************
**                   Structure Definitions                                    **
*******************************************************************************/


/*******************************************************************************
**                   Exported Functions                                       **
*******************************************************************************/
#define IFX_SWDG_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

extern void  SafeWdgExtCic_MainFunction   
(
  void
);

#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**            Imported Post-Build Data from Configuration files               **
*******************************************************************************/
#endif

