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
/*<VersionHead>
 * This File is generated using BCT Tool (automatically filled in) as listed below.
 *
 * $Generator__: rba_ComScl / AR40.21.0.0	Module Package Version
 * $Editor_____: ECU.WorX_2018.1.0 		Tool Version
 * $Model______: 1.0.0.0 					ECU Parameter Definition Version
 *
 </VersionHead>
 */
#ifndef COMSTACK_FLAGS_H
#define COMSTACK_FLAGS_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "ComStack_Types.h"
#include "Com_PBCfg.h"
#include "Com_Cfg_SymbolicNames.h"
#include "ComStack_Macros.h"
/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
/* Flags for the Pdus */
extern uint8 ComStack_TxPduFlags_au8[];
extern uint8 ComStack_RxPduFlags_au8[];
extern uint8 ComStack_TransferData_Producer_au8[];
extern uint8 ComStack_TransferData_Consumer_au8[];



#endif /* End of multiple include protection */
