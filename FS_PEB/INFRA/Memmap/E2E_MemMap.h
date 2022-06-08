/*<BASDKey>
**********************************************************************************************************************
*
* COPYRIGHT RESERVED, Robert Bosch GmbH, 2013. All rights reserved.
* The reproduction, distribution and utilization of this document as well as the communication of its contents to
* others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
* All rights reserved in the event of the grant of a patent, utility model or design.
*
**********************************************************************************************************************
* Administrative Information (automatically filled in)
* $Domain____:BASD$
* $Namespace_:\Deliveries\DGS_MDG1$
* $Class_____:H$
* $Name______:E2E_MemMap$
* $Variant___:13.11.00_COMMON$
* $Revision__:0$
**********************************************************************************************************************
</BASDKey>*/


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
/* MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 1-2 */

/*
**********************************************************************************************************************
The following section checks which of the preprocessor constants are defined for
the memory layout. Each .c file will do the following for each function 
definition:

1. define the E2E_START_SEC_<type> 
2. include this file 
3. define the function itself
4. define E2E_STOP_SEC_<type> after the function, 
5. include this file again.

There are two options for layout definitions in this file:

1. The standard Memmap concept using a central definition in another file. 
   Projects that do not use the CUBAS SW, In the case of a project using the 
   CUBAS SW, the BSW memmap header file will be available e.g.
       
        #if defined E2E_START_SEC_<section name>
            #define  BSW_START_SEC_DEFAULT_<section name>
            #include "Bsw_MemMap.h"
            #undef E2E_START_SEC_<section name>

2. Alternatively, the definition can be made directly in E2E with a #pragma e.g.
    
        #elif defined (E2E_START_SEC_<section name>)
           #undef      E2E_START_SEC_<section name>
           #pragma section ".text.bsw" ax

There are many different section names possible. Only those currently used in the
E2E module are defined below.
**********************************************************************************************************************
*/

/* Default code section */
/* MISRA RULE 19.15 VIOLATION: MemMap header concept - no protection against repeated inclusion intended */
#if defined E2E_START_SEC_CODE
    #define  BSW_START_SEC_DEFAULT_CODE
    #include "Bsw_MemMap.h"
    #undef E2E_START_SEC_CODE
    
#elif defined E2E_STOP_SEC_CODE
    #define  BSW_STOP_SEC_DEFAULT_CODE
    #include "Bsw_MemMap.h"
    #undef E2E_STOP_SEC_CODE

#else
    //#error "No valid memmap constant defined before including E2E_MemMap.h"
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

/*<BASDKey>
**********************************************************************************************************************
* $History___:
* 
* 13.11.00_COMMON; 0     25.11.2013 PBR4KOR
*   GIT Synchronization:
*   Tag: BASD_TRANSFER_13.11.00_2
*   SHA1 Id:  d8b8512618fd76bae32fb38cbf616f5e1114d6e2
* 
* $
**********************************************************************************************************************
</BASDKey>*/

/*<BASDKey>
**********************************************************************************************************************
* End of header file: $Name______:E2E_MemMap$
**********************************************************************************************************************
</BASDKey>*/

