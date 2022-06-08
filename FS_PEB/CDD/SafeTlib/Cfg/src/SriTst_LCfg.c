/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : SriTst_LCfg.c                                                 **
**                                                                            **
**  DATE, TIME: 2021-09-18, 15:12:40                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DESCRIPTION : SriTst.bmd/xdm                                   **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SriTst configuration                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include module header File */ 
#include "SriTst_Cfg.h"
#include "SriTst.h"
/*******************************************************************************
**                      Inclusion File Check                                  **
*******************************************************************************/


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
**                      Global Function Declarations                          **
*******************************************************************************/

/* Memory mapping of the SRI configuration */
#define IFX_SRI_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/* SRI test configuration:                                                  */
const SriTst_ConfigType SriTst_ConfigRoot[SRI_EDC_BUSERR_TST_CFG_PARAM_COUNT] =
{
  /* SriTst_ConfigRoot[0]:*/
  {
    {      
      /* LMU Test */
      1U,  /* LMU Test CPU0 Enabled  */
#if(MCAL_NO_OF_CORES > 1U)

      1U,  /* LMU Test CPU1 Enabled  */
#if(MCAL_NO_OF_CORES == 3U)

      1U,  /* LMU Test CPU2 Enabled  */
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */
    },
    
    {
      /* PMUDFlash Test */
      1U,  /* PMUDFlash Test CPU0 Enabled */
#if(MCAL_NO_OF_CORES > 1U)

      1U,  /* PMUDFlash Test CPU1 Enabled */
#if(MCAL_NO_OF_CORES == 3U)

      1U,  /* PMUDFlash Test CPU2 Enabled */
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    },

    {
      /* PMUPFlash Test */
      1U,  /* PMUPFlash Test CPU0 Enabled */
#if(MCAL_NO_OF_CORES > 1U)

      1U,  /* PMUPFlash Test CPU1 Enabled */
#if(MCAL_NO_OF_CORES == 3U)

      1U,  /* PMUPFlash Test CPU2 Enabled */
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    },
    
    {
      /* DMA Test */
      1U,        /* DMA Test CPU0 Enabled */
#if(MCAL_NO_OF_CORES > 1U)

      1U,        /* DMA Test CPU1 Enabled */
#if(MCAL_NO_OF_CORES == 3U)

      1U,        /* DMA Test CPU2 Enabled */
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    },

    {
      /* XBAR Test */
      1U,       /* SRI XBAR Test CPU0 Enabled  */
#if(MCAL_NO_OF_CORES > 1U)

      1U,       /* SRI XBAR Test CPU1 Enabled  */
#if(MCAL_NO_OF_CORES == 3U)

      1U,       /* SRI XBAR Test CPU2 Enabled  */
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    },
    
    {
      /* PSPR Test Address      */
      (uint32*)0x70101620U,   /* PSPR Test Address CPU0    */
#if(MCAL_NO_OF_CORES > 1U)

      (uint32*)0x60100120U,   /* PSPR Test Address CPU1    */
#if(MCAL_NO_OF_CORES == 3U)

      (uint32*)0x50100120U,   /* PSPR Test Address CPU2    */
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    },
    
    {
      /* DSPR Test Address    */
      (uint32*)0x7001bfe0U,   /* DSPR Test Address CPU0    */
#if(MCAL_NO_OF_CORES > 1U)

      (uint32*)0x60000000U,   /* DSPR Test Address CPU1    */
#if(MCAL_NO_OF_CORES == 3U)

      (uint32*)0x50000000U,   /* DSPR Test Address CPU2    */
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    },
    
    {
      /* LMU Test Address */
      (uint32*)0xb0000000U,    /* LMU Test Address CPU0   */
#if(MCAL_NO_OF_CORES > 1U)

      (uint32*)0xb0000000U,    /* LMU Test Address CPU1   */
#if(MCAL_NO_OF_CORES == 3U)

      (uint32*)0xb0000000U,    /* LMU Test Address CPU2   */
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    }, 
    
    {
      /* DFlash Test Address */
      (uint32*)0xaf000000U,  /* DFlash Test Address CPU0  */
#if(MCAL_NO_OF_CORES > 1U)

      (uint32*)0xaf000000U,    /* DFlash Test Address CPU1   */
#if(MCAL_NO_OF_CORES == 3U)

      (uint32*)0xaf000000U,    /* DFlash Test Address CPU2    */
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    }, 
    
    {
      /* PFlash Test Address */
      (uint32*)0xa0000000U,  /* PFlash Test Address CPU0  */
#if(MCAL_NO_OF_CORES > 1U)

      (uint32*)0xa0000000U, /* PFlash Test Address CPU1   */
#if(MCAL_NO_OF_CORES == 3U)

      (uint32*)0xa0000000U, /* PFlash Test Address CPU2    */
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    } 
  }  
};
#define IFX_SRI_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

