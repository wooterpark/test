/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Wdg_17_Scu_Cfg.h                                              **
**                                                                            **
**  $CC VERSION : \main\43 $                                                 **
**                                                                            **
**  DATE, TIME: 2021-09-29, 16:08:33                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : WDG configuration generated out of ECU configuration       **
**                 file  (Wdg_17_Scu.bmd )  4.0.3                             **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/******************************************************************************/
#ifndef WDG_17_SCU_CFG_H
#define WDG_17_SCU_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#define WDG_17_SCU_AS_VERSION (403)

/* AUTOSAR specification version numbers */
#define WDG_17_SCU_AR_RELEASE_MAJOR_VERSION     (4U)
#define WDG_17_SCU_AR_RELEASE_MINOR_VERSION     (0U)
#define WDG_17_SCU_AR_RELEASE_REVISION_VERSION  (3U)
#define WDG_17_SCU_MAJOR_VERSION           (WDG_17_SCU_AR_RELEASE_MAJOR_VERSION)

/* Vendor specific implementation version information */
#define WDG_17_SCU_SW_MAJOR_VERSION   (3U)
#define WDG_17_SCU_SW_MINOR_VERSION   (5U)
#define WDG_17_SCU_SW_PATCH_VERSION   (0U)

/*
Configuration: WDG_DEV_ERROR_DETECT  WDG069: WDG045: WDG064:
- if ON, DET is Enabled
- if OFF,DET is Disabled
WDG069: Compile switch to enable/disable development error detection
for this module.
- ON if WdgDevErrorDetect is true
*/
#define WDG_DEV_ERROR_DETECT      (STD_OFF)

/* 
This parameter is defined by IFX.
UTP : AI00253342 
*/
#define WDG_UNLOCK_RESTRICTION    (STD_ON)

/*
Configuration: WDG_DISABLE_ALLOWED WDG070:
WDG070: Compile switch to allow/forbid disabling the watchdog
driver during runtime.
- ON if WdgDisableAllowed is true
*/
#define WDG_DISABLE_ALLOWED       (STD_ON)

/*
Configuration: WDG_VERSION_INFO_API WDG081:
WDG081:Compile switch to enable/disable the version information API
- ON if WdgVersionInfoApi is true
*/
#define WDG_VERSION_INFO_API      (STD_ON)


/*
Configuration: WDG_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
#define WDG_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)

/*
Configuration: WDG_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
#define  WDG_USER_MODE_INIT_API_ENABLE (STD_OFF)


/*Configuration: WDG_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init APIs
- if STD_OFF, Disable Protected mode in APIs other than Init APIs
*/
#define  WDG_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)

/*
The Max timeout entered by the user is converted to milliseconds
This is used in STC to check for limits.
*/
#define WDG_MAX_TIMEOUT           (20000U)

/*
The Initial timeout entered by the user is converted to milliseconds
This is used in Wdg_17_Init to set the STC window post Wdg_17_Init()
*/
#define WDG_INITIAL_TIMEOUT       ((uint16)10000U)

/* WDG_MAX_TIMERS : holds maximum number of WDG timers  */
#define WDG_MAX_TIMERS            (3U) 


/* WDG_MAXSAFE_TIMERS holds maximum number of WDG with safety used */
#define WDG_MAXSAFE_TIMERS        (0U)


/* WDG_MAXQM_TIMERS holds maximum number of WDG without safety used */
#define WDG_MAXQM_TIMERS          (3U)

/* WDG0 safety enabled */
/*WDG0_SAFETY_ENABLE: STD_ON - WDG0 enabled with safety
                      STD_OFF- WDG0 enabled without safety  */
#define WDG0_SAFETY_ENABLE        (STD_OFF)

/*WDG1_SAFETY_ENABLE: STD_ON - WDG1 enabled with safety
                      STD_OFF- WDG1 enabled without safety  */
#define WDG1_SAFETY_ENABLE        (STD_OFF)


/*WDG2_SAFETY_ENABLE: STD_ON - WDG2 enabled with safety
                      STD_OFF- WDG2 enabled without safety  */
#define WDG2_SAFETY_ENABLE        (STD_OFF)

/* WDG_SET_OFF_MODE_API: STD_ON - SetOffMode API enabled
                         STD_OFF- SetOffMode API disabled */
#define WDG_SET_OFF_MODE_API      (STD_OFF)

/* WDG_ENABLE_TIME_CHECK: STD_ON - execution time check enabled
                          STD_OFF - execution time check disabled  */
#define WDG_ENABLE_TIME_CHECK     (STD_OFF)

/*
Configuration: WdgDebugSupport -> WDG_DEBUG_SUPPORT
Switches ON, debug support.
*/
#define WDG_DEBUG_SUPPORT         (STD_ON)

/* Wdg Fixed Address usage */
#define WDG_PB_FIXEDADDR          (STD_OFF)

/* DEM related pre-compile switches */
#define WDG_DISABLE_REJECT_DEM_REPORT   (DISABLE_DEM_REPORT)
#define WDG_MODE_FAIL_DEM_REPORT        (DISABLE_DEM_REPORT)
#define WDG_INIT_FAILED_DEM_REPORT      (DISABLE_DEM_REPORT)


/* MAcro Definition for Timer unit used for servicing of the WDG*/
#define WDG_GTM_ATOM_CHANNEL  0x00U
#define WDG_GTM_TOM_CHANNEL   0x01U
/* Instance ID for WDG_17 module */
#define WDG_17_SCU_INSTANCE_ID   ((uint8)0U)
#define Wdg_17_ScuConf_WdgGeneral_WdgIndex (WDG_17_SCU_INSTANCE_ID)

/* Total no. of config sets */
#define WDG_17_CONFIG_COUNT   (1U)

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
#endif  /* WDG_17_SCU_CFG_H */

