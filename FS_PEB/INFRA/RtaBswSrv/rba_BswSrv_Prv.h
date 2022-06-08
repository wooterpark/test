


#ifndef RBA_BSWSRV_PRV_H
#define RBA_BSWSRV_PRV_H

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */
#if(RBA_BSWSRV_CFG_KNOWN_MACHINE_FAM) && !defined(RBA_BSWSRV_CFG_HSM_CORE)
#include "Os.h"
 
/*
 ***************************************************************************************************
 * Defines
 ***************************************************************************************************
 */

#define RBA_BSWSRV_PRV_LOG_LEVEL 1 /* 0: no logging, 1: +interrupt suspend time log, 2: +lock counter */
 
#if (defined(RBA_BSWSRV_PRV_C_LOCK)) && (RBA_BSWSRV_MAX_PHYS_CORE > 4)
#  error "Current implementation only supports  up to 4 cores."
#endif

#if defined(RBA_BSWSRV_PRV_IFX_ARCH)
#  define RBA_BSWSRV_DATA_SYNC RBA_BSWSRV_IFX_DSYNC
#elif defined(RBA_BSWSRV_PRV_POWER_ARCH)
#  define RBA_BSWSRV_DATA_SYNC RBA_BSWSRV_JDP_MSYNC
#else
#  error "CPU architecture is not supported"
#endif

/* MISRA RULE 19.4 VIOLATION: unbalanced brackets are required here */
#ifdef RBA_BSWSRV_CFG_USER_MODE_SUPPORT
#  if defined(RBA_BSWSRV_PRV_IFX_ARCH)
#    define RBA_BSWSRV_PRV_SUPERVISOR_MODE()                                \
do {                                                                        \
    /* switch to Supervisor mode if in User mode */                         \
    uint32 regPsw_u32 = RBA_BSWSRV_IFX_MFCR(RBA_REG_CSFR_PSW_MXCR_OFFSET);  \
    if (0U == (regPsw_u32 & 0x800u))                                        \
    {                                                                       \
        asm volatile ("syscall 0":::"memory");                              \
    }                                                                       \
    do {} while(0)
#    define RBA_BSWSRV_PRV_RESTORE_MODE()                                   \
    /* restore User mode */                                                 \
    if (0U == (regPsw_u32 & 0x800u))                                        \
    {                                                                       \
        RBA_BSWSRV_IFX_DSYNC();                                             \
        RBA_BSWSRV_IFX_MTCR(RBA_REG_CSFR_PSW_MXCR_OFFSET, regPsw_u32);      \
        RBA_BSWSRV_IFX_ISYNC();                                             \
    }                                                                       \
} while(0)
#  else
#    define RBA_BSWSRV_PRV_SUPERVISOR_MODE()    do { do {} while(0)
#    define RBA_BSWSRV_PRV_RESTORE_MODE()       } while(0)
#    error "User mode support is not implemented for selected machine family"
#  endif
#else
#  define RBA_BSWSRV_PRV_SUPERVISOR_MODE()      do { do {} while(0)
#  define RBA_BSWSRV_PRV_RESTORE_MODE()         } while(0)
#endif

#ifdef RBA_MEMLAY_DATA_RAM_ALL
/* with CPU instanced memory at the same address */
#define RBA_BSWSRV_NUM_CORE_DATA RBA_BSWSRV_NUM_USED_CORE
#else
/* without CPU instanced memory at the same address */
#define RBA_BSWSRV_NUM_CORE_DATA RBA_BSWSRV_MAX_PHYS_CORE
#endif

/*
 *********************************************************************
 * Type definition
 *********************************************************************
 */

#if RBA_BSWSRV_PRV_LOG_LEVEL >= 1
typedef struct
{
    uint32 adLastSuspend_u32;
    uint32 tiMaxIntSuspend_u32;
    uint32 adMaxIntSuspend_u32;
    uint32 adMaxIntSuspendIgnore_u32;
    uint32 tiCurrIntSuspend_u32;
    uint16 ctIntSuspend_u16;
    uint16 ctIntSuspendRef_u16;
    #if (RBA_BSWSRV_NUM_USED_CORE > 1)
    uint16 ctLockUse_u16;
    uint16 ctLockUseRef_u16;
    uint16 ctLockWait_u16;
    uint16 ctLockWaitRef_u16;
    #endif
} rba_BswSrv_Log_tst;
#endif

