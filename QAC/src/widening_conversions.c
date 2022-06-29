/********************************************************************************************

WIDENING CONVERSIONS

********************************************************************************************/

#pragma PRQA_MESSAGES_OFF  344
#pragma PRQA_MESSAGES_OFF  345
#pragma PRQA_MESSAGES_OFF  346
#pragma PRQA_MESSAGES_OFF  584
#pragma PRQA_MESSAGES_OFF 1014
#pragma PRQA_MESSAGES_OFF 1251
#pragma PRQA_MESSAGES_OFF 1278
#pragma PRQA_MESSAGES_OFF 1800
#pragma PRQA_MESSAGES_OFF 1840
#pragma PRQA_MESSAGES_OFF 1850
#pragma PRQA_MESSAGES_OFF 1860
#pragma PRQA_MESSAGES_OFF 1890
#pragma PRQA_MESSAGES_OFF 1891
#pragma PRQA_MESSAGES_OFF 2100-2107
#pragma PRQA_MESSAGES_OFF 2101
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2834
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 2985
#pragma PRQA_MESSAGES_OFF 3103
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3121
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3760
#pragma PRQA_MESSAGES_OFF 3762
#pragma PRQA_MESSAGES_OFF 3763
#pragma PRQA_MESSAGES_OFF 3764
#pragma PRQA_MESSAGES_OFF 3774
#pragma PRQA_MESSAGES_OFF 3775
#pragma PRQA_MESSAGES_OFF 3843
#pragma PRQA_MESSAGES_OFF 4131
#pragma PRQA_MESSAGES_OFF 4152
#pragma PRQA_MESSAGES_OFF 4390-4399
#pragma PRQA_MESSAGES_OFF 4490
#pragma PRQA_MESSAGES_OFF 4433
#pragma PRQA_MESSAGES_OFF 4434
#pragma PRQA_MESSAGES_OFF 4443
#pragma PRQA_MESSAGES_OFF 4445
#pragma PRQA_MESSAGES_OFF 4453
#pragma PRQA_MESSAGES_OFF 4491
#pragma PRQA_MESSAGES_OFF 4492
#pragma PRQA_MESSAGES_OFF 4498
#pragma PRQA_MESSAGES_OFF 4499
#pragma PRQA_MESSAGES_OFF 4533
#pragma PRQA_MESSAGES_OFF 4543
#pragma PRQA_MESSAGES_OFF 4544
#pragma PRQA_MESSAGES_OFF 4570
#pragma PRQA_MESSAGES_OFF 4571

#include "xample.h"


