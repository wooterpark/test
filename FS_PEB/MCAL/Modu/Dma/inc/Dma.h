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
**  $FILENAME  : Dma.h $                                                      **
**                                                                            **
**  $CC VERSION : \main\33 $                                                 **
**                                                                            **
**  $DATE      : 2013-06-26 $                                                 **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This header file exports                                   **
**                 - functionality of Dma Driver.                             **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
********************************************************************************
**  TRACEABILITY : [cover parentID=SAS_NAS_ALL_PR748,SAS_NAS_ALL_PR746,
                   DS_NAS_HE2_DMA_PR3054,DS_NAS_EP_DMA_PR3054] 
                   [/cover]                                                   **
*******************************************************************************/

#ifndef DMA_H
#define DMA_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
 /* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

  /* Global functions like Set/Reset END INIT protection bit,
 Atomic write function */
#include "Mcal.h"

  /* Inclusion of configuration file */
#include "Dma_Cfg.h"

#if (DMA_DEV_ERROR_DETECT == STD_ON )
  /* Inclusion of Det.h */
#include "Det.h"
#endif /* End of DMA_DEV_ERROR_DETECT */
#if ((DMA_USER_MODE_INIT_API_ENABLE == STD_ON) ||                              \
     (DMA_USER_MODE_RUNTIME_API_ENABLE == STD_ON) ||                           \
     (DMA_USER_MODE_DEINIT_API_ENABLE == STD_ON) ||                            \
     (DMA_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON))
     #include "Dma_Protect.h"
#endif

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Vendor ID */
#define DMA_VENDOR_ID                   ((uint16)17U)

/* DMA Module ID 255 */
#define DMA_MODULE_ID                   ((uint16)255U)

#if (DMA_DEV_ERROR_DETECT == STD_ON)
/****************************Service ID's****************************/
#define DMA_SID_INIT                                    ((uint8)0x00U)
#define DMA_SID_DEINIT                                  ((uint8)0x01U)
#define DMA_SID_STARTSWTX                               ((uint8)0x02U)
#define DMA_SID_STARTHWTX                               ((uint8)0x03U)
#define DMA_SID_DISABLEHWTX                             ((uint8)0x04U)
#define DMA_SID_GETCHSTATUS                             ((uint8)0x05U)
#define DMA_SID_GETMEERRFLAGS                           ((uint8)0x06U)
#define DMA_SID_CLRMEERRFLAGS                           ((uint8)0x07U)
#define DMA_SID_CLRINTERRUPTS                           ((uint8)0x08U)
#define DMA_SID_GETTCOUNT                               ((uint8)0x09U)
#define DMA_SID_CONFIGHALTCH                            ((uint8)0x0AU)
#define DMA_SID_CONFIGCHINTR                            ((uint8)0x0BU)
#define DMA_SID_SWITCHBUFFER                            ((uint8)0x0CU)
#define DMA_SID_CONFIGCHLINKLIST                        ((uint8)0x0DU)
#define DMA_SID_GIVESWTRIG                              ((uint8)0x0EU)
#define DMA_SID_GETCHCRCVALUES                          ((uint8)0x0FU)
#define DMA_SID_GETVERSIONINFO                          ((uint8)0x10U)
#define DMA_SID_CONFIGSHADOW                            ((uint8)0x11U)
#define DMA_SID_RECONFIGCHANNEL                         ((uint8)0x12U)

/****************************DET Error ID***************************/
#define DMA_E_UNINIT                                    ((uint8)0x00U)
#define DMA_E_CH_UNINIT                                 ((uint8)0x01U)
#define DMA_E_INVALID_CHANNEL                           ((uint8)0x02U)
#define DMA_E_PARAM_CONFIG                              ((uint8)0x03U)
#define DMA_E_PARAM_POINTER                             ((uint8)0x05U)
#define DMA_E_INVALID_ADDR                              ((uint8)0x06U)
#define DMA_E_INVALID_SHADOW_CONFIG                     ((uint8)0x07U)
#define DMA_E_INVALID_TCOUNT                            ((uint8)0x08U)
#define DMA_E_INVALID_MASK                              ((uint8)0x09U)
#define DMA_E_INVALID_HALT_MODE                         ((uint8)0x0AU)
#define DMA_E_INVALID_INTR_MODE                         ((uint8)0x0BU)
#define DMA_E_INVALID_ME                                ((uint8)0x0CU)
#define DMA_E_INVALID_SWITCHREQ                         ((uint8)0x0DU)
#define DMA_E_INVALID_TCSPTR                            ((uint8)0x0EU)
#define DMA_E_INVALID_LLTYPE                            ((uint8)0x0FU)
#define DMA_E_INVALID_LLCOUNT                           ((uint8)0x10U)
#define DMA_E_INVALID_EXTBUFFPTR                        ((uint8)0x11U)
#endif /* End of DMA_DEV_ERROR_DETECT */

