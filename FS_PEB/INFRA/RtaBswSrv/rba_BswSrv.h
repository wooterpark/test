


#ifndef RBA_BSWSRV_H
#define RBA_BSWSRV_H

/*
 * important note about Core numbering scheme:
 * ============================================
 * IFX physical         JDP physical        Logical (OS)        Core usage
 * core numbering       core numbering      core numbering
 * -------------------------------------------------------------------------------
 *      0                    2                   0              BSW + boot
 *      1                    0                   1              ASW + Checker core
 *      2                    1                   2              ASW
 * -------------------------------------------------------------------------------
 *
 * For Device2, the logical core #2 is missing
 * For Device1, the only core is numbered "physical core #0" for both IFX and JDP. This reduces resource consumption.
 * Both scheduling and memory layout use the logical numbering scheme.
 */

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "Std_Types.h"
#include "rba_BswSrv_Cfg.h"
#include "rba_Reg_csfr_ifx_tc27x.h"
#include "IfxStm_reg.h"

/*
 ***************************************************************************************************
 * Defines
 ***************************************************************************************************
 */
/* Vendor and module identification */
#define RBA_BSWSRV_VENDOR_ID   (6)
#define RBA_BSWSRV_MODULE_ID   (255)
#define RBA_BSWSRV_INSTANCE_ID (0)

/* Module version information */
#define RBA_BSWSRV_SW_MAJOR_VERSION (3)
#define RBA_BSWSRV_SW_MINOR_VERSION (0)
#define RBA_BSWSRV_SW_PATCH_VERSION (0)

#  define RBA_BSWSRV_NOP()                      asm volatile ("nop" : : : "memory")

#ifndef RBA_BSWSRV_NUM_USED_CORE
# define MCU_RB_NR_OF_AVL_CORES (3U)
#endif

#define RBA_BSWSRV_PARAM_UNUSED(param)          (void)(param)

typedef unsigned long long rba_BswSrv_uint64;
// for testing purposes only
//#define RBA_BSWSRV_PRV_C_IMPL
//#define RBA_BSWSRV_PRV_C_LOCK
//#define RBA_BSWSRV_PRV_SWAP_LOCK

/* for backward compatibility to older MCAL versions */


/*
 ***************************************************************************************************
 * Variable declarations
 ***************************************************************************************************
 */

 /*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
 */




#define RBA_BSWSRV_START_SEC_CODE
#include "rba_BswSrv_MemMap.h"
extern void* rba_BswSrv_MemCopy(void* xDest_pv, const void* xSrc_pcv, uint32 numBytes_u32);
extern void* rba_BswSrv_MemSet(void* xDest_pv, sint32 xPattern_u32, uint32 numBytes_u32);
extern sint32 rba_BswSrv_MemCompare(const void* xSrc1_pcv, const void* xSrc2_pcv, uint32 numBytes_u32);
#define RBA_BSWSRV_STOP_SEC_CODE
#include "rba_BswSrv_MemMap.h"
LOCAL_INLINE uint32 rba_BswSrv_CountLeadingZero32(uint32 Input_u32);
LOCAL_INLINE uint32 rba_BswSrv_ByteOrderSwap32(uint32 Input_u32);
LOCAL_INLINE uint16 rba_BswSrv_ByteOrderSwap16(uint16 Input_u16);
LOCAL_INLINE void   rba_BswSrv_MemCopy64(rba_BswSrv_uint64* xDest_pu64, const rba_BswSrv_uint64* xSrc_pcu64, uint32 numBytes_u32);
LOCAL_INLINE void   rba_BswSrv_MemCopy32(uint32* xDest_pu32, const uint32* xSrc_pcu32, uint32 numBytes_u32);
LOCAL_INLINE void   rba_BswSrv_MemCopy16(uint16* xDest_pu16, const uint16* xSrc_pcu16, uint32 numBytes_u32);
LOCAL_INLINE void   rba_BswSrv_MemCopy8(uint8* xDest_pu8, const uint8* xSrc_pcu8, uint32 numBytes_u32);
LOCAL_INLINE uint32 rba_BswSrv_MemCompare64(const rba_BswSrv_uint64* xSrc1_pcu64, const rba_BswSrv_uint64* xSrc2_pcu64, uint32 numBytes_u32);
LOCAL_INLINE uint32 rba_BswSrv_MemCompare32(const uint32* xSrc1_pcu32, const uint32* xSrc2_pcu32, uint32 numBytes_u32);
LOCAL_INLINE uint32 rba_BswSrv_MemCompare16(const uint16* xSrc1_pcu16, const uint16* xSrc2_pcu16, uint32 numBytes_u32);
LOCAL_INLINE uint32 rba_BswSrv_MemCompare8(const uint8* xSrc1_pcu8, const uint8* xSrc2_pcu8, uint32 numBytes_u32);
LOCAL_INLINE void   rba_BswSrv_MemSet64(rba_BswSrv_uint64* xDest_pu64, rba_BswSrv_uint64 xPattern_u64, uint32 numBytes_u32);
LOCAL_INLINE void   rba_BswSrv_MemSet32(uint32* xDest_pu32, uint32 xPattern_u32, uint32 numBytes_u32);
LOCAL_INLINE void   rba_BswSrv_MemSet16(uint16* xDest_pu16, uint32 xPattern_u32, uint32 numBytes_u32);
LOCAL_INLINE void   rba_BswSrv_MemSet8(uint8* xDest_pu8, uint32 xPattern_u32, uint32 numBytes_u32);

/*
 ***************************************************************************************************
 * Inline function definitions
 ***************************************************************************************************
 */



