/********************************************************************************************

RESERVED IDENTIFIERS

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3210
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3602


/*****************************************************************************
:4600  The macro '%1s' is also defined in '<%2s>'.
:4601  The macro '%1s' is the name of an identifier in '<%2s>'.
:4602  The identifier '%1s' is declared as a macro in '<%2s>'.
:4603  The object/function '%1s'is being defined with the same name as an ordinary identifier defined in '<%2s>'.
:4604  The object/function '%1s' is being declared with the same name as an ordinary identifier defined in '<%2s>'.
:4605  The typedef '%1s' is also defined in '<%2s>'.
:4606  The typedef '%1s' has the same name as another ordinary identifier in '<%2s>'.
:4607  The enum constant '%1s' has the same name as another ordinary identifier in '<%2s>'.
:4608  The tag '%1s' is also defined in '<%2s>'.
*****************************************************************************/

#define        INT_MAX                  /* 4600 */            /* LIMITS  */
#define        acos                     /* 4601 */            /* MATH    */
extern void    DBL_MAX(void);           /* 4602 */            /* FLOAT   */
extern void    atan(void) { }           /* 4603 */            /* MATH    */
extern void    asin(void);              /* 4604 */            /* MATH    */
typedef int    float_t;                 /* 4605 */            /* MATH    */
typedef int    getc;                    /* 4606 */            /* STDIO   */
enum         { fclose };                /* 4607 */            /* STDIO   */
struct  tm   { int a; };                /* 4608 */            /* TIME    */

/*****************************************************************************
:4620  The macro '%1s' may also be defined as a macro in '<%2s>'.
:4621  The macro '%1s' may also be defined as a typedef in '<%2s>'.
:4622  The identifier '%1s' may be defined as a macro in '<%2s>'.
:4623  The typedef '%1s' may also be defined in '<%2s>'.
:4624  The ordinary identifier '%1s' may be defined as a typedef in '<%2s>'.
*****************************************************************************/

#define        INT1_MAX                 /* 4620 */             /* STDINT */
#define        uint3_t                  /* 4621 */             /* STDINT */
enum         { INT16_MIN };             /* 4622 */             /* STDINT */
typedef int    int16_t;                 /* 4623 */             /* STDINT */
extern int     uint16_t;                /* 4624 */             /* STDINT */

/*****************************************************************************
:4640  The macro '%1s' could conflict in the future with the name of a macro in '<%2s>'.
:4641  The identifier '%1s' could conflict in the future with the name of a macro in '<%2s>'.
:4642  The macro '%1s' could conflict in the future with the name of a function in '<%2s>'.
:4643  The identifier '%1s' could conflict in the future with the name of a function in '<%2s>'.
:4644  The macro '%1s' could conflict in the future with the name of a typedef in '<%2s>'.
:4645  The identifier '%1s' could conflict in the future with the name of a typedef in '<%2s>'.
*****************************************************************************/

#define        EABC                     /* 4640 */             /* ERRNO  */
enum         { EXYZ } ;                 /* 4641 */             /* ERRNO  */
#define        isb                      /* 4642 */             /* CTYPE  */
typedef int    tob;                     /* 4643 */             /* CTYPE  */
#define        intA_t                   /* 4644 */             /* STDINT */
extern int     intb_t;                  /* 4645 */             /* STDINT */

