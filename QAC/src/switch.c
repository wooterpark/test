/********************************************************************************************

SWITCH STATEMENTS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0277
#pragma PRQA_MESSAGES_OFF 0570
#pragma PRQA_MESSAGES_OFF 0572
#pragma PRQA_MESSAGES_OFF 1278
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2100-2107
#pragma PRQA_MESSAGES_OFF 2205
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2880
#pragma PRQA_MESSAGES_OFF 2890
#pragma PRQA_MESSAGES_OFF 2981
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 2986
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3196
#pragma PRQA_MESSAGES_OFF 3197
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3201
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3220
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3700-4031

#include "xample.h"


enum col { red, yellow, green };
enum planet { mercury=1, venus=3, mars=5 };


extern void foo1( int n, enum col colour )
{
    int r = 0;
    int x = 0;

/********************************************************************************************
:2002  No 'default' label found in this 'switch' statement.
:2003  The preceding 'switch' clause is not empty and does not end with a 'jump' statement. Execution will fall through.
:2020  Final 'switch' clause does not end with an explicit 'jump' statement.
:3315  This 'switch' statement contains only a single path - it is redundant.
:3352  This 'switch' statement contains only two execution paths.
********************************************************************************************/

    switch (n)
    {
    case 2:
        x = 1;
        break;
    }                                   /* 2002 3352 */


    switch (n)
    {
    case 2:
        x = 1;
        break;
    case 3:
        x = 2;

    default:                            /* 2003 */
        x = 1;
    }                                   /* 2020 */

    switch (n)
    {
    default:
        x = 4;
        break;
    }                                   /* 3315 */


/********************************************************************************************
:0735  Using relational or logical operators in a 'switch' expression is usually a programming error.
********************************************************************************************/

    switch (n != 0)                     /* 0735 */
    {
    case 1:
        ++r;
        break;

    default:
        r = 0;
        break;
    }                                   /* 3352 */


/********************************************************************************************
:2009  This 'default' label is not the final 'case' label within the 'switch' block.
:2016  This 'switch' statement 'default' clause is empty.
********************************************************************************************/

    switch (n)
    {
    default:                            /* 2009 */
        break;

    case 1:
        ++r;
        break;
    }                                   /* 2016 3352 */


/********************************************************************************************
:3309  The value of the controlling expression in this 'switch' statement is constant.
********************************************************************************************/

    switch ( 1 )                        /* 3309 */
    {
    default:
        r = 5;
        break;
    }                                   /* 3315 */



/********************************************************************************************
:3234  Declarations precede the first label in this 'switch' construct.
:3333  A 'break' statement has been used in the middle of a 'switch' 'case'/'default' clause.
********************************************************************************************/
    switch (n)
    {
        int sw1;                        /* 3234 */
    case 1:
        break;

    case 2:
        break;

    default:
        if (uia > 10U)
        {
            sw1 = 10;
            r = sw1;
            break;                      /* 3333 */
        }
        sw1 = 1;
        r = sw1;
        break;
    }


/********************************************************************************************
:1460  'Switch' label value, %s, not contained in enum type.
:1470  Numeric constant used as 'case' label with 'switch' expression of enum type.
:1472  Enum constant used as 'case' label with 'switch' expression of different enum type.
:2008  Code statements precede the first label in this 'switch' construct.
:2880  This statement is unreachable.
********************************************************************************************/
    switch (colour)
    {
    case red:
        ++r;
        break;

    case mercury:                       /* 1472 */
        ++r;
        break;

    case 2:                             /* 1470 */
        break;

    case 5:                             /* 1460 1470 */
        --r;
        break;

    default:
        r = r - 2;
        break;
    }

/********************************************************************************************
:2880  This statement is unreachable.
:3605  Type of 'switch' controlling expression cannot be represented in type 'int'.
:0594  Negative 'case' label expression is incompatible with unsigned controlling expression in 'switch' statement.
:0596  Value of 'case' label expression is too large for type of controlling expression in 'switch' statement.
:0597  Type of 'case' label expression is not consistent with type of controlling expression in 'switch' statement.
********************************************************************************************/

    switch (ula)                        /* 3605 */
    {
    case 2U: break;
    case -3: break;                     /* 0594 */
    case 80000L: break;                 /* 0597 */
    default: ++r; break;
    }

    switch (sla)                        /* 3605 */
    {
    case 2U: break;                     /* 0597 */
    case -3: break;
    case 40000L: break;
    case 50000UL: break;                /* 0597 */
    default: ++r; break;
    }

    switch (uia)                        /* 3605 */
    {
    case 2U: break;
    case -3: break;                     /* 0594 */
    case 80000UL: break;                /*      */
    default: ++r; break;
    }

    switch (sia)
    {
    case 2U: break;                     /* 0597 */
    case -3: break;
    case 40000L: break;                 /*      */
    case 50000UL: break;                /* 0597 */
    default: ++r; break;
    }

    switch (usa)
    {
    case 2U: break;
    case -3: break;                     /* 0594      */
    case 80000UL: break;                /* 0596 0597 */
    default: ++r; break;
    }

    switch (ssa)
    {
    case 2U: break;                     /* 0597      */
    case -3: break;
    case 40000UL: break;                /* 0596 0597 */
    default: ++r; break;
    }

    switch (uca)
    {
    case 2U: break;
    case -3: break;                     /* 0594      */
    case 256: break;                    /* 0596 0597 */
    default: ++r; break;
    }

    switch (sca)
    {
    case 2U: break;                     /* 0597      */
    case -3: break;
    case 128: break;                    /* 0596      */
    case -130: break;                   /* 0596      */
    default: ++r; break;
    }

    return;
}
