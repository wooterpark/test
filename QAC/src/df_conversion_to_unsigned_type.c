
#pragma PRQA_MESSAGES_OFF 1257,1278,1290,2000,2017,2982,2983,3120,3198,3199,3203,3227,3306,3408,3602

/********************************************************************************************

CONVERSION OF A NEGATIVE VALUE TO AN UNSIGNED TYPE
==================================================

OBSOLETE MESSAGES:

:0277  Conversion of a constant negative value to an unsigned type.
:0290  Definite conversion of a negative value to an unsigned type.
:0291  Apparent conversion of a negative value to an unsigned type.


NEW MESSAGES:

:2890  Constant: Negative value converted to an unsigned type.

:2891  Definite: Negative value implicitly converted to an unsigned type.
:2892  Apparent: Negative value implicitly converted to an unsigned type.
:2893  Suspicious: Negative value implicitly converted to an unsigned type.

:2896  Definite: Negative value cast to an unsigned type.
:2897  Apparent: Negative value cast to an unsigned type.
:2898  Suspicious: Negative value cast to an unsigned type.

:4434 A non-constant expression of 'essentially signed' type is being converted to unsigned type, on assignment.
:4436 A constant expression of 'essentially signed' type is being converted to unsigned type, on assignment.

********************************************************************************************/

extern void f1(signed int sip1, int sip2, int n)
{
    unsigned int uia;
    signed int   sia = -10;
    signed int   i;

/* CONSTANT */
    uia = (-1);                                               /* 2890 4436 */

/* DEFINITE */
    if (sip1 < 0)
    {
        uia = sip1;                                           /* 2891 3760 4434 */
    }

/* APPARENT */
    uia = sip1;                                               /* 2892 3760 4434 */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        sia = sia + 20;
    }

    uia = sia;                                                /* 2893 3760 4434 */

/* POSSIBLE */

    uia = sip2;                                               /*      3760 4434 */
}


extern void f2(signed int sip1, int sip2, int n)
{
    unsigned int uia;
    signed int   sia = -10;
    signed int   i;

/* CONSTANT */
    uia = (unsigned int )(-1);                                /* 2895      */

/* DEFINITE */
    if (sip1 < 0)
    {
        uia = (unsigned int )sip1;                            /* 2896      */
    }

/* APPARENT */
    uia = (unsigned int )sip1;                                /* 2897      */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        sia = sia + 20;
    }

    uia = (unsigned int)sia;                                  /* 2898      */

/* POSSIBLE */

    uia = (unsigned int)sip2;                                 /*           */

}

/********************************************************************************************

CONVERSION OF A POSITIVE VALUE TO AN UNSIGNED TYPE
==================================================

OBSOLETE MESSAGES:

:3306  Truncation of positive constant integer value during implicit conversion to a smaller unsigned type.
:3296  Definite truncation of positive integer value during implicit conversion to a smaller unsigned type.
:3297  Apparent truncation of positive integer value during implicit conversion to a smaller unsigned type.


NEW MESSAGES:

:2900  Constant: Positive integer value truncated by implicit conversion to a smaller unsigned type.

:2901  Definite: Positive integer value truncated by implicit conversion to a smaller unsigned type.
:2902  Apparent: Positive integer value truncated by implicit conversion to a smaller unsigned type.
:2903  Suspicious: Positive integer value truncated by implicit conversion to a smaller unsigned type.

:2906  Definite: Positive integer value truncated by cast to a smaller unsigned type.
:2907  Apparent: Positive integer value truncated by cast to a smaller unsigned type.
:2908  Suspicious: Positive integer value truncated by cast to a smaller unsigned type.

:4461 A non-constant expression of 'essentially unsigned' type is being converted to narrower unsigned type, on assignment.
********************************************************************************************/

extern void f3 (unsigned int uip1, unsigned int uip2, int n)
{
    unsigned int   uia = 70000;
    unsigned short usr;
    int            i;

/* CONSTANT */
    usr = 65536U;                                             /* 2900      */

/* DEFINITE */
    if (uip1 >= 65536U)
    {
        usr = uip1;                                           /* 2901 3770 4461 */
    }

/* APPARENT */
    usr = uip1;                                               /* 2902 3770 4461 */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        uia = uia - 10000U;
    }

    usr = uia;                                                /* 2903 3770 4461 */

/* POSSIBLE */
    usr = uip2;                                               /*      3770 4461 */

}

extern void f4 (unsigned int uip1, unsigned int uip2, int n)
{
    unsigned int   uia = 70000;
    unsigned short usr;
    int            i;

/* CONSTANT */
    usr = (unsigned short)65536U;                             /* 2905      */

/* DEFINITE */
    if (uip1 >= 65536U)
    {
        usr = (unsigned short)uip1;                           /* 2906      */
    }

/* APPARENT */
    usr = (unsigned short)uip1;                               /* 2907      */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        uia = uia - 10000U;
    }

    usr = (unsigned short)uia;                                /* 2908      */

/* POSSIBLE */
    usr = (unsigned short)uip2;                               /*           */

}
