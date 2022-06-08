/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#ifndef E2E_PRV_P01_H
#define E2E_PRV_P01_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */

/*
 **********************************************************************************************************************
 * Defines
 **********************************************************************************************************************
 */

#define E2E_P01_CRCOFFSET                     8U
#define E2E_P01_COUNTEROFFSET                 4U
#define E2E_P01_MAXCOUNTER                    14U             /* Maximum counter value */
#define E2E_P01_DELTACOUNTER_REPEATED         0U              /* Delta counter value when message repeated */
#define E2E_P01_DELTACOUNTER_OK               1U              /* Delta counter value when next message received */

/*
 **********************************************************************************************************************
 Prototypes for private routines for the E2E library
 **********************************************************************************************************************
 */

LOCAL_INLINE boolean   E2E_Prv_P01CheckConfigType(const E2E_P01ConfigType * const Config_pst);
LOCAL_INLINE boolean   E2E_Prv_P01CheckProtectStateType(const E2E_P01ProtectStateType * const State_pst);
LOCAL_INLINE boolean   E2E_Prv_P01CheckCheckStateType(const E2E_P01CheckStateType * const State_pst);
LOCAL_INLINE void      E2E_Prv_P01SetDataIdNibble(const E2E_P01ConfigType * const Config_pst, uint8 * Data_pu8);
LOCAL_INLINE void      E2E_Prv_P01GetDataIdNibble(const E2E_P01ConfigType * const Config_pst,
                                                  uint8 * RecDataIDNibble_pu8, const uint8 * const Data_pu8);
LOCAL_INLINE void      E2E_Prv_P01WriteCounter(const E2E_P01ConfigType * const Config_pst,
                                               const E2E_P01ProtectStateType * const State_pst, uint8 * Data_pu8);
LOCAL_INLINE uint8     E2E_Prv_P01ReadCounter(const E2E_P01ConfigType * const Config_pst, const uint8 * const Data_pu8);
LOCAL_INLINE uint8     E2E_Prv_P01CalcCRC8(const E2E_P01ConfigType * const Config_pst, uint8 Counter_u8,
                                           const uint8 * const Data_pu8);

/*
 **********************************************************************************************************************
 private routines for E2E profile P01
 **********************************************************************************************************************
 */

