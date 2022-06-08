/*<BASDKey>
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, 2011 Robert Bosch GmbH. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 * Administrative Information (automatically filled in)
 * $Domain____:BASD$
 * $Namespace_:\Comp\rta_bsw_BswSrv$
 * $Class_____:H_TPL$
 * $Name______:rta_bsw_BswSrv_Cfg$
 * $Variant___:AR40.2.0.0$
 * $Revision__:0$
 **********************************************************************************************************************
 </BASDKey>*/

/****************************************************************************
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *****************************************************************************
 * Project : Basic Software Service
 * Component : RTA_BSW_BSWSRV
 * Date : Mon December 28 2015
 * Version : 1.0
 * Description : RTA-BASE first revision
 ****************************************************************************/

#ifndef RTA_BSW_BSWSRV_CFG_H
#define RTA_BSW_BSWSRV_CFG_H

/*
 **********************************************************************************************************************
 * This file is for configuration of component rta_bsw_BswSrv
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
#define RTA_BSW_BSWSRV_CFG_LOW_PRIO_LEVEL         rta_bsw_OsShell_SystemTimer->imask


/* RTA_BSW_BSWSRV_CFG_OS_TASK_PRIO_LEVEL configures hardware priority level of operating system scheduler. */
/* This defines the minimum possible value for RTA_BSW_BSWSRV_CFG_LOW_PRIO_LEVEL */
/* Do not modify unless the OS interface has changed.*/
#define RTA_BSW_BSWSRV_CFG_OS_TASK_PRIO_LEVEL     rta_bsw_OsShell_SystemTimer->imask

/* RTA_BSW_BSWSRV_CFG_KNOWN_MACHINE_FAM configures machine family support: */
/* TRUE: implementation for known machine families like IFX-uc1 or JDP-uc1. Supports all interfaces. */
/* FALSE: limit implementation to hardware and compiler independent interfaces. No dependencies to other CUBAS modules. */

#define RTA_BSW_BSWSRV_CFG_KNOWN_MACHINE_FAM      FALSE

/* RTA_BSW_BSWSRV_CFG_H */
#endif

/*<BASDKey>
**********************************************************************************************************************
* $History__:$
**********************************************************************************************************************
</BASDKey>*/

/*<BASDKey>
**********************************************************************************************************************
* End of header file: $Name______:rta_bsw_BswSrv_Cfg$
**********************************************************************************************************************
</BASDKey>*/
