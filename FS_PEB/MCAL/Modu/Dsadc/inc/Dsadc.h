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
**  $FILENAME   : Dsadc.h $                                                  **
**                                                                            **
**  $CC VERSION : \main\24 $                                                 **
**                                                                            **
**  $DATE       : 2016-07-29 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                functionality of DSADC driver.                              **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEABILITY : [cover parentID=DS_NAS_DSADC_PR2824,DS_NAS_DSADC_PR2825,
DS_NAS_DSADC_PR2826,DS_NAS_DSADC_PR2827,DS_NAS_DSADC_PR2828,DS_NAS_DSADC_PR2829,
DS_NAS_DSADC_PR2830,DS_NAS_DSADC_PR2831,DS_NAS_DSADC_PR2832,DS_NAS_DSADC_PR2833,
DS_NAS_DSADC_PR2834,DS_NAS_DSADC_PR2835,DS_NAS_DSADC_PR2836]
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
*******************************************************************************/

#ifndef DSADC_H
#define DSADC_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
  /* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

  /* Global functions like Set/Reset END INIT protection bit,
  Enable/Disable interrupts, Atomic write function */
#include "Mcal.h"

/* Include Dsadc definitions  */
#include "IfxDsadc_reg.h"
#include "IfxDsadc_bf.h"
#include "IfxSrc_bf.h"
  /* Inclusion of configuration file */
#include "Dsadc_Cfg.h"

#if (DSADC_DEV_ERROR_DETECT == STD_ON )
  /* Inclusion of Det.h */
#include "Det.h"
#endif 
/* End of DSADC_DEV_ERROR_DETECT */

#if ((DSADC_USER_MODE_INIT_API_ENABLE == STD_ON)    || \
     (DSADC_USER_MODE_RUNTIME_API_ENABLE == STD_ON) || \
     (DSADC_USER_MODE_DEINIT_API_ENABLE == STD_ON)  || \
     (DSADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON))
#include "Dsadc_Protect.h"
#endif  
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#if (DSADC_DEV_ERROR_DETECT == STD_ON)

/****************************Service ID's****************************/
#define DSADC_SID_INIT                                   ((uint8)0x00U)
#define DSADC_SID_DEINIT                                 ((uint8)0x01U)
#define DSADC_SID_GETMAINRESULT                          ((uint8)0x02U)
#define DSADC_SID_GETAUXILIARYRESULT                     ((uint8)0x03U)
#define DSADC_SID_STARTCHANNEL                           ((uint8)0x04U)
#define DSADC_SID_STOPCHANNEL                            ((uint8)0x05U)
#define DSADC_SID_SETCARRIERMODE                         ((uint8)0x06U)
#define DSADC_SID_GETRESULTEVENTSTATUS                   ((uint8)0x07U)
#define DSADC_SID_CLEARRESULTEVENTSTATUS                 ((uint8)0x08U)
#define DSADC_SID_GETSDPOSVAL                            ((uint8)0x09U)
#define DSADC_SID_SETSDPOSVAL                            ((uint8)0x0AU)
#define DSADC_SID_GETSDNEGVAL                            ((uint8)0x0BU)
#define DSADC_SID_SETSDNEGVAL                            ((uint8)0x0CU)
#define DSADC_SID_GETSDCVALSTATUS                        ((uint8)0x0DU)
#define DSADC_SID_GETSDCAPVAL                            ((uint8)0x0EU)
#define DSADC_SID_ENABLERECTIFICATION                    ((uint8)0x0FU)
#define DSADC_SID_GETVERSIONINFO                         ((uint8)0x10U)
#define DSADC_SID_GETGROUPDELAY                          ((uint8)0x11U)
#define DSADC_SID_GETOUTPUTFREQ                          ((uint8)0x12U)
/****************************DET Error ID***************************/
#define DSADC_E_PARAM_CONFIG                             ((uint8)0x00U)
#define DSADC_E_PARAM_POINTER                            ((uint8)0x09U)

#endif /* End of DSADC_DEV_ERROR_DETECT */

#define DSADC_VENDOR_ID                   ((uint16)17U)
#define DSADC_MODULE_ID                   ((uint16)255U)

