/*<RBHead>
 *************************************************************************
 *                                                                       *
 *                      ROBERT BOSCH GMBH                                *
 *                          STUTTGART                                    *
 *                                                                       *
 *          Alle Rechte vorbehalten - All rights reserved                *
 *                                                                       *
 *************************************************************************

 *************************************************************************
 *    Administrative Information (automatically filled in by eASEE)      *
 *************************************************************************
 *
 * $Filename__:rba_MemDiag_MemMap.h$
 *
 * $Author____:SMT6KOR$
 *
 * $Function__:Transferred from BASD:
 *             ECU_CFG : rba_MemDiag \ 3.1.0_COMMON; 0 (\Comp\rba_MemDiag)$
 *
 *************************************************************************
 * $Domain____:SDOM$
 * $User______:FEU2ABT$
 * $Date______:16.09.2014$
 * $Class_____:SWHDR$
 * $Name______:rba_MemDiag_MemMap$
 * $Variant___:2.0.0$
 * $Revision__:0$
 * $Type______:H$
 * $State_____:AVAILABLE$
 * $Generated_:$
 *************************************************************************
 *
 * $UniqueName:$
 * $Component_:$
 *
 *
 *************************************************************************
 * List Of Changes
 *
 * $History
 * 
 * 2.0.0; 0     16.09.2014 FEU2ABT
 *   Reference configuration for platform diagnosis concept
 * 
 * $
 *
 *************************************************************************
</RBHead>*/

/* <component>_MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 3 */
/* MISRA RULE 19.15 VIOLATION: MemMap header concept - no protection against repeated inclusion intended */
#define MEMMAP_ERROR

#if defined (START_WITH_IF)

/* Used for global or static variables that are
    cleared to zero after every reset */
#elif defined RBA_MEMDIAG_START_SEC_VAR_RESET_SAFE_BOOLEAN
    /*  8 bit */
    #define BSW_START_SEC_DEFAULT_RESET_SAFE_8
    //#include "Bsw_MemMap.h"
    #undef RBA_MEMDIAG_START_SEC_VAR_RESET_SAFE_BOOLEAN
    #undef MEMMAP_ERROR
#elif defined RBA_MEMDIAG_STOP_SEC_VAR_RESET_SAFE_BOOLEAN
    #define BSW_STOP_SEC_DEFAULT_RESET_SAFE_8
    //#include "Bsw_MemMap.h"
    #undef RBA_MEMDIAG_STOP_SEC_VAR_RESET_SAFE_BOOLEAN
    #undef MEMMAP_ERROR	
	
#elif defined RBA_MEMDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    /*  8 bit */
    #define BSW_START_SEC_DEFAULT_RAM0_CLEARED_8
    //#include "Bsw_MemMap.h"
    #undef RBA_MEMDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    #undef MEMMAP_ERROR
#elif defined RBA_MEMDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define BSW_STOP_SEC_DEFAULT_RAM0_CLEARED_8
    //#include "Bsw_MemMap.h"
    #undef RBA_MEMDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef MEMMAP_ERROR

#elif defined RBA_MEMDIAG_START_SEC_VAR_CLEARED_8
    /*  8 bit */
    #define BSW_START_SEC_DEFAULT_RAM0_CLEARED_8
    //#include "Bsw_MemMap.h"
    #undef RBA_MEMDIAG_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR
#elif defined RBA_MEMDIAG_STOP_SEC_VAR_CLEARED_8
    #define BSW_STOP_SEC_DEFAULT_RAM0_CLEARED_8
    //#include "Bsw_MemMap.h"
    #undef RBA_MEMDIAG_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR

/* Saved zone for NvM */
#elif defined RBA_MEMDIAG_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    /* unspecified */
    #define BSW_START_SEC_SAVED_ZONE_UNSPECIFIED
    //#include "Bsw_MemMap.h"
    #undef RBA_MEMDIAG_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined RBA_MEMDIAG_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #define BSW_STOP_SEC_SAVED_ZONE_UNSPECIFIED
    //#include "Bsw_MemMap.h"
    #undef RBA_MEMDIAG_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #undef MEMMAP_ERROR


/* Code sections */
#elif defined RBA_MEMDIAG_START_SEC_CODE
    #define  BSW_START_SEC_DEFAULT_CODE
    //#include "Bsw_MemMap.h"
    #undef RBA_MEMDIAG_START_SEC_CODE
    #undef MEMMAP_ERROR
#elif defined RBA_MEMDIAG_STOP_SEC_CODE
    #define  BSW_STOP_SEC_DEFAULT_CODE
    //#include "Bsw_MemMap.h"
    #undef RBA_MEMDIAG_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined RBA_MEMDIAG_START_SEC_CODE_SLOW
    #define  BSW_START_SEC_DEFAULT_CODE
    //#include "Bsw_MemMap.h"
    #undef RBA_MEMDIAG_START_SEC_CODE_SLOW
    #undef MEMMAP_ERROR
#elif defined RBA_MEMDIAG_STOP_SEC_CODE_SLOW
    #define  BSW_STOP_SEC_DEFAULT_CODE
    //#include "Bsw_MemMap.h"
    #undef RBA_MEMDIAG_STOP_SEC_CODE_SLOW
    #undef MEMMAP_ERROR


#elif defined MEMMAP_ERROR
    #error "rba_MemDiag_MemMap.h, wrong #pragma command"
#endif
