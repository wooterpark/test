#ifndef  _MCUFUNC_H
#define  _MCUFUNC_H

#define MCU_START_SEC_CODE
#include "MemMap.h"
extern void McuFunc_InitializeClock(void);
#define MCU_STOP_SEC_CODE
#include "MemMap.h"

/* CIX2SGH */
#define Mcu_Config                  Mcu_ConfigRoot
#define Port_Config                 Port_ConfigRoot
#define Can_17_MCanP_Config         Can_17_MCanP_ConfigRoot
#define Dio_Config                  Dio_ConfigRoot
#define Fls_Config                  Fls_17_Pmu_ConfigRoot
#define Pwm_17_Gtm_Config           Pwm_ConfigRoot
#define Icu_17_GtmCcu6_Config       Icu_ConfigRoot
#define IoHwAb_Adc_Config           Adc_ConfigRoot
#define Spi_Config                  Spi_ConfigRoot
#define Gpt_Config                  Gpt_ConfigRoot
#define Uart_Config                 Uart_ConfigRoot
#define Dsadc_Config                Dsadc_ConfigRoot
#define FlsLoader_Config            NULL_PTR

#define Wdg_17_Scu_Config           Wdg_ConfigRoot
#define Smu_Config                  Smu_ConfigRoot[1]
#define Dma_Config                  Dma_ConfigRoot
/* CIX2SGH */

#endif /* _MCUFUNC_H */
