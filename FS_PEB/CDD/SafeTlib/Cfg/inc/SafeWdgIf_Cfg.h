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
**  FILENAME  : SafeWdgIf_Cfg.h                                               **
**                                                                            **
**  DATE, TIME: 2018-05-02, 11:54:20                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION :SafeWdgIf.bmd /xdm                                 **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / GNU /Diab                                           **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  :SafeWdgIf configuration header file                         **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SAFEWDGIF_CFG_H
#define SAFEWDGIF_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*Only internal watchdog is used*/
#define SWDG_INT_WDG_ONLY
#include "SafeWdgIf_Types.h"
#include "SafeWdgInt.h"
#define SAFEWDGIF_CFG_COUNT              ( 1u )

#define SafeWdgIf_CfgIntServiceFn(a)     SafeWdgInt_Service((a))
#define SafeWdgIf_CfgIntInitFn(a)        SafeWdgInt_Init((a))
#define SafeWdgIf_CfgIntDeInitFn()       SafeWdgInt_DeInit()
#define SafeWdgIf_CfgIntActivateFn()     SafeWdgInt_Activate()
#define SafeWdgIf_CfgIntGetSeedFn(a)     SafeWdgInt_GetSeed((a))
#define SafeWdgIf_CfgIntGetStateFn()     SafeWdgInt_GetState()
#define SafeWdgIf_CfgIntInfo()           (E_NOT_OK)
#define SafeWdgIf_CfgIntGetErrCntr(a)    (E_NOT_OK)
#define SafeWdgIf_CfgIntUserReqFn(a,b)   (E_NOT_OK)
#define SafeWdgIf_CfgIntJobResult()      (E_NOT_OK)

#define SafeWdgIf_CfgExtServiceFn(a)     (E_NOT_OK)
#define SafeWdgIf_CfgExtInitFn(a)        (E_NOT_OK)
#define SafeWdgIf_CfgExtDeInitFn()       (E_NOT_OK)
#define SafeWdgIf_CfgExtActivateFn()     (E_NOT_OK)
#define SafeWdgIf_CfgExtGetSeedFn(a)     (E_NOT_OK)
#define SafeWdgIf_CfgExtGetStateFn()     (E_NOT_OK)
#define SafeWdgIf_CfgExtUserReqFn(a,b)   (E_NOT_OK)
#define SafeWdgIf_CfgExtJobResult()      (E_NOT_OK)
#define SafeWdgIf_CfgExtGetErrCntr(a)    (E_NOT_OK)
#define SafeWdgIf_CfgExtTxDoneCallback(a)(E_NOT_OK)
#define SafeWdgIf_CfgExtInfo()           (E_NOT_OK)

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
#endif  /*SAFEWDGIF_CFG_H */
