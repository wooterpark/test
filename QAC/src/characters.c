/********************************************************************************************

CHARACTER SETS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0816
#pragma PRQA_MESSAGES_OFF 0862
#pragma PRQA_MESSAGES_OFF 1305
#pragma PRQA_MESSAGES_OFF 1292
#pragma PRQA_MESSAGES_OFF 2017
#pragma PRQA_MESSAGES_OFF 3116
#pragma PRQA_MESSAGES_OFF 3122
#pragma PRQA_MESSAGES_OFF 3123
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3434
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3609
#pragma PRQA_MESSAGES_OFF 3625


/********************************************************************************************
The basic source character set

:0285  [I] Character constant contains character which is not a member of the basic source character set.
:0286  [I] String literal contains character which is not a member of the basic source character set.
:0287  [I] Header name contains character which is not a member of the basic source character set.
:0289  [I] Source file '%s' has preprocessing tokens containing characters which are not members of the basic source character set.
:0299  [I] Source file '%s' includes #pragma directives containing characters which are not members of the basic source character set.

********************************************************************************************/

#include "abcde$.h"                                     /* 0287 */


const char *pcuc = "ABCDEFGHIJKLMNOPQRSTUVWZYZ";
const char *pclc = "abcdefghijklmnopqrstuvwxyz";
const char *pcnu = "0123456789";
const char *pcg1 = "!\"#%&\'()*+,-./:";
const char *pcg2 = ";<=>?[\\]^_{|}~";

/* Non-conforming character literals */
const char  pc_36 = '$';                                /* 0285 */
const char  pc_64 = '@';                                /* 0285 */
const char  pc_96 = '`';                                /* 0285 */


/* Non-conforming macro replacement list */

#define MACA ABC$                                       /* 0289 1002                         */
#define MACB ABC`                                       /*                                   */
#define MACC ABC@                                       /*                                   */


/* Non-conforming characters in pragmas */
#pragma ABC A$                                          /* 0299 1002                         */
#pragma ABC A`                                          /* These messages are only generated */
#pragma ABC A@                                          /* once per translation unit         */


/* Non-conforming string literals */
const char *ppc_36 = "$";                               /* 0286 */
const char *ppc_64 = "@";                               /* 0286 */
const char *ppc_96 = "`";                               /* 0286 */


/********************************************************************************************

:0235  [U] Unknown escape sequence.

********************************************************************************************/

/* ISO-C Escape sequences */

const char esa = '\a';
const char esb = '\b';
const char esf = '\f';
const char esn = '\n';
const char esr = '\r';
const char est = '\t';
const char esv = '\v';


const char esc = '\c';                                  /* 0235 */
const char esd = '\d';                                  /* 0235 */
const char ese = '\e';                                  /* 0235 */
const char esg = '\g';                                  /* 0235 */
const char esh = '\h';                                  /* 0235 */
const char esi = '\i';                                  /* 0235 */
const char esj = '\j';                                  /* 0235 */
const char esk = '\k';                                  /* 0235 */
const char esl = '\l';                                  /* 0235 */
const char esm = '\m';                                  /* 0235 */
const char eso = '\o';                                  /* 0235 */
const char esp = '\p';                                  /* 0235 */
const char esq = '\q';                                  /* 0235 */
const char ess = '\s';                                  /* 0235 */
const char esu = '\u';                                  /* 0235 */
const char esw = '\w';                                  /* 0235 */
const char esy = '\y';                                  /* 0235 */
const char esz = '\z';                                  /* 0235 */


/********************************************************************************************
Hex/Octal escape sequences

:3610  Hexadecimal escape sequence used.
:3628  Octal escape sequences used in a character constant or string literal.

********************************************************************************************/

const char *eshex = "ABC\x0D";                          /* 3610 */
const char *esoct = "ABC\15";                           /* 3628 */



/********************************************************************************************
Trigraphs

:3601  Trigraphs (??x) are an ISO feature.

********************************************************************************************/

/* ISO-C Trigraphs */

char tr1 = '??=';                                       /* 3601 */
char tr2 = '??(';                                       /* 3601 */
char tr3 = '??)';                                       /* 3601 */
char tr4 = '??'';                                       /* 3601 */
char tr5 = '??<';                                       /* 3601 */
char tr6 = '??!';                                       /* 3601 */
char tr7 = '??>';                                       /* 3601 */
char tr8 = '??-';                                       /* 3601 */

/********************************************************************************************
Wide characters

:0874  [U] Character string literal and wide character string literal are adjacent.
:0878  Using wide character or string literals.
:0284  [I] Multiple character constants have implementation defined values.

********************************************************************************************/


#define HELLO L"Hello"                                  /* 0878 */
#define WORLD " World.\n"

const unsigned char * text = L"Hello" "World.\n";       /* 0878 0874 */

char     mc = 'ax';                                     /* 0284 */
