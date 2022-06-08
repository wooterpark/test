/*----------------------------------------------------------------------------*/
/************** *SAMPLE* of MemMap.h. Not for production purposes *************/
/*----------------------------------------------------------------------------*/
#define MEM_VENDOR_ID        (11U)
#define MEM_AR_MAJOR_VERSION (4U)
#define MEM_AR_MINOR_VERSION (0U)
#define MEM_AR_PATCH_VERSION (3U)
#define MEM_SW_MAJOR_VERSION (5U)
#define MEM_SW_MINOR_VERSION (4U)
#define MEM_SW_PATCH_VERSION (2U)

/* -------------------------------------------------------------------------- */
/*             OS (Operating System)                                          */
/* -------------------------------------------------------------------------- */
//#include <Os_MemMap.h>

/*******************************************************************************
**                      Default section mapping                               **
*******************************************************************************/
#if defined (START_WITH_IF)

/*******************************/
/************  CPU0   **********/
/*******************************/
/*Code sec trusted*/
#elif defined CPU0_START_SEC_CODE
    #undef CPU0_START_SEC_CODE
    #pragma section ".text.CPU0_Code" ax 4
#elif defined CPU0_STOP_SEC_CODE
    #undef CPU0_STOP_SEC_CODE
	#pragma section

/*Data sec uninitialized trusted*/
#elif defined CPU0_START_SEC_RAM_CLEARED_UNSPECIFIED
    #undef CPU0_START_SEC_RAM_CLEARED_UNSPECIFIED
    #pragma section ".bss.CPU0_unspec" awB 4
#elif defined CPU0_STOP_SEC_RAM_CLEARED_UNSPECIFIED
    #undef CPU0_STOP_SEC_RAM_CLEARED_UNSPECIFIED
	#pragma section
#elif defined CPU0_START_SEC_RAM_CLEARED_BOOL
    #undef  CPU0_START_SEC_RAM_CLEARED_BOOL
    #pragma section ".bss.CPU0_bool" awB 1
#elif defined CPU0_STOP_SEC_RAM_CLEARED_BOOL
    #undef CPU0_STOP_SEC_RAM_CLEARED_BOOL
	#pragma section
#elif defined CPU0_START_SEC_RAM_CLEARED_8
    #undef  CPU0_START_SEC_RAM_CLEARED_8
    #pragma section ".bss.CPU0_8" awB 1
#elif defined CPU0_STOP_SEC_RAM_CLEARED_8
    #undef CPU0_STOP_SEC_RAM_CLEARED_8
	#pragma section
#elif defined CPU0_START_SEC_RAM_CLEARED_16
    #undef  CPU0_START_SEC_RAM_CLEARED_16
    #pragma section ".bss.CPU0_16" awB 2
#elif defined CPU0_STOP_SEC_RAM_CLEARED_16
    #undef CPU0_STOP_SEC_RAM_CLEARED_16
	#pragma section
#elif defined CPU0_START_SEC_RAM_CLEARED_32
    #undef  CPU0_START_SEC_RAM_CLEARED_32
    #pragma section ".bss.CPU0_32" awB 4
#elif defined CPU0_STOP_SEC_RAM_CLEARED_32
    #undef CPU0_STOP_SEC_RAM_CLEARED_32
	#pragma section
/*Data sec initialized trusted*/
#elif defined CPU0_START_SEC_RAM_INIT_UNSPECIFIED
    #undef  CPU0_START_SEC_RAM_INIT_UNSPECIFIED
    #pragma section ".data.CPU0_unspec" aw 4
#elif defined CPU0_STOP_SEC_RAM_INIT_UNSPECIFIED
    #undef CPU0_STOP_SEC_RAM_INIT_UNSPECIFIED
	#pragma section
#elif defined CPU0_START_SEC_RAM_INIT_BOOL
    #undef  CPU0_START_SEC_RAM_INIT_BOOL
    #pragma section ".data.CPU0_bool" aw 1
#elif defined CPU0_STOP_SEC_RAM_INIT_BOOL
    #undef CPU0_STOP_SEC_RAM_INIT_BOOL
	#pragma section
#elif defined CPU0_START_SEC_RAM_INIT_8
    #undef  CPU0_START_SEC_RAM_INIT_8
    #pragma section ".data.CPU0_8" aw 1
#elif defined CPU0_STOP_SEC_RAM_INIT_8
    #undef CPU0_STOP_SEC_RAM_INIT_8
	#pragma section
#elif defined CPU0_START_SEC_RAM_INIT_16
    #undef  CPU0_START_SEC_RAM_INIT_16
    #pragma section ".data.CPU0_16" aw 2
#elif defined CPU0_STOP_SEC_RAM_INIT_16
    #undef CPU0_STOP_SEC_RAM_INIT_16
	#pragma section
#elif defined CPU0_START_SEC_RAM_INIT_32
    #undef  CPU0_START_SEC_RAM_INIT_32
    #pragma section ".data.CPU0_32" aw 4
#elif defined CPU0_STOP_SEC_RAM_INIT_32
    #undef CPU0_STOP_SEC_RAM_INIT_32
	#pragma section

/*Read-Only data sec trusted*/
#elif defined CPU0_START_SEC_CONST_UNSPECIFIED
    #undef  CPU0_START_SEC_CONST_UNSPECIFIED
    #pragma section ".rodata.CPU0_unspec" a 4
#elif defined CPU0_STOP_SEC_CONST_UNSPECIFIED
    #undef CPU0_STOP_SEC_CONST_UNSPECIFIED
	#pragma section
#elif defined CPU0_START_SEC_CONST_BOOL
    #undef  CPU0_START_SEC_CONST_BOOL
    #pragma section ".rodata.CPU0_bool" a 1
#elif defined CPU0_STOP_SEC_CONST_BOOL
    #undef CPU0_STOP_SEC_CONST_BOOL
	#pragma section
#elif defined CPU0_START_SEC_CONST_8
    #undef  CPU0_START_SEC_CONST_8
    #pragma section ".rodata.CPU0_8" a 1
#elif defined CPU0_STOP_SEC_CONST_8
    #undef CPU0_STOP_SEC_CONST_8
	#pragma section
#elif defined CPU0_START_SEC_CONST_16
    #undef  CPU0_START_SEC_CONST_16
    #pragma section ".rodata.CPU0_16" a 2
#elif defined CPU0_STOP_SEC_CONST_16
    #undef CPU0_STOP_SEC_CONST_16
	#pragma section
#elif defined CPU0_START_SEC_CONST_32
    #undef  CPU0_START_SEC_CONST_32
    #pragma section ".rodata.CPU0_32" a 4
#elif defined CPU0_STOP_SEC_CONST_32
    #undef CPU0_STOP_SEC_CONST_32
	#pragma section
	
/*Read-Only data sec Calibration for XCP*/
#elif defined CALIB_START_SEC_CONST_UNSPECIFIED
    #undef  CALIB_START_SEC_CONST_UNSPECIFIED
    #pragma section ".rodata.Calib_unspec" a 4
#elif defined CALIB_STOP_SEC_CONST_UNSPECIFIED
    #undef CALIB_STOP_SEC_CONST_UNSPECIFIED
	#pragma section
#elif defined CALIB_START_SEC_CONST_BOOL
    #undef  CALIB_START_SEC_CONST_BOOL
    #pragma section ".rodata.Calib_bool" a 1
#elif defined CALIB_STOP_SEC_CONST_BOOL
    #undef CALIB_STOP_SEC_CONST_BOOL
	#pragma section
#elif defined CALIB_START_SEC_CONST_8
    #undef  CALIB_START_SEC_CONST_8
    #pragma section ".rodata.Calib_8" a 1
#elif defined CALIB_STOP_SEC_CONST_8
    #undef CALIB_STOP_SEC_CONST_8
	#pragma section
#elif defined CALIB_START_SEC_CONST_16
    #undef  CALIB_START_SEC_CONST_16
    #pragma section ".rodata.Calib_16" a 2
#elif defined CALIB_STOP_SEC_CONST_16
    #undef CALIB_STOP_SEC_CONST_16
	#pragma section
#elif defined CALIB_START_SEC_CONST_32
    #undef  CALIB_START_SEC_CONST_32
    #pragma section ".rodata.Calib_32" a 4
#elif defined CALIB_STOP_SEC_CONST_32
    #undef CALIB_STOP_SEC_CONST_32
	#pragma section

/*******************************/
/******  CPU1 TRUSTED  *********/
/*******************************/
/*Code sec trusted*/
#elif defined CPU1_START_SEC_CODE
    #undef  CPU1_START_SEC_CODE
    #pragma section ".text.CPU1_Code" ax 4
#elif defined CPU1_STOP_SEC_CODE
    #undef CPU1_STOP_SEC_CODE
	#pragma section

/*Data sec uninitialized trusted*/
#elif defined CPU1_START_SEC_RAM_CLEARED_UNSPECIFIED
    #undef  CPU1_START_SEC_RAM_CLEARED_UNSPECIFIED
    #pragma section ".bss.CPU1_unspec" awB 4
#elif defined CPU1_STOP_SEC_RAM_CLEARED_UNSPECIFIED
    #undef CPU1_STOP_SEC_RAM_CLEARED_UNSPECIFIED
	#pragma section
#elif defined CPU1_START_SEC_RAM_CLEARED_BOOL
    #undef  CPU1_START_SEC_RAM_CLEARED_BOOL
    #pragma section ".bss.CPU1_bool" awB 1
#elif defined CPU1_STOP_SEC_RAM_CLEARED_BOOL
    #undef CPU1_STOP_SEC_RAM_CLEARED_BOOL
	#pragma section
#elif defined CPU1_START_SEC_RAM_CLEARED_8
    #undef  CPU1_START_SEC_RAM_CLEARED_8
    #pragma section ".bss.CPU1_8" awB 1
#elif defined CPU1_STOP_SEC_RAM_CLEARED_8
    #undef CPU1_STOP_SEC_RAM_CLEARED_8
	#pragma section
#elif defined CPU1_START_SEC_RAM_CLEARED_16
    #undef  CPU1_START_SEC_RAM_CLEARED_16
    #pragma section ".bss.CPU1_16" awB 2
