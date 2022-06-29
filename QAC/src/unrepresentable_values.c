/********************************************************************************************

UNREPRESENTABLE VALUES

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 1277
#pragma PRQA_MESSAGES_OFF 1278
#pragma PRQA_MESSAGES_OFF 2753
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 3103
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3121
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408

#include "xample.h"


void unr_constants(void)
{

/******************************************************************

Constants that are not representable

:0580  [C] Constant is too large to be representable.
:0581  [I] Floating-point constant may be too small to be representable.

Constants must be representable within their type.

A floating literal constant must be representable within the type
determined by its suffix (or the absence of one).

The type of an integer literal constant is determined by its magnitude
as well as suffixes. It must always be representable within the largest
available unsigned type (long or long long if the appropriate extension is enabled).

Notice that the type of a literal constant is NOT determined by the type of
an object to which the constant may be assigned.

The messages indicated below will be obtained if long long extensions are
enabled and the size of long long is configured as 64 bits.

******************************************************************/

    uxa = 18446744073709551615ULL;                      /*           */
    uxa = 18446744073709551616ULL;                      /* 0580 0580 */

    fta = 1.17549435E-38F;
    fta = 1.17549434E-38F;                              /* 0581      */

    fta = 3.40282347E38F;
    fta = 3.40282348E38F;                               /* 0580      */

    lda = 2.2250738585072014E-308L;
    lda = 2.2250738585072013E-308L;                     /* 0581      */

    lda = 1.7976931348623157E308L;
    lda = 1.7976931348623158E308L;                      /* 0580      */

    lda = 2.2250738585072014E-308L;
    lda = 2.2250738585072013E-308L;                     /* 0581      */

    lda = 1.7976931348623157E308L;
    lda = 1.7976931348623158E308L;                      /* 0580      */

}
