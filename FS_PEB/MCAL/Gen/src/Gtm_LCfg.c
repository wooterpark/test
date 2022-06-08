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
**  FILENAME  : Gtm_LCfg.c                                                   **
**                                                                           **
**  $CC VERSION : \main\22 $                                                 **
**                                                                           **
**  DATE, TIME: 2021-09-29, 16:08:33                                         **
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
**  TRACEABILITY: 
    [cover parentID=SAS_AS4XX_GTM_PR679_1,SAS_AS4XX_GTM_PR679_2,
    SAS_AS4XX_GTM_PR679_3]
[/cover]                                                                     **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
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
**  DATE, TIME: 2021-09-29, 16:08:33                                         **
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

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/
extern void TomNotification_L2_FS
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void TomNotification_L2_ISR_1ms
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void Wdg_17_Scu_Cbk_GtmNotifySRV
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void TomNotification_Pwm3ph_Edge
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void Wdg_17_Scu_Cbk_GtmNotifySRV
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void Wdg_17_Scu_Cbk_GtmNotifySRV
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void TomNotification_VADC_RDC
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

#define GTM_START_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"

#ifdef GTM_MOD_CH_CONFIGURED
#if (GTM_MOD_CH_CONFIGURED == (STD_ON))

const Gtm_NotificationConfigType Gtm_kNotifConfig0 =
{
#if (GTM_NO_OF_TIM_CH_CONF_NOTIF > 0U)
	
{
  /*TIM Notification pointers*/

},
#endif 
  
#if (GTM_NO_OF_TOM_CH_CONF_NOTIF > 0U)
{
	/*TOM Notification pointers*/

  &TomNotification_L2_FS,
  &TomNotification_L2_ISR_1ms,
  &Wdg_17_Scu_Cbk_GtmNotifySRV,
  &TomNotification_Pwm3ph_Edge,
  &Wdg_17_Scu_Cbk_GtmNotifySRV,
  &Wdg_17_Scu_Cbk_GtmNotifySRV,
  &TomNotification_VADC_RDC,

},
#endif
#if (GTM_NO_OF_ATOM_CH_CONF_NOTIF > 0U)
{
  /*ATOM Notification pointers*/

}
#endif

};
#endif 
/*#ifdef GTM_MOD_CH_CONFIGURED*/
#endif 
/*#if (GTM_MOD_CH_CONFIGURED == (STD_ON))*/

#define GTM_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"


