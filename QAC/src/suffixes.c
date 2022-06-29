/********************************************************************************************

SUFFIXES

*******************************************************************************************/
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3121
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3606

#include "xample.h"


extern void suffixes(void)

{

/************************************************************************
ISO 6.1.3.2 RULES:
==================
The type of an integer constant is the first of the corresponding list
in which its value can be represented.

UNSUFFIXED DECIMAL:             int, long, unsigned long
UNSUFFIXED OCTAL OR HEX:        int, unsigned int, long, unsigned long
SUFFIXED WITH U:                unsigned int, unsigned long
SUFFIXED WITH L:                long, unsigned long
SUFFIXED U and L:               unsigned long

The table below shows the type of an integer constant of various
magnitudes in different formats. Types shown are for a 16bit integer
implementation with 32bit types shown in brackets where they differ.
------------------------------------------------------------------------
Decimal/Hexadecimal Value |UNSUFFXD|UNSUFFXD|SUFFIXED|SUFFIXED|SUFFIXED|
                          | DECIMAL| HEX/OCT|  WITH U|  WITH L| WITH UL|
------------------------------------------------------------------------
32767      / 0x7FFF       |  SI    |  SI    |  UI    |   SL   |   UL   |
32768      / 0x8000       |  SL(SI)|  UI(SI)|  UI    |   SL   |   UL   |
65536      / 0x10000      |  SL(SI)|  SL(SI)|  UL(UI)|   SL   |   UL   |
2147483647 / 0x7FFFFFFF   |  SL(SI)|  SL(SI)|  UL(UI)|   SL   |   UL   |
2147483648 / 0x80000000   |  UL    |  UL(UI)|  UL(UI)|   UL   |   UL   |
------------------------------------------------------------------------
*************************************************************************/


/**********************************************************************
SUFFIXES ON DECIMAL CONSTANTS

:1278  Decimal constant includes a suffix.

**********************************************************************/
                                                /* int=32         * int=16         */
                                                /***********************************/
    uia = 1234U;                                /* 1278           * 1278           */
    sla = 1234L;                                /* 1278           * 1278           */
    ula = 1234UL;                               /* 1278           * 1278           */


#pragma PRQA_MESSAGES_OFF 1278

/**********************************************************************
SUFFIXES ON HEX CONSTANTS

:1277  Hex constant does not include a "U" suffix.
:1279  Hex constant includes an "L" suffix.

When int=16, 0x8000 is unsigned int
When int=32, 0x8000 is   signed int

**********************************************************************/

                                                /* int=32         * int=16              */
                                                /****************************************/
    uia = 0x8000;                               /* 1277      1290 * 1255 1277      1281 */
    sla = 0x1234L;                              /* 1277 1279      *      1277 1279      */
    ula = 0x1234UL;                             /*      1279      *           1279      */
    uxa = 0x12345ULL;                           /*      1279      *           1279      */


#pragma PRQA_MESSAGES_OFF 1277
#pragma PRQA_MESSAGES_OFF 1279

/**************************************************************************
IMPLICIT CONVERSION OF OTHER OPERAND IN EXPRESSION
--------------------------------------------------
:1250  Unsuffixed integer constant causes implicit conversion of other operand.
:1251  Suffixed integer constant causes implicit conversion of other operand.
:1274  Unsuffixed floating constant causes implicit conversion of other (floating) operand.
:1275  Suffixed floating constant causes implicit conversion of other (floating) operand.
:1263  Floating constant causes implicit conversion of other (integral) operand.

These warnings occur in expressions where a numeric constant causes
another operand to be implicitly converted to a different type. If this
behaviour is intended it would be better practice to introduce an
explicit cast. If it is not intended, it may be appropriate to apply
a (different) suffix to the constant

:1250  Unsuffixed integer constant causes implicit conversion of other operand.
:1800 The %1s operand (essential type: '%2s') will be implicitly converted to a floating type, '%3s', in this arithmetic operation.
:1820 The %1s operand is non-constant and 'essentially signed' (%2s) but will be implicitly converted to an unsigned type (%3s) in this arithmetic operation.
:4434  A non-constant expression of 'essentially signed' type (%1s) is being converted to unsigned type, '%2s' on assignment.
When int=16, 0x8000 is unsigned int and 32768 is signed long
When int=32, 0x8000 is   signed int and 32768 is signed int
**************************************************************************/

                                                /* int=32         * int=16              */
                                                /****************************************/
    uia = sia + 0x8000;                         /*      3760 4434 * 1250 3760 1255 1281 */
    sla = sia + 32768;                          /*                * 1250      1255      */
    uia = sia + 1234U;                          /* 1251 3760 1820 * 1251 3760      1820 */
    sla = sia + 1234L;                          /* 1251           * 1251                */
    ula = uia + 1234UL;                         /* 1251           * 1251                */
    dba = fta + 12.34;                          /* 1274           * 1274                */
    lda = dba + 12.34L;                         /* 1275           * 1275                */
    dba = sia + 12.34;                          /* 1263 3764 1800 * 1263 3764      1800 */
    fta = sia + 12.34F;                         /* 1263 3763 1800 * 1263 3763      1800 */




/****************************************************************************
IMPLICIT CONVERSION OF CONSTANTS IN EXPRESSIONS
-----------------------------------------------
:1252  Suffixed integer constant implicitly converted to different integer type.
:1253  Unsuffixed integer constant implicitly converted to different integer type.
:1261  Suffixed floating constant implicitly converted to different floating type.
:1262  Unsuffixed floating constant implicitly converted to different floating type.
:1260  Integer constant implicitly converted to a floating type.
:1820  The %1s operand is non-constant and 'essentially signed' (%2s) but will be implicitly converted to an unsigned type (%3s) in this arithmetic operation.
:1840  The %1s operand is constant, 'essentially signed' (%2s) and non-negative but will be implicitly converted to an unsigned type (%3s) in this arithmetic operation.
:1850  The %1s operand is 'essentially unsigned' (%2s) but will be implicitly converted to a signed type (%3s) in this arithmetic operation.

OLD MESSAGES
============
:3784 Implicit conversion: long to unsigned long.
These warnings are generated when a constant is implicitly
converted to another type in the process of evaluating an expression.
It may be appropriate to reconsider the specification of the
suffix and/or introduce an explicit cast
****************************************************************************/


                                                /* int=32         * int=16              */
                                                /****************************************/
    ula = ula + 1234L;                          /* 1252      1840 * 1252 1840           */
    sla = sla + 1234U;                          /* 1252 3784 1820 * 1252 1850           */

    uia = uia + 1234;                           /* 1253      1840 * 1253 1840           */
    sla = sla + 1234;                           /* 1253           * 1253                */
    ula = ula + 1234;                           /* 1253      1840 * 1253 1840           */

    dba = dba + 12.34F;                         /* 1261           * 1261                */
    lda = lda + 12.34F;                         /* 1261           * 1261                */

    lda = lda + 12.34;                          /* 1262           * 1262                */

    fta = fta + 1234;                           /* 1260      1800 * 1260 1800           */
    fta = fta + 1234U;                          /* 1260      1800 * 1260 1800           */
    fta = fta + (float)1234L;
    fta = fta + 1234.0F;
    dba = dba + 1234;                           /* 1260      1800 * 1260 1800           */
    lda = lda + 1234;                           /* 1260      1800 * 1260 1800           */



/***********************************************************************
IMPLICIT CONVERSION OF INTEGRAL CONSTANTS ON ASSIGNMENT
:1256  Suffixed integer constant implicitly converted to larger integer type on assignment.
:1257  Suffixed integer constant implicitly converted to smaller integer type on assignment.
:1290  An integer constant of 'essentially signed' type is being converted to unsigned type on assignment.
:1291  An integer constant of 'essentially unsigned' type is being converted to signed type on assignment.
:1298  An integer constant of 'essentially signed' type is being converted to floating type on assignment.
:1299  An integer constant of 'essentially unsigned' type is being converted to floating type on assignment.
OLD MESSAGES
============
:1276  Integer constant implicitly converted to floating type on assignment.

These messages are generated when a constant needs to be
converted before it is assigned. The messages imply that an
approriate suffix should be applied to the constant

No message is generated when an unsuffixed integer is
assigned to an integral type
*************************************************************************/

                                                /* int=32         * int=16         */
                                                /***********************************/
    uca = 123;                                  /* 1290           * 1290           */
    sca = 123;
    usa = 1234;                                 /* 1290           * 1290           */
    ssa = 1234;
    uia = 1234;                                 /* 1290           * 1290           */
    sla = 1234;
    ula = 1234;                                 /* 1290           * 1290           */

    sla = 1234U;                                /* 1291           * 1291           */
    sla = 1234UL;                               /* 1291           * 1291           */
    ula = 1234U;                              
    ula = 1234L;                                /* 1290           * 1290           */

    uca = 123U;                               
    uca = 123L;                                 /* 1257 1290      * 1257 1290      */
    uca = 123UL;                                /* 1257           * 1257           */
    sca = 123U;                                 /* 1291           * 1257           */
    sca = 123L;                                 /* 1257           * 1257           */
    sca = 123UL;                                /* 1257 1291      * 1257 1291      */

    usa = 1234U;                              
    usa = 1234L;                                /* 1257 1290      * 1257 1290      */
    usa = 1234UL;                               /* 1257           * 1257           */
    ssa = 1234U;                                /* 1291           * 1257           */
    ssa = 1234L;                                /* 1257           * 1257           */
    ssa = 1234UL;                               /* 1257 1291      * 1257 1291      */
    sia = 1234U;                                /* 1291           * 1257           */
    sia = 1234L;                                /* 1257           * 1257           */
    sia = 1234UL;                               /* 1257 1291      * 1257 1291      */
    uia = 1234L;                                /* 1257 1290      * 1257 1290      */
    uia = 1234UL;                               /* 1257           * 1257           */

    fta = 1234;                                 /* 1276 1298      * 1276 1298      */
    dba = 1234;                                 /* 1276 1298      * 1276 1298      */
    lda = 1234;                                 /* 1276 1298      * 1276 1298      */
    fta = 1234U;                                /* 1276 1299      * 1276 1299      */
    fta = 1234L;                                /* 1276 1298      * 1276 1298      */


/***********************************************************************
IMPLICIT CONVERSION OF FLOATING CONSTANT ON ASSIGNMENT
------------------------------------------------------
:1264  Suffixed floating constant implicitly converted to different floating type on assignment.
:1265  Unsuffixed floating constant implicitly converted to different floating type on assignment.
:1266  Floating constant implicitly converted to an integral type on assignment.

These messages occur when a floating constant has to be
converted before it is assigned. The messages imply that an
approriate suffix should be applied to the constant
*************************************************************************/

    dba = 12.34F;                               /* 1264           * 1264           */
    lda = 12.34F;                               /* 1264           * 1264           */
    fta = 12.34L;                               /* 1264           * 1264           */
    dba = 12.34L;                               /* 1264           * 1264           */

    lda = 12.34;                                /* 1265           * 1265           */
    fta = 12.34;                                /* 1265           * 1265           */

    sia = 12.34;                                /* 1266           * 1266           */
    uia = 12.34L;                               /* 1266           * 1266           */
    uia = 12.34F;                               /* 1266           * 1266           */


/************************************************************************
EXPLICIT CASTING IN ABSENCE OF A SUFFIX
---------------------------------------
:1259  Unsuffixed integer constant cast to a different integral type.
:1268  Unsuffixed floating constant cast to another type.

************************************************************************/

    uia = (unsigned int)1234;                   /* 1259           * 1259           */
    sla = (long)1234;                           /* 1259           * 1259           */
    ula = (unsigned long)1234;                  /* 1259           * 1259           */

    fta = (float)12.34;                         /* 1268           * 1268           */
    lda = (long double)12.34;                   /* 1268           * 1268           */



/************************************************************************
EXPLICIT CASTING OF AN INAPPROPRIATE SUFFIX
-------------------------------------------
:1258  Suffixed integer constant cast to a different integral type.
:1267  Suffixed floating constant cast to another type.
************************************************************************/

    sia = sia + (int)1234UL;                    /* 1258           * 1258           */
    sia = sia + (int)1234U;                     /* 1258           * 1258           */

    uia = uia + (unsigned int)1234UL;           /* 1258           * 1258           */
    uia = uia + (unsigned int)1234L;            /* 1258           * 1258           */

    ula = ula + (unsigned long)1234U;           /* 1258           * 1258           */
    ula = ula + (unsigned long)1234L;           /* 1258           * 1258           */

    sla = sla + (long)1234UL;                   /* 1258           * 1258           */
    sla = sla + (long)1234U;                    /* 1258           * 1258           */

    dba = (double)12.34F;                       /* 1267           * 1267           */
    dba = dba + (double)12.34F;                 /* 1267           * 1267           */
    dba = (double)12.34L;                       /* 1267           * 1267           */
    dba = dba + (double)12.34L;                 /* 1267           * 1267           */
    lda = (long double)12.34F;                  /* 1267           * 1267           */
    lda = lda + (long double)12.34F;            /* 1267           * 1267           */




/**********************************************************************
EXPLICIT CASTING FLOAT TO INT
-----------------------------
:1269  Floating constant cast to integral type.
**********************************************************************/
    sia = (int)12.34;                           /* 1269           * 1269           */
    sia = (int)12.34L;                          /* 1269           * 1269           */



/**********************************************************************
EXPLICIT CASTING INT TO FLOAT
-----------------------------
NO MESSAGE GENERATED
**********************************************************************/
    fta = (float)1234;
    dba = (double)1234;



/**********************************************************************
INTEGER CONSTANTS WITH MISSING OR INAPPROPRIATE SUFFIX

:1255  Unsuffixed integer constant is not of type int.
:1254  Suffix is not consistent with a type of unsigned long.
:1281  Integer literal constant is of an unsigned type but does not include a "U" suffix.
:1290  An integer constant of 'essentially signed' type is being converted to unsigned type on assignment.


**********************************************************************/
/* Integer constants which are NOT of type int
** but have NO SUFFIX. The addition of a suffix
** would make the type explicit */
                                                /* int=32         * int=16         */
                                                /***********************************/
    uia = 0x8000;                               /*           1290 * 1255 1281      */
    uia = 0x8000U;                              /*                *                */

    sla = 32768;                                /*                * 1255           */
    sla = 32768L;                               /*                *                */

    ula = 2147483648;                           /* 1255           * 1255           */
    ula = 2147483648UL;                         /*                *                */

    ula = 0x80000000;                           /* 1255 1281      * 1255 1281      */
    ula = 0x80000000UL;                         /*                *                */

/* Integer constants which do not have the
** most appropriate suffix. All are of type
** unsigned long but do not have a UL suffix */

    ula = 2147483648L;                          /* 1254 1257 1290 * 1254 1257      */
    ula = 2147483648U;                          /* 1256           * 1254           */
    ula = 2147483648UL;                         /*                *                */

    ula = 0x80000000L;                          /* 1254 1281      * 1254 1281      */
    ula = 0x80000000U;                          /* 1256           * 1254           */
    ula = 0x80000000UL;                         /*                *                */

    ula = 65536U;                               /* 1256           * 1254           */
    ula = 65536UL;                              /*                *                */

    ula = 0x10000U;                             /* 1256           * 1254           */
    ula = 0x10000UL;                            /*                *                */

    uia = 0x8000;                               /*           1290 * 1255 1281      */
    ula = 0x80000000L;                          /* 1254 1281      * 1254 1281      */


/**********************************************************************
INTEGER CONSTANTS WITH MISSING OR INAPPROPRIATE SUFFIX

:1280  A lowercase letter L (l) has been used in an integer or floating suffix.
**********************************************************************/
    ula = 123lu;                                /* 1280           * 1280           */
    lda = 12.34l;                               /* 1280           * 1280           */


/**********************************************************************
INTEGER CONSTANTS WITH A NON-STANDARD INTEGER SUFFIX
:1042  [E] Using I64 or UI64 as an integer constant suffix. This is a language extension.
**********************************************************************/
    uxa = 1234ui64;                             /* 1042           * 1042           */
    sxa = 5678i64;                              /* 1042           * 1042           */

    return;
}
