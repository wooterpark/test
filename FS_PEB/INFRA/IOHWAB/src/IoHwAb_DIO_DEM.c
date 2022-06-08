/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \ArCfg\IOHWAB$
* $Class_____: C$
* $Name______: IOHWAB_DIO_DEM.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: xuwenliao$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: YES
**----------------------------------------------------------------------------**
** DESCRIPTION:

**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:

*******************************************************************************/

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Dio.h"
#include <Std_Types.h>
#include "IoHwAb_DIO.h"
#include "Dem.h"
#include "LvPower_Drv.h"
#include "IoHwAb_ADC.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define   IOHWAB_SBCSS1_P32_4_CHANNEL   DIO_CHANNEL_32_4
#define   IOHWAB_CRASH_P23_2_CHANNEL    DIO_CHANNEL_23_2
#define   IOHWAB_UDCOV_P22_11_CHANNEL   DIO_CHANNEL_22_11
#define   IOHWAB_IPHAOC_P21_0_CHANNEL   DIO_CHANNEL_21_0

#define   IOHWAB_DIO_DEM_flase                   (0u)
#define   IOHWAB_DIO_DEM_ture                    (1u)
#define   IOHWAB_DIO_AN29_IUVW_P_REF_INDEX       (12u)
#define   IOHWAB_DIO_AN30_IUVW_N_REF_INDEX       (13u)

#pragma section ".rodata.Calib_32"
const volatile float CAL_IOHWAB_DIO_AN29_IUVW_P_REF_DEM_f32=4.0f;   /*760A-600u-4.4V;750A-625u-4.375V*/
const volatile float CAL_IOHWAB_DIO_AN30_IUVW_N_REF_DEM_f32=1.0f;   /*760A-600u-0.6V;750A-625u-4.375V*/
#pragma section
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/

/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: IoHwAb_DIO_DEM
** Parameter[in] 	: channel
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	:  Fault diagnosis of I/O sampling in IoHwAb
*******************************************************************************/
FUNC (void , IoHwAbW_CODE) IoHwAb_DIO_DEM(void)
{
	boolean DI_SBCSS1_P32_4_b;
	boolean DI_CRASH_P23_2_b;
	boolean DI_UDCOV_P22_11_b;
	boolean DI_IPHAOC_P21_0_b;
  if( LV_PowerFinish() == PWR_LV_POWERSETUP_OK )
   {
	DI_SBCSS1_P32_4_b=(boolean) Dio_ReadChannel((Dio_ChannelType) IOHWAB_SBCSS1_P32_4_CHANNEL);     /*CpldNen33Fail fault diagnosis */
	if(DI_SBCSS1_P32_4_b==IOHWAB_DIO_DEM_flase)
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_Nen33Fail,DEM_EVENT_STATUS_PREFAILED);
	}

//	DI_CRASH_P23_2_b=(boolean) Dio_ReadChannel((Dio_ChannelType) CRASH_P23_2_CHANNEL);      /*CrashFail fault diagnosis */
//	if(DI_CRASH_P23_2_b==DIO_DEM_ture)
//	{
//		Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_CrashFail,DEM_EVENT_STATUS_PREFAILED);
//	}

	DI_UDCOV_P22_11_b=(boolean) Dio_ReadChannel((Dio_ChannelType) IOHWAB_UDCOV_P22_11_CHANNEL);   /*DcLnkOverVolFail fault diagnosis */
	if(DI_UDCOV_P22_11_b==IOHWAB_DIO_DEM_ture)
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail,DEM_EVENT_STATUS_PREFAILED);
	}
   }
  if((VAR_IoHwAb_Adc_Phy_IUVW_P_REF_f32>CAL_IOHWAB_DIO_AN29_IUVW_P_REF_DEM_f32)&&(VAR_IoHwAb_Adc_Phy_IUVW_N_REF_f32<CAL_IOHWAB_DIO_AN30_IUVW_N_REF_DEM_f32))
  {
  DI_IPHAOC_P21_0_b=(boolean) Dio_ReadChannel((Dio_ChannelType) IOHWAB_IPHAOC_P21_0_CHANNEL);  /*IphaOCFail fault diagnosis */
  if(DI_IPHAOC_P21_0_b==IOHWAB_DIO_DEM_flase)
  	{
  		(void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_IphaOCFail,DEM_EVENT_STATUS_PREFAILED);
  	}
  }
}
