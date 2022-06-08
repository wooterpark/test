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
**  FILENAME  :  PmuEccEdcTst_Cfg.h                                           **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:14                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : PmuEccEdcTst.bmd /xdm                             **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / GNU /Diab                                           **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : PmuEccEdcTst configuration header file                     **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef PMUECCEDCTST_CFG_H
#define PMUECCEDCTST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


#define PMU_ECC_EDC_TST_PF0_SELECT                  (1U)

#define PMU_ECC_EDC_TST_PF1_SELECT                  (1U)

#define PMU_ECC_EDC_TST_PF2_SELECT                  (0U) 

#define PMU_ECC_EDC_TST_PF3_SELECT                  (0U)

/* max number of flash banks supported */
#define PMU_ECC_EDC_TST_MAX_FLASHBANKS  ( 2U )


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
#endif  /* PMUECCEDCTST_CFG_H */
