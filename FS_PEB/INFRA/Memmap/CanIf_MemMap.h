

/* MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 3 */

/* MISRA RULE 19.15 VIOLATION: This file is required for Memory mapping       */
#define MEMMAP_ERROR

/* ============================   BSW   ============================ */

/*----------------------------------------------------------------------------*/
/* Constants with attributes that show that they reside in one segment for module configuration. */
/* Mostly for the Post Build modules and for the Configuration Data */
/* But right now it is unused as we support only selectable not loadable in Post Build */


/*----------------------------------------------------------------------------*/
/* To be used for calibration */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* To be used for global or static constants */
/* All generated constant variables */
/*----------------------------------------------------------------------------*/

/* To be used for PBL to pre-compile conversion when pre-compile variant is used */

#if ( CANIF_VARIANT_INFO == 1 )

/* If Module is Pre-Compile, then map Post-Build MemMap to Pre-Compile MemMap */
# if defined CANIF_START_SEC_CONFIG_DATA_POSTBUILD_32
#  undef CANIF_START_SEC_CONFIG_DATA_POSTBUILD_32
#  define CANIF_START_SEC_CONST_32
# elif defined CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_32
#  undef  CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_32
#  define CANIF_STOP_SEC_CONST_32

# elif defined CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#  undef CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#  define CANIF_START_SEC_CONST_UNSPECIFIED
# elif defined CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#  undef  CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#  define CANIF_STOP_SEC_CONST_UNSPECIFIED

# elif defined CANIF_START_SEC_VAR_CLEARED_POSTBUILD_8
#  undef CANIF_START_SEC_VAR_CLEARED_POSTBUILD_8
#  define CANIF_START_SEC_VAR_CLEARED_8
# elif defined CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#  undef CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#  define CANIF_STOP_SEC_VAR_CLEARED_8

# elif defined CANIF_START_SEC_VAR_CLEARED_POSTBUILD_16
#  undef CANIF_START_SEC_VAR_CLEARED_POSTBUILD_16
#  define CANIF_START_SEC_VAR_CLEARED_16
# elif defined CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_16
#  undef CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_16
#  define CANIF_STOP_SEC_VAR_CLEARED_16

# elif defined CANIF_START_SEC_VAR_CLEARED_POSTBUILD_32
#  undef CANIF_START_SEC_VAR_CLEARED_POSTBUILD_32
#  define CANIF_START_SEC_VAR_CLEARED_32
# elif defined CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_32
#  undef CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_32
#  define CANIF_STOP_SEC_VAR_CLEARED_32

# elif defined CANIF_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#  undef CANIF_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#  define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
# elif defined CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#  undef CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#  define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED

# endif

# endif
/* To be used for PBL to pre-compile conversion when pre-compile variant is used */

#if defined CANIF_START_SEC_CONST_BOOLEAN
    #define BSW_START_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_CONST_BOOLEAN
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_CONST_BOOLEAN
    #define BSW_STOP_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_CONST_BOOLEAN
    #undef MEMMAP_ERROR

#elif defined CANIF_START_SEC_CONST_8
    #define BSW_START_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_CONST_8
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_CONST_8
    #define BSW_STOP_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR



/* Unspecified size */
#elif defined CANIF_START_SEC_CONST_UNSPECIFIED
    #define BSW_START_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_CONST_UNSPECIFIED
    #define BSW_STOP_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #define BSW_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #define BSW_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
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
#elif defined CANIF_START_SEC_VAR_CLEARED_BOOLEAN
    /*  BOOLEAN */
    #define BSW_START_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_VAR_CLEARED_BOOLEAN
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define BSW_STOP_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef MEMMAP_ERROR


/* PBL RAM section - boolean - start*/
#elif defined CANIF_START_SEC_VAR_CLEARED_POSTBUILD_BOOLEAN
    /*  BOOLEAN */
    #define BSW_START_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_VAR_CLEARED_POSTBUILD_BOOLEAN
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_BOOLEAN
    #define BSW_STOP_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_BOOLEAN
    #undef MEMMAP_ERROR
/* PBL RAM section - boolean - end*/

