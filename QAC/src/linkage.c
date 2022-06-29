/********************************************************************************************

LINKAGE

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 1306
#pragma PRQA_MESSAGES_OFF 2021
#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3207
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3218
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3220
#pragma PRQA_MESSAGES_OFF 3222
#pragma PRQA_MESSAGES_OFF 3223
#pragma PRQA_MESSAGES_OFF 3229
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3450



/**************************************************************************
:0625  [U] '%s' has been declared with both internal and external linkage - the behaviour is undefined.
**************************************************************************/

extern int  a;
static int  a;                          /* 0625 */

int         b;
static int  b;                          /* 0625 */

static int  c;
int         c;                          /* 0625 */


/**************************************************************************
:3224  This identifier has previously been declared with internal linkage but is not declared here with the static storage class specifier.
**************************************************************************/
static int  d;
extern int  d;                          /* 3224 */


static int  fn1(void);
int         fn1(void) {return 1;}       /* 3224 */


/**************************************************************************
:3334  This declaration of '%s' hides a more global declaration.

The 3 declarations of "g" in the following code refer to the same object
The 3 declarations of "h" in the following code refer to different objects
**************************************************************************/

static int  g;
static int  h;

void fn2(void)
{
    extern int g;
    static int h;                       /* 3334 */
    {
        extern int g;
        static int h;                   /* 3334 */

        g = 1;
    }
}