#elif defined CPU1_STOP_SEC_RAM_CLEARED_16
    #undef CPU1_STOP_SEC_RAM_CLEARED_16
	#pragma section
#elif defined CPU1_START_SEC_RAM_CLEARED_32
    #undef  CPU1_START_SEC_RAM_CLEARED_32
    #pragma section ".bss.CPU1_32" awB 4
#elif defined CPU1_STOP_SEC_RAM_CLEARED_32
    #undef CPU1_STOP_SEC_RAM_CLEARED_32
	#pragma section
/*Data sec initialized trusted*/
#elif defined CPU1_START_SEC_RAM_INIT_UNSPECIFIED
    #undef  CPU1_START_SEC_RAM_INIT_UNSPECIFIED
    #pragma section ".data.CPU1_unspec" aw 4
#elif defined CPU1_STOP_SEC_RAM_INIT_UNSPECIFIED
    #undef CPU1_STOP_SEC_RAM_INIT_UNSPECIFIED
	#pragma section
#elif defined CPU1_START_SEC_RAM_INIT_BOOL
    #undef  CPU1_START_SEC_RAM_INIT_BOOL
    #pragma section ".data.CPU1_bool" aw 1
#elif defined CPU1_STOP_SEC_RAM_INIT_BOOL
    #undef CPU1_STOP_SEC_RAM_INIT_BOOL
	#pragma section
#elif defined CPU1_START_SEC_RAM_INIT_8
    #undef  CPU1_START_SEC_RAM_INIT_8
    #pragma section ".data.CPU1_8" aw 1
#elif defined CPU1_STOP_SEC_RAM_INIT_8
    #undef CPU1_STOP_SEC_RAM_INIT_8
	#pragma section
#elif defined CPU1_START_SEC_RAM_INIT_16
    #undef  CPU1_START_SEC_RAM_INIT_16
    #pragma section ".data.CPU1_16" aw 2
#elif defined CPU1_STOP_SEC_RAM_INIT_16
    #undef CPU1_STOP_SEC_RAM_INIT_16
	#pragma section
#elif defined CPU1_START_SEC_RAM_INIT_32
    #undef  CPU1_START_SEC_RAM_INIT_32
    #pragma section ".data.CPU1_32" aw 4
#elif defined CPU1_STOP_SEC_RAM_INIT_32
    #undef CPU1_STOP_SEC_RAM_INIT_32
	#pragma section

/*Read-Only data sec trusted*/
#elif defined CPU1_START_SEC_CONST_UNSPECIFIED
    #undef  CPU1_START_SEC_CONST_UNSPECIFIED
    #pragma section ".rodata.CPU1_unspec" a 4
#elif defined CPU1_STOP_SEC_CONST_UNSPECIFIED
    #undef CPU1_STOP_SEC_CONST_UNSPECIFIED
	#pragma section
#elif defined CPU1_START_SEC_CONST_BOOL
    #undef  CPU1_START_SEC_CONST_BOOL
    #pragma section ".rodata.CPU1_bool" a 1
#elif defined CPU1_STOP_SEC_CONST_BOOL
    #undef CPU1_STOP_SEC_CONST_BOOL
	#pragma section
#elif defined CPU1_START_SEC_CONST_8
    #undef  CPU1_START_SEC_CONST_8
    #pragma section ".rodata.CPU1_8" a 1
#elif defined CPU1_STOP_SEC_CONST_8
    #undef CPU1_STOP_SEC_CONST_8
	#pragma section
#elif defined CPU1_START_SEC_CONST_16
    #undef  CPU1_START_SEC_CONST_16
    #pragma section ".rodata.CPU1_16" a 2
#elif defined CPU1_STOP_SEC_CONST_16
    #undef CPU1_STOP_SEC_CONST_16
	#pragma section
#elif defined CPU1_START_SEC_CONST_32
    #undef  CPU1_START_SEC_CONST_32
    #pragma section ".rodata.CPU1_32" a 4
#elif defined CPU1_STOP_SEC_CONST_32
    #undef CPU1_STOP_SEC_CONST_32
	#pragma section

/**************************************/
/******  SHARED TRUSTED CODE  *********/
/**************************************/
#elif defined SHARED_TRUSTED_START_SEC_CODE
    #undef SHARED_TRUSTED_START_SEC_CODE
	#pragma section ".text.SharedTrusted_Code" ax 4
#elif defined SHARED_TRUSTED_STOP_SEC_CODE
    #undef SHARED_TRUSTED_STOP_SEC_CODE
	#pragma section

/*********************************/
/******  SHARED CODE  ************/
/*********************************/
/*(used by both trusted & un-trusted)*/
#elif defined SHARED_START_SEC_CODE
    #undef SHARED_START_SEC_CODE
	#pragma section ".text.Shared_Code" ax 4
#elif defined SHARED_STOP_SEC_CODE
    #undef SHARED_STOP_SEC_CODE
	#pragma section

/**********************************/
/******  DEFAULT CODE  ************/
/**********************************/
#elif defined DEFAULT_START_SEC_CODE
    #undef DEFAULT_START_SEC_CODE
	#pragma section ".text.defaultcode" ax 4
#elif defined DEFAULT_STOP_SEC_CODE
    #undef DEFAULT_STOP_SEC_CODE
	#pragma section

/**************************************/
/******  SHARED TRUSTED DATA  *********/
/**************************************/
/*Shared trusted data sec initialized*/
#elif defined SHARED_TRUSTED_START_SEC_RAM_INIT_UNSPECIFIED
    #undef  SHARED_TRUSTED_START_SEC_RAM_INIT_UNSPECIFIED
    #pragma section ".data.SharedTrusted_unspec" aw 4
#elif defined SHARED_TRUSTED_STOP_SEC_RAM_INIT_UNSPECIFIED
    #undef SHARED_TRUSTED_STOP_SEC_RAM_INIT_UNSPECIFIED
	#pragma section
#elif defined SHARED_TRUSTED_START_SEC_RAM_INIT_BOOL
    #undef  SHARED_TRUSTED_START_SEC_RAM_INIT_BOOL
    #pragma section ".data.SharedTrusted_bool" aw 1
#elif defined SHARED_TRUSTED_STOP_SEC_RAM_INIT_BOOL
    #undef SHARED_TRUSTED_STOP_SEC_RAM_INIT_BOOL
	#pragma section
#elif defined SHARED_TRUSTED_START_SEC_RAM_INIT_8
    #undef  SHARED_TRUSTED_START_SEC_RAM_INIT_8
    #pragma section ".data.SharedTrusted_8" aw 1
#elif defined SHARED_TRUSTED_STOP_SEC_RAM_INIT_8
    #undef SHARED_TRUSTED_STOP_SEC_RAM_INIT_8
	#pragma section
#elif defined SHARED_TRUSTED_START_SEC_RAM_INIT_16
    #undef  SHARED_TRUSTED_START_SEC_RAM_INIT_16
    #pragma section ".data.SharedTrusted_16" aw 2
#elif defined SHARED_TRUSTED_STOP_SEC_RAM_INIT_16
    #undef SHARED_TRUSTED_STOP_SEC_RAM_INIT_16
	#pragma section
#elif defined SHARED_TRUSTED_START_SEC_RAM_INIT_32
    #undef  SHARED_TRUSTED_START_SEC_RAM_INIT_32
    #pragma section ".data.SharedTrusted_32" aw 4
#elif defined SHARED_TRUSTED_STOP_SEC_RAM_INIT_32
    #undef SHARED_TRUSTED_STOP_SEC_RAM_INIT_32
	#pragma section

/*Shared trusted data sec uninitialized*/
#elif defined SHARED_TRUSTED_START_SEC_RAM_CLEARED_UNSPECIFIED
    #undef  SHARED_TRUSTED_START_SEC_RAM_CLEARED_UNSPECIFIED
    #pragma section ".bss.SharedTrusted_unspec" awB 4
#elif defined SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_UNSPECIFIED
    #undef SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_UNSPECIFIED
	#pragma section
#elif defined SHARED_TRUSTED_START_SEC_RAM_CLEARED_BOOL
    #undef  SHARED_TRUSTED_START_SEC_RAM_CLEARED_BOOL
    #pragma section ".bss.SharedTrusted_bool" awB 1
#elif defined SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_BOOL
    #undef SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_BOOL
	#pragma section
#elif defined SHARED_TRUSTED_START_SEC_RAM_CLEARED_8
    #undef  SHARED_TRUSTED_START_SEC_RAM_CLEARED_8
    #pragma section ".bss.SharedTrusted_8" awB 1
#elif defined SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_8
    #undef SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_8
	#pragma section
#elif defined SHARED_TRUSTED_START_SEC_RAM_CLEARED_16
    #undef  SHARED_TRUSTED_START_SEC_RAM_CLEARED_16
    #pragma section ".bss.SharedTrusted_16" awB 2
#elif defined SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_16
    #undef SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_16
	#pragma section
#elif defined SHARED_TRUSTED_START_SEC_RAM_CLEARED_32
    #undef  SHARED_TRUSTED_START_SEC_RAM_CLEARED_32
    #pragma section ".bss.SharedTrusted_32" awB 4
#elif defined SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_32
    #undef SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_32
	#pragma section

/*Shared trusted readonly data sec*/
#elif defined SHARED_TRUSTED_START_SEC_CONST_UNSPECIFIED
    #undef  SHARED_TRUSTED_START_SEC_CONST_UNSPECIFIED
    #pragma section ".rodata.SharedTrusted_unspec" a 4
#elif defined SHARED_TRUSTED_STOP_SEC_CONST_UNSPECIFIED
    #undef SHARED_TRUSTED_STOP_SEC_CONST_UNSPECIFIED
	#pragma section
#elif defined SHARED_TRUSTED_START_SEC_CONST_BOOL
    #undef  SHARED_TRUSTED_START_SEC_CONST_BOOL
    #pragma section ".rodata.SharedTrusted_bool" a 1
#elif defined SHARED_TRUSTED_STOP_SEC_CONST_BOOL
    #undef SHARED_TRUSTED_STOP_SEC_CONST_BOOL
	#pragma section
