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
* $Name______: LvPower_Drv.c$
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

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "LvPower_Drv.h"
#include "IgbtDrv.h"
#include "Test_Time.h"
#include "LvPower_Cfg.h"
#include "Adc.h"
#include "Dem.h"
#include "Pwm_17_Gtm.h"
#include "IfxPort_reg.h"
#include "IfxVadc_reg.h"
#include "Dem.h"
#include "Mcu.h"
#include "Rte_SWC_LvPower.h"

#include "TJA1043_Drv.h"
#include "HvMcu_Drv.h"
#include "HvMcu_Srv.h"
#include "IoHwAb_Adc.h"
#include "ComM.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define POWER_MONITOR_COUNT						(5u)	/*Power supply detects filter times*/
#define POWER_MONITOR_COUNT_TWO					(2u)	/*The power supply detects the filtering times about 2 times, and the collection is considered normal*/

#define PWR_PVDD16LS_TIME_LIMIT					(10u)
#define PWR_PVDD16HS_TIME_LIMIT					(10u)

#define ADC_12BITS								(4096.0f)
#define ADC_REFERENCE_VOLTAGE					(5.0f)


#define PwmChannel_PWM_OCRef                    (425u)        /*760A-600u;750A-625u*/


/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/




/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/
static en_PowerMangerStateType Prv_PowerSetup_State_en;			/*The power timing establishes the status value*/
static Adc_ValueGroupType    VAR_AdcInitSBC_u16;			/*KL30 ADC Collecting discrete values*/
static Adc_ValueGroupType    VAR_AdcInitSBC_Res_u16;			/*KL30 ADC Collecting discrete values*/
static float32				 VAR_AdcInitSBC_f32;			/*KL30 ADC Collecting physical values*/




/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
static uint8 LvPowerSetupStatus_u8 = PWR_LV_POWERSETUP_NOINIT;	        /*Power supply completed*/
static en_UBSBCStateType 			 Prv_UBSBC_Init_State_Control_en;
static en_LvPowerStateType           Prv_LvPower_Manegement_en=INIT_UBSBC_State;


#pragma section ".rodata.Calib_32"
/*
1) 0-6v, motor controller does not work, CAN communication module does not work, software control UBR does not enable.
2) 6-9v, motor controller ensures normal operation of TC277 and CAN modules, software controls UBR enabling, IGBT is not allowed to open the tube, and KL30 undervoltage fault is reported.
3) 9-16v, motor controller works normally.
4) 16-18v, motor controller ensures normal operation of TC277 and CAN communication module, software controls UBR enabling, IGBT is not allowed to open the tube, and KL30 overvoltage fault is reported (under this voltage for a long time is allowed).
5) 18-24v, motor controller ensures normal operation of TC277 and CAN communication module, software controls UBR enabling, IGBT is not allowed to open the tube, and KL30 overvoltage fault is reported (at this voltage for 60min is allowed).
6) 24-28v, motor controller ensures normal operation of TC277, CAN communication module does not work, IGBT is not allowed to open the tube, and software controls UBR enabling (under this voltage for 1min is allowed).
*/
const volatile float32  CAL_POWER_UBSBC_Threhold_V1_f32 			= 0.0f;
const volatile float32  CAL_POWER_UBSBC_Threhold_V2_f32 			= 6.0f;
const volatile float32  CAL_POWER_UBSBC_Threhold_V3_f32 			= 9.0f;
const volatile float32  CAL_POWER_UBSBC_Threhold_V4_f32 			= 16.0f;
const volatile float32  CAL_POWER_UBSBC_Threhold_V5_f32 			= 18.0f;
const volatile float32  CAL_POWER_UBSBC_Threhold_V6_f32 			= 24.0f;
const volatile float32  CAL_POWER_UBSBC_Threhold_V7_f32 			= 28.0f;
const volatile float32  CAL_POWER_UBSBC_Parem_Vol_f32 				= 0.177f;	/* UBSBC Hardware partial pressure coefficient*/

const volatile float32  CAL_POWER_VDD18_Threhold_Max_f32 			= 20.0f;
const volatile float32  CAL_POWER_VDD18_Threhold_Min_f32 			= 16.0f;

#pragma section
/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/
static en_UBSBCStateType UBSBC_ReadStatus( float32 UBSBC_Value_f32);




