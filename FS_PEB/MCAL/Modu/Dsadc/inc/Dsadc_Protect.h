/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Dsadc_Protect.h $                                          **
**                                                                            **
**   $CC VERSION : \main\2 $                                                  **
**                                                                            **
**   $DATE       : 2016-07-21 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This file file define all the first level                  **
**                 indirection macros for Protected mode support              **
**                                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** Traceabilty      :                                                         **
**                                                                            **
*******************************************************************************/

#ifndef  DSADC_PROTECT_CFG_H
#define  DSADC_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Dsadc_Cfg.h"

#define OS_AREA_DRV_DSADC ((uint16)255)
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*
  The below Macros are used when INIT API is executed in User-1 mode
*/
#if (DSADC_USER_MODE_INIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define DSADC_INIT_RESETENDINIT()                     TRUSTED_ApplResetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define DSADC_INIT_SETENDINIT()                         TRUSTED_ApplSetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define DSADC_INIT_WRITE32(reg, value)                                         \
                     OS_WritePeripheral32((OS_AREA_DRV_DSADC),                 \
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define DSADC_INIT_MODIFY32(reg,clearmask,setmask)                             \
                     OS_ModifyPeripheral32((OS_AREA_DRV_DSADC),                \
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
/*
  The below Macros are used when INIT API is executed in User-0 mode
*/
#if (DSADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define DSADC_INIT_USER_MODE_OS_API_WRITE32(reg,value)                       \
                     OS_WritePeripheral32((OS_AREA_DRV_DSADC),                 \
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define DSADC_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)          \
                     OS_ModifyPeripheral32((OS_AREA_DRV_DSADC),                \
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define DSADC_INIT_USER_MODE_OS_API_READ32(reg)                              \
                     OS_ReadPeripheral32((OS_AREA_DRV_DSADC),                  \
                                     (volatile uint32*)(volatile void*)(&(reg)))
#endif /* (DSADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)*/
#endif /* (DSADC_USER_MODE_INIT_API_ENABLE == STD_ON)  */

/*
  The below Macros are used when DEINIT API is executed in User-1 mode
*/
#if (DSADC_DEINIT_API == STD_ON)
#if (DSADC_USER_MODE_DEINIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define DSADC_DEINIT_RESETENDINIT()                   TRUSTED_ApplResetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define DSADC_DEINIT_SETENDINIT()                       TRUSTED_ApplSetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define DSADC_DEINIT_WRITE32(reg, value)                                       \
                     OS_WritePeripheral32((OS_AREA_DRV_DSADC),                 \
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define DSADC_DEINIT_MODIFY32(reg,clearmask,setmask)                           \
                     OS_ModifyPeripheral32((OS_AREA_DRV_DSADC),                \
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
/*
  The below Macros are used when DEINIT API is executed in User-0 mode
*/
#if (DSADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define DSADC_DEINIT_USER_MODE_OS_API_READ32(reg)                            \
                     OS_ReadPeripheral32((OS_AREA_DRV_DSADC),                  \
                                     (volatile uint32*)(volatile void*)(&(reg)))
#endif /* (DSADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)*/
#endif /* (DSADC_USER_MODE_DEINIT_API_ENABLE == STD_ON)  */
#endif /* (DSADC_DEINIT_API == STD_ON) */

/*
  The below Macros are used when RUNTIME APIs are executed in User-1 mode
*/
#if (DSADC_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
/*
  The below Macros are used when RUNTIME APIs are executed in User-0 mode
*/
#if (DSADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define DSADC_RUNTIME_USER_MODE_OS_API_WRITE32(reg,value)                    \
                     OS_WritePeripheral32((OS_AREA_DRV_DSADC),                 \
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define DSADC_RUNTIME_USER_MODE_OS_API_READ32(reg)                           \
                     OS_ReadPeripheral32((OS_AREA_DRV_DSADC),                  \
                                     (volatile uint32*)(volatile void*)(&(reg)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define DSADC_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)       \
                     OS_ModifyPeripheral32((OS_AREA_DRV_DSADC),                \
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#endif /* (DSADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)  */
#endif /* (DSADC_USER_MODE_RUNTIME_API_ENABLE == STD_ON)  */
#endif
