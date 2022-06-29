/********************************************************************************************

POINTER CONVERSIONS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0506
#pragma PRQA_MESSAGES_OFF 0510
#pragma PRQA_MESSAGES_OFF 1329
#pragma PRQA_MESSAGES_OFF 1336
#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2754
#pragma PRQA_MESSAGES_OFF 3004
#pragma PRQA_MESSAGES_OFF 3195
#pragma PRQA_MESSAGES_OFF 3197
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3207
#pragma PRQA_MESSAGES_OFF 3218
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3232
#pragma PRQA_MESSAGES_OFF 3410
#pragma PRQA_MESSAGES_OFF 3429
#pragma PRQA_MESSAGES_OFF 3450
#pragma PRQA_MESSAGES_OFF 3453
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3672
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 3673

#include <stddef.h>

extern void           loguc(const unsigned char *message);
extern void           logsc(const signed char *message);
extern void           logpc(const char *message);
extern unsigned char *ucbuf;
extern signed char   *scbuf;
extern char          *pcbuf;
extern void           crb(int *pn);
extern void           error( signed char * x );


static const    int   ci;
static volatile int   vi;
static const    int  *apci = &ci;
static volatile int  *apvi = &vi;

/*****************************************************************************
:0673  [C] Initializer points to a more heavily qualified type.
******************************************************************************/

static          int  *api  = &ci;                        /* 0673 */
static          int  *apj  = &vi;                        /* 0673 */




