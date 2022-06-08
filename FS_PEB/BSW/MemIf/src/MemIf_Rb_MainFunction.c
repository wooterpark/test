

#include "MemIf.h"
#include "MemIf_Cfg_SchM.h"

#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#if (!defined(DET_AR_RELEASE_MAJOR_VERSION) || (DET_AR_RELEASE_MAJOR_VERSION != MEMIF_AR_RELEASE_MAJOR_VERSION))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(DET_AR_RELEASE_MINOR_VERSION) || ((DET_AR_RELEASE_MINOR_VERSION != 0) && (DET_AR_RELEASE_MINOR_VERSION != 2)))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif

#define MEMIF_START_SEC_CODE
#include "MemIf_MemMap.h"

/**
 *********************************************************************
 * MemIf_Rb_MainFunction(): Calls requiered underlaying
 *                          Mainfunctions.
 *
 * The function calls the required underlaying main functions,
 * depending on which modules are configured.
 *
 * \param    none
 * \retval   none
 * \seealso
 * \usedresources
 *********************************************************************
 */
FUNC(void, MEMIF_CODE) MemIf_Rb_MainFunction(void)
{
    #if (MEMIF_FEE_USED == STD_ON)
    Fee_MainFunction();
    Fls_MainFunction();
    #endif
    #if (MEMIF_NUM_OF_EA_DEVICES > 0)
    Ea_MainFunction();
    Eep_MainFunction();
    Spi_MainFunction_Handling();
    #endif
}


#if (MEMIF_FEE_AND_EA_USED == STD_ON)
/**
 *********************************************************************
 * MemIf_Rb_BlockMaintenance(): Calls corresponding block maintenance functions.
 *
 * The function calls the required underlying block maintenance functions,
 * depending on which modules are configured.
 *
 * \param    Block number
 * \retval   E_OK:      Order was accepted
 * \retval   E_NOT_OK:  Order was not accepted.
 * \seealso
 * \usedresources
 *********************************************************************
 */
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Rb_BlockMaintenance(VAR(uint8, AUTOMATIC) DeviceIndex, VAR(uint16, AUTOMATIC) BlockNumber)
{
    VAR(Std_ReturnType,AUTOMATIC) xRetVal = E_NOT_OK;       /* Default return value */

    #if (MEMIF_DEV_ERROR_DETECT == STD_ON)
    MemIf_CheckDeviceIndex(DeviceIndex);
    #endif

    if (DeviceIndex == 0)
    {
        xRetVal = Fee_Rb_BlockMaintenance(BlockNumber);
    }
    else
    {
        xRetVal = Ea_Rb_BlockMaintenance(BlockNumber);
    }
    return(xRetVal);
}
#endif

#if (MEMIF_FEE_AND_EA_USED == STD_ON)
/**
 *********************************************************************
 * MemIf_VarLenRead(): MemIf_VarLenRead interface
 *
 * This function places a read job to the FEE when runtime RAM block
 * configuration feature is enabled and the block length is variable.
 *
 * \param    DeviceIndex:   Index of requeste device
 * \param    Blocknumber:   Nvm index (based on this index the
 *                          corresponding Fee index will be searched
 *                          and placed into the order queue)
 * \param    BlockOffset:   Offset of block
 * \param    DataBufferPtr: Pointer to data buffer
 * \param    Length:        Length of block
 * \return   Function success
 * \retval   E_OK:              Order was successfully placed
 * \retval   E_NOT_OK:          Order was not placed because the
 *                              respective order queue entry is
 *                              not empty or the module has not been
 *                              initialized yet
 * \seealso
 * \usedresources
 *********************************************************************
 */
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Rb_VarLenRead(VAR(uint8, AUTOMATIC) DeviceIndex, VAR(uint16, AUTOMATIC) BlockNumber, VAR(uint16, AUTOMATIC) BlockOffset, P2VAR(uint8, AUTOMATIC, MEMIF_DATA) DataBufferPtr, VAR(uint16, AUTOMATIC) Length)
{
    VAR(Std_ReturnType,AUTOMATIC) xRetVal = E_NOT_OK;       /* Default return value */

#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
    MemIf_CheckDeviceIndex(DeviceIndex);
#endif

#if (MEMIF_FEE_USED == STD_ON)
    if (DeviceIndex == 0)
    {
        /* Block is configured for Fee (Flash) */
        xRetVal = Fee_Rb_VarLenRead(BlockNumber,BlockOffset,DataBufferPtr,Length);
    }
#endif

#if (MEMIF_NUM_OF_EA_DEVICES > 0)
    if (DeviceIndex > 0)
    {
        /* Block is configured for Ea (EEPROM) */
        /* Feature not yet available */
    }
#endif

    return(xRetVal);
}
#endif