/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: UBSBC_ReadStatus
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: en_UBSBCStateType
** Note	  			: None
** Description	  	: Get KL30 voltage state
*******************************************************************************/
 static void UBSBC_Read_SW(void)
 {
	uint8 ui8_PorweSBC_MonitorCount = 0;
	/*In the software trigger mode, KL30 voltage is collected during the initialization process, and the conversion result value is taken after the ADC interruption*/
	Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_SBC,&VAR_AdcInitSBC_u16);	/*AN_G4_1,KL30 Coefficient of sampling 0.177*/
	Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_SBC);
	Timer_DelayTicks(8000);			     /*delay 80us*/																					/*Delay 1ms, waiting for the conversion to complete*/
	for( ui8_PorweSBC_MonitorCount = 0; ui8_PorweSBC_MonitorCount < POWER_MONITOR_COUNT; ui8_PorweSBC_MonitorCount++ )/*Collect 3 times, any 2 times meet the condition, judge KL30 normal, otherwise abnormal*/
	{
		VAR_AdcInitSBC_Res_u16= (uint16)(MODULE_VADC.G[4].RES[1].U);	/* */
		VAR_AdcInitSBC_f32 += ( (((float32)VAR_AdcInitSBC_Res_u16/ADC_12BITS)*ADC_REFERENCE_VOLTAGE)/CAL_POWER_UBSBC_Parem_Vol_f32  );

		Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_SBC);
		Timer_DelayTicks(8000);													/*Delay 80us, waiting for the conversion to complete*/
	}
	VAR_AdcInitSBC_f32/=(float32)POWER_MONITOR_COUNT;
 }
/*******************************************************************************
** Function Name	: UBSBC_ReadStatus
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: en_UBSBCStateType
** Note	  			: None
** Description	  	: Get KL30 voltage state
*******************************************************************************/
static en_UBSBCStateType UBSBC_ReadStatus(float32 UBSBC_Value_f32)
{
	en_UBSBCStateType e_UBSBCState = UBSBC_Fail_V1_2;

	if((UBSBC_Value_f32 >= CAL_POWER_UBSBC_Threhold_V1_f32)&&(UBSBC_Value_f32 < CAL_POWER_UBSBC_Threhold_V2_f32))
	{
		e_UBSBCState = UBSBC_Fail_V1_2;
	}
	else if((UBSBC_Value_f32 >= CAL_POWER_UBSBC_Threhold_V2_f32)&&(UBSBC_Value_f32 < CAL_POWER_UBSBC_Threhold_V3_f32))
	{
		e_UBSBCState = UBSBC_Fail_V2_3;
	}
	else if((UBSBC_Value_f32 >= CAL_POWER_UBSBC_Threhold_V3_f32)&&(UBSBC_Value_f32 < CAL_POWER_UBSBC_Threhold_V4_f32))
	{
		e_UBSBCState = UBSBC_Normal_V3_4;
	}
	else if( (UBSBC_Value_f32 >= CAL_POWER_UBSBC_Threhold_V4_f32)&&(UBSBC_Value_f32 < CAL_POWER_UBSBC_Threhold_V6_f32) )
	{
		e_UBSBCState = UBSBC_Fail_V4_6;
	}
	else if( (UBSBC_Value_f32 >= CAL_POWER_UBSBC_Threhold_V6_f32)&&(UBSBC_Value_f32 < CAL_POWER_UBSBC_Threhold_V7_f32) )
	{
		e_UBSBCState = UBSBC_Fail_V6_7;
	}
	else
	{
		e_UBSBCState = UBSBC_Fail_V7_x;
	}

	return e_UBSBCState;
}




/*******************************************************************************
** Function Name	: IoSigDio_Get
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: Dio_LevelType Level
** Note	  			: None
** Description	  	:DIO reads pin level
*******************************************************************************/
Dio_LevelType IoSigDio_Get(Dio_ChannelType ChannelId)
{
	Dio_LevelType Level;

	Level = Dio_ReadChannel(ChannelId);

	return (Level);
}

/*******************************************************************************
** Function Name	: IoSigDio_Set
** Parameter[in] 	: Dio_ChannelType ChannelId, Dio_LevelType Level
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: DIO sets pin level
*******************************************************************************/
void IoSigDio_Set(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	Dio_WriteChannel(ChannelId,Level);
}


