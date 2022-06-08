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
 * $Name______:rba_Mpu$
 * $Variant___:AR40.3.2.0$
 * $Revision__:0$
 **********************************************************************************************************************
</BASDKey>*/

/*!
 * \rba_comp rba_Mpu
 *  @{
 */

#ifndef RBA_MPU_H
#define RBA_MPU_H

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */
#include "Std_Types.h"
#include "Mcu.h"


/* Vendor and module identification */
#define RBA_MPU_VENDOR_ID   (6)
#define RBA_MPU_MODULE_ID   (39)
#define RBA_MPU_INSTANCE_ID (0)

/* Autosar version information */
#define RBA_MPU_AR_RELEASE_MAJOR_VERSION    (4)
#define RBA_MPU_AR_RELEASE_MINOR_VERSION    (0)
#define RBA_MPU_AR_RELEASE_REVISION_VERSION (2)

/* Module version information */
#define RBA_MPU_SW_MAJOR_VERSION (3)
#define RBA_MPU_SW_MINOR_VERSION (2)
#define RBA_MPU_SW_PATCH_VERSION (0)

/*
 ***************************************************************************************************
 * Defines for IFX/JDP
 ***************************************************************************************************
 */

/* core MPU specific stuff */
#if (MCU_RB_MACHINE_FAM == MCU_RB_JDP_UC1)

/*
 ***************************************************************************************************
 * Defines JDP
 ***************************************************************************************************
 */

/*
 ***************************************************************************************************
 * Enumerations JDP
 ***************************************************************************************************
 */

/*
 ***************************************************************************************************
 * Structures JDP
 ***************************************************************************************************
 */

/*
 ***************************************************************************************************
 * Prototypes JDP
 ***************************************************************************************************
 */

/* Start MemMap for default code */
#define RBA_MPU_START_SEC_DEFAULT_CODE
#include "rba_Mpu_MemMap.h"
/* ***************************** */

extern void rba_Mpu_SetCoreMpuCfg(void);
extern void rba_Mpu_EnableCoreMpu(void);

/* Stop MemMap for default code */
#define RBA_MPU_STOP_SEC_DEFAULT_CODE
#include "rba_Mpu_MemMap.h"
/* **************************** */

#define rba_Mpu_SetCfg rba_Mpu_SetCoreMpuCfg        // for compatibility
#define rba_Mpu_ReadMpuCfg rba_Mpu_ReadCoreMpuCfg   // for compatibility
#define rba_Mpu_EnableMpu rba_Mpu_EnableCoreMpu     // for compatibility


/* (MCU_RB_MACHINE_FAM == MCU_RB_JDP_UC1) */
#endif
/* ************************************** */


/* Crossbar MPU specific stuff */

/*
 ***************************************************************************************************
 * Structures for IFX/JDP
 ***************************************************************************************************
 */

/*
 ***************************************************************************************************
 * Prototypes for IFX/JDP
 ***************************************************************************************************
 */

/* Start MemMap for default code */
#define RBA_MPU_START_SEC_DEFAULT_CODE
#include "rba_Mpu_MemMap.h"
/* ***************************** */

extern void rba_Mpu_CrossbarMpuInit(void);

/* Stop MemMap for default code */
#define RBA_MPU_STOP_SEC_DEFAULT_CODE
#include "rba_Mpu_MemMap.h"
/* ***************************** */

/* RBA_MPU_H */
#endif
/* ********* */

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

