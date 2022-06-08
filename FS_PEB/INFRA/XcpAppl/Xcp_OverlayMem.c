/*
 * Xcp_OverlayMem.c
 *
 *  Created on: May 20, 2018
 *      Author: CIX2SGH
 */

/*******************************************************************************
* Include Files
*******************************************************************************/

#include "Xcp_OverlayMem.h"
#include "Xcp_Priv.h"

/*******************************************************************************
* Macro Definitions
*******************************************************************************/
/*
#define OVERLAY_MEM0_SIZE    SIZE_KB(64)
#define OVERLAY_MEM1_OFST    OVERLAY_MEM0_SIZE

#define MASTER_ENABLE_MASK  ((uint32)0x0FFFF0000UL)
#define OVERLAY_CRDSIZE_64K ((uint32)0x00000010UL)
*/


#define XCP_START_SEC_CODE
#include "Xcp_MemMap.h"
/*******************************************************************************
* Function Definitions
*******************************************************************************/
/*******************************************************************************
  Function name     :   Xcp_OverlayMem_init

  Description       :
  Parameter         :   none
  Return value      :   none

*******************************************************************************/
void Xcp_OverlayMem_Init(void)
{
	/* The calibration size is 24KB,
	 * Flash CAL: 0xAF05_8000H - 0xAF05_DFFFH, 24KB (16KB, 0xAF05_8000 - 0xAF05BFFF; 8KB, 0xAF05C000 - 0xAF05DFFF)
	 * Ram CAL  : 0x7000_0000H - 0x7000_5FFFH, 24KKB(16KB, 0x7000_0000 - 0x70003FFF; 8KB, 0x70004000 - 0x70005FFF)
	 */


	/* The calibration size is 24KB, but supported overlay block are 8,16,32,64KB...
	 * Here 2 overlay blocks are configured
	 * Block 0: size 16KB
	 * Block 1: size 8KB
	 */

	Mcal_ResetCpuENDINIT(-1);
	Mcal_ResetCpuENDINIT(0);
	SCU_OVCENABLE.B.OVEN0 = 1;
	SCU_OVCENABLE.B.OVEN1 = 1;
	SCU_OVCENABLE.B.OVEN2 = 1;
	Mcal_SetCpuENDINIT(0);
	Mcal_SetCpuENDINIT(-1);
	/* ----------------------------Start Configuration for Block 0 -----------------------------------*/

	OVC0_OSEL.B.SHOVEN0 	= 1; /* Enable overlay on Block 0 */

	OVC0_OMASK0.B.OMASK 	=  0xC00; /* 110000000000B, 32K block size */


	/* Base Address
	 * 								  |<-- OMASK--->|
	 * 0x8014_0000= 1000|0000|0001|0100|0000|0000|0000|0000
	 * OMASK      = 0000|1111|1111|1111|1000|0000|0000|0000 (0xC00)
	 * TBASE      = ****|0000|0001|0100|0000|0000|000*|****
	 * 			  = 	  000 0000 1010 0000 0000 0000 = 0x0A000
	 */

	OVC0_BLK0_OTAR.B.TBASE 	= 0xA000;

	/* Redirection to Core 0 DSPR/PSPR memory for Block 0 - 4kB */
	OVC0_BLK0_RABR.B.OMEM 	= 0x6;  /* 0, Core 0 DSPR; 1, Core 1 DSPR; 6 - Redirect to LMU memory; 7 - Redirection to EMEM; 3..5H Reserved, do not use */

	/* Overlay Address
	 * 								  |<-- OMASK--->|
	 * 0xB0000000 = 1011|0000|0000|0000|0000|0000|0000|0000
	 * OMASK      = 0000|1111|1111|1111|1000|0000|0000|0000 (0xC00,32k)
	 * OBASE      = ****|****|**00|0000|0000|0000|000*|****
	 * 			  =		        00 0000 0000 0000 0000 =0x000
	 */
	OVC0_BLK0_RABR.B.OBASE 	= 0x000;

	/* ---------------------------- End Configuration for Block 0 -------------------------------------*/
	/* ---------------------------- Start Configuration for Block 1 -----------------------------------*/

//	OVC0_OSEL.B.SHOVEN1 	= 1; /* Enable overlay on Block 1 */

//	OVC0_OMASK1.B.OMASK 	=  0xF00; /* 111100000000B, 8K block size */

	/* Base Address
	 * 								  |<-- OMASK---->|
	 * BaseAddr   = 1000|0000|0001|0100|0100|0000|0000|0000 (0x8014_4000)
	 * OMASK      = 0000|1111|1111|1111|1110|0000|0000|0000 (0xF00,8K)
	 * TBASE      = ****|0000 0001 0100 0100 0000 000*|****
	 * 			  = 	  000 0000 1010 0010 0000 0000 = 0xA200
	 */
//	OVC0_BLK1_OTAR.B.TBASE 	= 0xA200;
	/* Redirection to Core 0 DSPR/PSPR memory for Block 1 - 8kB */
//	OVC0_BLK1_RABR.B.OMEM 	= 0x0;  /* 0, Core 0 DSPR; 1, Core 1 DSPR; 6 - Redirect to LMU memory; 7 - Redirection to EMEM; 3..5H Reserved, do not use */

	/* Overlay Address
	 * 								  |<-- OMASK---->|
	 * OverAddr   = 0111|0000|0000|0001|1000|0000|0000|0000	(0x70018000)
	 * OMASK      = 0000|1111|1111|1111|1110|0000|0000|0000 (0xF00)
	 * OBASE      = ****|****|**00 0001 1000 0000 000*|****
	 * 			  =		        00 0000 1100 0000 0000 =0xC00
	 */

//	OVC0_BLK1_RABR.B.OBASE 	= 0xC00;
	/* ---------------------------- End Configuration for Block 1 -------------------------------------*/

	OVC1_OSEL.B.SHOVEN0 	= 1; /* Enable overlay on Block 0 */
	OVC1_OMASK0.B.OMASK 	=  0xC00;  /* 111000000000B, 16K block size */

	/* Base Address
		 * 								  |<-- OMASK--->|
		 * 0x8014_6000= 1000|0000|0001|0100|0110|0000|0000|0000
		 * OMASK      = 0000|1111|1111|1111|1100|0000|0000|0000 (0xE00)
		 * TBASE      = ****|0000|0001|0100|0100|0000|000*|****
		 * 			  = 	  000 0000 1010 0010 0000 0000 = 0x0A200
		 */
    OVC1_BLK0_OTAR.B.TBASE 	= 0xA000;
	OVC1_BLK0_RABR.B.OMEM 	= 0x6; /* 0, Core 0 DSPR; 1, Core 1 DSPR; 6 - Redirect to LMU memory; 7 - Redirection to EMEM; 3..5H Reserved, do not use */
	OVC1_BLK0_RABR.B.OBASE 	= 0x000;

	/* Overlay Address
		 * 								  |<-- OMASK--->|
		 * 0x60012700 = 0110|0000|0000|0001|0010|0111|0000|0000
		 * OMASK      = 0000|1111|1111|1111|1100|0000|0000|0000 (0xE00,16k)
		 * OBASE      = ****|****|**00|0001|0000|0000|000*|****
		 * 			  =		         0 0000 1000 0000 0000 =0x800
		 */
	/*
	OVC1_OSEL.B.SHOVEN1 	= 1;
	OVC1_OMASK1.B.OMASK 	=  0xF00;
	OVC1_BLK1_OTAR.B.TBASE 	= 0xA200;
	OVC1_BLK1_RABR.B.OMEM 	= 0x0;
	OVC1_BLK1_RABR.B.OBASE 	= 0xC00;
	*/


	OVC2_OSEL.B.SHOVEN0 	= 1;
	OVC2_OMASK0.B.OMASK 	=  0xC00;
	OVC2_BLK0_OTAR.B.TBASE 	= 0xA000;
	OVC2_BLK0_RABR.B.OMEM 	= 0x6;
	OVC2_BLK0_RABR.B.OBASE 	= 0x000;

	/*
	OVC2_OSEL.B.SHOVEN1 	= 1;
	OVC2_OMASK1.B.OMASK 	=  0xF00;
	OVC2_BLK1_OTAR.B.TBASE 	= 0xA200;
	OVC2_BLK1_RABR.B.OMEM 	= 0x0;
	OVC2_BLK1_RABR.B.OBASE 	= 0xC00;

	*/


	SCU_OVCCON.B.CSEL0 = 1; /* Select CPU0 */
	SCU_OVCCON.B.CSEL1 = 1; /* Select CPU1 */
	SCU_OVCCON.B.CSEL2 = 1; /* Select CPU2 */
	SCU_OVCCON.B.DCINVAL = 1; /* only use non-cached access */

//	SCU_OVCCON.B.OVCONF = 1;
//	SCU_OVCCON.B.POVCONF  = 1;
	SCU_OVCCON.U = 0x03000000;
}