/*******************************************************************************
** Function Name	: IoSigDio_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: IoSigDio_Init
** Note	  			: None
** Description	  	: DIO pin level initialization
*******************************************************************************/
void IoSigDio_Init(void)
{
	UBSBC_Read_SW();
	Prv_UBSBC_Init_State_Control_en = UBSBC_ReadStatus(VAR_AdcInitSBC_f32);							/*UBR£¨KL30£©Power state acquisition*/

	IoSigDio_Set(DO_FLNAKS,  STD_LOW);
	IoSigDio_Set(DO_ASC_RES1,STD_LOW);
	IoSigDio_Set(PIN_EN,     STD_LOW);
	IoSigDio_Set(PIN_EN_L,   STD_LOW);

	/**************************on the basis of KL30 power source state control PEB state***********************************************************/
	switch( Prv_UBSBC_Init_State_Control_en )
	{
	    case UBSBC_Fail_V1_2:								/*close UBR¡¢VDD18VLS¡¢PVDD15VLS¡¢PVDD15VHS¡¢EPP power £¬forbid 1043_CAN work*/
	    case UBSBC_Fail_V7_x:
	    case UBSBC_Fail_None:
		{
			IoSigDio_Set(DO_EN_EFUSE,   STD_LOW);			/*close UBR power*/
			IoSigDio_Set(DO_EN_BOOTST,  STD_HIGH);			/*close VDD18VLS power*/
			IoSigDio_Set(DO_DFW_ENABLE, STD_LOW);			/*close PVDD15VLS power*/
			IoSigDio_Set(DO_18VPWMHEN,  STD_LOW);			/*close PVDD15VHS power*/
			IoSigDio_Set(DO_EPP_INH,    STD_LOW);			/*close EPP power*/
			IoSigDio_Set(DO_RSLVCEXCN0, STD_LOW);			/*close the rotary transformer power supply enable signal*/
			IoSigDio_Set(DO_RSLVCEXCN1, STD_LOW);			/*close the rotary transformer power supply enable signal*/
			IoSigDio_Set(DO_TJA1043_NSTB,STD_LOW);			/*forbid tja1043_CAN work*/
			IoSigDio_Set(DO_TJA1043_EN,  STD_LOW);			/*forbid tja1043_CAN work*/

			Prv_PowerSetup_State_en = PWR_ERR;
		}
		break;
		case UBSBC_Fail_V2_3:								/*open the rotary transform power supply;enable motor temperature detection; enable 1043_CAN work*/
		case UBSBC_Normal_V3_4:
		case UBSBC_Fail_V4_6:
		{

			IoSigDio_Set(DO_RSLVCEXCN0, STD_HIGH);			/*open the rotary transformer power supply enable signal*/
			IoSigDio_Set(DO_RSLVCEXCN1, STD_HIGH);			/*open the rotary transformer power supply enable signal*/
			IoSigDio_Set(DO_TJA1043_NSTB,STD_HIGH);			/*enable tja1043_CAN work*/
			IoSigDio_Set(DO_TJA1043_EN,  STD_HIGH);			/*enable tja1043_CAN work*/

		//	IoSigDio_Set(DO_ENTemp1, STD_HIGH);		 		/*enable temperature detection */
			//IoSigDio_Set(DO_ENTemp2, STD_HIGH);				/*enable temperature detection*/

			IoSigDio_Set(DO_EN_EFUSE, STD_HIGH);			/*open UBR power supply*/
			IoSigDio_Set(DO_EPP_INH,  STD_HIGH);			/*open EPP power supply*/
			IoSigDio_Set(DO_EN_BOOTST, STD_LOW);			/*open PWR_VDD18LS power supply*/

			Pwm_17_Gtm_SetDutyCycle( Pwm_17_GtmConf_PwmChannel_PWM_OCRef_P,PwmChannel_PWM_OCRef );
			Pwm_17_Gtm_SetDutyCycle( Pwm_17_GtmConf_PwmChannel_PWM_OCRef_N,PwmChannel_PWM_OCRef );

			Prv_PowerSetup_State_en = PWR_UBR;
		}
		break;
		case UBSBC_Fail_V6_7:								/*open the rotary transform power supply £¬forbid TJA1043_CAN work*/
		{
			IoSigDio_Set(DO_RSLVCEXCN0, STD_HIGH);			/*open the rotary transformer power supply enable signal*/
			IoSigDio_Set(DO_RSLVCEXCN1, STD_HIGH);			/*open the rotary transformer power supply enable signal*/
			IoSigDio_Set(DO_TJA1043_NSTB,STD_LOW);			/*forbid tja1043_CAN work */
			IoSigDio_Set(DO_TJA1043_EN,  STD_LOW);			/*forbid tja1043_CAN work*/

			Prv_PowerSetup_State_en = PWR_UBR;
		}
		break;
		default:
		{

		}
		break;
	}

//	Mcal_DisableAllInterrupts();
}


