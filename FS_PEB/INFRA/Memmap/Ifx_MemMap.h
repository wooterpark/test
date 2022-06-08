/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Ifx_MemMap.h $                                             **
**                                                                           **
**  $CC VERSION : \main\151 $                                                **
**                                                                           **
**  $DATE       : 2016-09-30 $                                               **
**                                                                           **
**  PLATFORM  : Infineon Aurix                                               **
**                                                                           **
**  PROJECT   : DL-BLR-ATV-STC                                               **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  :                                                           **
**                                                                           **
**             This file allows to map variables, constants and code         **
**             of modules to individual memory sections. The user can        **
**             adapt the memory mapping to their ECU specific needs.         **
**                                                                           **
**             Important note 1: if specific variables and constants are     **
**             mapped to banked/paged memory, the related compiler           **
**             abstraction symbols must fit to these locations!              **
**                                                                           **
**             Important note 2: The section names passed via #pragmas must  **
**             be defined in the linker control and section map files!       **
**  SPECIFICATION(S) : AUTOSAR_SWS_MemoryMapping.pdf,Release 1.0.0           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/


/******************************************************************************
**                      Module section mapping                               **
******************************************************************************/
/*
 * The symbol 'START_WITH_IF' is undefined.
 *
 * Thus, the preprocessor continues searching for defined symbols
 * This first #ifdef makes integration of delivered parts of MemMap.h
 * easier because every supplier starts with #elif
 */
/*
 * MemMap 019 published information
 */
#undef  _DIABDATA_C_TRICORE_

#ifndef MEMMAP_H
#define MEMMAP_H
/* Mem Vendor ID */
#define MEM_VENDOR_ID         ((uint16)17)

/* MEM SW Major Version */
#define MEM_SW_MAJOR_VERSION  (1U)
/* MEM SW Minor Version */
#define MEM_SW_MINOR_VERSION  (0)
/* MEM SW Patch Version */
#define MEM_SW_PATCH_VERSION  (0)

/* MEM AR Major Version */
#define MEM_AR_MAJOR_VERSION  (1U)
/* MEM AR Minor Version */
#define MEM_AR_MINOR_VERSION  (0)
/* MEM AR Patch Version */
#define MEM_AR_PATCH_VERSION  (13U)

#endif
/*
  Identifier clash , upto 60 characters allowed
  MISRA Rule 92 violation : #undef should not be used.
  MemMap works with undefine and redefine principle.
*/
/*lint -idlen(60) -esym(961,92) */

/*lint -esym(960,19.6)   */  /* Allow usage of #undef */
#if defined (START_WITH_IF)

/*****************************************************************************
**                                 TSTHANDLER                                      **
******************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_TSTHANDLER_START_SEC_CODE_ASIL_B)
   #undef      IFX_TSTHANDLER_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_TSTHANDLER_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_TSTHANDLER_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */

#elif defined (IFX_TSTHANDLER_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_TSTHANDLER_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_TSTHANDLER_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_TSTHANDLER_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED


/*
 * To be used for global or static variables (32 bits) that are initialized
 * to non-zero after every reset (the normal case)
 */
#elif defined (IFX_TSTHANDLER_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_TSTHANDLER_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_32BIT
#elif defined (IFX_TSTHANDLER_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_TSTHANDLER_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_32BIT


/*
 * To be used for postbuild configuration (unspecified size)
 *
*/
#elif defined (IFX_TSTHANDLER_START_SEC_POSTBUILDCFG_ASIL_B)
   #undef      IFX_TSTHANDLER_START_SEC_POSTBUILDCFG_ASIL_B
   #define DEFAULT_START_SEC_POSTBUILDCFG
#elif defined (IFX_TSTHANDLER_STOP_SEC_POSTBUILDCFG_ASIL_B)
   #undef      IFX_TSTHANDLER_STOP_SEC_POSTBUILDCFG_ASIL_B
   #define DEFAULT_STOP_SEC_POSTBUILDCFG

/*****************************************************************************
**                                 VLTM                                      **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_VLTM_START_SEC_CODE_ASIL_B)
   #undef      IFX_VLTM_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_VLTM_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_VLTM_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_VLTM_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_VLTM_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_VLTM_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_VLTM_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

/*****************************************************************************
**                                 SRI                                      **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_SRI_START_SEC_CODE_ASIL_B)
   #undef      IFX_SRI_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_NO_OPTIMIZED_CODE
#elif defined (IFX_SRI_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_SRI_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_NO_OPTIMIZED_CODE

/*
 * To be used for global or static variables (8-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_SRI_START_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_SRI_START_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_SRI_STOP_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_SRI_STOP_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_SRI_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_SRI_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_SRI_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_SRI_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

/*
 * To be used for global or static constants (8 bit size)
 *
 */
#elif defined (IFX_SRI_START_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_SRI_START_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_8BIT
#elif defined (IFX_SRI_STOP_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_SRI_STOP_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_8BIT

/*
 * To be used for global or static constants (32 bit size)
 *
 */
#elif defined (IFX_SRI_START_SEC_CONST_32BYTE_ALIGN_ASIL_B)
   #undef      IFX_SRI_START_SEC_CONST_32BYTE_ALIGN_ASIL_B
   #define DEFAULT_START_SEC_VAR_CONST_32BYTEALIGN
#elif defined (IFX_SRI_STOP_SEC_CONST_32BYTE_ALIGN_ASIL_B )
   #undef      IFX_SRI_STOP_SEC_CONST_32BYTE_ALIGN_ASIL_B 
   #define DEFAULT_STOP_SEC_VAR_CONST_32BYTEALIGN

/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_SRI_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_SRI_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_SRI_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_SRI_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

/*****************************************************************************
**                          PERIPHERAL SRAM                                 **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_PHL_SRAM_START_SEC_CODE_ASIL_B)
   #undef      IFX_PHL_SRAM_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_PHL_SRAM_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_PHL_SRAM_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

   
/*
 * To be used for global or static variables (32-bit size) that are initialized
 * to non-zero after every reset (the normal case)
 */
#elif defined (IFX_PHL_SRAM_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_PHL_SRAM_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_32BIT
#elif defined (IFX_PHL_SRAM_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_PHL_SRAM_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_32BIT   

/*
 * To be used for global or static constants (32 bit size)
 *
 */

#elif defined (IFX_PHL_SRAM_START_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_PHL_SRAM_START_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_32BIT
#elif defined (IFX_PHL_SRAM_STOP_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_PHL_SRAM_STOP_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_32BIT
   
/*
 * To be used for global or static constants (32 bit size)
 *
 */

#elif defined (IFX_PHL_SRAM_START_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_PHL_SRAM_START_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_8BIT
#elif defined (IFX_PHL_SRAM_STOP_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_PHL_SRAM_STOP_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_8BIT   

/*
 * To be used for global or static constants (unspecified size)
 *
 */

#elif defined (IFX_PHL_SRAM_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_PHL_SRAM_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_PHL_SRAM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_PHL_SRAM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED

/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_PHL_SRAM_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_PHL_SRAM_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_PHL_SRAM_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_PHL_SRAM_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

/*****************************************************************************
**                              SRAM ECC                                    **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_SRAM_START_SEC_CODE_ASIL_B)
   #undef      IFX_SRAM_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_SRAM_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_SRAM_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE
/*to be used for code for which optimization should be off*/
#elif defined (IFX_SRAM_START_SEC_CODE_NO_OPTIMIZED_ASIL_B)
   #undef      IFX_SRAM_START_SEC_CODE_NO_OPTIMIZED_ASIL_B
   #define   DEFAULT_START_SEC_NO_OPTIMIZED_CODE  
#elif defined (IFX_SRAM_STOP_SEC_CODE_NO_OPTIMIZED_ASIL_B)
   #undef      IFX_SRAM_STOP_SEC_CODE_NO_OPTIMIZED_ASIL_B
   #define DEFAULT_STOP_SEC_NO_OPTIMIZED_CODE   

/*
 * To be used for global or static variables (8-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_SRAM_START_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_SRAM_START_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_SRAM_STOP_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_SRAM_STOP_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT

/*
 * To be used for global or static variables (32-bit size) that are initialized
 * to non-zero after every reset (the normal case)
 */
#elif defined (IFX_SRAM_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_SRAM_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_32BIT
#elif defined (IFX_SRAM_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_SRAM_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_32BIT


/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */

#elif defined (IFX_SRAM_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_SRAM_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_SRAM_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_SRAM_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/*
 * To be used for global or static constants (8 bit size)
 *
 */

#elif defined (IFX_SRAM_START_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_SRAM_START_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_8BIT
#elif defined (IFX_SRAM_STOP_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_SRAM_STOP_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_8BIT
/*
 * To be used for global or static constants (32 bit size)
 *
 */

#elif defined (IFX_SRAM_START_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_SRAM_START_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_32BIT
#elif defined (IFX_SRAM_STOP_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_SRAM_STOP_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_32BIT

#elif defined (IFX_SRAM_START_SEC_CONST_16BIT_ASIL_B)
   #undef      IFX_SRAM_START_SEC_CONST_16BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_16BIT
#elif defined (IFX_SRAM_STOP_SEC_CONST_16BIT_ASIL_B)
   #undef      IFX_SRAM_STOP_SEC_CONST_16BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_16BIT
   
/*
 * To be used for global or static constants (unspecified size)
 *
 */

#elif defined (IFX_SRAM_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_SRAM_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_SRAM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_SRAM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED

/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_SRAM_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_SRAM_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_SRAM_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_SRAM_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

/*****************************************************************************
**                              MBIST                                       **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_MBIST_START_SEC_CODE_ASIL_B)
   #undef      IFX_MBIST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_MBIST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_MBIST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for global or static variables (8-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_MBIST_START_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_MBIST_START_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_MBIST_STOP_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_MBIST_STOP_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT

/*
 * To be used for global or static variables (16-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_MBIST_START_SEC_VAR_16BIT_ASIL_B)
   #undef      IFX_MBIST_START_SEC_VAR_16BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_16BIT
#elif defined (IFX_MBIST_STOP_SEC_VAR_16BIT_ASIL_B)
   #undef      IFX_MBIST_STOP_SEC_VAR_16BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_16BIT

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_MBIST_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_MBIST_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_MBIST_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_MBIST_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */

#elif defined (IFX_MBIST_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_MBIST_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_MBIST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_MBIST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/*
 * To be used for global or static constants (8 bit size)
 *
 */

#elif defined (IFX_MBIST_START_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_MBIST_START_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_8BIT
#elif defined (IFX_MBIST_STOP_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_MBIST_STOP_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_8BIT

/*
 * To be used for global or static constants (16 bit size)
 *
 */

#elif defined (IFX_MBIST_START_SEC_CONST_16BIT_ASIL_B)
   #undef      IFX_MBIST_START_SEC_CONST_16BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_16BIT
#elif defined (IFX_MBIST_STOP_SEC_CONST_16BIT_ASIL_B)
   #undef      IFX_MBIST_STOP_SEC_CONST_16BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_16BIT

/*
 * To be used for global or static constants (32 bit size)
 *
 */

#elif defined (IFX_MBIST_START_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_MBIST_START_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_32BIT
#elif defined (IFX_MBIST_STOP_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_MBIST_STOP_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_32BIT

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */

#elif defined (IFX_MBIST_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_MBIST_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_MBIST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_MBIST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED

/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_MBIST_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_MBIST_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_MBIST_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_MBIST_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

/*****************************************************************************
**                                 SBST                                     **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_SBST_START_SEC_CODE_ASIL_B)
   #undef      IFX_SBST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_SBST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_SBST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_SBST_CALLBACK_START_SEC_CODE_ASIL_B)
   #undef      IFX_SBST_CALLBACK_START_SEC_CODE_ASIL_B
   #define     SBST_CALLBACK_START_SEC_CODE
#elif defined (IFX_SBST_CALLBACK_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_SBST_CALLBACK_STOP_SEC_CODE_ASIL_B
   #define     SBST_CALLBACK_STOP_SEC_CODE
/*****************************************************************************
**                                 CLKM                                     **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_CLKM_START_SEC_CODE_ASIL_B)
   #undef      IFX_CLKM_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_CLKM_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_CLKM_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_CLKM_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_CLKM_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_CLKM_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_CLKM_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

/*
 * To be used for global or static variables (8-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_CLKM_START_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_CLKM_START_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_CLKM_STOP_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_CLKM_STOP_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_CLKM_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_CLKM_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_CLKM_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_CLKM_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/*
 * To be used for global or static constants (8 bit size)
 *
 */
