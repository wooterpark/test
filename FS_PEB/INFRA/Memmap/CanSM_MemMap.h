

/* MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 3 */
/* MISRA RULE 19.15 VIOLATION: This file is required for Memory mapping       */
#define MEMMAP_ERROR

/* ============================   BSW   ============================ */

/*----------------------------------------------------------------------------*/
/* Constants with attributes that show that they reside in one segment for module configuration. */
/* Mostly for the Post Build modules and for the Configuration Data */
/* But right now it is unsed as we support only selectable not loadable in Post Build */


/*----------------------------------------------------------------------------*/
/* To be used for calibration */
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* To be used for global or static constants */
/* All generated constant variables */
/*----------------------------------------------------------------------------*/



#if defined CANSM_START_SEC_CONST_8
    #define BSW_START_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef CANSM_START_SEC_CONST_8
    #undef MEMMAP_ERROR
#elif defined CANSM_STOP_SEC_CONST_8
    #define BSW_STOP_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef CANSM_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR


#elif defined CANSM_START_SEC_CONST_BOOLEAN
    #define BSW_START_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef CANSM_START_SEC_CONST_BOOLEAN
    #undef MEMMAP_ERROR
#elif defined CANSM_STOP_SEC_CONST_BOOLEAN
    #define BSW_STOP_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef CANSM_STOP_SEC_CONST_BOOLEAN
    #undef MEMMAP_ERROR



#elif defined CANSM_START_SEC_CONST_UNSPECIFIED
    /* Unspecified size */
    #define BSW_START_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANSM_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANSM_STOP_SEC_CONST_UNSPECIFIED
    #define BSW_STOP_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANSM_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR

/*----------------------------------------------------------------------------*/
/* To be used for RAM buffers of variables saved in non volatile memory. */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* To be used for all global or static variables that are never initialized. */
/* NOT USED */
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* used for variables that are never cleared and never initialized */
/* NOT USED */
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/

/* Used for global or static variables that are
    cleared to zero after every reset */
#elif defined CANSM_START_SEC_VAR_CLEARED_BOOLEAN
    /*  BOOLEAN */
    #define BSW_START_SEC_VAR_CLEARED_8  
    #include "Bsw_MemMap.h"
    #undef CANSM_START_SEC_VAR_CLEARED_BOOLEAN
    #undef MEMMAP_ERROR
#elif defined CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define BSW_STOP_SEC_VAR_CLEARED_8 
    #include "Bsw_MemMap.h"
    #undef CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef MEMMAP_ERROR

#elif defined CANSM_START_SEC_VAR_CLEARED_8
    /*  8 bit */
    #define BSW_START_SEC_VAR_CLEARED_8 
    #include "Bsw_MemMap.h"
    #undef CANSM_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR
#elif defined CANSM_STOP_SEC_VAR_CLEARED_8
    #define BSW_STOP_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
    #undef CANSM_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR

#elif defined CANSM_START_SEC_VAR_CLEARED_16
    /*  16 bit */
    #define BSW_START_SEC_VAR_CLEARED_16
    #include "Bsw_MemMap.h"
    #undef CANSM_START_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR
#elif defined CANSM_STOP_SEC_VAR_CLEARED_16
    #define BSW_STOP_SEC_VAR_CLEARED_16  
    #include "Bsw_MemMap.h"
    #undef CANSM_STOP_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR

#elif defined CANSM_START_SEC_VAR_CLEARED_32
    /* 32 bit */
    #define BSW_START_SEC_VAR_CLEARED_32 
    #include "Bsw_MemMap.h"
    #undef CANSM_START_SEC_VAR_CLEARED_32
    #undef MEMMAP_ERROR
#elif defined CANSM_STOP_SEC_VAR_CLEARED_32
    #define BSW_STOP_SEC_VAR_CLEARED_32
    #include "Bsw_MemMap.h"
    #undef CANSM_STOP_SEC_VAR_CLEARED_32
    #undef MEMMAP_ERROR

#elif defined CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
    /* UNSPECIFIED */
    #define BSW_START_SEC_VAR_CLEARED_UNSPECIFIED 
    #include "Bsw_MemMap.h"
    #undef CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR

/*----------------------------------------------------------------------------*/
/* used for variables that are cleared to zero only after power on reset */
/* NOT USED */
/*-----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* used for variables that are initialized with values after every reset */
/* NOT USED */
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* used for variables that are initialized with values only after power on reset */
/* NOT USED */
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* VAR_FAST                for variables which are accessed frequently  */
/*----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* DEFAULT                normal or slow access        cyclic variable >= 10ms  */
/*----------------------------------------------------------------------------*/
#elif defined CANSM_START_SEC_CODE
    #define  BSW_START_SEC_CODE
    #include "Bsw_MemMap.h"
    #undef CANSM_START_SEC_CODE
    #undef MEMMAP_ERROR
#elif defined CANSM_STOP_SEC_CODE
    #define  BSW_STOP_SEC_CODE
    #include "Bsw_MemMap.h"
    #undef CANSM_STOP_SEC_CODE
    #undef MEMMAP_ERROR

/* Code that shall go into fast code memory segments - Scratchpad Memory (SPRAM) */




#elif defined MEMMAP_ERROR
    #error "CANSM_MemMap.h, wrong #pragma command"
#endif


/*<BASDKey>
*********************************************************************************************************
* $History___:$
*********************************************************************************************************
</BASDKey>*/
