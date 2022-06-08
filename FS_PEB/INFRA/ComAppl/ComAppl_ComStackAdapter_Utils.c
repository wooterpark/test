/*<BASDKey>
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, ETAS GmbH, 2019. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 * Administrative Information (automatically filled in)
 * $Domain____:$
 * $Namespace_:$
 * $Class_____:$
 * $Name______:$
 * $Variant___:$
 * $Revision__:$
 **********************************************************************************************************************
</BASDKey>*/
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "ComAppl_ComStackAdapter_Utils.h"


static const uint32 ComAppl_BitMaskTable[33] =
{
    0x00000000u,
    0x00000001u,
    0x00000003u,
    0x00000007u,
    0x0000000Fu,
    0x0000001Fu,
    0x0000003Fu,
    0x0000007Fu,
    0x000000FFu,
    0x000001FFu,
    0x000003FFu,
    0x000007FFu,
    0x00000FFFu,
    0x00001FFFu,
    0x00003FFFu,
    0x00007FFFu,
    0x0000FFFFu,
    0x0001FFFFu,
    0x0003FFFFu,
    0x0007FFFFu,
    0x000FFFFFu,
    0x001FFFFFu,
    0x003FFFFFu,
    0x007FFFFFu,
    0x00FFFFFFu,
    0x01FFFFFFu,
    0x03FFFFFFu,
    0x07FFFFFFu,
    0x0FFFFFFFu,
    0x1FFFFFFFu,
    0x3FFFFFFFu,
    0x7FFFFFFFu,
    0xFFFFFFFFu,
};


/* SUPPORTED_SWITCH_SETTINGS:                                               */
/*                                                                          */
/* FS_NETGETSIGNAL_ON, FS_NETGETSIGNAL_OFF                                  */
/* FS_NETSETSIGNAL_ON, FS_NETSETSIGNAL_OFF                                  */
/* FS_NETPARITYCHECK_ON, FS_NETPARITYCHECK_OFF                              */
/* FS_NETCANDEBUG_OFF, FS_NETCANDEBUG_ON                                    */
/*                                                                          */
#define FS_NETCANDEBUG_ON   TRUE
#define FS_NETGETSIGNAL_ON  TRUE
#define FS_NETSETSIGNAL_ON  TRUE
#define FS_NETPARITYCHECK_ON    TRUE
#define NTSIMULATION 123

#define FS_NETCANDEBUG FS_NETCANDEBUG_ON
#define FS_NETGETSIGNAL FS_NETGETSIGNAL_ON
#define FS_NETSETSIGNAL FS_NETSETSIGNAL_ON
#define FS_NETPARITYCHECK FS_NETPARITYCHECK_ON

#ifndef FS_NETGETSIGNAL
  #error (undefined function switch: FS_NETGETSIGNAL)
#endif
#ifndef FS_NETSETSIGNAL
  #error (undefined function switch: FS_NETSETSIGNAL)
#endif
#ifndef FS_NETPARITYCHECK
  #error (undefined function switch: FS_NETPARITYCHECK)
#endif
/*
 **********************************************************************************************************************
 * Function declarations
 **********************************************************************************************************************
*/
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
static void ComAppl_Invert_V(uint8* vektor_pub, uint8 length_ub);
#endif
static uint8 Convert_MotorolaFwLsb_To_MotorolaFwMsb(uint8 bitpos, uint8 bitsize);
/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
static void ComAppl_Invert_V(uint8* vektor_pub, uint8 length_ub)
{
    uint8 l_temp_UB, i;

    for(i=0; i<(length_ub/2); i++)
    {
        l_temp_UB                 = vektor_pub[i];
        vektor_pub[i]             = vektor_pub[length_ub-1-i];
        vektor_pub[length_ub-1-i] = l_temp_UB;
    }
}
#endif

#if (FS_NETCANDEBUG == FS_NETCANDEBUG_ON)
  #if(FS_NETGETSIGNAL == FS_NETGETSIGNAL_ON)
/*
 **********************************************************************************************************************
 * Function : Convert_MotorolaFwLsb_To_MotorolaFwMsb  (fully support of Motorola format at CAN)
 *
 * Description
 * applicable only to motorola formats(motorola forward msb)
 * using the bit position(msb) and the bit size
 * calculates the lsb position which is used in the packsignal and unpacksignal functions
 *
 * Interface
 *   Input :   uint8 bitpos         bit position of the msb bit of the signal in the pdu
 *             uint8 bitsize        bit size of the signal
 *   Output :  uint8 bitpos         lsb position of the signal
 *   Return : lsb position of the signal
 **********************************************************************************************************************
*/
static uint8 Convert_MotorolaFwLsb_To_MotorolaFwMsb(uint8 bitpos, uint8 bitsize)
{
    uint8 length = 1;
    while(length < bitsize)
    {
        if ( ((bitpos%8)==0) && (length<bitsize))
        {
            bitpos+=15;
            length++;

        }
        if (length<bitsize)
        {
            bitpos--;
            length++;
        }
    }
    return bitpos;
}

  #endif
#endif


#if(FS_NETGETSIGNAL == FS_NETGETSIGNAL_ON)

