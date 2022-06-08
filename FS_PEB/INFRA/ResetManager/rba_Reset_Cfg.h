/*<RBHead>

 ***********************************************************************************************************************
 *
 * $UniqueName:$
 * $Component_:$
 *
 ***********************************************************************************************************************
</RBHead>*/

#ifndef RBA_RESET_CFG_H
#define RBA_RESET_CFG_H

/**
 ***************************************************************************************************
 * \moduledescription
 *                 rba_reset_cfg.h  - automatically generated configuration headerfile of RESET
 *                 module.
 *
 * \scope          CONF
 ***************************************************************************************************
 */




/* defines and enums */

/* define for legacy support */
#define RBA_RESET_LEGADAPTUSED

/* define for using rba_Reset component in ASW environment or SB/CB environment */
#define RBA_RESET_USED_IN_ASW_MAKE TRUE

/* defines for reset id offsets */
#define RBA_RESET_HWRIDOFFSET 0x0000uL
#define RBA_RESET_SBSWRIDOFFSET 0x1000uL
#define RBA_RESET_CBSWRIDOFFSET 0x2000uL
#define RBA_RESET_ASWSWRIDOFFSET 0x3000uL
#define RBA_RESET_ASWSFTRIDOFFSET 0x4000uL
#define RBA_RESET_CPU0_TRAPIDOFFSET 0x5000uL
#define RBA_RESET_CPU1_TRAPIDOFFSET 0x6000uL
#define RBA_RESET_CPU2_TRAPIDOFFSET 0x7000uL
#define RBA_RESET_CPU3_TRAPIDOFFSET 0x8000uL
#define RBA_RESET_CPU4_TRAPIDOFFSET 0x9000uL
#define RBA_RESET_CPU5_TRAPIDOFFSET 0xB000uL

/* defines for trap class number offsets */
#define RBA_RESET_TCN1_OFFSET 0x0003uL
#define RBA_RESET_TCN2_OFFSET 0x000CuL
#define RBA_RESET_TCN3_OFFSET 0x0013uL
#define RBA_RESET_TCN4_OFFSET 0x001CuL
#define RBA_RESET_TCN5_OFFSET 0x0179uL
#define RBA_RESET_TCN6_OFFSET 0x017DuL
#define RBA_RESET_TCN7_OFFSET 0x017EuL

/* defines for trap identification numbers */
#define RBA_RESET_TIN1  0x0001uL
#define RBA_RESET_TIN2  0x0002uL
#define RBA_RESET_TIN3  0x0003uL
#define RBA_RESET_TIN4  0x0004uL
#define RBA_RESET_TIN5  0x0005uL
#define RBA_RESET_TIN6  0x0006uL
#define RBA_RESET_TIN7  0x0007uL

/* defines TIN offset */
#define RBA_RESET_PIE_OFFSET   10uL
#define RBA_RESET_DIE_OFFSET   179uL

/* defines max number of On Chip Bus Master TAG Assignments */
#define RBA_RESET_NBR_TAG_ASSIGN         32uL
#define RBA_RESET_TRAP_ERROR_MSK        0x3800uL
#define RBA_RESET_BUSMASTER_OFFSET_MUTIPLC     8u

/* defines total number of Trap Reset id's in TCN-4 class */
#define RBA_RESET_FPU_OFFSET       4uL

/* defines total number of Trap Reset id's in TCN-7 class */
#define RBA_RESET_NMI_OFFSET       22uL

/* defines for DEM handling */
#define RBA_RESET_DEM_MAX   0x03uL
#define RBA_RESET_DEM_MSK   0x60uL

/* defines for history buffer */
/* history buffer size */
#define RBA_RESET_HISTBUF_SIZE 0x08
/* extended history buffer size */
#define RBA_RESET_EXTHISTBUF_SIZE 10
/* mask for visibility in resethistorybuffer */
#define RBA_RESET_HISTBUFVIS_MSK 0x80
/* Bitmask for visibility in ResetHistoryBuffer */
#define RBA_RESET_HISTBUF_VISIBLE 0x01

/* enum dem events */
typedef enum
{
    RBA_RESET_DEM_0,
    RBA_RESET_DEM_1,
    RBA_RESET_DEM_2 
}rba_Reset_DemEvent_ten;



/* enum reset group ids */
typedef enum
{
/* enum for fix reset group ids */
    RBA_RESET_GRP_POWERON_E,    /* PowerOn reset group id */
    RBA_RESET_GRP_HWRESET_E,    /* hw reset group id */
    RBA_RESET_GRP_TRAP_E,    /* trap group id */
    RBA_RESET_GRP_TRAP,    /* trap1 group id */
    RBA_RESET_GRP_FES_E,    /* trap2 group id */
    RBA_RESET_GRP_SMU_E,    /* smu group id */
    RBA_RESET_GRP_WDT_E,    /* wdt group id */
    RBA_RESET_GRP_SB_E,    /* sb reset group id */
    RBA_RESET_GRP_CB_E,    /* cb reset group id */
    RBA_RESET_GRP_SOFTRESET_E,    /* softreset group id */
    RBA_RESET_GRP_SYC_KL15RST_E,    /* reset group for syc T15 handling */
/* enum for ASW reset group ids */
    MCU_RB_DTS_SENSOR,
    MCU_RB_GET_RESET_REASON,
    MCU_RB_MCU_PERFORM_RESET,
    MCU_RB_RESET_BUSERR_GRP,
    RBA_EMM_RESET_GROUP,
    RBA_MPU_RESET_GROUP,
    RBA_MULTISTACKTRACE_RESETGROUP,
    RBA_RESET_EEP_ENVRAM_GRP_E,
    RBA_RESET_EEP_FIRSTINIT_GRP_E,
    RBA_RESET_FIRST_GRP,
    RBA_RESET_GRP_BSW_DEFAULT_E,
    RBA_RESET_GRP_RBA_BSWSRV_E,
    RBA_RESET_RBA_MEMLAY_E,
    RBA_SWTRACE_RESETGROUP,
    RBA_SYC,
    RBA_SYC_POWERUNDERVOLTAGE_RSTGRP,
    RBA_SYC_SHUTDOWNSERVICES,
    RBE_OSSHELL_RESETGROUP,
    RBE_RESET_GROUP_CDDMONHW,
    RESET_SWRESET_ESC_E,
    SWRESET_SYCGRP_E,
    RBA_RESET_GRP_NUMASW_E
}rba_Reset_Grp_ten;



