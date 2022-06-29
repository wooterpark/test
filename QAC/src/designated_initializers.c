/********************************************************************************************

DESIGNATED INITIALIZERS

********************************************************************************************/

#pragma PRQA_MESSAGES_OFF 2203
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2216
#pragma PRQA_MESSAGES_OFF 3132
#pragma PRQA_MESSAGES_OFF 3210
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 3674

/******************************************************************************
:1053  [C99] Designators have been used in this initialization list.
*******************************************************************************/



int a11[4] = { [1] = 5, [3] = 7 };                                    /* 1053 */

int a21[ ] = { [0] = 1, [10] = 2, [30] = 3, [39] = 0 };               /* 1053 */

int aa01[][4] = { { [1]        = 5 },                                 /* 1053 */
                  { [3]        = 7 } };                               /*      */

int aa04[][4] = { [4]        = { [1]        = 5 },                    /* 1053 */
                  [6]        = { [3]        = 7 } };                  /*      */



struct S01 { int x; int y; int z; };

struct S01 gs01a = {.x = 1,.y = 2 };                                  /* 1053 */
struct S01 gs01xa[2] = { [0]={.y = 9}, [1]={.x = 7} };                /* 1053 */