#if (MEMIF_FEE_AND_EA_USED == STD_ON)
/**
 *********************************************************************
 * MemIf_Rb_VarLenWrite(): MemIf_Rb_VarLenWrite interface
 *
 * This function places a write job to the FEE when runtime RAM block
 * configuration feature is enabled and the block length is variable.
 *
 * \param    DeviceIndex:   Index of requested device
 * \param    Blocknumber:   Nvm index (based on this index the
 *                          corresponding Fee index will be searched
 *                          and placed into the order queue)
 * \param    DataBufferPtr: Pointer Pointer to data buffer
 * \param    Length:        NV block length
 * \return   Function success
 * \retval   E_OK:              Order was successfully placed
 * \retval   E_NOT_OK:          Order was not placed because the
 *                              respective order queue entry is
 *                              not empty or the module has not been
 *                              initialized yet
 * \seealso
 * \usedresources
 *********************************************************************
 */
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Rb_VarLenWrite(VAR(uint8, AUTOMATIC) DeviceIndex, VAR(uint16, AUTOMATIC) BlockNumber, P2VAR(uint8, AUTOMATIC, MEMIF_DATA) DataBufferPtr, VAR(uint16, AUTOMATIC) Length)
{
    VAR(Std_ReturnType,AUTOMATIC) xRetVal = E_NOT_OK;   /* Default return value */

#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
    MemIf_CheckDeviceIndex(DeviceIndex);
#endif

#if (MEMIF_FEE_USED == STD_ON)
    if (DeviceIndex == 0)
    {
        /* Block is configured for Fee (Flash) */
        xRetVal = Fee_Rb_VarLenWrite(BlockNumber,DataBufferPtr,Length);
    }
#endif

#if (MEMIF_NUM_OF_EA_DEVICES > 0)
    if (DeviceIndex > 0)
    {
        /* Block is configured for Ea (EEPROM) */
        /* Feature not yet available */
    }
#endif

    return(xRetVal);
}
#endif

#if (MEMIF_FEE_AND_EA_USED == STD_ON)
/**
 *********************************************************************
 * MemIf_Rb_GetMigrationResult(): MemIf_Rb_GetMigrationResult interface
 *
 * Service returns the migration result of the last data reading
 * during initialisation (calling the API after subsequent read jobs
 * in the same driving cycle does not change the initially returned
 * value anymore).
 *
 * \param    DeviceIndex:   Index of requested device
 * \param    BlockNumber:   Corresponding Fee or Ea block number
 *
 * \retval   MEMIF_RB_MIGRATION_RESULT_INIT_E
 * \retval   MEMIF_RB_MIGRATION_RESULT_NOT_NECESSARY_E
 * \retval   MEMIF_RB_MIGRATION_RESULT_TO_SMALLER_SIZE_E
 * \retval   MEMIF_RB_MIGRATION_RESULT_TO_BIGGER_SIZE_E
 * \retval   MEMIF_RB_MIGRATION_RESULT_NOT_DONE_E
 * \retval   MEMIF_RB_MIGRATION_RESULT_DEACTIVATED_E
 *
 * \seealso
 * \usedresources
 *********************************************************************
 */
FUNC(MemIf_Rb_MigrationResult_ten, MEMIF_CODE) MemIf_Rb_GetMigrationResult(VAR(uint8, AUTOMATIC) DeviceIndex,
                                                                           VAR(uint16, AUTOMATIC) BlockNumber)
{
    VAR(MemIf_Rb_MigrationResult_ten, AUTOMATIC) xRetVal = MEMIF_RB_MIGRATION_RESULT_INIT_E;  /* Default return value */

#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
    MemIf_CheckDeviceIndex(DeviceIndex);
#endif

#if (MEMIF_FEE_USED == STD_ON)
    if (DeviceIndex == 0)
    {
        /* Block is configured for Fee (Flash) */
        xRetVal = Fee_Rb_GetMigrationResult(BlockNumber);
    }
#endif

#if (MEMIF_NUM_OF_EA_DEVICES > 0)
    if (DeviceIndex > 0)
    {
        /* Block is configured for Ea (EEPROM) */
        /* Feature not yet available */
    }
#endif

    return(xRetVal);
}
#endif

#define MEMIF_STOP_SEC_CODE
#include "MemIf_MemMap.h"

