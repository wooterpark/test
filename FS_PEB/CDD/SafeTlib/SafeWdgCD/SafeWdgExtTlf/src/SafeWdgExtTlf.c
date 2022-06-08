/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            ** 
**   $FILENAME   : SafeWdgExtTlf.c $                                          **
**                                                                            **
**   $CC VERSION : \main\53 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking , GNU, WindRiver                                                      **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of external TLF35584 SafeWdg  driver       **
**                                                                            **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "SafeWdgIf.h"
#include "TLF35584_reg.h"
#include "Mcal.h"
#include "IfxPort_reg.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/* TLF command read/write bit: */
#define SAFEWDGEXT_TLF_WR_BIT                ( 0x00004000U )  

/* Mask and position of the TLF command, address and data within a data word: */
#define SAFEWDGEXT_TLF_CMD_POS               ( 8 )

/* Byte sequence to be written to PROTCFG register to unlock the TLF: */
#define SAFEWDGEXT_TLF_UNLOCK_SEQU0          ( (uint8)0xABU )
#define SAFEWDGEXT_TLF_UNLOCK_SEQU1          ( (uint8)0xEFU )
#define SAFEWDGEXT_TLF_UNLOCK_SEQU2          ( (uint8)0x56U )
#define SAFEWDGEXT_TLF_UNLOCK_SEQU3          ( (uint8)0x12U )

/* Byte sequence to be written to PROTCFG register to lock the TLF: */
#define SAFEWDGEXT_TLF_LOCK_SEQU0            ( (uint8)0xDFU )
#define SAFEWDGEXT_TLF_LOCK_SEQU1            ( (uint8)0x34U )
#define SAFEWDGEXT_TLF_LOCK_SEQU2            ( (uint8)0xBEU )
#define SAFEWDGEXT_TLF_LOCK_SEQU3            ( (uint8)0xCAU )

/* WDCFG bits: */
#define SAFEWDGEXT_TLF_WDCFG0_WDCYC_0_1MS_B    ( (uint8)0x00U )
#define SAFEWDGEXT_TLF_WDCFG0_WDCYC_1MS_B      ( (uint8)0x01U )
#define SAFEWDGEXT_TLF_WDCFG0_WWDTSEL_B        ( (uint8)0x02U )
#define SAFEWDGEXT_TLF_WDCFG0_FWDEN_B          ( (uint8)0x04U )
#define SAFEWDGEXT_TLF_WDCFG0_WWDEN_B          ( (uint8)0x08U )
#define SAFEWDGEXT_TLF_WDCFG0_WDETH_P          ( 4U )
#define SAFEWDGEXT_TLF_WDCFG1_FWETH_M          ( (uint8)0x0FU )

/* SYSPCFG bits: */
#ifdef SAFEWDGEXTTLF_ERR_PIN_MONITOR_ENABLE
  #define SAFEWDGEXT_TLF_SYSPCFG1_ERR_B        ( (uint8)0x08U ) 
#else
  #define SAFEWDGEXT_TLF_SYSPCFG1_ERR_B        ( (uint8)0x0U )
#endif

#define SAFEWDGEXT_TLF_SYSPCFG1_EREN_B        ( (uint8)0x08U )
/* FWDSTAT0 bits: */
#define SAFEWDGEXT_TLF_FW_QUEST_M              ( (uint8)0x0FU )

/*RWDCFG0 mask bits for FWDEN and WWDEN */
#define SAFEWDGEXT_TLF_RWDCFG0_M               ((uint8)0x0CU )

/* Px_OMC bits: */
#define SAFEWDGEXT_TLF_OMCR_BASE_P             ( 16U )

#define SAFEWDGEXT_TLF_ECNT_M                 ( (uint16)0x000FU )
#define SAFEWDGEXT_TLF_STATE_M                ( (uint16)0x0007U )
#define SAFEWDGEXT_TLF_FW_RSPCNT_M             ( (uint8)0x30U )
/*Definitions for device state*/
#define SAFEWDGEXT_TLF_DEVSTAT_RES            ( 0x0U)
#define SAFEWDGEXT_TLF_DEVSTAT_WAK            ( 0x5U)


/* SafeWdgExtTlf_JobType definitions: */
#define SAFEWDGEXT_TLF_IDLE                 ( 0U )/* Driver idle*/
#define SAFEWDGEXT_TLF_ULOCK_JOB            ( 1U )/*Init unlock job*/
#define SAFEWDGEXT_TLF_LOCK_JOB             ( 2U )/*Init lock job*/
#define SAFEWDGEXT_TLF_CHK_INIT_JOB         ( 9U )/*Init Wdg Disable check job*/
#define SAFEWDGEXT_TLF_ENBLE_JOB            ( 3U )/*Activate enable job*/
#define SAFEWDGEXT_TLF_ACT_SRV_JOB          ( 4U )/*Activat first service job*/
#define SAFEWDGEXT_TLF_INFO_JOB             ( 5U )/*Cyclic info job*/
#define SAFEWDGEXT_TLF_SER_JOB              ( 6U )/*Regular service job*/
#define SAFEWDGEXT_TLF_USR_JOB              ( 7U )/*User request job*/
#define SAFEWDGEXT_TLF_DEINIT_JOB           ( 8U )/*Deinit Job*/

#define SAFEWDGEXT_TLF_NOR_STATE_M          ( 0x02U )
#define SAFEWDGEXT_TLF_BITMASK              ( 0xFFU )

/*Maximum size of Tx and Rx Buffer*/
#define SAFEWDGEXT_TLF_MAXBUF               (25U)

#define SAFEWDGEXT_INVALIDATE_CRC           (0x0U)

/* Mask for last 4 bits*/
#define SAFEWDGEXT_TLF_MASK_BIT             ( (uint8)0x0FU )
/* SafeWdg TLF FWD Rsp counter reset value*/
#define SAFEWDGEXT_TLF_RSPCNT_RESET_VAL     ( (uint8)0x03U )
/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/

/* Macro to assemble a TLF register write command: */
#define SAFEWDGEXT_TLF_WR_CMD(REG, VAL)  ( ((((uint32)(REG) & (uint32)0x3FU) \
                                            << 8U) | SAFEWDGEXT_TLF_WR_BIT )| \
                                            ((uint32)(VAL) & (uint32)0xFFU) )

/* Macro to assemble a TLF register read command: */
#define SAFEWDGEXT_TLF_RD_CMD(REG)     ( ((uint32)(REG) & (uint32)0x3FU) << 8U )


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/* Type definition SafeWdgExtTlf_DataType - This structure contains local
 * working data of the TLF driver:
 */
typedef struct SafeWdgExtTlf_DataType
{
  const SafeWdgExtTlf_ConfigType* ConfigPtr;  /* Used configuration */
  SafeWdgIf_CmdType*              RequestPtr;/* List of user requests */
  SafeWdgExt_StateType            DeviceState;   /*current TLF  state*/
  uint8                           LastSeed;   /* Latest seed value */
  uint8                           RspCnt;     /* response counter */  
  uint8                           LastWwdScmd;/* Last WWD service cmd register
                                               value */
  uint8                           ErrCtr;   /*Error counter value of TLF*/
  uint8                           NoOfBytesToBeTfered;
  uint32                          Crc;       /* calculated Crc for data set */
  /* Current asynchronous job and result: */
  uint8                           JobState;
  SafeWdgIf_ResultType            JobResult;
  #if (_SAFEWDG_TLF_DEBUG_ == TRUE )
  /*Code is for development and debug purpose only.*/
  uint32                          XorMask[16];
  #endif
  /*Variable to store  value of register SYSPCFG0 */
  volatile uint16                 Syspcfg0;  
  /*Variable to store  value of register SYSPCFG1 */
  volatile uint16                 Syspcfg1;  
  /*Variable to store  value of register WDCFG0 */
  volatile uint16                 Wdcfg0;    
  /*Variable to store  value of register WDCFG1 */
  volatile uint16                 Wdcfg1;    
  /*Variable to store  value of register FWDCFG */
  volatile uint16                 Fwdcfg;    
  /*Variable to store  value of register WWDCFG0 */
  volatile uint16                 Wwdcfg0;   
  /*Variable to store  value of register WWDCFG1 */
  volatile uint16                 Wwdcfg1;
  /* Flag to indicate that the WDI pin reset is still pending: */
  boolean                         WdiRestoreFlag;
  /* Flag to indicate that activate has been requested: */
  boolean                         ActivateRequested;
} SafeWdgExtTlf_DataType;

/* SPI buffer indices for Unlock job: */
typedef enum
{
  TLF_UNLOCK_WR_PROTCFG_0 = 0U,
  TLF_UNLOCK_WR_PROTCFG_1,
  TLF_UNLOCK_WR_PROTCFG_2,
  TLF_UNLOCK_WR_PROTCFG_3,
  TLF_UNLOCK_RD_RSYSPCFG0,
  TLF_UNLOCK_RD_RSYSPCFG1,
  TLF_UNLOCK_RD_RWDCFG0,
  TLF_UNLOCK_RD_RWDCFG1,
  TLF_UNLOCK_RD_RFWDCFG,
  TLF_UNLOCK_RD_RWWDCFG0,
  TLF_UNLOCK_RD_RWWDCFG1,
  TLF_UNLOCK_MAX
}SafeWdgExtTlf_UnlockJob;

/* SPI buffer indices for Lock job: */
typedef enum
{
  TLF_LOCK_WR_SYSPCFG0 = 0U,
  TLF_LOCK_WR_SYSPCFG1,
  TLF_LOCK_WR_WDCFG0,
  TLF_LOCK_WR_WDCFG1,
  TLF_LOCK_WR_FWDCFG,
  TLF_LOCK_WR_WWDCFG0,
  TLF_LOCK_WR_WWDCFG1,
  TLF_LOCK_RD_SYSPCFG0,
  TLF_LOCK_RD_SYSPCFG1,
  TLF_LOCK_RD_WDCFG0,
  TLF_LOCK_RD_WDCFG1,
  TLF_LOCK_RD_FWDCFG,
  TLF_LOCK_RD_WWDCFG0,
  TLF_LOCK_RD_WWDCFG1,
  TLF_LOCK_WR_PROTCFG_0,
  TLF_LOCK_WR_PROTCFG_1,
  TLF_LOCK_WR_PROTCFG_2,
  TLF_LOCK_WR_PROTCFG_3,
  TLF_LOCK_MAX
}SafeWdgExtTlf_LockJob;

/* SPI buffer indices for ChkInit job: */
typedef enum
{
  TLF_CHK_INIT_RD_RWDCFG0 = 0U,
  TLF_CHK_INIT_MAX
}SafeWdgExtTlf_ChkInitJob;

/* SPI buffer indices for DeInit job: */
typedef enum
{
  TLF_DE_INIT_WR_PROTCFG_0 = 0U,
  TLF_DE_INIT_WR_PROTCFG_1,
  TLF_DE_INIT_WR_PROTCFG_2,
  TLF_DE_INIT_WR_PROTCFG_3,
  TLF_DE_INIT_WR_WDCFG0,
  TLF_DE_INIT_WR_SYSPCFG1,
  TLF_DE_INIT_WR_SYSPCFG0,
  TLF_DE_INIT_WR_WDCFG1,
  TLF_DE_INIT_WR_PROTCFG_4,
  TLF_DE_INIT_WR_PROTCFG_5,
  TLF_DE_INIT_WR_PROTCFG_6,
  TLF_DE_INIT_WR_PROTCFG_7,
  TLF_DE_INIT_MAX
}SafeWdgExtTlf_DeInitJob;

/* SPI buffer indices for Activate job: */
typedef enum
{
  TLF_ENABLE_WR_PROTCFG_0 = 0U,
  TLF_ENABLE_WR_PROTCFG_1,
  TLF_ENABLE_WR_PROTCFG_2,
  TLF_ENABLE_WR_PROTCFG_3,
  TLF_ENABLE_WR_SYSPCFG0,
  TLF_ENABLE_WR_SYSPCFG1,
  TLF_ENABLE_WR_WDCFG0,
  TLF_ENABLE_WR_WDCFG1,
  TLF_ENABLE_WR_FWDCFG,
  TLF_ENABLE_WR_WWDCFG0,
  TLF_ENABLE_WR_WWDCFG1,
  TLF_ENABLE_RD_WWDSCMD,
  TLF_ENABLE_RD_SYSPCFG0,
  TLF_ENABLE_RD_SYSPCFG1,
  TLF_ENABLE_RD_WDCFG0,
  TLF_ENABLE_RD_WDCFG1,
  TLF_ENABLE_RD_FWDCFG,
  TLF_ENABLE_RD_WWDCFG0,
  TLF_ENABLE_RD_WWDCFG1,
  TLF_ENABLE_WR_PROTCFG_4,
  TLF_ENABLE_WR_PROTCFG_5,
  TLF_ENABLE_WR_PROTCFG_6,
  TLF_ENABLE_WR_PROTCFG_7,
  TLF_ENABLE_MAX
}SafeWdgExtTlf_EnableJob;