/**
 ***********************************************************************************************************************
 * E2E_Prv_P01CheckConfigType
 *
 * \brief Tests the input parameter E2E_P01ConfigType for correctness
 *
 * Description: Tests the input parameter E2E_P01ConfigType for correctness
 * The range of the variable is restricted by the E2E specification:
 * - maximum length of the data stream protected by the E2E library functions
 * - maximum number of messages
 * - byte alignment for the data stream length
 * - nibble alignment for the counter positions
 * - byte alignment for the crc result position
 * - crc byte is inside the data stream
 * - counter nibble is inside the data stream
 * When at minimum on of the test fails, the function returns FALSE
 * The E2_P01Protect or E2E_P01Check function is interrupted and returns an error message.
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
 * \param   E2E_P01ConfigType       *Config_pst  Pointer to the configuration structure of E2E profile P01
 * \return  boolean                              returns TRUE if the check is ok, otherwise returns FALSE
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE boolean E2E_Prv_P01CheckConfigType(const E2E_P01ConfigType * const Config_pst)
{
    return ((boolean)((Config_pst->MaxDeltaCounterInit <= E2E_P01_MAXCOUNTER) &&
                      ((Config_pst->DataLength % 8U) == 0U) &&
                      ((Config_pst->CRCOffset % E2E_P01_CRCOFFSET) == 0U)  &&
                      ((Config_pst->CounterOffset % E2E_P01_COUNTEROFFSET) == 0U) &&
                      ((Config_pst->CounterOffset / 8U) != (Config_pst->CRCOffset / 8U)) &&
                      ((Config_pst->DataLength / 8U) > (Config_pst->CRCOffset / 8U)) &&
                      ((Config_pst->DataLength / 8U) > (Config_pst->CounterOffset / 8U))));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P01CheckProtectStateType
 *
 * \brief Tests the input parameter E2E_P01ProtectStateType for correctness
 *
 * Description: Tests the input parameter E2E_P01ProtectStateType for correctness
 * The counter values are in principle restricted to the range from 0 to E2E_P01_MAXCOUNTER
 *
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
 * \param   E2E_P01ProtectStateType  *State_pst  Pointer to the sender status structure of of E2E profile P01
 * \return  boolean                              returns TRUE if the check is ok, otherwise returns FALSE
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE boolean E2E_Prv_P01CheckProtectStateType(const E2E_P01ProtectStateType * const State_pst)
{
    return ((boolean)(State_pst->Counter <= E2E_P01_MAXCOUNTER));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P01CheckCheckStateType
 *
 * \brief Tests the input parameter E2E_P01CheckStateType for correctness
 *
 * Description: Tests the input parameter E2E_P01CheckStateType for correctness
 * The counter value are in principle restricted to the range from 0 to E2E_P01_MAXCOUNTER.
 * In case the functions returns a FALSE, the E2E_P01Check routine is interrupted.
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
 * \param   E2E_P01CheckStateType  *State_pst        Pointer to the receiver status structure of of E2E profile P01
 * \return  boolean                                  returns TRUE if the check is ok, otherwise returns FALSE
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE boolean E2E_Prv_P01CheckCheckStateType(const E2E_P01CheckStateType * const State_pst)
{
    return ((boolean)(State_pst->MaxDeltaCounter <= E2E_P01_MAXCOUNTER));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P01SetDataIdNibble
 *
 * \brief Writes the lower nibble of the data ID into the designated position of the data stream.
 *
 * Description:
 * In case of profile 1c writes the lower nibble of the data ID into the designated position of the data stream.
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
 * \param   E2E_P01ConfigType       *Config_pst     Pointer to the configuration structure of E2E profile P01
 * \param   uint8                   *Data_pu8       Pointer to the byte sequence within the Data to protect
 * \return  void
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE void  E2E_Prv_P01SetDataIdNibble(const E2E_P01ConfigType * const Config_pst, uint8 * Data_pu8)
{
    uint16 offset_u16 = Config_pst->DataIDNibbleOffset / 8U;


    /*  Look for the configured DataIdMode */
    if (E2E_P01_DATAID_NIBBLE == Config_pst->DataIDMode)
    {
        /* in case of Profile 1C add the lower nibble of the dataId into the data stream at the correct position */
        if (0U == (Config_pst->DataIDNibbleOffset % 8U))
        {
            Data_pu8[offset_u16] = (Data_pu8[offset_u16] & (uint8)E2E_MASK_H_NIBBLE) |
                                   ((uint8)((Config_pst->DataID >> 8U) & (uint8)E2E_MASK_L_NIBBLE));
        }
        else
        {
            Data_pu8[offset_u16] = (Data_pu8[offset_u16] & (uint8)E2E_MASK_L_NIBBLE) |
                                   ((uint8)((Config_pst->DataID >> 4U) & (uint8)E2E_MASK_H_NIBBLE));
        }
    }
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P01GetDataIdNibble
 *
 * \brief Writes the lower nibble of the data ID hold in the data stream into a provided buffer
 *
 * Description:
 * In case of profile 1c writes the lower nibble of the data ID hold in the data stream into a provided buffer
 *
 * Restrictions:
 *   -
 *
 * Resources:
 *   -
 *
 * \param   E2E_P01ConfigType     *Config_pst            Pointer to the configuration structure of E2E profile P01
 * \param   uint8 *               RecDataIDNibble_pu8    Pointer to the variable provided  to get the lower nibble of
 *                                                       the dataID
 * \param   uint8                 *Data_pu8              Pointer to the byte sequence within the Data to protect
 * \return  void
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE void  E2E_Prv_P01GetDataIdNibble(const E2E_P01ConfigType * const Config_pst, uint8 * RecDataIDNibble_pu8,
                                              const uint8 * const Data_pu8)
{
    /*  Look for the configured DataIdMode */
    if (E2E_P01_DATAID_NIBBLE == Config_pst->DataIDMode)
    {
        /* in case of Profile 1C add the lower nibble of the dataId into the data stream at the correct position */
        if (0 == (Config_pst->DataIDNibbleOffset % 8))
        {
            *RecDataIDNibble_pu8 = (Data_pu8[Config_pst->DataIDNibbleOffset / 8U] & (uint8)E2E_MASK_L_NIBBLE);
        }
        else
        {
            /* MR12 RULE 2.2 VIOLATION: This operation is not redundant */
            *RecDataIDNibble_pu8 = ((Data_pu8[Config_pst->DataIDNibbleOffset / 8U] >> 4U) & (uint8)E2E_MASK_L_NIBBLE);
        }
    }
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P01WriteCounter
 *
 * \brief Writes the counter value into the protected data stream
 *
 * Description:
 * Writes the counter value into the data stream. The position is given by the value of the CounterOsset.
 * The CounterOffset is given in bits. The Counter is a nibble in the data stream and is in the value from 0 to 14.
 * Value 15 is an error value.
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
 * \param   E2E_P01ConfigType       *Config_pst     Pointer to the configuration structure of E2E profile P01
 * \param   E2E_P01ProtectStateType *State_pst      Pointer to the sender status structure of of E2E profile P01
 * \param   uint8                   *Data_pu8       Pointer to the byte sequence within the Data to protect
 * \return  void
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE void  E2E_Prv_P01WriteCounter(const E2E_P01ConfigType * const Config_pst,
                                           const E2E_P01ProtectStateType * const State_pst, uint8 * Data_pu8)
{
    uint16 offset_u16 = Config_pst->CounterOffset / 8U;


    /*  Look for the configured Counter Offset */
    if (0U == (Config_pst->CounterOffset % 8U))
    {
        /* Write counter into the low nibble of the specified region of data */
        /* new counter = saved high nibble and actualised low nibble */
        Data_pu8[offset_u16] = (Data_pu8[offset_u16] & (uint8)E2E_MASK_H_NIBBLE) |
                               (State_pst->Counter & (uint8)E2E_MASK_L_NIBBLE);
    }
    else
    {
        /* Write counter into the high nibble of the specified region of data */
        /* new counter  = saved low nibble and actualised high nibble */
        /* MR12 RULE 2.2 VIOLATION: This operation is not redundant */
        Data_pu8[offset_u16] = (Data_pu8[offset_u16] & (uint8)E2E_MASK_L_NIBBLE) |
                               ((uint8)(State_pst->Counter << 4U) & (uint8)E2E_MASK_H_NIBBLE);
    }
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P01ReadCounter
 *
 * \brief Reads the in counter value, transmitted with the data stream
 *
 * Description:
 * Reads the in counter value, transmitted with the data data stream
 * position of the counter is hold in the configuration structure.
 * The position is given in bits. The function returns the counter as an uint8 value.
 * The received counter is a nibble in the counter. The functions cancels the unused nibble of the counter byte
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
 * \param   E2E_P01ConfigType       *Config_pst  Pointer to the configuration structure of E2E profile P01
 * \param   uint8                   *Data_pu8    Pointer to the data stream, a uint 8 array
 * \return  uint8                                Received counter, part of the data stream
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE uint8 E2E_Prv_P01ReadCounter(const E2E_P01ConfigType * const Config_pst, const uint8 * const Data_pu8)
{
    uint8 recCounter_u8;    /* received counter */


    /*  Look for the configured Counter Offset */
    if (0U == (Config_pst->CounterOffset % 8U))
    {
        /* Read counter from the low nibble of the specified region of data */
        recCounter_u8 = (Data_pu8[Config_pst->CounterOffset / 8U] & (uint8)E2E_MASK_L_NIBBLE);
    }
    else
    {
        /* Read counter from the high nibble of the specified region of data */
        /* MR12 RULE 2.2 VIOLATION: This operation is not redundant */
        recCounter_u8 = ((Data_pu8[Config_pst->CounterOffset / 8U] >> 4U) & (uint8)E2E_MASK_L_NIBBLE);
    }

    return (recCounter_u8);
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P01CalcCRC8
 *
 * \brief private routine to calculate CRC-8 SAE J1850 rest profile 1 of E2E library
 *
 * Description:
 * private routine to calculate CRC-8 SAE J1850 in profile 1 main routines of E2E library
 * CRC calculation is split in 3 parts: DataID from Configuration structure, part of Data before and past CRC-byte.
 * The crc byte itself is exclude from the crc calculation.
 * It is required to compensate the rest manipulation from Crc_CalculateCRC8, thus the
 * temporary results have to be manipulated before their use as initial value for next part of crc calculation
 * Past crc calculation over DataId, the crc over the data stream is performed. It is done in two steps:
 * Step 1 before the crc byte:  starts at byte[0] and ends at byte[(CRCOffset / 8) - 1].
 * The length of the first part of the stream is (CRCOffset / 8)
 * Step 2 past the crc byte: starts at byte[(CRCOffset / 8) + 1] and end at byte[datalength / 8]
 * The length is of the second part is (datalength - CRCOffset - 8) / 8
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
 * \param   E2E_P01ConfigType      *Config_pst   Pointer to the configuration structure
 * \param   uint8                  Counter_u8    Status variable
 * \param   uint8                  *Data_pu8     Pointer to the Data to protect
 * \return  uint8                                result of CRC-8 SAE J1850 over DataId and Data
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE uint8 E2E_Prv_P01CalcCRC8(const E2E_P01ConfigType * const Config_pst, uint8 Counter_u8,
                                       const uint8 * const Data_pu8)
{
    uint8  dataID_au8[2U];
    uint8  crc_u8;
    uint8  crcInitValue_u8 = 0xFF;
    uint16 crcOffset_u16;           /* crc offset in bytes */
    uint16 dataLength_u16;          /* datalength in bytes */


    /* Data ID: low byte [0], high byte[1] */
    dataID_au8[0U] = (uint8)(Config_pst->DataID);
    dataID_au8[1U] = (uint8)(Config_pst->DataID >> 8U);

    /* Crc calculation over DataID */
    switch (Config_pst->DataIDMode)
    {
        case E2E_P01_DATAID_BOTH:
        {
            /* if START-/XOR-values of CRC and E2E not equal an additional XOR of the start value must be done */
            crc_u8 = Crc_CalculateCRC8(dataID_au8, 2U, (uint8)E2E_MASK_BYTE,
                                       (boolean)(0U == crcInitValue_u8));
        }
        break;

        case E2E_P01_DATAID_LOW:
        {
            /* if START-/XOR-values of CRC and E2E not equal an additional XOR of the start value must be done */
            crc_u8 = Crc_CalculateCRC8(dataID_au8, 1U, (uint8)E2E_MASK_BYTE,
                                       (boolean)(0U == crcInitValue_u8));
        }
        break;

        case E2E_P01_DATAID_NIBBLE:
        {
            dataID_au8[1U] = 0U;

            /* if START-/XOR-values of CRC and E2E not equal an additional XOR of the start value must be done */
            crc_u8 = Crc_CalculateCRC8(dataID_au8, 2U, (uint8)E2E_MASK_BYTE,
                                       (boolean)(0U == crcInitValue_u8));
        }
        break;

        case E2E_P01_DATAID_ALT:
        default:
        {
            if (1U == (Counter_u8 % 2U))
            {
                /* counter is odd: low byte */
                /* if START-/XOR-values of CRC and E2E not equal an additional XOR of the start value must be done */
                crc_u8 = Crc_CalculateCRC8(dataID_au8, 1U, (uint8)E2E_MASK_BYTE,
                                           (boolean)(0U == crcInitValue_u8));
            }
            else
            {
                /* counter is even: high byte */
                /* if START-/XOR-values of CRC and E2E not equal an additional XOR of the start value must be done */
                crc_u8 = Crc_CalculateCRC8(&dataID_au8[1U], 1U, (uint8)E2E_MASK_BYTE,
                                           (boolean)(0U == crcInitValue_u8));
            }
        }
        break;
    }

    crcOffset_u16 = Config_pst->CRCOffset / 8U;
    dataLength_u16 = Config_pst->DataLength / 8U;

    /* Crc calculation over data stream (before byte with CRC), step 1 */
    if (crcOffset_u16 >= 1U)
    {
        crc_u8 = Crc_CalculateCRC8(Data_pu8, crcOffset_u16, crc_u8, FALSE);
    }

    /* Crc calculation over data stream (after byte with CRC), step 2 */
    if (crcOffset_u16 < (dataLength_u16 - sizeof(crc_u8)))
    {
        crc_u8 = Crc_CalculateCRC8(&Data_pu8[crcOffset_u16 + sizeof(crc_u8)],
                                   (dataLength_u16 - crcOffset_u16 - sizeof(crc_u8)),
                                   crc_u8,
                                   FALSE);
    }

    if (0U != crcInitValue_u8)
    {
        /* To negate the last XOR 0xFF operation done on computed CRC additional XORing performed */
        crc_u8 ^= (uint8)E2E_MASK_BYTE;
    }

    return (crc_u8);
}

/* E2E_PRV_P01_H */
#endif
