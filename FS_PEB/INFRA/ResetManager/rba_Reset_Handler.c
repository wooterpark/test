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
 * $Filename__:rba_Reset_Handler.c$
 *
 * $Author____:KUK1COB$
 *
 * $Function__:.$
 *
 ***********************************************************************************************************************
 * $Domain____:SDOM$
 * $User______:PHB1FE$
 * $Date______:17.07.2017$
 * $Class_____:SWSRC$
 * $Name______:rba_Reset_Handler$
 * $Variant___:1.30.0$
 * $Revision__:1$
 * $Type______:C$
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
#include "rba_MemLay.h"
#include "Mcu.h"//FJ 20200820
#include "NvM.h"
#include "MemIf.h"
#include "Fls.h"
#include "BswM_Appl.h"

/*External variable*/
extern rba_Reset_Env_tst rba_Reset_Env_History;

/*
 *********************************************************************************************************************
 * Variables
 *********************************************************************************************************************
 */

uint32 Odometer_New;
rba_Reset_Info_Type Laset_Reset_Info;                                                    /*The last reset reason info*/
rba_Reset_Info_Type Last_16_Reset_InfoList[RESET_INFOLIST_SIZE];  					  /*The last 16 reset reason info*/
rba_Reset_Info_Type Reset_List_History[RESET_INFOLIST_SIZE];                            /*Reset list read from DFlash*/

uint8 Reset_Init_Done;                        /*Variable to initialize history environment only once in reset monitor*/

rba_Reset_AddInfo_tst *rba_Reset_AddInfo_pst;                  /* pointer to additional reset information in FIX-RAM */

RBA_MEMLAY_USE_BOOTFIXRAM(rba_Reset_Env_tst ,rba_Reset_Env_st); /* points to the current reset environment structure */
rba_Reset_Env_tst *rba_Reset_Env_pst;

const rba_Reset_Conf_tst **rba_Reset_CurConf_ppcst;                                  /* pointer to ASW configuration */

/*Watch variables to INCA*/
uint8 VAR_RESET_AllReason_u8 = 255U;
uint8 VAR_RESET_McuReason_u8 = 255U;
uint8 VAR_RESET_Reason_List_au8[RESET_INFOLIST_SIZE] = {255U};

void rba_Reset_Init(void)
{
    uint32 adInfBlk_u32;
    adInfBlk_u32 = 0uL;
    rba_Reset_Env_pst=&rba_Reset_Env_st;
    Reset_Init_Done = 1U;

}

