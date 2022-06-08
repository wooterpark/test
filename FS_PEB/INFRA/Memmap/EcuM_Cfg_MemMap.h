

/*********************************************************************************************************************
* CONTAINS THE ECUM-MEMMAP SEC CODE DECLARATIONS
*********************************************************************************************************************/

/* MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 3 */

/* MISRA RULE 19.15 VIOLATION: MemMap header concept - no protection against multiple inclusion intended */
#define MEMMAP_ERROR
/*ECUM is shared between 3 cores*/
#if defined ECUM_START_SEC_VAR_CLEARED_8
    /*  8 bit */
    #define BSW_SHARED_TRUSTED_START_SEC_RAM_CLEARED_8
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_VAR_CLEARED_8
    #define BSW_SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_8
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR

#elif defined ECUM_START_SEC_VAR_CLEARED_16
    /* 16 bit */
    #define BSW_SHARED_TRUSTED_START_SEC_RAM_CLEARED_16
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_VAR_CLEARED_16
    #define BSW_SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_16
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR

#elif defined ECUM_START_SEC_VAR_CLEARED_32
    /* 32 bit */
    #define BSW_SHARED_TRUSTED_START_SEC_RAM_CLEARED_32
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_VAR_CLEARED_32
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_VAR_CLEARED_32
    #define BSW_SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_32
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_VAR_CLEARED_32
    #undef MEMMAP_ERROR


#elif defined ECUM_START_SEC_VAR_CLEARED_BOOLEAN
    #define BSW_SHARED_TRUSTED_START_SEC_RAM_CLEARED_BOOL
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_VAR_CLEARED_BOOLEAN
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define BSW_SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_BOOL
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef MEMMAP_ERROR

#elif defined ECUM_START_SEC_VAR_INIT_16
    #define BSW_SHARED_TRUSTED_START_SEC_RAM_INIT_16
    #include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_VAR_INIT_16
	#undef MEMMAP_ERROR

#elif defined ECUM_STOP_SEC_VAR_INIT_16
    #define BSW_SHARED_TRUSTED_STOP_SEC_RAM_INIT_16
    #include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_VAR_INIT_16
	#undef MEMMAP_ERROR

#elif defined ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED
    /* Unspecified size */
    #define BSW_SHARED_TRUSTED_START_SEC_RAM_CLEARED_UNSPECIFIED
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_UNSPECIFIED
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ECUM_START_SEC_VAR_POWER_ON_CLEARED_8
    /*  8 bit */
    /* MISRA RULE 3.4 VIOLATION: using #pragma directive  - intended Memmory section needs  #pragma directive */
    #define BSW_SHARED_TRUSTED_START_SEC_RAM_CLEARED_8
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_VAR_POWER_ON_CLEARED_8
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_8
 /* MISRA RULE 3.4 VIOLATION: using #pragma directive  - intended Memmory section needs  #pragma directive */
    #define BSW_SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_8
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_8
    #undef MEMMAP_ERROR

#elif defined ECUM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
    /* Unspecified size */
 /* MISRA RULE 3.4 VIOLATION: using #pragma directive  - intended Memmory section needs  #pragma directive */
    #define BSW_SHARED_TRUSTED_START_SEC_RAM_CLEARED_UNSPECIFIED
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
 /* MISRA RULE 3.4 VIOLATION: using #pragma directive  - intended Memmory section needs  #pragma directive */
    #define BSW_SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_UNSPECIFIED
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR


#elif defined ECUM_START_SEC_VAR_SAVED_ZONE0_BOOLEAN
    #define BSW_SHARED_TRUSTED_START_SEC_RAM_CLEARED_BOOL
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_VAR_SAVED_ZONE0_BOOLEAN
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_VAR_SAVED_ZONE0_BOOLEAN
    #define BSW_SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_BOOL
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_VAR_SAVED_ZONE0_BOOLEAN
    #undef MEMMAP_ERROR

