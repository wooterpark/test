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
**   $FILENAME   : SafeWdgQspi.h $                                            **
**                                                                            **
**   $CC VERSION : \main\19 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
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
**                 - Declarations for SafeWdgQspi driver.                     **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

#ifndef SAFEWDGQSPI_H
#define SAFEWDGQSPI_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "SafeWdgIf.h"
#include "IfxSrc_reg.h"
#include "SafeWdgQspi_Cfg.h"

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/
/* Type definition for QSPI notification function pointer for customer TxRx*/
typedef void (*SafeWdgQspi_UserCallbackFuncType)(void);

/* configuration container for QSPI Module  */
typedef struct SafeWdgQspi_ModuleConfigType
{
    /* Selected QSPI module (0-3): */
    volatile Ifx_QSPI*        QspiModule;
    /*Service request register for Tx & Rx Interrupts*/
    volatile Ifx_SRC_SRCR*    SrcTxRegister;
    volatile Ifx_SRC_SRCR*    SrcRxRegister;
    uint8           TxDmaChannel;
    uint8           RxDmaChannel;
    uint8           RcvInputSel;
    uint8           ModTimeQuantum;/* Global time quantum length(GLOBALCON.TQ)*/
  
    SafeWdgQspi_UserCallbackFuncType UserFunc;

}SafeWdgQspi_ModuleConfigType;


/* configuration container for QSPI channel */
typedef struct SafeWdgQspi_ChannelConfigType
{
    uint32          Channel;    /* Channel selection (0..15) */

    uint8           SlsoActiveLevel;  /* SLSO active level, 0 = low, 1 = high */
  /* Baud rate settings*/
    uint8           ChTimeQuantum;  /* Channel time quantum (ECONz.Q, 0..31) */
    uint8           BitSeg1;    /* Bit segment 1 (ECONz.A, 0..3) */
    uint8           BitSeg2;    /* Bit segment 2 (ECONz.B, 0..3) */
    uint8           BitSeg3;    /* Bit segment 3 (ECONz.C, 0..3) */
    /* QSPI communication  configuration: */
    uint8           ClockPhase; /* Clock phase (ECONz.CPH, 0, 1) */
    uint8           ClockPol;   /* Clock Polarity (ECONz.CPOL, 0,1) */
    uint8           ParityEn;   /* Parity enable (ECONz.PAREN, 0,1) */
    uint8           ParityType; /* Parity type (BACON.PARTYP, 0=EVEN, 1=ODD) */
    uint8           MsbFirst;   /* MSB/LSB first (BACON.MSB, 0=LSB, 1=MSB) */
    uint8           DataLength; /* Data length in bits (BACON.DL, 0..31); */
    uint8           IdlePrescaler; /* Idle delay prescaler  (BACON.IPRE, 0..7)*/
    uint8           IdleDelay;     /* Idle delay (BACON.IDLE, 0..7) */
    uint8           LeadPrescaler; /* Leading delay prescaler -BACON.LPRE,0..7*/
    uint8           LeadDelay;     /* Leading delay (BACON.LEAD, 0..7) */
    uint8           TrailPrescaler;/* Trailing delay prescaler-BACON.TPRE,0..7*/
    uint8           TrailDelay;    /* Trailing delay (BACON.TRAIL, 0..7) */

}SafeWdgQspi_ChannelConfigType;



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
extern SafeWdgIf_ResultType SafeWdgQspi_Init
(
  const SafeWdgQspi_ChannelConfigType* const ConfigPtr
);

extern void SafeWdgQspi_DeInit
(
  void
);

extern void SafeWdgQspi_TxRx
(
  uint32* TxBuf,
  uint32* RxBuf,
  uint8 Count
);

extern SafeWdgIf_ResultType SafeWdgQspi_CustTxRx
(
  uint32* TxBuf,
  uint32* RxBuf,
  uint8 Count,
  uint32 BACONRegisterValue
 );

extern boolean SafeWdgQspi_RxDone
(
  uint32* Error
);
#ifndef SAFEWDGQSPI_DMAUSED
extern void SafeWdgQspi_IsrTxRx
(
  void
);
#endif
#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                   Imported Post-Build Data from Configuration files        **
*******************************************************************************/

extern const SafeWdgQspi_ModuleConfigType  SafeWdgQspi_ModuleConfigRoot;
extern const SafeWdgQspi_ChannelConfigType 
                          SafeWdgQspi_ChannelConfigRoot[SAFEWDGQSPI_CFG_COUNT];


#endif /* SAFEWDGQSPI_H */


