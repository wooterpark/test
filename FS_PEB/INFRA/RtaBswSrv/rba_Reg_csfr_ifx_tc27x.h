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
 * $Filename__:$
 *
 * $Author____:$
 *
 * $Function__:$
 *
 ***********************************************************************************************************************
 * $Domain____:$
 * $User______:$
 * $Date______:$
 * $Class_____:$
 * $Name______:$
 * $Variant___:$
 * $Revision__:$
 * $Type______:$
 * $State_____:$
 * $Generated_:$
 ***********************************************************************************************************************
 *
 * $UniqueName:$
 * $Component_:$
 *
 ***********************************************************************************************************************
</RBHead>*/

 #ifndef RBA_CSFR_IFX_TC27X_H
 #define RBA_CSFR_IFX_TC27X_H

 #include "rba_Reg_attrb.h"

/* add ul suffix if file is used in C context */

#define RBA_REG_CSFR_UL(x) x##UL
/**
 ***************************************************************************************************
 * \moduledescription
 *              Register definitions for peripheral module CSFR on TC27x-D-C
 *
 * \scope           [API]
 ***************************************************************************************************
*/
/* This defines can only be used with _mtcr() _mfcr(). They are NOT usable with __mtcr __mfcr */
#define RBA_REG_CSFR_PMA0_MXCR_OFFSET        0x8100
#define RBA_REG_CSFR_PMA1_MXCR_OFFSET        0x8104
#define RBA_REG_CSFR_PMA2_MXCR_OFFSET        0x8108
#define RBA_REG_CSFR_COMPAT_MXCR_OFFSET        0x9400
#define RBA_REG_CSFR_PCXI_MXCR_OFFSET        0xFE00
#define RBA_REG_CSFR_PSW_MXCR_OFFSET        0xFE04
#define RBA_REG_CSFR_PC_MXCR_OFFSET            0xFE08
#define RBA_REG_CSFR_SYSCON_MXCR_OFFSET        0xFE14
#define RBA_REG_CSFR_CORE_ID_MXCR_OFFSET    0xFE1C
#define RBA_REG_CSFR_CPU_ID_MXCR_OFFSET        0xFE18
#define RBA_REG_CSFR_CUS_ID_MXCR_OFFSET        0xFE50
#define RBA_REG_CSFR_BIV_MXCR_OFFSET        0xFE20
#define RBA_REG_CSFR_BTV_MXCR_OFFSET        0xFE24
#define RBA_REG_CSFR_ISP_MXCR_OFFSET        0xFE28
#define RBA_REG_CSFR_ICR_MXCR_OFFSET        0xFE2C
#define RBA_REG_CSFR_FCX_MXCR_OFFSET        0xFE38
#define RBA_REG_CSFR_LCX_MXCR_OFFSET        0xFE3C

#if 0
/* C-structure definition for hardware module */
typedef struct
{
    volatile uint32 PMA[3];                                          //[0xF8818100...0xF8818108] : Data Access CacheabilityRegister
    volatile uint32 RESERVED0[1213];                                 //[0xF881810C...0xF88193FF] : reserved space
    volatile uint32 COMPAT;                                          //[0xF8819400] : Compatibility Control Register
    volatile uint32 RESERVED1[6783];                                 //[0xF8819404...0xF881FDFF] : reserved space
    volatile uint32 PCXI;                                            //[0xF881FE00] : Previous Context Information Register
    volatile uint32 PSW;                                             //[0xF881FE04] : Program Status Word
    volatile uint32 PC;                                              //[0xF881FE08] : Program Counter
    volatile uint32 RESERVED2[2];                                    //[0xF881FE0C...0xF881FE13] : reserved space
    volatile uint32 SYSCON;                                          //[0xF881FE14] : System Configuration Register
    volatile uint32 CPU_ID;                                          //[0xF881FE18] : CPU0 Identification Register TC1.6P
    volatile uint32 CORE_ID;                                         //[0xF881FE1C] : CPU0 Core Identification Register
    volatile uint32 BIV;                                             //[0xF881FE20] : Base Interrupt Vector Table Pointer
    volatile uint32 BTV;                                             //[0xF881FE24] : Base Trap Vector Table Pointer
    volatile uint32 ISP;                                             //[0xF881FE28] : Interrupt Stack Pointer
    volatile uint32 ICR;                                             //[0xF881FE2C] : Interrupt Control Register
    volatile uint32 RESERVED3[2];                                    //[0xF881FE30...0xF881FE37] : reserved space
    volatile uint32 FCX;                                             //[0xF881FE38] : Free CSA List Head Pointer
    volatile uint32 LCX;                                             //[0xF881FE3C] : Free CSA List Limit Pointer
    volatile uint32 RESERVED4[4];                                    //[0xF881FE40...0xF881FE4F] : reserved space
    volatile uint32 CUS_ID;                                          //[0xF881FE50] : CPU0 Customer ID register
} rba_Reg_CSFR_tst;

