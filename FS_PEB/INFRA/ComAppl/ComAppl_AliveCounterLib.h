/*<BASDKey>
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, RTAS GmbH, 2019. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 * Administrative Information (automatically filled in)
 * $Domain____:$
 * $Namespace_:$
 * $Class_____:$
 * $Name______:$
 * $Variant___:$
 * $Revision__:$
 **********************************************************************************************************************
</BASDKey>*/
#ifndef COMAPPL_ALIVECOUNTERLIB_H
#define COMAPPL_ALIVECOUNTERLIB_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "ComStack_Types.h"

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/

extern boolean ComAppl_EvalAc_Std(uint8 receivedAliveCounter, uint8 lastAliveCounter);
extern uint8 ComAppl_GenAc_Std(uint8 lastAliveCounter);

#endif /* RBA_COMSCL_ALIVECOUNTERLIB_H */

/*<BASDKey>
 **********************************************************************************************************************
 * $History___:$
 **********************************************************************************************************************
</BASDKey>*/

/*<BASDKey>
 **********************************************************************************************************************
 * End of header file: $Name______:$
 **********************************************************************************************************************
</BASDKey>*/
