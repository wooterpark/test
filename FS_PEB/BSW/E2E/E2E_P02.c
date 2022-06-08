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
#include "E2E_Prv.h"
#include "E2E_Prv_P02.h"

/**
 ***********************************************************************************************************************
 * E2E_P02ProtectInit
 *
 * \brief End to end communication protection state initialization
 *
 * Description: Protection initialization function of E2E profile P02
 * - Checks the pointer of the input variables
 * - Initializes the current counter value (message sequence number) to zero
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
 * \param   E2E_P02ProtectStateType  *StatePtr       Pointer to the protect status structure of of E2E profile P02
 * \return  Std_ReturnType                           Error Flags
 *
 ***********************************************************************************************************************
 */
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
Std_ReturnType E2E_P02ProtectInit(E2E_P02ProtectStateType *StatePtr)
{
    Std_ReturnType error_en = E2E_E_INTERR;


    /* Check for NULL pointer */
    if (NULL_PTR == StatePtr)
    {
        error_en = E2E_E_INPUTERR_NULL;
    }
    else
    {
        /* Initialize Protect state */
        StatePtr->Counter = 0U;

        /* no error occurred */
        error_en = E2E_E_OK;
    }

    return (error_en);
}
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/**
 ***********************************************************************************************************************
 * E2E_P02Protect
 *
 * \brief End to end communication protection routine corresponding to the profile P02 specified by AUTOSAR
 *
 * Description: Protection function of E2E profile P02
 * - Checks the pointer of the input variables
 * - Checks the range of the input variables
 * - Writes the current counter value (message sequence number) into the data stream
 * - Calculates a crc over the data stream to protect and writes the result into the data stream
 * - Updates the counter of the sender for the next message to send
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
 * \param   E2E_P02ConfigType       *ConfigPtr  Pointer to the configuration structure of E2E profile P02
 * \param   E2E_P02ProtectStateType *StatePtr   Pointer to the protect status structure of of E2E profile P02
 * \param   uint8                   *DataPtr    Pointer to the byte sequence within the Data to protect
 * \return  Std_ReturnType                      Error Flags
 *
 ***********************************************************************************************************************
 */
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
Std_ReturnType E2E_P02Protect(const E2E_P02ConfigType *ConfigPtr, E2E_P02ProtectStateType *StatePtr,
                              uint8 *DataPtr)
{
    /* Initialize internal error */
    Std_ReturnType error_en = E2E_E_INTERR;


    /* Check for NULL pointer */
    if ((NULL_PTR == ConfigPtr) || (NULL_PTR == StatePtr) || (NULL_PTR == DataPtr))
    {
        error_en = E2E_E_INPUTERR_NULL;
    }
    /* Check for range of input variables */
    /* MR12 RULE 13.5 VIOLATION: The exhaustive evaluation of the combined decision is not required */
    else if ((FALSE == E2E_Prv_P02CheckConfigType(ConfigPtr)) ||
             (FALSE == E2E_Prv_P02CheckProtectStateType(StatePtr)))
    {
        error_en = E2E_E_INPUTERR_WRONG;
    }
    else
    {
        /* Write counter in the specified area of Data */
        /* new counter  = saved high nibble and actualised low nibble */
        /* MR12 RULE 2.2 VIOLATION: This operation is not redundant */
        DataPtr[1] = (DataPtr[1] & (uint8)E2E_MASK_H_NIBBLE) | (StatePtr->Counter & (uint8)E2E_MASK_L_NIBBLE);

        /* Calculate CRC over data and DataID using CRC-8-H2F and write CRC in the specified region of data */
        DataPtr[0] = E2E_Prv_P02CalcCRC8H2F(ConfigPtr, ConfigPtr->DataIDList[StatePtr->Counter], DataPtr);

        /* Increments the sender status counter for the next message to send */
        if (StatePtr->Counter < E2E_P02_MAXCOUNTER)
        {
            StatePtr->Counter++;
        }
        else
        {
            /* Max counter value already reached reset counter */
            StatePtr->Counter = 0U;
        }

        /* no error occurred */
        error_en = E2E_E_OK;
    }

    return (error_en);
}
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/**
 ***********************************************************************************************************************
 * E2E_P02CheckInit
 *
 * \brief End to end communication check state initialization
 *
 * Description: Check initialization function of E2E profile P02
 * - Checks the pointer of the input values for NULL,
 * - Sets all variables in check state structure to default values
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
 * \param   E2E_P02CheckStateType     *StatePtr       Pointer to the check status structure of of E2E profile P02
 * \return  Std_ReturnType                            Error Flags
 *
 ***********************************************************************************************************************
*/
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
Std_ReturnType E2E_P02CheckInit(E2E_P02CheckStateType *StatePtr)
{
    Std_ReturnType error_en = E2E_E_INTERR;

    /* Check for NULL pointer */
    if (NULL_PTR == StatePtr)
    {
        error_en = E2E_E_INPUTERR_NULL;
    }
    else
    {
        /* Initialize Check state */
        StatePtr->LastValidCounter = 0U;
        StatePtr->MaxDeltaCounter = 0U;
        StatePtr->WaitForFirstData = TRUE;
        StatePtr->NewDataAvailable = TRUE;
        StatePtr->LostData = 0U;
        StatePtr->Status = E2E_P02STATUS_NONEWDATA;
        StatePtr->SyncCounter = 0U;
        StatePtr->NoNewOrRepeatedDataCounter = 0U;

        /* no error occurred */
        error_en = E2E_E_OK;
    }

    return (error_en);
}
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/**
 ***********************************************************************************************************************
 * E2E_P02Check
 *
 * \brief End to end communication check routine corresponding to the profile P02 specified by AUTOSAR
 *
 * Description: Check function of E2E profile P02
 * - Checks the pointer of the input values for NULL,
 * - Checks the range of the input values
 *   These two first check lead to a interrupt of the check routine when the result is FALSE.
 *   Otherwise the next checks are performed:
 * - Calculates the tolerable maximum loss of messages
 * - Gets the current Counter from the data stream
 * - Gets the crc result, calculated by the protect function from the data stream
 * - Calculates the crc result of the received data stream and compares it with the received crc result
 * - Checks the disposition of the receiver
 * - Checks the correctness of the received data stream
 * - Checks the sequence of the received message
 * - Evaluates the status of the receiver
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
 * \param   E2E_P02ConfigType       *ConfigPtr      Pointer to the configuration structure of E2E profile P02
 * \param   E2E_P02CheckStateType   *StatePtr       Pointer to the check status structure of of E2E profile P02
 * \param   uint8                   *DataPtr        Pointer to the byte sequence within the Data to be checked
 * \return  Std_ReturnType                          Error Flags
 *
 ***********************************************************************************************************************
*/
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
Std_ReturnType E2E_P02Check(const E2E_P02ConfigType *ConfigPtr, E2E_P02CheckStateType *StatePtr,
                            const uint8 *DataPtr)
{
    Std_ReturnType error_en = E2E_E_INTERR;
    uint8          recCounter_u8;     /* counter value received via data stream */
    uint8          deltaCounter_u8;   /* difference between received counter and last valid received counter */
    uint8          crc_u8;            /* calculated crc result from data stream */


    /* Check for NULL pointer */
    if ((NULL_PTR == ConfigPtr) || (NULL_PTR == StatePtr) || (NULL_PTR == DataPtr))
    {
        error_en = E2E_E_INPUTERR_NULL;
    }
    /* Check for range of input data */
    /* MR12 RULE 13.5 VIOLATION: The exhaustive evaluation of the combined decision is not required */
    else if ((FALSE == E2E_Prv_P02CheckConfigType(ConfigPtr)) ||
             (FALSE == E2E_Prv_P02CheckCheckStateType(StatePtr)))
    {
        error_en = E2E_E_INPUTERR_WRONG;
    }
    else
    {
        /* Increases StatePtr->MaxDeltaCounter until the maximum is reached */
        E2E_Prv_IncreaseCounter(&StatePtr->MaxDeltaCounter, E2E_P02_MAXCOUNTER);

        /* Check for new data available */
        if (FALSE != StatePtr->NewDataAvailable)
        {
            /* Read Counter in Data, second byte, low nibble */
            recCounter_u8  = (DataPtr[1] & (uint8)E2E_MASK_L_NIBBLE);

            /* Calculate crc over data stream and DataID */
            crc_u8 = E2E_Prv_P02CalcCRC8H2F(ConfigPtr, ConfigPtr->DataIDList[recCounter_u8], DataPtr);

            /* Check for correctness of crc transmitted with the byte */
            if (crc_u8 != DataPtr[0])
            {
                StatePtr->Status = E2E_P02STATUS_WRONGCRC;
            }
            /* Crc OK: Received and calculated Crc is the same */
            else
            {
                /* Check for disposition of the receiver */
                if (FALSE != StatePtr->WaitForFirstData)
                {
                    StatePtr->WaitForFirstData = FALSE;
                    StatePtr->MaxDeltaCounter  = ConfigPtr->MaxDeltaCounterInit;
                    StatePtr->LastValidCounter = recCounter_u8;
                    StatePtr->Status           = E2E_P02STATUS_INITIAL;
                }
                /* Receiver is ready to get Data */
                else
                {
                    /* Calculate DeltaCounter, respect the limitation to value (E2E_P02_MAXCOUNTER + 1U) */
                    deltaCounter_u8 = E2E_Prv_MaxDeltaCounter(recCounter_u8, StatePtr->LastValidCounter,
                                                              (E2E_P02_MAXCOUNTER + 1U));

                    /* Correct data */
                    if (E2E_P02_DELTACOUNTER_OK == deltaCounter_u8)
                    {
                        StatePtr->MaxDeltaCounter  = ConfigPtr->MaxDeltaCounterInit;
                        StatePtr->LastValidCounter = recCounter_u8;
                        StatePtr->LostData         = 0U;

                        /* check if synchronization is running */
                        if (FALSE != E2E_Prv_CheckSyncCounter(&StatePtr->SyncCounter,
                                                              &StatePtr->NoNewOrRepeatedDataCounter,
                                                              ConfigPtr->SyncCounterInit,
                                                              ConfigPtr->MaxNoNewOrRepeatedData))
                        {
                            StatePtr->Status = E2E_P02STATUS_SYNC;
                        }
                        else
                        {
                            StatePtr->Status = E2E_P02STATUS_OK;
                        }
                    }
                    /* Repeated data */
                    else if (E2E_P02_DELTACOUNTER_REPEATED == deltaCounter_u8)
                    {
                        E2E_Prv_IncreaseCounter(&StatePtr->NoNewOrRepeatedDataCounter, E2E_P02_MAXCOUNTER);

                        StatePtr->Status = E2E_P02STATUS_REPEATED;
                    }
                    /* Some data lost, but still ok */
                    else if (deltaCounter_u8 <= StatePtr->MaxDeltaCounter)
                    {
                        StatePtr->MaxDeltaCounter  = ConfigPtr->MaxDeltaCounterInit;
                        StatePtr->LastValidCounter = recCounter_u8;
                        StatePtr->LostData         = deltaCounter_u8 - 1U;

                        /* check if synchronization is running */
                        if (FALSE != E2E_Prv_CheckSyncCounter(&StatePtr->SyncCounter,
                                                              &StatePtr->NoNewOrRepeatedDataCounter,
                                                              ConfigPtr->SyncCounterInit,
                                                              ConfigPtr->MaxNoNewOrRepeatedData))
                        {
                            StatePtr->Status = E2E_P02STATUS_SYNC;
                        }
                        else
                        {
                            StatePtr->Status = E2E_P02STATUS_OKSOMELOST;
                        }
                    }
                    /* Wrong sequence or to many data lost */
                    else
                    {
                        StatePtr->NoNewOrRepeatedDataCounter = 0U;
                        StatePtr->SyncCounter = ConfigPtr->SyncCounterInit;

                        if (StatePtr->SyncCounter > 0U)
                        {
                            StatePtr->MaxDeltaCounter  = ConfigPtr->MaxDeltaCounterInit;
                            StatePtr->LastValidCounter = recCounter_u8;
                        }

                        StatePtr->Status = E2E_P02STATUS_WRONGSEQUENCE;
                    }
                }
            }
        }
        /* no new data available */
        else
        {
            E2E_Prv_IncreaseCounter(&StatePtr->NoNewOrRepeatedDataCounter, E2E_P02_MAXCOUNTER);

            StatePtr->Status = E2E_P02STATUS_NONEWDATA;
        }

        /* no error occurred */
        error_en = E2E_E_OK;
    }

    return (error_en);
}
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/**
 ***********************************************************************************************************************
 * E2E_P02MapStatusToSM
 *
 * \brief Map profile P02 check status to generic state machine status
 *
 * Description:
 * The function maps the check status of profile P02 to a generic check status, which can be used by E2E state machine
 * check function. The E2E profile P02 delivers a more fine-granular status, but this is not relevant for the E2E
 * state machine.
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
 * \param   Std_ReturnType            CheckReturn     Return value of the E2E_P02Check function
 * \param   E2E_P02CheckStatusType    Status          Status determined by E2E_P02Check function
 * \param   boolean                   profileBehavior FALSE: check has the legacy behavior, before R4.2
 *                                                    TRUE: check behaves like new P4/P5/P6 profiles introduced in R4.2
 * \return  E2E_PCheckStatusType                      Profile-independent status of the reception on one single Data
 *                                                    in one cycle
 *
 ***********************************************************************************************************************
*/
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
E2E_PCheckStatusType E2E_P02MapStatusToSM(Std_ReturnType CheckReturn, E2E_P02CheckStatusType Status,
                                          boolean profileBehavior)
{
    /* TRACE[SWS_E2E_00379], TRACE[SWS_E2E_00380], TRACE[SWS_E2E_00381], TRACE[SWS_E2E_00477] */
    /* report an ERROR as default */
    E2E_PCheckStatusType checkStatus_en = E2E_P_ERROR;


    /* Check if return value is correct */
    if (E2E_E_OK == CheckReturn)
    {
        /* Evaluate Profile status */
        switch (Status)
        {
            case E2E_P02STATUS_OK:
            case E2E_P02STATUS_OKSOMELOST:
            {
                checkStatus_en = E2E_P_OK;
            }
            break;

            case E2E_P02STATUS_NONEWDATA:
            {
                checkStatus_en = E2E_P_NONEWDATA;
            }
            break;

            case E2E_P02STATUS_WRONGSEQUENCE:
            {
                checkStatus_en = E2E_P_WRONGSEQUENCE;
            }
            break;

            case E2E_P02STATUS_WRONGCRC:
            {
                checkStatus_en = E2E_P_ERROR;
            }
            break;

            case E2E_P02STATUS_REPEATED:
            {
                checkStatus_en = E2E_P_REPEATED;
            }
            break;

            default: /* Status has an invalid value*/
            {
                checkStatus_en = E2E_P_ERROR;
            }
            break;
        }
        
        if (TRUE == profileBehavior)
        {
            switch (Status)
            {
                case E2E_P02STATUS_INITIAL:
                {
                    checkStatus_en = E2E_P_WRONGSEQUENCE;
                }
                break;
                
                case E2E_P02STATUS_SYNC:
                {
                    checkStatus_en = E2E_P_OK;
                }
                break;                 
                
                default:
                {
                    /* Nothing to do */
                }
                break;
            }
        }
        else
        {
            switch (Status)
            {
                case E2E_P02STATUS_INITIAL:
                {
                    checkStatus_en = E2E_P_OK;
                }
                break;
                
                case E2E_P02STATUS_SYNC:
                {
                    checkStatus_en = E2E_P_WRONGSEQUENCE;
                }
                break; 
                
                default:
                {
                    /* Nothing to do */
                }
                break;
            }
        }
    }

    return (checkStatus_en);
}
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"
