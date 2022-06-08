/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#ifndef E2E_P04_H
#define E2E_P04_H

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
/* TRACE[SWS_E2E_00337] */
typedef enum
{
    E2E_P04STATUS_OK            = 0x00U,
    E2E_P04STATUS_NONEWDATA     = 0x01U,
    E2E_P04STATUS_ERROR         = 0x02U,
    E2E_P04STATUS_REPEATED      = 0x08U,
    E2E_P04STATUS_OKSOMELOST    = 0x20U,
    E2E_P04STATUS_WRONGSEQUENCE = 0x40U
} E2E_P04CheckStatusType;

/* TRACE[SWS_E2E_00334] */
typedef struct
{
    uint32 DataID;                  /* system unique identifier */
    uint16 Offset;                  /* offset in bits of the header */
    uint16 MinDataLength;           /* minimum length of data in bits */
    uint16 MaxDataLength;           /* maximum length of data in bits */
    uint16 MaxDeltaCounter;         /* max allowed gap between 2 consecutive messages */
} E2E_P04ConfigType;

/* TRACE[SWS_E2E_00335] */
typedef struct
{
    uint16 Counter;
} E2E_P04ProtectStateType;

/* TRACE[SWS_E2E_00336] */
typedef struct
{
    E2E_P04CheckStatusType  Status;
    uint16                  Counter;
} E2E_P04CheckStateType;

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

extern Std_ReturnType E2E_P04ProtectInit(E2E_P04ProtectStateType *StatePtr);
extern Std_ReturnType E2E_P04Protect(const E2E_P04ConfigType *ConfigPtr, E2E_P04ProtectStateType *StatePtr,
                                     uint8 *DataPtr, uint16 Length);
extern Std_ReturnType E2E_P04CheckInit(E2E_P04CheckStateType *StatePtr);
extern Std_ReturnType E2E_P04Check(const E2E_P04ConfigType *ConfigPtr, E2E_P04CheckStateType *StatePtr,
                                   const uint8 *DataPtr, uint16 Length);
extern E2E_PCheckStatusType E2E_P04MapStatusToSM(Std_ReturnType CheckReturn, E2E_P04CheckStatusType Status);

#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/* E2E_P04_H */
#endif
