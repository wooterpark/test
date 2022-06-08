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

 #ifndef RBA_CBS_IFX_DEV3D_H
 #define RBA_CBS_IFX_DEV3D_H


/* add ul suffix if file is used in C context */

#define RBA_REG_CBS_UL(x) x##UL
/**
 ***************************************************************************************************
 * \moduledescription
 *              Register definitions for peripheral module CBS on TC27x-D-C
 *
 * \scope           [API]
 ***************************************************************************************************
*/
/* C-structure definition for hardware module */
typedef struct
{
    volatile uint32 JDPID;                                           //[0xF0000408] : Module Identification Register
    volatile uint32 OIFM;                                            //[0xF000040C] : OCDS Interface Mode Register
    volatile uint32 TIPR;                                            //[0xF0000410] : TG Input Pins Routing
    volatile uint32 TOPR;                                            //[0xF0000414] : TG Output Pins Routing
    volatile uint32 TOPPS;                                           //[0xF0000418] : TG Output Pins Pulse Stretcher
    volatile uint32 TCIP;                                            //[0xF000041C] : TG Capture for TG Input Pins
    volatile uint32 TRC[3];                                          //[0xF0000420...0xF0000428] : TG Routing for CPU0
    volatile uint32 RESERVED0[3];                                    //[0xF000042C...0xF0000437] : reserved space
    volatile uint32 TRHSM;                                           //[0xF0000438] : TG Routing for HSM Control
    volatile uint32 TRMC;                                            //[0xF000043C] : TG Routing for MCDS Control
    volatile uint32 TLCC[2];                                         //[0xF0000440...0xF0000444] : TG Line Counter Control
    volatile uint32 RESERVED1[2];                                    //[0xF0000448...0xF000044F] : reserved space
    volatile uint32 TLCV[2];                                         //[0xF0000450...0xF0000454] : TG Line Counter Value
    volatile uint32 RESERVED2[2];                                    //[0xF0000458...0xF000045F] : reserved space
    volatile uint32 TRSS;                                            //[0xF0000460] : TG Routing for Special Signals
    volatile uint32 JTAGID;                                          //[0xF0000464] : JTAG Device Identification Register
    volatile uint32 COMDATA;                                         //[0xF0000468] : Communication Mode Data Register
    volatile uint32 IOSR;                                            //[0xF000046C] : IOClient Status and Control Register
    volatile uint32 TLS;                                             //[0xF0000470] : TG Line State
    volatile uint32 TCTL;                                            //[0xF0000474] : TG Capture for TG Lines
    volatile uint32 OEC;                                             //[0xF0000478] : OCDS Enable Control Register
    volatile uint32 OCNTRL;                                          //[0xF000047C] : OSCU Control Register
    volatile uint32 OSTATE;                                          //[0xF0000480] : OSCU Status Register
    volatile uint32 INTMOD;                                          //[0xF0000484] : Internal Mode Status and Control Register
    volatile uint32 ICTSA;                                           //[0xF0000488] : Internally Controlled Trace Source Register
    volatile uint32 ICTTA;                                           //[0xF000048C] : Internally Controlled Trace Destination Register
    volatile uint32 TLC;                                             //[0xF0000490] : TG Line Control
    volatile uint32 TL1ST;                                           //[0xF0000494] : TG Line 1 Suspend Targets
    volatile uint32 TLCHE;                                           //[0xF0000498] : TG Line Capture and Hold Enable
    volatile uint32 TLCHS;                                           //[0xF000049C] : TG Line Capture and Hold Clear
    volatile uint32 TRIGS;                                           //[0xF00004A0] : Set Trigger to Host Register
    volatile uint32 TRIGC;                                           //[0xF00004A4] : Clear Trigger to Host Register
    volatile uint32 TLT;                                             //[0xF00004A8] : TG Line Timer
    volatile uint32 TLTTH;                                           //[0xF00004AC] : TG Lines for Trigger to Host
    volatile uint32 TCCB;                                            //[0xF00004B0] : TG Capture for Cores - BRKOUT
    volatile uint32 TCCH;                                            //[0xF00004B4] : TG Capture for Cores - HALT
    volatile uint32 TCTGB;                                           //[0xF00004B8] : TG Capture for OTGB0/1
    volatile uint32 TCM;                                             //[0xF00004BC] : TG Capture for MCDS
    volatile uint32 TREC[3];                                         //[0xF00004C0...0xF00004C8] : TG Routing Events of CPU0
    volatile uint32 RESERVED3[4];                                    //[0xF00004CC...0xF00004DB] : reserved space
    volatile uint32 TRMT;                                            //[0xF00004DC] : TG Routing for MCDS Triggers
    volatile uint32 TRTGB0L;                                         //[0xF00004E0] : TG Routing for OTGB0 Bits [7:0]
    volatile uint32 TRTGB0H;                                         //[0xF00004E4] : TG Routing for OTGB0 Bits [15:8]
    volatile uint32 TRTGB1L;                                         //[0xF00004E8] : TG Routing for OTGB1 Bits [7:0]
    volatile uint32 TRTGB1H;                                         //[0xF00004EC] : TG Routing for OTGB1 Bits [15:8]
    volatile uint32 RESERVED4[4];                                    //[0xF00004F0...0xF00004FF] : reserved space
    volatile uint32 TRIG[22];                                        //[0xF0000500...0xF0000550] : Trigger to Host Register 0
} rba_Reg_CBS_tst;

/* 'extern' declaration for the module struct. */
/* The module's base address will be assigned by the linker/locator. */

#define MODULE_CBS /*lint --e(923)*/ (*(rba_Reg_CBS_tst*)0xF0000408u)
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

/* RBA_REG_CBS_JDPID_MOD_REV (R) */
#define RBA_REG_CBS_JDPID_MODREV_POS                                       RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_JDPID_MODREV_LEN                                       RBA_REG_CBS_UL(8)

/* RBA_REG_CBS_JDPID_MOD_TYPE (R) */
#define RBA_REG_CBS_JDPID_MODTYPE_POS                                      RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_JDPID_MODTYPE_LEN                                      RBA_REG_CBS_UL(8)

/* RBA_REG_CBS_JDPID_MOD_NUMBER (R) */
#define RBA_REG_CBS_JDPID_MODNUMBER_POS                                    RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_JDPID_MODNUMBER_LEN                                    RBA_REG_CBS_UL(16)

/* RBA_REG_CBS_OIFM_DAPMODE (RW) */
#define RBA_REG_CBS_OIFM_DAPMODE_POS                                       RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_OIFM_DAPMODE_LEN                                       RBA_REG_CBS_UL(3)