typedef struct
{
    #if RBA_BSWSRV_PRV_LOG_LEVEL >= 1
    uint32 stLogEnable_u32;
    rba_BswSrv_Log_tst              Log_st;
    rba_BswSrv_Log_tst              LogLowPrio_st;
    #endif
    #if (RBA_BSWSRV_NUM_USED_CORE > 1)
    rba_BswSrv_Lock_to* volatile    ActiveNonestLock_vpst;
    #endif
    uint16                          IntMaskRestore_u16;
    uint8                           ctIntSuspLvl_u8;
    uint16                          LowPrioIntMaskRestore_u16;
    uint8                           ctLowPrioIntSuspLvl_u8;
    uint8                           stLowPrioInitFinished_u8;
} rba_BswSrv_CoreData_tst;

/*
 ***************************************************************************************************
 * Variable declarations
 ***************************************************************************************************
 */

#define RBA_BSWSRV_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "rba_BswSrv_MemMap.h"
extern rba_BswSrv_Lock_to rba_BswSrv_LockCommon_st;
extern rba_BswSrv_Lock_to rba_BswSrv_LockLowPrio_st;
#define RBA_BSWSRV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "rba_BswSrv_MemMap.h"

#ifdef RBA_MEMLAY_DATA_RAM_ALL
/* use CPU instanced memory instead of an array element for each core */
/* IFX supports local RAM addressing in hardware. For JDP it is emulated with small addressing */
#  define RBA_BSWSRV_START_SEC_RAMALL_CLEARED_UNSPECIFIED
#  include "rba_BswSrv_MemMap.h"
extern rba_BswSrv_CoreData_tst rba_BswSrv_LocalCoreData_st;
#  define RBA_BSWSRV_STOP_SEC_RAMALL_CLEARED_UNSPECIFIED
#  include "rba_BswSrv_MemMap.h"
/* just to be able to read/modify the data by debugger */
#  define RBA_BSWSRV_START_SEC_CONST_UNSPECIFIED
#  include "rba_BswSrv_MemMap.h"
extern rba_BswSrv_CoreData_tst* const rba_BswSrv_CoreData_capst[RBA_BSWSRV_NUM_CORE_DATA];
#  define RBA_BSWSRV_STOP_SEC_CONST_UNSPECIFIED
#  include "rba_BswSrv_MemMap.h"
#else
/* without CPU instanced memory at the same address */
#  define RBA_BSWSRV_START_SEC_VAR_CLEARED_UNSPECIFIED
#  include "rba_BswSrv_MemMap.h"
extern rba_BswSrv_CoreData_tst rba_BswSrv_CoreData_ast[RBA_BSWSRV_NUM_CORE_DATA];
#  define RBA_BSWSRV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#  include "rba_BswSrv_MemMap.h"
#endif

/* Measurement values of violations stored in ENVRAM */
#define RBA_BSWSRV_START_SEC_ENVRAM_32
#include "rba_BswSrv_MemMap.h"
extern uint32 rba_BswSrv_adIntSuspCtrViolation;
extern uint32 rba_BswSrv_adIntSuspCorruption;
extern uint32 rba_BswSrv_adLockNestingViolation;
extern uint32 rba_BswSrv_adLockCounterViolation;
#define RBA_BSWSRV_STOP_SEC_ENVRAM_32
#include "rba_BswSrv_MemMap.h"

