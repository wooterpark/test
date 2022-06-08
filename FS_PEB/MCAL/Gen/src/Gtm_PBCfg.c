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
**  FILENAME  : Gtm_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\78 $                                                 **
**                                                                            **
**  DATE, TIME: 2022-01-11, 09:09:03                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Mcu.bmd                                           **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GTM configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : complex driver implementation                          **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
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
**  FILENAME  : Gtm.m                                                        **
**                                                                           **
**  $CC VERSION : \main\59 $                                                 **
**                                                                           **
**  DATE, TIME: 2022-01-11, 09:09:03                                         **
**                                                                           **
**  GENERATOR : Build b141014-0350                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : GTM configuration generated out of ECU configuration      **
**                 file (Mcu.bmd/.xdm)                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
*******************************************************************************/




/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
#include "Gtm.h"



/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Note:
The user can configure the parameters with the tag Configuration:
The user should not change anything under the tag Configuration Options:
*/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define GTM_INTERRUPT_LEVEL_MODE          (0U)
#define GTM_INTERRUPT_PULSE_MODE          (1U)
#define GTM_INTERRUPT_PULSE_NOTIFY_MODE   (2U) 
#define GTM_INTERRUPT_SINGLE_PULSE_MODE   (3U)

#define TSPP1_SUBUNIT_OUTPUT 5

/* For Tbu */
#define BITS_0_TO_23   (0U)
#define BITS_3_TO_26   (1U)
#define FREE_RUNNING_COUNTER_MODE      (0)
#define FORWARD_BACKWARD_COUNTER_MODE  (1)

/*IFX_MISRA_RULE_19_07_STATUS= Function like macros used for simplifacation of
        configuration generation and increase the readability of config file */
#define Gtm_lTbuBuildControl(Bit0, Bit123, Bit5)                              \
 (0x00U | (uint8)(Bit0) | (uint8)((uint8)(Bit123) << 1) |                     \
                                                 (uint8)((uint8)(Bit5) << 5))
                                                 
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_lTimerCtrlValue(Word, ClockValue)                                 \
                        ((uint32)(Word) | (uint32)((uint32)(ClockValue) << 12))
                        
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_TimbuildReg(Word, ClockValue)                                     \
                         ((uint32)(Word)| (uint32)((uint32)(ClockValue) << 24))
                         
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_TimTduBuildReg(Word, ClockValue)                                  \
                        ((uint32)(Word) | (uint32)((uint32)(ClockValue) << 28))
                        
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_MapBuildReg(Word, ClockValue)                                     \
                         ((uint32)(Word) | (uint32)((uint32)(ClockValue) << 1))

/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_lMoveCcuTo8Bit(Ccu1,Ccu0)                                        \
                             (((uint16)(Ccu0))| (uint16)((uint16)(Ccu1) << 8))

/* For Interrupt Mode Appending */
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_lIncludeIntMode8Bit(Bytevalue, IrqMode)                           \
                          ((uint8)(Bytevalue) | (uint8)((uint8)(IrqMode) << 6))
                          
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_lIncludeIntMode16Bit(Intvalue, IrqMode)                           \
                       ((uint16)(Intvalue) | (uint16)((uint16)(IrqMode) << 14))
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
        
#define Gtm_lIncludeIntMode32Bit(Wordvalue, IrqMode)                          \
                      ((uint32)(Wordvalue) | (uint32)((uint32)(IrqMode) << 30))

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define MCU_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"

static const Gtm_ClockSettingType Gtm_kClockSetting0 = 
{
  0x0095556aU,
  {
    0x00000000U,
    0x00000007U,
    0x000003e7U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
  },

    0x0U,

  {
    {  0x00000001U,  0x00000001U  },
    {  0x00000001U,  0x00000001U  },
    {  0x00000001U,  0x00000001U  }
  }
};

static const Gtm_GeneralConfigType Gtm_kGeneralConfig0 =
{
  0x0001U,
  Gtm_lIncludeIntMode8Bit(0U,GTM_INTERRUPT_LEVEL_MODE)
  };





static const Gtm_TomTgcConfigGroupType Gtm_kTomTgcConfigGroup0[] =
{
  {

      0xa028U,
      0x0000U,
      0xa028U,
      0x0000U,
      0x2008U,
      0x00000000U,      
  },
  {

      0xaaaaU,
      0x0000U,
      0xaaaaU,
      0x0000U,
      0xaaaaU,      
      0x00000000U,
  },
  {

      0x8000U,
      0x0000U,
      0x8000U,
      0x0000U,
      0x0000U,
      0x00000000U,      
  },
  {

      0x8000U,
      0x0000U,
      0x8000U,
      0x0000U,
      0x0000U,
      0x00000000U,      
  },
  {

      0x0a00U,
      0x0000U,
      0x0a00U,
      0x0000U,
      0x0a00U,      
      0x00000000U,
  },

};

