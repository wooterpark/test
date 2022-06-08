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
* $Name______: IOHWAB_Get.c$
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
#include "Rte_IoHwAbW.h"
#include "IoHwAb_DIO.h"
#include "Dem.h"
#include "LvPower_Drv.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define IoHwAbW_START_SEC_CODE
#include "IoHwAbW_Cfg_MemMap.h"

#define IoHwAbW_STOP_SEC_CODE
#include "IoHwAbW_Cfg_MemMap.h"


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
** Function Name	: IoHwAb_DIO_Get
** Parameter[in] 	: channel
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: IoHwAb get I/O fuction
*******************************************************************************/
FUNC (void , IoHwAbW_CODE) IoHwAb_DIO_Get
(
		VAR(uint16, AUTOMATIC) channel,
		CONSTP2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) dio_status
)
{
	*dio_status = (boolean) Dio_ReadChannel((Dio_ChannelType) channel);
}

/*******************************************************************************
** Function Name	: IoHwAb_DIO_DEM
** Parameter[in] 	: channel
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	:  Fault diagnosis of I/O sampling in IoHwAb
*******************************************************************************/

//	DI_CRASH_P23_2_b=(boolean) Dio_ReadChannel((Dio_ChannelType) CRASH_P23_2_CHANNEL);      /*CrashFail fault diagnosis */
//	if(DI_CRASH_P23_2_b==DIO_DEM_flase)
//	{
//		Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_CrashFail,DEM_EVENT_STATUS_FAILED);
//	}




