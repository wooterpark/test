/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#ifndef E2E_PRV_H
#define E2E_PRV_H

/*
 **********************************************************************************************************************
 E2E LOCAL DEFINES
 **********************************************************************************************************************
*/

/* Masks required in uint8 context */
#define E2E_MASK_BYTE       0xFFU                   // Used in Profiles E2E_P01, E2E_P02 and E2E_Helpers
#define E2E_MASK_QWORD4     0xFFFFFFFFU             // Used in Profile E2E_P04 and E2E_Helpers
#define E2E_MASK_WORD       0xFFFFU                 // Used in Profiles E2E_P05, E2E_P06 and E2E_Helpers
#define E2E_MASK_QWORD      0xFFFFFFFFFFFFFFFFU     // Used in Profile E2E_P07 and E2E_Helpers
#define E2E_MASK_L_NIBBLE   0x0FU                   // Used in Profiles E2E_P01 and E2E_P02
#define E2E_MASK_H_NIBBLE   0xF0U                   // Used in Profiles E2E_P01 and E2E_P02

/*
 **********************************************************************************************************************
 E2E LOCAL VARIABLES
 **********************************************************************************************************************
*/

static const uint8 E2E_BitReverseLookupTable[256U] =
{
    0x00U, 0x80U, 0x40U, 0xC0U, 0x20U, 0xA0U, 0x60U, 0xE0U, 0x10U, 0x90U, 0x50U, 0xD0U, 0x30U, 0xB0U, 0x70U, 0xF0U,
    0x08U, 0x88U, 0x48U, 0xC8U, 0x28U, 0xA8U, 0x68U, 0xE8U, 0x18U, 0x98U, 0x58U, 0xD8U, 0x38U, 0xB8U, 0x78U, 0xF8U,
    0x04U, 0x84U, 0x44U, 0xC4U, 0x24U, 0xA4U, 0x64U, 0xE4U, 0x14U, 0x94U, 0x54U, 0xD4U, 0x34U, 0xB4U, 0x74U, 0xF4U,
    0x0CU, 0x8CU, 0x4CU, 0xCCU, 0x2CU, 0xACU, 0x6CU, 0xECU, 0x1CU, 0x9CU, 0x5CU, 0xDCU, 0x3CU, 0xBCU, 0x7CU, 0xFCU,
    0x02U, 0x82U, 0x42U, 0xC2U, 0x22U, 0xA2U, 0x62U, 0xE2U, 0x12U, 0x92U, 0x52U, 0xD2U, 0x32U, 0xB2U, 0x72U, 0xF2U,
    0x0AU, 0x8AU, 0x4AU, 0xCAU, 0x2AU, 0xAAU, 0x6AU, 0xEAU, 0x1AU, 0x9AU, 0x5AU, 0xDAU, 0x3AU, 0xBAU, 0x7AU, 0xFAU,
    0x06U, 0x86U, 0x46U, 0xC6U, 0x26U, 0xA6U, 0x66U, 0xE6U, 0x16U, 0x96U, 0x56U, 0xD6U, 0x36U, 0xB6U, 0x76U, 0xF6U,
    0x0EU, 0x8EU, 0x4EU, 0xCEU, 0x2EU, 0xAEU, 0x6EU, 0xEEU, 0x1EU, 0x9EU, 0x5EU, 0xDEU, 0x3EU, 0xBEU, 0x7EU, 0xFEU,
    0x01U, 0x81U, 0x41U, 0xC1U, 0x21U, 0xA1U, 0x61U, 0xE1U, 0x11U, 0x91U, 0x51U, 0xD1U, 0x31U, 0xB1U, 0x71U, 0xF1U,
    0x09U, 0x89U, 0x49U, 0xC9U, 0x29U, 0xA9U, 0x69U, 0xE9U, 0x19U, 0x99U, 0x59U, 0xD9U, 0x39U, 0xB9U, 0x79U, 0xF9U,
    0x05U, 0x85U, 0x45U, 0xC5U, 0x25U, 0xA5U, 0x65U, 0xE5U, 0x15U, 0x95U, 0x55U, 0xD5U, 0x35U, 0xB5U, 0x75U, 0xF5U,
    0x0DU, 0x8DU, 0x4DU, 0xCDU, 0x2DU, 0xADU, 0x6DU, 0xEDU, 0x1DU, 0x9DU, 0x5DU, 0xDDU, 0x3DU, 0xBDU, 0x7DU, 0xFDU,
    0x03U, 0x83U, 0x43U, 0xC3U, 0x23U, 0xA3U, 0x63U, 0xE3U, 0x13U, 0x93U, 0x53U, 0xD3U, 0x33U, 0xB3U, 0x73U, 0xF3U,
    0x0BU, 0x8BU, 0x4BU, 0xCBU, 0x2BU, 0xABU, 0x6BU, 0xEBU, 0x1BU, 0x9BU, 0x5BU, 0xDBU, 0x3BU, 0xBBU, 0x7BU, 0xFBU,
    0x07U, 0x87U, 0x47U, 0xC7U, 0x27U, 0xA7U, 0x67U, 0xE7U, 0x17U, 0x97U, 0x57U, 0xD7U, 0x37U, 0xB7U, 0x77U, 0xF7U,
    0x0FU, 0x8FU, 0x4FU, 0xCFU, 0x2FU, 0xAFU, 0x6FU, 0xEFU, 0x1FU, 0x9FU, 0x5FU, 0xDFU, 0x3FU, 0xBFU, 0x7FU, 0xFFU
};

