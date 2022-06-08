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
* $Name______: Snapshot_MemFunc.h$
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

#ifndef _SNAPSHOT_MEM_FUNC_H_
#define _SNAPSHOT_MEM_FUNC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

/*******************************************************************************
** Function Name : Snapshot_MemCopy
** Parameter[in] : (1)Destination Address, (2)Source Address, (3)Size
** Parameter[out]: None
** Return Value  : None
** Note          :
** Description   : Memory copy
*******************************************************************************/
extern void Snapshot_MemCopy(uint8 *dstAddr, const uint8 *srcAddr, uint32 size);

/*******************************************************************************
** Function Name : Snapshot_MemSet
** Parameter[in] : (1)Destination Address, (2)Value, (3)Size
** Parameter[out]: None
** Return Value  : None
** Note          :
** Description   : Memory copy
*******************************************************************************/
extern void Snapshot_MemSet(uint8 *memAddr, uint8 value, uint32 size);

#ifdef __cplusplus
}
#endif

#endif