static const Gtm_TomChannelConfigType Gtm_kTomChannelConfig0[]=
{
  {
    0x1U,
    0x0U,
    0x2710U,
    0x1388U,
    0x2710U,
    0x1388U,
  },     

  {
    0x1U,
    0x0U,
    0x186aU,
    0x186bU,
    0x186aU,
    0x186bU,
  },     

  {
    0x0U,
    0x0U,
    0x2710U,
    0x2711U,
    0x2710U,
    0x2711U,
  },     

  {
    0x1U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
  },     

  {
    0x0U,
    0x0U,
    0x2710U,
    0x2711U,
    0x2710U,
    0x2711U,
  },     

  {
    0x0U,
    0x0U,
    0x2711U,
    0x0U,
    0x2711U,
    0x0U,
  },     

  {
    0x0U,
    0x0U,
    0x2710U,
    0x2711U,
    0x2710U,
    0x2711U,
  },     

  {
    0x0U,
    0x0U,
    0x2711U,
    0x0U,
    0x2711U,
    0x0U,
  },     

  {
    0x0U,
    0x0U,
    0x2710U,
    0x2711U,
    0x2710U,
    0x2711U,
  },     

  {
    0x0U,
    0x0U,
    0x2711U,
    0x0U,
    0x2711U,
    0x0U,
  },     

  {
    0x0U,
    0x0U,
    0x2710U,
    0x2711U,
    0x2710U,
    0x2711U,
  },     

  {
    0x1U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
  },     

  {
    0x1U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
  },     

  {
    0x1U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
  },     

  {
    0x0U,
    0x0U,
    0x2800U,
    0x1400U,
    0x2800U,
    0x1400U,
  },     

  {
    0x1U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
  },     


};
static const Gtm_TomTgcConfigType Gtm_kTomTgcConfig0[] =
{
  {
    0x0U,
    0x0U,
    &Gtm_kTomTgcConfigGroup0[0]
  },
  {
    0x0U,
    0x0U,
    &Gtm_kTomTgcConfigGroup0[1]
  },
  {
    0x0U,
    0x0U,
    &Gtm_kTomTgcConfigGroup0[2]
  },
  {
    0x0U,
    0x0U,
    NULL_PTR	
  },
  {
    0x0U,
    0x0U,
    &Gtm_kTomTgcConfigGroup0[3]
  },
  {
    0x0U,
    0x0U,
    &Gtm_kTomTgcConfigGroup0[4]
  },

};

static const Gtm_TomConfigType Gtm_kTomConfig0[] = 
{
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x1000000U,GTM_FIXED_CLOCK_0),
    &Gtm_kTomChannelConfig0[0]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_1),
    &Gtm_kTomChannelConfig0[1]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x1000000U,GTM_FIXED_CLOCK_0),
    &Gtm_kTomChannelConfig0[2]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    &Gtm_kTomChannelConfig0[3]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x1000000U,GTM_FIXED_CLOCK_0),
    &Gtm_kTomChannelConfig0[4]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x100000U,GTM_FIXED_CLOCK_0),
    &Gtm_kTomChannelConfig0[5]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x100800U,GTM_FIXED_CLOCK_0),
    &Gtm_kTomChannelConfig0[6]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x100000U,GTM_FIXED_CLOCK_0),
    &Gtm_kTomChannelConfig0[7]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x100800U,GTM_FIXED_CLOCK_0),
    &Gtm_kTomChannelConfig0[8]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x100000U,GTM_FIXED_CLOCK_0),
    &Gtm_kTomChannelConfig0[9]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x100800U,GTM_FIXED_CLOCK_0),
    &Gtm_kTomChannelConfig0[10]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x100000U,GTM_FIXED_CLOCK_0),
    &Gtm_kTomChannelConfig0[11]
  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    &Gtm_kTomChannelConfig0[12]
  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    &Gtm_kTomChannelConfig0[13]
  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x1000000U,GTM_FIXED_CLOCK_0),
    &Gtm_kTomChannelConfig0[14]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x100000U,GTM_FIXED_CLOCK_0),
    &Gtm_kTomChannelConfig0[15]
  },


};

static const Gtm_AtomAgcConfigGroupType Gtm_kAtomAgcConfigGroup0[] =
{
  {
      0x0280U,
      0x0000U,
      0x0280U,
      0x0000U,
      0x0280U,
      0x00000000U,

  },
  {
      0xaa00U,
      0x0000U,
      0xaa00U,
      0x0000U,
      0xaa00U,
      0x00000000U,

  },

};

