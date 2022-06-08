

#define MEMMAP_ERROR
#if defined NM_START_SEC_VAR_CLEARED_UNSPECIFIED
    /* UNSPECIFIED */
    #define BSW_START_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef NM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined NM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef NM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined NM_START_SEC_CONST_UNSPECIFIED
    /* Unspecified size */
    #define BSW_START_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef NM_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined NM_STOP_SEC_CONST_UNSPECIFIED
    #define BSW_STOP_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef NM_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined NM_START_SEC_CONST_8
    #define BSW_START_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef NM_START_SEC_CONST_8
    #undef MEMMAP_ERROR
#elif defined NM_STOP_SEC_CONST_8
    #define BSW_STOP_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef NM_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR

#elif defined NM_START_SEC_CODE
  #define  BSW_START_SEC_CODE
    #include "Bsw_MemMap.h"
  #undef NM_START_SEC_CODE
  #undef MEMMAP_ERROR
#elif defined NM_STOP_SEC_CODE
  #define  BSW_STOP_SEC_CODE
    #include "Bsw_MemMap.h"
  #undef NM_STOP_SEC_CODE
  #undef MEMMAP_ERROR
#endif

#ifdef MEMMAP_ERROR
   #error "Nm_MemMap.h, wrong #pragma command"
#endif



