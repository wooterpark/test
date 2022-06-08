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
**  FILENAME  : Dsadc_PBCfg.c                                                **
**                                                                           **
**  $CC VERSION : \main\13 $                                                 **
**                                                                           **
**  DATE, TIME: 2021-09-29, 16:08:36                                     **
**                                                                           **
**  GENERATOR : Build b141014-0350                                         **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : Dsadc configuration generated out of ECU configuration    **
**                 file(Dsadc.bmd/.xdm)                                      **
**                                                                           **
**  SPECIFICATION(S) :                                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
**                                                                           **
**  TRACEBILITY :                                                            **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                            Includes                                        **
*******************************************************************************/
/* Include module header file */
#include "Dsadc.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                    Call Back Function Prototype                            **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* Memory Mapping the configuration constant */
#define DSADC_START_SEC_POSTBUILDCFG
#include "MemMap.h"    

/*
        Container: DsadcChannelConfigSet
        Multilplicity : 1 - *
*/















/*     DSADC Channel Configuration    */
static const Dsadc_ChannelConfigType Dsadc_kChannelConfiguration0[]=
{


  {
 



  0x84818003U, /* Configuration for DSADC register MODCFGx */
  0x80108080U, /* Configuration for DSADC register DICFGx */
  0x0003360fU, /* Configuration for DSADC register FCFGCx */
  0x0000000bU, /* Configuration for DSADC register FCFGMx */
  0x0000ffc8U, /* Configuration for DSADC register OFFMx */  
  0x00000000U, /* Configuration for DSADC register RECTCFGx */ 
  0x00000000U, /* Configuration for DSADC register CGSYNCx */   
  0x00000000U, /* Configuration for DSADC register IWCTRx */ 
  0x00000000U, /* Configuration for DSADC register TSTMPx */
  0x01U, /* Configuration for ChannelID */  
  },  
  {
 



  0x8481800cU, /* Configuration for DSADC register MODCFGx */
  0x80108080U, /* Configuration for DSADC register DICFGx */
  0x0003360fU, /* Configuration for DSADC register FCFGCx */
  0x0000000bU, /* Configuration for DSADC register FCFGMx */
  0x00000000U, /* Configuration for DSADC register OFFMx */  
  0x00000000U, /* Configuration for DSADC register RECTCFGx */ 
  0x00000000U, /* Configuration for DSADC register CGSYNCx */   
  0x00000000U, /* Configuration for DSADC register IWCTRx */ 
  0x00000000U, /* Configuration for DSADC register TSTMPx */
  0x02U, /* Configuration for ChannelID */  
  },  
  {
 



  0x8481800cU, /* Configuration for DSADC register MODCFGx */
  0x80108080U, /* Configuration for DSADC register DICFGx */
  0x0003360fU, /* Configuration for DSADC register FCFGCx */
  0x0000000bU, /* Configuration for DSADC register FCFGMx */
  0x0000ffd4U, /* Configuration for DSADC register OFFMx */  
  0x00000000U, /* Configuration for DSADC register RECTCFGx */ 
  0x00000000U, /* Configuration for DSADC register CGSYNCx */   
  0x00000000U, /* Configuration for DSADC register IWCTRx */ 
  0x00000000U, /* Configuration for DSADC register TSTMPx */
  0x03U, /* Configuration for ChannelID */  
  },  
  {
 



  0x85848000U, /* Configuration for DSADC register MODCFGx */
  0x80108780U, /* Configuration for DSADC register DICFGx */
  0x0003f60fU, /* Configuration for DSADC register FCFGCx */
  0x00000017U, /* Configuration for DSADC register FCFGMx */
  0x00000000U, /* Configuration for DSADC register OFFMx */  
  0x00000001U, /* Configuration for DSADC register RECTCFGx */ 
  0x0b030000U, /* Configuration for DSADC register CGSYNCx */   
  0x0f011000U, /* Configuration for DSADC register IWCTRx */ 
  0x00000000U, /* Configuration for DSADC register TSTMPx */
  0x04U, /* Configuration for ChannelID */  
  },  
  {
 



  0x85848000U, /* Configuration for DSADC register MODCFGx */
  0x80108780U, /* Configuration for DSADC register DICFGx */
  0x0003f60fU, /* Configuration for DSADC register FCFGCx */
  0x00000013U, /* Configuration for DSADC register FCFGMx */
  0x00000000U, /* Configuration for DSADC register OFFMx */  
  0x00000001U, /* Configuration for DSADC register RECTCFGx */ 
  0x0b030000U, /* Configuration for DSADC register CGSYNCx */   
  0x0f011000U, /* Configuration for DSADC register IWCTRx */ 
  0x00000000U, /* Configuration for DSADC register TSTMPx */
  0x05U, /* Configuration for ChannelID */  
  }  
};


/*
        Container: DSADC Config Root
        Multilplicity : 1 - *
*/
const Dsadc_ConfigType Dsadc_ConfigRoot[]=
{
{
  /* Configuration Set 0 for DSADC */
  100000000.0f,
  0x00800001U, /* Configuration for DSADC register GLOBCFG */
  0x00000047U, /* Configuration for DSADC register CGCFG */ 
  
{
  0x00000000U, /* Configuration for DSADC register GLOBVCMH0 */
  0x00000000U, /* Configuration for DSADC register GLOBVCMH1 */
  0x00000000U /* Configuration for DSADC register GLOBVCMH2 */
  
},

  
  0x01U, /* Configuration for DSADC register CLC */
  {
    &Dsadc_kChannelConfiguration0[0],      	 
    &Dsadc_kChannelConfiguration0[1],      	 
    &Dsadc_kChannelConfiguration0[2],      	 
    &Dsadc_kChannelConfiguration0[3],      	 
    &Dsadc_kChannelConfiguration0[4],      	 
    NULL_PTR,      	 
  }
}
};

#define DSADC_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS= Memmap file included as per AUTOSAR*/
#include "MemMap.h"