/* SPI buffer indices for Activate Service job: */
typedef enum
{
  TLF_ACT_SER_RD_DEVSTAT = 0U,
  TLF_ACT_SER_RD_FWDSTAT1,
  TLF_ACT_SER_RD_FWDSTAT0,
  TLF_ACT_SER_RD_WWDSTAT,
  TLF_ACT_SER_RD_WWDSCMD,
  TLF_ACT_SER_MAX
}SafeWdgExtTlf_ActSerJob;

/* SPI buffer indices for window watchdog service job: */
typedef enum
{
  TLF_SER_WWD_WR_WWDSCMD = 0U,
  TLF_SER_WWD_MAX
}SafeWdgExtTlf_ServiceWwdJob;

/* SPI buffer indices for functional watchdog service job: */
typedef enum
{
  TLF_SER_FWD_WR_FWDRSP_0 = 0U,
  TLF_SER_FWD_WR_FWDRSP_1,
  TLF_SER_FWD_WR_FWDRSP_2,
  TLF_SER_FWD_WR_FWDRSPSYNC,
  TLF_SER_FWD_MAX
}SafeWdgExtTlf_ServiceFwdJob;

/* SPI buffer indices for window & functional watchdog service job: */
typedef enum
{
  TLF_SER_FWD_WWD_WR_WWDSCMD = 0U,
  TLF_SER_FWD_WWD_WR_FWDRSP_0,
  TLF_SER_FWD_WWD_WR_FWDRSP_1,
  TLF_SER_FWD_WWD_WR_FWDRSP_2,
  TLF_SER_FWD_WWD_WR_FWDRSPSYNC,
  TLF_SER_FWD_WWD_MAX
}SafeWdgExtTlf_ServiceFwdWwdJob;

/* SPI buffer indices for Info job: */
typedef enum
{
  TLF_INFO_RD_DEVSTAT = 0U,
  TLF_INFO_RD_FWDSTAT1,
  TLF_INFO_RD_FWDSTAT0,
  TLF_INFO_RD_WWDSTAT,
  TLF_INFO_RD_WWDSCMD,
  TLF_INFO_MAX
}SafeWdgExtTlf_InfoJob;

/* SPI buffer indices for additional "Go-Normal" command in Info job: */
typedef enum
{
  TLF_INFO_NORMAL_WR_DEVCTRL = TLF_INFO_MAX,
  TLF_INFO_NORMAL_WR_DEVCTRLN = TLF_INFO_MAX + 1,
  TLF_INFO_NORMAL_MAX = TLF_INFO_MAX + 2
}SafeWdgExtTlf_InfoNormalJob;
#define IFX_SWDG_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static SafeWdgIf_ResultType SafeWdgExtTlf_lServiceWwd
(
  void
);
static SafeWdgIf_ResultType SafeWdgExtTlf_lServiceFwd
( 
  const uint8 UsedSeed,
  const uint32 Signature
);

static SafeWdgIf_ResultType SafeWdgExtTlf_lServiceFwdAndWwd
(
  const uint8 UsedSeed,
  const uint32 Signature
);

static void SafeWdgExtTlf_lProcessUsrReq
(
  void
);

static Std_ReturnType SafeWdgExtTlf_lCheckWrData
( 
  uint8 TxWordCount
);

static  Std_ReturnType SafeWdgExtTlf_lCheckDataCrc
(
  void
);

static  void SafeWdgExtTlf_lSetDataCrc
(
  void
);
static uint32 SafeWdgExtTlf_lCrc
(
  void
 );
static void SafeWdgExtTlf_lProcessCyclicRequest
(
  void
);

static void SafeWdgExtTlf_lProcessUnlock
( 
  void 
);
static void SafeWdgExtTlf_lProcessEnbleJob
( 
  void 
);
#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

#define IFX_SWDG_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/* TX and RX buffers need to be 4byte aligned. Therefore, they are defined
 * explicitly instead of being part of the local data set: */
static uint32                          SafeWdgExtTlf_TxBuf[SAFEWDGEXT_TLF_MAXBUF];
static uint32                          SafeWdgExtTlf_RxBuf[SAFEWDGEXT_TLF_MAXBUF];

#define IFX_SWDG_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_SWDG_START_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Local data set:  */
static SafeWdgExtTlf_DataType   SafeWdgExtTlf_Data;

#define IFX_SWDG_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#if (_SAFEWDG_TLF_DEBUG_ == TRUE )
  #pragma message("#### ~~~~ Debug version is being compiled! ~~~~ ####")
  #define IFX_SWDG_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
  #include "Ifx_MemMap.h"
  static uint32 SafeWdgExtTlf_kResponseTable[16] =
  {
    0xFF0FF000U,
    0xB040BF4FU,
    0xE919E616U,
    0xA656A959U,
    0x75857A8AU,
    0x3ACA35C5U,
    0x63936C9CU,
    0x2CDC23D3U,
    0xD222DD2DU,
    0x9D6D9262U,
    0xC434CB3BU,
    0x8B7B8474U,
    0x58A857A7U,
    0x17E718E8U,
    0x4EBE41B1U,
    0x01F10EFEU
  };
  #define IFX_SWDG_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
  #include "Ifx_MemMap.h"  
#endif
/*******************************************************************************
**                      Debug Purpose Definitions                             **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


#define IFX_SWDG_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       
**                                                                            
** Syntax           : SafeWdgIf_ResultType SafeWdgExtTlf_Init                 
**                      (const SafeWdgExtTlf_ConfigType* const ConfigPtr)     
**                                                                         
** Service ID       : none                                        
**                                                                         
** Sync/Async       : Asynchronous                           
**                                                                         
** Reentrancy       : Non Reentrant                          
**                                                                         
** Parameters(in)   : ConfigPtr - pointer to configuration                    
**                                                                           
** Parameters (out) : none                                               
**                                                                           
** Return value     :   SWDG_JOB_ACCEPTED  - Watchdog initialization accepted    
**                      SWDG_JOB_INV_PARAM - Invalid configuration             
 *                      SWDG_JOB_COM_ERR   - SPI communication error                          
**                                                                            
** Description      : Reads default configuration register data from TLF, and  
**                    disables the watchdog, Error pin monitoring .
**                                                                            
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgExtTlf_Init(const SafeWdgExtTlf_ConfigType* 
                                                                const ConfigPtr)
{
  SafeWdgIf_ResultType Result = SWDG_JOB_INV_PARAM;
  uint32 TempOmsr = 0U;
  
  /*Do init only if config pointer is not NULL */
  if( ConfigPtr != NULL_PTR)
  {
    /* Initialise QSPI communication: */
    if (SafeWdgQspi_Init(ConfigPtr->QspiCfgPtr) == SWDG_JOB_SUCCESS)
    {
      /*Set Job state to indicate init is under progress - TLF35584 will be
        unlocked first*/
      SafeWdgExtTlf_Data.JobState = SAFEWDGEXT_TLF_ULOCK_JOB;
      /* Store config pointer */
      SafeWdgExtTlf_Data.ConfigPtr = ConfigPtr;

      /* Initialize local data: */
      SafeWdgExtTlf_Data.LastSeed          = SAFEWDG_SEED_NOTVALID;
      SafeWdgExtTlf_Data.WdiRestoreFlag    = FALSE;
      SafeWdgExtTlf_Data.DeviceState       = SAFEWDG_TLF_UNDEFINEDSTATE;
      SafeWdgExtTlf_Data.ErrCtr            = SAFEWDG_ERR_NOTVALID;
      SafeWdgExtTlf_Data.RspCnt            = SAFEWDGEXT_TLF_RSPCNT_RESET_VAL;
      SafeWdgExtTlf_Data.ActivateRequested = FALSE;

      /* Set-up GPIO port if WWD triggering via GPIO pin (WDI) is selected: */
      if (TLF_WM_WWD_WDI == SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode)
      {
        TempOmsr = (uint32)((uint32)1U << (uint32)(ConfigPtr->WdiPin));
        /* Set WDI pin to high: */
        SafeWdgExtTlf_Data.ConfigPtr->WdiPort->OMSR.U = TempOmsr;
                                        
      }

      /*
         First 4 bytes   : Write Unlock sequence to unlock protected configuration registers
               5th byte  : Read System configuration 0 status
               6th byte  : Read System configuration 1 status
               7th byte  : Read Watchdog configuration 0 status
               8th byte  : Read Watchdog configuration 1 status
               9th byte  : Functional watchdog configuration status
               10th byte : Window watchdog configuration 0 status
               11th byte : Window watchdog configuration 1 status
      */
      SafeWdgExtTlf_TxBuf[TLF_UNLOCK_WR_PROTCFG_0] =
          SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_UNLOCK_SEQU0);
      SafeWdgExtTlf_TxBuf[TLF_UNLOCK_WR_PROTCFG_1] =
          SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_UNLOCK_SEQU1);
      SafeWdgExtTlf_TxBuf[TLF_UNLOCK_WR_PROTCFG_2] =
          SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_UNLOCK_SEQU2);
      SafeWdgExtTlf_TxBuf[TLF_UNLOCK_WR_PROTCFG_3] =
          SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_UNLOCK_SEQU3);
      SafeWdgExtTlf_TxBuf[TLF_UNLOCK_RD_RSYSPCFG0] =
          SAFEWDGEXT_TLF_RD_CMD(TLF_REG_RSYSPCFG0);
      SafeWdgExtTlf_TxBuf[TLF_UNLOCK_RD_RSYSPCFG1] =
          SAFEWDGEXT_TLF_RD_CMD(TLF_REG_RSYSPCFG1);
      SafeWdgExtTlf_TxBuf[TLF_UNLOCK_RD_RWDCFG0] =
          SAFEWDGEXT_TLF_RD_CMD(TLF_REG_RWDCFG0);
      SafeWdgExtTlf_TxBuf[TLF_UNLOCK_RD_RWDCFG1] =
          SAFEWDGEXT_TLF_RD_CMD(TLF_REG_RWDCFG1);
      SafeWdgExtTlf_TxBuf[TLF_UNLOCK_RD_RFWDCFG] =
          SAFEWDGEXT_TLF_RD_CMD(TLF_REG_RFWDCFG);
      SafeWdgExtTlf_TxBuf[TLF_UNLOCK_RD_RWWDCFG0] =
          SAFEWDGEXT_TLF_RD_CMD(TLF_REG_RWWDCFG0);
      SafeWdgExtTlf_TxBuf[TLF_UNLOCK_RD_RWWDCFG1] =
          SAFEWDGEXT_TLF_RD_CMD(TLF_REG_RWWDCFG1);

      SafeWdgExtTlf_Data.NoOfBytesToBeTfered = (uint8)TLF_UNLOCK_MAX;

      /*Send request to TLF35584*/
      SafeWdgQspi_TxRx(SafeWdgExtTlf_TxBuf,SafeWdgExtTlf_RxBuf,
                                  SafeWdgExtTlf_Data.NoOfBytesToBeTfered);
      Result = SWDG_JOB_ACCEPTED;
    } /* if (SafeWdgQspi_Init(ConfigPtr->QspiCfgPtr) == SWDG_JOB_SUCCESS)*/
    else
    {
      Result = SWDG_JOB_INV_PARAM;
    }
  } /* if (ConfigPtr != NULL_PTR) */

  /*Set job result state*/
  SafeWdgExtTlf_Data.JobResult = Result;

  /*Set up new CRC*/
  SafeWdgExtTlf_lSetDataCrc();
  
  return Result;
} /* SafeWdgExtTlf_Init */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                            
** Syntax           : SafeWdgIf_ResultType SafeWdgExtTlf_DeInit(void)         
**                                                                          
** Service ID       : none                                         
**                                                                          
** Sync/Async       : Asynchronous                            
**                                                                          
** Reentrancy       : Non Reentrant                           
**                                                                          
** Parameters(in)   : none                                       
**                                                                          
** Parameters (out) : none                                      
**                                                                          
** Return value     : SWDG_JOB_ACCEPTED - Watchdog de-initialization accepted 
**                    SWDG_JOB_FAILED_CRC - CRC check on internal data structure failed
**                    SWDG_JOB_BUSY       - last transmission is not yet completed
**                                                                            
** Description      : De-initializes the driver and disables the watchdog and 
**                    error pin monitoring                                
**                                                                            
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgExtTlf_DeInit(void)
{
  uint8 Wdcfg0Val = 0U;
  uint8 Syspcfg = 0U;
  uint8 Wdcfg1Val = 0U;
  uint8 Syspcfg0Val = 0U;
  SafeWdgIf_ResultType Result      = SWDG_JOB_BUSY;

  /*Check if driver is free. No other API's can alter this value now.*/
  if(SafeWdgExtTlf_Data.JobState == SAFEWDGEXT_TLF_IDLE)
  {
    /*Driver is free.This request can be accepted. Set JobState to
      SAFEWDGEXT_TLF_DEINIT_JOB and also set tempSafeWdgExtTlf_JobState*/
    SafeWdgExtTlf_Data.JobState = SAFEWDGEXT_TLF_DEINIT_JOB; 

    /* Change driver state to reset: */
    SafeWdgExtTlf_Data.DeviceState = SAFEWDG_TLF_RESET;

    /* invalidate stored information by destroying crc */
    SafeWdgExtTlf_Data.Crc ^= ~(SAFEWDGEXT_INVALIDATE_CRC);

    /*Unlock and disable watchdogs and error pin monitoring.*/
    /*
       First 4 bytes   : Write Unlock sequence to unlock protected configuration registers
             5th byte  : Protected Watchdog configuration request 0
             6th byte  : Protected System configuration request 1
             7th byte  : Protected System configuration request 0
             8th byte  : Protected Watchdog configuration request 0
             9-12 bytes: Write lock sequence to lock protected configuration registers
    */      
    SafeWdgExtTlf_TxBuf[TLF_DE_INIT_WR_PROTCFG_0] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_UNLOCK_SEQU0);
    SafeWdgExtTlf_TxBuf[TLF_DE_INIT_WR_PROTCFG_1] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_UNLOCK_SEQU1);
    SafeWdgExtTlf_TxBuf[TLF_DE_INIT_WR_PROTCFG_2] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_UNLOCK_SEQU2);
    SafeWdgExtTlf_TxBuf[TLF_DE_INIT_WR_PROTCFG_3] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_UNLOCK_SEQU3);
    
    /* Disable FWD*/    
    Wdcfg0Val &= ~SAFEWDGEXT_TLF_WDCFG0_FWDEN_B;    /* Wdcfg0Val = 0 & 0xFB ; Wdcfg0Val = 0;*/
    /* Disable WWD*/
    Wdcfg0Val &= ~SAFEWDGEXT_TLF_WDCFG0_WWDEN_B;    /* Wdcfg0Val = 0 & 0xF7 ; WWdcfg0Val = 0; So Final value of Wdcfg0Val = 0 */ 
    
    SafeWdgExtTlf_TxBuf[TLF_DE_INIT_WR_WDCFG0] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_WDCFG0, Wdcfg0Val);

    /*Disable Error pin monitoring and for other settings, set to user
      configured values*/
    Syspcfg &= ~SAFEWDGEXT_TLF_SYSPCFG1_EREN_B; /* Calculation: Syspcfg = 0 & 0xF7; Syspcfg = 0;*/
    Syspcfg |= ( SAFEWDGEXTTLF_ERRREC_TIME | SAFEWDGEXTTLF_SS2DEL_TIME |
                 SAFEWDGEXTTLF_ERR_REC_EN  | SAFEWDGEXTTLF_ERRSLP_EN ); /* Syspcfg = 0 | (User configured values) */
    SafeWdgExtTlf_TxBuf[TLF_DE_INIT_WR_SYSPCFG1] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_SYSPCFG1, Syspcfg);

    /*Set user configured values for these two registers:
    Protected System configuration request 0, Protected Watchdog configuration request 1 */
    Syspcfg0Val = SAFEWDGEXTTLF_STAND_BY_ENABLE;
    Wdcfg1Val   |= SAFEWDGEXTTLF_WDSLP_EN;
    SafeWdgExtTlf_TxBuf[TLF_DE_INIT_WR_SYSPCFG0] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_SYSPCFG0, Syspcfg0Val);
    SafeWdgExtTlf_TxBuf[TLF_DE_INIT_WR_WDCFG1] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_WDCFG1, Wdcfg1Val);
    
    /*Remaining protected configuration registers are not written since
      it would anyway get written with default values. But watchdog and error
      pin monitoring are enabled by default.*/
    SafeWdgExtTlf_TxBuf[TLF_DE_INIT_WR_PROTCFG_4] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_LOCK_SEQU0);
    SafeWdgExtTlf_TxBuf[TLF_DE_INIT_WR_PROTCFG_5] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_LOCK_SEQU1);
    SafeWdgExtTlf_TxBuf[TLF_DE_INIT_WR_PROTCFG_6] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_LOCK_SEQU2);
    SafeWdgExtTlf_TxBuf[TLF_DE_INIT_WR_PROTCFG_7] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_LOCK_SEQU3);

    SafeWdgExtTlf_Data.JobResult = SWDG_JOB_ACCEPTED;
    SafeWdgExtTlf_Data.NoOfBytesToBeTfered = (uint8)TLF_DE_INIT_MAX;
    SafeWdgQspi_TxRx(SafeWdgExtTlf_TxBuf,SafeWdgExtTlf_RxBuf,
                     SafeWdgExtTlf_Data.NoOfBytesToBeTfered);
    Result =  SWDG_JOB_ACCEPTED;
  }
  /*Set job result state*/
  SafeWdgExtTlf_Data.JobResult = Result;

  /*Set up new CRC*/
  SafeWdgExtTlf_lSetDataCrc();

  return Result;
} /* SafeWdgExtTlf_DeInit */