#define PCX PCXI /* PCX has same address as PCXI */

/* 'extern' declaration for the module struct. */
/* The module's base address will be assigned by the linker/locator. */

extern rba_Reg_CSFR_tst CSFR0           RBA_REG_ATTR_MEM_BSS_SECTION;
extern rba_Reg_CSFR_tst CSFR1           RBA_REG_ATTR_MEM_BSS_SECTION;
extern rba_Reg_CSFR_tst CSFR2           RBA_REG_ATTR_MEM_BSS_SECTION;

#endif
/*
 ***************************************************************************************************
 * Definitions of bits and bitfields.
 * Each bit(field) is defined by its position and length.
 *
 * Example:
 *                       /- length -\
 *           0000 0000 00xx xxxx xxxx 0000 0000 0000
 *           |                      ^              |
 *      Bit 0                      |              Bit 31
 *                                  +-- position
 *
 * Access mode flags:  r  - bit(field) can only be read
 *                     w  - bit(field) can only be written
 *                     rw - bit(field) can be read and written
 *                     h  - bit(field) can also be modified by hardware
 *                          (such as a status bit).
 *                          This symbol can be combined with rw or r
 *
 ***************************************************************************************************
 */

/* RBA_REG_CSFR_PMA0_DAC_D (r) */
#define RBA_REG_CSFR_PMA0_DAC_D_POS                                        RBA_REG_CSFR_UL(13)
#define RBA_REG_CSFR_PMA0_DAC_D_LEN                                        RBA_REG_CSFR_UL(3)

/* RBA_REG_CSFR_PMA0_DAC_B (rw) */
#define RBA_REG_CSFR_PMA0_DAC_B_POS                                        RBA_REG_CSFR_UL(11)
#define RBA_REG_CSFR_PMA0_DAC_B_LEN                                        RBA_REG_CSFR_UL(2)

/* RBA_REG_CSFR_PMA0_DAC_A (r) */
#define RBA_REG_CSFR_PMA0_DAC_A_POS                                        RBA_REG_CSFR_UL(10)
#define RBA_REG_CSFR_PMA0_DAC_A_LEN                                        RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PMA0_DAC_0 (rw) */
#define RBA_REG_CSFR_PMA0_DAC_0_POS                                        RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_PMA0_DAC_0_LEN                                        RBA_REG_CSFR_UL(10)

/* RBA_REG_CSFR_PMA1_CAC_E (r) */
#define RBA_REG_CSFR_PMA1_CAC_E_POS                                        RBA_REG_CSFR_UL(14)
#define RBA_REG_CSFR_PMA1_CAC_E_LEN                                        RBA_REG_CSFR_UL(2)

