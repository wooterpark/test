/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#ifndef E2E_PRV_P04_H
#define E2E_PRV_P04_H

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

#define E2E_P04_DELTACOUNTER_REPEATED         0U            /* Delta counter value when message repeated */
#define E2E_P04_DELTACOUNTER_OK               1U            /* Delta counter value when next message received */
#define E2E_P04_COUNTER_OFFSET                2U            /* Counter offset within datastream */
#define E2E_P04_DATAID_OFFSET                 4U            /* DataID offset within datastream */
#define E2E_P04_CRC_OFFSET                    8U            /* CRC offset within datastream */
#define E2E_P04_HEADER_SIZE                   96U           /* Size of E2E header in bits */


/*
 **********************************************************************************************************************
 Prototypes for private routines for the E2E library
 **********************************************************************************************************************
 */

LOCAL_INLINE boolean  E2E_Prv_P04CheckConfigType(const E2E_P04ConfigType * const Config_pst);
LOCAL_INLINE boolean  E2E_Prv_P04CheckData(const E2E_P04ConfigType * const Config_pst, const uint8 * const Data_pu8,
                                           uint16 Length_u16);
LOCAL_INLINE uint16   E2E_Prv_P04MaxDeltaCounter(uint16 ReceivedCounter_u16, uint16 LastValidCounter_u16);
LOCAL_INLINE uint16   E2E_Prv_P04ReadU16(const uint8 * const Data_pu8, uint16 offset_u16);
LOCAL_INLINE void     E2E_Prv_P04WriteU16(uint8 * const Data_pu8, uint16 offset_u16, uint16 value_u16);
LOCAL_INLINE uint32   E2E_Prv_P04ReadU32(const uint8 * const Data_pu8, uint16 offset_u16);
LOCAL_INLINE void     E2E_Prv_P04WriteU32(uint8 * const Data_pu8, uint16 offset_u16, uint32 value_u32);
LOCAL_INLINE uint32   E2E_Prv_P04CalcCRC32P4(const E2E_P04ConfigType * const Config_pst, const uint8 * const Data_pu8,
                                           uint16 Length_u16);

/*
 **********************************************************************************************************************
 private routines for E2E profile P04
 **********************************************************************************************************************
 */

/**
 ***********************************************************************************************************************
 * E2E_Prv_P04CheckConfigType
 *
 * \brief Tests the input parameter E2E_P04ConfigType for correctness
 *
 * Description: Tests the input parameter E2E_P04ConfigType for correctness
 * The range of the variable is restricted by the E2E specification:
 * - byte alignment for offset
 * - byte alignment for minimum data stream length
 * - minimum required data length
 * - byte alignment for maximum data stream length
 * - minimum data stream length has to be smaller than the maximum data stream length
 * - offset has to be smaller than data stream length - E2E header size
 * When at minimum on of the test fails, the function returns FALSE
 * The E2_P04Protect or E2E_P04Check function is interrupted and returns an error message.
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
 * \param   E2E_P04ConfigType       *Config_pst  Pointer to the configuration structure of E2E profile P04
 * \return  boolean                              returns TRUE if the check is ok, otherwise returns FALSE
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE boolean E2E_Prv_P04CheckConfigType(const E2E_P04ConfigType * const Config_pst)
{
    return ((boolean)(((Config_pst->Offset % 8U) == 0U) &&
                      ((Config_pst->MinDataLength % 8U) == 0U) &&
                      (Config_pst->MinDataLength >= E2E_P04_HEADER_SIZE) &&
                      ((Config_pst->MaxDataLength % 8U) == 0U) &&
                      (Config_pst->MinDataLength <= Config_pst->MaxDataLength) &&
                      (Config_pst->Offset <= (Config_pst->MaxDataLength - E2E_P04_HEADER_SIZE))));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P04CheckData
 *
 * \brief Tests the input parameters DataPtr and Length for correctness
 *
 * Description: Tests the input parameter DataPtr and Length for correctness
 * In case the functions returns a FALSE, the E2E_P04Check routine is interrupted.
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
 * \param   E2E_P04ConfigType       *Config_pst   Pointer to the configuration structure of E2E profile P04
 * \param   uint8                   *Data_pu8     Pointer to the byte sequence within the Data to be checked
 * \param   uint16                  Length        Length of the data in bytes
 * \return  boolean                               returns TRUE if the check is ok, otherwise returns FALSE
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE boolean E2E_Prv_P04CheckData(const E2E_P04ConfigType * const Config_pst, const uint8 * const Data_pu8,
                                          uint16 Length_u16)
{
    return ((boolean)(((NULL_PTR != Data_pu8) && (0U != Length_u16) &&
                       (Length_u16 >= (Config_pst->MinDataLength / 8U)) &&
                       (Length_u16 <= (Config_pst->MaxDataLength / 8U))) ||
                      ((NULL_PTR == Data_pu8) && (0U == Length_u16))));
}

/**
 *******************************************************************************************************************
 * E2E_Prv_P04MaxDeltaCounter
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
 * \param   uint16  ReceivedCounter_u16   New Counter
 * \param   uint16  LastValidCounter_u16  Old valid Counter
 * \return  uint16  deltaCounter_u16      Difference of two Counters
 *
 *******************************************************************************************************************
 */