/*******************************************************************************
** Function Name	: LV_PowerSetup()
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: 1ms task
** Description	  	: Power supply state management
*******************************************************************************/
void LV_PowerSetup(uint8 * powerSetup_Finish )
{
	static uint32 ui32_PWRSetup_Counter = 0;		/*Each power supply to establish a delay count*/
	static uint32 ui32_PWM_18VH1_Duty = DRV_POWER_RATE_OF_RISE_TICK;	/*5% Duty*/
	static uint32 ui32_PWM_18VL1_Duty = DRV_POWER_RATE_OF_RISE_TICK;	/*5% Duty*/

	float adc_Phy_18V_LS_f32 = 0.0F ;
	float adc_Phy_18V_HS_f32 = 0.0F ;

	switch( Prv_PowerSetup_State_en )
	{
		case PWR_UBR:
		{
			Prv_PowerSetup_State_en = PWR_VDD18LS;
		}
		break;
		case PWR_VDD18LS:
		{
			IoHwAb_ADC_GetPhyVoltage( IOHWAB_AN43_IGBT_18V_LS_CHANNEL,&adc_Phy_18V_LS_f32);                        /*AN43_18VLS_G5_3*/
			if( (adc_Phy_18V_LS_f32 > CAL_POWER_VDD18_Threhold_Min_f32) && (adc_Phy_18V_LS_f32 < CAL_POWER_VDD18_Threhold_Max_f32))
			{
				Prv_PowerSetup_State_en = PWR_VDD18HS;
			}
			else
			{
				Prv_PowerSetup_State_en = PWR_VDD18LS;
			}
		}
		break;
		case PWR_VDD18HS:
		{
//			IoHwAb_ADC_GetPhyVoltage( IOHWAB_AN27_IGBT_18V_HS_CHANNEL,&adc_Phy_18V_HS_f32);                        /*AN43_18VLS_G5_3*/
			adc_Phy_18V_HS_f32 = 18.0f;/*LQ With the MCU reset in mind, the CPLD will turn off the 18V overbridge power*/
			if( (adc_Phy_18V_HS_f32 > CAL_POWER_VDD18_Threhold_Min_f32) && (adc_Phy_18V_HS_f32 < CAL_POWER_VDD18_Threhold_Max_f32))
			{
				Prv_PowerSetup_State_en = PWR_PVDD16LS;
			}
			else
			{
				Prv_PowerSetup_State_en = PWR_VDD18HS;
			}
		}
		break;
		case PWR_PVDD16LS:
		{
			/*MCU control CPLD output the low bridge Driver power supply PWM signal,when VDD18_LS is normal then output duty is 5% ,period is 75kHz PWM signal£¬at rate of 5%/ms, the duty cycle is increased to 47%. CPLD follows the output and outputs the complementary PWM signal in the dead zone of 3%*/
			#if DRV_POWER_MODE
			Pwm_17_Gtm_SetPeriodAndDuty(Pwm_17_GtmConf_PwmChannel_PWM_18V_L1,DRV_POWER_PERIOD_TICK,ui32_PWM_18VL1_Duty);/*P10.2 PWM*/

			ui32_PWM_18VL1_Duty = DRV_POWER_RATE_OF_RISE_TICK*(ui32_PWRSetup_Counter+1U);
			if( ui32_PWM_18VL1_Duty >= DRV_POWER_DUTY_TICK_MAX)						/*duty from 5% to 47% need 9ms*/
			{
				ui32_PWM_18VL1_Duty = DRV_POWER_DUTY_TICK_MAX;
			}
			#else
			MODULE_P10.IOCR0.U &= 0xF800F8F8;
			MODULE_P10.IOCR0.U |= 0x00800000;				/* set P10.2 to IO output*/
			IoSigDio_Set(DO_DFW_ENABLE, STD_HIGH);			/*open PVDD15VLS power supply */
			#endif

			ui32_PWRSetup_Counter++;
			if( ui32_PWRSetup_Counter >= PWR_PVDD16LS_TIME_LIMIT)
			{
				Prv_PowerSetup_State_en = PWR_PVDD16HS;
				ui32_PWRSetup_Counter = 0;
			}

		}
		break;
		case PWR_PVDD16HS:
		{
			/*MCU control CPLD output the high bridge Driver power supply PWM signal,when high bridge Driver power supply PWM signal to the 47% and VDD18_HS is normal then output duty is 5% ,period is 75kHz PWM signal£¬t a rate of 5%/ms, the duty cycle is increased to 47%. CPLD follows the output and outputs the complementary PWM signal in the dead zone of 3%*/
			#if DRV_POWER_MODE
			Pwm_17_Gtm_SetPeriodAndDuty(Pwm_17_GtmConf_PwmChannel_PWM_18V_H1,DRV_POWER_PERIOD_TICK,ui32_PWM_18VH1_Duty);/*P21.1 PWM*/
			ui32_PWM_18VH1_Duty = DRV_POWER_RATE_OF_RISE_TICK*(ui32_PWRSetup_Counter+1U);
			if( ui32_PWM_18VH1_Duty >= DRV_POWER_DUTY_TICK_MAX)
			{
				ui32_PWM_18VH1_Duty = DRV_POWER_DUTY_TICK_MAX;
			}
			#else
			MODULE_P21.IOCR0.U &= 0xF8F8F8F8;
			MODULE_P21.IOCR0.U |= 0x00008000;				/*set P21.1 to IO output*/
			IoSigDio_Set(DO_18VPWMHEN,  STD_HIGH);			/*open PVDD15VHS power supply*/
			#endif

			ui32_PWRSetup_Counter++;
			if( ui32_PWRSetup_Counter >= PWR_PVDD16HS_TIME_LIMIT)					/*duty from 5% to 47% need 9ms*/
			{
				Prv_PowerSetup_State_en = PWR_FINISH;
				ui32_PWRSetup_Counter = 0U;
			}


		}
		break;
		case PWR_FINISH:
		{
			LvPowerSetupStatus_u8 = PWR_LV_POWERSETUP_OK;

			/*After Hv Power Setup,then initialize hvmcu*/
			HvMcu_Com_Init();
			PosLearn_Init();

			Prv_PowerSetup_State_en = PWR_IDLE;
		}
		break;
		case PWR_IDLE:
		{
			Prv_PowerSetup_State_en = PWR_IDLE;
		}
		break;
		case PWR_ERR:
		{
			Prv_PowerSetup_State_en = PWR_ERR;
			LvPowerSetupStatus_u8 = PWR_LV_POWERSETUP_FAIL;
		}
		break;
		default:
		{
			ui32_PWRSetup_Counter = 0;
			Prv_PowerSetup_State_en = PWR_IDLE;
		}
		break;
	}

	*powerSetup_Finish = LvPowerSetupStatus_u8;
}