/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                            
** Syntax           : SafeWdgIf_ResultType SafeWdgExtTlf_Activate(void)       
**                                                                         
** Service ID       : none                                         
**                                                                         
** Sync/Async       : Asynchronous                           
**                                                                         
** Reentrancy       : Non Reentrant                          
**                                                                         
** Parameters(in)   : none                                      
**                                                                         
** Parameters (out) : none                                     
**                                                                         
** Return value     : SWDG_JOB_ACCEPTED: Watchdog Activation Job accepted
                      SWDG_JOB_FAILED_CRC: CRC check on internal data structure failed
                      SWDG_JOB_INV_STATE: TLF35584 is not in INIT or WAKE state
                      SWDG_JOB_BUSY: SafeWdgExtTlf driver is already busy, processing another job
                           
**                                                                            
** Description      : Enables the watchdog , error pin monitoring and puts the 
**                    driver to ACTIVE state.                             
**                                                                            
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgExtTlf_Activate(  void)
{
  SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;
  uint16 Syspcfg0 = SafeWdgExtTlf_Data.Syspcfg0;
  uint16 Syspcfg1 = SafeWdgExtTlf_Data.Syspcfg1;
  uint16 Wdcfg1   = SafeWdgExtTlf_Data.Wdcfg1;
  uint8 WdCfg0   = 0U; /* All bit fields of wdgcf0 reg are to be updated as part of activation. So this variable is initialized with 0 */
  
  /*Check for CRC */
  if(SafeWdgExtTlf_lCheckDataCrc() == E_OK)
  {
    /*Activate if TLF35584 is in INIT, NORMAL, and WAKE */
    if((SafeWdgExtTlf_Data.DeviceState == SAFEWDG_TLF_INIT) ||
       (SafeWdgExtTlf_Data.DeviceState == SAFEWDG_TLF_NORMAL) ||
       (SafeWdgExtTlf_Data.DeviceState == SAFEWDG_TLF_WAKE))
    {
      
      if(SafeWdgExtTlf_Data.JobState == SAFEWDGEXT_TLF_IDLE)
      {
        /*Set JobState to SAFEWDGEXT_TLF_ENBLE_JOB*/
        SafeWdgExtTlf_Data.JobState = SAFEWDGEXT_TLF_ENBLE_JOB;

        /*Unlock TLF35584 to write to protected configuration registers*/
        /*
         First 4 bytes   : Write Unlock sequence to unlock protected configuration registers
       */        
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_PROTCFG_0] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_UNLOCK_SEQU0);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_PROTCFG_1] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_UNLOCK_SEQU1);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_PROTCFG_2] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_UNLOCK_SEQU2);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_PROTCFG_3] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_UNLOCK_SEQU3);

        /*Configure TLF35584 based on user configuration*/

        /* Set error pin monitoring based on user configuration: */
        Syspcfg1 |= SAFEWDGEXT_TLF_SYSPCFG1_ERR_B;
         
        /* Setup Watchdog configuration register 0: */
        if (0U == SafeWdgExtTlf_Data.ConfigPtr->HeartbeatBase)
        {
          WdCfg0 = SAFEWDGEXT_TLF_WDCFG0_WDCYC_0_1MS_B;/*0.1ms wdg cycle time*/
        }
        else
        {
          WdCfg0 = SAFEWDGEXT_TLF_WDCFG0_WDCYC_1MS_B; /* 1ms wdg cycle time */
        }

        /* Check watchdog mode */
        if((TLF_WM_WWD_SPI == SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode) ||
           (TLF_WM_FWD_WWD_SPI == SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode))
        {
          /*Set up Watchdog in SPI mode*/
          WdCfg0 |= SAFEWDGEXT_TLF_WDCFG0_WWDTSEL_B;
          WdCfg0 |= SAFEWDGEXT_TLF_WDCFG0_WWDEN_B;
          if(TLF_WM_FWD_WWD_SPI == SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode)
          {
            /*Functional watchdog has to be enabled too*/
            WdCfg0 |= SAFEWDGEXT_TLF_WDCFG0_FWDEN_B;
          }
        }

        if(TLF_WM_WWD_WDI == SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode)
        {
          /*Window watchdog in WDI mode selected by user*/
          WdCfg0 |= SAFEWDGEXT_TLF_WDCFG0_WWDEN_B;
        }

        if(TLF_WM_FWD == SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode)
        {
          /*Only functional watchdog selected by user*/
          WdCfg0 |= SAFEWDGEXT_TLF_WDCFG0_FWDEN_B;
        }

        /* WWD error threshold: */
        WdCfg0 |= (uint8)(SafeWdgExtTlf_Data.ConfigPtr->WWDWdgErrorThreshold
                                             << SAFEWDGEXT_TLF_WDCFG0_WDETH_P);
        /* FWD error threshold: */
        Wdcfg1 = (uint16)SafeWdgExtTlf_Data.ConfigPtr->
                              FWDWdgErrorThreshold & SAFEWDGEXT_TLF_WDCFG1_FWETH_M;

        /*Update these configuration registers based on user configuration */
        Syspcfg0 = SAFEWDGEXTTLF_STAND_BY_ENABLE;
        Syspcfg1 |= ( SAFEWDGEXTTLF_ERRREC_TIME |SAFEWDGEXTTLF_SS2DEL_TIME |
                      SAFEWDGEXTTLF_ERR_REC_EN  | SAFEWDGEXTTLF_ERRSLP_EN );
        Wdcfg1   |= SAFEWDGEXTTLF_WDSLP_EN;

        /*No partial configuration of protected registers allowed.So write
          values to all protected registers during each unlock-lock sequence.*/
        /*     
               5th byte  : Protected System configuration request 0
               6th byte  : Protected System configuration request 1
               7th byte  : Protected Watchdog configuration request 0
               8th byte  : Protected Watchdog configuration request 1
               9th byte  : Protected Functional watchdog configuration
               10th byte : Protected Window watchdog configuration request
               11th byte : Protected Window watchdog configuration request
               12th byte : Window watchdog service command                
         */         
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_SYSPCFG0] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_SYSPCFG0, Syspcfg0);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_SYSPCFG1] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_SYSPCFG1, Syspcfg1);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_WDCFG0] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_WDCFG0, WdCfg0);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_WDCFG1] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_WDCFG1, Wdcfg1);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_FWDCFG] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDCFG,
                                  (SafeWdgExtTlf_Data.ConfigPtr->FwdHeartbeat));
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_WWDCFG0] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_WWDCFG0,
                          (SafeWdgExtTlf_Data.ConfigPtr->CloseWindowHeartbeat));
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_WWDCFG1] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_WWDCFG1,
                           (SafeWdgExtTlf_Data.ConfigPtr->OpenWindowHeartbeat));
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_RD_WWDSCMD] =
            SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WWDSCMD);

        /*Read back all protected register values to verify correctness*/
      /*
               13th byte  : Read System configuration 0 status
               14th byte  : Read System configuration 1 status
               15th byte  : Read Watchdog configuration 0 status
               16th byte  : Read Watchdog configuration 1 status
               17th byte  : Functional watchdog configuration status
               18th byte : Window watchdog configuration 0 status
               19th byte : Window watchdog configuration 1 status
      */        
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_RD_SYSPCFG0] =
            SAFEWDGEXT_TLF_RD_CMD(TLF_REG_SYSPCFG0);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_RD_SYSPCFG1] =
            SAFEWDGEXT_TLF_RD_CMD(TLF_REG_SYSPCFG1);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_RD_WDCFG0] =
            SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WDCFG0);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_RD_WDCFG1] =
            SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WDCFG1);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_RD_FWDCFG] =
            SAFEWDGEXT_TLF_RD_CMD(TLF_REG_FWDCFG);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_RD_WWDCFG0] =
            SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WWDCFG0);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_RD_WWDCFG1] =
            SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WWDCFG1);

        /*
           20-23 bytes: Write lock sequence to lock protected configuration registers
        */        
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_PROTCFG_4] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_LOCK_SEQU0);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_PROTCFG_5] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_LOCK_SEQU1);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_PROTCFG_6] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_LOCK_SEQU2);
        SafeWdgExtTlf_TxBuf[TLF_ENABLE_WR_PROTCFG_7] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_LOCK_SEQU3);

        SafeWdgExtTlf_Data.NoOfBytesToBeTfered = (uint8)TLF_ENABLE_MAX;
        SafeWdgQspi_TxRx(SafeWdgExtTlf_TxBuf,SafeWdgExtTlf_RxBuf,
                                        SafeWdgExtTlf_Data.NoOfBytesToBeTfered);
        Result = SWDG_JOB_ACCEPTED;                                
      }
      else
      {
        Result = SWDG_JOB_BUSY;
      }        
    }
    else
    {
      Result = SWDG_JOB_INV_STATE;
    }
    /*Set job result state*/
    SafeWdgExtTlf_Data.JobResult = Result;

    /*Set up new CRC*/
    SafeWdgExtTlf_lSetDataCrc();
  }

  return Result;
} /* SafeWdgExtTlf_Activate */


