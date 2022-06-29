#pragma PRQA_MESSAGES_OFF 488,489,492,1277,1278,2000,2211,2824,2982,2983,3120,3132,3198,3199,3200,3203,3204,3227,3408,3447, 3625,3673
#include <stdlib.h>
#include <string.h>
/******************************************************************************

ARRAY BOUNDS VIOLATIONS
=======================

OBSOLETE MESSAGES:

:3680  [U] Access outside bounds of array using a constant array subscript.
:3685  [U] Definite access outside bounds of array.
:3689  [U] Apparent access outside bounds of array.


NEW MESSAGES:

:2840  Constant: Dereference of an invalid pointer value.
:2841  Definite: Dereference of an invalid pointer value.
:2842  Apparent: Dereference of an invalid pointer value.
:2843  Suspicious: Dereference of an invalid pointer value.

********************************************************************************************/

extern void f1(int sip1, int sip2, int n)
{
    int   buf[10];
    int   six = 10;
    int   i;

/* CONSTANT */
    buf[10] = 0;                                        /* 2840 */


/* DEFINITE */
    if (sip1 >= 10)
    {
        buf[sip1] = 0;                                  /* 2841 */
    }

/* APPARENT */
    buf[sip1] = 0;                                      /* 2842 */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        six = six - 1;
    }

    buf[six] = 0;                                       /* 2843 */

/* POSSIBLE */
    buf[sip2] = 0;                                      /*      */
}



/*****************************************************************************

COMPUTING AN INVALID POINTER VALUE
==================================

OBSOLETE MESSAGES:

:3680  [U] Access outside bounds of array using a constant array subscript.
:3685  [U] Definite access outside bounds of array.
:3689  [U] Apparent access outside bounds of array.

:3683  Use of constant address which points to one element beyond the end of the array.
:3688  Definite use of address which points to one element beyond the end of the array.
:3692  Apparent use of address which points to one element beyond the end of the array.

NEW MESSAGES:

:2930  Constant: Computing an invalid pointer value.
:2931  Definite: Computing an invalid pointer value.
:2932  Apparent: Computing an invalid pointer value.
:2933  Suspicious: Computing an invalid pointer value.

********************************************************************************************/


extern void f2(int sip1, int sip2, int n)
{
    int  buf[10];
    int  six = 11;
    int  i;
    int *pi;

/* CONSTANT */
    pi = &buf[11];                                      /* 2930 */


/* DEFINITE */
    if (sip1 >= 11)
    {
        pi = &buf[sip1];                                /* 2931 */
    }

/* APPARENT */
    pi = &buf[sip1];                                    /* 2932 */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        six = six - 1;
    }

    pi = &buf[six];                                     /* 2933 */

/* POSSIBLE */
    pi = &buf[sip2];                                    /*      */
}


extern void f3(int sip1, int sip2, int n)
{
    int  buf[10];
    int  six = 10;
    int  i;
    int *pi;

/* CONSTANT */
    pi = &buf[10];                                      /*      */


/* DEFINITE */
    if (sip1 == 10)
    {
        pi = &buf[sip1];                                /*      */
    }

/* APPARENT */
    pi = &buf[sip1];                                    /*      */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        six = six - 1;
    }

    pi = &buf[six];                                     /*      */

/* POSSIBLE */
    pi = &buf[sip2];                                    /*      */
}



/********************************************************************************************

USING A NEGATIVE ARRAY SUBSCRIPT
================================

OBSOLETE MESSAGES:

:3681  Use of a constant negative value in array subscript operation or pointer arithmetic.
:3686  Definite use of a negative value in array subscript operation or pointer arithmetic.
:3690  Apparent use of a negative value in array subscript operation or pointer arithmetic.

:3680  [U] Access outside bounds of array using a constant array subscript.
:3685  [U] Definite access outside bounds of array.
:3689  [U] Apparent access outside bounds of array.


NEW MESSAGES:

:2950  Constant: Negative value used in array subscript or pointer arithmetic operation.
:2951  Definite: Negative value used in array subscript or pointer arithmetic operation.
:2952  Apparent: Negative value used in array subscript or pointer arithmetic operation.
:2953  Suspicious: Negative value used in array subscript or pointer arithmetic operation.

:2840  Constant: Dereference of an invalid pointer value.
:2841  Definite: Dereference of an invalid pointer value.
:2842  Apparent: Dereference of an invalid pointer value.
:2843  Suspicious: Dereference of an invalid pointer value.

:2930  Constant: Computing an invalid pointer value.
:2931  Definite: Computing an invalid pointer value.
:2932  Apparent: Computing an invalid pointer value.
:2933  Suspicious: Computing an invalid pointer value.

2846 Definite: Maximum number of characters to be written is larger than the target buffer size.

********************************************************************************************/