/* Measurement values for counting of lock and interrupt suspend actions for each core */
#if RBA_BSWSRV_PRV_LOG_LEVEL >= 1
#  define RBA_BSWSRV_START_SEC_VAR_CLEARED_UNSPECIFIED
#  include "rba_BswSrv_MemMap.h"
extern uint16 rba_BswSrv_ctIntSuspend10ms[RBA_BSWSRV_NUM_CORE_DATA];
extern uint16 rba_BswSrv_ctLowPrioIntSuspend10ms[RBA_BSWSRV_NUM_CORE_DATA];
#  if (RBA_BSWSRV_NUM_USED_CORE > 1)
extern uint16 rba_BswSrv_ctLockUse10ms[RBA_BSWSRV_NUM_CORE_DATA];
extern uint16 rba_BswSrv_ctLowPrioLockUse10ms[RBA_BSWSRV_NUM_CORE_DATA];
extern uint16 rba_BswSrv_ctLockWait10ms[RBA_BSWSRV_NUM_CORE_DATA];
extern uint16 rba_BswSrv_ctLowPrioLockWait10ms[RBA_BSWSRV_NUM_CORE_DATA];
#  endif
#  define RBA_BSWSRV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#  include "rba_BswSrv_MemMap.h"
#endif

/* Measurement values for counting common lock */
#if RBA_BSWSRV_PRV_LOG_LEVEL >= 2
#  define RBA_BSWSRV_START_SEC_VAR_CLEARED_32
#  include "rba_BswSrv_MemMap.h"
extern uint32 rba_BswSrv_ctUseLockCommon;       /* lock use counter */
extern uint32 rba_BswSrv_ctWaitLockCommon;      /* lock wait counter */
extern uint32 rba_BswSrv_ctSelfNestLockCommon;  /* lock self nesting counter */
#  define RBA_BSWSRV_STOP_SEC_VAR_CLEARED_32
#  include "rba_BswSrv_MemMap.h"
#endif

/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
 */
/* rba_BswSrv_JumpResetRequest - force jump to reset to keep return address from calling function outside rba_BswSrv */
#define RBA_BSWSRV_START_SEC_CODE
#include "rba_BswSrv_MemMap.h"
extern void rba_BswSrv_JumpResetRequestDo(uint32 dResetIdentifier_u32) __attribute__ ((__noreturn__));
#define RBA_BSWSRV_STOP_SEC_CODE
#include "rba_BswSrv_MemMap.h"
LOCAL_INLINE void rba_BswSrv_JumpResetRequest(uint32 dResetIdentifier_u32);

LOCAL_INLINE uint32 rba_BswSrv_GetReturnAddress(void);
#if !defined(RBA_BSWSRV_PRV_C_LOCK) && !defined(RBA_BSWSRV_PRV_SWAP_LOCK)
LOCAL_INLINE uint32 rba_BswSrv_PrvTryToGetLock(volatile uint32* LockVar_pvu32, uint32 RequestedLock_u32);
#endif
#if !defined(RBA_BSWSRV_PRV_C_LOCK)
LOCAL_INLINE void rba_BswSrv_PrvWriteLock(volatile uint32* LockVar_pvu32, uint32 LockValue_u32);
#endif
 
/*
 ***************************************************************************************************
 * Inline functions
 ***************************************************************************************************
 */

/*
 *********************************************************************
 * rba_BswSrv_JumpResetRequest - force jump to reset to reduce context saves and keep return address.
 *********************************************************************
 */
LOCAL_INLINE void rba_BswSrv_JumpResetRequest(uint32 dResetIdentifier_u32)
{
#if defined(RBA_BSWSRV_PRV_POWER_ARCH)
    /* use inline assembler to force jump to reset function as "noreturn" still generates context save for JDP */
    asm volatile (" \n\
        li %%r3,%0  \n\
        b rba_BswSrv_JumpResetRequestDo": :"i" (dResetIdentifier_u32): "memory");
    do {} while(TRUE); /* tell the compiler that this function never returns */
#else
    rba_BswSrv_JumpResetRequestDo(dResetIdentifier_u32);
#endif
}

/*
 *********************************************************************
 * rba_BswSrv_GetReturnAddress - Get return address of calling function.
 *
 * use inline function to keep information about calling function
 *********************************************************************
 */
LOCAL_INLINE uint32 rba_BswSrv_GetReturnAddress(void)
{
    uint32 adrReturn_u32;

    #if defined(RBA_BSWSRV_PRV_IFX_ARCH)
    asm volatile ("mov.d %0, %%a11":"=d" (adrReturn_u32));
    #elif defined(RBA_BSWSRV_PRV_POWER_ARCH)
    asm volatile ("mflr %0":"=r" (adrReturn_u32));
    #else
    #  error "CPU architecture is not supported"
    #endif
    
    /* MISRA RULE 9.1 VIOLATION: adrReturn_u32 is definitely set by assembler statement before */
    return adrReturn_u32;
}

