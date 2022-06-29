#pragma PRQA_MESSAGES_OFF 1056,1278,1412,1422,1432,1442,2100,2104,2211,2213,2982,3200,3206,3209,3210,3447,3408,3602,3704,3705,3708,3755,3756,3760,3763,3766,3768,3771,3774,3799,3804,3805,3819,4120,4443,4570
#include "xample.h"
/***************************************************************

IMPLICIT ASSIGNING CONVERSIONS 
==============================

MESSAGES:
=========
:4401  An expression of 'essentially Boolean' type (%1s) is being assigned to an object of character type, '%2s'.
:4402  An expression of 'essentially Boolean' type (%1s) is being assigned to an object of enum type, '%2s'.
:4403  An expression of 'essentially Boolean' type (%1s) is being assigned to an object of signed type, '%2s'.
:4404  An expression of 'essentially Boolean' type (%1s) is being assigned to an object of unsigned type, '%2s'.
:4405  An expression of 'essentially Boolean' type (%1s) is being assigned to an object of floating type, '%2s'.
:4410  An expression of 'essentially character' type (%1s) is being assigned to an object of Boolean type, '%2s'.
:4412  An expression of 'essentially character' type (%1s) is being assigned to an object of enum type, '%2s'.
:4413  An expression of 'essentially character' type (%1s) is being assigned to an object of signed type, '%2s'.
:4414  An expression of 'essentially character' type (%1s) is being converted to unsigned type, '%2s' on assignment.
:4415  An expression of 'essentially character' type (%1s) is being assigned to an object of floating type, '%2s'.
:4420  An expression of 'essentially enum' type (%1s) is being assigned to an object of Boolean type, '%2s'.
:4421  An expression of 'essentially enum' type (%1s) is being assigned to an object of character type, '%2s'.
:4422  An expression of 'essentially enum' type (%1s) is being assigned to an object of a different enum type, '%2s'.
:4423  An expression of 'essentially enum' type (%1s) is being assigned to an object of signed type, '%2s'.
:4424  An expression of 'essentially enum' type (%1s) is being assigned to an object of unsigned type, '%2s'.
:4425  An expression of 'essentially enum' type (%1s) is being assigned to an object of floating type, '%2s'.
:4430  An expression of 'essentially signed' type (%1s) is being assigned to an object of Boolean type, '_Bool'.
:4431  An expression of 'essentially signed' type (%1s) is being converted to character type, '%2s' on assignment.
:4432  An expression of 'essentially signed' type (%1s) is being converted to enum type, '%2s' on assignment.
:4434  A non constant expression of 'essentially signed' type (%1s) is being assigned to an object of unsigned type, '%2s'.
:4435 A non-constant expression of 'essentially signed' type (%1s) is being assigned to an object of floating type, '%2s'.
:4436  A constant expression of 'essentially signed' type (%1s) is being assigned to an object of unsigned type, '%2s'.
:4437 A constant expression of 'essentially signed' type (%1s) is being assigned to an object of floating type, '%2s'.
:4440  An expression of 'essentially unsigned' type (unsigned char) is being assigned to an object of Boolean type, '_Bool'.
:4441  An expression of 'essentially unsigned' type (%1s) is being converted to character type, '%2s' on assignment.
:4442  An expression of 'essentially unsigned' type (%1s) is being converted to enum type, '%2s' on assignment.
:4443  A non-constant expression of 'essentially unsigned' type (%1s) is being assigned to an object of a larger signed type, '%2s'.
:4445 An expression of 'essentially unsigned' type (%1s) is being assigned to an object of floating type, '%2s'.
:4446  A non-constant expression of 'essentially unsigned' type (%1s) is being converted to signed type, '%2s' on assignment.
:4447  A constant expression of 'essentially unsigned' type (%1s) is being assigned to an object of signed type, '%2s'.
:4450 An expression of 'essentially floating' type (%1s) is being assigned to an object of Boolean type, '%2s'.
:4451  An expression of 'essentially floating' type (%1s) is being converted to character type, '%2s' on assignment.
:4452  An expression of 'essentially floating' type (%1s) is being converted to enum type, '%2s' on assignment.
:4453  An expression of 'essentially floating' type (%1s) is being converted to signed type, '%2s' on assignment.
:4454  An expression of 'essentially floating' type (%1s) is being converted to unsigned type, '%2s' on assignment.
:4460  A non-constant expression of 'essentially signed' type (%1s) is being converted to narrower signed type, '%2s' on assignment.
:4461  A non-constant expression of 'essentially unsigned' type (%1s) is being converted to narrower unsigned type, '%2s' on assignment.
:4462  A non-constant expression of 'essentially floating' type (%1s) is being converted to narrower floating type, '%2s' on assignment."
:4463  A constant expression of 'essentially signed' type (%1s) is being assigned to an object of narrower signed type, '%2s'.
:4464  A constant expression of 'essentially unsigned' type (%1s) is being assigned to an object of narrower unsigned type, '%2s'.
:4470  A non-constant expression of 'essentially signed' type (%1s) is being passed to a function parameter of wider signed type, '%2s'.
:4471  A non-constant expression of 'essentially unsigned' type (%1s) is being passed to a function parameter of wider unsigned type, '%2s'.
:4472 A non-constant expression of 'essentially floating' type (%1s) is being passed to a function parameter of wider floating type, '%2s'.
:4480  A non-constant expression of 'essentially signed' type (%1s) is being returned from a function defined with a wider signed return type, '%2s'."
:4481  A non-constant expression of 'essentially unsigned' type (%1s) is being returned from a function defined with a wider unsigned return type, '%2s'.
:4482 A non-constant expression of 'essentially floating' type (%1s) is being returned from a function defined with a wider floating return type, '%2s'.
:4490  A composite expression of 'essentially signed' type (%1s) is being converted to wider signed type, '%2s' on assignment."
:4498 An expression which is the result of a ~ or << operation has been assigned to an object of a different essential type category.
:4499 An expression which is the result of a ~ or << operation has been assigned to an object of a wider essential type.


***************************************************************/
#define BEXP (1==1)
enum X1 { A, B, C };
extern enum X1 en1;
enum X2 { RED,YELLOW,BLUE };
extern enum X2 en2;

