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
**  FILENAME  :  IomTst_LCfg.c                                                **
**                                                                            **
**  VERSION   : 0.0.2                                                         **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:13                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Iom.bmd/xdm                                       **
**                                                                            **
**  VARIANT   : VariantLinkTime                                                    **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : IomTst configuration generated out of ECU configuration    **
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
#include "IomTst.h"

#define IFX_IOMTST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

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

/* IOM Module Configuration */
const IomTst_ConfigType IomTst_ConfigRoot[IOMTST_CFG_PARAM_COUNT] =
{
  {

    
    /* IomFpcMonBlockIndex */
	(uint8)(0x5U),
	
    /* IomFpcMonPortIndex */
    (uint8)(0x33U),

    /* IomFpcMonPortCtrlRegIndex */
    (uint8)(0x1U),

    /* IomFpcMonPortCtrlBitsOff */
    (uint8)(0xbU),

    /* IomLamBlockIndex */
    {
      (uint8)(0x0U)
    },

    /* Dummy variable to ensure even address alignment */
    (uint32)(0x00U)
  }
};
#define IFX_IOMTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

