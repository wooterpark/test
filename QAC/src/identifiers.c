/********************************************************************************************

IDENTIFIERS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 2015
#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 2201
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2754
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3202
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3207
#pragma PRQA_MESSAGES_OFF 3210
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447


/***************************************************************************
:4150  The identifier '%s' may cause confusion because it contains only the letter 'l' and and the number '1'.
:4151  The identifier '%s' may cause confusion because it contains only the letter 'O' and the number '0'.
:4152  The identifier '%s' may cause confusion because the letter 'l' and the number '1' are adjacent.
:4153  The identifier '%s' may cause confusion because the letter 'O' and the number '0' are adjacent.
****************************************************************************/

extern int l1;                                  /* 4150 */
extern int O0;                                  /* 4151 */
extern int al1;                                 /* 4152 */
extern int MO0;                                 /* 4153 */




/***************************************************************************
The ISO specification requires that

   1) All external identifiers must be distinguishable within 6 characters
      while ignoring differences in upper and lower case. This requirement
      is particularly severe and is frequently ignored because all modern
      compilers and linkers are more tolerant.

   2) All internal identifiers must be distinguishable within 31 characters
      and alphabetic case IS significant.

   The warning messages associated with identifier lengths are
   controlled by a number of option settings (compiler personality).

   -XNAMELENGTH Specifies the number of significant characters in an
            external identifier

   -XCASE   When set, implements the ISO standard which specifies that
            alphabetic case should not be treated as significant for
            external identifiers.

   -NAMELENGTH Specifies the number of significant characters in
            internal identifiers.

   In the examples below messages are generated only in accordance with
   the QAC configuration options.

   Messages 0776 & 0778 are generated when identifiers are not distinguishable
   within the ISO specification regardless of the settings of -XN, -XC and -NA.

   Messages 0777 & 0779 are generated when identifiers are not distinguishable
   within the parameters specified by -XN, -XC and -NA


:0776  [L] External identifier matches other external identifier(s) (e.g. '%s') in first 6 characters - program does not conform strictly to ISO:C90.
:0777  [U] External identifier does not differ from other identifier(s) (e.g. '%s') within the specified number of significant characters.
:0778  [L] Identifier matches other identifier(s) (e.g. '%s') in first 31 characters - program does not conform strictly to ISO:C90.
:0779  [U] Identifier does not differ from other identifier(s) (e.g. '%s') within the specified number of significant characters.

****************************************************************************/


int a23456a;

int a23456b;                                    /* 0776 0777 */


int a23456c;                                    /* 0776 0777 */


static int a234567890123456789012345678901a;

static int a234567890123456789012345678901b;    /* 0778 0779 */


static int a234567890123456789012345678901c;    /* 0778 0779 */


/* Separate name spaces exist for

   1) Label names
   2) Tags of structures, unions and enums
   3) Members of structures and unions
   4) Ordinary identifiers

*/


/***************************************************************************
:0780  Another identifier '%s' is already in scope in a different namespace.
:0781  '%s' is being used as a structure/union member as well as being a label, tag or ordinary identifier.
:0782  This identifier, '%s', will still be in scope when the same identifier is declared later in a different namespace.
:0783  A subsequent declaration of '%s' means that it is being used both as a structure/union member and also as a label, tag or ordinary identifier.
***************************************************************************/

struct mode                                     /* 0782 0783 1577 1577 */
{
    int a;
    int b;
};

static long mode;                               /* 0780 1582 */

struct stag { int mode; };                      /* 0781 1582 */





/***************************************************************************
:0622  [C] The identifier '%s' has been declared both with and without linkage in the same scope.
:0627  [C] '%s' has different type to previous declaration in the same scope.
***************************************************************************/
typedef int t;
static long t;                                  /* 0622 0627 */





/***************************************************************************
ISO 7.1.2.1 Reserved Identifiers

1) All identifiers that begin with an underscore and either an uppercase
   letter or another underscore are always reserved for any use.
2) All identifiers that begin with an underscore are always reserved for
   use as identifiers with file scope in both the ordinary identifier and
   tag name spaces.
3) Each macro name listed in any of the following sections (including the
   future library directions) is reserved for any use if any of its
   associated headers is included
4) All identifiers with external linkage in any of the following sections
   (including the future library directions) are always reserved for use
   as identifiers with external linkage,
5) Each identifier with file scope listed in any of the following sections
   (including the future library directions) is reserved for use as an
   identifier with file scope in the same name space if any of its
   associated headers is included.

Any infringement on these reserved identifiers gives rise to undefined
behaviour.

:0602  [U] The identifier '%s' is reserved for use by the library.

****************************************************************************/


int __abc;                                      /* 0602 */
int __Bcd;                                      /* 0602 */
int _Cde;                                       /* 0602 */
int _abc;                                       /* 0602 */
int __1;                                        /* 0602 */
int _1;                                         /* 0602 */

struct fs
{
    int _x;                                     /*      */
    int __y;                                    /* 0602 */
    int _X;                                     /* 0602 */
};


typedef long LT;                                /* 0782 1577 */

void identifier(void)
{
    int __xyz;                                  /* 0602 */
    int __Xyz;                                  /* 0602 */
    int _Xyz;                                   /* 0602 */
    int _xyz;                                   /*      */
    struct bs
    {
        int _x;                                 /*      */
        int __y;                                /* 0602 */
        int _X;                                 /* 0602 */
    };


    _L1:                                        /* 0602 */
    __xyz = 1;


    __L1:                                       /* 0602 */
    __xyz = 2;


    _a1:                                        /*      */
    __xyz = 3;

/***************************************************************************
:0780  Another identifier '%s' is already in scope in a different namespace.
:1100  The label '%s' is also declared as a typedef.
***************************************************************************/

    LT:                                         /* 0780 1582 1100 */

    return;
}
