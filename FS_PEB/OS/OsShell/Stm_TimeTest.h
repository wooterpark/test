/*******************************************************************************

** DESCRIPTION:
** ����ʱ����Խӿں���ͷ�ļ���ʹ��STM��ʱ������ʱ��
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
/*����ʱ����Ժ꿪�أ�0 for No and 1 for Yes*/
#define TASK_TIME_TEST		1U



/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
typedef	struct	STM_Time
{
	uint32	ui32_StartTick;		/*��ʼ STM TICKֵ*/
	uint32	ui32_StopTick;		/*���� STM TICKֵ*/
	uint32	ui32_Interval;		/*���ζ�ȡSTM���*/
}st_STM_TimeType;
typedef	struct	CPULoadCalc
{
	uint32	ui32_LastSTMValue;		/*�ϴ�STMֵ*/
	uint32	ui32_CurrentSTMValue;	/*��ǰSTMֵ*/
	uint32	ui32_Interval;			/*���ζ�ȡSTM���*/
	uint32	ui32_OccupiedCnt;		/*ռ�ü����ۼ�*/
	float32	f32_CPULoad;			/*CPU������*/
}st_CPULoadeCalcType;
#define	MASK_TIME_SLICE		0x0003FFFFU	/*18λ,2.6 MS   wj*/
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
  	 ����STM_TimeData_Task[15]���ڲ��Ը�������Ҫ�ж�ִ��ʱ��
	ex:��STMʱ��Ϊ100M,ui32_Interval= 6551,Time = 6551/100 = 65.51 US

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
** Description	  	: ������ʼ STM TICKֵ
*******************************************************************************/
extern	void	Stm_Time_CaptureStart(st_STM_TimeType *arg_Data_pst);


/*******************************************************************************
** Function Name	: Stm_Time_CaptureStop
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: ������� STM TICKֵ,������
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
** Description	  	: ������ʼ STM TICKֵ
*******************************************************************************/
extern	void	Stm2_Time_CaptureStart(st_STM_TimeType *arg_Data_pst);


/*******************************************************************************
** Function Name	: Stm_Time_CaptureStop
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: ������� STM TICKֵ,������
*******************************************************************************/
extern	void	Stm2_Time_CaptureStop(st_STM_TimeType *arg_Data_pst);


/*******************************************************************************
** Function Name	: Stm_Time_CaptureInitStart
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: ������� STM TICKֵ,������
*******************************************************************************/
extern void	Stm_Time_CaptureInitStart(void);

/*******************************************************************************
** Function Name	: Stm_Time_CaptureInitStop
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: ������� STM TICKֵ,������
*******************************************************************************/
extern void	Stm_Time_CaptureInitStop(void);

extern void Test_CpuLoadCalc(void);
extern float32 VAR_Cpu_LoadCalc_f32;
#endif /* STM_TIMETEST_H_ */

/*******************************************************************************

*******************************************************************************/