#define RBA_BSWSRV_DEBUG_HALT()                 rba_BswSrv_PrvDebugHalt()
#  define RBA_BSWSRV_IFX_ISYNC()                asm volatile ("isync" : : : "memory")
#  define RBA_BSWSRV_IFX_DSYNC()                asm volatile ("dsync" : : : "memory")
#define RBA_BSWSRV_SET_SEQUENCE_POINT()         asm volatile ("" ::: "memory")
#  define RBA_BSWSRV_IFX_MFCR(regaddr)          RBA_BSWSRV_IFX_MFCR_PRV(regaddr)
#  define RBA_BSWSRV_IFX_MFCR_PRV(regaddr)      \
            /* MISRA RULE 1.1,9.1 VIOLATION: statement expression is required by function */ \
            ({ uint32 res; asm volatile ("mfcr %0,"#regaddr : "=d" (res) : : "memory"); res; })
#  define RBA_BSWSRV_IFX_MTCR(regaddr,val)      RBA_BSWSRV_IFX_MTCR_PRV(regaddr,val)
#  define RBA_BSWSRV_IFX_MTCR_PRV(regaddr,val)  \
            asm volatile ("mtcr "#regaddr",%0" : : "d" (val) : "memory")

LOCAL_INLINE void rba_BswSrv_AtomicWrite32(volatile uint32* Var_pvu32, uint32 Value_u32);
LOCAL_INLINE void rba_BswSrv_AtomicSetBit32(volatile uint32* Var_pvu32, uint32 BitPos_u32);
LOCAL_INLINE void rba_BswSrv_AtomicClearBit32(volatile uint32* Var_pvu32, uint32 BitPos_u32);
LOCAL_INLINE void rba_BswSrv_AtomicOr32(volatile uint32* Var_pvu32, uint32 Value_u32);
LOCAL_INLINE void rba_BswSrv_AtomicAnd32(volatile uint32* Var_pvu32, uint32 Value_u32);

/* rba_BswSrv_SyncWrite* functions ensure that values have been written into physical memory before end of function. */
LOCAL_INLINE void rba_BswSrv_SyncWrite8 (volatile uint8*  Var_pvu8,  uint8  Value_u8 );
LOCAL_INLINE void rba_BswSrv_SyncWrite16(volatile uint16* Var_pvu16, uint16 Value_u16);
LOCAL_INLINE void rba_BswSrv_PrvDebugHalt(void);

LOCAL_INLINE void rba_BswSrv_PrvDebugHalt(void)
{

    asm volatile ("debug" : : : "memory");

}




LOCAL_INLINE void rba_BswSrv_SyncWrite32(volatile uint32* Var_pvu32, uint32 Value_u32)
{

    *Var_pvu32 = Value_u32;
    RBA_BSWSRV_IFX_DSYNC();
    (void)*Var_pvu32;
    RBA_BSWSRV_SET_SEQUENCE_POINT();

}


LOCAL_INLINE uint32 rba_BswSrv_GetPhysCore(void)
{


    /* MISRA RULE 1.1,9.1 VIOLATION: statement expression is required by function */
    return RBA_BSWSRV_IFX_MFCR(RBA_REG_CSFR_CORE_ID_MXCR_OFFSET);

}

/**
 *********************************************************************
 * rba_BswSrv_AtomicWrite32
 *
 * Write 32 bit data compatible to atomic read-modify write
 * This is a possible workaround for a hardware which does not support fully atomic accesses.
 * JDP: previous write gets lost, if there is a concurrent "atomic set word if zero" stwdx
 *
 * \param   Var_pvu32       pointer to destination
 * \param   Value_u32       new value
 *********************************************************************
 */
/* MISRA RULE 16.7 VIOLATION: *Var_pvu32 is definitely modified by assembler statement. */
LOCAL_INLINE void rba_BswSrv_AtomicWrite32(volatile uint32* Var_pvu32, uint32 Value_u32)
{

    *Var_pvu32 = Value_u32;

}

/**
 *********************************************************************
 * rba_BswSrv_AtomicSetBit32
 *
 * Set specified bit in 32 bit data atomic
 *
 * \param   Var_pvu32       pointer to destination
 * \param   BitPos_u32      bit position
 *********************************************************************
 */
/* MISRA RULE 16.7 VIOLATION: *Var_pvu32 is definitely modified by assembler statement. */
LOCAL_INLINE void rba_BswSrv_AtomicSetBit32(volatile uint32* Var_pvu32, uint32 BitPos_u32)
{


    rba_BswSrv_uint64 temp_u64;
    asm volatile("imask %A1, 1, %2, 1; \n\
                  ldmst [%0]0, %A1" :"+a"(Var_pvu32), "=d"(temp_u64) : "d"(BitPos_u32) : "memory");

}

/**
 *********************************************************************
 * rba_BswSrv_AtomicClearBit32
 *
 * Clear specified bit in 32 bit data atomic
 *
 * \param   Var_pvu32       pointer to destination
 * \param   BitPos_u32      bit position
 *********************************************************************
 */
/* MISRA RULE 16.7 VIOLATION: *Var_pvu32 is definitely modified by assembler statement. */
LOCAL_INLINE void rba_BswSrv_AtomicClearBit32(volatile uint32* Var_pvu32, uint32 BitPos_u32)
{
    /* non atomic equivalent: *Var_pvu32 &= ~(1u << BitPos_u32) */

    rba_BswSrv_uint64 temp_u64;
    asm volatile("imask %A1, 0, %2, 1; \n\
                  ldmst [%0]0, %A1" :"+a"(Var_pvu32), "=d"(temp_u64) : "d"(BitPos_u32) : "memory");

}

/**
 *********************************************************************
 * rba_BswSrv_AtomicAnd32
 *
 * atomic and
 *
 * \param   Var_pvu32       pointer to destination
 * \param   Value_u32       and value
 *********************************************************************
 */
/* MISRA RULE 16.7 VIOLATION: *Var_pvu32 is definitely modified by assembler statement. */
LOCAL_INLINE void rba_BswSrv_AtomicAnd32(volatile uint32* Var_pvu32, uint32 Value_u32)
{
    /* non atomic equivalent: Var_pvu32 &= Value_u32 */

    rba_BswSrv_uint64 temp_u64 = ((rba_BswSrv_uint64)(~Value_u32)) << 32; /* And: mask = ~Value_u32 , data = 0 */
    asm volatile("ldmst [%0]0, %A1" ::"a"(Var_pvu32) , "d"(temp_u64) : "memory");

}

/**
 *********************************************************************
 * rba_BswSrv_AtomicOr32
 *
 * atomic or
 *
 * \param   Var_pvu32       pointer to destination
 * \param   Value_u32       or value
 *********************************************************************
 */
/* MISRA RULE 16.7 VIOLATION: *Var_pvu32 is definitely modified by assembler statement. */
LOCAL_INLINE void rba_BswSrv_AtomicOr32(volatile uint32* Var_pvu32, uint32 Value_u32)
{
    /* non atomic equivalent: Var_pvu32 |= Value_u32 */

    rba_BswSrv_uint64 temp_u64 = (((rba_BswSrv_uint64)(Value_u32)) << 32) + 0xFFFFFFFF; /* Or: mask = Value_u32 , data = 0xFFFFFFFF */
    asm volatile("ldmst [%0]0, %A1" ::"a"(Var_pvu32) , "d"(temp_u64) : "memory");

}

/**
 *********************************************************************
 * rba_BswSrv_SyncWrite8
 *
 * synchronized write to memory
 *
 * \param   Var_pvu8       pointer to destination
 * \param   Value_u8       value
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_SyncWrite8 (volatile uint8* Var_pvu8, uint8 Value_u8)
{

    *Var_pvu8 = Value_u8;
    RBA_BSWSRV_IFX_DSYNC();
    (void)*Var_pvu8;
    RBA_BSWSRV_SET_SEQUENCE_POINT();

}

/**
 *********************************************************************
 * rba_BswSrv_SyncWrite16
 *
 * synchronized write to memory
 *
 * \param   Var_pvu16       pointer to destination
 * \param   Value_u16       value
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_SyncWrite16(volatile uint16* Var_pvu16, uint16 Value_u16)
{

    *Var_pvu16 = Value_u16;
    RBA_BSWSRV_IFX_DSYNC();
    (void)*Var_pvu16;
    RBA_BSWSRV_SET_SEQUENCE_POINT();

}



/**
 *********************************************************************
 * rba_BswSrv_CountLeadingZero32
 *
 * count leading zeros in 32 bit value.
 *
 * \param   Input_u32: input value
 * \return  number of leading zeros
 * \retval  uint32
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE uint32 rba_BswSrv_CountLeadingZero32(uint32 Input_u32)
{
    uint32 numLeadingZero_u32;

    /* count leading zeros */
#if 1// defined(RBA_BSWSRV_PRV_IFX_ASM)
    asm volatile(" clz %0,%1 " : "=d"(numLeadingZero_u32) : "d"(Input_u32));

#else
    numLeadingZero_u32 = 32;
    while(Input_u32 != 0)
    {
        Input_u32 >>= 1;
        numLeadingZero_u32--;
    }
#endif

    /* MISRA RULE 9.1 VIOLATION: variable is set by inline assembly but the checker does not understand this */
    return numLeadingZero_u32;
}

/**
 *********************************************************************
 * rba_BswSrv_ByteOrderSwap32
 *
 * Swaps the byte order of a 32 bit value for endianess conversion.
 *
 * \param   Input_u32: input value
 * \return  value with swapped byte order
 * \retval  uint32
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE uint32 rba_BswSrv_ByteOrderSwap32(uint32 Input_u32)
{
    uint32 retVal_u32;

#if 1// defined(RBA_BSWSRV_PRV_IFX_ASM)
    asm volatile(" sh.h %0, %1,  8   \n\
                   sh.h %1, %1, -8   \n\
                   or %1, %0         \n\
                   sh %0, %1, -16    \n\
                   insert %0, %0, %1, 16, 16 \n\
                 ": "=&d" (retVal_u32) : "d" (Input_u32));
#elif defined(RBA_BSWSRV_PRV_POWER_ASM)
    asm volatile(" rotlwi %0,%1,8           \n\
                   rlwimi %0,%1,24,0,7      \n\
                   rlwimi %0,%1,24,16,23    \n\
                 ": "=&r" (retVal_u32) : "r" (Input_u32));
#else
    retVal_u32 = (Input_u32 << 24) | ((Input_u32 & 0xFF00u) << 8) | ((Input_u32 & 0x00FF0000u) >> 8) | (Input_u32 >> 24);
#endif

    /* MISRA RULE 9.1 VIOLATION: variable is set by inline assembly but the checker does not understand this */
    return retVal_u32;
}

/**
 *********************************************************************
 * rba_BswSrv_ByteOrderSwap16
 *
 * Swaps the byte order of a 16 bit value for endianess conversion.
 *
 * \param   Input_u16: input value
 * \return  value with swapped byte order
 * \retval  uint16
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE uint16 rba_BswSrv_ByteOrderSwap16(uint16 Input_u16)
{
    uint16 retVal_u16;

#if 1// defined(RBA_BSWSRV_PRV_IFX_ASM)
    asm volatile(" extr.u %0, %1, 8, 8     \n\
                   insert %0, %0, %1, 8, 8 \n\
                 ": "=&d" (retVal_u16) : "d" (Input_u16));
#else
    retVal_u16 = ((Input_u16 & 0x00FFu) << 8) | ((Input_u16 & 0xFF00u) >> 8);
#endif

    /* MISRA RULE 9.1 VIOLATION: variable is set by inline assembly but the checker does not understand this */
    return retVal_u16;
}


/**
 ***************************************************************************************************
 * rba_BswSrv_MemCopy64 - copy non overlapping memory in 64 Bit blocks
 *
 * Memory copy routine. Source and destination must not overlap. Pointer parameters must be 8 Byte
 * aligned. The size should be a multiple of 8. If not, it is rounded down to the next multiple
 * of 8.
 *
 * \param   xDest_pu64      destination address
 * \param   xSrc_pcu64      source address
 * \param   numBytes_u32    number of bytes to be copied
 * \seealso     rba_BswSrv_MemCopy8, rba_BswSrv_MemCopy16, rba_BswSrv_MemCopy32
 ***************************************************************************************************
 */
LOCAL_INLINE void rba_BswSrv_MemCopy64(rba_BswSrv_uint64* xDest_pu64, const rba_BswSrv_uint64* xSrc_pcu64, uint32 numBytes_u32)
{
#if 1// defined(RBA_BSWSRV_PRV_IFX_ASM)
    rba_BswSrv_uint64 xTemp_u64;
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < (numBytes_u32 / 8); ctLoop_u32++)
    {
        asm volatile( "         \n\
            ld.d   %A0,[%2+]8   \n\
            st.d   [%1+]8,%A0   \n\
            " : "=d"(xTemp_u64), "+a"(xDest_pu64), "+a"(xSrc_pcu64) : : "memory");
            /*       0                1                 2          */
    }

#else
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < (numBytes_u32 / 8); ctLoop_u32++)
    {
        *xDest_pu64 = *xSrc_pcu64;
        xDest_pu64++;
        xSrc_pcu64++;
    }
