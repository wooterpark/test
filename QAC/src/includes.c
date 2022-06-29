/********************************************************************************************

INCLUDE FILES

********************************************************************************************/

#pragma PRQA_MESSAGES_OFF 2022
#pragma PRQA_MESSAGES_OFF 2754
#pragma PRQA_MESSAGES_OFF 3108

/********************************************************************************************
:0838  File '%1s' has already been included directly from within file '%2s'.
********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 4150

#include <abcdef.h>
#include "abcdef.h"                     /* 0838 */

/********************************************************************************************
:0839  File '%1s' has already been included indirectly from within file '%2s'.

The include file "nest.h" is #include'd from within "top,h"
********************************************************************************************/
#include "top.h"
#include "nest.h"                       /* 0839 */


#pragma PRQA_MESSAGES_OFF 0838
#pragma PRQA_MESSAGES_OFF 0839

/********************************************************************************************
:0815  [L] #include <...> file name does not conform strictly to ISO:C90.
:0816  [L] #include "..." file name does not conform strictly to ISO:C90.
:0287  [I] Header name contains character which is not a member of the basic source character set.

Strict conformance to the ISO standard requires that include file
names shall be restricted to a maximum of 6 alpha chars followed
by a single alpha char extension

If names exceed this limit on length or include non-alpha characters,
message 815 or 816 will be generated:
In practice these limits are seldom observed and so messages 815 and
816 will usually be suppressed.

********************************************************************************************/

#include <abcde1.h>                     /* 0815 */
#include "abcde1.h"                     /* 0816 */
#include <abcde$.h>                     /* 0815 0287 */
#include "abcde$.h"                     /* 0816 0287 */
#include <abcdefg.h>                    /* 0815 */
#include "abcdefg.h"                    /* 0816 */

#pragma PRQA_MESSAGES_OFF 0815
#pragma PRQA_MESSAGES_OFF 0816


/********************************************************************************************
:0832  Macro substitution in #include preprocessing directive.
********************************************************************************************/
#define INCFILE1 "abcde.h"
#define INCFILE2 <abcde.h>

#include INCFILE1                       /* 0832 */

#include INCFILE2                       /* 0832 */


/********************************************************************************************
:0843  / character used in an include file name.

The use of a / character in an include file name is usually indicative
of the presence of a path name.
********************************************************************************************/

#include <inc2/pqrst.h>                 /* 843 */
#include "inc2/pqrst.h"                 /* 843 */


/********************************************************************************************
:0831  [E] Use of '\\' in this '#include' line is a PC extension - this usage is non-portable.

The use of a \ character would also usually indicate the presence of a
path name in a PC environment. However the use of a \ character actually
gives rise to undefined behaviour (it could be interpreted as introducing
an escape sequence)
********************************************************************************************/

#include <inc2\pqrst.h>                 /* 0831 */
#include "inc2\pqrst.h"                 /* 0831 */




/********************************************************************************************
:0813  [U] Using any of the characters ' " or /* in '#include <%s>' gives undefined behaviour.
:0814  [U] Using the characters ' or /* in '#include "%s"' gives undefined behaviour.
:0815  [L] #include <...> file name does not conform strictly to ISO:C90.
:0816  [L] #include "..." file name does not conform strictly to ISO:C90.
:0843  / character used in an include file name.

There are other characters and character sequences which give
rise to undefined behaviour. In particular the use of single or double
quote characters or a / followed by a * (The start of a C comment).
********************************************************************************************/

#include <'abcde.h>                     /* 0813 0818 */
#include "'abcde.h"                     /* 0814 0818 */

#include <"abcde.h>                     /* 0813 0818 */

#include <a/* 0813 0818 0843 */bcde.h>  /* 0813 0818 0843 */
#include "a/* 0814 0818 0843 */bcde.h"  /* 0814 0818 0843 */



/********************************************************************************************
:0831  [E] Use of '\\' in this '#include' line is a PC extension - this usage is non-portable.
:0843  / character used in an include file name.
:0868  An absolute path has been specified in a #include statement.
********************************************************************************************/


#include <C:\QAC\include\ansi\abcde.h>  /* 831 868 0818 */
#include "C:\QAC\include\ansi\abcde.h"  /* 831 868 0818 */

#include <C:/QAC/include/ansi/abcde.h>  /* 843 868 0818 */
#include "C:/QAC/include/ansi/abcde.h"  /* 843 868 0818 */

#include <C:\abcde.h>                   /* 831 868 0818 */
#include "C:\abcde.h"                   /* 831 868 0818 */

/**************************************************************
Include File Protection

Various methods are used to protect include files against repeated inclusion

0883: Include file code is not protected against repeated inclusion

Message 0883 IS NOT generated for the following include files

--- inca.h ---
#ifndef A
#define A
extern int a;
#endif

--- incb.h ---
#ifndef B
#define B
extern int b;
#else
#error "Include file B has been included more than once"
#endif

--- incc.h ---
#ifdef C
#error "Include file C has been included more than once"
#else
#define C
extern int c;
#endif

--- incd.h ---
#if !defined(D)
#define D
extern int d;
#endif

--- ince.h ---
#if !defined E
#define E
extern int e;
#else
#error "Include file E has been included more than once"
#endif

**************************************************************/
#include "inca.h"
#include "incb.h"
#include "incc.h"
#include "incd.h"
#include "ince.h"


/*************************************************************
Message 0883 IS generated for all the following include files.
--- incj.h ---
#ifndef J
extern int j;
#endif
extern int j1;

--- inck.h ---
extern int k1;
#ifndef K
#define K
extern int k2;
#endif

--- incl.h ---
#ifndef L
#define L
extern int l;
#else
int l = 0;
#endif

--- incm.h ---
#ifndef M
#define M
#endif
extern int m;

--- incn.h ---
#ifndef N
#define N
#endif
#define NX

--- incp.h ---
#if !defined P
extern int p;
#endif
#define P

--- incq.h ---
#ifndef Q
#define QX
extern int q;
#endif

**************************************************************/
#include "incj.h"
#include "inck.h"
#include "incl.h"
#include "incm.h"
#include "incn.h"
#include "incp.h"
#include "incq.h"


int x;

/********************************************************************************************
:0861  This #include <%s> directive is redundant.
:0862  This #include "%s" directive is redundant.
********************************************************************************************/
