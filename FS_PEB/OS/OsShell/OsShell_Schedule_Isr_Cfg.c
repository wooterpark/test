/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \OsShell\OsShell_Schedule_Isr_Cfg.c$
* $Class_____: C$
* $Name______: .c$
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
V1.0.0:   The initial release


*******************************************************************************/

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "OsShell_Schedule_Isr_cfg.h"
#include "Rte.h"
#include "Stm_TimeTest.h"
#include "L2Sample_FS.h"
#include "SWC_TRSP.h"
#include "SWC_SWD.h"
#include "SWC_ADM.h"
#include "SWC_TCF.h"
#include "SWC_FRP.h"
#include "SWC_STM.h"
#include "L2SOP_FS.h"
#include "L2COM_FS.h"
#include "Test_Time.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/



/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/
static st_STM_TimeType STM2_TimeDataPwm3ph_Edge_ISR;
static st_STM_TimeType STM0_TimeData_AdcISR;
static st_STM_TimeType STM0_TimeData_DsAdcISR;
static st_STM_TimeType STM1_TimeData_FS_L2_ISR;
static st_STM_TimeType STM1_TimeData_VADC_RDC_ISR;
static st_STM_TimeType STM1_TimeData_L2_1ms_ISR;

static uint32 ui32_TomNotification_Pwm3ph_Edge;
static uint32 ui32_GptNotification100us;
static uint32 ui32_U1_V2_AdcNotification;
static uint32 ui32_DsAdcNotification;
static uint32 ui32_ICU_TIM0SR5_p32_4_edge;
static uint32 ui32_TomNotification_L2_FS_edge;
static uint32 ui32_TomNotification_VADC_RDC_edge;
static uint32 VAR_RslSamp_TOM0CH1_TimeStampe_u32;
static uint32 VAR_RslSamp_TOM0CH1_TimeStampePre_u32 = 0;
static uint32 VAR_RslSamp_TOM2CH13_TimeStampe_u32;
static float32 VAR_CompDiff_TimeStampe_f32;
static float32 VAR_CompDiff_TimeStampe1_f32;
static float32 VAR_CompDiff_TimeStampeSpd_f32;
static float32 VAR_CompDiff_TimeStampeSpd1_f32;
/*******************************************************************************
**                   Global Variables Definition              		  **
*******************************************************************************/
uint32 VAR_STM0_TimeData_AdcISR_u32;
uint32 VAR_STM0_TimeData_DsAdcISR_u32;
uint32 VAR_STM2_TimeData_Pwm3ph_EdgeISR_u32;
uint32 VAR_STM1_TimeData_FS_L2_u32;
uint32 VAR_STM1_TimeData_VADC_RDC_u32;
uint32 VAR_FS_ISR_1ms_Cntr_u32;
uint32 VAR_FS_ISR_10ms_Cntr_u32;

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

ISR(SystemTimer_ISR)
{

  rba_OsShell_SystemTimer_Isr();
}


ISR(STM_OsCounter_Core2)
{
	STM1_Isr_Core2_Proc();
}

//#pragma section ".internalcode" ax
/*******************************************************************************
** Function Name	: U1_V2_AdcNotification
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	:
** Description	  	: Core0 ADC Finish ISR
*******************************************************************************/
void U1_V2_AdcNotification(void)
{
	ui32_U1_V2_AdcNotification++;
	Stm_Time_CaptureStart(&STM0_TimeData_AdcISR);

	Rte_task_Os_U1_V2_Core0_ISR();
	IoHwAb_DIO_DEM();
	Cpld_Clear_Fault_Management();
#if 0
#ifdef HIGHTEC_COMPILER
	ETK_Distab13_Process_Rxx(1, 1, 0, 0, 0x0101);/*ETK*/
#endif
#endif

	Stm_Time_CaptureStop(&STM0_TimeData_AdcISR);
	VAR_STM0_TimeData_AdcISR_u32 = STM0_TimeData_AdcISR.ui32_Interval/100;/*us*/
}


//#pragma section

/*******************************************************************************
** Function Name	: RdcNotification
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	:
**
** Description	  	: RdcNotification
*******************************************************************************/
void RdcNotification( )
{
	ui32_DsAdcNotification++;
	Stm_Time_CaptureStart(&STM0_TimeData_DsAdcISR);

	Rte_task_Os_GpDsadc_Res_Core0_ISR();/*Dsadc ISR*/

	Stm_Time_CaptureStop(&STM0_TimeData_DsAdcISR);
	VAR_STM0_TimeData_DsAdcISR_u32 = STM0_TimeData_DsAdcISR.ui32_Interval/100;/*us*/
}

