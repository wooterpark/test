

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/


/* <component>_MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 3 */
/* MISRA RULE 19.15 VIOLATION: MemMap header concept - no protection against repeated inclusion intended */
#define MEMMAP_ERROR

/*The compiler warning "CANNM_CONFIGURATION_VARIANT and CANNM_VARIANT_PRE_COMPILE is undefined" does not impact the functionality. The warning is displayed due to RTE generated files , RTE does not include CanNm_Cfg.h (Macro definition is available in the CanNm_Cfg.h file).*/
#if(CANNM_CONFIGURATION_VARIANT == CANNM_VARIANT_PRE_COMPILE)
/* If Module is pre-compile , then map post-build memmap to pre-compile memmap*/
#ifdef CANNM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #undef CANNM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #define CANNM_START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #undef CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #define CANNM_STOP_SEC_CONST_UNSPECIFIED
#endif

#ifdef CANNM_START_SEC_CONFIG_DATA_POSTBUILD_8
    #undef CANNM_START_SEC_CONFIG_DATA_POSTBUILD_8
    #define CANNM_START_SEC_CONST_8
#endif
#ifdef CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_8
    #undef CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_8
    #define CANNM_STOP_SEC_CONST_8
#endif
#endif /* #if(COMM_CONFIGURATION_VARIANT == COMM_VARIANT_PRECOMPILE)*/

#if defined CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED
    /* UNSPECIFIED */
    #define BSW_START_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CANNM_START_SEC_CONST_UNSPECIFIED
    /* Unspecified size */
    #define BSW_START_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANNM_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_CONST_UNSPECIFIED
    #define BSW_STOP_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANNM_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CANNM_START_SEC_CONST_8
    #define BSW_START_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef CANNM_START_SEC_CONST_8
    #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_CONST_8
    #define BSW_STOP_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef CANNM_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR




#elif defined CANNM_START_SEC_VAR_CLEARED_8
    /*  8 bit */
    #define BSW_START_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
    #undef CANNM_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_VAR_CLEARED_8
    #define BSW_STOP_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
    #undef CANNM_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR

#elif defined CANNM_START_SEC_CODE
   #define  BSW_START_SEC_CODE
    #include "Bsw_MemMap.h"
   #undef CANNM_START_SEC_CODE
   #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_CODE
   #define  BSW_STOP_SEC_CODE
    #include "Bsw_MemMap.h"
   #undef CANNM_STOP_SEC_CODE
   #undef MEMMAP_ERROR

/* ======================================================== */
/* == PBL Constants                                          == */
/* ======================================================== */

#elif defined CANNM_START_SEC_CONFIG_DATA_POSTBUILD_8
     /*  8 bit */
    #define BSW_START_SEC_CONFIG_DATA_POSTBUILD_8
    #include "Bsw_MemMap.h"
    #undef CANNM_START_SEC_CONFIG_DATA_POSTBUILD_8
    #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_8
    #define BSW_STOP_SEC_CONFIG_DATA_POSTBUILD_8
    #include "Bsw_MemMap.h"
    #undef CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_8
    #undef MEMMAP_ERROR



#elif defined CANNM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    /* Unspecified size */
    #define BSW_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANNM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #define BSW_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #undef MEMMAP_ERROR



#endif

#if defined MEMMAP_ERROR
   #error "CanNm_MemMap.h, wrong #pragma command"
#endif


