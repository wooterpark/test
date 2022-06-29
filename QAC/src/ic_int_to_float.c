/********************************************************************************************

IMPLICIT CONVERSIONS - INTEGER TO FLOAT

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
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 4415
#pragma PRQA_MESSAGES_OFF 4435
#pragma PRQA_MESSAGES_OFF 4445

#include "xample.h"

extern void intfloat( void )
{
/*****************************************************************************
OLD MESSAGES
============
:3730  Implicit conversion: signed char to float.
:3731  Implicit conversion: signed char to double.
:3732  Implicit conversion: signed char to long double.
*****************************************************************************/

    fta = sca;    /* 3730 */
    dba = sca;    /* 3731 */
    lda = sca;    /* 3732 */

/*****************************************************************************
OLD MESSAGES
============
:3719  Implicit conversion: unsigned char to float.
:3720  Implicit conversion: unsigned char to double.
:3721  Implicit conversion: unsigned char to long double.
*****************************************************************************/
    fta = uca;    /* 3719 */
    dba = uca;    /* 3720 */
    lda = uca;    /* 3721 */

/*****************************************************************************
OLD MESSAGES
============
:3708  Implicit conversion: char to float.
:3709  Implicit conversion: char to double.
:3710  Implicit conversion: char to long double.
*****************************************************************************/
    fta = pca;    /* 3708 */
    dba = pca;    /* 3709 */
    lda = pca;    /* 3710 */

/*****************************************************************************
OLD MESSAGES
============
:3741  Implicit conversion: short to float.
:3742  Implicit conversion: short to double.
:3743  Implicit conversion: short to long double.
*****************************************************************************/
    fta = ssa;    /* 3741 */
    dba = ssa;    /* 3742 */
    lda = ssa;    /* 3743 */

/*****************************************************************************
OLD MESSAGES
============
:3752  Implicit conversion: unsigned short to float.
:3753  Implicit conversion: unsigned short to double.
:3754  Implicit conversion: unsigned short to long double.
*****************************************************************************/
    fta = usa;    /* 3752 */
    dba = usa;    /* 3753 */
    lda = usa;    /* 3754 */

/*****************************************************************************
OLD MESSAGES
============
:3763  Implicit conversion: int to float.
:3764  Implicit conversion: int to double.
:3765  Implicit conversion: int to long double.
*****************************************************************************/
    fta = sia;    /* 3763 */
    dba = sia;    /* 3764 */
    lda = sia;    /* 3765 */

/*****************************************************************************
OLD MESSAGES
============
:3774  Implicit conversion: unsigned int to float.
:3775  Implicit conversion: unsigned int to double.
:3776  Implicit conversion: unsigned int to long double.
*****************************************************************************/
    fta = uia;    /* 3774 */
    dba = uia;    /* 3775 */
    lda = uia;    /* 3776 */

/*****************************************************************************
OLD MESSAGES
============
:3785  Implicit conversion: long to float.
:3786  Implicit conversion: long to double.
:3787  Implicit conversion: long to long double.
*****************************************************************************/
    fta = sla;    /* 3785 */
    dba = sla;    /* 3786 */
    lda = sla;    /* 3787 */

/*****************************************************************************
OLD MESSAGES
============
:3796  Implicit conversion: unsigned long to float.
:3797  Implicit conversion: unsigned long to double.
:3798  Implicit conversion: unsigned long to long double.
*****************************************************************************/
    fta = ula;    /* 3796 */
    dba = ula;    /* 3797 */
    lda = ula;    /* 3798 */

/*****************************************************************************
OLD MESSAGES
============
:3860  Implicit conversion: long long to float.
:3861  Implicit conversion: long long to double.
:3862  Implicit conversion: long long to long double.
*****************************************************************************/
    fta = sxa;   /* 3860 */
    dba = sxa;   /* 3861 */
    lda = sxa;   /* 3862 */