/**  DSADC channel resources definition. */
#define Dsadc_ChannelId_0   ((Dsadc_ChannelType)0)   /** DSADC Channel 0 */
#define Dsadc_ChannelId_1   ((Dsadc_ChannelType)1)   /** DSADC Channel 1 */
#define Dsadc_ChannelId_2   ((Dsadc_ChannelType)2)   /** DSADC Channel 2 */
#define Dsadc_ChannelId_3   ((Dsadc_ChannelType)3)   /** DSADC Channel 3 */
#define Dsadc_ChannelId_4   ((Dsadc_ChannelType)4)   /** DSADC Channel 4 */
#define Dsadc_ChannelId_5   ((Dsadc_ChannelType)5)   /** DSADC Channel 5 */
#define Dsadc_ChannelId_6   ((Dsadc_ChannelType)6)   /** DSADC Channel 6 */
#define Dsadc_ChannelId_7   ((Dsadc_ChannelType)7)   /** DSADC Channel 7 */
#define Dsadc_ChannelId_8   ((Dsadc_ChannelType)8)   /** DSADC Channel 8 */
#define Dsadc_ChannelId_9   ((Dsadc_ChannelType)9)   /** DSADC Channel 9 */

/* Defines DSADC channel demodulator enable value */
#define Dsadc_Channel0_RunCt   ((uint32)0x1)   /** DSADC Channel 0 */
#define Dsadc_Channel1_RunCt   ((uint32)0x2)   /** DSADC Channel 1 */
#define Dsadc_Channel2_RunCt   ((uint32)0x4)   /** DSADC Channel 2 */
#define Dsadc_Channel3_RunCt   ((uint32)0x8)   /** DSADC Channel 3 */
#define Dsadc_Channel4_RunCt   ((uint32)0x10)   /** DSADC Channel 4 */
#define Dsadc_Channel5_RunCt   ((uint32)0x20)   /** DSADC Channel 5 */
#define Dsadc_Channel6_RunCt   ((uint32)0x40)   /** DSADC Channel 6 */
#define Dsadc_Channel7_RunCt   ((uint32)0x80)   /** DSADC Channel 7 */
#define Dsadc_Channel8_RunCt   ((uint32)0x100)   /** DSADC Channel 8 */
#define Dsadc_Channel9_RunCt   ((uint32)0x200)   /** DSADC Channel 9 */

/* Defines DSADC channel modulator enable value */    
#define Dsadc_Channel0_Mod_RunCt ((uint32)0x10000)   /** DSADC Channel 0 */
#define Dsadc_Channel1_Mod_RunCt ((uint32)0x20000)   /** DSADC Channel 1 */
#define Dsadc_Channel2_Mod_RunCt ((uint32)0x40000)   /** DSADC Channel 2 */
#define Dsadc_Channel3_Mod_RunCt ((uint32)0x80000)   /** DSADC Channel 3 */
#define Dsadc_Channel4_Mod_RunCt ((uint32)0x100000)   /** DSADC Channel 4 */
#define Dsadc_Channel5_Mod_RunCt ((uint32)0x200000)   /** DSADC Channel 5 */
#define Dsadc_Channel6_Mod_RunCt ((uint32)0x400000)   /** DSADC Channel 6 */
#define Dsadc_Channel7_Mod_RunCt ((uint32)0x800000)   /** DSADC Channel 7 */
#define Dsadc_Channel8_Mod_RunCt ((uint32)0x1000000)   /** DSADC Channel 8 */
#define Dsadc_Channel9_Mod_RunCt ((uint32)0x2000000)   /** DSADC Channel 9 */

/* Defines channel result event*/
#define Dsadc_Channel0_MainEvent ((uint32)0x1)   /** DSADC Channel 0 */
#define Dsadc_Channel1_MainEvent ((uint32)0x2)   /** DSADC Channel 1 */
#define Dsadc_Channel2_MainEvent ((uint32)0x4)   /** DSADC Channel 2 */
#define Dsadc_Channel3_MainEvent ((uint32)0x8)   /** DSADC Channel 3 */
#define Dsadc_Channel4_MainEvent ((uint32)0x10)   /** DSADC Channel 4 */
#define Dsadc_Channel5_MainEvent ((uint32)0x20)   /** DSADC Channel 5 */
#define Dsadc_Channel6_MainEvent ((uint32)0x40)   /** DSADC Channel 6 */
#define Dsadc_Channel7_MainEvent ((uint32)0x80)   /** DSADC Channel 7 */
#define Dsadc_Channel8_MainEvent ((uint32)0x100)   /** DSADC Channel 8 */
#define Dsadc_Channel9_MainEvent ((uint32)0x200)   /** DSADC Channel 9 */

/* Defines DSADC channel auxiliary event status value */
#define Dsadc_Channel0_AuxEvent ((uint32)0x10000)   /** DSADC Channel 0 */
#define Dsadc_Channel1_AuxEvent ((uint32)0x20000)   /** DSADC Channel 1 */
#define Dsadc_Channel2_AuxEvent ((uint32)0x40000)   /** DSADC Channel 2 */
#define Dsadc_Channel3_AuxEvent ((uint32)0x80000)   /** DSADC Channel 3 */
#define Dsadc_Channel4_AuxEvent ((uint32)0x100000)   /** DSADC Channel 4 */
#define Dsadc_Channel5_AuxEvent ((uint32)0x200000)   /** DSADC Channel 5 */
#define Dsadc_Channel6_AuxEvent ((uint32)0x400000)   /** DSADC Channel 6 */
#define Dsadc_Channel7_AuxEvent ((uint32)0x800000)   /** DSADC Channel 7 */
#define Dsadc_Channel8_AuxEvent ((uint32)0x1000000)   /** DSADC Channel 8 */
#define Dsadc_Channel9_AuxEvent ((uint32)0x2000000)   /** DSADC Channel 9 */

