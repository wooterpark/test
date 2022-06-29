#pragma PRQA_MESSAGES_OFF 1056,1251,1253,1274,1278,1319,1418,1481,1482,1484,1841,1292,1821,1881,2000,2100,2106,2109,2103,2211,2213,2901,2982,2984,2992,2995,2996,3120,3121,3210,3203,3132,3344,3408,3447,3492,3602,3625,3631,3760,3768,3847,3892,4104,4105,4109,4111,4115,4121,4130,4131,4434,4436,4461,4491,4499,4570,4571
#include "xample.h"
/***************************************************************

IMPLICIT CASTING OF AN EXPRESSION
=================================

MESSAGES:
=========
4500  An expression of 'essentially Boolean' type (%1s) is being used as an array subscript.
4501  An expression of 'essentially Boolean' type (%1s) is being used as the %2s operand of this arithmetic operator (%3s).
4502  An expression of 'essentially Boolean' type (%1s) is being used as the %2s operand of this bitwise operator (%3s).
4503  An expression of 'essentially Boolean' type (%1s) is being used as the left-hand operand of this shift operator (%2s).
4504  An expression of 'essentially Boolean' type (%1s) is being used as the right-hand operand of this shift operator (%2s).
4505  An expression of 'essentially Boolean' type (%1s) is being used as the %2s operand of this relational operator (%3s).
4507  An expression of 'essentially Boolean' type (%1s) is being used as the operand of this increment/decrement operator (%2s).
4510  An expression of 'essentially character' type (%1s) is being used as an array subscript.
4511  An expression of 'essentially character' type (%1s) is being used as the %2s operand of this arithmetic operator (%3s).
4512  An expression of 'essentially character' type (%1s) is being used as the %2s operand of this bitwise operator (%3s).
4513  An expression of 'essentially character' type (%1s) is being used as the left-hand operand of this shift operator (%2s).
4514  An expression of 'essentially character' type (%1s) is being used as the right-hand operand of this shift operator (%2s).
4517  An expression of 'essentially character' type (%1s) is being used as the operand of this increment/decrement operator (%2s).
4518  An expression of 'essentially character' type (%1s) is being used as the %2s operand of this logical operator (%3s).
4519  An expression of 'essentially character' type (%1s) is being used as the first operand of this conditional operator (%2s).
4521  An expression of 'essentially enum' type (%1s) is being used as the %2s operand of this arithmetic operator (%3s).
4522  An expression of 'essentially enum' type (%1s) is being used as the %2s operand of this bitwise operator (%3s).
4523  An expression of 'essentially enum' type (%1s) is being used as the left-hand operand of this shift operator (%2s).
4524  An expression of 'essentially enum' type (%1s) is being used as the right-hand operand of this shift operator (%2s).
4527  An expression of 'essentially enum' type is being used as the operand of this increment/decrement operator.
4528  An expression of 'essentially enum' type (%1s) is being used as the %2s operand of this logical operator (%3s).
4529  An expression of 'essentially enum' type (%1s) is being used as the first operand of this conditional operator (%2s).
4532  An expression of 'essentially signed' type (%1s) is being used as the %2s operand of this bitwise operator (%3s).
4533  An expression of 'essentially signed' type (%1s) is being used as the left-hand operand of this shift operator (%2s).
4534  An expression of 'essentially signed' type (%1s) is being used as the right-hand operand of this shift operator (%2s).
4538  An expression of 'essentially signed' type (%1s) is being used as the %2s operand of this logical operator (%3s).
4539  An expression of 'essentially signed' type (%1s) is being used as the first operand of this conditional operator (%2s).
4542  A non-negative constant expression of 'essentially signed' type (%1s) is being used as the %2s operand of this bitwise operator (%3s).
4543  A non-negative constant expression of 'essentially signed' type (%1s) is being used as the left-hand operand of this shift operator (%2s).
4544  A non-negative constant expression of 'essentially signed' type (%1s) is being used as the right-hand operand of this shift operator (%2s).
4548  A non-negative constant expression of 'essentially signed' type (%1s) is being used as the %2s operand of this logical operator (%3s).
4549  A non-negative constant expression of 'essentially signed' type (%1s) is being used as the first operand of this conditional operator (%2s).
4558  An expression of 'essentially unsigned' type (%1s) is being used as the %2s operand of this logical operator (%3s).
4559  An expression of 'essentially unsigned' type (%1s) is being used as the first operand of this conditional operator (%2s).
4568  An expression of 'essentially floating' type (%1s) is being used as the %2s operand of this logical operator (%3s).
4569  An expression of 'essentially floating' type (%1s) is being used as the first operand of this conditional operator (%2s).
4570  The operand of this ~ operator has an 'essential type' which is narrower than type 'int'.
4571  The left-hand operand of this << operator has an 'essential type' which is narrower than type 'int'.
***************************************************************/

#define BEXP (1==1)
enum X1 { A, B, C };
extern enum X1 en1;
enum X2 { RED,YELLOW,BLUE };
extern enum X2 en2;

void func1(void)
{
    char buf[10];

    buf[bla] = 0;                   /* 4500 */
    uia = uia + bla;                /* 4501 */
    uia = uia | bla;                /* 4502 */
    uia = bla << 1U;                /* 4503 */
    uia = 1U << bla;                /* 4504 */
    if (uia < bla)                  /* 4505 */
    {
    }
    bla++;                          /* 4507 */

    buf[pca] = 0;                   /* 4510 */
    uia = uia + pca;                /* 4511 */
    uia = uia | pca;                /* 4512 */
    uia = pca << 1U;                /* 4513 */
    uia = 1U << pca;                /* 4514 */
    pca++;                          /* 4517 */
    bla = (uia == 1U) || pca;       /* 4518 */
    uia = (pca ? 1U : 2U);          /* 4519 */

    uia = uia + en1;                /* 4521 */
    uia = uia | en1;                /* 4522 */
    uia = en1 << 1U;                /* 4523 */
    uia = 1U << en1;                /* 4524 */
    en1++;                          /* 4527 */
    bla = (uia == 1U) || en1;       /* 4528 */
    uia = (en1 ? 1U : 2U);          /* 4529 */

    uia = uia | sia;                /* 4532 */
    uia = sia << 1U;                /* 4533 */
    uia = 1U << sia;                /* 4534 */
    bla = (uia == 1U) || sia;       /* 4538 */
    uia = (sia ? 1U : 2U);          /* 4539 */

    uia = uia | 1;                  /* 4542 */
    uia = 1 << 1U;                  /* 4543 */
    uia = 1U << 1;                  /* 4544 */
    bla = (uia == 1U) || 1;         /* 4548 */
    uia = (1 ? 1U : 2U);            /* 4549 */

    bla = (uia == 1U) || (usa + 1U);/* 4558 */
    uia = (usa ? 1U : 2U);          /* 4559 */

    bla = (uia == 1U) || (fta * 3.14);/* 4568 */
    uia = (fta ? 1U : 2U);          /* 4569 */

#pragma PRQA_MESSAGES_ON 4570,4571

    uia = ~uca;                     /* 4570 */
    uia = uca << 1U;                /* 4571 */

}

