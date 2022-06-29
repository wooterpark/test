#pragma PRQA_MESSAGES_OFF 306,488,489,1278,2000,2017,2982,2983,3120,3132,3198,3199,3203,3227,3408,3673,4600

/********************************************************************************************

DEREFERENCE OF NULL POINTER
===========================

OBSOLETE MESSAGES:

:0503  [U] Dereference of constant NULL pointer.
:0504  [U] Definite dereference of NULL pointer.
:0505  [U] Apparent dereference of NULL pointer.
:0506  Possible dereference of NULL pointer.


NEW MESSAGES:

:2810  Constant: Dereference of NULL pointer.
:2811  Definite: Dereference of NULL pointer.
:2812  Apparent: Dereference of NULL pointer.
:2813  Suspicious: Dereference of NULL pointer.
:2814  Possible: Dereference of NULL pointer.

********************************************************************************************/

#define NULL (void *)0

extern void f1(int *p1, int *p2, int sip1, int n)
{
    int  sia;
    int *pi = NULL;
    int  m = 0;
    int  i;

/* CONSTANT */
    sia = *(int *)(NULL);                               /* 2810 */


/* DEFINITE */
    if (p1 == NULL)
    {
        sia = *p1;                                      /* 2811 */
    }

/* APPARENT */
    sia = *p1;                                          /* 2812 */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        pi = &sip1;
        m = m + i;
    }

    sia = *pi;                                          /* 2813 */
    sia = *(int *)m;                                    /* 2813 */

/* POSSIBLE */
    sia = *p2;                                          /* 2814 */
}



/********************************************************************************************

ARITHMETIC OPERATION ON NULL POINTER
====================================

OBSOLETE MESSAGES:

:0507  [u] Arithmetic operation on constant NULL pointer.
:0508  [u] Definite arithmetic operation on NULL pointer.
:0509  [u] Apparent arithmetic operation on NULL pointer.
:0510  Possible arithmetic operation on NULL pointer.


NEW MESSAGES:

:2820  Constant: Arithmetic operation on NULL pointer.
:2821  Definite: Arithmetic operation on NULL pointer.
:2822  Apparent: Arithmetic operation on NULL pointer.
:2823  Suspicious: Arithmetic operation on NULL pointer.
:2824  Possible: Arithmetic operation on NULL pointer.

********************************************************************************************/

extern void f2(int *p1, int *p2, int n)
{
    int *pi = NULL;
    int  buf[10];
    int *p;
    int  i;

/* CONSTANT */
    p = (int *)NULL + 5U;                               /* 2820 */


/* DEFINITE */
    if (p1 == NULL)
    {
        p = p1 + 5U;                                    /* 2821 */
    }

/* APPARENT */
    p = p1 + 5U;                                        /* 2822 */


/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        pi = &buf[2];
    }

    ++pi;                                               /* 2823 */

/* POSSIBLE */
    ++p2;                                               /* 2824 */
}
