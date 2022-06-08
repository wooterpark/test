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
* $Name______: CPLD_Drv.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: XM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
			The Cpld Drive code file to achieve Communicate with CPLD.
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   Initial version.

*******************************************************************************/
#include "Dem.h"
#include "Spi.h"
#include "Dio.h"
#include "Cpld_Drv.h"
#include "Std_Types.h"
#include "Test_Time.h"
#include "IOHWAB_ADC.h"
#include "Icu_17_GtmCcu6.h"
#include "LvPower_Drv.h"

#define IOHWAB_ADC_OverCurRef    (uint8)17
#define CPLD_CLEAR_FAULT_DELAY            (uint8)6
#define CPLD_ALIVE_FAULT_DEBOUNCE         (uint8)11

static uint32 VAR_Cpld_Rx_Analys_u32;

volatile uint8 VAR_Cpld_Normal_Work_u8=0;

static uint8 VAR_Cpld_State_Fault_Debounce_u8=0;

static Cpld_Rx_Analys_U  Cpld_Rx_Analys =
		{{
			.CountNum		 = 0x00U,
			.SS1Flag        = Tlf35584_SS1_Low,
			.ClearFaultFlag = Mcu_Clear_Cpld_Fault_Unfinish,
			.ReservedBits = 0x00U,
			.ParityCheck	 = Zero,
			.CpldVersion	 = 0x00U,
			.DemoState = DemoA,
			.PublishState = TestVersion,
			.PlatformNum		 = EI07X,
			.PwmDriveState	 = Fully_Close,

			.SZTKTFault = Cpld_Normal,

			.CpldExdClockErr = Cpld_Normal,
			.LwBrgUnderVol	 = Cpld_Normal,
			.UpBrgUnderVol	 = Cpld_Normal,
			.LwBrgShortCru	 = Cpld_Normal,
			.UpBrgShortCru	 = Cpld_Normal,
			.IphOverCurrent	 = Cpld_Normal,
			.UdcOverVoltage	 = Cpld_Normal,
			.NENFault = Cpld_Normal,
		}};

static Cpld_Tx_Analys_U  Cpld_Tx_Analys =
		{
			{
			    US24, 0, 0, 0
		    }
		};

static Cpld_Comu_Cnt_S Cpld_Comu_Cnt;

static void Cpld_Com_DIag(Cpld_Comu_Cnt_S* mPtr);

static float32 OverCurRef;

static uint8 OverCurDiagEn = FALSE;

static Cpld_Clear_Fault_Info_E Cpld_Clear_Fault_State=Cpld_Clear_Fault_Start;

static Cpld_State_Manegement_Info_E Cpld_State=Read_Clear_Cpld_Fault_State;

#pragma section ".rodata.Calib_32"

const volatile uint8 CAL_Cpld_State_Fault_Debounce_Max_u8 	=	 10U;

