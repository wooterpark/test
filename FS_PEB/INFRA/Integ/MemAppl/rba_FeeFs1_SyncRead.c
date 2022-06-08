
/**
 *********************************************************************
 * Fee_Fls_SyncRead(): Service for synchronous data read
 *
 * This function performed synchronous read data from Data Flash.
 * Below is a template implementation. Integrators shall
 * implement this function in order to match with the target MCAL.
 *
 * \param    SourceAddress:     Relative address of the data to be read in flash memory.
 * 								This address offset will be added to the flash memory base address.
 * \param    TargetAddressPtr:  Pointer to target data buffer.
 * \param    Length:            Length in bytes to be read from Data Flash memory.
 * \return   Function success
 * \retval   E_OK:              Read command has been accepted.
 * \retval   E_NOT_OK:          Read command has not been accepted.
 * \seealso
 * \usedresources
 *********************************************************************
 */
 
 /*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */
/* #ifndef NOT_READY_FOR_TESTING_OR_DEPLOYMENT
#error The content of this file is a template which provides empty stubs. The content of this file must be completed by the integrator accordingly to project specific requirements
#else
#warning The content of this file is a template which provides empty stubs. The content of this file must be completed by the integrator accordingly to project specific requirements
#endif */ /* NOT_READY_FOR_TESTING_OR_DEPLOYMENT */

#include "rba_FeeFs1_SyncRead.h"
#include "Fls_17_Pmu_Cfg.h"
Std_ReturnType Fee_Fls_SyncRead( Fls_AddressType SourceAddress,
                                uint8 *TargetAddressPtr,
                                Fls_LengthType Length
                               )
{
	Std_ReturnType RetVal = E_OK;
	MemIf_JobResultType Fls_JobResult;
	Fls_LengthType tmp_Length;

	if(TargetAddressPtr == NULL_PTR)
	{
		RetVal = E_NOT_OK;
	}
	else if( SourceAddress > FLS_TOTAL_SIZE)
	{
		RetVal = E_NOT_OK;
	}
	else
	{
		if(( SourceAddress + Length ) > FLS_TOTAL_SIZE)
		{
			tmp_Length = FLS_TOTAL_SIZE - SourceAddress;
		}
		else
		{
			tmp_Length = Length;
		}
		RetVal = Fls_Read((Fls_AddressType) SourceAddress, (uint8*)TargetAddressPtr, tmp_Length);
		do{
			Fls_MainFunction();
			Fls_JobResult = Fls_GetJobResult();
		} while(Fls_JobResult == MEMIF_JOB_PENDING);

		if (Fls_JobResult != MEMIF_JOB_OK){
			RetVal = E_NOT_OK;
		}
	}
	return RetVal;
}
