



/****************************************************************************
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *****************************************************************************
 * Project : Flash Driver
 * Component : Fls
 * Date : Mon June 27 2016
 * Version : 1.0
 * Description : RTA-BASE first revision
 ****************************************************************************/


/* Fls_MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 3 */

/* MISRA RULE 19.15 VIOLATION: MemMap header concept - no protection against repeated inclusion intended */


/*
 **********************************************************************************************************************
 * Variables mapping
 **********************************************************************************************************************
*/
/* Variables that are cleared to zero after every reset */
/* MISRA RULE 19.15 VIOLATION: MemMap header concept - no protection against repeated inclusion intended */
#if defined FLS_START_SEC_VAR_CLEARED_BOOLEAN
    #undef FLS_START_SEC_VAR_CLEARED_BOOLEAN
    #define BSW_START_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef FLS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define BSW_STOP_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
#elif defined FLS_START_SEC_VAR_CLEARED_8
    #undef FLS_START_SEC_VAR_CLEARED_8
    #define BSW_START_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_VAR_CLEARED_8
    #undef FLS_STOP_SEC_VAR_CLEARED_8
    #define BSW_STOP_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
#elif defined FLS_START_SEC_VAR_CLEARED_16
    #undef FLS_START_SEC_VAR_CLEARED_16
    #define BSW_START_SEC_VAR_CLEARED_16
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_VAR_CLEARED_16
    #undef FLS_STOP_SEC_VAR_CLEARED_16
    #define BSW_STOP_SEC_VAR_CLEARED_16
    #include "Bsw_MemMap.h"
#elif defined FLS_START_SEC_VAR_CLEARED_32
    #undef FLS_START_SEC_VAR_CLEARED_32
    #define BSW_START_SEC_VAR_CLEARED_32
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_VAR_CLEARED_32
    #undef FLS_STOP_SEC_VAR_CLEARED_32
    #define BSW_STOP_SEC_VAR_CLEARED_32
    #include "Bsw_MemMap.h"
#elif defined FLS_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef FLS_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_START_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef FLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"

/* Variables that are reset to initial value after every reset */
#elif defined FLS_START_SEC_VAR_INIT_BOOLEAN
    #undef FLS_START_SEC_VAR_INIT_BOOLEAN
    #define BSW_START_SEC_VAR_INIT_8
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_VAR_INIT_BOOLEAN
    #undef FLS_STOP_SEC_VAR_INIT_BOOLEAN
    #define BSW_STOP_SEC_VAR_INIT_8
    #include "Bsw_MemMap.h"
#elif defined FLS_START_SEC_VAR_INIT_8
    #undef FLS_START_SEC_VAR_INIT_8
    #define BSW_START_SEC_VAR_INIT_8
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_VAR_INIT_8
    #undef FLS_STOP_SEC_VAR_INIT_8
    #define BSW_STOP_SEC_VAR_INIT_8
    #include "Bsw_MemMap.h"
#elif defined FLS_START_SEC_VAR_INIT_16
    #undef FLS_START_SEC_VAR_INIT_16
    #define BSW_START_SEC_VAR_INIT_16
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_VAR_INIT_16
    #undef FLS_STOP_SEC_VAR_INIT_16
    #define BSW_STOP_SEC_VAR_INIT_16
    #include "Bsw_MemMap.h"
#elif defined FLS_START_SEC_VAR_INIT_32
    #undef FLS_START_SEC_VAR_INIT_32
    #define BSW_START_SEC_VAR_INIT_32
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_VAR_INIT_32
    #undef FLS_STOP_SEC_VAR_INIT_32
    #define BSW_STOP_SEC_VAR_INIT_32
    #include "Bsw_MemMap.h"
#elif defined FLS_START_SEC_VAR_INIT_UNSPECIFIED
    #undef FLS_START_SEC_VAR_INIT_UNSPECIFIED
    #define BSW_START_SEC_VAR_INIT_UNSPECIFIED
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_INIT_UNSPECIFIED
    #include "Bsw_MemMap.h"

/*
 **********************************************************************************************************************
 * Constants mapping
 **********************************************************************************************************************
*/
/* Global or static Constants */
#elif defined FLS_START_SEC_CONST_8
    #undef FLS_START_SEC_CONST_8
    #define BSW_START_SEC_CONST_8
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_CONST_8
    #undef FLS_STOP_SEC_CONST_8
    #define BSW_STOP_SEC_CONST_8
    #include "Bsw_MemMap.h"
#elif defined FLS_START_SEC_CONST_16
    #undef FLS_START_SEC_CONST_16
    #define BSW_START_SEC_CONST_16
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_CONST_16
    #undef FLS_STOP_SEC_CONST_16
    #define BSW_STOP_SEC_CONST_16
    #include "Bsw_MemMap.h"
#elif defined FLS_START_SEC_CONST_32
    #undef FLS_START_SEC_CONST_32
    #define BSW_START_SEC_CONST_32
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_CONST_32
    #undef FLS_STOP_SEC_CONST_32
    #define BSW_STOP_SEC_CONST_32
    #include "Bsw_MemMap.h"
/* Fls Const (ROM): unspecified size */
#elif defined FLS_START_SEC_CONST_UNSPECIFIED
    #undef FLS_START_SEC_CONST_UNSPECIFIED
    #define BSW_START_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_CONST_UNSPECIFIED
    #undef FLS_STOP_SEC_CONST_UNSPECIFIED
    #define BSW_STOP_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"


/*
 **********************************************************************************************************************
 * Code mapping
 **********************************************************************************************************************
*/
/* Code located in normal code section (not defined by Autosar!) */

#elif defined FLS_START_SEC_CODE
    #undef FLS_START_SEC_CODE
    #define  BSW_START_SEC_CODE
    #include "Bsw_MemMap.h"
#elif defined FLS_STOP_SEC_CODE
    #undef FLS_STOP_SEC_CODE
    #define  BSW_STOP_SEC_CODE
    #include "Bsw_MemMap.h"

/*********************************************************************************************************************/
#else
    #error "Fls_MemMap.h: Unknown MemMap #define"
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