#elif defined (IFX_CLKM_START_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_CLKM_START_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_8BIT
#elif defined (IFX_CLKM_STOP_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_CLKM_STOP_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_8BIT


/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_CLKM_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_CLKM_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_CLKM_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_CLKM_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

/*****************************************************************************
**                                 CPUBUSMPULFM                             **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_CPUBUSMPULFM_START_SEC_CODE_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_CPUBUSMPULFM_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE


/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
   
#elif defined (IFX_CPUBUSMPULFM_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_CPUBUSMPULFM_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
/*
 * To be used for global or static constants (unspecified size) that are
 * initialized with non-zero after every reset (the normal case)
 */
#elif defined (IFX_CPUBUSMPULFM_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED 
#elif defined (IFX_CPUBUSMPULFM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED   

/*
 * To be used for global or static constants (32 bit size)
 *
 */
#elif defined (IFX_CPUBUSMPULFM_START_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_START_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_32BIT
#elif defined (IFX_CPUBUSMPULFM_STOP_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_STOP_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_32BIT

/*
 * To be used for global or static variables (32 bit size)
 *
 */
#elif defined (IFX_CPUBUSMPULFM_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_CPUBUSMPULFM_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT   

/*
 * To be used for global or static constants (8 bit size)
 *
 */
#elif defined (IFX_CPUBUSMPULFM_START_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_START_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_8BIT
#elif defined (IFX_CPUBUSMPULFM_STOP_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_STOP_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_8BIT

/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_CPUBUSMPULFM_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_CPUBUSMPULFM_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_CPUBUSMPULFM_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG
/*****************************************************************************
**                                 CPUBUSMPUSPFM                            **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_CPUBUSMPUSPFM_START_SEC_CODE_ASIL_B)
   #undef      IFX_CPUBUSMPUSPFM_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_CPUBUSMPUSPFM_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_CPUBUSMPUSPFM_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_CPUBUSMPUSPFM_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_CPUBUSMPUSPFM_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_CPUBUSMPUSPFM_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_CPUBUSMPUSPFM_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG


/*****************************************************************************
**                                 CPUMPUTST                                **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_CPUMPUTST_START_SEC_CODE_ASIL_B)
   #undef      IFX_CPUMPUTST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_NO_OPTIMIZED_CODE
#elif defined (IFX_CPUMPUTST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_CPUMPUTST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_NO_OPTIMIZED_CODE


/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_CPUMPUTST_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_CPUMPUTST_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_CPUMPUTST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_CPUMPUTST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED


/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_CPUMPUTST_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_CPUMPUTST_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_CPUMPUTST_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_CPUMPUTST_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

#elif defined (IFX_CPUMPUTST_START_SEC_VAR_8BYTE_ALIGN_ASIL_B)
   #undef      IFX_CPUMPUTST_START_SEC_VAR_8BYTE_ALIGN_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BYTEALIGN
#elif defined (IFX_CPUMPUTST_STOP_SEC_VAR_8BYTE_ALIGN_ASIL_B)
   #undef      IFX_CPUMPUTST_STOP_SEC_VAR_8BYTE_ALIGN_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BYTEALIGN

#elif defined (IFX_CPUMPUTST_START_SEC_CODE_8BYTE_ALIGN_ASIL_B)
   #undef      IFX_CPUMPUTST_START_SEC_CODE_8BYTE_ALIGN_ASIL_B
   #define DEFAULT_START_SEC_8BYTE_ALIGN_CODE
#elif defined (IFX_CPUMPUTST_STOP_SEC_CODE_8BYTE_ALIGN_ASIL_B)
   #undef      IFX_CPUMPUTST_STOP_SEC_CODE_8BYTE_ALIGN_ASIL_B
   #define DEFAULT_STOP_SEC_8BYTE_ALIGN_CODE

/*****************************************************************************
**                                OSCWDGTST                                 **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_OSCWDGTST_START_SEC_CODE_ASIL_B)
   #undef      IFX_OSCWDGTST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_OSCWDGTST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_OSCWDGTST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for postbuild configuration (unspecified size)
 *
*/
#elif defined (IFX_OSCWDGTST_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_OSCWDGTST_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_OSCWDGTST_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_OSCWDGTST_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

/*******************************************************************************
**                                SFFTST                                      **
*******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_SFFTST_START_SEC_CODE_ASIL_B)
   #undef      IFX_SFFTST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_SFFTST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_SFFTST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*****************************************************************************
**                                 SMU                                      **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_SMU_START_SEC_CODE_ASIL_B)
   #undef      IFX_SMU_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_SMU_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_SMU_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for global or static variables (8-bits size) that are
 * not required to be initialized after every reset (the normal case)
 */
#elif defined (IFX_SMU_START_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B)
   #undef      IFX_SMU_START_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_8BIT
#elif defined (IFX_SMU_STOP_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B)
   #undef      IFX_SMU_STOP_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_8BIT

/*
 * To be used for redundant global or static variables (8-bits size) that are
 * not required to be initialized after every reset (the normal case)
 * Not required separate section, but added to remove any dependent failure
 * if the section IFX_SMU_START_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B gets corrupted
 */
#elif defined (IFX_SMU_START_SEC_BACKUPVAR_NONZERO_INIT_8BIT_ASIL_B)
   #undef      IFX_SMU_START_SEC_BACKUPVAR_NONZERO_INIT_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_8BIT
#elif defined (IFX_SMU_STOP_SEC_BACKUPVAR_NONZERO_INIT_8BIT_ASIL_B)
   #undef      IFX_SMU_STOP_SEC_BACKUPVAR_NONZERO_INIT_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_8BIT

/*
 * To be used for global or static variables (8-bits size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_SMU_START_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_SMU_START_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_SMU_STOP_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_SMU_STOP_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT

/*
 * To be used for redundant global or static variables (8-bits size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 * Not required separate section, but added to remove any dependent failure
 * if the section IFX_SMU_START_SEC_VAR_8BIT_ASIL_B gets corrupted
 */
#elif defined (IFX_SMU_START_SEC_BACKUPVAR_8BIT_ASIL_B)
   #undef      IFX_SMU_START_SEC_BACKUPVAR_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_SMU_STOP_SEC_BACKUPVAR_8BIT_ASIL_B)
   #undef      IFX_SMU_STOP_SEC_BACKUPVAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT
/*
 * To be used for postbuild configuration (unspecified size)
 *
*/
#elif defined (IFX_SMU_START_SEC_POSTBUILDCFG_ASIL_B)
   #undef      IFX_SMU_START_SEC_POSTBUILDCFG_ASIL_B
   #define DEFAULT_START_SEC_POSTBUILDCFG
#elif defined (IFX_SMU_STOP_SEC_POSTBUILDCFG_ASIL_B)
   #undef      IFX_SMU_STOP_SEC_POSTBUILDCFG_ASIL_B
   #define DEFAULT_STOP_SEC_POSTBUILDCFG

/*****************************************************************************
**                             MCAL_WDGLIB                                   **
******************************************************************************/

/*
 * To be used for global or static variables (32 bits) that are initialized
 * to non-zero after every reset (the normal case)
 */
#elif defined (IFX_MCAL_WDGLIB_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_MCAL_WDGLIB_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_32BIT
#elif defined (IFX_MCAL_WDGLIB_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_MCAL_WDGLIB_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_32BIT

/*
 * To be used for global or static variables (32-bits size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_MCAL_WDGLIB_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_MCAL_WDGLIB_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_MCAL_WDGLIB_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_MCAL_WDGLIB_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

/*
 * To be used for constant global or static variables (32 bits)
 */

#elif defined (IFX_MCAL_WDGLIB_START_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_MCAL_WDGLIB_START_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_32BIT
#elif defined (IFX_MCAL_WDGLIB_STOP_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_MCAL_WDGLIB_STOP_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_32BIT

/*
 * To be used for mapping code
 */
#elif defined (IFX_MCAL_WDGLIB_START_SEC_CODE_ASIL_B)
   #undef      IFX_MCAL_WDGLIB_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_MCAL_WDGLIB_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_MCAL_WDGLIB_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE



/*****************************************************************************
**                               IRQ                                        **
******************************************************************************/
/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_IRQ_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_IRQ_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_IRQ_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_IRQ_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

/*
 * To be used for mapping code
 */

#elif defined (IFX_IRQ_START_SEC_CODE_ASIL_B)
   #undef      IFX_IRQ_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_IRQ_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_IRQ_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for mapping vector code
 */
#elif defined (IFX_IRQ_START_SEC_IVT_CODE_ASIL_B)
   #undef      IFX_IRQ_START_SEC_IVT_CODE_ASIL_B
   #define   DEFAULT_START_SEC_IVT_CODE
#elif defined (IFX_IRQ_STOP_SEC_IVT_CODE_ASIL_B)
   #undef      IFX_IRQ_STOP_SEC_IVT_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_IVT_CODE

/*****************************************************************************
**                                  MCAL                                    **
******************************************************************************/

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 * and placed in Core specific DSPR/PSPR for fast access
 */
#elif defined (IFX_MCAL_START_SEC_VAR_FAST_32BIT_ASIL_B)
   #undef      IFX_MCAL_START_SEC_VAR_FAST_32BIT_ASIL_B
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT
#elif defined (IFX_MCAL_STOP_SEC_VAR_FAST_32BIT_ASIL_B)
   #undef      IFX_MCAL_STOP_SEC_VAR_FAST_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT

/*
 * To be used for constant global or static variables (unspecified)
 */

#elif defined (IFX_MCAL_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_MCAL_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_MCAL_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_MCAL_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED

/*****************************************************************************
**                             MCAL_TCLIB                                   **
******************************************************************************/

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_MCAL_TCLIB_START_SEC_VAR_INIT_32BIT_ASIL_B)
   #undef      IFX_MCAL_TCLIB_START_SEC_VAR_INIT_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_32BIT
#elif defined (IFX_MCAL_TCLIB_STOP_SEC_VAR_INIT_32BIT_ASIL_B)
   #undef      IFX_MCAL_TCLIB_STOP_SEC_VAR_INIT_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_32BIT

/*
 * To be used for global or static constants (32-bit)
 */

#elif defined (IFX_MCAL_TCLIB_START_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_MCAL_TCLIB_START_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_32BIT
#elif defined (IFX_MCAL_TCLIB_STOP_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_MCAL_TCLIB_STOP_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_32BIT

/*
 * To be used for mapping code
 */
#elif defined (IFX_MCAL_TCLIB_START_SEC_CODE_ASIL_B)
   #undef      IFX_MCAL_TCLIB_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_MCAL_TCLIB_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_MCAL_TCLIB_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*****************************************************************************
**                                 MCAL_TRAP                               **
******************************************************************************/

/*
 * To be used for mapping code 
 */
#elif defined (IFX_MCAL_TRAP_START_SEC_CODE_ASIL_B)
   #undef      IFX_MCAL_TRAP_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_MCAL_TRAP_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_MCAL_TRAP_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE


#elif defined (IFX_MCAL_TRAP_START_SEC_CODE_CPU0_TRAP_ASIL_B)
   #undef      IFX_MCAL_TRAP_START_SEC_CODE_CPU0_TRAP_ASIL_B
   #define   MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU0
#elif defined (IFX_MCAL_TRAP_STOP_SEC_CODE_CPU0_TRAP_ASIL_B)
   #undef      IFX_MCAL_TRAP_STOP_SEC_CODE_CPU0_TRAP_ASIL_B
   #define MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU0


#elif defined (IFX_MCAL_TRAP_START_SEC_CODE_CPU1_TRAP_ASIL_B)
   #undef     IFX_MCAL_TRAP_START_SEC_CODE_CPU1_TRAP_ASIL_B
   #define   MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU1
#elif defined (IFX_MCAL_TRAP_STOP_SEC_CODE_CPU1_TRAP_ASIL_B)
   #undef      IFX_MCAL_TRAP_STOP_SEC_CODE_CPU1_TRAP_ASIL_B
   #define MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU1


