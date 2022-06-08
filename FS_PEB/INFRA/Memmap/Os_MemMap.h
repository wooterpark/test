/*
 * This is Os_MemMap.h, auto-generated for:
 *   Project: Os_Config
 *   Target:  TriCoreTasking
 *   Variant: TC27xC
 *   Version: 5.0.2
 *   It should be either copied into MemMap.h by the integrator OR #included into it.
 */
/* Generator info: generate_always */
/* This file defines the OS-specific MemMap.h [$UKS 652] [$UKS 653] [$UKS 655] [$UKS 656] [$UKS 657] */
#if defined (START_WITH_IF)
/* OS Uninitialized RAM: trace data */
#elif defined (OS_START_SEC_VAR_TRACE)
  #undef      OS_START_SEC_VAR_TRACE
  #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_TRACE)
  #undef      OS_STOP_SEC_VAR_TRACE
  #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED

/* OS Uninitialized RAM: boolean */
#elif defined (OS_START_SEC_VAR_NOINIT_BOOLEAN)
  #undef      OS_START_SEC_VAR_NOINIT_BOOLEAN
  #define SHARED_RO_START_SEC_RAM_CLEARED_BOOL
#elif defined (OS_STOP_SEC_VAR_NOINIT_BOOLEAN)
  #undef      OS_STOP_SEC_VAR_NOINIT_BOOLEAN
  #define SHARED_RO_STOP_SEC_RAM_CLEARED_BOOL

/* OS Uninitialized RAM: 8 bit values */
#elif defined (OS_START_SEC_VAR_NOINIT_8BIT)
  #undef      OS_START_SEC_VAR_NOINIT_8BIT
  #define SHARED_RO_START_SEC_RAM_CLEARED_8
#elif defined (OS_STOP_SEC_VAR_NOINIT_8BIT)
  #undef      OS_STOP_SEC_VAR_NOINIT_8BIT
  #define SHARED_RO_STOP_SEC_RAM_CLEARED_8

/* OS Uninitialized RAM: 16 bit values */
#elif defined (OS_START_SEC_VAR_NOINIT_16BIT)
  #undef      OS_START_SEC_VAR_NOINIT_16BIT
  #define SHARED_RO_START_SEC_RAM_CLEARED_16
#elif defined (OS_STOP_SEC_VAR_NOINIT_16BIT)
  #undef      OS_STOP_SEC_VAR_NOINIT_16BIT
  #define SHARED_RO_STOP_SEC_RAM_CLEARED_16

/* OS Uninitialized RAM: 32 bit values */
#elif defined (OS_START_SEC_VAR_NOINIT_32BIT)
  #undef      OS_START_SEC_VAR_NOINIT_32BIT
  #define SHARED_RO_START_SEC_RAM_CLEARED_32
#elif defined (OS_STOP_SEC_VAR_NOINIT_32BIT)
  #undef      OS_STOP_SEC_VAR_NOINIT_32BIT
  #define SHARED_RO_STOP_SEC_RAM_CLEARED_32

/* OS Uninitialized RAM: unspecified size */
#elif defined (OS_START_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef      OS_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define SHARED_RO_START_SEC_RAM_CLEARED_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef      OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define SHARED_RO_STOP_SEC_RAM_CLEARED_UNSPECIFIED

/* OS Power-on initialized RAM: boolean */
#elif defined (OS_START_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef      OS_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
  #define SHARED_RO_START_SEC_RAM_INIT_BOOL
#elif defined (OS_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef      OS_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
  #define SHARED_RO_STOP_SEC_RAM_INIT_BOOL

/* OS Power-on initialized RAM: 8 bit values */
#elif defined (OS_START_SEC_VAR_POWER_ON_INIT_8BIT)
  #undef      OS_START_SEC_VAR_POWER_ON_INIT_8BIT
  #define SHARED_RO_START_SEC_RAM_INIT_8