static const Gtm_AtomChannelConfigType Gtm_kAtomChannelConfig0[]=
{
  {
    0x0U,
    0x1fe01feU,
    0x0U,
    0x140U, 
    0xa0U,
    0x140U,
    0xa0U

  },     
  {
    0x0U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x0U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x0U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x0U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x0U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     

};

static const Gtm_AtomAgcConfigType Gtm_kAtomAgcConfig0[] =
{
  {
    0x0U,
    0x0U,
    &Gtm_kAtomAgcConfigGroup0[0]
  },
  {
    0x0U,
    0x0U,
    &Gtm_kAtomAgcConfigGroup0[1]
  },
  {
    0x0U,
    0x0U,
    NULL_PTR	
  },

};

static const Gtm_AtomConfigType Gtm_kAtomConfig0[] = 
{
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x1000002U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[0],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x1100002U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[1],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x1000002U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[2],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x1000002U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[3],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x1000002U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[4],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x1000002U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[5],

  },
  {
    GTM_DRIVER_GPT,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_2),
    NULL_PTR,

  },
  {
    GTM_DRIVER_GPT,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },

};



static const Gtm_TimConfigType Gtm_kTimConfig0[] =
{
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000005U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000050U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000500U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00500000U
    
},
  {
    GTM_DRIVER_COMPLEX,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x2005U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x05000000U
    
},
  {
    GTM_DRIVER_COMPLEX,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x2005U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x50000000U
    
},
  {
    GTM_DRIVER_COMPLEX,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x5U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000050U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00005000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00500000U
    
},
  {
    GTM_DRIVER_COMPLEX,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x2505U, GTM_CONFIGURABLE_CLOCK_1),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x50000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000005U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00005000U
    
},
  {
    GTM_DRIVER_COMPLEX,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x4504U, GTM_CONFIGURABLE_CLOCK_1),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00050000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00500000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x05000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x50000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000050U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00050000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00500000U
    
},
  {
    GTM_DRIVER_COMPLEX,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x5U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x05000000U
    
},

};

