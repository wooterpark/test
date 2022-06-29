/*******************************************************************************************

DECLARATIONS WITH EXTERNAL LINKAGE

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 2017,2022,2211,3120,3684

/*****************************************************************************
:0606  Object '%s' is declared using typedefs which are different to those in a previous declaration.
:0624  Function '%s' is declared using typedefs which are different to those in a previous declaration.
:0626  [U] '%s' has different type to previous declaration (which is no longer in scope).
:0630  [U] More than one definition of '%s' (with external linkage).
:2050  The 'int' type specifier has been omitted from a function declaration.
:2051  The 'int' type specifier has been omitted from an object declaration.
:3211  The global identifier '%s' is defined here but is not used in this translation unit.
:3221  Function with external linkage declared at block scope.
:3222  Object with external linkage declared at block scope.
:3337  The array '%s[]' is defined with a single element because no size has been specified.
:3408  '%s' has external linkage and is being defined without any previous declaration.
:3447  '%s' is being declared with external linkage but this declaration is not in a header file.
:3448  Declaration of typedef '%s' is not in a header file although it is used in a definition or declaration with external linkage.
*****************************************************************************/
typedef int INT;                         /* 3448           */

extern int gx1;                          /* 3447x2         */
extern INT gx3;                          /* 3447x2         */
extern int gx4;                          /* 3447x2         */
extern     gx6;                          /* 3447   2051    */
extern     gx7(void);                    /* 3447   2050    */
extern int f2(void);                     /* 3447x2         */

int gx1 = 1;
int gx1 = 1;                             /* 0630           */
int gx2 = 2;                             /* 3408           */
int gx3 = 3;                             /* 0606           */
int gx4 = 4;                             /* 3211           */
int gx5[];                               /* 3408 3337      */


extern int f1(void)                      /* 3408           */
{
    extern int   efunc1(void);           /* 3447 3221      */
    extern int   eobj;                   /* 3447 3222      */
    int r;
    r = gx1 + gx2 + gx3 + gx6;
    gx5[0] = 1;
    eobj = efunc1() + gx7();
    return r;
}

extern INT f2(void)                      /* 0624           */
{
    extern long efunc1(void);            /* 3447 0626 3221 */
    extern long eobj;                    /* 3447 0626 3222 */

    return 1;
}
