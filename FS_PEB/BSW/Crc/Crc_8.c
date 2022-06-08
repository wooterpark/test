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
#include "Crc.h"

/**
 **********************************************************************************************************************
 * Crc_calculateCRC8
 *
 * \brief Calculates the rest of a of a polynomial division: input ist divided by the CRC8H1D = SAE J 1850 polynomial
 *
 * Description: Calculates the crc remainder of a data stream. Crc polynomial is CRC8H1D = SAE-J-1850 polynomial.
 * The crc calculation starts with an initial value, Crc_StartValue8.
 * The data stream is transmitted via pointer *Crc_DataPtr and is of length Crc_Length.
 * The crc remainder is modified by a XOR operation using the value CRC_XOR_VALUE8.
 *
 * \param    Crc_DataPtr,      Pointer to start address of data block
 * \param    Crc_Length,       Length of data block to be calculated in bytes
 * \param    Crc_StartValue8   Start value when the algorithm starts
 * \return                     Remainder after polynomial division *const Crc_DataPtr / CRC8H1D
 **********************************************************************************************************************
 */


/*
 **********************************************************************************************************************
 * TABLE Version, Revision_2
 **********************************************************************************************************************
*/

#define CRC_START_SEC_CONST_8
#include "Crc_MemMap.h"
const uint8  CRC_8_H1D_Tbl[((uint16)CRC_8_TABLESIZE)] =
{
    /*  0:*/ 0x00u, 0x1du, 0x3au, 0x27u, 0x74u, 0x69u, 0x4eu, 0x53u,
    /*  8:*/ 0xe8u, 0xf5u, 0xd2u, 0xcfu, 0x9cu, 0x81u, 0xa6u, 0xbbu,
    /* 16:*/ 0xcdu, 0xd0u, 0xf7u, 0xeau, 0xb9u, 0xa4u, 0x83u, 0x9eu,
    /* 24:*/ 0x25u, 0x38u, 0x1fu, 0x02u, 0x51u, 0x4cu, 0x6bu, 0x76u,
    /* 32:*/ 0x87u, 0x9au, 0xbdu, 0xa0u, 0xf3u, 0xeeu, 0xc9u, 0xd4u,
    /* 40:*/ 0x6fu, 0x72u, 0x55u, 0x48u, 0x1bu, 0x06u, 0x21u, 0x3cu,
    /* 48:*/ 0x4au, 0x57u, 0x70u, 0x6du, 0x3eu, 0x23u, 0x04u, 0x19u,
    /* 56:*/ 0xa2u, 0xbfu, 0x98u, 0x85u, 0xd6u, 0xcbu, 0xecu, 0xf1u,
    /* 64:*/ 0x13u, 0x0eu, 0x29u, 0x34u, 0x67u, 0x7au, 0x5du, 0x40u,
    /* 72:*/ 0xfbu, 0xe6u, 0xc1u, 0xdcu, 0x8fu, 0x92u, 0xb5u, 0xa8u,
    /* 80:*/ 0xdeu, 0xc3u, 0xe4u, 0xf9u, 0xaau, 0xb7u, 0x90u, 0x8du,
    /* 88:*/ 0x36u, 0x2bu, 0x0cu, 0x11u, 0x42u, 0x5fu, 0x78u, 0x65u,
    /* 96:*/ 0x94u, 0x89u, 0xaeu, 0xb3u, 0xe0u, 0xfdu, 0xdau, 0xc7u,
    /*104:*/ 0x7cu, 0x61u, 0x46u, 0x5bu, 0x08u, 0x15u, 0x32u, 0x2fu,
    /*112:*/ 0x59u, 0x44u, 0x63u, 0x7eu, 0x2du, 0x30u, 0x17u, 0x0au,
    /*120:*/ 0xb1u, 0xacu, 0x8bu, 0x96u, 0xc5u, 0xd8u, 0xffu, 0xe2u,
    /*128:*/ 0x26u, 0x3bu, 0x1cu, 0x01u, 0x52u, 0x4fu, 0x68u, 0x75u,
    /*136:*/ 0xceu, 0xd3u, 0xf4u, 0xe9u, 0xbau, 0xa7u, 0x80u, 0x9du,
    /*144:*/ 0xebu, 0xf6u, 0xd1u, 0xccu, 0x9fu, 0x82u, 0xa5u, 0xb8u,
    /*152:*/ 0x03u, 0x1eu, 0x39u, 0x24u, 0x77u, 0x6au, 0x4du, 0x50u,
    /*160:*/ 0xa1u, 0xbcu, 0x9bu, 0x86u, 0xd5u, 0xc8u, 0xefu, 0xf2u,
    /*168:*/ 0x49u, 0x54u, 0x73u, 0x6eu, 0x3du, 0x20u, 0x07u, 0x1au,
    /*176:*/ 0x6cu, 0x71u, 0x56u, 0x4bu, 0x18u, 0x05u, 0x22u, 0x3fu,
    /*184:*/ 0x84u, 0x99u, 0xbeu, 0xa3u, 0xf0u, 0xedu, 0xcau, 0xd7u,
    /*192:*/ 0x35u, 0x28u, 0x0fu, 0x12u, 0x41u, 0x5cu, 0x7bu, 0x66u,
    /*200:*/ 0xddu, 0xc0u, 0xe7u, 0xfau, 0xa9u, 0xb4u, 0x93u, 0x8eu,
    /*208:*/ 0xf8u, 0xe5u, 0xc2u, 0xdfu, 0x8cu, 0x91u, 0xb6u, 0xabu,
    /*216:*/ 0x10u, 0x0du, 0x2au, 0x37u, 0x64u, 0x79u, 0x5eu, 0x43u,
    /*224:*/ 0xb2u, 0xafu, 0x88u, 0x95u, 0xc6u, 0xdbu, 0xfcu, 0xe1u,
    /*232:*/ 0x5au, 0x47u, 0x60u, 0x7du, 0x2eu, 0x33u, 0x14u, 0x09u,
    /*240:*/ 0x7fu, 0x62u, 0x45u, 0x58u, 0x0bu, 0x16u, 0x31u, 0x2cu,
    /*248:*/ 0x97u, 0x8au, 0xadu, 0xb0u, 0xe3u, 0xfeu, 0xd9u, 0xc4u
};
#define CRC_STOP_SEC_CONST_8
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

uint8 Crc_CalculateCRC8(const uint8* Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8,
                        boolean Crc_IsFirstCall)
{
    uint32_least  index;
    uint8         result;
    uint8         crcTemp;


    if (Crc_IsFirstCall != FALSE)
    {
        crcTemp = CRC_INITIAL_VALUE8;
    }
    else
    {
        crcTemp = Crc_StartValue8 ^ CRC_XOR_VALUE8;
    }

    for (index = 0U; index < Crc_Length; ++index)
    {
        /* Impact of temporary rest on next crc rest */
        crcTemp ^= Crc_DataPtr[index];

        /* Next temporary crc rest */
        crcTemp  = CRC_8_H1D_Tbl[crcTemp];
    }
    result = crcTemp ^ CRC_XOR_VALUE8;

    return (result);
}

#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

