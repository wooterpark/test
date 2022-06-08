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
* $Name______: FS_DischargeDrv.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: LQ$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:


**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:


*******************************************************************************/

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "FS_EmerDischargeDrv.h"
#include "Pwm_17_Gtm.h"
//#include "TLF35584Bist.h"
#include "Pwm3ph.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
//#define
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/


/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/


/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
#pragma section ".rodata.Calib_32"



#pragma section


/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/



/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/
/*******************************************************************************
** Function Name	: FS_EmerDischargeInit
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Emergency Discharge Module initialization function
*******************************************************************************/
void FS_EmerDischargeInit(void )
{

}

/*******************************************************************************
** Function Name	: FS_EmerDischargeAtion
** Parameter[in] 	: const FS_EmerDisInIFType* in
** Parameter[out] 	: FS_EmerDisOutIFType* out
** Return Value	  	: None
** Note	  			: 2ms
** Description	  	: Emergency Discharge Module initialization function
*******************************************************************************/
void FS_EmerDischargeAtion(const FS_EmerDisInIFType* in, FS_EmerDisOutIFType* out)
{

	if( in->EmerReqInvDcha_u8 ==  4 )
	{
		Pwm_17_Gtm_SetPeriodAndDuty( Pwm_17_GtmConf_PwmChannel_HMcu_330K_PWM,0,0 );
//		Tlf35584_GoTOWake( );
		out->EmerReqInvDcha_u8 = 1u;
		Pwm3ph_ShunDownallChannelImmediately();
	}
	else
	{
		out->EmerReqInvDcha_u8 = 0u;
	}
	out->EmerStL2BswInit_u8 = 1u;
}