/* RBA_REG_CSFR_PMA1_CAC_D (rw) */
#define RBA_REG_CSFR_PMA1_CAC_D_POS                                        RBA_REG_CSFR_UL(13)
#define RBA_REG_CSFR_PMA1_CAC_D_LEN                                        RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PMA1_CAC_C (r) */
#define RBA_REG_CSFR_PMA1_CAC_C_POS                                        RBA_REG_CSFR_UL(12)
#define RBA_REG_CSFR_PMA1_CAC_C_LEN                                        RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PMA1_CAC_B (rw) */
#define RBA_REG_CSFR_PMA1_CAC_B_POS                                        RBA_REG_CSFR_UL(11)
#define RBA_REG_CSFR_PMA1_CAC_B_LEN                                        RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PMA1_CAC_A (r) */
#define RBA_REG_CSFR_PMA1_CAC_A_POS                                        RBA_REG_CSFR_UL(10)
#define RBA_REG_CSFR_PMA1_CAC_A_LEN                                        RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PMA1_CAC_0 (rw) */
#define RBA_REG_CSFR_PMA1_CAC_0_POS                                        RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_PMA1_CAC_0_LEN                                        RBA_REG_CSFR_UL(10)

/* RBA_REG_CSFR_PMA2_PSI (R) */
#define RBA_REG_CSFR_PMA2_PSI_POS                                          RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_PMA2_PSI_LEN                                          RBA_REG_CSFR_UL(16)

/* RBA_REG_CSFR_COMPAT_RM (RW) */
#define RBA_REG_CSFR_COMPAT_RM_POS                                         RBA_REG_CSFR_UL(3)
#define RBA_REG_CSFR_COMPAT_RM_LEN                                         RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_COMPAT_SP (RW) */
#define RBA_REG_CSFR_COMPAT_SP_POS                                         RBA_REG_CSFR_UL(4)
#define RBA_REG_CSFR_COMPAT_SP_LEN                                         RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PCXI_PCXO (RW) */
#define RBA_REG_CSFR_PCXI_PCXO_POS                                         RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_PCXI_PCXO_LEN                                         RBA_REG_CSFR_UL(16)

/* RBA_REG_CSFR_PCXI_PCXS (RW) */
#define RBA_REG_CSFR_PCXI_PCXS_POS                                         RBA_REG_CSFR_UL(16)
#define RBA_REG_CSFR_PCXI_PCXS_LEN                                         RBA_REG_CSFR_UL(4)

/* RBA_REG_CSFR_PCXI_UL (RW) */
#define RBA_REG_CSFR_PCXI_UL_POS                                           RBA_REG_CSFR_UL(20)
#define RBA_REG_CSFR_PCXI_UL_LEN                                           RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PCXI_PIE (RW) */
#define RBA_REG_CSFR_PCXI_PIE_POS                                          RBA_REG_CSFR_UL(21)
#define RBA_REG_CSFR_PCXI_PIE_LEN                                          RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PCXI_PCPN (RW) */
#define RBA_REG_CSFR_PCXI_PCPN_POS                                         RBA_REG_CSFR_UL(22)
#define RBA_REG_CSFR_PCXI_PCPN_LEN                                         RBA_REG_CSFR_UL(10)

/* RBA_REG_CSFR_PSW_CDC (RWH) */
#define RBA_REG_CSFR_PSW_CDC_POS                                           RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_PSW_CDC_LEN                                           RBA_REG_CSFR_UL(7)

/* RBA_REG_CSFR_PSW_CDE (RWH) */
#define RBA_REG_CSFR_PSW_CDE_POS                                           RBA_REG_CSFR_UL(7)
#define RBA_REG_CSFR_PSW_CDE_LEN                                           RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PSW_GW (RWH) */
#define RBA_REG_CSFR_PSW_GW_POS                                            RBA_REG_CSFR_UL(8)
#define RBA_REG_CSFR_PSW_GW_LEN                                            RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PSW_IS (RWH) */
#define RBA_REG_CSFR_PSW_IS_POS                                            RBA_REG_CSFR_UL(9)
#define RBA_REG_CSFR_PSW_IS_LEN                                            RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PSW_IO (RWH) */
#define RBA_REG_CSFR_PSW_IO_POS                                            RBA_REG_CSFR_UL(10)
#define RBA_REG_CSFR_PSW_IO_LEN                                            RBA_REG_CSFR_UL(2)

