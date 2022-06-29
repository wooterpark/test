#pragma PRQA_MESSAGES_OFF 1056,1418,1482,1484,2100,2103,2211,2213,2901,2982,2984,3210,3408,3447,3602,3631,3768,3847,3892,4121,4434,4461,4570
#include "xample.h"
/***************************************************************

IMPLICIT CASTING OF AN EXPRESSION
=================================

MESSAGES:
=========
4301  An expression of 'essentially Boolean' type (%1s) is being cast to character type '%2s'.
4302  An expression of 'essentially Boolean' type (%1s) is being cast to enum type '%2s'.
4303  An expression of 'essentially Boolean' type (%1s) is being cast to signed type '%2s'.
4304  An expression of 'essentially Boolean' type (%1s) is being cast to unsigned type '%2s'.
4305  An expression of 'essentially Boolean' type (%1s) is being cast to floating type '%2s'.
4310  An expression of 'essentially character' type (%1s) is being cast to Boolean type, '%2s'.
4312  An expression of 'essentially character' type (%1s) is being cast to enum type, '%2s'.
4315  An expression of 'essentially character' type (%1s) is being cast to floating type, '%2s'.
4320  An expression of 'essentially enum' type (%1s) is being cast to Boolean type, '%2s'.
4322  An expression of 'essentially enum' type (%1s) is being cast to type a different enum type, '%2s'.
4325  An expression of 'essentially enum' type (%1s) is being cast to floating type, '%2s'.
4330   An expression of 'essentially signed' type (%1s) is being cast to Boolean type '_Bool'
4330  An expression of 'essentially signed' type (%1s) is being cast to Boolean type '%2s'.
4332  An expression of 'essentially signed' type (%1s) is being cast to enum type, '%2s'.
4340  An expression of 'essentially unsigned' type (%1s) is being cast to Boolean type '%2s'.
4342  An expression of 'essentially unsigned' type (%1s) is being cast to enum type, '%2s'.
4350  An expression of 'essentially floating' type (%1s) is being cast to Boolean type '%2s'.
4351  An expression of 'essentially floating' type (%1s) is being cast to character type '%2s'.
4352  An expression of 'essentially floating' type (%1s) is being cast to enum type, '%2s'.
4398 An expression which is the result of a ~ or << operation has been cast to a different essential type category.
4399 An expression which is the result of a ~ or << operation has been cast to a wider type.
***************************************************************/

#define BEXP (1==1)
enum X1 { A, B, C };
extern enum X1 en1;
enum X2 { RED,YELLOW,BLUE };
extern enum X2 en2;

void func1(void)
{
    pca = (char)BEXP;                           /* 4301 */
    en1 = (enum X1)BEXP;                        /* 4302 */
    sia = (signed int)BEXP;                     /* 4303 */
    uia = (unsigned int)BEXP;                   /* 4304 */
    fta = (float)BEXP;                          /* 4305 */

    bla = (_Bool)pca;                           /* 4310 */
    en1 = (enum X1)pca;                         /* 4312 */
    fta = (float)pca;                           /* 4315 */

    bla = (_Bool)en1;                           /* 4320 */
    en2 = (enum X2)en1;                         /* 4322 */
    fta = (float)en1;                           /* 4325 */

    bla = (_Bool)sia;                           /* 4330 */
    en2 = (enum X2)sia;                         /* 4332 */

    bla = (_Bool)uia;                           /* 4340 */
    en2 = (enum X2)uia;                         /* 4342 */

    bla = (_Bool)fta;                           /* 4350 */
    pca = (char)fta;                            /* 4351 */
    en2 = (enum X2)fta;                         /* 4352 */

    uxa = (signed long)~usa;                   /* 4398 */
    uca = (unsigned int)~uca;                   /* 4399 */
}

