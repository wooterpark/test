/********************************************************************************************
NEW MESSAGES
============
IMPLICIT CONVERSIONS - CONVERSION OF AN 'EFFECTIVELY BOOLEAN' EXPRESSION

:4401 An expression of 'essentially Boolean' type is being converted to character type, on assignment.
:4403 An expression of 'essentially Boolean' type is being converted to signed type, on assignment.
:4404 An expression of 'essentially Boolean' type is being converted to unsigned type, on assignment.
:4405 An expression of 'essentially Boolean' type is being converted to floating type, on assignment.
********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 3408,3447,3602,3625

extern char          pca;
extern signed char   sca;
extern unsigned char uca;
extern int           sia;
extern unsigned int  uia;
extern float         fta;

extern void pcf(char          pcp);
extern void scf(signed char   scp);
extern void ucf(unsigned char ucp);
extern void sif(signed int    sip);
extern void uif(unsigned int  uip);
extern void ftf(float         ftp);

extern long sla;
extern long slb;

#define BOOLEAN_EXP (sla > slb)

extern char fpc(void)
{
    pca = BOOLEAN_EXP;                             /* 4401 */
    pcf(BOOLEAN_EXP);                              /* 4401 */
    return (BOOLEAN_EXP);                          /* 4401 */
}

extern signed char fsc(void)
{
    sca = BOOLEAN_EXP;                             /* 4403 */
    scf(BOOLEAN_EXP);                              /* 4403 */
    return (BOOLEAN_EXP);                          /* 4403 */
}


extern unsigned char fuc(void)
{
    uca = BOOLEAN_EXP;                             /* 4404 */
    ucf(BOOLEAN_EXP);                              /* 4404 */
    return (BOOLEAN_EXP);                          /* 4404 */
}


extern int fsi(void)
{
    sia = BOOLEAN_EXP;                             /* 4403 */
    sif(BOOLEAN_EXP);                              /* 4403 */
    return (BOOLEAN_EXP);                          /* 4403 */
}


extern unsigned int fui(void)
{
    uia = BOOLEAN_EXP;                             /* 4404 */
    uif(BOOLEAN_EXP);                              /* 4404 */
    return (BOOLEAN_EXP);                          /* 4404 */
}


extern float fft(void)
{
    fta = BOOLEAN_EXP;                             /* 4405 */
    ftf(BOOLEAN_EXP);                              /* 4405 */
    return (BOOLEAN_EXP);                          /* 4405 */
}
