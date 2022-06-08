/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : SafeWdgInt_Cfg.h                                              **
**                                                                            **
**  DATE, TIME: 2018-05-02, 11:54:21                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION :SafeWdgInt.bmd /xdm                                **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / GNU / Diab                                          **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **                                                                      
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  :SafeWdgInt configuration header file                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SAFEWDGINT_CFG_H
#define SAFEWDGINT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

 /* number of available configurations for the SafeWdgInt test              */
#define SAFEWDGINT_CFG_COUNT (1u) 

/*
--------------------------------------------------------------------------------
  Debug switch:
   TRUE: It allows user to ignore signature verification by watchdog and 
          calculate expected watchdog signatures. 
   FALSE: Signatures are verified by internal watchdog. Default generated value.
          This switch MUST be FALSE in production code.
--------------------------------------------------------------------------------
*/
#define SAFEWDG_INT_DEBUG  (FALSE)

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

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

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /*SAFEWDGINT_CFG_H */
