/*
 * stubs.c
 *
 *  Created on: Jan 31, 2018
 *      Author: CIX2SGH
 */

#include "Fee.h"
#include "rba_FeeFs1_Prv.h"





/**************************************************************/
/* implementation of the blank check missing in MCAL		  */
/**************************************************************/

#define MAX_BLANK_CHECK_SIZE (((FEE_SEC_HEADER_SIZE/FEE_NUM_MARKER_IN_HEADER) > FEE_PAGE_LEN) ? (FEE_SEC_HEADER_SIZE/FEE_NUM_MARKER_IN_HEADER) : FEE_PAGE_LEN)


Std_ReturnType Fls_BlankCheck(Fls_AddressType TargetAddress,
                                         Fls_LengthType Length)
{
	Std_ReturnType RetVal;
    static uint8 compare_block[MAX_BLANK_CHECK_SIZE];
    uint32 blockIndex;
    for(blockIndex=0; blockIndex < Length; blockIndex++)
    {
    	compare_block[blockIndex] = (uint8)FEE_ERASE_PATTERN;
    }

    RetVal = Fls_Compare((Fls_AddressType)TargetAddress, &compare_block[0] , Length );
	return RetVal;

}