/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                            
** Syntax           : SafeWdgIf_ResultType SafeWdgExtTlf_Service 
**                     ( const uint32 Signature)     
**                                                            
** Service ID       : none                            
**                                                            
** Sync/Async       : Asynchronous              
**                                                            
** Reentrancy       : Non Reentrant             
**                                                            
** Parameters (in) : Signature - The signature to be used for watchdog service                          
**                                                                     
** Parameters (out) : none                                 
**                                                                     
** Return value     :   SWDG_JOB_ACCEPTED: Job accepted and ongoing
                        SWDG_JOB_FAILED_CRC: CRC check on internal data structure failed
                        SWDG_JOB_INV_STATE: TLF35584 is not in INIT, SLEEP, WAKE or NORMAL state
                        SWDG_JOB_BUSY: SafeWdgExtTlf driver is already busy, processing another job
**                                                                            
** Description      : Services the watchdog and requests a new seed value     
**                                                                            
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgExtTlf_Service(  const uint32 Signature)
{
  SafeWdgIf_ResultType  Result     = SWDG_JOB_FAILED_CRC;
  uint8 UsedSeed                   = SafeWdgExtTlf_Data.LastSeed;

  if(SafeWdgExtTlf_lCheckDataCrc() == E_OK) 
  {
    /* Servicing is possible if TLF35584 is in INIT, WAKE or NORMAL mode */
    if( (SafeWdgExtTlf_Data.DeviceState == SAFEWDG_TLF_INIT)  ||
         (SafeWdgExtTlf_Data.DeviceState == SAFEWDG_TLF_WAKE)  ||
         (SafeWdgExtTlf_Data.DeviceState == SAFEWDG_TLF_NORMAL)
        )
    {
      if(TLF_WM_WWD_WDI != SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode)
      {

        if(SafeWdgExtTlf_Data.JobState == SAFEWDGEXT_TLF_IDLE)
        {
          /*Set JobState to  SAFEWDGEXT_TLF_SER_JOB */
          SafeWdgExtTlf_Data.JobState  = SAFEWDGEXT_TLF_SER_JOB;

          if (TLF_WM_FWD == SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode)
          {
            /* Service functional watchdog: */
            Result = SafeWdgExtTlf_lServiceFwd(UsedSeed, Signature);

            /* Reset seed: */
            SafeWdgExtTlf_Data.LastSeed = SAFEWDG_SEED_NOTVALID;
          } /* if (TLF_WM_FWD == SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode)*/
          else if (TLF_WM_FWD_WWD_SPI == 
                                    SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode)
          {
            /* Service functional, as well as Window watchdog: */
            Result = SafeWdgExtTlf_lServiceFwdAndWwd(UsedSeed, Signature);
            
            /* Reset seed: */
            SafeWdgExtTlf_Data.LastSeed = SAFEWDG_SEED_NOTVALID;
          }
          else
          {
            /* Service window watchdog: */
            Result = SafeWdgExtTlf_lServiceWwd();
          } /* if (TLF_WM_FWD != SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode) */
        } /* if(SafeWdgExtTlf_Data.JobState == SAFEWDGEXT_TLF_IDLE)*/
        else
        {
          Result = SWDG_JOB_BUSY;
        }
      }
      else
      {
        /* Service window watchdog: */
        Result = SafeWdgExtTlf_lServiceWwd();
      }
    }
    else
    {
      Result = SWDG_JOB_INV_STATE;
    }

    /*Set job result state*/
    SafeWdgExtTlf_Data.JobResult = Result;

    /*Set up new CRC*/
    SafeWdgExtTlf_lSetDataCrc();
  }

  return Result;
} /* SafeWdgExtTlf_Service */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SafeWdgIf_ResultType SafeWdgExtTlf_GetWdgInfo(void)               **
**                                                                            **
** Description :   Initiates the read of TLF status registers                 **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
** Parameters (out): None                                                     **
** Return value    : SWDG_JOB_ACCEPTED  : Job accepted and ongoing            **
**                   SWDG_JOB_FAILED_CRC: CRC check on internal 
                                          data structure failed               **
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgExtTlf_GetWdgInfo (void)
{
  SafeWdgIf_ResultType Result      = SWDG_JOB_FAILED_CRC;
  uint16 DevCtrl   = 0U;
  uint16 DevCtrlN  = 0U;  
  if(SafeWdgExtTlf_lCheckDataCrc() == E_OK)
  {
    
    if(SafeWdgExtTlf_Data.JobState == SAFEWDGEXT_TLF_IDLE)
    {
      /*Set JobState to SAFEWDGEXT_TLF_INFO_JOB */
      SafeWdgExtTlf_Data.JobState = SAFEWDGEXT_TLF_INFO_JOB;

      /*Device status, seed value, error counter of functional watchdog,
        error counter of window watchdog and Window watchdog service command
        values are requested from TLF. This set of information is received 
        irrespective of the TLF35584 mode. This information will be used by 
        the driver based on the modes .
        This is done to avoid "if" checks in runtime to improve the drivers 
        runtime performance.*/
      SafeWdgExtTlf_TxBuf[TLF_INFO_RD_DEVSTAT] =
          SAFEWDGEXT_TLF_RD_CMD(TLF_REG_DEVSTAT);
      SafeWdgExtTlf_TxBuf[TLF_INFO_RD_FWDSTAT1] =
          SAFEWDGEXT_TLF_RD_CMD(TLF_REG_FWDSTAT1);
      SafeWdgExtTlf_TxBuf[TLF_INFO_RD_FWDSTAT0] =
          SAFEWDGEXT_TLF_RD_CMD(TLF_REG_FWDSTAT0);
      SafeWdgExtTlf_TxBuf[TLF_INFO_RD_WWDSTAT] =
          SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WWDSTAT);
      SafeWdgExtTlf_TxBuf[TLF_INFO_RD_WWDSCMD] =
          SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WWDSCMD);
      SafeWdgExtTlf_Data.NoOfBytesToBeTfered = (uint8)TLF_INFO_MAX;

      /* Send additional move-to-normal command in case the error counters
       * are sufficient below the threshold: */
      if (SafeWdgExtTlf_Data.ActivateRequested == TRUE)
      {
        uint8 ErrLimitWWD =
            ((uint8)SafeWdgExtTlf_Data.ConfigPtr->WWDWdgErrorThreshold > 1u) ?
            ((uint8)SafeWdgExtTlf_Data.ConfigPtr->WWDWdgErrorThreshold - 2u) :
            0x0u;
        uint8 ErrLimitFWD = ((uint8)SafeWdgExtTlf_Data.ConfigPtr->FWDWdgErrorThreshold > 1u) ?
            ((uint8)SafeWdgExtTlf_Data.ConfigPtr->FWDWdgErrorThreshold - 2u) :
            0x0u;
        ErrLimitFWD = (uint8)((uint8)ErrLimitFWD << 4);
        /* Check ErrLimit for WWD and FWD: */
        if ((((uint8)SafeWdgExtTlf_Data.ErrCtr & 0x0Fu) <= ErrLimitWWD) &&
            (((uint8)SafeWdgExtTlf_Data.ErrCtr & 0xF0u) <= ErrLimitFWD))
        {
          /*Get user configured values for VREF,COMEN,TRK1,TRK2*/
          DevCtrl = (SAFEWDGEXTTLF_VREF_EN | SAFEWDGEXTTLF_COM_EN |
                   SAFEWDGEXTTLF_TRK1_EN | SAFEWDGEXTTLF_TRK2_EN );
        
          DevCtrl |= SAFEWDGEXT_TLF_NOR_STATE_M;
          /*Write inverse values to DEVCTRLN register*/
          DevCtrlN = SAFEWDGEXT_TLF_BITMASK ^ DevCtrl;
          /*Move TLF35584 by writing to DEVCTRL and DEVCTRLN register*/          
          SafeWdgExtTlf_TxBuf[TLF_INFO_NORMAL_WR_DEVCTRL] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_DEVCTRL, DevCtrl);
          SafeWdgExtTlf_TxBuf[TLF_INFO_NORMAL_WR_DEVCTRLN] =
            SAFEWDGEXT_TLF_WR_CMD(TLF_REG_DEVCTRLN, DevCtrlN);
          SafeWdgExtTlf_Data.NoOfBytesToBeTfered = (uint8)TLF_INFO_NORMAL_MAX;
          SafeWdgExtTlf_Data.ActivateRequested = FALSE;
        }
      }

      SafeWdgQspi_TxRx(SafeWdgExtTlf_TxBuf,SafeWdgExtTlf_RxBuf,
                             SafeWdgExtTlf_Data.NoOfBytesToBeTfered);
      Result = SWDG_JOB_ACCEPTED;                       
    }
    else
    {
      Result = SWDG_JOB_BUSY;
    }  
    /*Set job result state*/
    SafeWdgExtTlf_Data.JobResult = Result;
    /*Set up new CRC*/
    SafeWdgExtTlf_lSetDataCrc();
  }

  return Result;
} 
/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                            
** Syntax           : SafeWdgIf_ResultType SafeWdgExtTlf_GetSeed              
**                      (uint8* const NextSeedPtr)                               
**                                                                        
** Service ID       : none                                       
**                                                                        
** Sync/Async       : Synchronous                          
**                                                                        
** Reentrancy       : Non -Reentrant                               
**                                                                        
** Parameters (in) :  none                                     
**                                                                        
** Parameters (out) : NextSeedPtr - Pointer that will receive the next seed  value 
**                     in case of success,remains unchanged   otherwise                                    
**                                                                            
** Return value     : SWDG_JOB_SUCCESS   : Operation successfully performed
                      SWDG_JOB_FAILED_CRC: CRC check on internal data structure failed
                      SWDG_JOB_INV_PARAM : Invalid parameter supplied
                      SWDG_JOB_INVALID_SEED : No valid seed available
        
