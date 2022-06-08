/*
 * This is Compiler.h for target platform: TriCoreHighTec/TC27xC
 */

#ifndef COMPILER_H
#define COMPILER_H

/* [COMPILER010] The compiler */
#define _HIGHTEC_C_TRICORE_
/* [COMPILER043] Published information : sample */
#define COMPILER_VENDOR_ID (11U)
#define COMPILER_AR_MAJOR_VERSION (4U)
#define COMPILER_AR_MINOR_VERSION (0U)
#define COMPILER_AR_PATCH_VERSION (3U)
#define COMPILER_SW_MAJOR_VERSION (0U)
#define COMPILER_SW_MINOR_VERSION (0U)
#define COMPILER_SW_PATCH_VERSION (0U)

#include <Compiler_Cfg.h>
#ifndef LOCAL_INLINE
#define LOCAL_INLINE static inline
#endif
#define AUTOMATIC  /* [COMPILER046] [COMPILER036] Used for local non static variables */
#define TYPEDEF  /* [COMPILER059] Type definitions where no memory qualifier can be specified. */
#define STATIC static /* COMPILER049 */
#define NULL_PTR ((void *)0) /* [COMPILER051] */


#define FUNC(rettype, memclass) rettype
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)
#define CONST(consttype, memclass) const consttype
#define VAR(vartype, memclass) vartype
#define FUNC_P2CONST( type , AUTOMATIC, ECUM_CALLOUT_CODE ) const type *

#define DEM_INLINE static inline

/**************************************** Green Hills *********************************************/
#ifdef __ghs__

    #define INLINE              __inline

    #define LOCAL_INLINE            static __inline

#endif /* #ifdef __ghs__ */

/**************************************** Wind River Diab *****************************************/
#ifdef __DCC__

    #define INLINE              __inline__
	
    #define LOCAL_INLINE            static __inline__

#endif /* #ifdef __DCC__ */

/*************************************** CodeWarrior **********************************************/
#ifdef __MWERKS__

    #define INLINE              inline
	
    #define LOCAL_INLINE            static inline

#endif /* #ifdef __MWERKS__ */

/*************************************** Cosmic ***************************************************/
#ifdef __CSMC__

    #define INLINE @inline

    #define LOCAL_INLINE            static @inline

#endif /* #ifdef __CSMC__ */
/*************************************** HighTec **********************************************/
#ifdef __GNUC__

    #define INLINE              __inline


    #define LOCAL_INLINE            static __inline


#endif /* #ifdef __GNUC__ */

//#define DEM_INLINE static inline/// allen

#endif /* COMPILER_H */
