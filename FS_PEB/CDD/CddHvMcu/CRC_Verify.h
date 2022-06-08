/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: CRC_Verify.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: XM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
			CRC_Verify
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0: Initial version.

*******************************************************************************/
#ifndef CRC_VERIFY_H_
#define CRC_VERIFY_H_

#include "Platform_Types.h"
 /*****************************************************************************************
Function:		uint8 cal_crc_table(uint8 *ptr, uint8 len) ;
Description:   	calculati CRC16 value
Input:			ubyte *ui8_Buf buf pointer
				ubyte Len     buf length
Output:         NONE
Return:			ui16_CRC     CRC value
Time:
Other:
*****************************************************************************************/
extern uint8 cal_crc_table(uint8 const *ptr, uint8 len) ;

#endif 


