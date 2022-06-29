#pragma PRQA_MESSAGES_OFF 1277,1278,2000,2982,2983,2984,3120,3198,3199,3203,3204,3227,3408,3447,3602,4131,4403,4533,4534,4543,4544

/********************************************************************************************

RIGHT HAND OPERAND OF SHIFT OPERATOR IS NEGATIVE OR TOO LARGE
=============================================================

OBSOLETE MESSAGES:

:0500  [U] Right operand of shift operator is negative - this is undefined.
:0501  [U] Right operand of shift operator is too large - this is undefined.

NEW MESSAGES:

:2790  Constant: Right hand operand of shift operator is negative or too large.
:2791  Definite: Right hand operand of shift operator is negative or too large.
:2792  Apparent: Right hand operand of shift operator is negative or too large.
:2793  Suspicious: Right hand operand of shift operator is negative or too large.

********************************************************************************************/

extern unsigned int uix;
extern   signed int six;

extern void f1(int sip1, int sip2, int n)
{
    unsigned int uia;
    signed   int sia;
    int          siy = -1;
    int          i;

/* CONSTANT */
    uia = uix << -1;                                    /* 2790           */
    sia = six << -1;                                    /* 2790           */


/* DEFINITE */
    if (sip1 < 0)
    {
        uia = uix << sip1;                              /* 2791           */
        sia = six << sip1;                              /* 2791           */
    }

/* APPARENT */
    uia = uix << sip1;                                  /* 2792           */
    sia = six << sip1;                                  /* 2792           */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        siy = siy + 1;
    }

    uia = uix << siy;                                   /* 2793           */
    sia = six << siy;                                   /* 2793           */

/* POSSIBLE */
    uia = uix << sip2;                                  /*                */
    sia = six << sip2;                                  /*                */
}


extern void f2(int sip1, int sip2, int n)
{
    unsigned int uia;
    signed   int sia;
    int          siy = 32;
    int          i;

/* CONSTANT */
    uia = uix << 32U;                                   /* 2790 2921      */
    sia = six << 32U;                                   /* 2790      2861 */


/* DEFINITE */
    if (sip1 > 31)
    {
        uia = uix << sip1;                              /* 2791           */
        sia = six << sip1;                              /* 2791           */
    }

/* APPARENT */
    uia = uix << sip1;                                  /* 2792           */
    sia = six << sip1;                                  /* 2792           */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        siy = siy - 1;
    }

    uia = uix << siy;                                   /* 2793           */
    sia = six << siy;                                   /* 2793           */

/* POSSIBLE */
    uia = uix << sip2;                                  /*                */
    sia = six << sip2;                                  /*                */
}


/********************************************************************************************

UNDEFINED RESULT FROM LEFT SHIFT OPERATIONS ON OPERAND OF SIGNED TYPE
=====================================================================

OBSOLETE MESSAGES:

:0271  [U] Left shift operation on constant signed expression generating an undefined value.
:0294  [U] Definite signed left shift operation generating an undefined value.
:0295  [U] Apparent signed left shift operation generating an undefined value.

NEW MESSAGES:

:2860  Constant: Undefined result from left shift operation on expression of signed type.
:2861  Definite: Undefined result from left shift operation on expression of signed type.
:2862  Apparent: Undefined result from left shift operation on expression of signed type.
:2863  Suspicious: Undefined result from left shift operation on expression of signed type.

********************************************************************************************/

extern void f3(int sip1, int sip2, int n)
{
    int sia;
    int sib = 0x1FFFFFFF;
    int i;

/* CONSTANT */
    sia = 0x1FFFFFFF << 3;                              /* 2860           */


/* DEFINITE */
    if (sip1 >= 0x1FFFFFFF)
    {
        sia = sip1 << 3;                                /* 2861           */
    }

/* APPARENT */
    sia = sip1 << 3;                                    /* 2862           */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        sib = sib > 1;
    }

    sia = sib << 3;                                     /* 2863           */

/* POSSIBLE */
    sia = sip2 << 3;                                    /*                */
}


extern void f4(int sip1, int sip2, int n)
{
    int sia;
    int sib = 0x1FFFFFFF;
    int siy = 3;
    int i;

/* CONSTANT */
    sia = 0x1FFFFFFF << 3;                              /* 2860           */


/* DEFINITE */
    if (sip1 >= 3)
    {
        sia = sib << sip1;                              /* 2861           */
    }

/* APPARENT */
    sia = sib << sip1;                                  /* 2862           */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        siy = siy - 1;
    }

    sia = sib << siy;                                   /* 2863           */


/* POSSIBLE */
    sia = sib << sip2;                                  /*                */
}


/********************************************************************************************

RIGHT HAND OPERAND OF SHIFT OPERATOR IS NEGATIVE OR TOO LARGE
=============================================================

OBSOLETE MESSAGES:

:3301  Truncation of bits in an unsigned left shift operation on a constant value.
:3371  Definite truncation of bits in an unsigned left shift operation.
:3381  Apparent truncation of bits in an unsigned left shift operation.


NEW MESSAGES:

:2920  Constant: Left shift operation on expression of unsigned type results in loss of high order bits.
:2921  Definite: Left shift operation on expression of unsigned type results in loss of high order bits.
:2922  Apparent: Left shift operation on expression of unsigned type results in loss of high order bits.
:2923  Suspicious: Left shift operation on expression of unsigned type results in loss of high order bits.

********************************************************************************************/

extern void f5(unsigned int uip1, unsigned int uip2, int n)
{
    unsigned int uia;
    unsigned int uib = 0x1FFFFFFFU;
    int          i;

/* CONSTANT */
    uia = 0x1FFFFFFFU << 4;                             /* 2920           */


/* DEFINITE */
    if (uip1 >= 0x1FFFFFFFU)
    {
        uia = uip1 << 4;                                /* 2921           */
    }

/* APPARENT */
    uia = uip1 << 4;                                    /* 2922           */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        uib = uib >> 1;
    }

    uia = uib << 4;                                     /* 2923           */

/* POSSIBLE */
    uia = uip2 << 4;                                    /*                */
}


extern void f6(int sip1, int sip2, int n)
{
    unsigned int uib = 0x1FFFFFFFU;
    unsigned int uiy = 4U;
    unsigned int uia;
    int          i;

/* CONSTANT */
    uia = 0x1FFFFFFFU << 4;                             /* 2920           */


/* DEFINITE */
    if (sip1 > 3)
    {
        uia = uib << sip1;                              /* 2921           */
    }

/* APPARENT */
    uia = uib << sip1;                                  /* 2922           */

/* SUSPICIOUS */
    for (i = 0; i < n; ++i)
    {
        uiy = uiy - 1U;
    }

    uia = uib << uiy;                                   /* 2923           */

/* POSSIBLE */
    uia = uib << sip2;                                  /*                */
}