/* enum for Reset Ids */
/* MR12 RULE 10.1, 10.3, 10.5 VIOLATION: enums necessary due to debugging issues!! Approved by MISRA2012_SUPPORT_TEAM.*/
typedef enum
{
/* enum for HWResets */
    RBA_RESET_POWERON_E = RBA_RESET_HWRIDOFFSET,    /* PowerOn Reset */
    RBA_RESET_POWERON_WARM_E = RBA_RESET_HWRIDOFFSET + 1,    /* Warm PowerOn Reset */
    RBA_RESET_POWERON_WDT_E = RBA_RESET_HWRIDOFFSET + 2,    /* PowerOn Monitoring Modul Reset */
    RBA_RESET_POWERON_KL15_E = RBA_RESET_HWRIDOFFSET + 3,    /* NOT USED: PowerOn T15 Reset */
    RBA_RESET_ESR0_E = RBA_RESET_HWRIDOFFSET + 4,    /* ESR0 Line Reset */
    RBA_RESET_ESR1_E = RBA_RESET_HWRIDOFFSET + 5,    /* ESR1 Line Reset */
    RBA_RESET_WDT_E = RBA_RESET_HWRIDOFFSET + 6,    /* NOT USED: Watchdog Reset */
    RBA_RESET_SMU_E = RBA_RESET_HWRIDOFFSET + 7,    /* SMU Reset */
    RBA_RESET_STM0_E = RBA_RESET_HWRIDOFFSET + 8,    /* STM0 Cerberus System Reset */
    RBA_RESET_STM1_E = RBA_RESET_HWRIDOFFSET + 9,    /* STM1 Cerberus System Rese */
	RBA_RESET_STM2_E = RBA_RESET_HWRIDOFFSET + 10,    /* STM2 Cerberus System Reset */
    RBA_RESET_CB_E = RBA_RESET_HWRIDOFFSET + 11,    /* CB System Reset */
	RBA_RESET_EVR_E = RBA_RESET_HWRIDOFFSET + 12,    /* EVR Reset */
    RBA_RESET_SUPPLY_WDOG_E = RBA_RESET_HWRIDOFFSET + 13,    /*Supply watch dog Reset */
    RBA_RESET_STBYR_E = RBA_RESET_HWRIDOFFSET + 14,    /* Standby watch dog reset */
    RBA_RESET_PIN1WAK_E = RBA_RESET_HWRIDOFFSET + 15,    /* PIN1 wakeup reset */
    RBA_RESET_PIN2WAK_E = RBA_RESET_HWRIDOFFSET + 16,    /* PIN2 wakeup reset */
    RBA_RESET_PIN3WAK_E = RBA_RESET_HWRIDOFFSET + 17,    /* PIN3 wakeup reset */
    RBA_RESET_STCWAK_E = RBA_RESET_HWRIDOFFSET + 18,    /* StopCounter wakeup reset */
    RBA_RESET_HW_E = RBA_RESET_HWRIDOFFSET + 19,    /* NOT USED: HW Reset */
/* enum for CPU0 traps */
    RBA_RESET_TRAP_E_OS_PROTECTION_MEMORY = RBA_RESET_CPU0_TRAPIDOFFSET,    /* TCN = 0, TIN = 0: MMU: Virtual Address Fill */
	RBA_RESET_TRAP_E_OS_PROTECTION_TIME = RBA_RESET_CPU0_TRAPIDOFFSET + 1,    /* TCN = 0, TIN = 1: MMU: Virtual Address Protection */
    RBA_RESET_TRAP_E_OS_PROTECTION_ARRIVAL = RBA_RESET_CPU0_TRAPIDOFFSET + 2,    /* TCN = 0, TIN = >1  */
	RBA_RESET_TRAP_E_OS_PROTECTION_LOCKED = RBA_RESET_CPU0_TRAPIDOFFSET + 3,    /* TCN = 1, TIN = 0: Unknown  */
	RBA_RESET_TRAP_E_OS_PROTECTION_EXCEPTION = RBA_RESET_CPU0_TRAPIDOFFSET + 4,    /* TCN = 1, TIN = 1: Privileged Instruction */
	RBA_RESET_TRAP_E_OS_PROTECTION_MORE = RBA_RESET_CPU0_TRAPIDOFFSET + 5,    /* TCN = 1, TIN = 2: Memory Protection: Read Access */
    RBA_RESET_CPU0_TRAP_INTPROT_MPW_E = RBA_RESET_CPU0_TRAPIDOFFSET + 6,    /* TCN = 1, TIN = 3: Memory Protection: Write Access */
    RBA_RESET_CPU0_TRAP_INTPROT_MPX_E = RBA_RESET_CPU0_TRAPIDOFFSET + 7,    /* TCN = 1, TIN = 4: Memory Protection: Execution Access */
    RBA_RESET_CPU0_TRAP_INTPROT_MPP_E = RBA_RESET_CPU0_TRAPIDOFFSET + 8,    /* TCN = 1, TIN = 5: Memory Protection: Peripheral Access */
    RBA_RESET_CPU0_TRAP_INTPROT_MPN_E = RBA_RESET_CPU0_TRAPIDOFFSET + 9,    /* TCN = 1, TIN = 6: Memory Protection: Null Address */
    RBA_RESET_CPU0_TRAP_INTPROT_GRWP_E = RBA_RESET_CPU0_TRAPIDOFFSET + 10,    /* TCN = 1, TIN = 7: Global Register Write Protection */
    RBA_RESET_CPU0_TRAP_TCN1_UNKNOWN_E = RBA_RESET_CPU0_TRAPIDOFFSET + 11,    /* TCN = 1, TIN = >7  */
    RBA_RESET_CPU0_TRAP_TCN2_TIN0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 12,    /* TCN = 2, TIN = : Unknown */
    RBA_RESET_CPU0_TRAP_INSTRERR_IOPC_E = RBA_RESET_CPU0_TRAPIDOFFSET + 13,    /* TCN = 2, TIN = 1: Illegal Opcode */
    RBA_RESET_CPU0_TRAP_INSTRERR_UOPC_E = RBA_RESET_CPU0_TRAPIDOFFSET + 14,    /* TCN = 2, TIN = 2: Unimplemented Opcode */
    RBA_RESET_CPU0_TRAP_INSTRERR_OPD_E = RBA_RESET_CPU0_TRAPIDOFFSET + 15,    /* TCN = 2, TIN = 3: Invalid Operand Specification */
    RBA_RESET_CPU0_TRAP_INSTRERR_ALN_E = RBA_RESET_CPU0_TRAPIDOFFSET + 16,    /* TCN = 2, TIN = 4: Data Address Alignment Error */
    RBA_RESET_CPU0_TRAP_INSTRERR_MEM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 17,    /* TCN = 2, TIN = 5: Invalid Local Memory Address */
    RBA_RESET_CPU0_TRAP_TCN2_UNKNOWN_E = RBA_RESET_CPU0_TRAPIDOFFSET + 18,    /* TCN = 2, TIN = >5  */
    RBA_RESET_CPU0_TRAP_TCN3_TIN0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 19,    /* TCN = 3, TIN = 0: Unknown */
    RBA_RESET_CPU0_TRAP_CONTMANA_FCD_E = RBA_RESET_CPU0_TRAPIDOFFSET + 20,    /* TCN = 3, TIN = 1: Free Context List Depleted */
    RBA_RESET_CPU0_TRAP_CONTMANA_CDO_E = RBA_RESET_CPU0_TRAPIDOFFSET + 21,    /* TCN = 3, TIN = 2: Call Depth Overflow */
    RBA_RESET_CPU0_TRAP_CONTMANA_CDU_E = RBA_RESET_CPU0_TRAPIDOFFSET + 22,    /* TCN = 3, TIN = 3: Call Depth Underflow */
    RBA_RESET_CPU0_TRAP_CONTMANA_FCU_E = RBA_RESET_CPU0_TRAPIDOFFSET + 23,    /* TCN = 3, TIN = 4: Free Context List Underflow */
    RBA_RESET_CPU0_TRAP_CONTMANA_CSU_E = RBA_RESET_CPU0_TRAPIDOFFSET + 24,    /* TCN = 3, TIN = 5: Context List Underflow */
    RBA_RESET_CPU0_TRAP_CONTMANA_CTYP_E = RBA_RESET_CPU0_TRAPIDOFFSET + 25,    /* TCN = 3, TIN = 6: Context Type Error */
    RBA_RESET_CPU0_TRAP_CONTMANA_NEST_E = RBA_RESET_CPU0_TRAPIDOFFSET + 26,    /* TCN = 3, TIN = 7: Nesting Error */
    RBA_RESET_CPU0_TRAP_TCN3_UNKNOWN_E = RBA_RESET_CPU0_TRAPIDOFFSET + 27,    /* TCN = 3, TIN = >7  */
    RBA_RESET_CPU0_TRAP_TCN4_TIN0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 28,    /* TCN = 4, TIN = 0: Unknown */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PSE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 29,    /* TCN = 4, TIN = 1: Program Fetch Synchronous Error */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DSE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 30,    /* TCN = 4, TIN = 2: Data Access Synchronous Error */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DAE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 31,    /* TCN = 4, TIN = 3: Data Access Asynchronous Error */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_CAE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 32,    /* TCN = 4, TIN = 4: Coprocessor TRAP_ Asynchronous Error */
    RBA_RESET_CPU0_TRAP_FPU_RNRSLT_E = RBA_RESET_CPU0_TRAPIDOFFSET + 33,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Rounded Result Error */
    RBA_RESET_CPU0_TRAP_FPU_UNRFLW_E = RBA_RESET_CPU0_TRAPIDOFFSET + 34,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Under Flow Error */
    RBA_RESET_CPU0_TRAP_FPU_DIVZRO_E = RBA_RESET_CPU0_TRAPIDOFFSET + 35,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Deivided By Zero Error */
    RBA_RESET_CPU0_TRAP_FPU_OVRFLW_E = RBA_RESET_CPU0_TRAPIDOFFSET + 36,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Over Flow Error */
    RBA_RESET_CPU0_TRAP_FPU_INVOPR_E = RBA_RESET_CPU0_TRAPIDOFFSET + 37,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Invalid Operation Error */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_UNKNOWN_E = RBA_RESET_CPU0_TRAPIDOFFSET + 38,    /* TCN = 4, TIN = 5: no bit is set in PIETR */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 39,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 40,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 41,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 42,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 43,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 44,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 45,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 46,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 47,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 48,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 49,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 50,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 51,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 52,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 53,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 54,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 55,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 56,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 57,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 58,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 59,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 60,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 61,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 62,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 63,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 64,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 65,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 66,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 67,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 68,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 69,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 70,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 71,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 72,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 73,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 74,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 75,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 76,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 77,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 78,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 79,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 80,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 81,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 82,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 83,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 84,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 85,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 86,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 87,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 88,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 89,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 90,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 91,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 92,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 93,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 94,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 95,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 96,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 97,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 98,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 99,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 100,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 101,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 102,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 103,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 104,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 105,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 106,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 107,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 108,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 109,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 110,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 111,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 112,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 113,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 114,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 115,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 116,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 117,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 118,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 119,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 120,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 121,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 122,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 123,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 124,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 125,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 126,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 127,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 128,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 129,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 130,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 131,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 132,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 133,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 134,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 135,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 136,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 137,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 138,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 139,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 140,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 141,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 142,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 143,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 144,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 145,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 146,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 147,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 148,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 149,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 150,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 151,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 152,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 153,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 154,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 155,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 156,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 157,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 158,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 159,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 160,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 161,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 162,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 163,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 164,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 165,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 166,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 167,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 168,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 169,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 170,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 171,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 172,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 173,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 174,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 175,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 176,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 177,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 178,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 179,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 180,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 181,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 182,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 183,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 184,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 185,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 186,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 187,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 188,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 189,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 190,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 191,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 192,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 193,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 194,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 195,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 196,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 197,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 198,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IED_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 199,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_T_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 200,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_C_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 201,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_S_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 202,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BI_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 203,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_UNC_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 204,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_SP_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 205,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_PIE_IE_BS_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 206,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_UNKNOWN_E = RBA_RESET_CPU0_TRAPIDOFFSET + 207,    /* TCN = 4, TIN = 6: no bit is set in DIETR */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 208,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 209,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 210,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 211,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 212,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 213,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 214,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 215,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 216,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 217,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 218,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 219,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 220,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 221,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 222,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_CPU0_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 223,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 224,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 225,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 226,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 227,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 228,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 229,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 230,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 231,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 232,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 233,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 234,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 235,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 236,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 237,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 238,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_CPU1_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 239,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 240,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 241,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 242,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 243,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 244,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 245,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 246,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 247,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 248,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 249,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 250,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 251,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 252,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 253,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 254,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_CPU2_DMI_SAFE_E = RBA_RESET_CPU0_TRAPIDOFFSET + 255,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 256,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 257,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 258,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 259,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 260,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 261,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 262,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_DMA_PARTITION_0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 263,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 264,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 265,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 266,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 267,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 268,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 269,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 270,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_DMA_PARTITION_1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 271,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 272,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 273,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 274,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 275,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 276,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 277,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 278,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_DMA_PARTITION_2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 279,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 280,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 281,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 282,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 283,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 284,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 285,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 286,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_DMA_PARTITION_3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 287,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 288,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 289,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 290,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 291,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 292,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 293,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 294,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_DMA_CERBERUS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 295,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 296,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 297,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 298,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 299,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 300,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 301,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 302,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_HSSL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 303,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 304,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 305,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 306,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 307,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 308,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 309,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 310,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_ETHERNET_E = RBA_RESET_CPU0_TRAPIDOFFSET + 311,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 312,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 313,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 314,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 315,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 316,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 317,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 318,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_HSM_HSMCMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 319,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 320,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 321,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 322,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 323,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 324,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 325,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 326,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_CPU0_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 327,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 328,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 329,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 330,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 331,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 332,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 333,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 334,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_CPU1_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 335,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 336,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 337,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 338,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 339,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 340,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 341,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 342,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_CPU2_PMI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 343,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 344,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 345,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 346,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 347,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 348,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 349,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 350,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_DAM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 351,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 352,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 353,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 354,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 355,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 356,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 357,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 358,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_CERBERUS_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 359,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 360,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 361,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 362,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 363,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 364,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 365,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 366,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_EMEM_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 367,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IED_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 368,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_T_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 369,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Tag Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_C_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 370,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Cache Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_S_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 371,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BI_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 372,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Bus Interface */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_UNC_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 373,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_SP_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 374,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU0_TRAP_SYSBUSERR_DIE_IE_BS_CIF_MASTER_BBB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 375,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU0_TRAP_TCN4_UNKNOWN_E = RBA_RESET_CPU0_TRAPIDOFFSET + 376,    /* TCN = 4, TIN = >6: Unknown */
    RBA_RESET_CPU0_TRAP_TCN5_TIN0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 377,    /* TCN = 5, TIN = 0: Unknown */
    RBA_RESET_CPU0_TRAP_ASSTRAP_OVF_E = RBA_RESET_CPU0_TRAPIDOFFSET + 378,    /* TCN = 5, TIN = 1: Arithmetic Overflow */
    RBA_RESET_CPU0_TRAP_ASSTRAP_SOVF_E = RBA_RESET_CPU0_TRAPIDOFFSET + 379,    /* TCN = 5, TIN = 2: Sticky Arithmetic Overflow */
    RBA_RESET_CPU0_TRAP_TCN5_UNKNOWN_E = RBA_RESET_CPU0_TRAPIDOFFSET + 380,    /* TCN = 5, TIN = >2  */
    RBA_RESET_CPU0_TRAP_SYSCALL_SYS_E = RBA_RESET_CPU0_TRAPIDOFFSET + 381,    /* TCN = 6, TIN = 0-255: System Call */
    RBA_RESET_CPU0_TRAP_NMI_UNKNOWN_E = RBA_RESET_CPU0_TRAPIDOFFSET + 382,    /* TCN = 7, TIN = 0: no SMUT, no ESR1, no ESR0 bit */
    RBA_RESET_CPU0_TRAP_NMI_ESR0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 383,    /* TCN = 7, TIN = 0: NMI ESR0 */
    RBA_RESET_CPU0_TRAP_NMI_ESR1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 384,    /* TCN = 7, TIN = 0: NMI ESR1 */
    RBA_RESET_CPU0_TRAP_NMI_SMUT_E = RBA_RESET_CPU0_TRAPIDOFFSET + 385,    /* TCN = 7, TIN = 0: NMI SMUT additional information under */
    RBA_RESET_CPU0_TRAP_NMI_SMU_CPU0_MPU_E = RBA_RESET_CPU0_TRAPIDOFFSET + 386,    /* TCN = 7, TIN = 0: NMI SMUT CPU0: MPU error (registers, DSPR, PSPR) */
    RBA_RESET_CPU0_TRAP_NMI_SMU_CPU1_MPU_E = RBA_RESET_CPU0_TRAPIDOFFSET + 387,    /* TCN = 7, TIN = 0: NMI SMUT CPU1: MPU error (registers, DSPR, PSPR) */
    RBA_RESET_CPU0_TRAP_NMI_SMU_CPU2_MPU_E = RBA_RESET_CPU0_TRAPIDOFFSET + 388,    /* TCN = 7, TIN = 0: NMI SMUT CPU2: MPU error (registers, DSPR, PSPR) */
    RBA_RESET_CPU0_TRAP_NMI_SMU_IR_E = RBA_RESET_CPU0_TRAPIDOFFSET + 389,    /* TCN = 7, TIN = 0: NMI SMUT IR: Interrupt Monitor: EDC error */
    RBA_RESET_CPU0_TRAP_NMI_SMU_CGU_WDT_E = RBA_RESET_CPU0_TRAPIDOFFSET + 390,    /* TCN = 7, TIN = 0: NMI SMUT CGU WDT:  System PLL OSC_WDT: out of range input clock */
    RBA_RESET_CPU0_TRAP_NMI_SMU_CGU_PLLLOL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 391,    /* TCN = 7, TIN = 0: NMI SMUT CGU PLL LossOfLock:  System PLL VCO Loss-of-Lock Event */
    RBA_RESET_CPU0_TRAP_NMI_SMU_CGU_PLLERAYLOL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 392,    /* TCN = 7, TIN = 0: NMI SMUT CGU PLL ERAY LossOfLock:  PLL_ERAY VCO Loss-of-Lock Event */
    RBA_RESET_CPU0_TRAP_NMI_SMU_CGU_STM_E = RBA_RESET_CPU0_TRAPIDOFFSET + 393,    /* TCN = 7, TIN = 0: NMI SMUT CGU STM:  Clock monitoring: Out of range frequency STM */
    RBA_RESET_CPU0_TRAP_NMI_SMU_CGU_PLLERAY_E = RBA_RESET_CPU0_TRAPIDOFFSET + 394,    /* TCN = 7, TIN = 0: NMI SMUT CGU PLLERAY:  Clock monitoring: Out of range frequency PLL_ERAY */
    RBA_RESET_CPU0_TRAP_NMI_SMU_CGU_PLL_E = RBA_RESET_CPU0_TRAPIDOFFSET + 395,    /* TCN = 7, TIN = 0: NMI SMUT CGU PLL: Clock monitoring: Out of range frequency System PLL */
    RBA_RESET_CPU0_TRAP_NMI_SMU_CGU_SRI_E = RBA_RESET_CPU0_TRAPIDOFFSET + 396,    /* TCN = 7, TIN = 0: NMI SMUT CGU SRI:  Clock monitoring: Out of range frequency SRI */
    RBA_RESET_CPU0_TRAP_NMI_SMU_CGU_SPB_E = RBA_RESET_CPU0_TRAPIDOFFSET + 397,    /* TCN = 7, TIN = 0: NMI SMUT CGU SPB:  Clock monitoring: Out of range frequency SPB */
    RBA_RESET_CPU0_TRAP_NMI_SMU_CGU_CPU0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 398,    /* TCN = 7, TIN = 0: NMI SMUT CGU CPU0: Clock monitoring: Out of range frequency CPU0 */
    RBA_RESET_CPU0_TRAP_NMI_SMU_SCUEVR_12UV_E = RBA_RESET_CPU0_TRAPIDOFFSET + 399,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 1.2V digital undervoltage */
    RBA_RESET_CPU0_TRAP_NMI_SMU_SCUEVR_12OV_E = RBA_RESET_CPU0_TRAPIDOFFSET + 400,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 1.2V digital overvoltage */
    RBA_RESET_CPU0_TRAP_NMI_SMU_SCUEVR_33UV_E = RBA_RESET_CPU0_TRAPIDOFFSET + 401,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 3.3V undervoltage */
    RBA_RESET_CPU0_TRAP_NMI_SMU_SCUEVR_33OV_E = RBA_RESET_CPU0_TRAPIDOFFSET + 402,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 3.3V overvoltage */
    RBA_RESET_CPU0_TRAP_NMI_SMU_SCUEVR_5UV_E = RBA_RESET_CPU0_TRAPIDOFFSET + 403,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 5V supply undervoltage */
    RBA_RESET_CPU0_TRAP_NMI_SMU_SCUEVR_5OV_E = RBA_RESET_CPU0_TRAPIDOFFSET + 404,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 5V supply overvoltage */
    RBA_RESET_CPU0_TRAP_NMI_SMU_SWDT_E = RBA_RESET_CPU0_TRAPIDOFFSET + 405,    /* TCN = 7, TIN = 0: NMI SMUT: safety watchdog timeout */
    RBA_RESET_CPU0_TRAP_NMI_SMU_WDT0_E = RBA_RESET_CPU0_TRAPIDOFFSET + 406,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog0 timeout */
    RBA_RESET_CPU0_TRAP_NMI_SMU_WDT1_E = RBA_RESET_CPU0_TRAPIDOFFSET + 407,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog1 timeout */
    RBA_RESET_CPU0_TRAP_NMI_SMU_WDT2_E = RBA_RESET_CPU0_TRAPIDOFFSET + 408,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog2 timeout */
    RBA_RESET_CPU0_TRAP_NMI_SMU_WDT3_E = RBA_RESET_CPU0_TRAPIDOFFSET + 409,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog3 timeout */
    RBA_RESET_CPU0_TRAP_NMI_SMU_WDT4_E = RBA_RESET_CPU0_TRAPIDOFFSET + 410,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog4 timeout */
    RBA_RESET_CPU0_TRAP_NMI_SMU_WDT5_E = RBA_RESET_CPU0_TRAPIDOFFSET + 411,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog5 timeout */
    RBA_RESET_CPU0_TRAP_TCN7_UNKNOWN_E = RBA_RESET_CPU0_TRAPIDOFFSET + 412,    /* TCN = 7, TIN = >0 */
/* enum for CPU1 traps */
    RBA_RESET_CPU1_TRAP_MMU_VAF_E = RBA_RESET_CPU1_TRAPIDOFFSET,    /* TCN = 0, TIN = 0: MMU: Virtual Address Fill */
    RBA_RESET_CPU1_TRAP_MMU_VAP_E = RBA_RESET_CPU1_TRAPIDOFFSET + 1,    /* TCN = 0, TIN = 1: MMU: Virtual Address Protection */
    RBA_RESET_CPU1_TRAP_TCN0_UNKNOWN_E = RBA_RESET_CPU1_TRAPIDOFFSET + 2,    /* TCN = 0, TIN = >1  */
    RBA_RESET_CPU1_TRAP_TCN1_TIN0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 3,    /* TCN = 1, TIN = 0: Unknown  */
    RBA_RESET_CPU1_TRAP_INTPROT_PRIV_E = RBA_RESET_CPU1_TRAPIDOFFSET + 4,    /* TCN = 1, TIN = 1: Privileged Instruction */
    RBA_RESET_CPU1_TRAP_INTPROT_MPR_E = RBA_RESET_CPU1_TRAPIDOFFSET + 5,    /* TCN = 1, TIN = 2: Memory Protection: Read Access */
    RBA_RESET_CPU1_TRAP_INTPROT_MPW_E = RBA_RESET_CPU1_TRAPIDOFFSET + 6,    /* TCN = 1, TIN = 3: Memory Protection: Write Access */
    RBA_RESET_CPU1_TRAP_INTPROT_MPX_E = RBA_RESET_CPU1_TRAPIDOFFSET + 7,    /* TCN = 1, TIN = 4: Memory Protection: Execution Access */
    RBA_RESET_CPU1_TRAP_INTPROT_MPP_E = RBA_RESET_CPU1_TRAPIDOFFSET + 8,    /* TCN = 1, TIN = 5: Memory Protection: Peripheral Access */
    RBA_RESET_CPU1_TRAP_INTPROT_MPN_E = RBA_RESET_CPU1_TRAPIDOFFSET + 9,    /* TCN = 1, TIN = 6: Memory Protection: Null Address */
    RBA_RESET_CPU1_TRAP_INTPROT_GRWP_E = RBA_RESET_CPU1_TRAPIDOFFSET + 10,    /* TCN = 1, TIN = 7: Global Register Write Protection */
    RBA_RESET_CPU1_TRAP_TCN1_UNKNOWN_E = RBA_RESET_CPU1_TRAPIDOFFSET + 11,    /* TCN = 1, TIN = >7  */
    RBA_RESET_CPU1_TRAP_TCN2_TIN0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 12,    /* TCN = 2, TIN = : Unknown */
    RBA_RESET_CPU1_TRAP_INSTRERR_IOPC_E = RBA_RESET_CPU1_TRAPIDOFFSET + 13,    /* TCN = 2, TIN = 1: Illegal Opcode */
    RBA_RESET_CPU1_TRAP_INSTRERR_UOPC_E = RBA_RESET_CPU1_TRAPIDOFFSET + 14,    /* TCN = 2, TIN = 2: Unimplemented Opcode */
    RBA_RESET_CPU1_TRAP_INSTRERR_OPD_E = RBA_RESET_CPU1_TRAPIDOFFSET + 15,    /* TCN = 2, TIN = 3: Invalid Operand Specification */
    RBA_RESET_CPU1_TRAP_INSTRERR_ALN_E = RBA_RESET_CPU1_TRAPIDOFFSET + 16,    /* TCN = 2, TIN = 4: Data Address Alignment Error */
    RBA_RESET_CPU1_TRAP_INSTRERR_MEM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 17,    /* TCN = 2, TIN = 5: Invalid Local Memory Address */
    RBA_RESET_CPU1_TRAP_TCN2_UNKNOWN_E = RBA_RESET_CPU1_TRAPIDOFFSET + 18,    /* TCN = 2, TIN = >5  */
    RBA_RESET_CPU1_TRAP_TCN3_TIN0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 19,    /* TCN = 3, TIN = 0: Unknown */
    RBA_RESET_CPU1_TRAP_CONTMANA_FCD_E = RBA_RESET_CPU1_TRAPIDOFFSET + 20,    /* TCN = 3, TIN = 1: Free Context List Depleted */
    RBA_RESET_CPU1_TRAP_CONTMANA_CDO_E = RBA_RESET_CPU1_TRAPIDOFFSET + 21,    /* TCN = 3, TIN = 2: Call Depth Overflow */
    RBA_RESET_CPU1_TRAP_CONTMANA_CDU_E = RBA_RESET_CPU1_TRAPIDOFFSET + 22,    /* TCN = 3, TIN = 3: Call Depth Underflow */
    RBA_RESET_CPU1_TRAP_CONTMANA_FCU_E = RBA_RESET_CPU1_TRAPIDOFFSET + 23,    /* TCN = 3, TIN = 4: Free Context List Underflow */
    RBA_RESET_CPU1_TRAP_CONTMANA_CSU_E = RBA_RESET_CPU1_TRAPIDOFFSET + 24,    /* TCN = 3, TIN = 5: Context List Underflow */
    RBA_RESET_CPU1_TRAP_CONTMANA_CTYP_E = RBA_RESET_CPU1_TRAPIDOFFSET + 25,    /* TCN = 3, TIN = 6: Context Type Error */
    RBA_RESET_CPU1_TRAP_CONTMANA_NEST_E = RBA_RESET_CPU1_TRAPIDOFFSET + 26,    /* TCN = 3, TIN = 7: Nesting Error */
    RBA_RESET_CPU1_TRAP_TCN3_UNKNOWN_E = RBA_RESET_CPU1_TRAPIDOFFSET + 27,    /* TCN = 3, TIN = >7  */
    RBA_RESET_CPU1_TRAP_TCN4_TIN0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 28,    /* TCN = 4, TIN = 0: Unknown */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PSE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 29,    /* TCN = 4, TIN = 1: Program Fetch Synchronous Error */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DSE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 30,    /* TCN = 4, TIN = 2: Data Access Synchronous Error */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DAE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 31,    /* TCN = 4, TIN = 3: Data Access Asynchronous Error */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_CAE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 32,    /* TCN = 4, TIN = 4: Coprocessor TRAP_ Asynchronous Error */
    RBA_RESET_CPU1_TRAP_FPU_RNRSLT_E = RBA_RESET_CPU1_TRAPIDOFFSET + 33,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Rounded Result Error */
    RBA_RESET_CPU1_TRAP_FPU_UNRFLW_E = RBA_RESET_CPU1_TRAPIDOFFSET + 34,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Under Flow Error */
    RBA_RESET_CPU1_TRAP_FPU_DIVZRO_E = RBA_RESET_CPU1_TRAPIDOFFSET + 35,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Deivided By Zero Error */
    RBA_RESET_CPU1_TRAP_FPU_OVRFLW_E = RBA_RESET_CPU1_TRAPIDOFFSET + 36,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Over Flow Error */
    RBA_RESET_CPU1_TRAP_FPU_INVOPR_E = RBA_RESET_CPU1_TRAPIDOFFSET + 37,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Invalid Operation Error */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_UNKNOWN_E = RBA_RESET_CPU1_TRAPIDOFFSET + 38,    /* TCN = 4, TIN = 5: no bit is set in PIETR */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 39,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 40,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 41,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 42,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 43,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 44,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 45,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 46,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 47,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 48,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 49,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 50,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 51,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 52,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 53,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 54,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 55,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 56,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 57,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 58,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 59,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 60,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 61,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 62,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 63,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 64,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 65,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 66,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 67,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 68,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 69,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 70,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 71,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 72,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 73,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 74,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 75,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 76,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 77,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 78,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 79,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 80,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 81,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 82,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 83,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 84,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 85,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 86,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 87,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 88,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 89,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 90,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 91,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 92,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 93,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 94,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 95,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 96,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 97,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 98,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 99,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 100,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 101,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 102,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 103,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 104,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 105,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 106,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 107,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 108,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 109,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 110,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 111,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 112,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 113,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 114,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 115,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 116,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 117,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 118,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 119,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 120,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 121,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 122,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 123,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 124,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 125,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 126,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 127,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 128,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 129,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 130,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 131,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 132,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 133,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 134,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 135,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 136,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 137,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 138,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 139,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 140,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 141,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 142,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 143,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 144,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 145,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 146,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 147,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 148,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 149,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 150,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 151,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 152,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 153,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 154,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 155,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 156,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 157,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 158,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 159,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 160,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 161,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 162,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 163,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 164,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 165,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 166,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 167,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 168,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 169,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 170,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 171,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 172,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 173,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 174,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 175,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 176,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 177,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 178,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 179,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 180,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 181,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 182,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 183,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 184,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 185,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 186,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 187,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 188,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 189,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 190,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 191,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 192,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 193,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 194,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 195,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 196,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 197,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 198,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IED_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 199,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_T_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 200,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_C_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 201,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_S_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 202,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BI_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 203,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_UNC_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 204,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_SP_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 205,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_PIE_IE_BS_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 206,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_UNKNOWN_E = RBA_RESET_CPU1_TRAPIDOFFSET + 207,    /* TCN = 4, TIN = 6: no bit is set in DIETR */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 208,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 209,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 210,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 211,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 212,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 213,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 214,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 215,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 216,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 217,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 218,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 219,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 220,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 221,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 222,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_CPU0_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 223,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 224,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 225,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 226,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 227,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 228,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 229,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 230,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 231,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 232,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 233,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 234,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 235,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 236,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 237,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 238,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_CPU1_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 239,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 240,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 241,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 242,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 243,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 244,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 245,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 246,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 247,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 248,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 249,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 250,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 251,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 252,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 253,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 254,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_CPU2_DMI_SAFE_E = RBA_RESET_CPU1_TRAPIDOFFSET + 255,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 256,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 257,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 258,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 259,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 260,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 261,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 262,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_DMA_PARTITION_0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 263,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 264,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 265,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 266,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 267,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 268,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 269,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 270,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_DMA_PARTITION_1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 271,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 272,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 273,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 274,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 275,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 276,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 277,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 278,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_DMA_PARTITION_2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 279,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 280,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 281,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 282,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 283,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 284,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 285,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 286,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_DMA_PARTITION_3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 287,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 288,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 289,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 290,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 291,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 292,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 293,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 294,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_DMA_CERBERUS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 295,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 296,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 297,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 298,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 299,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 300,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 301,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 302,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_HSSL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 303,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 304,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 305,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 306,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 307,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 308,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 309,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 310,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_ETHERNET_E = RBA_RESET_CPU1_TRAPIDOFFSET + 311,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 312,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 313,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 314,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 315,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 316,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 317,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 318,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_HSM_HSMCMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 319,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 320,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 321,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 322,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 323,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 324,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 325,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 326,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_CPU0_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 327,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 328,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 329,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 330,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 331,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 332,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 333,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 334,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_CPU1_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 335,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 336,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 337,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 338,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 339,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 340,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 341,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 342,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_CPU2_PMI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 343,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 344,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 345,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 346,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 347,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 348,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 349,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 350,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_DAM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 351,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 352,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 353,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 354,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 355,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 356,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 357,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 358,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_CERBERUS_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 359,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 360,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 361,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 362,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 363,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 364,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 365,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 366,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_EMEM_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 367,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IED_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 368,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_T_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 369,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Tag Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_C_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 370,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Cache Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_S_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 371,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BI_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 372,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Bus Interface */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_UNC_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 373,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_SP_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 374,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU1_TRAP_SYSBUSERR_DIE_IE_BS_CIF_MASTER_BBB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 375,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU1_TRAP_TCN4_UNKNOWN_E = RBA_RESET_CPU1_TRAPIDOFFSET + 376,    /* TCN = 4, TIN = >6: Unknown */
    RBA_RESET_CPU1_TRAP_TCN5_TIN0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 377,    /* TCN = 5, TIN = 0: Unknown */
    RBA_RESET_CPU1_TRAP_ASSTRAP_OVF_E = RBA_RESET_CPU1_TRAPIDOFFSET + 378,    /* TCN = 5, TIN = 1: Arithmetic Overflow */
    RBA_RESET_CPU1_TRAP_ASSTRAP_SOVF_E = RBA_RESET_CPU1_TRAPIDOFFSET + 379,    /* TCN = 5, TIN = 2: Sticky Arithmetic Overflow */
    RBA_RESET_CPU1_TRAP_TCN5_UNKNOWN_E = RBA_RESET_CPU1_TRAPIDOFFSET + 380,    /* TCN = 5, TIN = >2  */
    RBA_RESET_CPU1_TRAP_SYSCALL_SYS_E = RBA_RESET_CPU1_TRAPIDOFFSET + 381,    /* TCN = 6, TIN = 0-255: System Call */
    RBA_RESET_CPU1_TRAP_NMI_UNKNOWN_E = RBA_RESET_CPU1_TRAPIDOFFSET + 382,    /* TCN = 7, TIN = 0: no SMUT, no ESR1, no ESR0 bit */
    RBA_RESET_CPU1_TRAP_NMI_ESR0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 383,    /* TCN = 7, TIN = 0: NMI ESR0 */
    RBA_RESET_CPU1_TRAP_NMI_ESR1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 384,    /* TCN = 7, TIN = 0: NMI ESR1 */
    RBA_RESET_CPU1_TRAP_NMI_SMUT_E = RBA_RESET_CPU1_TRAPIDOFFSET + 385,    /* TCN = 7, TIN = 0: NMI SMUT additional information under */
    RBA_RESET_CPU1_TRAP_NMI_SMU_CPU0_MPU_E = RBA_RESET_CPU1_TRAPIDOFFSET + 386,    /* TCN = 7, TIN = 0: NMI SMUT CPU0: MPU error (registers, DSPR, PSPR) */
    RBA_RESET_CPU1_TRAP_NMI_SMU_CPU1_MPU_E = RBA_RESET_CPU1_TRAPIDOFFSET + 387,    /* TCN = 7, TIN = 0: NMI SMUT CPU1: MPU error (registers, DSPR, PSPR) */
    RBA_RESET_CPU1_TRAP_NMI_SMU_CPU2_MPU_E = RBA_RESET_CPU1_TRAPIDOFFSET + 388,    /* TCN = 7, TIN = 0: NMI SMUT CPU2: MPU error (registers, DSPR, PSPR) */
    RBA_RESET_CPU1_TRAP_NMI_SMU_IR_E = RBA_RESET_CPU1_TRAPIDOFFSET + 389,    /* TCN = 7, TIN = 0: NMI SMUT IR: Interrupt Monitor: EDC error */
    RBA_RESET_CPU1_TRAP_NMI_SMU_CGU_WDT_E = RBA_RESET_CPU1_TRAPIDOFFSET + 390,    /* TCN = 7, TIN = 0: NMI SMUT CGU WDT:  System PLL OSC_WDT: out of range input clock */
    RBA_RESET_CPU1_TRAP_NMI_SMU_CGU_PLLLOL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 391,    /* TCN = 7, TIN = 0: NMI SMUT CGU PLL LossOfLock:  System PLL VCO Loss-of-Lock Event */
    RBA_RESET_CPU1_TRAP_NMI_SMU_CGU_PLLERAYLOL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 392,    /* TCN = 7, TIN = 0: NMI SMUT CGU PLL ERAY LossOfLock:  PLL_ERAY VCO Loss-of-Lock Event */
    RBA_RESET_CPU1_TRAP_NMI_SMU_CGU_STM_E = RBA_RESET_CPU1_TRAPIDOFFSET + 393,    /* TCN = 7, TIN = 0: NMI SMUT CGU STM:  Clock monitoring: Out of range frequency STM */
    RBA_RESET_CPU1_TRAP_NMI_SMU_CGU_PLLERAY_E = RBA_RESET_CPU1_TRAPIDOFFSET + 394,    /* TCN = 7, TIN = 0: NMI SMUT CGU PLLERAY:  Clock monitoring: Out of range frequency PLL_ERAY */
    RBA_RESET_CPU1_TRAP_NMI_SMU_CGU_PLL_E = RBA_RESET_CPU1_TRAPIDOFFSET + 395,    /* TCN = 7, TIN = 0: NMI SMUT CGU PLL: Clock monitoring: Out of range frequency System PLL */
    RBA_RESET_CPU1_TRAP_NMI_SMU_CGU_SRI_E = RBA_RESET_CPU1_TRAPIDOFFSET + 396,    /* TCN = 7, TIN = 0: NMI SMUT CGU SRI:  Clock monitoring: Out of range frequency SRI */
    RBA_RESET_CPU1_TRAP_NMI_SMU_CGU_SPB_E = RBA_RESET_CPU1_TRAPIDOFFSET + 397,    /* TCN = 7, TIN = 0: NMI SMUT CGU SPB:  Clock monitoring: Out of range frequency SPB */
    RBA_RESET_CPU1_TRAP_NMI_SMU_CGU_CPU0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 398,    /* TCN = 7, TIN = 0: NMI SMUT CGU CPU0: Clock monitoring: Out of range frequency CPU0 */
    RBA_RESET_CPU1_TRAP_NMI_SMU_SCUEVR_12UV_E = RBA_RESET_CPU1_TRAPIDOFFSET + 399,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 1.2V digital undervoltage */
    RBA_RESET_CPU1_TRAP_NMI_SMU_SCUEVR_12OV_E = RBA_RESET_CPU1_TRAPIDOFFSET + 400,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 1.2V digital overvoltage */
    RBA_RESET_CPU1_TRAP_NMI_SMU_SCUEVR_33UV_E = RBA_RESET_CPU1_TRAPIDOFFSET + 401,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 3.3V undervoltage */
    RBA_RESET_CPU1_TRAP_NMI_SMU_SCUEVR_33OV_E = RBA_RESET_CPU1_TRAPIDOFFSET + 402,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 3.3V overvoltage */
    RBA_RESET_CPU1_TRAP_NMI_SMU_SCUEVR_5UV_E = RBA_RESET_CPU1_TRAPIDOFFSET + 403,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 5V supply undervoltage */
    RBA_RESET_CPU1_TRAP_NMI_SMU_SCUEVR_5OV_E = RBA_RESET_CPU1_TRAPIDOFFSET + 404,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 5V supply overvoltage */
    RBA_RESET_CPU1_TRAP_NMI_SMU_SWDT_E = RBA_RESET_CPU1_TRAPIDOFFSET + 405,    /* TCN = 7, TIN = 0: NMI SMUT: safety watchdog timeout */
    RBA_RESET_CPU1_TRAP_NMI_SMU_WDT0_E = RBA_RESET_CPU1_TRAPIDOFFSET + 406,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog0 timeout */
    RBA_RESET_CPU1_TRAP_NMI_SMU_WDT1_E = RBA_RESET_CPU1_TRAPIDOFFSET + 407,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog1 timeout */
    RBA_RESET_CPU1_TRAP_NMI_SMU_WDT2_E = RBA_RESET_CPU1_TRAPIDOFFSET + 408,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog2 timeout */
    RBA_RESET_CPU1_TRAP_NMI_SMU_WDT3_E = RBA_RESET_CPU1_TRAPIDOFFSET + 409,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog3 timeout */
    RBA_RESET_CPU1_TRAP_NMI_SMU_WDT4_E = RBA_RESET_CPU1_TRAPIDOFFSET + 410,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog4 timeout */
    RBA_RESET_CPU1_TRAP_NMI_SMU_WDT5_E = RBA_RESET_CPU1_TRAPIDOFFSET + 411,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog5 timeout */
    RBA_RESET_CPU1_TRAP_TCN7_UNKNOWN_E = RBA_RESET_CPU1_TRAPIDOFFSET + 412,    /* TCN = 7, TIN = >0 */
/* enum for CPU2 traps */
    RBA_RESET_CPU2_TRAP_MMU_VAF_E = RBA_RESET_CPU2_TRAPIDOFFSET,    /* TCN = 0, TIN = 0: MMU: Virtual Address Fill */
    RBA_RESET_CPU2_TRAP_MMU_VAP_E = RBA_RESET_CPU2_TRAPIDOFFSET + 1,    /* TCN = 0, TIN = 1: MMU: Virtual Address Protection */
    RBA_RESET_CPU2_TRAP_TCN0_UNKNOWN_E = RBA_RESET_CPU2_TRAPIDOFFSET + 2,    /* TCN = 0, TIN = >1  */
    RBA_RESET_CPU2_TRAP_TCN1_TIN0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 3,    /* TCN = 1, TIN = 0: Unknown  */
    RBA_RESET_CPU2_TRAP_INTPROT_PRIV_E = RBA_RESET_CPU2_TRAPIDOFFSET + 4,    /* TCN = 1, TIN = 1: Privileged Instruction */
    RBA_RESET_CPU2_TRAP_INTPROT_MPR_E = RBA_RESET_CPU2_TRAPIDOFFSET + 5,    /* TCN = 1, TIN = 2: Memory Protection: Read Access */
    RBA_RESET_CPU2_TRAP_INTPROT_MPW_E = RBA_RESET_CPU2_TRAPIDOFFSET + 6,    /* TCN = 1, TIN = 3: Memory Protection: Write Access */
    RBA_RESET_CPU2_TRAP_INTPROT_MPX_E = RBA_RESET_CPU2_TRAPIDOFFSET + 7,    /* TCN = 1, TIN = 4: Memory Protection: Execution Access */
    RBA_RESET_CPU2_TRAP_INTPROT_MPP_E = RBA_RESET_CPU2_TRAPIDOFFSET + 8,    /* TCN = 1, TIN = 5: Memory Protection: Peripheral Access */
    RBA_RESET_CPU2_TRAP_INTPROT_MPN_E = RBA_RESET_CPU2_TRAPIDOFFSET + 9,    /* TCN = 1, TIN = 6: Memory Protection: Null Address */
    RBA_RESET_CPU2_TRAP_INTPROT_GRWP_E = RBA_RESET_CPU2_TRAPIDOFFSET + 10,    /* TCN = 1, TIN = 7: Global Register Write Protection */
    RBA_RESET_CPU2_TRAP_TCN1_UNKNOWN_E = RBA_RESET_CPU2_TRAPIDOFFSET + 11,    /* TCN = 1, TIN = >7  */
    RBA_RESET_CPU2_TRAP_TCN2_TIN0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 12,    /* TCN = 2, TIN = : Unknown */
    RBA_RESET_CPU2_TRAP_INSTRERR_IOPC_E = RBA_RESET_CPU2_TRAPIDOFFSET + 13,    /* TCN = 2, TIN = 1: Illegal Opcode */
    RBA_RESET_CPU2_TRAP_INSTRERR_UOPC_E = RBA_RESET_CPU2_TRAPIDOFFSET + 14,    /* TCN = 2, TIN = 2: Unimplemented Opcode */
    RBA_RESET_CPU2_TRAP_INSTRERR_OPD_E = RBA_RESET_CPU2_TRAPIDOFFSET + 15,    /* TCN = 2, TIN = 3: Invalid Operand Specification */
    RBA_RESET_CPU2_TRAP_INSTRERR_ALN_E = RBA_RESET_CPU2_TRAPIDOFFSET + 16,    /* TCN = 2, TIN = 4: Data Address Alignment Error */
    RBA_RESET_CPU2_TRAP_INSTRERR_MEM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 17,    /* TCN = 2, TIN = 5: Invalid Local Memory Address */
    RBA_RESET_CPU2_TRAP_TCN2_UNKNOWN_E = RBA_RESET_CPU2_TRAPIDOFFSET + 18,    /* TCN = 2, TIN = >5  */
    RBA_RESET_CPU2_TRAP_TCN3_TIN0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 19,    /* TCN = 3, TIN = 0: Unknown */
    RBA_RESET_CPU2_TRAP_CONTMANA_FCD_E = RBA_RESET_CPU2_TRAPIDOFFSET + 20,    /* TCN = 3, TIN = 1: Free Context List Depleted */
    RBA_RESET_CPU2_TRAP_CONTMANA_CDO_E = RBA_RESET_CPU2_TRAPIDOFFSET + 21,    /* TCN = 3, TIN = 2: Call Depth Overflow */
    RBA_RESET_CPU2_TRAP_CONTMANA_CDU_E = RBA_RESET_CPU2_TRAPIDOFFSET + 22,    /* TCN = 3, TIN = 3: Call Depth Underflow */
    RBA_RESET_CPU2_TRAP_CONTMANA_FCU_E = RBA_RESET_CPU2_TRAPIDOFFSET + 23,    /* TCN = 3, TIN = 4: Free Context List Underflow */
    RBA_RESET_CPU2_TRAP_CONTMANA_CSU_E = RBA_RESET_CPU2_TRAPIDOFFSET + 24,    /* TCN = 3, TIN = 5: Context List Underflow */
    RBA_RESET_CPU2_TRAP_CONTMANA_CTYP_E = RBA_RESET_CPU2_TRAPIDOFFSET + 25,    /* TCN = 3, TIN = 6: Context Type Error */
    RBA_RESET_CPU2_TRAP_CONTMANA_NEST_E = RBA_RESET_CPU2_TRAPIDOFFSET + 26,    /* TCN = 3, TIN = 7: Nesting Error */
    RBA_RESET_CPU2_TRAP_TCN3_UNKNOWN_E = RBA_RESET_CPU2_TRAPIDOFFSET + 27,    /* TCN = 3, TIN = >7  */
    RBA_RESET_CPU2_TRAP_TCN4_TIN0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 28,    /* TCN = 4, TIN = 0: Unknown */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PSE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 29,    /* TCN = 4, TIN = 1: Program Fetch Synchronous Error */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DSE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 30,    /* TCN = 4, TIN = 2: Data Access Synchronous Error */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DAE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 31,    /* TCN = 4, TIN = 3: Data Access Asynchronous Error */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_CAE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 32,    /* TCN = 4, TIN = 4: Coprocessor TRAP_ Asynchronous Error */
    RBA_RESET_CPU2_TRAP_FPU_RNRSLT_E = RBA_RESET_CPU2_TRAPIDOFFSET + 33,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Rounded Result Error */
    RBA_RESET_CPU2_TRAP_FPU_UNRFLW_E = RBA_RESET_CPU2_TRAPIDOFFSET + 34,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Under Flow Error */
    RBA_RESET_CPU2_TRAP_FPU_DIVZRO_E = RBA_RESET_CPU2_TRAPIDOFFSET + 35,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Deivided By Zero Error */
    RBA_RESET_CPU2_TRAP_FPU_OVRFLW_E = RBA_RESET_CPU2_TRAPIDOFFSET + 36,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Over Flow Error */
    RBA_RESET_CPU2_TRAP_FPU_INVOPR_E = RBA_RESET_CPU2_TRAPIDOFFSET + 37,    /* TCN = 4, TIN = 4: FPU TRAP_ Asynchronous Invalid Operation Error */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_UNKNOWN_E = RBA_RESET_CPU2_TRAPIDOFFSET + 38,    /* TCN = 4, TIN = 5: no bit is set in PIETR */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 39,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 40,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 41,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 42,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 43,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 44,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 45,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 46,    /* TCN = 4, TIN = 5: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 47,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 48,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 49,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 50,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 51,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 52,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 53,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 54,    /* TCN = 4, TIN = 5: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 55,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 56,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 57,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 58,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 59,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 60,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 61,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 62,    /* TCN = 4, TIN = 5: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 63,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 64,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 65,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 66,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 67,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 68,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 69,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 70,    /* TCN = 4, TIN = 5: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 71,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 72,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 73,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 74,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 75,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 76,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 77,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 78,    /* TCN = 4, TIN = 5: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 79,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 80,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 81,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 82,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 83,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 84,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 85,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 86,    /* TCN = 4, TIN = 5: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 87,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 88,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 89,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 90,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 91,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 92,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 93,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 94,    /* TCN = 4, TIN = 5: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 95,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 96,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 97,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 98,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 99,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 100,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 101,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 102,    /* TCN = 4, TIN = 5: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 103,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 104,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 105,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 106,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 107,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 108,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 109,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 110,    /* TCN = 4, TIN = 5: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 111,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 112,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 113,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 114,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 115,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 116,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 117,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 118,    /* TCN = 4, TIN = 5: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 119,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 120,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 121,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 122,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 123,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 124,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 125,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 126,    /* TCN = 4, TIN = 5: DMA Cerberus, E_INFO(bus master tag): 001010 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 127,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 128,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 129,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 130,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 131,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 132,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 133,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 134,    /* TCN = 4, TIN = 5: High Speed Serial Link, E_INFO(bus master tag): 001011 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 135,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 136,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 137,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 138,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 139,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 140,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 141,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 142,    /* TCN = 4, TIN = 5: Ethernet, E_INFO(bus master tag): 001100 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 143,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 144,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 145,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 146,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 147,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 148,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 149,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 150,    /* TCN = 4, TIN = 5: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 151,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 152,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 153,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 154,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 155,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 156,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 157,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 158,    /* TCN = 4, TIN = 5: CPU0 PMI, E_INFO(bus master tag): 010000 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 159,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 160,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 161,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 162,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 163,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 164,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 165,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 166,    /* TCN = 4, TIN = 5: CPU1 PMI, E_INFO(bus master tag): 010001 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 167,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 168,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 169,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 170,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 171,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 172,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 173,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 174,    /* TCN = 4, TIN = 5: CPU2 PMI, E_INFO(bus master tag): 010010 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 175,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 176,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 177,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 178,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 179,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 180,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 181,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 182,    /* TCN = 4, TIN = 5: DAM, E_INFO(bus master tag): 011000 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 183,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 184,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 185,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 186,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 187,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 188,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 189,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 190,    /* TCN = 4, TIN = 5: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 191,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 192,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 193,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 194,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 195,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 196,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 197,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 198,    /* TCN = 4, TIN = 5: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IED_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 199,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_T_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 200,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_C_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 201,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_S_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 202,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BI_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 203,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_UNC_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 204,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_SP_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 205,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_PIE_IE_BS_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 206,    /* TCN = 4, TIN = 5: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Program Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_UNKNOWN_E = RBA_RESET_CPU2_TRAPIDOFFSET + 207,    /* TCN = 4, TIN = 6: no bit is set in DIETR */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 208,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 209,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 210,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 211,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 212,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 213,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 214,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_CPU0_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 215,    /* TCN = 4, TIN = 6: CPU0 DMI NonSafe, E_INFO(bus master tag): 000000 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 216,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 217,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 218,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 219,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 220,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 221,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 222,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_CPU0_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 223,    /* TCN = 4, TIN = 6: CPU0 DMI Safe, E_INFO(bus master tag): 000001 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 224,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 225,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 226,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 227,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 228,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 229,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 230,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_CPU1_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 231,    /* TCN = 4, TIN = 6: CPU1 DMI NonSafe, E_INFO(bus master tag): 000010 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 232,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 233,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 234,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 235,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 236,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 237,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 238,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_CPU1_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 239,    /* TCN = 4, TIN = 6: CPU1 DMI Safe, E_INFO(bus master tag): 000011 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 240,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 241,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 242,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 243,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 244,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 245,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 246,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_CPU2_DMI_NONESAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 247,    /* TCN = 4, TIN = 6: CPU2 DMI NonSafe, E_INFO(bus master tag): 000100 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 248,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 249,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 250,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 251,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 252,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 253,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 254,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_CPU2_DMI_SAFE_E = RBA_RESET_CPU2_TRAPIDOFFSET + 255,    /* TCN = 4, TIN = 6: CPU2 DMI Safe, E_INFO(bus master tag): 000101 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 256,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 257,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 258,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 259,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 260,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 261,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 262,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_DMA_PARTITION_0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 263,    /* TCN = 4, TIN = 6: DMA Resource Partition 0, E_INFO(bus master tag): 000110 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 264,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 265,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 266,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 267,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 268,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 269,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 270,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_DMA_PARTITION_1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 271,    /* TCN = 4, TIN = 6: DMA Resource Partition 1, E_INFO(bus master tag): 000111 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 272,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 273,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 274,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 275,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 276,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 277,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 278,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_DMA_PARTITION_2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 279,    /* TCN = 4, TIN = 6: DMA Resource Partition 2, E_INFO(bus master tag): 001000 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 280,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 281,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 282,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 283,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 284,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 285,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 286,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_DMA_PARTITION_3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 287,    /* TCN = 4, TIN = 6: DMA Resource Partition 3, E_INFO(bus master tag): 001001 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 288,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 289,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 290,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 291,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 292,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 293,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 294,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_DMA_CERBERUS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 295,    /* TCN = 4, TIN = 6: DMA Cerberus, E_INFO(bus master tag): 001010 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 296,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 297,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 298,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 299,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 300,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 301,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 302,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_HSSL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 303,    /* TCN = 4, TIN = 6: High Speed Serial Link, E_INFO(bus master tag): 001011 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 304,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 305,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 306,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 307,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 308,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 309,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 310,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_ETHERNET_E = RBA_RESET_CPU2_TRAPIDOFFSET + 311,    /* TCN = 4, TIN = 6: Ethernet, E_INFO(bus master tag): 001100 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 312,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 313,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 314,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 315,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 316,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 317,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 318,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_HSM_HSMCMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 319,    /* TCN = 4, TIN = 6: HSM HSMCMI, HSMRMI, E_INFO(bus master tag): 001101 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 320,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 321,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 322,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 323,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 324,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 325,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 326,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_CPU0_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 327,    /* TCN = 4, TIN = 6: CPU0 PMI, E_INFO(bus master tag): 010000 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 328,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 329,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 330,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 331,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 332,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 333,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 334,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_CPU1_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 335,    /* TCN = 4, TIN = 6: CPU1 PMI, E_INFO(bus master tag): 010001 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 336,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 337,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 338,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 339,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 340,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 341,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 342,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_CPU2_PMI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 343,    /* TCN = 4, TIN = 6: CPU2 PMI, E_INFO(bus master tag): 010010 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 344,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 345,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 346,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 347,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 348,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 349,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 350,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_DAM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 351,    /* TCN = 4, TIN = 6: DAM, E_INFO(bus master tag): 011000 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 352,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 353,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 354,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 355,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 356,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 357,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 358,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_CERBERUS_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 359,    /* TCN = 4, TIN = 6: Cerberus on Back Bone Bus (ED), E_INFO(bus master tag): 011100 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 360,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 361,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 362,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 363,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 364,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 365,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 366,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_EMEM_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 367,    /* TCN = 4, TIN = 6: EMEM Master on Back Bone Bus (ED), E_INFO(bus master tag): 011101 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IED_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 368,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_T_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 369,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Tag Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_C_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 370,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Cache Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_S_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 371,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Scratchpad Memory */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BI_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 372,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Bus Interface */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_UNC_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 373,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Dual Bit Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_SP_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 374,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Safety Protection Error Detected */
    RBA_RESET_CPU2_TRAP_SYSBUSERR_DIE_IE_BS_CIF_MASTER_BBB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 375,    /* TCN = 4, TIN = 6: CIF Master on Back Bone Bus (ED), E_INFO(bus master tag): 011110 Data Integrity Error Bus Slave Access Indicator */
    RBA_RESET_CPU2_TRAP_TCN4_UNKNOWN_E = RBA_RESET_CPU2_TRAPIDOFFSET + 376,    /* TCN = 4, TIN = >6: Unknown */
    RBA_RESET_CPU2_TRAP_TCN5_TIN0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 377,    /* TCN = 5, TIN = 0: Unknown */
    RBA_RESET_CPU2_TRAP_ASSTRAP_OVF_E = RBA_RESET_CPU2_TRAPIDOFFSET + 378,    /* TCN = 5, TIN = 1: Arithmetic Overflow */
    RBA_RESET_CPU2_TRAP_ASSTRAP_SOVF_E = RBA_RESET_CPU2_TRAPIDOFFSET + 379,    /* TCN = 5, TIN = 2: Sticky Arithmetic Overflow */
    RBA_RESET_CPU2_TRAP_TCN5_UNKNOWN_E = RBA_RESET_CPU2_TRAPIDOFFSET + 380,    /* TCN = 5, TIN = >2  */
    RBA_RESET_CPU2_TRAP_SYSCALL_SYS_E = RBA_RESET_CPU2_TRAPIDOFFSET + 381,    /* TCN = 6, TIN = 0-255: System Call */
    RBA_RESET_CPU2_TRAP_NMI_UNKNOWN_E = RBA_RESET_CPU2_TRAPIDOFFSET + 382,    /* TCN = 7, TIN = 0: no SMUT, no ESR1, no ESR0 bit */
    RBA_RESET_CPU2_TRAP_NMI_ESR0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 383,    /* TCN = 7, TIN = 0: NMI ESR0 */
    RBA_RESET_CPU2_TRAP_NMI_ESR1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 384,    /* TCN = 7, TIN = 0: NMI ESR1 */
    RBA_RESET_CPU2_TRAP_NMI_SMUT_E = RBA_RESET_CPU2_TRAPIDOFFSET + 385,    /* TCN = 7, TIN = 0: NMI SMUT additional information under */
    RBA_RESET_CPU2_TRAP_NMI_SMU_CPU0_MPU_E = RBA_RESET_CPU2_TRAPIDOFFSET + 386,    /* TCN = 7, TIN = 0: NMI SMUT CPU0: MPU error (registers, DSPR, PSPR) */
    RBA_RESET_CPU2_TRAP_NMI_SMU_CPU1_MPU_E = RBA_RESET_CPU2_TRAPIDOFFSET + 387,    /* TCN = 7, TIN = 0: NMI SMUT CPU1: MPU error (registers, DSPR, PSPR) */
    RBA_RESET_CPU2_TRAP_NMI_SMU_CPU2_MPU_E = RBA_RESET_CPU2_TRAPIDOFFSET + 388,    /* TCN = 7, TIN = 0: NMI SMUT CPU2: MPU error (registers, DSPR, PSPR) */
    RBA_RESET_CPU2_TRAP_NMI_SMU_IR_E = RBA_RESET_CPU2_TRAPIDOFFSET + 389,    /* TCN = 7, TIN = 0: NMI SMUT IR: Interrupt Monitor: EDC error */
    RBA_RESET_CPU2_TRAP_NMI_SMU_CGU_WDT_E = RBA_RESET_CPU2_TRAPIDOFFSET + 390,    /* TCN = 7, TIN = 0: NMI SMUT CGU WDT:  System PLL OSC_WDT: out of range input clock */
    RBA_RESET_CPU2_TRAP_NMI_SMU_CGU_PLLLOL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 391,    /* TCN = 7, TIN = 0: NMI SMUT CGU PLL LossOfLock:  System PLL VCO Loss-of-Lock Event */
    RBA_RESET_CPU2_TRAP_NMI_SMU_CGU_PLLERAYLOL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 392,    /* TCN = 7, TIN = 0: NMI SMUT CGU PLL ERAY LossOfLock:  PLL_ERAY VCO Loss-of-Lock Event */
    RBA_RESET_CPU2_TRAP_NMI_SMU_CGU_STM_E = RBA_RESET_CPU2_TRAPIDOFFSET + 393,    /* TCN = 7, TIN = 0: NMI SMUT CGU STM:  Clock monitoring: Out of range frequency STM */
    RBA_RESET_CPU2_TRAP_NMI_SMU_CGU_PLLERAY_E = RBA_RESET_CPU2_TRAPIDOFFSET + 394,    /* TCN = 7, TIN = 0: NMI SMUT CGU PLLERAY:  Clock monitoring: Out of range frequency PLL_ERAY */
    RBA_RESET_CPU2_TRAP_NMI_SMU_CGU_PLL_E = RBA_RESET_CPU2_TRAPIDOFFSET + 395,    /* TCN = 7, TIN = 0: NMI SMUT CGU PLL: Clock monitoring: Out of range frequency System PLL */
    RBA_RESET_CPU2_TRAP_NMI_SMU_CGU_SRI_E = RBA_RESET_CPU2_TRAPIDOFFSET + 396,    /* TCN = 7, TIN = 0: NMI SMUT CGU SRI:  Clock monitoring: Out of range frequency SRI */
    RBA_RESET_CPU2_TRAP_NMI_SMU_CGU_SPB_E = RBA_RESET_CPU2_TRAPIDOFFSET + 397,    /* TCN = 7, TIN = 0: NMI SMUT CGU SPB:  Clock monitoring: Out of range frequency SPB */
    RBA_RESET_CPU2_TRAP_NMI_SMU_CGU_CPU0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 398,    /* TCN = 7, TIN = 0: NMI SMUT CGU CPU0: Clock monitoring: Out of range frequency CPU0 */
    RBA_RESET_CPU2_TRAP_NMI_SMU_SCUEVR_12UV_E = RBA_RESET_CPU2_TRAPIDOFFSET + 399,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 1.2V digital undervoltage */
    RBA_RESET_CPU2_TRAP_NMI_SMU_SCUEVR_12OV_E = RBA_RESET_CPU2_TRAPIDOFFSET + 400,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 1.2V digital overvoltage */
    RBA_RESET_CPU2_TRAP_NMI_SMU_SCUEVR_33UV_E = RBA_RESET_CPU2_TRAPIDOFFSET + 401,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 3.3V undervoltage */
    RBA_RESET_CPU2_TRAP_NMI_SMU_SCUEVR_33OV_E = RBA_RESET_CPU2_TRAPIDOFFSET + 402,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 3.3V overvoltage */
    RBA_RESET_CPU2_TRAP_NMI_SMU_SCUEVR_5UV_E = RBA_RESET_CPU2_TRAPIDOFFSET + 403,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 5V supply undervoltage */
    RBA_RESET_CPU2_TRAP_NMI_SMU_SCUEVR_5OV_E = RBA_RESET_CPU2_TRAPIDOFFSET + 404,    /* TCN = 7, TIN = 0: NMI SMUT: EVR 5V supply overvoltage */
    RBA_RESET_CPU2_TRAP_NMI_SMU_SWDT_E = RBA_RESET_CPU2_TRAPIDOFFSET + 405,    /* TCN = 7, TIN = 0: NMI SMUT: safety watchdog timeout */
    RBA_RESET_CPU2_TRAP_NMI_SMU_WDT0_E = RBA_RESET_CPU2_TRAPIDOFFSET + 406,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog0 timeout */
    RBA_RESET_CPU2_TRAP_NMI_SMU_WDT1_E = RBA_RESET_CPU2_TRAPIDOFFSET + 407,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog1 timeout */
    RBA_RESET_CPU2_TRAP_NMI_SMU_WDT2_E = RBA_RESET_CPU2_TRAPIDOFFSET + 408,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog2 timeout */
    RBA_RESET_CPU2_TRAP_NMI_SMU_WDT3_E = RBA_RESET_CPU2_TRAPIDOFFSET + 409,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog3 timeout */
    RBA_RESET_CPU2_TRAP_NMI_SMU_WDT4_E = RBA_RESET_CPU2_TRAPIDOFFSET + 410,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog4 timeout */
    RBA_RESET_CPU2_TRAP_NMI_SMU_WDT5_E = RBA_RESET_CPU2_TRAPIDOFFSET + 411,    /* TCN = 7, TIN = 0: NMI SMUT: watchdog5 timeout */
    RBA_RESET_CPU2_TRAP_TCN7_UNKNOWN_E = RBA_RESET_CPU2_TRAPIDOFFSET + 412,    /* TCN = 7, TIN = >0 */
/* enum for SB reset ids */
    RBA_RESET_POWERON_SIMU_E = RBA_RESET_SBSWRIDOFFSET,    /* PowerOn Reset Simu */
    RBA_RESET_HWRESET_SIMU_E = RBA_RESET_SBSWRIDOFFSET + 1,    /* HW Reset Simu */
    RBA_RESET_RB_PROG_E = RBA_RESET_SBSWRIDOFFSET + 2,    /* Reprogramming Reset */
    RBA_RESET_CBPROG_E = RBA_RESET_SBSWRIDOFFSET + 3,    /* Reprogramming CB Reset */
    RBA_RESET_CBCPU_E = RBA_RESET_SBSWRIDOFFSET + 4,    /* CB Cpu Reset */
    RBA_RESET_RB_PROG_ILLEGAL_PATH_E = RBA_RESET_SBSWRIDOFFSET + 5,    /* Illegal Path in RB Programming Reset */
    RBA_RESET_TSW_EXIT_E = RBA_RESET_SBSWRIDOFFSET + 6,    /* TSW Exit Reset */
    RBA_RESET_TSW_MAGICPATTERN_E = RBA_RESET_SBSWRIDOFFSET + 7,    /* TSW Magic Pattern Reset */
    RBA_RESET_TRAP_IN_SB_E = RBA_RESET_SBSWRIDOFFSET + 8,    /* Trap occured in SB */
    RBA_RESET_SWDESTRST_RAMVALID_E = RBA_RESET_SBSWRIDOFFSET + 9,    /* Reset id which signalise a destructive reset with valid RAM content in case of FCCU failure */
    RBA_RESET_SWDESTRST_RAMINVALID_E = RBA_RESET_SBSWRIDOFFSET + 10,    /* Reset id which signalise a destructive reset with invalid RAM content in case of FCCU_SOFT or FCCU_HARD reset */
    RBA_RESET_SWDESTRST_REQ_RAMVALID_E = RBA_RESET_SBSWRIDOFFSET + 11,    /* Reset id which signalise the SB to trigger an additional destructive reset in case of FCCU NMI event */
    RBA_RESET_OBD_SVC11_RESET_E = RBA_RESET_SBSWRIDOFFSET + 12,    /* This software reset is triggered by OBD/Service tester */
    RBA_RESET_PLL_LOSS_OF_LOCK_E = RBA_RESET_SBSWRIDOFFSET + 13,    /* Loss of lock detected in BootCtrl before SMU is active */
    RBA_RESET_BCTL_FCCU_ERRABORT_E = RBA_RESET_SBSWRIDOFFSET + 14,    /* FCCU abort event occued while polling FCCU_CTRL register */
    RBA_RESET_RBA_BOOTCTRL_SB_OVERLAYRAM_INIT_FAILURE = RBA_RESET_SBSWRIDOFFSET + 15,    /* OverLay RAM Initialization Failure */
    RBA_RESET_DUMMY05_E = RBA_RESET_SBSWRIDOFFSET + 16,    /* Dummy reset id for later usage, should not be used */
    RBA_RESET_DUMMY06_E = RBA_RESET_SBSWRIDOFFSET + 17,    /* Dummy reset id for later usage, should not be used */
    RBA_RESET_DUMMY07_E = RBA_RESET_SBSWRIDOFFSET + 18,    /* Dummy reset id for later usage, should not be used */
    RBA_RESET_DUMMY08_E = RBA_RESET_SBSWRIDOFFSET + 19,    /* Dummy reset id for later usage, should not be used */
    RBA_RESET_POWERON_SIMU_SOFTRST_E = RBA_RESET_SBSWRIDOFFSET + 20,    /* Power On Simu Soft-Rest */
    RBA_RESET_CBPROG_SOFTRST_E = RBA_RESET_SBSWRIDOFFSET + 21,    /* Sb-Soft-Reset for usage in CB */
/* enum for ASW reset ids */
    MCU_RB_ERRORINT_SWRESET = RBA_RESET_ASWSWRIDOFFSET,    /* Mcu Error Interrupt Reset */
    MCU_RB_RESET_BUSERR_SBCU = RBA_RESET_ASWSWRIDOFFSET + 1,    /* Mcu Module detected a MCU_RB_RESET_BUSERR_SBCU Error Interrupt */
    MCU_RB_RESET_DTS_ERROR = RBA_RESET_ASWSWRIDOFFSET + 2,    /* Mcu Die Temperature Sensor Error */
    MCU_RB_RESET_UNKNOWN = RBA_RESET_ASWSWRIDOFFSET + 3,    /* Mcu Module detected a MCU_RB_RESET_UNKNOWN Error Interrupt */
    MCU_RB_RESET_XBAR_PROT_DEF_SLAVE = RBA_RESET_ASWSWRIDOFFSET + 4,    /* Mcu Module detected a MCU_RB_RESET_XBAR_PROT_DEF_SLAVE Error Interrupt */
    MCU_RB_RESET_XBAR_PROT_SCI00 = RBA_RESET_ASWSWRIDOFFSET + 5,    /* Mcu Module detected a MCU_RB_RESET_XBAR_PROT_SCI00 Error Interrupt */
    MCU_RB_RESET_XBAR_PROT_SCI01 = RBA_RESET_ASWSWRIDOFFSET + 6,    /* Mcu Module detected a MCU_RB_RESET_XBAR_PROT_SCI01 Error Interrupt */
    MCU_RB_RESET_XBAR_PROT_SCI02 = RBA_RESET_ASWSWRIDOFFSET + 7,    /* Mcu Module detected a MCU_RB_RESET_XBAR_PROT_SCI02 Error Interrupt */
    MCU_RB_RESET_XBAR_PROT_SCI03 = RBA_RESET_ASWSWRIDOFFSET + 8,    /* Mcu Module detected a MCU_RB_RESET_XBAR_PROT_SCI03 Error Interrupt */
    MCU_RB_RESET_XBAR_PROT_SCI04 = RBA_RESET_ASWSWRIDOFFSET + 9,    /* Mcu Module detected a MCU_RB_RESET_XBAR_PROT_SCI04 Error Interrupt */
    MCU_RB_RESET_XBAR_PROT_SCI05 = RBA_RESET_ASWSWRIDOFFSET + 10,    /* Mcu Module detected a MCU_RB_RESET_XBAR_PROT_SCI05 Error Interrupt */
    MCU_RB_RESET_XBAR_PROT_SCI06 = RBA_RESET_ASWSWRIDOFFSET + 11,    /* Mcu Module detected a MCU_RB_RESET_XBAR_PROT_SCI06 Error Interrupt */
    MCU_RB_RESET_XBAR_PROT_SCI07 = RBA_RESET_ASWSWRIDOFFSET + 12,    /* Mcu Module detected a MCU_RB_RESET_XBAR_PROT_SCI07 Error Interrupt */
    MCU_RB_RESET_XBAR_PROT_SCI08 = RBA_RESET_ASWSWRIDOFFSET + 13,    /* Mcu Module detected a MCU_RB_RESET_XBAR_PROT_SCI08 Error Interrupt */
    MCU_RB_RESET_XBAR_PROT_SCI09 = RBA_RESET_ASWSWRIDOFFSET + 14,    /* Mcu Module detected a MCU_RB_RESET_XBAR_PROT_SCI09 Error Interrupt */
    MCU_RB_RESET_XBAR_PROT_SCI10 = RBA_RESET_ASWSWRIDOFFSET + 15,    /* Mcu Module detected a MCU_RB_RESET_XBAR_PROT_SCI10 Error Interrupt */
    MCU_RB_RESET_XBAR_STARV_DEF_SLAVE = RBA_RESET_ASWSWRIDOFFSET + 16,    /* Mcu Module detected a MCU_RB_RESET_XBAR_STARV_DEF_SLAVE Error Interrupt */
    MCU_RB_RESET_XBAR_STARV_SCI00 = RBA_RESET_ASWSWRIDOFFSET + 17,    /* Mcu Module detected a MCU_RB_RESET_XBAR_STARV_SCI00 Error Interrupt */
    MCU_RB_RESET_XBAR_STARV_SCI01 = RBA_RESET_ASWSWRIDOFFSET + 18,    /* Mcu Module detected a MCU_RB_RESET_XBAR_STARV_SCI01 Error Interrupt */
    MCU_RB_RESET_XBAR_STARV_SCI02 = RBA_RESET_ASWSWRIDOFFSET + 19,    /* Mcu Module detected a MCU_RB_RESET_XBAR_STARV_SCI02 Error Interrupt */
    MCU_RB_RESET_XBAR_STARV_SCI03 = RBA_RESET_ASWSWRIDOFFSET + 20,    /* Mcu Module detected a MCU_RB_RESET_XBAR_STARV_SCI03 Error Interrupt */
    MCU_RB_RESET_XBAR_STARV_SCI04 = RBA_RESET_ASWSWRIDOFFSET + 21,    /* Mcu Module detected a MCU_RB_RESET_XBAR_STARV_SCI04 Error Interrupt */
    MCU_RB_RESET_XBAR_STARV_SCI05 = RBA_RESET_ASWSWRIDOFFSET + 22,    /* Mcu Module detected a MCU_RB_RESET_XBAR_STARV_SCI05 Error Interrupt */
    MCU_RB_RESET_XBAR_STARV_SCI06 = RBA_RESET_ASWSWRIDOFFSET + 23,    /* Mcu Module detected a MCU_RB_RESET_XBAR_STARV_SCI06 Error Interrupt */
    MCU_RB_RESET_XBAR_STARV_SCI07 = RBA_RESET_ASWSWRIDOFFSET + 24,    /* Mcu Module detected a MCU_RB_RESET_XBAR_STARV_SCI07 Error Interrupt */
    MCU_RB_RESET_XBAR_STARV_SCI08 = RBA_RESET_ASWSWRIDOFFSET + 25,    /* Mcu Module detected a MCU_RB_RESET_XBAR_STARV_SCI08 Error Interrupt */
    MCU_RB_RESET_XBAR_STARV_SCI09 = RBA_RESET_ASWSWRIDOFFSET + 26,    /* Mcu Module detected a MCU_RB_RESET_XBAR_STARV_SCI09 Error Interrupt */
    MCU_RB_RESET_XBAR_STARV_SCI10 = RBA_RESET_ASWSWRIDOFFSET + 27,    /* Mcu Module detected a MCU_RB_RESET_XBAR_STARV_SCI10 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_DEF_SLAVE = RBA_RESET_ASWSWRIDOFFSET + 28,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_DEF_SLAVE Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI00 = RBA_RESET_ASWSWRIDOFFSET + 29,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI00 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI01 = RBA_RESET_ASWSWRIDOFFSET + 30,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI01 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI02 = RBA_RESET_ASWSWRIDOFFSET + 31,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI02 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI03 = RBA_RESET_ASWSWRIDOFFSET + 32,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI03 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI04 = RBA_RESET_ASWSWRIDOFFSET + 33,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI04 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI05 = RBA_RESET_ASWSWRIDOFFSET + 34,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI05 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI06 = RBA_RESET_ASWSWRIDOFFSET + 35,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI06 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI07 = RBA_RESET_ASWSWRIDOFFSET + 36,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI07 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI08 = RBA_RESET_ASWSWRIDOFFSET + 37,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI08 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI09 = RBA_RESET_ASWSWRIDOFFSET + 38,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI09 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI10 = RBA_RESET_ASWSWRIDOFFSET + 39,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI10 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI11 = RBA_RESET_ASWSWRIDOFFSET + 40,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI11 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI12 = RBA_RESET_ASWSWRIDOFFSET + 41,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI12 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_MCI13 = RBA_RESET_ASWSWRIDOFFSET + 42,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_MCI13 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_SCI00 = RBA_RESET_ASWSWRIDOFFSET + 43,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_SCI00 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_SCI01 = RBA_RESET_ASWSWRIDOFFSET + 44,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_SCI01 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_SCI02 = RBA_RESET_ASWSWRIDOFFSET + 45,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_SCI02 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_SCI03 = RBA_RESET_ASWSWRIDOFFSET + 46,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_SCI03 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_SCI04 = RBA_RESET_ASWSWRIDOFFSET + 47,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_SCI04 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_SCI05 = RBA_RESET_ASWSWRIDOFFSET + 48,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_SCI05 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_SCI06 = RBA_RESET_ASWSWRIDOFFSET + 49,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_SCI06 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_SCI07 = RBA_RESET_ASWSWRIDOFFSET + 50,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_SCI07 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_SCI08 = RBA_RESET_ASWSWRIDOFFSET + 51,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_SCI08 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_SCI09 = RBA_RESET_ASWSWRIDOFFSET + 52,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_SCI09 Error Interrupt */
    MCU_RB_RESET_XBAR_TRANS_ID_SCI10 = RBA_RESET_ASWSWRIDOFFSET + 53,    /* Mcu Module detected a MCU_RB_RESET_XBAR_TRANS_ID_SCI10 Error Interrupt */
    MCU_RB_RESET_ILLEGAL_CALL_OF_MCU_PERFORM_RESET = RBA_RESET_ASWSWRIDOFFSET + 54,    /* Illegal usage of Mcu_PerformReset() */
    MCU_RB_RESET_UNDEFINED = RBA_RESET_ASWSWRIDOFFSET + 55,    /* Mcu Module dummy reset type for Mcu_GetResetReason() */
    RBA_EMM_ERRORPIN_SWRESET_CFG_RESET = RBA_RESET_ASWSWRIDOFFSET + 56,    /* rba_Emm Module reset for error pin and software-reset cfg could not be set */
    RBA_EMM_EVR13OVCFG_ERROR_RESET = RBA_RESET_ASWSWRIDOFFSET + 57,    /* rba_Emm Module reset for EVR 1.3V over voltage detected */
    RBA_EMM_EVR13UVCFG_ERROR_RESET = RBA_RESET_ASWSWRIDOFFSET + 58,    /* rba_Emm Module reset for EVR 1.3V under voltage detected */
    RBA_EMM_EVR33OVCFG_ERROR_RESET = RBA_RESET_ASWSWRIDOFFSET + 59,    /* rba_Emm Module reset for EVR 3.3V over voltage detected */
    RBA_EMM_EVR33UVCFG_ERROR_RESET = RBA_RESET_ASWSWRIDOFFSET + 60,    /* rba_Emm Module reset for EVR 3.3V under voltage detected */
    RBA_EMM_EVR50OVCFG_ERROR_RESET = RBA_RESET_ASWSWRIDOFFSET + 61,    /* rba_Emm Module reset for EVR 5.0V over voltage detected */
    RBA_EMM_EVR50UVCFG_ERROR_RESET = RBA_RESET_ASWSWRIDOFFSET + 62,    /* rba_Emm Module reset for EVR 5.0V under voltage detected */
    RBA_EMM_INT_TEMP_MON_RESET = RBA_RESET_ASWSWRIDOFFSET + 63,    /* rba_Emm Module reset for internal termperature monitoring */
    RBA_EMM_INVALID_STAT_RESET = RBA_RESET_ASWSWRIDOFFSET + 64,    /* rba_Emm Module reset for invalid Status register values */
    RBA_EMM_UNEXPECTED_LOCK_RESET = RBA_RESET_ASWSWRIDOFFSET + 65,    /* rba_Emm Module reset for unexpected Lock during configuration */
    RBA_EMM_VDDMOVCFG_ERROR_RESET = RBA_RESET_ASWSWRIDOFFSET + 66,    /* rba_Emm Module reset for VDDM ADC over voltage detected */
    RBA_EMM_VDDMUVCFG_ERROR_RESET = RBA_RESET_ASWSWRIDOFFSET + 67,    /* rba_Emm Module reset for VDDM ADC under voltage detected */
    RBA_EMM_VDDPDOVCFG_ERROR_RESET = RBA_RESET_ASWSWRIDOFFSET + 68,    /* rba_Emm Module reset for VDDPD over voltage detected */
    RBA_EMM_VDDPDUVCFG_ERROR_RESET = RBA_RESET_ASWSWRIDOFFSET + 69,    /* rba_Emm Module reset for VDDPD under voltage detected */
    RBA_EMM_VEVRSBOVCFG_ERROR_RESET = RBA_RESET_ASWSWRIDOFFSET + 70,    /* rba_Emm Module reset for VEVRSB over voltage detected */
    RBA_EMM_VEVRSBUVCFG_ERROR_RESET = RBA_RESET_ASWSWRIDOFFSET + 71,    /* rba_Emm Module reset for VEVRSB under voltage detected */
    RBA_MPU_COREMPU_INVALID_ADDRESS_ALIGNMENT_RESET = RBA_RESET_ASWSWRIDOFFSET + 72,    /* rba_Mpu reset if one region address is not 8 byte aligned */
    RBA_MPU_COREMPU_INVALID_NUMBER_CODE_REGIONS_RESET = RBA_RESET_ASWSWRIDOFFSET + 73,    /* rba_Mpu reset if too many code regions for the core MPU are forwarded */
    RBA_MPU_COREMPU_INVALID_NUMBER_DATA_REGIONS_RESET = RBA_RESET_ASWSWRIDOFFSET + 74,    /* rba_Mpu reset if too many data regions for the core MPU are forwarded */
    RBA_MPU_COREMPU_INVALID_NUMBER_REGIONS_RESET = RBA_RESET_ASWSWRIDOFFSET + 75,    /* rba_Mpu reset if too many regions for the core MPU are forwarded */
    RBA_MPU_COREMPU_INVALID_REGION_RESET = RBA_RESET_ASWSWRIDOFFSET + 76,    /* rba_Mpu reset if a region is not defined as code region, but has execute rights - or is defined as code region and has read or write access rights */
    RBA_MPU_COREMPU_INVALID_SETUP_RESET = RBA_RESET_ASWSWRIDOFFSET + 77,    /* for IFX: rba_Mpu reset if rba_Mpu_CoreMpu_SetAccess is called before rba_Mpu_CoreMpu_SetRegions
                                                                                   for JDP: rba_Mpu reset if rba_Mpu_SetCoreMpuCfg is called after rba_Mpu_CoreMpu_SetRegions was already called */
    RBA_MPU_COREMPU_REGION_START_END_ADDRESS_RESET = RBA_RESET_ASWSWRIDOFFSET + 78,    /* rba_Mpu reset if a start address of a region is greater than the end address of the same region */
    RBA_MPU_COREMPU_UNEQUAL_NUMBER_REGIONS_RESET = RBA_RESET_ASWSWRIDOFFSET + 79,    /* rba_Mpu reset if number of regions forwarded in rba_Mpu_CoreMpu_SetRegions is unequal to number of regions forwarded in rba_Mpu_CoreMpu_SetAcces */
    RBA_MPU_INVALID_ADDRESS_ALIGNMENT_RESET = RBA_RESET_ASWSWRIDOFFSET + 80,    /* rba_Mpu reset if one region address is not 32 byte aligned */
    RBA_MPU_INVALID_NUMBER_REGIONS_RESET = RBA_RESET_ASWSWRIDOFFSET + 81,    /* rba_Mpu reset if too many regions (including configured and filled regions) are needed for the configured regions */
    RBA_MPU_INVALID_NUMBER_SYSRAM_REGIONS_RESET = RBA_RESET_ASWSWRIDOFFSET + 82,    /* rba_Mpu reset if too many regions are configured */
    RBA_MPU_INVALID_REGION_ADDRESS_RESET = RBA_RESET_ASWSWRIDOFFSET + 83,    /* rba_Mpu reset if at least one region address within one CPU protection set is not in the same core local RAM than the other region addresses */
    RBA_MPU_INVALID_SYSRAM_REGION_ADDRESS_RESET = RBA_RESET_ASWSWRIDOFFSET + 84,    /* rba_Mpu reset if one region address is not in the system RAM area */
    RBA_MPU_REGION_START_END_ADDRESS_RESET = RBA_RESET_ASWSWRIDOFFSET + 85,    /* rba_Mpu reset if a start address of a region is greater than the end address of the same region */
    RBA_MULTISTACKTRACE_UNDEROVERFLOW = RBA_RESET_ASWSWRIDOFFSET + 86,    /* Stack overflow or underflow occured */
    RBA_RESET_BSW_DEFAULT_E = RBA_RESET_ASWSWRIDOFFSET + 87,    /* default reset id of reset trigger */
    RBA_RESET_ESC_TaskLinkBufSyncPnd_RESET_E = RBA_RESET_ASWSWRIDOFFSET + 88,    /* W Reset requested due to synchro tasks buffer overflow */
    RBA_RESET_FIRST_SWRESET = RBA_RESET_ASWSWRIDOFFSET + 89,    /* this is the first configured reset */
    RBA_RESET_INFOBLK_FAULT = RBA_RESET_ASWSWRIDOFFSET + 90,    /* Reset id created from rba_Reset comp. Used in case of infoblock handling fault. */
    RBA_RESET_RBA_BSWSRV_ADDRESS_RANGE_VIOLATION_E = RBA_RESET_ASWSWRIDOFFSET + 91,    /* Address does not support atomic bit access */
    RBA_RESET_RBA_BSWSRV_INTSUSP_CORRUPTION = RBA_RESET_ASWSWRIDOFFSET + 92,    /* Interrupt suspend state corrupted by other software */
    RBA_RESET_RBA_BSWSRV_INTSUSP_CTR_VIOLATION_E = RBA_RESET_ASWSWRIDOFFSET + 93,    /* Invalid use of interrupt resume: suspend counter underflow */
    RBA_RESET_RBA_BSWSRV_LOCK_CTR_VIOLATION_E = RBA_RESET_ASWSWRIDOFFSET + 94,    /* Invalid use of spinlock: lock counter underflow */
    RBA_RESET_RBA_BSWSRV_LOCK_NESTING_VIOLATION_E = RBA_RESET_ASWSWRIDOFFSET + 95,    /* Invalid use of spinlock: lock nesting violation */
    RBA_RESET_RBA_MEMLAY_CB_RAM1_SIZE_E = RBA_RESET_ASWSWRIDOFFSET + 96,    /* Size of CB used Ram in RAM1 is different between config and CB inside */
    RBA_RESET_RBA_MEMLAY_CB_RAM2_SIZE_E = RBA_RESET_ASWSWRIDOFFSET + 97,    /* Size of CB used Ram in RAM2 is different between config and CB inside */
    RBA_RESET_RBA_MEMLAY_CB_SYS_SIZE_E = RBA_RESET_ASWSWRIDOFFSET + 98,    /* Size of CB used Ram in SysRam is different between config and CB inside */
    RBA_RESET_RBA_MEMLAY_PCACHE_TIME_E = RBA_RESET_ASWSWRIDOFFSET + 99,    /* Time for invalidation of P-Cache is too long. */
    RBA_RESET_SWRST_EEPACTFIRSTINIT_E = RBA_RESET_ASWSWRIDOFFSET + 100,    /* restart after firstinitialization via Label */
    RBA_RESET_SWRST_EEPDELENVRAM_E = RBA_RESET_ASWSWRIDOFFSET + 101,    /* restart after deleting envram */
    RBA_SWTRACE_INIT = RBA_RESET_ASWSWRIDOFFSET + 102,    /* rba_SwTrace init failure */
    RBA_SYC_CY327_OVERVOLTAGE = RBA_RESET_ASWSWRIDOFFSET + 103,    /* Reset triggered on overvoltage on CY327 supply voltages */
    RBA_SYC_RESET_T15 = RBA_RESET_ASWSWRIDOFFSET + 104,    /* Reset because of T15 on used in Integration Code and ShutDown */
    RBA_SYC_SHUTDOWNSERVICES_RSTID_T15 = RBA_RESET_ASWSWRIDOFFSET + 105,    /* Reset because of T15 signal used in ShutDown */
    RBE_OSSHELL_OSERRLIMEXCDD = RBA_RESET_ASWSWRIDOFFSET + 106,    /* OS error limit exceeded */
    RBE_RESET_SWRST_CDDMONHW_EMM_RSTREQ = RBA_RESET_ASWSWRIDOFFSET + 107,    /* This reset is triggered if a fast shut of over reset request... is requested */
    RBE_RESET_SWRST_CDDMONHW_EMM_SMURSTLIMIT = RBA_RESET_ASWSWRIDOFFSET + 108,    /* This reset is triggered after the SMU hardware reset/trap counter reaches a certain limit */
	SWRESET_UDS_SOFTRESET = RBA_RESET_ASWSWRIDOFFSET + 109,    /* This reset is used for measurement unlimited Trace-Data */
    SWRESET_UPPER_COMPUTER_SERVICES = RBA_RESET_ASWSWRIDOFFSET + 110,    /* This reset is used for upper computer to update program */
	SWRESET_UDS_JUMP_TO_BOOT = RBA_RESET_ASWSWRIDOFFSET + 111,    /* This reset is used for upper computer to update program */
    RBA_RESET_NUM_ASW = RBA_RESET_ASWSWRIDOFFSET + 112,    /* number of ASW resets */
/* enum for ASW soft reset ids */
    RBA_SYC_POWERUNDERVOLTAGE_RSTID_UV_DETECTED = RBA_RESET_ASWSFTRIDOFFSET,    /* This reset is caused if a 5V undervoltage was detected via interrupt service routine. */
    RBA_SYC_RESET_CALPRM = RBA_RESET_ASWSFTRIDOFFSET + 1,    /* Reset which used for parameter initialization */
    RBA_SYC_RESET_RESTART = RBA_RESET_ASWSFTRIDOFFSET + 2,    /* Reset which can used in Integration Code to "restart" the ECU. */
    RBA_SYC_RESET_WAKEUP = RBA_RESET_ASWSFTRIDOFFSET + 3,    /* Reset because of a Wakeup used in Integration Code and ShutDown */
    RBA_SYC_SHUTDOWNSERVICES_RSTID_WAKEUP = RBA_RESET_ASWSFTRIDOFFSET + 4,    /* Reset because of a Wakeup used in ShutDown */
    RBA_RESET_NUM_ASW_SOFTRST = RBA_RESET_ASWSFTRIDOFFSET + 5    /* number of ASW softresets */
}rba_Reset_Id_ten;