/*This function designed to process Reset Monitor*/
/* For now, this function is implement to initialize the history rest environment when the last rest type is POWER-ON RESET.*/
void rba_Reset_Monitor_Proc(void)
{
	/*To initialize history environment only when rba_Reset_Init has been performed*/
    if((1U == Reset_Init_Done) && (BSWM_MODE_ECUM_STATE_APP_RUN == BswM_ModeState_Run_State))
    {
		Mcu_ResetType Last_Reset_Reason = Mcu_GetResetReason();
		/*read MCU reset reason*/
		switch(Last_Reset_Reason)
		{
		case MCU_ESR0_RESET:
			VAR_RESET_McuReason_u8 = 0U;
			VAR_RESET_AllReason_u8 = 0U;
			break;
		case MCU_ESR1_RESET:
			VAR_RESET_McuReason_u8 = 1U;
			VAR_RESET_AllReason_u8 = 1U;
			break;
		case MCU_SMU_RESET:
			VAR_RESET_McuReason_u8 = 2U;
			VAR_RESET_AllReason_u8 = 2U;
			break;
		case MCU_SW_RESET:
			VAR_RESET_McuReason_u8 = 3U;
			VAR_RESET_AllReason_u8 = 3U;
			break;
		case MCU_STM0_RESET:
			VAR_RESET_McuReason_u8 = 4U;
			VAR_RESET_AllReason_u8 = 4U;
			break;
		case MCU_STM1_RESET:
			VAR_RESET_McuReason_u8 = 5U;
			VAR_RESET_AllReason_u8 = 5U;
			break;
		case MCU_STM2_RESET:
			VAR_RESET_McuReason_u8 = 6U;
			VAR_RESET_AllReason_u8 = 6U;
			break;
		case MCU_POWER_ON_RESET:
			VAR_RESET_McuReason_u8 = 7U;
			VAR_RESET_AllReason_u8 = 7U;
			break;
		case MCU_CB0_RESET:
			VAR_RESET_McuReason_u8 = 8U;
			VAR_RESET_AllReason_u8 = 8U;
			break;
		case MCU_CB1_RESET:
			VAR_RESET_McuReason_u8 = 9U;
			VAR_RESET_AllReason_u8 = 9U;
			break;
		case MCU_CB3_RESET:
			VAR_RESET_McuReason_u8 = 10U;
			VAR_RESET_AllReason_u8 = 10U;
			break;
		case MCU_TP_RESET:
			VAR_RESET_McuReason_u8 = 11U;
			VAR_RESET_AllReason_u8 = 11U;
			break;
		case MCU_EVR13_RESET:
			VAR_RESET_McuReason_u8 = 12U;
			VAR_RESET_AllReason_u8 = 12U;
			break;
		case MCU_EVR33_RESET:
			VAR_RESET_McuReason_u8 = 13U;
			VAR_RESET_AllReason_u8 = 13U;
			break;
		case MCU_SUPPLY_WDOG_RESET:
			VAR_RESET_McuReason_u8 = 14U;
			VAR_RESET_AllReason_u8 = 14U;
			break;
		case MCU_STBYR_RESET:
			VAR_RESET_McuReason_u8 = 15U;
			VAR_RESET_AllReason_u8 = 15U;
			break;
		case MCU_RESET_MULTIPLE:
			VAR_RESET_McuReason_u8 = 154U;
			VAR_RESET_AllReason_u8 = 154U;
			break;
		case MCU_RESET_UNDEFINED:
			VAR_RESET_McuReason_u8 = 255U;
			VAR_RESET_AllReason_u8 = 255U;
			break;
		default:
			break;
		}

		/*read SW reset reason*/
		switch(rba_Reset_Env_History.Type_en)
		{
		case RBA_SYC_RESET_T15:
			VAR_RESET_AllReason_u8 = 16U;/*Reset caused by EcuM state transition*/
			break;
		case RBA_RESET_TRAP_E_OS_PROTECTION_MEMORY:
			VAR_RESET_AllReason_u8 = 17U;
			break;
		case RBA_RESET_TRAP_E_OS_PROTECTION_TIME:
			VAR_RESET_AllReason_u8 = 18U;
			break;
		case RBA_RESET_TRAP_E_OS_PROTECTION_ARRIVAL:
			VAR_RESET_AllReason_u8 = 19U;
			break;
		case RBA_RESET_TRAP_E_OS_PROTECTION_LOCKED:
			VAR_RESET_AllReason_u8 = 20U;
			break;
		case RBA_RESET_TRAP_E_OS_PROTECTION_EXCEPTION:
			VAR_RESET_AllReason_u8 = 21U;
			break;
		case SWRESET_UPPER_COMPUTER_SERVICES:
			VAR_RESET_AllReason_u8 = 22U;/*Reset caused by sys boot*/
			break;
		case RBA_RESET_CPU2_TRAP_NMI_SMU_CPU0_MPU_E:
			VAR_RESET_AllReason_u8 = 23U;/*Reset caused by MPU */
			break;
		case SWRESET_UDS_JUMP_TO_BOOT:
			VAR_RESET_AllReason_u8 = 24U;
			break;
		case SWRESET_UDS_SOFTRESET:
			VAR_RESET_AllReason_u8 = 25U;
			break;
		default:
			/* Do nothing*/
			break;
		}

		/*Store last reset info list,including reset reason and time-Stamp*/
		Reset_NvM_WriteResetInfoList();

		Reset_Init_Done = 0U;
    }
    else
    {
    	Reset_Init_Done = 0U;
    }
}

void Reset_NvM_WriteResetInfoList(void)
{
	/*Update reset info*/
	Laset_Reset_Info.Reset_Reason_u8 = VAR_RESET_McuReason_u8;
	Laset_Reset_Info.Reset_Vehicle_Odometer_u32 = Odometer_New;

	/*Update last RESET_INFOLIST_SIZE times reset info list*/
	Last_16_Reset_InfoList[0].Reset_Reason_u8 = Laset_Reset_Info.Reset_Reason_u8;
	Last_16_Reset_InfoList[0].Reset_Vehicle_Odometer_u32 = Laset_Reset_Info.Reset_Vehicle_Odometer_u32;
	VAR_RESET_Reason_List_au8[0] = Last_16_Reset_InfoList[0].Reset_Reason_u8;

	uint8 Loop_i = 0U;
	for(Loop_i = RESET_INFOLIST_SIZE - 1;Loop_i > 0U;Loop_i--)
	{
		Last_16_Reset_InfoList[Loop_i].Reset_Reason_u8 = Reset_List_History[Loop_i-1].Reset_Reason_u8;
		Last_16_Reset_InfoList[Loop_i].Reset_Vehicle_Odometer_u32 = Reset_List_History[Loop_i-1].Reset_Vehicle_Odometer_u32;
		VAR_RESET_Reason_List_au8[Loop_i] = Last_16_Reset_InfoList[Loop_i].Reset_Reason_u8;
	}

	NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvM_Reset_Info,Last_16_Reset_InfoList);
}

/*<RBHead>
 ***********************************************************************************************************************
 * List of changes
 *
 * $History
 * 

 * 
 * $
 *
 ***********************************************************************************************************************
</RBHead>*/