#elif defined SHARED_TRUSTED_START_SEC_CONST_8
    #undef  SHARED_TRUSTED_START_SEC_CONST_8
    #pragma section ".rodata.SharedTrusted_8" a 1
#elif defined SHARED_TRUSTED_STOP_SEC_CONST_8
    #undef SHARED_TRUSTED_STOP_SEC_CONST_8
	#pragma section
#elif defined SHARED_TRUSTED_START_SEC_CONST_16
    #undef  SHARED_TRUSTED_START_SEC_CONST_16
    #pragma section ".rodata.SharedTrusted_16" a 2
#elif defined SHARED_TRUSTED_STOP_SEC_CONST_16
    #undef SHARED_TRUSTED_STOP_SEC_CONST_16
	#pragma section
#elif defined SHARED_TRUSTED_START_SEC_CONST_32
    #undef  SHARED_TRUSTED_START_SEC_CONST_32
    #pragma section ".rodata.SharedTrusted_32" a 4
#elif defined SHARED_TRUSTED_STOP_SEC_CONST_32
    #undef SHARED_TRUSTED_STOP_SEC_CONST_32
	#pragma section

/**************************************/
/******  SHARED DATA  *********/
/**************************************/
/*Shared data sec initialized*/
#elif defined SHARED_START_SEC_RAM_INIT_UNSPECIFIED
    #undef  SHARED_START_SEC_RAM_INIT_UNSPECIFIED
    #pragma section ".data.Shared_unspec" aw 4
#elif defined SHARED_STOP_SEC_RAM_INIT_UNSPECIFIED
    #undef SHARED_STOP_SEC_RAM_INIT_UNSPECIFIED
	#pragma section
#elif defined SHARED_START_SEC_RAM_INIT_BOOL
    #undef  SHARED_START_SEC_RAM_INIT_BOOL
    #pragma section ".data.Shared_bool" aw 1
#elif defined SHARED_STOP_SEC_RAM_INIT_BOOL
    #undef SHARED_STOP_SEC_RAM_INIT_BOOL
	#pragma section
#elif defined SHARED_START_SEC_RAM_INIT_8
    #undef  SHARED_START_SEC_RAM_INIT_8
    #pragma section ".data.Shared_8" aw 1
#elif defined SHARED_STOP_SEC_RAM_INIT_8
    #undef SHARED_STOP_SEC_RAM_INIT_8
	#pragma section
#elif defined SHARED_START_SEC_RAM_INIT_16
    #undef  SHARED_START_SEC_RAM_INIT_16
    #pragma section ".data.Shared_16" aw 2
#elif defined SHARED_STOP_SEC_RAM_INIT_16
    #undef SHARED_STOP_SEC_RAM_INIT_16
	#pragma section
#elif defined SHARED_START_SEC_RAM_INIT_32
    #undef  SHARED_START_SEC_RAM_INIT_32
    #pragma section ".data.Shared_32" aw 4
#elif defined SHARED_STOP_SEC_RAM_INIT_32
    #undef SHARED_STOP_SEC_RAM_INIT_32
	#pragma section

/*Shared data sec uninitialized*/
#elif defined SHARED_START_SEC_RAM_CLEARED_UNSPECIFIED
    #undef  SHARED_START_SEC_RAM_CLEARED_UNSPECIFIED
    #pragma section ".bss.Shared_unspec" awB 4
#elif defined SHARED_STOP_SEC_RAM_CLEARED_UNSPECIFIED
    #undef SHARED_STOP_SEC_RAM_CLEARED_UNSPECIFIED
	#pragma section
#elif defined SHARED_START_SEC_RAM_CLEARED_BOOL
    #undef  SHARED_START_SEC_RAM_CLEARED_BOOL
    #pragma section ".bss.Shared_bool" awB 1
#elif defined SHARED_STOP_SEC_RAM_CLEARED_BOOL
    #undef SHARED_STOP_SEC_RAM_CLEARED_BOOL
	#pragma section
#elif defined SHARED_START_SEC_RAM_CLEARED_8
    #undef  SHARED_START_SEC_RAM_CLEARED_8
    #pragma section ".bss.Shared_8" awB 1
#elif defined SHARED_STOP_SEC_RAM_CLEARED_8
    #undef SHARED_STOP_SEC_RAM_CLEARED_8
	#pragma section
#elif defined SHARED_START_SEC_RAM_CLEARED_16
    #undef  SHARED_START_SEC_RAM_CLEARED_16
    #pragma section ".bss.Shared_16" awB 2
#elif defined SHARED_STOP_SEC_RAM_CLEARED_16
    #undef SHARED_STOP_SEC_RAM_CLEARED_16
	#pragma section
#elif defined SHARED_START_SEC_RAM_CLEARED_32
    #undef  SHARED_START_SEC_RAM_CLEARED_32
    #pragma section ".bss.Shared_32" awB 4
#elif defined SHARED_STOP_SEC_RAM_CLEARED_32
    #undef SHARED_STOP_SEC_RAM_CLEARED_32
	#pragma section

/*Shared data sec initialized; readonly for un-trusted*/
#elif defined SHARED_RO_START_SEC_RAM_INIT_UNSPECIFIED
    #undef  SHARED_RO_START_SEC_RAM_INIT_UNSPECIFIED
    #pragma section ".data.Shared_RO_unspec" aw 4
#elif defined SHARED_RO_STOP_SEC_RAM_INIT_UNSPECIFIED
    #undef SHARED_RO_STOP_SEC_RAM_INIT_UNSPECIFIED
	#pragma section
#elif defined SHARED_RO_START_SEC_RAM_INIT_BOOL
    #undef  SHARED_RO_START_SEC_RAM_INIT_BOOL
    #pragma section ".data.Shared_RO_bool" aw 1
#elif defined SHARED_RO_STOP_SEC_RAM_INIT_BOOL
    #undef SHARED_RO_STOP_SEC_RAM_INIT_BOOL
	#pragma section
#elif defined SHARED_RO_START_SEC_RAM_INIT_8
    #undef  SHARED_RO_START_SEC_RAM_INIT_8
    #pragma section ".data.Shared_RO_8" aw 1
#elif defined SHARED_RO_STOP_SEC_RAM_INIT_8
    #undef SHARED_RO_STOP_SEC_RAM_INIT_8
	#pragma section
#elif defined SHARED_RO_START_SEC_RAM_INIT_16
    #undef  SHARED_RO_START_SEC_RAM_INIT_16
    #pragma section ".data.Shared_RO_16" aw 2
#elif defined SHARED_RO_STOP_SEC_RAM_INIT_16
    #undef SHARED_RO_STOP_SEC_RAM_INIT_16
	#pragma section
#elif defined SHARED_RO_START_SEC_RAM_INIT_32
    #undef  SHARED_RO_START_SEC_RAM_INIT_32
    #pragma section ".data.Shared_RO_32" aw 4
#elif defined SHARED_RO_STOP_SEC_RAM_INIT_32
    #undef SHARED_RO_STOP_SEC_RAM_INIT_32
	#pragma section

/*Shared data sec uninitialized; readonly for un-trusted*/
#elif defined SHARED_RO_START_SEC_RAM_CLEARED_UNSPECIFIED
    #undef  SHARED_RO_START_SEC_RAM_CLEARED_UNSPECIFIED
    #pragma section ".bss.Shared_RO_unspec" awB 4
#elif defined SHARED_RO_STOP_SEC_RAM_CLEARED_UNSPECIFIED
    #undef SHARED_RO_STOP_SEC_RAM_CLEARED_UNSPECIFIED
	#pragma section
#elif defined SHARED_RO_START_SEC_RAM_CLEARED_BOOL
    #undef  SHARED_RO_START_SEC_RAM_CLEARED_BOOL
    #pragma section ".bss.Shared_RO_bool" awB 1
#elif defined SHARED_RO_STOP_SEC_RAM_CLEARED_BOOL
    #undef SHARED_RO_STOP_SEC_RAM_CLEARED_BOOL
	#pragma section
#elif defined SHARED_RO_START_SEC_RAM_CLEARED_8
    #undef  SHARED_RO_START_SEC_RAM_CLEARED_8
    #pragma section ".bss.Shared_RO_8" awB 1
#elif defined SHARED_RO_STOP_SEC_RAM_CLEARED_8
    #undef SHARED_RO_STOP_SEC_RAM_CLEARED_8
	#pragma section
#elif defined SHARED_RO_START_SEC_RAM_CLEARED_16
    #undef  SHARED_RO_START_SEC_RAM_CLEARED_16
    #pragma section ".bss.Shared_RO_16" awB 2
#elif defined SHARED_RO_STOP_SEC_RAM_CLEARED_16
    #undef SHARED_RO_STOP_SEC_RAM_CLEARED_16
	#pragma section
#elif defined SHARED_RO_START_SEC_RAM_CLEARED_32
    #undef  SHARED_RO_START_SEC_RAM_CLEARED_32
    #pragma section ".bss.Shared_RO_32" awB 4
#elif defined SHARED_RO_STOP_SEC_RAM_CLEARED_32
    #undef SHARED_RO_STOP_SEC_RAM_CLEARED_32
	#pragma section

/*Shared readonly data sec*/
#elif defined SHARED_START_SEC_CONST_UNSPECIFIED
    #undef  SHARED_START_SEC_CONST_UNSPECIFIED
    #pragma section ".rodata.Shared_unspec" a 4
#elif defined SHARED_STOP_SEC_CONST_UNSPECIFIED
    #undef SHARED_STOP_SEC_CONST_UNSPECIFIED
	#pragma section
#elif defined SHARED_START_SEC_CONST_BOOL
    #undef  SHARED_START_SEC_CONST_BOOL
    #pragma section ".rodata.Shared_bool" a 1
#elif defined SHARED_STOP_SEC_CONST_BOOL
    #undef SHARED_STOP_SEC_CONST_BOOL
	#pragma section
#elif defined SHARED_START_SEC_CONST_8
    #undef  SHARED_START_SEC_CONST_8
    #pragma section ".rodata.Shared_8" a 1
