/********************************************************************************************

OPERATOR PRECEDENCE

A number of messages are used to identify expressions which may be considered to
be inadequately parenthesised. The conditions under which these messages are
generated is determined by the sequence of operators in an expression.

A level of nesting is introduced when

1. An expression is surrounded by parentheses
2. An expression is contained within an array subscript operator []
3. An expression is used as an argument in a function call
4. An expression is the operand of a sizeof operator

Restrictions are imposed on any sequence of two operators which exist
AT THE LOWEST LEVEL OF NESTING WITHIN THE SAME NESTED EXPRESSION.
The sequence of operators is determined by the order in
which they are evaluated, not the order in which they exist in the code.

=======================================================
15      ( ) [ ] -> .                    L to R
14      ! ~ ++ -- + - * & (type) sizeof R to L    U

13      %                               L to R    B
13      * /                             L to R    B CO
12      + -                             L to R    B CO

11      << >>                           L to R    B NA
10      < <= >= >                       L to R    B NA
9       == !=                           L to R    B NA

8       &                               L to R    B
7       ^                               L to R    B
6       |                               L to R    B
5       &&                              L to R    B
4       ||                              L to R    B

3       ?:                              R to L    T

2       = += -= *= /= %= ^= |= <<= >>=  R to L
1       ,                               L to R
=======================================================

U    the set of Unary Operators:

B    the set of Binary Operators excluding the comma operator,
     the assignment operator and compound assignment operators.

T    the Ternary Operator

CO   the set of Common Operators: +, -, * , /

NA   the set of binary operators (excluding CO's) which are
     "non-associative" in their behaviour.


:3400  Extra parentheses recommended. A binary operation is the operand of a logical && or ||.
:3399  Extra parentheses recommended. A unary operation is the operand of a logical && or ||.
:3398  Extra parentheses recommended. A function call, array subscript, or member operation is the operand of a logical && or ||.
:3397  Extra parentheses recommended. A binary operation is the operand of a binary operator with different precedence.
:3396  Extra parentheses recommended. A binary operation is the operand of a conditional operator.
:3395  Extra parentheses recommended. A * or / operation is the operand of a + or - operator.
:3394  Extra parentheses recommended. A shift, relational or equality operation is the operand of a different operator with the same precedence.
:3393  Extra parentheses recommended. An arithmetic operation (* / + -) is the operand of a different operator with the same precedence.
:3392  Extra parentheses recommended. A shift, relational or equality operation is the operand of a second identical operator.
:3391  Extra parentheses recommended. A conditional operation is the operand of another conditional operator.
:3389  Extra parentheses recommended to clarify the ordering of a % operator and another arithmetic operator (* / % + -).

These messages will each be generated only once in any expression.

:3390  Expression is equivalent to: "%s"

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0488
#pragma PRQA_MESSAGES_OFF 0489
#pragma PRQA_MESSAGES_OFF 0502
#pragma PRQA_MESSAGES_OFF 0505
#pragma PRQA_MESSAGES_OFF 0506
#pragma PRQA_MESSAGES_OFF 0510
#pragma PRQA_MESSAGES_OFF 0584
#pragma PRQA_MESSAGES_OFF 0585
#pragma PRQA_MESSAGES_OFF 1278
#pragma PRQA_MESSAGES_OFF 1307
#pragma PRQA_MESSAGES_OFF 1336
#pragma PRQA_MESSAGES_OFF 1881
#pragma PRQA_MESSAGES_OFF 2100-2107
#pragma PRQA_MESSAGES_OFF 2205
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2214
#pragma PRQA_MESSAGES_OFF 2216
#pragma PRQA_MESSAGES_OFF 2814
#pragma PRQA_MESSAGES_OFF 2834
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 3103
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3132
#pragma PRQA_MESSAGES_OFF 3197
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3206
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3344
#pragma PRQA_MESSAGES_OFF 3401
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3416
#pragma PRQA_MESSAGES_OFF 3440
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3492
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3617
#pragma PRQA_MESSAGES_OFF 3671
#pragma PRQA_MESSAGES_OFF 3672
#pragma PRQA_MESSAGES_OFF 3673
#pragma PRQA_MESSAGES_OFF 3684
#pragma PRQA_MESSAGES_OFF 3689
#pragma PRQA_MESSAGES_OFF 4109
#pragma PRQA_MESSAGES_OFF 4112
#pragma PRQA_MESSAGES_OFF 4115
#pragma PRQA_MESSAGES_OFF 4116
#pragma PRQA_MESSAGES_OFF 4130
#pragma PRQA_MESSAGES_OFF 4131
#pragma PRQA_MESSAGES_OFF 4403-4405
#pragma PRQA_MESSAGES_OFF 4505
#pragma PRQA_MESSAGES_OFF 4532-4539
#pragma PRQA_MESSAGES_OFF 4558

extern int buf[];
extern int tbuf[][50];
extern int ifoo(int x);

struct S
{
    int x;
    int y;
    struct
    {
        int z;
    } *pst;
} ;

extern struct S *s;
extern struct S sl;

extern int      *pi;
extern int     **ppi;

extern long         rl;
extern int          r;
extern unsigned int ua;
extern unsigned int ub;
extern unsigned int uc;
extern unsigned int ur;
extern int      (*f[10])(int);


void f1(int a, int b, int c, int d, int e)
{
    sl = *s;

    r = a - b - c;
    r = a * b * c;
    r = a & b & c;
    r = a ^ b ^ c;
    r = a | b | c;
    r = a && b && c;
    r = a || b || c;

    r = buf[a * b] + c;
    r = ifoo(a * b) + c;
    r = sl.x + a;
    r = s->pst->z;
    r = a++;
    r = *pi;
    r = !a;
    r = *++pi;
    r = a - b--;
    r = a + b++;
    r = a-- + b;
    r = buf[b * c] + d;
    r = buf[a] * b * c;
    r = (a + b) > 200;
    rl = (long)a + 280L;
    r = s->x + a;
    r = a + *pi;
    r = *pi + a;
    r = a + **ppi;
    r = *pi + **ppi;
    r = a + ~b;
    r = (a > 200) && c;
    ur = ~ua & ub;
    ur = ~ua >> ub;
    r = buf[a] + s->y;
    r = tbuf[a*b][c] - d;
    pi = &buf[3];
    pi = &buf[3] + 2;
}

/***********************************************************************************
:3399  Extra parentheses recommended. A unary operation is the operand of a logical && or ||.
***********************************************************************************/
void f2(int a, int b, int c, int d, int e)
{
    ur = ua && ~ub;                     /* 3399 3390 */
    r = !a || b;                        /* 3399 3390 */
    r = *pi || b;                       /* 3399 3390 */
    r = a && (int)rl;                   /* 3399 3390 */
}

