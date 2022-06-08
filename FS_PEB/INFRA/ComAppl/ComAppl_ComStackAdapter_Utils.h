/*<BASDKey>
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, ETAS GmbH, 2019. All rights reserved.
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
#ifndef ComAppl_COMSTACKADAPTER_UTILS_H
#define ComAppl_COMSTACKADAPTER_UTILS_H

#include "ComStack_Types.h"

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/
extern uint32 ComAppl_UnPackSignal(const uint8* Src_Buf,
                                uint8 Bit_Pos,
                                uint8 Bitsize,
                                boolean  IntelFormat,
                                uint8 MsgLength);

extern void   ComAppl_PackSignal(uint8* Dest_Buf,
                                uint32 Src_Buf,
                                uint8 Bit_Pos,
                                uint8 Bitsize,
                                boolean IntelFormat,
                                uint8 MsgLength);



#endif /* ComAppl_CUBAS_COMSTACKADAPTER_UTILS_H */

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
