/*******************************************************************************************

DECLARATIONS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0506
#pragma PRQA_MESSAGES_OFF 1278
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2017
#pragma PRQA_MESSAGES_OFF 2205
#pragma PRQA_MESSAGES_OFF 2209
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3121
#pragma PRQA_MESSAGES_OFF 3122
#pragma PRQA_MESSAGES_OFF 3132
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3206
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3313
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 3684



extern int foo(int n)
{
/*****************************************************************************
:0623  [U] '%s' has incomplete type and no linkage - this is undefined.

:2007  'auto' does not add information to a declaration, and is best avoided.
:2011  The 'register' storage class specifier has been used.
:2050  The 'int' type specifier has been omitted from a function declaration.
:2051  The 'int' type specifier has been omitted from an object declaration.
:3204  The variable '%s' is only set once and so it could be declared with the 'const' qualifier.
:3220  Identifier declared at a nested level of block scope.
:3223  Object with static storage duration declared at block scope.
:3620  'register' may be illegal on array and 'struct' / 'union' types in some compilers.
*****************************************************************************/
    int xx[];                           /* 0623      */
    int c = 1;                          /* 3204      */
    auto int e = 1;                     /* 2007      */
    register int g;                     /* 2011      */
    register struct st {int i;}loc;     /* 2011 3620 */
    static int s;                       /* 3223      */
    const a = 1;                        /* 2051x2    */


    if (n > 0)
    {
        const int h = 2;                /* 3220      */

        ++e;
        s = a + c + e;
    }

    return s;
}
