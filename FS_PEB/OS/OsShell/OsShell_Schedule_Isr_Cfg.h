/*
 * OsShell_Schedule_Isr_Cfg.h
 *
 *  Created on: Nov 7, 2019
 *      Author: frank.zhang
 */

#ifndef RTOS_OSSHELL_OSSHELL_SCHEDULE_ISR_CFG_H_
#define RTOS_OSSHELL_OSSHELL_SCHEDULE_ISR_CFG_H_
#include "Os.h"
#include "Std_Types.h"
FUNC(void, OS_APPL_CODE) rba_OsShell_SystemTimer_Isr(void);
void STM1_Isr_Core2_Proc(void);
#endif /* RTOS_OSSHELL_OSSHELL_SCHEDULE_ISR_CFG_H_ */
