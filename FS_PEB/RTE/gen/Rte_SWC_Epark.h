/** @file     Rte_SWC_Epark.h
  *
  * @brief    Application header file
  *
  * @note     AUTOMATICALLY GENERATED FILE! DO NOT EDIT!
  *
  * @note     Generated by ETAS RTA-RTE
  * @note     Version 6.6.0 
  */

#ifndef RTE_SWC_EPARK_H
#define RTE_SWC_EPARK_H

#ifndef RTE_CORE
#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE
#endif /* RTE_CORE */

/*******************************************************
 ***
 *** Includes
 ***
 *******************************************************/

#include "Rte.h"
#include "Rte_Intl.h"
#include "Rte_SWC_Epark_Type.h"

#include "Rte_DataHandleType.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined(RTE_RUNNABLEAPI_RE_Epark_10ms)
   /* Do nothing for this and all elif clauses below (rte_sws_2751) */
#else
   /* None of above defined so define value including all APIs (rte_sws_2751) */
   #define RTE_PRV_ALL_API
#endif

/*******************************************************
 ***
 *** Constants
 ***
 *******************************************************/


/*******************************************************
 ***
 *** Public Types
 ***
 *******************************************************/

/* BEGIN: SWC types (core visible) */
struct Rte_CDS_SWC_Epark {
   uint8 Rte_Dummy;
};
typedef struct Rte_CDS_SWC_Epark Rte_CDS_SWC_Epark;
/* END: SWC types (core visible) */

/*******************************************************
 ***
 *** Private Types
 ***
 *******************************************************/

/* BEGIN: SWC types (private) */
/* END: SWC types (private) */

/*******************************************************
 ***
 *** Instance Declarations
 ***
 *******************************************************/

#define RTE_START_SEC_Partition_Core0_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
extern CONST(struct Rte_CDS_SWC_Epark, RTE_CONST) Rte_Inst_SWC_Epark;
#define RTE_STOP_SEC_Partition_Core0_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */


#ifndef RTE_CORE
typedef CONSTP2CONST(struct Rte_CDS_SWC_Epark, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_CORE */

/*******************************************************
 ***
 *** API Mapping macros
 ***
 *******************************************************/

/* API Mapping Macros */
#ifndef RTE_CORE
#define RTE_START_SEC_Partition_Core0_VAR_CLEARED_32
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
extern VAR(float32, RTE_DATA) Rte_Rx_000037_Epark_iPcf;
#define RTE_STOP_SEC_Partition_Core0_VAR_CLEARED_32
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
#define RTE_START_SEC_Partition_Core0_VAR_CLEARED_32
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
extern VAR(float32, RTE_DATA) Rte_Rx_000038_Epark_posPcf;
#define RTE_STOP_SEC_Partition_Core0_VAR_CLEARED_32
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
#define RTE_START_SEC_Partition_Core0_VAR_CLEARED_32
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
extern VAR(float32, RTE_DATA) Rte_Rx_000039_Epark_posPcfMon;
#define RTE_STOP_SEC_Partition_Core0_VAR_CLEARED_32
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
#define RTE_START_SEC_Partition_Core0_VAR_CLEARED_BOOLEAN
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
extern VAR(boolean, RTE_DATA) Rte_Rx_000138_PCF_MotDir;
#define RTE_STOP_SEC_Partition_Core0_VAR_CLEARED_BOOLEAN
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
#define RTE_START_SEC_Partition_Core0_VAR_CLEARED_32
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
extern VAR(float32, RTE_DATA) Rte_Rx_000143_PCF_dycPWM;
#define RTE_STOP_SEC_Partition_Core0_VAR_CLEARED_32
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
#if defined(RTE_PRV_ALL_API) || defined(RTE_RUNNABLEAPI_RE_Epark_10ms)
/* Inline read optimization; Rte_Read_RP_SWC_PCF_PCF_MotDir to direct access */
#define Rte_Read_RP_SWC_PCF_PCF_MotDir( data )  ( ((*(data)) = Rte_Rx_000138_PCF_MotDir),((VAR(Std_ReturnType, AUTOMATIC))RTE_E_OK) )
#endif
#if defined(RTE_PRV_ALL_API) || defined(RTE_RUNNABLEAPI_RE_Epark_10ms)
/* Inline read optimization; Rte_Read_RP_SWC_PCF_PCF_dycPWM to direct access */
#define Rte_Read_RP_SWC_PCF_PCF_dycPWM( data )  ( ((*(data)) = Rte_Rx_000143_PCF_dycPWM),((VAR(Std_ReturnType, AUTOMATIC))RTE_E_OK) )
#endif
#if defined(RTE_PRV_ALL_API) || defined(RTE_RUNNABLEAPI_RE_Epark_10ms)
/* Inline Write optimization; Rte_Write_PP_SWC_Epark_Epark_iPcf to direct write */
#define Rte_Write_PP_SWC_Epark_Epark_iPcf( data ) ( (Rte_Rx_000037_Epark_iPcf = data), RTE_E_OK )
#endif
#if defined(RTE_PRV_ALL_API) || defined(RTE_RUNNABLEAPI_RE_Epark_10ms)
/* Inline Write optimization; Rte_Write_PP_SWC_Epark_Epark_posPcf to direct write */
#define Rte_Write_PP_SWC_Epark_Epark_posPcf( data ) ( (Rte_Rx_000038_Epark_posPcf = data), RTE_E_OK )
#endif
#if defined(RTE_PRV_ALL_API) || defined(RTE_RUNNABLEAPI_RE_Epark_10ms)
/* Inline Write optimization; Rte_Write_PP_SWC_Epark_Epark_posPcfMon to direct write */
#define Rte_Write_PP_SWC_Epark_Epark_posPcfMon( data ) ( (Rte_Rx_000039_Epark_posPcfMon = data), RTE_E_OK )
#endif

#endif /* RTE_CORE */

/*******************************************************
 ***
 *** RE Prototypes
 ***
 *******************************************************/

#define SWC_Epark_START_SEC_CODE
#include "SWC_Epark_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, SWC_Epark_CODE) SWC_Epark_10ms(void);
#define SWC_Epark_STOP_SEC_CODE
#include "SWC_Epark_MemMap.h" /*lint !e537 permit multiple inclusion */

/* Initial values for data element prototypes */

#ifdef __cplusplus
} /* extern C */
#endif /* __cplusplus */

#endif /* !RTE_SWC_EPARK_H */