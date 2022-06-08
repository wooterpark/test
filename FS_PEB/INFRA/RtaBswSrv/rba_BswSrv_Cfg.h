

#ifndef RBA_BSWSRV_CFG_H
#define RBA_BSWSRV_CFG_H

/*
 **********************************************************************************************************************
 * This file is for configuration of component rba_BswSrv
 **********************************************************************************************************************
 */

/*
 **********************************************************************************************************************
 * Defines
 **********************************************************************************************************************
 */

/* Hardware priority level of low priority lock: priority is increased to this value. */
/* Prevents activation of lower priority tasks and interrupts. Higher priority interrupts still can interrupt. */
/* Low priority lock must not be used at a higher interrupt priority. */
#define RBA_BSWSRV_CFG_LOW_PRIO_LEVEL         rba_OsShell_SystemTimer->imask

/* RBA_BSWSRV_CFG_OS_TASK_PRIO_LEVEL configures hardware priority level of operating system scheduler. */
/* This defines the minimum possible value for RBA_BSWSRV_CFG_LOW_PRIO_LEVEL */
/* Do not modify unless the OS interface has changed.*/
#define RBA_BSWSRV_CFG_OS_TASK_PRIO_LEVEL     rba_OsShell_SystemTimer->imask

/* RBA_BSWSRV_CFG_KNOWN_MACHINE_FAM configures machine family support: */
/* TRUE: implementation for known machine families like IFX-uc1 or JDP-uc1. Supports all interfaces. */
/* FALSE: limit implementation to hardware and compiler independent interfaces. No dependencies to other CUBAS modules. */
#define RBA_BSWSRV_CFG_KNOWN_MACHINE_FAM      FALSE

/* Activate the following #define ONLY for HSM projects. Activates support for special HSM core. */
//#define RBA_BSWSRV_CFG_HSM_CORE

/* Activate the following #define ONLY for projects which require position independent code (e.g. CB). */
/* Do not use for regular projects, as it increases runtime for 64bit memory services on JDP target. */
//#define RBA_BSWSRV_CFG_JDP_PIC_SUPPORT

/* Activate the following #define ONLY for projects which require user mode support. */
/* Currently only supported for IFX target. Make will abort if activated for other targets. */
//#define RBA_BSWSRV_CFG_USER_MODE_SUPPORT

/* RBA_BSWSRV_CFG_H */
#endif

/*<BASDKey>
**********************************************************************************************************************
* $History__:$
**********************************************************************************************************************
</BASDKey>*/

/*<BASDKey>
**********************************************************************************************************************
* End of header file: $Name______:rba_BswSrv_Cfg$
**********************************************************************************************************************
</BASDKey>*/
