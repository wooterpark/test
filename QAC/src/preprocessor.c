/********************************************************************************************

PREPROCESSOR STATEMENTS

********************************************************************************************/

#pragma PRQA_MESSAGES_OFF 0553
#pragma PRQA_MESSAGES_OFF 2754
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3122
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3204
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3409
#pragma PRQA_MESSAGES_OFF 3410
#pragma PRQA_MESSAGES_OFF 3429
#pragma PRQA_MESSAGES_OFF 3432
#pragma PRQA_MESSAGES_OFF 3452


/*****************************************************************
:3118  Using the #line preprocessing directive.
*****************************************************************/
#line 20                                                /* 3118 */
#pragma PRQA_MESSAGES_OFF 3118



/*****************************************************************
:3104  [S] #pragma '%s' has invalid arguments and has been ignored.
*****************************************************************/
#pragma PRQA_MESSAGES_OFF 111111                        /* 3104 */


/*****************************************************************
:0830  [E] Unrecognized text encountered after a preprocessing directive.
:0864  [U] '#line' directive specifies line number which is not in the range 1 to 32767.
:0865  [U] '#line' directive is badly formed.
:0867  [U] '#line' has not been followed by a line number.
*****************************************************************/

#line 100000                                            /* 0864 */
#line ABC                                               /* 0830 0867 */
#line 100   DEF                                         /* 0830 0865 */


/*****************************************************************
:0880  Using # and ## operators in the same macro definition.
:0881  Using multiple ## operators in the same macro definition.
:0884  Using multiple # operators in the same macro definition.
*****************************************************************/

#define NAME(FIRST, SECOND) FIRST ## SECOND
#define SUM(NAME1,NAME2) NAME1 ## + NAME2
#define FULL(NAME1,NAME2,NAME3) NAME1 ## NAME2 ## NAME3 /* 0881 */
#define DEBUG(S) printf("us" #S "=%d\n", us ## S)       /* 0880 3435 */
#define FOO1(X,Y)    #X #Y                              /* 0884 */



/*****************************************************************
:0879  [S] Illegal operator in '#if' or '#elif' expression.
:0887  [U] Use of 'defined' must match either 'defined(identifier)' or 'defined identifier'.
:0885  [U] The token 'defined' is generated in the expansion of this macro.
*****************************************************************/

#if defined [FERGY]                                     /* 0879 0887 0897 3332 */
#endif

#define X 1
#define Y !defined((X))

#if (Y)                                                 /* 0885 0888 0898 */
#endif


/*****************************************************************
:0841  Using '#undef'.
*****************************************************************/
#define DUMMY
#undef DUMMY                                            /* 0841 */


/*****************************************************************
:0887  [U] Use of 'defined' must match either 'defined(identifier)' or 'defined identifier'.
:0888  [U] 'defined' requires an identifier as an argument.
:0889  #undef refers to a macro that has previously been #undef'd.
:0891  #ifdef refers to a macro that has been #undef'd previously.
:0897  [S] Missing operator in '#if' or '#elif' expression.
*****************************************************************/
#if defined (%)                                         /* 0888 */
#endif
#undef DUMMY                                            /* 0889 0841 */

#ifdef DUMMY                                            /* 0891 */
#endif

#define DUMMY


/*****************************************************************
:0841  Using '#undef'.
:0890  #ifdef refers to a macro that has been #undef'd in a previous #if block.
*****************************************************************/
#if 1
#undef DUMMY                                            /* 0841 */
#ifdef DUMMY                                            /* 0890 */
#endif
#endif


/*****************************************************************
:3115  Unrecognized preprocessing directive has been ignored because of conditional inclusion directives.
*****************************************************************/
#if 1 == 0
#RHUBARB CUSTARD                                        /* 3115 */
#endif


/*****************************************************************
:3116  Unrecognized #pragma arguments '%s' This #pragma directive has been ignored.
:3117  Expected 'on' or 'off' after '#pragma' flag.
*****************************************************************/
#pragma system_call on
#pragma system_call not_on                              /* 3117 */
#pragma non-portable off                                /* 3116 */



/*****************************************************************
:0872  [U] Result of '##' operator is not a legal preprocessing token.
*****************************************************************/
int foo(void)
{
    int  NAME(Bill, Clinton) = 1;
    int  NAME(George, Bush) = 2;
    int  FULL(George, W, Bush) = 3;
    int  usa;

    usa = BillClinton + GeorgeBush;

    usa = NAME(Bill, Clinton) + NAME(George, Bush);

    /* The following statement contains illegal usage of the ## operator
       because the combination of BillClinton and + is not a valid "token"
       and the behaviour is undefined according to ISO 6.8.3.3
       QAC warning 872 is generated along with several other warnings. */

    usa = SUM(BillClinton, GeorgeBush);                 /* 0872 */

    return usa;
}

/*****************************************************************
:3616  Character constants may have different values in preprocessor arithmetic than in actual code.
*****************************************************************/
#if 'a'==43                                             /* 3616 */
#endif


/*****************************************************************
:1690  Null preprocessing directive used.
:1691  Null preprocessing directive used in an excluded section of code.
*****************************************************************/
#                                                       /* 1690 */

#if 0
#                                                       /* 1691 */
#endif
