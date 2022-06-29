/********************************************************************************************

FUNCTIONS DECLARATIONS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2753
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3204
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3206
#pragma PRQA_MESSAGES_OFF 3210
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 4702


/******************************************************************************************
ISO STYLE PROTOTYPE DEFINITIONS
******************************************************************************************/

extern int func2(int a, int b);
extern int func3(int x, int y);
extern int func12(int a);

/******************************************************************************************
:1335  Parameter identifiers missing in function prototype declaration.
:1336  Parameter identifiers missing in declaration of a function type.
******************************************************************************************/
extern int func11(int  , int  );              /* 1335 */

extern void (* const pvf)(int);               /* 1336 */

/******************************************************************************************
:1330  The parameter identifiers in this function declaration differ from those in a previous declaration.
:1334  The parameter identifiers in the prototypes of these functions/function pointers are different.
******************************************************************************************/
int func3(int a, int b)                       /* 1330 */
{
    int (* const pf)(int x, int y) = &func2;  /* 1334 */

    return a + b;
}


/******************************************************************************************
K&R STYLE FUNCTION DECLARATIONS AND DEFINITIONS
******************************************************************************************/


/*****************************************************************************
:1304  Old style definition of function '%s()' is not portable to C++.
:3002  Defining '%s()' with an identifier list and separate parameter declarations is an obsolescent feature.

Messages 1304 and 3002 are functionally identical

******************************************************************************/

int func4(a, b)                                 /* 1304 3002 */
int a;
int b;
{
    return a + b;
}


/*****************************************************************************
:3001  Function has been declared with an empty parameter list.
:1303  An empty parameter list in a function type has a different meaning in C++.
:3007  "void" has been omitted when defining a function with no parameters.

******************************************************************************/

extern int func1();                     /* 3001 1303 */

int func10()                            /* 1303      */
{                                       /* 3007      */
    return 1;
}


struct st1 { int x;};
struct st2 { long x;};


extern int func6(struct st1 s);

extern int func7(struct st2 s);

int foo(int sia, long slb, struct st1 s1, struct st2 s2, struct st3 s3) /* 3313 */
{
/*****************************************************************************
:3671  Function called via pointer to function.
:3672  Using non-const pointer to function.

Note alternative ways of using a function pointer
******************************************************************************/

    int (* const fp1)(void) = &func1;
    int (*       fp2)(void) = &func1;   /* 3672 */
    int r;

    r = fp1();                          /* 3671 */
    r = (*fp1)();                       /* 3671 */
    r = fp2();                          /* 3671 */


/*****************************************************************************
Wrong number of arguments

:0422  [C] Function call contains fewer arguments than prototype specifies.
:0423  [C] Function call contains more arguments than prototype specifies.
:3319  [U] Function called with number of arguments which differs from number of parameters in definition.

func2 is declared with a full prototype
func3 is declared with a full prototype and defined in ISO style
func4 is defined  with an old style function header

******************************************************************************/

    r = func2(sia);                     /* 0422 */
    r = func3(sia);                     /* 0422 */
    r = func4(sia);                     /* 3319 */

    r = func2(sia, 0, 0);               /* 0423 */
    r = func3(sia, 0, 0);               /* 0423 */
    r = func4(sia, 0, 0);               /* 3319 */


/*****************************************************************************
Wrong argument type

:3320  Type of argument no. %s differs from its type in definition of function.

func3 is ISO defined as "extern int func3(int x, int y);"
func4 is old-style defined  as "int func4(a, b) int a; int b;"
******************************************************************************/

    r = func3(sia, slb);                /* Implicit cast message */
    r = func4(sia, slb);                /* 3320 */


/*****************************************************************************
Missing declarations

:1302  '%s()' must be declared before use in C++.
:3335  No function declaration. Implicit declaration inserted: 'extern int %s();'.

Messages 1302 and 3335 are functionally identical
******************************************************************************/

    r = func5(sia);                     /* 1302 3335 */


/*****************************************************************************
Confusion over type or number of arguments

:1302  '%s()' must be declared before use in C++.
:1331  Type or number of arguments doesn't match previous use of the function.
:1332  Type or number of arguments doesn't match prototype found later.
:1333  Type or number of arguments doesn't match function definition found later.
:3335  No function declaration. Implicit declaration inserted: 'extern int %s();'.

******************************************************************************/
    r = func5(slb);                     /* 1331 */
    r = func5(sia, slb);                /* 1331 */
    r = func8(sia);                     /* 1302 1332 3335 */
    r = func9(sia);                     /* 1302 1333 3335 */


/*****************************************************************************
:0430  [C] Function argument is not of compatible 'struct'/'union' type.
:3623  Passing a struct/union by value as a function argument.
:0541  [C] Argument no. %s does not have object type.
:3623  Passing a struct/union by value as a function argument.
:3313  No definition has been found for structure/union tag '%s'.
******************************************************************************/
    r = func6(s1);                      /* 3623 */
    r = func7(s1);                      /* 3623 0430 */
    r = func6(s3);                      /* 3623 0430 0541 */

    return(r);
}



extern int func8(long x, int y);

int func9(long x, int y)
{
    return 1;
}


extern int func11(int a, int b)
{
    return (a + b);
}


/*****************************************************************************
:3675  Function parameter declared with type qualification which differs from previous declaration.
******************************************************************************/
extern int func12(const int a)          /* 3675 */
{
    return a;
}

/*****************************************************************************
:1337 Function defined with a variable number of parameters.
******************************************************************************/
extern int func13 (int a, ...)
{
    return a;
}

/*****************************************************************************
:3330  '%s()' has been called with a variable number of arguments.
******************************************************************************/
