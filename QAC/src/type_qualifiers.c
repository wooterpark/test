/********************************************************************************************

TYPE QUALIFIERS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0506
#pragma PRQA_MESSAGES_OFF 0510
#pragma PRQA_MESSAGES_OFF 1278
#pragma PRQA_MESSAGES_OFF 1329
#pragma PRQA_MESSAGES_OFF 2205
#pragma PRQA_MESSAGES_OFF 2209
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2753
#pragma PRQA_MESSAGES_OFF 2814
#pragma PRQA_MESSAGES_OFF 2824
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 2986
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3122
#pragma PRQA_MESSAGES_OFF 3132
#pragma PRQA_MESSAGES_OFF 3195
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3221
#pragma PRQA_MESSAGES_OFF 3223
#pragma PRQA_MESSAGES_OFF 3313
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 3674
#pragma PRQA_MESSAGES_OFF 3684

/********************************************************************************
Identifying unused variables and using 'const' to identify objects that are not modified

:3203  The variable '%s' is set but never used.
:3204  The variable '%s' is only set once and so it could be declared with the 'const' qualifier.
:3205  The identifier '%s' is not used and could be removed.

If a variable is defined but never used
    3205 is generated
else if a variable is assigned a value but never used
    3203 is generated
else if a variable is initialised or assigned a value
        which is never subsequently used and the variable is not declared 'const'
    3204 is generated

In general, an object can be modified either by assignment or through
a pointer. In generating message 3204 a variable is considered 'modified'
if its address is assigned to a "pointer to non-const"

*********************************************************************************/

void boo1 (void)
{
    int         a = 1;                /* 3204 */
    int         b;                    /* 3204 */
    const int   c = 3;                /* 3205 */
    int         d = 4;                /* 3205 */
    int         e;                    /* 3203 */
    const int   f = 6;
    int         g = 7;
    int         h = 8;                /* 3204 */
    int *       pi;
    const int * pci;
    int r;                            /* 3203 */

    b = 2;
    e = 5;
    pi = &g;
    pci = &h;

    r = a + b + f + *pi + *pci;
}


/******************************************************
Using 'const' on function parameters

:3206  The parameter '%s' is not used in this function.
:3227  The parameter '%s' is never modified and so it could be declared with the 'const' qualifier.
:3673  The object addressed by the pointer parameter '%s' is not modified and so the pointer could be of type 'pointer to const'.

Both 3227 and 3673 encourage the use of the 'const' qualifier in the
declaration of function parameters.
Message 3227 is generated for a function parameter declared without
the 'const' modifier whose value is used but never modified.
Message 3673 is generated for a function parameter declared as a pointer
to a 'non-const' object which is not modified within the function.

******************************************************/

int boo2 (
int                a,                   /* 3206 */
int                b,                   /* 3227 */
const int          c,
int                d,
int                p1[],
int                p2[],                /* 3673 */
int                p3[],                /* 3673 */
int                p4[],
int                p5[] )               /* 3673 */
{
    int            r;
    int           *pnc;
    const int     *pc;
    extern void    ef1(int *x);
    extern void    ef2(const int *x);

    ef1(p1);       /* Prototype indicates p1 is an output parameter */
    ef2(p2);

    pnc = p4;      /* p4 is addressed by a pointer to non-const */
    *pnc = 1;

    pc = p5;       /* p5 is addressed by a pointer to const */

    ++d;

    r = b + c + d + p1[1] + p2[1] + p3[1] + *pc;

    return(r);
}

#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3673




