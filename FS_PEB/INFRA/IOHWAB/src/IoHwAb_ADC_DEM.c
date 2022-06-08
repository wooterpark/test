/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \ArCfg\IOHWAB$
* $Class_____: C$
* $Name______: IOHWAB_ADC_DEM.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: xuwenliao$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: YES
**----------------------------------------------------------------------------**
** DESCRIPTION:

**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:


*******************************************************************************/

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "IoHwAb_Adc.h"
#include "PhC_Drv.h"
#include "Dem.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :IoHwAb_ADC_GetPhyVoltage) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :IoHwAb_ADC_GetPhyVoltage) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :IoHwAb_ADC_GetPhyVoltage) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/

#define IOHWAB_CPLD_1_8V_Min               (1.73f)
#define IOHWAB_CPLD_1_8V_Max               (1.87f)
#define IOHWAB_CPLD_3_3V_Min               (3.1f)
#define IOHWAB_CPLD_3_3V_Max               (3.448f)
#define IOHWAB_MCU_1_3V_Min                (1.2f)
#define IOHWAB_MCU_1_3V_Max                (1.33f)
#define IOHWAB_MCU_3_3V_Min                (3.0f)
#define IOHWAB_MCU_3_3V_Max                (3.6f)
#define IOHWAB_MCU_5V_Min                  (4.6f)
#define IOHWAB_MCU_5V_Max                  (5.2f)
#define IOHWAB_IGBT_18V_Min                (16.0f)
#define IOHWAB_IGBT_18V_Max                (20.0f)
#define IOHWAB_12V_Narr_Gain               (0.00244f)                  /*narr min is 9V,switch AD value is 3686*/
#define IOHWAB_12V_Narr_Min                (9.0f)                  /*narr max is 10V,switch AD value is 4096*/
#define IOHWAB_12V_Wide_Max                (16.0f)
#define IOHWAB_5V_Min                      (4.8f)
#define IOHWAB_5V_Max                      (5.2f)

