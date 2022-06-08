/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  :  CpuSbstTst_Cfg.h                                             **
**                                                                            **
**  DATE, TIME: 2021-08-16, 10:12:33                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuSbstTst.bmd /xdm                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CpuSbstTst configuration header file                       **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef CPUSBSTTST_CFG_H
#define CPUSBSTTST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Notification Function is a NULL */

/* Sbst Enter SafeTcore	*/ 
#define CPUSBSTTST_ENTER_NOTIF ( NULL_PTR ) 

/* Sbst Exit SafeTcore	*/
#define CPUSBSTTST_EXIT_NOTIF  ( NULL_PTR ) 
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Expected SBST CRC Value*/
/*SBST Expected CRC value is based on the DSPR and PSPR memory location, the 
default Expected CRC value used in safetlib is based on the SBST DSPR 0xd0000000 
to 0xd0000100 and SBST PSPR 0xc0000000 to 0xc0000040, if user changes the DSPR 
and PSPR memory location then the expected CRC value to be updated accordingly*/
#define SBST_EXPECTED_CRC_VALUE (0x900d900dU)
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/* Notification Function for CpuSbstTstEnterSafeTcore notification */
/* Notification Function is a NULL */


/* Notification Function for CpuSbstTstExitSafeTcore notification */
/* Notification Function is a NULL */
/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* CPUSBSTTST_CFG_H */