**                                                                            
** Description      : Returns the next seed value to be used.                 
**                                                                            
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgExtTlf_GetSeed(uint8* const NextSeedPtr)
{
  SafeWdgIf_ResultType  Result = SWDG_JOB_FAILED_CRC;

  if(SafeWdgExtTlf_lCheckDataCrc() == E_OK)
  {
    /* Check for NULL pointer */
    if (NULL_PTR != NextSeedPtr)
    {
      /*Check if the seed is valid.*/
      if (SAFEWDG_SEED_NOTVALID != SafeWdgExtTlf_Data.LastSeed)
      {
        /*Update new seed and set result to SUCCESS.Seed will be updated when 
          GetWdgInfo() is called and will be updated in Main().*/
        *NextSeedPtr = SafeWdgExtTlf_Data.LastSeed;
        Result    = SWDG_JOB_SUCCESS;
      } /* if (SAFEWDG_SEED_NOTVALID == SafeWdgExtTlf_Data.LastSeed) */
      else
      {
        Result = SWDG_JOB_INVALID_SEED;
      }
    } /* if (NULL_PTR != NextSeedPtr) */
    else
    {
      Result = SWDG_JOB_INV_PARAM;
    }

  }

  return Result;
} /* SafeWdgExtTlf_GetSeed */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                            
** Syntax           : SafeWdgIf_StateType SafeWdgExtTlf_GetState(void)  
**                                                                           
** Service ID       : none                                          
**                                                                           
** Sync/Async       : Synchronous                             
**                                                                           
** Reentrancy       : Non-Reentrant                                  
**                                                                           
** Parameters (in) :  none                                        
**                                                                           
** Parameters (out) : none                                       
**                                                                           
** Return value     : 
**            SAFE_WDG_INIT         
**            SAFE_WDG_NORMAL     
**            SAFE_WDG_SLEEP      
**            SAFE_WDG_STANDBY    
**            SAFE_WDG_WAKE
              SAFE_WDG_RESET       
**            SAFEWDG_TLF_UNDEFINEDSTATE 
**
** Description      : Returns the current state of the watchdog driver.       
**                                                                            
*******************************************************************************/
SafeWdgExt_StateType SafeWdgExtTlf_GetState(void)
{
  SafeWdgExt_StateType DeviceState;

  /*Update the device state information requested by GetWdgInfo() API.*/
  if(SafeWdgExtTlf_lCheckDataCrc() == E_OK)
  {
    DeviceState = SafeWdgExtTlf_Data.DeviceState;
  }
  else 
  {
    DeviceState = SAFEWDG_TLF_UNDEFINEDSTATE;
  }
  
  return DeviceState;
} /* SafeWdgExtTlf_GetState */


/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                            
** Syntax           : SafeWdgIf_ResultType SafeWdgExtTlf_GetJobResult ()                      
**                                                                       
** Service ID       : none                                       
**                                                                       
** Sync/Async       : Synchronous                         
**                                                                       
** Reentrancy       : Non Reentrant                               
**                                                                       
** Parameters (in) :  none                                    
**                                                                       
** Parameters (out) : none                                   
**                                                                       
** Return value     : SWDG_JOB_SUCCESS   : Job successfully performed
                      SWDG_JOB_ACCEPTED  : Accepted Job still ongoing
                      SWDG_JOB_FAILED    : Program flow consistency error; should never be returned
                      SWDG_JOB_FAILED_CRC: CRC check on internal data structure failed
                      SWDG_JOB_INV_STATE : Request could not be processed because TLF35584 is in an invalid state
                      SWDG_JOB_BUSY      : SafeWdgExtTlf driver is already busy, processing another job
                      SWDG_JOB_INV_PARAM : An invalid parameter was supplied
                      SWDG_JOB_INVALID_SEED : Requesting seed value failed because no seed is currently available: check sequence of API calls
                      SWDG_JOB_READBACK_FAIL: Values written to TLF35584 configuration registers did not match values read back or wrong values echo’ed back by the TLF35584
                      SWDG_JOB_COM_ERR   : SPI communication error or SafeWdgQspi driver error
             
**                                                                            
** Description      : SafeWdgExtTlf_GetJobResult returns the state / result  of
**                     the last asynchronous data transmission, i.e. either  
**                      watchdog servicing or user requests.                    
**                                                                            
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgExtTlf_GetJobResult(void)
{
  SafeWdgIf_ResultType Result = SWDG_JOB_FAILED_CRC;

  if(SafeWdgExtTlf_lCheckDataCrc() == E_OK)
  {
    Result = (SafeWdgExtTlf_Data.JobResult);
  }

  return Result;
} /* SafeWdgExtTlf_GetJobResult */


/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                    
** Syntax            :  SafeWdgIf_ResultType SafeWdgExtTlf_UserRequest      
**                      (SafeWdgIf_CmdType* const UserCmdPtr,            
**                       const uint8 Count)                               
**                                                                    
** Service ID       :  none                                              
**                                                                    
** Sync/Async       :  Asynchronus                         
**                                                                    
** Reentrancy       :  Non Reentrant                                     
**                                                                    
** Parameters (in)  :  *UserCmdPtr - Array of user commands to send to the TLF 
**                     Count - Number of entries in UserCmdPtr                
**                                                                    
** Parameters (out) : *UserCmdPtr - Once the data transmission has completed, the 
**                              responses from the watchdog will be copied to
**                              the UserCmdPtr entries, i.e. the original data   
**                              in UserCmdPtr array will be overwritten          
**                                                                            
** Return value     :  SWDG_JOB_ACCEPTED: Job accepted and ongoing
                       SWDG_JOB_FAILED_CRC: CRC check on internal data structure failed
                       SWDG_JOB_INV_PARAM: Invalid parameter supplied
                       SWDG_JOB_BUSY: SafeWdgExtTlf driver is already busy, processing another job
                       
** Description      : This API sends user requests to the watchdog and        
**                    returns the watchdog response to the caller. The        
**                    requests are transferred asynchronously and the   
**                    SafeWdgExtTlf_GetJobResult API needs to be polled to    
**                    check whether transmission succeeded and the response   
**                    is available.                                           
**                                                                            **
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgExtTlf_UserRequest(SafeWdgIf_CmdType* const UserCmdPtr,
                                                const uint8 Count)
{
  uint8  Index;
  uint16 TxValue = 0U;  
  SafeWdgIf_ResultType  Result     = SWDG_JOB_FAILED_CRC;

  /*Check for null pointer*/
  if(SafeWdgExtTlf_lCheckDataCrc() == E_OK)
  {
    if( NULL_PTR != UserCmdPtr)
    {
      /*Check if this "Count" value could be processed*/
      if( (Count > 0U) &&  (Count <= SAFEWDGEXT_TLF_MAXBUF) )
      {
        if(SafeWdgExtTlf_Data.JobState == SAFEWDGEXT_TLF_IDLE)
        {
          /*Set JobState to SAFEWDGEXT_TLF_USR_JOB */
          SafeWdgExtTlf_Data.JobState = SAFEWDGEXT_TLF_USR_JOB;

          /* Save user request buffer and size: */
          SafeWdgExtTlf_Data.RequestPtr = UserCmdPtr;
          SafeWdgExtTlf_Data.NoOfBytesToBeTfered = Count;

          /* Copy user command and data to the TX buffer: */
          for (Index = 0U; Index < Count; Index++)
          {
            TxValue = ( ( (uint16)UserCmdPtr[Index].ReqCmd) << 
                                                        SAFEWDGEXT_TLF_CMD_POS);
            TxValue = (TxValue | (uint16)UserCmdPtr[Index].UserData) ; 
            SafeWdgExtTlf_TxBuf[Index] = TxValue;
            SafeWdgExtTlf_RxBuf[Index] = 0U;
          } /* for (Index = 0U; Index < Count; Index++) */

          SafeWdgQspi_TxRx(SafeWdgExtTlf_TxBuf, SafeWdgExtTlf_RxBuf, Count);
          Result = SWDG_JOB_ACCEPTED;
        }
        else
        {
          Result = SWDG_JOB_BUSY;
        }
      }
      else
      {
        Result = SWDG_JOB_INV_PARAM;
      }  
    }
    else
    {
      Result = SWDG_JOB_INV_PARAM;
    }
    /*Set job result state*/
    SafeWdgExtTlf_Data.JobResult = Result;

    /*Set up new CRC*/
    SafeWdgExtTlf_lSetDataCrc();
  }

  return Result;
} /* SafeWdgExtTlf_UserRequest */

 
/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                    
** Syntax           : void SafeWdgExtTlf_lProcessCyclicRequest(void)    
**                                                                    
** Service ID       : none                                              
**                                                                    
** Sync/Async       : Synchronous                                     
**                                                                    
** Reentrancy       : Non Reentrant                                     
**                                                                    
** Parameters(in)   : none                                              
**                                                                    
** Parameters (out) : none                                            
**                                                                    
** Return value     : None                  
**                                                                    
** Description      : Process cyclic responses received from TLF                                     
**                                                                    
*******************************************************************************/
static void SafeWdgExtTlf_lProcessCyclicRequest(void)
{
  uint8 DeviceState;
  uint8 WwdgErrCtr = 0U;
  uint8 FuncWdgErrCtr = 0U;

  /*process device information received from TLF35584*/
  DeviceState                    =
    (uint8)(SafeWdgExtTlf_RxBuf[TLF_INFO_RD_DEVSTAT] & SAFEWDGEXT_TLF_STATE_M);
  FuncWdgErrCtr                  =
    (uint8)(SafeWdgExtTlf_RxBuf[TLF_INFO_RD_FWDSTAT1] & SAFEWDGEXT_TLF_ECNT_M);
  SafeWdgExtTlf_Data.LastSeed    =
    (uint8)(SafeWdgExtTlf_RxBuf[TLF_INFO_RD_FWDSTAT0] &
            SAFEWDGEXT_TLF_FW_QUEST_M);
  SafeWdgExtTlf_Data.RspCnt    =
    (uint8)((SafeWdgExtTlf_RxBuf[TLF_INFO_RD_FWDSTAT0] &
            SAFEWDGEXT_TLF_FW_RSPCNT_M) >> 4U);            
  WwdgErrCtr                     =
    (uint8)(SafeWdgExtTlf_RxBuf[TLF_INFO_RD_WWDSTAT] & SAFEWDGEXT_TLF_ECNT_M);
  SafeWdgExtTlf_Data.LastWwdScmd =
    (uint8)SafeWdgExtTlf_RxBuf[TLF_INFO_RD_WWDSCMD];

  /*Update device status*/
  if( (DeviceState > SAFEWDGEXT_TLF_DEVSTAT_RES) &&
                            (DeviceState <= SAFEWDGEXT_TLF_DEVSTAT_WAK) )
  {
    SafeWdgExtTlf_Data.DeviceState = (SafeWdgExt_StateType)DeviceState;
  }
  else
  {
    SafeWdgExtTlf_Data.DeviceState = SAFEWDG_TLF_UNDEFINEDSTATE;
  }

  /* Store both, WWD and FWD error counters: */
  SafeWdgExtTlf_Data.ErrCtr = ((uint8)((FuncWdgErrCtr & SAFEWDGEXT_TLF_MASK_BIT) << 4U) | WwdgErrCtr);


  /*Cyclic request successful*/
  SafeWdgExtTlf_Data.JobResult = SWDG_JOB_SUCCESS;

  /*Cyclic request completed*/
  SafeWdgExtTlf_Data.JobState = SAFEWDGEXT_TLF_IDLE;
}

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                    
** Syntax           : void SafeWdgExtTlf_Mainfunction(void)                 
**                                                                    
** Service ID       : none                                              
**                                                                    
** Sync/Async       : Synchronous                                     
**                                                                    
** Reentrancy       : Non Reentrant                                     
**                                                                    
** Parameters (in) :  none                                              
**                                                                    
** Parameters (out) : none                                            
**                                                                    
** Return value     : none                                            
**                                                                    
** Description      : Main function handles watchdog servicing and cyclically
**                  . updates device information.
**                    If the window watchdog mode is enabled, the WDI pin will b 
**                    set to high in this API.All asynchronous request's 
                      responses will be evaluated in this function.
