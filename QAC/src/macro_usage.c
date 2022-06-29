/********************************************************************************************

MACRO USAGE

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0553
#pragma PRQA_MESSAGES_OFF 0881
#pragma PRQA_MESSAGES_OFF 0911
#pragma PRQA_MESSAGES_OFF 1252
#pragma PRQA_MESSAGES_OFF 1278
#pragma PRQA_MESSAGES_OFF 1302
#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 2201
#pragma PRQA_MESSAGES_OFF 2214
#pragma PRQA_MESSAGES_OFF 2215
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2753
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 3110
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3200
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3209
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3226
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3335
#pragma PRQA_MESSAGES_OFF 3401
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3409
#pragma PRQA_MESSAGES_OFF 3410
#pragma PRQA_MESSAGES_OFF 3417
#pragma PRQA_MESSAGES_OFF 3425
#pragma PRQA_MESSAGES_OFF 3429
#pragma PRQA_MESSAGES_OFF 3440
#pragma PRQA_MESSAGES_OFF 3446
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3450
#pragma PRQA_MESSAGES_OFF 3453
#pragma PRQA_MESSAGES_OFF 3454


/*************************************************************************
REDEFINING   MACROS

:0834  [C] Function-like macro '%s()' is being redefined as an object-like macro.
:0835  [C] Macro '%s' is being redefined with different parameter names.
:0844  [C] Macro '%s' is being redefined with a different replacement list.
:0845  [C] Object-like macro '%s' is being redefined as a function-like macro.
:3614  Macro '%s' is being defined more than once without using #undef to remove the previous definition.
*************************************************************************/

#define R1 1
#define R1 1                            /* 3614 */
#define R1 2                            /* 0844 3614 */

#define R2 1
#define R2 1                            /* 3614 */
#define R2(x) ((x) + 1)                 /* 0845 3614 */

#define R3(x) ((x) + 2)
#define R3(x) ((x) + 2)                 /* 3614 */
#define R3 1                            /* 0834 3614 */

#define R4(x,y) ((x) + (y))
#define R4(x,y) ((x) + (y))             /* 3614 */
#define R4(a,b) ((a) + (b))             /* 0835 3614 */




/*************************************************************************
HIDING OF IDENTIFIERS

:3436  Macro definition hides previously declared identifier.
*************************************************************************/

typedef int mode;
#define mode (type)                     /* 3436 */
int sic;
#define sic (y)                         /* 3436 */



/*************************************************************************
MISSING MACRO DEFINITION

:3332  The macro '%s' used in this '#if' or '#elif' expression is not defined.
*************************************************************************/

#if (MISSINGMAC == 1L)                  /* 3332 */
#define MISSINGMAC (2)
#endif



/*************************************************************************
:0836  [U] Definition of macro named 'defined'.
*************************************************************************/
#define defined 1                       /* 0836 */



/*************************************************************************
UNDEF'ING

:0841  Using '#undef'.
:0889  #undef refers to a macro that has previously been #undef'd.
:0837  [U] Use of '#undef' to remove the operator 'defined'.
*************************************************************************/
#define MAN 1
#undef  MAN                             /* 0841 */
#undef  MAN                             /* 0841 0889 */
#undef defined                          /* 0837 0841 */

#pragma PRQA_MESSAGES_OFF 0841


/*************************************************************************
:0848  [U] Attempting to #undef '%s', which is a predefined macro name.
:0854  [U] Attempting to #define '%s', which is a predefined macro name.
:3438  [U] #undef'ing the assert macro to call a function of that name causes undefined behaviour.
:4602  The identifier '%1s' is declared as a macro in '<%2s>'.
*************************************************************************/
#undef __LINE__                         /* 0848 */
#define __LINE__ 1                      /* 0854 0602 */
#undef assert                           /* 3438 */


extern void assert(int x);              /* 4602 */
extern int bar(int x);



#define BL1

#define MULTIPLY(x,y) (x * y)
#define A1(M)       x ## m = 1
#define A2(M, N)    x ## m ## n = 1
#define ADD(A,B,C,D) ((A) + (B) + (C) ) /*      */



static int foo(int a, int b, int i, int j, int k)
{
    int r;
    int x,xm,xn,xmn;

/*************************************************************************
MISSING ARGUMENTS

:0850  [C99] Macro argument is empty.
:0856  [C] Fewer arguments in macro call than specified in definition.
*************************************************************************/

    A1(m);                              /*      */
    A1( );                              /* 0850 */
    A2(m, n);                           /*      */
    A2(    );                           /* 0856 */


/*************************************************************************
:0853  [U] Macro arguments contain a sequence of tokens that has the form of a preprocessing directive.
*************************************************************************/

   r =     ADD(    5,                   /* 0907 0907 0434 0434 0434 */
#ifdef SW                               /* 0853 */
                   a,
#else                                   /* 0853 */
                   b,
#endif                                  /* 0853 */
                   0   );



/*************************************************************************
:0842  Using #define or #undef inside a function.
*************************************************************************/
#undef BL1                              /* 0842 */
#define BL2                             /* 0842 */
#undef BL2                              /* 0842 */
#define AM(X, Y) ((X) * (Y))            /* 0842 */


/*************************************************************************
:3430  Macro argument expression may require parentheses.
*************************************************************************/

    r = MULTIPLY(a + 1, b + 2);         /* 3430 3390 3395 */
    r = MULTIPLY(a, b);                 /*      */


/*************************************************************************
:3437  [u] The assert macro has been suppressed to call a function of that name.
*************************************************************************/
    assert(3);                          /* 3437 */


/**************************************************************
:3454  Macro argument contains an increment, decrement or assignment operator.
**************************************************************/
    r = AM(i++, j);                     /* 3454 */
    r = AM(i, j--);                     /* 3454 */
    r = AM(i = i + k, j);               /* 3454 */
    r = AM(i, j *= k);                  /* 3454 */

/**************************************************************
:3455  Macro argument contains a function call.
**************************************************************/
    r = AM(bar(i), j);                  /* 3455 */
    r = AM(i, bar(j));                  /* 3455 */
    r = AM(i + bar(j) + j, k);          /* 3455 */

    return(r);
}

/**************************************************************
Conditional Operator
:3491  Using conditional operator in a macro.
:3492  Using conditional operator outside a macro.
:3495  Using a conditional operator in place of a selection statement.
**************************************************************/

#define SELECT(a, b, c) ((a) ? (b) : (c))

int foo2 (int a)
{
  return SELECT (a < 0, 0, a);          /* 3491 */
}

int f003 (int a)
{
  return ((a < 0) ? 0 : a);             /* 3492 */
}


void foo4 (int a)
{
  SELECT (a > 0, --a, 0);               /* 3495 3491 */

  ((a > 0) ? --a : 0);                  /* 3495 3492 */

  if (a > 0)
  {
    --a;
  }
  else
  {
    /* no side effect */
  }
}

