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
 * $Namespace_:\Comp\IoHwAbW$
 * $Class_____:H_TPL$
 * $Name______:IoHwAbW_Cfg_MemMap$
 * $Variant___:AR40.8.0.0$
 * $Revision__:1$
 **********************************************************************************************************************

 ****************************************************************************
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *****************************************************************************
 * Project : Io Hardware Abtraction
 * Component : IoHwAbW
 * Date : Mon Nov 25 2015
 * Version : 1.0
 * Description : RTA-BASE first revision
 ****************************************************************************
</BASDKey>*/


/* MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 3 */

/* MISRA RULE 19.15 VIOLATION: MemMap header concept - no protection against multiple inclusion intended */

/* note: this area is protected against multiple includes */

/* ============================   BSW   ============================ */

/* Used for global or static variables that are
    cleared to zero after every reset */
#if defined IoHwAbW_START_SEC_VAR_CLEARED_8
    /*  8 bit */
    #define CPU0_START_SEC_RAM_CLEARED_8
	#undef IoHwAbW_START_SEC_VAR_CLEARED_8
#elif defined IoHwAbW_STOP_SEC_VAR_CLEARED_8
    #define CPU0_STOP_SEC_RAM_CLEARED_8
	#undef IoHwAbW_STOP_SEC_VAR_CLEARED_8
#elif defined IoHwAbW_START_SEC_VAR_CLEARED_16
    /* 16 bit */
    #define CPU0_START_SEC_RAM_CLEARED_16
	#undef IoHwAbW_START_SEC_VAR_CLEARED_16
#elif defined IoHwAbW_STOP_SEC_VAR_CLEARED_16
    #define CPU0_STOP_SEC_RAM_CLEARED_16
	#undef IoHwAbW_STOP_SEC_VAR_CLEARED_16
#elif defined IoHwAbW_START_SEC_VAR_CLEARED_32
    /* 32 bit */
    #define CPU0_START_SEC_RAM_CLEARED_32
	#undef IoHwAbW_START_SEC_VAR_CLEARED_32
#elif defined IoHwAbW_STOP_SEC_VAR_CLEARED_32
    #define CPU0_STOP_SEC_RAM_CLEARED_32
	#undef IoHwAbW_STOP_SEC_VAR_CLEARED_32
#elif defined IoHwAbW_START_SEC_VAR_CLEARED_BOOLEAN
    /* BOOLEAN size */
    #define CPU0_START_SEC_RAM_CLEARED_BOOL
	#undef IoHwAbW_START_SEC_VAR_CLEARED_BOOLEAN
#elif defined IoHwAbW_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define CPU0_STOP_SEC_RAM_CLEARED_BOOL
	#undef IoHwAbW_STOP_SEC_VAR_CLEARED_BOOLEAN
#elif defined IoHwAbW_START_SEC_VAR_CLEARED_UNSPECIFIED
    /* UNSPECIFIED */
    #define CPU0_START_SEC_RAM_CLEARED_UNSPECIFIED
	#undef IoHwAbW_START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined IoHwAbW_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define CPU0_STOP_SEC_RAM_CLEARED_UNSPECIFIED
	#undef IoHwAbW_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined IoHwAbW_START_SEC_VAR_INIT_UNSPECIFIED
    /* UNSPECIFIED */
    #define CPU0_START_SEC_RAM_INIT_UNSPECIFIED
	#undef IoHwAbW_START_SEC_VAR_INIT_UNSPECIFIED
#elif defined IoHwAbW_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define CPU0_STOP_SEC_RAM_INIT_UNSPECIFIED
	#undef IoHwAbW_STOP_SEC_VAR_INIT_UNSPECIFIED
/*For all the sections defined in RTE have included via IoHwAbW_MemMap.h file and redeclarations have been removed with the following mapping*/
#elif defined IoHwAbW_START_SEC_CODE
    #define  CPU0_START_SEC_CODE
	#undef IoHwAbW_START_SEC_CODE
#elif defined IoHwAbW_STOP_SEC_CODE
    #define  CPU0_STOP_SEC_CODE
	#undef IoHwAbW_STOP_SEC_CODE
#endif

#include "MemMap.h"
/*
<BASDKey>
 **********************************************************************************************************************
 * Administrative Information (automatically filled in)
 * $History___:
 *
 * AR40.8.0.0; 1     17.07.2015 PMR1KOR
 *   CSCRM00893001:Combined Request CSCRM00835549 + fix MISRA 2012 warnings
 *
 * AR40.8.0.0; 0     05.03.2015 CRD5KOR
 *   CSCRM00733239: Remove VARIANT-LINK-TIME for IoHwAbW configuration and MemMap
 *   changes
 *
 * AR40.5.0.0; 1     24.12.2013 GJR1KOR
 *   Updated memmap section during CSCRM00551607 - Interrupt handling in IoHwAbW
 *
 * AR40.5.0.0; 0     05.09.2013 SIH6KOR
 *
 *
 * $
 **********************************************************************************************************************

 **********************************************************************************************************************
 * End of header file: $Name______:IoHwAbW_Cfg_MemMap$
 **********************************************************************************************************************
</BASDKey>
*/
