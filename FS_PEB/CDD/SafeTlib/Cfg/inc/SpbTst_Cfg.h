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
**  FILENAME  :  SpbTst_Cfg.h                                                 **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:14                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SpbTst.bmd /xdm                                   **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SpbTst configuration header file                           **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SPBTST_CFG_H
#define SPBTST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SmuInt.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* SMU Alarm Group Index                                                      */
#define SPBTST_BUSERR_GRP                  ( (uint8)SMU_ALARM_GROUP3 )

/* SPB Peripherals Access Enable Error - ALM3[22]*/
#define SPBTST_SPB_ACC_ENB_ERR_STS         ( (uint32)1U << SMU_ALARM_22 )

/* SRI Bus Error - ALM3[30] */
#define SPBTST_SRI_BUS_ERR_STS             ( (uint32)1U << SMU_ALARM_30 )

/* SPB Bus Error - ALM3[31] */
#define SPBTST_SPB_BUS_ERR_STS             ( (uint32)1U << SMU_ALARM_31 )

/* number of available configurations for the SFR test                        */
#define SPB_TST_CFG_PARAM_COUNT     ( 1U ) 


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
/* Exported SFR test configuration                                            */


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* SPBTST_CFG_H */
