/********************************************************************************************

IMPLICIT CONVERSIONS - SIGNED TO UNSIGNED

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
#pragma PRQA_MESSAGES_OFF 4434

#include "xample.h"


extern void foo ( void )
{
/******************************************************************
OLD MESSAGES
============
:3723  Implicit conversion: signed char to unsigned char.
:3725  Implicit conversion: signed char to unsigned short.
:3727  Implicit conversion: signed char to unsigned int.
:3729  Implicit conversion: signed char to unsigned long.
:3837  Implicit conversion: signed char to unsigned long long.
******************************************************************/
    uca = sca;        /* 3723 */
    usa = sca;        /* 3725 */
    uia = sca;        /* 3727 */
    ula = sca;        /* 3729 */
    uxa = sca;        /* 3837 */



/******************************************************************
OLD MESSAGES
============
:3735  Implicit conversion: short to unsigned char.
:3736  Implicit conversion: short to unsigned short.
:3738  Implicit conversion: short to unsigned int.
:3740  Implicit conversion: short to unsigned long.
:3839  Implicit conversion: short to unsigned long long.
******************************************************************/
    uca = ssa;        /* 3735 */
    usa = ssa;        /* 3736 */
    uia = ssa;        /* 3738 */
    ula = ssa;        /* 3740 */
    uxa = ssa;        /* 3839 */



/******************************************************************
OLD MESSAGES
============
:3757  Implicit conversion: int to unsigned char.
:3759  Implicit conversion: int to unsigned short.
:3760  Implicit conversion: int to unsigned int.
:3762  Implicit conversion: int to unsigned long.
:3843  Implicit conversion: int to unsigned long long.
******************************************************************/
    uca = sia;        /* 3757 */
    usa = sia;        /* 3759 */
    ula = sia;        /* 3762 */
    uia = sia;        /* 3760 */
    uxa = sia;        /* 3843 */



/******************************************************************
OLD MESSAGES
============
:3779  Implicit conversion: long to unsigned char.
:3781  Implicit conversion: long to unsigned short.
:3783  Implicit conversion: long to unsigned int.
:3784  Implicit conversion: long to unsigned long.
:3847  Implicit conversion: long to unsigned long long.
******************************************************************/
    uca = sla;        /* 3779 */
    usa = sla;        /* 3781 */
    uia = sla;        /* 3783 */
    ula = sla;        /* 3784 */
    uxa = sla;        /* 3847 */



/******************************************************************
OLD MESSAGES
============
:3852  Implicit conversion: long long to unsigned char.
:3854  Implicit conversion: long long to unsigned short.
:3856  Implicit conversion: long long to unsigned int.
:3858  Implicit conversion: long long to unsigned long.
:3859  Implicit conversion: long long to unsigned long long.
******************************************************************/
    uca = sxa;        /* 3852 */
    usa = sxa;        /* 3854 */
    uia = sxa;        /* 3856 */
    ula = sxa;        /* 3858 */
    uxa = sxa;        /* 3859 */


    return;
}

/******************************************************************
OLD MESSAGES
============
:3923  signed char value returned from unsigned char %s().
:3935  short value returned from unsigned char %s().
:3957  int value returned from unsigned char %s().
:3979  long value returned from unsigned char %s().
:4052  long long value returned from unsigned char %s().
******************************************************************/
static unsigned char fuc(int mode)
{
    if      (mode == 0) return(sca);  /* 3923 */
    else if (mode == 1) return(ssa);  /* 3935 */
    else if (mode == 2) return(sia);  /* 3957 */
    else if (mode == 3) return(sla);  /* 3979 */
    else                return(sxa);  /* 4052 */
}


/******************************************************************
OLD MESSAGES
============
:3925  signed char value returned from unsigned short %s().
:3936  short value returned from unsigned short %s().
:3959  int value returned from unsigned short %s().
:3981  long value returned from unsigned short %s().
:4054  long long value returned from unsigned short %s().
******************************************************************/
static unsigned short fus(int mode)
{
    if      (mode == 0) return(sca);  /* 3925 */
    else if (mode == 1) return(ssa);  /* 3936 */
    else if (mode == 2) return(sia);  /* 3959 */
    else if (mode == 3) return(sla);  /* 3981 */
    else                return(sxa);  /* 4054 */
}


/******************************************************************
OLD MESSAGES
============
:3927  signed char value returned from unsigned int %s().
:3938  short value returned from unsigned int %s().
:3960  int value returned from unsigned int %s().
:3983  long value returned from unsigned int %s().
:4056  long long value returned from unsigned int %s().
******************************************************************/
static unsigned int fui(int mode)
{
    if      (mode == 0) return(sca);  /* 3927 */
    else if (mode == 1) return(ssa);  /* 3938 */
    else if (mode == 2) return(sia);  /* 3960 */
    else if (mode == 3) return(sla);  /* 3983 */
    else                return(sxa);  /* 4056 */
}


/******************************************************************
OLD MESSAGES
============
:3929  signed char value returned from unsigned long %s().
:3940  short value returned from unsigned long %s().
:3962  int value returned from unsigned long %s().
:3984  long value returned from unsigned long %s().
:4058  long long value returned from unsigned long %s().
******************************************************************/
static unsigned long ful(int mode)
{
    if      (mode == 0) return(sca);  /* 3929 */
    else if (mode == 1) return(ssa);  /* 3940 */
    else if (mode == 2) return(sia);  /* 3962 */
    else if (mode == 3) return(sla);  /* 3984 */
    else                return(sxa);  /* 4058 */
}


/******************************************************************
OLD MESSAGES
============
:4037  signed char value returned from unsigned long long %s().
:4039  short value returned from unsigned long long %s().
:4043  int value returned from unsigned long long %s().
:4047  long value returned from unsigned long long %s().
:4059  long long value returned from unsigned long long %s().
******************************************************************/
static unsigned long long fux(int mode)
{
    if      (mode == 0) return(sca);  /* 4037 */
    else if (mode == 1) return(ssa);  /* 4039 */
    else if (mode == 2) return(sia);  /* 4043 */
    else if (mode == 3) return(sla);  /* 4047 */
    else                return(sxa);  /* 4059 */
}
