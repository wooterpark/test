
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
**  FILENAME  :  SafeWdgInt_PBCfg.c                                           **
**                                                                            **
**  DATE, TIME: 2018-05-02, 11:54:21                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgInt.bmd/xdm                                **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / GNU / Diab                                          **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **                                                                      
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SafeWdgInt configuration file                              **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SafeWdgInt.h"

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

/* internal watchdog configuration */
const SafeWdgInt_ConfigType SafeWdgInt_ConfigRoot[] =
{
  {
    0u,  91u, /* timeout settings */

    /* Signature table */
    {
      {
        {MCAL_WDT_PW_FIXPART_READ, 0x512544bfu},
        {MCAL_WDT_PW_FIXPART_READ+0x300u, 0xce775978u},
        {MCAL_WDT_PW_FIXPART_READ+0x500u, 0xb3f82b36u},
        {MCAL_WDT_PW_FIXPART_READ+0x700u, 0x2caa36f1u},
        {MCAL_WDT_PW_FIXPART_READ+0x900u, 0x746709bfu},
        {MCAL_WDT_PW_FIXPART_READ+0xb00u, 0xeb351478u},
        {MCAL_WDT_PW_FIXPART_READ+0xd00u, 0x96ba6636u},
        {MCAL_WDT_PW_FIXPART_READ+0xf00u, 0x9e87bf1u},
        {MCAL_WDT_PW_FIXPART_READ+0xe00u, 0x3966a4bbu},
        {MCAL_WDT_PW_FIXPART_READ+0xc00u, 0xa634b97cu},
        {MCAL_WDT_PW_FIXPART_READ+0xa00u, 0xdbbbcb32u},
        {MCAL_WDT_PW_FIXPART_READ+0x800u, 0x44e9d6f5u},
        {MCAL_WDT_PW_FIXPART_READ+0x600u, 0x1c24e9bbu},
        {MCAL_WDT_PW_FIXPART_READ+0x400u, 0x8376f47cu},
        {MCAL_WDT_PW_FIXPART_READ+0x200u, 0xfef98632u},
        {MCAL_WDT_PW_FIXPART_READ+0x100u, 0x61ab9bf5u}
      }
    }
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