#elif defined (IFX_MCAL_TRAP_START_SEC_CODE_CPU2_TRAP_ASIL_B)
   #undef      IFX_MCAL_TRAP_START_SEC_CODE_CPU2_TRAP_ASIL_B
   #define   MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU2
#elif defined (IFX_MCAL_TRAP_STOP_SEC_CODE_CPU2_TRAP_ASIL_B)
   #undef      IFX_MCAL_TRAP_STOP_SEC_CODE_CPU2_TRAP_ASIL_B
   #define MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU2

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_MCAL_TRAP_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_MCAL_TRAP_START_SEC_VAR_32BIT_ASIL_B
   #define   DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_MCAL_TRAP_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_MCAL_TRAP_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT


/*****************************************************************************
**                       SFR CMP & CRC TESTS                                **
******************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_SFRTST_START_SEC_CODE_ASIL_B)
   #undef      IFX_SFRTST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_SFRTST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_SFRTST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for postbuild configuration (unspecified size)
 *
*/
#elif defined (IFX_SFRTST_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_SFRTST_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_SFRTST_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_SFRTST_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG
/*****************************************************************************
**                            REGACCPROTTST                                 **
******************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_REGACCPROTTST_START_SEC_CODE_ASIL_B)
   #undef      IFX_REGACCPROTTST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_REGACCPROTTST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_REGACCPROTTST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for global or static variables (8-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_REGACCPROTTST_START_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_REGACCPROTTST_START_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_REGACCPROTTST_STOP_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_REGACCPROTTST_STOP_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT

/*
 * To be used for global or static constants (32 bit size)
 *
 */
#elif defined (IFX_REGACCPROTTST_START_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_REGACCPROTTST_START_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_32BIT
#elif defined (IFX_REGACCPROTTST_STOP_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_REGACCPROTTST_STOP_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_32BIT

/*
 * To be used for global or static constants (8 bit size)
 *
 */
#elif defined (IFX_REGACCPROTTST_START_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_REGACCPROTTST_START_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_8BIT
#elif defined (IFX_REGACCPROTTST_STOP_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_REGACCPROTTST_STOP_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_8BIT

#elif defined (IFX_REGACCPROTTST_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_REGACCPROTTST_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_REGACCPROTTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_REGACCPROTTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
/*****************************************************************************
**                            DMATST                                 **
******************************************************************************/
#elif defined (IFX_DMATST_START_SEC_CODE_ASIL_B)
   #undef      IFX_DMATST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_DMATST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_DMATST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE
   /*
	* To be used for LinkTime configuration (unspecified size)
	*
   */
#elif defined (IFX_DMATST_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_DMATST_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_DMATST_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_DMATST_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG
 /*
  * To be used for global or static variables (32 byte size) that are
  * initialized after every reset (the normal case)
  */
#elif defined (IFX_DMATST_START_SEC_VAR_32BYTEALIGN_ASIL_B)
   #undef      IFX_DMATST_START_SEC_VAR_32BYTEALIGN_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BYTEALIGN
#elif defined (IFX_DMATST_STOP_SEC_VAR_32BYTEALIGN_ASIL_B)
   #undef      IFX_DMATST_STOP_SEC_VAR_32BYTEALIGN_ASIL_B
#define DEFAULT_STOP_SEC_VAR_32BYTEALIGN

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_DMATST_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_DMATST_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_DMATST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_DMATST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_DMATST_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_DMATST_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_DMATST_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_DMATST_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

   /*
	* To be used for global or static constants (8 bit size)
	*
	*/
#elif defined (IFX_DMATST_START_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_DMATST_START_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_8BIT
#elif defined (IFX_DMATST_STOP_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_DMATST_STOP_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_8BIT

/*****************************************************************************
**                            SPBTST                                 **
******************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_SPBTST_START_SEC_CODE_ASIL_B)
   #undef      IFX_SPBTST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_SPBTST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_SPBTST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE
/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_SPBTST_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_SPBTST_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_SPBTST_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_SPBTST_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG
   
/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_SPBTST_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_SPBTST_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_SPBTST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_SPBTST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */

#elif defined (IFX_SPBTST_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_SPBTST_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_SPBTST_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_SPBTST_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

/*
 * To be used for global or static constants (8 bit size)
 *
 */
#elif defined (IFX_SPBTST_START_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_SPBTST_START_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_8BIT
#elif defined (IFX_SPBTST_STOP_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_SPBTST_STOP_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_8BIT
   
#elif defined (IFX_SPBTST_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_SPBTST_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_32BIT
#elif defined (IFX_SPBTST_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_SPBTST_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_32BIT   

/*****************************************************************************
**                                 TRAPTST                                  **
******************************************************************************/
/*
 * Trap test trap vector section alignment.
 */

#elif defined (IFX_TRAPTST_START_SEC_CODE_ASIL_B)
   #undef      IFX_TRAPTST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_TRAPTST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_TRAPTST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */

#elif defined (IFX_TRAPTST_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_TRAPTST_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_TRAPTST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_TRAPTST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_TRAPTST_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_TRAPTST_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_TRAPTST_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_TRAPTST_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT
   
/*
 * To be used for global or static variables (8-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_TRAPTST_START_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_TRAPTST_START_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_TRAPTST_STOP_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_TRAPTST_STOP_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT   
  
/*
 * To be used for global or static constants (unspecified size)
 *
 */
#elif defined (IFX_TRAPTST_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_TRAPTST_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_TRAPTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_TRAPTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED   




/*****************************************************************************
**                         GENERIC TRAP HANDLER                             **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_GNRTRAPHANDLER_START_SEC_CODE_ASIL_B)
   #undef      IFX_GNRTRAPHANDLER_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_GNRTRAPHANDLER_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_GNRTRAPHANDLER_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

#elif defined (IFX_GNRTRAPHANDLER_START_SEC_TVT_CODE_ASIL_B)
   #undef      IFX_GNRTRAPHANDLER_START_SEC_TVT_CODE_ASIL_B
   #define   DEFAULT_MTL_START_SEC_TVT_CODE
#elif defined (IFX_GNRTRAPHANDLER_STOP_SEC_TVT_CODE_ASIL_B)
   #undef      IFX_GNRTRAPHANDLER_STOP_SEC_TVT_CODE_ASIL_B
   #define DEFAULT_MTL_STOP_SEC_TVT_CODE
   
 /*
 * To be used for global or static variables (unspecified size) that are
 * initialized with non-zero after every reset (the normal case)
 */
#elif defined (IFX_GNRTRAPHANDLER_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B)
   #undef IFX_GNRTRAPHANDLER_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED
#elif defined (IFX_GNRTRAPHANDLER_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B)
   #undef IFX_GNRTRAPHANDLER_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED



/*****************************************************************************
**                                 SMUTST                                   **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_SMUTST_START_SEC_CODE_ASIL_B)
   #undef      IFX_SMUTST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_SMUTST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_SMUTST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE
/*
 * To be used for global or static constants (8 bit size)
 *
 */
#elif defined (IFX_SMUTST_START_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_SMUTST_START_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_8BIT
#elif defined (IFX_SMUTST_STOP_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_SMUTST_STOP_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_8BIT

/*
 * To be used for postbuild configuration (unspecified size)
 *
*/
#elif defined (IFX_SMUTST_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_SMUTST_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_SMUTST_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_SMUTST_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

/*
 * To be used for global or static variables (8-bits size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_SMUTST_START_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_SMUTST_START_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_SMUTST_STOP_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_SMUTST_STOP_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT


/*****************************************************************************
**                                 IRTST                                   **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_IRTST_START_SEC_CODE_ASIL_B)
   #undef      IFX_IRTST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_IRTST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_IRTST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/* Mapping IR Interupt vector */
#elif defined (IFX_IRTST_START_SEC_IVT_CODE_ASIL_B)
   #undef      IFX_IRTST_START_SEC_IVT_CODE_ASIL_B
   #define   DEFAULT_IRTST_START_SEC_IVT_CODE
#elif defined (IFX_IRTST_STOP_SEC_IVT_CODE_ASIL_B)
   #undef      IFX_IRTST_STOP_SEC_IVT_CODE_ASIL_B
   #define DEFAULT_IRTST_STOP_SEC_IVT_CODE
   
/*
 * To be used for global or static variables (8-bits size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_IRTST_START_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_IRTST_START_SEC_VAR_8BIT_ASIL_B
   #define   DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_IRTST_STOP_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_IRTST_STOP_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT

/*
 * To be used for global or static variables (32-bits size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_IRTST_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_IRTST_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_IRTST_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_IRTST_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/

#elif defined (IFX_IRTST_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_IRTST_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_IRTST_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_IRTST_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

/*
 * To be used for global or static constants (unspecified size)
 *
 */
#elif defined (IFX_IRTST_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_IRTST_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_IRTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_IRTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with non-zero after every reset (the normal case)
 */
#elif defined (IFX_IRTST_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_IRTST_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_32BIT
#elif defined (IFX_IRTST_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_IRTST_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_32BIT

/*
 * To be used for global or static variables (8-bits size) that are
 * initialized with non-zero after every reset (the normal case)
 */

#elif defined (IFX_IRTST_START_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B)
   #undef      IFX_IRTST_START_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_8BIT
#elif defined (IFX_IRTST_STOP_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B)
   #undef      IFX_IRTST_STOP_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_8BIT


/*****************************************************************************
**                                 IOMTST                                   **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_IOMTST_START_SEC_CODE_ASIL_B)
   #undef      IFX_IOMTST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_IOMTST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_IOMTST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

  
/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_IOMTST_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_IOMTST_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_IOMTST_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_IOMTST_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG  
  
  
/*****************************************************************************
**                                 SWDG Stack                               **
******************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_SWDG_START_SEC_CODE_ASIL_B)
   #undef      IFX_SWDG_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_SWDG_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_SWDG_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */

#elif defined (IFX_SWDG_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_SWDG_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_SWDG_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_SWDG_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with a non-zero value after every reset (the normal case)
 */

#elif defined (IFX_SWDG_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B)
   #undef      IFX_SWDG_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED
#elif defined (IFX_SWDG_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B)
   #undef      IFX_SWDG_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with non-zero after every reset (the normal case)
 */
#elif defined (IFX_SWDG_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_SWDG_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_32BIT
#elif defined (IFX_SWDG_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_SWDG_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_32BIT



/*
 * To be used for global or static constants (unspecified size)
 *
 */
#elif defined (IFX_SWDG_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_SWDG_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_SWDG_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_SWDG_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED


/*
 * To be used for postbuild configuration (unspecified size)
 *
*/
#elif defined (IFX_SWDG_START_SEC_POSTBUILDCFG_ASIL_B)
   #undef      IFX_SWDG_START_SEC_POSTBUILDCFG_ASIL_B
   #define DEFAULT_START_SEC_POSTBUILDCFG
#elif defined (IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B)
   #undef      IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
   #define DEFAULT_STOP_SEC_POSTBUILDCFG  


/*
 * To be used for global or static variables (16-bit size) that are
 * initialized with non-zero after every reset (the normal case)
 */
#elif defined (IFX_SWDG_START_SEC_VAR_16BIT_ASIL_B)
   #undef      IFX_SWDG_START_SEC_VAR_16BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_16BIT   
#elif defined (IFX_SWDG_STOP_SEC_VAR_16BIT_ASIL_B)
   #undef      IFX_SWDG_STOP_SEC_VAR_16BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_16BIT   

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with non-zero after every reset (the normal case)
 */
#elif defined (IFX_SWDG_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_SWDG_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_SWDG_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_SWDG_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

/*****************************************************************************
**                                 WDG                                       **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc

 */
#elif defined (IFX_WDG_START_SEC_CODE_ASIL_B)
   #undef      IFX_WDG_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_WDG_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_WDG_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_WDG_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_WDG_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_WDG_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_WDG_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT


/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_WDG_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_WDG_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_WDG_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_WDG_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG


/*****************************************************************************
**                                 PMUECCEDC                                **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc

 */
#elif defined (IFX_PMUECCEDCTST_START_SEC_CODE_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_SEC_CODE_ASIL_B
   #define DEFAULT_START_SEC_NO_OPTIMIZED_CODE
#elif defined (IFX_PMUECCEDCTST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_NO_OPTIMIZED_CODE

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_PMUECCEDCTST_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_PMUECCEDCTST_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT
   
/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */

