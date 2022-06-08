/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/


/**********************************************************************************************************************
 *  Include files                                                                                                    
 **********************************************************************************************************************/

#include "BswM.h"
#include "BswM_Prv.h"

/**********************************************************************************************************************
 *  Definition of Global Functions                                                                                                    
 **********************************************************************************************************************/

/********************************  LogicalExpressionEvaluateFunctions  ***************************************/
#define BSWM_START_SEC_CODE
#include "BswM_Cfg_MemMap.h"

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_AfterRun (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_AfterRun
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_AFTERRUN)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_AFTERRUN)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DcmEnableRxAndTx_CAN0 (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_DcmEnableRxAndTx_CAN0
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_DCMENABLERXANDTX_CAN0)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_DCMENABLERXANDTX_CAN0)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DcmEnableRxDisableTx_CAN0 (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_DcmEnableRxDisableTx_CAN0
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_DCMENABLERXDISABLETX_CAN0)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_DCMENABLERXDISABLETX_CAN0)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_GoDown (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_GoDown
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_GODOWN)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_GODOWN)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_InitBlockReadAllComplete (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_InitBlockReadAllComplete
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_INITBLOCKREADALLCOMPLETE)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_INITBLOCKREADALLCOMPLETE)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_InitBlockTwo (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_InitBlockTwo
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_INITBLOCKTWO)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_INITBLOCKTWO)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_PostRun_Core0 (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_PostRun_Core0
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_POSTRUN_CORE0)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_POSTRUN_CORE0)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_Shutdown (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_Shutdown
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_SHUTDOWN)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_SHUTDOWN)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_StartCom (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_StartCom
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_STARTCOM)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_STARTCOM)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_StartPduGroup_FR (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_StartPduGroup_FR
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_STARTPDUGROUP_FR)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_STARTPDUGROUP_FR)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_StartPduGroup_Sys (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_StartPduGroup_Sys
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_STARTPDUGROUP_SYS)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_STARTPDUGROUP_SYS)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_StopPduGroup_FR (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_StopPduGroup_FR
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_STOPPDUGROUP_FR)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_STOPPDUGROUP_FR)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_StopPduGroup_Sys (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_StopPduGroup_Sys
(
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb,
		P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb
)
{
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if(FALSE != BSWMMODEVALUE_BSWM_LE_STOPPDUGROUP_SYS)
	{
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if(FALSE != BSWMLOGEXP_BSWM_LE_STOPPDUGROUP_SYS)
		{
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

#define BSWM_STOP_SEC_CODE
#include "BswM_Cfg_MemMap.h"

/**********************************************************************************************************************
 *																										
 **********************************************************************************************************************/