**                    It should be called periodically by the OS or the
                      application software.     
**                                                                    
*******************************************************************************/
void SafeWdgExtTlf_MainFunction(void)
{
  boolean SafeWdgExtTlf_QSPITransferComplete ;
  uint32  SafeWdgExtTlf_QSPIError = 0U;
  uint32  TempOmsr  = 0U;
  uint8   LoopIndex = 0U;
  uint32  RxValue   = 0U;
  uint32  TxValue   = 0U;
  boolean ProtectedRegistersConfigNotOk = FALSE;

  if(SafeWdgExtTlf_lCheckDataCrc() == E_OK)
  {
    /* Check if WDI pin is to be toggled:.This will be done only if TLF35584 is
      configured in window watchdog - WDI mode. This flag will always be set 
      to FALSE (set to FALSE in Init API) if window watchdog - WDI mode is not
      used.*/
    if (TRUE == SafeWdgExtTlf_Data.WdiRestoreFlag)
    {
      /* Set WDI pin: */
      TempOmsr = (uint32)((uint32)1U << (uint32)
                                     (SafeWdgExtTlf_Data.ConfigPtr->WdiPin));
      SafeWdgExtTlf_Data.ConfigPtr->WdiPort->OMSR.U = TempOmsr;
      /* Clear task flag: */ 
      SafeWdgExtTlf_Data.WdiRestoreFlag = FALSE;

    } /* if ((boolean)TRUE == SafeWdgExtTlf_Data.WdiRestoreFlag) */
    
    /*Proceed further only if any Asynchronous activity is pending /requested*/
    if(SafeWdgExtTlf_Data.JobState != SAFEWDGEXT_TLF_IDLE)
    {
      /*Call RxDone() to know the status of Async request placed by TLF API's*/
      SafeWdgExtTlf_QSPITransferComplete = 
                                   SafeWdgQspi_RxDone(&SafeWdgExtTlf_QSPIError);

      /* Check for QSPI communication errors*/
      if ( SafeWdgExtTlf_QSPIError == 0x0U)
      {
        /*If Transfer is complete process the responses*/
        if (SafeWdgExtTlf_QSPITransferComplete == TRUE)
        {
          /*Check if all write commands were cycled back by TLF35584*/
          if(SafeWdgExtTlf_lCheckWrData
                              (SafeWdgExtTlf_Data.NoOfBytesToBeTfered) == E_OK)
          {
            switch (SafeWdgExtTlf_Data.JobState)
            {
              
               case SAFEWDGEXT_TLF_ULOCK_JOB:
                    SafeWdgExtTlf_lProcessUnlock();
                    break;

               case SAFEWDGEXT_TLF_LOCK_JOB:
                    for(LoopIndex = 0U; ((LoopIndex <
                        (uint8)(TLF_LOCK_WR_PROTCFG_0 - TLF_LOCK_RD_SYSPCFG0)) &&
                        (ProtectedRegistersConfigNotOk != TRUE) ); LoopIndex++)
                    {
                      /*Check if data written to protected configuration registers
                        are fine. TLF35584 will send inverted values of data written
                        to protected registers.*/
                      RxValue =SafeWdgExtTlf_RxBuf[(LoopIndex +
                                                    (uint8)TLF_LOCK_RD_SYSPCFG0)] &
                                                                   (uint32)0x00FFU;
                      TxValue = SafeWdgExtTlf_TxBuf[LoopIndex] &
                                                                   (uint32)0x00FFU;
                      
                      /*Data send (Tx) and read request from the protected registers
                       (Rx) xor will be FF,if data written 2 protected configuration
                       registers are OK.*/
                      if(( TxValue ^ RxValue) != (uint32)0xFFU)
                      {
                        ProtectedRegistersConfigNotOk = TRUE;
                      }
                    }
                    if(ProtectedRegistersConfigNotOk == FALSE)
                    {
                      /*Issue command to check if disable request by the driver 
                        reflects  at TLF35584 status too.*/
                      SafeWdgExtTlf_TxBuf[TLF_CHK_INIT_RD_RWDCFG0] =
                                            SAFEWDGEXT_TLF_RD_CMD(TLF_REG_RWDCFG0);
                      SafeWdgExtTlf_Data.NoOfBytesToBeTfered =
                                            (uint8)TLF_CHK_INIT_MAX;
                      SafeWdgExtTlf_Data.JobState  = SAFEWDGEXT_TLF_CHK_INIT_JOB;
                      SafeWdgQspi_TxRx(SafeWdgExtTlf_TxBuf,
                                       SafeWdgExtTlf_RxBuf,
                                       SafeWdgExtTlf_Data.NoOfBytesToBeTfered);
                    }
                    else
                    {
                      SafeWdgExtTlf_Data.JobResult = SWDG_JOB_READBACK_FAIL;
                      SafeWdgExtTlf_Data.JobState  = SAFEWDGEXT_TLF_IDLE;
                    }
                    break;

               case SAFEWDGEXT_TLF_CHK_INIT_JOB:
                    /*Read RWDCFG0 register to check if watchdogs are disabled(To 
                    check if disable request is executed as intended)*/
                    if((SAFEWDGEXT_TLF_RWDCFG0_M & 
                        (uint8)SafeWdgExtTlf_RxBuf[TLF_CHK_INIT_RD_RWDCFG0]) == 0U)
                    {
                      SafeWdgExtTlf_Data.DeviceState = SAFEWDG_TLF_INIT;
                      SafeWdgExtTlf_Data.JobResult        = SWDG_JOB_SUCCESS; 
                    }
                    else
                    {
                      /*Watchdog not initialized properly. Set the state to unknown/
                        reset*/
                      SafeWdgExtTlf_Data.DeviceState = SAFEWDG_TLF_RESET;
                      SafeWdgExtTlf_Data.JobResult   = SWDG_JOB_INIT_FAIL; 
                    }
                    SafeWdgExtTlf_Data.JobState      = SAFEWDGEXT_TLF_IDLE;
                    break;

                    
               case SAFEWDGEXT_TLF_ENBLE_JOB:
                    SafeWdgExtTlf_lProcessEnbleJob(); 
                    break;

               case SAFEWDGEXT_TLF_ACT_SRV_JOB:
                    /* Activation successful.
                       Get seed and WwdScmd value for servicing */
                    SafeWdgExtTlf_lProcessCyclicRequest();
                    break;

               case SAFEWDGEXT_TLF_INFO_JOB:
                     SafeWdgExtTlf_lProcessCyclicRequest();
                     break;

               case SAFEWDGEXT_TLF_SER_JOB:
                    SafeWdgExtTlf_Data.JobResult = SWDG_JOB_SUCCESS;
                    SafeWdgExtTlf_Data.JobState = SAFEWDGEXT_TLF_IDLE;
                    break;

               case SAFEWDGEXT_TLF_USR_JOB:
                    SafeWdgExtTlf_lProcessUsrReq();
                    break;

               case SAFEWDGEXT_TLF_DEINIT_JOB:
                     /* De-initialize QSPI driver: */ 
                     SafeWdgQspi_DeInit();
                     SafeWdgExtTlf_Data.JobResult = SWDG_JOB_SUCCESS;
                     SafeWdgExtTlf_Data.JobState = SAFEWDGEXT_TLF_IDLE;
                     break;
               
               default: /*Nothing to do*/
                     break;
             } 
          }
          else
          {
            SafeWdgExtTlf_Data.JobResult = SWDG_JOB_RD_DATA_FAIL;
            SafeWdgExtTlf_Data.JobState = SAFEWDGEXT_TLF_IDLE;
          }
        }
      }
      else
      {
        SafeWdgExtTlf_Data.JobResult = SWDG_JOB_COM_ERR;
        SafeWdgExtTlf_Data.JobState  = SAFEWDGEXT_TLF_IDLE;        
      }         
    } 

    /*Seed , Device state and error count info updated.Set new CRC*/
    SafeWdgExtTlf_lSetDataCrc();
  }
} /* SafeWdgExtTlf_MainFunction */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                    
** Syntax           : void SafeWdgExtTlf_lProcessUnlock         
**                     (void)                          
**                                                                    
** Service ID       : none                                              
**                                                                    
** Sync/Async       : ASynchronous                                     
**                                                                    
** Reentrancy       : Non Reentrant                                     
**                                                                    
** Parameters (in) :  none     
**                                                                    
** Parameters (out) : none                                            
**                                                                    
** Return value     : none
**                                                                    
** Description      : This function is called by SafeWdgExtTlf_Main() to process
                      SAFEWDGEXT_TLF_ULOCK_JOB request.                           
**                                                                    
*******************************************************************************/
static void SafeWdgExtTlf_lProcessUnlock( void )
{
  uint16 Wdgcfg0Val  = 0U;
  uint16 Syspcfg0Val = 0U;
  uint16 Syspcfg1Val = 0U;

  /*Copy protected configuration register values from Rx Buffer*/
  Syspcfg0Val                 =
      (uint16)((0x0001U) & (SafeWdgExtTlf_RxBuf[TLF_UNLOCK_RD_RSYSPCFG0]));
  Syspcfg1Val                 =
      (uint16)((0x00FFU) & (SafeWdgExtTlf_RxBuf[TLF_UNLOCK_RD_RSYSPCFG1]));
  Wdgcfg0Val                  =
      (uint16)((0x00FFU) & (SafeWdgExtTlf_RxBuf[TLF_UNLOCK_RD_RWDCFG0]));
  SafeWdgExtTlf_Data.Wdcfg1   =
      (uint16)((0x001FU) & (SafeWdgExtTlf_RxBuf[TLF_UNLOCK_RD_RWDCFG1]));
  SafeWdgExtTlf_Data.Fwdcfg   =
      (uint16)((0x001FU) & (SafeWdgExtTlf_RxBuf[TLF_UNLOCK_RD_RFWDCFG]));
  SafeWdgExtTlf_Data.Wwdcfg0  =
      (uint16)((0x001FU) & (SafeWdgExtTlf_RxBuf[TLF_UNLOCK_RD_RWWDCFG0]));
  SafeWdgExtTlf_Data.Wwdcfg1  =
      (uint16)((0x001FU) & (SafeWdgExtTlf_RxBuf[TLF_UNLOCK_RD_RWWDCFG1]));

  /* Disable FWD */
  Wdgcfg0Val = (uint16)(Wdgcfg0Val & ((uint8)(~SAFEWDGEXT_TLF_WDCFG0_FWDEN_B))); 
  /* Disable WWD */
  Wdgcfg0Val = (uint16)(Wdgcfg0Val & ((uint8)(~SAFEWDGEXT_TLF_WDCFG0_WWDEN_B))); 
  SafeWdgExtTlf_Data.Wdcfg0 = Wdgcfg0Val;
  SafeWdgExtTlf_Data.Syspcfg0 = Syspcfg0Val;
  /*Disable error pin monitoring*/
  Syspcfg1Val =(uint16)(Syspcfg1Val & ((uint8)
                                            (~SAFEWDGEXT_TLF_SYSPCFG1_EREN_B)));
  SafeWdgExtTlf_Data.Syspcfg1 = Syspcfg1Val;
  
  /*No partial configuration of protected registers allowed.So write values
    to all protected registers during each unlock-lock sequence.*/
  SafeWdgExtTlf_TxBuf[TLF_LOCK_WR_SYSPCFG0] =
      SAFEWDGEXT_TLF_WR_CMD(TLF_REG_SYSPCFG0, SafeWdgExtTlf_Data.Syspcfg0);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_WR_SYSPCFG1] =
      SAFEWDGEXT_TLF_WR_CMD(TLF_REG_SYSPCFG1, SafeWdgExtTlf_Data.Syspcfg1);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_WR_WDCFG0] =
      SAFEWDGEXT_TLF_WR_CMD(TLF_REG_WDCFG0, SafeWdgExtTlf_Data.Wdcfg0);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_WR_WDCFG1] =
      SAFEWDGEXT_TLF_WR_CMD(TLF_REG_WDCFG1, SafeWdgExtTlf_Data.Wdcfg1);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_WR_FWDCFG] =
      SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDCFG, SafeWdgExtTlf_Data.Fwdcfg);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_WR_WWDCFG0] =
      SAFEWDGEXT_TLF_WR_CMD(TLF_REG_WWDCFG0, SafeWdgExtTlf_Data.Wwdcfg0);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_WR_WWDCFG1] =
      SAFEWDGEXT_TLF_WR_CMD(TLF_REG_WWDCFG1, SafeWdgExtTlf_Data.Wwdcfg1);
  
  /*Read back all protected register values to verify correctness*/
  SafeWdgExtTlf_TxBuf[TLF_LOCK_RD_SYSPCFG0] =
      SAFEWDGEXT_TLF_RD_CMD(TLF_REG_SYSPCFG0);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_RD_SYSPCFG1] =
      SAFEWDGEXT_TLF_RD_CMD(TLF_REG_SYSPCFG1);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_RD_WDCFG0] =
      SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WDCFG0);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_RD_WDCFG1] =
      SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WDCFG1);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_RD_FWDCFG] =
      SAFEWDGEXT_TLF_RD_CMD(TLF_REG_FWDCFG);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_RD_WWDCFG0] =
      SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WWDCFG0);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_RD_WWDCFG1] =
      SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WWDCFG1);

  /*Issue lock command*/
  SafeWdgExtTlf_TxBuf[TLF_LOCK_WR_PROTCFG_0] =
      SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_LOCK_SEQU0);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_WR_PROTCFG_1] =
      SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_LOCK_SEQU1);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_WR_PROTCFG_2] =
      SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_LOCK_SEQU2);
  SafeWdgExtTlf_TxBuf[TLF_LOCK_WR_PROTCFG_3] =
      SAFEWDGEXT_TLF_WR_CMD(TLF_REG_PROTCFG, SAFEWDGEXT_TLF_LOCK_SEQU3);
  SafeWdgExtTlf_Data.JobState = SAFEWDGEXT_TLF_LOCK_JOB; 
  SafeWdgExtTlf_Data.NoOfBytesToBeTfered = (uint8)TLF_LOCK_MAX;
  SafeWdgQspi_TxRx(SafeWdgExtTlf_TxBuf,SafeWdgExtTlf_RxBuf,
                            SafeWdgExtTlf_Data.NoOfBytesToBeTfered); 
}

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                    
** Syntax           : void SafeWdgExtTlf_lProcessEnbleJob         
**                     (void)                          
**                                                                    
** Service ID       : none                                              
**                                                                    
** Sync/Async       : ASynchronous                                     
**                                                                    
** Reentrancy       : Non Reentrant                                     
**                                                                    
** Parameters (in) :  none     
**                                                                    
** Parameters (out) : none                                            
**                                                                    
** Return value     : none
**                                                                    
** Description      : This function is called by SafeWdgExtTlf_Main() to process
                      SAFEWDGEXT_TLF_ENBLE_JOB request.                           
