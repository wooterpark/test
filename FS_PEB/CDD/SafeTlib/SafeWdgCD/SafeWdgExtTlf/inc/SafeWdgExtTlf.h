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
**   $FILENAME   : SafeWdgExtTlf.h $                                          **
**                                                                            **
**   $CC VERSION : \main\20 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
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
**                 - Declarations for SafeWdgExtTlf driver.                   **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

#ifndef SAFEWDGEXTTLF_H
#define SAFEWDGEXTTLF_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
#include "IfxPort_reg.h"
#include "SafeWdgIf.h"
#include "SafeWdgExtTlf_Cfg.h"
#include "SafeWdgQspi.h"
#include "SafeWdgAscLin.h"
#include "SafeWdgExtCic.h"
#include "SafeWdgInt.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/* Operation mode of window watchdog: */
typedef enum
{
  TLF_WM_FWD,         /* Use functional watchdog */
  TLF_WM_FWD_WWD_SPI, /* Use functional watchdog & window watchdog with SPI 
                      trig */
  TLF_WM_WWD_WDI,     /* Use window watchdog with triggering via WDI pin */
  TLF_WM_WWD_SPI     /* Use window watchdog with SPI triggering*/
} SafeWdgExtTlf_WdgModeType;

/* Configuration container for external watchdog */
typedef struct SafeWdgExtTlf_ConfigType
{
  /* Config ptr to QSPI: */
  const SafeWdgQspi_ChannelConfigType*   QspiCfgPtr;

  /* Window watchdog operation mode (disabled/WDI triggering/SPI trig.): */
  SafeWdgExtTlf_WdgModeType             WatchdogMode;

  uint8                                 HeartbeatBase;

  uint8                                 OpenWindowHeartbeat;

  uint8                                 CloseWindowHeartbeat;
  
  uint8                                 FwdHeartbeat;

  /* Window Watchdog error threshold: */
  uint8                                 WWDWdgErrorThreshold;
  /* Functional Watchdog error threshold: */
  uint8                                 FWDWdgErrorThreshold;
  
  volatile Ifx_P*                       WdiPort; /* Pointer to WDI GPIO port */
  uint8                                 WdiPin; /* WDI port pin index (0..15) */
  /* Signature XOR table: */
  uint32                                XorResponse[SAFEWDG_MAXNBR_SEED];
} SafeWdgExtTlf_ConfigType;


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
extern SafeWdgIf_ResultType SafeWdgExtTlf_Init
(
  const SafeWdgExtTlf_ConfigType* const ConfigPtr
);

extern SafeWdgIf_ResultType SafeWdgExtTlf_DeInit
(
  void
);

extern SafeWdgIf_ResultType SafeWdgExtTlf_Activate
(
  void
);

extern SafeWdgIf_ResultType SafeWdgExtTlf_Service
(
   const uint32 Signature
);

extern SafeWdgIf_ResultType SafeWdgExtTlf_GetSeed
(
  uint8* const NextSeedPtr
);

extern SafeWdgExt_StateType SafeWdgExtTlf_GetState
(
  void
);

extern SafeWdgIf_ResultType SafeWdgExtTlf_GetErrCntr
(
  uint8* const ErrCtrPtr
);

extern SafeWdgIf_ResultType SafeWdgExtTlf_GetJobResult
(
  void
);

extern SafeWdgIf_ResultType SafeWdgExtTlf_UserRequest
(
  SafeWdgIf_CmdType* const UserCmdPtr,
  const uint8 Count
);

extern void SafeWdgExtTlf_MainFunction
(
  void 
);


extern SafeWdgIf_ResultType SafeWdgExtTlf_GetWdgInfo 
(
  void
);
#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                   Imported Post-Build Data from Configuration files        **
*******************************************************************************/

extern const SafeWdgExtTlf_ConfigType        
                      SafeWdgExtTlf_ConfigRoot[SAFEWDGEXTTLF_CFG_PARAM_COUNT];


#endif /* SAFEWDGEXTTLF_H */