#elif defined SHARED_STOP_SEC_CONST_8
    #undef SHARED_STOP_SEC_CONST_8
	#pragma section
#elif defined SHARED_START_SEC_CONST_16
    #undef  SHARED_START_SEC_CONST_16
    #pragma section ".rodata.Shared_16" a 2
#elif defined SHARED_STOP_SEC_CONST_16
    #undef SHARED_STOP_SEC_CONST_16
	#pragma section
#elif defined SHARED_START_SEC_CONST_32
    #undef  SHARED_START_SEC_CONST_32
    #pragma section ".rodata.Shared_32" a 4
#elif defined SHARED_STOP_SEC_CONST_32
    #undef SHARED_STOP_SEC_CONST_32
	#pragma section
/**********************************/
/******  DEFAULT DATA  ************/
/**********************************/
/*Default data sec initialized*/
#elif defined DEFAULT_START_SEC_RAM_INIT_UNSPECIFIED
    #undef  DEFAULT_START_SEC_RAM_INIT_UNSPECIFIED
    #pragma section ".data.default_unspec" aw 4
#elif defined DEFAULT_STOP_SEC_RAM_INIT_UNSPECIFIED
    #undef DEFAULT_STOP_SEC_RAM_INIT_UNSPECIFIED
	#pragma section
#elif defined DEFAULT_START_SEC_RAM_INIT_BOOL
    #undef  DEFAULT_START_SEC_RAM_INIT_BOOL
    #pragma section ".data.default_bool" aw 1
#elif defined DEFAULT_STOP_SEC_RAM_INIT_BOOL
    #undef DEFAULT_STOP_SEC_RAM_INIT_BOOL
	#pragma section
#elif defined DEFAULT_START_SEC_RAM_INIT_8
    #undef  DEFAULT_START_SEC_RAM_INIT_8
    #pragma section ".data.default_8" aw 1
#elif defined DEFAULT_STOP_SEC_RAM_INIT_8
    #undef DEFAULT_STOP_SEC_RAM_INIT_8
	#pragma section
#elif defined DEFAULT_START_SEC_RAM_INIT_16
    #undef  DEFAULT_START_SEC_RAM_INIT_16
    #pragma section ".data.default_16" aw 2
#elif defined DEFAULT_STOP_SEC_RAM_INIT_16
    #undef DEFAULT_STOP_SEC_RAM_INIT_16
	#pragma section
#elif defined DEFAULT_START_SEC_RAM_INIT_32
    #undef  DEFAULT_START_SEC_RAM_INIT_32
    #pragma section ".data.default_32" aw 4
#elif defined DEFAULT_STOP_SEC_RAM_INIT_32
    #undef DEFAULT_STOP_SEC_RAM_INIT_32
	#pragma section

/*Default data sec uninitialized*/
#elif defined DEFAULT_START_SEC_RAM_CLEARED_UNSPECIFIED
    #undef  DEFAULT_START_SEC_RAM_CLEARED_UNSPECIFIED
    #pragma section ".bss.default_unspec" awB 4
#elif defined DEFAULT_STOP_SEC_RAM_CLEARED_UNSPECIFIED
    #undef DEFAULT_STOP_SEC_RAM_CLEARED_UNSPECIFIED
	#pragma section
#elif defined DEFAULT_START_SEC_RAM_CLEARED_BOOL
    #undef  DEFAULT_START_SEC_RAM_CLEARED_BOOL
    #pragma section ".bss.default_bool" awB 1
#elif defined DEFAULT_STOP_SEC_RAM_CLEARED_BOOL
    #undef DEFAULT_STOP_SEC_RAM_CLEARED_BOOL
	#pragma section
#elif defined DEFAULT_START_SEC_RAM_CLEARED_8
    #undef  DEFAULT_START_SEC_RAM_CLEARED_8
    #pragma section ".bss.default_8" awB 1
#elif defined DEFAULT_STOP_SEC_RAM_CLEARED_8
    #undef DEFAULT_STOP_SEC_RAM_CLEARED_8
	#pragma section
#elif defined DEFAULT_START_SEC_RAM_CLEARED_16
    #undef  DEFAULT_START_SEC_RAM_CLEARED_16
    #pragma section ".bss.default_16" awB 2
#elif defined DEFAULT_STOP_SEC_RAM_CLEARED_16
    #undef DEFAULT_STOP_SEC_RAM_CLEARED_16
	#pragma section
#elif defined DEFAULT_START_SEC_RAM_CLEARED_32
    #undef  DEFAULT_START_SEC_RAM_CLEARED_32
    #pragma section ".bss.default_32" awB 4
#elif defined DEFAULT_STOP_SEC_RAM_CLEARED_32
    #undef DEFAULT_STOP_SEC_RAM_CLEARED_32
	#pragma section

/*Default readonly data sec*/
#elif defined DEFAULT_START_SEC_CONST_UNSPECIFIED
    #undef  DEFAULT_START_SEC_CONST_UNSPECIFIED
    #pragma section ".rodata.default_unspec" a 4
#elif defined DEFAULT_STOP_SEC_CONST_UNSPECIFIED
    #undef DEFAULT_STOP_SEC_CONST_UNSPECIFIED
	#pragma section
#elif defined DEFAULT_START_SEC_CONST_BOOL
    #undef  DEFAULT_START_SEC_CONST_BOOL
    #pragma section ".rodata.default_bool" a 1
#elif defined DEFAULT_STOP_SEC_CONST_BOOL
    #undef DEFAULT_STOP_SEC_CONST_BOOL
	#pragma section
#elif defined DEFAULT_START_SEC_CONST_8
    #undef  DEFAULT_START_SEC_CONST_8
    #pragma section ".rodata.default_8" a 1
#elif defined DEFAULT_STOP_SEC_CONST_8
    #undef DEFAULT_STOP_SEC_CONST_8
	#pragma section
#elif defined DEFAULT_START_SEC_CONST_16
    #undef  DEFAULT_START_SEC_CONST_16
    #pragma section ".rodata.default_16" a 2
#elif defined DEFAULT_STOP_SEC_CONST_16
    #undef DEFAULT_STOP_SEC_CONST_16
	#pragma section
#elif defined DEFAULT_START_SEC_CONST_32
    #undef  DEFAULT_START_SEC_CONST_32
    #pragma section ".rodata.default_32" a 4
#elif defined DEFAULT_STOP_SEC_CONST_32
    #undef DEFAULT_STOP_SEC_CONST_32
	#pragma section

/* -------------------------------------------------------------------------- */
/* RAM variables not initialized                                              */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_NOINIT_BOOLEAN)
  #undef      DEFAULT_START_SEC_VAR_NOINIT_BOOLEAN
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_BOOLEAN)
  #undef      DEFAULT_STOP_SEC_VAR_NOINIT_BOOLEAN

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT)
  #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT)
  #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT)
  #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT)
  #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT)
  #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT)
  #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED

/* -------------------------------------------------------------------------- */
/* RAM variables power-on initialized                                         */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN

#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT)
  #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
  #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT

#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT)
  #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
  #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT

#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT)
  #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
  #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT

#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED

/* -------------------------------------------------------------------------- */
/* RAM variables initialized from ROM on reset                                */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_BOOLEAN)
  #undef      DEFAULT_START_SEC_VAR_BOOLEAN
#elif defined (DEFAULT_STOP_SEC_VAR_BOOLEAN)
  #undef      DEFAULT_STOP_SEC_VAR_BOOLEAN

#elif defined (DEFAULT_START_SEC_VAR_8BIT)
  #undef      DEFAULT_START_SEC_VAR_8BIT
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT)
  #undef      DEFAULT_STOP_SEC_VAR_8BIT

#elif defined (DEFAULT_START_SEC_VAR_16BIT)
  #undef      DEFAULT_START_SEC_VAR_16BIT
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT)
  #undef      DEFAULT_STOP_SEC_VAR_16BIT

#elif defined (DEFAULT_START_SEC_VAR_32BIT)
  #undef      DEFAULT_START_SEC_VAR_32BIT
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT)
  #undef      DEFAULT_STOP_SEC_VAR_32BIT

#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/* -------------------------------------------------------------------------- */
/* RAM variables frequently used or accessed bitwise                          */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_FAST_BOOLEAN)
  #undef      DEFAULT_START_SEC_VAR_FAST_BOOLEAN
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_BOOLEAN)
  #undef      DEFAULT_STOP_SEC_VAR_FAST_BOOLEAN

#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT)
  #undef      DEFAULT_START_SEC_VAR_FAST_8BIT
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT)
  #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT

#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT)
  #undef      DEFAULT_START_SEC_VAR_FAST_16BIT
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT)
  #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT

#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT)
  #undef      DEFAULT_START_SEC_VAR_FAST_32BIT
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT)
  #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT

#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED

/* -------------------------------------------------------------------------- */
/* ROM constants                                                              */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_CONST_BOOLEAN)
  #undef      DEFAULT_START_SEC_CONST_BOOLEAN
#elif defined (DEFAULT_STOP_SEC_CONST_BOOLEAN)
  #undef      DEFAULT_STOP_SEC_CONST_BOOLEAN

#elif defined (DEFAULT_START_SEC_CONST_8BIT)
  #undef      DEFAULT_START_SEC_CONST_8BIT
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT)
  #undef      DEFAULT_STOP_SEC_CONST_8BIT

#elif defined (DEFAULT_START_SEC_CONST_16BIT)
  #undef      DEFAULT_START_SEC_CONST_16BIT
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT)
  #undef      DEFAULT_STOP_SEC_CONST_16BIT

#elif defined (DEFAULT_START_SEC_CONST_32BIT)
  #undef      DEFAULT_START_SEC_CONST_32BIT
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT)
  #undef      DEFAULT_STOP_SEC_CONST_32BIT

#elif defined (DEFAULT_START_SEC_CONST_FAST_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_CONST_FAST_UNSPECIFIED
#elif defined (DEFAULT_STOP_SEC_CONST_FAST_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_CONST_FAST_UNSPECIFIED


