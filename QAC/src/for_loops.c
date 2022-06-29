/********************************************************************************************

FOR LOOP MESSAGES

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 1319
#pragma PRQA_MESSAGES_OFF 1481
#pragma PRQA_MESSAGES_OFF 1296
#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2214
#pragma PRQA_MESSAGES_OFF 2753
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3121
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3201
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3218
#pragma PRQA_MESSAGES_OFF 3220
#pragma PRQA_MESSAGES_OFF 3222
#pragma PRQA_MESSAGES_OFF 3355
#pragma PRQA_MESSAGES_OFF 3356
#pragma PRQA_MESSAGES_OFF 3359
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3416
#pragma PRQA_MESSAGES_OFF 3418
#pragma PRQA_MESSAGES_OFF 3440
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 4527

extern int n;
static int fsloop;

int foo(void)
{
    int   loop = 0;
    int   x;
    int  *pi;
    float ft;


/***********************************************************************************
IDENTIFICATION OF THE "LOOP CONTROL VARIABLE":

:2461  Loop control variable, %s, has file scope.
:2471  Unable to identify a loop control variable.
:2472  More than one possible loop control variable.
:3340  Floating point variable used as 'for' loop control variable.
:3342  Controlling expression of 'for' loop is a floating point comparison.
***********************************************************************************/
    for (x = 0; loop < n; ++x) ++loop;                  /* 2471 */

    for (; loop < (x * 2); ++loop, ++x) ++loop;         /* 2472 */

    for (ft = 0.0F; ft < 10.0F; ft = ft + 2.0F) ++loop; /* 3340 3342 */

    for (fsloop = 1; fsloop < n; ++fsloop) ++x;         /* 2461 */


/***********************************************************************************
DECLARATIONS IN FOR STATEMENTS:

:0320  [C99] Declaration within 'for' statement.
:0321  [C] Declaration within 'for' statement defines an identifier '%s' which is not an object.
:0322  [C] Illegal storage class specifier used in 'for' statement declaration.
***********************************************************************************/
    for (int lv = 0; lv < n; ++lv) { }                  /* 0320 */

    for (enum { X, Y, Z } i = X; i < Z; ++i) { }        /* 0320 0321 */

    for (extern int gi; gi < n; ++gi) { }               /* 0320 0322 */

/***********************************************************************************
CONTROL VARIABLE INITIALISATION:

:2462  The variable initialized in the first expression of this 'for' statement is not the variable identified as the 'loop control variable' (%s).
:3419  Initialization expression of 'for' statement has no side effects.
***********************************************************************************/
    for (x = 0; loop < n; ++loop) ++x;                  /* 2462 */

    for (loop == 0; loop < 10; ++loop) ++x;             /* 2462 3419 */

/***********************************************************************************
:2463  The variable incremented in the third expression of this 'for' statement is not the variable identified as the 'loop control variable' (%s).
:2469  Loop control variable in this 'for' statement, %s, is modified in the body of the loop.
:2470  Taking address of loop control variable, %s.
**********************************************************************************/
    for (loop = 0; loop < 30; ++x)                      /* 2463 */
    {
        loop = 2 * x;                                   /* 2469 */
    }

    for (loop = 0; loop < 30; ++loop)
    {
        pi = &loop;                                     /* 2469 2470 */
    }

/***********************************************************************************
:2466  The value of this controlling expression is always 'false'. The contained code is unreachable.
***********************************************************************************/

    for (loop = 0; loop < 0; ++loop) ++x;               /* 2466 */

/***********************************************************************************
:2463  The variable incremented in the third expression of this 'for' statement is not the variable identified as the 'loop control variable' (%s).
:2464  Loop control variable, %s, modified twice in for-loop header.
:2467  Loop control variable, %s, is not modified inside loop.
:2468  Loop control variable, %s, is not modified inside loop but has file scope.
:3420  Increment expression of 'for' statement has no side effects.
***********************************************************************************/
    for (loop = 0; loop < n;) ++x;                      /* 2467 */

    for (loop = 0; ++loop < n; ++loop) ++x;             /* 2464 */

    for (loop = 0; ++loop < 10; loop + 1) ++x;          /* 2463 3420 */

    for (fsloop = 0; fsloop < n;) ++x;                  /* 2461 2468 */

    return loop;
}


