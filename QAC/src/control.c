/********************************************************************************************

CONTROL

******************************************************************************/
#pragma PRQA_MESSAGES_OFF 2006
#pragma PRQA_MESSAGES_OFF 2212
#pragma PRQA_MESSAGES_OFF 2214
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3204
#pragma PRQA_MESSAGES_OFF 3206
#pragma PRQA_MESSAGES_OFF 3210
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3446
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3492
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 4115
#pragma PRQA_MESSAGES_OFF 4116
#pragma PRQA_MESSAGES_OFF 4403
#pragma PRQA_MESSAGES_OFF 4538

#include "xample.h"

extern int foo2(void);


extern void control (int r, int p1, int p2)
{
/****************************************************************************************
:2000  No 'else' clause exists for this 'if' statement.
****************************************************************************************/

    if ( p1 > 10 )                      /* 2000 */
        --r;
#pragma PRQA_MESSAGES_OFF 2000


/****************************************************************************************
:2004  No concluding 'else' exists in this 'if'-'else'-'if' statement.
****************************************************************************************/

    if ( p1 > 10 )
        --r;
    else if (p1 < 5)                    /* 2004 */
        ++r;



/****************************************************************************************
:0769  A 'break' statement has been used to terminate an iteration statement.
:0770  A 'continue' statement has been used.
:0771  More than one 'break' statement has been used to terminate this iteration statement.
:2005  A 'continue' statement has been used.
****************************************************************************************/

    while (p2 > 10)
    {
        ++p2;

        if (p2 > 40)
            break;                      /* 0769 */


        if (p2 > 30)
            break;                      /* 0771 */


        if (p2 > 20)
            continue;                   /* 0770 2005 */

        ++p2;
    }


/****************************************************************************************
:3344  Controlling expression is not an 'effectively Boolean' expression.
****************************************************************************************/

    if (!(r > 5)) ++r;
    if (!(sia < sib)) ++r;
    if (!((sia < sib) && (sic != sid))) ++r;
    if ((!(sia < sib)) && (sic != sid)) ++r;
    if (r > 5) ++r;
    if (sia < sib) ++r;
    if ((sia + sib) < sic) ++r;
    if ((sia < sib) && (sic != sid)) ++r;
    if ((sia + sib) < sic) ++r;
    if (sia && sib) ++r;
    if (!r) ++r;
    if (!sia) ++r;
    r = !sia;
    r = (sia > 1) && sib;
    r = (sia > 1) || sib;
    r = (sia > 1) ? sib : sic;
    if (r) ++r;                         /* 3344 */
    if (uia & uib) ++r;                 /* 3344 */
    if (sia + sib) ++r;                 /* 3344 */


/****************************************************************************************
:3314  This controlling expression is an assignment.
:3326  The result of an assignment is being used in a logical operation.
:3416  Logical operation performed on expression with possible side effects.
****************************************************************************************/

    if ( (r = foo2()) == 0)             /* 3326           3416 3416 */
        ++r;

    if ( r = foo2() )                   /* 3314 3326 3344 3416 3416 */
        ++r;

    while (r = foo2())                  /* 3314 3326 3344 3416 3416 */
        ++r;


}
