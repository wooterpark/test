/********************************************************************************************

STRUCTURES AND UNIONS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0911
#pragma PRQA_MESSAGES_OFF 1307
#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 2205
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2754
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3122
#pragma PRQA_MESSAGES_OFF 3132
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3207
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3218
#pragma PRQA_MESSAGES_OFF 3223
#pragma PRQA_MESSAGES_OFF 3233
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3603
#pragma PRQA_MESSAGES_OFF 3604
#pragma PRQA_MESSAGES_OFF 3625



/*****************************************************************************************
:0620  [C] Cannot initialize '%s' because it has unknown size.
:0632  [U] Tentative definition of '%s' with internal linkage cannot have unknown size.
:0759  An object of union type has been defined.
:3313  No definition has been found for structure/union tag '%s'.
*****************************************************************************************/
static struct Fred  fred1;              /* 0620 0632 3313 */

static union  John  john;               /* 0620 0632 0759 3313 */

/*****************************************************************************************
:0693  Struct initializer is missing the optional {.
:0672  [U] The initializer for a 'struct', 'union' or array is not enclosed in braces.
:1041  [E] Empty aggregate initializers are a language extension.
*****************************************************************************************/
struct sid
{
    int a;
    int b;
} as1[2] = {1, 1, 2, 2};                /* 0693 */

struct sid as2 = 3, 3;                  /* 0926 0605 0605 0672 */

extern struct sid  as3 = { };           /* 1041 */


/*****************************************************************************************
:0547  [C] This declaration of tag '%s' conflicts with a previous declaration.
:0619  [C] The identifier '%s' has already been defined in the current scope within the ordinary identifier namespace.
:0660  [E] Defining an unnamed member in a struct or union. This is a language extension.
:0633  [E] Empty structures and unions are a language extension.
:0636  [U] There are no named members in this 'struct' or 'union'.
:1043  [E] Defining an anonymous union object. This is a language extension.
:1044  [E] Defining an anonymous struct object. This is a language extension.
*****************************************************************************************/
struct at
{
    int n;
    struct sid;                         /* 0660 */
} atx;

enum sid                                /* 0547 */
{
    barry,
    mandy
} Names;

struct pxa { };                         /* 0633 */

struct pxb
{
    int;                                /* 0660 */
    float;                              /* 0660 */
};                                      /* 0636 */

union
{                                       /* 0750 */
    int  una;                           /* 0783 1577 */
    long unb;
};                                      /* 1043 0759 */

struct
{
    int  sta;
    long stb;
};                                      /* 1044 */

int una;                                /* 0781 1582 0619 */

int *px;

struct as
{
    int x;
    int y;
};

extern void foo2(struct as ass);
extern void foo3(struct as *ass);

int foo ( void )
{
    int *p;
    struct as asx = { 1, 2 };
    struct as asy;
    static int ai[6];
    int loc;


/*****************************************************************************************
:0750  A union type specifier has been defined.
:2547  This declaration of tag '%s' hides a more global declaration.
:3629  Union contains member of floating type.
*****************************************************************************************/
    union sid                           /* 2547 */
    {                                   /* 0750 */
        char  a[4];
        int   b[2];
        float ft;                       /* 3629 */
    } asid;                             /* 0759 */


/*****************************************************************************************
:0623  [U] '%s' has incomplete type and no linkage - this is undefined.
*****************************************************************************************/
    static struct UST us;               /* 0623 3313 */


/*****************************************************************************************
:0675  [C] Initializer is not of compatible 'struct'/'union' type.
*****************************************************************************************/
    struct bs
    {
        char f1;
    } ls = asx;                         /* 0675 */


/*****************************************************************************************
:0544  [U] The value of an incomplete 'union' may not be used.
:0671  [C] Initializer for object of arithmetic type is not of arithmetic type.
*****************************************************************************************/
    int j = john;                       /* 0544 0671 */


/********************************************************************************************
:3617  Assignment of a struct/union by value.
********************************************************************************************/
    asy = asx;                          /* 3617 */

/********************************************************************************************
:3623  Passing a struct/union by value as a function argument.
********************************************************************************************/
    foo2(asx);                          /* 3623 */
    foo3(&asx);

/********************************************************************************************
:0662  [E] Accessing a member of an unnamed struct or union member in this way is a language extension.
********************************************************************************************/
    atx.a = 1;                          /* 0662 */

    return 1;
}