/* Macros to define the SFR mask values */
#define DSADC_KRST0_SFR_MSK         (0x00000002U)
#define DSADC_KRST1_SFR_MSK         (0x00000001U)
#define DSADC_KRSTCLR_SFR_MSK       (0x00000001U)
#define DSADC_CLC_SFR_EDIS_MSK      (0x00000003U)
#define DSADC_CLC_SFR_DISR_MSK      (0x0000000AU)
#define DSADC_SRC_SRCR_MSK          (0x7F3F1CFFU)
#define DSADC_CGCFG_SFR_MSK         (0x7F1F80FCU)
#define DSADC_CGSYNC_SFR_SDPOS_MSK  (0xFF00FFFFU)
#define DSADC_CGSYNC_SFR_SDNEG_MSK  (0x00FFFFFFU)
#define DSADC_RECTCFG_SFR_MSK       (0xC0008030U)
#define DSADC_SFR_CLEAR_MSK         (0x00000000U)
/*
  The below Macros are used when INIT API is executed in User-1 mode
*/
#if (DSADC_USER_MODE_INIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_INIT_RESETENDINIT()                  DSADC_INIT_RESETENDINIT()
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_INIT_SETENDINIT()                      DSADC_INIT_SETENDINIT()
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_INIT_WRITE32(reg,value)      DSADC_INIT_WRITE32((reg),(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_INIT_MODIFY32(reg,clearmask,setmask)                       \
                                DSADC_INIT_MODIFY32((reg),(clearmask),(setmask))
/*
  The below Macros are used when INIT API is executed in User-0 mode
*/
#if (DSADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_INIT_USER_MODE_WRITE32(reg,value)                          \
                              DSADC_INIT_USER_MODE_OS_API_WRITE32((reg),(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask)               \
               DSADC_INIT_USER_MODE_OS_API_MODIFY32((reg),(clearmask),(setmask))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_INIT_USER_MODE_READ32(reg)                                 \
                                       DSADC_INIT_USER_MODE_OS_API_READ32((reg))
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_INIT_USER_MODE_WRITE32(reg,value)                          \
                                                 ((reg) = (unsigned_int)(value))
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced 
  initialiser*/
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask)             \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                               (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_INIT_USER_MODE_READ32(reg)                             (reg)
#endif /* DSADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON  */
/*
  The below Macros are used when INIT API is executed in SV mode
*/
#else
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_INIT_RESETENDINIT()                        Mcal_ResetENDINIT()
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_INIT_SETENDINIT()                            Mcal_SetENDINIT()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_INIT_WRITE32(reg,value)               \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_INIT_MODIFY32(reg,clearmask,setmask)                         \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                               (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_INIT_USER_MODE_WRITE32(reg,value)                 \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced 
  initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask)               \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                               (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_INIT_USER_MODE_READ32(reg)                               (reg)
#endif /* DSADC_USER_MODE_INIT_API_ENABLE == STD_ON  */

/*
  The below Macros are used when RUNTIME API is executed in User-1 mode
*/
#if (DSADC_USER_MODE_RUNTIME_API_ENABLE == STD_ON) 
/*
  The below Macros are used when RUNTIME APIs is executed in User-0 mode
*/
#if (DSADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_RUNTIME_USER_MODE_WRITE32(reg,value)                       \
                           DSADC_RUNTIME_USER_MODE_OS_API_WRITE32((reg),(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_RUNTIME_USER_MODE_READ32(reg)                              \
                                    DSADC_RUNTIME_USER_MODE_OS_API_READ32((reg))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask)          \
            DSADC_RUNTIME_USER_MODE_OS_API_MODIFY32((reg),(clearmask),(setmask))
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_RUNTIME_USER_MODE_WRITE32(reg,value)                       \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_RUNTIME_USER_MODE_READ32(reg)                          (reg)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask)          \
  { uint32 (val) ; (val) = (reg); (val) &= (clearmask); (val) |= (setmask);    \
                                                                (reg) = (val);}
#endif /* DSADC_RUNNING_IN_USER_MODE_ENABLE == STD_ON  */

/*
  The below Macros are used when RUNTIME APIs is executed in SV mode
*/
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_RUNTIME_USER_MODE_WRITE32(reg,value)                         \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_RUNTIME_USER_MODE_READ32(reg)                           (reg)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask)          \
      { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask);                 \
      (val) |= (setmask);(reg) = (val);}

#endif /* DSADC_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */

/*
  The below Macros are used when DEINIT API is executed in User-1 mode
*/
#if (DSADC_DEINIT_API == STD_ON)
#if (DSADC_USER_MODE_DEINIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_DEINIT_RESETENDINIT()              DSADC_DEINIT_RESETENDINIT()
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_DEINIT_SETENDINIT()                  DSADC_DEINIT_SETENDINIT()

/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_DEINIT_WRITE32(reg,value)  DSADC_DEINIT_WRITE32((reg),(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_DEINIT_MODIFY32(reg,clearmask,setmask)                       \
                              DSADC_DEINIT_MODIFY32((reg),(clearmask),(setmask))

/*
  The below Macros are used when DEINIT API is executed in User-0 mode
*/
#if (DSADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_DEINIT_USER_MODE_READ32(reg)                               \
                                     DSADC_DEINIT_USER_MODE_OS_API_READ32((reg))
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define DSADC_SFR_DEINIT_USER_MODE_READ32(reg)                           (reg)
#endif /* DSADC_RUNNING_IN_USER_MODE_ENABLE == STD_ON  */

/*
  The below Macros are used when DEINIT API is executed in SV mode
*/
#else
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_DEINIT_RESETENDINIT()                      Mcal_ResetENDINIT()
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_DEINIT_SETENDINIT()                          Mcal_SetENDINIT()

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_DEINIT_WRITE32(reg,value)      ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_DEINIT_MODIFY32(reg,clearmask,setmask)                       \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                               (reg) = (val);}  
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define DSADC_SFR_DEINIT_USER_MODE_READ32(reg)                             (reg)
#endif /* DSADC_USER_MODE_DEINIT_API_ENABLE == STD_ON  */
#endif /* (DSADC_DEINIT_API == STD_ON) */

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*
 * Type : Dsadc_CarrierWaveformModeType
 * Typedef for Dsadc Carrier Waveform Mode
*/
typedef enum
{
    DSADC_WAVEFORM_STOPPED,   
    DSADC_SQUARE_WAVEFORM,    
    DSADC_TRIANGLE_WAVEFORM,  
    DSADC_SINE_WAVEFORM       
} Dsadc_CarrierWaveformModeType;

/* Dsadc channel ID type */ 
typedef uint8 Dsadc_ChannelType;
/* Dsadc result type */
typedef sint16 Dsadc_ChannelDataType;

/*
 * Type : Dsadc_ChannelConfigType
 * Typedef for Channel Configuration
*/
typedef struct Dsadc_ChannelConfigType
{
  uint32 ModulatorConfig;
  uint32 DemodulatorConfig;
  uint32 MainCICConfig;
  uint32 FIRConfig;  
  uint32 OffsetConfig;
  #if(DSADC_ENABLE_LIMIT_CHECK == STD_ON)
  uint32 AuxCICConfig;
  uint32 BoundaryConfig;
  #endif
  uint32 RectfierConfig;
  uint32 CGSyncConfig;
  uint32 IntegrationConfig;
  uint32 TimeStampConfig;
  #if(DSADC_INITIAL_CONFIGURATION == STD_ON)
  uint32 InitialChannelConfig;
  #endif
  Dsadc_ChannelType ChannelID;
}Dsadc_ChannelConfigType;

/*
 * Type : Dsadc_ConfigType
 * Typedef for config root
*/
typedef struct Dsadc_ConfigType
{
  float32 SourceClkFreq;
  uint32 GlobalConfig;
  #if (DSADC_INITIAL_CONFIGURATION ==  STD_ON)
  uint32 GlobalInitialConfig;
  #endif
  uint32 CarrierGenConfig;
  #if (DSADC_COMMON_MODE_HOLD_VOLTAGE == STD_ON)
  uint32 CommonModeHoldConfig[DSADC_MAX_CMHV_REG];
  #endif
  uint8 SleepMode;
  const Dsadc_ChannelConfigType *Dsadc_kChannelConf[DSADC_NUM_OF_CHANNELS];
}Dsadc_ConfigType;




/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define DSADC_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* Declaration of DSADC Post Build Configuration */
extern const struct Dsadc_ConfigType Dsadc_ConfigRoot[DSADC_CONFIG_COUNT];
#define DSADC_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"
#define DSADC_START_SEC_VAR_8BIT
#include "MemMap.h"
#if (DSADC_DEBUG_SUPPORT == STD_ON)
/*IFX_MISRA_RULE_08_08_STATUS=Dsadc_DriverState is declared extern only here 
  and is defined in Dsadc.c. This violation is reported incorrectly
   by PC-lint tool*/
extern uint8 Dsadc_DriverState;
#endif
#define DSADC_STOP_SEC_VAR_8BIT
#include "MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*Memory Map of the DSADC Code*/
#define DSADC_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void Dsadc_Init(const Dsadc_ConfigType* ConfigPtr)       **
**                                                                            **
** Service ID      : 0x00                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : ConfigPtr - Pointer to DSADC Driver configuration set    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Driver Module Initialization                                 **
**               1.This function will initialize all relevant registers of    **
**                 with the values of structure given by ConfigPtr            **
**                                                                            **
*******************************************************************************/
extern void Dsadc_Init(const Dsadc_ConfigType* ConfigPtr);
#if (DSADC_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void Dsadc_DeInit(void)                                  **
**                                                                            **
** Service ID      : 0x01                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Driver DeInitialization                                      **
**               1.This function will deinitialize the DSADC peripheral       **
**                                                                            **
*******************************************************************************/
extern void Dsadc_DeInit(void);
#else
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate 
   compile time error in case of incorrect configuration*/
/*IFX_MISRA_RULE_19_04_STATUS=function cannot be expand to a braced 
 initialiser*/   
#define Dsadc_DeInit()                    ERROR_Dsadc_DeInit_NOT_SELECTED
#endif /* End of DSADC_DEINIT_API */


/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          :float32 Dsadc_CalGroupDelay(Dsadc_ChannelType ChannelId)  **
**                                                                            **
** Service ID      : 0x12                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      :  Reentrant                                               **
**                                                                            **
** Parameters (in) : ChannnelId - Dsadc Channel number                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : returns calculated group delay of the channel            **
**                                                                            **
** Description :     calculates group delay of the given channel              **
**                                                                            **
*******************************************************************************/
extern float32 Dsadc_CalGroupDelay(Dsadc_ChannelType ChannelId);

  
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax    :   float32 Dsadc_GetChOutputFreq (Dsadc_ChannelType ChannelId) **
**                                                                            **
** Service ID      : 0x13                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      :  Reentrant                                               **
**                                                                            **
** Parameters (in) : ChannnelId - Dsadc Channel number                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : returns output frequency of the channel                  **
**                                                                            **
** Description :     calculates output frequency of the given channel         **
**                                                                            **
*******************************************************************************/
extern float32 Dsadc_GetChOutputFreq(Dsadc_ChannelType ChannelId);

/*******************************************************************************
** Syntax : IFX_INLINE Dsadc_ChannelDataType Dsadc_GetMainResult              **
**                                          (Dsadc_ChannelType ChannelId)     **
**                                                                            **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): ChannelId: Which channel to be get the Main filter        **
**                             converted result.                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: sint16                                                       **
**                                                                            **
** Description : This service read the Main filter converted result.          **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
_IFXEXTERN_ IFX_INLINE Dsadc_ChannelDataType Dsadc_GetMainResult 
                                        (Dsadc_ChannelType ChannelId)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
  uint32 RetValue;

  RetValue = (((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(MODULE_DSADC.CH[ChannelId].RESM.U)) & \
      ((uint32)IFX_DSADC_CH_RESM_RESULT_MSK << IFX_DSADC_CH_RESM_RESULT_OFF));
  RetValue = (RetValue >> IFX_DSADC_CH_RESM_RESULT_OFF);
  
  return ((sint16)RetValue);
}

#if (DSADC_ENABLE_LIMIT_CHECK == STD_ON)
/*******************************************************************************
** Syntax : IFX_INLINE Dsadc_ChannelDataType Dsadc_GetAuxiliaryResult         **
**                                             (Dsadc_ChannelType channelID)  **
**                                                                            **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): ChannelId: Which channel to be get the Auxiliary filter   **
**                             converted result.                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: sint16                                                       **
**                                                                            **
** Description : This service read the Auxiliary filter converted result.     **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
_IFXEXTERN_ IFX_INLINE Dsadc_ChannelDataType Dsadc_GetAuxiliaryResult( \
                                                 Dsadc_ChannelType ChannelId)
{
  uint32 RetValue;

  RetValue = (((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(MODULE_DSADC.CH[ChannelId].RESA.U)) & \
      ((uint32)IFX_DSADC_CH_RESA_RESULT_MSK << IFX_DSADC_CH_RESA_RESULT_OFF));
  RetValue = (RetValue >> IFX_DSADC_CH_RESA_RESULT_OFF);
  
  return ((sint16)RetValue);
}
#endif

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Dsadc_StartChannel                    **
**                                               (uint32 ChannelsGroup)       **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): ChannelsGroup: Group(Combination) of channels and         **
**                                  modulators.                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This service enables one or more DSADC Channels.             **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in 
    header files*/
_IFXEXTERN_ IFX_INLINE void Dsadc_StartChannel(uint32 ChannelsGroup)
{
    /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in 
    header files*/
    DSADC_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_DSADC.GLOBRC.U, \
                             (uint32)DSADC_GLOBRC_SFR_MSK,(uint32)ChannelsGroup)
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Dsadc_StopChannel                     **
**                                                (uint32 ChannelsGroup)      **
**                                                                            **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): ChannelsGroup: Group(Combination) of channels and         **
**                                  modulators.                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This service disables one or more DSADC Channels.            **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
     files*/
_IFXEXTERN_ IFX_INLINE void Dsadc_StopChannel(uint32 ChannelsGroup)
{
    /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
     files*/
    DSADC_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_DSADC.GLOBRC.U, \
                                (uint32)(~(ChannelsGroup)),DSADC_GLOBRC_SFR_MSK)
}

#if (DSADC_RESOLVER_SUPPORT == STD_ON)
/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Dsadc_SetCarrierMode                  **
**                               (Dsadc_CarrierWaveformModeType CGMode)       **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): CGMode: Carrier Generation Pattern.                       **
** DSADC_WAVEFORM_STOPPED : Stop the Carrier Generation                       **
** DSADC_SQUARE_WAVEFORM : Generate square pattern PWM carrier waveform       **
** DSADC_TRIANGLE_WAVEFORM : Generate triangle pattern PWM carrier waveform   **
**DSADC_SINE_WAVEFORM : Generate sine pattern PWM carrier waveform            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Stop or Start / switch carrier generation with sine,         **
**               triangle & square pattern.                                   **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
     files*/
