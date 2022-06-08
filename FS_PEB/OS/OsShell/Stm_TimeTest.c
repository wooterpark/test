/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: $
* $Class_____: C$
* $Name______: Stm_TimeTest.c$
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
#include	"Stm_TimeTest.h"
#include	"IfxStm_reg.h"
#include	"IfxCpu_reg.h"
#include	"intrinsics.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
/* 间隔值大于IDLE任务执行时间 (估计时间 N us)100M STM 5us */
#define	EMPTY_LOOP_TIME						500U

/*SLICE设置必须为2^n-1*/
//#define	MASK_TIME_SLICE		0x01FFFFFFU	/*25位,335.5 MS*/
//#define	MASK_TIME_SLICE		0x00FFFFFFU	/*24位,167.7 MS*/
//#define	MASK_TIME_SLICE		0x007FFFFFU	/*23位,83.8 MS*/
//#define	MASK_TIME_SLICE		0x003FFFFFU	/*22位,41.9 MS*/
//#define	MASK_TIME_SLICE		0x001FFFFFU	/*21位,20.9 MS*/
#define	MASK_TIME_SLICE		0x000FFFFFU	/*20位,10.5 MS*/
//#define	MASK_TIME_SLICE		0x0007FFFFU	/*19位,5.2 MS*/
//#define	MASK_TIME_SLICE		0x0003FFFFU	/*18位,2.6 MS*/

/* CPU ID MASK */
#define CPU_LOAD_FACTOR_CORE_ID_MASK		0x07U

#define CPU_LOAD_FACTOR_CPU_NUM				3U	/*CPU数量*/
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
st_STM_TimeType STM_TimeData_Task[30U];
st_STM_TimeType st_STMInit;

/*CPU负载率计算结构体数据数组*/
st_CPULoadeCalcType	st_CPULoadeCalc[CPU_LOAD_FACTOR_CPU_NUM];
/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: Stm_Time_CaptureStart
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 捕获起始 STM TICK值
*******************************************************************************/
void	Stm_Time_CaptureStart(st_STM_TimeType *arg_Data_pst)
{
	arg_Data_pst->ui32_StartTick = STM0_TIM0.B.STM31_0;
}

/*******************************************************************************
** Function Name	: Stm_Time_CaptureStop
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 捕获结束 STM TICK值,并计算
*******************************************************************************/
void	Stm_Time_CaptureStop(st_STM_TimeType *arg_Data_pst)
{
	arg_Data_pst->ui32_StopTick = STM0_TIM0.B.STM31_0;

	if(arg_Data_pst->ui32_StopTick > arg_Data_pst->ui32_StartTick)
	{
		arg_Data_pst->ui32_Interval = \
				arg_Data_pst->ui32_StopTick - arg_Data_pst->ui32_StartTick;
	}
	else
	{
		arg_Data_pst->ui32_Interval = \
			0xFFFFFFFFU - arg_Data_pst->ui32_StartTick +\
			arg_Data_pst->ui32_StopTick;
	}
}

/*******************************************************************************
** Function Name	: Stm_Time_CaptureStart
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 捕获起始 STM TICK值
*******************************************************************************/
void	Stm2_Time_CaptureStart(st_STM_TimeType *arg_Data_pst)
{
	arg_Data_pst->ui32_StartTick = STM2_TIM0.B.STM31_0;
}

/*******************************************************************************
** Function Name	: Stm_Time_CaptureStop
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 捕获结束 STM TICK值,并计算
*******************************************************************************/
void	Stm2_Time_CaptureStop(st_STM_TimeType *arg_Data_pst)
{
	arg_Data_pst->ui32_StopTick = STM2_TIM0.B.STM31_0;

	if(arg_Data_pst->ui32_StopTick > arg_Data_pst->ui32_StartTick)
	{
		arg_Data_pst->ui32_Interval = \
				arg_Data_pst->ui32_StopTick - arg_Data_pst->ui32_StartTick;
	}
	else
	{
		arg_Data_pst->ui32_Interval = \
			0xFFFFFFFFU - arg_Data_pst->ui32_StartTick +\
			arg_Data_pst->ui32_StopTick;
	}
}

void	Stm1_Time_CaptureStart(st_STM_TimeType *arg_Data_pst)
{
	arg_Data_pst->ui32_StartTick = STM1_TIM0.B.STM31_0;
}
/**************************************************************************
** Function Name	: Stm_Time_CaptureStop
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: capture stop STM TICK value and resolve
*******************************************************************************/
void	Stm1_Time_CaptureStop(st_STM_TimeType *arg_Data_pst)
{
	arg_Data_pst->ui32_StopTick = STM1_TIM0.B.STM31_0;
	if(arg_Data_pst->ui32_StopTick > arg_Data_pst->ui32_StartTick)
	{
		arg_Data_pst->ui32_Interval = \
				arg_Data_pst->ui32_StopTick - arg_Data_pst->ui32_StartTick;
	}
	else
	{
		arg_Data_pst->ui32_Interval = \
			0xFFFFFFFFU - arg_Data_pst->ui32_StartTick +\
			arg_Data_pst->ui32_StopTick;
	}
}