/* enum for different loopcond */
enum
{
    RBA_RESET_DEFAULT_LOOPCOND,
    RBA_RESET_SOFTRST_NOLOOP,
    RBA_RESET_SPEC_LOOPCOND,
    RBA_SYC_POWERUNDERVOLTAGE_RSTID_UV_DETECTED_LOOPCOND,
    RBE_RESET_LOOPCDN_CDDMONHW_EMM_RSTREQ,
    RBE_RESET_LOOPCDN_CDDMONHW_EMM_SMURSTLIMIT,
    RBE_RESET_LOOPCDN_CDDMONHW_EMM_TRACEDATARSTREQ 
};


/* typedefs und extern declarations */
/* typedef for loop condition configuration */
typedef struct
{
    uint32 MinCyc_u32;                                            /* minimum SWReset cycle time */
    uint8  Max_u8;              /* maximum number of SWReset that may occur within tiMinCyc_u32 */
}rba_Reset_LoopCond_tst;

/* typedef for reset configuration */
typedef struct
{
    void (* const *CallbackFctPtrTable_pacpfct)(void); /* callback function pointer table */
    const uint8 * const *ConfTable_acpcu8;   /* table of bitmasks for loopcondition and visibility in DSM */
    const rba_Reset_LoopCond_tst *LoopCondTable_pcst;     /* table of different loop conditions */
}rba_Reset_Conf_tst;

