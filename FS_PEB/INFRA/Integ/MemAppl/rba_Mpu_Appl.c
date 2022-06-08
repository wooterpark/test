/*
 * rba_Mpu_Appl.c
 *
 *  Created on: Dec 9, 2019
 *      Author: frank.zhang
 */

#include "rba_Mpu_Prv.h"
#include "rba_MemLay.h"
#include "rba_Reset.h"
#include "IfxCpu_reg.h"
#include "rba_Mpu_Appl.h"
#include "rba_Mpu_Sfty_Linker.h"

void rba_Mpu_Sfty_Init(void)
{

	uint32 cntr_RegionCounter_au32[3];
    rba_Mpu_Region_tst rba_Mpu_Region_st[3][3];

    cntr_RegionCounter_au32[0] = 1;
    cntr_RegionCounter_au32[1] = 1;
    cntr_RegionCounter_au32[2] = 1;


    /* MISRA RULE 11.3 VIOLATION: the real address is needed for checks in C code and as value for registers */
    rba_Mpu_Region_st[0][0].startAddress_u32 = (uint32)__RAM0_MPU_SFTY_SECTION0_START;
    rba_Mpu_Region_st[0][0].endAddress_u32 = (uint32)__RAM0_MPU_SFTY_SECTION0_END;
    rba_Mpu_Region_st[0][0].accessCfg_u32 = 0x00010003;

    /* MISRA RULE 11.3 VIOLATION: the real address is needed for checks in C code and as value for registers */
    rba_Mpu_Region_st[1][0].startAddress_u32 = (uint32)__RAM1_MPU_SFTY_SECTION0_START;
    rba_Mpu_Region_st[1][0].endAddress_u32 = (uint32)__RAM1_MPU_SFTY_SECTION0_END;
    rba_Mpu_Region_st[1][0].accessCfg_u32 = 0x0002000c;

    /* MISRA RULE 11.3 VIOLATION: the real address is needed for checks in C code and as value for registers */
    //rba_Mpu_Region_st[1][1].startAddress_u32 = (uint32)__RAM1_MPU_SFTY_SECTION1_START;
    //rba_Mpu_Region_st[1][1].endAddress_u32 = (uint32)__RAM1_MPU_SFTY_SECTION1_END;
    //rba_Mpu_Region_st[1][1].accessCfg_u32 = 0x00073fff;

    /* MISRA RULE 11.3 VIOLATION: the real address is needed for checks in C code and as value for registers */
    //rba_Mpu_Region_st[1][2].startAddress_u32 = (uint32)__RAM1_MPU_SFTY_SECTION2_START;
    //rba_Mpu_Region_st[1][2].endAddress_u32 = (uint32)__RAM1_MPU_SFTY_SECTION2_END;
    //rba_Mpu_Region_st[1][2].accessCfg_u32 = 0x0002000c;
	//rba_Mpu_Region_st[1][2].accessCfg_u32 = 0x00073fff;

    /* MISRA RULE 11.3 VIOLATION: the real address is needed for checks in C code and as value for registers */
    //rba_Mpu_Region_st[1][3].startAddress_u32 = (uint32)__RAM1_MPU_SFTY_SECTION3_START;
    //rba_Mpu_Region_st[1][3].endAddress_u32 = (uint32)__RAM1_MPU_SFTY_SECTION3_END;
    //rba_Mpu_Region_st[1][3].accessCfg_u32 = 0x00073fff;

    /* MISRA RULE 11.3 VIOLATION: the real address is needed for checks in C code and as value for registers */
    //rba_Mpu_Region_st[1][4].startAddress_u32 = (uint32)__RAM1_MPU_SFTY_SECTION4_START;
    //rba_Mpu_Region_st[1][4].endAddress_u32 = (uint32)__RAM1_MPU_SFTY_SECTION4_END;
    //rba_Mpu_Region_st[1][4].accessCfg_u32 = 0x0002000c;
	//rba_Mpu_Region_st[1][4].accessCfg_u32 = 0x00073fff;

    /* MISRA RULE 11.3 VIOLATION: the real address is needed for checks in C code and as value for registers */
    //rba_Mpu_Region_st[1][5].startAddress_u32 = (uint32)__RAM1_MPU_SFTY_SECTION5_START;
    //rba_Mpu_Region_st[1][5].endAddress_u32 = (uint32)__RAM1_MPU_SFTY_SECTION5_END;
    //rba_Mpu_Region_st[1][5].accessCfg_u32 = 0x00073fff;

    /* MISRA RULE 11.3 VIOLATION: the real address is needed for checks in C code and as value for registers */
    rba_Mpu_Region_st[2][0].startAddress_u32 = (uint32)__RAM2_MPU_SFTY_SECTION0_START;
    rba_Mpu_Region_st[2][0].endAddress_u32 = (uint32)__RAM2_MPU_SFTY_SECTION0_END;
    rba_Mpu_Region_st[2][0].accessCfg_u32 = 0x00040030;

    /* call Safety MPU set configuration function */
    rba_Mpu_SetCrossbarMpuCfg(3, rba_Mpu_Region_st, cntr_RegionCounter_au32);


	return;
}
volatile uint8 MpuTest_Core0_case_u8=100;
volatile uint8 MpuTest_Core1_case_u8=100;
volatile uint8 MpuTest_Core2_case_u8=100;
volatile uint32 *MpuTest_Addr_pu32=0x50018200;
void rba_Mpu_Sfty_Core0_Test(void)
{
	switch(MpuTest_Core0_case_u8)
	{
		case 0:
			break;
		case 1:
			//MpuTest_Core0_case_u8=0;
			(*MpuTest_Addr_pu32)++;
			break;
		default:
			break;
	}


}
void rba_Mpu_Sfty_Core1_Test(void)
{
	switch(MpuTest_Core1_case_u8)
	{
		case 0:
			break;
		case 1:
			*MpuTest_Addr_pu32+=160;
			break;
		default:
			break;
	}

}
void rba_Mpu_Sfty_Core2_Test(void)
{
	switch(MpuTest_Core2_case_u8)
	{
		case 0:
			break;
		case 1:
			*MpuTest_Addr_pu32+=1600;
			break;
		default:
			break;
	}

}