#pragma section ".rodata.Calib_32"
const volatile float CAL_IOHWAB_AN29_IUVW_P_REF_MAX_f32=4.45f;   /*760A-600u-4.4V;750A-625u-4.375V*/
const volatile float CAL_IOHWAB_AN29_IUVW_P_REF_MIN_f32=4.35f;
const volatile float CAL_IOHWAB_AN30_IUVW_N_REF_MAX_f32=0.65f;   /*760A-600u-0.6V;750A-625u-4.375V*/
const volatile float CAL_IOHWAB_AN30_IUVW_N_REF_MIN_f32=0.55f;
#pragma section
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
float32 VAR_IoHwAb_Adc_Phy_12V_Narr_f32;
float32 VAR_IoHwAb_Adc_Phy_12V_Wide_f32;
float32 VAR_IoHwAb_Adc_Phy_5V_Qt1_f32;
float32 VAR_IoHwAb_Adc_Phy_CPLD_3_3V_f32;
float32 VAR_IoHwAb_Adc_Phy_5V_Qt2_f32;
float32 VAR_IoHwAb_Adc_Phy_CPLD_1_8V_f32;
float32 VAR_IoHwAb_Adc_Phy_5V_Qco_f32;
float32 VAR_IoHwAb_Adc_Phy_18V_HS_f32;
float32 VAR_IoHwAb_Adc_Phy_18V_LS_f32;
float32 VAR_IoHwAb_Adc_Phy_1V3_MCU_f32;
float32 VAR_IoHwAb_Adc_Phy_3V3_MCU_f32;
float32 VAR_IoHwAb_Adc_Phy_5V_QUC_f32;
float32 VAR_IoHwAb_Adc_Phy_IUVW_P_REF_f32;
float32 VAR_IoHwAb_Adc_Phy_IUVW_N_REF_f32;
float32 VAR_IoHwAb_Adc_Phy_5V_LEM_f32;
float32 VAR_IoHwAb_Adc_Phy_KL30_f32;
/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: IOHWAB_ADC_DEM
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Fault diagnosis of ADC sampling in IoHwAb
*******************************************************************************/
FUNC (void , IoHwAbW_CODE) IoHwAb_ADC_DEM(void)
{
     if( LV_PowerFinish() == PWR_LV_POWERSETUP_OK )
     {
       if(((Adc_RawData[IOHWAB_AN5_STTRTEMP1_CHANNEL]<IoHwAb_ADC_Min)||(Adc_RawData[IOHWAB_AN5_STTRTEMP1_CHANNEL]>IoHwAb_ADC_Max))&&((Adc_RawData[IOHWAB_AN13_STTRTEMP2_CHANNEL]<IoHwAb_ADC_Min)||(Adc_RawData[IOHWAB_AN13_STTRTEMP2_CHANNEL]>IoHwAb_ADC_Max)))     /*Adc_RawData[3]is AN5_STTRTEMP1_G0_5;Adc_RawData[8] is AN13_STTRTEMP2_G1_5*/
         {
	        (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail,DEM_EVENT_STATUS_PREFAILED);
         }
       if((Adc_RawData[IOHWAB_AN5_STTRTEMP1_CHANNEL]<IoHwAb_ADC_Min)||(Adc_RawData[IOHWAB_AN5_STTRTEMP1_CHANNEL]>IoHwAb_ADC_Max))
         {
	        (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail,DEM_EVENT_STATUS_PREFAILED);
         }
       if((Adc_RawData[IOHWAB_AN13_STTRTEMP2_CHANNEL]<IoHwAb_ADC_Min)||(Adc_RawData[IOHWAB_AN13_STTRTEMP2_CHANNEL]>IoHwAb_ADC_Max))
         {
	        (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail,DEM_EVENT_STATUS_PREFAILED);
         }
       if((Adc_RawData[IOHWAB_AN34_WATERTEMP_CHANNEL]<IoHwAb_ADC_Min)||(Adc_RawData[IOHWAB_AN34_WATERTEMP_CHANNEL]>IoHwAb_ADC_Max))                                                                /*Adc_RawData[25] is AN34_WATERTEMP_G4_2*/
         {
	        (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_TCoolantSampFail,DEM_EVENT_STATUS_PREFAILED);
         }

       VAR_IoHwAb_Adc_Phy_12V_Narr_f32 = (float32)VAR_Adc_RES_Buffer_CUR_MCU_u16[2U]*IOHWAB_12V_Narr_Gain;                        /*AN7_UBRNARR_G0_7*/
       if(VAR_IoHwAb_Adc_Phy_12V_Narr_f32<IOHWAB_12V_Narr_Min)
         {
	        (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_12VNarrSampErr,DEM_EVENT_STATUS_PREFAILED);
         }

       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN3_12V_Wide_CHANNEL,&VAR_IoHwAb_Adc_Phy_12V_Wide_f32);                               /*AN3_UBRWIDE_G0_3*/
       if(VAR_IoHwAb_Adc_Phy_12V_Wide_f32>IOHWAB_12V_Wide_Max)
         {
	        (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_12VWideSampErr,DEM_EVENT_STATUS_PREFAILED);
         }

       if((VAR_IoHwAb_Adc_Phy_12V_Narr_f32<IOHWAB_12V_Narr_Min)||(VAR_IoHwAb_Adc_Phy_12V_Wide_f32>IOHWAB_12V_Wide_Max))
       {
	        (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_12VSampErr,DEM_EVENT_STATUS_PREFAILED);
       }

       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN6_5V_Qt1_CHANNEL,&VAR_IoHwAb_Adc_Phy_5V_Qt1_f32);                                    /*AN6_5VQT1_G0_6*/                                              /*AN6_5VQT1_G0_6*/
       if((VAR_IoHwAb_Adc_Phy_5V_Qt1_f32<IOHWAB_5V_Min)||(VAR_IoHwAb_Adc_Phy_5V_Qt1_f32>IOHWAB_5V_Max))
         {
	        (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_5VQt1SampFail,DEM_EVENT_STATUS_PREFAILED);
         }

       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN11_CPLD_3_3V_CHANNEL,&VAR_IoHwAb_Adc_Phy_CPLD_3_3V_f32);                               /*AN11_3V3CPLD_G1_3*/
       if((VAR_IoHwAb_Adc_Phy_CPLD_3_3V_f32<IOHWAB_CPLD_3_3V_Min)||(VAR_IoHwAb_Adc_Phy_CPLD_3_3V_f32>IOHWAB_CPLD_3_3V_Max))
         {
 	       (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail,DEM_EVENT_STATUS_PREFAILED);
         }

       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN12_5V_Qt2_CHANNEL,&VAR_IoHwAb_Adc_Phy_5V_Qt2_f32);                                  /*AN12_5VQT2_G1_4*/
       if((VAR_IoHwAb_Adc_Phy_5V_Qt2_f32<IOHWAB_5V_Min)||(VAR_IoHwAb_Adc_Phy_5V_Qt2_f32>IOHWAB_5V_Max))
         {
  	       (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_5VQt2SampFail,DEM_EVENT_STATUS_PREFAILED);
         }

       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN19_CPLD_1_8V_CHANNEL,&VAR_IoHwAb_Adc_Phy_CPLD_1_8V_f32);                                 /*AN19_1V8CPLD_G2_3*/
       if((VAR_IoHwAb_Adc_Phy_CPLD_1_8V_f32<IOHWAB_CPLD_1_8V_Min)||(VAR_IoHwAb_Adc_Phy_CPLD_1_8V_f32>IOHWAB_CPLD_1_8V_Max))
         {
   	       (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail,DEM_EVENT_STATUS_PREFAILED);
         }

       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN22_5V_Qco_CHANNEL,&VAR_IoHwAb_Adc_Phy_5V_Qco_f32);                                   /*AN22_5VQCO_G2_6*/
       if((VAR_IoHwAb_Adc_Phy_5V_Qco_f32<IOHWAB_5V_Min)||(VAR_IoHwAb_Adc_Phy_5V_Qco_f32>IOHWAB_5V_Max))
         {
           (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_5VQcoSampFail,DEM_EVENT_STATUS_PREFAILED);
         }

       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN27_IGBT_18V_HS_CHANNEL,&VAR_IoHwAb_Adc_Phy_18V_HS_f32);                         /*AN27_18VHS_G3_3*/
       if((VAR_IoHwAb_Adc_Phy_18V_HS_f32<IOHWAB_IGBT_18V_Min)||(VAR_IoHwAb_Adc_Phy_18V_HS_f32>IOHWAB_IGBT_18V_Max))
         {
           (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail,DEM_EVENT_STATUS_PREFAILED);
         }

       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN43_IGBT_18V_LS_CHANNEL,&VAR_IoHwAb_Adc_Phy_18V_LS_f32);                        /*AN43_18VLS_G5_3*/
       if((VAR_IoHwAb_Adc_Phy_18V_LS_f32<IOHWAB_IGBT_18V_Min)||(VAR_IoHwAb_Adc_Phy_18V_LS_f32>IOHWAB_IGBT_18V_Max))
         {
           (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail,DEM_EVENT_STATUS_PREFAILED);
         }
       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN35_1V3_CHANNEL,&VAR_IoHwAb_Adc_Phy_1V3_MCU_f32);
       if((VAR_IoHwAb_Adc_Phy_1V3_MCU_f32<IOHWAB_MCU_1_3V_Min)||(VAR_IoHwAb_Adc_Phy_1V3_MCU_f32>IOHWAB_MCU_1_3V_Max))
       {
    	   (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail,DEM_EVENT_STATUS_PREFAILED);
       }
       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN14_3V3_CHANNEL,&VAR_IoHwAb_Adc_Phy_3V3_MCU_f32);
       if((VAR_IoHwAb_Adc_Phy_3V3_MCU_f32<IOHWAB_MCU_3_3V_Min)||(VAR_IoHwAb_Adc_Phy_3V3_MCU_f32>IOHWAB_MCU_3_3V_Max))
       {
          (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail,DEM_EVENT_STATUS_PREFAILED);
       }
       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN23_5VQUC_CHANNEL,&VAR_IoHwAb_Adc_Phy_5V_QUC_f32);
       if((VAR_IoHwAb_Adc_Phy_5V_QUC_f32<IOHWAB_MCU_5V_Min)||(VAR_IoHwAb_Adc_Phy_5V_QUC_f32>IOHWAB_MCU_5V_Max))
       {
          (void)Dem_SetEventStatus(DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail,DEM_EVENT_STATUS_PREFAILED);
       }
       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN29_IUVW_P_REF_CHANNEL,&VAR_IoHwAb_Adc_Phy_IUVW_P_REF_f32);
       if((VAR_IoHwAb_Adc_Phy_IUVW_P_REF_f32<CAL_IOHWAB_AN29_IUVW_P_REF_MIN_f32)||(VAR_IoHwAb_Adc_Phy_IUVW_P_REF_f32>CAL_IOHWAB_AN29_IUVW_P_REF_MAX_f32))
       {
       }
       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN30_IUVW_N_REF_CHANNEL,&VAR_IoHwAb_Adc_Phy_IUVW_N_REF_f32);
       if((VAR_IoHwAb_Adc_Phy_IUVW_N_REF_f32<CAL_IOHWAB_AN30_IUVW_N_REF_MIN_f32)||(VAR_IoHwAb_Adc_Phy_IUVW_N_REF_f32>CAL_IOHWAB_AN30_IUVW_N_REF_MAX_f32))
       {
       }
       IoHwAb_ADC_GetPhyVoltage(IOHWAB_AN24_5V_LEM_CHANNEL,&VAR_IoHwAb_Adc_Phy_5V_LEM_f32);
       if((VAR_IoHwAb_Adc_Phy_5V_LEM_f32<IOHWAB_MCU_5V_Min)||(VAR_IoHwAb_Adc_Phy_5V_LEM_f32>IOHWAB_MCU_5V_Max))
       {
       }
     }
}
