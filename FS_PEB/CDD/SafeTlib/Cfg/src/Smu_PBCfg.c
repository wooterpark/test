
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
**  FILENAME  :  Smu_PBCfg.c                                                 **
**                                                                            **
**  VERSION   : 0.0.4                                                         **
**                                                                            **
**  DATE, TIME: 2021-09-26, 19:51:01                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Smu.bmd/xdm                                       **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SMU configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Smu_Cfg.h"
#include "Mcal_Options.h"


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
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_START_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_START_SEC_POSTBUILDCFG
#include "MemMap.h"
#endif

/* SMU Module Configuration */
const Smu_ConfigType Smu_ConfigRoot[2] = 
{
  {
    /* FSP Cfg */
    (uint32)0x400058U,
 
    /* AGC Cfg */
    (uint32)0x20000000U,
 
    /* RTC Cfg */
    (uint32)0x3fff00U,
 
    /* RTAC0 Cfg */
    (uint32)0x0U,
 
    /* RTAC1 Cfg */
    (uint32)0x0U,
    
    /*AlarmConfig*/
    {
      0x0U,0x0U,0x0U,    
      0x0U,0x0U,0x0U,    
      0x0U,0x0U,0x0U,    
      0x0U,0x0U,0x0U,    
      0x0U,0x0U,0x0U,    
      0x0U,0x0U,0x0U,    
      0x0U,0x0U,0x0U    
    },
    /*AlarmFspConfig*/
    {
      0x0U,    
      0x0U,    
      0x0U,    
      0x0U,    
      0x0U,    
      0x0U,    
      0x0U    
    }
  },  
  {
    /* FSP Cfg */
    (uint32)0x400058U,
 
    /* AGC Cfg */
    (uint32)0x20000000U,
 
    /* RTC Cfg */
    (uint32)0x3fff00U,
 
    /* RTAC0 Cfg */
    (uint32)0x0U,
 
    /* RTAC1 Cfg */
    (uint32)0x0U,
    
    /*AlarmConfig*/
    {
      0x0U,0xc3ffbU,0x0U,    
      0xffffbU,0xffffbU,0x0U,    
      0xe7ff81fcU,0xe7ff81fcU,0x0U,    
      0xee41fbebU,0xee41fbebU,0x0U,    
      0x0U,0xfb0ffU,0x0U,    
      0x0U,0x0U,0x0U,    
      0x0U,0x0U,0xffff8U    
    },
    /*AlarmFspConfig*/
    {
      0x0U,    
      0xfbbbbU,    
      0x6fd81f0U,    
      0xc84003ebU,    
      0x0U,    
      0x0U,    
      0x0U    
    }
  }  
};
#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"
#endif
