/********************************************************************************************

ARRAYS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0488
#pragma PRQA_MESSAGES_OFF 0506
#pragma PRQA_MESSAGES_OFF 0510
#pragma PRQA_MESSAGES_OFF 0753
#pragma PRQA_MESSAGES_OFF 1336
#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 2201
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2212
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2215
#pragma PRQA_MESSAGES_OFF 2824
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3122
#pragma PRQA_MESSAGES_OFF 3132
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3210
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3223
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3448
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 3632
#pragma PRQA_MESSAGES_OFF 3672


/*****************************************************************************************
:1037  [E] Arrays of length zero are a language extension.
*****************************************************************************************/
int array[0];                           /* 1037 */


/*****************************************************************************************
:0694  Array initializer is missing the optional {.
*****************************************************************************************/
int a2[2][2] = {1, 2, 3, 4};            /* 0694 */


/*****************************************************************************************
:0676  [u] Array element is of function type. Arrays cannot be constructed from function types.
:0678  [u] Array element is array of unknown size. Arrays cannot be constructed from incomplete types.
*****************************************************************************************/
int (a0[3])(int, char *);               /* 0676 */
int blob2[10][];                        /* 0678 */


/*****************************************************************************************
:0680  [u] Array element is 'void' or an incomplete 'struct' or 'union'. Arrays cannot be constructed from incomplete types.
:3313  No definition has been found for structure/union tag '%s'.
*****************************************************************************************/
struct bill blob3[3];                   /* 3313, 0680 */


/*****************************************************************************************
:0686  Array has fewer initializers than its declared size. Default initialization is applied to the remainder of the array elements.
:0687  Array has been initialized using concatenated strings and has fewer initializers than its declared size.
:0688  Array size determined by number of initializers which include concatenated string literals.
:3337  The array '%s[]' is defined with a single element because no size has been specified.
:3650  Typedef defines an array type of unknown size.
:3651  Using a typedef for an array of unknown size can lead to unexpected results.
:3674  Array size defined implicitly by the number of initializers.
:3684  Array declared with unknown size.
*****************************************************************************************/
extern int param[];                     /* 3684 */

int a1[4] = {1, 2, 3};                  /* 0686 */

char *autumn[2] = { "rainy" "season" }; /* 0687 */


char seasons[4][20] =
{"winter", "spring" "summer", "autumn"};/* 0687 */

char *coldmonths[] =                    /* 3674 */
{"December", "January", "February"};

char *winter[]  = { "cold" "season" };  /* 0688, 3674 */

int a4[];                               /* 3684, 3337 */

typedef char UA[];                      /* 3650 */

UA uax = "abc";                         /* 3651, 3674 */


/*****************************************************************************************
:1312  The array being initialized is not large enough to hold a terminating null byte for the string initializer.
:3111  Redundant comma at end of braced initializer will be ignored.
*****************************************************************************************/
char spring[6] = "spring";              /* 1312 */

int a3[2] = {1, 2,};                    /* 3111 */


/*****************************************************************************************
:1051  [C99] A variable length array has been declared.
:1052  [C99] A variable length array of unspecified size has been declared.
*****************************************************************************************/
extern void f1(int (*pvb)[*]);          /* 1052 */

extern void foo (int n)
{
    int vb[n];                          /* 1051 */

/*****************************************************************************************
:0623  [U] '%s' has incomplete type and no linkage - this is undefined.
*****************************************************************************************/
    static int buf[];                   /* 0623 3684 */
}

/*****************************************************************************************
:0491  Array subscripting applied to an object of pointer type.
:0492  Array subscripting applied to a function parameter declared as a pointer.
:3405  Index[Array] is equivalent to Array[Index] but more confusing.
*****************************************************************************************/

extern int *gpi;

extern int f2(const int *pi, int n)
{
    int r;
    int buf[10];

    r = pi[5];                          /* 0492 */

    r = r + gpi[5];                     /* 0491 */

    buf[n] = 0;
    n[buf] = 1;                         /* 3405 */

    return r;
}