_IFXEXTERN_ IFX_INLINE void Dsadc_SetCarrierMode ( \
                                        Dsadc_CarrierWaveformModeType CGMode)
{
    /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
     files*/
    DSADC_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_DSADC.CGCFG.U, \
             DSADC_CGCFG_SFR_MSK, ((uint32)CGMode << IFX_DSADC_CGCFG_CGMOD_OFF))
}
#endif

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE uint32 Dsadc_GetResultEventStatus(void)    **
**                                                                            **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): None                                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: uint32                                                       **
**               Return combination of Main and Auxiliary event status        **
**               Dsadc_Channel0_MainEvent = 0x1                               **
**               Dsadc_Channel1_MainEvent = 0x2                               **
**               Dsadc_Channel2_MainEvent = 0x4                               **
**               Dsadc_Channel3_MainEvent = 0x8                               **
**               Dsadc_Channel4_MainEvent = 0x10                              **
**               Dsadc_Channel5_MainEvent = 0x20                              **
**               Dsadc_Channel0_AuxEvent = 0x10000                            **
**               Dsadc_Channel1_AuxEvent = 0x20000                            **
**               Dsadc_Channel2_AuxEvent = 0x40000                            **
**               Dsadc_Channel3_AuxEvent = 0x80000                            **
**               Dsadc_Channel4_AuxEvent = 0x100000                           **
**               Dsadc_Channel5_AuxEvent = 0x200000                           **
**                                                                            **
** Description : This used to check availability of DSADC result during       **
**               polling method.                                              **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
_IFXEXTERN_ IFX_INLINE uint32 Dsadc_GetResultEventStatus(void)
{
   return ((uint32)(DSADC_SFR_RUNTIME_USER_MODE_READ32(MODULE_DSADC.EVFLAG.U)));
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Dsadc_ClearResultEventStatus          **
**                                                  (uint32 EventGroup)       **
**                                                                            **
** Service ID:  0x08                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): EventGroup: Group combination of Main and Auxiliary event **
**                              status                                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This used to clear DSADC result event status after DSADC     **
**               result is read during polling method.                        **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
_IFXEXTERN_ IFX_INLINE void Dsadc_ClearResultEventStatus(uint32 EventGroup)
{
    DSADC_SFR_RUNTIME_USER_MODE_WRITE32(MODULE_DSADC.EVFLAGCLR.U, EventGroup);
}

