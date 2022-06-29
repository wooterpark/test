/********************************************************************************************

SIGNED INTEGER OVERFLOW
=======================

OBSOLETE MESSAGES:

:0278  [C] Overflow in signed arithmetic operation on constant operands.
:0296  [U] Definite overflow in signed arithmetic operation.
:0297  [U] Apparent overflow in signed arithmetic operation.


NEW MESSAGES:

:2800  Constant: Overflow in signed arithmetic operation.
:2801  Definite: Overflow in signed arithmetic operation.
:2802  Apparent: Overflow in signed arithmetic operation.
:2803  Suspicious: Overflow in signed arithmetic operation.

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 1277,1278,2000,2982,2983,2984,3103,3120,3121,3198,3199,3203,3227,3408,3447

extern void f1 (int sip1, int sip2, int n)
{
    int i;
    int sia;
    int six = 2000000000;

/* CONSTANT */
    sia =  2147483647 + 1;                      /* 2800 */
    sia = -2147483647 - 2;                      /* 2800 */

/* DEFINITE */
    if (sip1 >= 2147483640)
    {
        sia = sip1 + 8;                         /* 2801 */
        sia = sip1 * 2;                         /* 2801 */
    }

/* APPARENT */
    sia = sip1 + 8;                             /* 2802 */
    sia = sip1 * 2;                             /* 2802 */


/* SUSPICIOUS */
    for (i = 1; i < n; ++i)
    {
        six = six / 2;
    }

    sia = six + 1000000000;                     /* 2803 */

/* POSSIBLE */
    sia = sip2 + 1000000000;                    /*      */
}

/******************************************************************************

DIVISION BY ZERO
================

OBSOLETE MESSAGES:

:0586  [U] Division by constant zero.
:0587  [U] Definite division by zero.
:0585  [U] Apparent division by zero.
:0584  Possible division by zero.


NEW MESSAGES:

:2830  Constant: Division by zero.
:2831  Definite: Division by zero.
:2832  Apparent: Division by zero.
:2833  Suspicious: Division by zero.
:2834  Possible: Division by zero.

********************************************************************************************/

extern void f2(int sip1, int sip2, int sip3, int sip4, int n)
{
    int sia;
    int six = 0;
    int i;

/* CONSTANT */
    sia = sip1 / 0;                             /* 2830 */
    sia = sip1 % 0;                             /* 2830 */

/* DEFINITE */
    if (sip2 == 0)
    {
        sia = sip1 / sip2;                      /* 2831 */
        sia = sip1 % sip2;                      /* 2831 */
    }

/* APPARENT */
    sia = sip1 / sip2;                          /* 2832 */
    sia = sip1 % sip2;                          /* 2832 */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        ++six;
    }

    sia = sip3 / six;                           /* 2833 */
    sia = sip3 % six;                           /* 2833 */

/* POSSIBLE */
    sia = sip1 / sip4;                          /* 2834 */
    sia = sip1 % sip4;                          /* 2834 */

}


/********************************************************************************************

UNSIGNED INTEGER WRAPAROUND
===========================

OBSOLETE MESSAGES:

:3302  Wraparound past zero in unsigned subtraction of constant operands.
:3303  Wraparound past zero in unsigned addition of constant operands.
:3304  Wraparound past zero in unsigned multiplication of constant operands.
:3372  Definite wraparound past zero in an unsigned arithmetic operation.
:3382  Apparent wraparound past zero in an unsigned arithmetic operation.


NEW MESSAGES:

:2910  Constant: Wraparound in unsigned arithmetic operation.
:2911  Definite: Wraparound in unsigned arithmetic operation.
:2912  Apparent: Wraparound in unsigned arithmetic operation.
:2913  Suspicious: Wraparound in unsigned arithmetic operation.

********************************************************************************************/

extern void f3 (unsigned int uip1, unsigned int uip2, int n)
{
    int          i;
    unsigned int uia;
    unsigned int uix = 2000000000U;

/* CONSTANT */
    uia =  10U - 20U;                           /* 2910 */
    uia =  4000000000U + 4000000000U;           /* 2910 */
    uia =  2000000000U * 10U;                   /* 2910 */


/* DEFINITE */
    if (uip1 >= 2000000000U)
    {
        uia = uip1 * 10U;                       /* 2911 */
    }

/* APPARENT */
    uia = uip1 * 10U;                           /* 2912 */

/* SUSPICIOUS */
    for (i = 1; i < n; ++i)
    {
        uix = uix / 2U;
    }

    uia = uix * 10U;                            /* 2913 */

/* POSSIBLE */

    uia = uip2 * 10U;                           /*      */

}
