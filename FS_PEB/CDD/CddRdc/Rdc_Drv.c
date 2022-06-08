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

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Rdc_Drv.h"
#include "RDC.h"
#include "IfxGtm_reg.h"
#include "Dem.h"
#include "PhC_Drv.h"
#include "IoHwAb_ADC.h"
#include "LvPower_Drv.h"
#include "IfxVadc_reg.h"
#include "Dio.h"
#include "L2Sample_FS.h"   /*XWL202111030 test*/
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define RDC_RSLV_GMA_CNT  			1000u					/*Take the extremum filter parameter*/
															/*IOHWAB ADC Buf Number*/
#define RDC_RSLV_EXC_AN44CHANNEL    26U
#define RDC_RSLV_EXCN_AN26CHANNEL   15U

#define RDC_SPEED_DOSERR_FWD_MIN 		250.0F
#define RDC_SPEED_DOSERR_REV_MIN 	   -250.0F
#define RDC_SPEED_DOSERR_CNT            120U				/*250rpm/60s,  One circle requires 240ms,2ms diagnostic task, and 120 counts are needed to complete a circle of data recording*/

#define GET_MAX_AMPLITUDE(res ,resPosBack,resNegBack)    		 \
		{														 \
			if( (res)>0 )											 \
			{										 			 \
				if( (res) > (resPosBack) ) 				 			 \
				{ 												 \
					(resPosBack) = (res); 							 \
				} 												 \
			} 													 \
			else/* negative amplitudeMAX*/						 \
			{ 													 \
				if( (res) < (resNegBack) ) 							 \
				{ 												 \
					(resNegBack) = (res); 							 \
				} 												 \
			} 										 			 \
		}                                                        \


#define RDC_RSL_FILTER_DIAG(cnt,limit,demEventParErr) 							\
		{																		\
			(cnt)++;                                          					\
			if( (cnt) > (limit) )                                   			 		\
			{                                               					\
				(cnt) = (limit);                                   					\
				(void)Dem_SetEventStatus(demEventParErr,DEM_EVENT_STATUS_FAILED);  	\
			}                                              					 	\
		}

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
typedef struct
{
	volatile sint16 si16_Dsadc_Res0_PosMax ;			/*sin  positive amplitudeMAX*/
	volatile sint16 si16_Dsadc_Res0_NegMax ;			/*sin  negative amplitudeMAX*/
	volatile sint16 si16_Dsadc_Res1_PosMax ;			/*Cos  positive amplitudeMAX*/
	volatile sint16 si16_Dsadc_Res1_NegMax ;			/*Cos  negative amplitudeMAX*/
}st_RdcRslMaxAmplitudeType;

typedef struct
{
	uint32 ui32_Gp_Dsadc_GMA_Cont;
	sint16 si16_Dsadc_Res0_PosBack ;		/*sin  Back positive amplitude */
	sint16 si16_Dsadc_Res0_NegBack ;		/*sin  Back negative amplitude*/
	sint16 si16_Dsadc_Res1_PosBack ;		/*Cos  Back positive amplitude*/
	sint16 si16_Dsadc_Res1_NegBack ;		/*Cos  Back negative amplitude*/
}st_RdcRslMaxAmplitudeBackType;

typedef struct
{
	volatile sint16  Dsadc_Sin_Res_s16 ;
	volatile sint16  Dsadc_Cos_Res_s16 ;
	volatile sint32  RslRef_s32;
	uint32  Rdc_Res_DebugCnt_u32;
	float32 OutputFreq_f32 ;
    float32 GroupDelay_f32    ;
	volatile uint32 ICU0_CH6_TimeStampe_u32 ;
	volatile uint32 ICU0_CH7_TimeStampe_u32 ;
	volatile float32 Rdc_TimeStampe_f32 	 ;
    uint32 Dsadc_MaxTicks_u32       ;

	st_RdcRslMaxAmplitudeType     RdcRslMaxAmplitude_st;
	st_RdcRslMaxAmplitudeBackType RdcRslMaxAmplitudeBack_st;

}st_DsadcModuleType;

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/
static st_DsadcModuleType DsadcModule_st =
{
	0,
	0,
	0,
	0,
	0.0f,
	0.0f,
	0,
	0,
	0.0f,
	0,
	{
		1800,
		-1800,
		1800,
		-1800,
	},
	{
		0,
		0,
		0,
		0,
		0,
	}

};

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
  /*JEE_MISRA_Dir_1_01 It's allowed .*/
