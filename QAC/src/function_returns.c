/*****************************************************************************

FUNCTION RETURN MESSAGES

******************************************************************************/
#pragma PRQA_MESSAGES_OFF 0506
#pragma PRQA_MESSAGES_OFF 0776
#pragma PRQA_MESSAGES_OFF 0777
#pragma PRQA_MESSAGES_OFF 1278
#pragma PRQA_MESSAGES_OFF 1290
#pragma PRQA_MESSAGES_OFF 1304
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2050
#pragma PRQA_MESSAGES_OFF 2205
#pragma PRQA_MESSAGES_OFF 2209
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2216
#pragma PRQA_MESSAGES_OFF 2814
#pragma PRQA_MESSAGES_OFF 2991
#pragma PRQA_MESSAGES_OFF 2995
#pragma PRQA_MESSAGES_OFF 3002
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3197
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3204
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3206
#pragma PRQA_MESSAGES_OFF 3210
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3344
#pragma PRQA_MESSAGES_OFF 3355
#pragma PRQA_MESSAGES_OFF 3358
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3604
#pragma PRQA_MESSAGES_OFF 4702


extern void function_dont_call(void);
extern int  noparenth(int x);


struct st
{
    int sa;
    int sb;
};



/********************************************************************************************
:1328  Tag type defined within a function declaration.
********************************************************************************************/

extern int fentag1(enum en { A, B, C } x);              /* 1328 */
extern int fentag2(struct tg {int a; int b;} s);        /* 1328 */


int foo(void)
{
    int r = 1;

/****************************************************************
:0428  Function identifier is not followed by () but a function call may be intended.
:3112  This statement has no side-effect - it can be removed.
:3635  Function identifier used as a pointer without a preceding & operator.
*****************************************************************/

    noparenth;                                          /* 0428 3635 3112 */

    &noparenth;                                         /* 0428      3112 */

    if ( noparenth ) { }                                /* 0428 3635      */

    if ( &noparenth ) { }                               /* 0428           */

    if (noparenth != 0) { }                             /* 0428 3635      */

    if (&noparenth != 0) { }                            /* 0428           */

/****************************************************************
:2010  The function '%s()' must not be called.
*****************************************************************/

    function_dont_call();                               /* 2010 */

    return(r);
}



/****************************************************************
:3670  Recursive call to function containing this call.
*****************************************************************/

extern unsigned int refact(unsigned int n)
{
    unsigned int ur;

    if (n == 0U)
    {
        ur = 1;
    }
    else
    {
        ur = n * refact( n - 1U );                      /* 3670 */
    }

    return(ur);
}


/****************************************************************
:3200  '%s' returns a value which is not being used.
:3208  '%s()' returns a value which is sometimes ignored.
:3209  '%s()' returns a value which is always ignored.
*****************************************************************/

extern int rvala(void);                                 /* 3208 */
extern int rvalb(void);                                 /* 3209 */

extern int retval(void)
{
    int r;

    rvala();                                            /* 3200 */
    rvalb();                                            /* 3200 */
    r = rvala() + 1;

    return r;
}

/****************************************************************
:3624  Function returns a struct/union by value.
*****************************************************************/
struct st retstruct(int a)
{                                                       /* 3624 */
    struct st stx = {0};

    stx.sa = a;
    stx.sb = a;
    return stx;
}


/******************************************************************************
:3225  Address of automatic object exported using a function parameter.
:4140  Address of automatic object exported in function return value.
******************************************************************************/
extern int * retunset( int **appsi )
{
    int r = 0;

    *appsi = &r;                                        /* 3225 */

    return &r;                                          /* 4140 */
}
