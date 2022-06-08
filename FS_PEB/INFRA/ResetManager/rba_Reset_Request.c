/*<RBHead>
 ***********************************************************************************************************************
 *                                                                                                                     *

 *
 * $Filename__:rba_Reset_Request.c$
 *
 * $Author____:KUK1COB$
 *
 * $Function__:.$
 *
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
 *              reset utilities
 *
 * \scope           API
 *********************************************************************************************************************
 */

/*
 *********************************************************************************************************************
 * Includes

 *********************************************************************************************************************
 */
#include "rba_Reset.h"
#include "rba_Reset_Prv.h"
#include "rba_BswSrv.h"
#include "Mcu.h"
#include "NvM.h"
#include "MemIf.h"
#include "Fls.h"

volatile uint32 rba_Reset_ResetLock_u32;

rba_Reset_Env_tst rba_Reset_Env_History;
uint8 Reset_Write_Counter;

/*
 *********************************************************************************************************************

 * used functions
 *********************************************************************************************************************
 */


/* Start MemMap for default code */
/**
 *********************************************************************************************************************

 * rba_Reset_Request - triggers a reset.
 *
 * This function will be called from the ASW. It will save different information
 * about the system and then restart the system.
 *
 * \param           uint8 dResetGrp_u8 : group for SWResets
 * \param           uint16 dResetIdentifier_u16 : identifier of SWReset type
 * \param           uint32 dUserDefined_u32 : user defined 32-bit value
 * \return          none
 * \seealso
 * \usedresources
 *********************************************************************************************************************
 */
void rba_Reset_Request(rba_Reset_Grp_ten dResetGrp_en, rba_Reset_Id_ten dResetIdentifier_en, uint32 dUserDefined_u32)
{
    /* disable interrupts and set spinlock */
    rba_Reset_GetResetLock();

    /* store reset Group */
    rba_Reset_Env_pst->Grp_en = dResetGrp_en;

    /* store reset ID */
    rba_Reset_Env_pst->Type_en = dResetIdentifier_en;

    /* store user defined 32bit value */
    rba_Reset_Env_pst->UserDefined_u32 = dUserDefined_u32;

    /*Store the reset environment in DFlash*/
    IC_NvM_WriteBlock();

    /* execute reset */
    //RBA_BSWSRV_DEBUG_HALT();//FJ 2020/8/18
    Mcu_PerformReset();
    while(1);
}

void IC_NvM_WriteBlock(void)
{
	NvM_Rb_StatusType status_NvM;
	MemIf_StatusType stMemIf_en;
	Std_ReturnType returnvalue;

	NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvM_SWReset_Env,rba_Reset_Env_pst);

	Fls_ControlTimeoutDet(0);
	do
	{
		NvM_MainFunction();
		MemIf_Rb_MainFunction();

		returnvalue = NvM_Rb_GetStatus(&status_NvM);
		stMemIf_en = MemIf_Rb_GetStatus();
		Reset_Write_Counter++;
	} while ( (status_NvM == NVM_RB_STATUS_BUSY ) || (stMemIf_en == MEMIF_BUSY));

	Fls_ControlTimeoutDet(1);
}
/*<RBHead>
 ***********************************************************************************************************************

 *   COMP : rba_Reset \ AR40.2.0.0; 0 (\Comp\rba_Reset)
 * 
 * $
 *
 ***********************************************************************************************************************
</RBHead>*/