#pragma section ".rodata.Calib_32"

const volatile uint16 CAL_RDC_IsrTimeCmpsa_u16 = 600u;
const volatile float32 CAL_RdcRslExcFaultMin_f32 = 1.0f;
const volatile float32 CAL_RdcRslExcFaultMax_f32 = 3.0f;
const volatile uint8 CAL_RdcRslExcFaultDebounce_u8 = 10u;
const volatile sint32 CAL_RDC_RslRefMax_s32 = 3400000;
const volatile sint32 CAL_RDC_RslRefMin_s32 = 2600000;
const volatile sint16 CAL_RDC_RslDosFaultValMin_s16 = -2000;
const volatile sint16 CAL_RDC_RslDosFaultValMax_s16 = 2000;
const volatile sint16 CAL_RDC_RslDosOffMin_s16 = -100;
const volatile sint16 CAL_RDC_RslDosOffMax_s16 = 100;
  /*JEE_MISRA_Dir_1_01 It's allowed .*/
#pragma section


sint16  VAR_Rdc_Sin_s16      = 0;
sint16  VAR_Rdc_Cos_s16      = 0;
uint16  VAR_RDC_flg_u16      = 0U;
float32 VAR_Rdc_tisamp_f32   = 0.0f;

/*test code*/
sint16  VAR_DSADC_Rdc_Sin_s16[64];
sint16  VAR_DSADC_Rdc_Cos_s16[64];

/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/
static void Rdc_Get_MAX_Amplitude_Per102ms( sint16 res0_arg,sint16 res1_arg );

static void Rdc_FaultHandle( void );

static void Rdc_TimestampCompensation( void );
/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: Rdc_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Rdc_Init
*******************************************************************************/
void Rdc_Init( void )
{

	Dsadc_StartChannel( Dsadc_Channel4_RunCt | Dsadc_Channel4_Mod_RunCt);
	Dsadc_StartChannel( Dsadc_Channel5_RunCt | Dsadc_Channel5_Mod_RunCt);
	Dsadc_SetSdposVal( Dsadc_ChannelId_4, 3 );
	Dsadc_SetSdnegVal( Dsadc_ChannelId_4,11 );
	Dsadc_SetSdposVal( Dsadc_ChannelId_5, 3 );
	Dsadc_SetSdnegVal( Dsadc_ChannelId_5,11 );

	DsadcModule_st.GroupDelay_f32 = Dsadc_CalGroupDelay( Dsadc_ChannelId_4 );
	DsadcModule_st.GroupDelay_f32 = DsadcModule_st.GroupDelay_f32 * 1000000.0f;			/*US*/
	VAR_CDD_Rslv_TimeGp_f32   = DsadcModule_st.GroupDelay_f32;

	DsadcModule_st.OutputFreq_f32 = Dsadc_GetChOutputFreq(Dsadc_ChannelId_4);
 /*JEE_MISRA_RULE_10_08 It's allowed .*/
	DsadcModule_st.Dsadc_MaxTicks_u32 	= (uint32)( (1.0f/DsadcModule_st.OutputFreq_f32)*100000000.0f );

}