/*
 **********************************************************************************************************************
 Prototypes for private routines for the E2E library
 **********************************************************************************************************************
 */

LOCAL_INLINE boolean E2E_Prv_CheckSyncCounter(uint8 *const SyncCounter_pu8, uint8 *const RepeatedDataCounter_pu8,
                                              uint8 SyncCounterInit_u8, uint8 MaxRepeatedDataCounter_u8);
LOCAL_INLINE uint8 E2E_Prv_MaxDeltaCounter(uint8 ReceivedCounter_u8, uint8 LastValidCounter_u8, uint16 MaxCounter_u16);
LOCAL_INLINE void  E2E_Prv_IncreaseCounter(uint8 * const Counter_pu8, uint8 Limit_u8);
LOCAL_INLINE uint8 E2E_Prv_ReverseBitsU8(uint8 Number_u8);

 /*
 **********************************************************************************************************************
 private routines for E2E component
 **********************************************************************************************************************
 */

/**
 ***********************************************************************************************************************
 * E2E_Prv_CheckSyncCounter
 *
 * \brief Checks if synchronization of sender and receiver is running
 *
 * Description: private function for E2E library routines.
 *              If a maximum of repeated messages is reached the following messages synchronizes the connection.
 *              The synchronization counter is initialized with the maximum and decreased until enough messages
 *              are received.
 *
 * Restrictions:
 *   -
 *
 * Dependencies:
 *   -
 *
 * Resources:
 *   -
 * \param   uint8   const* SyncCounter_pu8      constant pointer to the synchronization counter
 * \param   uint8   const* RPCounter_pu8        constant pointer to the counter defining the maximal repeated messages
 * \param   uint8   SyncCounterInit_u8          initialization value for synchronization counter
 * \param   uint8   MaxRepeatedDataCounter_u8   Limit of the repeated messages
 * \return  boolean                             TRUE: synchronization is running
 *                                              FALSE: no synchronization necessary or enough sync messages are received
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE boolean E2E_Prv_CheckSyncCounter(uint8* const SyncCounter_pu8, uint8* const RepeatedDataCounter_pu8,
                                              uint8 SyncCounterInit_u8, uint8 MaxRepeatedDataCounter_u8)
{
    boolean sync_b = FALSE;


    if (*RepeatedDataCounter_pu8 <= MaxRepeatedDataCounter_u8)
    {
        if (*SyncCounter_pu8 > 0)
        {
            /* synchronization is running */
            (*SyncCounter_pu8)--;

            sync_b = TRUE;
        }
    }
    else
    {
        /* start synchronization */
        *SyncCounter_pu8 = SyncCounterInit_u8;

        sync_b = TRUE;
    }

    /* reset repetition counter */
    *RepeatedDataCounter_pu8 = 0;

    return (sync_b);
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_IncreaseCounter
 *
 * \brief Increases Calculates the maximum of counter with respect to a limit
 *
 * Description: private function for E2E library routines.
 *              Service increases the counter until a maximum is reached
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
 * \param   uint8   const* Counter_pu8  constant pointer to the counter
 * \param   uint8   Limit_u8            Limit of the counter
 * \return  void
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE void E2E_Prv_IncreaseCounter(uint8 *const Counter_pu8, uint8 Limit_u8)
{
    if (*Counter_pu8 < Limit_u8)
    {
        (*Counter_pu8)++;
    }
    else
    {
        *Counter_pu8 = Limit_u8;
    }
}

/**
 *******************************************************************************************************************
 * E2E_Prv_MaxDeltaCounter
 *
 * \brief       Calculates the deltaCounter as difference between ReceivedCounter and LastValidCounter.
 *              deltaCounter is restricted to the values [0, MaxCounter]
 *
 * Description: private function for E2E library routines.
 *              Service calculates the Delta of two counter and limits the result
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
 * \param   uint8   ReceivedCounter_u8    New Counter
 * \param   uint8   LastValidCounter_u8   Old valid Counter
 * \param   uint16  MaxCounter_u16        Border of the counter. Counter maximally can reach MaxCounter.
 *                                        MaxCounter is the maximum of deltaCounter + 1.
 * \return  uint8   deltaCounter_u8       Difference of two Counters with respect to a limit
 *
 *******************************************************************************************************************
 */

LOCAL_INLINE uint8 E2E_Prv_MaxDeltaCounter(uint8 ReceivedCounter_u8, uint8 LastValidCounter_u8, uint16 MaxCounter_u16)
{
    uint8 deltaCounter_u8;


    /* Calculate the Delta of the two Counter, respect the limitation */
    if (ReceivedCounter_u8 >= LastValidCounter_u8)
    {
        deltaCounter_u8 = ReceivedCounter_u8 - LastValidCounter_u8;
    }
    else
    {
        deltaCounter_u8 = (uint8)((MaxCounter_u16 - LastValidCounter_u8) + ReceivedCounter_u8);
    }

    return (deltaCounter_u8);
}

/**
 *******************************************************************************************************************
 * E2E_Prv_ReverseBitsU8
 *
 * \brief       Reverse the order of bits
 *
 * Description: private function for E2E library routines.
 *              Service reverse the order of bits of an u8 value
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
 * \param   uint8   Number_u8             input variable to reverse the bits
 * \return  uint8   Number_u8             output variable with reversed bits
 *
 *******************************************************************************************************************
 */

LOCAL_INLINE uint8 E2E_Prv_ReverseBitsU8(uint8 Number_u8)
{
    return (E2E_BitReverseLookupTable[Number_u8]);
}

/* E2E_PRV_H */
#endif