/* RBA_REG_CBS_OIFM_DAPRST (RWH) */
#define RBA_REG_CBS_OIFM_DAPRST_POS                                        RBA_REG_CBS_UL(3)
#define RBA_REG_CBS_OIFM_DAPRST_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OIFM_F_JTAG (RW) */
#define RBA_REG_CBS_OIFM_F_JTAG_POS                                        RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_OIFM_F_JTAG_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OIFM_N_JTAG (RW) */
#define RBA_REG_CBS_OIFM_N_JTAG_POS                                        RBA_REG_CBS_UL(9)
#define RBA_REG_CBS_OIFM_N_JTAG_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OIFM_PADCTL (RW) */
#define RBA_REG_CBS_OIFM_PADCTL_POS                                        RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_OIFM_PADCTL_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TIPR_PIN0 (RW) */
#define RBA_REG_CBS_TIPR_PIN0_POS                                          RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TIPR_PIN0_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TIPR_PIN1 (RW) */
#define RBA_REG_CBS_TIPR_PIN1_POS                                          RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TIPR_PIN1_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TIPR_PIN2 (RW) */
#define RBA_REG_CBS_TIPR_PIN2_POS                                          RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TIPR_PIN2_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TIPR_PIN3 (RW) */
#define RBA_REG_CBS_TIPR_PIN3_POS                                          RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TIPR_PIN3_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TIPR_PIN4 (RW) */
#define RBA_REG_CBS_TIPR_PIN4_POS                                          RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TIPR_PIN4_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TIPR_PIN5 (RW) */
#define RBA_REG_CBS_TIPR_PIN5_POS                                          RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TIPR_PIN5_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TIPR_PIN6 (RW) */
#define RBA_REG_CBS_TIPR_PIN6_POS                                          RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_TIPR_PIN6_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TIPR_PIN7 (RW) */
#define RBA_REG_CBS_TIPR_PIN7_POS                                          RBA_REG_CBS_UL(28)
#define RBA_REG_CBS_TIPR_PIN7_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TOPR_PIN0 (RW) */
#define RBA_REG_CBS_TOPR_PIN0_POS                                          RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TOPR_PIN0_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TOPR_PIN1 (RW) */
#define RBA_REG_CBS_TOPR_PIN1_POS                                          RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TOPR_PIN1_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TOPR_PIN2 (RW) */
#define RBA_REG_CBS_TOPR_PIN2_POS                                          RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TOPR_PIN2_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TOPR_PIN3 (RW) */
#define RBA_REG_CBS_TOPR_PIN3_POS                                          RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TOPR_PIN3_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TOPR_PIN4 (RW) */
#define RBA_REG_CBS_TOPR_PIN4_POS                                          RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TOPR_PIN4_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TOPR_PIN5 (RW) */
#define RBA_REG_CBS_TOPR_PIN5_POS                                          RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TOPR_PIN5_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TOPR_PIN6 (RW) */
#define RBA_REG_CBS_TOPR_PIN6_POS                                          RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_TOPR_PIN6_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TOPR_PIN7 (RW) */
#define RBA_REG_CBS_TOPR_PIN7_POS                                          RBA_REG_CBS_UL(28)
#define RBA_REG_CBS_TOPR_PIN7_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TOPPS_PIN0 (RW) */
#define RBA_REG_CBS_TOPPS_PIN0_POS                                         RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TOPPS_PIN0_LEN                                         RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TOPPS_PIN1 (RW) */
#define RBA_REG_CBS_TOPPS_PIN1_POS                                         RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_TOPPS_PIN1_LEN                                         RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TOPPS_PIN2 (RW) */
#define RBA_REG_CBS_TOPPS_PIN2_POS                                         RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TOPPS_PIN2_LEN                                         RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TOPPS_PIN3 (RW) */
#define RBA_REG_CBS_TOPPS_PIN3_POS                                         RBA_REG_CBS_UL(6)
#define RBA_REG_CBS_TOPPS_PIN3_LEN                                         RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TOPPS_PIN4 (RW) */
#define RBA_REG_CBS_TOPPS_PIN4_POS                                         RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TOPPS_PIN4_LEN                                         RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TOPPS_PIN5 (RW) */
#define RBA_REG_CBS_TOPPS_PIN5_POS                                         RBA_REG_CBS_UL(10)
#define RBA_REG_CBS_TOPPS_PIN5_LEN                                         RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TOPPS_PIN6 (RW) */
#define RBA_REG_CBS_TOPPS_PIN6_POS                                         RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TOPPS_PIN6_LEN                                         RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TOPPS_PIN7 (RW) */
#define RBA_REG_CBS_TOPPS_PIN7_POS                                         RBA_REG_CBS_UL(14)
#define RBA_REG_CBS_TOPPS_PIN7_LEN                                         RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TCIP_P0 (RH) */
#define RBA_REG_CBS_TCIP_P0_POS                                            RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TCIP_P0_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCIP_P1 (RH) */
#define RBA_REG_CBS_TCIP_P1_POS                                            RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_TCIP_P1_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCIP_P2 (RH) */
#define RBA_REG_CBS_TCIP_P2_POS                                            RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_TCIP_P2_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCIP_P3 (RH) */
#define RBA_REG_CBS_TCIP_P3_POS                                            RBA_REG_CBS_UL(3)
#define RBA_REG_CBS_TCIP_P3_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCIP_P4 (RH) */
#define RBA_REG_CBS_TCIP_P4_POS                                            RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TCIP_P4_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCIP_P5 (RH) */
#define RBA_REG_CBS_TCIP_P5_POS                                            RBA_REG_CBS_UL(5)
#define RBA_REG_CBS_TCIP_P5_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCIP_P6 (RH) */
#define RBA_REG_CBS_TCIP_P6_POS                                            RBA_REG_CBS_UL(6)
#define RBA_REG_CBS_TCIP_P6_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCIP_P7 (RH) */
#define RBA_REG_CBS_TCIP_P7_POS                                            RBA_REG_CBS_UL(7)
#define RBA_REG_CBS_TCIP_P7_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRCx_HALT (RW) */
#define RBA_REG_CBS_TRCx_HALT_POS                                          RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TRCx_HALT_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRCx_BRKOUT (RW) */
#define RBA_REG_CBS_TRCx_BRKOUT_POS                                        RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TRCx_BRKOUT_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRCx_BT1 (RW) */
#define RBA_REG_CBS_TRCx_BT1_POS                                           RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TRCx_BT1_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRCx_BRKIN (RW) */
#define RBA_REG_CBS_TRCx_BRKIN_POS                                         RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TRCx_BRKIN_LEN                                         RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRCx_SUSIN (RW) */
#define RBA_REG_CBS_TRCx_SUSIN_POS                                         RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_TRCx_SUSIN_LEN                                         RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRHSM_HALT (RW) */
#define RBA_REG_CBS_TRHSM_HALT_POS                                         RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TRHSM_HALT_LEN                                         RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRHSM_BRKOUT (RW) */
#define RBA_REG_CBS_TRHSM_BRKOUT_POS                                       RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TRHSM_BRKOUT_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRHSM_BT1 (RW) */
#define RBA_REG_CBS_TRHSM_BT1_POS                                          RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TRHSM_BT1_LEN                                          RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRHSM_BRKIN (RW) */
#define RBA_REG_CBS_TRHSM_BRKIN_POS                                        RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TRHSM_BRKIN_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRHSM_SUSIN (RW) */
#define RBA_REG_CBS_TRHSM_SUSIN_POS                                        RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_TRHSM_SUSIN_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRMC_BRKOUT (RW) */
#define RBA_REG_CBS_TRMC_BRKOUT_POS                                        RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TRMC_BRKOUT_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRMC_SUSOUT (RW) */
#define RBA_REG_CBS_TRMC_SUSOUT_POS                                        RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TRMC_SUSOUT_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRMC_BRKIN (RW) */
#define RBA_REG_CBS_TRMC_BRKIN_POS                                         RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TRMC_BRKIN_LEN                                         RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TLCCx_TGL (RW) */
#define RBA_REG_CBS_TLCCx_TGL_POS                                          RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TLCCx_TGL_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TLCCx_LE (RW) */
#define RBA_REG_CBS_TLCCx_LE_POS                                           RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TLCCx_LE_LEN                                           RBA_REG_CBS_UL(3)

