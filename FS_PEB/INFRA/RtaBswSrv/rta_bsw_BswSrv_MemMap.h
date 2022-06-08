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
 * $Namespace_:\Comp\rta_bsw_BswSrv$
 * $Class_____:H_TPL$
 * $Name______:rta_bsw_BswSrv_MemMap$
 * $Variant___:AR40.2.0.0$
 * $Revision__:1$
 **********************************************************************************************************************
</BASDKey>*/

/****************************************************************************
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *****************************************************************************
 * Project : Basic Software Service
 * Component : RTA_BSW_BSWSRV
 * Date : Mon December 28 2015
 * Version : 1.0
 * Description : RTA-BASE first revision
 ****************************************************************************/

/* <component>_MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 3 */
/* MISRA RULE 19.15 VIOLATION: MemMap header concept - no protection against repeated inclusion intended */
/**/
#if defined RTA_BSW_BSWSRV_START_SEC_ENVRAM_32
    #undef  RTA_BSW_BSWSRV_START_SEC_ENVRAM_32
    /* MISRA RULE 3.4 VIOLATION: MemMap header concept - pragma is required */
    #pragma section ".bss.envram.a4" awB
#elif defined RTA_BSW_BSWSRV_STOP_SEC_ENVRAM_32
    #undef    RTA_BSW_BSWSRV_STOP_SEC_ENVRAM_32
    #pragma section

#elif defined RTA_BSW_BSWSRV_START_SEC_VAR_CLEARED_32
    #undef    RTA_BSW_BSWSRV_START_SEC_VAR_CLEARED_32
    #define BSW_START_SEC_DEFAULT_RAM0_CLEARED_32
    #include "Bsw_MemMap.h"
#elif defined RTA_BSW_BSWSRV_STOP_SEC_VAR_CLEARED_32
    #undef    RTA_BSW_BSWSRV_STOP_SEC_VAR_CLEARED_32
    #define BSW_STOP_SEC_DEFAULT_RAM0_CLEARED_32
    #include "Bsw_MemMap.h"

#elif defined RTA_BSW_BSWSRV_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef    RTA_BSW_BSWSRV_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_START_SEC_DEFAULT_RAM0_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
#elif defined RTA_BSW_BSWSRV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef    RTA_BSW_BSWSRV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_STOP_SEC_DEFAULT_RAM0_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"

/* CPU instanced memory instead of an array element for each core */
/* IFX supports local RAM addressing in hardware. For JDP it is emulated with small addressing */
/* only used if RTA_BSW_MEMLAY_DATA_RAM_ALL is defined */
#elif defined RTA_BSW_BSWSRV_START_SEC_RAMALL_CLEARED_UNSPECIFIED
    #undef    RTA_BSW_BSWSRV_START_SEC_RAMALL_CLEARED_UNSPECIFIED
    /* MISRA RULE 3.4 VIOLATION: MemMap header concept - pragma is required */
    #if (MCU_RB_MACHINE_FAM == MCU_RB_IFX_UC1)
    #  pragma section ".zbss.ram_all.a4" awBz
    #else
    #  pragma section ".sbss.ram_all.a4" awBs
    #endif
#elif defined RTA_BSW_BSWSRV_STOP_SEC_RAMALL_CLEARED_UNSPECIFIED
    #undef    RTA_BSW_BSWSRV_STOP_SEC_RAMALL_CLEARED_UNSPECIFIED
    #pragma section

#elif defined RTA_BSW_BSWSRV_START_SEC_CONST_UNSPECIFIED
    #undef    RTA_BSW_BSWSRV_START_SEC_CONST_UNSPECIFIED
    #define BSW_START_SEC_DEFAULT_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
#elif defined RTA_BSW_BSWSRV_STOP_SEC_CONST_UNSPECIFIED
    #undef    RTA_BSW_BSWSRV_STOP_SEC_CONST_UNSPECIFIED
    #define BSW_STOP_SEC_DEFAULT_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"

#elif defined RTA_BSW_BSWSRV_START_SEC_CODE
    #undef    RTA_BSW_BSWSRV_START_SEC_CODE
    #define  BSW_START_SEC_DEFAULT_CODE
    #include "Bsw_MemMap.h"
#elif defined RTA_BSW_BSWSRV_STOP_SEC_CODE
    #undef    RTA_BSW_BSWSRV_STOP_SEC_CODE
    #define  BSW_STOP_SEC_DEFAULT_CODE
    #include "Bsw_MemMap.h"

/* Code for simple lock, common lock and interrupt suspend */
#elif defined RTA_BSW_BSWSRV_START_SEC_CODE_FAST
    #undef    RTA_BSW_BSWSRV_START_SEC_CODE_FAST
    #define  BSW_START_SEC_SPRAM_CODE
    #include "Bsw_MemMap.h"
#elif defined RTA_BSW_BSWSRV_STOP_SEC_CODE_FAST
    #undef    RTA_BSW_BSWSRV_STOP_SEC_CODE_FAST
    #define  BSW_STOP_SEC_SPRAM_CODE
    #include "Bsw_MemMap.h"

/* Code for nonest lock */
#elif defined RTA_BSW_BSWSRV_START_SEC_CODE_NONEST
    #undef    RTA_BSW_BSWSRV_START_SEC_CODE_NONEST
    #define  BSW_START_SEC_SPRAM_CODE
    #include "Bsw_MemMap.h"
#elif defined RTA_BSW_BSWSRV_STOP_SEC_CODE_NONEST
    #undef    RTA_BSW_BSWSRV_STOP_SEC_CODE_NONEST
    #define  BSW_STOP_SEC_SPRAM_CODE
    #include "Bsw_MemMap.h"

/* Code for low priority lock and low priority interrupt suspend */
#elif defined RTA_BSW_BSWSRV_START_SEC_CODE_LOW_PRIO
    #undef    RTA_BSW_BSWSRV_START_SEC_CODE_LOW_PRIO
    #define  BSW_START_SEC_DEFAULT_CODE
    #include "Bsw_MemMap.h"
#elif defined RTA_BSW_BSWSRV_STOP_SEC_CODE_LOW_PRIO
    #undef    RTA_BSW_BSWSRV_STOP_SEC_CODE_LOW_PRIO
    #define  BSW_STOP_SEC_DEFAULT_CODE
    #include "Bsw_MemMap.h"
	
#else
    #error "unknown MemMap define"
#endif

/*<BASDKey>
**********************************************************************************************************************
* $History___:
* 
* AR40.2.0.0; 1     14.02.2014 HCJ2FE
*   release 2/2014
* 
* AR40.2.0.0; 0     19.12.2013 HCJ2FE
*   release 2/2014
* 
* $
**********************************************************************************************************************
</BASDKey>*/

/*<BASDKey>
**********************************************************************************************************************
* End of header file: $Name______:rta_bsw_BswSrv_MemMap$
**********************************************************************************************************************
</BASDKey>*/
