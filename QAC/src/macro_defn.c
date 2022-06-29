/********************************************************************************************

MACRO DEFINITION


Various macro types are recognised according to the tokens which they contain.

The ISO-C standard (6.1.1) defines a set of 32 "keywords".

These keywords can be further categorised as follows:
Storage class specifier:        static, extern, typedef, auto, register

Type qualifier:                 const, volatile

Type specifier keywords:        void, char, short, int, long, float, double,
                                signed, unsigned, struct, union, enum

Control statement keywords:     while, do, for, if, else, switch, case, default,
                                goto, return, break, continue

Operator keywords:              sizeof


The ISO-C standard also defines a range of operators (6.1.5):
                                [  ]  (  )  .  ->
                                ++  --  &  *  +  -  ~  !  sizeof
                                /  %  <<  >>  <  >  <=  >=  ==  !=  ^  |  &&  ||
                                ?  :
                                =  *=  /=  %=  +=  -=  <<=  >>=  &=  ^=  |=
                                , # ##

and a set of punctuators (6.1.6):
                                [  ]  (  )  {  }  *  ,  :  =  ;  ...  #

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 2017
#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3408


/******************************************************************

SINGLE TOKEN MACROS

:3414  Macro defines a storage-class specifier keyword.
:3428  Macro defines a type qualifier keyword.
:3460  Macro defines a type specifier keyword.

*******************************************************************/

#define SC1  static                             /* 3414 */
#define SC2  extern                             /* 3414 */
#define SC3  typedef                            /* 3414 */
#define SC4  auto                               /* 3414 */
#define SC5  register                           /* 3414 */


#define TQ1  const                              /* 3428 */
#define TQ2  volatile                           /* 3428 */


#define TD1  void                               /* 3460 */
#define TD2  char                               /* 3460 */
#define TD3  short                              /* 3460 */
#define TD4  int                                /* 3460 */
#define TD5  long                               /* 3460 */
#define TD6  float                              /* 3460 */
#define TD7  double                             /* 3460 */
#define TD8  signed                             /* 3460 */
#define TD9  unsigned                           /* 3460 */
#define TD10 struct                             /* 3460 */
#define TD11 union                              /* 3460 */
#define TD12 enum                               /* 3460 */


/*******************************************
SINGLE TOKEN MACROS

:3431  Macro defines an operator, a punctuator or a control statement keyword,

********************************************/

#define LK01     break                          /* 3431 */
#define LK02     case                           /* 3431 */
#define LK03     continue                       /* 3431 */
#define LK04     default                        /* 3431 */
#define LK05     do                             /* 3431 */
#define LK06     else                           /* 3431 */
#define LK07     for                            /* 3431 */
#define LK08     goto                           /* 3431 */
#define LK09     if                             /* 3431 */
#define LK10     return                         /* 3431 */
#define LK11     switch                         /* 3431 */
#define LK12     while                          /* 3431 */




#define OP01     [                              /* 3431 */
#define OP02     ]                              /* 3431 */
#define OP03     (                              /* 3431 */
#define OP04     )                              /* 3431 */
#define OP05     .                              /* 3431 */
#define OP06     ->                             /* 3431 */
#define OP07     ++                             /* 3431 */
#define OP08     --                             /* 3431 */
#define OP09     &                              /* 3431 */
#define OP10     *                              /* 3431 */
#define OP11     +                              /* 3431 */
#define OP12     -                              /* 3431 */
#define OP13     ~                              /* 3431 */
#define OP14     !                              /* 3431 */
#define OP15     sizeof                         /* 3431 */
#define OP16     ?                              /* 3431 */
#define OP17     :                              /* 3431 */
#define OP18     =                              /* 3431 */
#define OP19     *=                             /* 3431 */
#define OP20     /=                             /* 3431 */
#define OP21     %=                             /* 3431 */
#define OP22     +=                             /* 3431 */
#define OP23     -=                             /* 3431 */
#define OP24     <<=                            /* 3431 */
#define OP25     >>=                            /* 3431 */
#define OP26     &=                             /* 3431 */
#define OP27     ^=                             /* 3431 */
#define OP28     |=                             /* 3431 */
#define OP29     ,                              /* 3431 */
#define OP30     #                              /* 3431 */
#define OP32     {                              /* 3431 */
#define OP33     }                              /* 3431 */
#define OP34     ...                            /* 3431 */
#define OP35     ;                              /* 3431 */
#define OP36     *                              /* 3431 */
#define OP37     /                              /* 3431 */
#define OP38     %                              /* 3431 */
#define OP39     <<                             /* 3431 */
#define OP40     >>                             /* 3431 */
#define OP41     <                              /* 3431 */
#define OP42     >                              /* 3431 */
#define OP43     <=                             /* 3431 */
#define OP44     >=                             /* 3431 */
#define OP45     ==                             /* 3431 */
#define OP46     !=                             /* 3431 */
#define OP47     ^                              /* 3431 */
#define OP48     |                              /* 3431 */
#define OP49     &&                             /* 3431 */
#define OP50     ||                             /* 3431 */