#if (DSADC_RESOLVER_SUPPORT == STD_ON)   
/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE uint8 Dsadc_GetSdposVal(                   **
**                                               Dsadc_ChannelType ChannelId) **
**                                                                            **
** Service ID:  0x09                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): ChannelId: Identifies the DSADC channel for the function  **
*                              execution.                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: uint8 - SDPOS value                                          **
**                                                                            **
** Description : This API is used to get the value of SDPOS.                  **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
     files*/
_IFXEXTERN_ IFX_INLINE uint8 Dsadc_GetSdposVal(Dsadc_ChannelType ChannelId)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
     files*/
  uint32 RetValue;

  RetValue = (((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(MODULE_DSADC.CH[ChannelId].CGSYNC.U)) & \
      ((uint32)IFX_DSADC_CH_CGSYNC_SDPOS_MSK << IFX_DSADC_CH_CGSYNC_SDPOS_OFF));
  RetValue = (RetValue >> IFX_DSADC_CH_CGSYNC_SDPOS_OFF);
  
  return((uint8)RetValue);
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Dsadc_SetSdposVal(                      
**                                               Dsadc_ChannelType ChannelId, **
**                                                       uint8 SdposVal)      **
**                                                                            **
** Service ID:  0x0A                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): ChannelId: Identifies the DSADC channel for the function  **
**                             execution.                                     **
**                  SdposVal : New SDPOS value to be updated for              **
**                             corresponding channel                          **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This API is used to set the value of SDPOS.                  **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
_IFXEXTERN_ IFX_INLINE void Dsadc_SetSdposVal(Dsadc_ChannelType ChannelId,  \
                                                   uint8 SdposVal)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
  DSADC_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_DSADC.CH[ChannelId].CGSYNC.U, \
  DSADC_CGSYNC_SFR_SDPOS_MSK, ((uint32)SdposVal<<IFX_DSADC_CH_CGSYNC_SDPOS_OFF))
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE uint8 Dsadc_GetSdnegVal(                   **
**                                               Dsadc_ChannelType ChannelId) **
**                                                                            **
** Service ID:  0x0B                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): ChannelId: Identifies the DSADC channel for the function  **
**                             execution.                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: uint8 - SDNEG value                                          **
**                                                                            **
** Description : This API is used to get the value of SDPOS.                  **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
_IFXEXTERN_ IFX_INLINE uint8 Dsadc_GetSdnegVal(Dsadc_ChannelType ChannelId)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
  uint32 RetValue;

  RetValue = (((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(MODULE_DSADC.CH[ChannelId].CGSYNC.U)) & \
      ((uint32)IFX_DSADC_CH_CGSYNC_SDNEG_MSK << IFX_DSADC_CH_CGSYNC_SDNEG_OFF));
  RetValue = (RetValue >> IFX_DSADC_CH_CGSYNC_SDNEG_OFF);
  
  return((uint8)RetValue);
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Dsadc_SetSdnegVal(                    **
**                                                Dsadc_ChannelType ChannelId,**
**                                                       uint8 SdnegVal)      **
**                                                                            **
** Service ID:  0x0C                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): ChannelId: Identifies the DSADC channel for the function  **
**                             execution.                                     **
**                  SdnegVal : New SDNEG value to be updated for              **
**                             corresponding channel                          **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This API is used to set the value of SDNEG.                  **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
_IFXEXTERN_ IFX_INLINE void Dsadc_SetSdnegVal(Dsadc_ChannelType ChannelId, \
                                             uint8 SdnegVal)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
  DSADC_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_DSADC.CH[ChannelId].CGSYNC.U, \
  DSADC_CGSYNC_SFR_SDNEG_MSK, ((uint32)SdnegVal<<IFX_DSADC_CH_CGSYNC_SDNEG_OFF))
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE uint8 Dsadc_GetSdcvalStatus(               **
**                                               Dsadc_ChannelType ChannelId) **
**                                                                            **
** Service ID:  0x0D                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): ChannelId: Identifies the DSADC channel for the function  **
*                              execution.                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: uint8                                                        **
**               FALSE : No new result available                              **
**               TRUE : Bitfield SDCAP has been updated with a new captured   **
**                      value and has not yet been read                       **
**                                                                            **
** Description : This is used to get status of SDCVAL (new value in SDCAP)    **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
_IFXEXTERN_ IFX_INLINE uint8 Dsadc_GetSdcvalStatus(Dsadc_ChannelType ChannelId)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
  uint32 RetValue;

  RetValue = (((uint32) \
   DSADC_SFR_RUNTIME_USER_MODE_READ32(MODULE_DSADC.CH[ChannelId].RECTCFG.U)) & \
  ((uint32)IFX_DSADC_CH_RECTCFG_SDCVAL_MSK << IFX_DSADC_CH_RECTCFG_SDCVAL_OFF));
  RetValue = (RetValue >> IFX_DSADC_CH_RECTCFG_SDCVAL_OFF);
  
  return((uint8)RetValue); 
}

