/** @file     Rte_IoHwAbW.h
  *
  * @brief    Application header file
  *
  * @note     AUTOMATICALLY GENERATED FILE! DO NOT EDIT!
  *
  * @note     Generated by ETAS RTA-RTE
  * @note     Version 6.6.0 
  */

#ifndef RTE_IOHWABW_H
#define RTE_IOHWABW_H

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
#include "Rte_IoHwAbW_Type.h"

#include "Rte_DataHandleType.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined(RTE_RUNNABLEAPI_IoHwAb_ADC_GetPhyVoltage)
   /* Do nothing for this and all elif clauses below (rte_sws_2751) */
#elif defined(RTE_RUNNABLEAPI_IoHwAb_DIO_Get)
#elif defined(RTE_RUNNABLEAPI_IoHwAb_DIO_Set)
#elif defined(RTE_RUNNABLEAPI_IoHwAb_ICU_GetPeriod_DutyCycle)
#elif defined(RTE_RUNNABLEAPI_IoHwAb_PWM_SetDutyCycle)
#elif defined(RTE_RUNNABLEAPI_IoHwAb_PWM_SetPeriod_DutyCycle)
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
struct Rte_CDS_IoHwAbW {
   uint8 Rte_Dummy;
};
typedef struct Rte_CDS_IoHwAbW Rte_CDS_IoHwAbW;
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
extern CONST(struct Rte_CDS_IoHwAbW, RTE_CONST) Rte_Inst_IoHwAbW;
#define RTE_STOP_SEC_Partition_Core0_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */


#ifndef RTE_CORE
typedef CONSTP2CONST(struct Rte_CDS_IoHwAbW, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_CORE */

/*******************************************************
 ***
 *** API Mapping macros
 ***
 *******************************************************/

/* API Mapping Macros */
#ifndef RTE_CORE

#endif /* RTE_CORE */

/*******************************************************
 ***
 *** RE Prototypes
 ***
 *******************************************************/

#define IoHwAbW_START_SEC_CODE
#include "IoHwAbW_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, IoHwAbW_CODE) IoHwAb_ADC_GetPhyVoltage(VAR(uint8, AUTOMATIC) Channel,
                                                  CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) RawVoltage);
FUNC(void, IoHwAbW_CODE) IoHwAb_DIO_Get(VAR(uint16, AUTOMATIC) channel,
                                        CONSTP2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) dio_status);
FUNC(void, IoHwAbW_CODE) IoHwAb_DIO_Set(VAR(uint16, AUTOMATIC) channel,
                                        VAR(boolean, AUTOMATIC) dio_status);
FUNC(void, IoHwAbW_CODE) IoHwAb_ICU_GetPeriod_DutyCycle(VAR(uint8, AUTOMATIC) channel,
                                                        CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) Period,
                                                        CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) Dutycycle);
FUNC(void, IoHwAbW_CODE) IoHwAb_PWM_SetDutyCycle(VAR(uint16, AUTOMATIC) channel,
                                                 VAR(float32, AUTOMATIC) dutycycle);
FUNC(void, IoHwAbW_CODE) IoHwAb_PWM_SetPeriod_DutyCycle(VAR(uint16, AUTOMATIC) channel,
                                                        VAR(uint32, AUTOMATIC) period,
                                                        VAR(float32, AUTOMATIC) dutycycle);
#define IoHwAbW_STOP_SEC_CODE
#include "IoHwAbW_MemMap.h" /*lint !e537 permit multiple inclusion */

/* Initial values for data element prototypes */

#ifdef __cplusplus
} /* extern C */
#endif /* __cplusplus */

#endif /* !RTE_IOHWABW_H */