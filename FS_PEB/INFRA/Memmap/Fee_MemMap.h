


/* Fee_MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 3 */

/*
 **********************************************************************************************************************
 * Variables mapping
 **********************************************************************************************************************
*/

/* Variables that are cleared to zero after every reset */
/* MR12 DIR 4.10 VIOLATION: MemMap header concept - no protection against repeated inclusion intended */
#if defined FEE_START_SEC_VAR_CLEARED_8
    #undef FEE_START_SEC_VAR_CLEARED_8
    #define BSW_START_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_VAR_CLEARED_8
    #undef FEE_STOP_SEC_VAR_CLEARED_8
    #define BSW_STOP_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
#elif defined FEE_START_SEC_VAR_CLEARED_16
    #undef FEE_START_SEC_VAR_CLEARED_16
    #define BSW_START_SEC_VAR_CLEARED_16
    #include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_VAR_CLEARED_16
    #undef FEE_STOP_SEC_VAR_CLEARED_16
    #define BSW_STOP_SEC_VAR_CLEARED_16
    #include "Bsw_MemMap.h"
#elif defined FEE_START_SEC_VAR_CLEARED_32
    #undef FEE_START_SEC_VAR_CLEARED_32
    #define BSW_START_SEC_VAR_CLEARED_32
    #include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_VAR_CLEARED_32
    #undef FEE_STOP_SEC_VAR_CLEARED_32
    #define BSW_STOP_SEC_VAR_CLEARED_32
    #include "Bsw_MemMap.h"
#elif defined FEE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef FEE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_START_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef FEE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"

/* Variables that are reset to initial value after every reset */
#elif defined FEE_START_SEC_VAR_INIT_8
    #undef FEE_START_SEC_VAR_INIT_8
    #define BSW_START_SEC_VAR_INIT_16   /* CIX2SGH - to align Fee_hdr2Buffer_au8 to even addr */
    #include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_VAR_INIT_8
    #undef FEE_STOP_SEC_VAR_INIT_8
    #define BSW_STOP_SEC_VAR_INIT_16
    #include "Bsw_MemMap.h"
#elif defined FEE_START_SEC_VAR_INIT_32
    #undef FEE_START_SEC_VAR_INIT_32
    #define BSW_START_SEC_VAR_INIT_32
    #include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_VAR_INIT_32
    #undef FEE_STOP_SEC_VAR_INIT_32
    #define BSW_STOP_SEC_VAR_INIT_32
    #include "Bsw_MemMap.h"
#elif defined FEE_START_SEC_VAR_INIT_UNSPECIFIED
    #undef FEE_START_SEC_VAR_INIT_UNSPECIFIED
    #define BSW_START_SEC_VAR_INIT_UNSPECIFIED
    #include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_INIT_UNSPECIFIED
    #include "Bsw_MemMap.h"

/*
 **********************************************************************************************************************
 * Constants mapping
 **********************************************************************************************************************
*/

/* Global or static Constants */
#elif defined FEE_START_SEC_CONST_8
    #undef FEE_START_SEC_CONST_8
    #define BSW_START_SEC_CONST_8
    #include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_CONST_8
    #undef FEE_STOP_SEC_CONST_8
    #define BSW_STOP_SEC_CONST_8
    #include "Bsw_MemMap.h"
#elif defined FEE_START_SEC_CONST_32
    #undef FEE_START_SEC_CONST_32
    #define BSW_START_SEC_CONST_32
    #include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_CONST_32
    #undef FEE_STOP_SEC_CONST_32
    #define BSW_STOP_SEC_CONST_32
    #include "Bsw_MemMap.h"
#elif defined FEE_START_SEC_CONST_UNSPECIFIED
    #undef FEE_START_SEC_CONST_UNSPECIFIED
    #define BSW_START_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_CONST_UNSPECIFIED
    #undef FEE_STOP_SEC_CONST_UNSPECIFIED
    #define BSW_STOP_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"

/*
**********************************************************************************************************************
* Mapping for special protected of variables 
**********************************************************************************************************************
*/
#elif defined FEE_START_SEC_VAR_CLEARED_32_SECURED
	#undef FEE_START_SEC_VAR_CLEARED_32_SECURED
    #define BSW_START_SEC_VAR_CLEARED_32_SECURED
	#include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_VAR_CLEARED_32_SECURED
	#undef FEE_STOP_SEC_VAR_CLEARED_32_SECURED
    #define BSW_STOP_SEC_VAR_CLEARED_32_SECURED
    #include "Bsw_MemMap.h"

#elif defined FEE_START_SEC_VAR_CLEARED_8_SECURED
	#undef FEE_START_SEC_VAR_CLEARED_8_SECURED
    #define BSW_START_SEC_VAR_CLEARED_8_SECURED
	#include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_VAR_CLEARED_8_SECURED
	#undef FEE_STOP_SEC_VAR_CLEARED_8_SECURED
    #define BSW_STOP_SEC_VAR_CLEARED_8_SECURED
    #include "Bsw_MemMap.h"

 #elif defined FEE_START_SEC_VAR_CLEARED_UNSPECIFIED_SECURED
	#undef FEE_START_SEC_VAR_CLEARED_UNSPECIFIED_SECURED
    #define BSW_START_SEC_VAR_CLEARED_UNSPECIFIED_SECURED
	#include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_SECURED
	#undef FEE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_SECURED
    #define BSW_STOP_SEC_VAR_CLEARED_UNSPECIFIED_SECURED
    #include "Bsw_MemMap.h"
/*
 **********************************************************************************************************************
 * Code mapping
 **********************************************************************************************************************
*/

/* Code located in normal code section  (not defined by Autosar!)*/
#elif defined FEE_START_SEC_CODE
    #undef FEE_START_SEC_CODE
    #define  BSW_START_SEC_CODE
    #include "Bsw_MemMap.h"
#elif defined FEE_STOP_SEC_CODE
    #undef FEE_STOP_SEC_CODE
    #define  BSW_STOP_SEC_CODE
    #include "Bsw_MemMap.h"



/*********************************************************************************************************************/
#else
    #error "Fee_MemMap.h: unknown MemMap define "
#endif

/*<BASDKey>
 **********************************************************************************************************************
 * $History___:$
 **********************************************************************************************************************
</BASDKey>*/

/*<BASDKey>
 **********************************************************************************************************************
 * End of header file: $Name______:$
 **********************************************************************************************************************
</BASDKey>*/

