/********************************************************************************************

IMPLICIT CONVERSIONS - FLOAT TO INTEGER

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 2006
#pragma PRQA_MESSAGES_OFF 2100
#pragma PRQA_MESSAGES_OFF 2101
#pragma PRQA_MESSAGES_OFF 2214
#pragma PRQA_MESSAGES_OFF 2889
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3210
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3450
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 4451-4454

#include "xample.h"


extern void fltoint ( void )
{

/*****************************************************************************
OLD MESSAGES
============
:3799  Implicit conversion: float to char.
:3800  Implicit conversion: float to signed char.
:3801  Implicit conversion: float to unsigned char.
:3802  Implicit conversion: float to short.
:3803  Implicit conversion: float to unsigned short.
:3804  Implicit conversion: float to int.
:3805  Implicit conversion: float to unsigned int.
:3806  Implicit conversion: float to long.
:3807  Implicit conversion: float to unsigned long.
:3876  Implicit conversion: float to long long.
:3877  Implicit conversion: float to unsigned long long.
*****************************************************************************/

    pca = fta;         /* 3799 */
    sca = fta;         /* 3800 */
    uca = fta;         /* 3801 */
    ssa = fta;         /* 3802 */
    usa = fta;         /* 3803 */
    sia = fta;         /* 3804 */
    uia = fta;         /* 3805 */
    sla = fta;         /* 3806 */
    ula = fta;         /* 3807 */
    sxa = fta;         /* 3876 */
    uxa = fta;         /* 3877 */


/*****************************************************************************
OLD MESSAGES
============
:3810  Implicit conversion: double to char.
:3811  Implicit conversion: double to signed char.
:3812  Implicit conversion: double to unsigned char.
:3813  Implicit conversion: double to short.
:3814  Implicit conversion: double to unsigned short.
:3815  Implicit conversion: double to int.
:3816  Implicit conversion: double to unsigned int.
:3817  Implicit conversion: double to long.
:3818  Implicit conversion: double to unsigned long.
:3878  Implicit conversion: double to long long.
:3879  Implicit conversion: double to unsigned long long.
*****************************************************************************/


    pca = dba;         /* 3810 */
    sca = dba;         /* 3811 */
    uca = dba;         /* 3812 */
    ssa = dba;         /* 3813 */
    usa = dba;         /* 3814 */
    sia = dba;         /* 3815 */
    uia = dba;         /* 3816 */
    sla = dba;         /* 3817 */
    ula = dba;         /* 3818 */
    sxa = dba;         /* 3878 */
    uxa = dba;         /* 3879 */


/*****************************************************************************
OLD MESSAGES
============
:3821  Implicit conversion: long double to char.
:3822  Implicit conversion: long double to signed char.
:3823  Implicit conversion: long double to unsigned char.
:3824  Implicit conversion: long double to short.
:3825  Implicit conversion: long double to unsigned short .
:3826  Implicit conversion: long double to int.
:3827  Implicit conversion: long double to unsigned int.
:3828  Implicit conversion: long double to long.
:3829  Implicit conversion: long double to unsigned long.
:3880  Implicit conversion: long double to long long.
:3881  Implicit conversion: long double to unsigned long long.
*****************************************************************************/

    pca = lda;         /* 3821 */
    sca = lda;         /* 3822 */
    uca = lda;         /* 3823 */
    ssa = lda;         /* 3824 */
    usa = lda;         /* 3825 */
    sia = lda;         /* 3826 */
    uia = lda;         /* 3827 */
    sla = lda;         /* 3828 */
    ula = lda;         /* 3829 */
    sxa = lda;         /* 3880 */
    uxa = lda;         /* 3881 */

    return;
}





/*****************************************************************************
OLD MESSAGES
============
:3999  float value returned from char %s().
:4010  double value returned from char %s().
:4021  long double value returned from char %s().
*****************************************************************************/

static char fpc(int mode)
{
    if      (mode == 0) return(fta);  /* 3999 */
    else if (mode == 1) return(dba);  /* 4010 */
    else                return(lda);  /* 4021 */
}