#elif defined (OS_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
  #undef      OS_STOP_SEC_VAR_POWER_ON_INIT_8BIT
  #define SHARED_RO_STOP_SEC_RAM_INIT_8

/* OS Power-on initialized RAM: 16 bit values */
#elif defined (OS_START_SEC_VAR_POWER_ON_INIT_16BIT)
  #undef      OS_START_SEC_VAR_POWER_ON_INIT_16BIT
  #define SHARED_RO_START_SEC_RAM_INIT_16
#elif defined (OS_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
  #undef      OS_STOP_SEC_VAR_POWER_ON_INIT_16BIT
  #define SHARED_RO_STOP_SEC_RAM_INIT_16

/* OS Power-on initialized RAM: 32 bit values */
#elif defined (OS_START_SEC_VAR_POWER_ON_INIT_32BIT)
  #undef      OS_START_SEC_VAR_POWER_ON_INIT_32BIT
  #define SHARED_RO_START_SEC_RAM_INIT_32
#elif defined (OS_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
  #undef      OS_STOP_SEC_VAR_POWER_ON_INIT_32BIT
  #define SHARED_RO_STOP_SEC_RAM_INIT_32

/* OS Power-on initialized RAM: unspecified size */
#elif defined (OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef      OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
  #define SHARED_RO_START_SEC_RAM_INIT_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef      OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
  #define SHARED_RO_STOP_SEC_RAM_INIT_UNSPECIFIED

/******************************
 * For write access OS data **
 *****************************/
/* OS Uninitialized RAM: boolean */
#elif defined (OS_WRITABLE_START_SEC_VAR_NOINIT_BOOLEAN)
  #undef      OS_WRITABLE_START_SEC_VAR_NOINIT_BOOLEAN
  #define SHARED_START_SEC_RAM_CLEARED_BOOL
#elif defined (OS_WRITABLE_STOP_SEC_VAR_NOINIT_BOOLEAN)
  #undef      OS_WRITABLE_STOP_SEC_VAR_NOINIT_BOOLEAN
  #define SHARED_STOP_SEC_RAM_CLEARED_BOOL

/* OS Uninitialized RAM: 8 bit values */
#elif defined (OS_WRITABLE_START_SEC_VAR_NOINIT_8BIT)
  #undef      OS_WRITABLE_START_SEC_VAR_NOINIT_8BIT
  #define SHARED_START_SEC_RAM_CLEARED_8
#elif defined (OS_WRITABLE_STOP_SEC_VAR_NOINIT_8BIT)
  #undef      OS_WRITABLE_STOP_SEC_VAR_NOINIT_8BIT
  #define SHARED_STOP_SEC_RAM_CLEARED_8

/* OS Uninitialized RAM: 16 bit values */
#elif defined (OS_WRITABLE_START_SEC_VAR_NOINIT_16BIT)
  #undef      OS_WRITABLE_START_SEC_VAR_NOINIT_16BIT
  #define SHARED_START_SEC_RAM_CLEARED_16
#elif defined (OS_WRITABLE_STOP_SEC_VAR_NOINIT_16BIT)
  #undef      OS_WRITABLE_STOP_SEC_VAR_NOINIT_16BIT
  #define SHARED_STOP_SEC_RAM_CLEARED_16

/* OS Uninitialized RAM: 32 bit values */
#elif defined (OS_WRITABLE_START_SEC_VAR_NOINIT_32BIT)
  #undef      OS_WRITABLE_START_SEC_VAR_NOINIT_32BIT
  #define SHARED_START_SEC_RAM_CLEARED_32
#elif defined (OS_WRITABLE_STOP_SEC_VAR_NOINIT_32BIT)
  #undef      OS_WRITABLE_STOP_SEC_VAR_NOINIT_32BIT
  #define SHARED_STOP_SEC_RAM_CLEARED_32

