/********************************************************************************************

INTEGRAL PROMOTION AND DEFAULT ARGUMENT PROMOTION

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0634
#pragma PRQA_MESSAGES_OFF 0635
#pragma PRQA_MESSAGES_OFF 1277
#pragma PRQA_MESSAGES_OFF 1302
#pragma PRQA_MESSAGES_OFF 1810
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3131
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3206
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3335
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3621
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 4443
#pragma PRQA_MESSAGES_OFF 4490

#include "xample.h"

extern void promotion(void)
{
                                 /*             *            * char=schar *  char=uchar */
                                 /*             *            *            *             */
                                 /*     char= 8 *    char= 8 *    char=16 *     char=16 */
                                 /*    short=16 *   short=16 *   short=16 *    short=16 */
                                 /*      int=32 *     int=16 *     int=16 *      int=16 */

/********************************************************************************************
:2100  Integral promotion : unsigned char promoted to signed int.
:2101  Integral promotion : unsigned short promoted to signed int.
:2102  Integral promotion : unsigned char promoted to unsigned int.
:2103  Integral promotion : unsigned short promoted to unsigned int.
:2104  Integral promotion : signed char promoted to signed int.
:2105  Integral promotion : signed short promoted to signed int.
:2106  Integral promotion : plain char promoted to signed int.
:2107  Integral promotion : plain char promoted to unsigned int.
********************************************************************************************/

    sir = uca + ucb;             /*        2100 *       2100 *       2102 *        2102 */
    sir = usa + usb;             /*        2101 *       2103 *       2103 *        2103 */
    sir = sca + scb;             /*        2104 *       2104 *       2104 *        2104 */
    sir = ssa + ssb;             /*        2105 *       2105 *       2105 *        2105 */
    sir = pca + pcb;             /*        2106 *       2106 *       2106 *        2107 */


/********************************************************************************************
:2110  Default argument promotion : unsigned char promoted to signed int.
:2111  Default argument promotion : unsigned short promoted to signed int.
:2112  Default argument promotion : unsigned char promoted to unsigned int.
:2113  Default argument promotion : unsigned short promoted to unsigned int.
:2114  Default argument promotion : signed char promoted to signed int.
:2115  Default argument promotion : signed short promoted to signed int.
:2116  Default argument promotion : plain char promoted to signed int.
:2117  Default argument promotion : plain char promoted to unsigned int.
:2118  Default argument promotion : float promoted to double.
********************************************************************************************/

    sir = foo1(uca);             /*        2110 *       2110 *       2112 *        2112 */
    sir = foo2(usa);             /*        2111 *       2113 *       2113 *        2113 */
    sir = foo3(sca);             /*        2114 *       2114 *       2114 *        2114 */
    sir = foo4(ssa);             /*        2115 *       2115 *       2115 *        2115 */
    sir = foo5(pca);             /*        2116 *       2116 *       2116 *        2117 */

    sir = foo6(fta);             /*        2118 *       2118 *       2118 *        2118 */

    return;
}
