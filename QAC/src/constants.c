/********************************************************************************************

CONSTANTS

********************************************************************************************/

#pragma PRQA_MESSAGES_OFF 0753
#pragma PRQA_MESSAGES_OFF 0842
#pragma PRQA_MESSAGES_OFF 1256
#pragma PRQA_MESSAGES_OFF 1257
#pragma PRQA_MESSAGES_OFF 1269
#pragma PRQA_MESSAGES_OFF 1277
#pragma PRQA_MESSAGES_OFF 1278
#pragma PRQA_MESSAGES_OFF 1279
#pragma PRQA_MESSAGES_OFF 1290
#pragma PRQA_MESSAGES_OFF 1305
#pragma PRQA_MESSAGES_OFF 2201
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3207
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3409
#pragma PRQA_MESSAGES_OFF 3429
#pragma PRQA_MESSAGES_OFF 3433
#pragma PRQA_MESSAGES_OFF 3434
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3603
#pragma PRQA_MESSAGES_OFF 3606
#pragma PRQA_MESSAGES_OFF 3621
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 4542


#include "xample.h"

#define S "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"


void constant ( void )
{

/*****************************************************************************
:3120  Hard-coded 'magic' integer constant, '%s'.
:3121  Hard-coded 'magic' floating constant, '%s'.
:3122  Hard-coded 'magic' string literal, %s.
:3123  Hard coded 'magic' character constant, %s.
:3131  Hard coded 'magic' number, '%s', used to define the size of a bit-field.
:3132  Hard coded 'magic' number, '%s', used to define the size of an array.
******************************************************************************/

    int                  lsia  = 5;             /* 3120 */
    const int            lsib  = 5;             /*      */
    float                lfta  = 3.5F;          /* 3121 */
    const float          lftb  = 3.5F;          /*      */
    char                *lppca = "abc";         /* 3122 */
    const char          *lppcb = "abc";         /*      */
    char                 luca  = 'a';           /* 3123 */
    const char           lucb  = 'a';           /*      */
    struct Ast { unsigned int a:3; };           /* 3131 */
    char                 lbuf[100];             /* 3132 */


#pragma PRQA_MESSAGES_OFF 3120

/*****************************************************************************
:0875  [L] String literal exceeds 509 characters - program does not conform strictly to ISO:C90.
:3003  This token is a suspicious NULL pointer constant.
******************************************************************************/

    const char          *lppcc = S S S S S S;   /* 0875 */
    const char          *lppcd = '\0';          /* 3003 */



/*****************************************************************************
SINGLE and DOUBLE QUOTE characters in constants

:3626  Double-quote character in a character constant is not preceded by a backslash character.
:3627  Single-quote character in a string literal is not preceded by a backslash character.

******************************************************************************/

    const char          *lppci = "AB'C";        /* 3627 */
    const char           lpca  = '"';           /* 3626 */



/*****************************************************************************
OCTAL and BINARY constants

:0246  [E] Binary integer constants are a language extension.
:0336  Macro defined as an octal constant.
:0339  Octal constant used.
:3628  Octal escape sequences used in a character constant or string literal.
:3613  Some pre-ISO compilers would treat this 8 or 9 as an octal digit.

******************************************************************************/

#define M1 0160                                 /* 0336 */
#define M2 (0160)                               /* 0336 */
#define M3 0                                    /*      */
#define M4 0x0160                               /*      */
#define M5 (0123 | M1)                          /*      */

    int                  x1 = M1;               /*      */
    int                  x2 = M2;               /*      */
    int                  x3 = M3;               /*      */
    int                  x4 = M4;               /*      */
    int                  x5 = M5;               /*  339 */
    int                  lsibin = 0b10101;      /* 0246 */
    int                  lsioct = 0123;         /* 0339 */
    const char          *lppce  = "AB\176C";    /* 3628 */
    const char          *lppcg  = "AB\179C";    /* 3628 3613 */




/*****************************************************************************
INTEGER LITERALS WITH MISSING SUFFIX

:1255  Unsuffixed integer constant is not of type int.
   Integer constants which are NOT of type int but have NO SUFFIX.
   The addition of a suffix would make the type explicit

:1254  Suffix is not consistent with a type of unsigned long.
   Integer constants which do not have the most appropriate suffix.
   All are of type unsigned long but do not have a UL suffix

:1281  Integer literal constant is of an unsigned type but does not include a "U" suffix.

******************************************************************************/

    uxa = 2147483647;                           /*            */
    uxa = 2147483648;                           /* 1255       */
    uxa = 2147483648ULL;                        /*            */
    uxa = 0x7FFFFFFF;                           /*            */
    uxa = 0x80000000;                           /* 1255, 1281 */
    uxa = 0x80000000ULL;                        /*            */
    uxa = 2147483648L;                          /* 1254       */
    uxa = 2147483648U;                          /*            */
    uxa = 2147483648UL;                         /*            */
    uxa = 0x80000000L;                          /* 1254, 1281 */
    uxa = 0x80000000U;                          /*            */
    uxa = 0x80000000UL;                         /*            */
    ula = 0x80000000L;                          /* 1254, 1281 */





/*****************************************************************************
INTEGER CONSTANTS WITH LEADING ZEROES

:1272  Redundant leading zeroes on a numeric constant.

******************************************************************************/

    uia = 0x00000001U;                          /*      */
    uia = 0x000000001U;                         /* 1272 */

    ula = 0x00000001UL;                         /*      */
    ula = 0x000000001UL;                        /* 1272 */

    uxa = 0x0000000000000001ULL;                /*      */
    uxa = 0x00000000000000001ULL;               /* 1272 */

}