#if (DMA_USER_MODE_INIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_INIT_WRITE32(reg,value)                                        \
                                   (DMA_INIT_WRITE32((reg), (value)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_INIT_RESETSAFETYENDINIT(Time)                                  \
                                          (DMA_INIT_RESETSAFETYENDINIT(Time))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_INIT_SETSAFETYENDINIT()                                        \
                                              (DMA_INIT_SETSAFETYENDINIT())
#if (DMA_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DMA_SFR_INIT_USER_MODE_READ32(reg)                                   \
                                      (DMA_INIT_USER_MODE_OS_API_READ32(reg))
#else
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DMA_SFR_INIT_USER_MODE_READ32(reg)                 (reg)
#endif /* DMA_RUNNING_IN_USER_MODE_ENABLE == STD_ON  */
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_INIT_WRITE32(reg, value)                                       \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_INIT_RESETSAFETYENDINIT(Time)                                  \
                                           (Mcal_ResetSafetyENDINIT_Timed(Time))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_INIT_SETSAFETYENDINIT()       (Mcal_SetSafetyENDINIT_Timed())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_INIT_USER_MODE_READ32(reg)             (reg)
#endif /* DMA_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (DMA_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_RUNTIME_WRITE32(reg,value)                                     \
                                   (DMA_RUNTIME_WRITE32((reg), (value)))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_RUNTIME_MODIFY32(reg,clearmask,setmask)                        \
                       DMA_RUNTIME_MODIFY32((reg),(clearmask),(setmask))
#if (DMA_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DMA_SFR_RUNTIME_USER_MODE_READ32(reg)                                \
                                      (DMA_RUNTIME_USER_MODE_OS_API_READ32(reg))
#else
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DMA_SFR_RUNTIME_USER_MODE_READ32(reg)                 (reg)
#endif /* DMA_RUNNING_IN_USER_MODE_ENABLE == STD_ON  */
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_RUNTIME_WRITE32(reg, value)                                    \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_RUNTIME_MODIFY32(reg, clearmask,setmask)                       \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                               (reg) = (val);}  
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_RUNTIME_USER_MODE_READ32(reg)             (reg)
#endif /* DMA_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */

#if (DMA_USER_MODE_DEINIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_DEINIT_WRITE32(reg,value)                                      \
                                   (DMA_DEINIT_WRITE32((reg), (value)))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_DEINIT_MODIFY32(reg,clearmask,setmask)                         \
                       DMA_DEINIT_MODIFY32((reg),(clearmask),(setmask))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_DEINIT_RESETSAFETYENDINIT(Time)                                \
                                          (DMA_DEINIT_RESETSAFETYENDINIT(Time))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_DEINIT_SETSAFETYENDINIT()                                      \
                                              (DMA_DEINIT_SETSAFETYENDINIT())
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_DEINIT_WRITE32(reg, value)                                     \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_DEINIT_MODIFY32(reg, clearmask,setmask)                        \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                               (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_DEINIT_RESETSAFETYENDINIT(Time)                                \
                                           (Mcal_ResetSafetyENDINIT_Timed(Time))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DMA_SFR_DEINIT_SETSAFETYENDINIT()       (Mcal_SetSafetyENDINIT_Timed())
#endif /* DMA_USER_MODE_DEINIT_API_ENABLE == STD_ON  */
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/*
Type : Dma_ChType
Specifies the identification for a Channel.
All enum elements are being initialized to avoid
MISRA-C rule 9.3 violation.
*/
typedef enum
{
  DMA_CH0        =   0U,
  DMA_CH1        =   1U,
  DMA_CH2        =   2U,
  DMA_CH3        =   3U,
  DMA_CH4        =   4U,
  DMA_CH5        =   5U,
  DMA_CH6        =   6U,
  DMA_CH7        =   7U,
  DMA_CH8        =   8U,
  DMA_CH9        =   9U,
  DMA_CH10       =  10U,
  DMA_CH11       =  11U,
  DMA_CH12       =  12U,
  DMA_CH13       =  13U,
  DMA_CH14       =  14U,
  DMA_CH15       =  15U,
  DMA_CH16       =  16U,
  DMA_CH17       =  17U,
  DMA_CH18       =  18U,
  DMA_CH19       =  19U,
  DMA_CH20       =  20U,
  DMA_CH21       =  21U,
  DMA_CH22       =  22U,
  DMA_CH23       =  23U,
  DMA_CH24       =  24U,
  DMA_CH25       =  25U,
  DMA_CH26       =  26U,
  DMA_CH27       =  27U,
  DMA_CH28       =  28U,
  DMA_CH29       =  29U,
  DMA_CH30       =  30U,
  DMA_CH31       =  31U,
  DMA_CH32       =  32U,
  DMA_CH33       =  33U,
  DMA_CH34       =  34U,
  DMA_CH35       =  35U,
  DMA_CH36       =  36U,
  DMA_CH37       =  37U,
  DMA_CH38       =  38U,
  DMA_CH39       =  39U,
  DMA_CH40       =  40U,
  DMA_CH41       =  41U,
  DMA_CH42       =  42U,
  DMA_CH43       =  43U,
  DMA_CH44       =  44U,
  DMA_CH45       =  45U,
  DMA_CH46       =  46U,
  DMA_CH47       =  47U,
  DMA_CH48       =  48U,
  DMA_CH49       =  49U,
  DMA_CH50       =  50U,
  DMA_CH51       =  51U,
  DMA_CH52       =  52U,
  DMA_CH53       =  53U,
  DMA_CH54       =  54U,
  DMA_CH55       =  55U,
  DMA_CH56       =  56U,
  DMA_CH57       =  57U,
  DMA_CH58       =  58U,
  DMA_CH59       =  59U,
  DMA_CH60       =  60U,
  DMA_CH61       =  61U,
  DMA_CH62       =  62U,
  DMA_CH63       =  63U,
  DMA_CH64       =  64U,
  DMA_CH65       =  65U,
  DMA_CH66       =  66U,
  DMA_CH67       =  67U,
  DMA_CH68       =  68U,
  DMA_CH69       =  69U,
  DMA_CH70       =  70U,
  DMA_CH71       =  71U,
  DMA_CH72       =  72U,
  DMA_CH73       =  73U,
  DMA_CH74       =  74U,
  DMA_CH75       =  75U,
  DMA_CH76       =  76U,
  DMA_CH77       =  77U,
  DMA_CH78       =  78U,
  DMA_CH79       =  79U,
  DMA_CH80       =  80U,
  DMA_CH81       =  81U,
  DMA_CH82       =  82U,
  DMA_CH83       =  83U,
  DMA_CH84       =  84U,
  DMA_CH85       =  85U,
  DMA_CH86       =  86U,
  DMA_CH87       =  87U,
  DMA_CH88       =  88U,
  DMA_CH89       =  89U,
  DMA_CH90       =  90U,
  DMA_CH91       =  91U,
  DMA_CH92       =  92U,
  DMA_CH93       =  93U,
  DMA_CH94       =  94U,
  DMA_CH95       =  95U,
  DMA_CH96       =  96U,
  DMA_CH97       =  97U,
  DMA_CH98       =  98U,
  DMA_CH99       =  99U,
  DMA_CH100      = 100U,
  DMA_CH101      = 101U,
  DMA_CH102      = 102U,
  DMA_CH103      = 103U,
  DMA_CH104      = 104U,
  DMA_CH105      = 105U,
  DMA_CH106      = 106U,
  DMA_CH107      = 107U,
  DMA_CH108      = 108U,
  DMA_CH109      = 109U,
  DMA_CH110      = 110U,
  DMA_CH111      = 111U,
  DMA_CH112      = 112U,
  DMA_CH113      = 113U,
  DMA_CH114      = 114U,
  DMA_CH115      = 115U,
  DMA_CH116      = 116U,
  DMA_CH117      = 117U,
  DMA_CH118      = 118U,
  DMA_CH119      = 119U,
  DMA_CH120      = 120U,
  DMA_CH121      = 121U,
  DMA_CH122      = 122U,
  DMA_CH123      = 123U,
  DMA_CH124      = 124U,
  DMA_CH125      = 125U,
  DMA_CH126      = 126U,
  DMA_CH127      = 127U,
  DMA_CH_INVALID = 0xFFU
}Dma_ChType;
/*
 * Type : Dma_ChannelHaltType
 * Typedef for switching halt mode to ON/OFF.
*/
typedef enum
{
  DMA_HALT_OFF,
  DMA_HALT_ON
}Dma_ChannelHaltType;
/*
 * Type : Dma_InterruptModeType
 * Typedef for switching interrupt mode to ON/OFF.
*/
typedef enum
{
  DMA_CH_INT_OFF,
  DMA_CH_INT_ON
}Dma_InterruptModeType;
/*
 * Type : Dma_ChannelStatusType
 * Typedef structure for storing Dma channel status
*/
typedef struct Dma_ChannelStatusType
{
  unsigned_int DmaInvalidStatus:1;
  unsigned_int DmaPending:1;
  unsigned_int DmaIntDetected:1;
  unsigned_int DmaPatternMatch:1;
  unsigned_int DmaHaltAck:1;
  unsigned_int DmaTxReqLost:1;
  unsigned_int DmaHwReqOn:1;
  unsigned_int DmaCurrBuffer:1;
  unsigned_int DmaFrozenBuff:1;
  unsigned_int Reserved_Bits:7;
}Dma_ChannelStatusType;
/*
 * Type : Dma_ErrorType
 * Typedef structure for storing Dma move engine error flags
*/
typedef struct Dma_ErrorType
{
  unsigned_int DmaMovEngInvalidErr:1;
  unsigned_int DmaMovEngSrcErr:1;
  unsigned_int DmaMovEngDestErr:1;
  unsigned_int DmaMovEngSpbErr:1;
  unsigned_int DmaMovEngSriErr:1;
  unsigned_int DmaMovEngRamErr:1;
  unsigned_int DmaMovEngSafeLinkListErr:1;
  unsigned_int DmaMovEngLinkListErr:1;
}Dma_ErrorType;
/*
 * Type : Dma_CrcSetType
 * Typedef for read data and source/destination address register set.
*/
typedef struct Dma_CrcSetType
{
  uint32 DmaRdDataCrc;
  uint32 DmaSrcDstAddrCrc;
  uint8  DmaInvalidCrc;
}Dma_CrcSetType;
/*
 * Type : Dma_TransactionSetType
 * Typedef structure for storing parameters which are required for performing
 *linked list operation.
*/
typedef struct Dma_TransactionSetType
{
  uint32 DmaSrcDestCrcVal;
  uint32 DmaSrcAddr;
  uint32 DmaDestAddr;
  uint16 DmaXferReloadValue;
  uint8  DmaAutoStart;
}Dma_TransactionSetType;

/*
 * Type : Dma_FullTxCtrlSetType
 * Typedef structure for storing all 8 registers associated with a channel for
 *linked list operation.
*/
typedef struct Dma_FullTxCtrlSetType
{
  uint32 DmaReadDataCrc;
  uint32 DmaSrcDestCrc;
  uint32 DmaSourceAddress;
  uint32 DmaDestinationAddress;
  uint32 DmaAddressIntrControl;
  uint32 DmaChannelConfig;
  struct Dma_FullTxCtrlSetType* DmaShadowAddress;
  uint32 DmaChControlStatus;
}Dma_FullTxCtrlSetType;

/*
 * Type : Dma_ChIncrementDirectionType
 * Typedef for storing address increment/decrement direction.
*/

typedef enum
{
  DMA_CH_INCREMENT_DIR_NEG,
  DMA_CH_INCREMENT_DIR_POS
} Dma_ChIncrementDirectionType;

/*
 * Type : Dma_ChAddressModOffsetType
 * Typedef for storing address offset value which will be used for calculating
 * next address location given that address modification is enabled.
*/
typedef enum
{
  DMA_CH_ADDR_MOD_FACTOR_1,
  DMA_CH_ADDR_MOD_FACTOR_2,
  DMA_CH_ADDR_MOD_FACTOR_4,
  DMA_CH_ADDR_MOD_FACTOR_8,
  DMA_CH_ADDR_MOD_FACTOR_16,
  DMA_CH_ADDR_MOD_FACTOR_32,
  DMA_CH_ADDR_MOD_FACTOR_64,
  DMA_CH_ADDR_MOD_FACTOR_128
} Dma_ChAddressModOffsetType;

/*
 * Type : Dma_ChCircularBuffEnType
 * Typedef for enabling/disabling of a circular buffer.
*/

typedef enum
{
  DMA_CH_CIRC_BUFF_DISABLE,
  DMA_CH_CIRC_BUFF_ENABLE
} Dma_ChCircularBuffEnType;

/*
 * Type : Dma_ChWrapEnType
 * Typedef for enabling/disabling wrap around interrpt for a buffer.
*/

typedef enum
{
  DMA_CH_WRAP_DISABLE,
  DMA_CH_WRAP_ENABLE
} Dma_ChWrapEnType;


typedef enum
{
  DMA_CH_CIRC_BUFF_LEN_1,
  DMA_CH_CIRC_BUFF_LEN_2,
  DMA_CH_CIRC_BUFF_LEN_4,
  DMA_CH_CIRC_BUFF_LEN_8,
  DMA_CH_CIRC_BUFF_LEN_16,
  DMA_CH_CIRC_BUFF_LEN_32,
  DMA_CH_CIRC_BUFF_LEN_64,
  DMA_CH_CIRC_BUFF_LEN_128,
  DMA_CH_CIRC_BUFF_LEN_256,
  DMA_CH_CIRC_BUFF_LEN_512,
  DMA_CH_CIRC_BUFF_LEN_1KB,
  DMA_CH_CIRC_BUFF_LEN_2KB,
  DMA_CH_CIRC_BUFF_LEN_4KB,
  DMA_CH_CIRC_BUFF_LEN_8KB,
  DMA_CH_CIRC_BUFF_LEN_16KB,
  DMA_CH_CIRC_BUFF_LEN_32KB
} Dma_ChCircBuffSizeType;
/*
 * Type : Dma_ChannelAddressConfigType
 * Typedef structure for storing address control configurations for a channel
*/
typedef struct Dma_ChannelAddressConfigType
{
  Dma_ChIncrementDirectionType IncrementSrcDirection;
  Dma_ChIncrementDirectionType IncrementDstDirection;
  Dma_ChAddressModOffsetType   SrcAddressOffset;
  Dma_ChAddressModOffsetType   DstAddressOffset;
  Dma_ChCircularBuffEnType     SrcCircularBuffEn;
  Dma_ChCircularBuffEnType     DstCircularBuffEn;
  Dma_ChCircBuffSizeType       SrcCircularBuffLength;
  Dma_ChCircBuffSizeType       DstCircularBuffLength;
  Dma_ChWrapEnType             SrcWrapEn;
  Dma_ChWrapEnType             DstWrapEn;
}Dma_ChannelAddressConfigType;

/*
 * Type : Dma_ChannelConfigType
 * Typedef structure for storing configuration related to each channel of DMA.
*/
typedef struct Dma_ChannelConfigType
{
  uint32 DmaChannelConfig;
  uint32 DmaAddrIntControl;
  uint8  DmaHwResourceMode;
  uint8  DmaChannelHwPartitionConfig;
  uint8  DmaChannelNumber;
}Dma_ChannelConfigType;
/*
 * Type : Dma_ConfigType
 * Typedef structure for storing configuration which is necessary for DMA
 * initialization.
*/
typedef struct Dma_ConfigType
{
  const Dma_ChannelConfigType *ChannelCfgPtr;
  uint32 DmaPat0;
  uint32 DmaPat1;
  uint32 DmaMovEng0Err;
  uint32 DmaMovEng1Err;
  uint8  ChannelsConfigured;
}Dma_ConfigType;


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define DMA_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* Declaration of DMA Post Build Configuration */
extern const Dma_ConfigType Dma_ConfigRoot[DMA_CONFIG_COUNT];
#define DMA_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*******************************************************************************

*******************************************************************************/
/*Memory Map of the DMA Code*/
#define DMA_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Syntax : void Dma_Init(const Dma_ConfigType *ConfigPtr)                    **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to DMA Driver configuration set     **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Initialises the Dma Move Engines                             **
**            This function should be called before calling any other Dma apis**
*******************************************************************************/
extern void Dma_Init(const Dma_ConfigType *ConfigPtr);

#if (DMA_DEINIT_API == STD_ON)
/*******************************************************************************
** Syntax : void Dma_DeInit(Std_ReturnType)                                   **
**                                                                            **
** Service ID:  0x01                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver DeInitialization                                      **
**               This function will deinitialize the DMA peripheral           **
*******************************************************************************/
extern void Dma_DeInit(void);
#else
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Dma_DeInit()                   (ERROR_Dma_DeInit_NOT_SELECTED)
#endif /* End of DMA_DEINIT_API */

/*******************************************************************************
** Syntax : Std_ReturnType Dma_StartHwTransaction(Dma_ChType Channel, const   **
**          uint32 *SrcAddressPtr,const uint32 *DestAddressPtr, uint16 TCount)**
**                                                                            **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) : Channel - Channel ID                                     **
**                   SrcAddressPtr - Source address for read move             **
**                   DestAddressPtr - Destination address for write move      **
**                   TCount - Number of transfers per transaction             **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description :  This function starts a transaction with a software trigger  **
**                and will move data as per source and destination address for**
**                TCount number of transfers                                  **
*******************************************************************************/
extern Std_ReturnType Dma_StartSwTransaction(Dma_ChType Channel, const uint32
                  *SrcAddressPtr,const uint32 *DestAddressPtr, uint16 TCount);
/*******************************************************************************
** Syntax : Std_ReturnType Dma_StartSwTransaction(Dma_ChType Channel, const   **
**          uint32 *SrcAddressPtr,const uint32 *DestAddressPtr, uint16 TCount)**
**                                                                            **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) : Channel - Channel ID                                     **
**                   SrcAddressPtr - Source address for read move             **
**                   DestAddressPtr - Destination address for write move      **
**                   TCount - Number of transfers per transaction             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description :  This function starts a transaction with a hardware trigger  **
**                and will move data as per source and destination address for**
**                TCount number of transfers                                  **
*******************************************************************************/
extern Std_ReturnType Dma_StartHwTransaction(Dma_ChType Channel,const uint32
                  *SrcAddressPtr, const uint32 *DestAddressPtr, uint16 TCount);
/*******************************************************************************
** Syntax : Std_ReturnType Dma_DisableHwTransaction(Dma_ChType Channel)       **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : Disables the hardware transaction mode                       **
*******************************************************************************/
extern Std_ReturnType Dma_DisableHwTransaction(Dma_ChType Channel);

/*******************************************************************************
** Syntax :Dma_ChannelStatusType Dma_GetChannelStatus(Dma_ChType Channel)     **
**                                                                            **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Dma_ChannelStatusType                                   **
**                                                                            **
** Description :  Returns a structure of type Dma_ChannelStatusType with      **
**                  following bitfields:                                      **
**                DmaPending: indicates channel is active/idle                **
**                DmaIntDetected: indicates interrupt from channel has been   **
**                                 detected depending on Interrupt settings   **
**                DmaPatternMatch: indicates a pattern match has been detected**
**                DmaHaltAck: Status of halt acknowledge bit                  **
**                DmaTxReqLost: transaction request lost bit status           **
**                DmaHwReqOn: indicates whether hardware request bit is on    **
**                DmaCurrBuffer: indicates active buffer is buffer0/buffer1   **
**                DmaFrozenBuffER:indicates one of a double buffer is frozen  **
**                DmaInvalidStatus:In case of DETs                            **
*******************************************************************************/
extern Dma_ChannelStatusType Dma_GetChannelStatus(Dma_ChType Channel);

/*******************************************************************************
** Syntax : Dma_ErrorType Dma_GetMoveEngineErrFlags(uint8 MoveEngine)         **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  MoveEngine - Move Engine ID                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Dma_ErrorType                                            **
**                                                                            **
** Description :  Returns a structure of type Dma_ErrorType with following    **
**                bitfields:                                                  **
**                DmaMovEngSrcErr: Holds Move engine source error flag        **
**                DmaMovEngDestErr: Holds Move engine destination error flag  **
**                DmaMovEngSpbErr:  Holds Move engine SPB error flag          **
**                DmaMovEngSriErr:  Holds Move engine SRI error flag          **
**                DmaMovEngRamErr:  Holds Move engine RAM error flag          **
**                DmaMovEngSafeLinkListErr: Holds Move engine Safe linkedlist **
**                                          error flag                        **
**                DmaMovEngLinkListErr:Holds Move engine linkedlist error flag**
**                DmaMovEngInvalidErr:  This bit is set if some DET occurs.   **
*******************************************************************************/
extern Dma_ErrorType Dma_GetMoveEngineErrFlags(uint8 MoveEngine);

/*******************************************************************************
** Syntax:Std_ReturnType Dma_ClearMoveEngineErrFlags(uint8 MoveEngine,        **
**                                                      uint32 ClrErrMask)    **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  MoveEngine - Move Engine ID                             **
**                    ClrErrMask - Error mask                                 **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description :  clears error flags related to move engine as per the mask   **
*******************************************************************************/
extern Std_ReturnType Dma_ClearMoveEngineErrFlags (uint8 MoveEngine,
                                                         uint32 ClrErrMask);

/*******************************************************************************
** Syntax : Std_ReturnType Dma_ClearInterruptStatus(Dma_ChType Channel)       **
**                                                                            **
** Service ID:  0x08                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : Clears interrupt related flags for the channel               **
*******************************************************************************/
extern Std_ReturnType Dma_ClearInterruptStatus(Dma_ChType Channel);

/*******************************************************************************
** Syntax : uint16 Dma_GetTransferCount(Dma_ChType Channel)                   **
**                                                                            **
** Service ID:  0x09                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  uint16                                                  **
**                                                                            **
** Description : returns the number of transfers remaining for the channel    **
*******************************************************************************/
extern uint16 Dma_GetTransferCount(Dma_ChType Channel);

/*******************************************************************************
** Syntax : Std_ReturnType Dma_ConfigHaltChannel(Dma_ChType Channel,          **
**                                          Dma_ChannelHaltType HaltMode)     **
**                                                                            **
** Service ID:  0x0A                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                HaltMode- Halt ON/OFF mode                                  **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : Service for configuring halt mode of a DMA channel           **
*******************************************************************************/
extern Std_ReturnType Dma_ConfigHaltChannel(Dma_ChType Channel,
                                            Dma_ChannelHaltType HaltMode);

/*******************************************************************************
** Syntax : Std_ReturnType Dma_ConfigChannelInterrupt(Dma_ChType Channel,**
**                                        Dma_InterruptModeType InterruptMode)**
**                                                                            **
** Service ID:  0x0B                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                InterruptMode- Interrupt ON/OFF mode                        **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : Service for configuring interrupt mode of a DMA channel      **
*******************************************************************************/
extern Std_ReturnType Dma_ConfigChannelInterrupt(Dma_ChType Channel,
                                          Dma_InterruptModeType InterruptMode);

/*******************************************************************************
** Traceability   :                                                           **
**                                                                            **
** Syntax : Std_ReturnType Dma_ConfigShadowAddress(Dma_ChType Channel, const  **
**                                                uint32 *ShadowAddrPtr)      **
** Service ID:  0x11                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                    ShadowAddrPtr: Contains address to be put in shadow     **
**                                   register.                                **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : This API is used to switch buffers provided double buffering **
**               mode is ON                                                   **
*******************************************************************************/
extern Std_ReturnType Dma_ConfigShadowAddress(Dma_ChType Channel, const uint32
                                                               *ShadowAddrPtr);
#if (DMA_DOUBLE_BUFFER_ENABLE == STD_ON)
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1799,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_22]                       **
**                                                                            **
** Syntax : Std_ReturnType Dma_SwitchBuffer(Dma_ChType Channel)               **
**                                                                            **
** Service ID:  0x0C                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : This API is used to switch buffers provided double buffering **
**               mode is ON                                                   **
*******************************************************************************/
extern Std_ReturnType Dma_SwitchBuffer(Dma_ChType Channel);
#else
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Dma_SwitchBuffer(Channel) (ERROR_Dma_DoubleBuffer_NOT_SELECTED)
#endif /* End of DMA_DOUBLE_BUFFER_ENABLE */

#if (DMA_LINKED_LIST_ENABLE == STD_ON)
/*******************************************************************************
** Syntax : Std_ReturnType Dma_ConfigChannelLinkList (Dma_ChType Channel,     **
**                const Dma_TransactionSetType *TcsPtr, Dma_FullTxCtrlSetType **
**                *ExtBuffBasePtr, uint32 LinkedListCount)                    **
**                                                                            **
** Service ID:  0x0D                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                TcsPtr - Pointer to a structure that will contain source    **
**                         address, CRC values, destination address and       **
**                         transfer count.                                    **
**                LinkedListCount - Total number of transactions to be made   **
**                ExtBuffBasePtr  - Pointer to array of structure of type     **
**                                    Dma_FullTxCtrlSetType which is of size  **
**                                    equivalent to a transaction control set **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : This API is used to trigger a transaction in linkedlist style**
*******************************************************************************/
extern Std_ReturnType Dma_ConfigChannelLinkList (Dma_ChType Channel, const
                      Dma_TransactionSetType *TcsPtr, Dma_FullTxCtrlSetType
                      *ExtBuffBasePtr,uint32 LinkedListCount);
#else
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Dma_ConfigChannelLinkList( Channel, TcsPtr, ExtBuffBasePtr,\
                         LinkedListCount)  (ERROR_Dma_LinkedList_NOT_SELECTED)
#endif /* End of DMA_LINKED_LIST_ENABLE */
/*******************************************************************************
** Syntax : Std_ReturnType Dma_GiveSwTrigger(Dma_ChType Channel)              **
**                                                                            **
** Service ID:  0x0E                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : This API performs a software trigger.                        **
*******************************************************************************/
extern Std_ReturnType Dma_GiveSwTrigger(Dma_ChType Channel);
/*******************************************************************************
** Syntax : Dma_CrcSetType Dma_GetCRC(Dma_ChType Channel)                     **
**                                                                            **
** Service ID:  0x0F                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Dma_CrcSetType                                          **
**                                                                            **
** Description : Returns CRC values of read data and source/destinatinon      **
**               address registers calculated by the hardware for the channel.**
*******************************************************************************/
extern Dma_CrcSetType Dma_GetCRC(Dma_ChType Channel);

/*******************************************************************************
** Syntax : Std_ReturnType Dma_ReconfigureChannel(Dma_ChType Channel,         **
                         const Dma_ChannelAddressConfigType *ChAddrConfigPtr) **
**                                                                            **
** Service ID:  0x12                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : This service reconfigures/reinitializes the Dma channel with **
**               the configuration pointed by ChAddrConfigPtr of              **
**               type ChannelAddressConfigType.                               **
*******************************************************************************/
extern Std_ReturnType Dma_ReconfigureChannel(Dma_ChType Channel,
                           const Dma_ChannelAddressConfigType *ChAddrConfigPtr);
/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_DMA_PR63_25,DS_NAS_DMA_PR63_27,
                                     DS_NAS_DMA_PR128]                        **
