/*
 * Xcp_OverlayMem.h
 *
 *  Created on: May 24, 2018
 *      Author: CIX2SGH
 */

#ifndef ECUINTEGRATION_INCLUDE_XCP_OVERLAYMEM_H_
#define ECUINTEGRATION_INCLUDE_XCP_OVERLAYMEM_H_

/*******************************************************************************
* Include Files
*******************************************************************************/
#include "Platform_Types.h"

#include "Std_Types.h"
#include "IfxOvc_reg.h"
#include "IfxScu_reg.h"
/*******************************************************************************
* Macro Definitions
*******************************************************************************/

extern uint32 __RODATA_CALIB_START[];
extern uint32 __RODATA_CALIB_END[];
//extern uint32 __RODATA_CPU1_CALIB_START[];
//extern uint32 __RODATA_CPU1_CALIB_END[];

#define SIZE_KB(size)       ((uint32)(size * 1024UL))
//#define CALFLASH_START_ADDR ((uint32)(0x80140000UL))
#define CALFLASH_START_ADDR  ((uint32)(__RODATA_CALIB_START))
#define CALRAM_START_ADDR   ((uint32)(0xB0000000UL))
#define CAL_MEM_TOTAL_SIZE        SIZE_KB(32)
#define CAL_MEM_USED_SIZE  ((((uint32)(__RODATA_CALIB_END)-(uint32)(__RODATA_CALIB_START))/4)*4+8)
/*
//#define CALFLASH_CPU1_START_ADDR ((uint32)(0x80146000UL))
#define CALFLASH_CPU1_START_ADDR  ((uint32)(__RODATA_CPU1_CALIB_START))
#define CALRAM_CPU1_START_ADDR    ((uint32)(0x60012700UL))
//#define CAL_CPU1_MEM_TOTAL_SIZE   SIZE_KB(16)
#define CAL_CPU1_MEM_USED_SIZE ((((uint32)(__RODATA_CPU1_CALIB_END)-(uint32)(__RODATA_CPU1_CALIB_START))/4)*4+8)
*/
#define CONVERT_TO_OVERLAYMEM_Addr(addr)  \
    ((uint32)addr - CALFLASH_START_ADDR + CALRAM_START_ADDR)

/*******************************************************************************
* Function Declarations
*******************************************************************************/
extern void Xcp_OverlayMem_Init(void);
extern void Xcp_OverlayMem_SetEnabled(boolean enabled);
extern void Xcp_OverlayMem_CheckEnabled(boolean *enabled);
extern void Xcp_OverlayMem_Sync(void);

#endif /* ECUINTEGRATION_INCLUDE_XCP_OVERLAYMEM_H_ */