/*****************************************************************************
OLD MESSAGES
============
:4000  float value returned from signed char %s().
:4011  double value returned from signed char %s().
:4022  long double value returned from signed char %s().
*****************************************************************************/
static signed char fsc(int mode)
{
    if      (mode == 0) return(fta);  /* 4000 */
    else if (mode == 1) return(dba);  /* 4011 */
    else                return(lda);  /* 4022 */
}

/*****************************************************************************
OLD MESSAGES
============
:4001  float value returned from unsigned char %s().
:4012  double value returned from unsigned char %s().
:4023  long double value returned from unsigned char %s().
*****************************************************************************/
static unsigned char fuc(int mode)
{
    if      (mode == 0) return(fta);  /* 4001 */
    else if (mode == 1) return(dba);  /* 4012 */
    else                return(lda);  /* 4023 */
}

/*****************************************************************************
OLD MESSAGES
============
:4002  float value returned from short %s().
:4013  double value returned from short %s().
:4024  long double value returned from short %s().
*****************************************************************************/
static short fss(int mode)
{
    if      (mode == 0) return(fta);  /* 4002 */
    else if (mode == 1) return(dba);  /* 4013 */
    else                return(lda);  /* 4024 */
}

/*****************************************************************************
OLD MESSAGES
============
:4003  float value returned from unsigned short %s().
:4014  double value returned from unsigned short %s().
:4025  long double value returned from unsigned short %s().
*****************************************************************************/
static unsigned short fus(int mode)
{
    if      (mode == 0) return(fta);  /* 4003 */
    else if (mode == 1) return(dba);  /* 4014 */
    else                return(lda);  /* 4025 */
}

/*****************************************************************************
OLD MESSAGES
============
:4004  float value returned from int %s().
:4015  double value returned from int %s().
:4026  long double value returned from int %s().
*****************************************************************************/
static int fsi(int mode)
{
    if      (mode == 0) return(fta);  /* 4004 */
    else if (mode == 1) return(dba);  /* 4015 */
    else                return(lda);  /* 4026 */
}

/*****************************************************************************
OLD MESSAGES
============
:4005  float value returned from unsigned int %s().
:4016  double value returned from unsigned int %s().
:4027  long double value returned from unsigned int %s().
*****************************************************************************/
static unsigned int fui(int mode)
{
    if      (mode == 0) return(fta);  /* 4005 */
    else if (mode == 1) return(dba);  /* 4016 */
    else                return(lda);  /* 4027 */
}

/*****************************************************************************
OLD MESSAGES
============
:4006  float value returned from long %s().
:4017  double value returned from long %s().
:4028  long double value returned from long %s().
*****************************************************************************/
static long fsl(int mode)
{
    if      (mode == 0) return(fta);  /* 4006 */
    else if (mode == 1) return(dba);  /* 4017 */
    else                return(lda);  /* 4028 */
}

/*****************************************************************************
OLD MESSAGES
============
:4007  float value returned from unsigned long %s().
:4018  double value returned from unsigned long %s().
:4029  long double value returned from unsigned long %s().
*****************************************************************************/
static unsigned long ful(int mode)
{
    if      (mode == 0) return(fta);  /* 4007 */
    else if (mode == 1) return(dba);  /* 4018 */
    else                return(lda);  /* 4029 */
}

/*****************************************************************************
OLD MESSAGES
============
:4076  float value returned from long long %s().
:4078  double value returned from long long %s().
:4080  long double value returned from long long %s().
*****************************************************************************/
static long long fsx(int mode)
{
    if      (mode == 0) return(fta);  /* 4076 */
    else if (mode == 1) return(dba);  /* 4078 */
    else                return(lda);  /* 4080 */
}

/*****************************************************************************
OLD MESSAGES
============
:4077  float value returned from unsigned long long %s().
:4079  double value returned from unsigned long long %s().
:4081  long double value returned from unsigned long long %s().
*****************************************************************************/
static unsigned long long fux(int mode)
{
    if      (mode == 0) return(fta);  /* 4077 */
    else if (mode == 1) return(dba);  /* 4079 */
    else                return(lda);  /* 4081 */
}
