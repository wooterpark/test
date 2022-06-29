/*************************************************************
This include file should generate no messages
**************************************************************/
#if !defined E
#define E
extern int e;
#else
#error "Include file E has been included more than once"
#endif
