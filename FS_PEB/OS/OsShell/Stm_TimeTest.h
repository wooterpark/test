/*******************************************************************************

** DESCRIPTION:
** 任务时间测试接口函数头文件，使用STM定时器捕获时间
*******************************************************************************/
#ifndef STM_TIMETEST_H_
#define STM_TIMETEST_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include	"Std_Types.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
/*任务时间测试宏开关，0 for No and 1 for Yes*/
#define TASK_TIME_TEST		1U



/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
typedef	struct	STM_Time
{
	uint32	ui32_StartTick;		/*起始 STM TICK值*/
	uint32	ui32_StopTick;		/*结束 STM TICK值*/
	uint32	ui32_Interval;		/*两次读取STM间隔*/
}st_STM_TimeType;
typedef	struct	CPULoadCalc
{
	uint32	ui32_LastSTMValue;		/*上次STM值*/
	uint32	ui32_CurrentSTMValue;	/*当前STM值*/
	uint32	ui32_Interval;			/*两次读取STM间隔*/
	uint32	ui32_OccupiedCnt;		/*占用计数累计*/
	float32	f32_CPULoad;			/*CPU负载率*/
}st_CPULoadeCalcType;
#define	MASK_TIME_SLICE		0x0003FFFFU	/*18位,2.6 MS   wj*/
/*100M STM 5us*/
#define	EMPTY_LOOP_TIME		500U
/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/
#if (TASK_TIME_TEST == 1U)
extern	st_STM_TimeType STM_TimeData_Task[30U];
#endif
extern st_STM_TimeType STM_TimeData_NvM;

extern st_STM_TimeType st_STMInit;
/*******************************************************************************
  	 变量STM_TimeData_Task[15]用于测试各任务及重要中断执行时间
	ex:若STM时钟为100M,ui32_Interval= 6551,Time = 6551/100 = 65.51 US

*******************************************************************************/

/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

/*******************************************************************************
** Function Name	: Stm_Time_CaptureStart
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 捕获起始 STM TICK值
*******************************************************************************/
extern	void	Stm_Time_CaptureStart(st_STM_TimeType *arg_Data_pst);


/*******************************************************************************
** Function Name	: Stm_Time_CaptureStop
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 捕获结束 STM TICK值,并计算
*******************************************************************************/
extern	void	Stm_Time_CaptureStop(st_STM_TimeType *arg_Data_pst);

/*******************************************************************************
** Function Name	: Stm_Time_CaptureStart
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: capture start STM TICK value
*******************************************************************************/
extern void	Stm1_Time_CaptureStart(st_STM_TimeType *arg_Data_pst);

/*******************************************************************************
** Function Name	: Stm_Time_CaptureStop
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: capture stop STM TICK value and resolve
*******************************************************************************/
extern void	Stm1_Time_CaptureStop(st_STM_TimeType *arg_Data_pst);

/*******************************************************************************
** Function Name	: Stm_Time_CaptureStart
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 捕获起始 STM TICK值
*******************************************************************************/
extern	void	Stm2_Time_CaptureStart(st_STM_TimeType *arg_Data_pst);


/*******************************************************************************
** Function Name	: Stm_Time_CaptureStop
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 捕获结束 STM TICK值,并计算
*******************************************************************************/
extern	void	Stm2_Time_CaptureStop(st_STM_TimeType *arg_Data_pst);


/*******************************************************************************
** Function Name	: Stm_Time_CaptureInitStart
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 捕获结束 STM TICK值,并计算
*******************************************************************************/
extern void	Stm_Time_CaptureInitStart(void);

/*******************************************************************************
** Function Name	: Stm_Time_CaptureInitStop
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 捕获结束 STM TICK值,并计算
*******************************************************************************/
extern void	Stm_Time_CaptureInitStop(void);

extern void Test_CpuLoadCalc(void);
extern float32 VAR_Cpu_LoadCalc_f32;
#endif /* STM_TIMETEST_H_ */

/*******************************************************************************

*******************************************************************************/
