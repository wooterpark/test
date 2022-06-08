/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.        All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: Snapshot_MemFunc.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: Rory.Li$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   Initial version.

*******************************************************************************/

#include "Snapshot_MemFunc.h"

/*******************************************************************************
** Function Name : Snapshot_MemCopy
** Parameter[in] : (1)Destination Address, (2)Source Address, (3)Size
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Memory copy
*******************************************************************************/
void Snapshot_MemCopy(uint8 *dstAddr, const uint8 *srcAddr, uint32 size)
{
    uint32 temp_Size = size;
    uint8 *addr1 = dstAddr;
    const uint8 *addr2 = srcAddr;

    while (temp_Size > 0U)
    {
        *addr1 = *addr2;
        addr1++;
        addr2++;
        temp_Size--;
    }
    return;
}

/*******************************************************************************
** Function Name : Snapshot_MemSet
** Parameter[in] : (1)Destination Address, (2)Value, (3)Size
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Memory copy
*******************************************************************************/
void Snapshot_MemSet(uint8 *memAddr, uint8 value, uint32 size)
{
    uint32 temp_Size = size;
    uint8 *addr1 = memAddr;

    while (temp_Size > 0U)
    {
        *addr1 = value;
        addr1++;
        temp_Size--;
    }
    return;
}