/* -------------------------------------------------------------------------- */
/* ROM FAR constants                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_CONST_BOOLEAN_FAR)
  #undef      DEFAULT_START_SEC_CONST_BOOLEAN_FAR
#elif defined (DEFAULT_STOP_SEC_CONST_BOOLEAN_FAR)
  #undef      DEFAULT_STOP_SEC_CONST_BOOLEAN_FAR

#elif defined (DEFAULT_START_SEC_CONST_8BIT_FAR)
  #undef      DEFAULT_START_SEC_CONST_8BIT_FAR
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_FAR)
  #undef      DEFAULT_STOP_SEC_CONST_8BIT_FAR

#elif defined (DEFAULT_START_SEC_CONST_16BIT_FAR)
  #undef      DEFAULT_START_SEC_CONST_16BIT_FAR
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_FAR)
  #undef      DEFAULT_STOP_SEC_CONST_16BIT_FAR

#elif defined (DEFAULT_START_SEC_CONST_32BIT_FAR)
  #undef      DEFAULT_START_SEC_CONST_32BIT_FAR
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_FAR)
  #undef      DEFAULT_STOP_SEC_CONST_32BIT_FAR

#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_FAR)
  #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_FAR
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_FAR)
  #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_FAR

/* -------------------------------------------------------------------------- */
/* ROM code                                                                   */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_CODE_FAST)
  #undef      DEFAULT_START_SEC_CODE_FAST
#elif defined (DEFAULT_STOP_SEC_CODE_FAST)
  #undef      DEFAULT_STOP_SEC_CODE_FAST

#elif defined (DEFAULT_START_SEC_CODE_SLOW)
  #undef      DEFAULT_START_SEC_CODE_SLOW
#elif defined (DEFAULT_STOP_SEC_CODE_SLOW)
  #undef      DEFAULT_STOP_SEC_CODE_SLOW

#elif defined (DEFAULT_START_SEC_CODE_LIB)
  #undef      DEFAULT_START_SEC_CODE_LIB
#elif defined (DEFAULT_STOP_SEC_CODE_LIB)
  #undef      DEFAULT_STOP_SEC_CODE_LIB

#elif defined (DEFAULT_START_SEC_VECTORS)
  #undef      DEFAULT_START_SEC_VECTORS
#elif defined (DEFAULT_STOP_SEC_VECTORS)
  #undef      DEFAULT_STOP_SEC_VECTORS

#elif defined (BMD_HDR_START_SEC_CONST_UNSPECIFIED)
   #undef      BMD_HDR_START_SEC_CONST_UNSPECIFIED
   #pragma section ".rodata.BMD_HDR_CONST_FAR_UNSPECIFIED"
   #define BMD_HDR_START_SEC_BMI_HEADER
#elif defined (BMD_HDR_STOP_SEC_CONST_UNSPECIFIED)
   #undef      BMD_HDR_STOP_SEC_CONST_UNSPECIFIED
   #pragma section
   #define   BMD_HDR_STOP_SEC_BMI_HEADER

/*************************************************/
/***************** FLASH DRIVER SEC***************/
/*************************************************/
/*Data sec; allocated on trusted partition core 0*/
#elif defined FLS_17_PMU_START_SEC_VAR_UNSPECIFIED
	#undef FLS_17_PMU_START_SEC_VAR_UNSPECIFIED
	#pragma section ".bss.CPU0_unspec" awB 4
#elif defined FLS_17_PMU_STOP_SEC_VAR_UNSPECIFIED
	#undef FLS_17_PMU_STOP_SEC_VAR_UNSPECIFIED
	#pragma section
#elif defined FLS_17_PMU_START_SEC_VAR_32BIT
	#undef FLS_17_PMU_START_SEC_VAR_32BIT
	#pragma section ".bss.CPU0_32" awB 4
#elif defined FLS_17_PMU_STOP_SEC_VAR_32BIT
	#undef FLS_17_PMU_STOP_SEC_VAR_32BIT
	#pragma section
#elif defined FLS_17_PMU_START_SEC_POSTBUILDCFG
	#undef FLS_17_PMU_START_SEC_POSTBUILDCFG
	#pragma section ".rodata.CPU0_unspec" a 4
#elif defined FLS_17_PMU_STOP_SEC_POSTBUILDCFG
	#undef FLS_17_PMU_STOP_SEC_POSTBUILDCFG
	#pragma section
#elif defined FLS_17_PMU_START_SEC_CONST_32BIT
	#undef FLS_17_PMU_START_SEC_CONST_32BIT
	#pragma section ".rodata.CPU0_32" a 4
#elif defined FLS_17_PMU_STOP_SEC_CONST_32BIT
	#undef FLS_17_PMU_STOP_SEC_CONST_32BIT
	#pragma section
/*Code sec; allocated on trusted partition core 0*/
#elif defined FLS_17_PMU_START_SEC_CODE
	#undef FLS_17_PMU_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined FLS_17_PMU_STOP_SEC_CODE
	#undef FLS_17_PMU_STOP_SEC_CODE
	#pragma section


/* ---The following sections attempt to locate FLS Write and Erase command-----
   ---Cycles in an order. It is essential to enforce the correct sequence------
   ---so that the FLS driver can perform as requird.-------------------------*/
#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN)
   #undef     FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN
   #pragma section ".text.FLS_AC_WRITE_SOURCE" ax 4

#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN)
   #undef     FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN
   #pragma section

#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN)
   #undef     FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN
   #pragma section ".text.FLS_AC_ERASE_SOURCE" ax 4

#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN)
   #undef     FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN
   #pragma section

/*************************************************/
/***************** CAN DRIVER SEC*****************/
/*************************************************/
/*Data sec; allocated on trusted partition core 0*/
#elif defined CAN_17_MCANP_START_SEC_VAR_8BIT
	#undef CAN_17_MCANP_START_SEC_VAR_8BIT
	#pragma section ".bss.CPU0_8" awB 1
#elif defined CAN_17_MCANP_STOP_SEC_VAR_8BIT
	#undef CAN_17_MCANP_STOP_SEC_VAR_8BIT
	#pragma section
#elif defined CAN_17_MCANP_START_SEC_VAR_16BIT
	#undef CAN_17_MCANP_START_SEC_VAR_16BIT
	#pragma section ".bss.CPU0_16" awB 2
#elif defined CAN_17_MCANP_STOP_SEC_VAR_16BIT
	#undef CAN_17_MCANP_STOP_SEC_VAR_16BIT
	#pragma section
#elif defined CAN_17_MCANP_START_SEC_VAR_32BIT
	#undef CAN_17_MCANP_START_SEC_VAR_32BIT
	#pragma section ".bss.CPU0_32" awB 4
#elif defined CAN_17_MCANP_STOP_SEC_VAR_32BIT
	#undef CAN_17_MCANP_STOP_SEC_VAR_32BIT
	#pragma section
#elif defined CAN_17_MCANP_START_SEC_CONST_8BIT
	#undef CAN_17_MCANP_START_SEC_CONST_8BIT
	#pragma section ".rodata.CPU0_8" a 1
#elif defined CAN_17_MCANP_STOP_SEC_CONST_8BIT
	#undef CAN_17_MCANP_STOP_SEC_CONST_8BIT
	#pragma section
#elif defined CAN_17_MCANP_START_SEC_CONST_32BIT
	#undef CAN_17_MCANP_START_SEC_CONST_32BIT
	#pragma section ".rodata.CPU0_32" a 4
#elif defined CAN_17_MCANP_STOP_SEC_CONST_32BIT
	#undef CAN_17_MCANP_STOP_SEC_CONST_32BIT
	#pragma section
#elif defined CAN_17_MCANP_START_SEC_POSTBUILDCFG
	#undef CAN_17_MCANP_START_SEC_POSTBUILDCFG
	#pragma section ".rodata.CPU0_unspec" a 4
#elif defined CAN_17_MCANP_STOP_SEC_POSTBUILDCFG
	#undef CAN_17_MCANP_STOP_SEC_POSTBUILDCFG
	#pragma section
/*Code sec; allocated on trusted partition core 0*/
#elif defined CAN_17_MCANP_START_SEC_CODE
	#undef CAN_17_MCANP_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined CAN_17_MCANP_STOP_SEC_CODE
	#undef CAN_17_MCANP_STOP_SEC_CODE
	#pragma section

/*************************************************/
/***************** DIO DRIVER SEC*****************/
/*************************************************/
/*Data sec; allocated on trusted partition core 1*/
#elif defined DIO_START_SEC_VAR_8BIT
	#undef DIO_START_SEC_VAR_8BIT
	#pragma section ".bss.CPU0_8" awB 1
#elif defined DIO_STOP_SEC_VAR_8BIT
	#undef DIO_STOP_SEC_VAR_8BIT
	#pragma section
#elif defined DIO_START_SEC_VAR_32BIT
	#undef DIO_START_SEC_VAR_32BIT
	#pragma section ".bss.CPU0_32" awB 4
#elif defined DIO_STOP_SEC_VAR_32BIT
	#undef DIO_STOP_SEC_VAR_32BIT
	#pragma section
#elif defined DIO_START_SEC_CONST_8BIT
	#undef DIO_START_SEC_CONST_8BIT
	#pragma section ".rodata.CPU0_8" a 1
#elif defined DIO_STOP_SEC_CONST_8BIT
	#undef DIO_STOP_SEC_CONST_8BIT
	#pragma section
#elif defined DIO_START_SEC_CONST_16BIT
	#undef DIO_START_SEC_CONST_16BIT
	#pragma section ".rodata.CPU0_16" a 2
#elif defined DIO_STOP_SEC_CONST_16BIT
	#undef DIO_STOP_SEC_CONST_16BIT
	#pragma section
#elif defined DIO_START_SEC_CONST_32BIT
	#undef DIO_START_SEC_CONST_32BIT
	#pragma section ".rodata.CPU0_32" a 4
#elif defined DIO_STOP_SEC_CONST_32BIT
	#undef DIO_STOP_SEC_CONST_32BIT
	#pragma section
#elif defined DIO_START_SEC_POSTBUILDCFG
	#undef DIO_START_SEC_POSTBUILDCFG
	#pragma section ".rodata.CPU0_unspec" a 4
