/********************************************************************************************

GOTO and LABELS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2212
#pragma PRQA_MESSAGES_OFF 2214
#pragma PRQA_MESSAGES_OFF 2752
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3220
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3347
#pragma PRQA_MESSAGES_OFF 3408

/****************************************************************************************
:2001  A 'goto' statement has been used.
:2015  A statement 'label' has been used.
:3202  The label '%s:' is not used in this function and could be removed.
:0706  [U] Label '%s' is not unique within this function.
****************************************************************************************/
extern void f1(int n)
{
    int i;

    START:                               /* 2015 3202      */
    for (i = 0; i < 10; ++i)
    {
        if (i > n)
        {
            goto RET;                    /* 2001           */
        }
    }

    RET:  ++i;                           /* 2015           */

    ALAB: ++i;                           /* 2015           */
    ALAB: ++i;                           /*      3202 0706 */

    return;
}


extern void f2(int n, int m)
{
    int i;

    BLAB: ++n;                           /* 2015           */

    for (i = 0; i < n; ++i)
    {
        if (i > m)
        {
            goto BLAB;                   /* 2001           */
        }
    }
}

/********************************************************************************************
:2001  A 'goto' statement has been used.
:2015  A statement 'label' has been used.
:1313  Executing 'goto %s' will cause local initialization to be skipped.
:3311  [u] An earlier jump to this statement will bypass the initialization of local variables.
********************************************************************************************/

extern int f3(int n)
{
    int i = 0;
    int r = 0;

    if (n > 10)
    {
        goto B1;                         /* 2001           */
    }

    for (i = 0; i < n; ++i)
    {
        int x = n;

        B1: --x;                         /* 2015 1313 3311 */
        r = x;
    }

    return r;
}


/********************************************************************************************
:2001  A 'goto' statement has been used.
:2015  A statement 'label' has been used.
:1313  Executing 'goto %s' will cause local initialization to be skipped.
:3312  [u] This goto statement will jump into a previous block and bypass the initialization of local variables.
********************************************************************************************/

extern void f4(int y, int z )
{
    if (y > 0)
    {
        int w = 2;

        if (z > 0)
        {
            LAB2:                       /* 2015           */
            ++y;
        }

    }
    if (z > 0)
        goto LAB2;                      /* 2001 1313 3312 */

    return;

}