/* RBA_REG_CBS_TLCCx_CLR (W) */
#define RBA_REG_CBS_TLCCx_CLR_POS                                          RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TLCCx_CLR_LEN                                          RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TLCCx_STOP (W) */
#define RBA_REG_CBS_TLCCx_STOP_POS                                         RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TLCCx_STOP_LEN                                         RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TLCVx_CV (RH) */
#define RBA_REG_CBS_TLCVx_CV_POS                                           RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TLCVx_CV_LEN                                           RBA_REG_CBS_UL(31)

/* RBA_REG_CBS_TLCVx_SO (RH) */
#define RBA_REG_CBS_TLCVx_SO_POS                                           RBA_REG_CBS_UL(31)
#define RBA_REG_CBS_TLCVx_SO_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRSS_TT (RW) */
#define RBA_REG_CBS_TRSS_TT_POS                                            RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TRSS_TT_LEN                                            RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRSS_SRC0 (RW) */
#define RBA_REG_CBS_TRSS_SRC0_POS                                          RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TRSS_SRC0_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRSS_SRC1 (RW) */
#define RBA_REG_CBS_TRSS_SRC1_POS                                          RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TRSS_SRC1_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_JTAGID_JTAG_ID (RW) */
#define RBA_REG_CBS_JTAGID_JTAG_ID_POS                                     RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_JTAGID_JTAG_ID_LEN                                     RBA_REG_CBS_UL(32)

/* RBA_REG_CBS_COMDATA_DATA (RW) */
#define RBA_REG_CBS_COMDATA_DATA_POS                                       RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_COMDATA_DATA_LEN                                       RBA_REG_CBS_UL(32)

/* RBA_REG_CBS_IOSR_CRSYNC (RH) */
#define RBA_REG_CBS_IOSR_CRSYNC_POS                                        RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_IOSR_CRSYNC_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_IOSR_CWSYNC (RH) */
#define RBA_REG_CBS_IOSR_CWSYNC_POS                                        RBA_REG_CBS_UL(5)
#define RBA_REG_CBS_IOSR_CWSYNC_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_IOSR_CW_ACK (W) */
#define RBA_REG_CBS_IOSR_CW_ACK_POS                                        RBA_REG_CBS_UL(6)
#define RBA_REG_CBS_IOSR_CW_ACK_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_IOSR_COM_SYNC (RH) */
#define RBA_REG_CBS_IOSR_COM_SYNC_POS                                      RBA_REG_CBS_UL(7)
#define RBA_REG_CBS_IOSR_COM_SYNC_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_IOSR_HOSTED (RH) */
#define RBA_REG_CBS_IOSR_HOSTED_POS                                        RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_IOSR_HOSTED_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_IOSR_CHANNEL (RH) */
#define RBA_REG_CBS_IOSR_CHANNEL_POS                                       RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_IOSR_CHANNEL_LEN                                       RBA_REG_CBS_UL(3)

/* RBA_REG_CBS_TLS_TL1 (RH) */
#define RBA_REG_CBS_TLS_TL1_POS                                            RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_TLS_TL1_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLS_TL2 (RH) */
#define RBA_REG_CBS_TLS_TL2_POS                                            RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_TLS_TL2_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLS_TL3 (RH) */
#define RBA_REG_CBS_TLS_TL3_POS                                            RBA_REG_CBS_UL(3)
#define RBA_REG_CBS_TLS_TL3_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLS_TL4 (RH) */
#define RBA_REG_CBS_TLS_TL4_POS                                            RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TLS_TL4_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLS_TL5 (RH) */
#define RBA_REG_CBS_TLS_TL5_POS                                            RBA_REG_CBS_UL(5)
#define RBA_REG_CBS_TLS_TL5_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLS_TL6 (RH) */
#define RBA_REG_CBS_TLS_TL6_POS                                            RBA_REG_CBS_UL(6)
#define RBA_REG_CBS_TLS_TL6_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLS_TL7 (RH) */
#define RBA_REG_CBS_TLS_TL7_POS                                            RBA_REG_CBS_UL(7)
#define RBA_REG_CBS_TLS_TL7_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCTL_TL1 (RH) */
#define RBA_REG_CBS_TCTL_TL1_POS                                           RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_TCTL_TL1_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCTL_TL2 (RH) */
#define RBA_REG_CBS_TCTL_TL2_POS                                           RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_TCTL_TL2_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCTL_TL3 (RH) */
#define RBA_REG_CBS_TCTL_TL3_POS                                           RBA_REG_CBS_UL(3)
#define RBA_REG_CBS_TCTL_TL3_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCTL_TL4 (RH) */
#define RBA_REG_CBS_TCTL_TL4_POS                                           RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TCTL_TL4_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCTL_TL5 (RH) */
#define RBA_REG_CBS_TCTL_TL5_POS                                           RBA_REG_CBS_UL(5)
#define RBA_REG_CBS_TCTL_TL5_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCTL_TL6 (RH) */
#define RBA_REG_CBS_TCTL_TL6_POS                                           RBA_REG_CBS_UL(6)
#define RBA_REG_CBS_TCTL_TL6_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCTL_TL7 (RH) */
#define RBA_REG_CBS_TCTL_TL7_POS                                           RBA_REG_CBS_UL(7)
#define RBA_REG_CBS_TCTL_TL7_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OEC_PAT (W) */
#define RBA_REG_CBS_OEC_PAT_POS                                            RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_OEC_PAT_LEN                                            RBA_REG_CBS_UL(8)

