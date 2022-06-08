/*
 * SpiApp.c
 *
 *  Created on: 2020Äê3ÔÂ11ÈÕ
 *      Author: fujian
 */
#include "Spi.h"
#include "SpiApp.h"

void SpiApp_SetAsyncMode(void)
{
	Spi_SetAsyncMode(SPI_POLLING_MODE);
}
