/********************************************************************************************

DEGENERATE COMPARISONS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0277
#pragma PRQA_MESSAGES_OFF 1253
#pragma PRQA_MESSAGES_OFF 1842
#pragma PRQA_MESSAGES_OFF 1862
#pragma PRQA_MESSAGES_OFF 2100-2107
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2212
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2890
#pragma PRQA_MESSAGES_OFF 2981
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2995
#pragma PRQA_MESSAGES_OFF 2996
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3197
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3355
#pragma PRQA_MESSAGES_OFF 3356
#pragma PRQA_MESSAGES_OFF 3358
#pragma PRQA_MESSAGES_OFF 3359
#pragma PRQA_MESSAGES_OFF 4403



enum colours {red = 1, blue = 2, green = 3};

int foo(
unsigned char  uca,
unsigned short usa,
unsigned int   uia,
enum colours col )
{
    int r = 0;


/******************************************************************************************
:1475  Range of possible enum values suggests this test is always true.
:1476  Range of possible enum values suggests this test is always false.

:3201  This statement is unreachable.

:3316  An unsigned value can never be less than zero - this test is always false.
:3324  An unsigned value is always greater than or equal to zero - this test is always true.
:3328  An unsigned value is being compared with a negative constant - this is dangerous.

******************************************************************************************/

    r = col <= green;           /* 1475 */

    r = col < red;              /* 1476 */

    r = uia < 0;                /* 3316 */

    r = uca >= 0;               /* 3324 */

    /* The unsigned char will be promoted to a signed int for the comparison
       Result always false */

    r = uca < - 10;             /* 3328 */

    /* The constant will be converted to a "large" unsigned int
       and the comparison will be performed in type unsigned int.
       Result may be true or false */

    r = uia < -10;              /* 3328 */


    /* In a 32 bit environment, usa will be promoted to signed int for the comparison
       Result always false

       In a 16 bit environment, usa will be promoted to unsigned int for the comparison
       Result may be true or false */

    r = usa < - 10;             /* 3328 */

    return(r);
}
