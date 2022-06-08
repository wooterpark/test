/*
 * WdgM_SWC.h
 *
 *  Created on: Dec 6, 2019
 *      Author: frank.zhang
 */

#ifndef SWC_SRC_SWC_WDGM_WDGM_SWC_H_
#define SWC_SRC_SWC_WDGM_WDGM_SWC_H_

#include "Rte_WdgM_SWC.h"
#include "WdgIf.h"
#include "WdgM.h"

FUNC (void, WdgM_SWC_CODE) RE_WdgM_SWC_10ms_func(void);
FUNC (void, WdgM_SWC_CODE) RE_WdgM_SWC_1ms_Core0_func // return value & FctID
(
		void
);

FUNC (void, WdgM_SWC_CODE) RE_WdgM_SWC_10ms_Core1_func // return value & FctID
(
		void
);

FUNC (void, WdgM_SWC_CODE) RE_WdgM_SWC_10ms_Core0_func // return value & FctID
(
		void
);

#endif /* SWC_SRC_SWC_WDGM_WDGM_SWC_H_ */