#elif defined DIO_STOP_SEC_POSTBUILDCFG
	#undef DIO_STOP_SEC_POSTBUILDCFG
	#pragma section
/*Code sec; allocated on trusted partition core 1*/
#elif defined DIO_START_SEC_CODE
	#undef DIO_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined DIO_STOP_SEC_CODE
	#undef DIO_STOP_SEC_CODE
	#pragma section

/*************************************************/
/***************** IRQ DRIVER SEC*****************/
/*************************************************/
/*Code sec; allocated on trusted partition core 0*/
#elif defined IRQ_START_SEC_CODE
	#undef IRQ_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined IRQ_STOP_SEC_CODE
	#undef IRQ_STOP_SEC_CODE
	#pragma section
#elif defined IFX_IRQ_START_SEC_CODE_ASIL_B
	#undef IFX_IRQ_START_SEC_CODE_ASIL_B
	#pragma section ".text.CPU0_Code" ax 4
#elif defined IFX_IRQ_START_SEC_CODE_ASIL_B
	#undef IFX_IRQ_START_SEC_CODE_ASIL_B
	#pragma section

/*************************************************/
/***************** GTM DRIVER SEC*****************/
/*************************************************/
/*Data sec; allocated on trusted partition core 1*/
#elif defined GTM_START_SEC_VAR_32BIT
	#undef GTM_START_SEC_VAR_32BIT
	#pragma section ".bss.SharedTrusted_32" awB 4
#elif defined GTM_STOP_SEC_VAR_32BIT
	#undef GTM_STOP_SEC_VAR_32BIT
	#pragma section
#elif defined GTM_START_SEC_CONST_UNSPECIFIED
	#undef GTM_START_SEC_CONST_UNSPECIFIED
	#pragma section ".rodata.CPU0_unspec" a 4
#elif defined GTM_STOP_SEC_CONST_UNSPECIFIED
	#undef GTM_STOP_SEC_CONST_UNSPECIFIED
	#pragma section
/*Code sec; allocated on trusted partition core 1*/
#elif defined GTM_START_SEC_CODE
	#undef GTM_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined GTM_STOP_SEC_CODE
	#undef GTM_STOP_SEC_CODE
	#pragma section

/*************************************************/
/***************** GPT DRIVER SEC*****************/
/*************************************************/
/*Data sec; allocated on trusted partition core 0*/

#elif defined GPT_START_SEC_VAR_8BIT
	#undef GPT_START_SEC_VAR_8BIT
	#pragma section ".bss.CPU0_8" awB 4
#elif defined GPT_STOP_SEC_VAR_8BIT
	#undef GPT_STOP_SEC_VAR_8BIT
	#pragma section
#elif defined GPT_START_SEC_VAR_32BIT
	#undef GPT_START_SEC_VAR_32BIT
	#pragma section ".bss.CPU0_32" awB 4
#elif defined GPT_STOP_SEC_VAR_32BIT
	#undef GPT_STOP_SEC_VAR_32BIT
	#pragma section
#elif defined GPT_START_SEC_POSTBUILDCFG
	#undef GPT_START_SEC_POSTBUILDCFG
	#pragma section ".rodata.CPU0_unspec" a 4
#elif defined GPT_STOP_SEC_POSTBUILDCFG
	#undef GPT_STOP_SEC_POSTBUILDCFG
	#pragma section
/*Code sec; allocated on trusted partition core 1*/
#elif defined GPT_START_SEC_CODE
	#undef GPT_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined GPT_STOP_SEC_CODE
	#undef GPT_STOP_SEC_CODE
	#pragma section
#elif defined GPT_START_SEC_CALLOUT_CODE
	#undef GPT_START_SEC_CALLOUT_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined GPT_STOP_SEC_CALLOUT_CODE
	#undef GPT_STOP_SEC_CALLOUT_CODE
	#pragma section

/*************************************************/
/***************** SPI DRIVER SEC*****************/
/*************************************************/
/*Data sec; allocated on trusted partition core 0*/

#elif defined SPI_START_SEC_VAR_8BIT
	#undef SPI_START_SEC_VAR_8BIT
	#pragma section ".bss.CPU0_8" awB 4
#elif defined SPI_STOP_SEC_VAR_8BIT
	#undef SPI_STOP_SEC_VAR_8BIT
	#pragma section
#elif defined SPI_START_SEC_VAR_32BIT
	#undef SPI_START_SEC_VAR_32BIT
	#pragma section ".bss.CPU0_32" awB 4
#elif defined SPI_STOP_SEC_VAR_32BIT
	#undef SPI_STOP_SEC_VAR_32BIT
	#pragma section
#elif defined SPI_START_SEC_VAR_UNSPECIFIED
	#undef SPI_START_SEC_VAR_UNSPECIFIED
	#pragma section ".bss.CPU0_unspec" awB 4
#elif defined SPI_STOP_SEC_VAR_UNSPECIFIED
	#undef SPI_STOP_SEC_VAR_UNSPECIFIED
	#pragma section
#elif defined SPI_START_SEC_POSTBUILDCFG
	#undef SPI_START_SEC_POSTBUILDCFG
	#pragma section ".rodata.CPU0_unspec" a 4
#elif defined SPI_STOP_SEC_POSTBUILDCFG
	#undef SPI_STOP_SEC_POSTBUILDCFG
	#pragma section
#elif defined SPI_START_SEC_VAR_FAST_32BIT
	#undef SPI_START_SEC_VAR_FAST_32BIT
	#pragma section ".bss.CPU0_32" awB 4
#elif defined SPI_STOP_SEC_VAR_FAST_32BIT
	#undef SPI_STOP_SEC_VAR_FAST_32BIT
	#pragma section

/*Code sec; allocated on trusted partition core 1*/
#elif defined SPI_START_SEC_CODE
	#undef SPI_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined SPI_STOP_SEC_CODE
	#undef SPI_STOP_SEC_CODE
	#pragma section

/*************************************************/
/***************** MCU DRIVER SEC*****************/
/*************************************************/
/*Data sec; allocated on trusted partition core 0*/
#elif defined MCU_START_SEC_VAR_8BIT
	#undef MCU_START_SEC_VAR_8BIT
	#pragma section ".bss.CPU0_8" awB 1
#elif defined MCU_STOP_SEC_VAR_8BIT
	#undef MCU_STOP_SEC_VAR_8BIT
	#pragma section
#elif defined MCU_START_SEC_VAR_INIT_32BIT
	#undef MCU_START_SEC_VAR_INIT_32BIT
	#pragma section ".data.CPU0_32" aw 4
#elif defined MCU_STOP_SEC_VAR_INIT_32BIT
	#undef MCU_STOP_SEC_VAR_INIT_32BIT
	#pragma section
#elif defined MCU_START_SEC_POSTBUILDCFG
	#undef MCU_START_SEC_POSTBUILDCFG
	#pragma section ".rodata.CPU0_unspec" a 4
#elif defined MCU_STOP_SEC_POSTBUILDCFG
	#undef MCU_STOP_SEC_POSTBUILDCFG
	#pragma section
#elif defined MCU_START_SEC_CONST_32BIT
	#undef MCU_START_SEC_CONST_32BIT
	#pragma section ".rodata.CPU0_32" a 4
#elif defined MCU_STOP_SEC_CONST_32BIT
	#undef MCU_STOP_SEC_CONST_32BIT
	#pragma section
/*Code sec; allocated on trusted partition core 0*/
#elif defined MCU_START_SEC_CODE
	#undef MCU_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined MCU_STOP_SEC_CODE
	#undef MCU_STOP_SEC_CODE
	#pragma section

/*************************************************/
/**************** PORT DRIVER SEC*****************/
/*************************************************/
/*Data sec; allocated on trusted partition core 1*/
#elif defined PORT_START_SEC_VAR_8BIT
	#undef PORT_START_SEC_VAR_8BIT
	#pragma section ".bss.CPU0_8" awB 1
#elif defined PORT_STOP_SEC_VAR_8BIT
	#undef PORT_STOP_SEC_VAR_8BIT
	#pragma section
#elif defined PORT_START_SEC_VAR_32BIT
	#undef PORT_START_SEC_VAR_32BIT
	#pragma section ".bss.CPU0_32" awB 4
#elif defined PORT_STOP_SEC_VAR_32BIT
	#undef PORT_STOP_SEC_VAR_32BIT
	#pragma section
#elif defined PORT_START_SEC_CONST_16BIT
	#undef PORT_START_SEC_CONST_16BIT
	#pragma section ".rodata.CPU0_16" a 2
#elif defined PORT_STOP_SEC_CONST_16BIT
	#undef PORT_STOP_SEC_CONST_16BIT
	#pragma section
#elif defined PORT_START_SEC_CONST_32BIT
	#undef PORT_START_SEC_CONST_32BIT
	#pragma section ".rodata.CPU0_32" a 4
#elif defined PORT_STOP_SEC_CONST_32BIT
	#undef PORT_STOP_SEC_CONST_32BIT
	#pragma section
#elif defined PORT_START_SEC_POSTBUILDCFG
	#undef PORT_START_SEC_POSTBUILDCFG
	#pragma section ".rodata.CPU0_unspec" a 4
#elif defined PORT_STOP_SEC_POSTBUILDCFG
	#undef PORT_STOP_SEC_POSTBUILDCFG
	#pragma section
/*Code sec; allocated on trusted partition core 1*/
#elif defined PORT_START_SEC_CODE
	#undef PORT_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined PORT_STOP_SEC_CODE
	#undef PORT_STOP_SEC_CODE
	#pragma section

/*************************************************/
/**************** ADC DRIVER SEC*****************/
/*************************************************/
/*Data sec; allocated on trusted partition core 1*/
#elif defined ADC_START_SEC_VAR_8BIT
	#undef ADC_START_SEC_VAR_8BIT
	#pragma section ".bss.CPU0_8" awB 1
#elif defined ADC_STOP_SEC_VAR_8BIT
	#undef ADC_STOP_SEC_VAR_8BIT
	#pragma section