void func1(void)
{
    pca = BEXP;                             /* 4401 */
    en1 = BEXP;                             /* 4402 */
    sia = BEXP;                             /* 4403 */
    uia = BEXP;                             /* 4404 */
    fta = BEXP;                             /* 4405 */

    bla = pca;                              /* 4410 */
    en1 = pca;                              /* 4412 */
    sia = pca;                              /* 4413 */
    uia = pca;                              /* 4414 */
    fta = pca;                              /* 4415 */

    bla = en1;                              /* 4420 */
    pca = en1;                              /* 4421 */
    en2 = en1;                              /* 4422 */
    sia = en1;                              /* 4423 */
    uia = en1;                              /* 4424 */
    fta = en1;                              /* 4425 */

    bla = sia;                              /* 4430 */
    pca = sia;                              /* 4431 */
    en2 = sia;                              /* 4432 */
    uia = sia;                              /* 4434 */
    fta = sia;                              /* 4435 */
    uia = 1 + 1;                            /* 4436 */
    fta = 1 + 1;                            /* 4437 */

    bla = uia;                              /* 4440 */
    pca = uia;                              /* 4441 */
    en2 = uia;                              /* 4442 */
    fta = uia;                              /* 4445 */
    sia = uia;                              /* 4446 */
    sia = 1U + 1U;                          /* 4447 */

    bla = fta;                              /* 4450 */
    pca = fta;                              /* 4451 */
    en2 = fta;                              /* 4452 */
    sia = fta;                              /* 4453 */
    uia = fta;                              /* 4454 */

    sca = sia;                              /* 4460 */
    uca = uia;                              /* 4461 */
    fta = dba;                              /* 4462 */
    ssa = 1L + 1L;                          /* 4463 */
    usa = 1UL + 1UL;                        /* 4464 */

}

int func2(int x)
{
    return sca;                             /* 4480 */
}
unsigned int func3(unsigned int x)
{
    return uca;                             /* 4481 */
}
double func4(double x)
{
    return fta;                             /* 4482 */
}

void func5(void)
{
    func2(sca);                             /* 4470 */
    func3(uca);                             /* 4471 */
    func4(fta);                             /* 4472 */
}

void func6(void)
{
    ssa = sca + scb;                        /* 4490 */
    sla = ~uca;                             /* 4498 */
    usa = ~uca;                             /* 4499 */
}
