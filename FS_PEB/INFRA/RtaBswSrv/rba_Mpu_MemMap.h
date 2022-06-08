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
 * $Namespace_:\Deliveries\DGS_MDG1$
 * $Class_____:H$
 * $Name______:rba_Mpu_MemMap$
 * $Variant___:13.11.00_COMMON$
 * $Revision__:0$
 **********************************************************************************************************************
</BASDKey>*/

/*
 * rba_Emm_MemMap.h
 *
 *  Created on: 18.09.2013
 *      Author: sba1fe
 */

/* rba_Mpu_MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 3 */
/* MISRA RULE 19.15 VIOLATION: MemMap header concept - no protection against repeated inclusion intended */
#ifndef RBA_MPU_ENABLE_MEMMAP
#   define RBA_MPU_ENABLE_MEMMAP     STD_OFF
#endif
/**/
#if defined RBA_MPU_START_SEC_DEFAULT_CODE                              // for default code
#   if (RBA_MPU_ENABLE_MEMMAP == STD_ON)
#       define BSW_START_SEC_DEFAULT_CODE
#       include "Bsw_MemMap.h"
#   endif
#   undef RBA_MPU_START_SEC_DEFAULT_CODE
#   undef MEMMAP_ERROR
#elif defined RBA_MPU_STOP_SEC_DEFAULT_CODE
#   if (RBA_MPU_ENABLE_MEMMAP == STD_ON)
#       define BSW_STOP_SEC_DEFAULT_CODE
#       include "Bsw_MemMap.h"
#   endif
#   undef RBA_MPU_STOP_SEC_DEFAULT_CODE
#   undef MEMMAP_ERROR

#elif defined RBA_MPU_START_SEC_DEFAULT_CONST                           // for example constants
#   if (RBA_MPU_ENABLE_MEMMAP == STD_ON)
#       define BSW_START_SEC_DEFAULT_CONST_32
#       include "Bsw_MemMap.h"
#   endif
#   undef RBA_MPU_START_SEC_DEFAULT_CONST
#   undef MEMMAP_ERROR
#elif defined RBA_MPU_STOP_SEC_DEFAULT_CONST
#   if (RBA_MPU_ENABLE_MEMMAP == STD_ON)
#       define BSW_STOP_SEC_DEFAULT_CONST_32
#       include "Bsw_MemMap.h"
#   endif
#   undef RBA_MPU_STOP_SEC_DEFAULT_CONST
#   undef MEMMAP_ERROR

#elif defined RBA_MPU_START_SEC_DEFAULT_RAM0_CLEARED_UNSPECIFIED        // for vars called by my self
#   if (RBA_MPU_ENABLE_MEMMAP == STD_ON)
#       define BSW_START_SEC_DEFAULT_RAM0_CLEARED_UNSPECIFIED
#       include "Bsw_MemMap.h"
#   endif
#   undef RBA_MPU_START_SEC_DEFAULT_RAM0_CLEARED_UNSPECIFIED
#   undef MEMMAP_ERROR
#elif defined RBA_MPU_STOP_SEC_DEFAULT_RAM0_CLEARED_UNSPECIFIED
#   if (RBA_MPU_ENABLE_MEMMAP == STD_ON)
#       define BSW_STOP_SEC_DEFAULT_RAM0_CLEARED_UNSPECIFIED
#       include "Bsw_MemMap.h"
#   endif
#   undef RBA_MPU_STOP_SEC_DEFAULT_RAM0_CLEARED_UNSPECIFIED
#   undef MEMMAP_ERROR

#elif defined RBA_MPU_START_SEC_DEFAULT_RAM1_CLEARED_UNSPECIFIED        // for vars called from user
#   if (RBA_MPU_ENABLE_MEMMAP == STD_ON)
#       define BSW_START_SEC_DEFAULT_RAM1_CLEARED_UNSPECIFIED
#       include "Bsw_MemMap.h"
#   endif
#   undef RBA_MPU_START_SEC_DEFAULT_RAM1_CLEARED_UNSPECIFIED
#   undef MEMMAP_ERROR
#elif defined RBA_MPU_STOP_SEC_DEFAULT_RAM1_CLEARED_UNSPECIFIED
#   if (RBA_MPU_ENABLE_MEMMAP == STD_ON)
#       define BSW_STOP_SEC_DEFAULT_RAM1_CLEARED_UNSPECIFIED
#       include "Bsw_MemMap.h"
#   endif
#   undef RBA_MPU_STOP_SEC_DEFAULT_RAM1_CLEARED_UNSPECIFIED
#   undef MEMMAP_ERROR

#endif


/*<BASDKey>
 **********************************************************************************************************************
 * $History___:
 * 
 * 13.11.00_COMMON; 0     04.11.2013 SMT6KOR
 *   rba_Mpu Config added
 * 
 * $
 **********************************************************************************************************************
</BASDKey>*/

/*<BASDKey>
 **********************************************************************************************************************
 * End of header file: $Name______:rba_Mpu_MemMap$
 **********************************************************************************************************************
</BASDKey>*/
