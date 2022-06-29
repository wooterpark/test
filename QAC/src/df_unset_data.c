#pragma PRQA_MESSAGES_OFF 2000,2017,2982,2983,3120,3196,3198,3199,3203,3204,3226,3227,3408,3440,3446,3447,3602

/********************************************************************************************

ACCESSING UNSET DATA
====================

OBSOLETE MESSAGES:

:3321  [U] The variable '%s' is definitely unset at this point.
:3347  [U] The variable '%s' is apparently unset at this point.
:3353  The variable '%s' is possibly unset at this point.

NEW MESSAGES:

:2961  Definite: Using value of uninitialized automatic object '%s'.
:2962  Apparent: Using value of uninitialized automatic object '%s'.
:2964  Possible:   Using value of uninitialized automatic object.

********************************************************************************************/



extern void f1(int n)
{
    int  six;
    int  siy;
    int  siz;
    int  sia;
    int  sib;
    int  sic;
    int  i;
    int  j;

/* CONSTANT */



/* DEFINITE */
    if (n > 0)
    {
        sia = six;                                      /* 2961 */
        siy = 1;
    }

/* APPARENT */
    sib = siy;                                          /* 2962 */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        siz = 1;
    }

    sic = siz;                                          /* 2963 */

    for (i = 0; i < 10 ; ++i )
    {
        if (i == 5)
        {
            sia = j;                                    /*      */
        }
        else
        {
            j = 0;
        }
    }

    return;
}



/********************************************************************************************

ACCESSING UNSET DATA
====================

OBSOLETE MESSAGES:

:3348  Definite use of unset pointer as an argument to a function which expects a read-only pointer.
:3349  Apparent use of unset pointer as an argument to a function which expects a read-only pointer.
:3354  Possible use of unset pointer as an argument to a function which expects a read-only pointer.


NEW MESSAGES:

:2971  Definite: Passing address of uninitialized object '%s' to a function parameter declared as a pointer to const.
:2972  Apparent: Passing address of uninitialized object '%s' to a function parameter declared as a pointer to const.
:2974  Possible: Passing address of uninitialized object to a function parameter declared as a pointer to const.

********************************************************************************************/

extern void func(const int * p);

extern void f2(int n)
{
    int  siw;
    int  six;
    int  siy;
    int  siz;
    int  i;

/* CONSTANT */



/* DEFINITE */
    if (n > 0)
    {
        func(&six);                                     /* 2971 */
        siy = 1;
    }

/* APPARENT */
    func(&siy);                                         /* 2972 */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        siz = 1;
    }

    func(&siz);                                         /* 2973 */

    for (i = 0; i < 10 ; ++i )
    {
        if (i == 5)
        {
            func(&siw);                                 /*      */
        }
        else
        {
            siw=0;
        }
    }

    return;
}
