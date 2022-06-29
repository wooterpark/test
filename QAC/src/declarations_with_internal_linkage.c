/*******************************************************************************************

DECLARATIONS WITH INTERNAL LINKAGE

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0553,2022,2211,2754,3221,3684


/*****************************************************************************
:0629  [C] More than one definition of '%s' (with internal linkage).
:0632  [U] Tentative definition of '%s' with internal linkage cannot have unknown size.
:0661  [U] '%s()' may not have a storage class specifier of 'static' when declared at block scope.

:2050  The 'int' type specifier has been omitted from a function declaration.
:2051  The 'int' type specifier has been omitted from an object declaration.
:3337  The array '%s[]' is defined with a single element because no size has been specified.
:3450  Function '%s', with internal linkage, is being defined without a previous declaration.
*****************************************************************************/
static int ax1 = 1;
static int ax1 = 1;                      /* 0629      */
static int ax2[];                        /* 0632 3337 */
static     ax3;                          /* 2051      */

static     af3(void);                    /* 2050      */

static int af1(void)                     /* 3219 3450 */
{
    static int  wibble(void);            /* 0661      */
    int r;
    r = ax1 + ax3;
    ++ax1;
    ax2[0] = wibble();
    return r;
}

static int af2(void)                     /* 3219 3450 */
{
    int r;
    r = ax2[0];
    ax2[0] = ax1;
    ax3 = af3();

    return r;
}

static af3(void)
{                                        /* 2050      */
    return ax1;
}

/*****************************************************************************
:3218  File scope static, '%s', is only accessed in one function.
:3229  File scope static, '%s', is written but never used.
:3232  File scope static, '%s', is never modified. It could be declared const.
:3233  File scope static, '%s', is not explicitly initialized but its value is used.
*****************************************************************************/
static int bx1 = 1;                      /* 3218      */
static int bx2 = 1;                      /* 3232      */
static int bx3 = 0;                      /* 3229      */
static int bx4;                          /* 3233      */

static int bf1(void)                      /* 3219 3450 */
{
    bx3 = bx2;
    return bx2 + bx4;
}

static int bf2(void)                      /* 3219 3450 */
{
    int r;
    r = bx1;
    bx1++;
    bx3 = bx2;

    return r + bx4;
}
