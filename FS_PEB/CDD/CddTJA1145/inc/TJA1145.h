/*
 * TJA1145.h
 *
 *  Created on: Dec 15, 2017
 *      Author: PUY1HC
 */

#ifndef CDD_CDDTJA1145_INC_TJA1145_H_
#define CDD_CDDTJA1145_INC_TJA1145_H_

#include "Spi.h"
#define CPU0_START_SEC_CODE
#include "MemMap.h"
extern void TJA1145_GotoStandBy(uint8 channel);
extern void TJA1145_GotoNormal(uint8 channel);
#define CPU0_STOP_SEC_CODE
#include "MemMap.h"
#endif /* CDD_CDDTJA1145_INC_TJA1145_H_ */