/* RBA_REG_CSFR_PSW_PRS (RWH) */
#define RBA_REG_CSFR_PSW_PRS_POS                                           RBA_REG_CSFR_UL(12)
#define RBA_REG_CSFR_PSW_PRS_LEN                                           RBA_REG_CSFR_UL(2)

/* RBA_REG_CSFR_PSW_S (RWH) */
#define RBA_REG_CSFR_PSW_S_POS                                             RBA_REG_CSFR_UL(14)
#define RBA_REG_CSFR_PSW_S_LEN                                             RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PSW_SAV (RWH) */
#define RBA_REG_CSFR_PSW_SAV_POS                                           RBA_REG_CSFR_UL(27)
#define RBA_REG_CSFR_PSW_SAV_LEN                                           RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PSW_AV (RWH) */
#define RBA_REG_CSFR_PSW_AV_POS                                            RBA_REG_CSFR_UL(28)
#define RBA_REG_CSFR_PSW_AV_LEN                                            RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PSW_SV (RWH) */
#define RBA_REG_CSFR_PSW_SV_POS                                            RBA_REG_CSFR_UL(29)
#define RBA_REG_CSFR_PSW_SV_LEN                                            RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PSW_V (RWH) */
#define RBA_REG_CSFR_PSW_V_POS                                             RBA_REG_CSFR_UL(30)
#define RBA_REG_CSFR_PSW_V_LEN                                             RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PSW_C (RWH) */
#define RBA_REG_CSFR_PSW_C_POS                                             RBA_REG_CSFR_UL(31)
#define RBA_REG_CSFR_PSW_C_LEN                                             RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_PC_PC (R) */
#define RBA_REG_CSFR_PC_PC_POS                                             RBA_REG_CSFR_UL(1)
#define RBA_REG_CSFR_PC_PC_LEN                                             RBA_REG_CSFR_UL(31)

/* RBA_REG_CSFR_SYSCON_FCDSF (RWH) */
#define RBA_REG_CSFR_SYSCON_FCDSF_POS                                      RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_SYSCON_FCDSF_LEN                                      RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_SYSCON_PROTEN (RW) */
#define RBA_REG_CSFR_SYSCON_PROTEN_POS                                     RBA_REG_CSFR_UL(1)
#define RBA_REG_CSFR_SYSCON_PROTEN_LEN                                     RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_SYSCON_TPROTEN (RW) */
#define RBA_REG_CSFR_SYSCON_TPROTEN_POS                                    RBA_REG_CSFR_UL(2)
#define RBA_REG_CSFR_SYSCON_TPROTEN_LEN                                    RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_SYSCON_IS (RW) */
#define RBA_REG_CSFR_SYSCON_IS_POS                                         RBA_REG_CSFR_UL(3)
#define RBA_REG_CSFR_SYSCON_IS_LEN                                         RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_SYSCON_IT (RW) */
#define RBA_REG_CSFR_SYSCON_IT_POS                                         RBA_REG_CSFR_UL(4)
#define RBA_REG_CSFR_SYSCON_IT_LEN                                         RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_SYSCON_U1_IED (RW) */
#define RBA_REG_CSFR_SYSCON_U1_IED_POS                                     RBA_REG_CSFR_UL(16)
#define RBA_REG_CSFR_SYSCON_U1_IED_LEN                                     RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_SYSCON_U1_IOS (RW) */
#define RBA_REG_CSFR_SYSCON_U1_IOS_POS                                     RBA_REG_CSFR_UL(17)
#define RBA_REG_CSFR_SYSCON_U1_IOS_LEN                                     RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_CPU_ID_MOD_REV (R) */
#define RBA_REG_CSFR_CPU_ID_MODREV_POS                                     RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_CPU_ID_MODREV_LEN                                     RBA_REG_CSFR_UL(8)

/* RBA_REG_CSFR_CPU_ID_MOD_32B (R) */
#define RBA_REG_CSFR_CPU_ID_MOD_32B_POS                                    RBA_REG_CSFR_UL(8)
#define RBA_REG_CSFR_CPU_ID_MOD_32B_LEN                                    RBA_REG_CSFR_UL(8)

