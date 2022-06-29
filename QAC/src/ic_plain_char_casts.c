/********************************************************************************************

IMPLICIT CONVERSIONS - PLAIN CHAR

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 2006
#pragma PRQA_MESSAGES_OFF 2100
#pragma PRQA_MESSAGES_OFF 2101
#pragma PRQA_MESSAGES_OFF 2205
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2214
#pragma PRQA_MESSAGES_OFF 2889
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3450
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3625
#pragma PRQA_MESSAGES_OFF 4152
#pragma PRQA_MESSAGES_OFF 4413-4415
#pragma PRQA_MESSAGES_OFF 4431
#pragma PRQA_MESSAGES_OFF 4441
#pragma PRQA_MESSAGES_OFF 4451

#include "xample.h"



extern void plainchar(void)
{
/*************************************************************
OLD MESSAGES
============
:3700  Implicit conversion: char to signed char.
:3701  Implicit conversion: char to unsigned char.
:3702  Implicit conversion: char to short.
:3703  Implicit conversion: char to unsigned short.
:3704  Implicit conversion: char to int.
:3705  Implicit conversion: char to unsigned int.
:3706  Implicit conversion: char to long.
:3707  Implicit conversion: char to unsigned long.
:3832  Implicit conversion: char to long long.
:3833  Implicit conversion: char to unsigned long long.
:3708  Implicit conversion: char to float.
:3709  Implicit conversion: char to double.
:3710  Implicit conversion: char to long double.
*************************************************************/
    sca = pca;                                      /* 3700 */
    uca = pca;                                      /* 3701 */
    ssa = pca;                                      /* 3702 */
    usa = pca;                                      /* 3703 */
    sia = pca;                                      /* 3704 */
    uia = pca;                                      /* 3705 */
    sla = pca;                                      /* 3706 */
    ula = pca;                                      /* 3707 */
    sxa = pca;                                      /* 3832 */
    uxa = pca;                                      /* 3833 */
    fta = pca;                                      /* 3708 */
    dba = pca;                                      /* 3709 */
    lda = pca;                                      /* 3710 */

/*************************************************************
OLD MESSAGES
============
:3711  Implicit conversion: unsigned char to char.
:3722  Implicit conversion: signed char to char.
:3733  Implicit conversion: short to char.
:3744  Implicit conversion: unsigned short to char.
:3755  Implicit conversion: int to char.
:3766  Implicit conversion: unsigned int to char.
:3777  Implicit conversion: long to char.
:3788  Implicit conversion: unsigned long to char.
:3850  Implicit conversion: long long to char.
:3863  Implicit conversion: unsigned long long to char.
:3799  Implicit conversion: float to char.
:3810  Implicit conversion: double to char.
:3821  Implicit conversion: long double to char.
*************************************************************/
    pca = uca;                                      /* 3711 */
    pca = sca;                                      /* 3722 */
    pca = ssa;                                      /* 3733 */
    pca = usa;                                      /* 3744 */
    pca = sia;                                      /* 3755 */
    pca = uia;                                      /* 3766 */
    pca = sla;                                      /* 3777 */
    pca = ula;                                      /* 3788 */
    pca = sxa;                                      /* 3850 */
    pca = uxa;                                      /* 3863 */
    pca = fta;                                      /* 3799 */
    pca = dba;                                      /* 3810 */
    pca = lda;                                      /* 3821 */

    return;
}


/*************************************************************
OLD MESSAGES
============
:3900  char value returned from signed char %s().
:3901  char value returned from unsigned char %s().
:3902  char value returned from short %s().
:3903  char value returned from unsigned short %s().
:3904  char value returned from int %s().
:3905  char value returned from unsigned int %s().
:3906  char value returned from long %s().
:3907  char value returned from unsigned long %s().
:4032  char value returned from long long %s().
:4033  char value returned from unsigned long long %s().
:3908  char value returned from float %s().
:3909  char value returned from double %s().
:3910  char value returned from long double %s().
*************************************************************/
extern signed char        fsc(void) {return(pca);}  /* 3900 */
extern unsigned char      fuc(void) {return(pca);}  /* 3901 */
extern short              fss(void) {return(pca);}  /* 3902 */
extern unsigned short     fus(void) {return(pca);}  /* 3903 */
extern int                fsi(void) {return(pca);}  /* 3904 */
extern unsigned int       fui(void) {return(pca);}  /* 3905 */
extern long               fsl(void) {return(pca);}  /* 3906 */
extern unsigned long      ful(void) {return(pca);}  /* 3907 */
extern long long          fsx(void) {return(pca);}  /* 4032 */
extern unsigned long long fux(void) {return(pca);}  /* 4033 */
extern float              fft(void) {return(pca);}  /* 3908 */
extern double             fdb(void) {return(pca);}  /* 3909 */
extern long double        fld(void) {return(pca);}  /* 3910 */


/*************************************************************
OLD MESSAGES
============
:3922  signed char value returned from char %s().
:3911  unsigned char value returned from char %s().
:3933  short value returned from char %s().
:3944  unsigned short value returned from char %s().
:3955  int value returned from char %s().
:3966  unsigned int value returned from char %s().
:3977  long value returned from char %s().
:3988  unsigned long value returned from char %s().
:4050  long long value returned from char %s().
:4063  unsigned long long value returned from char %s().
:3999  float value returned from char %s().
:4010  double value returned from char %s().
:4021  long double value returned from char %s().
*************************************************************/

extern char fpc(int mode)
{
    if      (mode ==  0) return(sca);               /* 3922 */
    else if (mode ==  1) return(uca);               /* 3911 */
    else if (mode ==  2) return(ssa);               /* 3933 */
    else if (mode ==  3) return(usa);               /* 3944 */
    else if (mode ==  4) return(sia);               /* 3955 */
    else if (mode ==  5) return(uia);               /* 3966 */
    else if (mode ==  6) return(sla);               /* 3977 */
    else if (mode ==  7) return(ula);               /* 3988 */
    else if (mode ==  8) return(sxa);               /* 4050 */
    else if (mode ==  9) return(uxa);               /* 4063 */
    else if (mode == 10) return(fta);               /* 3999 */
    else if (mode == 11) return(dba);               /* 4010 */
    else                 return(lda);               /* 4021 */
}