#elif defined (IFX_PMUECCEDCTST_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_PMUECCEDCTST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/*
 * To be used for global or static constants (unspecified size)
 *
 */
#elif defined (IFX_PMUECCEDCTST_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_PMUECCEDCTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED


/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_PMUECCEDCTST_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_PMUECCEDCTST_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

   /*
 * To be used for PF0 reserved test area (unspecified size)
 *
*/
#elif defined (IFX_PMUECCEDCTST_START_SEC_CONST_PF0_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_SEC_CONST_PF0_UNSPECIFIED_ASIL_B
   #define IFX_PMUECCEDCTST_START_PF0_UNSPECIFIED_ASIL_B
#elif defined (IFX_PMUECCEDCTST_STOP_SEC_CONST_PF0_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_SEC_CONST_PF0_UNSPECIFIED_ASIL_B
   #define IFX_PMUECCEDCTST_STOP_PF0_UNSPECIFIED_ASIL_B

/*
 * To be used for PF1 reserved test area (unspecified size)
 *
 */

#elif defined (IFX_PMUECCEDCTST_START_SEC_CONST_PF1_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_SEC_CONST_PF1_UNSPECIFIED_ASIL_B
   #define IFX_PMUECCEDCTST_START_PF1_UNSPECIFIED_ASIL_B
#elif defined (IFX_PMUECCEDCTST_STOP_SEC_CONST_PF1_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_SEC_CONST_PF1_UNSPECIFIED_ASIL_B
   #define IFX_PMUECCEDCTST_STOP_PF1_UNSPECIFIED_ASIL_B

/*
 * To be used for PF2 reserved test area (unspecified size)
 *
 */
#elif defined (IFX_PMUECCEDCTST_START_SEC_CONST_PF2_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_SEC_CONST_PF2_UNSPECIFIED_ASIL_B
   #define IFX_PMUECCEDCTST_START_PF2_UNSPECIFIED_ASIL_B
#elif defined (IFX_PMUECCEDCTST_STOP_SEC_CONST_PF2_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_SEC_CONST_PF2_UNSPECIFIED_ASIL_B
   #define IFX_PMUECCEDCTST_STOP_PF2_UNSPECIFIED_ASIL_B

/*
 * To be used for PF3 reserved test area (unspecified size)
 *
 */
#elif defined (IFX_PMUECCEDCTST_START_SEC_CONST_PF3_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_SEC_CONST_PF3_UNSPECIFIED_ASIL_B
   #define IFX_PMUECCEDCTST_START_PF3_UNSPECIFIED_ASIL_B
#elif defined (IFX_PMUECCEDCTST_STOP_SEC_CONST_PF3_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_SEC_CONST_PF3_UNSPECIFIED_ASIL_B
   #define IFX_PMUECCEDCTST_STOP_PF3_UNSPECIFIED_ASIL_B   
   
/*
 * PmuEccEdc test trap vector section alignment.
 */
#elif defined (IFX_PMUECCEDCTST_START_SEC_TVT_CODE_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_SEC_TVT_CODE_ASIL_B
   #define   DEFAULT_PMUECCEDCTST_START_SEC_TVT_CODE
#elif defined (IFX_PMUECCEDCTST_STOP_SEC_TVT_CODE_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_SEC_TVT_CODE_ASIL_B
   #define DEFAULT_PMUECCEDCTST_STOP_SEC_TVT_CODE
   
/* For copytable approach of copying functions from Pflash
to RAM during startup*/   
#elif defined (IFX_PMUECCEDCTST_START_SEC_RAM_CODE_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_SEC_RAM_CODE_ASIL_B
   #define   DEFAULT_PMUECCEDCTST_START_SEC_RAM_CODE
#elif defined (IFX_PMUECCEDCTST_STOP_SEC_RAM_CODE_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_SEC_RAM_CODE_ASIL_B
   #define DEFAULT_PMUECCEDCTST_STOP_SEC_RAM_CODE

/* Used by Sl_FlsErrPtrn.c */   
#elif defined (IFX_PMU_APPL_START_SEC_CODE_ASIL_B)
   #undef      IFX_PMU_APPL_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_NO_OPTIMIZED_CODE
#elif defined (IFX_PMU_APPL_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_PMU_APPL_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_NO_OPTIMIZED_CODE


#elif defined (IFX_PMU_APPL_START_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_PMU_APPL_START_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_32BIT
#elif defined (IFX_PMU_APPL_STOP_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_PMU_APPL_STOP_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_32BIT

/* For copytable approach of copying functions from Pflash
to RAM during startup*/   
#elif defined (IFX_PMU_APPL_START_SEC_RAM_CODE_ASIL_B)
   #undef      IFX_PMU_APPL_START_SEC_RAM_CODE_ASIL_B
   #define   DEFAULT_PMU_APPL_START_SEC_RAM_CODE
#elif defined (IFX_PMU_APPL_STOP_SEC_RAM_CODE_ASIL_B)
   #undef      IFX_PMU_APPL_STOP_SEC_RAM_CODE_ASIL_B
   #define DEFAULT_PMU_APPL_STOP_SEC_RAM_CODE
   
   #elif defined (IFX_PMU_APPL_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_PMU_APPL_START_SEC_VAR_32BIT_ASIL_B
   #define   DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_PMU_APPL_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_PMU_APPL_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with non-zero after every reset (the normal case)
 */
#elif defined (IFX_PMU_APPL_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMU_APPL_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED
#elif defined (IFX_PMU_APPL_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMU_APPL_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED

   


/*****************************************************************************
**                            LOCK STEP TST                                 **
******************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_LOCKSTEP_START_SEC_CODE_ASIL_B)
   #undef      IFX_LOCKSTEP_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_LOCKSTEP_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_LOCKSTEP_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for global or static constants (unspecified size)
 *
 */

#elif defined (IFX_LOCKSTEP_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_LOCKSTEP_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_LOCKSTEP_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_LOCKSTEP_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED


/*
 * To be used for global or static constants (32 bit size)
 *
 */
#elif defined (IFX_LOCKSTEP_START_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_LOCKSTEP_START_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_32BIT
#elif defined (IFX_LOCKSTEP_STOP_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_LOCKSTEP_STOP_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_32BIT

/*
 * To be used for global or static constants (8 bit size)
 *
 */
#elif defined (IFX_LOCKSTEP_START_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_LOCKSTEP_START_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_8BIT
#elif defined (IFX_LOCKSTEP_STOP_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_LOCKSTEP_STOP_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_8BIT


/*****************************************************************************
**                                 SRITST                                **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_SRITST_START_SEC_CODE_ASIL_B)
   #undef      IFX_SRITST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_SRITST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_SRITST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE


/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */

#elif defined (IFX_SRITST_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_SRITST_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_SRITST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_SRITST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_SRITST_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_SRITST_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_SRITST_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_SRITST_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

/*****************************************************************************
**                            LMUREGACCPROTTST                              **
******************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_LMUREGACCPROTTST_START_SEC_CODE_ASIL_B)
   #undef      IFX_LMUREGACCPROTTST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_LMUREGACCPROTTST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_LMUREGACCPROTTST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE


/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_LMUREGACCPROTTST_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_LMUREGACCPROTTST_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_LMUREGACCPROTTST_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_LMUREGACCPROTTST_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

/*
 * To be used for global or static variables (8-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_LMUREGACCPROTTST_START_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_LMUREGACCPROTTST_START_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_LMUREGACCPROTTST_STOP_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_LMUREGACCPROTTST_STOP_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT

/*
 * To be used for variables located to a specific SRAM:
*/
#elif defined (IFX_LMUREGACCPROTTST_START_SEC_VAR_32BIT_CPU0_DSPR)
   #undef      IFX_LMUREGACCPROTTST_START_SEC_VAR_32BIT_CPU0_DSPR
   #define DEFAULT_START_SEC_VAR_32BIT_CPU0_DSPR
#elif defined (IFX_LMUREGACCPROTTST_STOP_SEC_VAR_32BIT_CPU0_DSPR)
   #undef      IFX_LMUREGACCPROTTST_STOP_SEC_VAR_32BIT_CPU0_DSPR
   #define DEFAULT_STOP_SEC_VAR_32BIT_CPU0_DSPR
   
   
/*
 * To be used for variables located to a specific SRAM:
 */
#elif defined (IFX_LMUREGACCPROTTST_START_SEC_VAR_8BIT_CPU0_DSPR)
   #undef      IFX_LMUREGACCPROTTST_START_SEC_VAR_8BIT_CPU0_DSPR
   #define DEFAULT_START_SEC_VAR_8BIT_CPU0_DSPR
#elif defined (IFX_LMUREGACCPROTTST_STOP_SEC_VAR_8BIT_CPU0_DSPR)
   #undef      IFX_LMUREGACCPROTTST_STOP_SEC_VAR_8BIT_CPU0_DSPR
   #define DEFAULT_STOP_SEC_VAR_8BIT_CPU0_DSPR
/*****************************************************************************
**                                 LMUBUSMPULFM                             **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_LMUBUSMPULFM_START_SEC_CODE_ASIL_B)
   #undef      IFX_LMUBUSMPULFM_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_LMUBUSMPULFM_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_LMUBUSMPULFM_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_LMUBUSMPULFM_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_LMUBUSMPULFM_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_LMUBUSMPULFM_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_LMUBUSMPULFM_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   

   
/*
 * To be used for global or static constants (32 bit size)
 *
 */
#elif defined (IFX_LMUBUSMPULFM_START_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_LMUBUSMPULFM_START_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_32BIT
#elif defined (IFX_LMUBUSMPULFM_STOP_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_LMUBUSMPULFM_STOP_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_32BIT

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_LMUBUSMPULFM_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_LMUBUSMPULFM_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_LMUBUSMPULFM_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_LMUBUSMPULFM_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT


/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_LMUBUSMPULFM_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_LMUBUSMPULFM_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_LMUBUSMPULFM_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_LMUBUSMPULFM_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG
   
   
   
/*
 * To be used for global or static constants (unspecified size)
 *
 */

#elif defined (IFX_LMUBUSMPULFM_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_LMUBUSMPULFM_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_LMUBUSMPULFM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_LMUBUSMPULFM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED


/*
 * To be used for variables located to a specific SRAM:
 */
#elif defined (IFX_LMUBUSMPULFM_START_SEC_VAR_32BIT_CPU0_DSPR)
   #undef      IFX_LMUBUSMPULFM_START_SEC_VAR_32BIT_CPU0_DSPR
   #define DEFAULT_START_SEC_VAR_32BIT_CPU0_DSPR
#elif defined (IFX_LMUBUSMPULFM_STOP_SEC_VAR_32BIT_CPU0_DSPR)
   #undef      IFX_LMUBUSMPULFM_STOP_SEC_VAR_32BIT_CPU0_DSPR
   #define DEFAULT_STOP_SEC_VAR_32BIT_CPU0_DSPR
   
   
/*
 * To be used for variables located to a specific SRAM:
 */
#elif defined (IFX_LMUBUSMPULFM_START_SEC_VAR_8BIT_CPU0_DSPR)
   #undef      IFX_LMUBUSMPULFM_START_SEC_VAR_8BIT_CPU0_DSPR
   #define DEFAULT_START_SEC_VAR_8BIT_CPU0_DSPR
#elif defined (IFX_LMUBUSMPULFM_STOP_SEC_VAR_8BIT_CPU0_DSPR)
   #undef      IFX_LMUBUSMPULFM_STOP_SEC_VAR_8BIT_CPU0_DSPR
   #define DEFAULT_STOP_SEC_VAR_8BIT_CPU0_DSPR
  


/*****************************************************************************
**                            FCETST                                        **
******************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_FCETST_START_SEC_CODE_ASIL_B)
   #undef      IFX_FCETST_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_FCETST_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_FCETST_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE


/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with non-zero after every reset (the normal case)
 */
#elif defined (IFX_FCETST_START_SEC_CONST_UNSPECIFIED_ASIL_B )
   #undef      IFX_FCETST_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define     DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_FCETST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_FCETST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define     DEFAULT_STOP_SEC_CONST_UNSPECIFIED

/*
 * To be used for global or static variables (8-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_FCETST_START_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_FCETST_START_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_FCETST_STOP_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_FCETST_STOP_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT

/*
 * To be used for global or static constants (32 bit size)
 *
 */
