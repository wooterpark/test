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
**   $FILENAME   : SafeWdgInt.h $                                             **
**                                                                            **
**   $CC VERSION : \main\15 $                                                 **
**                                                                            **
**   $DATE       : 2016-02-22 $                                               **
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
**                 - Declarations for SafeWdgInt driver.                      **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


#ifndef SAFEWDGINT_H
#define SAFEWDGINT_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "Mcal.h"
#include "SafeWdgIf_Types.h"
#include "SafeWdgInt_Cfg.h"

/*******************************************************************************
**                      Typedefs                                          **
*******************************************************************************/

/* configuration container for seed/signature pairs for internal watchdog */
/* one element of the table */
typedef struct SafeWdgInt_SignaturesType
{
    /* password value for internal watchdog */
    uint32  BaseValue;                      
    /* expected signature to be used for watchdog service */
    uint32  ExptdTstSig;                    
} SafeWdgInt_SignaturesType;

/* seed/signature table */
typedef struct SafeWdgInt_SignatureListType
{
    SafeWdgInt_SignaturesType SigPair[SAFEWDG_MAXNBR_SEED];
} SafeWdgInt_SignatureListType;


/* configuration container for internal watchdog */
typedef struct SafeWdgInt_ConfigType
{
    /* input frequency selector for slow service interval */
    uint8   SwdtInputFreq;              
    /* timer reload value for slow service interval */
    uint16  SwdtTimerReload;      
    /* signature table */    
    SafeWdgInt_SignatureListType  SwdtSignTable;
} SafeWdgInt_ConfigType;



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

extern SafeWdgIf_ResultType       SafeWdgInt_Init         
(
  const SafeWdgInt_ConfigType* const ConfigPtr
);
extern void                 SafeWdgInt_DeInit       
(
  void
);
extern SafeWdgIf_ResultType       SafeWdgInt_Activate     
(
  void
);
extern SafeWdgIf_ResultType       SafeWdgInt_Service      
(
  const uint32 Signature
);
extern SafeWdgIf_ResultType       SafeWdgInt_GetSeed      
(
  uint8* const NextSeedPtr
 );
extern SafeWdgInt_StateType  SafeWdgInt_GetState     
(
  void
);

#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                   Imported Post-Build Data from Configuration files        **
*******************************************************************************/
#define IFX_SWDG_START_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

extern const SafeWdgInt_ConfigType  SafeWdgInt_ConfigRoot[SAFEWDGINT_CFG_COUNT];

#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

#endif

