/*
 * test.h
 *
 *  Created on: 2021Äê8ÔÂ14ÈÕ
 *      Author: allen.zhao
 */
#include "ChipId.h"
#include "Mcal_TcLib.h"
#include "Mcal_WdgLib.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"
#include "IfxScu_reg.h"

#ifndef CDD_SAFETLIB_TEST_H_
#define CDD_SAFETLIB_TEST_H_

extern Sl_TstRsltType  CpuTst_CpuSbstETst(const   Sl_ParamSetType ParamSetIndex,
                                 const   uint8 TstSeed,
                                 uint32* const TstSignature);


extern Sl_TstRsltType  CpuTst_CpuSbstPTst(const   Sl_ParamSetType ParamSetIndex,
                                 const   uint8 TstSeed,
                                 uint32* const TstSignature);


#endif /* CDD_SAFETLIB_TEST_H_ */
