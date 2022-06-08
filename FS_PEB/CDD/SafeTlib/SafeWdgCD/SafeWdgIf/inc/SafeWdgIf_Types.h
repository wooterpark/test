/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : SafeWdgIf_Types.h $                                        **
**                                                                            **
**   $CC VERSION : \main\18 $                                                 **
**                                                                            **
**   $DATE       : 2016-03-02 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**  DESCRIPTION  : This file contains                                         **
**                 - Declarations for SafeWdgIf driver.                       **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


#ifndef SAFEWDGIF_TYPES_H
#define SAFEWDGIF_TYPES_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Typedefs                                          **
*******************************************************************************/
/* Cic states */
#define SAFEWDG_CIC_NR               ( 0x78U )    /* cic in Not Ready state */
#define SAFEWDG_CIC_READY            ( 0x3CU )    /* cic in Ready state */
#define SAFEWDG_CIC_ACTIVE           ( 0x1EU )    /* cic in Active state */
#define SAFEWDG_CIC_TRIPPING1        ( 0x96U )    /* cic in Trip1 state */
#define SAFEWDG_CIC_TRIPPING2        ( 0xB4U )    /* cic in Trip2 state */
#define SAFEWDG_CIC_TRIPPING3        ( 0xA5U )    /* cic in  Trip3 state */
#define SAFEWDG_CIC_DISABLED         ( 0x2DU )    /* cic in disabled state */
#define SAFEWDG_CIC_SECURE           ( 0x4BU )    /* cic in secure SPI state */
#define SAFEWDG_CIC_UNKNOWN          ( 0x00U )    /* cic state not yet retrieved */

/* TLF35584 states */
#define SAFEWDG_TLF_INIT             ( 0x1U )      /*TLF35584 initialized*/
#define SAFEWDG_TLF_NORMAL           ( 0x2U )      /*TLF35584 in normal state */
#define SAFEWDG_TLF_SLEEP            ( 0x3U )      /*TLF35584 in Sleep state*/
#define SAFEWDG_TLF_STANDBY          ( 0x4U )      /*TLF35584 in STANDBY state */
#define SAFEWDG_TLF_WAKE             ( 0x5U )      /*TLF35584 in WAKE state */
#define SAFEWDG_TLF_RESET            ( 0x7U )      /*TLF35584 in reset state*/
#define SAFEWDG_TLF_UNDEFINEDSTATE   ( 0xFFU )     /*TLF35584 in Undefined state*/

/* Internal watchdog states */ 
#define SAFEWDGINT_UNKNOWN           ( 0U )
#define SAFEWDGINT_INIT              ( 1U )
#define SAFEWDGINT_ACTIVE            ( 2U )
#define SAFEWDGINT_FAIL              ( 3U )


#define SAFEWDG_UNKNOWN              ( 0x00U )
#define SAFEWDG_MAXNBR_SEED          ( 16U )     /* max. number of supported seed values */
#define SAFEWDG_SEED_NOTVALID        ( 255U )    /* seed not valid/not available */
#define SAFEWDG_ERR_NOTVALID         ( 255U )    /* error counter not yet valid */

/* shall be treated as unknown */
#define SAFEWDGIF_UNKNOWN            ( 0U )  


/* state types for internal and external watchdog */
typedef uint8 SafeWdgIf_ResultType;
typedef uint16 SafeWdgExt_StateType;
typedef uint16 SafeWdgInt_StateType;


/* structure for user command */
typedef struct SafeWdgIf_CmdType
{
    uint8                       ReqCmd;         /* requested user command to ext. watch dog */
    uint8                       UserData;       /* send/receive back data for this operation */
}SafeWdgIf_CmdType;

/* container for common watchdog configuration */
typedef struct SafeWdgIf_ConfigType
{
    const void* const                  DriverIntConfigPtr;
    const void* const                  DriverExtConfigPtr;
} SafeWdgIf_ConfigType;

typedef struct 
{
  SafeWdgInt_StateType IntWdgState;
  SafeWdgExt_StateType ExtWdgState;
}SafeWdgIf_StateType;


/*******************************************************************************
**                      Enumerations                                          **
*******************************************************************************/


/*******************************************************************************
**                   Structure Definitions                                    **
*******************************************************************************/



/*******************************************************************************
**                   Exported Functions                                       **
*******************************************************************************/



/*******************************************************************************
**                   Exported global configuration data                       **
*******************************************************************************/



#endif