/* RBA_REG_CBS_OEC_DS (W) */
#define RBA_REG_CBS_OEC_DS_POS                                             RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_OEC_DS_LEN                                             RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OEC_OCO (W) */
#define RBA_REG_CBS_OEC_OCO_POS                                            RBA_REG_CBS_UL(9)
#define RBA_REG_CBS_OEC_OCO_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OEC_IF_LCK_P (W) */
#define RBA_REG_CBS_OEC_IF_LCK_P_POS                                       RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_OEC_IF_LCK_P_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OEC_IF_LCK (W) */
#define RBA_REG_CBS_OEC_IF_LCK_POS                                         RBA_REG_CBS_UL(17)
#define RBA_REG_CBS_OEC_IF_LCK_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OEC_AUT_OK_P (W) */
#define RBA_REG_CBS_OEC_AUT_OK_P_POS                                       RBA_REG_CBS_UL(18)
#define RBA_REG_CBS_OEC_AUT_OK_P_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OEC_AUT_OK (W) */
#define RBA_REG_CBS_OEC_AUT_OK_POS                                         RBA_REG_CBS_UL(19)
#define RBA_REG_CBS_OEC_AUT_OK_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OC0_P (W) */
#define RBA_REG_CBS_OCNTRL_OC0_P_POS                                       RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_OCNTRL_OC0_P_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OC0 (W) */
#define RBA_REG_CBS_OCNTRL_OC0_POS                                         RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_OCNTRL_OC0_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OC1_P (W) */
#define RBA_REG_CBS_OCNTRL_OC1_P_POS                                       RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_OCNTRL_OC1_P_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OC1 (W) */
#define RBA_REG_CBS_OCNTRL_OC1_POS                                         RBA_REG_CBS_UL(3)
#define RBA_REG_CBS_OCNTRL_OC1_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OC2_P (W) */
#define RBA_REG_CBS_OCNTRL_OC2_P_POS                                       RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_OCNTRL_OC2_P_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OC2 (W) */
#define RBA_REG_CBS_OCNTRL_OC2_POS                                         RBA_REG_CBS_UL(5)
#define RBA_REG_CBS_OCNTRL_OC2_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OC3_P (W) */
#define RBA_REG_CBS_OCNTRL_OC3_P_POS                                       RBA_REG_CBS_UL(6)
#define RBA_REG_CBS_OCNTRL_OC3_P_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OC3 (W) */
#define RBA_REG_CBS_OCNTRL_OC3_POS                                         RBA_REG_CBS_UL(7)
#define RBA_REG_CBS_OCNTRL_OC3_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OC4_P (W) */
#define RBA_REG_CBS_OCNTRL_OC4_P_POS                                       RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_OCNTRL_OC4_P_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OC4 (W) */
#define RBA_REG_CBS_OCNTRL_OC4_POS                                         RBA_REG_CBS_UL(9)
#define RBA_REG_CBS_OCNTRL_OC4_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OC5_P (W) */
#define RBA_REG_CBS_OCNTRL_OC5_P_POS                                       RBA_REG_CBS_UL(10)
#define RBA_REG_CBS_OCNTRL_OC5_P_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OC5 (W) */
#define RBA_REG_CBS_OCNTRL_OC5_POS                                         RBA_REG_CBS_UL(11)
#define RBA_REG_CBS_OCNTRL_OC5_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_WDTSUS_P (W) */
#define RBA_REG_CBS_OCNTRL_WDTSUS_P_POS                                    RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_OCNTRL_WDTSUS_P_LEN                                    RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_WDTSUS (W) */
#define RBA_REG_CBS_OCNTRL_WDTSUS_POS                                      RBA_REG_CBS_UL(13)
#define RBA_REG_CBS_OCNTRL_WDTSUS_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_STABLE_P (W) */
#define RBA_REG_CBS_OCNTRL_STABLE_P_POS                                    RBA_REG_CBS_UL(14)
#define RBA_REG_CBS_OCNTRL_STABLE_P_LEN                                    RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_STABLE (W) */
#define RBA_REG_CBS_OCNTRL_STABLE_POS                                      RBA_REG_CBS_UL(15)
#define RBA_REG_CBS_OCNTRL_STABLE_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC0_P (W) */
#define RBA_REG_CBS_OCNTRL_OJC0_P_POS                                      RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_OCNTRL_OJC0_P_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC0 (W) */
#define RBA_REG_CBS_OCNTRL_OJC0_POS                                        RBA_REG_CBS_UL(17)
#define RBA_REG_CBS_OCNTRL_OJC0_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC1_P (W) */
#define RBA_REG_CBS_OCNTRL_OJC1_P_POS                                      RBA_REG_CBS_UL(18)
#define RBA_REG_CBS_OCNTRL_OJC1_P_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC1 (W) */
#define RBA_REG_CBS_OCNTRL_OJC1_POS                                        RBA_REG_CBS_UL(19)
#define RBA_REG_CBS_OCNTRL_OJC1_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC2_P (W) */
#define RBA_REG_CBS_OCNTRL_OJC2_P_POS                                      RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_OCNTRL_OJC2_P_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC2 (W) */
#define RBA_REG_CBS_OCNTRL_OJC2_POS                                        RBA_REG_CBS_UL(21)
#define RBA_REG_CBS_OCNTRL_OJC2_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC3_P (W) */
#define RBA_REG_CBS_OCNTRL_OJC3_P_POS                                      RBA_REG_CBS_UL(22)
#define RBA_REG_CBS_OCNTRL_OJC3_P_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC3 (W) */
#define RBA_REG_CBS_OCNTRL_OJC3_POS                                        RBA_REG_CBS_UL(23)
#define RBA_REG_CBS_OCNTRL_OJC3_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC4_P (W) */
#define RBA_REG_CBS_OCNTRL_OJC4_P_POS                                      RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_OCNTRL_OJC4_P_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC4 (W) */
#define RBA_REG_CBS_OCNTRL_OJC4_POS                                        RBA_REG_CBS_UL(25)
#define RBA_REG_CBS_OCNTRL_OJC4_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC5_P (W) */
#define RBA_REG_CBS_OCNTRL_OJC5_P_POS                                      RBA_REG_CBS_UL(26)
#define RBA_REG_CBS_OCNTRL_OJC5_P_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC5 (W) */
#define RBA_REG_CBS_OCNTRL_OJC5_POS                                        RBA_REG_CBS_UL(27)
#define RBA_REG_CBS_OCNTRL_OJC5_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC6_P (W) */
#define RBA_REG_CBS_OCNTRL_OJC6_P_POS                                      RBA_REG_CBS_UL(28)
#define RBA_REG_CBS_OCNTRL_OJC6_P_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC6 (W) */
#define RBA_REG_CBS_OCNTRL_OJC6_POS                                        RBA_REG_CBS_UL(29)
#define RBA_REG_CBS_OCNTRL_OJC6_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC7_P (W) */
#define RBA_REG_CBS_OCNTRL_OJC7_P_POS                                      RBA_REG_CBS_UL(30)
#define RBA_REG_CBS_OCNTRL_OJC7_P_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OCNTRL_OJC7 (W) */
#define RBA_REG_CBS_OCNTRL_OJC7_POS                                        RBA_REG_CBS_UL(31)
#define RBA_REG_CBS_OCNTRL_OJC7_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_OEN (RH) */
#define RBA_REG_CBS_OSTATE_OEN_POS                                         RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_OSTATE_OEN_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_OC0 (RH) */
#define RBA_REG_CBS_OSTATE_OC0_POS                                         RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_OSTATE_OC0_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_OC1 (RH) */
#define RBA_REG_CBS_OSTATE_OC1_POS                                         RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_OSTATE_OC1_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_OC2 (RH) */
#define RBA_REG_CBS_OSTATE_OC2_POS                                         RBA_REG_CBS_UL(3)
#define RBA_REG_CBS_OSTATE_OC2_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_ENIDIS (RH) */
#define RBA_REG_CBS_OSTATE_ENIDIS_POS                                      RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_OSTATE_ENIDIS_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_EECTRC (RH) */
#define RBA_REG_CBS_OSTATE_EECTRC_POS                                      RBA_REG_CBS_UL(5)
#define RBA_REG_CBS_OSTATE_EECTRC_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_EECDIS (RH) */
#define RBA_REG_CBS_OSTATE_EECDIS_POS                                      RBA_REG_CBS_UL(6)
#define RBA_REG_CBS_OSTATE_EECDIS_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_WDTSUS (RH) */
#define RBA_REG_CBS_OSTATE_WDTSUS_POS                                      RBA_REG_CBS_UL(7)
#define RBA_REG_CBS_OSTATE_WDTSUS_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_HARR (RH) */
#define RBA_REG_CBS_OSTATE_HARR_POS                                        RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_OSTATE_HARR_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_OJC1 (RH) */
#define RBA_REG_CBS_OSTATE_OJC1_POS                                        RBA_REG_CBS_UL(9)
#define RBA_REG_CBS_OSTATE_OJC1_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_OJC2 (RH) */
#define RBA_REG_CBS_OSTATE_OJC2_POS                                        RBA_REG_CBS_UL(10)
#define RBA_REG_CBS_OSTATE_OJC2_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_OJC3 (RH) */
#define RBA_REG_CBS_OSTATE_OJC3_POS                                        RBA_REG_CBS_UL(11)
#define RBA_REG_CBS_OSTATE_OJC3_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_RSTCL0 (RH) */
#define RBA_REG_CBS_OSTATE_RSTCL0_POS                                      RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_OSTATE_RSTCL0_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_RSTCL1 (RH) */
#define RBA_REG_CBS_OSTATE_RSTCL1_POS                                      RBA_REG_CBS_UL(13)
#define RBA_REG_CBS_OSTATE_RSTCL1_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_OJC6 (RH) */
#define RBA_REG_CBS_OSTATE_OJC6_POS                                        RBA_REG_CBS_UL(14)
#define RBA_REG_CBS_OSTATE_OJC6_LEN                                        RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_RSTCL3 (RH) */
#define RBA_REG_CBS_OSTATE_RSTCL3_POS                                      RBA_REG_CBS_UL(15)
#define RBA_REG_CBS_OSTATE_RSTCL3_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_IF_LCK (RH) */
#define RBA_REG_CBS_OSTATE_IF_LCK_POS                                      RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_OSTATE_IF_LCK_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_AUT_OK (RH) */
#define RBA_REG_CBS_OSTATE_AUT_OK_POS                                      RBA_REG_CBS_UL(17)
#define RBA_REG_CBS_OSTATE_AUT_OK_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_STABLE (RH) */
#define RBA_REG_CBS_OSTATE_STABLE_POS                                      RBA_REG_CBS_UL(18)
#define RBA_REG_CBS_OSTATE_STABLE_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_OSTATE_OCO (RH) */
#define RBA_REG_CBS_OSTATE_OCO_POS                                         RBA_REG_CBS_UL(19)
#define RBA_REG_CBS_OSTATE_OCO_LEN                                         RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_INTMOD_SET_CRS (W) */
#define RBA_REG_CBS_INTMOD_SET_CRS_POS                                     RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_INTMOD_SET_CRS_LEN                                     RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_INTMOD_SET_CWS (W) */
#define RBA_REG_CBS_INTMOD_SET_CWS_POS                                     RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_INTMOD_SET_CWS_LEN                                     RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_INTMOD_SET_CS (W) */
#define RBA_REG_CBS_INTMOD_SET_CS_POS                                      RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_INTMOD_SET_CS_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_INTMOD_CLR_CS (W) */
#define RBA_REG_CBS_INTMOD_CLR_CS_POS                                      RBA_REG_CBS_UL(3)
#define RBA_REG_CBS_INTMOD_CLR_CS_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_INTMOD_CHANNEL_P (W) */
#define RBA_REG_CBS_INTMOD_CHANNEL_P_POS                                   RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_INTMOD_CHANNEL_P_LEN                                   RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_INTMOD_CHANNEL (RW) */
#define RBA_REG_CBS_INTMOD_CHANNEL_POS                                     RBA_REG_CBS_UL(5)
#define RBA_REG_CBS_INTMOD_CHANNEL_LEN                                     RBA_REG_CBS_UL(3)