/* OS Uninitialized RAM: unspecified size */
#elif defined (OS_WRITABLE_START_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef      OS_WRITABLE_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define SHARED_START_SEC_RAM_CLEARED_UNSPECIFIED
#elif defined (OS_WRITABLE_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef      OS_WRITABLE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define SHARED_STOP_SEC_RAM_CLEARED_UNSPECIFIED

/* OS Power-on initialized RAM: boolean */
#elif defined (OS_WRITABLE_START_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef      OS_WRITABLE_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
  #define SHARED_START_SEC_RAM_INIT_BOOL
#elif defined (OS_WRITABLE_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef      OS_WRITABLE_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
  #define SHARED_STOP_SEC_RAM_INIT_BOOL

/* OS Power-on initialized RAM: 8 bit values */
#elif defined (OS_WRITABLE_START_SEC_VAR_POWER_ON_INIT_8BIT)
  #undef      OS_WRITABLE_START_SEC_VAR_POWER_ON_INIT_8BIT
  #define SHARED_START_SEC_RAM_INIT_8
#elif defined (OS_WRITABLE_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
  #undef      OS_WRITABLE_STOP_SEC_VAR_POWER_ON_INIT_8BIT
  #define SHARED_STOP_SEC_RAM_INIT_8

/* OS Power-on initialized RAM: 16 bit values */
#elif defined (OS_WRITABLE_START_SEC_VAR_POWER_ON_INIT_16BIT)
  #undef      OS_WRITABLE_START_SEC_VAR_POWER_ON_INIT_16BIT
  #define SHARED_START_SEC_RAM_INIT_16
#elif defined (OS_WRITABLE_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
  #undef      OS_WRITABLE_STOP_SEC_VAR_POWER_ON_INIT_16BIT
  #define SHARED_STOP_SEC_RAM_INIT_16

/* OS Power-on initialized RAM: 32 bit values */
#elif defined (OS_WRITABLE_START_SEC_VAR_POWER_ON_INIT_32BIT)
  #undef      OS_WRITABLE_START_SEC_VAR_POWER_ON_INIT_32BIT
  #define SHARED_START_SEC_RAM_INIT_32
#elif defined (OS_WRITABLE_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
  #undef      OS_WRITABLE_STOP_SEC_VAR_POWER_ON_INIT_32BIT
  #define SHARED_STOP_SEC_RAM_INIT_32

/* OS Power-on initialized RAM: unspecified size */
#elif defined (OS_WRITABLE_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef      OS_WRITABLE_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
  #define SHARED_START_SEC_RAM_INIT_UNSPECIFIED
#elif defined (OS_WRITABLE_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef      OS_WRITABLE_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
  #define SHARED_STOP_SEC_RAM_INIT_UNSPECIFIED


/* OS Initialized RAM: boolean */
#elif defined (OS_START_SEC_VAR_BOOLEAN)
  #undef      OS_START_SEC_VAR_BOOLEAN
  #define DEFAULT_START_SEC_VAR_BOOLEAN
#elif defined (OS_STOP_SEC_VAR_BOOLEAN)
  #undef      OS_STOP_SEC_VAR_BOOLEAN
  #define DEFAULT_STOP_SEC_VAR_BOOLEAN

/* OS Initialized RAM: 8 bit values */
#elif defined (OS_START_SEC_VAR_8BIT)
  #undef      OS_START_SEC_VAR_8BIT
  #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (OS_STOP_SEC_VAR_8BIT)
  #undef      OS_STOP_SEC_VAR_8BIT
  #define DEFAULT_STOP_SEC_VAR_8BIT

/* OS Initialized RAM: 16 bit values */
#elif defined (OS_START_SEC_VAR_16BIT)
  #undef      OS_START_SEC_VAR_16BIT
  #define DEFAULT_START_SEC_VAR_16BIT
#elif defined (OS_STOP_SEC_VAR_16BIT)
  #undef      OS_STOP_SEC_VAR_16BIT
  #define DEFAULT_STOP_SEC_VAR_16BIT