#endif
    return;
}

/**
 ***************************************************************************************************
 * rba_BswSrv_MemCopy32 - copy non overlapping memory in 32 Bit blocks
 *
 * Memory copy routine. Source and destination must not overlap. Pointer parameters must be 4 Byte
 * aligned. The size should be a multiple of 4. If not, it is rounded down to the next multiple
 * of 4.
 *
 * \param   xDest_pu32      destination address
 * \param   xSrc_pcu32      source address
 * \param   numBytes_u32    number of bytes to be copied
 * \seealso     rba_BswSrv_MemCopy8, rba_BswSrv_MemCopy16, rba_BswSrv_MemCopy64
 ***************************************************************************************************
 */
LOCAL_INLINE void rba_BswSrv_MemCopy32(uint32* xDest_pu32, const uint32* xSrc_pcu32, uint32 numBytes_u32)
{
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < (numBytes_u32 / 4); ctLoop_u32++)
    {
        *xDest_pu32 = *xSrc_pcu32;
        xDest_pu32++;
        xSrc_pcu32++;
    }

    return;
}

/**
 ***************************************************************************************************
 * rba_BswSrv_MemCopy16 - copy non overlapping memory in 16 Bit blocks
 *
 * Memory copy routine. Source and destination must not overlap. Pointer parameters must be 2 Byte
 * aligned. The size should be a multiple of 2. If not, it is rounded down to the next multiple
 * of 2.
 *
 * \param   xDest_pu16      destination address
 * \param   xSrc_pcu16      source address
 * \param   numBytes_u32    number of bytes to be copied
 * \seealso     rba_BswSrv_MemCopy8, rba_BswSrv_MemCopy32, rba_BswSrv_MemCopy64
 ***************************************************************************************************
 */