#elif defined (IFX_FCETST_START_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_FCETST_START_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_32BIT
#elif defined (IFX_FCETST_STOP_SEC_CONST_32BIT_ASIL_B)
   #undef      IFX_FCETST_STOP_SEC_CONST_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_32BIT

/*
 * To be used for global or static constants (8 bit size)
 *
 */
#elif defined (IFX_FCETST_START_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_FCETST_START_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_8BIT
#elif defined (IFX_FCETST_STOP_SEC_CONST_8BIT_ASIL_B)
   #undef      IFX_FCETST_STOP_SEC_CONST_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_8BIT

/*
 * To be used for global or static constants (16 bit size)
 *
 */
#elif defined (IFX_FCETST_START_SEC_CONST_16BIT_ASIL_B)
   #undef      IFX_FCETST_START_SEC_CONST_16BIT_ASIL_B
   #define DEFAULT_START_SEC_CONST_16BIT
#elif defined (IFX_FCETST_STOP_SEC_CONST_16BIT_ASIL_B)
   #undef      IFX_FCETST_STOP_SEC_CONST_16BIT_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_16BIT


/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
 #elif defined (IFX_FCETST_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_FCETST_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_FCETST_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_FCETST_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

/*****************************************************************************
**                                 PFLASH MONITOR                           **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc

 */
#elif defined (IFX_PFLASHMON_START_SEC_CODE_ASIL_B)
   #undef      IFX_PFLASHMON_START_SEC_CODE_ASIL_B
   #define DEFAULT_START_SEC_NO_OPTIMIZED_CODE
#elif defined (IFX_PFLASHMON_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_PFLASHMON_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_NO_OPTIMIZED_CODE
   
/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_PFLASHMON_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_PFLASHMON_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_PFLASHMON_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_PFLASHMON_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */

#elif defined (IFX_PFLASHMON_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_PFLASHMON_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_PFLASHMON_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_PFLASHMON_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/*
 * To be used for global or static constants (unspecified size)
 *
 */
#elif defined (IFX_PFLASHMON_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_PFLASHMON_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_PFLASHMON_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_PFLASHMON_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED


/*
 * To be used for LinkTime configuration (unspecified size)
 *
*/
#elif defined (IFX_PFLASHMON_START_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_PFLASHMON_START_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_START_SEC_LINKTIMECFG
#elif defined (IFX_PFLASHMON_STOP_SEC_LINKTIMECFG_ASIL_B)
   #undef      IFX_PFLASHMON_STOP_SEC_LINKTIMECFG_ASIL_B
   #define DEFAULT_STOP_SEC_LINKTIMECFG

/* For copytable approach of copying functions from Pflash
to RAM during startup*/
#elif defined (IFX_PFLASHMONTST_START_SEC_RAM_CODE_ASIL_B)
   #undef      IFX_PFLASHMONTST_START_SEC_RAM_CODE_ASIL_B
   #define   DEFAULT_PFLASHMONTST_START_SEC_RAM_CODE
#elif defined (IFX_PFLASHMONTST_STOP_SEC_RAM_CODE_ASIL_B)
   #undef      IFX_PFLASHMONTST_STOP_SEC_RAM_CODE_ASIL_B
   #define DEFAULT_PFLASHMONTST_STOP_SEC_RAM_CODE
   
/*****************************************************************************
**                                 APPLICATION                              **
******************************************************************************/

/*
 * To be used for global or static constants (unspecified size)
 *
 */
#elif defined (IFX_APPL_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_APPL_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#elif defined (IFX_APPL_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_APPL_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED

/*
 * To be used for global or static variables (8-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_APPL_START_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_APPL_START_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_8BIT
#elif defined (IFX_APPL_STOP_SEC_VAR_8BIT_ASIL_B)
   #undef      IFX_APPL_STOP_SEC_VAR_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_8BIT

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */
#elif defined (IFX_APPL_START_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_APPL_START_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_32BIT
#elif defined (IFX_APPL_STOP_SEC_VAR_32BIT_ASIL_B)
   #undef      IFX_APPL_STOP_SEC_VAR_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_32BIT

/*
 * To be used for global or static variables (32-bit size) that are
 * initialized with non-zero after every reset (the normal case)
 */

#elif defined (IFX_APPL_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_APPL_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_32BIT
#elif defined (IFX_APPL_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B)
   #undef      IFX_APPL_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_32BIT

/*
 * To be used for global or static variables (8-bit size) that are
 * initialized with non-zero after every reset (the normal case)
 */

#elif defined (IFX_APPL_START_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B)
   #undef      IFX_APPL_START_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_8BIT
#elif defined (IFX_APPL_STOP_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B)
   #undef      IFX_APPL_STOP_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_8BIT

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with non-zero after every reset (the normal case)
 */

#elif defined (IFX_APPL_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B)
   #undef      IFX_APPL_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED
#elif defined (IFX_APPL_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B)
   #undef      IFX_APPL_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED

/*
 * To be used for global or static variables (unspecified size) that are
 * initialized with zero (= cleared) after every reset (the normal case)
 */

#elif defined (IFX_APPL_START_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_APPL_START_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (IFX_APPL_STOP_SEC_VAR_UNSPECIFIED_ASIL_B)
   #undef      IFX_APPL_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED


/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (IFX_APPL_START_SEC_CODE_ASIL_B)
   #undef      IFX_APPL_START_SEC_CODE_ASIL_B
   #define   DEFAULT_START_SEC_CODE
#elif defined (IFX_APPL_STOP_SEC_CODE_ASIL_B)
   #undef      IFX_APPL_STOP_SEC_CODE_ASIL_B
   #define DEFAULT_STOP_SEC_CODE
   


/*******************************************************************************
**                            BMI_HEADER                                      **
*******************************************************************************/
#elif defined (IFX_BMD_HDR_START_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_BMD_HDR_START_SEC_CONST_UNSPECIFIED_ASIL_B
   #define   BMD_HDR_START_SEC_BMI_HEADER
#elif defined (IFX_BMD_HDR_STOP_SEC_CONST_UNSPECIFIED_ASIL_B)
   #undef      IFX_BMD_HDR_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
   #define   BMD_HDR_STOP_SEC_BMI_HEADER
  
   
#else
  #error "Ifx_MemMap.h: No valid section define found"
#endif  /* START_WITH_IF */


/*******************************************************************************
**                      Default section mapping                               **
*******************************************************************************/
/* general start of #elif chain whith #if                                     */
#if defined (START_WITH_IF)

/*****************************************************************************
**                                 ROM CONFIG DATA                          **
******************************************************************************/
/*
Memory Section of Post Build Configuration
*/

#elif defined (DEFAULT_START_SEC_POSTBUILDCFG)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG
   #if defined __TASKING__
   #pragma section farrom="CONFIGURATION_PB"
   #elif defined __GNUC__ 
   #pragma section ".rodata.SafeTlib_CONFIGURATION_PB" a
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CONFIGURATION_PB" far-absolute R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG
   #if defined __TASKING__
   #pragma section farrom restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_LINKTIMECFG)
   #undef      DEFAULT_START_SEC_LINKTIMECFG
   #if defined __TASKING__
   #pragma section farrom="CONFIGURATION_LT"
   #elif defined __GNUC__ 
   #pragma section ".rodata.SafeTlib_CONFIGURATION_LT" a
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CONFIGURATION_LT" far-absolute R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_LINKTIMECFG)
   #undef      DEFAULT_STOP_SEC_LINKTIMECFG
   #if defined __TASKING__
   #pragma section farrom restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
/*
Memory Section of Ecum Post Build Configuration
*/
#elif defined (DEFAULT_START_SEC_ECUM_POSTBUILDCFG)
   #undef      DEFAULT_START_SEC_ECUM_POSTBUILDCFG
   #if defined __TASKING__
   #pragma section farrom="CONFIGURATION_ECUM_PB"
   #elif defined __GNUC__ 
   #pragma section ".rodata.SafeTlib_CONFIGURATION_ECUM_PB" a
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CONFIGURATION_ECUM_PB" far-absolute R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_ECUM_POSTBUILDCFG)
   #undef      DEFAULT_STOP_SEC_ECUM_POSTBUILDCFG
   #if defined __TASKING__
   #pragma section farrom restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
   
#elif defined (DEFAULT_START_SEC_VAR_CONST_32BYTEALIGN)
   #undef      DEFAULT_START_SEC_VAR_CONST_32BYTEALIGN
   #if defined __TASKING__
   #pragma section farrom="MTL_SRI_EDC_BUSERROR_TST"
   #pragma align 32
   #elif defined __GNUC__ 
   #pragma section ".rodata.SafeTlib_MTL_SRI_EDC_BUSERROR_TST" a 32
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.MTL_SRI_EDC_BUSERROR_TST" far-absolute R
   #pragma align_variables 32
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_CONST_32BYTEALIGN)
   #undef      DEFAULT_STOP_SEC_VAR_CONST_32BYTEALIGN
   #if defined __TASKING__
   #pragma align restore
   #pragma section farrom restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
   
