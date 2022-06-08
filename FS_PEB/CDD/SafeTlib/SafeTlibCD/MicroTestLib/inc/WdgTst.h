#ifndef STL_WDG_H_INCLUDED
#define STL_WDG_H_INCLUDED

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
**   $FILENAME   : WdgTst.h $                                                 **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   $DATE       : 2016-11-23 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains watchdog latent fault metric tests      **
**                                                                            **
**  REFERENCE(S) :                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Platform_Types.h"
#include "Compiler_Cfg.h"
#include "Sl_ErrorCodes.h"
#include "WdgTst_Cfg.h"
#include "Mcal_Compiler.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* 
Watchdog no overflow timeout count:
This macro defines the number of loop cycles to wait for a watchdog timeout 
event. During this test the watchdog’s input frequency is set to fSPB / 64 and 
the watchdogs reload value is set to 0xFFF6,  so that a timer overflow will 
happen after a short time.
The current maximum loop count measured has been found to be in the range of 
120 to 128 loop iterations. Based on worst case assumptions and given a safe 
timeout margin of factor five, the herein used value for this watchdog timeout 
has been set to 1024.
*/
#define WDG_NO_OVERFLOW_TIMEOUT          (0x400U)


/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/
/* WdgTst module configuration type - LinkTime configuration                 */
typedef struct WdgTst_ConfigType
{
  boolean WdgTstPflowMonEn;
  uint32 Reserved; 
} WdgTst_ConfigType;

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

#define IFX_WDG_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

/* Exported WdgTst configuration:                                            */
extern const WdgTst_ConfigType WdgTstCpu_ConfigRoot[WDGCPU_TST_CFG_PARAM_COUNT];
extern const WdgTst_ConfigType WdgTstSafety_ConfigRoot[WDGCPU_TST_CFG_PARAM_COUNT];

#define IFX_WDG_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define IFX_WDG_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

extern Sl_TstRsltType       WdgTst_WdgCpuTst(const Sl_ParamSetType ParamSetIndex,
                                            const uint8 TstSeed,
                                            uint32* const TstSignature);

extern Sl_TstRsltType       WdgTst_WdgSafetyTst(const Sl_ParamSetType ParamSetIndex,
                                                  const uint8 TstSeed,
                                                  uint32* const TstSignature);
#define IFX_WDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/


#endif /* STL_SRI_H_INCLUDED */


