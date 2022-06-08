/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/





/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */
 /*TRACE[WDGIF003] WdgIf shall not add functionality not abstract from properties from watchdog drivers*/
#include "WdgIf.h"

#if (WDGIF_DEV_ERROR_DETECT==STD_ON)
#include "Det.h"
#if (!defined(DET_AR_RELEASE_MAJOR_VERSION) || (DET_AR_RELEASE_MAJOR_VERSION != 4))
#error “AUTOSAR major version undefined or mismatched?
#endif
#if (!defined(DET_AR_RELEASE_MINOR_VERSION) || (DET_AR_RELEASE_MINOR_VERSION != 2))
#error “AUTOSAR minor version undefined or mismatched?
#endif
#endif /*(WDGIF_DEV_ERROR_DETECT==STD_ON)*/



 /*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
 */


 /*
 ***************************************************************************************************
 * Function Definitions
 ***************************************************************************************************
 */







