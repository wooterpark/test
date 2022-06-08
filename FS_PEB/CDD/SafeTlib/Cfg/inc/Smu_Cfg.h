
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  :  Smu_Cfg.h                                                   **
**                                                                            **
**  DATE, TIME: 2021-09-26, 19:51:01                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Smu.bmd /xdm                                      **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SMU configuration header file                             **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SMU_CFG_H
#define SMU_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Smu.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#define SmuConfigSet_0         ((uint8)0)
#define SmuConfigSet_1         ((uint8)1)

/* Timeout value for function blocking spinlock */ 
#define SMU_SPINLOCK_TIMEOUT    ((uint32)(3000U))

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
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* SMU_CFG_H */