extern void widening(void)
{
    usa = uca;
    uia = uca;
    ula = uca;
    uxa = uca;

    ssa = sca;
    sia = sca;
    sla = sca;
    sxa = sca;

    sia = ssa;
    sla = ssa;
    sxa = ssa;

    uia = usa;
    ula = usa;
    uxa = usa;

    sla = sia;
    sxa = sia;

    ula = uia;
    uxa = uia;

    dba = fta;
    lda = fta;
    lda = dba;


/**************************************************************************

Because of integral promotion, all integral expressions are evaluated
in type: int, unsigned int
         long or unsigned long
         long long or unsigned long long

Message 4120 is generated when an expression is implicitly widened to a
type of higher rank (e.g. int to long or long long, long to long long)
and:
   a) the conversion involves widening
   b) the expression contains one of the operators *, +, -, << or ~.

Message 4121 is generated for conversions performed explicitly with a cast.

The intention of these message is to prevent the programmer assuming (falsely)
that the expression has been evaluated in the wider type.

****************************************************************************/


/**************************************************************
OLD MESSAGES
============
:4120  Implicit conversion: complex expression of integral type to wider type.
:4121  Cast of complex expression of integral type to wider type.
**************************************************************/

                                            /*******************/
                                            /* int=32 * int=16 */
                                            /*******************/

    sla = sca << 1;                         /*        * 4120   */
    sla = sca + scb;                        /*        * 4120   */
    sla = sla + (sca + scb);                /*        * 4120   */
    sla = sca - scb;                        /*        * 4120   */
    sla = sca * 2;                          /*        * 4120   */
    sla = sca / 2;                          /*        *        */
    sla = uca << 1;                         /*        * 4120   */
    sla = uca + ucb;                        /*        * 4120   */
    sla = uca - ucb;                        /*        * 4120   */
    sla = uca * 2;                          /*        * 4120   */
    sla = uca / 2;                          /*        *        */
    sla = ~uca;                             /*        * 4120   */
    sla = ssa << 1;                         /*        * 4120   */
    sla = ssa + ssb;                        /*        * 4120   */
    sla = ssa - ssb;                        /*        * 4120   */
    sla = ssa * 2;                          /*        * 4120   */
    sla = ssa / 2;                          /*        *        */
    sla = sla + (sia + sia);                /*        * 4120   */
    sla = sla + sia + sia;                  /*        *        */
    sla = sla + (sia - sca);                /*        * 4120   */
    sla = sla + (sia * sca);                /*        * 4120   */
    sla = sla + (uca << 3);                 /*        * 4120   */
    sla = sla + (uca >> 3);                 /*        *        */
    sla = sla + (usa / 2);                  /*        *        */
    sla = sia << 4;                         /*        * 4120   */
    sla = sia << 1;                         /*        * 4120   */
    sla = sia + sib;                        /*        * 4120   */
    sla = sia - sib;                        /*        * 4120   */
    sla = sia * 2;                          /*        * 4120   */
    sla = sia / 2;                          /*        *        */

    sla = sla + (long)(sca << 1);           /*        *        */
                                            /*        * 4121   */
    sla = (long)(sia << 4);                 /*        *        */
                                            /*        * 4121   */
    sla = (signed long) (uca << 1);         /*        *        */
                                            /*        * 4121   */
    sla =               (uca << 1);         /*        * 4120   */

    ula = sca << 1;                         /*        * 4120   */
    ula = sca + scb;                        /*        * 4120   */
    ula = sca - scb;                        /*        * 4120   */
    ula = sca * 2;                          /*        * 4120   */
    ula = sca / 2;                          /*        *        */
    ula = uca << 1;                         /*        * 4120   */
    ula = uca + ucb;                        /*        * 4120   */
    ula = uca - ucb;                        /*        * 4120   */
    ula = uca * 2U;                         /*        * 4120   */
    ula = uca / 2U;                         /*        *        */
    ula = ~uca;                             /*        * 4120   */
    ula = usa << 1;                         /*        * 4120   */
    ula = usa + usb;                        /*        * 4120   */
    ula = usa - usb;                        /*        * 4120   */
    ula = usa * 2U;                         /*        * 4120   */
    ula = usa / 2U;                         /*        *        */
    ula = ~usa;                             /*        * 4120   */
    ula = uia << 4;                         /*        * 4120   */
    ula = uia << 1;                         /*        * 4120   */
    ula = uia + uib;                        /*        * 4120   */
    ula = uia - uib;                        /*        * 4120   */
    ula = uia * 2U;                         /*        * 4120   */
    ula = uia / 2U;                         /*        *        */
    ula = ~uia;                             /*        * 4120   */
    ula = usa + usa;                        /*        * 4120   */
    ula = uca + uca;                        /*        * 4120   */
    ula = ula + (uia + uia);                /*        * 4120   */
    ula = ula + uia + uia;                  /*        *        */
    ula = ula + (uia - uca);                /*        * 4120   */
    ula = ula + (uia * uca);                /*        * 4120   */
    ula = ula + (uca << 3);                 /*        * 4120   */
    ula = ula + (uca >> 3);                 /*        *        */
    ula = ula + (usa / 2U);                 /*        *        */
    ula = (unsigned long)(uia << 4);        /*        * 4121   */

    ula = (unsigned long)(uca + ucb);       /*        * 4121   */
    ula = (unsigned long)(usa - usb);       /*        * 4121   */
    ula = (unsigned long)(uca * 2);         /*        * 4121   */
    ula = (unsigned long)(usa * 2);         /*        * 4121   */
    ula = (unsigned long)(~uca);            /*        * 4121   */
    ula = (unsigned long)(~usa);            /*        * 4121   */
    ula = (unsigned long)(usa + usb);       /*        * 4121   */
    ula = (unsigned long)(uca - ucb);       /*        * 4121   */
    ula = (unsigned long)(uca << 1);        /*        *        */
                                            /*        * 4121   */


    sxa = sla + sla;                        /* 4120   * 4120   */
    sxa = sia + sia;                        /* 4120   * 4120   */
    sxa = ssa + ssa;                        /* 4120   * 4120   */
    sxa = sia << 4;                         /* 4120   * 4120   */
    sxa = (long long)(sia << 4);            /* 4121   * 4121   */

    uxa = ula + ula;                        /* 4120   * 4120   */
    uxa = uia + uia;                        /* 4120   * 4120   */
    uxa = usa + usa;                        /* 4120   * 4120   */
    uxa = uia << 4;                         /* 4120   * 4120   */
    uxa = (unsigned long long)(uia << 4);   /* 4121   * 4121   */


/**************************************************************
OLD MESSAGES
============
:4123  Implicit conversion: complex expression of type float to type double.
**************************************************************/
    dba = fta + fta;                        /* 4123   * 4123   */
    dba = fta + sia;                        /* 4123   * 4123   */
    dba = fta - uia;                        /* 4123   * 4123   */


/**************************************************************
OLD MESSAGES
============
:4126  Cast of complex expression of type float to type double.
**************************************************************/
    dba = (double)(fta + fta);              /* 4126   * 4126   */
    dba = (double)(fta + sia);              /* 4126   * 4126   */
    dba = (double)(fta - uia);              /* 4126   * 4126   */

/**************************************************************
OLD MESSAGES
============
:4124  Implicit conversion: complex expression of type float to type long double.
**************************************************************/
    lda = fta + fta;                        /* 4124   * 4124   */
    lda = fta + sia;                        /* 4124   * 4124   */
    lda = fta - uia;                        /* 4124   * 4124   */


/**************************************************************
OLD MESSAGES
============
:4127  Cast of complex expression of type float to type long double.
**************************************************************/
    lda = (long double)(fta + fta);         /* 4127   * 4127   */
    lda = (long double)(fta + sia);         /* 4127   * 4127   */
    lda = (long double)(fta - uia);         /* 4127   * 4127   */

/**************************************************************
OLD MESSAGES
============
:4125  Implicit conversion: complex expression of type double to type long double.
**************************************************************/
    lda = dba + dba;                        /* 4125   * 4125   */
    lda = dba + sia;                        /* 4125   * 4125   */
    lda = dba - uia;                        /* 4125   * 4125   */

/**************************************************************
OLD MESSAGES
============
:4128  Cast of complex expression of type double to type long double.
**************************************************************/
    lda = (long double)(dba + dba);         /* 4128   * 4128   */
    lda = (long double)(dba + sia);         /* 4128   * 4128   */
    lda = (long double)(dba - uia);         /* 4128   * 4128   */

/**************************************************************
:4117  Result of integer division operation implicitly converted to a floating type.
:4118  Result of integer division operation cast to a floating type.
**************************************************************/
    fta = uia / uib;                        /* 4117   * 4117   */
    fta += uia / uib;                       /* 4117   * 4117   */
    fta = fta + (float)(uia / uib);         /* 4118   * 4118   */
    fta += (float)(uia / uib);              /* 4118   * 4118   */

/**************************************************************
:4119  Result of floating point operation cast to an integral type.
OLD MESSAGES
============
:3815 Implicit conversion: double to int.
**************************************************************/
    sia = ( int )( 1234.5 / 35.7 );         /* 4119   * 4119   */
    sib =          1234.5 / 35.7  ;         /* 3815   * 3815   */
}