#elif defined ECUM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
    #define BSW_SHARED_TRUSTED_START_SEC_RAM_CLEARED_UNSPECIFIED
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
    #define BSW_SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_UNSPECIFIED
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ECUM_START_SEC_CONST_8
    /*  8 bit */
    #define BSW_SHARED_TRUSTED_START_SEC_CONST_8
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_CONST_8
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_CONST_8
    #define BSW_SHARED_TRUSTED_STOP_SEC_CONST_8
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR

#elif defined ECUM_START_SEC_CONST_UNSPECIFIED
    #define BSW_SHARED_TRUSTED_START_SEC_CONST_UNSPECIFIED
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_CONST_UNSPECIFIED
    #define BSW_SHARED_TRUSTED_STOP_SEC_CONST_UNSPECIFIED
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ECUM_START_SEC_CONST_16
    /* 16 bit */
    #define BSW_SHARED_TRUSTED_START_SEC_CONST_16
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_CONST_16
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_CONST_16
    #define BSW_SHARED_TRUSTED_STOP_SEC_CONST_16
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_CONST_16
    #undef MEMMAP_ERROR


#elif defined ECUM_START_SEC_CONST_32
    /* 32 bit */
    #define BSW_SHARED_TRUSTED_START_SEC_CONST_32
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_CONST_32
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_CONST_32
    #define BSW_SHARED_TRUSTED_STOP_SEC_CONST_32
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_CONST_32
    #undef MEMMAP_ERROR


#elif defined ECUM_START_SEC_CONFIG_DATA_8
    #define BSW_SHARED_TRUSTED_START_SEC_CONST_8
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_CONFIG_DATA_8
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_CONFIG_DATA_8
    #define BSW_SHARED_TRUSTED_STOP_SEC_CONST_8
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_CONFIG_DATA_8
    #undef MEMMAP_ERROR

/*
**********************************************************************************************************************
*   Config_Data_postbuild
**********************************************************************************************************************
*/

#elif defined ECUM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #define BSW_SHARED_TRUSTED_START_SEC_CONST_UNSPECIFIED
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #define BSW_SHARED_TRUSTED_STOP_SEC_CONST_UNSPECIFIED
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ECUM_START_SEC_CALLOUT_CODE
    #define BSW_SHARED_TRUSTED_START_SEC_CODE
	#include "Bsw_MemMap.h"
    #undef ECUM_START_SEC_CALLOUT_CODE
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_CALLOUT_CODE
    #define BSW_SHARED_TRUSTED_STOP_SEC_CODE
	#include "Bsw_MemMap.h"
    #undef ECUM_STOP_SEC_CALLOUT_CODE
    #undef MEMMAP_ERROR

#elif defined ECUM_START_SEC_VAR_INIT_8
      #define BSW_SHARED_TRUSTED_START_SEC_RAM_INIT_8
      #include "Bsw_MemMap.h"
      #undef ECUM_START_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_VAR_INIT_8
      #define BSW_SHARED_TRUSTED_STOP_SEC_RAM_INIT_8
      #include "Bsw_MemMap.h"
      #undef ECUM_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR
#endif

/*For all the sections defined in RTE have included via EcuM_MemMap.h file and redeclarations have been removed with the following mapping*/
#ifdef ECUM_START_SEC_CODE
   #define BSW_SHARED_TRUSTED_START_SEC_CODE
   #include "Bsw_MemMap.h"
   #undef ECUM_START_SEC_CODE
   #undef MEMMAP_ERROR
#elif defined ECUM_STOP_SEC_CODE
   #define BSW_SHARED_TRUSTED_STOP_SEC_CODE
   #include "Bsw_MemMap.h"
   #undef ECUM_STOP_SEC_CODE
   #undef MEMMAP_ERROR
#endif

#ifdef MEMMAP_ERROR
  #error "EcuM_Cfg_MemMap.h, wrong #pragma command"
#endif