/*****************************************************************************
OLD MESSAGES
============
:3873  Implicit conversion: unsigned long long to float.
:3874  Implicit conversion: unsigned long long to double.
:3875  Implicit conversion: unsigned long long to long double.
*****************************************************************************/
    fta = uxa;   /* 3873 */
    dba = uxa;   /* 3874 */
    lda = uxa;   /* 3875 */

}



/*****************************************************************************
OLD MESSAGES
============
:3908  char value returned from float %s().
:3930  signed char value returned from float %s().
:3919  unsigned char value returned from float %s().
:3941  short value returned from float %s().
:3952  unsigned short value returned from float %s().
:3963  int value returned from float %s().
:3974  unsigned int value returned from float %s().
:3985  long value returned from float %s().
:3996  unsigned long value returned from float %s().
:4060  long long value returned from float %s().
:4073  unsigned long long value returned from float %s().
*****************************************************************************/
static float fft( int mode )
{
    if      (mode == 0) return(pca);  /* 3908 */
    else if (mode == 1) return(sca);  /* 3930 */
    else if (mode == 2) return(uca);  /* 3919 */
    else if (mode == 3) return(ssa);  /* 3941 */
    else if (mode == 4) return(usa);  /* 3952 */
    else if (mode == 5) return(sia);  /* 3963 */
    else if (mode == 6) return(uia);  /* 3974 */
    else if (mode == 7) return(sla);  /* 3985 */
    else if (mode == 8) return(ula);  /* 3996 */
    else if (mode == 9) return(sxa);  /* 4060 */
    else                return(uxa);  /* 4073 */
}



/*****************************************************************************
OLD MESSAGES
============
:3909  char value returned from double %s().
:3931  signed char value returned from double %s().
:3920  unsigned char value returned from double %s().
:3942  short value returned from double %s().
:3953  unsigned short value returned from double %s().
:3964  int value returned from double %s().
:3975  unsigned int value returned from double %s().
:3986  long value returned from double %s().
:3997  unsigned long value returned from double %s().
:4061  long long value returned from double %s().
:4074  unsigned long long value returned from double %s().
*****************************************************************************/
static double fdb( int mode )
{
    if      (mode == 0) return(pca);  /* 3909 */
    else if (mode == 1) return(sca);  /* 3931 */
    else if (mode == 2) return(uca);  /* 3920 */
    else if (mode == 3) return(ssa);  /* 3942 */
    else if (mode == 4) return(usa);  /* 3953 */
    else if (mode == 5) return(sia);  /* 3964 */
    else if (mode == 6) return(uia);  /* 3975 */
    else if (mode == 7) return(sla);  /* 3986 */
    else if (mode == 8) return(ula);  /* 3997 */
    else if (mode == 9) return(sxa);  /* 4061 */
    else                return(uxa);  /* 4074 */
}


/*****************************************************************************
OLD MESSAGES
============
:3910  char value returned from long double %s().
:3932  signed char value returned from long double %s().
:3921  unsigned char value returned from long double %s().
:3943  short value returned from long double %s().
:3954  unsigned short value returned from long double %s().
:3965  int value returned from long double %s().
:3976  unsigned int value returned from long double %s().
:3987  long value returned from long double %s().
:3998  unsigned long value returned from long double %s().
:4062  long long value returned from long double %s().
:4075  unsigned long long value returned from long double %s().
*****************************************************************************/
static long double fld( int mode )
{
    if      (mode == 0) return(pca);  /* 3910 */
    else if (mode == 1) return(sca);  /* 3932 */
    else if (mode == 2) return(uca);  /* 3921 */
    else if (mode == 3) return(ssa);  /* 3943 */
    else if (mode == 4) return(usa);  /* 3954 */
    else if (mode == 5) return(sia);  /* 3965 */
    else if (mode == 6) return(uia);  /* 3976 */
    else if (mode == 7) return(sla);  /* 3987 */
    else if (mode == 8) return(ula);  /* 3998 */
    else if (mode == 9) return(sxa);  /* 4062 */
    else                return(uxa);  /* 4075 */
}
