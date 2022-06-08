/*
 ********************************************************************************************************************** 
 *
 * COPYRIGHT RESERVED, 2018 Robert Bosch GmbH. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 ********************************************************************************************************************** 
 */
#ifndef COMSTACK_MACROS_H
#define COMSTACK_MACROS_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "ComStack_Types.h"
#include "ComStack_Flags.h"
/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */
/* Test, Set and Reset Bit Macros */
#define ComStack_TestBit(Variable,SetMask)   ((boolean)(((Variable) & (SetMask)) == (SetMask)))
#define ComStack_SetBit(Variable,SetMask)    \
    do\
    {\
        (Variable) |= (SetMask);\
    }while (0)
#define ComStack_ResBit(Variable,SetMask)    \
    do\
    {\
        (Variable) &= (uint8)(~(SetMask));\
    }while (0)\

/* Timeout Flag (COM does NOT receive the Pdu) */
#define ComStack_Flag_TO               ((uint8)0x01) /* Bit 0 */
/* DLC Flag (only for CAN/LIN?) COM does NOT receive the Pdu and CanIf calls the User_DlcErrorNotification) */
#define ComStack_Flag_DLC              ((uint8)0x02) /* Bit 1 */
/* Checksum Error Flag for Pdu or SignalGroup */
#define ComStack_Flag_CHK              ((uint8)0x04) /* Bit 2 */
/* AliveCounter Error Flag for Pdu or SignalGroup */
#define ComStack_Flag_AC               ((uint8)0x08) /* Bit 3 */
#define ComStack_Flag_RxOnceUnEval     ((uint8)0x10) /* Bit 4 */
#define ComStack_Flag_RxOnceEval       ((uint8)0x20) /* Bit 5 */
/* Indication that a Pdu or SignalGroup has been received */
#define ComStack_Flag_Indication       ((uint8)0x40) /* Bit 6 */
/* Flag to detect a timeout error that happens after a DLC error for Pdu or SignalGroup */
#define ComStack_Flag_DLCErrNoTO       ((uint8)0x80) /* Bit 7 */
/*******************************************/
/* Transfer data byte layout               */
/*******************************************/
/*|Bit    | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |*/
/*+-------+---------------+---+---+---+---+*/
/*|       |    Counter    |AC |CHK|   |   |*/
/*******************************************/
/* Transfer data flags */
#define ComStack_Mask_TransferFlags             ((uint8)0x0F) /* Bit 0-3 */
#define ComStack_Flag_TransferCHK               ComStack_Flag_CHK
#define ComStack_Flag_TransferAC                ComStack_Flag_AC
#define ComStack_Flag_TransferDLC               ComStack_Flag_DLC
/* Transfer data counter */
#define ComStack_Val_TransferCounterInc    ((uint8)0x10)
/*************************/
/* Number of ReceivePdus */
/*************************/
#define ComStack_NumRxPDUs   	((uint8)8)

#endif /* End of multiple include protection */
