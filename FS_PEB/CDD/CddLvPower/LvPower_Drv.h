/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \CDD\CddLvPower$
* $Class_____: C$
* $Name______: LvPower_Drv.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: LQ$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
   This module describes the process of establishing a low voltage power supply

**----------------------------------------------------------------------------**
** HISTORY:
   V1.0.0:   The initial release

*******************************************************************************/
#ifndef LVPOWER_DRV_H_
#define LVPOWER_DRV_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include	"LvPower_Cfg.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
/*Low power setup state*/
#define PWR_LV_POWERSETUP_NOINIT		0U
#define PWR_LV_POWERSETUP_OK			1U
#define PWR_LV_POWERSETUP_FAIL			2U

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
typedef enum UBSBCState_
{
	UBSBC_Fail_V1_2 = 0  ,
	UBSBC_Fail_V2_3      ,
	UBSBC_Normal_V3_4    ,
	UBSBC_Fail_V4_6      ,
	UBSBC_Fail_V6_7      ,
	UBSBC_Fail_V7_x      ,
	UBSBC_Fail_None
}en_UBSBCStateType;
typedef enum PowerMangerState_
{
	PWR_UBR  = 0,
	PWR_VDD18LS  ,
	PWR_VDD18HS  ,
	PWR_PVDD16LS ,
	PWR_PVDD16HS ,
	PWR_FINISH   ,
	PWR_IDLE,
	PWR_ERR
}en_PowerMangerStateType;

typedef enum LvPowerState_
{
	INIT_UBSBC_State = 0  ,
	RUN_UBSBC_State
}en_LvPowerStateType;
/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/

/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

/*******************************************************************************
** Function Name	: IoSigDio_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: IoSigDio_Init
** Note	  			: None
** Description	  	: DIO pin level initialization
*******************************************************************************/
extern	void IoSigDio_Init(void);

/*******************************************************************************
** Function Name	: IoSigDio_Get
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: Dio_LevelType Level
** Note	  			: None
** Description	  	: DIO reads pin level
*******************************************************************************/
extern	Dio_LevelType IoSigDio_Get(Dio_ChannelType ChannelId);

/*******************************************************************************
** Function Name	: IoSigDio_Set
** Parameter[in] 	: Dio_ChannelType ChannelId, Dio_LevelType Level
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: DIO sets pin level
*******************************************************************************/
extern	void IoSigDio_Set(Dio_ChannelType ChannelId, Dio_LevelType Level);

/*******************************************************************************
** Function Name	: LV_PowerSetup()
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: 1ms task
** Description	  	: Power supply state management
*******************************************************************************/
extern	void LV_PowerSetup(uint8 * powerSetup_Finish );

/*******************************************************************************
** Function Name	: LV_PowerFinish()
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			:
** Description	  	: Lv Power setup successfully
*******************************************************************************/
extern	uint8 LV_PowerFinish( void);

/*******************************************************************************
** Function Name	: All_ShutDown()
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			:
** Description	  	:
*******************************************************************************/
extern	void All_ShutDown( void);
/*******************************************************************************
** Function Name	: LvPower_Manegement
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: IoSigDio_Init
** Note	  			: None
** Description	  	: DIO pin level initialization
*******************************************************************************/
extern void LvPower_Manegement(void);


#endif /* LVPOWER_DRV_H_ */

/*******************************************************************************

*******************************************************************************/
