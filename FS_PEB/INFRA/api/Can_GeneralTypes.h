

/**
\defgroup CAN_GENERALTYPES_H    CANIF - AUTOSAR interfaces Upper Layer
*/
#ifndef CAN_GENERAL_TYPES_H
#define CAN_GENERAL_TYPES_H

#define CAN_UPPER_READONLY
#define CANIF_CFG_CONST

#include "ComStack_Types.h"
#ifndef VECURH850P1X //Autosar 4.0.2 driver specifies that can_cfg.h shall be included from Can.h (p. 17)
//#include "Can_Cfg.h"
#else
#define Can_Config Can_ConfigData
#endif


/* FC_VariationPoint_START */
/* Size of CanId */
//#if(CAN_EXTENDED_ID != STD_OFF)
typedef uint32 Can_IdType;  /* CIX2SGH */
//#else
//typedef uint16 Can_IdType;
//#endif
/* FC_VariationPoint_END */

typedef uint16 Can_HwHandleType; /*[$CAN 429]*/

/**
 * @ingroup CAN_GENERALTYPES_H
 *
 * This is a Can Pdu Type structure \n
 * typedef struct                   \n
 * {                                \n
 *   P2VAR(uint8,TYPEDEF,CAN_UPPER_READONLY) sdu;   This corresponds to the data unit pointer \n
 *   Can_IdType id;                                 This variable indicates the Can Id.  \n
 *   PduIdType  swPduHandle;                        This variable determines the Pdu Handle \n
 *   uint8      length;                             This corresponds to the length of the Pdu \n
 * }Can_PduType;                    \n
 */
typedef struct
{
    P2VAR(uint8,TYPEDEF,CAN_UPPER_READONLY) sdu;
    Can_IdType id;
    PduIdType  swPduHandle;
    uint8      length;

}Can_PduType;
/**
 * @ingroup CAN_GENERALTYPES_H
 *
 * This enum represents the CAN state Transition type       \n
 *typedef enum                                              \n
 * {                                                            \n
 *  CAN_T_START,           CAN controller transition value to request state STARTED \n
 *  CAN_T_STOP,            CAN controller transition value to request state STOPPED \n
 *  CAN_T_SLEEP,           CAN controller transition value to request state SLEEP   \n
 *  CAN_T_WAKEUP,          CAN controller transition value to request state STOPPED from state SLEEP \n
 *  CAN_T_MAXTRANSITION    Max number of transitions that can happen  \n
 * }Can_StateTransitionType;
 */
typedef enum
{
    CAN_T_START,
    CAN_T_STOP,
    CAN_T_SLEEP,
    CAN_T_WAKEUP,
    CAN_T_MAXTRANSITION

}Can_StateTransitionType;

/**
 * @ingroup CAN_GENERALTYPES_H
 *
 * This enum represents the CAN return type         \n
 * typedef enum                                             \n
 *  {                                                       \n
 *   CAN_OK,                Represents CAN bus has been allocated successfully \n
 *   CAN_NOT_OK,            Error occurred or wakeup event occurred during sleep transition \n
 *   CAN_BUSY               Transmit request could not be processed because no transmit object was available \n
 *  }Can_ReturnType;
 */
typedef enum
{
    CAN_OK,
    CAN_NOT_OK,
    CAN_BUSY

}Can_ReturnType;

/**
 * @ingroup CAN_GENERALTYPES_H
 *
 * Types of operating modes of canif, can controller and driver \n
 * typedef enum                                                 \n
 *  {                                                           \n
 *    CANIF_CS_UNINIT = 0,      Default mode of the CAN Driver and all CAN controllers connected to one CAN network after power on. \n
 *    CANIF_CS_STOPPED,         At least one of all CAN controllers connected to one CAN network is halted and does not operate on the network. \n
 *    CANIF_CS_STARTED,         All CAN controllers connected to one CAN network are started by the CAN Driver and in full-operational mode. \n
 *    CANIF_CS_SLEEP,           At least one of all CAN controllers connected to one CAN network are set into the SLEEP mode and can be woken up
 *                              by request of the CAN Driver or by a network event \n
 *    CANIF_CS_MAXMODE          Need to be removed as a part of IP clean up  \n
 *  }CanIf_ControllerModeType;
 */
