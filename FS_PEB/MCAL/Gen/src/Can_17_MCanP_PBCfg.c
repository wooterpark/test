/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Can_17_MCanP_PBCfg.c $                                     **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\45 $                               **
**                                                                            **
**  DATE, TIME: 2021-09-29, 16:08:35                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CAN configuration generated out of ECU configuration       **
**                   file(Can_17_MCanP.bmd)                                   **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/**  TRACEABILITY: [cover parentID=DS_NAS_CAN_PR69_PR469_PR122,DS_NAS_CAN_PR446,
            DS_NAS_CAN_PR700,DS_NAS_CAN_PR701,DS_NAS_CAN_PR704,DS_NAS_CAN_PR707,
            DS_NAS_CAN_PR708,DS_NAS_CAN_PR712,DS_NAS_CAN_PR713,DS_NAS_CAN_PR714,
            DS_NAS_CAN_PR716,DS_NAS_CAN_PR717,DS_NAS_CAN_PR723,DS_NAS_CAN_PR724,
            DS_NAS_CAN_PR728,DS_NAS_CAN_PR709,SAS_AS4XX_CAN_PR680,
			DS_NAS_CAN_PR3162_PR3163_2]
                     [/cover]                                                **/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include CAN Driver Header File */
#include "Can_17_MCanP.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define CAN_17_MCANP_START_SEC_POSTBUILDCFG
#include "MemMap.h"


/******************************************************************************/
                /* CAN Controller Baudrate Configurations */
/******************************************************************************/
                          /* Baudrate Setting */
   /* (uint16)((DIV8 << 15)|(TSEG2 << 12)|(TSEG1 << 8)|(SJW << 6)|(BRP)) */
   /* SJW   -> CanControllerSyncJumpWidth - 1                            */
   /* TSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1              */
   /* TSEG2 -> CanControllerSeg2 - 1                                     */
/******************************************************************************/


/* CanConfigSet -> Can_Network_CANNODE_0 Baudrate Configuration */

static const Can_17_MCanP_ControllerBaudrateConfigType Can_kBaudrateConfig_0_0[] =
{
  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* BRP   -> 9 */
    /* SJW   -> 3  */
    /* TSEG1 -> 14  */
    /* TSEG2 -> 3  */
    /* DIV8  -> 0  */
    0x3ec9U,
    500U
  }
};

/* CanConfigSet -> Can_Network_CANNODE_1 Baudrate Configuration */

static const Can_17_MCanP_ControllerBaudrateConfigType Can_kBaudrateConfig_0_1[] =
{
  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* BRP   -> 9 */
    /* SJW   -> 3  */
    /* TSEG1 -> 14  */
    /* TSEG2 -> 3  */
    /* DIV8  -> 0  */
    0x3ec9U,
    500U
  }
};

static const Can_BaudrateConfigPtrType Can_kBaudrateConfig_0[] =
{
  { &Can_kBaudrateConfig_0_0[0] },
  { &Can_kBaudrateConfig_0_1[0] },
};



/******************************************************************************/
            /* Loopback and receive input pin selection setting */
/******************************************************************************/

/* Config 0 */
static const struct Can_NPCRValueType Can_kNPCR_0[] =
{
  /* LoopBack Disabled, RXDCANxB */
  { 1U },
  /* LoopBack Disabled, RXDCANxB */
  { 1U },
};

/******************************************************************************/
            /* CAN Controller wakeup source configuration */
/******************************************************************************/

/* Config 0 */
static const uint32 Can_kWakeupSourceId_0[] =
{
  0U,  /* Wakeup source not configured for CAN Controller 0 */
  0U,  /* Wakeup source not configured for CAN Controller 1 */
};

