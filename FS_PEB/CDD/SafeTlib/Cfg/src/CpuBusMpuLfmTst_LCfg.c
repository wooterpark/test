
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
**  FILENAME  :  CpuBusMpuLfmTst_LCfg.c                                       **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:12                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuBusMpuLfmTst.bmd/xdm                           **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CpuBusMpuLfmTst configuration                              **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "CpuBusMpuLfmTst_Cfg.h"

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

#define IFX_CPUBUSMPULFM_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"



	



/* CPU Bus MPU LFM test configuration:                                      */
const CpuBusMpuLfmTst_ConfigType
CpuBusMpuLfmTst_ConfigRoot[CPUBUSMPU_LFM_TST_CFG_PARAM_COUNT] =
{
  /* CpuBusMpuLfmTst_ConfigRoot[0]:*/
  {
    {
      /* Core0 TestMemory */
      {
        (uint32*)0x70101520U,
        (uint32*)0x70101540U,
        (uint32*)0x70101560U,
        (uint32*)0x70101580U,
        (uint32*)0x701015a0U,
        (uint32*)0x701015c0U,
        (uint32*)0x701015e0U,
        (uint32*)0x70101600U 
      },
	  
      /* Core1 TestMemory */
      {
        (uint32*)0x60100020U,
        (uint32*)0x60100040U,
        (uint32*)0x60100060U,
        (uint32*)0x60100080U,
        (uint32*)0x601000a0U,
        (uint32*)0x601000c0U,
        (uint32*)0x601000e0U,
        (uint32*)0x60100100U 
      },  
      /* Core2 TestMemory */
      {
        
        (uint32*)0x50100040U,
        (uint32*)0x50100060U,
        (uint32*)0x50100080U,
        (uint32*)0x501000a0U,
        (uint32*)0x501000c0U,
        (uint32*)0x501000c0U,
        (uint32*)0x501000e0U,
        (uint32*)0x50100100U 
      }
    },
    {     
      /*  Unauthorized Addr Cpu0 */
      {
        (uint32*)0x70101500U,
      },
      /*  Unauthorized Addr Cpu1 */
      {
        (uint32*)0x60100000U,
      }, 
      /*  Unauthorized Addr Cpu1 */
      {
        (uint32*)0x50100000U,
      }, 
    }
  }  
};


#define IFX_CPUBUSMPULFM_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
