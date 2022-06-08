/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#ifndef E2E_PRV_P07_H
#define E2E_PRV_P07_H

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

#define E2E_P07_DELTACOUNTER_REPEATED         0U            /* Delta counter value when message repeated */
#define E2E_P07_DELTACOUNTER_OK               1U            /* Delta counter value when next message received */
#define E2E_P07_LENGTH_OFFSET                 8U            /* Length offset within datastream */
#define E2E_P07_COUNTER_OFFSET                12U           /* Counter offset within datastream */
#define E2E_P07_DATAID_OFFSET                 16U           /* DataID offset within datastream */
#define E2E_P07_HEADER_SIZE                   160U          /* Size of E2E header in bits */


/*
 **********************************************************************************************************************
 Prototypes for private routines for the E2E library
 **********************************************************************************************************************
 */

LOCAL_INLINE boolean  E2E_Prv_P07CheckConfigType(const E2E_P07ConfigType * const Config_pst);
LOCAL_INLINE boolean  E2E_Prv_P07CheckData(const E2E_P07ConfigType * const Config_pst, const uint8 * const Data_pu8,
                                           uint32 Length_u32);
LOCAL_INLINE uint32   E2E_Prv_P07MaxDeltaCounter(uint32 ReceivedCounter_u32, uint32 LastValidCounter_u32);
LOCAL_INLINE uint32   E2E_Prv_P07ReadU32(const uint8 * const Data_pu8, uint32 offset_u32);
LOCAL_INLINE void     E2E_Prv_P07WriteU32(uint8 * const Data_pu8, uint32 offset_u32, uint32 value_u32);
LOCAL_INLINE uint64   E2E_Prv_P07ReadU64(const uint8 * const Data_pu8, uint32 offset_u32);
LOCAL_INLINE void     E2E_Prv_P07WriteU64(uint8 * const Data_pu8, uint32 offset_u32, uint64 value_u64);
LOCAL_INLINE uint64   E2E_Prv_P07CalcCRC64(const E2E_P07ConfigType * const Config_pst, const uint8 * const Data_pu8,
                                           uint32 Length_u32);

/*
 **********************************************************************************************************************
 private routines for E2E profile P07
 **********************************************************************************************************************
 */

/**
 ***********************************************************************************************************************
 * E2E_Prv_P07CheckConfigType
 *
 * \brief Tests the input parameter E2E_P07ConfigType for correctness
 *
 * Description: Tests the input parameter E2E_P07ConfigType for correctness
 * The range of the variable is restricted by the E2E specification:
 * - byte alignment for offset
 * - byte alignment for minimum data stream length
 * - minimum required data length
 * - byte alignment for maximum data stream length
 * - minimum data stream length has to be smaller than the maximum data stream length
 * - offset has to be smaller than data stream length - E2E header size
 * When at minimum on of the test fails, the function returns FALSE
 * The E2_P07Protect or E2E_P07Check function is interrupted and returns an error message.
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
 * \param   E2E_P07ConfigType       *Config_pst  Pointer to the configuration structure of E2E profile P07
 * \return  boolean                              returns TRUE if the check is ok, otherwise returns FALSE
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE boolean E2E_Prv_P07CheckConfigType(const E2E_P07ConfigType * const Config_pst)
{
    return ((boolean)(((Config_pst->Offset % 8U) == 0U) &&
                      ((Config_pst->MinDataLength % 8U) == 0U) &&
                      (Config_pst->MinDataLength >= E2E_P07_HEADER_SIZE) &&
                      ((Config_pst->MaxDataLength % 8U) == 0U) &&
                      (Config_pst->MinDataLength <= Config_pst->MaxDataLength) &&
                      (Config_pst->Offset <= (Config_pst->MaxDataLength - E2E_P07_HEADER_SIZE))));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P07CheckData
 *
 * \brief Tests the input parameters DataPtr and Length for correctness
 *
 * Description: Tests the input parameter DataPtr and Length for correctness
 * In case the functions returns a FALSE, the E2E_P07Check routine is interrupted.
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
 * \param   E2E_P07ConfigType       *Config_pst   Pointer to the configuration structure of E2E profile P07
 * \param   uint8                   *Data_pu8     Pointer to the byte sequence within the Data to be checked
 * \param   uint32                  Length        Length of the data in bytes
 * \return  boolean                               returns TRUE if the check is ok, otherwise returns FALSE
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE boolean E2E_Prv_P07CheckData(const E2E_P07ConfigType * const Config_pst, const uint8 * const Data_pu8,
                                          uint32 Length_u32)
{
    return ((boolean)(((NULL_PTR != Data_pu8) && (0U != Length_u32) &&
                       (Length_u32 >= (Config_pst->MinDataLength / 8U)) &&
                       (Length_u32 <= (Config_pst->MaxDataLength / 8U))) ||
                      ((NULL_PTR == Data_pu8) && (0U == Length_u32))));
}

/**
 *******************************************************************************************************************
 * E2E_Prv_P07MaxDeltaCounter
 *
 * \brief       Calculates the deltaCounter as difference between ReceivedCounter and LastValidCounter.
  *
 * Description: Service calculates the Delta of two counter
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
 * \param   uint32  ReceivedCounter_u32   New Counter
 * \param   uint32  LastValidCounter_u32  Old valid Counter
 * \return  uint32  deltaCounter_u32      Difference of two Counters
 *
 *******************************************************************************************************************
 */

