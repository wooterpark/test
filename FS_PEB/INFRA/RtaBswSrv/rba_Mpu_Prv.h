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
 * $Class_____:H$
 * $Name______:rba_Mpu_Prv$
 * $Variant___:AR40.4.0.0$
 * $Revision__:0$
 **********************************************************************************************************************
</BASDKey>*/

/*
 * rba_Mpu_Prv.h
 *
 *  Created on: 21.06.2013
 *      Author: sba1fe
 */

/*!
 * \rba_comp rba_Mpu
 *  @{
 */

#ifndef RBA_MPU_PRV_H
#define RBA_MPU_PRV_H

/*
 ***************************************************************************************************
 * Defines for IFX/JDP
 ***************************************************************************************************
 */
#define RBA_MPU_CORE0ID             0xFF00FF00
#define RBA_MPU_CORE1ID             0xFF00FF01
#define RBA_MPU_CORE2ID             0xFF00FF02
#define RBA_MPU_INVALID_ADDR        0xDEADDEAD

#define RBA_MPU_ALIGNMENT           0x0000001F

#define RBA_MPU_MAX_REGION_NUMBER       3
#include "Std_Types.h"




#if ((MCU_RB_MACHINE_FAM == MCU_RB_IFX_UC1))

#define RBA_MPU_CORE0_START_ADDR    0x70000000      // core 0 RAM start address
#define RBA_MPU_CORE0_END_ADDR      0x7FFFFFFF      // core 0 RAM end address
#define RBA_MPU_CORE1_START_ADDR    0x60000000      // core 1 RAM start address
#define RBA_MPU_CORE1_END_ADDR      0x6FFFFFFF      // core 1 RAM end address
#define RBA_MPU_CORE2_START_ADDR    0x50000000      // core 2 RAM start address
#define RBA_MPU_CORE2_END_ADDR      0x5FFFFFFF      // core 2 RAM end address

/* ((MCU_RB_MACHINE_FAM == MCU_RB_IFX_UC1)) */
#endif
/* **************************************** */

/* Crossbar MPU specific stuff */

/*
 ***************************************************************************************************
 * Structures for IFX/JDP
 ***************************************************************************************************
 */
typedef struct
{
    uint32 startAddress_u32;
    uint32 endAddress_u32;
    uint32 accessCfg_u32;
} rba_Mpu_Region_tst;

/*
 ***************************************************************************************************
 * Prototypes for IFX/JDP
 ***************************************************************************************************
 */

/* Start MemMap for default code */
#define RBA_MPU_START_SEC_DEFAULT_CODE
#include "rba_Mpu_MemMap.h"
/* ***************************** */

void rba_Mpu_SetCrossbarMpuCfg(uint32 indexCores_u32, rba_Mpu_Region_tst rba_Mpu_Region_ast[][RBA_MPU_MAX_REGION_NUMBER], const uint32 regionCounter_au32[]);
void rba_Mpu_SetCrossbarMpuConfiguration(void);

void rba_Mpu_BubbleSort(uint32 regionCounter_u32, rba_Mpu_Region_tst rba_Mpu_Region_ast[]);
Std_ReturnType rba_Mpu_CheckCoreRegionCfg(uint32 regionCounter_u32, const rba_Mpu_Region_tst rba_Mpu_Region_ast[]);
uint32 rba_Mpu_CheckAddresses(uint32 regionCounter_u32, const rba_Mpu_Region_tst rba_Mpu_Region_ast[]);
Std_ReturnType rba_Mpu_CheckFor32ByteAddressAlignment(uint32 regionCounter_u32, const rba_Mpu_Region_tst  rba_Mpu_Region_ast[]);

/* Stop MemMap for default code */
#define RBA_MPU_STOP_SEC_DEFAULT_CODE
#include "rba_Mpu_MemMap.h"
/* **************************** */

/* RBA_MPU_PRV_H */
#endif
/* ************* */

/*! @} */

/* <BASDKey>
*********************************************************************************************************
* $History__:$
*********************************************************************************************************
</BASDKey>*/

/*<BASDKey>
**********************************************************************************************************************
* End of header file: $Name___:$
**********************************************************************************************************************
</BASDKey>*/