/*******************************************
SINGLE TOKEN MACROS

Identifiers
Constants
String literals
********************************************/

#define XY1           n                         /*      */
#define XY2           123                       /*      */
#define XY3           'a'                       /*      */
#define XY4           "abc"                     /*      */
#define XY5           123.456E02                /*      */
#define XY6           abracadabra               /*      */
#define XY7           __fred                    /*      */


/*********************************************

MULTIPLE TOKEN MACROS

**********************************************/

/*********************************************

:3429  A function-like macro is being defined.

**********************************************/

#define A9(a,b) a ## b                                      /* 3429 */

#pragma PRQA_MESSAGES_OFF 3429


/*********************************************

:3435  Parameter '%s' occurs more than once in the replacement list of this macro.
:3456  Parameter '%s' will be evaluated more than once when this macro is used.

Message 3435 is generated for any macro definition where the same parameter is
used more than once.
Message 3456 will only consider an parameter to be "evaluated" when it
is NOT adjacent to either a # or a ## operator.

**********************************************/


#define BM(X)         printf("\"%s\" = %d\n", #X, X)        /* 3435 */
#define ASQ(B)        (X_##A * (B) * (B))                   /* 3435 3456 */


#pragma PRQA_MESSAGES_OFF 3435, 3456


/**********************************************
:3457  Macro defines a braced initializer.

A macro body contained in braces {} which DOES NOT contain:
         a control statement keyword
      or a semicolon
**********************************************/

#define IN1(x)        {x, 0.0, 1.0}                         /* 3457 */
#define IN2(x)        { {x, 0}, {(x) + 1, 0} }              /* 3457 */
#define A6(a)         {a}                                   /* 3457 */
#define FN5           {z-1}                                 /* 3457 */
#define VPD_MNVS(lab,i,t,v,l,d)                    \
                      { lab,                       \
                        (i)|((t)<<14),             \
                        VPD_CLASS_NVS,             \
                        ((d)<<16) | ((v)<<8) | (l) \
                      }                                     /* 3457 */
#define VPD_MSCE(lab,i,t,s)                        \
                      { lab,                       \
                        (i)|((t)<<14),             \
                        VPD_CLASS_SERVICE,         \
                        (uint32)(s) \
                      }                                     /* 3457 */


/**********************************************
:3458  Macro defines a braced code statement block.

A macro body contained in braces {} which DOES contain a semicolon
**********************************************/

#define DA(buf,n)     { int i;                       \
                        for (i = 0; i < (n); ++i) {  \
                        (buf)[i] = 0; } }                   /* 3458 */
#define FNC1(x)       {if ((x) < 0) (x) = 10;}              /* 3458 */
#define FNC2(x)       {++(x);}                              /* 3458 */
#define BMAX(A,B)     {x = ((A) > (B)) ? (A) : (B);}        /* 3458 */
#define AddString(s)  { l = strlen(s);                    \
                        if (Length > 0)                   \
                        {                                 \
                           if ((p-Buffer+l) >= Length)    \
                           {                              \
                              SetLastError(ERROR_BUFFER); \
                              return 0;                   \
                           }                              \
                           memcpy(p, s, l);               \
                        }                                 \
                        p+=l;                             \
                      }                                     /* 3458 */
#define Swap(i, j)    { BYTE * t = a[i];       \
                        a[i] = a[j]; a[j] = t; \
                      }                                     /* 3458 */



/**********************************************
:3459  Macro defines a 'do-while-zero' construct.

A macro body of the form: do { ... } while (0)
**********************************************/


#define READ_TIME_32()                            \
    do {                                          \
       DISABLE_INTERRUPTS ();                     \
       time_now = (uint32_t)TIMER_HI << 16;       \
       time_now = time_now | (uint32_t) TIMER_LO; \
       ENABLE_INTERRUPTS ();                      \
    } while (0)                                             /* 3459 */




/**********************************************
:3413  Macro definition could be replaced by a typedef.

Any macro which appears to be a multi-token type specifier.
**********************************************/

#define TD15          int *                                 /* 3413 */
#define TD16          const int *                           /* 3413 */
#define TD17          int **                                /* 3413 */
#define TD18          volatile int * const                  /* 3413 */


/**********************************************
:3461  Macro defines a storage-class specifier/type qualifier sequence.

A multi-token macro body which contains only storage-class specifiers and type qualifiers
**********************************************/

#define TY01          static const                          /* 3461 */
#define TY02          static volatile                       /* 3461 */
#define TY03          static const volatile                 /* 3461 */
#define TY04          extern const                          /* 3461 */
#define TY05          volatile extern                       /* 3461 */
#define TY06          const volatile                        /* 3461 */