/*******************************************************************************
** Function Name	: LV_PowerFinish()
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			:
** Description	  	: Lv Power setup successfully
*******************************************************************************/
uint8 LV_PowerFinish( void)
{
	uint8 ret = 0;
	ret = LvPowerSetupStatus_u8;
	return ret;
}

/*******************************************************************************
** Function Name	: UBSBC_Init_State_Manegement
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: IoSigDio_Init
** Note	  			: None
** Description	  	: DIO pin level initialization
*******************************************************************************/
static void UBSBC_Init_State_Manegement(void)
{
	switch( Prv_UBSBC_Init_State_Control_en )
		{
			case UBSBC_Fail_V1_2:
			{
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail,DEM_EVENT_STATUS_FAILED);
			}
			break;
			case UBSBC_Fail_V2_3:
			{
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr,DEM_EVENT_STATUS_FAILED);
			}
			break;
			case UBSBC_Fail_V4_6:
			{
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr,DEM_EVENT_STATUS_FAILED);
			}
			break;
			case UBSBC_Fail_V6_7:
			case UBSBC_Fail_V7_x:
			{
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail,DEM_EVENT_STATUS_FAILED);
			}
			break;
			default:
			{
				/*Intentionally Empty*/
			}
			break;
		}

}

/*******************************************************************************
** Function Name	: UBSBC_Init_State_Manegement
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: IoSigDio_Init
** Note	  			: None
** Description	  	: DIO pin level initialization
*******************************************************************************/
static void UBSBC_Run_State_Manegement(void)
{
	static en_UBSBCStateType 			 Prv_UBSBC_Run_State_Manegement_en;
    IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN33_KL30_CHANNEL,&VAR_IoHwAb_Adc_Phy_KL30_f32);      /*use for get KL30 Physic value*/
	Prv_UBSBC_Run_State_Manegement_en = UBSBC_ReadStatus(VAR_IoHwAb_Adc_Phy_KL30_f32);
	switch( Prv_UBSBC_Run_State_Manegement_en )
		{
			case UBSBC_Fail_V1_2:
			{
				IoSigDio_Set(DO_EN_EFUSE,   STD_LOW);
				IoSigDio_Set(DO_TJA1043_NSTB,STD_LOW);			/*forbid tja1043_CAN work,Close CAN0 */
			    IoSigDio_Set(DO_TJA1043_EN,  STD_LOW);			/*forbid tja1043_CAN work,Close CAN0 */
			    ComM_CommunicationAllowed(ComMConf_ComMChannel_ComMChannel_Can_Network_0_Channel,FALSE);   /*Close CAN0 communication*/
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail,DEM_EVENT_STATUS_PREFAILED);
			}
			break;
			case UBSBC_Fail_V2_3:
			{
				IoSigDio_Set(DO_EN_EFUSE,   STD_LOW);
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr,DEM_EVENT_STATUS_PREFAILED);
			}
			break;
			case UBSBC_Fail_V4_6:
			{
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr,DEM_EVENT_STATUS_PREFAILED);
			}
			break;
			case UBSBC_Fail_V6_7:
			{
				IoSigDio_Set(DO_TJA1043_NSTB,STD_LOW);			/*forbid tja1043_CAN work*/
				IoSigDio_Set(DO_TJA1043_EN,  STD_LOW);			/*forbid tja1043_CAN work*/
				ComM_CommunicationAllowed(ComMConf_ComMChannel_ComMChannel_Can_Network_0_Channel,FALSE);   /*Close CAN0 communication*/
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail,DEM_EVENT_STATUS_PREFAILED);
			}
			break;
			case UBSBC_Fail_V7_x:
			{
				IoSigDio_Set(DO_EN_EFUSE,   STD_LOW);
				IoSigDio_Set(DO_TJA1043_NSTB,STD_LOW);			/*forbid tja1043_CAN work,Close CAN0 */
				IoSigDio_Set(DO_TJA1043_EN,  STD_LOW);			/*forbid tja1043_CAN work,Close CAN0 */
				ComM_CommunicationAllowed(ComMConf_ComMChannel_ComMChannel_Can_Network_0_Channel,FALSE);   /*Close CAN0 communication*/
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail,DEM_EVENT_STATUS_PREFAILED);
			}
			break;
			default:
			{
				/*Intentionally Empty*/
			}
			break;
		}
}
/*******************************************************************************
** Function Name	: LvPower_Manegement
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: IoSigDio_Init
** Note	  			: None
** Description	  	: DIO pin level initialization
*******************************************************************************/
void LvPower_Manegement(void)
{

	switch(Prv_LvPower_Manegement_en)
	{
		case INIT_UBSBC_State:
		{
			UBSBC_Init_State_Manegement();
			Prv_LvPower_Manegement_en=RUN_UBSBC_State;
		}
		break;
		case RUN_UBSBC_State:
		{
			UBSBC_Run_State_Manegement();
		}
		break;
		default:
		{
			/*Intentionally Empty*/
		}
		break;
	}


}
/*******************************************************************************
** Function Name	: All_ShutDown()
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			:
** Description	  	:
*******************************************************************************/
void All_ShutDown(void)
{

	Pwm_17_Gtm_SetPeriodAndDuty(Pwm_17_GtmConf_PwmChannel_PWM_18V_L1,0,0);/*P10.2 PWM*/
	Pwm_17_Gtm_SetPeriodAndDuty(Pwm_17_GtmConf_PwmChannel_PWM_18V_H1,0,0);/*P21.1 PWM*/

	/*close 18V Enboost*/
	Dio_WriteChannel(DO_EN_BOOTST,STD_HIGH);
	/*close UBR power supply*/
	Dio_WriteChannel(DO_EN_EFUSE,STD_LOW);

//	Pws_DevCtrl(State_STBY);
	Tlf35584SafeWdg_GoTOStandby();
	Timer_DelayTicks(500000);			   /*delay 5ms*/
	while(1)
	{
		Timer_DelayTicks(500000);			/*delay 5ms*/
	     Mcu_PerformReset();
	}
}
/*******************************************************************************

*******************************************************************************/
