/*
 * SpiApp.c
 *
 *  Created on: 2020��3��11��
 *      Author: fujian
 */
#include "Spi.h"
#include "SpiApp.h"

void SpiApp_SetAsyncMode(void)
{
	Spi_SetAsyncMode(SPI_POLLING_MODE);
}
