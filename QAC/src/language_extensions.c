/********************************************************************************************

LANGUAGE EXTENSIONS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0288
#pragma PRQA_MESSAGES_OFF 0289
#pragma PRQA_MESSAGES_OFF 0292
#pragma PRQA_MESSAGES_OFF 0861
#pragma PRQA_MESSAGES_OFF 1277
#pragma PRQA_MESSAGES_OFF 1278
#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 2209
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 2986
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3122
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3204
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3210
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3218
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3232
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3429
#pragma PRQA_MESSAGES_OFF 3435
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3453
#pragma PRQA_MESSAGES_OFF 3604


/***************************************************************
:1030  [C99] Macro defined with variable argument list.
***************************************************************/

#define debug(...) fprintf(stderr, __VA_ARGS__)                        /* 1030 */
#define showlist(...) puts(#__VA_ARGS__)                               /* 1030 */
#define report(test, ...) ((test)?puts(#test):printf(__VA_ARGS__))     /* 1030 */
#define print(text, ...) printf("%s, %d\n", text, __VA_ARGS__)         /* 1030 */

/*********************************************************************
:1028  [E] Use of the sizeof operator in a preprocessing directive is a language extension.
*********************************************************************/

#if  (sizeof(int) == 2)                                                /* 1028 */
#define SMALL
#endif


/*********************************************************************
:1029  [E] Whitespace encountered between backslash and new-line has been ignored.
*********************************************************************/

/* If the -ex sl option is enabled ...,
    1. The space character following \ will be ignored
    2. Message 1029 will be generated.
    3. "#define MYMACRO" will become part of the definition of TEST
    4. Macro MYMACRO will not be defined.

   If the -ex sl option is not enabled,
    1. The \ character will not be treated as a line splicing token
    2. Macro MYMACRO will be defined
    3. The #error directive will be activated

*/

#define TEST SOMETHING \
#define MYMACRO

#ifdef MYMACRO
#error Whitespace after \ was not ignored !
#endif



/*********************************************************************
:1019  [E] '@ address' is not supported in ISO C - this will be treated as a language extension.

The character "@" is sometimes used to introduce a memory address when
declaring non-standard types used as special function registers.
*********************************************************************/
unsigned int PORTA @0x1234;             /* 1019 */

unsigned int PORTB @2345;               /* 1019 */


/*********************************************************************
:1026  [E] The indicated @word construct has been ignored.

The character "@" is often used to introduce a non-standard keyword.
The @ character and keyword will be ignored by QAC if the keyword is
redefined as the macro "_ignore_at" or "_munch_at". Typically the
macro will be defined using a configuration option; in the following
code the macros are defined explicitly. In the absence of these
macro definitions, syntax errors will be generated.
*********************************************************************/
#define tiny _munch_at
#define interrupt _ignore_at

@tiny    int mask;                      /* 1026 */

@interrupt int foo5 (void)              /* 1026 */
{
    return(1);
}

/*********************************************************************
:1006  [E] This in-line assembler construct is a language extension. The code has been ignored.
:1003  [E] '#%s' is a language extension for in-line assembler. All statements located between #asm and #endasm will be ignored.
:3006  This function contains a mixture of in-line assembler statements and C statements.

-ex asm
   This option will enable a number of inline assembler constructs
   to be parsed and ignored.
   1. The keywords asm and __asm used in the declaration of
      a function will cause that function to be ignored.
   2. Assembler code blocks introduced by the keywords asm and
      __asm will be ignored.
   3. Blocks of statements enclosed between the directives
      #asm and #endasm will be ignored.
   4. In-line assembler statements of the form asm(...); will be
      igonored

*********************************************************************/
asm (Some assembler at file scope);     /* 1006 */

asm int foo4a(void);                    /* 1006 */

int asm foo4b(void);                    /* 1006 */

asm int foo4c(void)                     /* 1006 */
{
    All statements will be ignored in
    the body of this function.
}

int asm foo4d(void)                     /* 1006 */
{
    All statements will be ignored in
    the body of this function.
    return 1;
}

int __asm foo4e(void)                   /* 1006 */
{
    All statements will be ignored in
    the body of this function.
    return 1;
}