#elif defined CANIF_START_SEC_VAR_CLEARED_8
    /*  8 bit */
    #define BSW_START_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_VAR_CLEARED_8
    #define BSW_STOP_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR

/*  PBL RAM section - 8 bit start*/
#elif defined CANIF_START_SEC_VAR_CLEARED_POSTBUILD_8
    /*  8 bit */
    #define BSW_START_SEC_VAR_CLEARED_POSTBUILD_8
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_VAR_CLEARED_POSTBUILD_8
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_8
    #define BSW_STOP_SEC_VAR_CLEARED_POSTBUILD_8
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_8
    #undef MEMMAP_ERROR
/*  PBL RAM section - 8 bit end*/

/*  PBL RAM section - 32 bit start*/
#elif defined CANIF_START_SEC_VAR_CLEARED_POSTBUILD_32
    /* 32 bit */
    #define BSW_START_SEC_VAR_CLEARED_POSTBUILD_32
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_VAR_CLEARED_POSTBUILD_32
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_32
    #define BSW_STOP_SEC_VAR_CLEARED_POSTBUILD_32
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_32
    #undef MEMMAP_ERROR
/*  PBL RAM section - 32 bit end*/

#elif defined CANIF_START_SEC_VAR_CLEARED_32
    /* 32 bit */
    #define BSW_START_SEC_VAR_CLEARED_32
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_VAR_CLEARED_32
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_VAR_CLEARED_32
    #define BSW_STOP_SEC_VAR_CLEARED_32
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_VAR_CLEARED_32
    #undef MEMMAP_ERROR

#elif defined CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
    /* UNSPECIFIED */
    #define BSW_START_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR

/* PBL RAM - UNSPECIFIED - start */
#elif defined CANIF_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
    /* UNSPECIFIED */
    #define BSW_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
    #undef MEMMAP_ERROR

/* PBL RAM - UNSPECIFIED - end */

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


#elif defined CANIF_START_SEC_VAR_FAST_CLEARED_8
    #define BSW_START_SEC_VAR_FAST_CLEARED_8
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_VAR_FAST_CLEARED_8
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_VAR_FAST_CLEARED_8
    #define BSW_STOP_SEC_VAR_FAST_CLEARED_8
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_VAR_FAST_CLEARED_8
    #undef MEMMAP_ERROR
#elif defined CANIF_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #define BSW_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR

/*-----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* DEFAULT              normal or slow access       cyclic variable >= 10ms  */
/*----------------------------------------------------------------------------*/
#elif defined CANIF_START_SEC_CODE
    #define  BSW_START_SEC_CODE
    #include "Bsw_MemMap.h"
    #undef CANIF_START_SEC_CODE
    #undef MEMMAP_ERROR
#elif defined CANIF_STOP_SEC_CODE
    #define  BSW_STOP_SEC_CODE
    #include "Bsw_MemMap.h"
    #undef CANIF_STOP_SEC_CODE
    #undef MEMMAP_ERROR

/* Code that shall go into fast code memory segments */

#elif defined (CANIF_START_SEC_CODE_FAST)
  #define BSW_START_SEC_CODE_FAST
  #include "Bsw_MemMap.h"
  #undef CANIF_START_SEC_CODE_FAST
  #undef MEMMAP_ERROR
#elif defined (CANIF_STOP_SEC_CODE_FAST)
  #define BSW_STOP_SEC_CODE_FAST
  #include "Bsw_MemMap.h"
  #undef CANIF_STOP_SEC_CODE_FAST
  #undef MEMMAP_ERROR

#elif defined MEMMAP_ERROR
    #error "CANIF_MemMap.h, wrong #pragma command"
#endif

/*<BASDKey>
*********************************************************************************************************
* $History___:
*
* 14.09.00_COMMON; 0     25.08.2014 NNR6KOR
*   GIT to BASD Transfer:
*   Tag:BASD_TRANSFER_14.09.00_#1
*   SHA1 Id:5149885dabb89dcf8fd64b2a2b44194e48864615
*
* $
*********************************************************************************************************
</BASDKey>*/
