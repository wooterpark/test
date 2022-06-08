/*
 *
 * 	Clock initializzation Funcntion
 *
 *
 */

#include "McuFunc.h"
#include "Mcu.h"
#include "IfxSmu_reg.h"

#define MCU_START_SEC_CODE
#include "MemMap.h"
void McuFunc_InitializeClock(void)
{
	Std_ReturnType RetValue;
	/* Initialize MCU Clock*/
	/* parameter 0 is chosen here by default, the first clock configuration */
	RetValue = Mcu_InitClock(0);
	/* wait till PLL lock */
	while(Mcu_GetPllStatus() == MCU_PLL_UNLOCKED)
	{

	}
	/* distribute the clock */
	Mcu_DistributePllClock();

	/* SMU is configured for Reset on WDG timeout */
	// Mcal_ResetENDINIT();
	// SCU_TRAPDIS.B.SMUT = 0;
	// Mcal_SetENDINIT();
	// #if (IFX_SAFETLIB_USED == STD_OFF)
	// Mcal_ResetSafetyENDINIT_Timed(ECUM_ENDINIT_TIMEOUT);
	// SMU_KEYS.U = 0xbc;
	// SMU_CMD.U = 0x00;
	// SMU_AGCF3_0.U = 0x00000000;
	// SMU_AGCF3_1.U = 0x001E0000;
	// SMU_AGCF3_2.U = 0x001E0000;
	// Mcal_SetSafetyENDINIT_Timed();
	// #endif
}
#define MCU_STOP_SEC_CODE
#include "MemMap.h"