int foo4f(int a)                        /* 3006 */
{
    int r;

    r = a + 1;

    asm { int 3 }                       /* 1006 */

    __asm { int 3 }                     /* 1006 */

    asm(Assembler Statements);          /* 1006 */

#asm                                    /* 1003 */

    Any assembler statements
    will be ignored in this block

#endasm                                 /* 1003 */

    return r;
}



/*********************************************************************
:1015  [E] '%s' is not a legal keyword in ISO C - this will be treated as a language extension.

The PC extensions option will permit various extension
keywords to be used in identifier declarations.

*********************************************************************/

near    int * ppcni;                    /* 1015 */
far     int * ppcfi;                    /* 1015 */
huge    int * ppchi;                    /* 1015 */
cdecl   int * ppccd;                    /* 1015 */
pascal  int * ppcpasci;                 /* 1015 */
fortran int * ppcforti;                 /* 1015 */



/*********************************************************************
:1015  [E] '%s' is not a legal keyword in ISO C - this will be treated as a language extension.

The ANSIPC extensions option will permit various extension
keywords to be used in identifier declarations.

*********************************************************************/

__near    int * xsopni;                 /* 1015 */
__far     int * xsopfi;                 /* 1015 */
__huge    int * xsophi;                 /* 1015 */
__cdecl   int * xsopcd;                 /* 1015 */
__pascal  int * xsoppasci;              /* 1015 */
__fortran int * xsopforti;              /* 1015 */



/*********************************************************************
:1002  [E] '%s' is not a legal identifier in ISO C.

A $ character in an identifier is normally treated as an illegal
character and a syntax error will be generated.
If the dollar extensions option is enabled (-ex dollar), the
character will be parsed as a legitimate identifer character.
Message 1002 will be generated.
*********************************************************************/

int vms$identifier;                     /* 1002 */





void foo6 (int x)
{
    int       r;


/*********************************************************************
:1027  [C99] Use of type 'long long'.
:1018  [C99] Use of LL suffix.

Messages 1027 & 1018 will be generated if the "long long"
extensions option is not enabled (-ex longlong)

*********************************************************************/
    long long lla;                      /*      */ /* 1027 will be generated if -ex longlong not enabled */

    lla = 12345LL;                      /*      */ /* 1018 will be generated if -ex longlong not enabled */


/*********************************************************************
:1011  [C99] Use of '//' comment.

C++ style comments (introduced by //) will generate message 1011
unless the C++ extensions option is enabled (-ex C++)
*********************************************************************/
    r = x + 1;                          /*      */  // 1011 will be generated if -ex C++ is not enabled */

    return;
}

/*********************************************************************
:1031  [C99] Initializer for 'struct', 'union' or array type is not a constant expression.
*********************************************************************/

void foo7(int va)
{
    struct stag
    {
        int x;
        int y;
    } st = { 0x00, va };               /* 1031 */
}

/*********************************************************************
C99 inline keyword
:1055  [C99] The keyword 'inline' has been used.
:3228 Storage class specifier not positioned at the beginning of declaration.
:3244  [C] 'inline' may only be used in the declaration of a function identifier.
:3240  inline function 'func' is being defined with external linkage.  
*********************************************************************/

static int internal=0;

inline static void foo8(void)          /* 1055 3228 */
{
}

void foo9(void)
{
    inline int i=0;                    /* 1055 3244 */
}

inline void foo10(void)                /* 1055 3240 */
{
    static int x=0;                    /* 3237 */
}

inline int foo11(void)                 /* 1055 3240 */
{
    return internal;                   /* 3238 */
}

/*********************************************************************
C99 _Bool keyword
:1056 [C99] The keyword '_Bool' has been used.
*********************************************************************/

_Bool foo12(_Bool x)
{
    return x;                          /* 1056x2 */
}

/*********************************************************************
GCC #include_next preprocessor directive
:1045 [E] Use of the #include_next preprocessing directive is a language extension.
*********************************************************************/

#include_next <xample.h>               /* 1045 */ 
#include_next "top.h"                  /* 1045 */
