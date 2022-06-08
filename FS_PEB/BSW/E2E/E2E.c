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
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "E2E.h"

/*
 **********************************************************************************************************************
 Auxiliary functions
 **********************************************************************************************************************
*/
/**
*******************************************************************************************************************
* E2E_GetVersionInfo
*
* \brief private routine to spend information about the version of the library
*
* Description:
*
* Restrictions:
*   -
*
* Dependencies:
*   -
*
* Resources:
*   -
*
* \param   Std_VersionInfoType *VersionInfo  Pointer to the version structure
* \return  void
*
*******************************************************************************************************************
*/
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"

void E2E_GetVersionInfo(Std_VersionInfoType * VersionInfo_pst)
{
    VersionInfo_pst->vendorID = E2E_VENDOR_ID;
    VersionInfo_pst->moduleID = E2E_MODULE_ID;
    VersionInfo_pst->sw_major_version = E2E_SW_MAJOR_VERSION;
    VersionInfo_pst->sw_minor_version = E2E_SW_MINOR_VERSION;
    VersionInfo_pst->sw_patch_version=  E2E_SW_PATCH_VERSION;
}

#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"
