/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \CDD\CddRdc$
* $Class_____: C$
* $Name______: Rdc_Drv.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: LQ$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
	Transformer software decoding

**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   The initial release


*******************************************************************************/
#ifndef RDCDRV_H_
#define RDCDRV_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Dsadc.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
typedef struct {
	float32 ArctanAgRtr_f32;
	float32 nWoFlt_f32;
} RdcOutIFType;

/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/
#pragma section ".rodata.Calib_32"

extern const volatile uint16 CAL_RDC_IsrTimeCmpsa_u16 ;
extern const volatile float32 CAL_RdcRslExcFaultMin_f32 ;
extern const volatile float32 CAL_RdcRslExcFaultMax_f32 ;
extern const volatile uint8 CAL_RdcRslExcFaultDebounce_u8 ;
extern const volatile sint32 CAL_RDC_RslRefMax_s32 ;
extern const volatile sint32 CAL_RDC_RslRefMin_s32 ;
extern const volatile sint16 CAL_RDC_RslDosFaultValMin_s16 ;
extern const volatile sint16 CAL_RDC_RslDosFaultValMax_s16 ;
extern const volatile sint16 CAL_RDC_RslDosOffMin_s16 ;
extern const volatile sint16 CAL_RDC_RslDosOffMax_s16 ;

#pragma section

extern float32 VAR_Rdc_tisamp_f32;
extern sint16 VAR_Rdc_Sin_s16;
extern sint16 VAR_Rdc_Cos_s16;
extern uint16 VAR_RDC_flg_u16;
/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

/*******************************************************************************
** Function Name	: Rdc_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Rdc_Init
*******************************************************************************/
extern	void Rdc_Init(void);


/*******************************************************************************
** Function Name	: GpDsadc_Res_Isr
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: DSADC ISR
*******************************************************************************/
extern void Rdc_Res_Isr(void);

/*******************************************************************************
** Function Name	: CddRDC_FaultHand
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: 2ms per
** Description	  	: RDC Module Fault Hand
*******************************************************************************/
extern	void Rdc_FaultHandleMainFunction(void);

/*******************************************************************************
** Function Name	: Rdc_AngleHandle
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	:
*******************************************************************************/
extern	void Rdc_AngleHandle(const float32* cofFrqPwm_f32, RdcOutIFType * out);/*100us*/

#endif /* RDCDRV_H_ */