#pragma section
/*******************************************************************************
** Function Name : Cpld_Com_DIag
** Parameter[in] : Cpld_Comu_Cnt_S*
** Parameter[out]: void
** Return Value  : void
** Note          : static
** Description   : Diag the SPI Rec and Tec Data.
*******************************************************************************/
static void Cpld_Com_DIag(Cpld_Comu_Cnt_S* mPtr)
{
	uint8 i ;
	uint8 ParityBit = (uint8)((Cpld_Rx_Analys.All&0x02U)>>1U);

	for(i = 2U; i < 31U; i++)
	{
		ParityBit ^= (uint8)((Cpld_Rx_Analys.All >> i)&0x01U);
	}



	if(LV_PowerFinish())
	{

	Std_Equal_Diag((ParityBit&0x01U),((uint8)(Cpld_Rx_Analys.Bit.ParityCheck)),(mPtr->ParityChkCnt),\
			((void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_ParityChkErr,DEM_EVENT_STATUS_FAILED)))

	Std_Equal_Diag((((uint8)(Cpld_Rx_Analys.Bit.UdcOverVoltage))&OverCurDiagEn),(0U),(mPtr->UdcOverVolCnt),\
			((void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_UdcOverVolFail,DEM_EVENT_STATUS_FAILED)))

	Std_Equal_Diag((((uint8)(Cpld_Rx_Analys.Bit.CpldExdClockErr))&OverCurDiagEn),(0U),(mPtr->ExdClockErrCnt),\
			((void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_ExdClkInFail,DEM_EVENT_STATUS_FAILED)))

	Std_Equal_Diag((Dio_ReadChannel(DioConf_DioChannel_DI_SPIERR_P10_1)),(STD_HIGH),(mPtr->SPIComErrCnt),\
				((void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_SPIComFail,DEM_EVENT_STATUS_FAILED)))

	Std_Equal_Diag((Dio_ReadChannel(DioConf_DioChannel_DI_CLKERR_P21_3)),(STD_HIGH),(mPtr->DIExdClockErrCnt),\
					((void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail,DEM_EVENT_STATUS_FAILED)))

	Std_Equal_Diag((((uint8)(Cpld_Rx_Analys.Bit.IphOverCurrent))&OverCurDiagEn),(0U),(mPtr->IphOverCurCnt),\
			((void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_IphaOC,DEM_EVENT_STATUS_FAILED)))

	Std_Equal_Diag((((uint8)(Cpld_Rx_Analys.Bit.SZTKTFault))&OverCurDiagEn),(0U),(mPtr->SZTKTFaultCnt),\
			((void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_SZTKT_InFail,DEM_EVENT_STATUS_FAILED)))

	Std_Equal_Diag((((uint8)(Cpld_Rx_Analys.Bit.LwBrgUnderVol))&OverCurDiagEn),(0U),(mPtr->LwBrgUnderVolCnt),\
			((void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail,DEM_EVENT_STATUS_FAILED)))

	Std_Equal_Diag((((uint8)(Cpld_Rx_Analys.Bit.UpBrgUnderVol))&OverCurDiagEn),(0U),(mPtr->UpBrgUnderVolCnt),\
			((void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail,DEM_EVENT_STATUS_FAILED)))

	Std_Equal_Diag((((uint8)(Cpld_Rx_Analys.Bit.LwBrgShortCru))&OverCurDiagEn),(0U),(mPtr->LwBrgShortCruCnt),\
			((void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail,DEM_EVENT_STATUS_FAILED)))

	Std_Equal_Diag((((uint8)(Cpld_Rx_Analys.Bit.UpBrgShortCru))&OverCurDiagEn),(0U),(mPtr->UpBrgShortCruCnt),\
			((void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail,DEM_EVENT_STATUS_FAILED)))

	Std_Equal_Diag((((uint8)(Cpld_Rx_Analys.Bit.NENFault))&OverCurDiagEn),(0U),(mPtr->NENFaultCnt),\
			((void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_NEN_InFail,DEM_EVENT_STATUS_FAILED)))
	}
}

/*******************************************************************************
** Function Name : Cpld_Com_Task
** Parameter[in] : void
** Parameter[out]: void
** Return Value  : void
** Note          : 10ms/100ms
** Description   : The Function is Creat for SPI community in task.
*******************************************************************************/
void Cpld_Com_Task(Cpld_OutPut_S *mOut)
{
    (void)Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_CPLD, (uint8*)&Cpld_Tx_Analys.All, (uint8*)&Cpld_Rx_Analys.All, 1);

    (void)Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_CPLD);

    Cpld_Com_DIag(&Cpld_Comu_Cnt);

    mOut->CpldVersion = (uint8)Cpld_Rx_Analys.Bit.CpldVersion;
	mOut->ProjectNum = (uint8)Cpld_Rx_Analys.Bit.PlatformNum;
	mOut->PwmDriveState = Cpld_Rx_Analys.Bit.PwmDriveState;
	VAR_Cpld_Rx_Analys_u32=Cpld_Rx_Analys.All;
}

/*******************************************************************************
** Function Name : Cpld_Clear_Fault
** Parameter[in] : void
** Parameter[out]: void
** Return Value  : void
** Note          : clear the cpld fault and dealy 20us in the process of clear.
** Description   : The Function will be use to Clear the Fault of Cpld return in the init.
*******************************************************************************/
void Cpld_Start_Clear_Fault(void)
{
	Dio_WriteChannel(DioConf_DioChannel_DO_CPLDCLR_P10_0,STD_HIGH);

}

/*******************************************************************************
** Function Name : Cpld_Stop_Clear_Fault
** Parameter[in] : void
** Parameter[out]: void
** Return Value  : void
** Note          : StoPing clear the cpld fault .
** Description   : The Function will be use to Stoping Clear the Fault of Cpld .
*******************************************************************************/
void Cpld_Stop_Clear_Fault(void)
{
	Dio_WriteChannel(DioConf_DioChannel_DO_CPLDCLR_P10_0,STD_LOW);
}

