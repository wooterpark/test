/*<RBHead>
 ***********************************************************************************************************************
 *                                                                                                                     *
 *                                                  ROBERT BOSCH GMBH                                                  *
 *                                                      STUTTGART                                                      *
 *                                                                                                                     *
 *                                    Alle Rechte vorbehalten - All rights reserved                                    *
 *                                                                                                                     *
 ***********************************************************************************************************************

 ***********************************************************************************************************************
 * Administrative information (automatically filled in by eASEE)
 ***********************************************************************************************************************
 *
 * $Filename__:rba_Reset_CB.h$
 *
 * $Author____:MOR2ABT$
 *
 * $Function__:Transferred from BASD:
 *             COMP : rba_Reset \ AR40.0.7.0; 1$
 *
 ***********************************************************************************************************************
 * $Domain____:SDOM$
 * $User______:WIP2FE$
 * $Date______:10.03.2015$
 * $Class_____:SWHDR$
 * $Name______:rba_Reset_CB$
 * $Variant___:1.21.0$
 * $Revision__:0$
 * $Type______:H$
 * $State_____:AVAILABLE$
 * $Generated_:$
 ***********************************************************************************************************************
 *
 * $UniqueName:$
 * $Component_:$
 *
 ***********************************************************************************************************************
</RBHead>*/


/**
 *********************************************************************************************************************
 * \moduledescription
 *              friend header file only usable for CB (customerblock) in DGS projects
 *
 * \scope           API
 *********************************************************************************************************************
 */
#ifndef RBA_RESET_CB_H
#define RBA_RESET_CB_H

/* includes */
#include "Std_Types.h"


/* typedef for reset handling */
typedef struct
{
    uint64_reset TiStampCurr_u64;                                                     /* timestamp of current reset */
    uint64_reset TiStampLast_u64;                                                        /* timestamp of last reset */
    uint32 UserDefined_u32;                                          /* user defined vaule, free for individual use */
    uint32 Loc_u32;                                                       /* location where the reset was triggered */
    rba_Reset_Id_ten Type_en;                                                                           /* reset id */
    uint16 TypeCompl_u16;                                                                 /* complement of reset id */
    rba_Reset_Grp_ten  Grp_en;                                                                    /* reset group id */
    uint8  CntrReset_u8;                                     /* count the number of reset since last power on reset */
    uint8  LoopCond_u8;                                                            /* reset loop conditions reached */
    uint16 ComplConfigPtr_u16;                                /* complement of lower 16 bit of reset config pointer */
}rba_Reset_Env_tst;

typedef struct{
	uint8 Reset_Reason_u8;                                         /*All reset reason, including MCU reset and SW reset*/
	uint32 Reset_Vehicle_Odometer_u32;                                                    /*TimeStamp from STM when resetting*/
}rba_Reset_Info_Type;

/* extern declarations of variables */
/* points to the current reset environment structure */
extern rba_Reset_Env_tst *rba_Reset_Env_pst;


extern void rba_Reset_DestroyRstConfPtr(void);                       /* function only for customer block usage !!!! */

#endif

/*<RBHead>
 ***********************************************************************************************************************

 * 1.6.0; 0     23.05.2013 MOR2ABT
 *   Transferred from BASD:
 *   COMP : rba_Reset \ AR40.0.7.0; 1
 * 
 * $
 *
 ***********************************************************************************************************************
</RBHead>*/
