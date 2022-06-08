/****************************************************************************
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *****************************************************************************
 * Project : Function Inhibition Manager
 * Component : FiM
 * Date : Mon August 06 2015
 * Version : 1.0
 * Description : RTA-BASE first revision
 ****************************************************************************/

#ifndef MCU_MACHINE_CFG_H
#define MCU_MACHINE_CFG_H

/*-------------------------------------------------------------------------------------------------------------------*
 * Includes
 *-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*
 * Macros
 *-------------------------------------------------------------------------------------------------------------------*/
/* Numbers >= 1  and < 10 are used for MachineFamilies */
/* Numbers >= 10 and < 50 are used for MachineTypes    */
/* Numbers >= 50          are used for MachineSubTypes */

/* Machine Types and Subtypes for deprecated CPUs                                             */
/* they are dummy defined here that software which has #if statements in the code with the    */
/* deprecated machine type do not generate a C-compiler warning                               */
#define MCU_RB_IFX_UC1_DEV3_PRE 9999

#define MCU_RB_IFX_UC1                                                                   1
#define MCU_RB_IFX_UC1_DEV2                                                              10
#define MCU_RB_IFX_UC1_DEV3                                                              11
#define MCU_RB_IFX_UC1_DEV3_B                                                            12
#define MCU_RB_IFX_UC1_DEV4                                                              13
#define MCU_RB_IFX_UC1_DEV2_LQFP_144                                                     50
#define MCU_RB_IFX_UC1_DEV3_B_LQFP_176                                                   51
#define MCU_RB_IFX_UC1_DEV3_B_BGA_292                                                    52
#define MCU_RB_IFX_UC1_DEV3_LQFP                                                         53
#define MCU_RB_IFX_UC1_DEV3_BGA_292                                                      54
#define MCU_RB_IFX_UC1_DEV4_BGA_416                                                      55
#define MCU_RB_JDP_UC1                                                                   2
#define MCU_RB_JDP_UC1_DEV1                                                              14
#define MCU_RB_JDP_UC1_DEV2                                                              15
#define MCU_RB_JDP_UC1_DEV3                                                              16
#define MCU_RB_JDP_UC1_DEV4                                                              17
#define MCU_RB_JDP_UC1_DEV4_C2                                                           18
#define MCU_RB_JDP_UC1_DEV1_LQFP_80                                                      56
#define MCU_RB_JDP_UC1_DEV2_LQFP_144                                                     57
#define MCU_RB_JDP_UC1_DEV3_LQFP                                                         58
#define MCU_RB_JDP_UC1_DEV4_BGA_416                                                      59
#define MCU_RB_JDP_UC1_DEV4_C2_BGA_416                                                   60


#define MCU_RB_MACHINE_FAM                                                               MCU_RB_IFX_UC1
#define MCU_RB_MACHINE_TYPE                                                              MCU_RB_IFX_UC1
#define MCU_RB_MACHINE_SUBTYPE                                                           MCU_RB_IFX_UC1_DEV3_LQFP
#define MCU_RB_NR_OF_AVL_CORES                                                           3


#endif

/*<BASDKey>
 **********************************************************************************************************************
 * $History___:$
 **********************************************************************************************************************
</BASDKey>*/

/*<BASDKey>
 **********************************************************************************************************************
 * End of header file: $Name______:$
 **********************************************************************************************************************
</BASDKey>*/