/*******************************************************************************
               Transmit / Receive Hardware Object Configurations
********************************************************************************
 Tx Object -> { HW MO Id, [No. of Multiplexed MOs,] Hw Controller Id, Id Type }
        Rx Object -> { Mask, Msg Id, HW MO Id, Hw Controller Id, [Id Type] }
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   Hw Controller Id -> 255
             [2] If CanFilterMaskRef is not configured then,
                   Mask -> 0x7ff - for STANDARD Msg Id Type
                           0x1fffffff - for EXTENDED/MIXED Msg Id Type
*******************************************************************************/

/* CanConfigSet -> Transmit Hardware Object Configuration */
static const Can_TxHwObjectConfigType Can_kTxHwObjectConfig_0[] =
{
  { 16U, 3U, ((uint32)0x80000000U) },
  { 17U, 3U, ((uint32)0x80000000U) },
  { 18U, 3U, ((uint32)0x80000000U) },
  { 19U, 3U, ((uint32)0x80000000U) },
  { 20U, 3U, ((uint32)0x80000000U) },
  { 21U, 3U, ((uint32)0x80000000U) },
  { 22U, 3U, ((uint32)0x80000000U) },
  { 23U, 3U, ((uint32)0x80000000U) },
  { 24U, 3U, ((uint32)0x80000000U) },
  { 25U, 3U, ((uint32)0x80000000U) },
  { 26U, 1U, ((uint32)0x80000000U) },
  { 27U, 1U, ((uint32)0x80000000U) },
  { 28U, 1U, ((uint32)0x80000000U) },
  { 29U, 1U, ((uint32)0x80000000U) },
  { 30U, 1U, ((uint32)0x80000000U) },
  { 31U, 1U, ((uint32)0x80000000U) },
  { 32U, 1U, ((uint32)0x80000000U) }
};
/* CanConfigSet -> Receive Hardware Object Configuration */
static const Can_RxHwObjectConfigType Can_kRxHwObjectConfig_0[] =
{
  { 0x7ffU, 0x120U, 0U, 3U },
  { 0x7ffU, 0x100U, 1U, 3U },
  { 0x7ffU, 0x310U, 2U, 3U },
  { 0x7ffU, 0x220U, 3U, 3U },
  { 0x7ffU, 0x320U, 4U, 3U },
  { 0x7ffU, 0x300U, 5U, 3U },
  { 0x7ffU, 0x110U, 6U, 3U },
  { 0x7ffU, 0x603U, 7U, 3U },
  { 0x7ffU, 0x602U, 8U, 3U },
  { 0x0U, 0x7ffU, 9U, 3U },
  { 0x7ffU, 0x780U, 10U, 1U },
  { 0x7ffU, 0x220U, 11U, 1U },
  { 0x7ffU, 0x604U, 12U, 1U },
  { 0x7ffU, 0x210U, 13U, 1U },
  { 0x7ffU, 0x603U, 14U, 1U },
  { 0x7ffU, 0x602U, 15U, 1U }
};