/* RBA_REG_CSFR_CPU_ID_MOD (R) */
#define RBA_REG_CSFR_CPU_ID_MOD_POS                                        RBA_REG_CSFR_UL(16)
#define RBA_REG_CSFR_CPU_ID_MOD_LEN                                        RBA_REG_CSFR_UL(16)

/* RBA_REG_CSFR_CORE_ID_CORE_ID (RW) */
#define RBA_REG_CSFR_CORE_ID_CORE_ID_POS                                   RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_CORE_ID_CORE_ID_LEN                                   RBA_REG_CSFR_UL(3)

/* RBA_REG_CSFR_BIV_VSS (RW) */
#define RBA_REG_CSFR_BIV_VSS_POS                                           RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_BIV_VSS_LEN                                           RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_BIV_BIV (RW) */
#define RBA_REG_CSFR_BIV_BIV_POS                                           RBA_REG_CSFR_UL(1)
#define RBA_REG_CSFR_BIV_BIV_LEN                                           RBA_REG_CSFR_UL(31)

/* RBA_REG_CSFR_BTV_BTV (RW) */
#define RBA_REG_CSFR_BTV_BTV_POS                                           RBA_REG_CSFR_UL(1)
#define RBA_REG_CSFR_BTV_BTV_LEN                                           RBA_REG_CSFR_UL(31)

/* RBA_REG_CSFR_ISP_ISP (RW) */
#define RBA_REG_CSFR_ISP_ISP_POS                                           RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_ISP_ISP_LEN                                           RBA_REG_CSFR_UL(32)

/* RBA_REG_CSFR_ICR_CCPN (RWH) */
#define RBA_REG_CSFR_ICR_CCPN_POS                                          RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_ICR_CCPN_LEN                                          RBA_REG_CSFR_UL(10)

/* RBA_REG_CSFR_ICR_IE (RWH) */
#define RBA_REG_CSFR_ICR_IE_POS                                            RBA_REG_CSFR_UL(15)
#define RBA_REG_CSFR_ICR_IE_LEN                                            RBA_REG_CSFR_UL(1)

/* RBA_REG_CSFR_ICR_PIPN (RH) */
#define RBA_REG_CSFR_ICR_PIPN_POS                                          RBA_REG_CSFR_UL(16)
#define RBA_REG_CSFR_ICR_PIPN_LEN                                          RBA_REG_CSFR_UL(10)

/* RBA_REG_CSFR_FCX_FCXO (RW) */
#define RBA_REG_CSFR_FCX_FCXO_POS                                          RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_FCX_FCXO_LEN                                          RBA_REG_CSFR_UL(16)

/* RBA_REG_CSFR_FCX_FCXS (RW) */
#define RBA_REG_CSFR_FCX_FCXS_POS                                          RBA_REG_CSFR_UL(16)
#define RBA_REG_CSFR_FCX_FCXS_LEN                                          RBA_REG_CSFR_UL(4)

/* RBA_REG_CSFR_LCX_LCXO (RW) */
#define RBA_REG_CSFR_LCX_LCXO_POS                                          RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_LCX_LCXO_LEN                                          RBA_REG_CSFR_UL(16)

/* RBA_REG_CSFR_LCX_LCXS (RW) */
#define RBA_REG_CSFR_LCX_LCXS_POS                                          RBA_REG_CSFR_UL(16)
#define RBA_REG_CSFR_LCX_LCXS_LEN                                          RBA_REG_CSFR_UL(4)

/* RBA_REG_CSFR_CUS_ID_CID (R) */
#define RBA_REG_CSFR_CUS_ID_CID_POS                                        RBA_REG_CSFR_UL(0)
#define RBA_REG_CSFR_CUS_ID_CID_LEN                                        RBA_REG_CSFR_UL(3)

#endif

/*<RBHead>
 ***********************************************************************************************************************
 * List of changes
 *
 * $History$
 *
 ***********************************************************************************************************************
</RBHead>*/

/*<RBHead>
 ***********************************************************************************************************************
 * End of header file: $Name______:$
 ***********************************************************************************************************************
</RBHead>*/