#elif defined (IFX_PMUECCEDCTST_START_PF0_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_PF0_UNSPECIFIED_ASIL_B
   #if defined __TASKING__
   #pragma section farrom="MTL_PMU_ECC_EDC_TST_PF0"
   #pragma align 32
   #pragma protect on
   #elif defined __GNUC__ 
   #pragma section ".PF.MTL_PMU_ECC_EDC_TST_PF0" a 32
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.MTL_PMU_ECC_EDC_TST_PF0" far-absolute R
   #pragma align_variables 32
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (IFX_PMUECCEDCTST_STOP_PF0_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_PF0_UNSPECIFIED_ASIL_B
   #if defined __TASKING__
   #pragma protect restore
   #pragma align restore
   #pragma section farrom restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (IFX_PMUECCEDCTST_START_PF1_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_PF1_UNSPECIFIED_ASIL_B
   #if defined __TASKING__
   #pragma section farrom="MTL_PMU_ECC_EDC_TST_PF1"
   #pragma align 32
   #pragma protect on
   #elif defined __GNUC__ 
   #pragma section ".PF.MTL_PMU_ECC_EDC_TST_PF1" a 32
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.MTL_PMU_ECC_EDC_TST_PF1" far-absolute R
   #pragma align_variables 32
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (IFX_PMUECCEDCTST_STOP_PF1_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_PF1_UNSPECIFIED_ASIL_B
   #if defined __TASKING__
   #pragma protect restore
   #pragma align restore
   #pragma section farrom restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (IFX_PMUECCEDCTST_START_PF2_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_PF2_UNSPECIFIED_ASIL_B
   #ifdef __TASKING__
   #pragma section farrom="MTL_PMU_ECC_EDC_TST_PF2"
   #pragma align 32
   #pragma protect on
   #elif defined __GNUC__
   #pragma section ".rodata.SafeTlib_MTL_PMU_ECC_EDC_TST_PF2" a 32
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.MTL_PMU_ECC_EDC_TST_PF2" far-absolute R
   #pragma align_variables 32
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (IFX_PMUECCEDCTST_STOP_PF2_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_PF2_UNSPECIFIED_ASIL_B
   #ifdef __TASKING__
   #pragma protect restore
   #pragma align restore
   #pragma section farrom restore
   #elif defined __GNUC__
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (IFX_PMUECCEDCTST_START_PF3_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_START_PF3_UNSPECIFIED_ASIL_B
   #ifdef __TASKING__
   #pragma section farrom="MTL_PMU_ECC_EDC_TST_PF3"
   #pragma align 32
   #pragma protect on
   #elif defined __GNUC__
   #pragma section ".rodata.SafeTlib_MTL_PMU_ECC_EDC_TST_PF3" a 32
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.MTL_PMU_ECC_EDC_TST_PF3" far-absolute R
   #pragma align_variables 32
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (IFX_PMUECCEDCTST_STOP_PF3_UNSPECIFIED_ASIL_B)
   #undef      IFX_PMUECCEDCTST_STOP_PF3_UNSPECIFIED_ASIL_B
   #ifdef __TASKING__
   #pragma protect restore
   #pragma align restore
   #pragma section farrom restore
   #elif defined __GNUC__
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
   
#elif defined (LIN_17_START_LOADABLECFG)
   #undef   LIN_17_START_LOADABLECFG
   #if defined __TASKING__
   #pragma section farrom="LIN_LOADABLE_CHANCFG"
   #elif defined __GNUC__ 
   #pragma section ".rodata.LIN_LOADABLE_CHANCFG" a
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".LIN_LOADABLE_CHANCFG" far-absolute R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (LIN_17_STOP_LOADABLECFG)
   #undef   LIN_17_STOP_LOADABLECFG
   #if defined __TASKING__
   #pragma section farrom restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

/*****************************************************************************
**                                 ROM CODE                                 **
******************************************************************************/
#elif defined (DEFAULT_START_SEC_CODE)
   #undef      DEFAULT_START_SEC_CODE
   #if defined __TASKING__
   #pragma section code "DEFAULT_CODE_ROM"
   #elif defined __GNUC__ 
    /*To provide 4 byte alignment for the functions */
   #pragma section ".text.SafeTlib_DEFAULT_CODE_ROM" ax 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.DEFAULT_CODE_ROM" RX
   #pragma align_functions 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE)
   #undef      DEFAULT_STOP_SEC_CODE
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (SBST_CALLBACK_START_SEC_CODE)
   #undef      SBST_CALLBACK_START_SEC_CODE
   #if defined __TASKING__
   #pragma section code "SBST_CALLBACK_CODE_ROM"
   #elif defined __GNUC__ 
    /*To provide 4 byte alignment for the functions */
   #pragma section ".text.SafeTlib_SBST_CALLBACK_CODE_ROM" ax 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.SBST_CALLBACK_CODE_ROM" RX
   #pragma align_functions 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (SBST_CALLBACK_STOP_SEC_CODE)
   #undef      SBST_CALLBACK_STOP_SEC_CODE
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
  /* Zero optimization is applicable only for GNU 
   * (For tasking, zero optimization sections can be added for 
   * individual functions, same is not possible for GNU)
  */
#elif defined (DEFAULT_START_SEC_NO_OPTIMIZED_CODE)
   #undef      DEFAULT_START_SEC_NO_OPTIMIZED_CODE
   #if defined __TASKING__
   #pragma section code "DEFAULT_CODE_ROM"
   #elif defined __GNUC__ 
  /*To provide 4 byte alignment for the functions since O3 optimization does
   * not ensure 4 byte alignment for functions
  */
   #pragma section ".text.SafeTlib_DEFAULT_CODE_ROM" ax 4
    /* Optimization should be disabled */
   #pragma GCC optimize "O0"
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.DEFAULT_CODE_ROM" RX
   #pragma align_functions 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_NO_OPTIMIZED_CODE)
   #undef      DEFAULT_STOP_SEC_NO_OPTIMIZED_CODE
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma GCC reset_options
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_START_SEC_IVT_CODE)
   #undef      DEFAULT_START_SEC_IVT_CODE
   #if defined __TASKING__
   #pragma section code "inttab"
   #elif defined __GNUC__ 
   #pragma section ".inttab" ax 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".inttab" X
   #pragma align_functions 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_IVT_CODE)
   #undef      DEFAULT_STOP_SEC_IVT_CODE
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE X
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_IRTST_START_SEC_IVT_CODE)
   #undef      DEFAULT_IRTST_START_SEC_IVT_CODE
   #if defined __TASKING__
   #pragma section code "IRTst_IRTab.IRTst_inttab"
   #elif defined __GNUC__ 
   #pragma section ".text.SafeTlib_IRTst_IRTab.IRTst_inttab" ax
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.IRTst_IRTab.IRTst_inttab" X
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_IRTST_STOP_SEC_IVT_CODE)
   #undef      DEFAULT_IRTST_STOP_SEC_IVT_CODE
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE X
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
   
#elif defined (DEFAULT_MTL_START_SEC_TVT_CODE)
   #undef      DEFAULT_MTL_START_SEC_TVT_CODE
   #ifdef __TASKING__
   #pragma section code "Mtl_TrapTab.Stl_TrapVectors"
   #elif defined __GNUC__
   #pragma section ".text.SafeTlib_Mtl_TrapTab.Stl_TrapVectors" ax 256
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.Mtl_TrapTab.Stl_TrapVectors" X
   #pragma align_functions 256
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_MTL_STOP_SEC_TVT_CODE)
   #undef      DEFAULT_MTL_STOP_SEC_TVT_CODE
   #ifdef __TASKING__
   #pragma section code restore
   #elif defined __GNUC__
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE X
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif  

#elif defined (DEFAULT_PMUECCEDCTST_START_SEC_TVT_CODE)
   #undef      DEFAULT_PMUECCEDCTST_START_SEC_TVT_CODE
   #if defined __TASKING__
   #pragma section code "PMUECCEDCTST_TVT_RAMCODE"
   #elif defined __GNUC__ 
   #pragma section ".SafeTlib_PMUECCEDCTST_TVT_RAMCODE" ax 256
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".PMUECCEDCTST_TVT_RAMCODE" far-absolute RX
   #pragma align_functions 256
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_PMUECCEDCTST_STOP_SEC_TVT_CODE)
   #undef      DEFAULT_PMUECCEDCTST_STOP_SEC_TVT_CODE
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
   
#elif defined (DEFAULT_PMUECCEDCTST_START_SEC_RAM_CODE)
   #undef      DEFAULT_PMUECCEDCTST_START_SEC_RAM_CODE
   #if defined __TASKING__
   #pragma section code "PFLASH_MON_ECCEDC_RAMCODE"
   #elif defined __GNUC__
   #pragma section ".SafeTlib_PFLASH_MON_ECCEDC_RAMCODE" ax 4
   /* As per the Design, Helper functions should not be optimized to prevent the compiler from merging code of functions under this section with other code */
   #pragma GCC optimize "O0"
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".PFLASH_MON_ECCEDC_RAMCODE" far-absolute RX
   #pragma align_functions 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_PMUECCEDCTST_STOP_SEC_RAM_CODE)
   #undef      DEFAULT_PMUECCEDCTST_STOP_SEC_RAM_CODE
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__
   #pragma section
   #pragma GCC reset_options
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif   

#elif defined (DEFAULT_PFLASHMONTST_START_SEC_RAM_CODE)
   #undef      DEFAULT_PFLASHMONTST_START_SEC_RAM_CODE
   #if defined __TASKING__
   #pragma section code "PFLASH_MON_ECCEDC_RAMCODE"
   #elif defined __GNUC__
   #pragma section ".SafeTlib_PFLASH_MON_ECCEDC_RAMCODE" ax 4
   /* As per the Design, Helper functions should not be optimized to prevent the compiler from merging code of functions under this section with other code */
   #pragma GCC optimize "O0"
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma noinline PflashMonTst_lClearAlarms,PflashMonTst_lWaitForValidBit 
   #pragma section CODE ".PFLASH_MON_ECCEDC_RAMCODE" far-absolute RX
   #pragma align_functions 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_PFLASHMONTST_STOP_SEC_RAM_CODE)
   #undef      DEFAULT_PFLASHMONTST_STOP_SEC_RAM_CODE
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__
   #pragma section
   #pragma GCC reset_options
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif   
   
#elif defined (DEFAULT_PMU_APPL_START_SEC_RAM_CODE)
   #undef      DEFAULT_PMU_APPL_START_SEC_RAM_CODE
   #if defined __TASKING__
   #pragma section code "PFLASH_MON_ECCEDC_RAMCODE"
   #elif defined __GNUC__
   #pragma section ".SafeTlib_PFLASH_MON_ECCEDC_RAMCODE" ax 4
   /* As per the Design, Helper functions should not be optimized to prevent the compiler from merging code of functions under this section with other code */
   #pragma GCC optimize "O0"
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma noinline Sl_lReadFlashPage
   #pragma section CODE ".PFLASH_MON_ECCEDC_RAMCODE" far-absolute RX
   #pragma align_functions 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_PMU_APPL_STOP_SEC_RAM_CODE)
   #undef      DEFAULT_PMU_APPL_STOP_SEC_RAM_CODE
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__
   #pragma section
   #pragma GCC reset_options
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
   
#elif defined (DEFAULT_START_SEC_8BYTE_ALIGN_CODE)
   #undef      DEFAULT_START_SEC_8BYTE_ALIGN_CODE
   #if defined __TASKING__
   #pragma section code "CpuMpuExAccess"
   #elif defined __GNUC__ 
   #pragma section ".text.SafeTlib_CpuMpuExAccess" ax 8
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CpuMpuExAccess" X
   #pragma align_functions 8
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_8BYTE_ALIGN_CODE)
   #undef      DEFAULT_STOP_SEC_8BYTE_ALIGN_CODE
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE X
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
   
#elif defined (PWM_17_START_SEC_NOTIFICATION)
   #undef      PWM_17_START_SEC_NOTIFICATION
   #if defined __TASKING__
   #pragma section code "PWM_NOTIFICATION"
   #elif defined __GNUC__ 
   #pragma section ".text.PWM_NOTIFICATION" ax
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".PWM_NOTIFICATION" RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (PWM_17_STOP_SEC_NOTIFICATION)
   #undef      PWM_17_STOP_SEC_NOTIFICATION
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (ICU_17_START_SEC_NOTIFICATION)
   #undef      ICU_17_START_SEC_NOTIFICATION
   #if defined __TASKING__
   #pragma section code "ICU_NOTIFICATION"
   #elif defined __GNUC__ 
   #pragma section ".text.ICU_NOTIFICATION" ax
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".ICU_NOTIFICATION" RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (ICU_17_STOP_SEC_NOTIFICATION)
   #undef      ICU_17_STOP_SEC_NOTIFICATION
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (WDG_17_START_SEC_NOTIFICATION)
   #undef      WDG_17_START_SEC_NOTIFICATION
   #if defined __TASKING__
   #pragma section code "WDG_NOTIFICATION"
   #elif defined __GNUC__ 
   #pragma section ".text.WDG_NOTIFICATION" ax
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".WDG_NOTIFICATION" RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (WDG_17_STOP_SEC_NOTIFICATION)
   #undef      WDG_17_STOP_SEC_NOTIFICATION
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (STM_START_SEC_NOTIFICATION)
   #undef      STM_START_SEC_NOTIFICATION
   #if defined __TASKING__
   #pragma section code "STM_NOTIFICATION"
   #elif defined __GNUC__ 
   #pragma section ".text.STM_NOTIFICATION" ax
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".STM_NOTIFICATION" RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (STM_STOP_SEC_NOTIFICATION)
   #undef      STM_STOP_SEC_NOTIFICATION
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (GPT_START_SEC_NOTIFICATION)
   #undef      GPT_START_SEC_NOTIFICATION
   #if defined __TASKING__
   #pragma section code "GPT_NOTIFICATION"
   #elif defined __GNUC__ 
   #pragma section ".text.GPT_NOTIFICATION" ax
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".GPT_NOTIFICATION" RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (GPT_STOP_SEC_NOTIFICATION)
   #undef      GPT_STOP_SEC_NOTIFICATION
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

/* WR Section: Fls Loader Write API placed here */
#elif defined (FLSLOADER_START_WRITE_API)
   #undef     FLSLOADER_START_WRITE_API
   #if defined __TASKING__
   #pragma section code "FLSLOADER_WRITE_SOURCE"
   #elif defined __GNUC__ 
   #pragma section ".text.FLSLOADER_WRITE_SOURCE" ax
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FLSLOADER_WRITE_SOURCE" RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (FLSLOADER_STOP_WRITE_API)
   #undef     FLSLOADER_STOP_WRITE_API
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
/* ER Section: Fls Loader Erase API placed here */
#elif defined (FLSLOADER_START_ERASE_API)
   #undef     FLSLOADER_START_ERASE_API
   #if defined __TASKING__
   #pragma section code "FLSLOADER_ERASE_SOURCE"
   #elif defined __GNUC__ 
   #pragma section ".text.FLSLOADER_ERASE_SOURCE" ax
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FLSLOADER_ERASE_SOURCE" RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (FLSLOADER_STOP_ERASE_API)
   #undef     FLSLOADER_STOP_ERASE_API
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

/* ---The following sections attempt to locate FLS Write and Erase command-----
   ---Cycles in an order. It is essential to enforce the correct sequence------
   ---so that the FLS driver can perform as requird.-------------------------*/
