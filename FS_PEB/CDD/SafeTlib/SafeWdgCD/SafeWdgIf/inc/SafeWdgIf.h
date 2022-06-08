/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : SafeWdgIf.h $                                              **
**                                                                            **
**   $CC VERSION : \main\28 $                                                 **
**                                                                            **
**   $DATE       : 2016-03-04 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**  DESCRIPTION  : This file contains                                         **
**                 - Declarations for SafeWdgIf driver.                       **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


#ifndef SAFEWDGIF_H
#define SAFEWDGIF_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "SafeWdgIf_Cfg.h"
#include "SafeWdgExtCic.h"
#include "SafeWdgAscLin.h"
#include "SafeWdgExtTlf.h"
#include "SafeWdgQspi.h"
#include "SafeWdgInt.h"
/*******************************************************************************
**                      Typedefs                                          **
*******************************************************************************/



#define SWDG_JOB_ACCEPTED          (0x3U)
#define SWDG_JOB_FAILED            (0x7U)
#define SWDG_JOB_FAILED_CRC        (0x8U)
#define SWDG_JOB_INV_PARAM         (0x9U)
#define SWDG_JOB_COM_ERR           (0xAU)
#define SWDG_JOB_BUSY              (0xBU)
#define SWDG_JOB_INV_STATE         (0xCU)
#define SWDG_JOB_READBACK_FAIL     (0xDU) 
#define SWDG_JOB_INIT_FAIL         (0xEU)
#define SWDG_JOB_RD_DATA_FAIL      (0xFU)
#define SWDG_JOB_RX_ERR_FAIL       (0x10U)
#define SWDG_JOB_FAILED_SERVICE    (0x11U)
#define SWDG_JOB_INVALID_SEED      (0x12U)
#define SWDG_JOB_SUCCESS           (0xFFU)


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

extern SafeWdgIf_ResultType      SafeWdgIf_Init
( 
   const SafeWdgIf_ConfigType* const ConfigPtr
);

extern SafeWdgIf_ResultType      SafeWdgIf_DeInit
(
   void
);

extern SafeWdgIf_ResultType      SafeWdgIf_Activate
(
   void
);

extern SafeWdgIf_ResultType      SafeWdgIf_Service
(
   const uint32 Signature
);

extern SafeWdgIf_ResultType      SafeWdgIf_GetSeed
(
   uint8* const NextSeedPtr
);

extern SafeWdgIf_StateType       SafeWdgIf_GetState
(
   void
);

/* These APIs are required only if external watchdog is used */
extern SafeWdgIf_ResultType      SafeWdgIf_UserRequest    
(
   SafeWdgIf_CmdType* const UserCmdPtr, 
   uint8 Count
);

extern SafeWdgIf_ResultType      SafeWdgIf_GetJobResult   
(
   void
);

extern SafeWdgIf_ResultType      SafeWdgIf_GetErrCntr     
(
   uint8* const ErrCtrPtr
);

extern SafeWdgIf_ResultType      SafeWdgIf_GetWdgInfo     
(
   void
);


#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"


/*******************************************************************************
**                   Exported global configuration data                       **
*******************************************************************************/
#define IFX_SWDG_START_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

extern const SafeWdgIf_ConfigType SafeWdgIf_ConfigRoot[SAFEWDGIF_CFG_COUNT];

#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

#endif