/* RBA_REG_CBS_INTMOD_SET_INT_MOD (W) */
#define RBA_REG_CBS_INTMOD_SET_INT_MOD_POS                                 RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_INTMOD_SET_INT_MOD_LEN                                 RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_INTMOD_SET_INT_TRC (W) */
#define RBA_REG_CBS_INTMOD_SET_INT_TRC_POS                                 RBA_REG_CBS_UL(18)
#define RBA_REG_CBS_INTMOD_SET_INT_TRC_LEN                                 RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_INTMOD_CLR_INT_TRC (W) */
#define RBA_REG_CBS_INTMOD_CLR_INT_TRC_POS                                 RBA_REG_CBS_UL(19)
#define RBA_REG_CBS_INTMOD_CLR_INT_TRC_LEN                                 RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_INTMOD_TRC_MOD_P (W) */
#define RBA_REG_CBS_INTMOD_TRC_MOD_P_POS                                   RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_INTMOD_TRC_MOD_P_LEN                                   RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_INTMOD_TRC_MOD (RW) */
#define RBA_REG_CBS_INTMOD_TRC_MOD_POS                                     RBA_REG_CBS_UL(21)
#define RBA_REG_CBS_INTMOD_TRC_MOD_LEN                                     RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_INTMOD_INT_MOD (RH) */
#define RBA_REG_CBS_INTMOD_INT_MOD_POS                                     RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_INTMOD_INT_MOD_LEN                                     RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_INTMOD_INT_TRC (RH) */
#define RBA_REG_CBS_INTMOD_INT_TRC_POS                                     RBA_REG_CBS_UL(25)
#define RBA_REG_CBS_INTMOD_INT_TRC_LEN                                     RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_ICTSA_ADDR (RW) */
#define RBA_REG_CBS_ICTSA_ADDR_POS                                         RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_ICTSA_ADDR_LEN                                         RBA_REG_CBS_UL(32)

/* RBA_REG_CBS_ICTTA_ADDR (RW) */
#define RBA_REG_CBS_ICTTA_ADDR_POS                                         RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_ICTTA_ADDR_LEN                                         RBA_REG_CBS_UL(32)

