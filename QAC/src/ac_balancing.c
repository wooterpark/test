#pragma PRQA_MESSAGES_OFF 1056,1253,2100-2109,2211,2213,2890,2985,3112,3120,3328,3408,3447,3602,3708,3719,3730,3741,3752,3753,3760,3762,3763,3772,3774,3785,3796,3843,3844,3860,3873,4103-4105,4130
#include "xample.h"
/* **************************************************************

BALANCING OF OPERANDS IN ARITHMETIC OPERATIONS
==============================================

NEW MESSAGES:
=============

:1800  The %1s operand (essential type: '%2s') will be implicitly converted to a floating type, '%3s', in this arithmetic operation.
:1810  An operand of 'essentially character' type is being added to another operand of 'essentially character' type
:1820  The %1s operand is non-constant and 'essentially signed' (%2s) but will be implicitly converted to an unsigned type (%3s) in this arithmetic  operation.
:1830  The %1s operand is constant, 'essentially signed' (%2s) and negative but will be implicitly converted to an unsigned type (%3s) in this arithmetic operation.
:1840  The %1s operand is constant, 'essentially signed' (%2s) and non-negative but will be implicitly converted to an unsigned type (%3s) in this arithmetic  operation.
:1850  The %1s operand is 'essentially unsigned' (%2s) but will be implicitly converted to a signed type (%3s) in this arithmetic  operation.
:1860  The operands of this arithmetic operator are of different 'essential signedness' but will generate a result of type 'signed int'.

:1831  The %1s operand is constant, 'essentially signed' (%2s) and negative but will be implicitly converted to an unsigned type (%3s) in this bitwise operation.
:1832  The %1s operand is constant, 'essentially signed' (%2s) and negative but will be implicitly converted to an unsigned type (%3s) in this relational operation.
:1833  The %1s operand is constant, 'essentially signed' (%2s) and negative but will be implicitly converted to an unsigned type (%3s) in this equality operation.

:1810  An operand of 'essentially character' type is being added to another operand of 'essentially character' type."
:1811  An operand of 'essentially character' type is being subtracted from an operand of 'essentially signed' type."
:1812  An operand of 'essentially character' type is being subtracted from an operand of 'essentially unsigned' type."
:1813  An operand of 'essentially character' type is being balanced with an operand of 'essentially floating' type in an addition or subtraction operation.

:4501  An expression of 'essentially Boolean' type (%1s) is being used as the %2s operand of this arithmetic operator (%3s).
:4511  An expression of 'essentially character' type (%1s) is being used as the %2s operand of this arithmetic operator (%3s).
:4521  An expression of 'essentially enum' type (%1s) is being used as the %2s operand of this arithmetic operator (%3s).
:4532 An expression of 'essentially signed' type (%1s) is being used as the %2 operand of this bitwise operator (%3s).

******************************************************************************/


enum X1 { A, B, C };
extern enum X1 en1;
enum X2 { RED,YELLOW,BLUE };
extern enum X2 en2;

extern void foo(void)
{
    en2 + fta;                    /* 1800 */

    pcb + pca;                    /* 1810 */
    sib - pca;                    /* 1811 */
    uib - pca;                    /* 1812 */
    pcb + fta;                    /* 1813 */

    uia * -23  ;                  /* 1830 */
    uia & -23  ;                  /* 1831 4532 */
    uia > -23  ;                  /* 1832 */
    uia == -23  ;                 /* 1833 */
 
    uib + sca;                    /* 1820 */
    uia * 2;                      /* 1840 */
    sib + uca;                    /* 1850 */
    uca * sca;                    /* 1860 */  

    blb + bla;                    /* 4501x2 */
    blb + pca;                    /* 4501 */
    sca * pcb;                    /* 4511 */
    blb + en1;                    /* 4501 4521 */

    en2 + pca;                    /* 4521 */
    en2 + en1;                    /* 4521x2 */
    
    return;
}
