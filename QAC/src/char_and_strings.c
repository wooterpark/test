/*******************************************************************************************

CHAR TYPE and STRING LITERALS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0310
#pragma PRQA_MESSAGES_OFF 1292
#pragma PRQA_MESSAGES_OFF 2753
#pragma PRQA_MESSAGES_OFF 3122
#pragma PRQA_MESSAGES_OFF 3132
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3206
#pragma PRQA_MESSAGES_OFF 3210
#pragma PRQA_MESSAGES_OFF 3211
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3602


/*****************************************************************************
:3625  Type 'char' has been used in the declaration of an object or a function.
:3631  Type 'char' has been used in a cast.
:3632  Type 'char' has been used in the declaration of a typedef.
:3633  Type 'char' has been used in the operand of the sizeof operator.
*****************************************************************************/
extern char buffer[10];                 /* 3625 */
extern void chararg(char *pch);         /* 3625 */
extern char elc;                        /* 3625 */
extern char * pelc;                     /* 3625 */

unsigned char a = 0;
signed   char b = 0;
char          c = 0;                    /* 3625 */

typedef char tc;                        /* 3632 */
typedef char *tpc;                      /* 3632 */


extern void chartype(
int         n,
char        cx,                         /* 3625 */
char       *pc,                         /* 3625 */
const char *pca )                       /* 3625 */
{
/*****************************************************************************
:0753  String literal assigned to pointer which is not a 'pointer to const'.
*****************************************************************************/
    char *pstr = "A STRING LITERAL";    /* 3625 0753 */

    int   r;
    char  cl;                           /* 3625 */
    char *lpc;                          /* 3625 */
    tpc   pcx;                          /*      */


    cl = (char)n;                       /* 3631 */

    r = (int)sizeof(char);              /* 3633 */
    r = (int)sizeof(tc);                /*      */
    r = (int)sizeof(tpc);               /*      */

    lpc = (char *)&r;                   /* 3631 */
    pcx = (tpc)&r;                      /*      */



/*****************************************************************************
:0431  [C] Function argument points to a more heavily qualified type.
:0752  String literal passed as argument to function whose parameter is not a 'pointer to const'.
*****************************************************************************/
    chararg(pc);
    chararg("123");                     /* 0752 */
    chararg(pca);                       /* 0431 */

    return;
}