#elif defined (FLS_17_START_SEC_SPL_CODE_WRITECMD_BEGIN_API)
   #undef     FLS_17_START_SEC_SPL_CODE_WRITECMD_BEGIN_API
   #if defined __TASKING__
   #pragma section code "FLS_AC_WRITE_SOURCE"
   #pragma optimize R
   #elif defined __GNUC__ 
   #pragma section ".text.FLS_AC_WRITE_SOURCE" ax
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FLS_AC_WRITE_SOURCE" far-absolute RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (FLS_17_STOP_SEC_SPL_CODE_WRITECMD_BEGIN_API)
   #undef     FLS_17_STOP_SEC_SPL_CODE_WRITECMD_BEGIN_API
   #if defined __TASKING__
   #pragma section code restore
   #pragma endoptimize
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (FLS_17_START_SEC_SPL_CODE_ERASECMD_BEGIN_API)
   #undef     FLS_17_START_SEC_SPL_CODE_ERASECMD_BEGIN_API
   #if defined __TASKING__
   #pragma section code "FLS_AC_ERASE_SOURCE"
   #pragma optimize R
   #elif defined __GNUC__ 
   #pragma section ".text.FLS_AC_ERASE_SOURCE" ax
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FLS_AC_ERASE_SOURCE" far-absolute RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (FLS_17_STOP_SEC_SPL_CODE_ERASECMD_BEGIN_API)
   #undef     FLS_17_STOP_SEC_SPL_CODE_ERASECMD_BEGIN_API
   #if defined __TASKING__
   #pragma section code restore
   #pragma endoptimize
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (FEE_START_JOBENDNOTIF)
   #undef   FEE_START_JOBENDNOTIF
   #if defined __TASKING__
   #pragma section code "FEE_JOBENDNOTIF_CODE"
   #elif defined __GNUC__ 
   #pragma section ".text.FEE_JOBENDNOTIF_CODE" ax
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FEE_JOBENDNOTIF_CODE" RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (FEE_STOP_JOBENDNOTIF)
   #undef   FEE_STOP_JOBENDNOTIF
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (FEE_START_JOBERRNOTIF)
   #undef   FEE_START_JOBERRNOTIF
   #if defined __TASKING__
   #pragma section code "FEE_JOBERRNOTIF_CODE"
   #elif defined __GNUC__ 
   #pragma section ".text.FEE_JOBERRNOTIF_CODE" ax
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FEE_JOBERRNOTIF_CODE" RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (FEE_STOP_JOBERRNOTIF)
   #undef   FEE_STOP_JOBERRNOTIF
   #if defined __TASKING__
   #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif



/*****************************************************************************
**                            RAM variables not initialized                 **
******************************************************************************/
#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #if defined __TASKING__
   #pragma section farnoclear="DEFAULT_RAM_NOINIT_8BIT"
   #pragma noclear
   #elif defined __GNUC__ 
   #pragma section ".bss.SafeTlib_DEFAULT_RAM_NOINIT_8BIT" aw 1
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in initialized section for windriver*/
   #pragma section DATA ".error" ".bss.DEFAULT_RAM_NOINIT_8BIT" RW 
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #if defined __TASKING__
   #pragma clear
   #pragma section farnoclear restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #if defined __TASKING__
   #pragma section farnoclear="DEFAULT_RAM_NOINIT_16BIT"
   #pragma noclear
   #pragma align 4
   #elif defined __GNUC__ 
   #pragma section ".bss.SafeTlib_DEFAULT_RAM_NOINIT_16BIT" aw 2
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in initialized section for windriver*/
   #pragma section DATA ".error" ".bss.DEFAULT_RAM_NOINIT_16BIT" RW
   #pragma align_variables 2
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #if defined __TASKING__
   #pragma align restore
   #pragma clear
   #pragma section farnoclear restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #if defined __TASKING__
   #pragma section farnoclear="DEFAULT_RAM_NOINIT_32BIT"
   #pragma noclear
   #pragma align 4
   #elif defined __GNUC__ 
   #pragma section ".bss.SafeTlib_DEFAULT_RAM_NOINIT_32BIT" aw 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in initialized section for windriver*/
   #pragma section DATA ".error" ".bss.DEFAULT_RAM_NOINIT_32BIT" RW
   #pragma align_variables 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #if defined __TASKING__
   #pragma align restore
   #pragma clear
   #pragma section farnoclear restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #if defined __TASKING__
   #pragma section farnoclear="DEFAULT_RAM_NOINIT_UNSPECIFIED"
   #pragma noclear
   #elif defined __GNUC__ 
   #pragma section ".bss.SafeTlib_DEFAULT_RAM_NOINIT_UNSPECIFIED" aw
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in initialized section for windriver*/
   #pragma section DATA ".error" ".bss.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #if defined __TASKING__
   #pragma clear
   #pragma section farnoclear restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

/*****************************************************************************
**              RAM variables initialized from ROM on reset                 **
** These variables memory locations will be out in lc_cp table created      **
** by the linker.                                                           **
******************************************************************************/

#elif defined (DEFAULT_START_SEC_VAR_8BIT)
   #undef      DEFAULT_START_SEC_VAR_8BIT
   #if defined __TASKING__
   #pragma section farbss="DEFAULT_RAM_8BIT"
   #elif defined __GNUC__ 
   #pragma section ".data.SafeTlib_DEFAULT_RAM_8BIT" aw 1
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*.data will be used for Initialized data and .bss for uninitialized data*/
   #pragma section DATA ".data.DEFAULT_RAM_8BIT" ".bss.DEFAULT_RAM_8BIT" far-absolute RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT
   #if defined __TASKING__
   #pragma section farbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_16BIT)
   #undef      DEFAULT_START_SEC_VAR_16BIT
   #if defined __TASKING__
   #pragma section farbss="DEFAULT_RAM_16BIT"
   #pragma align 4
   #elif defined __GNUC__ 
   #pragma section ".data.SafeTlib_DEFAULT_RAM_16BIT" aw 2
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*.data will be used for Init data and .bss for uninit data*/
   #pragma section DATA ".data.DEFAULT_RAM_16BIT" ".bss.DEFAULT_RAM_16BIT" far-absolute RW
   #pragma align_variables 2
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT
   #if defined __TASKING__
   #pragma align restore
   #pragma section farbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_32BIT)
   #undef      DEFAULT_START_SEC_VAR_32BIT
   #if defined __TASKING__
   #pragma section farbss="DEFAULT_RAM_32BIT"
   #pragma align 4
   #elif defined __GNUC__ 
   #pragma section ".data.SafeTlib_DEFAULT_RAM_32BIT" aw 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*.data will be used for Init data and .bss for uninit data*/
   #pragma section DATA ".data.DEFAULT_RAM_32BIT" ".bss.DEFAULT_RAM_32BIT" far-absolute RW
   #pragma align_variables 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT
   #if defined __TASKING__
   #pragma align restore
   #pragma section farbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED
   #if defined __TASKING__
   #pragma section farbss="DEFAULT_RAM_UNSPECIFIED"
   #elif defined __GNUC__ 
   #pragma section ".data.SafeTlib_DEFAULT_RAM_UNSPECIFIED" aw
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*.data will be used for Init data and .bss for uninit data*/
   #pragma section DATA ".data.DEFAULT_RAM_UNSPECIFIED" ".bss.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #if defined __TASKING__
   #pragma section farbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BYTEALIGN)
   #undef      DEFAULT_START_SEC_VAR_32BYTEALIGN
   #if defined __TASKING__
   #pragma section farbss="DEFAULT_RAM_32BYTE"
   #pragma align 32
   #elif defined __GNUC__ 
   #pragma section ".data.SafeTlib_DEFAULT_RAM_32BYTE" aw 32
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*.data will be used for Init data and .bss for uninit data*/
   #pragma section DATA ".data.DEFAULT_RAM_32BYTE" ".bss.DEFAULT_RAM_32BYTE" far-absolute RW
   #pragma align_variables 32
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BYTEALIGN)
   #undef      DEFAULT_STOP_SEC_VAR_32BYTEALIGN
   #if defined __TASKING__
   #pragma align restore
   #pragma section farbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_8BYTEALIGN)
   #undef      DEFAULT_START_SEC_VAR_8BYTEALIGN
   #if defined __TASKING__
   #pragma section farbss="CpuMpu.DEFAULT_RAM_8BYTE"
   #pragma align 8
   #elif defined __GNUC__ 
   #pragma section ".bss.SafeTlib_CpuMpu.DEFAULT_RAM_8BYTE" awB 8
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*.data will be used for Init data and .bss for uninit data*/
   #pragma section DATA ".data.CpuMpu.DEFAULT_RAM_8BYTE" ".bss.CpuMpu.DEFAULT_RAM_8BYTE" far-absolute RW
   #pragma align_variables 8
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BYTEALIGN)
   #undef      DEFAULT_STOP_SEC_VAR_8BYTEALIGN
   #if defined __TASKING__
   #pragma align restore
   #pragma section farbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif



#elif defined (DEFAULT_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED
   #if defined __TASKING__
   #pragma section fardata="DEFAULT_RAM_UNSPECIFIED_NONZERO_INIT"
   #elif defined __GNUC__ 
   #pragma section ".data.SafeTlib_DEFAULT_RAM_UNSPECIFIED_NONZERO_INIT" aw
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in uninitialized section for windriver*/
   #pragma section DATA ".data.DEFAULT_RAM_UNSPECIFIED_NONZERO_INIT" ".error" far-absolute RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED
   #if defined __TASKING__
   #pragma section fardata restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_NONZERO_INIT_32BIT)
   #undef      DEFAULT_START_SEC_VAR_NONZERO_INIT_32BIT
   #if defined __TASKING__
   #pragma section fardata="DEFAULT_RAM_32BIT_NONZERO_INIT"
   #pragma align 4
   #elif defined __GNUC__ 
   #pragma section ".data.SafeTlib_DEFAULT_RAM_32BIT_NONZERO_INIT" aw 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in uninitialized section for windriver*/
   #pragma section DATA ".data.DEFAULT_RAM_32BIT_NONZERO_INIT" ".error" RW
   #pragma align_variables 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_STOP_SEC_VAR_NONZERO_INIT_32BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NONZERO_INIT_32BIT
   #if defined __TASKING__
   #pragma section fardata restore
   #pragma align restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_NONZERO_INIT_8BIT)
   #undef      DEFAULT_START_SEC_VAR_NONZERO_INIT_8BIT
   #if defined __TASKING__
   #pragma section fardata="DEFAULT_RAM_NONZERO_INIT_8BIT"
   #elif defined __GNUC__ 
   #pragma section ".data.SafeTlib_DEFAULT_RAM_NONZERO_INIT_8BIT" aw
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in uninitialized section for windriver*/
   #pragma section DATA ".data.DEFAULT_RAM_NONZERO_INIT_8BIT" ".error" RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_STOP_SEC_VAR_NONZERO_INIT_8BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NONZERO_INIT_8BIT
   #if defined __TASKING__
   #pragma section fardata restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif


#elif defined (FLS_17_START_CONFIG)
   #undef      FLS_17_START_CONFIG
   #if defined __TASKING__
   #pragma section fardata="FLS_RESERVED"
   #pragma align 4
   #elif defined __GNUC__ 
   #pragma section ".data.FLS_RESERVED" aw 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in uninitialized section for windriver*/
   #pragma section DATA ".data.FLS_RESERVED" ".error" far-absolute RW
   #pragma align_variables 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (FLS_17_STOP_CONFIG)
   #undef      FLS_17_STOP_CONFIG
   #if defined __TASKING__
   #pragma align restore
   #pragma section fardata restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif


/*****************************************************************************
**              RAM variables frequently used or accessed                   **
**              bitwise                                                     **
******************************************************************************/