static const Gtm_ModUsageConfigType Gtm_kModUsage0 =
{  
  { /*TIM Module Usage */
    
     /*TIM0 Module Usage*/   {
      0x4U, /*ICU channel no*/
      0xbU, /*ICU channel no*/
      0x1U, /*ICU channel no*/
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      0xdU, /*ICU channel no*/ 
      GTM_TIM_CH_NOT_USEDBY_ICU, 
      GTM_TIM_CH_NOT_USEDBY_ICU,
   },
     /*TIM1 Module Usage*/
   {
      GTM_TIM_CH_NOT_USEDBY_ICU, 
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      0x7U, /*ICU channel no*/
      GTM_TIM_CH_NOT_USEDBY_ICU,
      0x8U, /*ICU channel no*/
      GTM_TIM_CH_NOT_USEDBY_ICU, 
      GTM_TIM_CH_NOT_USEDBY_ICU,
   },
     /*TIM2 Module Usage*/
   {
      0x3U, /*ICU channel no*/
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      0x5U, /*ICU channel no*/ 
      GTM_TIM_CH_NOT_USEDBY_ICU,
      0x2U, /*ICU channel no*/
      0x9U, /*ICU channel no*/
      0x0U, /*ICU channel no*/
   },
     /*TIM3 Module Usage*/
   {
      GTM_TIM_CH_NOT_USEDBY_ICU,
      0xcU, /*ICU channel no*/
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      0xaU, /*ICU channel no*/
      0x6U, /*ICU channel no*/ 
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
   },
  },
  {   /*TOM module Usage */
     /*TOM Module 0 Usage*/    {
      0xbU,/*PWM channel no*/
      0x00U, /* GTM configured channel*/
      0x01U, /* GTM configured channel*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x02U, /* GTM configured channel*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x03U, /* GTM configured channel*/
    },
     /*TOM Module 1 Usage*/
    {
      0x9U,/*PWM channel no*/
      0x0U,/*PWM channel no*/
      0x1U,/*PWM channel no*/
      0x2U,/*PWM channel no*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x3U,/*PWM channel no*/
      0x04U, /* GTM configured channel*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0xaU,/*PWM channel no*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*TOM Module 2 Usage*/
    {
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x4U,/*PWM channel no*/
      0x5U,/*PWM channel no*/
      0x6U,/*PWM channel no*/
      0x05U, /* GTM configured channel*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x7U,/*PWM channel no*/
      0x8U,/*PWM channel no*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x06U, /* GTM configured channel*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
    },
  },  {     /*ATOM module Usage */


     /*ATOM Module 0 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*ATOM Module 1 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*ATOM Module 2 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*ATOM Module 3 Usage*/
   {
      0x1U, /*GPT channel no*/
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      0x0U, /*GPT channel no*/
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },

   /*ATOM Module 4 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },
  }

};


static const Gtm_TbuConfigType Gtm_kTbuConfig0[GTM_NO_OF_TBU_CHANNELS] = 
{
  {  Gtm_lTbuBuildControl(BITS_0_TO_23, GTM_CONFIGURABLE_CLOCK_0, 1U),  0U  },
  {  Gtm_lTbuBuildControl(FREE_RUNNING_COUNTER_MODE, GTM_CONFIGURABLE_CLOCK_1, 1U),  0U  },
  {  GTM_SETUNUSED8 ,0x00000000U   },
};

static const Gtm_DsadcConnectionsType Gtm_kDsadcConnections0 = 
{

  0x04000000U,
  0x00000000U,
  0x00000000U,
  0x00000000U,
  0x00000000U,
};

static const uint8 Gtm_kAdcConnections0[GTM_NO_OF_ADC_MODULES] = 
{
 0xa9U, 0xbaU, 0xbbU, 0x85U, 0x89U, 0x85U, 0x00U, 0x00U, 0x00U,
};


static const Gtm_PortConfigType Gtm_kPortConfig0 =
{
  {
    0x1e500a03U,
    0x10203090U,
    0x73541007U,
    0x07030070U,
  },
  {
    0xf0110000U,
    0x0004050dU,
    0x00300000U,
    0x0a040100U,
    0x00000000U,
    0x00000000U,
    0x00010540U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,

  }
};

static const Gtm_ModuleConfigType Gtm_kModuleConfig0 =
{
  0x00U | (uint8)((uint8)1U << 5),  /* ARU Configuration */
  (uint8)GTM_ZERO_U,  /* Mcfg Configuration*/
  GTM_SLEEP_ENABLE,  /* Module Sleep Mode */
  1U,  /* Global Clock Configuration - Numerator */
  1U,/* Global Clock Configuration - Denominator */
  0xFFFFFFFFU,  /* Access Enable 0 */
  0UL,  /* Access Enable 1 */
  {  0x8448a415U, 
     0x25045641U,
  },    /* TIM Module Usage by GTM and ICU driver*/
  {  0x72f9aae7U,
  },  /* TIM Usage */
  &Gtm_kTimConfig0[0],  /* TIM Configuration Pointer */
  {0x0000003fU},  /* TOM TGC Usage */
  &Gtm_kTomTgcConfig0[0],  /* TOM TGC Configuration Pointer */
  {0xfffff03dU,
   0x0100d055U,0x0f14d500U,  
   },
  {0x10cfffc7U,
   0x000036f0U,

  },  /* TOM Usage */
  &Gtm_kTomConfig0[0],  /* TOM Configuration Pointer */
  {0x0000000bU},  /* ATOM AGC Usage */
  &Gtm_kAtomAgcConfig0[0],  /* ATOM AGC Configuration Pointer */  
  { 0xff0003c0U, 
    0x08020000U, 
    0x00000000U,
  },
  {0x2100f018U,
    
    0x00000000U,
    
    
    },  /* ATOM Usage */
  &Gtm_kAtomConfig0[0],  /* ATOM Configuration Pointer */   
    

  &Gtm_kModUsage0, /* Configuration for GTM Usage by other modules */
  &Gtm_kGeneralConfig0,  /* GTM General Configuration */
  &Gtm_kTbuConfig0[0],  /* TBU Configuration Pointer */
  NULL_PTR,  /* BRC Configuration Pointer*/
  NULL_PTR,  /* Fifo Configuration Pointer*/
  NULL_PTR,  /* F2a Configuration Pointer*/
  NULL_PTR,  /* Mcs Configuration Pointer*/
  GTM_SETUNUSED32,  /* Map Configuration*/
  NULL_PTR,  /* Dpll Configuration Pointer*/
  { /* Spe Configurations*/
    NULL_PTR,  /* Spe Configuration Pointer*/
    NULL_PTR,  /* Spe Configuration Pointer*/
  },
  NULL_PTR,  /* Cmp Configuration Pointer*/
  NULL_PTR,  /* Msc Connections Configuration Pointer*/
  &Gtm_kDsadcConnections0,  /* Dsadc Connections Configuration Pointer*/
  &Gtm_kAdcConnections0[0],  /* Adc Connections Configuration Pointer*/
  {
    0x00000000U,  /* Ttcan Connections Configuration*/
  },
  0x00000000U,  /* Psi5 Connections Configuration Pointer*/
  0x00000000U  /* Psi5S Connections Configuration Pointer*/
};

const Gtm_ConfigType Gtm_ConfigRoot[]  =
{
  {
    /*  GTM Module Clock Settings  */
    &Gtm_kClockSetting0,
    /*  Pointer to Gtm Configuration structure  */
    &Gtm_kPortConfig0,
    &Gtm_kModuleConfig0,
  },
};
#define MCU_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"




/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