/*******************************************************************************
** Function Name	: Rdc_Get_MAX_Amplitude_Per102ms
** Parameter[in] 	: res0_arg,res1_arg
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: DSADC Get_MAX_Amplitude
*******************************************************************************/
static void Rdc_Get_MAX_Amplitude_Per102ms( sint16 res0_arg,sint16 res1_arg )
{
	st_RdcRslMaxAmplitudeType     *rslMaxAmplitude_pst     = &DsadcModule_st.RdcRslMaxAmplitude_st;
	st_RdcRslMaxAmplitudeBackType *rslMaxAmplitudeBack_pst = &DsadcModule_st.RdcRslMaxAmplitudeBack_st;

	if( rslMaxAmplitudeBack_pst->ui32_Gp_Dsadc_GMA_Cont < RDC_RSLV_GMA_CNT )
	{
		/********************************sin*********************************************/
		GET_MAX_AMPLITUDE(res0_arg,rslMaxAmplitudeBack_pst->si16_Dsadc_Res0_PosBack,rslMaxAmplitudeBack_pst->si16_Dsadc_Res0_NegBack)

		/********************************Cos ******************************************/
		GET_MAX_AMPLITUDE(res1_arg,rslMaxAmplitudeBack_pst->si16_Dsadc_Res1_PosBack,rslMaxAmplitudeBack_pst->si16_Dsadc_Res1_NegBack)

		rslMaxAmplitudeBack_pst->ui32_Gp_Dsadc_GMA_Cont ++;
	}
	else/*MAX*/
	{
		rslMaxAmplitude_pst->si16_Dsadc_Res0_PosMax = rslMaxAmplitudeBack_pst->si16_Dsadc_Res0_PosBack;
		rslMaxAmplitude_pst->si16_Dsadc_Res0_NegMax = rslMaxAmplitudeBack_pst->si16_Dsadc_Res0_NegBack;
		rslMaxAmplitude_pst->si16_Dsadc_Res1_PosMax = rslMaxAmplitudeBack_pst->si16_Dsadc_Res1_PosBack;
		rslMaxAmplitude_pst->si16_Dsadc_Res1_NegMax = rslMaxAmplitudeBack_pst->si16_Dsadc_Res1_NegBack;

		rslMaxAmplitudeBack_pst->si16_Dsadc_Res0_PosBack = 0;
		rslMaxAmplitudeBack_pst->si16_Dsadc_Res0_NegBack = 0;
		rslMaxAmplitudeBack_pst->si16_Dsadc_Res1_PosBack = 0;
		rslMaxAmplitudeBack_pst->si16_Dsadc_Res1_NegBack = 0;

		rslMaxAmplitudeBack_pst->ui32_Gp_Dsadc_GMA_Cont = 0;
	}
}

