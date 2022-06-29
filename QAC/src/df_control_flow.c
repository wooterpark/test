
#pragma PRQA_MESSAGES_OFF 769,1253,1278,1862,2000,2001,2015,2017,2101,2200,2201,2212,2215,2467,2983,2992,2996,3103,3120,3139,3141,3196,3203,3205,3220,3227,3234,3323,3344,3408,3140,3447,3416,3442,3602,3605

/********************************************************************************************

LOOP ANALYSIS
=============


OBSOLETE MESSAGES:
:2465  This 'for' loop will only be executed once.


NEW MESSAGES:

:2870  Infinite loop construct with constant control expression.
:2871  Infinite loop identified.
:2872  This loop, if entered, will never terminate.
:2877  This loop will only be executed once.
:2990  The value of this loop controlling expression is always 'true'.

********************************************************************************************/

extern volatile int g;

/***********************
 CONSTANT LOOPS
***********************/

extern void f2870a(void)
{
    while (1)                                   /* 2740 2870 */
    {
        ;
    }
}

extern void f2870b(void)
{
    while (1)                                   /* 2740      */
    {
        if (g != 0)
            break;
    }
}

extern void f2870c(void)
{
    do                                          /*      2870 */
    {
    } while (1);                                /* 2740      */
}

extern void f2870d(void)
{
    do                                          /*           */
    {
        if (g != 0)
            break;
    } while (1);                                /* 2740      */
}

extern void f2870e(void)
{
    for (;1;)                                   /* 2740 2870 */
    {
    }
}

extern void f2870f(void)
{
    for (;1;)                                   /* 2740      */
    {
        if (g != 0)
            break;
    }
}


extern void f2870g(void)
{
    for (;;)                                    /*      2870 */
    {
    }
}

extern void f2870h(void)
{
    for (;;)                                    /*           */
    {
        if (g != 0)
            break;
    }
}


/***********************
 NON-CONSTANT LOOPS
***********************/

extern void f2871a(int n)
{
    while (n)                                   /*      2872 */
    {
        ;
    }
}

extern void f2871b(int n)
{
    if (n > 10)
    {
        while (n)                               /* 2990 2871 */
        {
        }
    }
}

extern void f2871c(int n)
{
    do                                          /*           */
    {
    } while (n);                                /*           */
}


extern void f2871d(int n)
{
    do                                          /*           */
    {
        if (g != 0)
            break;
    } while (n);                                /*           */
}


extern void f2871e(int n)
{
    for (;n;)                                   /*      2872 */
    {
    }
}

extern void f2871f(int n)
{
    for (;n;)                                   /*           */
    {
        if (g != 0)
            break;
    }
}

/***********************
 LOOPS EXECUTED ONCE
***********************/

extern void f2877(void)
{
    int i;

    for (i = 0; i < 1; ++i)                     /* 2877       */
    {
    }


    i = 10;

    while (i <= 10)                             /* 2877       */
    {
        ++i;
    }

}

/********************************************************************************************

UNREACHABLE CODE
================


OBSOLETE MESSAGES:

:0689  [u] 'Switch' statement will bypass the initialization of this local variable.
:0744  [U] '%s()' has been declared with a non void return type but ends with an implicit 'return ;' statement.
:2006  '%s()' has more than one 'return' path.
:2018  This 'switch' 'default' label is probably unreachable.
:3201  This statement is unreachable.
:1313  Executing 'goto %s' will cause local initialization to be skipped.
:3311  [u] An earlier jump to this statement will bypass the initialization of local variables.


NEW MESSAGES:

:2880  This statement is unreachable.
:2881  This 'switch' 'default' label is unreachable.
:2882  This 'switch' statement will bypass the initialization of local variables.
:2883  This goto statement will always bypass the initialization of local variables.
:2887  Function 'main' ends with an implicit return statement.
:2888  This function has been declared with a non void return type but ends with an implicit 'return ;' statement.
:2889  This function has more than one 'return' path.

********************************************************************************************/

extern void f2880(int n)
{
    if ((n < 5) && (n > 10))
    {                                           /*           */
        ;                                       /*      2880 */
    }
}

extern int f2881a(unsigned short uin, int r)
{
    if (uin < 3)
    {
        switch (uin)
        {
        case 0U:
            ++r;
            break;
        case 1U:
            --r;
            break;
        case 2U:
            r = r * 2;
            break;
        default:                                /*      2881 */
            r = r / 2;
            break;
        }
    }
    return r;
}

extern int f2882a(unsigned int uin, int r)
{
    switch (uin)                                /*      2882 */
    {
        int x = 10;                             /*           */
    case 0U:
        r = r + x;                              /*      2961 */
        break;
    case 1u:
        r = r - x;
        break;
    default:
        r = r * x;
        break;
    }
    return r;
}

extern void f2883a(int n)
{
    goto A;                                     /* 2883      */

    {                                           /*           */
        int c = 0;                              /*           */

A:      ++n;                                    /* 1313 3311 */
    }
}

extern void f2883b(int n)
{
    if (n > 10)
    {
        goto A;                                 /*           */
    }

    {                                           /*           */
        int c = 0;                              /*           */

A:      ++n;                                    /* 1313 3311 */
    }
}


extern void f2883c(int n)
{
    if (n > 10)
    {
        goto A;                                 /*           */
    }

    {                                           /*           */
        int c;                                  /*           */

        c = 0;

A:      ++n;                                    /*           */
    }
}


int main(void)                                  /* 2887      */
{
}                                               /*           */


extern int f2888a(void)                         /* 2888      */
{
}                                               /*           */



extern int f2889a(int n)                        /* 2889      */
{
    if (n > 10)
    {
        return 1;
    }

    return 0;
}                                               /*           */