/* RBA_REG_CBS_TLC_TLSP1 (RW) */
#define RBA_REG_CBS_TLC_TLSP1_POS                                          RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TLC_TLSP1_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TLC_TLSP2 (RW) */
#define RBA_REG_CBS_TLC_TLSP2_POS                                          RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TLC_TLSP2_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TLC_TLSP3 (RW) */
#define RBA_REG_CBS_TLC_TLSP3_POS                                          RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TLC_TLSP3_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TLC_TLSP4 (RW) */
#define RBA_REG_CBS_TLC_TLSP4_POS                                          RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TLC_TLSP4_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TLC_TLSP5 (RW) */
#define RBA_REG_CBS_TLC_TLSP5_POS                                          RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TLC_TLSP5_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TLC_TLSP6 (RW) */
#define RBA_REG_CBS_TLC_TLSP6_POS                                          RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_TLC_TLSP6_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TLC_TLSP7 (RW) */
#define RBA_REG_CBS_TLC_TLSP7_POS                                          RBA_REG_CBS_UL(28)
#define RBA_REG_CBS_TLC_TLSP7_LEN                                          RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TL1ST_C0 (RW) */
#define RBA_REG_CBS_TL1ST_C0_POS                                           RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TL1ST_C0_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TL1ST_C1 (RW) */
#define RBA_REG_CBS_TL1ST_C1_POS                                           RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_TL1ST_C1_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TL1ST_C2 (RW) */
#define RBA_REG_CBS_TL1ST_C2_POS                                           RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_TL1ST_C2_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TL1ST_HSS (RW) */
#define RBA_REG_CBS_TL1ST_HSS_POS                                          RBA_REG_CBS_UL(28)
#define RBA_REG_CBS_TL1ST_HSS_LEN                                          RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TL1ST_DMA (RW) */
#define RBA_REG_CBS_TL1ST_DMA_POS                                          RBA_REG_CBS_UL(29)
#define RBA_REG_CBS_TL1ST_DMA_LEN                                          RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TL1ST_HSM (RW) */
#define RBA_REG_CBS_TL1ST_HSM_POS                                          RBA_REG_CBS_UL(31)
#define RBA_REG_CBS_TL1ST_HSM_LEN                                          RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLCHE_TL1 (RW) */
#define RBA_REG_CBS_TLCHE_TL1_POS                                          RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_TLCHE_TL1_LEN                                          RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLCHE_TL2 (RW) */
#define RBA_REG_CBS_TLCHE_TL2_POS                                          RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_TLCHE_TL2_LEN                                          RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLCHE_TL3 (RW) */
#define RBA_REG_CBS_TLCHE_TL3_POS                                          RBA_REG_CBS_UL(3)
#define RBA_REG_CBS_TLCHE_TL3_LEN                                          RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLCHS_TL1 (W) */
#define RBA_REG_CBS_TLCHS_TL1_POS                                          RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_TLCHS_TL1_LEN                                          RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLCHS_TL2 (W) */
#define RBA_REG_CBS_TLCHS_TL2_POS                                          RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_TLCHS_TL2_LEN                                          RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLCHS_TL3 (W) */
#define RBA_REG_CBS_TLCHS_TL3_POS                                          RBA_REG_CBS_UL(3)
#define RBA_REG_CBS_TLCHS_TL3_LEN                                          RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGS_BITNUM (W) */
#define RBA_REG_CBS_TRIGS_BITNUM_POS                                       RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TRIGS_BITNUM_LEN                                       RBA_REG_CBS_UL(13)

/* RBA_REG_CBS_TRIGC_TRGX_0 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_0_POS                                       RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TRIGC_TRGX_0_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_1 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_1_POS                                       RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_TRIGC_TRGX_1_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_2 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_2_POS                                       RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_TRIGC_TRGX_2_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_3 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_3_POS                                       RBA_REG_CBS_UL(3)
#define RBA_REG_CBS_TRIGC_TRGX_3_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_4 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_4_POS                                       RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TRIGC_TRGX_4_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_5 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_5_POS                                       RBA_REG_CBS_UL(5)
#define RBA_REG_CBS_TRIGC_TRGX_5_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_6 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_6_POS                                       RBA_REG_CBS_UL(6)
#define RBA_REG_CBS_TRIGC_TRGX_6_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_7 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_7_POS                                       RBA_REG_CBS_UL(7)
#define RBA_REG_CBS_TRIGC_TRGX_7_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_8 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_8_POS                                       RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TRIGC_TRGX_8_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_9 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_9_POS                                       RBA_REG_CBS_UL(9)
#define RBA_REG_CBS_TRIGC_TRGX_9_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_10 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_10_POS                                      RBA_REG_CBS_UL(10)
#define RBA_REG_CBS_TRIGC_TRGX_10_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_11 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_11_POS                                      RBA_REG_CBS_UL(11)
#define RBA_REG_CBS_TRIGC_TRGX_11_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_12 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_12_POS                                      RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TRIGC_TRGX_12_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_13 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_13_POS                                      RBA_REG_CBS_UL(13)
#define RBA_REG_CBS_TRIGC_TRGX_13_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_14 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_14_POS                                      RBA_REG_CBS_UL(14)
#define RBA_REG_CBS_TRIGC_TRGX_14_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_15 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_15_POS                                      RBA_REG_CBS_UL(15)
#define RBA_REG_CBS_TRIGC_TRGX_15_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_16 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_16_POS                                      RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TRIGC_TRGX_16_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_17 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_17_POS                                      RBA_REG_CBS_UL(17)
#define RBA_REG_CBS_TRIGC_TRGX_17_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_18 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_18_POS                                      RBA_REG_CBS_UL(18)
#define RBA_REG_CBS_TRIGC_TRGX_18_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_19 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_19_POS                                      RBA_REG_CBS_UL(19)
#define RBA_REG_CBS_TRIGC_TRGX_19_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_20 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_20_POS                                      RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TRIGC_TRGX_20_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_21 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_21_POS                                      RBA_REG_CBS_UL(21)
#define RBA_REG_CBS_TRIGC_TRGX_21_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_22 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_22_POS                                      RBA_REG_CBS_UL(22)
#define RBA_REG_CBS_TRIGC_TRGX_22_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_TRGX_23 (RH) */
#define RBA_REG_CBS_TRIGC_TRGX_23_POS                                      RBA_REG_CBS_UL(23)
#define RBA_REG_CBS_TRIGC_TRGX_23_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGC_X (RH) */
#define RBA_REG_CBS_TRIGC_X_POS                                            RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_TRIGC_X_LEN                                            RBA_REG_CBS_UL(8)

/* RBA_REG_CBS_TLT_TGL (RW) */
#define RBA_REG_CBS_TLT_TGL_POS                                            RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TLT_TGL_LEN                                            RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TLT_VTZ (RW) */
#define RBA_REG_CBS_TLT_VTZ_POS                                            RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TLT_VTZ_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TLT_TIM (RWH) */
#define RBA_REG_CBS_TLT_TIM_POS                                            RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TLT_TIM_LEN                                            RBA_REG_CBS_UL(16)