/*******************************************************************************
** Function Name	: Rdc_TimestampCompensation
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: CddRdc  Timestamp  Compensation
*******************************************************************************/
static void Rdc_TimestampCompensation( void )
{
	st_DsadcModuleType *dsadcModule_pst  = &DsadcModule_st;
	uint32 cH7_CH6_Dif_u32;

	static sint16 sintemp = 0;
	static sint16 costemp = 0;
	static sint16 sinb = 0;
	static sint16 sinn = 0;
	static sint16 cosb = 0;
	static sint16 cosn = 0;
	static uint32 ch6n = 0;
	static uint32 ch6b = 0;
	static uint32 ch6temp = 0;
	static uint8 flg1 = 0;
	static uint8 flg2 = 0;

	sinn = dsadcModule_pst->Dsadc_Sin_Res_s16;
	cosn = dsadcModule_pst->Dsadc_Cos_Res_s16;
	ch6n = dsadcModule_pst->ICU0_CH6_TimeStampe_u32;

	ch6b = ch6temp;
    sinb = sintemp;
    cosb = costemp;
    sintemp = sinn;
    costemp = cosn;
    ch6temp = ch6n;
    VAR_RDC_flg_u16 = 0;
 /*JEE_MISRA_RULE_11_04 It's allowed .*/
    dsadcModule_pst->ICU0_CH7_TimeStampe_u32 = GTM_TIM0_CH7_GPR0.B.GPR0 + CAL_RDC_IsrTimeCmpsa_u16;
    if( (sinn == sinb)&&(cosn == cosb) )
    {
    	flg1 = 1;
    }
    else
    {
    	flg1 = 0;
    }
    if( ( (dsadcModule_pst->ICU0_CH6_TimeStampe_u32 - dsadcModule_pst->ICU0_CH7_TimeStampe_u32) <102400U )||( ( (float)dsadcModule_pst->ICU0_CH7_TimeStampe_u32  -  (float)dsadcModule_pst->ICU0_CH6_TimeStampe_u32 ) >102400.0F) )
    {
    	flg2 = 1;
    }
    else
    {
    	flg2 = 0;
    }
	if( ( (float)dsadcModule_pst->ICU0_CH6_TimeStampe_u32  -  (float)dsadcModule_pst->ICU0_CH7_TimeStampe_u32 )  > 102400.0F )
	{
		cH7_CH6_Dif_u32 = dsadcModule_pst->ICU0_CH7_TimeStampe_u32 + 16777216U - dsadcModule_pst->ICU0_CH6_TimeStampe_u32;
		VAR_Rdc_Sin_s16   = dsadcModule_pst->Dsadc_Sin_Res_s16;
		VAR_Rdc_Cos_s16   = dsadcModule_pst->Dsadc_Cos_Res_s16;
	}
	else if( (flg1 == 1U )&&( flg2 == 1U) )
	{
		cH7_CH6_Dif_u32 = 10240;
		VAR_Rdc_Sin_s16   = dsadcModule_pst->Dsadc_Sin_Res_s16;
		VAR_Rdc_Cos_s16   = dsadcModule_pst->Dsadc_Cos_Res_s16;
	}
	else if( (flg1 == 0U)&&(flg2 == 1U) )
	{
		VAR_RDC_flg_u16 = 1;
		VAR_Rdc_Sin_s16 = sinb;
		VAR_Rdc_Cos_s16 = cosb;
		if( ( (float)ch6b  -  (float)dsadcModule_pst->ICU0_CH7_TimeStampe_u32 )  > 102400.0F )
		{
			cH7_CH6_Dif_u32 = dsadcModule_pst->ICU0_CH7_TimeStampe_u32 + 16777216U - ch6b;
		}
		else
		{
			cH7_CH6_Dif_u32 = dsadcModule_pst->ICU0_CH7_TimeStampe_u32 - ch6b;
		}
	}
	else
	{
		cH7_CH6_Dif_u32 = dsadcModule_pst->ICU0_CH7_TimeStampe_u32 - dsadcModule_pst->ICU0_CH6_TimeStampe_u32;
		VAR_Rdc_Sin_s16   = dsadcModule_pst->Dsadc_Sin_Res_s16;
		VAR_Rdc_Cos_s16   = dsadcModule_pst->Dsadc_Cos_Res_s16;

	}

	dsadcModule_pst->Rdc_TimeStampe_f32 = ((float)cH7_CH6_Dif_u32)*0.01f  ; /*   cH7_CH6_Dif_u32/100M*1M Convert to units of time us     */

	VAR_Rdc_tisamp_f32 = dsadcModule_pst->Rdc_TimeStampe_f32;


}


