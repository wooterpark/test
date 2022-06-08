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
**  FILENAME  :  CpuMpuTst_Cfg.h                                              **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:12                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuMpuTst.bmd /xdm                                **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CpuMpuTst configuration header file                        **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef CPUMPUTST_CFG_H
#define CPUMPUTST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/



/* Set of protection registers (DPRE_x, DPWE_x, CPXE_x) to use for testing
   Valid Range: 0..3
*/
#define CPU_MPU_TST_PROT_REGISTER_SET               ( 1U )

/* Total number of data protection ranges available:                        */
#define CPU_MPU_TST_DATA_RANGE_COUNT                ( 16U )

/* Total number of code protection ranges available:                        */
#define CPU_MPU_TST_CODE_RANGE_COUNT                ( 8U )

/* Number of different test configuration sets:                             */
#define CPU_MPU_TST_CFG_PARAM_COUNT                 ( 1U )
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
#endif  /* CPUMPUTST_CFG_H */
