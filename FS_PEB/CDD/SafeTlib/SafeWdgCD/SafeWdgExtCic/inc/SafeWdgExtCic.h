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
**   $FILENAME   : SafeWdgExtCic.h $                                          **
**                                                                            **
**   $CC VERSION : \main\19 $                                                 **
**                                                                            **
**   $DATE       : 2016-02-23 $                                               **
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
**                 - Declarations for SafeWdgExtCic driver.                   **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


#ifndef SAFEWDGEXTCIC_H
#define SAFEWDGEXTCIC_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "Mcal.h"
#include "SafeWdgIf_Types.h"
#include "SafeWdgExtCic_Cfg.h"
#include "SafeWdgAscLin.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Typedefs                                          **
*******************************************************************************/


/* configuration container for seed/signature pairs for CIC61508 watchdog */
/* one element of the table */
typedef struct SafeWdgExtCic_SignaturesType
{
    uint32  XorResponse;        /* Xor mask to generate watchdog answer */
    uint32  ExptdTstSig;        /* expected signature from tests to be used for 
                                   watchdog service */
} SafeWdgExtCic_SignaturesType;

/* seed/signature table */
typedef struct SafeWdgExtCic_SignatureListType
{
    SafeWdgExtCic_SignaturesType SigPair[SAFEWDG_MAXNBR_SEED];
} SafeWdgExtCic_SignatureListType;


/* configuration container for external watchdog */
typedef struct SafeWdgExtCic_ConfigType
{
  /* config ptr ASCLIN */
  const SafeWdgAscLin_ConfigType*  AscLinCfgPtr;    

  /* seed / signature table */
  SafeWdgExtCic_SignatureListType  SwdtSignTable;
  
} SafeWdgExtCic_ConfigType;



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

extern SafeWdgIf_ResultType     SafeWdgExtCic_Init
(
  const SafeWdgExtCic_ConfigType* const ConfigPtr
);

extern SafeWdgIf_ResultType     SafeWdgExtCic_DeInit
(
  void
);

extern SafeWdgIf_ResultType     SafeWdgExtCic_Activate
(
  void
);

extern SafeWdgIf_ResultType     SafeWdgExtCic_Service
(
  const uint32 Signature
);

extern SafeWdgIf_ResultType     SafeWdgExtCic_GetSeed
(
  uint8* const NextSeedPtr
);

extern SafeWdgExt_StateType    SafeWdgExtCic_GetState
(
  void
);

extern SafeWdgIf_ResultType     SafeWdgExtCic_UserRequest
(
  SafeWdgIf_CmdType* const UserCmdPtr, 
  uint8 Count
);

extern SafeWdgIf_ResultType     SafeWdgExtCic_GetJobResult
(
  void
);

extern SafeWdgIf_ResultType     SafeWdgExtCic_GetErrCntr
(
  uint8* const ErrCtrPtr
);

extern SafeWdgIf_ResultType     SafeWdgExtCic_GetWdgInfo 
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

extern const SafeWdgExtCic_ConfigType
                              SafeWdgExtCic_ConfigRoot[SAFEWDGEXTCIC_CFG_COUNT];

#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"
                              
#endif