LOCAL_INLINE void rba_BswSrv_MemCopy16(uint16* xDest_pu16, const uint16* xSrc_pcu16, uint32 numBytes_u32)
{
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < (numBytes_u32 / 2); ctLoop_u32++)
    {
        *xDest_pu16 = *xSrc_pcu16;
        xDest_pu16++;
        xSrc_pcu16++;
    }

    return;
}

/**
 ***************************************************************************************************
 * rba_BswSrv_MemCopy8 - copy non overlapping memory
 *
 * Memory copy routine. Source and destination must not overlap.
 *
 * \param   xDest_pu8       destination address
 * \param   xSrc_pcu8       source address
 * \param   numBytes_u32    number of bytes to be copied
 * \seealso     rba_BswSrv_MemCopy16, rba_BswSrv_MemCopy32, rba_BswSrv_MemCopy64
 ***************************************************************************************************
 */
LOCAL_INLINE void rba_BswSrv_MemCopy8(uint8* xDest_pu8, const uint8* xSrc_pcu8, uint32 numBytes_u32)
{
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < numBytes_u32; ctLoop_u32++)
    {
        *xDest_pu8 = *xSrc_pcu8;
        xDest_pu8++;
        xSrc_pcu8++;
    }

    return;
}

/**
 ***************************************************************************************************
 * rba_BswSrv_MemCompare64 - compare memory in 64 Bit blocks
 *
 * Memory compare routine. Pointer parameters must be 8 Byte aligned. The size should be a
 * multiple of 8. If not, it is rounded down to the next multiple of 8.
 *
 * \param   xSrc1_pcu32     first source address
 * \param   xSrc2_pcu32     second source address
 * \param   numBytes_u32    number of bytes to be compared
 * \return  stEqual_u32     result of comparison
 * \retval  0               memory area contents are equal
 * \retval  1               memory area contents differ
 * \seealso     rba_BswSrv_MemCompare8, rba_BswSrv_MemCompare16, rba_BswSrv_MemCompare32
 ***************************************************************************************************
 */
LOCAL_INLINE uint32 rba_BswSrv_MemCompare64(const rba_BswSrv_uint64* xSrc1_pcu64, const rba_BswSrv_uint64* xSrc2_pcu64, uint32 numBytes_u32)
{
#if 1// defined(RBA_BSWSRV_PRV_IFX_ASM)
    uint32 stEqual_u32;
    rba_BswSrv_uint64 xTemp1_u64;
    rba_BswSrv_uint64 xTemp2_u64;
    uint8* ctLoop_pu8;

    /* initialize return value */
    stEqual_u32 = 1UL;

    if (numBytes_u32 > 7UL)
    {
        /* MISRA RULE 11.3 VIOLATION: cast is required for inline assembly */
        ctLoop_pu8 = (uint8*)((numBytes_u32 / 8UL) - 1UL);

        /* fast forward compare loop */
        asm volatile(
        "                       \n\
        1:                      \n\
            ld.d   %A4,[%1+]8   \n\
            ld.d   %A5,[%2+]8   \n\
            jne    %L4,%L5,2f   \n\
            jne    %H4,%H5,2f   \n\
            loop   %3,1b        \n\
            mov    %0,0         \n\
        2:                      \n\
        "
        : "+d"(stEqual_u32), "+a"(xSrc1_pcu64), "+a"(xSrc2_pcu64),
        /*   0                  1                2      */
        "+a"(ctLoop_pu8),  "=d"(xTemp1_u64), "=d"(xTemp2_u64): : "memory");
        /*   3                  4                5      */
    }
#else
    uint32 stEqual_u32 = 0ul;
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < (numBytes_u32 / 8); ctLoop_u32++)
    {
        /* MISRA RULE 12.13 VIOLATION: required for code optimization */
        if (*xSrc1_pcu64++ != *xSrc2_pcu64++)
        {
            stEqual_u32 = 1ul;
            break;
        }
    }
#endif
    return stEqual_u32;
}

/**
 ***************************************************************************************************
 * rba_BswSrv_MemCompare32 - compare memory in 32 Bit blocks
 *
 * Memory compare routine. Pointer parameters must be 4 Byte aligned. The size should be a
 * multiple of 4. If not, it is rounded down to the next multiple of 4.
 *
 * \param   xSrc1_pcu32     first source address
 * \param   xSrc2_pcu32     second source address
 * \param   numBytes_u32    number of bytes to be compared
 * \return  stEqual_u32     result of comparison
 * \retval  0               memory area contents are equal
 * \retval  1               memory area contents differ
 * \seealso     rba_BswSrv_MemCompare8, rba_BswSrv_MemCompare16, rba_BswSrv_MemCompare64
 ***************************************************************************************************
 */
