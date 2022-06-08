/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \CDD\CddLvPower$
* $Class_____: C$
* $Name______: LvPower_Cfg.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: LQ$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
   This module describes the process of establishing a low voltage power supply

**----------------------------------------------------------------------------**
** HISTORY:
   V1.0.0:   The initial release

*******************************************************************************/
#ifndef IOSIGDIO_CFG_H_
#define IOSIGDIO_CFG_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include	"Dio.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define  DRV_POWER_MODE					1U                              /*MCU control CPLD Drive power mode;  0 express IO control mode; 1 express PWM control mode*/
#define  DRV_POWER_PERIOD_TICK			1333U 							/*MCU control CPLD output drive power supply PWM signal,75kHz frequency PWM signal*/
#define  DRV_POWER_RATE_OF_RISE_TICK	67U 							/*at rate of 5%/ms, the duty cycle is increased to 47%.*/
#define  DRV_POWER_DUTY_TICK_MAX		627U 							/*MCU control CPLD output drive power supply PWM signal,max duty is 47% */

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
/************************************************INPUT***************************************/

#define DI_KL15							DioConf_DioChannel_DI_KL15_P21_5			/*KL15 signal detection*/
#define DI_WAKE							DioConf_DioChannel_DI_WAKE_P22_8
#define DI_MOTOROPEN 					DioConf_DioChannel_DI_MOTOROPEN_P01_3
#define DI_EPPOC						DioConf_DioChannel_DI_EPPOC_P00_3
#define DI_CPLD_SPI_COM_ERROR_FLG 		DioConf_DioChannel_CPLD_SPI_COM_ERROR_FLG
#define	DI_1EDI_RDY_L					DioConf_DioChannel_NRST_RDY_L_10_4
#define	DI_1EDI_RDY_H					DioConf_DioChannel_IGBT_NRST_RDY_H_11_1		/*3 high bridge ready ok signal*/
#define	DI_1EDI_NFLTA_H					DioConf_DioChannel_IGBT_NFLTA_H_11_4
#define	DI_PCBA_HARDWARE_RELEASE1		DioConf_DioChannel_HardVersion1_11_13		/*HW Version*/
#define	DI_PCBA_HARDWARE_RELEASE2		DioConf_DioChannel_HardVersion1_11_14
#define	DI_PCBA_HARDWARE_RELEASE3		DioConf_DioChannel_HardVersion1_11_15
#define	DI_1EDI_NFLTB_H					DioConf_DioChannel_DI_NFLTHB_P12_1
#define	DI_1EDI_NFLTA_L					DioConf_DioChannel_DI_NFLTLA_P13_3
#define	DI_1EDI_NFLTB_L					DioConf_DioChannel_DI_NFLTLB_P14_8
#define	DI_SBCSS1						DioConf_DioChannel_DI_SBCSS1_P32_4
#define	DI_UDCOV						DioConf_DioChannel_DI_UDCOV_22_11				/*DC Link Over Voltage detection*/
#define	DI_IPHAOC						DioConf_DioChannel_DI_IPHAOC_P21_0				/*Phase Over Current signal,reserve*/
#define	DI_CRASH						DioConf_DioChannel_DI_Crash_23_2				/*Crash signal input£¬reserve*/
#define	DI_CPLD_RES1					DioConf_DioChannel_DO_CPLDRES1_P21_1			/*CPLD reserve*/

#define	DI_CPLD_RES3					DioConf_DioChannel_DI_CLKERR_P21_3
#define	DI_TJA1043_ERR					DioConf_DioChannel_DI_CAN0ERR_P23_0				/*CAN Drive error Signal */
#define	DI_EPP_PPARK					DioConf_DioChannel_DI_PARKP_P23_1				/*Epark P gear detection*/
#define DI_OPENPROTECT					DioConf_DioChannel_DI_OPENPROTECT_P21_4			/*MCU open detection£¬open is 0V£¬Close is 3.2V*/


/****************************************OUTPUT********************************************************/
/*Output*/
#define	DO_ENTemp1				DioConf_DioChannel_DO_ENTemp1_P01_5
#define	DO_ENTemp2				DioConf_DioChannel_DO_ENTemp2_P01_6
#define	DO_EN_EFUSE				DioConf_DioChannel_DO_ENEFUSE_P02_11
#define DO_ASC_RES1 			DioConf_DioChannel_DO_ASC_P02_10
#define DO_EPP_INH				DioConf_DioChannel_DO_ENEPPEFUSE_P22_4
#define DO_CPLDCLR_P10_0 		DioConf_DioChannel_DO_CPLDCLR_P10_0
#define DO_DFW_ENABLE 			DioConf_DioChannel_DO_18VPWMLEN_P10_2
#define DO_18VPWMHEN 			DioConf_DioChannel_DO_18VPWMHEN_P21_1
#define DO_NRSTHS   			DioConf_DioChannel_DO_NRSTHS_P11_7
#define	DO_1EDI_NRST_L			DioConf_DioChannel_DO_NRSTLS_P11_12
#define	DO_1EDI_EN_H			DioConf_DioChannel_DO_CTR_ENHS_DR_P11_5
#define	DO_1EDI_EN_L			DioConf_DioChannel_DO_CTR_ENLS_DR_P13_2
#define	DO_EN_BOOTST			DioConf_DioChannel_DO_ENBOOST_P14_7				/**/
#define DO_SBCWDI_P14_9			DioConf_DioChannel_DO_SBCWDI_P14_9
#define	DO_TJA1043_NSTB			DioConf_DioChannel_DO_STBCAN_P23_5				/*CAN Drive Control Signal*/
#define	DO_TJA1043_EN			DioConf_DioChannel_DO_CAN0EN_P22_7
#define DO_RSLVCEXCN0 			DioConf_DioChannel_DO_RSLVCEXCN_P32_5
#define DO_RSLVCEXCN1 			DioConf_DioChannel_DO_RSLVCEXC_P32_7
#define	DO_FLNAKS				DioConf_DioChannel_DO_FLNAKS_P00_10
#define DO_ENEPARK_P00_0		DioConf_DioChannel_DO_ENEPARK_P00_0
//#define	DO_CPLD_RES2			DioConf_DioChannel_DO_CPLDRES2_P21_2	DioConf_DioChannel_DI_CPLDRES2_P21_2		/*IN test software (Define EOL test),The state of P21.2 is associated with the state controlling the opening of the low voltage tube*/
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/

/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

#endif /* IOSIGDIO_CFG_H_ */


/*******************************************************************************

*******************************************************************************/
