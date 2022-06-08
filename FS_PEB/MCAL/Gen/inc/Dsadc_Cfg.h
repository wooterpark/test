/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME  : Dsadc_Cfg.h                                                  **
**                                                                           **
**  $CC VERSION : \main\8 $                                                  **
**                                                                           **
**  DATE, TIME: 2021-09-29, 16:08:36                                     **
**                                                                           **
**  GENERATOR : Build b141014-0350                                         **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : DSADC configuration generated out of ECU configuration    **
**                 file (Dsadc.bmd/.xdm)                                     **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
**                                                                           **
**  TRACEBILITY :                                                            **
**                                                                           **
******************************************************************************/
#ifndef DSADC_CFG_H
#define DSADC_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/



#define DSADC_MODULE_INSTANCE             ((uint8)0U)

/*SW Version Information*/
#define DSADC_SW_MAJOR_VERSION            (2U)
#define DSADC_SW_MINOR_VERSION            (2U)
#define DSADC_SW_PATCH_VERSION            (0U)

/*Number of DSADC modules present in the controller*/
#define DSADC_NUM_OF_CHANNELS              (6U)

/* Derived Configuration for DsadcDevErrorDetect */
#define DSADC_DEV_ERROR_DETECT            (STD_OFF)

/* Derived Configuration for DsadcVersionInfoApi */
#define DSADC_VERSION_INFO_API            (STD_OFF)

/* Derived Configuration for DsadcVersionInfoApi */
#define DSADC_RESET_SFR_INIT            (STD_OFF)


/* Derived Configuration for DsadcDeInitApi */
#define DSADC_DEINIT_API                  (STD_OFF)

/* Derived Configuration DsadcPBFixedAddress*/
#define DSADC_PB_FIXEDADDR                (STD_OFF)

/* Derived Configuration DsadcDebugSupport*/
#define DSADC_DEBUG_SUPPORT               (STD_OFF)

/*Configuration: DSADC_ENABLE_LIMIT_CHECK
Preprocessor switch for enabling the Limit Check feature. 
- if STD_ON, Limit checking feature of DSADC is Enabled 
- if STD_OFF,Limit checking feature of DSADC is Disabled 
*/
#define DSADC_ENABLE_LIMIT_CHECK          (STD_OFF)

/* Derived Configuration DsadcResolverSupport*/
#define DSADC_RESOLVER_SUPPORT            (STD_ON)




/* Derived Configuration Common mode hold voltage*/
#define DSADC_COMMON_MODE_HOLD_VOLTAGE            (STD_ON)


/* Derived initial configuration registers enabling.
    DSADC_INITIAL_CONFIGURATION is equal to STD_ON if TC27x DA step, 
    TC26x BB step, TC29x BB step */
#define DSADC_INITIAL_CONFIGURATION           (STD_OFF)

/* Configuration: Total number of Config Root */
#define DSADC_CONFIG_COUNT  (1U)

/* Defines number of global common mode hold voltage registers */
#define DSADC_MAX_CMHV_REG  (3U)


/*
Configuration: DSADC_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
#define DSADC_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)

/*
Configuration: DSADC_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
#define  DSADC_USER_MODE_INIT_API_ENABLE (STD_OFF)

/*Configuration: DSADC_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
#define  DSADC_USER_MODE_DEINIT_API_ENABLE (STD_OFF)

/*Configuration: DSADC_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
#define  DSADC_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)

/* Mask value for the GLOBCFG and GLOBRC sfrs */
#define DSADC_GLOBCFG_SFR_MSK               (0x005F3807U)
#define DSADC_GLOBRC_SFR_MSK                (0x003F003FU)


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

#endif  /*End of DSADC_CFG_H */

