/********************************************************************************************

TYPEDEFS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 553,2017,2021,2022,2211,2213,3132,3205,3206,3207,3210,3211,3219,3222,3223,3308,3408,3414,3447,3448,3602,3603,4600


/***********************************************************
:3260  Typedef defined with more than 2 levels of indirection.
***********************************************************/


typedef int *                   T1A;                                         /*      */
typedef int *                   T1B[2];                                      /*      */
typedef int                  (* T1C)[2];                                     /*      */

typedef int * *                 T2A;                                         /*      */
typedef T1A *                   T2B;                                         /*      */
typedef int * *                 T2C[2];                                      /*      */
typedef int  (* *               T2D)[2];                                     /*      */


typedef int * * *               T3A;                                         /* 3260 */
typedef T1A * *                 T3B;                                         /* 3260 */
typedef T2A *                   T3C;                                         /* 3260 */
typedef T2B *                   T3D;                                         /* 3260 */
typedef int * * *               T3E[2];                                      /* 3260 */
typedef int (* * *              T3F)[2];                                     /* 3260 */
typedef int * (* *              T3G)[2];                                     /* 3260 */
typedef int * *              (* T3H)[2];                                     /* 3260 */


/***********************************************************
:3261  Member of struct/union defined with more than 2 levels of indirection.
***********************************************************/

struct ST1
{
    T1A                         M1A;                                         /*      */
    T1B                         M1B;                                         /*      */
    T1C                         M1C;                                         /*      */
    int *                       M1H;                                         /*      */
    int *                       M1I[2];                                      /*      */
    int                      (* M1J)[2];                                     /*      */
};

struct ST2
{
    T2A                         M2A;                                         /*      */
    T2B                         M2B;                                         /*      */
    T2C                         M2C;                                         /*      */
    T2D                         M2D;                                         /*      */
    int * *                     M2G;                                         /*      */
    T1A *                       M2H;                                         /*      */
    int * *                     M2I[2];                                      /*      */
    int                    (* * M2J)[2];                                     /*      */
};


struct ST3
{
    T3A                         M3A;                                         /* 3261 */
    T3B                         M3B;                                         /* 3261 */
    T3C                         M3C;                                         /* 3261 */
    T3D                         M3D;                                         /* 3261 */
    T3E                         M3E;                                         /* 3261 */
    T3F                         M3F;                                         /* 3261 */
    T3G                         M3G;                                         /* 3261 */
    T3H                         M3H;                                         /* 3261 */
    int * * *                   M3O;                                         /* 3261 */
    T1A * *                     M3P;                                         /* 3261 */
    T2A *                       M3Q;                                         /* 3261 */
    T2B *                       M3R;                                         /* 3261 */
    int * * *                   M3S[2];                                      /* 3261 */
    int (* * *                  M3T)[2];                                     /* 3261 */
    int * (* *                  M3U)[2];                                     /* 3261 */
    int * *                  (* M3V)[2];                                     /* 3261 */
};


