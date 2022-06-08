/*
 * OsShell_Schedule_Cfg.h
 *
 *  Created on: Nov 2, 2019
 *      Author: frank.zhang
 */

#ifndef RTOS_OSSHELL_OSSHELL_SCHEDULE_CFG_H_
#define RTOS_OSSHELL_OSSHELL_SCHEDULE_CFG_H_

#include "Os.h"
#include "Rte.h"
#include "CanTp.h"
#include "EcuM.h"
#include "Xcp.h"
//#include "Test_Bsw.h"
#include "rba_MemDiag.h"
#include "WdgM.h"
#include "WdgM_SWC.h"
#include "rba_Mpu_Appl.h"
#include "Smu_Appl.h"

FUNC(void, RTE_CODE) Rte_task_BSW_1ms_Task_Core0(void);
FUNC(void, RTE_CODE) Rte_task_BSW_5ms_Task_Core0(void);
FUNC(void, RTE_CODE) Rte_task_BSW_10ms_Task_Core0(void);
FUNC(void, RTE_CODE) Rte_task_Dcm_task(void);
FUNC(void, RTE_CODE) Rte_task_SWC_1ms_Task_Core0(void);
FUNC(void, RTE_CODE) Rte_task_SWC_5ms_Task_Core0(void);
FUNC(void, RTE_CODE) Rte_task_SWC_10ms_Task_Core0(void);
FUNC(void, RTE_CODE) Rte_task_SWC_20ms_Task_Core0(void);
FUNC(void, RTE_CODE) Rte_task_SWC_50ms_Task_Core0(void);
FUNC(void, RTE_CODE) Rte_task_SWC_100ms_Task_Core0(void);
FUNC(void, RTE_CODE) Rte_task_SWC_1000ms_Task_Core0(void);
FUNC(void, RTE_CODE) Rte_task_Os_Init_Task_Core0(void);
FUNC(void, RTE_CODE) Rte_task_Os_Init_Task_Core1(void);
FUNC(void, RTE_CODE) Rte_task_Os_Init_Task_Core2(void);

FUNC(void, RTE_CODE) Rte_task_BSW_1ms_Task_Core1(void);
FUNC(void, RTE_CODE) Rte_task_BSW_5ms_Task_Core1(void);
FUNC(void, RTE_CODE) Rte_task_BSW_10ms_Task_Core1(void);
FUNC(void, RTE_CODE) Rte_task_SWC_1ms_Task_Core1(void);
FUNC(void, RTE_CODE) Rte_task_SWC_5ms_Task_Core1(void);
FUNC(void, RTE_CODE) Rte_task_SWC_10ms_Task_Core1(void);
FUNC(void, RTE_CODE) Rte_task_SWC_20ms_Task_Core1(void);
FUNC(void, RTE_CODE) Rte_task_SWC_50ms_Task_Core1(void);
FUNC(void, RTE_CODE) Rte_task_SWC_100ms_Task_Core1(void);
FUNC(void, RTE_CODE) Rte_task_SWC_1000ms_Task_Core1(void);
void Bsw_StartUp_0Core0_Proc(void);
void Bsw_StartUp_0Core1_Proc(void);
void Bsw_StartUp_0Core2_Proc(void);

void Bsw_StartUp_1Core0_Proc(void);
void Bsw_StartUp_1Core1_Proc(void);
void Bsw_StartUp_1Core2_Proc(void);

void WdgAppl_Core0(void);
void WdgAppl_Core1(void);
void WdgAppl_Core2(void);

FUNC(void, RTE_CODE) Rte_task_BSW_10ms_Task_Core2(void);

#endif /* RTOS_OSSHELL_OSSHELL_SCHEDULE_CFG_H_ */
