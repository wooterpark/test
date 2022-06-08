
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
**  FILENAME  :  SafeWdgAscLin_PBCfg.c                                        **
**                                                                            **
**  VERSION   : 0.0.1                                                         **
**                                                                            **
**  DATE, TIME: 2016-08-04, 12:03:02                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgAscLin.bmd/xdm                             **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/HighTec/WindRiver                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **                                                                      
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SafeWdgAscLin configuration generated file                 **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgAscLin.docm, Ver 0.1        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SafeWdgIf.h"
#include "IfxAsclin_reg.h"
#include "SafeWdgAscLin_Cfg.h"
/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/


/*******************************************************************************
**                      Configuration Options                                 **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define IFX_SWDG_START_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"


/* external CiC watchdog configuration */
const SafeWdgAscLin_ConfigType SafeWdgAscLin_ConfigRoot[1] =
{
  { 
    
        /* ASCLIN selection */
       &MODULE_ASCLIN3,     /* selected ASCLIN module */     
       14u,             /* DMA Tx channel */          
       /* Baudrate configuration */
       7u,          /* oversampling (4-16)*/
       4u,          /* Defines the length of the first SCLK half period (1 -15)*/
       1u,          /* prescaler value (1-4096) */
       49u,         /* baudrate denominator (1-4095)*/
       8u,         /* baudrate numerator (1-4095) */
       
       /* Frame configuration */
       7u,          /* idle cycles between two transmissions  (0-7) */
       1u,          /* trail cycles after transmission (0-7) */
       3u,          /* leading cycles before transmission (0-7) */
       0u,          /* MSB first (0: no, 1: yes) */
       
       /* IOCR configuration */
       1u,          /* slave CS polarity (0: high active, 1: low active) */
       4u,          /* receiver port input selector (0-7) */ 
     
       /* Functions configuration */
       NULL,
	   NULL,
//       &SafeWdgExtCic_Helper_EnableTOMChOSM,        /* Enable TOM Channel */
//       &SafeWdgExtCic_Helper_DisableTOMChOSM,       /* Disable TOM Channel */
    
        
    }    

};

#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