/* Reset configuration for ASW */

extern const rba_Reset_Conf_tst rba_Reset_Conf_cst;

extern const uint8 rba_Reset_ConfHWRTable_acu8[20];

extern const uint8 rba_Reset_ConfSBTable_acu8[22];

extern const uint8 rba_Reset_ConfCBTable_acu8[1];

extern const uint8 rba_Reset_ConfASWTable_acu8[112];

extern const uint8 rba_Reset_ConfASWSoftResetTable_acu8[5];

extern const uint8 rba_Reset_ConfTrapTable_acu8[1];

extern const uint8 *const rba_Reset_ConfTables_acpcu8[6];

extern void (* const rba_Reset_CallbackFctPtrTable_acpfct[1])(void);

extern const uint32 rba_Reset_TagAssignmentTable_acu32[RBA_RESET_NBR_TAG_ASSIGN];




/* typedef for RAM areas for clearing after different resets */
typedef enum
{
    RBA_RESET_NOTHING,
    RBA_RESET_PORST_AREA,
    RBA_RESET_SWR_AREA,
    RBA_RESET_TRAPHWR_AREA,
    RBA_RESET_PORST_SIMU_AREA 
}rba_Reset_RAMClrAreas_ten;

/* 
***************************************************************************************************
* Functions
***************************************************************************************************
*/



/* RBA_RESET_CFG_H */
#endif

/*<RBHead>
 ***********************************************************************************************************************
 * List of changes
 *
 * $History
 * 
 * 1.21.0; 0     10.03.2015 WIP2FE
 *   -
 * 
 * 1.7.0; 0     30.07.2013 SMT6KOR
 *   Transferred from BASD:
 *   COMP : rba_Reset \ AR40.1.0.0; 3
 * 
 * 1.5.0; 0     27.03.2013 MOR2ABT
 *   Transferred from BASD:
 *   COMP : rba_Reset \ AR40.0.6.0; 0
 * 
 * 2.0.0; 0     25.05.2012 SBR6KOR
 *   .
 * 
 * $
 *
 ***********************************************************************************************************************
</RBHead>*/
