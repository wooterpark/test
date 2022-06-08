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

#ifndef DEM_CFG_ENVEXTENDEDDATAREC_H
#define DEM_CFG_ENVEXTENDEDDATAREC_H

#define DEM_CFG_ENVEXTDATA2DATAELEMENT \
{ \
   DEM_DATAELEM_DEMDATAELEMENTCLASS_EVENTSTATUSBYTE,   DEM_DATAELEM_DEMDATAELEMENTCLASS_OCCCTR,   DEM_DATAELEM_DEMDATAELEMENTCLASS_AGINGCTR,   DEM_DATAELEM_DEMDATAELEMENTCLASS_PRIORITY,    /* Ext_DEM_Internal_Data */ \
   0 \
}

#define DEM_EXTDATAREC_EXT_DEM_INTERNAL_DATA          1

#define DEM_CFG_ENVEXTDATAREC \
{ \
/*	   RecNum Trigger                       Update Index  */ \
	 { 0,     DEM_TRIGGER_NONE,             FALSE,0    } \
	,{ 1,     DEM_TRIGGER_ON_TEST_FAILED,   FALSE,4    } /* DEM_EXTDATAREC_EXT_DEM_INTERNAL_DATA */ \
}

#define DEM_CFG_ENVEXTDATAREC_ARRAYLENGTH  (1+1)

#endif

