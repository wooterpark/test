/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: Adc_Drv.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: XM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
				ADC current and Udc Sample.
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   initial version

*******************************************************************************/
#ifndef PHC_DRV_H_
#define PHC_DRV_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "PhC_DrvCfg.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define PHASECURR_ADC_LOWER_LIMITING_VALUE    25U
#define PHASECURR_ADC_HIGH_LIMITING_VALUE     4070U
#define PhC_Bilateral_Diag(value,up,low,count1,count2,output)  \
	    if ((count1)<4)                                        \
         {                                                     \
            if(((value)>(up))||((value)<(low)))                \
			{                                                  \
             (count2)++;                                       \
            }                                                  \
            if((count2)>=3)                                    \
			{                                                  \
			  (output);                                        \
			}                                                  \
			(count1)++;                                        \
         }
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
typedef struct {
	uint16 iUNoOff;
	uint16 iVNoOff;
	uint16 iWNoOff;
	float32 uDcLnkLowMcu;
} PhCOutIFType;
typedef struct {
	uint8 ADC_UPhaseBISTcnt;
	uint8 ADC_UPhaseBISTerrcnt;
	uint8 ADC_VPhaseBISTcnt;
	uint8 ADC_VPhaseBISTerrcnt;
	uint8 ADC_WPhaseBISTcnt;
	uint8 ADC_WPhaseBISTerrcnt;
}PhCDiagType;
/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/
/*ADC Result Buffers */

extern	Adc_ValueGroupType VAR_Adc_RES_Buffer_CUR_MCU_u16[9U];



/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

/*******************************************************************************
** Function Name	: PhC_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: GP ADC initialize
*******************************************************************************/
extern	void PhC_Init(void);

#if(ADC_HW_TRIGGER_USE_DMA == 0U) /*not use DMA*/
/*******************************************************************************
** Function Name	: PhC_GetResult_MCUHwAdc
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: PWM interrupt/ADC finish the Notification function call
** Description	  	: GP ADC get three-phase current ADC data
*******************************************************************************/
extern	void PhC_GetResult_MCUHwAdc(PhCOutIFType *out);
#endif

/*******************************************************************************
** Function Name	: CddADC_FaultHand
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: CDD ADC module fault diagnosis 2ms per;
** Description	  	: CDD ADC Fault hand
*******************************************************************************/
extern	void PhC_FaultHand(void);


#endif /* PHC_H_ */

/*******************************************************************************

*******************************************************************************/

