/********************************************************************************************

NULL STATEMENTS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0344
#pragma PRQA_MESSAGES_OFF 0345
#pragma PRQA_MESSAGES_OFF 1011
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2201
#pragma PRQA_MESSAGES_OFF 2203
#pragma PRQA_MESSAGES_OFF 2205
#pragma PRQA_MESSAGES_OFF 2212
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2214
#pragma PRQA_MESSAGES_OFF 2215
#pragma PRQA_MESSAGES_OFF 2461
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3412
#pragma PRQA_MESSAGES_OFF 3416
#pragma PRQA_MESSAGES_OFF 3431
#pragma PRQA_MESSAGES_OFF 3602


/************************************************************************
:3140  Null statement occurs on a line by itself.
:3141  Null statement does not occur on a line by itself.
:3109  Null statement follows other code on the same line.
:3138  Null statement is located close to other code or comments.
:3139  Null statement is obscured by code or comment on the same line.

Message 3139 is generated whenever a NULL statement is detected, EXCEPT when:

1) the NULL statement follows expansion of a macro which terminates with a "}" or
2) the NULL statement follows expansion of a macro which terminates with a ";"
3) the NULL statement is on a line by itself (before preprocessing) , or
4) the NULL statement follows expansion of an empty macro on the same line
5) the NULL statement follows expansion of an empty macro on the same line, and the line includes comments.

NOTES:
======
When an empty statement (;) is found
   if ; is alone on the line with only spaces before and after, message 3140 is generated
   else, if the are some "code tokens" (non comments) before ; then message 3109 is generated
   else message 3141 is generated

************************************************************************/

#define NOTHING
#define BRACES {}
#define SCOLON ;
#define SCOLON2 ;;

extern void nullst(int n)
{
    int i;



/*********************************************************************************
No messages are generated for the following null statements
Null statements within a macro are not detected
*********************************************************************************/

    SCOLON
    SCOLON2 SCOLON2
    SCOLON SCOLON

/************************************************************************
:3140  Null statement occurs on a line by itself.

       Generated when the null statement is not PRECEDED or FOLLOWED by any tokens
************************************************************************/
#pragma PRQA_MESSAGES_OFF 3109,3138,3139,3141

    /* 3140 is generated on the following lines */

    ;


    /* 3140 is NOT generated on the following lines */

    SCOLON
    SCOLON2
    ; NOTHING
    NOTHING ;
    ; /* ... */
    /* ... */ ;

#pragma PRQA_MESSAGES_ON 3109,3138,3139,3141

/*********************************************************************************
:3109  Null statement follows other code on the same line.

       Generated when the null statement is PRECEDED on the same by "code" or a "non-null" macro
********************************************************************************/
#pragma PRQA_MESSAGES_OFF 3138,3139,3140,3141

    /* 3109 is generated on the following lines */

    if (n == 1);
    if (n == 2) /* ... */  ;
    if (n == 3)
    {
    };
    for (i = 0; i < n; ++i);
    {};
    ;NOTHING;
    BRACES;
    BRACES /* ... */ ;
    SCOLON;
    SCOLON /* ... */;
    ;;
    ; /* ... */ ;
    /* ... */ ;;  /* ... */


    /* 3109 is NOT generated on the following lines */

    ; i = 1;
    ;for (i = 0; i < n; ++i)
    {
    }
    NOTHING;
    NOTHING; i = 1;
    ;NOTHING
    ;BRACES
    SCOLON
    SCOLON2
    ;SCOLON
    NOTHING SCOLON
    BRACES SCOLON

    /* ... */ NOTHING; /* ... */
    /* ... */ ;NOTHING /* ... */
    /* ... */ ;BRACES /* ... */
    /* ... */ SCOLON /* ... */
    /* ... */ ;SCOLON /* ... */
    /* ... */ NOTHING SCOLON /* ... */
    /* ... */ BRACES SCOLON /* ... */


#pragma PRQA_MESSAGES_ON 3138,3139,3140,3141

/*********************************************************************************
:3141  Null statement does not occur on a line by itself.

       Generated when a null statement is FOLLOWED by
         a) code tokens
         b) null macros
         c) comments
*********************************************************************************/
#pragma PRQA_MESSAGES_OFF 3109,3138,3139,3140

    /* 3141 is generated on the following lines */

    ; if (n == 1) {}
    ; for (i = 0; i < n; ++i) { }
    ; i = 1;
    ; {}
    ;;
    ; /* ... */
    /* ... */ ;
    ;NOTHING
    NOTHING;
    ;BRACES
    ;SCOLON


    /* 3141 is NOT generated on the following lines */

    if (n == 1) {} ;
    for (i = 0; i < n; ++i) { } ;
    for (i = 0; i < n; ++i);
    i = 1; ;
    {};
    {};
    /* ... */ {};
    BRACES;
    SCOLON;
    SCOLON2;
    NOTHING SCOLON
    BRACES SCOLON


#pragma PRQA_MESSAGES_ON 3109,3138,3139,3140


/*********************************************************************************
:3139  Null statement is obscured by code or comment on the same line.

       Used to implement TOYOTA's specific requirements

       Generated whenever a null statement is encountered unless:
       a) it is in a line on its own
       b) it follows a macro terminated with } or ;
       c) it follows a blank macro
*********************************************************************************/
#pragma PRQA_MESSAGES_OFF 3109,3138,3140,3141

    /* Message 3139 is generated on the following lines */
    ;i = 1;
    i = 1;;
    if (n == 1);
    if (n == 2) /* ... */  ;
    {};
    for (i = 0; i < n; ++i);
    ;for (i = 0; i < n; ++i)
    ;NOTHING
    ;BRACES
    ;SCOLON
    /* ... */ ;
    ;  /* ... */


/*********************************************************************************
   Message 3139 is NOT generated for the following null statements because either

       a) it is in a line on its own or
       b) it follows a macro terminated with } or ;
       c) it follows a blank macro
*********************************************************************************/

    ;

    NOTHING;
    NOTHING /* ... */;
    NOTHING; /* ... */
    /* ... */ NOTHING;

    BRACES;
    BRACES; /* ... */
    /* ... */ BRACES;
    BRACES SCOLON

    SCOLON ;
    /* ... */ SCOLON; /* ... */

#pragma PRQA_MESSAGES_ON 3109,3138,3140,3141



/*********************************************************************************
:3138  Null statement is located close to other code or comments.

MISRA RULE 14.3
===============
"Before preprocessing, a null statement shall only occur on a line by itself; it may be followed by a comment
provided that the first character following the null statement is a white-space character"

       Generated whenever a null statement is encountered if the line also contains:
       a) Code tokens or non-null macros
       b) Comments which are not separated from the ; by whitespace
*********************************************************************************/
#pragma PRQA_MESSAGES_OFF 3109,3139,3140,3141

    /* Message 3138 is generated on the following lines */

    ;i = 1;
    i = 1;;
    {};
    ;/* ... */
    /* ... */;
    /* ... */ ;
    ;//
    if (n == 1);
    if (n == 2) /* ... */  ;
    for (i = 0; i < n; ++i);
    ;for (i = 0; i < n; ++i)
    ;BRACES
    BRACES;
    BRACES; /* ... */
    ;SCOLON
    /* ... */;
    ;/* ... */
    /* ... */ ;
    /* A Comment */ ; /* Not compliant, comment before semi-colon */
    ;/* Not compliant, no white-space char after semi-colon */


    /* Message 3138 is NOT generated for the following null statements */

    ;
    ; /* Compliant */
    ; /* ... */


#pragma PRQA_MESSAGES_ON 3109,3138,3139,3140,3141

    return;
}
