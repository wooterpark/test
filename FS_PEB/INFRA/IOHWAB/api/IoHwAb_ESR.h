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
* $Name______: IOHWAB_ESR.h$
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

#ifndef IOHWAB_API_IOHWAB_ESR_H_
#define IOHWAB_API_IOHWAB_ESR_H_
/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "IfxScu_reg.h"
#include "Dio.h"
#include "Pwm_17_Gtm.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define IoHwAbW_START_SEC_VAR_CLEARED_BOOLEAN
#include "IoHwAbW_Cfg_MemMap.h"

#define IoHwAbW_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "IoHwAbW_Cfg_MemMap.h"

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
//extern boolean CPLD_TO_ARX_1_status;
/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/
/*******************************************************************************
** Function Name	: IOHWAB_ESR_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: IoHwAb_ESR Module initialization function
*******************************************************************************/
extern void IoHwAb_ESR_Init(void);

#endif /* IOHWAB_API_IOHWAB_ESR_H_ */
