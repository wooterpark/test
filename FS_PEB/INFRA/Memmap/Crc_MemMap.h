/*
**********************************************************************************************************************
* Includes
**********************************************************************************************************************
*/


/*
**********************************************************************************************************************
* Defines/Macros
**********************************************************************************************************************
*/
/* Crc_MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 1-2 */

/*
**********************************************************************************************************************
The following section checks which of the preprocessor constants are defined for
the memory layout. Each .c file will do the following for each function 
definition:

1. define the CRC_START_SEC_<type> 
2. include this file 
3. define the function itself
4. define CRC_STOP_SEC_<type> after the function, 
5. include this file again.

There are two options for layout definitions in this file:

1. The standard Memmap concept using a central definition in another file. 
   Projects that do not use the CUBAS SW, In the case of a project using the 
   CUBAS SW, the BSW memmap header file will be available e.g.
       
        #if defined CRC_START_SEC_<section name>
            #define  BSW_START_SEC_<section name>
            #include "Bsw_MemMap.h"
            #undef CRC_START_SEC_<section name>

2. Alternatively, the definition can be made directly in Crc with a #pragma e.g.
    
        #elif defined (CRC_START_SEC_<section name>)
           #undef      CRC_START_SEC_<section name>
           #pragma section ".text.bsw" ax

There are many different section names possible. Only those currently used in the
Crc module are defined below.
**********************************************************************************************************************
*/

/* Default code section */
/* MISRA RULE 19.15 VIOLATION: MemMap header concept - no protection against repeated inclusion intended */
#if defined CRC_START_SEC_CODE
    #define  BSW_START_SEC_CODE
    #include "Bsw_MemMap.h"
    #undef CRC_START_SEC_CODE
    
#elif defined CRC_STOP_SEC_CODE
    #define  BSW_STOP_SEC_CODE
    #include "Bsw_MemMap.h"
    #undef CRC_STOP_SEC_CODE

/* Constants which allocate 64 bits */
#elif defined CRC_START_SEC_CONST_64
    #define BSW_START_SEC_CONST_32
    #include "Bsw_MemMap.h"
    #undef CRC_START_SEC_CONST_64
#elif defined CRC_STOP_SEC_CONST_64
    #define BSW_STOP_SEC_CONST_32
    #include "Bsw_MemMap.h"
    #undef CRC_STOP_SEC_CONST_64

/* Constants which allocate 32 bits */
#elif defined CRC_START_SEC_CONST_32
    #define BSW_START_SEC_CONST_32
    #include "Bsw_MemMap.h"
    #undef CRC_START_SEC_CONST_32
#elif defined CRC_STOP_SEC_CONST_32
    #define BSW_STOP_SEC_CONST_32
    #include "Bsw_MemMap.h"
    #undef CRC_STOP_SEC_CONST_32    

/* Constants which allocate 16 bits */     
#elif defined CRC_START_SEC_CONST_16
    #define BSW_START_SEC_CONST_16
    #include "Bsw_MemMap.h"
    #undef CRC_START_SEC_CONST_16
#elif defined CRC_STOP_SEC_CONST_16
    #define BSW_STOP_SEC_CONST_16
    #include "Bsw_MemMap.h"
    #undef CRC_STOP_SEC_CONST_16     

/* Constants which allocate 8 bits */     
#elif defined CRC_START_SEC_CONST_8
    #define BSW_START_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef CRC_START_SEC_CONST_8
#elif defined CRC_STOP_SEC_CONST_8
    #define BSW_STOP_SEC_CONST_8
    #include "Bsw_MemMap.h"
    #undef CRC_STOP_SEC_CONST_8
    
#elif defined TESTCD_CRC_START_SEC_CODE
    #define  BSW_START_SEC_CODE
    #include "Bsw_MemMap.h"
    #undef TESTCD_CRC_START_SEC_CODE
#elif defined TESTCD_CRC_STOP_SEC_CODE
    #define  BSW_STOP_SEC_CODE
    #include "Bsw_MemMap.h"
    #undef TESTCD_CRC_STOP_SEC_CODE

#else
    #error "No valid memmap constant defined before including Crc_MemMap.h"
#endif

/*
**********************************************************************************************************************
* Type definitions
**********************************************************************************************************************
*/


/*
**********************************************************************************************************************
* Variables
**********************************************************************************************************************
*/


/*
**********************************************************************************************************************
* Extern declarations
**********************************************************************************************************************
*/

