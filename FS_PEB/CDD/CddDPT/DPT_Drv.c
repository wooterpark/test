
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
* $Name______: xx.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: xuwenliao$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
				Note Use English

**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   Note Use English

V1.0.1:	  Note Use English


*******************************************************************************/
/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "LvPower_Drv.h"
#include "Test_Time.h"
#include "IfxPort_reg.h"
#include "IfxSrc_reg.h"
#include "DPT_Drv.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/


/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
#pragma section ".rodata.Calib_32"
const volatile uint8 CAL_CddDPT_byte_au8[6]={0,0,0,0,0,0} ;
#pragma section

uint8 CddDPT_Pulse_Channel_u8;
uint8 CddDPT_S_D_Pulse_u8;
uint32 CddDPT_Pulse_ReqTimeTicks1_u32,CddDPT_Pulse_ReqTimeTicks2_u32,CddDPT_Pulse_ReqTimeTicks3_u32;
uint8 CddDPT_Start_Pulse_u8;
uint8 CddDPT_Start_Pulse_Back_u8=0;
uint8 CddDPT_Start_Pulse_Flag_u8;
/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: Pulse_Test
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Double pulse test  I / O control
*******************************************************************************/
void DPT_IO_Ctr(uint8 Channel,uint8 S_D_Pulse ,uint32 ReqTimeTicks1,uint32 ReqTimeTicks2,uint32 ReqTimeTicks3)
{
	if(  (ReqTimeTicks1<5931)&&  (ReqTimeTicks3<5931) && (ReqTimeTicks2<1931) )
	{
			if( S_D_Pulse == 1 )/*Single pulse*/
			{
				IoSigDio_Set(Channel,1);
				Timer_DelayTicks( ReqTimeTicks1);/*pulse width */
				IoSigDio_Set(Channel,0);
			}
			else if( S_D_Pulse == 2 )/*Double pulse */
			{
				IoSigDio_Set( Channel,1);
				Timer_DelayTicks( ReqTimeTicks1);/*pulse 1 width*/
				IoSigDio_Set( Channel,0);

				Timer_DelayTicks( ReqTimeTicks2);/*width between two pulses */

				IoSigDio_Set(Channel,1);
				Timer_DelayTicks( ReqTimeTicks3);/*pulse 2 width*/
				IoSigDio_Set(Channel,0);
			}
			else
			{
				IoSigDio_Set( Channel,0);
				S_D_Pulse = 0;
			}
	}
	else
	{
		IoSigDio_Set( Channel,0);
	}

}

/*******************************************************************************
** Function Name	: DPT_MainFunction
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Main function of double pulse program
*******************************************************************************/
void DPT_MainFunction(void)
{

	CddDPT_Pulse_Channel_u8 = CAL_CddDPT_byte_au8[0];		 				/*channel£º33¡¢34¡¢35¡¢36¡¢37¡¢38*/
	CddDPT_Pulse_ReqTimeTicks1_u32 = (CAL_CddDPT_byte_au8[1]-1)*100+30;	/*pulse 1 £º0~60 us*/
	CddDPT_Pulse_ReqTimeTicks2_u32 = (CAL_CddDPT_byte_au8[2]-1)*100+30;	/*width between two pulses 0~20 us*/
	CddDPT_S_D_Pulse_u8 = CAL_CddDPT_byte_au8[3];							/*Single or double pulse selection£º 1(Single)/2(double)*/
	CddDPT_Start_Pulse_u8 = CAL_CddDPT_byte_au8[4];						/*Start command */
	CddDPT_Pulse_ReqTimeTicks3_u32 = (CAL_CddDPT_byte_au8[5]-1)*100+30;	/*pulse 1 £º0~60 us*/

	if( CddDPT_Start_Pulse_u8==1 )
	{
		if(CddDPT_Start_Pulse_Back_u8==0)
		{
			CddDPT_Start_Pulse_Flag_u8=1;
		}
	}
	else
	{
		CddDPT_Start_Pulse_Back_u8=0;
	}
	if( CddDPT_Start_Pulse_Flag_u8==1 )
	{
		if( (CddDPT_Pulse_Channel_u8>32)&&(CddDPT_Pulse_Channel_u8<39) )
		{
			if( (CddDPT_Pulse_ReqTimeTicks1_u32>0)&&(CddDPT_Pulse_ReqTimeTicks2_u32>0) )
			{
				DPT_IO_Ctr(CddDPT_Pulse_Channel_u8,CddDPT_S_D_Pulse_u8 ,CddDPT_Pulse_ReqTimeTicks1_u32,CddDPT_Pulse_ReqTimeTicks2_u32,CddDPT_Pulse_ReqTimeTicks3_u32);
			}
		}
		else
		{

		}
		CddDPT_Start_Pulse_Back_u8=1;
		CddDPT_Start_Pulse_Flag_u8=0;
	}
	else
	{

	}
}

/*******************************************************************************
** Function Name	: DPT_IO_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Initialization of I / O port in double pulse experiment
*******************************************************************************/
void DPT_IO_Init(void)
{
	MODULE_P02.IOCR0.U &= 0x000000F8;
	MODULE_P02.IOCR0.U |= 0x80808000;/*Set P2.1¡¢P2.2¡¢P2.3 general I/O*/

	MODULE_P02.IOCR4.U &= 0xF8000000;
	MODULE_P02.IOCR4.U |= 0x00808080;/*Set P2.4¡¢P2.5¡¢P2.6 general I/O*/
}

/*******************************************************************************
** Function Name	: DPT_Irq_Init
** Parameter[in] 	: None
**
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Initialization of Interrupt in double pulse experiment
*******************************************************************************/
void DPT_Irq_Init()
{
	/*clear ADC interrupt*/
	 SRC_VADCG0SR0.U &= ( 0xFFFFFF00);
	 SRC_VADCG0SR1.U &= ( 0xFFFFFF00);

	 SRC_VADCG1SR0.U &= ( 0xFFFFFF00);
	 SRC_VADCG1SR1.U &= ( 0xFFFFFF00);

	 SRC_VADCG2SR0.U &= ( 0xFFFFFF00);
	 SRC_VADCG2SR1.U &= ( 0xFFFFFF00);

	 SRC_VADCG3SR0.U &= (0xFFFFFF00);
	 SRC_VADCG3SR1.U &= (0xFFFFFF00);

	 SRC_VADCG4SR0.U &= (0xFFFFFF00);
	 SRC_VADCG4SR1.U &= (0xFFFFFF00);


	 SRC_VADCG5SR0.U &= (0xFFFFFF00);
	 SRC_VADCG5SR1.U &= (0xFFFFFF00);

	 /*clear DSADC interrupt*/
	 SRC_DSADCSRM4.U &= ( 0xFFFFFF00);

		/*clear ASCLIN1 interrupt*/
	 SRC_ASCLIN1TX.U   &= (0xFFFFFF00);
	 SRC_ASCLIN1RX.U   &= (0xFFFFFF00);
	 SRC_ASCLIN1ERR.U  &= (0xFFFFFF00);

	 SRC_GTMTOM04.U  &= (0xFFFFFF00);
}
/*******************************************************************************

*******************************************************************************/