#elif defined ADC_START_SEC_ASIL0_CONST_8BIT
	#undef ADC_START_SEC_ASIL0_CONST_8BIT
	#pragma section ".bss.CPU0_8" awB 1
#elif defined ADC_STOP_SEC_ASIL0_CONST_8BIT
	#undef ADC_STOP_SEC_ASIL0_CONST_8BIT
	#pragma section
#elif defined ADC_START_SEC_ASIL1_CONST_8BIT
	#undef ADC_START_SEC_ASIL1_CONST_8BIT
	#pragma section ".bss.CPU0_8" awB 1
#elif defined ADC_STOP_SEC_ASIL1_CONST_8BIT
	#undef ADC_STOP_SEC_ASIL1_CONST_8BIT
	#pragma section
#elif defined ADC_START_SEC_VAR_32BIT
	#undef ADC_START_SEC_VAR_32BIT
	#pragma section ".bss.CPU0_32" awB 4
#elif defined ADC_STOP_SEC_VAR_32BIT
	#undef ADC_STOP_SEC_VAR_32BIT
	#pragma section
#elif defined ADC_START_SEC_CONST_16BIT
	#undef ADC_START_SEC_CONST_16BIT
	#pragma section ".rodata.CPU0_16" a 2
#elif defined ADC_STOP_SEC_CONST_16BIT
	#undef ADC_STOP_SEC_CONST_16BIT
	#pragma section
#elif defined ADC_START_SEC_CONST_32BIT
	#undef ADC_START_SEC_CONST_32BIT
	#pragma section ".rodata.CPU0_32" a 4
#elif defined ADC_STOP_SEC_CONST_32BIT
	#undef ADC_STOP_SEC_CONST_32BIT
	#pragma section
#elif defined ADC_START_SEC_ASIL0_VAR_UNSPECIFIED
	#undef ADC_START_SEC_ASIL0_VAR_UNSPECIFIED
	#pragma section ".bss.CPU0_unspec" awB 4
#elif defined ADC_STOP_SEC_ASIL0_VAR_UNSPECIFIED
	#undef ADC_STOP_SEC_ASIL0_VAR_UNSPECIFIED
	#pragma section
#elif defined ADC_START_SEC_ASIL1_VAR_UNSPECIFIED
	#undef ADC_START_SEC_ASIL1_VAR_UNSPECIFIED
	#pragma section ".bss.CPU0_unspec" awB 4
#elif defined ADC_STOP_SEC_ASIL1_VAR_UNSPECIFIED
	#undef ADC_STOP_SEC_ASIL1_VAR_UNSPECIFIED
	#pragma section
#elif defined ADC_START_SEC_VAR_UNSPECIFIED
	#undef ADC_START_SEC_VAR_UNSPECIFIED
	#pragma section ".bss.CPU0_unspec" awB 4
#elif defined ADC_STOP_SEC_VAR_UNSPECIFIED
	#undef ADC_STOP_SEC_VAR_UNSPECIFIED
	#pragma section
#elif defined ADC_START_SEC_POSTBUILDCFG
	#undef ADC_START_SEC_POSTBUILDCFG
	#pragma section ".rodata.CPU0_unspec" a 4
#elif defined ADC_STOP_SEC_POSTBUILDCFG
	#undef ADC_STOP_SEC_POSTBUILDCFG
	#pragma section
#elif defined ADC_START_SEC_VAR_DMABUFFER
	#undef ADC_START_SEC_VAR_DMABUFFER
	#pragma section ".bss.CPU0_unspec" awB 4
#elif defined ADC_STOP_SEC_VAR_DMABUFFER
	#undef ADC_STOP_SEC_VAR_DMABUFFER
	#pragma section
/*Code sec; allocated on trusted partition core 1*/
#elif defined ADC_START_SEC_CODE
	#undef ADC_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined ADC_STOP_SEC_CODE
	#undef ADC_STOP_SEC_CODE
	#pragma section

/*************************************************/
/**************** DSADC DRIVER SEC*****************/
/*************************************************/
/*Data sec; allocated on trusted partition core 1*/
#elif defined DSADC_START_SEC_VAR_8BIT
	#undef DSADC_START_SEC_VAR_8BIT
	#pragma section ".bss.CPU0_8" awB 1
#elif defined DSADC_STOP_SEC_VAR_8BIT
	#undef DSADC_STOP_SEC_VAR_8BIT
	#pragma section
#elif defined DSADC_START_SEC_VAR_32BIT
	#undef DSADC_START_SEC_VAR_32BIT
	#pragma section ".bss.CPU0_32" awB 4
#elif defined DSADC_STOP_SEC_VAR_32BIT
	#undef DSADC_STOP_SEC_VAR_32BIT
	#pragma section
#elif defined DSADC_START_SEC_CONST_32BIT
	#undef DSADC_START_SEC_CONST_32BIT
	#pragma section ".rodata.CPU0_32" a 4
#elif defined DSADC_STOP_SEC_CONST_32BIT
	#undef DSADC_STOP_SEC_CONST_32BIT
	#pragma section
#elif defined DSADC_START_SEC_POSTBUILDCFG
	#undef DSADC_START_SEC_POSTBUILDCFG
	#pragma section ".rodata.CPU0_unspec" a 4
#elif defined DSADC_STOP_SEC_POSTBUILDCFG
	#undef DSADC_STOP_SEC_POSTBUILDCFG
	#pragma section
/*Code sec; allocated on trusted partition core 1*/
#elif defined DSADC_START_SEC_CODE
	#undef DSADC_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined DSADC_STOP_SEC_CODE
	#undef DSADC_STOP_SEC_CODE
	#pragma section

/*************************************************/
/**************** ICU_17_GTMCCU6 DRIVER SEC*****************/
/*************************************************/
/*Data sec; allocated on trusted partition core 1*/
#elif defined ICU_17_GTMCCU6_START_SEC_VAR_8BIT
	#undef ICU_17_GTMCCU6_START_SEC_VAR_8BIT
	#pragma section ".bss.CPU0_8" awB 1
#elif defined ICU_17_GTMCCU6_STOP_SEC_VAR_8BIT
	#undef ICU_17_GTMCCU6_STOP_SEC_VAR_8BIT
	#pragma section
#elif defined ICU_17_GTMCCU6_START_SEC_VAR_32BIT
	#undef ICU_17_GTMCCU6_START_SEC_VAR_32BIT
	#pragma section ".bss.CPU0_32" awB 4
#elif defined ICU_17_GTMCCU6_STOP_SEC_VAR_32BIT
	#undef ICU_17_GTMCCU6_STOP_SEC_VAR_32BIT
	#pragma section
#elif defined ICU_17_GTMCCU6_START_SEC_CONST_16BIT
	#undef ICU_17_GTMCCU6_START_SEC_CONST_16BIT
	#pragma section ".rodata.CPU0_16" a 2
#elif defined ICU_17_GTMCCU6_STOP_SEC_CONST_16BIT
	#undef ICU_17_GTMCCU6_STOP_SEC_CONST_16BIT
	#pragma section
#elif defined ICU_17_GTMCCU6_START_SEC_CONST_32BIT
	#undef ICU_17_GTMCCU6_START_SEC_CONST_32BIT
	#pragma section ".rodata.CPU0_32" a 4
#elif defined ICU_17_GTMCCU6_STOP_SEC_CONST_32BIT
	#undef ICU_17_GTMCCU6_STOP_SEC_CONST_32BIT
	#pragma section
#elif defined ICU_17_GTMCCU6_START_SEC_POSTBUILDCFG
	#undef ICU_17_GTMCCU6_START_SEC_POSTBUILDCFG
	#pragma section ".rodata.CPU0_unspec" a 4
#elif defined ICU_17_GTMCCU6_STOP_SEC_POSTBUILDCFG
	#undef ICU_17_GTMCCU6_STOP_SEC_POSTBUILDCFG
	#pragma section
#elif defined ICU_17_GTMCCU6_START_SEC_VAR_UNSPECIFIED
	#undef ICU_17_GTMCCU6_START_SEC_VAR_UNSPECIFIED
	#pragma section ".bss.CPU0_unspec" awB 4
#elif defined ICU_17_GTMCCU6_STOP_SEC_VAR_UNSPECIFIED
	#undef ICU_17_GTMCCU6_STOP_SEC_VAR_UNSPECIFIED
	#pragma section
#elif defined ICU_17_GTMCCU6_START_SEC_ASIL0_VAR_UNSPECIFIED
	#undef ICU_17_GTMCCU6_START_SEC_ASIL0_VAR_UNSPECIFIED
	#pragma section ".bss.CPU0_unspec" awB 4
#elif defined ICU_17_GTMCCU6_STOP_SEC_ASIL0_VAR_UNSPECIFIED
	#undef ICU_17_GTMCCU6_STOP_SEC_ASIL0_VAR_UNSPECIFIED
	#pragma section
#elif defined ICU_17_GTMCCU6_START_SEC_ASIL1_VAR_UNSPECIFIED
	#undef ICU_17_GTMCCU6_START_SEC_ASIL1_VAR_UNSPECIFIED
	#pragma section ".bss.CPU0_unspec" awB 4
#elif defined ICU_17_GTMCCU6_STOP_SEC_ASIL1_VAR_UNSPECIFIED
	#undef ICU_17_GTMCCU6_STOP_SEC_ASIL1_VAR_UNSPECIFIED
	#pragma section
/*Code sec; allocated on trusted partition core 1*/
#elif defined ICU_17_GTMCCU6_START_SEC_CODE
	#undef ICU_17_GTMCCU6_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined ICU_17_GTMCCU6_STOP_SEC_CODE
	#undef ICU_17_GTMCCU6_STOP_SEC_CODE
	#pragma section
#elif defined ICU_17_GTMCCU6_START_SEC_CALLOUT_CODE
	#undef ICU_17_GTMCCU6_START_SEC_CALLOUT_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined ICU_17_GTMCCU6_STOP_SEC_CALLOUT_CODE
	#undef ICU_17_GTMCCU6_STOP_SEC_CALLOUT_CODE
	#pragma section