/* OS Initialized RAM: 32 bit values */
#elif defined (OS_START_SEC_VAR_32BIT)
  #undef      OS_START_SEC_VAR_32BIT
  #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (OS_STOP_SEC_VAR_32BIT)
  #undef      OS_STOP_SEC_VAR_32BIT
  #define DEFAULT_STOP_SEC_VAR_32BIT

/* OS Initialized RAM: unspecified size */
#elif defined (OS_START_SEC_VAR_UNSPECIFIED)
  #undef      OS_START_SEC_VAR_UNSPECIFIED
  #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_UNSPECIFIED)
  #undef      OS_STOP_SEC_VAR_UNSPECIFIED
  #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/* OS Initialized fast RAM: boolean */
#elif defined (OS_START_SEC_VAR_FAST_BOOLEAN)
  #undef      OS_START_SEC_VAR_FAST_BOOLEAN
  #define DEFAULT_START_SEC_VAR_FAST_BOOLEAN
#elif defined (OS_STOP_SEC_VAR_FAST_BOOLEAN)
  #undef      OS_STOP_SEC_VAR_FAST_BOOLEAN
  #define DEFAULT_STOP_SEC_VAR_FAST_BOOLEAN

/* OS Initialized fast RAM: 8 bit values */
#elif defined (OS_START_SEC_VAR_FAST_8BIT)
  #undef      OS_START_SEC_VAR_FAST_8BIT
  #define DEFAULT_START_SEC_VAR_FAST_8BIT
#elif defined (OS_STOP_SEC_VAR_FAST_8BIT)
  #undef      OS_STOP_SEC_VAR_FAST_8BIT
  #define DEFAULT_STOP_SEC_VAR_FAST_8BIT

/* OS Initialized fast RAM: 16 bit values */
#elif defined (OS_START_SEC_VAR_FAST_16BIT)
  #undef      OS_START_SEC_VAR_FAST_16BIT
  #define DEFAULT_START_SEC_VAR_FAST_16BIT
#elif defined (OS_STOP_SEC_VAR_FAST_16BIT)
  #undef      OS_STOP_SEC_VAR_FAST_16BIT
  #define DEFAULT_STOP_SEC_VAR_FAST_16BIT

/* OS Initialized fast RAM: 32 bit values */
#elif defined (OS_START_SEC_VAR_FAST_32BIT)
  #undef      OS_START_SEC_VAR_FAST_32BIT
  #define DEFAULT_START_SEC_VAR_FAST_32BIT
#elif defined (OS_STOP_SEC_VAR_FAST_32BIT)
  #undef      OS_STOP_SEC_VAR_FAST_32BIT
  #define DEFAULT_STOP_SEC_VAR_FAST_32BIT

/* OS Initialized fast RAM: unspecified size */
#elif defined (OS_START_SEC_VAR_FAST_UNSPECIFIED)
  #undef      OS_START_SEC_VAR_FAST_UNSPECIFIED
  #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_FAST_UNSPECIFIED)
  #undef      OS_STOP_SEC_VAR_FAST_UNSPECIFIED
  #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED

/* OS Const (ROM): boolean */
#elif defined (OS_START_SEC_CONST_BOOLEAN)
  #undef      OS_START_SEC_CONST_BOOLEAN
  #define SHARED_START_SEC_CONST_BOOL
#elif defined (OS_STOP_SEC_CONST_BOOLEAN)
  #undef      OS_STOP_SEC_CONST_BOOLEAN
  #define SHARED_STOP_SEC_CONST_BOOL

/* OS Const (ROM): 8 bit values */
#elif defined (OS_START_SEC_CONST_8BIT)
  #undef      OS_START_SEC_CONST_8BIT
  #define SHARED_START_SEC_CONST_8
#elif defined (OS_STOP_SEC_CONST_8BIT)
  #undef      OS_STOP_SEC_CONST_8BIT
  #define SHARED_STOP_SEC_CONST_8