typedef enum
{
    CANIF_CS_UNINIT = 0,
    CANIF_CS_STOPPED,
    CANIF_CS_STARTED,
    CANIF_CS_SLEEP,
    CANIF_CS_MAXMODE

}CanIf_ControllerModeType;
/**
 * @ingroup CAN_GENERALTYPES_H
 *
 * This enum indicates the Can tranceiver state             \n
 * typedef enum                                             \n
 * {                                                        \n
 *  CANTRCV_TRCVMODE_NORMAL=0,    Transceiver mode NORMAL   \n
 *  CANTRCV_TRCVMODE_SLEEP,       Transceiver mode SLEEP    \n
 *  CANTRCV_TRCVMODE_STANDBY      Transceiver mode STANDBY  \n
 *}CanTrcv_TrcvModeType;
 */
typedef enum
{
    CANTRCV_TRCVMODE_NORMAL=0,
    CANTRCV_TRCVMODE_SLEEP,
    CANTRCV_TRCVMODE_STANDBY

}CanTrcv_TrcvModeType;

/**
 * @ingroup CAN_GENERALTYPES_H
 *
 * CAN transceiver concerned wake up events and wake up notifications.                                  \n
 * typedef enum                                                                                         \n
 * {                                                                                                    \n
 *  CANTRCV_WUMODE_ENABLE=0,    The notification for wakeup events is enabled on the addressed network. \n
 *  CANTRCV_WUMODE_DISABLE,     The notification for wakeup events is disabled on the addressed network.\n
 *  CANTRCV_WUMODE_CLEAR        A stored wakeup event is cleared on the addressed network.              \n
 * }CanTrcv_TrcvWakeupModeType;
 */
typedef enum
{
    CANTRCV_WUMODE_ENABLE=0,
    CANTRCV_WUMODE_DISABLE,
    CANTRCV_WUMODE_CLEAR

}CanTrcv_TrcvWakeupModeType;


/**
 * @ingroup CAN_GENERALTYPES_H
 *
 * Wake up reason detected by the CAN transceiver.
 * typedef enum
 * {
 *  CANTRCV_WU_ERROR=0,         Wake up reason not detected due to some error. This may only be reported when error was reported to DEM before \n
 *  CANTRCV_WU_NOT_SUPPORTED,   The transceiver does not support any information for the wake up reason.\n
 *  CANTRCV_WU_BY_BUS,          The transceiver has detected, that the network has caused the wake up of the ECU.\n
 *  CANTRCV_WU_INTERNALLY,      The transceiver has detected, that the network has woken up by the ECU via a request to NORMAL mode. \n
 *  CANTRCV_WU_RESET,           The transceiver has detected, that the "wake up" is due to an ECU reset. \n
 *  CANTRCV_WU_POWER_ON,        The transceiver has detected, that the "wake up" is due to an ECU reset after power on.\n
 *  CANTRCV_WU_BY_PIN           The transceiver has detected a wake-up event at one of the transceiver's pins (not at the CAN bus). \n
 * }CanTrcv_TrcvWakeupReasonType;
 */
typedef enum
{

    CANTRCV_WU_ERROR=0,
    CANTRCV_WU_NOT_SUPPORTED,
    CANTRCV_WU_BY_BUS,
    CANTRCV_WU_INTERNALLY,
    CANTRCV_WU_RESET,
    CANTRCV_WU_POWER_ON,
    CANTRCV_WU_BY_PIN

}CanTrcv_TrcvWakeupReasonType;
#endif /* CAN_GENERAL_TYPES_H */

/*<BASDKey>
*********************************************************************************************************
* $History___:$
*********************************************************************************************************
</BASDKey>*/

/*<BASDKey>
**********************************************************************************************************************
* End of header file: $Name______:$
**********************************************************************************************************************
</BASDKey>*/