/*************************************************/
/**************** PWM_17_GTM DRIVER SEC*****************/
/*************************************************/
/*Data sec; allocated on trusted partition core 1*/
#elif defined PWM_17_GTM_START_SEC_VAR_8BIT
	#undef PWM_17_GTM_START_SEC_VAR_8BIT
	#pragma section ".bss.CPU0_8" awB 1
#elif defined PWM_17_GTM_STOP_SEC_VAR_8BIT
	#undef PWM_17_GTM_STOP_SEC_VAR_8BIT
	#pragma section
#elif defined PWM_17_GTM_START_SEC_VAR_32BIT
	#undef PWM_17_GTM_START_SEC_VAR_32BIT
	#pragma section ".bss.CPU0_32" awB 4
#elif defined PWM_17_GTM_STOP_SEC_VAR_32BIT
	#undef PWM_17_GTM_STOP_SEC_VAR_32BIT
	#pragma section
#elif defined PWM_17_GTM_START_SEC_CONST_16BIT
	#undef PWM_17_GTM_START_SEC_CONST_16BIT
	#pragma section ".rodata.CPU0_16" a 2
#elif defined PWM_17_GTM_STOP_SEC_CONST_16BIT
	#undef PWM_17_GTM_STOP_SEC_CONST_16BIT
	#pragma section
#elif defined PWM_17_GTM_START_SEC_CONST_32BIT
	#undef PWM_17_GTM_START_SEC_CONST_32BIT
	#pragma section ".rodata.CPU0_32" a 4
#elif defined PWM_17_GTM_STOP_SEC_CONST_32BIT
	#undef PWM_17_GTM_STOP_SEC_CONST_32BIT
	#pragma section
#elif defined PWM_17_GTM_START_SEC_POSTBUILDCFG
	#undef PWM_17_GTM_START_SEC_POSTBUILDCFG
	#pragma section ".rodata.CPU0_unspec" a 4
#elif defined PWM_17_GTM_STOP_SEC_POSTBUILDCFG
	#undef PWM_17_GTM_STOP_SEC_POSTBUILDCFG
	#pragma section
#elif defined PWM_17_GTM_START_SEC_ASIL0_VAR_32BIT
	#undef PWM_17_GTM_START_SEC_ASIL0_VAR_32BIT
	#pragma section ".bss.CPU0_unspec" a 4
#elif defined PWM_17_GTM_STOP_SEC_ASIL0_VAR_32BIT
	#undef PWM_17_GTM_STOP_SEC_ASIL0_VAR_32BIT
	#pragma section
#elif defined PWM_17_GTM_START_SEC_VAR_FAST_32BIT
	#undef PWM_17_GTM_START_SEC_VAR_FAST_32BIT
	#pragma section ".bss.CPU0_unspec" awB 4
#elif defined PWM_17_GTM_STOP_SEC_VAR_FAST_32BIT
	#undef PWM_17_GTM_STOP_SEC_VAR_FAST_32BIT
	#pragma section
/*Code sec; allocated on trusted partition core 1*/
#elif defined PWM_17_GTM_START_SEC_CODE
	#undef PWM_17_GTM_START_SEC_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined PWM_17_GTM_STOP_SEC_CODE
	#undef PWM_17_GTM_STOP_SEC_CODE
	#pragma section
#elif defined PWM_17_GTM_START_SEC_CALLOUT_CODE
	#undef PWM_17_GTM_START_SEC_CALLOUT_CODE
	#pragma section ".text.CPU0_Code" ax 4
#elif defined PWM_17_GTM_STOP_SEC_CALLOUT_CODE
	#undef PWM_17_GTM_STOP_SEC_CALLOUT_CODE
	#pragma section

/* WDG lib */
#elif defined (MCAL_WDGLIB_START_SEC_VAR_INIT_32BIT)
   #undef     MCAL_WDGLIB_START_SEC_VAR_INIT_32BIT
   #pragma section ".data.CPU0_32" aw 4
#elif defined (MCAL_WDGLIB_STOP_SEC_VAR_INIT_32BIT)
   #undef     MCAL_WDGLIB_STOP_SEC_VAR_INIT_32BIT
   #pragma section

#elif defined (MCAL_WDGLIB_START_SEC_VAR_32BIT)
   #undef     MCAL_WDGLIB_START_SEC_VAR_32BIT
   #pragma section ".bss.CPU0_32" awB 4
#elif defined (MCAL_WDGLIB_STOP_SEC_VAR_32BIT)
   #undef     MCAL_WDGLIB_STOP_SEC_VAR_32BIT
   #pragma section
#elif defined MCAL_WDGLIB_START_SEC_CONST_32BIT
   #undef MCAL_WDGLIB_START_SEC_CONST_32BIT
   #pragma section ".rodata.CPU0_32" a 4
#elif defined MCAL_WDGLIB_STOP_SEC_CONST_32BIT
   #undef MCAL_WDGLIB_STOP_SEC_CONST_32BIT
   #pragma section
#elif defined MCAL_WDGLIB_START_SEC_CODE
   #undef MCAL_WDGLIB_START_SEC_CODE
   #pragma section ".text.CPU0_Code" ax 4
#elif defined MCAL_WDGLIB_STOP_SEC_CODE
   #undef MCAL_WDGLIB_STOP_SEC_CODE
   #pragma section

/*MCAL lib*/
#elif defined MCAL_START_SEC_VAR_FAST_32BIT
   #undef MCAL_START_SEC_VAR_FAST_32BIT
   #pragma section ".data.CPU0_32" aw 4
#elif defined MCAL_STOP_SEC_VAR_FAST_32BIT
   #undef MCAL_STOP_SEC_VAR_FAST_32BIT
   #pragma section
#elif defined MCAL_START_SEC_VAR_CLEARED_32BIT
   #undef MCAL_START_SEC_VAR_CLEARED_32BIT
   #pragma section ".bss.CPU0_32" awB 4
#elif defined MCAL_STOP_SEC_VAR_CLEARED_32BIT
   #undef MCAL_STOP_SEC_VAR_CLEARED_32BIT
   #pragma section
#elif defined MCAL_START_SEC_CONST_UNSPECIFIED
   #undef MCAL_START_SEC_CONST_UNSPECIFIED
   #pragma section ".rodata.CPU0_unspec" a 4
#elif defined MCAL_STOP_SEC_CONST_UNSPECIFIED
   #undef MCAL_STOP_SEC_CONST_UNSPECIFIED
   #pragma section
#elif defined MCAL_START_SEC_CODE
   #undef MCAL_START_SEC_CODE
   #pragma section ".text.CPU0_Code" ax 4
#elif defined MCAL_STOP_SEC_CODE
   #undef MCAL_STOP_SEC_CODE
   #pragma section

/*MCAL DMA lib*/
#elif defined MCAL_DMALIB_START_SEC_CODE
   #undef MCAL_DMALIB_START_SEC_CODE
   #pragma section ".text.CPU0_Code" ax 4
#elif defined MCAL_DMALIB_STOP_SEC_CODE
   #undef MCAL_DMALIB_STOP_SEC_CODE
   #pragma section

/*MCAL TC lib*/
#elif defined MCAL_TCLIB_START_SEC_VAR_INIT_32BIT
   #undef MCAL_TCLIB_START_SEC_VAR_INIT_32BIT
   #pragma section ".data.CPU0_32" aw 4
#elif defined MCAL_TCLIB_STOP_SEC_VAR_INIT_32BIT
   #undef MCAL_TCLIB_STOP_SEC_VAR_INIT_32BIT
   #pragma section
#elif defined MCAL_TCLIB_START_SEC_CONST_32BIT
   #undef MCAL_TCLIB_START_SEC_CONST_32BIT
   #pragma section ".rodata.CPU0_32" a 4
#elif defined MCAL_TCLIB_STOP_SEC_CONST_32BIT
   #undef MCAL_TCLIB_STOP_SEC_CONST_32BIT
   #pragma section
#elif defined MCAL_TCLIB_START_SEC_CODE
   #undef MCAL_TCLIB_START_SEC_CODE
   #pragma section ".text.CPU0_Code" ax 4
#elif defined MCAL_TCLIB_STOP_SEC_CODE
   #undef MCAL_TCLIB_STOP_SEC_CODE
   #pragma section

/*Start up*/
#elif defined STARTUP_START_SEC_CODE
   #undef STARTUP_START_SEC_CODE
   #pragma section ".text.CPU0_Code" ax 4
#elif defined STARTUP_STOP_SEC_CODE
   #undef STARTUP_STOP_SEC_CODE
   #pragma section

/*fix cstart address*/
#elif defined CSTART_START_SEC_CODE
   #undef CSTART_START_SEC_CODE
   #pragma section ".text.cstart" ax 4
#elif defined CSTART_STOP_SEC_CODE
   #undef CSTART_STOP_SEC_CODE
   #pragma section

/*Main*/
#elif defined MAIN_START_SEC_CODE
   #undef MAIN_START_SEC_CODE
   #pragma section ".text.CPU0_Code" ax 4
#elif defined MAIN_STOP_SEC_CODE
   #undef MAIN_STOP_SEC_CODE
   #pragma section

/*CAT1_ISR*/
#elif defined CAT1_ISR_START_SEC_CODE
   #undef CAT1_ISR_START_SEC_CODE
   #pragma section ".text.CPU0_Code" ax 4
#elif defined CAT1_ISR_STOP_SEC_CODE
   #undef CAT1_ISR_STOP_SEC_CODE
   #pragma section

/*****************************************************************************
**                                 FLSLOADER
******************************************************************************/
#elif defined (FLSLOADER_START_SEC_WRITE_CODE)
   #undef      FLSLOADER_START_SEC_WRITE_CODE
   #pragma section ".FLSLOADERRAMCODE" ax
#elif defined (FLSLOADER_STOP_SEC_WRITE_CODE)
   #undef      FLSLOADER_STOP_SEC_WRITE_CODE
   #pragma section

/* -------------------------------------------------------------------------- */
/* End of default section mapping                                             */
/* -------------------------------------------------------------------------- */
#endif  /* START_WITH_IF */




/*** End of file **************************************************************/
