#pragma PRQA_MESSAGES_OFF 0597,0815,1056,1278,1259,2013,2100,2103,2016,2204,2211,2213,3120,3123,3408,3602,3605,3610
#include "xample.h"
/***************************************************************

IMPLICIT CONVERSIONS IN SWITCH CASE EVALUATION
==============================================

MESSAGES:
=========
:0570 This switch case label of 'essential type' '%1s', is not consistent with a controlling expression of essential type '%2s'.
:0571 This switch case label of 'essential type' '%1s' is not consistent with a controlling expression which has an essential type of higher rank (%2s).
:0572 This switch case label of 'essential type' '%1s' is not consistent with a controlling expression which has an essential type of lower rank (%2s).
******************************************************************************/

extern void foo (void)
{
    switch (usa)
    {
        case 0:               break;                       /* 0570 */
        case 1:               break;                       /* 0570 */
        case 2:               break;                       /* 0570 */
        case 1 + 2:           break;                       /* 0570 */
        case (signed char)4:  break;                       /* 0570 */
        case (signed short)5: break;                       /* 0570 */
        case 6L:              break;                       /* 0570 */
        case 7LL:             break;                       /* 0570 */

        default:              break;
    }

    switch (sxa)
    {
        case 0L:              break;                       /* 0571 */
        case (long)1:         break;                       /* 0571 */
        case 2:               break;                       /*      */
        case 3LL:             break;                       /*      */

        default:              break;
    }

    switch (uia)
    {
        case 0U:              break;                       /*      */
        case 1U:              break;                       /*      */
        case 2U:              break;                       /*      */
        case (UC)7 + (UC)1:   break;                       /*      */
        case 10U:             break;                       /*      */
        case 10U + 1U:        break;                       /*      */
        case 12UL:            break;                       /* 0572 */
        case 14ULL:           break;                       /* 0572 */
    
        default:              break;
    }

    return;
}