**                                                                            **
**                                                                            **
** Syntax     : Std_ReturnType Dma_GetVersionInfo( Std_VersionInfoType        **
**                             *VersionInfoPtr)                               **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID   : 0x0D                                                        **
**                                                                            **
** Sync/Async   : Synchronous                                                 **
**                                                                            **
** Reentrancy   : Non-reentrant                                               **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): VersionInfoPtr (Pointer to store the version             **
**                   information of this module)                              **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
** Description  : This service returns the version information of this module.**
**               The version information includes:                            **
**               - Module Id                                                  **
**               - Vendor Id                                                  **
**               - Instance Id                                                **
**               - Vendor specific version numbers                            **
**                                                                            **
*******************************************************************************/
#if ((DMA_VERSION_INFO_API == STD_ON) && (DMA_DEV_ERROR_DETECT == STD_ON))
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand to a 
 braced initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a 
 function like macro as per AUTOSAR*/
#define Dma_GetVersionInfo(VersionInfoPtr)                                \
{                                                                         \
  if (((VersionInfoPtr) == NULL_PTR))                                     \
  {                                                                       \
    /* Report to DET */                                                   \
    Det_ReportError(                                                      \
                     (uint16)DMA_MODULE_ID,                               \
                     DMA_MODULE_INSTANCE,                                 \
                     DMA_SID_GETVERSIONINFO,                              \
                     DMA_E_PARAM_POINTER                                  \
                   );                                                     \
  }                                                                       \
  else                                                                    \
  {                                                                       \
    /* DMA Module ID */                                                   \
    ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = DMA_MODULE_ID;   \
    /* DMA vendor ID */                                                   \
    ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = DMA_VENDOR_ID;   \
    /* major version of DMA */                                            \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =          \
                                    (uint8)DMA_SW_MAJOR_VERSION;          \
    /* minor version of DMA */                                            \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =          \
                                    (uint8)DMA_SW_MINOR_VERSION;          \
    /* patch version of DMA */                                            \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =          \
                                    (uint8)DMA_SW_PATCH_VERSION;          \
  }                                                                       \
}
#elif ((DMA_VERSION_INFO_API == STD_ON) && (DMA_DEV_ERROR_DETECT == STD_OFF))
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand to a 
 braced initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a 
 function like macro as per AUTOSAR*/
#define Dma_GetVersionInfo(VersionInfoPtr)                                \
{                                                                         \
  /* DMA Module ID */                                                     \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = DMA_MODULE_ID;     \
  /* DMA vendor ID */                                                     \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = DMA_VENDOR_ID;     \
  /* major version of DMA */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =            \
                                  (uint8)DMA_SW_MAJOR_VERSION;            \
  /* minor version of DMA */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =            \
                                  (uint8)DMA_SW_MINOR_VERSION;            \
  /* patch version of DMA */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =            \
                                  (uint8)DMA_SW_PATCH_VERSION;            \
}
#else

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Dma_GetVersionInfo(VersionInfoPtr)                                \
                                 (ERROR_Dma_GetVersionInfo_NOT_SELECTED)
#endif

#define DMA_STOP_SEC_CODE
#include "MemMap.h"

#endif /* End of DMA_H*/