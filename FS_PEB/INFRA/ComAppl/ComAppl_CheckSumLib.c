#include "ComAppl_CheckSumLib.h"

const uint16 CanIdTmp_u16[10] = {0x229,0x215,0x375,0x379,0x8C,0x1f8,0x238,0x2a8,0x348,0x438};
const uint8 DataCrcTmp_cst[256] = {	0x00, 0x1d, 0x3a, 0x27, 0x74, 0x69, 0x4e, 0x53,//0~7
									0xe8, 0xf5, 0xd2, 0xcf, 0x9c, 0x81, 0xa6, 0xbb,//8~15
									0xcd, 0xd0, 0xf7, 0xea, 0xb9, 0xa4, 0x83, 0x9e,//16~23
									0x25, 0x38, 0x1f, 0x02, 0x51, 0x4c, 0x6b, 0x76,//24~31
									0x87, 0x9a, 0xbd, 0xa0, 0xf3, 0xee, 0xc9, 0xd4,//32~39
									0x6f, 0x72, 0x55, 0x48, 0x1b, 0x06, 0x21, 0x3c,//40~47
									0x4a, 0x57, 0x70, 0x6d, 0x3e, 0x23, 0x04, 0x19,//48~55
									0xa2, 0xbf, 0x98, 0x85, 0xd6, 0xcb, 0xec, 0xf1,//56~63
									0x13, 0x0e, 0x29, 0x34, 0x67, 0x7a, 0x5d, 0x40,//64~71
									0xfb, 0xe6, 0xc1, 0xdc, 0x8f, 0x92, 0xb5, 0xa8,//72~79
									0xde, 0xc3, 0xe4, 0xf9, 0xaa, 0xb7, 0x90, 0x8d,//80~87
									0x36, 0x2b, 0x0c, 0x11, 0x42, 0x5f, 0x78, 0x65,//88~95
									0x94, 0x89, 0xae, 0xb3, 0xe0, 0xfd, 0xda, 0xc7,//96~103
									0x7c, 0x61, 0x46, 0x5b, 0x08, 0x15, 0x32, 0x2f,//104~111
									0x59, 0x44, 0x63, 0x7e, 0x2d, 0x30, 0x17, 0x0a,//112~119
									0xb1, 0xac, 0x8b, 0x96, 0xc5, 0xd8, 0xff, 0xe2,//120~127
									0x26, 0x3b, 0x1c, 0x01, 0x52, 0x4f, 0x68, 0x75,//128~135
									0xce, 0xd3, 0xf4, 0xe9, 0xba, 0xa7, 0x80, 0x9d,//136~143
									0xeb, 0xf6, 0xd1, 0xcc, 0x9f, 0x82, 0xa5, 0xb8,//144~151
									0x03, 0x1e, 0x39, 0x24, 0x77, 0x6a, 0x4d, 0x50,//152~159
									0xa1, 0xbc, 0x9b, 0x86, 0xd5, 0xc8, 0xef, 0xf2,//160~167
									0x49, 0x54, 0x73, 0x6e, 0x3d, 0x20, 0x07, 0x1a,//168~175
									0x6c, 0x71, 0x56, 0x4b, 0x18, 0x05, 0x22, 0x3f,//176~183
									0x84, 0x99, 0xbe, 0xa3, 0xf0, 0xed, 0xca, 0xd7,//184~191
									0x35, 0x28, 0x0f, 0x12, 0x41, 0x5c, 0x7b, 0x66,//192~199
									0xdd, 0xc0, 0xe7, 0xfa, 0xa9, 0xb4, 0x93, 0x8e,//200~207
									0xf8, 0xe5, 0xc2, 0xdf, 0x8c, 0x91, 0xb6, 0xab,//208~215
									0x10, 0x0d, 0x2a, 0x37, 0x64, 0x79, 0x5e, 0x43,//216~223
									0xb2, 0xaf, 0x88, 0x95, 0xc6, 0xdb, 0xfc, 0xe1,//224~231
									0x5a, 0x47, 0x60, 0x7d, 0x2e, 0x33, 0x14, 0x09,//232~239
									0x7f, 0x62, 0x45, 0x58, 0x0b, 0x16, 0x31, 0x2c,//240~247
									0x97, 0x8a, 0xad, 0xb0, 0xe3, 0xfe, 0xd9, 0xc4 }; //248-255

uint8  VAR_CheckSumValue_u8;

