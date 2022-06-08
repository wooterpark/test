/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: FS_DischargeDrv.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: LQ$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: yes
**----------------------------------------------------------------------------**
** DESCRIPTION:


**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   Note Use English

V1.0.1:	  Note Use English


*******************************************************************************/

#ifndef FS_EMERDISCHARGE_DRV_H_
#define FS_EMERDISCHARGE_DRV_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
#include"Platform_Types.h";
typedef struct {
	uint8  EmerReqInvDcha_u8;
} FS_EmerDisInIFType;

typedef struct {

	uint8   EmerReqInvDcha_u8;
	uint8   EmerStL2BswInit_u8;
} FS_EmerDisOutIFType;
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
** Function Name	: FS_EmerDischargeAtion
** Parameter[in] 	: const FS_EmerDisInIFType* in
** Parameter[out] 	: FS_EmerDisOutIFType* out
** Return Value	  	: None
** Note	  			: 2ms
** Description	  	: Emergency Discharge Module initialization function
*******************************************************************************/
extern void FS_EmerDischargeAtion(const FS_EmerDisInIFType* in, FS_EmerDisOutIFType* out);






#endif /* FS_EMERDISCHARGE_DRV_H_ */