LOCAL_INLINE uint32 rba_BswSrv_MemCompare32(const uint32* xSrc1_pcu32, const uint32* xSrc2_pcu32, uint32 numBytes_u32)
{
#if 1// defined(RBA_BSWSRV_PRV_IFX_ASM)
    uint32 stEqual_u32;
    uint32 xTemp1_u32;
    uint32 xTemp2_u32;
    uint8* ctLoop_pu8;

    /* initialize return value */
    stEqual_u32 = 1UL;

    if (numBytes_u32 > 3UL)
    {
        /* MISRA RULE 11.3 VIOLATION: cast is required for inline assembly */
        ctLoop_pu8 = (uint8*)((numBytes_u32 / 4UL) - 1UL);

        /* fast forward compare loop */
        asm volatile(
        "                       \n\
        1:                      \n\
            ld.w   %4,[%1+]4    \n\
            ld.w   %5,[%2+]4    \n\
            jne    %4,%5,2f     \n\
            loop   %3,1b        \n\
            mov    %0,0         \n\
        2:                      \n\
        "
        : "+d"(stEqual_u32), "+a"(xSrc1_pcu32), "+a"(xSrc2_pcu32),
        /*   0                  1                2      */
        "+a"(ctLoop_pu8),  "=d"(xTemp1_u32), "=d"(xTemp2_u32): : "memory");
        /*   3                  4                5      */
    }
#else
    uint32 stEqual_u32 = 0ul;
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < (numBytes_u32 / 4); ctLoop_u32++)
    {
        /* MISRA RULE 12.13 VIOLATION: required for code optimization */
        if (*xSrc1_pcu32++ != *xSrc2_pcu32++)
        {
            stEqual_u32 = 1ul;
            break;
        }
    }
#endif
    return stEqual_u32;
}

/**
 ***************************************************************************************************
 * rba_BswSrv_MemCompare16 - compare memory in 16 Bit blocks
 *
 * Memory compare routine. Pointer parameters must be 2 Byte aligned. The size should be a
 * multiple of 2. If not, it is rounded down to the next multiple of 2.
 *
 * \param   xSrc1_pcu16     first source address
 * \param   xSrc2_pcu16     second source address
 * \param   numBytes_u32    number of bytes to be compared
 * \return  stEqual_u32     result of comparison
 * \retval  0               memory area contents are equal
 * \retval  1               memory area contents differ
 * \seealso     rba_BswSrv_MemCompare8, rba_BswSrv_MemCompare32, rba_BswSrv_MemCompare64
 ***************************************************************************************************
 */
LOCAL_INLINE uint32 rba_BswSrv_MemCompare16(const uint16* xSrc1_pcu16, const uint16* xSrc2_pcu16, uint32 numBytes_u32)
{
#if 1// defined(RBA_BSWSRV_PRV_IFX_ASM)
    uint32 stEqual_u32;
    uint32 xTemp1_u32;
    uint32 xTemp2_u32;
    uint8* ctLoop_pu8;

    /* initialize return value */
    stEqual_u32 = 1UL;

    if (numBytes_u32 > 1UL)
    {
        /* MISRA RULE 11.3 VIOLATION: cast is required for inline assembly */
        ctLoop_pu8 = (uint8*)((numBytes_u32 / 2UL) - 1UL);

        /* fast forward compare loop */
        asm volatile(
        "                       \n\
        1:                      \n\
            ld.hu  %4,[%1+]2    \n\
            ld.hu  %5,[%2+]2    \n\
            jne    %4,%5,2f     \n\
            loop   %3,1b        \n\
            mov    %0,0         \n\
        2:                      \n\
        "
        : "+d"(stEqual_u32), "+a"(xSrc1_pcu16), "+a"(xSrc2_pcu16),
        /*   0                  1                2      */
        "+a"(ctLoop_pu8),  "=d"(xTemp1_u32), "=d"(xTemp2_u32): : "memory");
        /*   3                  4                5      */
    }
#else
    uint32 stEqual_u32 = 0ul;
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < (numBytes_u32 / 2); ctLoop_u32++)
    {
        /* MISRA RULE 12.13 VIOLATION: required for code optimization */
        if (*xSrc1_pcu16++ != *xSrc2_pcu16++)
        {
            stEqual_u32 = 1ul;
            break;
        }
    }
#endif
    return stEqual_u32;
}

/**
 ***************************************************************************************************
 * rba_BswSrv_MemCompare8 - compare memory
 *
 * Memory compare routine.
 *
 * \param   xSrc1_pcu8      pointer to the first source address
 * \param   xSrc2_pcu8      pointer to the second source address
 * \param   numBytes_u32    number of bytes to be compared
 * \return  stEqual_u32     result of comparison
 * \retval  0               memory area contents are equal
 * \retval  1               memory area contents differ
 * \seealso     rba_BswSrv_MemCompare16, rba_BswSrv_MemCompare32, rba_BswSrv_MemCompare64
 ***************************************************************************************************
 */
LOCAL_INLINE uint32 rba_BswSrv_MemCompare8(const uint8* xSrc1_pcu8, const uint8* xSrc2_pcu8, uint32 numBytes_u32)
{
#if 1// defined(RBA_BSWSRV_PRV_IFX_ASM)
    uint32 stEqual_u32;
    uint32 xTemp1_u32;
    uint32 xTemp2_u32;
    uint8* ctLoop_pu8;

    /* initialize return value */
    stEqual_u32 = 1UL;

    if (numBytes_u32 > 0UL)
    {
        /* MISRA RULE 11.3 VIOLATION: cast is required for inline assembly */
        ctLoop_pu8 = (uint8*)(numBytes_u32 - 1UL);

        /* fast forward compare loop */
        asm volatile(
        "                       \n\
        1:                      \n\
            ld.bu  %4,[%1+]1    \n\
            ld.bu  %5,[%2+]1    \n\
            jne    %4,%5,2f     \n\
            loop   %3,1b        \n\
            mov    %0,0         \n\
        2:                      \n\
        "
        : "+d"(stEqual_u32), "+a"(xSrc1_pcu8), "+a"(xSrc2_pcu8),
        /*   0                  1               2       */
        "+a"(ctLoop_pu8), "=d"(xTemp1_u32), "=d"(xTemp2_u32): : "memory");
        /*   3                 4                5       */
    }
#else
    uint32 stEqual_u32 = 0ul;
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < numBytes_u32; ctLoop_u32++)
    {
        /* MISRA RULE 12.13 VIOLATION: required for code optimization */
        if (*xSrc1_pcu8++ != *xSrc2_pcu8++)
        {
            stEqual_u32 = 1ul;
            break;
        }
    }
#endif
    return stEqual_u32;
}

/**
 ***************************************************************************************************
 * rba_BswSrv_MemSet64 - initialize memory with 64 Bit data
 *
 * Memory initialization routine. 64 Bit Pattern is written to the destination.
 * Destination must be 4 Byte aligned. The size should be a multiple of 8. If not, it is rounded
 * down to the next multiple of 8.
 *
 * \param   xDest_pu32      destination address
 * \param   Pattern_u32     fill pattern
 * \param   numBytes_u32    number of bytes to be initialized
 * \seealso     rba_BswSrv_MemSet8, rba_BswSrv_MemSet16, rba_BswSrv_MemSet32
 ***************************************************************************************************
 */