extern int gab[100];

extern void f4(int buf[], int *ppp,int sip1, int sip2, int n)
{
    int  six = -1;
    int  i;
    int *pi;
    int *pj;

/* CONSTANT */
    pi = &gab[-5];                                      /* 2930 */
    pi = gab - 5;                                       /* 2930 */
    i  = gab[-5];                                       /* 2840 */
    pi = &gab[50];                                      /*      */
    pj = pi + 5;                                        /*      */
    pj = pi - 5;                                        /*      */
    pj = pi + (-5);                                     /*      */
    pj = pi - (-5);                                     /*      */

    pi = &buf[-5];                                      /* 2950 */
    pi = buf - 5;                                       /*      */
    pi = buf + (-5);                                    /* 2950 */
    i  = buf[-5];                                       /* 2950 */

    pi = &ppp[-5];                                      /* 2950 */
    pi = ppp - 5;                                       /*      */
    pi = ppp + (-5);                                    /* 2950 */
    pi = ppp - (-5);                                    /* 2950 */
    i  = *(ppp - 5);                                    /*      */
    i  = *(ppp + (-5));                                 /* 2950 */
    i  = *(ppp - (-5));                                 /* 2950 */
    --ppp;                                              /*      */


/* DEFINITE */
    if (sip1 < 0)
    {
        pi = &gab[sip1];                                /* 2931 */
        pi = gab + sip1;                                /* 2931 */
        i  = gab[sip1];                                 /* 2841 */

        pi = &buf[sip1];                                /* 2951 */
        pi = buf + sip1;                                /* 2951 */
        pi = buf - sip1;                                /* 2951 */
        i  = buf[sip1];                                 /* 2951 */

        pi = &ppp[sip1];                                /* 2951 */
        pi = ppp + sip1;                                /* 2951 */
        pi = ppp - sip1;                                /* 2951 */
        i  = *(ppp + sip1);                             /* 2951 */
        i  = *(ppp - sip1);                             /* 2951 */
    }

/* APPARENT */
    pi = &gab[sip1];                                    /* 2932 */
    pi = gab + sip1;                                    /* 2932 */
    i  = gab[sip1];                                     /* 2842 */

    pi = &buf[sip1];                                    /* 2952 */
    pi = buf + sip1;                                    /* 2952 */
    pi = buf - sip1;                                    /* 2952 */
    i  = buf[sip1];                                     /* 2952 */

    pi = &ppp[sip1];                                    /* 2952 */
    pi = ppp + sip1;                                    /* 2952 */
    pi = ppp - sip1;                                    /* 2952 */
    i  = *(ppp + sip1);                                 /* 2952 */
    i  = *(ppp - sip1);                                 /* 2952 */



/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        six++;
    }

    pi = &gab[six];                                     /* 2933 */
    pi = gab + six;                                     /* 2933 */
    i  = gab[six];                                      /* 2843 */

    pi = &buf[six];                                     /* 2953 */
    pi = buf + six;                                     /* 2953 */
    pi = buf - six;                                     /* 2953 */
    i  = buf[six];                                      /* 2953 */

    pi = &ppp[six];                                     /* 2953 */
    pi = ppp + six;                                     /* 2953 */
    pi = ppp - six;                                     /* 2953 */
    i  = *(ppp + six);                                  /* 2953 */
    i  = *(ppp - six);                                  /* 2953 */


/* POSSIBLE */
    pi = &gab[sip2];                                    /*      */
    pi = gab + sip2;                                    /*      */
    i  = gab[sip2];                                     /*      */

    pi = &buf[sip2];                                    /*      */
    pi = buf + sip2;                                    /*      */
    pi = buf - sip2;                                    /*      */
    i  = buf[sip2];                                     /*      */

    pi = &ppp[sip2];                                    /*      */
    pi = ppp + sip2;                                    /*      */
    pi = ppp - sip2;                                    /*      */
    i  = *(ppp + sip2);                                 /*      */
    i  = *(ppp - sip2);                                 /*      */
}

#pragma PRQA_MESSAGES_OFF 2814
void f5 (char * src)
{
    char dst[10];
    size_t size = 20U;
  
    strncpy (dst, src, size);                           /* 2846 */
}

void f6 (void)
{
    char dst[10];
    const char *src="test";
    size_t size = 20U;          
  
    strncpy (dst, src, size);                           /* 2846 */
}