/*******************************************************************************
** Function Name	: CddRDC_FaultHand
** Parameter[in] 	: rdcRslFaultHandle_pst
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: 2ms per
** Description	  	: RDC Module Fault Hand
*******************************************************************************/
static void Rdc_FaultHandle(void)
{
	float32 rslExcP_f32 = 0.0F;
	float32 rslExcN_f32 = 0.0F;
	sint16 sinOff_s16,cosOff_s16;
	static uint8  dosErrMask = 0U;
	static uint8  RdcRslExcFaultDncCnt_u8 = 0U;
	static uint16 RdcRslDosDncCnt_u8 = 0U;
	static uint8   VAR_Rsl_FaultType_u8 = 0U;
    /*JEE_MISRA_RULE_8_13 It's allowed .*/
    st_DsadcModuleType  *faultHandle_pst  = &DsadcModule_st;

	/*AN20_RSLVEXC_G2_4 \AN21_RSLVEXCN_G2_5 \AN28_Sin_G3_4\AN31_SinLO_G3_7 \AN14_Cos_G1_6 \AN23_CosLO_G2_7*/
	IoHwAb_ADC_GetPhyVoltage(RDC_RSLV_EXC_AN44CHANNEL,  &rslExcP_f32 );
	IoHwAb_ADC_GetPhyVoltage(RDC_RSLV_EXCN_AN26CHANNEL, &rslExcN_f32 );

	 if( LV_PowerFinish() == PWR_LV_POWERSETUP_OK )		/*when Power successfully Turn on diagnostic function*/
	 {
		 /*************************************RSL_ExcFaultErr*********************************************/
		 /*JEE_MISRA_RULE_13_05 It's allowed .*/
		 	 if( ( rslExcP_f32 < CAL_RdcRslExcFaultMin_f32 )||( rslExcP_f32 >CAL_RdcRslExcFaultMax_f32 )||  \
					 ( rslExcN_f32 <CAL_RdcRslExcFaultMin_f32 )||(rslExcN_f32 >CAL_RdcRslExcFaultMax_f32 ) )
			{
				RDC_RSL_FILTER_DIAG( RdcRslExcFaultDncCnt_u8,CAL_RdcRslExcFaultDebounce_u8,DemConf_DemEventParameter_RSL_ExcErr );
				if( RdcRslExcFaultDncCnt_u8 >= CAL_RdcRslExcFaultDebounce_u8 )
				{
					IoSigDio_Set( DO_RSLVCEXCN0, STD_LOW );			/*close the rotary transformer power supply enable signal*/
					IoSigDio_Set( DO_RSLVCEXCN1, STD_LOW );			/*close the rotary transformer power supply enable signal*/
					VAR_Rsl_FaultType_u8 = 1U;
				}
			}
			else
			{
				RdcRslExcFaultDncCnt_u8  = 0u;
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_RSL_ExcErr,DEM_EVENT_STATUS_PREPASSED);
			}

	 /*************************************RSL_Sin/CosErr*********************************************/
			/*JEE_MISRA_RULE_13_02 It's allowed .*/
 	 	 if( faultHandle_pst->RslRef_s32 < CAL_RDC_RslRefMin_s32 )					/*Los Err*/
			{
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_RSL_LOSErr,DEM_EVENT_STATUS_PREFAILED);
				VAR_Rsl_FaultType_u8 = 2U;

			}
  	  	  /*JEE_MISRA_RULE_13_02 It's allowed .*/
		    else if( faultHandle_pst->RslRef_s32 > CAL_RDC_RslRefMax_s32 )				/*DOS Err*/
			{
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_RSL_DOSErr,DEM_EVENT_STATUS_PREFAILED);
				VAR_Rsl_FaultType_u8 = 3U;
				dosErrMask &= 0xFEU;
			}
			else
			{
				(void)Dem_SetEventStatus( DemConf_DemEventParameter_RSL_LOSErr,DEM_EVENT_STATUS_PREPASSED );
				dosErrMask |= 0x01U;
			}

			  /*JEE_MISRA_RULE_13_05 It's allowed .*/
			if(     ( faultHandle_pst->RdcRslMaxAmplitude_st.si16_Dsadc_Res0_PosMax < CAL_RDC_RslDosFaultValMax_s16 )    &&  \
					( faultHandle_pst->RdcRslMaxAmplitude_st.si16_Dsadc_Res0_NegMax > CAL_RDC_RslDosFaultValMin_s16 )    &&  \
					( faultHandle_pst->RdcRslMaxAmplitude_st.si16_Dsadc_Res1_PosMax < CAL_RDC_RslDosFaultValMax_s16 ) 	 &&  \
					( faultHandle_pst->RdcRslMaxAmplitude_st.si16_Dsadc_Res1_NegMax > CAL_RDC_RslDosFaultValMin_s16 )    )
			{
				dosErrMask |= 0x02U;

			}
			else
			{
				(void)Dem_SetEventStatus( DemConf_DemEventParameter_RSL_DOSErr,DEM_EVENT_STATUS_PREFAILED );
				VAR_Rsl_FaultType_u8 = 4U;
				dosErrMask &= 0xFDU;
			}
