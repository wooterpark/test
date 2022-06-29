/********************************************************************************************

ENUMERATIONS

********************************************************************************************/

#pragma PRQA_MESSAGES_OFF 0570
#pragma PRQA_MESSAGES_OFF 0702
#pragma PRQA_MESSAGES_OFF 776-779
#pragma PRQA_MESSAGES_OFF 1255
#pragma PRQA_MESSAGES_OFF 1277
#pragma PRQA_MESSAGES_OFF 1278
#pragma PRQA_MESSAGES_OFF 1263
#pragma PRQA_MESSAGES_OFF 1296
#pragma PRQA_MESSAGES_OFF 1304
#pragma PRQA_MESSAGES_OFF 1303
#pragma PRQA_MESSAGES_OFF 1880
#pragma PRQA_MESSAGES_OFF 1881
#pragma PRQA_MESSAGES_OFF 1882
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2006
#pragma PRQA_MESSAGES_OFF 2016
#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 2201-2214
#pragma PRQA_MESSAGES_OFF 2754
#pragma PRQA_MESSAGES_OFF 2889
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 3002
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3200
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3209
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3323
#pragma PRQA_MESSAGES_OFF 3341
#pragma PRQA_MESSAGES_OFF 3344
#pragma PRQA_MESSAGES_OFF 3416
#pragma PRQA_MESSAGES_OFF 3417
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3450
#pragma PRQA_MESSAGES_OFF 3470
#pragma PRQA_MESSAGES_OFF 3492
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 4332
#pragma PRQA_MESSAGES_OFF 4422
#pragma PRQA_MESSAGES_OFF 4423
#pragma PRQA_MESSAGES_OFF 4432
#pragma PRQA_MESSAGES_OFF 4521
#pragma PRQA_MESSAGES_OFF 4522
#pragma PRQA_MESSAGES_OFF 4527
#pragma PRQA_MESSAGES_OFF 4539


/************************************************************************************
:0647  [L] Number of enumeration constants exceeds 127 - program does not conform strictly to ISO:C90.
************************************************************************************/

typedef enum many {aa,ab,ac,ad,ae,af,ag,ah,ai,aj,ak,al,am, \
                   an,ao,ap,aq,ar,as,at,au,av,aw,ax,ay,az, \
                   ba,bb,bc,bd,be,bf,bg,bh,bi,bj,bk,bl,bm, \
                   bn,bo,bp,bq,br,bs,bt,bu,bv,bw,bx,by,bz, \
                   ca,cb,cc,cd,ce,cf,cg,ch,ci,cj,ck,cl,cm, \
                   cn,co,cp,cq,cr,cs,ct,cu,cv,cw,cx,cy,cz, \
                   da,db,dc,dd,de,df,dg,dh,di,dj,dk,dl,dm, \
                   dn,d0,dp,dq,dr,ds,dt,du,dv,dw,dx,dy,dz, \
                   ea,eb,ec,ed,ee,ef,eg,eh,ei,ej,ek,el,em, \
                   en,eo,ep,eq,er,es,et,eu,ev,ew,ex,ey,ez, \
                   fa,fb,fc,fd,fe,ff,fg,fh,fi,fj,fk,fl,fm, \
                   fn,fo,fp,fq,fr,fs,ft,fu,fv,fw,fx,fy,fz  } many_enums; /* 647 */

enum Colors {Red , Blue, Green} color;

/************************************************************************************
:0646  [C] Enumeration constants must have values representable as 'int's.
:1434  This enum constant is not representable in a 16 bit integer type.
************************************************************************************/

                                                /* int=32 ** int = 16 */
                                                /**********************/
enum Sport
{
    HUNTING  = 70000,                           /* 1434   ** 0646     */
    SHOOTING = 80000,                           /* 1434   ** 0646     */
    FISHING  = 90000                            /* 1434   ** 0646     */
};

enum Fruit {Lemon= -1, Orange=1, Apple=3} fruit;

enum Days {Monday=8 , Tuesday=6, Wednesday=4, Thursday=1} weekdays;

enum Control {Start=0x0001, Continue=0x0010, Pause=0x0100, Stop=0x1000} CtrlObj;


/************************************************************************************
:0722  Enum constant not explicitly initialized, but a previous constant has been.
:0723  Initialize none, first only, or all entries in this enumerator list.
************************************************************************************/
enum
{
    e1 = 1,
    e2,                                         /* 0722 */
    e3 = 3                                      /* 0723 */
} globEnum;


/************************************************************************************
:1271  Using a non-int expression to define an enum constant.
************************************************************************************/
enum euk
{
    England  = 0L,                              /* 1271 */
    Scotland = 1L,                              /* 1271 */
    Wales    = 2L,                              /* 1271 */
    Ireland  = 3L                               /* 1271 */
} uk;


static int globInt;

/************************************************************************************
:0546  [C] 'enum %s' has unknown content. Use of an enum tag with undefined content is not permitted.
************************************************************************************/
enum incomp_tag incomplete;                     /* 0546 */

extern enum Control bit_func(void);
extern void enum_args(enum Colors p1);
extern void int_args(int p1);

static int no_proto(p1)
int p1;
{
    return p1 + 1;
}

/************************************************************************************
OLD MESSAGES
============
:1400  Enum object is being compared with an enum constant of a different enum type using an equality operator.
:1410  Enum object is being compared with a constant, non-enum expression using an equality operator.
:1420  Enum object is being compared with an object of a different enum type using an equality operator.
:1440  Enum object is being compared with a non-constant, non-enum expression using an equality operator.
************************************************************************************/
void badEqualities(void)
{
    if (color == Thursday)  {}                  /* 1400 */
    if (color == 2) {}                          /* 1410 */
    if (color == globEnum) {}                   /* 1420 */
    if (color == globInt) {}                    /* 1440 */
}