/*******************************************************************************
** Syntax : IFX_INLINE uint8 Dsadc_GetSdcapVal(Dsadc_ChannelType ChannelId)   **
**                                                                            **
** Service ID:  0x0E                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): ChannelId: Identifies the DSADC channel for the function  **
*                              execution.                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: uint8                                                        **
**                                                                            **
** Description : Read & return a SDCAP value from Carrier Generator           **
**               Synchronization Register                                     **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
_IFXEXTERN_ IFX_INLINE uint8 Dsadc_GetSdcapVal(Dsadc_ChannelType ChannelId)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
  uint32 RetValue;

  RetValue = (((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(MODULE_DSADC.CH[ChannelId].CGSYNC.U)) & \
      ((uint32)IFX_DSADC_CH_CGSYNC_SDCAP_MSK << IFX_DSADC_CH_CGSYNC_SDCAP_OFF));
  RetValue = (RetValue >> IFX_DSADC_CH_CGSYNC_SDCAP_OFF);
  
  return((uint8)RetValue);
}

/*******************************************************************************
** Syntax : IFX_INLINE void  Dsadc_EnableRectification(                       **
**                                               Dsadc_ChannelType ChannelId) **
**                                                                            **
** Service ID:  0x0F                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): ChannelId: Identifies the DSADC channel for the function  **
*                              execution.                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: void                                                         **
**                                                                            **
** Description : This service shall Enable rectifier for specified channel    **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
_IFXEXTERN_ IFX_INLINE void Dsadc_EnableRectification(Dsadc_ChannelType 
                                                         ChannelId)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header 
     files*/
  DSADC_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_DSADC.CH[ChannelId].RECTCFG.U, \
        DSADC_RECTCFG_SFR_MSK, ((uint32)TRUE << IFX_DSADC_CH_RECTCFG_RFEN_OFF))
}
#endif 
/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_PR63_18,DS_NAS_PR63_19]           **
**                                                                            **
** Syntax    : void Dsadc_GetVersionInfo( Std_VersionInfoType *VersionInfoPtr)**
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID   : 0x10                                                        **
**                                                                            **
** Sync/Async   : Synchronous                                                 **
**                                                                            **
** Reentrancy   : Non-reentrant                                               **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): VersionInfoPtr (Pointer to store the version             **
**                   information of this module)                              **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
** Description  : This service returns the version information of this module.**
**               The version information includes:                            **
**               - Module Id                                                  **
**               - Vendor Id                                                  **
**               - Instance Id                                                **
**               - Vendor specific version numbers                            **
**                                                                            **
*******************************************************************************/
#if ((DSADC_VERSION_INFO_API == STD_ON) && (DSADC_DEV_ERROR_DETECT == STD_ON))
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is function like macro used to 
  generate compile time error in case of incorrect configuration*/