#if 1
			if(  ( VAR_RDC_nWoFlt_f32 > RDC_SPEED_DOSERR_FWD_MIN)||( VAR_RDC_nWoFlt_f32 < RDC_SPEED_DOSERR_REV_MIN )  )/*need to spin it to rotate it*/
			{
				RdcRslDosDncCnt_u8++;
				if( RdcRslDosDncCnt_u8 > RDC_SPEED_DOSERR_CNT )
				{
					RdcRslDosDncCnt_u8 = 0U;
					 /*DOS Err, signal asymmetry*/
					sinOff_s16 = faultHandle_pst->RdcRslMaxAmplitude_st.si16_Dsadc_Res0_PosMax + faultHandle_pst->RdcRslMaxAmplitude_st.si16_Dsadc_Res0_NegMax ;
					cosOff_s16 = faultHandle_pst->RdcRslMaxAmplitude_st.si16_Dsadc_Res1_PosMax + faultHandle_pst->RdcRslMaxAmplitude_st.si16_Dsadc_Res1_NegMax ;
  					/*JEE_MISRA_RULE_13_05 It's allowed .*/					
					if( (sinOff_s16 < CAL_RDC_RslDosOffMax_s16 )&&(sinOff_s16 > CAL_RDC_RslDosOffMin_s16 ) && (cosOff_s16 < CAL_RDC_RslDosOffMax_s16 )&&(cosOff_s16 > CAL_RDC_RslDosOffMin_s16 ) )
					{
						dosErrMask |= 0x04U;
					}
					else
					{
						(void)Dem_SetEventStatus(DemConf_DemEventParameter_RSL_DOSErr,DEM_EVENT_STATUS_PREFAILED);
						VAR_Rsl_FaultType_u8 = 5U;
						dosErrMask &= 0xFBU;
					}
				}
			}
			else
			{
				RdcRslDosDncCnt_u8 = 0U;
			}
#endif
			if( dosErrMask == 0x07U )/*Clear DOS failure without any failure*/
			{
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_RSL_DOSErr,DEM_EVENT_STATUS_PREPASSED );
				dosErrMask = 0U;
			}
			/****************************************LOT Err***************************/
			if( VAR_RDC_flgLotErr_b == 1U )
			{	
				(void)Dem_SetEventStatus( DemConf_DemEventParameter_RSL_LOTErr,DEM_EVENT_STATUS_PREFAILED );
			
			}
			else
			{
			    (void)Dem_SetEventStatus( DemConf_DemEventParameter_RSL_LOTErr,DEM_EVENT_STATUS_PREPASSED );
			}	 

	 }

}
/*******************************************************************************
** Function Name	: RDC_FaultHandleMainFunction
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: 2ms per
** Description	  	: RDC Module Fault Hand
*******************************************************************************/
void Rdc_FaultHandleMainFunction( void )
{
	Rdc_FaultHandle( );
}

