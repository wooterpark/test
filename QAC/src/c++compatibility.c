/********************************************************************************************

C++ COMPATIBILITY

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0702
#pragma PRQA_MESSAGES_OFF 0750
#pragma PRQA_MESSAGES_OFF 0759
#pragma PRQA_MESSAGES_OFF 1291
#pragma PRQA_MESSAGES_OFF 1296
#pragma PRQA_MESSAGES_OFF 2001
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2015
#pragma PRQA_MESSAGES_OFF 2021
#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 2201
#pragma PRQA_MESSAGES_OFF 2205
#pragma PRQA_MESSAGES_OFF 2209
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2212
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2216
#pragma PRQA_MESSAGES_OFF 2981
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 2986
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3122
#pragma PRQA_MESSAGES_OFF 3123
#pragma PRQA_MESSAGES_OFF 3132
#pragma PRQA_MESSAGES_OFF 3196
#pragma PRQA_MESSAGES_OFF 3197
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3204
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3207
#pragma PRQA_MESSAGES_OFF 3210
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3220
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3470
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 3673
#pragma PRQA_MESSAGES_OFF 4403
#pragma PRQA_MESSAGES_OFF 4432
#pragma PRQA_MESSAGES_OFF 4521
#pragma PRQA_MESSAGES_OFF 4527


extern int main(void);


/*************************************************************************
:1300  '%s' is a keyword in C++.
*************************************************************************/
int class = 0;                          /* 1300 */


/*************************************************************************
:1301  '%s' is a keyword in some C++ implementations.
*************************************************************************/
int overload = 0;                       /* 1301 */


/*************************************************************************
:1302  '%s()' must be declared before use in C++.
:3335  No function declaration. Implicit declaration inserted: 'extern int %s();'.
*************************************************************************/
int func01(void) { return func02();}    /* 1302 3335 */


/*************************************************************************
:1303  An empty parameter list in a function type has a different meaning in C++.
:3001  Function has been declared with an empty parameter list.
*************************************************************************/
int func03();                           /* 1303 3001 */


/*************************************************************************
:1304  Old style definition of function '%s()' is not portable to C++.
:3002  Defining '%s()' with an identifier list and separate parameter declarations is an obsolescent feature.
*************************************************************************/
int func04(x) int x; {return x;}        /* 1304 3002 */


/*************************************************************************
:1305  The global object '%s' declared 'const' has external linkage in C but internal linkage in C++.
:1329  The global object '%s' declared 'const' has been defined without an explicit initializer. This is not allowed in C++.
*************************************************************************/
const int globa = 1;                    /* 1305 */
const int globb;                        /* 1305 1329 */


/*************************************************************************
:1306  Multiple tentative definitions of '%s'. This is not allowed in C++.
*************************************************************************/
int sia; int sia;                       /* 1306 */


/*************************************************************************
:1307  Unnamed 'struct' and 'union' types may cause portability problems when moving to C++.
*************************************************************************/
struct {int a; long b;} sta;            /* 1307 */


/*************************************************************************
:0780  Another identifier '%s' is already in scope in a different namespace.
:0782  This identifier, '%s', will still be in scope when the same identifier is declared later in a different namespace.
:1308  The tag '%s' would clash with an existing typedef in C++.
:1309  The typedef '%s' would clash with an existing 'struct' / 'union' / 'enum' tag in C++.
:1310  '%s' is used as a tag and a typedef for the same 'struct' / 'union' / 'enum'.
*************************************************************************/
typedef int filx;                       /*           0782 */
struct filx {int x; long y;};           /* 1308 0780      */
struct fily {int x; long y;};           /*           0782 */
typedef int fily;                       /* 1309 0780      */
typedef struct filz { int x;} filz;     /* 1310 0780 0782 */


/*************************************************************************
:1312  The array being initialized is not large enough to hold a terminating null byte for the string initializer.
*************************************************************************/
char hello[5] = "Hello";                /* 1312 */


/*************************************************************************
:1314  The tag '%s' is defined within another 'struct' / 'union'.
*************************************************************************/
struct st1
{ struct st2 { int i; } ST2; } ST1;     /* 1314 */


/*************************************************************************
:0605  [C] A declaration must declare a tag or an identifier.
:1315  The 'static' qualifier has been used in the declaration of a tag.
:1043  [E] Defining an anonymous union object. This is a language extension.
:1044  [E] Defining an anonymous struct object. This is a language extension.
*************************************************************************/

static union     {int i1; char c1; };   /* 1043           */
static union  U1 {int i1; char c1; };   /* 1315           */
static union  U2 {int i1; char c1; } u2;
static union  U1                     u1;


static struct    {int i2; char c2;};    /* 1044           */
static struct S1 {int i2; char c2;};    /* 1315           */
static struct S2 {int i2; char c2;} s2;
static struct S1                   s1;


static enum      {A, B };               /* 1315           */
static enum   T1 {C, D };               /* 1315           */
static enum   T2 {E, F }           e2;
static enum   T1                   e1;



/*************************************************************************
:1328  Tag type defined within a function declaration.
*************************************************************************/
int enfo (enum enf { txm, ted, tim } x);/* 1328 */


int foo (
    int         x,
    const int * pci,
    void *      pv)
{
    int                   r = 1;
    enum TE1 {X1=2, X2=4 , X3=6} en1;
/*************************************************************************
:1311  'void *' and 'const T *' pointers used as operands to an equality or conditional operator.
*************************************************************************/

    r = (pci == pv);                    /* 1311 */


/*************************************************************************
:1317  Value of constant expression is not in the enum type to which it is being converted.
:1412  Object of enum type is being assigned the value of a constant, non-enum expression.
*************************************************************************/
    en1 = 3;                            /* 1317 1412 */


/*************************************************************************
:1318  Object of enum type is being modified with a compound assignment operator.
:1479  Object of enum type is being modified with an arithmetic compound assignment operator.
*************************************************************************/
    en1 += 1;                           /* 1318 1479 */


/*************************************************************************
:1319  Object of enum type is being modified with an increment or decrement operator.
:1481  Object of enum type is being modified with an increment or decrement operator.
*************************************************************************/
    ++en1;                              /* 1319 1481 */


/*************************************************************************
:1322  In C, sizeof('c') == sizeof(int), but in C++, sizeof('c') == sizeof(char) == 1.
*************************************************************************/
    r = sizeof('A');                    /* 1322 */


/*************************************************************************
:1323  The sizeof operator has been applied to an enum constant.
*************************************************************************/
    r = sizeof(X1);                     /* 1323 */


/*************************************************************************
:1324  Function 'main' cannot be called or have its address taken in C++.
*************************************************************************/
    r = main();                         /* 1324 */

/*************************************************************************
:1327  The macro __STDC__ has been used. It may not be present in a C++ environment.
*************************************************************************/
#ifdef __STDC__                         /* 1327 */
#endif


    if ( x > 10 )
        goto LAB1;

    if (x > 5)
    {
        int z = 5;

/*************************************************************************
:1313  Executing 'goto %s' will cause local initialization to be skipped.
:3311  [u] An earlier jump to this statement will bypass the initialization of local variables.
*************************************************************************/
        LAB1:                           /* 1313 3311 */
        z = 1;
        r = r + z;
    }


/*************************************************************************
:1325  '%s()' is defined with a non-void return type but contains 'return;'. This is not allowed in C++.
:0745  [U] 'return;' found in '%s()', which has been defined with a non-'void' return type.
*************************************************************************/
    return;                             /* 1325 0745 */
                                        /* (messages are functionally identical) */
}