#define Dsadc_GetVersionInfo(VersionInfoPtr)                                \
{                                                                         \
  if ((VersionInfoPtr) == NULL_PTR)                                       \
  {                                                                       \
    /* Report to DET */                                                   \
    Det_ReportError(                                                      \
                     (uint16)DSADC_MODULE_ID,                               \
                     DSADC_MODULE_INSTANCE,                                 \
                     DSADC_SID_GETVERSIONINFO,                              \
                     DSADC_E_PARAM_POINTER                                  \
                   );                                                     \
  }                                                                       \
  else                                                                    \
  {                                                                       \
    /* DSADC Module ID */                                                   \
    ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = DSADC_MODULE_ID;   \
    /* DSADC vendor ID */                                                   \
    ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = DSADC_VENDOR_ID;   \
    /* major version of DSADC */                                            \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =          \
                                    (uint8)DSADC_SW_MAJOR_VERSION;          \
    /* minor version of DSADC */                                            \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =          \
                                    (uint8)DSADC_SW_MINOR_VERSION;          \
    /* patch version of DSADC */                                            \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =          \
                                    (uint8)DSADC_SW_PATCH_VERSION;          \
  }                                                                       \
}
#elif ((DSADC_VERSION_INFO_API == STD_ON) && \
                (DSADC_DEV_ERROR_DETECT == STD_OFF))
#define Dsadc_GetVersionInfo(VersionInfoPtr)                                \
{                                                                         \
  /* DSADC Module ID */                                                     \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = DSADC_MODULE_ID;     \
  /* DSADC vendor ID */                                                     \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = DSADC_VENDOR_ID;     \
  /* major version of DSADC */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =            \
                                  (uint8)DSADC_SW_MAJOR_VERSION;            \
  /* minor version of DSADC */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =            \
                                  (uint8)DSADC_SW_MINOR_VERSION;            \
  /* patch version of DSADC */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =            \
                                  (uint8)DSADC_SW_PATCH_VERSION;            \
}
#else
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is function like macro used to 
  generate compile time error in case of incorrect configuration*/
#define Dsadc_GetVersionInfo(VersionInfoPtr)\
                                (ERROR_Dsadc_GetVersionInfo_NOT_SELECTED)
#endif

#define DSADC_STOP_SEC_CODE
#include "MemMap.h"
#endif /* DSADC_H */
