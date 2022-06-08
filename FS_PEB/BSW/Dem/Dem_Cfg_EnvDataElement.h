/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/

/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/

#ifndef DEM_CFG_ENVDATAELEMENT_H
#define DEM_CFG_ENVDATAELEMENT_H

#include "Std_Types.h"

#define DEM_CFG_ENV_DATAELEMENTS_EXTERN_AVAILABILITY   STD_ON
#define DEM_CFG_ENV_DATAELEMENTS_INTERN_AVAILABILITY  STD_ON

#define DEM_CFG_READDEM_AGINGCTR_UPCNT_SUPPORTED                         TRUE
#define DEM_CFG_READDEM_OCCCTR_SUPPORTED                                 TRUE
#define DEM_CFG_READDEM_OVFLIND_SUPPORTED                                FALSE
#define DEM_CFG_READDEM_SIGNIFICANCE_SUPPORTED                           TRUE
#define DEM_CFG_READDEM_DEBUG0_SUPPORTED                                 FALSE
#define DEM_CFG_READDEM_DEBUG1_SUPPORTED                                 FALSE
#define DEM_CFG_READDEM_EVENT_ID_SUPPORTED                               FALSE
#define DEM_CFG_READDEM_CURRENT_FDC_SUPPORTED                            FALSE
#define DEM_CFG_READDEM_MAX_FDC_DURING_CURRENT_CYCLE_SUPPORTED           FALSE
#define DEM_CFG_READDEM_MAX_FDC_SINCE_LAST_CLEAR_SUPPORTED               FALSE
#define DEM_CFG_READDEM_CYCLES_SINCE_FIRST_FAILED_SUPPORTED              FALSE
#define DEM_CFG_READDEM_CYCLES_SINCE_LAST_FAILED_SUPPORTED               FALSE
#define DEM_CFG_READDEM_CYCLES_SINCE_LAST_FAILED_EXCLUDING_TNC_SUPPORTED   FALSE
#define DEM_CFG_READDEM_FAILED_CYCLES_SUPPORTED                          FALSE
#define DEM_CFG_READDEM_PRJ_SPECIFIC_DATA_ON_RETRIEVE_SUPPORTED          FALSE
#define DEM_CFG_READDEM_PRJ_SPECIFIC_DATA_ON_REPORT_SUPPORTED            FALSE

#define DEM_DATAELEM_DEMDATAELEMENTCLASS_IS  1
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_TRQMECH  2
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_NWOFLT  3
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_TDBCTEMPUFLT  4
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_TSTRRTEMP1FLT  5
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_TSTRRTEMP2FLT  6
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_UKL30FLT  7
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_IU  8
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_IV  9
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_IW  10
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_UDCLNK  11
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_PRIORITY  12
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_AGINGCTR  13
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_EVENTSTATUSBYTE  14
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_OCCCTR  15

#define DEM_CFG_ENV_DATAELEMENTS \
{ \
   { DEM_ENV_DATAELEMENTS_EXTCS_INIT(NULL_PTR) DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 0, FALSE } \
   ,{ &DEM_FF_Is, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 2, FALSE } \
   ,{ &DEM_FF_TrqMech, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 2, FALSE } \
   ,{ &DEM_FF_nWoFlt, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 2, FALSE } \
   ,{ &DEM_FF_tDBCTempUFlt, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 1, FALSE } \
   ,{ &DEM_FF_tStrrTemp1Flt, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 1, FALSE } \
   ,{ &DEM_FF_tStrrTemp2Flt, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 1, FALSE } \
   ,{ &DEM_FF_uKl30Flt, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 2, FALSE } \
   ,{ &DEM_FF_iU, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 2, FALSE } \
   ,{ &DEM_FF_iV, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 2, FALSE } \
   ,{ &DEM_FF_iW, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 2, FALSE } \
   ,{ &DEM_FF_uDcLnk, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 2, FALSE } \
   ,{ DEM_ENV_DATAELEMENTS_EXTCS_INIT(NULL_PTR) &Dem_ReadSignificance, 1, FALSE } \
   ,{ DEM_ENV_DATAELEMENTS_EXTCS_INIT(NULL_PTR) &Dem_ReadAgingCtr, 1, TRUE } \
   ,{ DEM_ENV_DATAELEMENTS_EXTCS_INIT(NULL_PTR) &Dem_ReadEventStatusByte, 1, FALSE } \
   ,{ DEM_ENV_DATAELEMENTS_EXTCS_INIT(NULL_PTR) &Dem_ReadOccCtr, 1, TRUE } \
}

#define DEM_CFG_ENV_DATAELEMENTS_ARRAYLENGTH      (15+1)

#endif

