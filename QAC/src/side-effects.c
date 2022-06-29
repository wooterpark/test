/********************************************************************************************

SIDE-EFFECTS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0506
#pragma PRQA_MESSAGES_OFF 0510
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2100
#pragma PRQA_MESSAGES_OFF 2205
#pragma PRQA_MESSAGES_OFF 2209
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2462
#pragma PRQA_MESSAGES_OFF 2814
#pragma PRQA_MESSAGES_OFF 2824
#pragma PRQA_MESSAGES_OFF 2981
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 2986
#pragma PRQA_MESSAGES_OFF 3103
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3132
#pragma PRQA_MESSAGES_OFF 3197
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3218
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3417
#pragma PRQA_MESSAGES_OFF 3418
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3492
#pragma PRQA_MESSAGES_OFF 3495
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 3672
#pragma PRQA_MESSAGES_OFF 3684
#pragma PRQA_MESSAGES_OFF 4397
#pragma PRQA_MESSAGES_OFF 4403
#pragma PRQA_MESSAGES_OFF 4544
#pragma PRQA_MESSAGES_OFF 4571



extern int fi(int n);

extern volatile unsigned char *port1;
extern volatile unsigned char *port2;
extern volatile unsigned char vp1;
extern volatile unsigned char vp2;
extern          unsigned char buf[10];


extern void sideeffects(char s[], int n, int m)
{
    int           i = 0;
    int           j = 0;
    int           r;
    unsigned char z;

/*******************************************************************************
:3226  The result of an assignment is being used in an arithmetic operation or another assigning operation.
*******************************************************************************/
    i = j = 1;                          /* 3226 */
    i = (j = fi(n));                    /* 3226 */


/*******************************************************************************
:3440  Using the value resulting from a ++ or -- operation.
*******************************************************************************/
    i = j++;                            /* 3440 */

#pragma PRQA_MESSAGES_OFF 3440

/*******************************************************************************
:3441  Function call argument is an expression with possible side effects.
*******************************************************************************/
    i = fi(j++);                        /* 3441 */



/*******************************************************************************
:3110  The left-hand operand of this ',' has no side effects.
:3426  Right hand side of comma expression has no side effect and its value is not used.
*******************************************************************************/
    j = (i, i + 1);                     /* 3110 */
    i + 1, j = 1;                       /* 3110 */
    for (i, j=1; i < n; i++, j++)       /* 3110 */
    {
        s[i] = s[j];
    }
    j = (i = 0, i + 1);                 /* 3226 */
    i = 1, j + 1;                       /* 3426 */
    n = (i = 1, j + 1);                 /* 3226 */
    j = i + 1, i = 0;


/*******************************************************************************
:3112  This statement has no side-effect - it can be removed.
*******************************************************************************/
    i;                                  /* 3112 */
    (j + 1) / n;                        /* 3112 */
    i == m;                             /* 3112 */


/*******************************************************************************
:3415  Right hand operand of '&&' or '||' is an expression with possible side effects.
:3416  Logical operation performed on expression with possible side effects.
:3326  The result of an assignment is being used in a logical operation.
:3427  Right hand side of logical operator has no side effect and its value is not used.
*******************************************************************************/
    r = (fi(n) != 0);                   /* 3416 */
    r = (i++ == m);                     /* 3416 */
    r = (m++ != 0);                     /* 3416 */
    r = ((m++ != i) && (m > j));        /* 3416 */
    if ((i = fi(n)) != 0) { ++r; }      /* 3416 3416 3326 */
    if ((i == 0) && (fi(j)!= 0)) {++i;} /* 3415 3416 */
    (i != 0) && (fi(j) != 0);           /* 3415 3416 */
    (fi(i) != 0) && (i != 0);           /* 3416 3427 */


/*******************************************************************************
:3112  This statement has no side-effect - it can be removed.
:3226  The result of an assignment is being used in an arithmetic operation or another assigning operation.
:3425  One branch of this conditional operation is a redundant expression.
:3446  The 2nd or 3rd operand of this conditional operator is an expression with possible side effects.
*******************************************************************************/
    (i > 0) ? j : (j = 2);              /* 3226 3425 3446 */
    (i > 0) ? j : (j+1);                /* 3112 */
    (i > 0) ? (j = 1) : (j = 2);        /* 3226 3226 3446 3446 */
    j = (i > 0) ? fi(i) : fi(i+1);      /* 3446 3446 */
    j = (i > 0) ? 1 : 2;


/*******************************************************************************
:3442  Operator other than & (address-of) or = (assignment) applied to a volatile object.
:3345  Statement contains more than one access to objects that are volatile.
*******************************************************************************/
    z = *port1;
    z = vp1;
    z = buf[vp1];                       /* 3442 */
    z = buf[*port2];                    /* 3442 */
    z = *port1 + *port2;                /* 3345 3442 */
    z = vp1 + vp2;                      /* 3345 3442 */
    z = vp1 + buf[vp2];                 /* 3345 3442 */
    z = vp1 + (vp1 << 4);               /* 3345 3442 0400 */

    return;
}