LOCAL_INLINE void rba_BswSrv_MemSet64(rba_BswSrv_uint64* xDest_pu64, rba_BswSrv_uint64 xPattern_u64, uint32 numBytes_u32)
{
#if 1// defined(RBA_BSWSRV_PRV_IFX_ASM)
    uint8* ct_pu8;

    if (numBytes_u32 > 7UL)
    {
        /* MISRA RULE 11.3 VIOLATION: cast is required for inline assembly */
        ct_pu8      = (uint8*)(((numBytes_u32) / 8UL) - 1UL);

        /* fast forward copy loop */
        asm volatile(
        "                       \n\
        1:                      \n\
            st.d   [%0+]8,%A2   \n\
            loop   %1,1b        \n\
        "
        : "+a"(xDest_pu64), "+a"(ct_pu8) : "d"(xPattern_u64): "memory");
        /*   0                1             2     */
    }

#else
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < (numBytes_u32 / 8); ctLoop_u32++)
    {
        *xDest_pu64 = xPattern_u64;
        xDest_pu64++;
    }
#endif
    return;
}

/**
 ***************************************************************************************************
 * rba_BswSrv_MemSet32 - initialize memory with 32 Bit data
 *
 * Memory initialization routine. 32 Bit Pattern is written to the destination.
 * Destination must be 4 Byte aligned. The size should be a multiple of 4. If not, it is rounded
 * down to the next multiple of 4.
 *
 * \param   xDest_pu32      destination address
 * \param   Pattern_u32     fill pattern
 * \param   numBytes_u32    number of bytes to be initialized
 * \seealso     rba_BswSrv_MemSet8, rba_BswSrv_MemSet16, rba_BswSrv_MemSet64
 ***************************************************************************************************
 */
LOCAL_INLINE void rba_BswSrv_MemSet32(uint32* xDest_pu32, uint32 xPattern_u32, uint32 numBytes_u32)
{
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < (numBytes_u32 / 4); ctLoop_u32++)
    {
        *xDest_pu32 = xPattern_u32;
        xDest_pu32++;
    }

    return;
}

/**
 ***************************************************************************************************
 * rba_BswSrv_MemSet16 - initialize memory with 16 Bit data
 *
 * Memory initialization routine. 16 Bit Pattern is written to the destination.
 * Destination must be 2 Byte aligned. The size should be a multiple of 2. If not, it is rounded
 * down to the next multiple of 2.
 *
 * \param   xDest_pu32      destination address
 * \param   Pattern_u32     fill pattern
 * \param   numBytes_u32    number of bytes to be initialized
 * \seealso     rba_BswSrv_MemSet8, rba_BswSrv_MemSet32, rba_BswSrv_MemSet64
 ***************************************************************************************************
 */
LOCAL_INLINE void rba_BswSrv_MemSet16(uint16* xDest_pu16, uint32 xPattern_u32, uint32 numBytes_u32)
{
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < (numBytes_u32 / 2); ctLoop_u32++)
    {
        *xDest_pu16 = (uint16)xPattern_u32;
        xDest_pu16++;
    }

    return;
}

/**
 ***************************************************************************************************
 * rba_BswSrv_MemSet8 - initialize memory with 8 Bit data
 *
 * Memory initialization routine. 8 Bit Pattern is written to the destination.
 *
 * \param   xDest_pu8       destination address
 * \param   xPattern_u32    fill pattern, only lower 8 bit used
 * \param   numBytes_u32    number of bytes to be initialized
 * \seealso     rba_BswSrv_MemSet16, rba_BswSrv_MemSet32, rba_BswSrv_MemSet64
 ***************************************************************************************************
 */
LOCAL_INLINE void rba_BswSrv_MemSet8(uint8* xDest_pu8, uint32 xPattern_u32, uint32 numBytes_u32)
{
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < numBytes_u32; ctLoop_u32++)
    {
        *xDest_pu8 = (uint8)xPattern_u32;
        xDest_pu8++;
    }

    return;
}

/* end of #ifndef RBA_BSWSRV_H */

LOCAL_INLINE rba_BswSrv_uint64 Mcu_Rb_GetSysTime(void)
{
    uint32 tiStmTim0_u32;
    uint32 tiStmTim6_u32;
    rba_BswSrv_uint64 tiSys_u64;

    /* Memory clobber needs to be here since a inline function is according to c standard no */
    /* "reorder barrier" so this memory clobber prevents instruction reordering */
    RBA_BSWSRV_SET_SEQUENCE_POINT();

    do{
        tiStmTim6_u32 =STM0_TIM6.U;

        /* ensure that STM0.TIM6 is read before STM0.TIM0
           This is done since if the low part would be read first and the low part value would be short before the
           overflow and it takes some time to read the high part, we would have the old (without overflow) low part
           and the new incremented high part which would be wrong

           High Part | Low Part
           0000      | FFFE
           0000      | FFFF     <- Low part is read and stored
           0001      | 0000     <- High part is saved

           So the resulting time stamp would be 0001FFFF but the correct one would be 0000FFFF */

        tiStmTim0_u32  = STM0_TIM0.U;
    } while(tiStmTim6_u32 != STM0_TIM6.U);

    tiSys_u64 = (((rba_BswSrv_uint64)tiStmTim6_u32 << 32uL) | tiStmTim0_u32);

    return tiSys_u64;
}


#endif

#if(RBA_BSWSRV_CFG_KNOWN_MACHINE_FAM)




/* MISRA RULE 19.4 VIOLATION: unbalanced brackets are required here */
#  define RBA_BSWSRV_SUSPEND_CORE_LOCAL_INT()       do { rba_BswSrv_SuspendCoreLocalInt()
#  define RBA_BSWSRV_RESUME_CORE_LOCAL_INT()        rba_BswSrv_ResumeCoreLocalInt(); } while(0)
#  define RBA_BSWSRV_GET_LOCK_COMMON()              do { rba_BswSrv_GetLockCommon()
#  define RBA_BSWSRV_RELEASE_LOCK_COMMON()          rba_BswSrv_ReleaseLockCommon(); } while(0)
#  define RBA_BSWSRV_GET_LOCK_NONEST(Lock_pst)      do { rba_BswSrv_GetLockNonest(Lock_pst)
#  define RBA_BSWSRV_RELEASE_LOCK_NONEST(Lock_pst)  rba_BswSrv_ReleaseLockNonest(Lock_pst); } while(0)