extern void implptrconv(
void                 *pvd,                              /* Ptr. to void                  */
signed char          *psc,                              /* Ptr. to signed char           */
unsigned char        *puc,                              /* Ptr. to unsigned char         */
char                 *ppc,                              /* Ptr. to plain char            */
int                  *pi,                               /* Ptr. to int                   */
int                 **ppi,                              /* Ptr. to ptr. to int           */
const    int         *pci,                              /* Ptr. to con. int              */
volatile int         *pvi,                              /* Ptr. to vol. int              */
const volatile int   *pcvi,                             /* Ptr. to con. vol. int         */
int * const          *pcpi,                             /* Ptr. to con. ptr. to int      */
int * volatile       *pvpi,                             /* Ptr. to vol. ptr. to int      */
int * const           cpi,                              /* Con. ptr. to int              */
int * volatile        vpi,                              /* Vol. ptr. to int              */
const int           **ppci,                             /* Ptr. to ptr. to con. int      */
volatile int        **ppvi,                             /* Ptr. to ptr. to vol. int      */
const int * const    *pcpci,                            /* Ptr. to con. ptr. to con. int */
const int * volatile *pvpci,                            /* Ptr. to vol. ptr. to con. int */
volatile int * const *pcpvi,                            /* Ptr. to con. ptr. to vol. int */
long                 *pl,                               /* Ptr. to long                  */
long                **ppl,                              /* Ptr. to ptr. to long          */
void                (*pfna)( int * p),                  /* Ptr. to function              */
void               (**ppfna)( int * p),                 /* Ptr. to ptr. function         */
short                 ssa,
int                   sia,
float                 fta
)
{
    int            r;
    int            n;
/******************************************************************************
:3313  No definition has been found for structure/union tag '%s'.
******************************************************************************/
    struct st     *psta;                                /* 3313 */


/***************************************************************************
:0563  [C] Right operand of assignment is not of compatible pointer type.
:0562  [C] Right operand of assignment points to a more heavily qualified type.
:0432  [C] Function argument is not of compatible pointer type.
:0431  [C] Function argument points to a more heavily qualified type.

******************************************************************************/

    puc = scbuf;                                        /* 0563 */
    puc = pcbuf;                                        /* 0563 */
    psc = ucbuf;                                        /* 0563 */
    psc = pcbuf;                                        /* 0563 */
    ppc = ucbuf;                                        /* 0563 */
    ppc = scbuf;                                        /* 0563 */
    pi = pl;                                            /* 0563 */
    ppi = ppl;                                          /* 0563 */
    ppi = ppci;                                         /* 0563 */
    ppi = ppvi;                                         /* 0563 */
    pcpi = pcpci;                                       /* 0563 */
    pvpi = pvpci;                                       /* 0563 */
    pcpi = pcpvi;                                       /* 0563 */
    pvpi = pcpvi;                                       /* 0563 */

    pi = pci;                                           /* 0562 */
    pi = pvi;                                           /* 0562 */
    pi = pcvi;                                          /* 0562 */
    pci = pcvi;                                         /* 0562 */
    pvi = pcvi;                                         /* 0562 */
    ppi = pcpi;                                         /* 0562 */
    ppi = pvpi;                                         /* 0562 */
    *ppi = *ppci;                                       /* 0562 */
    *ppi = *ppvi;                                       /* 0562 */


    loguc(scbuf);                                       /* 0432 */
    loguc(pcbuf);                                       /* 0432 */
    logsc(ucbuf);                                       /* 0432 */
    logsc(pcbuf);                                       /* 0432 */
    logpc(ucbuf);                                       /* 0432 */
    logpc(scbuf);                                       /* 0432 */

    crb(pci);                                           /* 0431 */
    crb(pvi);                                           /* 0431 */


/******************************************************************************
:0487  [C] If two pointers are subtracted, they must be pointers that address compatible types.
******************************************************************************/

    r = puc - psc;                                      /* 0487 */
    r = puc - ppc;                                      /* 0487 */
    r = psc - puc;                                      /* 0487 */
    r = psc - ppc;                                      /* 0487 */
    r = ppc - puc;                                      /* 0487 */
    r = ppc - psc;                                      /* 0487 */



/***************************************************************************

POINTER CASTING

:0301  [u] Cast between a pointer to object and a floating type.
:0302  [u] Cast between a pointer to function and a floating type.
:0307  [u] Cast between a pointer to object and a pointer to function.

:0306  [I] Cast between a pointer to object and an integral type.
:0305  [I] Cast between a pointer to function and an integral type.
:0303  [I] Cast between a pointer to volatile object and an integral type.

:0310  Casting to different object pointer type.
:0313  Casting to different function pointer type.

:0314  [I] Cast from a pointer to object type to a pointer to void.
:0316  [I] Cast from a pointer to void to a pointer to object type.


                          | integer |  float  | obj ptr |void ptr|v.obj ptr| fnc ptr |
--------------------------|---------|---------|---------|--------|---------|---------|
integer                   |   nnn   |   nnn   |   306   |  306   |   303   |   305   |
float                     |   nnn   |   nnn   |   301   |  301   |   301   |   302   |
object pointer            |   306   |   301   |   310   |  314   |   310   |   307   |
void pointer              |   306   |   301   |   316   |  ---   |   316   |   307   |
volatile object pointer   |   303   |   301   |   310   |  314   |   310   |   307   |
function pointer          |   305   |   302   |   307   |  307   |   307   |   313   |

****************************************************************************/


    /* Casting to an integer type */
    n  = (int)  pi;                                     /* 0306 */
    n  = (int)  pvi;                                    /* 0303 */
    n  = (int)  pcvi;                                   /* 0303 */
    n  = (int)  pfna;                                   /* 0305 */
    n  = (int)  ppi;                                    /* 0306 */
    n  = (int)  ppfna;                                  /* 0306 */
    n =  (int)  pvd;                                    /* 0306 */

    /* Casting to a float type */
    fta = (float) pi;                                   /* 0301 */
    fta = (float) pvi;                                  /* 0301 */
    fta = (float) pcvi;                                 /* 0301 */
    fta = (float) ppi;                                  /* 0301 */
    fta = (float) ppfna;                                /* 0301 */
    fta = (float) pfna;                                 /* 0302 */
    fta = (float) pvd;                                  /* 0301 */

    /* Casting to an object pointer type */

    psc = (signed char *)  sia;                         /* 0306 */
    psc = (signed char *)  fta;                         /* 0301 */
    psc = (signed char *)  pi;                          /* 0310 */
    psc = (signed char *)  pfna;                        /* 0307 */
    psc = (signed char *)  NULL;                        /*      */
    psc = (signed char *)  0;                           /*      */
    psc = (signed char *)  pvd;                         /* 0316 */

    /* Casting to a pointer to void type */

    pvd = (void *) sia;                                 /* 0306 */
    pvd = (void *) fta;                                 /* 0301 */
    pvd = (void *) pi;                                  /* 0314 */
    pvd = (void *) pvi;                                 /* 0314 0312      */
    pvd = (void *) pcvi;                                /* 0314 0311 0312 */
    pvd = (void *) pfna;                                /* 0307 */

    /* Casting to a volatile object pointer type */

    pvi = (volatile int *)  sia;                        /* 0303 */
    pvi = (volatile int *)  fta;                        /* 0301 */
    pvi = (volatile int *)  pi;                         /*      */
    pvi = (volatile int *)  pcvi;                       /* 0311 */
    pvi = (volatile int *)  pfna;                       /* 0307 */
    pvi = (volatile int *)  pvd;                        /* 0316 */

    pcvi = (const volatile int *)  sia;                 /* 0303 */
    pcvi = (const volatile int *)  fta;                 /* 0301 */
    pcvi = (const volatile int *)  pi;                  /*      */
    pcvi = (const volatile int *)  pfna;                /* 0307 */


    /* Casting to a function pointer type */

    pfna = (void (*)( int *)) sia;                      /* 0305 */
    pfna = (void (*)( int *)) fta;                      /* 0302 */
    pfna = (void (*)( int *)) pi;                       /* 0307 */
    pfna = (void (*)( int *)) pvi;                      /* 0307 */
    pfna = (void (*)( int *)) &error;                   /* 0313 */
    pfna = (void (*)( int *)) pvd;                      /* 0307 */

    pfna = (void (*)( int *)) NULL;                     /*      */
    pfna = (void (*)( int *)) 0;                        /*      */
    pfna = NULL;                                        /*      */
    pfna = 0;                                           /*      */





/***************************************************************************

IMPLICIT POINTER CONVERSIONS:

:0315  [I] Implicit conversion from a pointer to object type to a pointer to void.
:0317  [I] Implicit conversion from a pointer to void to a pointer to object type.

****************************************************************************/

    /* A null pointer may be implicitly converted
       to a pointer to object type
       or a pointer to function type */

    psc = NULL;                                         /*      */
    psc = 0;                                            /*      */
    pfna =  NULL;                                       /*      */
    pfna =  0;                                          /*      */


    /* A pointer to void may be implicitly
       converted to a pointer to object type */

    psc = pvd;                                          /* 0317 */

    /* A pointer to object may be implicitly
       converted to a pointer to void */

    pvd = pi;                                           /* 0315 */

    /* A pointer cannot be implicitly
       converted to an arithmetic type */

    n  = pi;                                            /* 0557 */
    n =  pvd;                                           /* 0557 */
    n  = pvi;                                           /* 0557 */
    n  = pfna;                                          /* 0557 */
    n  = ppi;                                           /* 0557 */
    n  = ppfna;                                         /* 0557 */

    fta = pi;                                           /* 0557 */
    fta = pvi;                                          /* 0557 */
    fta = pcvi;                                         /* 0557 */
    fta = ppi;                                          /* 0557 */
    fta = ppfna;                                        /* 0557 */
    fta = pfna;                                         /* 0557 */
    fta = pvd;                                          /* 0557 */


    /* Arithmetic types cannot be implicitly
       converted to pointers. */

    psc = sia;                                          /* 0563 */
    psc = fta;                                          /* 0563 */
    pvd = sia;                                          /* 0563 */
    pvd = fta;                                          /* 0563 */
    pfna =  sia;                                        /* 0563 */
    pfna =  fta;                                        /* 0563 */

    /* A pointer cannot be implicitly converted to
       a pointer to a different type */

    psc = pi;                                           /* 0563 */
    psc = pfna;                                         /* 0563 */
    pvd = pfna;                                         /* 0563 */
    pfna =  pi;                                         /* 0563 */
    pfna =  pvi;                                        /* 0563 */
    pfna =  &error;                                     /* 0563 */
    pfna =  pvd;                                        /* 0563 */


/******************************************************************************
:0310  Casting to different object pointer type.
:0311  Dangerous pointer cast results in loss of const qualification.
:0312  Dangerous pointer cast results in loss of volatile qualification.
******************************************************************************/

    pl   = (long *)cpi;                                 /* 0310           */
    pl   = (long *)vpi;                                 /* 0310           */

    pi   = (int *)pci;                                  /*      0311      */
    pvi  = (volatile int *)pcvi;                        /*      0311      */
    ppi  = (int **)pcpi;                                /*      0311      */
    ppi  = (int **)ppci;                                /* 0310 0311      */
    *ppi = (int *)*ppci;                                /*      0311      */
    pcpi = (int * const *)pcpci;                        /* 0310 0311      */
    pvpi = (int * volatile *)pvpci;                     /* 0310 0311      */
    pvpi = (int * volatile *)pvpci;                     /* 0310 0311      */

    pci  = (const int *)pcvi;                           /*           0312 */
    ppi  = (int **)pvpi;                                /*           0312 */
    *ppi = (int *)*ppvi;                                /*           0312 */
    pcpi = (int * const *)pcpvi;                        /* 0310      0312 */
    pi   = (int *)pvi;                                  /*           0312 */

    pi   = (int *)pcvi;                                 /*      0311 0312 */


/******************************************************************************
:3305  Pointer cast to stricter alignment.
******************************************************************************/

    pi = (int *) psc;                                   /* 0310 3305 */


/******************************************************************************
:0309  [U] Integral type is not large enough to hold a pointer value.
******************************************************************************/

    ssa = (short)pi;                                    /* 0306 0309 */


/******************************************************************************
:0308  Non-portable cast involving pointer to an incomplete type.
******************************************************************************/

    psta = (struct st *)pi;                             /* 0308 0310 */

}


/******************************************************************************
:0757  [C] 'return' expression points to a more heavily qualified type.
******************************************************************************/
static int *fpi(void)
{
    return(apci);                                       /* 0757 */
}

static int *fpj(void)
{
    return(apvi);                                       /* 0757 */
}
