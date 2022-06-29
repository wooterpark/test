#pragma PRQA_MESSAGES_OFF 315,488,490,702,776,777,1253,1277,1290,1840,2000,2017,2211,2814,2980,2984,2983,3103,3112,3120,3132,3199,3203,3204,3210,3227,3408,3429,3436,3447,3453,3602,3625,3673,4601

/********************************************************************************************

POINTER ANALYSIS
================

NEW MESSAGES:

:2771  Definite: These pointers address different objects.
:2772  Apparent: These pointers address different objects.
:2773  Suspicious: These pointers address different objects.

:2776  Definite: Copy between overlapping objects.
:2777  Apparent: Copy between overlapping objects.
:2778  Suspicious: Copy between overlapping objects.


:2991  The value of this 'if' controlling expression is always 'true'.
:2995  The result of this logical operation is always 'true'.
:3355  The result of this logical operation is always 'true'.
:3358  The value of this 'if' controlling expression is always 'true'.

********************************************************************************************/

#include <string.h>
#include <stdlib.h>

extern int  buf1[10];
extern int  buf2[10];
extern char carr[10];


extern void f2771(void)
{
    int * p1;
    int * p2;
    long  d;

    p1 = buf1;
    p2 = buf2;
    d = p2 - p1;                                 /* 2771           */

    if (p2 > p1)                                 /* 2771 2991 2995 */
    {
    }
}

extern void f2772(int n)
{
    int * p1;
    int * p2;
    long  d;

    p1 = buf1;
    p2 = &buf1[5];

    if (n > 0)
    {
        p2 = buf2;
    }

    d = p2 - p1;                                 /* 2772           */

    if (p2 > p1)                                 /* 2772 2991 2995 */
    {
    }
}

extern void f2773(int n)
{
    int * p1;
    int * p2;
    long  d;
    int   i;

    p1 = buf1;
    p2 = buf2;

    for (i = 0; i < n; ++i)
    {
        p2 = &buf1[5];
    }

    d = p2 - p1;                                 /* 2773           */

    if (p2 > p1)                                 /* 2773 2991 2995 */
    {
    }
}

extern void f2776a(void)
{
    char * p1;
    char * p2;

    p1 = carr;
    p2 = &carr[3];

    (void)memcpy (p1, p2, 5);                    /* 2776           */
}

extern void f2776b(void)
{
    char * p1;
    char * p2;
    unsigned int  n = 5;

    p1 = carr;
    p2 = &carr[3];

    (void)memcpy (p1, p2, n);                    /* 2776           */
}

extern void f2777a(int p)
{
    int * p1;
    int * p2;

    p1 = buf1;
    p2 = &buf1[5];

    if (p > 0)
    {
        p2 = &buf1[3];
    }

    (void)memcpy(p1, p2, 5 * sizeof(int));       /* 2777           */
}

extern void f2777b(int p)
{
    int * p1;
    int * p2;
    unsigned int  n = 3;

    p1 = buf1;
    p2 = &buf1[3];

    if (p > 0)
    {
        n = 5;
    }

    (void)memcpy(p1, p2, n * sizeof(int));       /* 2777           */
}

extern void f2778a(int p)
{
    int * p1;
    int * p2;
    int i;

    p1 = buf1;
    p2 = &buf1[5];

    for (i = 0; i < p; ++i)
    {
        p2 = &buf1[3];
    }

    (void)memcpy(p1, p2, 5 * sizeof(int));       /* 2778           */
}

extern void f2778b(int p)
{
    int * p1;
    int * p2;
    int i;
    unsigned int  n = 3;

    p1 = buf1;
    p2 = &buf1[3];

    for (i = 0; i < p; ++i)
    {
        n = 5;
    }

    (void)memcpy(p1, p2, n * sizeof(int));       /* 2778           */
}

void fdynamic(void)
{
    int *p1;
    p1=(int*)malloc(10 * sizeof(int));

    if(p1 != NULL)
    {
        *(p1) = 1;                              /*      */
        *(p1+10) = 10;                          /* 2841 */
    }
}

/********************************************************************************************
 
POINTER ALIASING
================

********************************************************************************************/

void falias1 (int * p)
{
    *p = 0;
    1 / *p;                                     /* 2831 */
}


void falias2 (int * p1, int * p2)
{
    *p1 = 0;
    p2 = p1;                
    1 / *p2;                                    /* 2831 */
}

void falias_inter(void)
{
    int x=1;
    int y=1;
  
    falias2(&x, &y);
    1 / x;                                      /* 2831 */
    1 / y;                                      /*      */
}