LOCAL_INLINE uint16 E2E_Prv_P04MaxDeltaCounter(uint16 ReceivedCounter_u16, uint16 LastValidCounter_u16)
{
    return (ReceivedCounter_u16 - LastValidCounter_u16);
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P04ReadU16
 *
 * \brief Read an U16 value from data stream
 *
 * Description: Read an U16 value from datastream regarding the endianess.
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
 * \param   uint16                  offset_u16    Offset of value within data stream
 * \return  uint16                                returns U16 value from data stream
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE uint16 E2E_Prv_P04ReadU16(const uint8 * const Data_pu8, uint16 offset_u16)
{
    /* Read U16 value from Data (big endian order and bit order is flipped) */
    return (((uint16)((uint16)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u16]) << 8U)) |
            ((uint16)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u16 + 1U])));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P04WriteU16
 *
 * \brief Write an U16 value into data stream
 *
 * Description: Write an U16 value into datastream regarding the endianess and bit order.
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
 * \param   uint16                  offset_u16    Offset of value within data stream
 * \param   uint16                  value_u16     U16 value to write into the data stream
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE void E2E_Prv_P04WriteU16(uint8 * const Data_pu8, uint16 offset_u16, uint16 value_u16)
{
    /* Write U16 value into the specified region of data (big endian order and bit order is flipped) */
    Data_pu8[offset_u16]      = E2E_Prv_ReverseBitsU8((uint8)(value_u16 >> 8U));
    Data_pu8[offset_u16 + 1U] = E2E_Prv_ReverseBitsU8((uint8)(value_u16));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P04ReadU32
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
 * \param   uint16                  offset_u16    Offset of value within data stream
 * \return  uint32                                returns U32 value from data stream
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE uint32 E2E_Prv_P04ReadU32(const uint8 * const Data_pu8, uint16 offset_u16)
{
    /* Read U32 value from Data (big endian order and bit order is flipped) */
    return (((uint32)((uint32)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u16])      << 24U)) |
            ((uint32)((uint32)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u16 + 1U]) << 16U)) |
            ((uint32)((uint32)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u16 + 2U]) << 8U))  | 
            ((uint32)E2E_Prv_ReverseBitsU8(Data_pu8[offset_u16 + 3U])));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P04WriteU32
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
 * \param   uint16                  offset_u16    Offset of value within data stream
 * \param   uint32                  value_u32     U32 value to write into the data stream
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE void E2E_Prv_P04WriteU32(uint8 * const Data_pu8, uint16 offset_u16, uint32 value_u32)
{
    /* Write U32 value into the specified region of data (big endian order and bit order is flipped) */
    Data_pu8[offset_u16]      = E2E_Prv_ReverseBitsU8((uint8)(value_u32 >> 24U));
    Data_pu8[offset_u16 + 1U] = E2E_Prv_ReverseBitsU8((uint8)(value_u32 >> 16U));
    Data_pu8[offset_u16 + 2U] = E2E_Prv_ReverseBitsU8((uint8)(value_u32 >> 8U));
    Data_pu8[offset_u16 + 3U] = E2E_Prv_ReverseBitsU8((uint8)(value_u32));
}

/**
 ***********************************************************************************************************************
 * E2E_Prv_P04CalcCRC32P4
 *
 * \brief private routine to calculate CRC32 for profile P04 of E2E library
 *
 * Description:
 * Private routine to calculate CRC32 in profile P04 main routines of E2E library
 * CRC calculation is split in 2 parts: 
 *  - crc over the data stream and parts of the header (Length + Counter + DataID)
 *  - crc over bytes that are after CRC (if any) 
 * The crc byte itself is excluded from the crc calculation.
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
 * \param   E2E_P04ConfigType      *Config_pst  Pointer to the configuration structure
 * \param   uint8                  *Data_pu8    Pointer to the data to protect
 * \param   uint16                 Length       Length of the data in bytes
 * \return  uint32                              result of CRC32 over data and header
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE uint32 E2E_Prv_P04CalcCRC32P4(const E2E_P04ConfigType * const Config_pst, const uint8 * const Data_pu8,
                                         uint16 Length_u16)
{
    /* TRACE[SWS_E2E_00329], TRACE[SWS_E2E_00330], TRACE[SWS_E2E_00367] */
    uint32 crc_u32 = 0U;
    uint16 offset_u16 = Config_pst->Offset / 8U;
    uint16 headerSize_u16 = E2E_P04_HEADER_SIZE / 8U;


    /* Calculate CRC over data exclusive the CRC byte */
    crc_u32 = Crc_CalculateCRC32P4(Data_pu8, offset_u16 + 8, (uint32)E2E_MASK_QWORD4, TRUE);
    
    /* Length used for CRC calculation is the data length minus the offset minus the size of header in bytes */
    if ((offset_u16 + headerSize_u16) < Length_u16)
    {
        crc_u32 = Crc_CalculateCRC32P4(&Data_pu8[offset_u16 + headerSize_u16], 
                                      Length_u16 - offset_u16 - headerSize_u16, 
                                      crc_u32, 
                                      FALSE);
    }
    
    return (crc_u32);
}

/* E2E_PRV_P04_H */
#endif