#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT
   #if defined __TASKING__
   #pragma section nearbss="DEFAULT_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
   #elif defined __GNUC__ 
   #pragma section ".zbss.SafeTlib_DEFAULT_RAM_FAST_8BIT" awBz 1
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".error" ".zbss.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #if defined __TASKING__
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT
   #if defined __TASKING__
   #pragma section nearbss="DEFAULT_RAM_FAST_16BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #elif defined __GNUC__ 
   #pragma section ".zbss.SafeTlib_DEFAULT_RAM_FAST_16BIT" awBz 2
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".error" ".zbss.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #pragma align_variables 2
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #if defined __TASKING__
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT
   #if defined __TASKING__
   #pragma section nearbss="DEFAULT_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #elif defined __GNUC__ 
   #pragma section ".zbss.SafeTlib_DEFAULT_RAM_FAST_32BIT" awBz 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.DEFAULT_RAM_FAST_32BIT" ".zbss.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #pragma align_variables 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #if defined __TASKING__
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (ETH_17_RES_START_SEC_VAR_FAST_8BIT)
   #undef      ETH_17_RES_START_SEC_VAR_FAST_8BIT
   #if defined __TASKING__
   #pragma section nearbss="ETH_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
   #elif defined __GNUC__ 
   #pragma section ".bss.ETH_RAM_FAST_8BIT" awB 1
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in initialized section for windriver*/
   #pragma section DATA ".error" ".bss.ETH_RAM_FAST_8BIT" RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (ETH_17_RES_STOP_SEC_VAR_FAST_8BIT)
   #undef      ETH_17_RES_STOP_SEC_VAR_FAST_8BIT
   #if defined __TASKING__
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (ETH_17_RES_START_SEC_VAR_FAST_32BIT)
   #undef      ETH_17_RES_START_SEC_VAR_FAST_32BIT
   #if defined __TASKING__
   #pragma section nearbss="ETH_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #elif defined __GNUC__ 
   #pragma section ".bss.ETH_RAM_FAST_32BIT" awB 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in initialized section for windriver*/
   #pragma section DATA ".error" ".zbss.ETH_RAM_FAST_32BIT" RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (ETH_17_RES_STOP_SEC_VAR_FAST_32BIT)
   #undef      ETH_17_RES_STOP_SEC_VAR_FAST_32BIT
   #if defined __TASKING__
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (SPI_START_SEC_VAR_FAST_32BIT)
   #undef      SPI_START_SEC_VAR_FAST_32BIT
   /*".error" is there protect any allocation in initialized section for windriver*/
   #pragma section DATA ".error" ".zbss.SPI_RAM_FAST_32BIT" RW
#elif defined (SPI_STOP_SEC_VAR_FAST_32BIT)
   #undef      SPI_STOP_SEC_VAR_FAST_32BIT
   #pragma section DATA RW

#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #if defined __TASKING__
   #pragma section nearbss="DEFAULT_RAM_FAST_UNSPECIFIED"
   #pragma for_uninitialized_data_use_memory near
   #elif defined __GNUC__ 
   #pragma section ".zbss.SafeTlib_DEFAULT_RAM_FAST_UNSPECIFIED" awBz
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in initialized section for windriver*/
   #pragma section DATA ".error" ".zbss.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #if defined __TASKING__
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

/*****************************************************************************
**              Variables that needs to be initialized only                 **
**              after Power on reset                                        **
******************************************************************************/
/*
 * There are no specific #pragmas given in Tasking
 */
#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT
   #if defined __TASKING__
   #pragma section farbss="DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #elif defined __GNUC__ 
   #pragma section ".data.SafeTlib_DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*.data will be used for Init data and .bss for uninit data*/
   #pragma section DATA ".data.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #if defined __TASKING__
   #pragma section farbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT
   #if defined __TASKING__
   #pragma section farbss="DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #elif defined __GNUC__ 
   #pragma section ".data.SafeTlib_DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*.data will be used for Init data and .bss for uninit data*/
   #pragma section DATA  ".data.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #if defined __TASKING__
   #pragma section farbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT
   #if defined __TASKING__
   #pragma section farbss="DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #elif defined __GNUC__ 
   #pragma section ".data.SafeTlib_DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*.data will be used for Init data and .bss for uninit data*/
   #pragma section DATA ".data.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #if defined __TASKING__
   #pragma section farbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #if defined __TASKING__
   #pragma section farbss="DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #elif defined __GNUC__ 
   #pragma section ".data.SafeTlib_DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*.data will be used for Init data and .bss for uninit data*/
   #pragma section DATA ".data.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #if defined __TASKING__
   #pragma section farbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

/*****************************************************************************
**      RAM variables not initialized and located to specific SRAM          **
******************************************************************************/
#elif defined (DEFAULT_START_SEC_VAR_8BIT_CPU0_DSPR)
   #undef      DEFAULT_START_SEC_VAR_8BIT_CPU0_DSPR
   #if defined __TASKING__
   #pragma section farbss="Lmu.CPU0_DSPR_RAM_8BIT"
   #elif defined __GNUC__
   #pragma section ".bss.Lmu.CPU0_DSPR_RAM_8BIT" awB 1
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in initialized section for windriver*/
   #pragma section DATA ".error" ".bss.Lmu.CPU0_DSPR_RAM_8BIT" far-absolute RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_CPU0_DSPR)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_CPU0_DSPR
   #if defined __TASKING__   
   #pragma section farbss restore
   #elif defined __GNUC__
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
   
#elif defined (DEFAULT_START_SEC_VAR_32BIT_CPU0_DSPR)
   #undef      DEFAULT_START_SEC_VAR_32BIT_CPU0_DSPR
   #if defined __TASKING__
   #pragma section farbss="Lmu.CPU0_DSPR_RAM_32BIT"
   #pragma align 4
   #elif defined __GNUC__
   #pragma section ".bss.Lmu.CPU0_DSPR_RAM_32BIT" awB 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*".error" is there protect any allocation in initialized section for windriver*/
   #pragma section DATA ".error" ".bss.Lmu.CPU0_DSPR_RAM_32BIT" far-absolute RW
   #pragma align_variables 4   
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_CPU0_DSPR)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_CPU0_DSPR
   #if defined __TASKING__
   #pragma align restore
   #pragma section farbss restore
   #elif defined __GNUC__
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif   
   
/*****************************************************************************
**              ADC Special                                                 **
******************************************************************************/

#elif defined (ADC_DMA_START_SEC_EMUXSCAN_BUFFER)
   #undef      ADC_DMA_START_SEC_EMUXSCAN_BUFFER
   #if defined __TASKING__
   #pragma section farbss="ADC_DMA_EMUXSCAN_RAM_16BIT"
   #pragma align 4
   #elif defined __GNUC__ 
   #pragma section ".data.ADC_DMA_EMUXSCAN_RAM_16BIT" aw 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   /*.data will be used for Init data and .bss for uninit data*/
   #pragma section DATA ".data.ADC_DMA_EMUXSCAN_RAM_16BIT" ".bss.ADC_DMA_EMUXSCAN_RAM_16BIT" far-absolute RW
   #pragma align_variables 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (ADC_DMA_STOP_SEC_EMUXSCAN_BUFFER)
   #undef      ADC_DMA_STOP_SEC_EMUXSCAN_BUFFER
   #if defined __TASKING__
   #pragma align restore
   #pragma section farbss restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section DATA RW
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif



/*****************************************************************************
**              Constants                                                   **
******************************************************************************/

#elif defined (DEFAULT_START_SEC_CONST_8BIT)
   #undef      DEFAULT_START_SEC_CONST_8BIT
   #if defined __TASKING__
   #pragma section farrom="DEFAULT_CONST_8BIT"
   #elif defined __GNUC__ 
   #pragma section ".rodata.SafeTlib_DEFAULT_CONST_8BIT" a 1
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.DEFAULT_CONST_8BIT" far-absolute R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT
   #if defined __TASKING__
   #pragma section farrom restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_CONST_16BIT)
   #undef      DEFAULT_START_SEC_CONST_16BIT
   #if defined __TASKING__
   #pragma section farrom="DEFAULT_CONST_16BIT"
   #pragma align 4
   #elif defined __GNUC__ 
   #pragma section ".rodata.SafeTlib_DEFAULT_CONST_16BIT" a 2
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.DEFAULT_CONST_16BIT" far-absolute R
   #pragma align_variables 2
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT
   #if defined __TASKING__
   #pragma align restore
   #pragma section farrom restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_CONST_32BIT)
   #undef      DEFAULT_START_SEC_CONST_32BIT
   #if defined __TASKING__
   #pragma section farrom="DEFAULT_CONST_32BIT"
   #pragma align 4
   #elif defined __GNUC__ 
   #pragma section ".rodata.SafeTlib_DEFAULT_CONST_32BIT" a 4
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.DEFAULT_CONST_32BIT" far-absolute R
   #pragma align_variables 4
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT
   #if defined __TASKING__
   #pragma align restore
   #pragma section farrom restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_variables 0
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED
   #if defined __TASKING__
   #pragma section farrom="DEFAULT_CONST_FAR_UNSPECIFIED"
   #elif defined __GNUC__ 
   #pragma section ".rodata.SafeTlib_DEFAULT_CONST_FAR_UNSPECIFIED" a
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #if defined __TASKING__
   #pragma section farrom restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif

#elif defined (BMD_HDR_START_SEC_BMI_HEADER)
   #undef      BMD_HDR_START_SEC_BMI_HEADER
   #if defined __TASKING__
   #pragma section farrom="BMD_HDR_CONST_FAR_UNSPECIFIED"
   #elif defined __GNUC__ 
   #pragma section ".rodata.BMD_HDR_CONST_FAR_UNSPECIFIED" a
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".BMD_HDR_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (BMD_HDR_STOP_SEC_BMI_HEADER)
   #undef      BMD_HDR_STOP_SEC_BMI_HEADER
   #if defined __TASKING__
   #pragma section farrom restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
/* -------------------------------------------------------------------------- */
/* End of default section mapping                                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* TRAP Section mapping                                                       */
/* -------------------------------------------------------------------------- */

#elif defined (MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU0)
   #undef      MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU0
   #if defined __TASKING__
   #pragma section code="CPU0_TRAP_HANDLER_CODE_ROM"
      #elif defined __GNUC__ 
   #pragma section ".text.CPU0_TRAP_HANDLER_CODE_ROM" ax 32
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU0_TRAP_HANDLER_CODE_ROM" X
   #pragma align_functions 32
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU0)
   #undef      MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU0
   #if defined __TASKING__
      #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE X
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif


#elif defined (MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU1)
   #undef      MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU1
   #if defined __TASKING__
   #pragma section code="CPU1_TRAP_HANDLER_CODE_ROM"
      #elif defined __GNUC__ 
   #pragma section ".text.CPU1_TRAP_HANDLER_CODE_ROM" ax 32
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU1_TRAP_HANDLER_CODE_ROM" X
   #pragma align_functions 32
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU1)
   #undef      MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU1
   #if defined __TASKING__
      #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE X
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif


#elif defined (MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU2)
   #undef      MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU2
   #if defined __TASKING__
   #pragma section code="CPU2_TRAP_HANDLER_CODE_ROM"
      #elif defined __GNUC__ 
   #pragma section ".text.CPU2_TRAP_HANDLER_CODE_ROM" ax 32
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU2_TRAP_HANDLER_CODE_ROM" X
   #pragma align_functions 32
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif
#elif defined (MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU2)
   #undef      MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU2
   #if defined __TASKING__
      #pragma section code restore
   #elif defined __GNUC__ 
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_   
   #if (_DIABDATA_C_TRICORE_ == 1U)
   #pragma align_functions 0
   #pragma section CODE X
   #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
   #endif


/* -------------------------------------------------------------------------- */
/* Begin alignment mapping                                                    */
/* -------------------------------------------------------------------------- */

#elif defined (DEFAULT_START_VAR_ALIGN_16_BIT)
   #undef      DEFAULT_START_VAR_ALIGN_16_BIT
   #pragma align 4
#elif defined (DEFAULT_STOP_VAR_ALIGN_16_BIT)
   #undef      DEFAULT_STOP_VAR_ALIGN_16_BIT
   #pragma align restore
/* -------------------------------------------------------------------------- */
/* End of alignment mapping                                                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* Begin Packing                                                              */
/* -------------------------------------------------------------------------- */

#elif defined (DEFAULT_START_VAR_PACK_2)
   #undef      DEFAULT_START_VAR_PACK_2
   #pragma pack 2
#elif defined (DEFAULT_STOP_VAR_PACK_2)
   #undef      DEFAULT_STOP_VAR_PACK_2
   #pragma pack 0
/* -------------------------------------------------------------------------- */
/* End of Packing                                                             */
/* -------------------------------------------------------------------------- */

/*lint +idlen(60) +esym(961,92) */
/*lint +esym(960,19.6)   */  /* Allow usage of #undef */

#endif  /* START_WITH_IF */


/*** End of file **************************************************************/
