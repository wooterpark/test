/*<BASDKey>
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, 2010 Robert Bosch GmbH. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 * Administrative Information (automatically filled in)
 * $Domain____:BASD$
 * $Namespace_:\Comp\rta_bsw_BswSrv$
 * $Class_____:H$
 * $Name______:rta_bsw_BswSrv$
 * $Variant___:AR40.2.0.0$
 * $Revision__:5$
 **********************************************************************************************************************
</BASDKey>*/

/****************************************************************************
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *****************************************************************************
 * Project : Basic Software Service
 * Component : RTA_BSW_BSWSRV
 * Date : Mon December 28 2015
 * Version : 1.0
 * Description : RTA-BASE first revision
 ****************************************************************************/


#ifndef RTA_BSW_BSWSRV_H
#define RTA_BSW_BSWSRV_H

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "Std_Types.h"
#include "rta_bsw_BswSrv_Cfg.h"

#ifndef RTA_BSW_BSWSRV_CFG_KNOWN_MACHINE_FAM
#  error "RTA_BSW_BSWSRV_CFG_KNOWN_MACHINE_FAM is missing in rta_bsw_BswSrv_Cfg.h"
#endif

#if(RTA_BSW_BSWSRV_CFG_KNOWN_MACHINE_FAM)
#  include "rta_bsw_Reg.h" /* required for machine family */
#  if (MCU_RB_MACHINE_FAM == MCU_RB_IFX_UC1)
#    include RTA_BSW_REG_CSFR_H     /* required for rta_bsw_BswSrv_GetPhysCore() */
#  elif (MCU_RB_MACHINE_FAM == MCU_RB_JDP_UC1)
#    include RTA_BSW_REG_SPR_H      /* required for rta_bsw_BswSrv_GetPhysCore() */
#  endif
#endif

/*
 ***************************************************************************************************
 * Defines
 ***************************************************************************************************
 */
/* Vendor and module identification */
#define RTA_BSW_BSWSRV_VENDOR_ID   (6)
#define RTA_BSW_BSWSRV_MODULE_ID   (255)
#define RTA_BSW_BSWSRV_INSTANCE_ID (0)

/* Module version information */
#define RTA_BSW_BSWSRV_SW_MAJOR_VERSION (2)
#define RTA_BSW_BSWSRV_SW_MINOR_VERSION (0)
#define RTA_BSW_BSWSRV_SW_PATCH_VERSION (0)

// for testing purposes only
//#define RTA_BSW_BSWSRV_PRV_C_IMPL
//#define RTA_BSW_BSWSRV_PRV_C_LOCK
//#define RTA_BSW_BSWSRV_PRV_SWAP_LOCK

/* for backward compatibility to older MCAL versions */
#ifndef MCU_RB_JDP_UC1_DEV2_C2
#  define MCU_RB_JDP_UC1_DEV2_C2 9999
#endif
#ifndef MCU_RB_JDP_UC1_DEV3_C2
#  define MCU_RB_JDP_UC1_DEV3_C2 9999
#endif
#ifndef MCU_RB_JDP_UC1_DEV4_C2
#  define MCU_RB_JDP_UC1_DEV4_C2 9999
#endif


#ifndef RTA_BSW_BSWSRV_PRV_C_IMPL
#  if(RTA_BSW_BSWSRV_CFG_KNOWN_MACHINE_FAM)
#    if (MCU_RB_MACHINE_FAM == MCU_RB_JDP_UC1)
#      define RTA_BSW_BSWSRV_PRV_JDP_UC1_ASM
#    elif (MCU_RB_MACHINE_FAM == MCU_RB_IFX_UC1)
#      define RTA_BSW_BSWSRV_PRV_IFX_UC1_ASM
#    else
#      error "Machine family not supported"
#    endif
#  else
#    define RTA_BSW_BSWSRV_PRV_C_IMPL
#  endif
#endif



#if(RTA_BSW_BSWSRV_CFG_KNOWN_MACHINE_FAM)
/* MISRA RULE 19.4 VIOLATION: unbalanced brackets are required here */
#define RTA_BSW_BSWSRV_SUSPEND_CORE_LOCAL_INT()       do { rta_bsw_BswSrv_SuspendCoreLocalInt()
#define RTA_BSW_BSWSRV_RESUME_CORE_LOCAL_INT()        rta_bsw_BswSrv_ResumeCoreLocalInt(); } while(0)
#define RTA_BSW_BSWSRV_GET_LOCK_COMMON()              do { rta_bsw_BswSrv_GetLockCommon()
#define RTA_BSW_BSWSRV_RELEASE_LOCK_COMMON()          rta_bsw_BswSrv_ReleaseLockCommon(); } while(0)
#define RTA_BSW_BSWSRV_GET_LOCK_NONEST(Lock_pst)      do { rta_bsw_BswSrv_GetLockNonest(Lock_pst)
#define RTA_BSW_BSWSRV_RELEASE_LOCK_NONEST(Lock_pst)  rta_bsw_BswSrv_ReleaseLockNonest(Lock_pst); } while(0)