/* structure content may change without notice as it depends on implementation */
typedef struct
{
#if (RBA_BSWSRV_NUM_USED_CORE > 1)
#  ifdef RBA_BSWSRV_PRV_C_LOCK
    volatile uint32 Prv_Lock_vu32;
#  else
#    ifdef RBA_BSWSRV_PRV_SWAP_LOCK
    volatile uint32 Prv_SwapLock_vu32;      /* 0: no core tries to get the lock, 1: get lock action in progress */
#    endif
    volatile uint32 Prv_CoreLock_vu32;      /* bit 0-7:  n=0: no core has lock
                                                         n>0: physical Core n-1 has lock */
                                            /* bit 8-31: lock nesting counter */
#  endif
    uint32          Prv_adActivation_u32;   /* address at which Lock was activated (log level 2) */
    volatile uint16 Prv_ctLockUse_vu16;     /* lock use counter (may overflow, log level 2)  */
    volatile uint16 Prv_ctLockWait_vu16;    /* lock wait counter (may overflow, log level 2) */
    volatile uint16 Prv_ctLockNest_vu16;    /* lock self nesting counter (may overflow, log level 2) */
#else
    uint8           Prv_Dummy_u8;           /* minimum data structure for single core use */
#endif
} rba_BswSrv_Lock_to;

/* structure content may change without notice as it depends on implementation */
typedef struct
{
#ifdef RBA_BSWSRV_PRV_C_LOCK
    volatile uint32 Prv_Lock_vu32;
#else
#  ifdef RBA_BSWSRV_PRV_SWAP_LOCK
    volatile uint32 Prv_SwapLock_vu32;      /* 0: no core tries to get the lock, 1: get lock action in progress */
#  endif
    volatile uint32 Prv_CoreLock_vu32;      /* bit 0-7:  n=0: no core has lock
                                                         n>RBA_BSWSRV_MAX_PHYS_CORE: physical Core ((n-1)-RBA_BSWSRV_MAX_PHYS_CORE) has SimpleLock */
                                            /* bit 8-31: always 0 for SimpleLock */
#endif
} rba_BswSrv_SimpleLock_to;

#define RBA_BSWSRV_START_SEC_CODE
#include "rba_BswSrv_MemMap.h"
extern void rba_BswSrv_LockMeasure_10ms_Proc(void);
extern void rba_BswSrv_TerminateAllCoreLocks(void);
#define RBA_BSWSRV_STOP_SEC_CODE
#include "rba_BswSrv_MemMap.h"

LOCAL_INLINE void rba_BswSrv_SuspendLowPrioInt(void);
LOCAL_INLINE void rba_BswSrv_ResumeLowPrioInt(void);
LOCAL_INLINE void rba_BswSrv_SuspendCoreLocalInt(void);
LOCAL_INLINE void rba_BswSrv_ResumeCoreLocalInt(void);
LOCAL_INLINE void rba_BswSrv_GetLockLowPrio(void);
LOCAL_INLINE void rba_BswSrv_ReleaseLockLowPrio(void);
LOCAL_INLINE void rba_BswSrv_GetLockCommon(void);
LOCAL_INLINE void rba_BswSrv_ReleaseLockCommon(void);
LOCAL_INLINE void rba_BswSrv_GetLockNonest(rba_BswSrv_Lock_to* Lock_pst);
LOCAL_INLINE void rba_BswSrv_ReleaseLockNonest(rba_BswSrv_Lock_to* Lock_pst);
LOCAL_INLINE uint8_least rba_BswSrv_TryToGetSimpleLock(rba_BswSrv_SimpleLock_to* Lock_pst);
LOCAL_INLINE void rba_BswSrv_ReleaseSimpleLock(rba_BswSrv_SimpleLock_to* Lock_pst);

/* rba_BswSrv_Atomic* functions are generally only atomic, if all write actions use rba_BswSrv_Atomic interfaces. */
/* Exceptions are hardware dependant: for JDP and IFX devices accesses to peripheral registers are atomic even when mixed with normal write accesses. */



/* private functions to be used in inline functions only */
/* MISRA RULE 3.4 VIOLATION: pragma is required for function */
#define RBA_BSWSRV_START_SEC_CODE_FAST
#include "rba_BswSrv_MemMap.h"
extern uint8_least rba_BswSrv_PrvTryToGetSimpleLock(rba_BswSrv_SimpleLock_to* Lock_pst);
extern void rba_BswSrv_PrvReleaseSimpleLock(rba_BswSrv_SimpleLock_to* Lock_pst);
extern void rba_BswSrv_PrvSuspendCoreLocalInt(void);
extern void rba_BswSrv_PrvResumeCoreLocalInt(void);
extern void rba_BswSrv_PrvGetLockCommon(void);
extern void rba_BswSrv_PrvReleaseLockCommon(void);
#define RBA_BSWSRV_STOP_SEC_CODE_FAST
#include "rba_BswSrv_MemMap.h"

#define RBA_BSWSRV_START_SEC_CODE_NONEST
#include "rba_BswSrv_MemMap.h"
extern void rba_BswSrv_PrvGetLockNonest(rba_BswSrv_Lock_to* Lock_pst);
extern void rba_BswSrv_PrvReleaseLockNonest(rba_BswSrv_Lock_to* Lock_pst);
#define RBA_BSWSRV_STOP_SEC_CODE_NONEST
#include "rba_BswSrv_MemMap.h"

#define RBA_BSWSRV_START_SEC_CODE_LOW_PRIO
#include "rba_BswSrv_MemMap.h"
extern void rba_BswSrv_PrvSuspendLowPrioInt(void);
extern void rba_BswSrv_PrvResumeLowPrioInt(void);
extern void rba_BswSrv_PrvGetLockLowPrio(void);
extern void rba_BswSrv_PrvReleaseLockLowPrio(void);
#define RBA_BSWSRV_STOP_SEC_CODE_LOW_PRIO
#include "rba_BswSrv_MemMap.h"

/* end of #ifndef RBA_BSWSRV_CFG_HSM_CORE */
#endif


#if 0//(RBA_BSWSRV_CFG_KNOWN_MACHINE_FAM)

/**
 *********************************************************************
 * rba_BswSrv_TryToGetSimpleLock
 *
 * Try to get a SimpleLock without interrupt suspend.
 *********************************************************************
 */
