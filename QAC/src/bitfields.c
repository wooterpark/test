/********************************************************************************************

BIT-FIELDS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0488
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2211
#pragma PRQA_MESSAGES_OFF 2214
#pragma PRQA_MESSAGES_OFF 2753
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3204
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3625


#define NA (3)

/********************************************************************************************

:3621  A bit-field is being defined as a member of a struct or union.
:3131  Hard coded 'magic' number '%s' used to define the size of a bit-field.

********************************************************************************************/

struct B1
{
    unsigned int  b1a:NA;               /* 3621 */
    unsigned int  b1b:3;                /* 3131 */
};

#pragma PRQA_MESSAGES_OFF 3131



/********************************************************************************************

:0634  [I] Bit-field is not declared explicitly as unsigned or signed.
:0635  [E] Bit-fields not of type int, signed int or unsigned int are not supported in ISO-C.
:3659  Unnamed zero-width bit-field declared with a signed type.
:3660  Named bit-field consisting of a single bit declared with a signed type.
:3663  Unnamed bit-field defined with non-zero width.
:3665  Unnamed bit-field consisting of a single bit declared with a signed type.

********************************************************************************************/

struct st                               /* 0634, 0635, 3663 */
{
    unsigned int   ui:12;
    signed int     si:10;
    int            pi:13;
    unsigned short us:12;
    signed short   ss:10;
    signed int       :1;                /* 3665 */
    short          ps:13;
    unsigned char  uc:7;
    signed int       :0;                /* 3659 */
    signed char    sc:6;
    char           pc:5;
    signed int     b1:1;                /* 3660 */
    unsigned int     :3;
};



extern struct st func(void);

void bitfields (const int x)
{
    struct st sta;
    int a;

/********************************************************************************************

:0476  [C] 'sizeof' cannot be applied to a bit-field.
:0475  [u] Operand of 'sizeof' is an expression designating a bit-field.
:3470  The operand of 'sizeof' is not an expression which designates either an object or a type.

********************************************************************************************/

    a = (int)sizeof(sta.ui);            /* 0476 */

    a = (int)sizeof(func().ui);         /* 0475 3307 3470 */

    sta.pi = x;

/********************************************************************************************

:3661  Plain int bit-field compared with zero.
:3662  Plain int bit-field compared with negative constant.

********************************************************************************************/

    if (sta.pi < 0) ++a;                /* 3661 3316 */

    if (sta.pi < -1) ++a;               /* 3662 3328 */

    return;
}
