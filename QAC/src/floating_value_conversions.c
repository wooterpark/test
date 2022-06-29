/********************************************************************************************

FLOATING VALUE CONVERSIONS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 1269
#pragma PRQA_MESSAGES_OFF 1277
#pragma PRQA_MESSAGES_OFF 1278
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3121
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408

#include "xample.h"


void floating_conversions (void)
{

/******************************************************************
CONVERSION OF FLOATING TYPES

Conversions of floating constants which do not fit in their destination type

:0275  [U] Floating value is out of range for conversion to destination type.

*******************************************************************/
    sca = (signed char)(128.0);                         /* 0275 */
    sca = (signed char)(-129.0);                        /* 0275 */

    ssa = (signed short)32768.0;                        /* 0275 */
    ssa = (signed short)(-32769.0);                     /* 0275 */

    sia = (signed int)2147483648.0;                     /* 0275 */
    sia = (signed int)(-2147483649.0);                  /* 0275 */

    sla = (signed long)(2147483648.0);                  /* 0275 */
    sla = (signed long)(-2147483649.0);                 /* 0275 */

    uca = (unsigned char)256.0;                         /* 0275 */

    usa = (unsigned short)65536.0;                      /* 0275 */

    uia = (unsigned int)4294967296.0;                   /* 0275 */

    ula = (unsigned long)4294967296.0;                  /* 0275 */

}
