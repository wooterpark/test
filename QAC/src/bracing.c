/********************************************************************************************

BRACING

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2461
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 2986
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3132
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3204
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3352
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3450
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3604


extern int a;

void bracing( const int n )
{
    int i;

/********************************************************************************************

:2213  Matching braces appear on the same line - proper indentation would be preferred.

********************************************************************************************/

    int buf[3] = {1, 2, 3};             /* 2213 */


/********************************************************************************************

:2209  This brace style is not consistent with 'exdented' style.

       N.B. The generation of messages 2207-2209 depends on the setting of the -style
       configuration option.

********************************************************************************************/

    if (a > 0) {                        /* 2209 */
        --a;
    }

/********************************************************************************************

:2212  Body of control statement is not enclosed within braces.
:2214  Body of control statement is on the same line and is not enclosed within braces.

********************************************************************************************/

    while (a > 20)
        --a;                            /* 2212 */

    while (a > 10) --a;                 /* 2214 */

    if ( a > 5 )
        a = 4;                          /* 2212 */

    if ( a > 3 ) a = 2;                 /* 2214 */

    for (i = 0; i < n; ++i)
        ++a;                            /* 2212 */

    for (i = 0; i < n; ++i) ++a;        /* 2214 */


/********************************************************************************************

:2204  '%s' is not aligned to match its controlling 'switch' statement.

********************************************************************************************/


    switch (n)
    {
        case 1:                         /* 2204 */
        i = 1;
        break;

        default:                        /* 2204 */
        i = 2;
        break;
    }


/********************************************************************************************

:3402  Braces are needed to clarify the structure of this 'if'-'if'-'else' statement.

********************************************************************************************/

    if (n != 0)                         /* 3402 */
        if (a > 0)                      /* 2212 */
        {
            i = 1;
        }
    else
    {
        i = 2;
    }

    return;


/********************************************************************************************

:2203  This closing brace is not aligned appropriately with the matching opening brace.

********************************************************************************************/

 }                                      /* 2203 */
