/********************************************************************************************

IMPLICIT CONVERSIONS - UNSIGNED TO SIGNED OR SMALLER SIGNED

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 2006
#pragma PRQA_MESSAGES_OFF 2100
#pragma PRQA_MESSAGES_OFF 2101
#pragma PRQA_MESSAGES_OFF 2214
#pragma PRQA_MESSAGES_OFF 2889
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3450
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 4446

#include "xample.h"


extern void foo(void)
{
/*************************************************************
OLD MESSAGES
============
:3712  Implicit conversion: unsigned char to signed char.
*************************************************************/
    sca = uca;        /* 3712 */


/*************************************************************
OLD MESSAGES
============
:3745  Implicit conversion: unsigned short to signed char.
:3747  Implicit conversion: unsigned short to short.
*************************************************************/
    sca = usa;        /* 3745 */
    ssa = usa;        /* 3747 */


/*************************************************************
OLD MESSAGES
============
:3767  Implicit conversion: unsigned int to signed char.
:3769  Implicit conversion: unsigned int to short.
:3771  Implicit conversion: unsigned int to int.
*************************************************************/
    sca = uia;        /* 3767 */
    ssa = uia;        /* 3769 */
    sia = uia;        /* 3771 */

/*************************************************************
OLD MESSAGES
============
:3789  Implicit conversion: unsigned long to signed char.
:3791  Implicit conversion: unsigned long to short.
:3793  Implicit conversion: unsigned long to int.
:3795  Implicit conversion: unsigned long to long.
*************************************************************/
    sca = ula;        /* 3789 */
    ssa = ula;        /* 3791 */
    sia = ula;        /* 3793 */
    sla = ula;        /* 3795 */


/*************************************************************
OLD MESSAGES
============
:3864  Implicit conversion: unsigned long long to signed char.
:3866  Implicit conversion: unsigned long long to short.
:3868  Implicit conversion: unsigned long long to int.
:3870  Implicit conversion: unsigned long long to long.
:3872  Implicit conversion: unsigned long long to long long.
*************************************************************/
    sca = uxa;        /* 3864 */
    ssa = uxa;        /* 3866 */
    sia = uxa;        /* 3868 */
    sla = uxa;        /* 3870 */
    sxa = uxa;        /* 3872 */

    return;
}

/*************************************************************
OLD MESSAGES
============
:3912  unsigned char value returned from signed char %s().
:3945  unsigned short value returned from signed char %s().
:3967  unsigned int value returned from signed char %s().
:3989  unsigned long value returned from signed char %s().
:4064  unsigned long long value returned from signed char %s().
*************************************************************/
extern signed char fsc(int mode)
{
    if      (mode == 0) return(uca);    /* 3912 */
    else if (mode == 1) return(usa);    /* 3945 */
    else if (mode == 2) return(uia);    /* 3967 */
    else if (mode == 3) return(ula);    /* 3989 */
    else                return(uxa);    /* 4064 */
}

/*************************************************************
OLD MESSAGES
============
:3947  unsigned short value returned from short %s().
:3969  unsigned int value returned from short %s().
:3991  unsigned long value returned from short %s().
:4066  unsigned long long value returned from short %s().
*************************************************************/
extern short fss(int mode)
{
    if      (mode == 0) return(usa);    /* 3947 */
    else if (mode == 1) return(uia);    /* 3969 */
    else if (mode == 2) return(ula);    /* 3991 */
    else                return(uxa);    /* 4066 */
}

/*************************************************************
OLD MESSAGES
============
:3971  unsigned int value returned from int %s().
:3993  unsigned long value returned from int %s().
:4068  unsigned long long value returned from int %s().
*************************************************************/
extern int fsi(int mode)
{
    if      (mode == 0) return(uia);    /* 3971 */
    else if (mode == 1) return(ula);    /* 3993 */
    else                return(uxa);    /* 4068 */
}

/*************************************************************
OLD MESSAGES
============
:3995  unsigned long value returned from long %s().
:4070  unsigned long long value returned from long %s().
*************************************************************/
extern long fsl(int mode)
{
    if      (mode == 0) return(ula);    /* 3995 */
    else                return(uxa);    /* 4070 */
}

/*************************************************************
OLD MESSAGES
============
:4072  unsigned long long value returned from long long %s().
*************************************************************/
extern long long fsx(void)
{
    return(uxa);                        /* 4072 */
}