/*******************************************************************************
  Function name     :   Xcp_OverlayMem_SetEnabled

  Description       :
  Parameter         :   enabled
  Return value      :   none

*******************************************************************************/
void Xcp_OverlayMem_SetEnabled(boolean enabled)
{
	/* XcpApp_CurrentCalPage is WORKING_CAL_PAGE; */

	if(enabled==TRUE)
	{
		SCU_OVCCON.U = 0x00050007;//Overlay Start, OVSTRT = 0
	}
	else
	{
		SCU_OVCCON.U = 0x00060007; //Overlay Stop, OVSTP = 1
	}

}

/*******************************************************************************
  Function name     :   Xcp_OverlayMem_CheckEnabled

  Description       :
  Parameter         :   *enabled
  Return value      :   none

*******************************************************************************/
void Xcp_OverlayMem_CheckEnabled(boolean *enabled)
{
    boolean overlay_enabled = FALSE;

    if (SCU_OVCCON.U == 0x00050007)
    {
        overlay_enabled = TRUE;
    }

    *enabled = overlay_enabled;
}

/*******************************************************************************
  Function name     :   Xcp_OverlayMem_Sync

  Description       :
  Parameter         :   none
  Return value      :   none

*******************************************************************************/
void Xcp_OverlayMem_Sync(void)
{
    Xcp_MemCopy((uint32*)CALRAM_START_ADDR,
                (uint32*)CALFLASH_START_ADDR,
				CAL_MEM_USED_SIZE);
/*
    Xcp_MemCopy((uint32*)CALRAM_CPU1_START_ADDR,
                (uint32*)CALFLASH_CPU1_START_ADDR,
				CAL_CPU1_MEM_USED_SIZE);
*/
}

#define XCP_STOP_SEC_CODE
#include "Xcp_MemMap.h"
