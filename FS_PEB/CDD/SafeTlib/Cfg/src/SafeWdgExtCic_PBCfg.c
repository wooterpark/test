
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
**  FILENAME  :  SafeWdgExtCic_PBCfg.c                                        **
**                                                                            **
**  VERSION   : 0.0.1                                                         **
**                                                                            **
**  DATE, TIME: 2016-08-04, 12:03:06                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgExtCic.bmd/xdm                             **
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
**  DESCRIPTION  : SafeWdgExtCic configuration generated file                 **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgExtCic.docm, Ver 0.1        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SafeWdgIf.h"

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
const SafeWdgExtCic_ConfigType SafeWdgExtCic_ConfigRoot[] =
{
 
    {
      /* configuration for safety path check */
       &SafeWdgAscLin_ConfigRoot[0],   /* pointer to config for ASCLIN */       
       {
     
        {                 
                 
           /* Cic expected values */
           {0xa928adcbu, 0x512544bfu},      /* F80DE974  0*/
           {0x7935ff43u, 0xce775978u},      /* B742A63B  1*/
           {0x5de3d454u, 0xb3f82b36u},      /* EE1BFF62  2*/
           {0x8dfe86dcu, 0x2caa36f1u},      /* A154B02D  3*/
           {0x6e06a41u, 0x746709bfu},      /* 728763FE  4*/
           {0xd6fd38c9u, 0xeb351478u},      /* 3DC82CB1  5*/   
           {0xf22b13deu, 0x96ba6636u},      /* 649175E8  6*/    
           {0x22364156u, 0x9e87bf1u},      /* 2BDE3AA7  7*/
           {0xec4660e2u, 0x3966a4bbu},      /* D520C459  8*/
           {0x3c5b326au, 0xa634b97cu},      /* 9A6F8B16  9*/
           {0x188d197du, 0xdbbbcb32u},    /* C336D24F  10*/
           {0xc8904bf5u, 0x44e9d6f5u},    /* 8C799D00  11*/
           {0x438ea768u, 0x1c24e9bbu},    /* 5FAA4ED3  12*/
           {0x9393f5e0u, 0x8376f47cu},    /* 10E5019C  13*/
           {0xb745def7u, 0xfef98632u},    /* 49BC58C5  14*/
           {0x67588c7fu, 0x61ab9bf5u}     /* 06F3178A  15*/
        
      }  
    }    
  }  
};

#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

