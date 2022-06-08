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
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "ComAppl_AliveCounterLib.h"

/*
 ***************************************************************************************************
 * Functions
 ***************************************************************************************************
 */
/**
 * Evaluate if the received AliveCounter (receivedAliveCounter) and the previously received (lastAliveCounter)
 * have a different value.
 * Parameters:
 *    receivedAliveCounter: AliveCounter received in the Pdu.
 *    lastAliveCounter: AliveCounter previously received.
 * Output:  TRUE: The AliveCounter has changed.
 *          FALSE: The AliveCounter has NOT changed.
 */
boolean ComAppl_EvalAc_Std(uint8 receivedAliveCounter, uint8 lastAliveCounter)
{
    boolean isOk;

    isOk = TRUE;

//    if( (receivedAliveCounter == lastAliveCounter) )
    if( (receivedAliveCounter - lastAliveCounter==1)||(receivedAliveCounter - lastAliveCounter==-15))
    {
        isOk = TRUE;
    }
    else
    {
        isOk = FALSE;
    }
    return (isOk);
}


/**
 * Generate a Counter module 15.
 * Parameters:
 *    lastAliveCounterPtr: AliveCounter previously generated.
 * Output: New value of the AliveCounter.
 */
uint8 ComAppl_GenAc_Std(uint8 lastAliveCounter)
{
    uint8 msgCtr_u8 = lastAliveCounter;

    if(msgCtr_u8 < 14)
    {
        msgCtr_u8++;
    }
    else
    {
        msgCtr_u8 = 0;
    }

    lastAliveCounter = msgCtr_u8;

    return (msgCtr_u8);
}

/*<BASDKey>
 **********************************************************************************************************************
 * $History___:$
 **********************************************************************************************************************
</BASDKey>*/