/*******************************************************************************
     CAN Hardware object Id <-> CAN Transmit/Recieve Object Handle Mapping
*******************************************************************************/
/* CanConfigSet -> Kernal 0 CAN Hw Object ID - CAN Hth Mapping */
static const uint8 Can_kTxObjectHthKer0Map_0[] =
{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

/* CanConfigSet -> Kernal 0 CAN Hw Object ID - CAN Hrh Mapping */
static const uint16 Can_kRxObjectHrhKer0Map_0[] =
{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };



/*******************************************************************************
              CAN Controller <-> CAN Hardware Object Mapping
********************************************************************************
        { First Rx Hardware Object, No. of Rx Hardware Objects,
          First Tx Hardware Object, No. of Tx Hardware Objects }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/

/* CanConfigSet -> CAN Controller - CAN Hardware Object Mapping */
static const Can_ControllerMOMapConfigType Can_kControllerMOMapConfig_0[] =
{

  { { 0U, 10U, 16U, 10U } },
  { { 10U, 6U, 26U, 7U } }
};



/*******************************************************************************
              CAN Controller Handling of Events : Interrupt/Polling
********************************************************************************
        { CanBusoffProcessing, CanRxProcessing,
          CanTxProcessing, CanWakeupProcessing }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/

/* CanConfigSet -> CAN Controller - Handling of Events */
static const Can_EventHandlingType Can_kEventHandlingConfig_0[] =
{
 { { (CAN_POLLING),(CAN_POLLING),(CAN_POLLING),(CAN_POLLING)} },
 { { (CAN_POLLING),(CAN_POLLING),(CAN_POLLING),(CAN_POLLING)} }
};



/*******************************************************************************
              CAN Controller <-> Default Baudrate Mapping
********************************************************************************
          { NBTR Register Settings, Default Baudrate in kbps }
*******************************************************************************/

/* CanConfigSet -> CAN Controller - default baudrate mapping */
static const Can_17_MCanP_ControllerBaudrateConfigType Can_kDefaultBaudrateConfig_0[] =
{
  /* CAN Controller 0 :
     Configured Baudrate -> 500 kbps
     Actual Baudrate     -> 500.0 kbps */
  { 0x3ec9U, 500U },
  /* CAN Controller 1 :
     Configured Baudrate -> 500 kbps
     Actual Baudrate     -> 500.0 kbps */
  { 0x3ec9U, 500U }
};




/******************************************************************************/
                      /* CAN Configuration Pointer */
/******************************************************************************/
      /* Over all CAN configurations in the array, pointer to one of the
           configuration is passed as parameter to Can_Init API */
/******************************************************************************/

const Can_17_MCanP_ConfigType Can_17_MCanP_ConfigRoot[] =
{
  {
    /* Pointer to Loopback and receive input pin selection setting */
    &Can_kNPCR_0[0],

    /* Pointer to Wakeup Source Id Configuration */
    &Can_kWakeupSourceId_0[0],

    /* Pointer to CAN Controller <-> Hardware Objects Mapping */
    &Can_kControllerMOMapConfig_0[0],

    /* Pointer to CAN Controller Handling of Events : Interrupt/Polling */
    &Can_kEventHandlingConfig_0[0],

    /* Pointer to Controller Baudrate Configuration */
    &Can_kBaudrateConfig_0[0],

    /* Pointer to default baudrate configuration */
    &Can_kDefaultBaudrateConfig_0[0],



   /* Pointer to Configuration of transmit hardware objects */
    &Can_kTxHwObjectConfig_0[0],

    /* Pointer to Configuration of receive hardware objects */
    &Can_kRxHwObjectConfig_0[0],


    /* Pointer to Configuration of Kernal0 Hth Mapping */
    &Can_kTxObjectHthKer0Map_0[0],


    /* Pointer to Configuration of Hrh Mapping */
    &Can_kRxObjectHrhKer0Map_0[0],


    /* CAN Module clock configuration : Fractional Divider Register setting */
    /* NORMAL_DIVIDER - Bit 14 is set */
    /* CanClockStepValue 1023 (0x3ff) is assigned to bit 0-9. */
    0x43ffU,

    /* Number of configured CAN controllers */
    2U,

    /* CanControllerId --> CanHwControllerId (MultiCAN+ Controller Id) */
    { 3U, 1U },

    /* CAN Controller-wise number of baudrate configurations */
    { 1U, 1U },

    /* Total number of Transmit Hardware Objects */
    17U,

    /* Total number of Receive Hardware Objects */
    16U,

    /* Transmit Hardware Objects Offset Kernel wise */
    { 16U },

    /* Receive Hardware Objects Offset Kernel wise */
    { 0U },

    /* Last MSPND register to be scanned for Rx MOs */
    0U,

    /* First MSPND register to be scanned for Tx MOs */
    0U,

    /* Last MSPND register to be scanned for Tx MOs */
    1U,

  }
};

#define CAN_17_MCANP_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
