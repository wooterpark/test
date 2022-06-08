/*<BASDKey>
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, 2010 Robert Bosch GmbH. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 * Administrative Information (automatically filled in)
 * $Domain____:BASD$
 * $Namespace_:\Comp\rba_Mpu$
 * $Class_____:CT$
 * $Name______:rba_Mpu_Cfg$
 * $Variant___:AR40.3.0.0$
 * $Revision__:0$
 **********************************************************************************************************************
</BASDKey>*/


/*-------------------------------------------------------------------------------------------------------------------*
 * Includes
 *-------------------------------------------------------------------------------------------------------------------*/

#include "rba_Mpu.h"
#include "rba_Mpu_Prv.h"
#include "rba_MemLay.h"

/* makro to publicize the linker label to the header file*/ 


#define RBA_MPU_CORE_NUMBER		0


void rba_Mpu_SetCrossbarMpuConfiguration(void)
{

#if (RBA_MPU_CORE_NUMBER > 0)

    uint32 cntr_RegionCounter_au32[RBA_MPU_CORE_NUMBER];
    rba_Mpu_Region_tst rba_Mpu_Region_st[RBA_MPU_CORE_NUMBER][RBA_MPU_MAX_REGION_NUMBER];



    /* call Safety MPU set configuration function */
    rba_Mpu_SetCrossbarMpuCfg(RBA_MPU_CORE_NUMBER, rba_Mpu_Region_st, cntr_RegionCounter_au32);


#endif

}