/***********************************************************
:3262  Object defined or declared with more than 2 levels of indirection.
***********************************************************/

    extern T1A                  V1A;                                         /*      */
    extern T1B                  V1B;                                         /*      */
    extern T1C                  V1C;                                         /*      */
    extern int *                V1H;                                         /*      */
    extern int *                V1I[2];                                      /*      */
    extern int               (* V1J)[2];                                     /*      */


    extern T2A                  V2A;                                         /*      */
    extern T2B                  V2B;                                         /*      */
    extern T2C                  V2C;                                         /*      */
    extern T2D                  V2D;                                         /*      */
    extern int * *              V2G;                                         /*      */
    extern T1A *                V2H;                                         /*      */
    extern int * *              V2I[2];                                      /*      */
    extern int  (* *            V2J)[2];                                     /*      */


    extern T3A                  V3A;                                         /* 3262 */
    extern T3B                  V3B;                                         /* 3262 */
    extern T3C                  V3C;                                         /* 3262 */
    extern T3D                  V3D;                                         /* 3262 */
    extern T3E                  V3E;                                         /* 3262 */
    extern T3F                  V3F;                                         /* 3262 */
    extern T3G                  V3G;                                         /* 3262 */
    extern T3H                  V3H;                                         /* 3262 */
    extern int * * *            V3O;                                         /* 3262 */
    extern T1A * *              V3P;                                         /* 3262 */
    extern T2A *                V3Q;                                         /* 3262 */
    extern T2B *                V3R;                                         /* 3262 */
    extern int * * *            V3S[2];                                      /* 3262 */
    extern int (* * *           V3T)[2];                                     /* 3262 */
    extern int * (* *           V3U)[2];                                     /* 3262 */
    extern int * *           (* V3V)[2];                                     /* 3262 */

    extern void F1(
    T1A                         P1A,                                         /*      */
    T1B                         P1B,                                         /*      */
    T1C                         P1C,                                         /*      */
    int *                       P1H,                                         /*      */
    int *                       P1I[2],                                      /*      */
    int                      (* P1J)[2]                                      /*      */
    );

    extern void F2(
    T2A                         P2A,                                         /*      */
    T2B                         P2B,                                         /*      */
    T2C                         P2C,                                         /* 3262 */
    T2D                         P2D,                                         /*      */
    int * *                     P2G,                                         /*      */
    T1A *                       P2H,                                         /*      */
    int * *                     P2I[2],                                      /* 3262 */
    int  (* *                   P2J)[2]                                      /*      */
    );


    extern void F3(
    T3A                         P3A,                                         /* 3262 */
    T3B                         P3B,                                         /* 3262 */
    T3C                         P3C,                                         /* 3262 */
    T3D                         P3D,                                         /* 3262 */
    T3E                         P3E,                                         /* 3262 */
    T3F                         P3F,                                         /* 3262 */
    T3G                         P3G,                                         /* 3262 */
    T3H                         P3H,                                         /* 3262 */
    int * * *                   P3O,                                         /* 3262 */
    T1A * *                     P3P,                                         /* 3262 */
    T2A *                       P3Q,                                         /* 3262 */
    T2B *                       P3R,                                         /* 3262 */
    int * * *                   P3S[2],                                      /* 3262 */
    int (* * *                  P3T)[2],                                     /* 3262 */
    int * (* *                  P3U)[2],                                     /* 3262 */
    int * *                  (* P3V)[2]                                      /* 3262 */
    );


/***********************************************************
:3263  Function defined or declared with a return type which has more than 2 levels of indirection.
***********************************************************/

    extern T1A                  F1A(void);                                   /*      */
    extern T1C                  F1C(void);                                   /*      */
    extern int *                F1H(void);                                   /*      */
    extern int               (* F1J(void))[2];                               /*      */


    extern T2A                  F2A(void);                                   /*      */
    extern T2B                  F2B(void);                                   /*      */
    extern T2D                  F2D(void);                                   /*      */
    extern int * *              F2G(void);                                   /*      */
    extern T1A *                F2H(void);                                   /*      */
    extern int *             (* F2I(void))[2];                               /*      */
    extern int             (* * F2J(void))[2];                               /*      */


    extern T3A                  F3A(void);                                   /* 3263 */
    extern T3B                  F3B(void);                                   /* 3263 */
    extern T3C                  F3C(void);                                   /* 3263 */
    extern T3D                  F3D(void);                                   /* 3263 */
    extern T3F                  F3F(void);                                   /* 3263 */
    extern T3G                  F3G(void);                                   /* 3263 */
    extern T3H                  F3H(void);                                   /* 3263 */
    extern int * * *            F3O(void);                                   /* 3263 */
    extern T1A * *              F3P(void);                                   /* 3263 */
    extern T2A *                F3Q(void);                                   /* 3263 */
    extern T2B *                F3R(void);                                   /* 3263 */
    extern int * *           (* F3S(void))[2];                               /* 3263 */
    extern int           (* * * F3T(void))[2];                               /* 3263 */
    extern int *           (* * F3U(void))[2];                               /* 3263 */
    extern int * *           (* F3V(void))[2];                               /* 3263 */
