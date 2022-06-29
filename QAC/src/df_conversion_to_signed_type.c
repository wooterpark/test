/*****************************************************************************

CONVERSIONS TO SIGNED INTEGER TYPES

******************************************************************************/

#pragma PRQA_MESSAGES_OFF 2000,2017,2984,2982,3120,3198,3227,3408,3447,3756,3758,3602,4460
/********************************************************************************************

CONVERSIONS TO A SIGNED INTEGER TYPE
====================================

Conversions to a signed type of insufficient size.
These messages are generated when a positive or negative integer value
is (or may be) too large for the signed type to which it is being converted

OBSOLETE MESSAGES:

:0274  [I] Conversion of integer constant expression to a signed integer type which cannot represent the value.
:0273  [I] Definite conversion of integer expression to a signed integer type which cannot represent the value.
:0272  [I] Apparent conversion of integer expression to a signed integer type which cannot represent the value.


NEW MESSAGES:

:2850  Constant: Implicit conversion to a signed integer type of insufficient size.
:2851  Definite: Implicit conversion to a signed integer type of insufficient size.
:2852  Apparent: Implicit conversion to a signed integer type of insufficient size.
:2853  Suspicious: Implicit conversion to a signed integer type of insufficient size.

:2856  Definite: Casting to a signed integer type of insufficient size.
:2857  Apparent: Casting to a signed integer type of insufficient size.
:2858  Suspicious: Casting to a signed integer type of insufficient size.

********************************************************************************************/

extern signed short ssa;
extern signed short ssb;
extern signed char  sca;


extern void f1 (int sip1, int sip2, int sip3)
{
    int sia = 128;
    int i;

/* CONSTANT */
    ssa = 40000;                                /* 2850 */

/* DEFINITE */
    if (sip1 >= 40000)
    {
        ssa = sip1;                             /* 2851 */
    }

/* APPARENT */
    ssb = sip1;                                 /* 2852 */


/* SUSPICIOUS */
    for (i = 0; i < sip2; ++i)
    {
        sia = sia - 10;
    }

    sca = sia;                                  /* 2853 */

/* POSSIBLE */
    sca = sip3;                                 /*      */
}



extern void f2 (int sip1, int sip2, int sip3)
{
    int sia = 128;
    int i;

/* CONSTANT */
    ssa = (signed short)40000;                  /* 2855 */

/* DEFINITE */
    if (sip1 >= 40000)
    {
        ssa = (signed short)sip1;               /* 2856 */
    }

/* APPARENT */
    ssb = (signed short)sip1;                   /* 2857 */

/* SUSPICIOUS */
    for (i = 0; i < sip2; ++i)
    {
        sia = sia - 10;
    }

    sca = (signed char)sia;                     /* 2858 */

/* POSSIBLE */
    sca = (signed char)sip3;                    /*      */
}

/******************************************************************************

CONVERSIONS WHICH ASSUME TWO'S COMPLEMENT REPRESENTATION
========================================================

Use of negative value which assumes two's complement representation
These messages are intended to identify situations where a negative integer value
is being generated in a type that can only represent the value if 2's
complement arithmetic is assumed.

OBSOLETE MESSAGES:

:0280  Use of constant negative value which assumes a two's complement representation of signed values.
:0281  Definite use of a negative value which assumes a two's complement representation of signed values.
:0282  Apparent use of a negative value which assumes a two's complement implementation of signed values.


NEW MESSAGES:

:2940  Constant: Result of type conversion is only representable in a two's complement implementation.
:2941  Definite: Result of implicit conversion is only representable in a two's complement implementation.
:2942  Apparent: Result of implicit conversion is only representable in a two's complement implementation.
:2943  Suspicious: Result of implicit conversion is only representable in a two's complement implementation.

:2946  Definite: Result of cast is only representable in a two's complement implementation.
:2947  Apparent: Result of cast is only representable in a two's complement implementation.
:2948  Suspicious: Result of cast is only representable in a two's complement implementation.

********************************************************************************************/

extern signed short ssa;
extern signed char  sca;
extern signed char  scb;

extern void f3 (int sip1, int sip2, int sip3)
{
    int sia = -128;
    int i;

/* CONSTANT */
    ssa = -32768;                               /* 2940 */

/* DEFINITE */
    if (sip1 == -128)
    {
        sca = sip1;                             /* 2941 */
    }

/* APPARENT */
    scb = sip1;                                 /* 2942 */

/* SUSPICIOUS */
    for (i = 0; i < sip2; ++i)
    {
        ++sia;
    }

    sca = sia;                                  /* 2943 */

/* POSSIBLE */
    sca = sip3;                                 /*      */
}


extern void f4 (int sip1, int sip2, int sip3)
{
    int sia = -128;
    int i;

/* CONSTANT */
    ssa = (signed short)-32768;                 /* 2945 */

/* DEFINITE */
    if (sip1 == -128)
    {
        sca = (signed char)sip1;                /* 2946 */
    }

/* APPARENT */
    scb = (signed char)sip1;                    /* 2947 */

/* SUSPICIOUS */
    for (i = 0; i < sip2; ++i)
    {
        ++sia;
    }

    sca = (signed char)sia;                     /* 2948 */

/* POSSIBLE */
    sca = (signed char)sip3;                    /*      */
}