/**********************************************
:3412  Macro defines an unrecognized code-fragment.

Any macro which contains
       control statement keywords
    or storage class specifiers
    or braces { }
    or semicolons
   and which is NOT
       an initialiser macro (3457)
       a statement block macro (3458)
       a do-while-zero macro (3459)
       a storage-class specifier/type qualifier sequence (3461)
       a type specifier macro (3413)
**********************************************/
#define DC01          extern const volatile int             /* 3412 */
#define ANIF          if (                                  /* 3412 3411 */
#define SETIF(A, EXP) if ((A) > 0) {x = (EXP);}             /* 3412 */
#define XY8           static int x                          /* 3412 */
#define XY9           static const                          /*      3461 */
#define XYA           const static                          /*      3461 */
#define XYB           {}                                    /* 3412 */
#define XYC           ;;                                    /* 3412 */
#define TOGGLE_FLAG( Flag ) { (Flag) = !(Flag); };          /* 3412 */
#define KS()          ks_disable();                         /* 3412 */
#define XT            while (1) \
                      { \
                          _XData _XD; \
                          _XInitBlock(&_XD); \
                          switch (XSAVE(&_XD.Context)) \
                      }                                     /* 3412 */


/***********************************
EXPRESSION MACROS

:3409  The replacement list of function-like macro '%s' is not enclosed in ().
:3452  The replacement list of object-like macro '%s' is not enclosed in ().
:3453  A function could probably be used instead of this function-like macro.
:3410  Macro parameter not enclosed in ().

These macros do NOT contain:
       control statement keywords
       storage class specifiers
       braces
       semicolons
    and any type specifier keyword must be parenthesised
    (as in a cast)

    If an expression macro is not parenthesised
       and it contains an operator other than # or ##
       If it is function-like
       ... then generate                           Message 3409
        :3409 The body of function-like macro '%s' is
          not enclosed in ().
       If it is object-like
       ... then generate                           Message 3452
        :3452 The body of object-like macro '%s' is
          not enclosed in ().


    If an expression macro is function-like and
       a) contains an operator other than # or ##
       b) does not contain # or ## operators
       ... then generate                           Message 3453
    :3453 A function could probably be used
          instead of this function-like macro.

************************************************/

#define FN7           (-1)                                  /*           */
#define A14           -2                                    /* 3452      */
#define CASTI         (int)                                 /*           */
#define CASTUL        (unsigned long)                       /*           */
#define CASTUCP       (unsigned char *)                     /*           */
#define CONSTANT      (100)                                 /*           */

#define A1(a, b, c)   ((a) + (b) + (c))                     /*      3453 */
#define A2(a)         ((a) + 1)                             /*      3453 */
#define A5(a)         (a)                                   /*      3453 */
#define ADDA(A,B)     ((A) = (A) + (B))                     /*      3453 */
#define ADDB(A,B)     ((A) += (B))                          /*      3453 */
#define CMAX(A,B)     ((A)[1] + (B)[2])                     /*      3453 */
#define FUNC(X)       ((X)+2)                               /*      3453 */

#define A8(a,b)       (a ## b)                              /*           */
#define A10(a)        (#a)                                  /*           */
#define A12(a,b,c,d)  ((a) * b ## c * (d))                  /*           */

#define A15(A, B)     (A) + (B)                             /* 3409 3453 */
#define B2(a,b)       foo(a,b)                              /*      3453 */
#define B3(a)         foo(x * (a))                          /*      3453 */
#define MAKEA(X)      a = ((X) > 0) ? 10 : 0                /* 3409 3453 */
#define FOO(a,b) f1(a) + f2(b)                              /* 3409 3453 */

#define FUNC2         FUNC(10)                              /*           */
#define CONSTANT2     CONSTANT                              /*           */
#define ANULL         (void *)0                             /*           */
#define MAC1          (sizeof(V2VIO_DATA))                  /*           */
#define MAC2          ((char)(-1))                          /*           */

#define A11(a)        #a                                    /*           */
#define PT1(A, B)     A ## B                                /*           */
#define ST1(A)        #A                                    /*           */
#define ST2(X,Y)      ST1(X##Y)                             /*           */

#define B1(a, b)      (a + b)                               /* 3410 3453 */



/*********************************************
RECURSIVE MACROS

:3443  Macro '%s' has a replacement list which appears recursive.
*********************************************/

#define R1  (R2 + 1)
#define R2  (R3 + 2)
#define R3  (R1 + 3)                                        /* 3443 */


/********************************************
MACROS WHICH REDEFINE KEYWORDS
:3439  Macro redefines a keyword.

Message 3439 is generated when macro name is a keyword
********************************************/

#define int      long                                       /* 3439 3460 */
#define static                                              /* 3439      */



/*********************************************

:3411  Macro defined with unbalanced brackets, parentheses or braces.

Message 3411 is generated for any multiple token macro with or without parameters
when the macro body contains unbalanced (), {} or [].

**********************************************/

#define UB1           )(                                    /* 3411 */
#define UB2           ())(()                                /* 3411 */
#define UB3           (( )]                                 /* 3411 */
#define UB4           ((x+1)                                /* 3411 */
#define UB5           ([y+2]                                /* 3411 */

int x;