LOCAL_INLINE uint32 E2E_Prv_P07MaxDeltaCounter(uint32 ReceivedCounter_u32, uint32 LastValidCounter_u32)
{
    return (ReceivedCounter_u32 - LastValidCounter_u32);
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P07ReadU32
 *
 * \brief Read an U32 value from data stream
 *
 * Description: Read an U32 value from datastream regarding the endianess.
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
 * \param   uint8                   *Data_pu8     Pointer to the byte sequence within the Data
 * \param   uint32                  offset_u32    Offset of value within data stream
 * \return  uint32                                returns U32 value from data stream
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE uint32 E2E_Prv_P07ReadU32(const uint8 * const Data_pu8, uint32 offset_u32)
{
    /* Read U32 value from Data (big endian order and bit order is flipped) */
    return (((uint32)((uint32)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u32])      << 24U)) |
            ((uint32)((uint32)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u32 + 1U]) << 16U)) |
            ((uint32)((uint32)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u32 + 2U]) << 8U))  | 
            ((uint32)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u32 + 3U])));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P07WriteU32
 *
 * \brief Write an U32 value into data stream
 *
 * Description: Write an U32 value into datastream regarding the endianess and bit order.
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
 * \param   uint8                   *Data_pu8     Pointer to the byte sequence within the Data
 * \param   uint32                  offset_u32    Offset of value within data stream
 * \param   uint32                  value_u32     U32 value to write into the data stream
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE void E2E_Prv_P07WriteU32(uint8 * const Data_pu8, uint32 offset_u32, uint32 value_u32)
{
    /* Write U32 value into the specified region of data (big endian order and bit order is flipped) */
    Data_pu8[offset_u32]      = E2E_Prv_ReverseBitsU8((uint8)(value_u32 >> 24U));
    Data_pu8[offset_u32 + 1U] = E2E_Prv_ReverseBitsU8((uint8)(value_u32 >> 16U));
    Data_pu8[offset_u32 + 2U] = E2E_Prv_ReverseBitsU8((uint8)(value_u32 >> 8U));
    Data_pu8[offset_u32 + 3U] = E2E_Prv_ReverseBitsU8((uint8)(value_u32));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P07ReadU64
 *
 * \brief Read an U64 value from data stream
 *
 * Description: Read an U64 value from datastream regarding the endianess.
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
 * \param   uint8                   *Data_pu8     Pointer to the byte sequence within the Data
 * \param   uint32                  offset_u32    Offset of value within data stream
 * \return  uint64                                returns U64 value from data stream
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE uint64 E2E_Prv_P07ReadU64(const uint8 * const Data_pu8, uint32 offset_u32)
{
    /* Read U64 value from Data (big endian order and bit order is flipped) */
    return (((uint64)((uint64)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u32])      << 56U)) |
            ((uint64)((uint64)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u32 + 1U]) << 48U)) |
            ((uint64)((uint64)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u32 + 2U]) << 40U)) |
            ((uint64)((uint64)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u32 + 3U]) << 32U)) |
            ((uint64)((uint64)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u32 + 4U]) << 24U)) |
            ((uint64)((uint64)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u32 + 5U]) << 16U)) |
            ((uint64)((uint64)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u32 + 6U]) << 8U))  | 
            ((uint64)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u32 + 7U])));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P07WriteU64
 *
 * \brief Write an U64 value into data stream
 *
 * Description: Write an U64 value into datastream regarding the endianess and bit order.
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
 * \param   uint8                   *Data_pu8     Pointer to the byte sequence within the Data
 * \param   uint32                  offset_u32    Offset of value within data stream
 * \param   uint64                  value_u64     U64 value to write into the data stream
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE void E2E_Prv_P07WriteU64(uint8 * const Data_pu8, uint32 offset_u32, uint64 value_u64)
{
    /* Write U64 value into the specified region of data (big endian order and bit order is flipped) */
    Data_pu8[offset_u32]      = E2E_Prv_ReverseBitsU8((uint8)(value_u64 >> 56U));
    Data_pu8[offset_u32 + 1U] = E2E_Prv_ReverseBitsU8((uint8)(value_u64 >> 48U));
    Data_pu8[offset_u32 + 2U] = E2E_Prv_ReverseBitsU8((uint8)(value_u64 >> 40U));
    Data_pu8[offset_u32 + 3U] = E2E_Prv_ReverseBitsU8((uint8)(value_u64 >> 32U));
    Data_pu8[offset_u32 + 4U] = E2E_Prv_ReverseBitsU8((uint8)(value_u64 >> 24U));
    Data_pu8[offset_u32 + 5U] = E2E_Prv_ReverseBitsU8((uint8)(value_u64 >> 16U));
    Data_pu8[offset_u32 + 6U] = E2E_Prv_ReverseBitsU8((uint8)(value_u64 >> 8U));
    Data_pu8[offset_u32 + 7U] = E2E_Prv_ReverseBitsU8((uint8)(value_u64));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P07CalcCRC64
 *
 * \brief private routine to calculate CRC64 over the data stream and the DataID for profile P07 of E2E library
 *
 * Description:
 * Private routine to calculate CRC64 in profile P07 main routines of E2E library
 * CRC calculation is split in 2 parts: crc over the data stream and crc over parts of the header.
 * The crc byte itself is excluded from the crc calculation. It is the last byte of the data stream.
 * It is required to compensate the rest manipulation from Crc_CalculateCRC64, thus the
 * temporary results have to be manipulated before their use as initial value for next part of crc calculation.
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
 * \param   E2E_P07ConfigType      *Config_pst  Pointer to the configuration structure
 * \param   uint8                  *Data_pu8    Pointer to the data to protect
 * \param   uint32                 Length       Length of the data in bytes
 * \return  uint64                              result of CRC64 over data and header
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE uint64 E2E_Prv_P07CalcCRC64(const E2E_P07ConfigType * const Config_pst, const uint8 * const Data_pu8,
                                         uint32 Length_u32)
{
    uint64 crc_u64 = 0U;
    uint32 offset_u32 = Config_pst->Offset / 8U;


    /* Calculate CRC over data exclusive the CRC byte */
    /* Length used for CRC calculation is the data length minus the offset minus the size of the CRC */
    if (offset_u32 >= 1U)
    {
        crc_u64 = Crc_CalculateCRC64(Data_pu8, offset_u32, (uint64)E2E_MASK_QWORD, TRUE);
        crc_u64 = Crc_CalculateCRC64(&Data_pu8[offset_u32 + sizeof(crc_u64)],
                                     Length_u32 - offset_u32 - sizeof(crc_u64),
                                     crc_u64,
                                     FALSE);
    }
    else
    {
        /* 0 == Config_pst->Offset */
        crc_u64 = Crc_CalculateCRC64(&Data_pu8[sizeof(crc_u64)],
                                     Length_u32 - sizeof(crc_u64),
                                     (uint64)E2E_MASK_QWORD,
                                     TRUE);
    }

    return (crc_u64);
}

/* E2E_PRV_P07_H */
#endif
