/********************************************************************************************

REDUNDANT CONSTRUCTS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 489,506,510,2017,2022,2213,2824,2982,2983,3120,3198,3199,3227,3401,3408,3416,3440,3447,3450,3602

#include "xample.h"

extern int redun1(int x);


/*****************************************************************************
:3210  The global identifier '%s' is declared here but is not used in this translation unit.
:3207  File scope static, '%s', is not used, and could be removed.
:3308  'static %s()' has been declared but no definition has been provided. This is redundant.
:3219  Static function '%s()' is not used within this translation unit.
*****************************************************************************/
extern int  gi;                         /* 3210 */
static int  si;                         /* 3207 */
static int sfn1( void );                /* 3308 */
static void sfn2(void) {}               /* 3219 */


/*****************************************************************************
:3196  The variable '%s' is never set.
:3203  The variable '%s' is set but never used.
:3205  The identifier '%s' is not used and could be removed.
:3206  The parameter '%s' is not used in this function.
*****************************************************************************/
void redundant(
    int ap,                             /* 3206 */
    int *pi,
    int r)
{
    int          setvar;                /* 3203 */
    int          unusedvar;             /* 3205 */
    typedef int  unusedtd;              /* 3205 */
    int          y;                     /* 3196 */
    const int   *pci;                   /* 3203 */
    struct stag
    {
        int m1;
        int m2;
    } unusedst;                         /* 3205 */

/*****************************************************************************
:3212  This cast is redundant.
:3307  The operand of 'sizeof' is an expression with implied side effects, but they will not be evaluated.
:3404  Statement contains a redundant * operator at top level. *p++ means *(p++) not (*p)++.
:3422  Statement contains a redundant operator at top level.
:3423  Statement contains a redundant cast at top level.
:3470  The operand of 'sizeof' is not an expression which designates either an object or a type.
:3892  The result of this cast is implicitly converted to another type.
*****************************************************************************/

    sir = (int)(r + 2);                 /* 3212 */
    setvar = r;
    sir == redun1(1);                   /* 3422 */
    *(pi++);                            /* 3422 */
    *pi++;                              /* 3404 */
    (*pi)++;
    sir = (long)(sia);                  /* 3892 */
    (long)(sia+=1);                     /* 3423 */
    sia = (int)sizeof(uia++);           /* 3307 3470 */
    sib = (int)sizeof(uia + uib);       /*      3470 */
    pci = &y;
}
