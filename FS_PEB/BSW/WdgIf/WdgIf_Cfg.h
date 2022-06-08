/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#ifndef WDGIF_CFG_H
#define WDGIF_CFG_H


/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */





#include "WdgIf_Types.h"

/*
 ***************************************************************************************************
 * Defines
 ***************************************************************************************************
 */

#define WDGIF_DEV_ERROR_DETECT                                       (STD_OFF)
#define WDGIF_VERSION_INFO_API                                       (STD_OFF)
#define WDGIF_NUMBER_OF_DEVICES                                      (1)

/* Symbolic names for Watchdog instances */
#define WdgIfConf_WdgIfDevice_WdgIfExtDev                            ((uint8) (0))

/*
 ***************************************************************************************************
 * Type definitions
 ***************************************************************************************************
 */



/* 	According to WDGIF020 it is a case of single watchdog driver, to have
	efficient mechanisms to map the API calls to the appropriate watchdog
	driver without additional overhead, DeviceIndex is ignored */

#define WdgIf_SetMode(DeviceIndex, WdgMode)  //WdgExtDev_SetMode(WdgMode)/*LQ20201017*/
#define WdgIf_SetTriggerCondition(DeviceIndex, WdgTimeout)  //WdgExtDev_SetTriggerCondition(WdgTimeout)/*LQ20201017*/


/*
***************************************************************************************************
* External declaration
***************************************************************************************************
*/








#endif /*WDGIF_CFG_H*/

