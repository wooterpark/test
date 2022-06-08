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
**  FILENAME  :  SafeWdgExtTlf_Cfg.h                                          **
**                                                                            **
**  DATE, TIME: 2016-08-03, 17:35:23                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgExtTlf.bmd /xdm                            **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SafeWdgExtTlf configuration header file                    **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SAFEWDGEXTTLF_CFG_H
#define SAFEWDGEXTTLF_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


#define SAFEWDGEXTTLF_CFG_PARAM_COUNT       (1U )

/*SYSPCFG0 register settings*/
/*Standby Enabled*/
#define SAFEWDGEXTTLF_STAND_BY_ENABLE 0x01U
/*SYSPCFG1 register settings*/
/*ERR pin monitor recovery time is set to 1 ms*/
#define SAFEWDGEXTTLF_ERRREC_TIME 0x0U
/*Safe state 2 delay is set to 0 ms*/
#define SAFEWDGEXTTLF_SS2DEL_TIME 0x0U
/*Err pin monitor recovery Disabled*/
#define SAFEWDGEXTTLF_ERR_REC_EN 0x0U
/*ERR pin monitor functionality while the system is in
SLEEP mode is disabled*/
#define SAFEWDGEXTTLF_ERRSLP_EN 0x0U
/*WDCFG1 register settings*/
/*watchdog functionality while the system is in SLEEP
mode is disabled*/
#define SAFEWDGEXTTLF_WDSLP_EN 0x0U
/*DEVCTRL register settings*/
/*reference voltage is disabled*/
#define SAFEWDGEXTTLF_VREF_EN 0x0U
/*communication LDO is disabled*/
#define SAFEWDGEXTTLF_COM_EN 0x0U
/*Tracker1 LDO is disabled*/
#define SAFEWDGEXTTLF_TRK1_EN 0x0U
/*Tracker2 LDO is disabled*/
#define SAFEWDGEXTTLF_TRK2_EN 0x0U
/*
--------------------------------------------------------------------------------
  Debug switch:
   TRUE: It allows user to ignore signature verification by watchdog and 
          calculate expected XOR mask required to generate required signature. 
   FALSE: Signatures are verified by TLF watchdog. Default generated value.
          This switch MUST be FALSE in production code.
--------------------------------------------------------------------------------
*/
#define _SAFEWDG_TLF_DEBUG_  (FALSE)

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
#endif  /*SAFEWDGEXTTLF_CFG_H */