#define RTA_BSW_BSWSRV_PARAM_UNUSED(param)          (void)(param)
#define RTA_BSW_BSWSRV_SET_SEQUENCE_POINT()         asm volatile ("" ::: "memory")

#ifdef __GNUC_PATCHLEVEL__
/* RTA_BSW_BSWSRV_GCC_VERSION is only defined if GNU GCC compiler is used */
#  define RTA_BSW_BSWSRV_GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#else
#  error "Compiler is not supported #RTA_BSW_BSWSRV_GCC_VERSION"
#endif

#if (MCU_RB_MACHINE_FAM == MCU_RB_IFX_UC1)
/* check compiler version */
#if ((RTA_BSW_BSWSRV_GCC_VERSION < 40600) || (RTA_BSW_BSWSRV_GCC_VERSION >= 40700))
#  error "Compiler version is not supported for IFX"
#endif
/* To be used with #include RTA_BSW_REG_CSFR_H */
/* Note: The parameter "regaddr" in the MFCR and MTCR macros may either
   be specified as a 16-bit constant or as a symbolic name (e.g., $psw).  */
#  define RTA_BSW_BSWSRV_IFX_MFCR(regaddr)          RTA_BSW_BSWSRV_IFX_MFCR_PRV(regaddr)
#  define RTA_BSW_BSWSRV_IFX_MFCR_PRV(regaddr)      \
            /* MISRA RULE 1.1,9.1 VIOLATION: statement expression is required by function */ \
            ({ uint32 res; asm volatile ("mfcr %0,"#regaddr : "=d" (res) : : "memory"); res; })
#  define RTA_BSW_BSWSRV_IFX_MTCR(regaddr,val)      RTA_BSW_BSWSRV_IFX_MTCR_PRV(regaddr,val)
#  define RTA_BSW_BSWSRV_IFX_MTCR_PRV(regaddr,val)  \
            asm volatile ("mtcr "#regaddr",%0" : : "d" (val) : "memory")
#  define RTA_BSW_BSWSRV_IFX_ISYNC()                asm volatile ("isync" : : : "memory")
#  define RTA_BSW_BSWSRV_IFX_DSYNC()                asm volatile ("dsync" : : : "memory")

#  define RTA_BSW_BSWSRV_NOP()                      asm volatile ("nop" : : : "memory")
#  define RTA_BSW_BSWSRV_DEBUG_HALT()               asm volatile ("debug" : : : "memory")


#elif (MCU_RB_MACHINE_FAM == MCU_RB_JDP_UC1)
/* check compiler version */
#if ((RTA_BSW_BSWSRV_GCC_VERSION < 40600) || (RTA_BSW_BSWSRV_GCC_VERSION >= 40700))
#  error "Compiler version is not supported for JDP"
#endif

/* To be used with #include RTA_BSW_REG_SPR_H */
#  define RTA_BSW_BSWSRV_JDP_MFSPR(regaddr)         RTA_BSW_BSWSRV_JDP_MFSPR_PRV(regaddr)
#  define RTA_BSW_BSWSRV_JDP_MFSPR_PRV(regaddr)     \
            /* MISRA RULE 1.1,9.1 VIOLATION: statement expression is required by function */ \
            ({ uint32 result; asm volatile ("mfspr %0,%1" : "=r" (result) : "n" (regaddr)); result; })
#  define RTA_BSW_BSWSRV_JDP_MTSPR(regaddr,val)     RTA_BSW_BSWSRV_JDP_MTSPR_PRV(regaddr,val)
#  define RTA_BSW_BSWSRV_JDP_MTSPR_PRV(regaddr,val) \
            asm volatile ("mtspr %0,%1" : : "n" (regaddr), "r" (val))

#  define RTA_BSW_BSWSRV_JDP_MFDCR(regaddr)         RTA_BSW_BSWSRV_JDP_MFDCR_PRV(regaddr)
#  define RTA_BSW_BSWSRV_JDP_MFDCR_PRV(regaddr)     \
            /* MISRA RULE 1.1,9.1 VIOLATION: statement expression is required by function */ \
            ({ uint32 result; asm volatile ("mfdcr %0,%1" : "=r" (result) : "n" (regaddr)); result; })
#  define RTA_BSW_BSWSRV_JDP_MTDCR(regaddr,val)     RTA_BSW_BSWSRV_JDP_MTDCR_PRV(regaddr,val)
#  define RTA_BSW_BSWSRV_JDP_MTDCR_PRV(regaddr,val) \
            asm volatile ("mtdcr %0,%1" : : "n" (regaddr), "r" (val))

#  define RTA_BSW_BSWSRV_JDP_ISYNC()                asm volatile ("isync" : : : "memory")
#  define RTA_BSW_BSWSRV_JDP_MSYNC()                asm volatile ("msync" : : : "memory")  /* MSYNC is equivalent to ISYNC+MBAR */
#  define RTA_BSW_BSWSRV_JDP_MBAR()                 asm volatile ("mbar"  : : : "memory")

#  define RTA_BSW_BSWSRV_NOP()                      asm volatile ("nop"   : : : "memory")

#else
#  error "Machine family not supported"
#endif


/* Define for maximum return value of RTA_BSW_BswSrv_GetPhysCore() + 1 */
/* JDP device 2 uses physical core numbers 2 and 0. Therefore an physical core array has to provide 3 array elements too. */
/* For IFX, there core numbering is always continous.*/
#if (MCU_RB_MACHINE_FAM == MCU_RB_IFX_UC1)
#  define RTA_BSW_BSWSRV_MAX_PHYS_CORE  MCU_RB_NR_OF_AVL_CORES
#elif (MCU_RB_MACHINE_TYPE == MCU_RB_JDP_UC1_DEV1)
#  define RTA_BSW_BSWSRV_MAX_PHYS_CORE  1u
#elif (MCU_RB_MACHINE_TYPE == MCU_RB_JDP_UC1_DEV2)      || \
      (MCU_RB_MACHINE_TYPE == MCU_RB_JDP_UC1_DEV2_C2)   || \
      (MCU_RB_MACHINE_TYPE == MCU_RB_JDP_UC1_DEV3)      || \
      (MCU_RB_MACHINE_TYPE == MCU_RB_JDP_UC1_DEV3_C2)   || \
      (MCU_RB_MACHINE_TYPE == MCU_RB_JDP_UC1_DEV4)      || \
      (MCU_RB_MACHINE_TYPE == MCU_RB_JDP_UC1_DEV4_C2)
#  define RTA_BSW_BSWSRV_MAX_PHYS_CORE  3u
#else
#  error "Machine type not supported"
#endif

#ifndef MCU_RB_NR_OF_AVL_CORES
#  error "Define MCU_RB_NR_OF_AVL_CORES is missing in configuration"
#endif

/* end of #if(RTA_BSW_BSWSRV_CFG_KNOWN_MACHINE_FAM) */
#endif

/*
 *********************************************************************
 * Type definition
 *********************************************************************
 */

typedef unsigned long long rta_bsw_BswSrv_uint64;

#if(RTA_BSW_BSWSRV_CFG_KNOWN_MACHINE_FAM)
/* structure content may change without notice as it depends on implementation */
typedef struct
{
#ifdef RTA_BSW_BSWSRV_PRV_C_LOCK
    volatile uint32 Prv_Lock_vu32;
#else
# ifdef RTA_BSW_BSWSRV_PRV_SWAP_LOCK
    volatile uint32 Prv_SwapLock_vu32;      /* 0: no core tries to get the lock, 1: get lock action in progress */
# endif
    volatile uint32 Prv_CoreLock_vu32;      /* bit 0-7:  n=0: no core has lock
                                                         n>0: physical Core n-1 has lock */
                                            /* bit 8-31: lock nesting counter */
#endif
    uint32          Prv_adActivation_u32;   /* address at which Lock was activated (log level 1) */
    volatile uint16 Prv_ctLockUse_vu16;     /* lock use counter (may overflow, log level 2)  */
    volatile uint16 Prv_ctLockWait_vu16;    /* lock wait counter (may overflow, log level 2) */
    volatile uint16 Prv_ctLockNest_vu16;    /* lock self nesting counter (may overflow, log level 2) */
} rta_bsw_BswSrv_Lock_to;

/* structure content may change without notice as it depends on implementation */
typedef struct
{
#ifdef RTA_BSW_BSWSRV_PRV_C_LOCK
    volatile uint32 Prv_Lock_vu32;
#else
# ifdef RTA_BSW_BSWSRV_PRV_SWAP_LOCK
    volatile uint32 Prv_SwapLock_vu32;      /* 0: no core tries to get the lock, 1: get lock action in progress */
# endif
    volatile uint32 Prv_CoreLock_vu32;      /* bit 0-7:  n=0: no core has lock
                                                         n>RTA_BSW_BSWSRV_MAX_PHYS_CORE: physical Core ((n-1)-RTA_BSW_BSWSRV_MAX_PHYS_CORE) has SimpleLock */
                                            /* bit 8-31: always 0 for SimpleLock */
#endif
} rta_bsw_BswSrv_SimpleLock_to;

/* end of #if(RTA_BSW_BSWSRV_CFG_KNOWN_MACHINE_FAM) */
#endif

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
#if(RTA_BSW_BSWSRV_CFG_KNOWN_MACHINE_FAM)

#define RTA_BSW_BSWSRV_START_SEC_CODE
#include "rta_bsw_BswSrv_MemMap.h"
#define RTA_BSW_BSWSRV_STOP_SEC_CODE
#include "rta_bsw_BswSrv_MemMap.h"


/* rta_bsw_BswSrv_Atomic* functions are generally only atomic, if all write actions use rta_bsw_BswSrv_Atomic interfaces. */
/* Exceptions are hardware dependant: for JDP and IFX devices accesses to peripheral registers are atomic even when mixed with normal write accesses. */

/* rta_bsw_BswSrv_SyncWrite* functions ensure that values have been written into physical memory before end of function. */

/* private functions to be used in inline functions only */
/* MISRA RULE 3.4 VIOLATION: pragma is required for function */
#define RTA_BSW_BSWSRV_START_SEC_CODE_FAST
#include "rta_bsw_BswSrv_MemMap.h"
#define RTA_BSW_BSWSRV_STOP_SEC_CODE_FAST
#include "rta_bsw_BswSrv_MemMap.h"

#define RTA_BSW_BSWSRV_START_SEC_CODE_NONEST
#include "rta_bsw_BswSrv_MemMap.h"
#define RTA_BSW_BSWSRV_STOP_SEC_CODE_NONEST
#include "rta_bsw_BswSrv_MemMap.h"

#define RTA_BSW_BSWSRV_START_SEC_CODE_LOW_PRIO
#include "rta_bsw_BswSrv_MemMap.h"
#define RTA_BSW_BSWSRV_STOP_SEC_CODE_LOW_PRIO
#include "rta_bsw_BswSrv_MemMap.h"

#if (MCU_RB_MACHINE_FAM == MCU_RB_JDP_UC1)
#endif
LOCAL_INLINE uint32 rta_bsw_BswSrv_GetPhysCore(void);

/* end of #if(RTA_BSW_BSWSRV_CFG_KNOWN_MACHINE_FAM) */
#endif

#define RTA_BSW_BSWSRV_START_SEC_CODE
#include "rta_bsw_BswSrv_MemMap.h"
extern void* rta_bsw_BswSrv_MemCopy(void* xDest_pv, const void* xSrc_pcv, sint32 numBytes_s32);
extern void* rta_bsw_BswSrv_MemSet(void* xDest_pv, sint32 xPattern_u32, sint32 numBytes_s32);
extern sint32 rta_bsw_BswSrv_MemCompare(const void* xSrc1_pcv, const void* xSrc2_pcv, sint32 numBytes_s32);
#define RTA_BSW_BSWSRV_STOP_SEC_CODE
#include "rta_bsw_BswSrv_MemMap.h"
LOCAL_INLINE uint32 rta_bsw_BswSrv_ByteOrderSwap32(uint32 Input_u32);
LOCAL_INLINE uint16 rta_bsw_BswSrv_ByteOrderSwap16(uint16 Input_u16);
LOCAL_INLINE void   rta_bsw_BswSrv_MemCopy64(rta_bsw_BswSrv_uint64* xDest_pu64, const rta_bsw_BswSrv_uint64* xSrc_pcu64, uint32 numBytes_u32);
LOCAL_INLINE void   rta_bsw_BswSrv_MemCopy32(uint32* xDest_pu32, const uint32* xSrc_pcu32, uint32 numBytes_u32);
LOCAL_INLINE void   rta_bsw_BswSrv_MemCopy16(uint16* xDest_pu16, const uint16* xSrc_pcu16, uint32 numBytes_u32);
LOCAL_INLINE void   rta_bsw_BswSrv_MemCopy8(uint8* xDest_pu8, const uint8* xSrc_pcu8, uint32 numBytes_u32);
LOCAL_INLINE uint32 rta_bsw_BswSrv_MemCompare64(const rta_bsw_BswSrv_uint64* xSrc1_pcu64, const rta_bsw_BswSrv_uint64* xSrc2_pcu64, uint32 numBytes_u32);
LOCAL_INLINE uint32 rta_bsw_BswSrv_MemCompare32(const uint32* xSrc1_pcu32, const uint32* xSrc2_pcu32, uint32 numBytes_u32);
LOCAL_INLINE uint32 rta_bsw_BswSrv_MemCompare16(const uint16* xSrc1_pcu16, const uint16* xSrc2_pcu16, uint32 numBytes_u32);
LOCAL_INLINE uint32 rta_bsw_BswSrv_MemCompare8(const uint8* xSrc1_pcu8, const uint8* xSrc2_pcu8, uint32 numBytes_u32);
LOCAL_INLINE void   rta_bsw_BswSrv_MemSet64(rta_bsw_BswSrv_uint64* xDest_pu64, rta_bsw_BswSrv_uint64 xPattern_u64, uint32 numBytes_u32);
LOCAL_INLINE void   rta_bsw_BswSrv_MemSet32(uint32* xDest_pu32, uint32 xPattern_u32, uint32 numBytes_u32);
LOCAL_INLINE void   rta_bsw_BswSrv_MemSet16(uint16* xDest_pu16, uint32 xPattern_u32, uint32 numBytes_u32);
LOCAL_INLINE void   rta_bsw_BswSrv_MemSet8(uint8* xDest_pu8, uint32 xPattern_u32, uint32 numBytes_u32);

LOCAL_INLINE void rta_bsw_BswSrv_GetLockCommon(void);
LOCAL_INLINE void rta_bsw_BswSrv_ReleaseLockCommon(void);

/**
 *********************************************************************
 * rta_bsw_BswSrv_ByteOrderSwap32
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
LOCAL_INLINE uint32 rta_bsw_BswSrv_ByteOrderSwap32(uint32 Input_u32)
{
    uint32 retVal_u32;

#if defined(RTA_BSW_BSWSRV_PRV_IFX_UC1_ASM)
    asm volatile(" sh.h %0, %1,  8   \r\n\
                   sh.h %1, %1, -8   \r\n\
                   or %1, %0         \r\n\
                   sh %0, %1, -16    \r\n\
                   insert %0, %0, %1, 16, 16 \r\n\
				 ": "=&d" (retVal_u32) : "d" (Input_u32));
#elif defined(RTA_BSW_BSWSRV_PRV_JDP_UC1_ASM)
    asm volatile(" rotlwi %0,%1,8           \r\n\
                   rlwimi %0,%1,24,0,7      \r\n\
                   rlwimi %0,%1,24,16,23    \r\n\
                 ": "=&r" (retVal_u32) : "r" (Input_u32));
#else
    retVal_u32 = (Input_u32 << 24) | ((Input_u32 & 0xFF00u) << 8) | ((Input_u32 & 0x00FF0000u) >> 8) | (Input_u32 >> 24);
#endif

    /* MISRA RULE 9.1 VIOLATION: variable is set by inline assembly but the checker does not understand this */
    return retVal_u32;
}

/**
 *********************************************************************
 * rta_bsw_BswSrv_ByteOrderSwap16
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
LOCAL_INLINE uint16 rta_bsw_BswSrv_ByteOrderSwap16(uint16 Input_u16)
{
    uint16 retVal_u16;

#if defined(RTA_BSW_BSWSRV_PRV_IFX_UC1_ASM)
    asm volatile(" extr.u %0, %1, 8, 8     \r\n\
                   insert %0, %0, %1, 8, 8 \r\n\
                 ": "=&d" (retVal_u16) : "d" (Input_u16));
#else
    retVal_u16 = ((Input_u16 & 0x00FFu) << 8) | ((Input_u16 & 0xFF00u) >> 8);
#endif

    /* MISRA RULE 9.1 VIOLATION: variable is set by inline assembly but the checker does not understand this */
    return retVal_u16;
}


/**
 ***************************************************************************************************
 * rta_bsw_BswSrv_MemCopy64 - copy non overlapping memory in 64 Bit blocks
 *
 * Memory copy routine. Source and destination must not overlap. Pointer parameters must be 8 Byte
 * aligned. The size should be a multiple of 8. If not, it is rounded down to the next multiple
 * of 8.
 *
 * \param   xDest_pu64      destination address
 * \param   xSrc_pcu64      source address
 * \param   numBytes_u32    number of bytes to be copied
 * \seealso     rta_bsw_BswSrv_MemCopy8, rta_bsw_BswSrv_MemCopy16, rta_bsw_BswSrv_MemCopy32
 ***************************************************************************************************
 */
LOCAL_INLINE void rta_bsw_BswSrv_MemCopy64(rta_bsw_BswSrv_uint64* xDest_pu64, const rta_bsw_BswSrv_uint64* xSrc_pcu64, uint32 numBytes_u32)
{
#if defined(RTA_BSW_BSWSRV_PRV_IFX_UC1_ASM)
    rta_bsw_BswSrv_uint64 xTemp_u64;
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < (numBytes_u32 / 8); ctLoop_u32++)
    {
        asm volatile( "         \r\n\
            ld.d   %A0,[%2+]8   \r\n\
            st.d   [%1+]8,%A0   \r\n\
            " : "=d"(xTemp_u64), "+a"(xDest_pu64), "+a"(xSrc_pcu64) : : "memory");
            /*       0                1                 2          */
    }
#elif defined(RTA_BSW_BSWSRV_PRV_JDP_UC1_ASM)
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < (numBytes_u32 / 8); ctLoop_u32++)
    {
        asm volatile(" e_lmw    %%r30,0(%1)  \r\n\
                       e_stmw   %%r30,0(%0)  \r\n\
                       se_addi  %1,8         \r\n\
                       se_addi  %0,8         \r\n\
                     " : "+wr"(xDest_pu64), "+wr"(xSrc_pcu64) : : "r0", "r30", "r31", "memory");
                     /*       0                 1        */
                     /* r0 must be clobbered, because it must not be used for load/store instructions */
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
 * rta_bsw_BswSrv_MemCopy32 - copy non overlapping memory in 32 Bit blocks
 *
 * Memory copy routine. Source and destination must not overlap. Pointer parameters must be 4 Byte
 * aligned. The size should be a multiple of 4. If not, it is rounded down to the next multiple
 * of 4.
 *
 * \param   xDest_pu32      destination address
 * \param   xSrc_pcu32      source address
 * \param   numBytes_u32    number of bytes to be copied
 * \seealso     rta_bsw_BswSrv_MemCopy8, rta_bsw_BswSrv_MemCopy16, rta_bsw_BswSrv_MemCopy64
 ***************************************************************************************************
 */
LOCAL_INLINE void rta_bsw_BswSrv_MemCopy32(uint32* xDest_pu32, const uint32* xSrc_pcu32, uint32 numBytes_u32)
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
 * rta_bsw_BswSrv_MemCopy16 - copy non overlapping memory in 16 Bit blocks
 *
 * Memory copy routine. Source and destination must not overlap. Pointer parameters must be 2 Byte
 * aligned. The size should be a multiple of 2. If not, it is rounded down to the next multiple
 * of 2.
 *
 * \param   xDest_pu16      destination address
 * \param   xSrc_pcu16      source address
 * \param   numBytes_u32    number of bytes to be copied
 * \seealso     rta_bsw_BswSrv_MemCopy8, rta_bsw_BswSrv_MemCopy32, rta_bsw_BswSrv_MemCopy64
 ***************************************************************************************************
 */
LOCAL_INLINE void rta_bsw_BswSrv_MemCopy16(uint16* xDest_pu16, const uint16* xSrc_pcu16, uint32 numBytes_u32)
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
 * rta_bsw_BswSrv_MemCopy8 - copy non overlapping memory
 *
 * Memory copy routine. Source and destination must not overlap.
 *
 * \param   xDest_pu8       destination address
 * \param   xSrc_pcu8       source address
 * \param   numBytes_u32    number of bytes to be copied
 * \seealso     rta_bsw_BswSrv_MemCopy16, rta_bsw_BswSrv_MemCopy32, rta_bsw_BswSrv_MemCopy64
 ***************************************************************************************************
 */
LOCAL_INLINE void rta_bsw_BswSrv_MemCopy8(uint8* xDest_pu8, const uint8* xSrc_pcu8, uint32 numBytes_u32)
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
 * rta_bsw_BswSrv_MemCompare64 - compare memory in 64 Bit blocks
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
 * \seealso     rta_bsw_BswSrv_MemCompare8, rta_bsw_BswSrv_MemCompare16, rta_bsw_BswSrv_MemCompare32
 ***************************************************************************************************
 */
LOCAL_INLINE uint32 rta_bsw_BswSrv_MemCompare64(const rta_bsw_BswSrv_uint64* xSrc1_pcu64, const rta_bsw_BswSrv_uint64* xSrc2_pcu64, uint32 numBytes_u32)
{
#if defined(RTA_BSW_BSWSRV_PRV_IFX_UC1_ASM)
    uint32 stEqual_u32;
    rta_bsw_BswSrv_uint64 xTemp1_u64;
    rta_bsw_BswSrv_uint64 xTemp2_u64;
    uint8* ctLoop_pu8;

    /* initialize return value */
    stEqual_u32 = 1UL;

    if (numBytes_u32 > 7UL)
    {
        /* MISRA RULE 11.3 VIOLATION: cast is required for inline assembly */
        ctLoop_pu8 = (uint8*)((numBytes_u32 / 8UL) - 1UL);

        /* fast forward compare loop */
        asm volatile(
        "                       \r\n\
        1:                      \r\n\
            ld.d   %A4,[%1+]8   \r\n\
            ld.d   %A5,[%2+]8   \r\n\
            jne    %L4,%L5,2f   \r\n\
            jne    %H4,%H5,2f   \r\n\
            loop   %3,1b        \r\n\
            mov    %0,0         \r\n\
        2:                      \r\n\
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
 * rta_bsw_BswSrv_MemCompare32 - compare memory in 32 Bit blocks
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
 * \seealso     rta_bsw_BswSrv_MemCompare8, rta_bsw_BswSrv_MemCompare16, rta_bsw_BswSrv_MemCompare64
 ***************************************************************************************************
 */
LOCAL_INLINE uint32 rta_bsw_BswSrv_MemCompare32(const uint32* xSrc1_pcu32, const uint32* xSrc2_pcu32, uint32 numBytes_u32)
{
#if defined(RTA_BSW_BSWSRV_PRV_IFX_UC1_ASM)
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
        "                       \r\n\
        1:                      \r\n\
            ld.w   %4,[%1+]4    \r\n\
            ld.w   %5,[%2+]4    \r\n\
            jne    %4,%5,2f     \r\n\
            loop   %3,1b        \r\n\
            mov    %0,0         \r\n\
        2:                      \r\n\
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
 * rta_bsw_BswSrv_MemCompare16 - compare memory in 16 Bit blocks
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
 * \seealso     rta_bsw_BswSrv_MemCompare8, rta_bsw_BswSrv_MemCompare32, rta_bsw_BswSrv_MemCompare64
 ***************************************************************************************************
 */
LOCAL_INLINE uint32 rta_bsw_BswSrv_MemCompare16(const uint16* xSrc1_pcu16, const uint16* xSrc2_pcu16, uint32 numBytes_u32)
{
#if defined(RTA_BSW_BSWSRV_PRV_IFX_UC1_ASM)
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
        "                       \r\n\
        1:                      \r\n\
            ld.hu  %4,[%1+]2    \r\n\
            ld.hu  %5,[%2+]2    \r\n\
            jne    %4,%5,2f     \r\n\
            loop   %3,1b        \r\n\
            mov    %0,0         \r\n\
        2:                      \r\n\
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
 * rta_bsw_BswSrv_MemCompare8 - compare memory
 *
 * Memory compare routine.
 *
 * \param   xSrc1_pcu8      pointer to the first source address
 * \param   xSrc2_pcu8      pointer to the second source address
 * \param   numBytes_u32    number of bytes to be compared
 * \return  stEqual_u32     result of comparison
 * \retval  0               memory area contents are equal
 * \retval  1               memory area contents differ
 * \seealso     rta_bsw_BswSrv_MemCompare16, rta_bsw_BswSrv_MemCompare32, rta_bsw_BswSrv_MemCompare64
 ***************************************************************************************************
 */
LOCAL_INLINE uint32 rta_bsw_BswSrv_MemCompare8(const uint8* xSrc1_pcu8, const uint8* xSrc2_pcu8, uint32 numBytes_u32)
{
#if defined(RTA_BSW_BSWSRV_PRV_IFX_UC1_ASM)
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
        "                       \r\n\
        1:                      \r\n\
            ld.bu  %4,[%1+]1    \r\n\
            ld.bu  %5,[%2+]1    \r\n\
            jne    %4,%5,2f     \r\n\
            loop   %3,1b        \r\n\
            mov    %0,0         \r\n\
        2:                      \r\n\
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
 * rta_bsw_BswSrv_MemSet64 - initialize memory with 64 Bit data
 *
 * Memory initialization routine. 64 Bit Pattern is written to the destination.
 * Destination must be 4 Byte aligned. The size should be a multiple of 8. If not, it is rounded
 * down to the next multiple of 8.
 *
 * \param   xDest_pu32      destination address
 * \param   Pattern_u32     fill pattern
 * \param   numBytes_u32    number of bytes to be initialized
 * \seealso     rta_bsw_BswSrv_MemSet8, rta_bsw_BswSrv_MemSet16, rta_bsw_BswSrv_MemSet32
 ***************************************************************************************************
 */
LOCAL_INLINE void rta_bsw_BswSrv_MemSet64(rta_bsw_BswSrv_uint64* xDest_pu64, rta_bsw_BswSrv_uint64 xPattern_u64, uint32 numBytes_u32)
{
#if defined(RTA_BSW_BSWSRV_PRV_IFX_UC1_ASM)
    uint8* ct_pu8;

    if (numBytes_u32 > 7UL)
    {
        /* MISRA RULE 11.3 VIOLATION: cast is required for inline assembly */
        ct_pu8      = (uint8*)(((numBytes_u32) / 8UL) - 1UL);

        /* fast forward copy loop */
        asm volatile(
        "                       \r\n\
        1:                      \r\n\
            st.d   [%0+]8,%A2   \r\n\
            loop   %1,1b        \r\n\
        "
        : "+a"(xDest_pu64), "+a"(ct_pu8) : "d"(xPattern_u64): "memory");
        /*   0                1             2     */
    }
#elif defined(RTA_BSW_BSWSRV_PRV_JDP_UC1_ASM)
    if (numBytes_u32 > 7UL)
    {
        uint32 ctLoop_u32 = numBytes_u32 / 8;

        /* fast forward copy loop */
        asm volatile("                      \r\n\
                mr   %%r30,%H[Pattern]      \r\n\
                mr   %%r31,%L[Pattern]      \r\n\
                mtctr   %[ctLoop]           \r\n\
            1:                              \r\n\
                e_stmw  %%r30,0(%[Dest])    \r\n\
                se_addi %[Dest],8           \r\n\
                e_bc 2,lt,1b                \r\n\
            " : [ctLoop] "+r"(ctLoop_u32), [Dest] "+wr"(xDest_pu64) : [Pattern] "r"(xPattern_u64) : "ctr", "r0","r30", "r31", "memory");
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
 * rta_bsw_BswSrv_MemSet32 - initialize memory with 32 Bit data
 *
 * Memory initialization routine. 32 Bit Pattern is written to the destination.
 * Destination must be 4 Byte aligned. The size should be a multiple of 4. If not, it is rounded
 * down to the next multiple of 4.
 *
 * \param   xDest_pu32      destination address
 * \param   Pattern_u32     fill pattern
 * \param   numBytes_u32    number of bytes to be initialized
 * \seealso     rta_bsw_BswSrv_MemSet8, rta_bsw_BswSrv_MemSet16, rta_bsw_BswSrv_MemSet64
 ***************************************************************************************************
 */
LOCAL_INLINE void rta_bsw_BswSrv_MemSet32(uint32* xDest_pu32, uint32 xPattern_u32, uint32 numBytes_u32)
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
 * rta_bsw_BswSrv_MemSet16 - initialize memory with 16 Bit data
 *
 * Memory initialization routine. 16 Bit Pattern is written to the destination.
 * Destination must be 2 Byte aligned. The size should be a multiple of 2. If not, it is rounded
 * down to the next multiple of 2.
 *
 * \param   xDest_pu32      destination address
 * \param   Pattern_u32     fill pattern
 * \param   numBytes_u32    number of bytes to be initialized
 * \seealso     rta_bsw_BswSrv_MemSet8, rta_bsw_BswSrv_MemSet32, rta_bsw_BswSrv_MemSet64
 ***************************************************************************************************
 */
LOCAL_INLINE void rta_bsw_BswSrv_MemSet16(uint16* xDest_pu16, uint32 xPattern_u32, uint32 numBytes_u32)
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
 * rta_bsw_BswSrv_MemSet8 - initialize memory with 8 Bit data
 *
 * Memory initialization routine. 8 Bit Pattern is written to the destination.
 *
 * \param   xDest_pu8       destination address
 * \param   xPattern_u32    fill pattern, only lower 8 bit used
 * \param   numBytes_u32    number of bytes to be initialized
 * \seealso     rta_bsw_BswSrv_MemSet16, rta_bsw_BswSrv_MemSet32, rta_bsw_BswSrv_MemSet64
 ***************************************************************************************************
 */
LOCAL_INLINE void rta_bsw_BswSrv_MemSet8(uint8* xDest_pu8, uint32 xPattern_u32, uint32 numBytes_u32)
{
    uint32 ctLoop_u32;

    for(ctLoop_u32 = 0; ctLoop_u32 < numBytes_u32; ctLoop_u32++)
    {
        *xDest_pu8 = (uint8)xPattern_u32;
        xDest_pu8++;
    }

    return;
}

/**
 *********************************************************************
 * rta_bsw_BswSrv_GetLockCommon
 *
 * Get common spinlock. Must not be called, if a nonest lock is already
 * active for the current core.
 *********************************************************************
 */
LOCAL_INLINE void rta_bsw_BswSrv_GetLockCommon(void)
{
	return;
}

/**
 *********************************************************************
 * rta_bsw_BswSrv_ReleaseLockCommon
 *
 * Release common spinlock. Must not be called, if a nonest lock is already
 * active for the current core.
 *********************************************************************
 */
LOCAL_INLINE void rta_bsw_BswSrv_ReleaseLockCommon(void)
{
	return;
}
/* end of #ifndef RTA_BSW_BSWSRV_H */
#endif


/*<BASDKey>
**********************************************************************************************************************
* $History__:$
**********************************************************************************************************************
</BASDKey>*/

/*<BASDKey>
**********************************************************************************************************************
* End of header file: $Name______:rta_bsw_BswSrv$
**********************************************************************************************************************
</BASDKey>*/