/************************************************************************************
:1483  Enum object or constant passed as argument to function declared in K&R style.
OLD MESSAGES
============
:1401  Function parameter of enum type is being passed the value of an enum constant of a different enum type.
:1411  Function parameter of enum type is being passed the value of a constant, non-enum argument.
:1421  Function parameter of enum type is being passed the value of an object of a different enum type.
:1431  Function parameter of non-enum type is being passed the value of an object of enum type.
:1441  Function parameter of enum type is being passed the value of a non-constant, non-enum expression.
************************************************************************************/
void badParams(void)
{
    enum_args(Thursday);                        /* 1401 */
    enum_args(1);                               /* 1411 */
    enum_args(globEnum);                        /* 1421 */
    int_args(fruit);                            /* 1431 */
    enum_args(globInt);                         /* 1441 */
    no_proto(fruit);                            /* 1483 */
}

/************************************************************************************
:1317  Value of constant expression is not in the enum type to which it is being converted.
OLD MESSAGES
============
:1402  Object of enum type is being assigned the value of an enum constant of a different enum type.
:1412  Object of enum type is being assigned the value of a constant, non-enum expression.
:1422  Object of enum type is being assigned the value of an object of a different enum type.
:1432  Object of non-enum type is being assigned the value of an object of enum type.
:1442  Object of enum type is being assigned the value of a non-constant, non-enum expression.
:1482  Non-constant expression cast to enum type.
:1484  Constant expression cast to enum type.
************************************************************************************/
void badAssigns(int n)
{
    color=Wednesday;                            /* 1317 1402 */
    color=1;                                    /* 1412 */
    color=fruit;                                /* 1422 */
    globInt=fruit;                              /* 1432 */
    globEnum=globInt;                           /* 1442 */
    color=1;                                    /* 1412 */
    color=10;                                   /* 1317 1412 */
    color=(enum Colors)1;                       /* 1484 */
    color=(enum Colors)10;                      /* 1317 1484 */
    color=(enum Colors)n;                       /* 1482 */
}

/************************************************************************************
OLD MESSAGES
============
:1403  Function of enum type is returning the value of an enum constant of a different enum type.
:1413  Function of enum type is returning the value of a constant, non-enum expression.
:1423  Function of enum type is returning the value of an object of a different enum type.
:1443  Function of enum type is returning the value of a non-constant, non-enum expression.
************************************************************************************/
enum Colors badReturns(void)
{
    switch (globInt)
    {
    case 1:
        return Thursday;                        /* 1403 */

    case 3:
        return 0;                               /* 1413 */

    case 4:
        return fruit;                           /* 1423 */

    case 6:
        return globInt;                         /* 1443 */

    default:
        return Red;
    }
}

/************************************************************************************
OLD MESSAGES
============
:1433  Function of non-enum type is returning the value of an object of enum type.
************************************************************************************/
int moreBadReturns(void)
{
    return fruit;                               /* 1433 */
}

/************************************************************************************
OLD MESSAGES
============
:1404  Enum object is being compared with an enum constant of a different enum type using a relational operator.
:1414  Enum object is being compared with a constant, non-enum expression using a relational operator.
:1424  Enum object is being compared with an object of a different enum type using a relational operator.
:1444  Enum object is being compared with a non-constant, non-enum expression using a relational operator.
:1477  Object of enum type is being implicitly compared against zero in a controlling expression.
************************************************************************************/
void badCompares(void)
{
    if (color > Thursday)  {}                   /* 1404 */
    if (color > 1) {}                           /* 1414 */
    if (color > globEnum) {}                    /* 1424 */
    if (color > globInt) {}                     /* 1444 */
    if (color) {}                               /* 1477 */
}

/************************************************************************************
:1460  'Switch' label value, %s, not contained in enum type.
:1470  Numeric constant used as 'case' label with 'switch' expression of enum type.
:1472  Enum constant used as 'case' label with 'switch' expression of different enum type.
************************************************************************************/
void badSwitch(int pi)
{
    switch (color)
    {
    case 2:                                     /* 1470 */
        pi--;
        break;

    case 10:                                    /* 1460 1470 */
        pi -= 10;
        break;

    case Orange:                                /* 1472 */
        pi += 3;
        break;

    default:
        break;
    }
}

/************************************************************************************
:1318  Object of enum type is being modified with a compound assignment operator.
:1319  Object of enum type is being modified with an increment or decrement operator.
:1323  The sizeof operator has been applied to an enum constant.
OLD MESSAGES
============
:1461  Value of constant expression is not in the enum type to which it is being converted, but is bitwise OR of constants in the enum type.
:1473  The 2nd and 3rd operands of this conditional operator (? :) are of different enum types.
:1474  Object of enum type is being modified with a bitwise compound assignment operator.
:1479  Object of enum type is being modified with an arithmetic compound assignment operator.
:1480  Objects or constants of different enum types are operands of a bitwise operator.
:1481  Object of enum type is being modified with an increment or decrement operator.
************************************************************************************/
void badOperators(void)
{
    int n;
    color = globInt ? color : Lemon;            /* 1473      */
    color |= Blue;                              /* 1318 1474 */
    color += Blue;                              /* 1318 1479 */
    color++;                                    /* 1319 1481 */
    color = Blue | Thursday;                    /* 1422 1480 */
    if (bit_func() == (Start | Pause)) {}       /* 1461      */
    n = sizeof(Blue);                           /* 1323 3470 */
}
