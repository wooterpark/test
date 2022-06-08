/*
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, ETAS GmbH, 2017. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 ************************************************************************************************
 * Component : Wdg.h
 * Date      : May 08 2018
 * Version   : 1.0
 * Description  : This module implements Wdg Driver for external Wdg as non MCAL modules
 ***********************************************************************************************
*/
#ifndef CDD_SBC_DRIVER_H
#define CDD_SBC_DRIVER_H


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Std_Types.h"
#include "WdgIf_Types.h"


/*
 **********************************************************************************************************************
 * Define/Macros
 **********************************************************************************************************************
 */

#define WDG_AR_RELEASE_MAJOR_VERSION	4
#define WDG_AR_RELEASE_MINOR_VERSION	2

/* WD module ID */
#define WDG_MODULE_ID               102

/* Wdg_Init function ID */
#define WDG_INIT_ID                 ((uint8) 0x00u)

/* Wdg_SetMode function ID */
#define WDG_SETMODE_ID              ((uint8) 0x01u)

/* SetTriggerCondition function ID */
#define WDG_SETTRIGGERCONDITION_ID  ((uint8) 0x03u)

/* Wdg_GetVersionInfo function ID */
#define WDG_GETVERIONINFO_ID        ((uint8) 0x04u)

/* Wdg_MainFunction function ID */
#define WDG_MAINFUNCTION_ID         ((uint8) 0x05u)


/* API service used in wrong context (e.g. module not initialized). */
#define WDG_E_DRIVER_STATE           0x10

/* API service called with wrong / inconsistent parameter(s) */
#define WDG_E_PARAM_MODE             0x11
#define WDG_E_PARAM_CONFIG           0x12

/* The passed timeout value is higher than the maximum timeout value */
#define WDG_E_PARAM_TIMEOUT          0x13

/* API is called with wrong pointer value (e.g. NULL pointer) */
#define WDG_E_PARAM_POINTER          0x14

/* Invalid configuration set selection */
#define WDG_E_INIT_FAILED            0x15


#define WDG_DEV_ERROR_DETECT         STD_ON


/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */

/**
 * @brief  Defines the configuration structure
 * @implements     Wdg_ConfigType_struct
 */
typedef struct
{
    CONST(WdgIf_ModeType, WDG_CONST)Ext_Wdg_DefaultMode;
} Wdg_ConfigType;


/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */

extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_pConfig;




/* Function prototypes for Watchdog functionality */
FUNC(Std_ReturnType, WDG_CODE) Wdg_Init( P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) pConfigPtr);

FUNC(Std_ReturnType, WDG_CODE_FAST) Wdg_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) l_WdgMode);

FUNC(void, WDG_CODE)Wdg_SetTriggerCondition(uint16 timeout);

FUNC(void, WDG_CODE)Wdg_MainFunction_Handling(void);

FUNC(void, WDG_CODE) Wdg_GetVersionInfo( Std_VersionInfoType* versioninfo );


#endif /* CDD_SBC_DRIVER_H */

/*
 **********************************************************************************************************************
 * End of the file
 **********************************************************************************************************************
 */
