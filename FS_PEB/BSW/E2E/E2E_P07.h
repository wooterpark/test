/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#ifndef E2E_P07_H
#define E2E_P07_H

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
    E2E_P07STATUS_OK            = 0x00U,
    E2E_P07STATUS_NONEWDATA     = 0x01U,
    E2E_P07STATUS_ERROR         = 0x02U,
    E2E_P07STATUS_REPEATED      = 0x08U,
    E2E_P07STATUS_OKSOMELOST    = 0x20U,
    E2E_P07STATUS_WRONGSEQUENCE = 0x40U
} E2E_P07CheckStatusType;

typedef struct
{
    uint32 DataID;                  /* system unique identifier */
    uint32 Offset;                  /* offset in bits of the header */
    uint32 MinDataLength;           /* minimum length of data in bits */
    uint32 MaxDataLength;           /* maximum length of data in bits */
    uint32 MaxDeltaCounter;         /* max allowed gap between 2 consecutive messages */
} E2E_P07ConfigType;

typedef struct
{
    uint32 Counter;
} E2E_P07ProtectStateType;

typedef struct
{
    E2E_P07CheckStatusType  Status;
    uint32                  Counter;
} E2E_P07CheckStateType;

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

extern Std_ReturnType E2E_P07ProtectInit(E2E_P07ProtectStateType *StatePtr);
extern Std_ReturnType E2E_P07Protect(const E2E_P07ConfigType *ConfigPtr, E2E_P07ProtectStateType *StatePtr,
                                     uint8 *DataPtr, uint32 Length);
extern Std_ReturnType E2E_P07CheckInit(E2E_P07CheckStateType *StatePtr);
extern Std_ReturnType E2E_P07Check(const E2E_P07ConfigType *ConfigPtr, E2E_P07CheckStateType *StatePtr,
                                   const uint8 *DataPtr, uint32 Length);
extern E2E_PCheckStatusType E2E_P07MapStatusToSM(Std_ReturnType CheckReturn, E2E_P07CheckStatusType Status);

#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/* E2E_P07_H */
#endif