LOCAL_INLINE uint8_least rba_BswSrv_TryToGetSimpleLock(rba_BswSrv_SimpleLock_to* Lock_pst)
{
    uint8_least stReturn_qu8;
    stReturn_qu8 = rba_BswSrv_PrvTryToGetSimpleLock(Lock_pst);
    RBA_BSWSRV_SET_SEQUENCE_POINT();  /* forces call instead of jump to previous function */

    return stReturn_qu8;
}

/**
 *********************************************************************
 * rba_BswSrv_ReleaseSimpleLock
 *
 * release a SimpleLock without interrupt suspend.
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_ReleaseSimpleLock(rba_BswSrv_SimpleLock_to* Lock_pst)
{
    rba_BswSrv_PrvReleaseSimpleLock(Lock_pst);
    RBA_BSWSRV_SET_SEQUENCE_POINT();  /* forces call instead of jump to previous function */
}

/**
 *********************************************************************
 * rba_BswSrv_SuspendLowPrioInt
 *
 * Suspend low priority interrupt processing of current core
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_SuspendLowPrioInt(void)
{
    rba_BswSrv_PrvSuspendLowPrioInt();
    RBA_BSWSRV_SET_SEQUENCE_POINT();  /* forces call instead of jump to previous function */
}

/**
 *********************************************************************
 * rba_BswSrv_ResumeLowPrioInt
 *
 * Resume low priority interrupt processing of current core
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_ResumeLowPrioInt(void)
{
    rba_BswSrv_PrvResumeLowPrioInt();
    RBA_BSWSRV_SET_SEQUENCE_POINT();  /* forces call instead of jump to previous function */
}

/**
 *********************************************************************
 * rba_BswSrv_SuspendCoreLocalInt
 *
 * Suspend interrupt processing of current core
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_SuspendCoreLocalInt(void)
{
    rba_BswSrv_PrvSuspendCoreLocalInt();
    RBA_BSWSRV_SET_SEQUENCE_POINT();  /* forces call instead of jump to previous function */
}

/**
 *********************************************************************
 * rba_BswSrv_ResumeCoreLocalInt
 *
 * Resume interrupt processing of current core
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_ResumeCoreLocalInt(void)
{
    rba_BswSrv_PrvResumeCoreLocalInt();
    RBA_BSWSRV_SET_SEQUENCE_POINT();  /* forces call instead of jump to previous function */
}

/**
 *********************************************************************
 * rba_BswSrv_GetLockLowPrio
 *
 * Get low priority spinlock. Must not be called, if a common lock or
 * a nonest lock is already active for the current core.
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_GetLockLowPrio(void)
{
#if (RBA_BSWSRV_NUM_USED_CORE > 1)
    rba_BswSrv_PrvGetLockLowPrio();
#else
    rba_BswSrv_PrvSuspendLowPrioInt();
#endif
    RBA_BSWSRV_SET_SEQUENCE_POINT();  /* forces call instead of jump to previous function */
}

/**
 *********************************************************************
 * rba_BswSrv_ReleaseLockLowPrio
 *
 * Release low priority spinlock. Must not be called, if a common lock or
 * a nonest lock is already active for the current core.
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_ReleaseLockLowPrio(void)
{
#if (RBA_BSWSRV_NUM_USED_CORE > 1)
    rba_BswSrv_PrvReleaseLockLowPrio();
#else
    rba_BswSrv_PrvResumeLowPrioInt();
#endif
    RBA_BSWSRV_SET_SEQUENCE_POINT();  /* forces call instead of jump to previous function */
}

/**
 *********************************************************************
 * rba_BswSrv_GetLockCommon
 *
 * Get common spinlock. Must not be called, if a nonest lock is already
 * active for the current core.
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_GetLockCommon(void)
{
#if (RBA_BSWSRV_NUM_USED_CORE > 1)
    rba_BswSrv_PrvGetLockCommon();
#else
    rba_BswSrv_PrvSuspendCoreLocalInt();
#endif
    RBA_BSWSRV_SET_SEQUENCE_POINT();  /* forces call instead of jump to previous function */
}

/**
 *********************************************************************
 * rba_BswSrv_ReleaseLockCommon
 *
 * Release common spinlock. Must not be called, if a nonest lock is already
 * active for the current core.
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_ReleaseLockCommon(void)
{
#if (RBA_BSWSRV_NUM_USED_CORE > 1)
    rba_BswSrv_PrvReleaseLockCommon();
#else
    rba_BswSrv_PrvResumeCoreLocalInt();
#endif
    RBA_BSWSRV_SET_SEQUENCE_POINT();  /* forces call instead of jump to previous function */
}

/**
 *********************************************************************
 * rba_BswSrv_GetLockNonest
 *
 * Get specified nonest lock. Must not be called, if a different nonest lock
 * is already active for the current core.
 *
 * \param   Lock_pst        pointer to nonest lock
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_GetLockNonest(rba_BswSrv_Lock_to* Lock_pst)
{
#if (RBA_BSWSRV_NUM_USED_CORE > 1)
    rba_BswSrv_PrvGetLockNonest(Lock_pst);
#else
    RBA_BSWSRV_PARAM_UNUSED(Lock_pst);
    rba_BswSrv_PrvSuspendCoreLocalInt();
#endif
    RBA_BSWSRV_SET_SEQUENCE_POINT();  /* forces call instead of jump to previous function */
}

/**
 *********************************************************************
 * rba_BswSrv_ReleaseLockNonest
 *
 * Release specified nonest lock. Must not be called, if a different nonest lock
 * is already active for the current core.
 *
 * \param   Lock_pst        pointer to nonest lock
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_ReleaseLockNonest(rba_BswSrv_Lock_to* Lock_pst)
{
#if (RBA_BSWSRV_NUM_USED_CORE > 1)
    rba_BswSrv_PrvReleaseLockNonest(Lock_pst);
#else
    RBA_BSWSRV_PARAM_UNUSED(Lock_pst);
    rba_BswSrv_PrvResumeCoreLocalInt();
#endif
    RBA_BSWSRV_SET_SEQUENCE_POINT();  /* forces call instead of jump to previous function */
}




/* end of #if(RBA_BSWSRV_CFG_KNOWN_MACHINE_FAM) */
#endif



/*<BASDKey>
**********************************************************************************************************************
* $History__:$
**********************************************************************************************************************
</BASDKey>*/

/*<BASDKey>
**********************************************************************************************************************
* End of header file: $Name______:rba_BswSrv$
**********************************************************************************************************************
</BASDKey>*/