/*******************************************************************************
** Function Name : Cpld_Clear_Fault_Management
** Parameter[in] : void
** Parameter[out]: void
** Return Value  : void
** Note          : management Start and Stop Clear the Cpld fault
** Description   : The Function will management  Start and Stop Clear the Cpld fault.
*******************************************************************************/
void Cpld_Clear_Fault_Management(void)
{
	static uint8 Cpld_Clear_Fault_Delay_Count;
	static Dio_LevelType Cpld_Alive_Dio_Level;
	static uint8 Cpld_Alive_Fault_Count;

    switch(Cpld_Clear_Fault_State)
    {
    	case Cpld_Clear_Fault_Start:
    	{
    		if(FALSE == OverCurDiagEn)
    			{
    				IoHwAb_ADC_GetPhyVoltage(IOHWAB_ADC_OverCurRef,&OverCurRef);
				if ((OverCurRef > 4.0F)&&(LV_PowerFinish()==1))
    				{
					Cpld_Alive_Fault_Count=0;
					Cpld_Clear_Fault_Delay_Count=0;
    	    			Cpld_Start_Clear_Fault();
    	    			Cpld_Clear_Fault_State=Cpld_Clear_Fault_Stop;

    				}
    			}

    	}
    	break;
       	case Cpld_Clear_Fault_Stop:
        	{
        		    Cpld_Clear_Fault_Delay_Count++;
        		    if(CPLD_CLEAR_FAULT_DELAY==Cpld_Clear_Fault_Delay_Count)
        		    {
        			Cpld_Stop_Clear_Fault();
        			OverCurDiagEn = TRUE;
						Cpld_Clear_Fault_State=Cpld_Alive_Detect_Start;
        		    }
        	}
        break;
    	case Cpld_Alive_Detect_Start:
    	{
    		Cpld_Alive_Dio_Level=Dio_ReadChannel(DioConf_DioChannel_DI_CPLDRES2_P21_2);
    		if(STD_LOW==Cpld_Alive_Dio_Level)
			{
    			Cpld_Alive_Fault_Count++;
			}
    		if(CPLD_ALIVE_FAULT_DEBOUNCE==Cpld_Alive_Fault_Count)
    		{
    			Cpld_Clear_Fault_State=Cpld_Alive_Fault_Occur;
    		}

    	}
    	break;
       	case Cpld_Alive_Fault_Occur:
		{

			(void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_AliveChkErr,DEM_EVENT_STATUS_FAILED);
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
** Function Name : Cpld_State_Management
** Parameter[in] : void
** Parameter[out]: void
** Return Value  : void
** Note          : management Start and Stop Clear the Cpld fault
** Description   : The Function will management  Start and Stop Clear the Cpld fault.
*******************************************************************************/
void Cpld_State_Management(void)
{
	static Dio_LevelType DO_ASC_P02_10_Dio_Level;
	switch(Cpld_State)
	{
		case Read_Clear_Cpld_Fault_State:
		{
			if(TRUE==OverCurDiagEn)
			{
				Cpld_State=Read_TLF35584_SS1_State;
			}
		}
		break;
		case Read_TLF35584_SS1_State:
		{
			DO_ASC_P02_10_Dio_Level=Dio_ReadChannel(DioConf_DioChannel_DO_ASC_P02_10);
			if(STD_HIGH==DO_ASC_P02_10_Dio_Level)
			{
				Cpld_State=Read_Cpld_Rx_State;
			}
		}
		break;
		case Read_Cpld_Rx_State:
		{
			if((Mcu_Clear_Cpld_Fault_Finish==Cpld_Rx_Analys.Bit.ClearFaultFlag)&&(Tlf35584_SS1_High==Cpld_Rx_Analys.Bit.SS1Flag))
			{
				VAR_Cpld_Normal_Work_u8=1;
				Cpld_State=Cpld_State_Normal;
			}
			else
			{
				VAR_Cpld_State_Fault_Debounce_u8++;
				if(VAR_Cpld_State_Fault_Debounce_u8>=CAL_Cpld_State_Fault_Debounce_Max_u8)
				{
					Cpld_State=Cpld_State_Fault_Occur;
				}
			}
		}
		break;
		case Cpld_State_Fault_Occur:
		{
			(void)Dem_SetEventStatus(DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail,DEM_EVENT_STATUS_FAILED);
		}
		break;
		case Cpld_State_Normal:
		{

		}
		break;
		default:
		{

		}
		break;

	}
}
