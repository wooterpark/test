/********************************************************************************************

K&R RESTRICTIONS

Messages in the range 340 to 352 are all associated with
features of the ISO language that were not always supported in pre-ISO
compilers. The intention of these messages is to enable such features
to be identified so that code is portable to pre-ISO environments.

The messages are unusual in that they are not generated unless an
appropriate -k+r parser option is enabled. The k+r option is followed by a
series of single character arguments which each correspond to one
of the K&R messages. See below.

Some of the K&R messages also have a twin message. The twin message is only
generated when the K&R message has NOT been enabled with the k+r option.
For example:

   0347 K&R compilers do not allow initialisation of 'extern' variables.
   3603 Initialization of externals not available in K&R C.

   If the -k+r x option is applied, message 0347 is generated
   Otherwise .......................message 3603

Notice that message 3602 is a twin for both 346 and 350.

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0753
#pragma PRQA_MESSAGES_OFF 1255
#pragma PRQA_MESSAGES_OFF 1290
#pragma PRQA_MESSAGES_OFF 1305
#pragma PRQA_MESSAGES_OFF 2016
#pragma PRQA_MESSAGES_OFF 2209
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2881
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 2986
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3122
#pragma PRQA_MESSAGES_OFF 3123
#pragma PRQA_MESSAGES_OFF 3131
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3204
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3352
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3409
#pragma PRQA_MESSAGES_OFF 3432
#pragma PRQA_MESSAGES_OFF 3433
#pragma PRQA_MESSAGES_OFF 3434
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 3628
#pragma PRQA_MESSAGES_OFF 3674


#define M1 1
#define M2 2

/***************************************************************************************
:0341  Using the stringify operator '#'.
:0342  Using the glue operator '##'.
***************************************************************************************/
#define S1 abc
#define S2 def
#define S3 S1##S2               /* 0342 */ /* (-k+r g) */
#define S4 #S3                  /* 0341 */ /* (-k+r s) */

/***************************************************************************************
:0340  Using the '#error' preprocessing directive.
:0352  Using the '#elif' preprocessing directive.

Message 3608 is suppressed by option "-k+r l"
:3608  Using the '#elif' preprocessing directive.
***************************************************************************************/
#ifdef ERROR
#error "This is wrong"          /* 0340 */ /* (-k+r e) */
#elif  M1 == 1                  /* 0352 */ /* (-k+r l) or else 3608 */
#define FRED
#elif  M2                       /* 0352 */ /* (-k+r l) or else 3608 */
#endif


/***************************************************************************************
:0347  Using 'extern' in the definition of a global variable.

Message 3603 is suppressed by option "-k+r x"
:3603  Using 'extern' in the definition of a global variable.
***************************************************************************************/
int          a = 1;
extern int   b = 1;             /* 0347 */ /* (-k+r x) or else 3603 */


/***************************************************************************************
:0343  Using string literal concatenation.
***************************************************************************************/
char         c[] = "ABC""DEF";  /* 0343 */ /* (-k+r c) */


/***************************************************************************************
:0346  Using one of the keywords 'signed', 'const' or 'volatile'.
:0350  Using the keyword 'enum'.

Message 3602 is not generated for keyword  "signed" if option "-k+r i" is enabled
Message 3602 is not generated for keywords "const" or "volatile" if option "-k+r t" is enabled
Message 3602 is not generated for keyword  "enum"   if option "-k+r n" is enabled
:3602  Using one of the keywords 'signed', 'const', 'volatile' or 'enum'.
***************************************************************************************/
const int    d = 1;             /* 0346 */ /* (-k+r t) or else 3602 */
volatile int v = 1;             /* 0346 */ /* (-k+r t) or else 3602 */
signed int   e = 1;             /* 0346 */ /* (-k+r i) or else 3602 */
enum e1 { red, blue, green };   /* 0350 */ /* (-k+r n) or else 3602 */


/***************************************************************************************
:3615  Using 'entry' as an identifier.
***************************************************************************************/
int          entry = 1;         /* 3615 */


/***************************************************************************************
:0344  Using function prototype syntax.
:0345  Using the keyword 'void'.
***************************************************************************************/
int foo(void)                   /* 0344 0345 */ /* (-k+r pv) */
{

/***************************************************************************************
:0351  Using an initializer when defining an automatic object of struct, union or array type.
:3604  Using an initializer when defining an automatic object of struct, union or array type.
***************************************************************************************/
    char x[]="a string";        /* 0351 */ /* (-k+r a) or else 3604 */


/***************************************************************************************
:3601  Trigraphs (??x) are an ISO feature.
***************************************************************************************/
    char tc = '??!';            /* 3601 */


/***************************************************************************************
:3609  Using the alert escape sequence '\\a'.
***************************************************************************************/
    char bell = '\a';           /* 3609 */


/***************************************************************************************
:3610  Hexadecimal escape sequence used.
***************************************************************************************/
    char hex  = '\x13';         /* 3610 */


/***************************************************************************************
:3613  Some pre-ISO compilers would treat this 8 or 9 as an octal digit.
***************************************************************************************/
    char *ost = "\019AB";       /* 3613 */


/***************************************************************************************
:3606  This unsuffixed decimal constant has type 'long', but had type 'unsigned int' in K&R C.
***************************************************************************************/
    long ls;
    long gi = 32769;            /*      */  /* 3606 is generated when -size int=16   */
                                            /* Under K&R rules, type is unsigned int */
                                            /* Under ISO rules, type is long         */


/***************************************************************************************
:0348  Using a bit-field.
:3621  A bit-field is being defined as a member of a struct or union.
***************************************************************************************/
    struct s2
    {
        unsigned int b1:4;      /* 0348 */ /* (-k+r b) or else 3621 */
        unsigned int s;
    } st1, st2;

    int r;


/***************************************************************************************
:0349  Using the unary '+' operator.
:3600  Using the unary '+' operator.
***************************************************************************************/
    r = +d;                     /* 0349 */ /* (-k+r u) or else 3600 */

/***************************************************************************************
:3605  Type of 'switch' controlling expression cannot be represented in type 'int'.
***************************************************************************************/
    ls = r;

    switch (ls)                 /* 3605 */
    {
    case 1:
        ++r;
        break;

    default:
        break;
    }


/***************************************************************************************
:3617  Assignment of a struct/union by value.
***************************************************************************************/
    st1.b1 = 2;
    st1.s  = 1;

    st2 = st1;                  /* 3617 */

    return r;
}
