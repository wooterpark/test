/********************************************************************************************

VARIABLE SCOPE

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0506
#pragma PRQA_MESSAGES_OFF 2006
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 2212
#pragma PRQA_MESSAGES_OFF 2814
#pragma PRQA_MESSAGES_OFF 2889
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 2986
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3218
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3220
#pragma PRQA_MESSAGES_OFF 3222
#pragma PRQA_MESSAGES_OFF 3223
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3229
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3450
#pragma PRQA_MESSAGES_OFF 3602


extern int *esp;

static int *ssp;

extern int* getptr(const int n, int **appsi, int **appli)
{
    extern int *lep;
    static int *lsp;
    int        *lap;
    static int  lsx = 0;
    int         lax = 0;


/************************************************************************
:3216  Address of local static object exported to a pointer with linkage or wider scope.
:3217  Address of automatic object exported to a pointer with linkage or wider scope.
:3230  Address of automatic object assigned to local pointer with static storage duration.
************************************************************************/

    esp = &lsx;                    /* 3216 */
    esp = &lax;                    /* 3217 */

    ssp = &lsx;                    /* 3216 */
    ssp = &lax;                    /* 3217 */

    lep = &lsx;                    /* 3216 */
    lep = &lax;                    /* 3217 */

    lsp = &lsx;                    /*      */
    lsp = &lax;                    /* 3230 */

    lap = &lsx;                    /*      */
    lap = &lax;                    /*      */

    if (n > 0)
    {
        extern int *nep;
        static int *nsp;
        int        *nap;
        static int  nsx = 1;
        int         nax = 1;

        esp = &nsx;                /* 3216 */
        esp = &nax;                /* 3217 */

        ssp = &nsx;                /* 3216 */
        ssp = &nax;                /* 3217 */

        lep = &nsx;                /* 3216 */
        lep = &nax;                /* 3217 */

        lsp = &nsx;                /* 3216 */
        lsp = &nax;                /* 3217 */

        lap = &nsx;                /* 3216 */
        lap = &nax;                /* 3217 */

        nep = &nsx;                /* 3216 */
        nep = &nax;                /* 3217 */

        nsp = &nsx;                /*      */
        nsp = &nax;                /* 3230 */

        nap = &nsx;                /*      */
        nap = &nax;                /*      */
    }


/************************************************************************
:3231  Address of local static object exported using a function parameter.
:3225  Address of automatic object exported using a function parameter.
************************************************************************/
    *appsi = &lsx;                 /* 3231 */

    *appli = &lax;                 /* 3225 */


/************************************************************************
:4139  Address of local static object exported in function return value.
:4140  Address of automatic object exported in function return value.
************************************************************************/
    if (n == 0)
        return &lsx;               /* 4139 */
    else
        return &lax;               /* 4140 */
}
