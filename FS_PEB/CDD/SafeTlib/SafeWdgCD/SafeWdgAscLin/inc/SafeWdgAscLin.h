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
**   $FILENAME   : SafeWdgAscLin.h $                                          **
**                                                                            **
**   $CC VERSION : \main\23 $                                                 **
**                                                                            **
**   $DATE       : 2015-08-03 $                                               **
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
**                 - Declarations for SafeWdgAscLin driver.                   **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


#ifndef SAFEWDGASCLIN_H
#define SAFEWDGASCLIN_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "SafeWdgAscLin_Cfg.h"
#include "SafeWdgIf.h"
#include "IfxPort_reg.h"
#include "IfxAsclin_reg.h"



/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/* Type definitions to configure/control interrupt for selected TOM channel */
typedef void    (*SafeWdgAscLin_EnIfdTmrChOSM)  (void);
typedef void    (*SafeWdgAscLin_DisIfdTmrChOSM) (void);

/* configuration container for ASCLIN device */
typedef struct SafeWdgAscLin_ConfigType
{
    /* ASCLIN selection */
    /* selected ASCLIN module (0-3) */
    volatile Ifx_ASCLIN*            AscLinModule;      
     /* DMA channel used for transmit */
    uint8                           DmaTxChannel;
    /* Baudrate configuration */
    
    /* oversampling (4-16) */
    uint8                           BConOversample;
    /* bit sampling point within oversampling range */
    uint8                           BConSamplePoint;
    /* prescaler value (0-4095) */
    uint16                          BConPreScaler;
    /* baudrate denomintor (0-4095)*/
    uint16                          BrgDenominator;
    /* baudrate numerator (0-4095) */
    uint16                          BrgNumerator;

    /* Frame configuration */
    /* idle cycles between two transmissions  (0-7) */
    uint8                           FConIdleCnt;
    /* trail cycles after transmission (0-7) */
    uint8                           FConTrailCnt;
    /* leading cycles before transmission (0-7) */
    uint8                           FConLeadCnt;
    /* MSB first (0: no, 1: yes) */
    uint8                           FConMsb;

    /* IOCR configuration */
    /* slave CS polarity (0: high active, 1: low active) */
    uint8                           CsPolarity;
    /* receiver port input selector */
    uint8                           RxInputSelect;

    /* Function configuration */
    
    /* Function to enable TOM Channel */
    SafeWdgAscLin_EnIfdTmrChOSM     EnableTOMChOSMFunc;
    /* Function to disable TOM Channel */
    SafeWdgAscLin_DisIfdTmrChOSM    DisableTOMChFunc;
  
} SafeWdgAscLin_ConfigType;



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

extern SafeWdgIf_ResultType SafeWdgAscLin_Init
( 
  const SafeWdgAscLin_ConfigType* const ConfigPtr
);

extern void                 SafeWdgAscLin_DeInit
(
  void
);

extern void                 SafeWdgAscLin_TxRx
(
  uint16* TxBuf, 
  uint16* RxBuf, 
  uint8 Count
);

extern boolean              SafeWdgAscLin_RxDone
(
  uint32* Error
);

#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                   Imported Post-Build Data from Configuration files        **
*******************************************************************************/
#define IFX_SWDG_START_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

extern const SafeWdgAscLin_ConfigType  
                              SafeWdgAscLin_ConfigRoot[SAFEWDGASCLIN_CFG_COUNT];

#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

#endif