**                                                                    
*******************************************************************************/
static void SafeWdgExtTlf_lProcessEnbleJob( void )
{
  uint8   LoopIndex = 0U;
  uint32  RxValue   = 0U;
  uint32  TxValue   = 0U;
  
  boolean ProtectedRegistersConfigNotOk = FALSE;
  for (LoopIndex = (uint8)TLF_ENABLE_WR_SYSPCFG0;
       ((LoopIndex < (uint8)TLF_ENABLE_RD_WWDSCMD) &&
        (ProtectedRegistersConfigNotOk != TRUE) );
       LoopIndex++)
  {
    /*Check if data written to protected configuration registers are
      fine.TLF35584 will send inverted values of data written to 
      protected registers.*/
    RxValue = SafeWdgExtTlf_RxBuf[(LoopIndex +
                                   ((uint8)TLF_ENABLE_RD_SYSPCFG0 -
                                    (uint8)TLF_ENABLE_WR_SYSPCFG0))] & (uint32)0x00FFU;
    TxValue = SafeWdgExtTlf_TxBuf[LoopIndex] & (uint32)0x00FFU;
    
    /*Data send (Tx) and read request from the protected registers
     (Rx) xor will be 0xFF, if data written to protected configuration
     registers are OK.*/
    if(( TxValue ^ RxValue) != (uint32)0xFFU)
    {
      ProtectedRegistersConfigNotOk = TRUE;
    }
  }
  if(ProtectedRegistersConfigNotOk == FALSE)
  {
    /* Read status registers */
    SafeWdgExtTlf_TxBuf[TLF_ACT_SER_RD_DEVSTAT] =
        SAFEWDGEXT_TLF_RD_CMD(TLF_REG_DEVSTAT);
    SafeWdgExtTlf_TxBuf[TLF_ACT_SER_RD_FWDSTAT1] =
        SAFEWDGEXT_TLF_RD_CMD(TLF_REG_FWDSTAT1);
    SafeWdgExtTlf_TxBuf[TLF_ACT_SER_RD_FWDSTAT0] =
        SAFEWDGEXT_TLF_RD_CMD(TLF_REG_FWDSTAT0);
    SafeWdgExtTlf_TxBuf[TLF_ACT_SER_RD_WWDSTAT] =
        SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WWDSTAT);
    SafeWdgExtTlf_TxBuf[TLF_ACT_SER_RD_WWDSCMD] =
        SAFEWDGEXT_TLF_RD_CMD(TLF_REG_WWDSCMD);
    SafeWdgExtTlf_Data.NoOfBytesToBeTfered  = (uint8)TLF_ACT_SER_MAX;
    
    /* Set activate request to issue move-to-normal command in GetInfo API: */
    SafeWdgExtTlf_Data.ActivateRequested    = TRUE;
    SafeWdgExtTlf_Data.JobState             = SAFEWDGEXT_TLF_ACT_SRV_JOB;
    SafeWdgQspi_TxRx(SafeWdgExtTlf_TxBuf,SafeWdgExtTlf_RxBuf,
                                        SafeWdgExtTlf_Data.NoOfBytesToBeTfered);
  }
  else
  {
    SafeWdgExtTlf_Data.JobResult = SWDG_JOB_READBACK_FAIL;
    SafeWdgExtTlf_Data.JobState  = SAFEWDGEXT_TLF_IDLE; 
  }
}
/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                    
** Syntax           : SafeWdgIf_ResultType SafeWdgExtTlf_GetErrCntr
**                    ( uint8* const ErrCtrPtr)   
**                                                                    
** Service ID       : none                                              
**                                                                    
** Sync/Async       : Synchronous                                     
**                                                                    
** Reentrancy       : Non Reentrant                                     
**                                                                    
** Parameters (in) :  ErrCtrPtr - pointer to report back error counter value                                          
**                                                                            
** Parameters (out) : *ErrCtrPtr - returned error counter value   
**                                                                    
** Return value     : SWDG_JOB_SUCCESS - Operation successfully performed               
**                    SWDG_JOB_FAILED_CRC - CRC check on internal data structure failed.
** Description      : Returns error counter of configured watchdog.                                       
**                                                                    
*******************************************************************************/
SafeWdgIf_ResultType SafeWdgExtTlf_GetErrCntr(uint8* const ErrCtrPtr)
{
  SafeWdgIf_ResultType  Result = SWDG_JOB_FAILED_CRC;

  /*Check for CRC*/
  if(SafeWdgExtTlf_lCheckDataCrc() == E_OK)
  {
    Result = SWDG_JOB_INV_PARAM;

    /* Check for NULL pointer */
    if (NULL_PTR != ErrCtrPtr)
    {
      *ErrCtrPtr = SafeWdgExtTlf_Data.ErrCtr;
       Result =  SWDG_JOB_SUCCESS;
    }
  }

  return Result;
}

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**
** Syntax           : SafeWdgIf_ResultType SafeWdgExtTlf_ServiceWwd(void) 
**                                                                    
** Service ID       : none                                              
**                                                                    
** Sync/Async       : Synchronous (WDI triggering) / Asynchronous (SPI      
**                    triggering)                                       
**                                                                    
** Reentrancy       : Non Reentrant                                     
**                                                                    
** Parameters (in) :  none                                              
**                                                                    
** Parameters (out) : none                                            
**                                                                    
** Return value     : SWDG_JOB_SUCCESS - Watchdog service succeeded   
**                    SWDG_JOB_ACCEPTED - Watchdog service was started and is 
**                                        still pending                       
**                                                                            
** Description      : Services the window watchdog                            
**                                                                            
*******************************************************************************/
static SafeWdgIf_ResultType SafeWdgExtTlf_lServiceWwd(void)
{
  SafeWdgIf_ResultType  Result = SWDG_JOB_SUCCESS;
  uint32 TempOmcr     = 0U;
  uint32 TempOmcrBase = 0U;

  /* Check operation mode window watchdog: */
  if (TLF_WM_WWD_WDI == SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode)
  {
    /* Triggering via GPIO pin selected, clear WDI pin to generate a falling
     * edge:     */
    TempOmcrBase = ((uint32)(SafeWdgExtTlf_Data.ConfigPtr->WdiPin) +
                                                   SAFEWDGEXT_TLF_OMCR_BASE_P);
    TempOmcr =    (uint32)((uint32)1U << (uint32)TempOmcrBase) ;
    SafeWdgExtTlf_Data.ConfigPtr->WdiPort->OMCR.U = TempOmcr;
    

    /* Set up task for WDI restoration: */
    SafeWdgExtTlf_Data.WdiRestoreFlag = TRUE;

    Result = SWDG_JOB_SUCCESS;
  } /* if (TLF_WM_WWD_WDI == SafeWdgExtTlf_Data.ConfigPtr->WatchdogMode) */
  else
  {
    /* Invert previously read WWDSCMD.TRIG bit: */
    SafeWdgExtTlf_Data.LastWwdScmd ^= (uint8)0x01U;
    
    SafeWdgExtTlf_TxBuf[TLF_SER_WWD_WR_WWDSCMD] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_WWDSCMD, SafeWdgExtTlf_Data.LastWwdScmd);

    SafeWdgExtTlf_Data.NoOfBytesToBeTfered = (uint8)TLF_SER_WWD_MAX;

    /*Send service command to TLF35584*/
    SafeWdgQspi_TxRx(SafeWdgExtTlf_TxBuf,SafeWdgExtTlf_RxBuf,
                                      SafeWdgExtTlf_Data.NoOfBytesToBeTfered);
    Result = SWDG_JOB_ACCEPTED;
  }

  return Result;
} /* SafeWdgExtTlf_lServiceWwd */


/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                    
**                                                                  
** Syntax           : static SafeWdgIf_ResultType SafeWdgExtTlf_lServiceFwd(const uint8 UsedSeed,
                                                      const uint32 Signature)                        
