/*
 * TJA1145.c
 *
 *  Created on: Dec 15, 2017
 *      Author: PUY1HC
 */
#include "TJA1145.h"
#define CPU0_START_SEC_CODE
#include "MemMap.h"
void TJA1145_GotoStandBy(uint8 channel)
{
	uint16 cmd_GotoStandby = 0x0204;
	uint16 res=0x0;
	uint8 count = 0;
	while((res != 0x0204U))
	{
		count++;
		if(count == 100U)
		{
			(void)Det_ReportError(0x01, channel, 0x02, 0x01);	//Report error to DET due to can't disable CAN_Trcv
			break;
		}
		/* MISRA C:2012 Rule-1.1 VIOLATION:  This function is used to transfer uint16 Data by SPI*/
		(void)Spi_SetupEB(channel, &cmd_GotoStandby, &res, 1);
		if(SPI_SEQ_PENDING != Spi_GetSequenceResult(channel))
		{
			(void)Spi_AsyncTransmit(channel);
		}
	}
}
void TJA1145_GotoNormal(uint8 channel)
{
	uint16 cmd_GotoNormal = 0x0207;
	uint16 res=0x0;
	uint8 count = 0;
	while((res != 0x0207U))
	{
		count++;
		if(count == 100U)
		{
			(void)Det_ReportError(0x01, channel, 0x01, 0x01);	//Report error to DET due to can't enable CAN_Trcv
			break;
		}
		/* MISRA C:2012 Rule-1.1 VIOLATION:  This function is used to transfer uint16 Data by SPI*/
		(void)Spi_SetupEB(channel, &cmd_GotoNormal, &res, 1);
		if(SPI_SEQ_PENDING != Spi_GetSequenceResult(channel))
		{
			(void)Spi_AsyncTransmit(channel);
		}
	}
}
#define CPU0_STOP_SEC_CODE
#include "MemMap.h"