/*********************************************************************
 * rba_BswSrv_PrvTryToGetLock - atomic test and set.
 *
 * Test and set is atomic, but information whether this was successful is not atomic on JDP.
 * Therefore it is necessary to store the origin of the lock!
 *********************************************************************
 */
#if !defined(RBA_BSWSRV_PRV_C_LOCK) && !defined(RBA_BSWSRV_PRV_SWAP_LOCK)
/* MISRA RULE 16.7 VIOLATION: *LockVar_pvu32 is definitely modified by assembler statement. */
LOCAL_INLINE uint32 rba_BswSrv_PrvTryToGetLock(volatile uint32* LockVar_pvu32, uint32 RequestedLock_u32)
{
    /* Atomic set word if zero */
#if defined(RBA_BSWSRV_PRV_POWER_ARCH)
    /* Use decorated read instruction with "Load-and-Set-1(Bit)" decoration */
    /* Attention: this is only atomic, if all write action use decorated write instructions. See rba_BswSrv_PrvWriteLock(...) */
    uint32 Decoration_u32 = 0x60000000u | ((31u - 7u) << 22u); /* set lock bit 0x00000080 */
    uint32 PrevValue_u32;
    asm volatile ("lwdx %0,%2,%1" : "=r" (PrevValue_u32) : "r" (LockVar_pvu32), "r" (Decoration_u32) : "memory");
    /* MISRA RULE 9.1 VIOLATION: PrevValue_u32 is definitely set by assembler statement before */
    if (PrevValue_u32 == 0u) /* return TRUE if value has been set */
    {
        rba_BswSrv_PrvWriteLock(LockVar_pvu32, RequestedLock_u32); /* add Lock information */
    }
    return PrevValue_u32;
#elif defined(RBA_BSWSRV_PRV_IFX_ARCH)
    rba_BswSrv_uint64 CmpSwap_u64 = RequestedLock_u32;
    /* The CMPSWAP.W instruction conditionally swaps the data register D[a] and the contents of the memory word.
       If the contents of the memory word is equal to the contents of register D[a+1] then swap the contents of the memory 
       word with the register D[a]. Register D[a] is unconditionally updated with the contents of the memory word. */
    asm volatile(" cmpswap.w [%1]0,%A0 " : "+d"(CmpSwap_u64) : "a"(LockVar_pvu32): "memory");
    return (uint32)CmpSwap_u64; /* return previous value */
#else
#error "CPU architecture is not supported"
#endif
}
#endif

/*********************************************************************
 * rba_BswSrv_PrvWriteLock - Store to allow atomic test and Set.
 *********************************************************************
 */
#if !defined(RBA_BSWSRV_PRV_C_LOCK)
/* MISRA RULE 16.7 VIOLATION: *LockVar_pvu32 is definitely modified by assembler statement. */
LOCAL_INLINE void rba_BswSrv_PrvWriteLock(volatile uint32* LockVar_pvu32, uint32 LockValue_u32)
{
#if defined(RBA_BSWSRV_PRV_POWER_ARCH)
    /* workaround for a hardware problem: previous write gets lost, if there is a concurrent "atomic set word if zero" stwdx */
    uint32 Decoration_u32 = 0x00000000u;
    asm volatile ("stwdx %1,%2,%0" : : "r" (LockVar_pvu32), "r" (LockValue_u32), "r" (Decoration_u32) : "memory");
#else
    *LockVar_pvu32 = LockValue_u32;
#endif
}
#endif

/* end #if(RBA_BSWSRV_CFG_KNOWN_MACHINE_FAM) && !defined(RBA_BSWSRV_CFG_HSM_CORE) */
#endif
 
/* end of #ifndef RBA_BSWSRV_PRV_H */
#endif

/*<BASDKey>
**********************************************************************************************************************
* $History__:$
**********************************************************************************************************************
</BASDKey>*/

/*<BASDKey>
**********************************************************************************************************************
* End of header file: $Name______:rba_BswSrv_Prv$
**********************************************************************************************************************
</BASDKey>*/