/*******************************************************************************
** Function Name	: RDC_Res_Isr
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: 102us Per
** Description	  	: DSADC ISR
*******************************************************************************/
void Rdc_Res_Isr( void )
{
	st_DsadcModuleType *rdc_pst = &DsadcModule_st ;

	rdc_pst->Rdc_Res_DebugCnt_u32 ++;
	rdc_pst->Dsadc_Sin_Res_s16 		= Dsadc_GetMainResult(Dsadc_ChannelId_4);
	rdc_pst->Dsadc_Cos_Res_s16 		= Dsadc_GetMainResult(Dsadc_ChannelId_5);

	/*test code*/
	if(DMA_Read_Buffer_Count<64)
	{
     	VAR_DSADC_Rdc_Sin_s16[DMA_Read_Buffer_Count] = rdc_pst->Dsadc_Sin_Res_s16;
     	VAR_DSADC_Rdc_Cos_s16[DMA_Read_Buffer_Count] = rdc_pst->Dsadc_Cos_Res_s16;
//     	DMA_Read_Buffer_Count++;
	}
      /*JEE_MISRA_RULE_13_02 It's allowed .*/
	rdc_pst->RslRef_s32 = (sint32)( rdc_pst->Dsadc_Sin_Res_s16*rdc_pst->Dsadc_Sin_Res_s16 + \
			rdc_pst->Dsadc_Cos_Res_s16*rdc_pst->Dsadc_Cos_Res_s16 );
 /*JEE_MISRA_RULE_11_04 It's allowed .*/
	rdc_pst->ICU0_CH6_TimeStampe_u32 = GTM_TIM0_CH6_GPR0.B.GPR0;
  /*JEE_MISRA_RULE_13_02 It's allowed .*/
	Rdc_Get_MAX_Amplitude_Per102ms( rdc_pst->Dsadc_Sin_Res_s16,rdc_pst->Dsadc_Cos_Res_s16 );
}

/*******************************************************************************
** Function Name	: Rdc_AngleHandle
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: 100us
** Description	  	: Angle and Speed Calculate
*******************************************************************************/
void Rdc_AngleHandle( const float32* cofFrqPwm_f32, RdcOutIFType * out )
{
 	/*JEE_MISRA_RULE_8_13 It's allowed .*/
	st_DsadcModuleType *angleHandle_pst  = &DsadcModule_st;

	Rdc_TimestampCompensation( );

	VAR_CDD_Rslv_Sin_f32 = (float32)VAR_Rdc_Sin_s16;         /* '<Root>/CDD_Rslv_Sin' */
	VAR_CDD_Rslv_Cos_f32 = (float32)VAR_Rdc_Cos_s16;         /* '<Root>/CDD_Rslv_Cos' */
	VAR_CDD_RslvTimeStamp_f32 = angleHandle_pst->Rdc_TimeStampe_f32;    							/* '<Root>/CDD_RslvTimeStamp' */

	VAR_CDD_Rslv_SinMax_f32   = (float32)(angleHandle_pst->RdcRslMaxAmplitude_st.si16_Dsadc_Res0_PosMax);      /* '<Root>/CDD_Rslv_SinMax' */
	VAR_CDD_Rslv_SinMin_f32   = (float32)(angleHandle_pst->RdcRslMaxAmplitude_st.si16_Dsadc_Res0_NegMax);      /* '<Root>/CDD_Rslv_SinMin' */
	VAR_CDD_Rslv_CosMax_f32   = (float32)(angleHandle_pst->RdcRslMaxAmplitude_st.si16_Dsadc_Res1_PosMax);      /* '<Root>/CDD_Rslv_CosMax' */
	VAR_CDD_Rslv_CosMin_f32   = (float32)(angleHandle_pst->RdcRslMaxAmplitude_st.si16_Dsadc_Res1_NegMax);      /* '<Root>/CDD_Rslv_CosMin' */
	VAR_LvPower_PowerUpFnh_u8 = LV_PowerFinish();

	VAR_MCF_cofFrqPwm_f32     = * cofFrqPwm_f32;        		/* '<Root>/MCF_cofFrqPwm' */

	RDC_step();

	out->ArctanAgRtr_f32 = VAR_RDC_ArctanAgRtr_f32 ;      	/* '<S6>/Switch' */
	out->nWoFlt_f32 =  VAR_RDC_nWoFlt_f32  ;           		/* '<S12>/Divide' */

	if( VAR_RDC_flgSpdHorL_b == 1U )
	{
		Dio_WriteChannel(DioConf_DioChannel_DO_FLNAKS_P00_10, 0);/*Low speed is low level*/
	}
	else
	{
		Dio_WriteChannel(DioConf_DioChannel_DO_FLNAKS_P00_10, 1);/*High speed is high level*/
	}
}

