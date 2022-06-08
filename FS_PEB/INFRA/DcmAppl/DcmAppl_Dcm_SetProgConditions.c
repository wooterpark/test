
#include "DcmCore_DslDsd_Inf.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/
#if(DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)

#include "FlsLoader.h"
#include "FlsLoader_Cfg.h"


#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define FBL_PROG_FLAG_ADDR			0xAF05E003
#define DF0_SECTOR_SIZE				0x2000 /* 8KB, also reserve 8KB of RAM for sector back up */
#define FBL_SECTOR_BACKUP_SIZE		0x100 /* 256 bytes */
#define PROG_FLAG_VALUE				0x2A


/**
 * @ingroup DCM_TPL
 * Dcm_SetProgConditions :-\n
 * This API is used for Setting the Programming Information in the application.This API should take a copy of the Programming conditions given by Dcm to the Non volaitile memory.\n
 * This information will be restored again during Jump from Boot.\n
 *
 ** @param[in]       ProgConditions  : Pointer to the location where the programming conditions are stored.\n
 *  The information available to this API which needs to be stored are\n
 *     1. ProtocolID - protocol which needs to be started as default\n
 *     2. Tester Source address - Connection will be derived from this input\n
 *     3. SID - service identifier (In case of Warm request/Warm response)\n
 *     4. SubFncId - Sub function ID\n
 *     5. StoreType - Storage Type used for restoring, Warm Request/Warm Response/Warm Init\n
 *     6. SessionLevel - Session level which needs to be started\n
 *     7. SecurityLevel - Security level which needs to be started\n
 *     8. ReqResLen - Total request/response length including SID and Sub func\n
 *     9. Request/Response bytes which follows the SID and Sub func\n
 *     10.Number of Response pending 0x78 triggered before the jump\n
 *     11.Elapsed time in Drive or Boot\n
 *     12. NumOfSecurityLevels - Number of security levels configured
 *           If the configuration parameter DcmDspSecurityStoreDelayCountAndTimerOnJump  is set to True, then the below information has to be stored
 *     13. SecurityInformation[].SecurityLevel = Security level
 *     14.SecurityInformation[].DelayCount = The failed attempt count per SecurityLevel
 *     15.SecurityInformation[].ResidualDelay = Remaining delay (either remaining powerOndelay/remaining delay time) per SecurityLevel which will be started in Dcm per security level
 *     16.freeForProjectUse 6 bytes of free space is provided for projects to store additional information like CAN ID, BAUD Rate, etc..\n
 *
 * @param[in]       Opstatus        : Information on the opstatus\n
 * @param[out]      None
 * @retval          E_OK            : Storing is sucessful\n
 * @retval          DCM_E_PENDING   : Need more time for Storing\n
 * @retval          E_NOT_OK        : Storing is unsucessful\n
 * @retval          DCM_E_FORCE_RCRRP : Application requests the transmission of a response Response Pending (NRC 0x78)\n
 *
 */

#pragma GCC push_options
#pragma GCC optimize ("O0")


FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_SetProgConditions(VAR(Dcm_OpStatusType,AUTOMATIC) OpStatus,
                                                        P2CONST(Dcm_ProgConditionsType,AUTOMATIC,DCM_INTERN_DATA) ProgConditions)
{
#if 0
	FlsLoader_ReturnType flsRetVal;
#endif
	Std_ReturnType retVal = E_OK;
#if 0
	/* first initialize the flash loader */
	FlsLoader_Init(NULL_PTR);

	 /* get address of programming flag relatively to DF0 base addr */
	uint32 relative_addr = FBL_PROG_FLAG_ADDR - FLSLOADER_DFLASH0_START_ADDRESS;

	/* get the index of the sector in which the programming flag lies */
	uint8 sector_idx = (uint8)(relative_addr/DF0_SECTOR_SIZE);

	/* start address (absolute) of the sector */
	uint32 sector_start_addr = sector_idx * DF0_SECTOR_SIZE + FLSLOADER_DFLASH0_START_ADDRESS;

	/* offset of programming flag inside the sector */
	uint32 offset = relative_addr - sector_idx * DF0_SECTOR_SIZE;

	/* back up the sector that contains programming flag to RAM
	 * size = 256 bytes
	 * an 1KB area on RAM is already reserved for this purpose */
	rta_bsw_BswSrv_MemCopy((void*)&FBL_SECTOR_BACKUP_START, (void*)sector_start_addr, FBL_SECTOR_BACKUP_SIZE);

	/* set the programming flag to 0x2A */
	uint8* ptr_to_pf = (uint8*)(&FBL_SECTOR_BACKUP_START) + offset;

	*ptr_to_pf = PROG_FLAG_VALUE;

	/* clear the specified sector, this call is synchronous */
	flsRetVal = FlsLoader_Erase(sector_start_addr, (FlsLoader_LengthType)1);
	/* re-write the sector, with the programming flag set */
	if(flsRetVal == FLSLOADER_E_OK)
	{
		flsRetVal = FlsLoader_Write(sector_start_addr, (FlsLoader_LengthType)FBL_SECTOR_BACKUP_SIZE, (uint8*)&FBL_SECTOR_BACKUP_START);
	}

	if(flsRetVal == FLSLOADER_E_OK)
	{
		retVal = E_OK;
	}
	else
	{
		retVal = E_NOT_OK;
	}
#endif
	return retVal;
}

#pragma GCC pop_options
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#endif

