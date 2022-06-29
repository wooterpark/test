#pragma PRQA_MESSAGES_OFF 2000,2017,2467,2983,3120,3139,3140,3141,3199,3203,3204,3227,3344,3355,3357,3408,3492,4403,4539

/********************************************************************************************

INVARIANT CONSTANT OPERATIONS
=============================


OBSOLETE MESSAGES:


:3323  This controlling expression has a constant 'true' value.
:3346  The controlling expression in this 'if' statement has a constant 'true' value.
:3329  This 'if' controlling expression has a constant 'false' value.
:3361  Using a 'do-while-zero' construct. The loop will only be executed once.
:3325  This 'while' or 'for' loop controlling expression has a constant 'false' value.


NEW MESSAGES:

:2740  This loop controlling expression is a constant expression and its value is 'true'.
:2741  This 'if' controlling expression is a constant expression and its value is 'true'.
:2742  This 'if' controlling expression is a constant expression and its value is 'false'.
:2743  This 'do - while' loop controlling expression is a constant expression and its value is 'false'. The loop will only be executed once.
:2744  This 'while' or 'for' loop controlling expression is a constant expression and and its value is 'false'. The loop will not be entered.

TBD:
:2745  This logical operation is a constant expression and the result is 'true'.
:2746  This logical operation is a constant expression and the result is 'false'.
:2747  The first operand of this conditional operation is a constant expression and its value is 'true'.
:2748  The first operand of this conditional operation is a constant expression and its value is 'false'.

:2870  Infinite loop construct with constant control expression.

********************************************************************************************/


extern void f2740a (void)
{
    while (1)                           /* 2740 2870 */
    {
    }
}

extern void f2740b(void)
{
    do                                  /*      2870 */
    {
    } while (1);                        /* 2740      */
}

extern void f2740c(void)
{
    for (;1;)                           /* 2740 2870 */
    {
    }
}

extern void f2740d(void)
{
    for (;;)                            /*      2870 */
    {
    }
}

extern void f2741a(void)
{
    if (1)                              /* 2741      */
    {
    }
}

extern void f2742a(void)
{
    if (0)                              /* 2742      */
    {                                   /*           */
        ;                               /* 2880      */
    }
}

extern void f2743a(void)
{
    do
    {
    } while(0);                         /* 2743      */
}

extern void f2744a(void)
{
    while (0)                           /* 2744      */
    {                                   /*           */
        ;                               /* 2880      */
    }
}

extern void f2744b(void)
{
    for (;0;)                           /* 2744      */
    {                                   /*           */
        ;                               /* 2880      */
    }
}

extern void f2745a(void)
{
    int r;

    r = 1 < 2;                          /*           */
}

extern void f2746a(void)
{
    int r;

    r = 1 > 2;                          /*           */
}

extern void f2747a(int a, int b)
{
    int r;

    r = (1 < 2) ? a : b;                /*           */
}

extern void f2748a(int a, int b)
{
    int r;

    r = (1 > 2) ? a : b;                /*           */
}

/********************************************************************************************

INVARIANT NON-CONSTANT OPERATIONS
=================================


OBSOLETE MESSAGES:

:3357  The value of this loop controlling expression is always 'true'.
:3358  The value of this 'if' controlling expression is always 'true'.
:3359  The value of this controlling expression is always 'false'.
:3360  The value of this 'do - while' controlling expression is always 'false'. The loop will only be executed once.
:3355  The result of this logical operation is always 'true'.
:3356  The result of this logical operation is always 'false'.



NEW MESSAGES:

:2990  The value of this loop controlling expression is always 'true'.
:2991  The value of this 'if' controlling expression is always 'true'.
:2992  The value of this 'if' controlling expression is always 'false'.
:2993  The value of this 'do - while' loop controlling expression is always 'false'. The loop will only be executed once.
:2994  The value of this 'while' or 'for' loop controlling expression is always 'false'. The loop will not be entered.
:2995  The result of this logical operation is always 'true'.
:2996  The result of this logical operation is always 'false'.

TBD:
:2997  The value of the first operand of this conditional operation is always 'true'.
:2998  The value of the first operand of this conditional operation is always 'false'.


********************************************************************************************/

extern void f2990a (void)
{
    int n = 1;

    while (n)                           /* 2990 2871 */
    {
    }
}

extern void f2990b(void)
{
    int n = 1;

    do                                  /*      2871 */
    {
    } while (n);                        /* 2990      */
}

extern void f2990c(void)
{
    int n = 1;

    for (;n;)                           /* 2990 2871 */
    {
    }
}

extern void f2991a(void)
{
    int n = 1;

    if (n)                              /* 2991      */
    {
    }
}

extern void f2992a(void)
{
    int n = 0;

    if (n)                              /* 2992      */
    {                                   /*           */
        ;                               /* 2880      */
    }
}

extern void f2993a(void)
{
    int n = 0;

    do
    {
    } while(n);                         /* 2993      */
}

extern void f2994a(void)
{
    int n = 0;

    while (n)                           /* 2994      */
    {                                   /*           */
        ;                               /* 2880      */
    }
}

extern void f2994b(void)
{
    int n = 0;

    for (;n;)                           /* 2994      */
    {                                   /*           */
        ;                               /* 2880      */
    }
}

extern void f2995a(void)
{
    int a = 10;
    int b = 20;
    int r;

    r = a < b;                          /* 2995      */
}

extern void f2996a(void)
{
    int a = 10;
    int b = 20;
    int r;

    r = a > b;                          /* 2996      */
}

extern void f2997a(int a, int b)
{
    int n = 1;
    int r;

    r = n ? a : b;                      /*           */
}

extern void f2998a(int a, int b)
{
    int n = 0;
    int r;

    r = n ? a : b;                      /*           */
}