/*******************************************************************************
** Function Name	: Test_CpuLoadCalc
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	：IDLE任务调用
** Description	  	: CPU负载率测试函数
*******************************************************************************/
float32 VAR_Cpu_LoadCalc_f32;
void Test_CpuLoadCalc(void)
{
#if 0u
	/*读STM0值*/
	st_CPULoadeCalc[0U].ui32_CurrentSTMValue = STM0_TIM0.B.STM31_0;

	/*取前N位*/
	st_CPULoadeCalc[0U].ui32_CurrentSTMValue &= MASK_TIME_SLICE;

	/*当前STM值大于等于上次STM值*/
	if(st_CPULoadeCalc[0U].ui32_CurrentSTMValue >= \
			st_CPULoadeCalc[0U].ui32_LastSTMValue)
	{
		/*计算间隔值*/
		st_CPULoadeCalc[0U].ui32_Interval = \
			st_CPULoadeCalc[0U].ui32_CurrentSTMValue - \
			st_CPULoadeCalc[0U].ui32_LastSTMValue;

		/*间隔值大于IDLE任务执行时间 (估计时间 N us)*/
		if(st_CPULoadeCalc[0U].ui32_Interval > EMPTY_LOOP_TIME)
		{
			/*占用计数累计增加*/
			st_CPULoadeCalc[0U].ui32_OccupiedCnt += \
					st_CPULoadeCalc[0U].ui32_Interval;
		}
	}
	/* 当前STM值小于上次STM值，说明计数已超过MASK_TIME_SLICE，
	 * 可计算MASK_TIME_SLICE时间内的CPU负载率 */
	else
	{
		/*计算CPU负载率*/
		st_CPULoadeCalc[0U].f32_CPULoad = \
			(float32)st_CPULoadeCalc[0U].ui32_OccupiedCnt / \
				(float32)MASK_TIME_SLICE;
		st_CPULoadeCalc[0U].ui32_OccupiedCnt = 0U;	/*占用计数清零*/
	}

	/*更新上次STM值*/
	st_CPULoadeCalc[0U].ui32_LastSTMValue = \
			st_CPULoadeCalc[0U].ui32_CurrentSTMValue;

	VAR_Cpu_LoadCalc_f32 = st_CPULoadeCalc[0U].f32_CPULoad;
#endif


	uint8 CoreId;

	CoreId = ((uint8)__mfcr(CPU_CORE_ID)) & (uint8)CPU_LOAD_FACTOR_CORE_ID_MASK;

	/*读STM0值*/
	st_CPULoadeCalc[CoreId].ui32_CurrentSTMValue = STM0_TIM0.B.STM31_0;

	/*取前N位*/
	st_CPULoadeCalc[CoreId].ui32_CurrentSTMValue &= MASK_TIME_SLICE;

	/*当前STM值大于等于上次STM值*/
	if(st_CPULoadeCalc[CoreId].ui32_CurrentSTMValue >= \
			st_CPULoadeCalc[CoreId].ui32_LastSTMValue)
	{
		/*计算间隔值*/
		st_CPULoadeCalc[CoreId].ui32_Interval = \
			st_CPULoadeCalc[CoreId].ui32_CurrentSTMValue - \
			st_CPULoadeCalc[CoreId].ui32_LastSTMValue;

		/*间隔值大于IDLE任务执行时间 (估计时间 N us)*/
		if(st_CPULoadeCalc[CoreId].ui32_Interval > EMPTY_LOOP_TIME)
		{
			/*占用计数累计增加*/
			st_CPULoadeCalc[CoreId].ui32_OccupiedCnt += \
					st_CPULoadeCalc[CoreId].ui32_Interval;
		}
	}
	/* 当前STM值小于上次STM值，说明计数已超过MASK_TIME_SLICE，
	 * 可计算MASK_TIME_SLICE时间内的CPU负载率 */
	else
	{
		/*计算CPU负载率*/
		st_CPULoadeCalc[CoreId].f32_CPULoad = \
			(float32)st_CPULoadeCalc[CoreId].ui32_OccupiedCnt / \
				(float32)MASK_TIME_SLICE;
		st_CPULoadeCalc[CoreId].ui32_OccupiedCnt = 0U;	/*占用计数清零*/
	}

	/*更新上次STM值*/
	st_CPULoadeCalc[CoreId].ui32_LastSTMValue = \
			st_CPULoadeCalc[CoreId].ui32_CurrentSTMValue;



}

/*******************************************************************************
** Function Name	: Stm_Time_CaptureInitStart
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 捕获起始 STM TICK值
*******************************************************************************/
void	Stm_Time_CaptureInitStart(void)
{
	st_STMInit.ui32_StartTick = STM0_TIM0.B.STM31_0;
}

/*******************************************************************************
** Function Name	: Stm_Time_CaptureInitStop
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 捕获结束 STM TICK值,并计算
*******************************************************************************/
void	Stm_Time_CaptureInitStop(void)
{
	st_STMInit.ui32_StopTick = STM0_TIM0.B.STM31_0;

	if(st_STMInit.ui32_StopTick > st_STMInit.ui32_StartTick)
	{
		st_STMInit.ui32_Interval = \
				st_STMInit.ui32_StopTick - st_STMInit.ui32_StartTick;
	}
	else
	{
		st_STMInit.ui32_Interval = \
			0xFFFFFFFFU - st_STMInit.ui32_StartTick +\
			st_STMInit.ui32_StopTick;
	}
}

