/*******************************************************************************
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**  $FILENAME   : SafeWdgExt_Config.h $                                      **
**                                                                            **
**  $CC VERSION : \main\8 $                                                  **
**                                                                            **
**  $DATE       : 2016-01-14 $                                               **
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
**                 - Functionality for extlernal watchdog specific functions  **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

#ifndef SAFEWDGEXT_CONFIG_H
#define SAFEWDGEXT_CONFIG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SafeWdgIf.h"

#if (defined SWDG_EXT_TLF_WDG_ONLY) || \
    (defined SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
 #include "IfxQspi_reg.h"
 #include "SafeWdgQspi.h"
 #include "SafeWdgExtTlf_UcHandler.h"
 #include "Compiler_Cfg.h"
 #include "IfxStm_reg.h"
 #include "IfxScu_reg.h"
 #include "IfxCpu_reg.h"
 #include "IfxSrc_reg.h"
#endif

/*******************************************************************************
**                      Global Macro Definitions                              **
********************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
********************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
********************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
********************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
********************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#ifdef SWDG_EXT_CIC_WDG_ONLY /*CIC specific fucntions*/
  extern void    SafeWdgExt_Config_Timer           (void);
#endif

/*Fucntions common to both TLF & CIC*/
#ifndef SWDG_INT_WDG_ONLY 
extern void    SafeWdgExt_Config_DMA             (void);
extern void    SafeWdgExt_Config_Port            (void);
extern void    SafeWdgExt_Config_Irq             (void);
#endif

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* SAFEWDGEXT_CONFIG_H */