**                                                                  
** Service ID       : none                                            
**                                                                  
** Sync/Async       : Asynchronous                                   
**                                                                  
** Reentrancy       : Non Reentrant                                   
**                                                                  
** Parameters (in) :  Signature - The signature to be used for watchdog     
**                                service
**                     UsedSeed - Seed considered to generate the signature                              
**                                                                  
** Parameters (out) : none                                          
**                                                                  
** Return value     : SWDG_JOB_ACCEPTED - Watchdog service was started and is 
**                                        still pending                       
**                                                                            
** Description      : Services the functional watchdog                        
**                                                                            
*******************************************************************************/
static SafeWdgIf_ResultType SafeWdgExtTlf_lServiceFwd(const uint8 UsedSeed,
                                                      const uint32 Signature)
{
  uint8 Rsp;

  #if (_SAFEWDG_TLF_DEBUG_ == TRUE )
  /*Code is for development and debug purpose only.*/
  uint32 SignTmp = SafeWdgExtTlf_kResponseTable[SafeWdgExtTlf_Data.LastSeed];
  SafeWdgExtTlf_Data.XorMask[SafeWdgExtTlf_Data.LastSeed] = 
        Signature ^ SafeWdgExtTlf_kResponseTable[SafeWdgExtTlf_Data.LastSeed];
  #else
  uint32 SignTmp = 
              Signature ^ SafeWdgExtTlf_Data.ConfigPtr->XorResponse[UsedSeed];
  #endif

  /*From the signature extract 4  bytes and write the first 3 bytes to
    FUNCWDGRSP register and the last byte to FUNCWDGRSPSYNC register 
    to service the functional watchdog*/
  switch (SafeWdgExtTlf_Data.RspCnt)
  {
    case 0:      
      Rsp = (uint8)((SignTmp & 0x000000FFU) >>  0);
      SafeWdgExtTlf_TxBuf[0] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSPSYNC, Rsp);
      break; 
    case 1:
      Rsp = (uint8)((SignTmp & 0x0000FF00U) >>  8);
      SafeWdgExtTlf_TxBuf[0] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSP, Rsp);
      Rsp = (uint8)((SignTmp & 0x000000FFU) >>  0);
      SafeWdgExtTlf_TxBuf[1] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSPSYNC, Rsp);      
      break;      
    case 2:
      Rsp = (uint8)((SignTmp & 0x00FF0000U) >> 16);
      SafeWdgExtTlf_TxBuf[0] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSP, Rsp);
      Rsp = (uint8)((SignTmp & 0x0000FF00U) >>  8);
      SafeWdgExtTlf_TxBuf[1] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSP, Rsp);
      Rsp = (uint8)((SignTmp & 0x000000FFU) >>  0);
      SafeWdgExtTlf_TxBuf[2] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSPSYNC, Rsp);
      break;
    case 3:
    default:
      Rsp = (uint8)((SignTmp & 0xFF000000U) >> 24);
      SafeWdgExtTlf_TxBuf[0] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSP, Rsp);
      Rsp = (uint8)((SignTmp & 0x00FF0000U) >> 16);
      SafeWdgExtTlf_TxBuf[1] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSP, Rsp);
      Rsp = (uint8)((SignTmp & 0x0000FF00U) >>  8);
      SafeWdgExtTlf_TxBuf[2] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSP, Rsp);
      Rsp = (uint8)((SignTmp & 0x000000FFU) >>  0);
      SafeWdgExtTlf_TxBuf[3] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSPSYNC, Rsp);
      break;

  }
  SafeWdgExtTlf_Data.NoOfBytesToBeTfered = (uint8)(SafeWdgExtTlf_Data.RspCnt + 1U);
  SafeWdgQspi_TxRx(SafeWdgExtTlf_TxBuf,SafeWdgExtTlf_RxBuf,
                                        SafeWdgExtTlf_Data.NoOfBytesToBeTfered);
  return SWDG_JOB_ACCEPTED;
} /* SafeWdgExtTlf_lServiceFwd */


/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                    
** Syntax           : static SafeWdgIf_ResultType SafeWdgExtTlf_lServiceFwdAndWwd(const uint8 
                                                UsedSeed,const uint32 Signature)                           
**                                                                    
** Service ID       : none                                              
**                                                                    
** Sync/Async       : Asynchronous                                     
**                                                                    
** Reentrancy       : Non Reentrant                                     
**                                                                    
** Parameters (in) :  Signature - The signature to be used for watchdog       
**                                service                               
**                     UsedSeed - Seed used to generate the corresponding signature
** Parameters (out) : none                                            
**                                                                    
** Return value     : SWDG_JOB_ACCEPTED - Watchdog service was started and is 
**                                        still pending                       
**                                                                            
** Description      : Services the both functional and window watchdog                       
**                                                                            
*******************************************************************************/
static SafeWdgIf_ResultType SafeWdgExtTlf_lServiceFwdAndWwd(const uint8 
                                                UsedSeed,const uint32 Signature)
{
  uint8                 Rsp;

  #if (_SAFEWDG_TLF_DEBUG_ == TRUE )
  uint32 SignTmp = SafeWdgExtTlf_kResponseTable[SafeWdgExtTlf_Data.LastSeed];
  SafeWdgExtTlf_Data.XorMask[SafeWdgExtTlf_Data.LastSeed] = 
        Signature ^ SafeWdgExtTlf_kResponseTable[SafeWdgExtTlf_Data.LastSeed];
  #else
  uint32 SignTmp = 
              Signature ^ SafeWdgExtTlf_Data.ConfigPtr->XorResponse[UsedSeed];
  #endif
  /* Invert previously read WWDSCMD.TRIG bit: */
  SafeWdgExtTlf_Data.LastWwdScmd ^= (uint8)0x01U;
  /* Prepare TX buffer for data transfer, write new trigger bit: */
  SafeWdgExtTlf_TxBuf[TLF_SER_FWD_WWD_WR_WWDSCMD] =
        SAFEWDGEXT_TLF_WR_CMD(TLF_REG_WWDSCMD,SafeWdgExtTlf_Data.LastWwdScmd);
 

  /*From the signature extract 4  bytes and write the first 3 bytes to
  FUNCWDGRSP register and the last byte to FUNCWDGRSPSYNC register 
  to service the functional watchdog*/
  switch (SafeWdgExtTlf_Data.RspCnt)
  {
    case 0:      
      Rsp = (uint8)((SignTmp & 0x000000FFU) >>  0);
      SafeWdgExtTlf_TxBuf[1] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSPSYNC, Rsp);
      break; 
    case 1:
      Rsp = (uint8)((SignTmp & 0x0000FF00U) >>  8);
      SafeWdgExtTlf_TxBuf[1] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSP, Rsp);
      Rsp = (uint8)((SignTmp & 0x000000FFU) >>  0);
      SafeWdgExtTlf_TxBuf[2] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSPSYNC, Rsp);      
      break;      
    case 2:
      Rsp = (uint8)((SignTmp & 0x00FF0000U) >> 16);
      SafeWdgExtTlf_TxBuf[1] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSP, Rsp);
      Rsp = (uint8)((SignTmp & 0x0000FF00U) >>  8);
      SafeWdgExtTlf_TxBuf[2] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSP, Rsp);
      Rsp = (uint8)((SignTmp & 0x000000FFU) >>  0);
      SafeWdgExtTlf_TxBuf[3] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSPSYNC, Rsp);
      break;
    case 3:
    default:
      Rsp = (uint8)((SignTmp & 0xFF000000U) >> 24);
      SafeWdgExtTlf_TxBuf[1] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSP, Rsp);
      Rsp = (uint8)((SignTmp & 0x00FF0000U) >> 16);
      SafeWdgExtTlf_TxBuf[2] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSP, Rsp);
      Rsp = (uint8)((SignTmp & 0x0000FF00U) >>  8);
      SafeWdgExtTlf_TxBuf[3] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSP, Rsp);
      Rsp = (uint8)((SignTmp & 0x000000FFU) >>  0);
      SafeWdgExtTlf_TxBuf[4] = SAFEWDGEXT_TLF_WR_CMD(TLF_REG_FWDRSPSYNC, Rsp);
      break;

  }
  SafeWdgExtTlf_Data.NoOfBytesToBeTfered = (uint8)(SafeWdgExtTlf_Data.RspCnt + 2U);
  /*Send the signature to Window and functional watchdog*/
  SafeWdgQspi_TxRx(SafeWdgExtTlf_TxBuf,SafeWdgExtTlf_RxBuf,
                                    SafeWdgExtTlf_Data.NoOfBytesToBeTfered);   

  return SWDG_JOB_ACCEPTED;
} /* SafeWdgExtTlf_lServiceFwd */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                        
** Syntax           : SafeWdgIf_ResultType SafeWdgExtTlf_lProcessUsrReq       
**                     (void)                                               
**                                                                        
** Service ID       : none                                                  
**                                                                        
** Sync/Async       : Synchronous                                         
**                                                                        
** Reentrancy       : Non Reentrant                                         
**                                                                        
** Parameters (in) :  none                                                  
**                                                                        
** Parameters (out) : none                                                
**                                                                        
** Return value     : none   
**                                                                        
** Description      : This function checks for complete reception of the user 
**                    request response and processes the response, once it    
**                    has been received.                                    
**                                                                        
*******************************************************************************/
static void SafeWdgExtTlf_lProcessUsrReq(void)
{
  uint8 LoopIndex;
  uint8 tempNumberOfBytesToBeTransffered = \
                    SafeWdgExtTlf_Data.NoOfBytesToBeTfered;

  /* Data transfer complete, copy RX data to user request array: */
  for (LoopIndex = 0U; LoopIndex < tempNumberOfBytesToBeTransffered;LoopIndex++)
  {
    /* Copy response back to user buffer*/
    SafeWdgExtTlf_Data.RequestPtr[LoopIndex].UserData = 
                                   (uint8)SafeWdgExtTlf_RxBuf[LoopIndex];
  } 

  /* Reset job state and return success: */
  SafeWdgExtTlf_Data.JobResult = SWDG_JOB_SUCCESS;
  SafeWdgExtTlf_Data.JobState = SAFEWDGEXT_TLF_IDLE;
} 


/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      
**                                                                    
** Syntax           : Std_ReturnType SafeWdgExtTlf_lCheckWrData         
**                     (const uint8 TxWordCount)                          
**                                                                    
** Service ID       : none                                              
**                                                                    
** Sync/Async       : Synchronous                                     
**                                                                    
** Reentrancy       : Non Reentrant                                     
**                                                                    
** Parameters (in) :  TxWordCount - Number of data words that have been   
**                                  transmitted                         
**                                                                    
** Parameters (out) : none                                            
**                                                                    
** Return value     : E_OK - All data was echoed back correctly            
**                    E_NOT_OK - Unexpected data was echoed back       
**                                                                    
** Description      : This function checks if all register write commands of  
**                    the last transmitted data packet were echoed back    
**                    correctly via SPI. Register read commands are not   
**                    checked by this function.                           
**                                                                    
*******************************************************************************/
static Std_ReturnType SafeWdgExtTlf_lCheckWrData(uint8 TxWordCount)
{
  uint8           Index;
  Std_ReturnType  Result = E_OK;

  /* Check that all write commands are cycled back correctly: */
  for (Index = 0U; Index < TxWordCount; Index++)
  {
    /* Current data word is a write command? */
    if ((SafeWdgExtTlf_TxBuf[Index] & SAFEWDGEXT_TLF_WR_BIT) > 0U)
    {
      /* TX data was echoed back to RX data? */
      if (SafeWdgExtTlf_TxBuf[Index] != SafeWdgExtTlf_RxBuf[Index])
      {
        Result = E_NOT_OK;
      } 
    } /* if ((SafeWdgExtTlf_TxBuf[Index] & SAFEWDGEXT_TLF_WR_BIT) > 0U) */
  } /* for (Index = 0U; Index < TxWordCount; Index++) */

  return Result;
} /* SafeWdgExtTlf_lCheckWrData */

/******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Std_ReturnType SafeWdgExtTlf_CheckDataCrc(void)                   **
**                                                                            **
** Description :    check data set integrity by CRC validation                **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
** Parameters (out): None                                                     **
** Return value    : E_OK, if Crc matches the stored on, data integrity okay  **
**                   E_NOT_OK otherwise                                       **
**                                                                            **
*******************************************************************************/
static Std_ReturnType SafeWdgExtTlf_lCheckDataCrc(void)
{
  uint32 CurrCrc = SafeWdgExtTlf_lCrc();
  return ((CurrCrc == SafeWdgExtTlf_Data.Crc) ? E_OK : E_NOT_OK);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void SafeWdgExtTlf_lSetDataCrc(void)                              **
**                                                                            **
** Description :    calculate and update crc for data set                     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
** Parameters (out): None                                                     **
** Return value    : E_OK, if Crc matches the stored on, data integrity okay  **
**                   E_NOT_OK otherwise                                       **
**                                                                            **
*******************************************************************************/
static void SafeWdgExtTlf_lSetDataCrc(void)
{
  SafeWdgExtTlf_Data.Crc = SafeWdgExtTlf_lCrc();
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void SafeWdgExtTlf_lSetDataCrc(void)                              **
**                                                                            **
** Description :    calculate crc for data set                                **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
** Parameters (out): None                                                     **
** Return value    : Calculated CRC value                                     **
**                                                                            **
*******************************************************************************/
static uint32 SafeWdgExtTlf_lCrc(void)
{
  uint32 CurrCrc          = 0U;

  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.LastSeed);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.ErrCtr);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.DeviceState);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.LastWwdScmd);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.JobState);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.JobResult);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.ConfigPtr);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.NoOfBytesToBeTfered);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.WdiRestoreFlag);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.ActivateRequested);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.RequestPtr);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.RspCnt);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.Syspcfg0);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.Syspcfg1);
  CurrCrc = (uint32)CRC32(CurrCrc, SafeWdgExtTlf_Data.Wdcfg1);
  
  return (CurrCrc);
}
#define IFX_SWDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
