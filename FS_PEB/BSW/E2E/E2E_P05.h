/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#ifndef E2E_P05_H
#define E2E_P05_H

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
    E2E_P05STATUS_OK            = 0x00U,
    E2E_P05STATUS_NONEWDATA     = 0x01U,
    E2E_P05STATUS_ERROR         = 0x07U,
    E2E_P05STATUS_REPEATED      = 0x08U,
    E2E_P05STATUS_OKSOMELOST    = 0x20U,
    E2E_P05STATUS_WRONGSEQUENCE = 0x40U
} E2E_P05CheckStatusType;

typedef struct
{
    uint16 Offset;                  /* offset in bits of the header */
    uint16 DataLength;              /* length of data in bits */
    uint16 DataID;                  /* system unique identifier */
    uint8  MaxDeltaCounter;         /* max allowed gap between 2 consecutive messages */
} E2E_P05ConfigType;

typedef struct
{
    uint8 Counter;
} E2E_P05ProtectStateType;

typedef struct
{
    E2E_P05CheckStatusType  Status;
    uint8                   Counter;
} E2E_P05CheckStateType;

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

extern Std_ReturnType E2E_P05ProtectInit(E2E_P05ProtectStateType *StatePtr);
extern Std_ReturnType E2E_P05Protect(const E2E_P05ConfigType *ConfigPtr, E2E_P05ProtectStateType *StatePtr,
                                     uint8 *DataPtr, uint16 Length);
extern Std_ReturnType E2E_P05CheckInit(E2E_P05CheckStateType *StatePtr);
extern Std_ReturnType E2E_P05Check(const E2E_P05ConfigType *ConfigPtr, E2E_P05CheckStateType *StatePtr,
                                   const uint8 *DataPtr, uint16 Length);
extern E2E_PCheckStatusType E2E_P05MapStatusToSM(Std_ReturnType CheckReturn, E2E_P05CheckStatusType Status);

#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/* E2E_P05_H */
#endif
