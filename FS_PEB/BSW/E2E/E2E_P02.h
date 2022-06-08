/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#ifndef E2E_P02_H
#define E2E_P02_H

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

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

typedef enum
{
    E2E_P02STATUS_OK            = 0x00U,
    E2E_P02STATUS_NONEWDATA     = 0x01U,
    E2E_P02STATUS_WRONGCRC      = 0x02U,
    E2E_P02STATUS_SYNC          = 0x03U,
    E2E_P02STATUS_INITIAL       = 0x04U,
    E2E_P02STATUS_REPEATED      = 0x05U,
    E2E_P02STATUS_OKSOMELOST    = 0x06U,
    E2E_P02STATUS_WRONGSEQUENCE = 0x07U
} E2E_P02CheckStatusType;

typedef struct
{
    uint16 DataLength;              /* length of data in bits */
    uint8  DataIDList[16];          /* list of sender Identifier */
    uint8  MaxDeltaCounterInit;     /* maximum allowed gap, init value */
    uint8  MaxNoNewOrRepeatedData;  /* maximum of missing or repeated data */
    uint8  SyncCounterInit;         /* number of data required for syncronization */
    uint16 Offset ;                 /* offset of the E2E header in the Data[] array in bits. */
                                    /* Currently not used it should be always set to 0. */
} E2E_P02ConfigType;

typedef struct
{
    uint8 Counter;
} E2E_P02ProtectStateType;

typedef struct
{
    uint8                   LastValidCounter;
    uint8                   MaxDeltaCounter;
    boolean                 WaitForFirstData;
    boolean                 NewDataAvailable;
    uint8                   LostData;
    E2E_P02CheckStatusType  Status;
    uint8                   SyncCounter;
    uint8                   NoNewOrRepeatedDataCounter;
} E2E_P02CheckStateType;

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * External declarations
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"

extern Std_ReturnType E2E_P02ProtectInit(E2E_P02ProtectStateType *StatePtr);
extern Std_ReturnType E2E_P02Protect(const E2E_P02ConfigType *ConfigPtr, E2E_P02ProtectStateType *StatePtr,
                                     uint8 *DataPtr);
extern Std_ReturnType E2E_P02CheckInit(E2E_P02CheckStateType *StatePtr);
extern Std_ReturnType E2E_P02Check(const E2E_P02ConfigType *ConfigPtr, E2E_P02CheckStateType *StatePtr,
                                   const uint8 *DataPtr);
extern E2E_PCheckStatusType E2E_P02MapStatusToSM(Std_ReturnType CheckReturn, E2E_P02CheckStatusType Status,
                                                 boolean profileBehavior);

#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/* E2E_P02_H */
#endif