/* OS Const (ROM): 16 bit values */
#elif defined (OS_START_SEC_CONST_16BIT)
  #undef      OS_START_SEC_CONST_16BIT
  #define SHARED_START_SEC_CONST_16
#elif defined (OS_STOP_SEC_CONST_16BIT)
  #undef      OS_STOP_SEC_CONST_16BIT
  #define SHARED_STOP_SEC_CONST_16

/* OS Const (ROM): 32 bit values */
#elif defined (OS_START_SEC_CONST_32BIT)
  #undef      OS_START_SEC_CONST_32BIT
  #define SHARED_START_SEC_CONST_32
#elif defined (OS_STOP_SEC_CONST_32BIT)
  #undef      OS_STOP_SEC_CONST_32BIT
  #define SHARED_STOP_SEC_CONST_32

/* OS Const (ROM): unspecified size */
#elif defined (OS_START_SEC_CONST_UNSPECIFIED)
  #undef      OS_START_SEC_CONST_UNSPECIFIED
  #define SHARED_START_SEC_CONST_UNSPECIFIED
#elif defined (OS_STOP_SEC_CONST_UNSPECIFIED)
  #undef      OS_STOP_SEC_CONST_UNSPECIFIED
  #define SHARED_STOP_SEC_CONST_UNSPECIFIED

/* OS Code */
#elif defined (OS_START_SEC_CODE)
  #undef      OS_START_SEC_CODE
  #define SHARED_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE)
  #undef      OS_STOP_SEC_CODE
  #define SHARED_STOP_SEC_CODE

/* OS Fast Code */
#elif defined (OS_START_SEC_CODE_FAST)
  #undef      OS_START_SEC_CODE_FAST
  #define SHARED_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE_FAST)
  #undef      OS_STOP_SEC_CODE_FAST
  #define SHARED_STOP_SEC_CODE

/* OS Slow Code */
#elif defined (OS_START_SEC_CODE_SLOW)
  #undef      OS_START_SEC_CODE_SLOW
  #define SHARED_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE_SLOW)
  #undef      OS_STOP_SEC_CODE_SLOW
  #define SHARED_STOP_SEC_CODE

/* OS Library Code */
#elif defined (OS_START_SEC_CODE_LIB)
  #undef      OS_START_SEC_CODE_LIB
#elif defined (OS_STOP_SEC_CODE_LIB)
  #undef      OS_STOP_SEC_CODE_LIB

/* OS Interrupt vectors */
#elif defined (OS_START_SEC_VECTORS)
  #undef      OS_START_SEC_VECTORS
  #define DEFAULT_START_SEC_VECTORS
#elif defined (OS_STOP_SEC_VECTORS)
  #undef      OS_STOP_SEC_VECTORS
  #define DEFAULT_STOP_SEC_VECTORS

/* Application code. Tasks, ISRs and Trusted Functions. */
#elif defined (OS_START_SEC_APPL_CODE)
  #undef      OS_START_SEC_APPL_CODE
  #define SHARED_START_SEC_CODE
#elif defined (OS_STOP_SEC_APPL_CODE)
  #undef      OS_STOP_SEC_APPL_CODE
  #define SHARED_STOP_SEC_CODE

/* Application code. Callbacks/callouts from the OS. */
#elif defined (OS_START_SEC_CALLOUT_CODE)
  #undef      OS_START_SEC_CALLOUT_CODE
  #define SHARED_START_SEC_CODE
#elif defined (OS_STOP_SEC_CALLOUT_CODE)
  #undef      OS_STOP_SEC_CALLOUT_CODE
  #define SHARED_STOP_SEC_CODE
/* MPU Code */
#elif defined (OS_MEM_PRO_START_SEC_CODE)
  #undef      OS_MEM_PRO_START_SEC_CODE
  #define CPU0_START_SEC_CODE
#elif defined (OS_MEM_PRO_STOP_SEC_CODE)
  #undef      OS_MEM_PRO_STOP_SEC_CODE
  #define CPU0_STOP_SEC_CODE

#endif