/* RBA_REG_CBS_TLTTH_TL1 (RW) */
#define RBA_REG_CBS_TLTTH_TL1_POS                                          RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_TLTTH_TL1_LEN                                          RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TLTTH_TL2 (RW) */
#define RBA_REG_CBS_TLTTH_TL2_POS                                          RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TLTTH_TL2_LEN                                          RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TLTTH_TL3 (RW) */
#define RBA_REG_CBS_TLTTH_TL3_POS                                          RBA_REG_CBS_UL(6)
#define RBA_REG_CBS_TLTTH_TL3_LEN                                          RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TLTTH_TL4 (RW) */
#define RBA_REG_CBS_TLTTH_TL4_POS                                          RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TLTTH_TL4_LEN                                          RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TLTTH_TL5 (RW) */
#define RBA_REG_CBS_TLTTH_TL5_POS                                          RBA_REG_CBS_UL(10)
#define RBA_REG_CBS_TLTTH_TL5_LEN                                          RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TLTTH_TL6 (RW) */
#define RBA_REG_CBS_TLTTH_TL6_POS                                          RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TLTTH_TL6_LEN                                          RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TLTTH_TL7 (RW) */
#define RBA_REG_CBS_TLTTH_TL7_POS                                          RBA_REG_CBS_UL(14)
#define RBA_REG_CBS_TLTTH_TL7_LEN                                          RBA_REG_CBS_UL(2)

/* RBA_REG_CBS_TCCB_C0 (RH) */
#define RBA_REG_CBS_TCCB_C0_POS                                            RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TCCB_C0_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCCB_C1 (RH) */
#define RBA_REG_CBS_TCCB_C1_POS                                            RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_TCCB_C1_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCCB_C2 (RH) */
#define RBA_REG_CBS_TCCB_C2_POS                                            RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_TCCB_C2_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCCB_HSM (RH) */
#define RBA_REG_CBS_TCCB_HSM_POS                                           RBA_REG_CBS_UL(31)
#define RBA_REG_CBS_TCCB_HSM_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCCH_C0 (RH) */
#define RBA_REG_CBS_TCCH_C0_POS                                            RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TCCH_C0_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCCH_C1 (RH) */
#define RBA_REG_CBS_TCCH_C1_POS                                            RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_TCCH_C1_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCCH_C2 (RH) */
#define RBA_REG_CBS_TCCH_C2_POS                                            RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_TCCH_C2_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCCH_HSM (RH) */
#define RBA_REG_CBS_TCCH_HSM_POS                                           RBA_REG_CBS_UL(31)
#define RBA_REG_CBS_TCCH_HSM_LEN                                           RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCTGB_OTGB0 (RH) */
#define RBA_REG_CBS_TCTGB_OTGB0_POS                                        RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TCTGB_OTGB0_LEN                                        RBA_REG_CBS_UL(16)

/* RBA_REG_CBS_TCTGB_OTGB1 (RH) */
#define RBA_REG_CBS_TCTGB_OTGB1_POS                                        RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TCTGB_OTGB1_LEN                                        RBA_REG_CBS_UL(16)

/* RBA_REG_CBS_TCM_BRK (RH) */
#define RBA_REG_CBS_TCM_BRK_POS                                            RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TCM_BRK_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCM_SUS (RH) */
#define RBA_REG_CBS_TCM_SUS_POS                                            RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_TCM_SUS_LEN                                            RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCM_T0 (RH) */
#define RBA_REG_CBS_TCM_T0_POS                                             RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TCM_T0_LEN                                             RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCM_T1 (RH) */
#define RBA_REG_CBS_TCM_T1_POS                                             RBA_REG_CBS_UL(9)
#define RBA_REG_CBS_TCM_T1_LEN                                             RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCM_T2 (RH) */
#define RBA_REG_CBS_TCM_T2_POS                                             RBA_REG_CBS_UL(10)
#define RBA_REG_CBS_TCM_T2_LEN                                             RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TCM_T3 (RH) */
#define RBA_REG_CBS_TCM_T3_POS                                             RBA_REG_CBS_UL(11)
#define RBA_REG_CBS_TCM_T3_LEN                                             RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRECx_TR0EV (RW) */
#define RBA_REG_CBS_TRECx_TR0EV_POS                                        RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TRECx_TR0EV_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRECx_TR2EV (RW) */
#define RBA_REG_CBS_TRECx_TR2EV_POS                                        RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TRECx_TR2EV_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRECx_TR4EV (RW) */
#define RBA_REG_CBS_TRECx_TR4EV_POS                                        RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TRECx_TR4EV_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRECx_TR6EV (RW) */
#define RBA_REG_CBS_TRECx_TR6EV_POS                                        RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_TRECx_TR6EV_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRMT_TG0 (RW) */
#define RBA_REG_CBS_TRMT_TG0_POS                                           RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TRMT_TG0_LEN                                           RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRMT_TG1 (RW) */
#define RBA_REG_CBS_TRMT_TG1_POS                                           RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TRMT_TG1_LEN                                           RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRMT_TG2 (RW) */
#define RBA_REG_CBS_TRMT_TG2_POS                                           RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TRMT_TG2_LEN                                           RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRMT_TG3 (RW) */
#define RBA_REG_CBS_TRMT_TG3_POS                                           RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TRMT_TG3_LEN                                           RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0L_TG0 (RW) */
#define RBA_REG_CBS_TRTGB0L_TG0_POS                                        RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TRTGB0L_TG0_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0L_TG1 (RW) */
#define RBA_REG_CBS_TRTGB0L_TG1_POS                                        RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TRTGB0L_TG1_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0L_TG2 (RW) */
#define RBA_REG_CBS_TRTGB0L_TG2_POS                                        RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TRTGB0L_TG2_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0L_TG3 (RW) */
#define RBA_REG_CBS_TRTGB0L_TG3_POS                                        RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TRTGB0L_TG3_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0L_TG4 (RW) */
#define RBA_REG_CBS_TRTGB0L_TG4_POS                                        RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TRTGB0L_TG4_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0L_TG5 (RW) */
#define RBA_REG_CBS_TRTGB0L_TG5_POS                                        RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TRTGB0L_TG5_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0L_TG6 (RW) */
#define RBA_REG_CBS_TRTGB0L_TG6_POS                                        RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_TRTGB0L_TG6_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0L_TG7 (RW) */
#define RBA_REG_CBS_TRTGB0L_TG7_POS                                        RBA_REG_CBS_UL(28)
#define RBA_REG_CBS_TRTGB0L_TG7_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0H_TG8 (RW) */
#define RBA_REG_CBS_TRTGB0H_TG8_POS                                        RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TRTGB0H_TG8_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0H_TG9 (RW) */
#define RBA_REG_CBS_TRTGB0H_TG9_POS                                        RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TRTGB0H_TG9_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0H_TG10 (RW) */
#define RBA_REG_CBS_TRTGB0H_TG10_POS                                       RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TRTGB0H_TG10_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0H_TG11 (RW) */
#define RBA_REG_CBS_TRTGB0H_TG11_POS                                       RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TRTGB0H_TG11_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0H_TG12 (RW) */
#define RBA_REG_CBS_TRTGB0H_TG12_POS                                       RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TRTGB0H_TG12_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0H_TG13 (RW) */
#define RBA_REG_CBS_TRTGB0H_TG13_POS                                       RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TRTGB0H_TG13_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0H_TG14 (RW) */
#define RBA_REG_CBS_TRTGB0H_TG14_POS                                       RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_TRTGB0H_TG14_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB0H_TG15 (RW) */
#define RBA_REG_CBS_TRTGB0H_TG15_POS                                       RBA_REG_CBS_UL(28)
#define RBA_REG_CBS_TRTGB0H_TG15_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1L_TG0 (RW) */
#define RBA_REG_CBS_TRTGB1L_TG0_POS                                        RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TRTGB1L_TG0_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1L_TG1 (RW) */
#define RBA_REG_CBS_TRTGB1L_TG1_POS                                        RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TRTGB1L_TG1_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1L_TG2 (RW) */
#define RBA_REG_CBS_TRTGB1L_TG2_POS                                        RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TRTGB1L_TG2_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1L_TG3 (RW) */
#define RBA_REG_CBS_TRTGB1L_TG3_POS                                        RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TRTGB1L_TG3_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1L_TG4 (RW) */
#define RBA_REG_CBS_TRTGB1L_TG4_POS                                        RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TRTGB1L_TG4_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1L_TG5 (RW) */
#define RBA_REG_CBS_TRTGB1L_TG5_POS                                        RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TRTGB1L_TG5_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1L_TG6 (RW) */
#define RBA_REG_CBS_TRTGB1L_TG6_POS                                        RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_TRTGB1L_TG6_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1L_TG7 (RW) */
#define RBA_REG_CBS_TRTGB1L_TG7_POS                                        RBA_REG_CBS_UL(28)
#define RBA_REG_CBS_TRTGB1L_TG7_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1H_TG8 (RW) */
#define RBA_REG_CBS_TRTGB1H_TG8_POS                                        RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TRTGB1H_TG8_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1H_TG9 (RW) */
#define RBA_REG_CBS_TRTGB1H_TG9_POS                                        RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TRTGB1H_TG9_LEN                                        RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1H_TG10 (RW) */
#define RBA_REG_CBS_TRTGB1H_TG10_POS                                       RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TRTGB1H_TG10_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1H_TG11 (RW) */
#define RBA_REG_CBS_TRTGB1H_TG11_POS                                       RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TRTGB1H_TG11_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1H_TG12 (RW) */
#define RBA_REG_CBS_TRTGB1H_TG12_POS                                       RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TRTGB1H_TG12_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1H_TG13 (RW) */
#define RBA_REG_CBS_TRTGB1H_TG13_POS                                       RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TRTGB1H_TG13_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1H_TG14 (RW) */
#define RBA_REG_CBS_TRTGB1H_TG14_POS                                       RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_TRTGB1H_TG14_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRTGB1H_TG15 (RW) */
#define RBA_REG_CBS_TRTGB1H_TG15_POS                                       RBA_REG_CBS_UL(28)
#define RBA_REG_CBS_TRTGB1H_TG15_LEN                                       RBA_REG_CBS_UL(4)

