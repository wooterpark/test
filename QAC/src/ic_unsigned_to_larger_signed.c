/********************************************************************************************

IMPLICIT CONVERSIONS - UNSIGNED TO LARGER SIGNED TYPE

********************************************************************************************/

#pragma PRQA_MESSAGES_OFF 2006
#pragma PRQA_MESSAGES_OFF 2100
#pragma PRQA_MESSAGES_OFF 2101
#pragma PRQA_MESSAGES_OFF 2201
#pragma PRQA_MESSAGES_OFF 2214
#pragma PRQA_MESSAGES_OFF 2889
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3206
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3450
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 4443
#pragma PRQA_MESSAGES_OFF 4446

#include "xample.h"


extern void unstolsigned(void)
{
/******************************************************************
OLD MESSAGES
============
:3713  Implicit conversion: unsigned char to short.
:3715  Implicit conversion: unsigned char to int.
:3717  Implicit conversion: unsigned char to long.
:3834  Implicit conversion: unsigned char to long long.
******************************************************************/
    ssa = uca;                          /* 3713 */
    sia = uca;                          /* 3715 */
    sla = uca;                          /* 3717 */
    sxa = uca;                          /* 3834 */

/******************************************************************
OLD MESSAGES
============
:3748  Implicit conversion: unsigned short to int.
:3750  Implicit conversion: unsigned short to long.
:3840  Implicit conversion: unsigned short to long long.
******************************************************************/
    sia = usa;                          /* 3748 */
    sla = usa;                          /* 3750 */
    sxa = usa;                          /* 3840 */

/******************************************************************
OLD MESSAGES
============
:3772  Implicit conversion: unsigned int to long.
:3844  Implicit conversion: unsigned int to long long.
******************************************************************/
    sla = uia;                          /* 3772 */
    sxa = uia;                          /* 3844 */

/******************************************************************
OLD MESSAGES
============
:3848  Implicit conversion: unsigned long to long long.
******************************************************************/
    sxa = ula;                          /* 3848 */

    return;
}



/******************************************************************
OLD MESSAGES
============
:3913  unsigned char value returned from short %s().
******************************************************************/
static short fus(int mode)
{
    return(uca);                        /* 3913 */
}

/******************************************************************
OLD MESSAGES
============
:3915  unsigned char value returned from int %s().
:3948  unsigned short value returned from int %s().
******************************************************************/
static int fui(int mode)
{
    if      (mode == 0) return(uca);    /* 3915 */
    else                return(usa);    /* 3948 */
}

/******************************************************************
OLD MESSAGES
============
:3917  unsigned char value returned from long %s().
:3950  unsigned short value returned from long %s().
:3972  unsigned int value returned from long %s().
******************************************************************/
static long ful(int mode)
{
    if      (mode == 0) return(uca);    /* 3917 */
    else if (mode == 1) return(usa);    /* 3950 */
    else                return(uia);    /* 3972 */
}

/******************************************************************
OLD MESSAGES
============
:4034  unsigned char value returned from long long %s().
:4040  unsigned short value returned from long long %s().
:4044  unsigned int value returned from long long %s().
:4048  unsigned long value returned from long long %s().
******************************************************************/
static long long fux(int mode)
{
    if      (mode == 0) return(uca);    /* 4034 */
    else if (mode == 1) return(usa);    /* 4040 */
    else if (mode == 2) return(uia);    /* 4044 */
    else                return(ula);    /* 4048 */
}