static uint8 ComAppl_CheckSum_XOR8(const uint8* byteArray, uint8 byteArrayLen)
{
    uint8 i;
    uint8 cheksum = 0u;

    for(i = 0; i < byteArrayLen; i++)
    {
        cheksum = cheksum ^ byteArray[i];
    }
    return cheksum;
}

static uint8 ComAppl_CheckSum_Add8(const uint8* byteArray, uint8 byteArrayLen)
{
    uint8 i;
    uint8 cheksum = 0u;

    for(i = 0; i < byteArrayLen; i++)
    {
        cheksum = cheksum + byteArray[i];
    }
    return cheksum;
}
uint8 Com_CRC(uint8* BuffPtr)
{
	uint8 PduLength = 7;
	uint8 PduData[8] = {0,0,0,0,0,0,0,0};
	uint8 loop;
	uint8 DataCrcTmp_u8;
	DataCrcTmp_u8 = 0xff;
	PduData[0] = *(BuffPtr++);
	PduData[1] = *(BuffPtr++);
	PduData[2]= *(BuffPtr++);
	PduData[3] = *(BuffPtr++);
	PduData[4] = *(BuffPtr++);
	PduData[5] = *(BuffPtr++);
	PduData[6] = *(BuffPtr++);
	PduData[7] = *BuffPtr;
	for (loop=1;loop<=PduLength;loop++)
	{
		DataCrcTmp_u8 ^= PduData[loop];
		DataCrcTmp_u8 = DataCrcTmp_cst[DataCrcTmp_u8];
	}
	DataCrcTmp_u8 ^= 0xff;
    return DataCrcTmp_u8;
}

boolean ComAppl_EvalChk_XOR8(const uint8* pduPtr, uint8 pduLen,uint8 sigStartbit, uint8 sigLen, uint8* checksumPtr)
{
    uint8 calChecksum = 0x00;
    boolean result = TRUE;


    /* calculate the XOR8 for the whole Pdu, including the received checksum */
    calChecksum = ComAppl_CheckSum_XOR8(pduPtr, pduLen);

    /* Checksum logic is XOR: If the checksum received is wrong, XOR8 of the whole Pdu is a non zero value */
    if (calChecksum != 0u)
    {
        result = FALSE;
    }

    /* Set the inout parameter to the value of the calculated checksum. */
    (*checksumPtr) = (calChecksum ^ (*checksumPtr));

    return (result);
}

uint8 ComAppl_GenChk_XOR8(uint8* pduPtr, uint8 pduLen,uint8 sigStartbit, uint8 sigLen)
{
    uint8 chksum = 0x00;

    /* Prepare the array of bytes to calculate the Checksum. For XOR setting them to 0 will get the same result. */
    /* Calculate the checksum */
    chksum = ComAppl_CheckSum_XOR8(pduPtr, pduLen);

    return (chksum);
}


boolean ComAppl_EvalChk_Add8(const uint8* pduPtr, uint8 pduLen,uint8 sigStartbit, uint8 sigLen, uint8* checksumPtr)
{
    uint8 calChecksum = 0x00;
    boolean result = TRUE;

    /* calculate the XOR8 for the whole Pdu, including the received checksum */
    calChecksum = ComAppl_CheckSum_Add8(pduPtr, pduLen);

    /* Checksum logic is Add8: If the checksum received is wrong, XOR8 of the whole Pdu is a non zero value */
    if (calChecksum != *checksumPtr)
    {
        result = FALSE;
    }

    return (result);
}

uint8 ComAppl_GenChk_Add8(uint8* pduPtr, uint8 pduLen,uint8 sigStartbit, uint8 sigLen)
{
    uint8 chksum = 0x00;

    /* Prepare the array of bytes to calculate the Checksum. For XOR setting them to 0 will get the same result. */
    /* Calculate the checksum */
    chksum = ComAppl_CheckSum_Add8(pduPtr, pduLen);

    return (chksum);
}
boolean ComAppl_EvalChk_ComCrc(const uint8* pduPtr, uint8 pduLen,uint8 sigStartbit, uint8 sigLen, uint8* checksumPtr)
{
    uint8 calChecksum = 0x00;
    boolean result = TRUE;
    calChecksum = Com_CRC(pduPtr);
    VAR_CheckSumValue_u8 =calChecksum;
    if (calChecksum != *checksumPtr)
    {
        result = FALSE;
    }
    return (result);
}