/* RBA_REG_CBS_TRIGx_TRGX_0 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_0_POS                                       RBA_REG_CBS_UL(0)
#define RBA_REG_CBS_TRIGx_TRGX_0_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_1 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_1_POS                                       RBA_REG_CBS_UL(1)
#define RBA_REG_CBS_TRIGx_TRGX_1_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_2 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_2_POS                                       RBA_REG_CBS_UL(2)
#define RBA_REG_CBS_TRIGx_TRGX_2_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_3 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_3_POS                                       RBA_REG_CBS_UL(3)
#define RBA_REG_CBS_TRIGx_TRGX_3_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_4 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_4_POS                                       RBA_REG_CBS_UL(4)
#define RBA_REG_CBS_TRIGx_TRGX_4_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_5 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_5_POS                                       RBA_REG_CBS_UL(5)
#define RBA_REG_CBS_TRIGx_TRGX_5_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_6 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_6_POS                                       RBA_REG_CBS_UL(6)
#define RBA_REG_CBS_TRIGx_TRGX_6_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_7 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_7_POS                                       RBA_REG_CBS_UL(7)
#define RBA_REG_CBS_TRIGx_TRGX_7_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_8 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_8_POS                                       RBA_REG_CBS_UL(8)
#define RBA_REG_CBS_TRIGx_TRGX_8_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_9 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_9_POS                                       RBA_REG_CBS_UL(9)
#define RBA_REG_CBS_TRIGx_TRGX_9_LEN                                       RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_10 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_10_POS                                      RBA_REG_CBS_UL(10)
#define RBA_REG_CBS_TRIGx_TRGX_10_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_11 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_11_POS                                      RBA_REG_CBS_UL(11)
#define RBA_REG_CBS_TRIGx_TRGX_11_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_12 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_12_POS                                      RBA_REG_CBS_UL(12)
#define RBA_REG_CBS_TRIGx_TRGX_12_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_13 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_13_POS                                      RBA_REG_CBS_UL(13)
#define RBA_REG_CBS_TRIGx_TRGX_13_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_14 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_14_POS                                      RBA_REG_CBS_UL(14)
#define RBA_REG_CBS_TRIGx_TRGX_14_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_15 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_15_POS                                      RBA_REG_CBS_UL(15)
#define RBA_REG_CBS_TRIGx_TRGX_15_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_16 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_16_POS                                      RBA_REG_CBS_UL(16)
#define RBA_REG_CBS_TRIGx_TRGX_16_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_17 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_17_POS                                      RBA_REG_CBS_UL(17)
#define RBA_REG_CBS_TRIGx_TRGX_17_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_18 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_18_POS                                      RBA_REG_CBS_UL(18)
#define RBA_REG_CBS_TRIGx_TRGX_18_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_19 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_19_POS                                      RBA_REG_CBS_UL(19)
#define RBA_REG_CBS_TRIGx_TRGX_19_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_20 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_20_POS                                      RBA_REG_CBS_UL(20)
#define RBA_REG_CBS_TRIGx_TRGX_20_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_21 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_21_POS                                      RBA_REG_CBS_UL(21)
#define RBA_REG_CBS_TRIGx_TRGX_21_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_22 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_22_POS                                      RBA_REG_CBS_UL(22)
#define RBA_REG_CBS_TRIGx_TRGX_22_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_TRGX_23 (RH) */
#define RBA_REG_CBS_TRIGx_TRGX_23_POS                                      RBA_REG_CBS_UL(23)
#define RBA_REG_CBS_TRIGx_TRGX_23_LEN                                      RBA_REG_CBS_UL(1)

/* RBA_REG_CBS_TRIGx_X (RH) */
#define RBA_REG_CBS_TRIGx_X_POS                                            RBA_REG_CBS_UL(24)
#define RBA_REG_CBS_TRIGx_X_LEN                                            RBA_REG_CBS_UL(8)

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