#pragma section ".internalcode" ax
/*******************************************************************************
** Function Name	: TomNotification_Pwm3ph_Edge
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	:
** Description	  	: Core2 PWM Algorithm ISR
*******************************************************************************/
void TomNotification_Pwm3ph_Edge(void)
{
	ui32_TomNotification_Pwm3ph_Edge++;
	Stm2_Time_CaptureStart(&STM2_TimeDataPwm3ph_Edge_ISR);

	Rte_task_Os_Com_Pwm3ph_Edge_Core2_ISR( );

	Stm2_Time_CaptureStop(&STM2_TimeDataPwm3ph_Edge_ISR);
	VAR_STM2_TimeData_Pwm3ph_EdgeISR_u32 = STM2_TimeDataPwm3ph_Edge_ISR.ui32_Interval/100;/*us*/
}
#pragma section


/*******************************************************************************
** Function Name	: AtomNotification_Pwm3ph_Central
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	:
** Description	  	: Temp
*******************************************************************************/
#pragma section ".text.CPU1_Code" ax
void TomNotification_L2_FS(void)
{
	//Dio_WriteChannel(DIO_CHANNEL_1_5,STD_LOW);
	ui32_TomNotification_L2_FS_edge++;
	Stm1_Time_CaptureStart(&STM1_TimeData_FS_L2_ISR);
	L2Sampling_FS();
	if(ui32_TomNotification_L2_FS_edge > 1500)
	{
		SWC_TRSP_100us();
	}
	Stm1_Time_CaptureStop(&STM1_TimeData_FS_L2_ISR);
	VAR_STM1_TimeData_FS_L2_u32 = STM1_TimeData_FS_L2_ISR.ui32_Interval/100;/*us*/
	//Dio_WriteChannel(DIO_CHANNEL_1_5,STD_HIGH);
}

/*******************************************************************************
** Function Name	: TomNotification_L2_ISR_1ms
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	:
** Description	  	: FS L2 1ms Interrupt
*******************************************************************************/
void TomNotification_L2_ISR_1ms(void)
{

	Stm1_Time_CaptureStart(&STM1_TimeData_L2_1ms_ISR);

	FS_Shut_Of_Path_L2();

	VAR_FS_ISR_1ms_Cntr_u32++;
	VAR_FS_ISR_10ms_Cntr_u32++;
	IgbtDrv_10ms_MainFunction();
	SWC_TRSP_1ms();
	if(VAR_FS_ISR_10ms_Cntr_u32==10)
	{
		 FS_FltInfoCom_Report();
		 VAR_FS_ISR_10ms_Cntr_u32=0;
	}
	SWC_TCF_1ms();
	SWC_STM_1ms();
	SWC_ADM_1ms();
	SWC_FRP_1ms();

    Stm1_Time_CaptureStop(&STM1_TimeData_L2_1ms_ISR);

    }
#pragma section
/*******************************************************************************
** Function Name	: TomNotification_L2_FS
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	:
** Description	  	: L2 safety function sample interrupt
*******************************************************************************/
void TomNotification_VADC_RDC(void)
{
//	Dio_WriteChannel(DIO_CHANNEL_1_6,STD_LOW);

	ui32_TomNotification_VADC_RDC_edge++;
	Stm1_Time_CaptureStart(&STM1_TimeData_VADC_RDC_ISR);
	FS_VADC_RDC_offset();//Temporary disable YXQ 20210203
	//Timer_DelayTicks(2000U);//ZJR
	if(ui32_TomNotification_VADC_RDC_edge >= 1000)
	{
	Rdc_FS_DMA_Buffer_RD_Result(); //Temporary disable YXQ 20210203
	}
	SWC_SWD_100us();
	FS_ICU_Get_3phPWMPeriod_DutyCycle();

	Stm1_Time_CaptureStop(&STM1_TimeData_VADC_RDC_ISR);
	VAR_STM1_TimeData_VADC_RDC_u32 = STM1_TimeData_VADC_RDC_ISR.ui32_Interval/100;/*us*/
}
/*******************************************************************************
** Function Name	: GptNotification100us
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	:
**
** Description	  	: Core0 100us ISR
*******************************************************************************/
void GptNotification100us()
{
	ui32_GptNotification100us++;
	Rte_task_Os_Gpt100us_core0_ISR(  );
}

void ICU_TIM0SR5_P32_4_edge(void)
{
	ui32_ICU_TIM0SR5_p32_4_edge++;

}
