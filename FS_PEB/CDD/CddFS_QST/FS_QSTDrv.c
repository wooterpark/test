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
* $Name______: FS_QSTDrv.c$
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
#include "FS_QSTDrv.h"
#include "Pwm_17_Gtm.h"
#include "IoHwAb_ICU.h"
#include "Dio.h"
#include "Dem.h"
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
typedef struct
{
	float32 	Cpld_PWM_H_Duty_f32;			/*PWM Duty signal */
	float32 	Cpld_PWM_H_Period_f32;			/*PWM Duty signal */
	float32 	Cpld_PWM_L_Duty_f32;			/*PWM Duty signal */
	float32 	Cpld_PWM_L_Period_f32;			/*PWM Duty signal */
} st_CpldBridgrPwmOutType;

typedef struct
{
	st_CpldBridgrPwmOutType Cpld_PWM_U;
	st_CpldBridgrPwmOutType Cpld_PWM_V;
	st_CpldBridgrPwmOutType Cpld_PWM_W;
} st_QstIcuType;

st_QstIcuType QstCpldIcu_st;

typedef enum
{
	UpAsc_step1 = 0  ,
	PwmRead_step2    ,
	DownAsc_step3    ,
	PwmRead_step4    ,
	Judge_step5      ,
	Idle_step6       ,
}en_QstStateType;

en_QstStateType QstState_en;

uint16   QstPWM3phIcuChannel_au16[6U] = {
										   DIO_CHANNEL_1_7,		/*H U*/
										   DIO_CHANNEL_2_9,		/*H V*/
										   DIO_CHANNEL_11_8,	/*H W*/
										   DIO_CHANNEL_11_0,	/*L U*/
										   DIO_CHANNEL_10_7,	/*L V*/
										   DIO_CHANNEL_0_4		/*L W*/
                              	  	  	 };
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
** Function Name	: FS_QSTInit
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: QM  SOP Module initialization function
*******************************************************************************/
void FS_QSTInit(void )
{

}

/*******************************************************************************
** Function Name	: FS_QSTAtion
** Parameter[in] 	: const FS_QSTInIFType* in
** Parameter[out] 	: FS_QSTOutIFType* out
** Return Value	  	: None
** Note	  			: 2ms
** Description	  	: QM  SOP  Module Mainfunction
*******************************************************************************/
void FS_QSTAtion( const FS_QSTInIFType* in, FS_QSTOutIFType* out )
{
	uint8 channel;
	uint8 level_au8[6U];
	static uint8 QstAscCnt_u8 = 0U;
	static uint8 QstUpAscFlg_u8 = 0U;
	static uint8 QstDownAscFlg_u8 = 0U;

	if( in->SCF_stPreDrvCtl_u8 ==  2U )/*开始自检*/
	{
		switch( QstState_en )
		{
			case UpAsc_step1:
			{
				out->QST_stASCReq_u8 = 1u;/*下ASC*/
				QstState_en = PwmRead_step2;
			}
			break;
			case PwmRead_step2:
			{
				for( channel = 0; channel < 6U; channel ++ )
				{
					level_au8[channel] = Dio_ReadChannel( QstPWM3phIcuChannel_au16[channel] );
				}
				if( (level_au8[0U] == 0U)&&(level_au8[1U] == 0U)&&(level_au8[2U] == 0U) )
				{
					if( (level_au8[3U] == 1U)&&(level_au8[4U] == 1U)&&(level_au8[5U] == 1U) )
					{
						QstUpAscFlg_u8 = 1U;
					}
				}
				QstState_en = DownAsc_step3;
			}
			break;
			case DownAsc_step3:
			{
				out->QST_stASCReq_u8 = 2u;/*上ASC*/
				QstState_en = PwmRead_step4;
			}
			break;
			case PwmRead_step4:
			{
				for( channel = 0; channel < 6U; channel ++ )
				{
					level_au8[channel] = Dio_ReadChannel( QstPWM3phIcuChannel_au16[channel] );
				}
				if( (level_au8[0U] == 1U)&&(level_au8[1U] == 1U)&&(level_au8[2U] == 1U) )
				{
					if( (level_au8[3U] == 0U)&&(level_au8[4U] == 0U)&&(level_au8[5U] == 0U) )
					{
						QstDownAscFlg_u8 = 1U;
					}
				}

				QstState_en = Judge_step5;
			}
			break;
			case Judge_step5:
			{
				if( (QstUpAscFlg_u8 == 1U)&&(QstDownAscFlg_u8 == 1U) )
				{
					out->QST_stQmSopTest_u8 = 1u;/*自检成功*/
				}
				else
				{
					out->QST_stQmSopTest_u8 = 2u;/*自检失败*/
//					Dem_SetEventStatus(DemConf_DemEventParameter_QST_QmSopTstErr,DEM_EVENT_STATUS_FAILED);
				}
				out->QST_stASCReq_u8 = 0u;/*退出自检模式*/

				QstState_en = Idle_step6;
			}
			break;
			case Idle_step6:
			{
				out->QST_stASCReq_u8 = 0U;/*退出自检模式*/
				QstUpAscFlg_u8 = 0U;
				QstDownAscFlg_u8 = 0U;
			}
			break;
			default:
			{
				QstState_en = Idle_step6;
			}
			break;
		}
	}
	else
	{
		out->QST_stASCReq_u8 = 0U;/*退出自检模式*/
		QstUpAscFlg_u8 = 0U;
		QstDownAscFlg_u8 = 0U;
	}

}