/***********************************************************************************
:3398  Extra parentheses recommended. A function call, array subscript, or member operation is the operand of a logical && or ||.
***********************************************************************************/
void f3(int a, int b, int c, int d, int e)
{
    r = buf[a] && b;                    /* 3398 3390 */
    r = ifoo(a + b) || c;               /* 3398 3390 */
    r = s->x && a;                      /* 3398 3390 */
    r = sl.x || b;                      /* 3398 3390 */
}

/***********************************************************************************
:3397  Extra parentheses recommended. A binary operation is the operand of a binary operator with different precedence.
:3400  Extra parentheses recommended. A binary operation is the operand of a logical && or ||.
***********************************************************************************/
void f4(int a, int b, int c, int d, int e)
{
    ur = ua & ub + uc;                  /* 3397 3390 */
    ur = ua & ub | uc;                  /* 3397 3390 */
    ur = ua << ub + uc;                 /* 3397 3390 */
    ur = ua >> ub | uc;                 /* 3397 3390 */
    r = a & b + c;                      /* 3397 3390 */
    r = a & b * c;                      /* 3397 3390 */
    r = a + b > 200;                    /* 3397 3390 */
    r = a + b & c;                      /* 3397 3390 */
    r = a + b >> c;                     /* 3397 3390 */
    r = a * b > 200;                    /* 3397 3390 */
    r = a * b & c;                      /* 3397 3390 */
    r = a * b >> c;                     /* 3397 3390 */
    r = a > b + 1;                      /* 3397 3390 */
    r = a & b | c;                      /* 3397 3390 */

    ur = ua && ub + uc;                 /* 3397 3400 3390 */
    ur = ua || ub ^ uc;                 /* 3397 3400 3390 */
    r = a && b || c;                    /* 3397 3400 3390 */
    r = a || b && c;                    /* 3397 3400 3390 */
    r = a > 200 && c;                   /* 3397 3400 3390 */
}

