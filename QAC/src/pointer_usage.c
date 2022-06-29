/********************************************************************************************

POINTER USAGE

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0306
#pragma PRQA_MESSAGES_OFF 0506
#pragma PRQA_MESSAGES_OFF 1336
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2771
#pragma PRQA_MESSAGES_OFF 2814
#pragma PRQA_MESSAGES_OFF 2880
#pragma PRQA_MESSAGES_OFF 2881
#pragma PRQA_MESSAGES_OFF 2981
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 2991
#pragma PRQA_MESSAGES_OFF 2992
#pragma PRQA_MESSAGES_OFF 2995
#pragma PRQA_MESSAGES_OFF 2996
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3132
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3201
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3204
#pragma PRQA_MESSAGES_OFF 3218
#pragma PRQA_MESSAGES_OFF 3223
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3229
#pragma PRQA_MESSAGES_OFF 3355
#pragma PRQA_MESSAGES_OFF 3356
#pragma PRQA_MESSAGES_OFF 3359
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3410
#pragma PRQA_MESSAGES_OFF 3429
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3453
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 3673
#pragma PRQA_MESSAGES_OFF 4600


extern void foo(int *p);
extern int  buf1[100];
extern int  buf2[100];

extern void ptrconv1 (void)
{
    int     n;
    int    *psia = buf1;
    int    *psib = &buf2[30];
    int   * const *ppsia = &psia;
    int   * const *ppsib = &psib;

/******************************************************************************
:3672  Using non-const pointer to function.
*****************************************************************************/
    void (* pfna)( int * p) = &foo;        /* 3672 */


/******************************************************************************
:3671  Function called via pointer to function.
******************************************************************************/
    pfna(psia);                            /* 3671 */


/******************************************************************************
:0488  Performing pointer arithmetic.
:0489  The integer value 1 is being added or subtracted from a pointer.
******************************************************************************/

    psia = psia + 2;                       /* 0488 */
    n = psia - psib;                       /* 0488 */
    ++psia;                                /* 0489 */


/******************************************************************************
:0490  Relational operator used to compare two pointers.
******************************************************************************/


    if (psia > psib) { n = 1; }            /* 0490 */
    if (*ppsia > *ppsib) {n = 2;}          /* 0490 */


    return;
}


/******************************************************************************
:3216  Address of local static object exported to a pointer with linkage or wider scope.
:3217  Address of automatic object exported to a pointer with linkage or wider scope.
:3230  Address of automatic object assigned to local pointer with static storage duration.
:3225  Address of automatic object exported using a function parameter.
:4140  Address of automatic object exported in function return value.
******************************************************************************/

extern int          *gpsi;
static int          *fpsi = buf1;

int * foo1 ( int ** appsi )
{
    int         r = 0;
    static int  sti;
    static int *spsi;

    fpsi   = &sti;                         /* 3216 */
    gpsi   = &r;                           /* 3217 */
    spsi   = &r;                           /* 3230 */
    *appsi = &r;                           /* 3225 */

    return &r;                             /* 4140 */
}

/******************************************************************************
:3004 This integral constant expression is being interpreted as a NULL pointer constant.
******************************************************************************/

#define NULL (void *)0

void foo2 (void *);

void foo3 (void)
{
    char *p = NULL;                          /*      */
    p = 0;                                   /* 3004 */

    if (p == 0)                              /* 3004 */
    {
    }

    if (0 != p)                              /* 3004 */
    {
    }

    if (p == NULL)                           /*      */
    {
    }

    foo2 (0);                                /* 3004 */
}

