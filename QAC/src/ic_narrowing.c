/********************************************************************************************

IMPLICIT CONVERSIONS - NARROWING

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 2006
#pragma PRQA_MESSAGES_OFF 2100
#pragma PRQA_MESSAGES_OFF 2101
#pragma PRQA_MESSAGES_OFF 2214
#pragma PRQA_MESSAGES_OFF 2889
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3203
#pragma PRQA_MESSAGES_OFF 3219
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3450
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 4460-4462

#include "xample.h"

extern void narrow (void)
{

/************************************************************
OLD MESSAGES
============
:3734  Implicit conversion: short to signed char.
:3756  Implicit conversion: int to signed char.
:3778  Implicit conversion: long to signed char.
:3851  Implicit conversion: long long to signed char.
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
    sca = ssa;                            /* 3734   * 3734   */
    sca = sia;                            /* 3756   * 3756   */
    sca = sla;                            /* 3778   * 3778   */
    sca = sxa;                            /* 3851   * 3851   */

/************************************************************
OLD MESSAGES
============
:3746  Implicit conversion: unsigned short to unsigned char.
:3768  Implicit conversion: unsigned int to unsigned char.
:3790  Implicit conversion: unsigned long to unsigned char.
:3865  Implicit conversion: unsigned long long to unsigned char.
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
    uca = usa;                            /* 3746   * 3746   */
    uca = uia;                            /* 3768   * 3768   */
    uca = ula;                            /* 3790   * 3790   */
    uca = uxa;                            /* 3865   * 3865   */

/************************************************************
OLD MESSAGES
============
:3758  Implicit conversion: int to short.
:3780  Implicit conversion: long to short.
:3853  Implicit conversion: long long to short.
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
    ssa = sia;                            /* 3758   *        */
    ssa = sla;                            /* 3780   * 3780   */
    ssa = sxa;                            /* 3853   * 3853   */

/************************************************************
OLD MESSAGES
============
:3770  Implicit conversion: unsigned int to unsigned short.
:3792  Implicit conversion: unsigned long to unsigned short.
:3867  Implicit conversion: unsigned long long to unsigned short.
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
    usa = uia;                            /* 3770   *        */
    usa = ula;                            /* 3792   * 3792   */
    usa = uxa;                            /* 3867   * 3867   */

/************************************************************
OLD MESSAGES
============
:3782  Implicit conversion: long to int.
:3855  Implicit conversion: long long to int.
*************************************************************/
                                          /*int=32 * int=16  */
                                          /*******************/
    sia = sla;                            /*       * 3782    */
    sia = sxa;                            /*3855   * 3855    */

/************************************************************
OLD MESSAGES
============
:3794  Implicit conversion: unsigned long to unsigned int.
:3869  Implicit conversion: unsigned long long to unsigned int.
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
    uia = ula;                            /*        * 3794   */
    uia = uxa;                            /* 3869   * 3869   */

/************************************************************
OLD MESSAGES
============
:3857  Implicit conversion: long long to long
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
    sla = sxa;                            /* 3857   * 3857   */

/************************************************************
OLD MESSAGES
============
:3871  Implicit conversion: unsigned long long to unsigned long.
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
    ula = uxa;                            /* 3871   * 3871   */

/************************************************************
OLD MESSAGES
============
:3819  Implicit conversion: double to float.
:3830  Implicit conversion: long double to float.
:3831  Implicit conversion: long double to double.
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
    fta = dba;                            /* 3819   * 3819   */
    fta = lda;                            /* 3830   * 3830   */
    dba = lda;                            /* 3831   * 3831   */

    return;
}

/************************************************************
OLD MESSAGES
============
:3934  short value returned from signed char %s().
:3956  int value returned from signed char %s().
:3978  long value returned from signed char %s().
:4051  long long value returned from signed char %s().
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
static signed char fsc(int mode)
{
    if      (mode == 0) return(ssa);      /* 3934   * 3934   */
    else if (mode == 1) return(sia);      /* 3956   * 3956   */
    else if (mode == 2) return(sla);      /* 3978   * 3978   */
    else                return(sxa);      /* 4051   * 4051   */
}

/************************************************************
OLD MESSAGES
============
:3946  unsigned short value returned from unsigned char %s().
:3968  unsigned int value returned from unsigned char %s().
:3990  unsigned long value returned from unsigned char %s().
:4065  unsigned long long value returned from unsigned char %s().
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
static unsigned char fuc(int mode)
{
    if      (mode == 0) return(usa);      /* 3946   * 3946   */
    else if (mode == 1) return(uia);      /* 3968   * 3968   */
    else if (mode == 2) return(ula);      /* 3990   * 3990   */
    else                return(uxa);      /* 4065   * 4065   */
}

/************************************************************
OLD MESSAGES
============
:3958  int value returned from short %s().
:3980  long value returned from short %s().
:4053  long long value returned from short %s().
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
static short fss(int mode)
{
    if      (mode == 0) return(sia);      /* 3958   *        */
    else if (mode == 1) return(sla);      /* 3980   * 3980   */
    else                return(sxa);      /* 4053   * 4053   */
}

/************************************************************
OLD MESSAGES
============
:3970  unsigned int value returned from unsigned short %s().
:3992  unsigned long value returned from unsigned short %s().
:4067  unsigned long long value returned from unsigned short %s().
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
static unsigned short fus(int mode)
{
    if      (mode == 0) return(uia);      /* 3970   *        */
    else if (mode == 1) return(ula);      /* 3992   * 3992   */
    else                return(uxa);      /* 4067   * 4067   */
}

/************************************************************
OLD MESSAGES
============
:3982  long value returned from int %s().
:4055  long long value returned from int %s().
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
static int fsi(int mode)
{
    if      (mode == 0) return(sla);      /*        * 3982   */
    else                return(sxa);      /* 4055   * 4055   */
}

/************************************************************
OLD MESSAGES
============
:3994  unsigned long value returned from unsigned int %s().
:4069  unsigned long long value returned from unsigned int %s().
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
static unsigned int fui(int mode)
{
    if      (mode == 0) return(ula);      /*        * 3994   */
    else                return(uxa);      /* 4069   * 4069   */
}

/************************************************************
OLD MESSAGES
============
:4057  long long value returned from long %s().
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
static long fsl(void)
{
    return(sxa);                          /* 4057   * 4057   */
}

/************************************************************
OLD MESSAGES
============
:4071  unsigned long long value returned from unsigned long %s().
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
static unsigned long ful(void)
{
    return(uxa);                          /* 4071   * 4071   */
}

/************************************************************
OLD MESSAGES
============
:4019  double value returned from float %s().
:4030  long double value returned from float %s().
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
static float fft(int mode)
{
    if      (mode == 0) return(dba);      /* 4019   * 4019   */
    else                return(lda);      /* 4030   * 4030   */
}

/************************************************************
OLD MESSAGES
============
:4031  long double value returned from double %s().
*************************************************************/
                                          /* int=32 * int=16 */
                                          /*******************/
static double fdb(void)
{
    return(lda);                          /* 4031   * 4031   */
}