/***********************************************************************************
:3396  Extra parentheses recommended. A binary operation is the operand of a conditional operator.
***********************************************************************************/
void f5(int a, int b, int c, int d, int e)
{
    r = a == b ? a : (a - b);           /* 3396 3390 */
    r = a ? b + c : d;                  /* 3396 3390 */
    r = a ? b : c + d;                  /* 3396 3390 */
    r = a && b ? c : d;                 /* 3396 3390 */
}

/***********************************************************************************
:3395  Extra parentheses recommended. A * or / operation is the operand of a + or - operator.
***********************************************************************************/
void f6(int a, int b, int c, int d, int e)
{
    r = a + b * c;                      /* 3395 3390 */
    r = a + b / c;                      /* 3395 3390 */
    r = a - b * c;                      /* 3395 3390 */
    r = a - b / c;                      /* 3395 3390 */
    r = a + (b - c) * d;                /* 3395 3390 */
    r = buf[a] * b + c;                 /* 3395 3390 */
    r = a * (f[a+b])(c+2) + d;          /* 3395 3390 */
}

/***********************************************************************************
:3394  Extra parentheses recommended. A shift, relational or equality operation is the operand of a different operator with the same precedence.
***********************************************************************************/
void f7(int a, int b, int c, int d, int e)
{
    r = a == b != c;                    /* 3394 3390 */
    r = a << b >> c;                    /* 3394 3390 */
    r = a <  b >  c;                    /* 3394 3390 */
}

/***********************************************************************************
:3393  Extra parentheses recommended. An arithmetic operation (* / + -) is the operand of a different operator with the same precedence.
***********************************************************************************/
void f8(int a, int b, int c, int d, int e)
{
    r = a + b - c;                      /* 3393 3390 */
    r = a / b * c;                      /* 3393 3390 */
}

/***********************************************************************************
:3392  Extra parentheses recommended. A shift, relational or equality operation is the operand of a second identical operator.
***********************************************************************************/
void f9(int a, int b, int c, int d, int e)
{

    r = a << b << c;                    /* 3392 3390 */
    r = a >> b >> c;                    /* 3392 3390 */
    r = a <  b <  c;                    /* 3392 3390 */
    r = a <= b <= c;                    /* 3392 3390 */
    r = a >  b >  c;                    /* 3392 3390 */
    r = a >= b >= c;                    /* 3392 3390 */
    r = a == b == c;                    /* 3392 3390 */
    r = a != b != c;                    /* 3392 3390 */
}

/***********************************************************************************
:3391  Extra parentheses recommended. A conditional operation is the operand of another conditional operator.
***********************************************************************************/
void f10(int a, int b, int c, int d, int e)
{
    r = a ? b : c ? d : e;              /* 3391 3390 */
}

/***********************************************************************************
:3389  Extra parentheses recommended to clarify the ordering of a % operator and another arithmetic operator (* / % + -).
***********************************************************************************/
void f11(int a, int b, int c, int d, int e)
{
    r = a + b % c;                      /* 3389 3390 */
    r = a - b % c;                      /* 3389 3390 */
    r = a * b % c;                      /* 3389 3390 */
    r = a / b % c;                      /* 3389 3390 */
    r = a % b % c;                      /* 3389 3390 */
}