uint32 ComAppl_UnPackSignal(const uint8* Src_Buf,
                             uint8 Bit_Pos,
                             uint8 Bitsize,
                             boolean  IntelFormat,
                             uint8 MsgLength)
{

    uint8 ByteNo;
    uint8 Bits_left;
    uint8 Total_BitsCopied;
    uint32 a_data;
    uint32 shifted_value;
    uint8 Bit_Pos_intern;

    if(IntelFormat==FALSE)
    {
        Bit_Pos_intern=Convert_MotorolaFwLsb_To_MotorolaFwMsb(Bit_Pos,Bitsize);
    }
    else
    {
        Bit_Pos_intern = Bit_Pos;
    }

    (void)MsgLength;
    /* Src_Buf = Src_Buf;  Introduced for MISRA sake. Will be removed by Optimiser anyway : MISRA 3673 warning :The object addressed by the pointer parameter  is not modified and so the pointer could be of type pointer to const.*/
    a_data = 0x00;

    /*Finding the 1st Byte No*/
    ByteNo = (Bit_Pos_intern >> 3u);

    if((((ByteNo*8)+8) - Bit_Pos_intern)<= Bitsize)
    {
        /*This Part will be executed if the Signal is placed in more than 1 byte */
        Total_BitsCopied = (((ByteNo*8)+8) - Bit_Pos_intern);

        a_data = *(Src_Buf + ByteNo)>> (Bit_Pos_intern - (ByteNo *8));
    }
    else
    {
        /*This Part will be executed if the Signal is placed within the same byte */
        a_data = *(Src_Buf + ByteNo)>> (Bit_Pos_intern - (ByteNo *8));
        a_data = a_data & (uint32)(~(0xFFuL << Bitsize));
        Total_BitsCopied = Bitsize;
    }


    while (Total_BitsCopied < Bitsize)
    {
        Bits_left = Bitsize - Total_BitsCopied;

        if(IntelFormat == TRUE)
        {
            ByteNo++;
        }
        else
        {
            ByteNo--;
        }

        if(Bits_left >= 8)
        {
            shifted_value = (*(Src_Buf + ByteNo) << Total_BitsCopied);
            a_data =  shifted_value | a_data;
            Total_BitsCopied = Total_BitsCopied + 8;
        }
        else
        {
            shifted_value = ((*(Src_Buf + ByteNo) & (0xFFu >> (8 - Bits_left))) << Total_BitsCopied);
            a_data = shifted_value | a_data;
            Total_BitsCopied = Total_BitsCopied + Bits_left;
        }

    }

    /*Return the Unpacked data*/
    return(a_data);
}
/* end of function ComAppl_UnPackSignal */
#endif

#if(FS_NETSETSIGNAL == FS_NETSETSIGNAL_ON)

void ComAppl_PackSignal(uint8* Dest_Buf,
                            uint32 Src_Buf,
                            uint8 Bit_Pos,
                            uint8 Bitsize,
                            boolean IntelFormat,
                            uint8 MsgLength)
{

/* Bfx - AR specific service library is not used, for the signal packing operations for below reasons
 * 1. There is a function Bfx_GetBits which takes a variable of type (uint8/16/32), extracts bits from it,
 * returns the data in the same respective type(uint8/16/32).If this api is used in Com, there will still be many bit operations(Bitshift etc..)
 * which have to be performed in the Com code,hence there is no much help,as bit operations (significant in number) are done both in Com and SrvLib.
 */

    uint8 ByteNo;
    uint8 BitOffsetInByte;
    uint8 Mask;
    uint8 Bit_Pos_intern;
    uint16 Bits_left;
    uint16 Total_BitsCopied;
    uint32 a_data;

    if(IntelFormat==FALSE)
    {
        Bit_Pos_intern=Convert_MotorolaFwLsb_To_MotorolaFwMsb(Bit_Pos,Bitsize);
    }
    else
    {
        Bit_Pos_intern = Bit_Pos;
    }

    (void)MsgLength;
    a_data = 0x00;

    if(Bitsize != 32u)
    {
        Src_Buf = Src_Buf & (~(0xFFFFFFFFu << Bitsize));
    }

    ByteNo = Bit_Pos_intern >> 3u;
    BitOffsetInByte = Bit_Pos_intern - (ByteNo * 8);

    a_data = Src_Buf << BitOffsetInByte;

    /*If the value is within the same byte */
    if((((ByteNo*8)+8) - Bit_Pos_intern) <= Bitsize)
    {
        Mask =(uint8)( ~(0xFFuL << BitOffsetInByte));
        Total_BitsCopied = (((ByteNo*8)+8) - Bit_Pos_intern);
    }
    /* If the value is spread across bytes */
    else
    {
        Mask = (uint8) (~(ComAppl_BitMaskTable[Bitsize] << BitOffsetInByte));
        Total_BitsCopied = Bitsize;
    }

    *(Dest_Buf+ByteNo) = ((*(Dest_Buf+ByteNo)) & Mask)  | (uint8)a_data;

    while (Total_BitsCopied < Bitsize)
    {
        Bits_left = Bitsize - Total_BitsCopied;

        if(IntelFormat == TRUE)
        {
            ByteNo++;
        }
        else
        {
            ByteNo--;
        }

        a_data = Src_Buf >> Total_BitsCopied;

        if(Bits_left >= 8)
        {
            *(Dest_Buf+ByteNo) = (uint8)a_data;
            Total_BitsCopied = Total_BitsCopied + 8;
        }
        else
        {
            Mask = (uint8)(0xFFuL << Bits_left);
            *(Dest_Buf+ByteNo) = *(Dest_Buf+ByteNo) & Mask;
            *(Dest_Buf+ByteNo) = *(Dest_Buf+ByteNo) | (uint8)a_data;

            Total_BitsCopied = Total_BitsCopied + Bits_left;
        }
    }

}
/* end of function ComAppl_PackSignal */
#endif

/*<BASDKey>
 **********************************************************************************************************************
 * $History___:$
 **********************************************************************************************************************
</BASDKey>*/