/***********************************************************************
Casting away const or volatile qualification in pointers

:0311  Dangerous pointer cast results in loss of const qualification.
:0312  Dangerous pointer cast results in loss of volatile qualification.
:0562  [C] Right operand of assignment points to a more heavily qualified type.
:0563  [C] Right operand of assignment is not of compatible pointer type.
:0673  [C] Initializer points to a more heavily qualified type.
:0757  [C] 'return' expression points to a more heavily qualified type.

It is a illegal in the C language to assign a "pointer to const" to
an unqualified pointer and QAC will generate message 562.
Similarly it is not legal to initialise an unqualified pointer with
the address of a qualified object. QAC will generated message 673.
It is possible, although dangerous, to perform such an assignment
using a cast. QAC will flag such an operation with message 311 or 312.
************************************************************************/

void boo3(
int                  *pi,               /* Ptr. to int                   */
int                 **ppi,              /* Ptr. to ptr. to int           */
const    int         *pci,              /* Ptr. to con. int              */
volatile int         *pvi,              /* Ptr. to vol. int              */
const volatile int   *pcvi,             /* Ptr. to con. vol. int         */
int * const          *pcpi,             /* Ptr. to con. ptr. to int      */
int * volatile       *pvpi,             /* Ptr. to vol. ptr. to int      */
const int           **ppci,             /* Ptr. to ptr. to con. int      */
volatile int        **ppvi              /* Ptr. to ptr. to vol. int      */

)
{
    static          int  li;
    static const    int  lci;
    static volatile int  lvi;

    static          int *lpi1 = &lci;   /* 0673 */
    static          int *lpi2 = &lvi;   /* 0673 */
    static const    int *lpci = &li;
    static volatile int *lpvi = &li;

    static int *lpi3 = (int *)(&lci);   /* 0311 */
    static int *lpi4 = (int *)(&lvi);   /* 0312 */


    pi = pci;                           /* 0562 */
    pi = (int *)pci;                    /* 0311 */

    pi = pvi;                           /* 0562 */
    pi = (int *)pvi;                    /* 0312 */

    pi = pcvi;                          /* 0562 */
    pi = (int *)pcvi;                   /* 0311 0312 */

    ppci = &pci;
    ppvi = &pvi;
    pci = *ppci;
    pvi = *ppvi;

    pci = pcvi;                         /* 0562 */
    pci = (const int *)pcvi;            /* 0312 */

    pvi = pcvi;                         /* 0562 */
    pvi = (volatile int *)pcvi;         /* 0311 */

    ppi = pcpi;                         /* 0562 */
    ppi = (int **)pcpi;                 /* 0311 */

    ppi = pvpi;                         /* 0562 */
    ppi = (int **)pvpi;                 /* 0312 */

    *ppi = *ppci;                       /* 0562 */
    *ppi = (int *)*ppci;                /* 0311 */

    *ppi = *ppvi;                       /* 0562 */
    *ppi = (int *)*ppvi;                /* 0312 */

}


int *boo4(void)
{
    static const int ia[] = { 5, 4, 3, 2, 1 };
    const int * const pci = ia;

    return(pci);                         /* 757 */
}

int *boo5(void)
{
    static const int ia[] = { 5, 4, 3, 2, 1 };
    const int * const pci = ia;

    return((int *)pci);                  /* 311 */
}


/*********************************************************************
Addressing a string literal with a pointer that is not "const" qualified.

:0431  [C] Function argument points to a more heavily qualified type.
:0752  String literal passed as argument to function whose parameter is not a 'pointer to const'.
:0753  String literal assigned to pointer which is not a 'pointer to const'.

Message 431 is generated if a "pointer to const" is supplied as a
function argument to a function whose corresponding parameter is
a "pointer to non-const".

Message 752 is generated if a string literal is supplied as a
function argument to a function whose corresponding parameter is
a "pointer to non-const".

Message 753 is generated when the address of a string literal is
assigned to a pointer that is not "const qualified"
*********************************************************************/

void boo6 (
const char * pca,
char       * pa )
{
    extern void efoo3(char *pi);

    efoo3(pa);
    efoo3("123");                        /* 0752 */
    efoo3(pca);                          /* 0431 */
    pca = "xyz";
    pa = "abc";                          /* 0753 */
}
