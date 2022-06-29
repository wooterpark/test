#pragma PRQA_MESSAGES_OFF 2017,3103,3120,3203,3408,3447

/*****************************************************************************

REDUNDANT INITIALIZATIONS AND ASSIGNMENTS
=========================================


OBSOLETE MESSAGES:

:3195  The function parameter '%s' is always modified before use.
:3197  This initialization is redundant. The value of '%s' is never used before being modified.
:3198  This assignment is redundant. The value of '%s' is never used before being modified.
:3199  This assignment is redundant. The value of '%s' is never subsequently used.


NEW MESSAGES:

:2980  The function parameter '%1s' is always modified before use.
:2981  This initialization is redundant. The value of '%1s' is never used before being modified.
:2982  This assignment is redundant. The value of '%1s' is never used before being modified.
:2983  This assignment is redundant. The value of '%1s' is never subsequently used.

********************************************************************************************/

extern void foo(int p);

extern void f1(int n)                   /* 2980 */
{
    int  i = 0;                         /* 2981 */

    n = 10;
    foo(n);

    i = 10;
    foo(i);

    i = 20;                             /* 2982 */
    foo(0);
    i = 30;
    foo(i);

    i = 40;                             /* 2983 */

    return;
}

/*****************************************************************************

REDUNDANT OPERATIONS
====================

********************************************************************************************/

void f2(int n)
{
    int x = 1;

    n = n * x;                         /*           2985 */ 
    n = n / x;                         /*           2985 */
    n = n / (x * 100);                 /*      2984      */

    x = 0;
    n = n + x;                         /*           2985 */
    n = n - x;                         /*           2985 */
    n = n + (x * x);                   /* 2983 2984 2985 */
}
