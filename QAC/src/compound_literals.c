/********************************************************************************************

COMPOUND LITERALS

********************************************************************************************/

#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2216
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 2986
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3122
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3604
#pragma PRQA_MESSAGES_OFF 3617
#pragma PRQA_MESSAGES_OFF 3625



/********************************************************
:1054  [C99] A compound literal has been used.
*********************************************************/

struct ST8 { int a; int b; };


void f1(void)
{
    const char **pcca;
    struct ST8 st8a;

    pcca = (const char *[]) {"xyz"};      /* 1054 */
    st8a = (struct ST8) { 1, 2 };         /* 1054 */
}
