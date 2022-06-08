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
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "ComAppl_Cbk.h"
#include "ComStack_Flags.h"
#include "ComStack_Macros.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
/* Flags for the Pdus */
uint8 ComStack_TxPduFlags_au8[COM_NUM_TX_IPDU];
uint8 ComStack_RxPduFlags_au8[COM_NUM_RX_IPDU];
uint8 ComStack_TransferData_Producer_au8[COM_NUM_RX_IPDU];
uint8 ComStack_TransferData_Consumer_au8[COM_NUM_RX_IPDU];
