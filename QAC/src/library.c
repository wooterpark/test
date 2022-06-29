/********************************************************************************************

LIBRARY

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 0702
#pragma PRQA_MESSAGES_OFF 1840
#pragma PRQA_MESSAGES_OFF 1290
#pragma PRQA_MESSAGES_OFF 2753
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3122
#pragma PRQA_MESSAGES_OFF 3132
#pragma PRQA_MESSAGES_OFF 3196
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3200
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3209
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 3631

#include <stdio.h>
#include <stdlib.h>

void foo(int si, float ft, double db, unsigned char *sc)
{
    void *pv = NULL;
    int   buf[100];
    char *pc;
    int  *pi;

/******************************************************************************
:0160  [U] Using unsupported conversion specifier number %s.
:0161  [U] Unknown length modifier used with 'i' or 'd' conversion specifier, number %s.
:0162  [U] Unknown length modifier used with 'o' conversion specifier, number %s.
:0163  [U] Unknown length modifier used with 'u' conversion specifier, number %s.
:0164  [U] Unknown length modifier used with 'x' conversion specifier, number %s.
:0165  [U] Unknown length modifier used with 'X' conversion specifier, number %s.
:0166  [U] Unknown length modifier used with 'f' conversion specifier, number %s.
:0167  [U] Unknown length modifier used with 'e' conversion specifier, number %s.
:0168  [U] Unknown length modifier used with 'E' conversion specifier, number %s.
:0169  [U] Unknown length modifier used with 'g' conversion specifier, number %s.
:0170  [U] Unknown length modifier used with 'G' conversion specifier, number %s.
:0171  [U] Unknown length modifier used with 'c' conversion specifier, number %s.
:0172  [U] Unknown length modifier used with '%%' conversion specifier, number %s.
:0173  [U] Unknown length modifier used with 's' conversion specifier, number %s.
:0174  [U] Unknown length modifier used with 'n' conversion specifier, number %s.
:0175  [U] Unknown length modifier used with 'p' conversion specifier, number %s.
:0176  [U] Incomplete conversion specifier, number %s.
:0177  [U] Field width of format conversion specifier exceeds 509 characters.
:0178  [U] Precision of format conversion specifier exceeds 509 characters.
:0179  [U] Argument type does not match conversion specifier number %s.
:0184  [U] Insufficient arguments to satisfy conversion specifier, number %s.
:0185  [U] Call contains more arguments than conversion specifiers.
:0186  [U] A call to this function must include at least one argument.
******************************************************************************/
    printf("%a");                               /* 0160 */
    printf("%#d",si);                           /* 0161 */
    printf("%Lo",si);                           /* 0162 */
    printf("%Lu",si);                           /* 0163 */
    printf("%Lx",si);                           /* 0164 */
    printf("%LX",si);                           /* 0165 */
    printf("%hf",ft);                           /* 0166 */
    printf("%he",ft);                           /* 0167 */
    printf("%hE",db);                           /* 0168 */
    printf("%hg",db);                           /* 0169 */
    printf("%hG",db);                           /* 0170 */
    printf("%hc",si);                           /* 0171 */
    printf("%h%d");                             /* 0172 */
    printf("%hs",sc);                           /* 0173 0179 */
    printf("aaa%n, &si");                       /* 0184 */
    printf("%hp",pv);                           /* 0175 */
    printf("%#",si);                            /* 0176 */
    printf("%510.510d",si);                     /* 0177 0178 */
    printf("%s",si);                            /* 0179 */
    printf("%s");                               /* 0184 */
    printf("abc", si);                          /* 0185 */
    printf();                                   /* 0186 0422 */

/******************************************************************************
:0190  [U] Using unsupported conversion specifier number %s.
:0191  [U] Unknown length modifier used with 'd/i/n' conversion specifier, number %s.
:0192  [U] Unknown length modifier used with 'o' conversion specifier, number %s.
:0193  [U] Unknown length modifier used with 'u' conversion specifier, number %s.
:0194  [U] Unknown length modifier used with 'x/X' conversion specifier, number %s.
:0195  [U] Unknown length modifier used with 'e/E/f/F/g/G' conversion specifier, number %s.
:0196  [U] Unknown length modifier used with 's' conversion specifier, number %s.
:0197  [U] Unknown length modifier used with 'p' conversion specifier, number %s.
:0198  [U] Unknown length modifier used with '%%' conversion specifier, number %s.
:0199  [U] Unknown length modifier used with '[' conversion specifier, number %s.
:0200  [U] Unknown length modifier used with 'c' conversion specifier, number %s.
:0201  [U] Incomplete conversion specifier, number %s.
:0202  [I] '-' character in '[]' conversion specification is implementation defined.
:0203  [U] Value of character prior to '-' in '[]' is greater than following character.
:0204  [U] Field width of format conversion specifier exceeds 509 characters.
:0206  [U] Argument type does not match conversion specifier number %s.
:0207  [U] 'scanf' expects address of objects being stored into.
:0208  [U] Same character occurs in scanset more than once.
******************************************************************************/

    scanf("%#",&si);                            /* 0190 */
    scanf("%Ld",&si);                           /* 0191 */
    scanf("%Lo",&si);                           /* 0192 */
    scanf("%Lu",&si);                           /* 0193 */
    scanf("%Lx",&si);                           /* 0194 */
    scanf("%hf",&ft);                           /* 0195 */
    scanf("%hs",sc);                            /* 0196 */
    scanf("%hp",&pv);                           /* 0197 */
    scanf("%h%d");                              /* 0198 */
    scanf("%L[ABC]", sc);                       /* 0199 */
    scanf("%hc",sc);                            /* 0200 */
    scanf("%h",&si);                            /* 0201 */
    scanf("%[a-f]s",sc);                        /* 0202 */
    scanf("%[p-f]s",sc);                        /* 0202 0203 */
    scanf("%510.1d",&si);                       /* 0204 */
    scanf("%d", sc);                            /* 0206 */
    scanf("%d", si);                            /* 0207 */
    scanf("%[aa]",sc);                          /* 0208 */


/******************************************************************************
:0235  [U] Unknown escape sequence.
:0695  Type given in sizeof is not compatible with the pointed to type used to cast malloc.
:0696  The size of the allocated memory block is smaller than the size of the object type addressed by the pointer cast.
:0697  The size of the allocated memory block is not an integral multiple of the size of the object type addressed by the pointer cast.
******************************************************************************/
    printf("ABC\z");                            /* 0235 */
    pc = (char *) malloc( sizeof(buf) );        /* 0695 */
    pi = (int *)  malloc(1);                    /* 0696 */
    pi = (int *)  malloc( sizeof(int) + 1);     /* 0697 */

}
