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

#ifndef DEM_CFG_ENVFFRECNUMERATION_H
#define DEM_CFG_ENVFFRECNUMERATION_H

/* ---------------------------------------- */
/* DEM_CFG_FFRECNUM                         */
/* ---------------------------------------- */
#define DEM_CFG_FFRECNUM_CALCULATED   1
#define DEM_CFG_FFRECNUM_CONFIGURED   2
#define DEM_CFG_FFRECNUM  DEM_CFG_FFRECNUM_CONFIGURED

#define DEM_CFG_FFRECCLASS_NUMBEROF_FFRECCLASSES          1
#define DEM_CFG_FFRECCLASS_MAXNUMBEROF_FFFRECNUMS         1

#define DEM_CFG_FFRECNUMCLASSES \
{ \
   {0x1  }   /* DemFreezeFrameRecNumClass */ \
}

#define DEM_CFG_ENVFFREC \
{ \
/*     RecNum    Trigger                       Update  */ \
     { 0,        DEM_TRIGGER_NONE,             FALSE } \
    ,{ 1,        DEM_TRIGGER_ON_TEST_FAILED,   TRUE } /* DEM_FFREC_DEMFREEZEFRAMERECORDCLASS */ \
}

#define DEM_CFG_ENVFFREC_ARRAYLENGTH  (1u+1u)

#endif

