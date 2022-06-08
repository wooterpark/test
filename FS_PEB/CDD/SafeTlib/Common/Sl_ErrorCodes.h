/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Sl_ErrorCodes.h $                                          **
**                                                                           **
**  $CC VERSION : \main\139 $                                                **
**                                                                           **
**  $DATE       : 2016-04-12 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Defines common error codes shared by all tests and some    **
**                 simple macros for error code assembly / disassembly.       **
**                                                                            **
**  REFERENCE(S) :                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef SL_ERRORCODES_H
#define SL_ERRORCODES_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Platform_Types.h"
#include "Sl_Timeout.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Assemble an error code from a given Test Type ID, Error Group ID and Error ID:   */
#define ERROR_CODE(TTID, GRP, EID)  ( (Sl_TstRsltType)(((((uint32)(TTID)) & (uint32)0xFFFF) << 16U) | \
                                                       ((((uint32)(GRP))  & (uint32)0xFF)   <<  8U) | \
                                                       ((((uint32)(EID))  & (uint32)0xFF))) )

/* Extract the Test Type ID from a given error code:                                */
#define ERROR_TTID(EC)              ( (Sl_ErrorTstTypeIdType)(((EC) & (uint32)0xFFFF0000U) >> 16U) )

/* Extract the Error Group ID from a given error code:                              */
#define ERROR_GROUP_ID(EC)          ( (Sl_ErrorGroupIdType)(((EC) & (uint32)0xFF00) >> 8U) )

/* Extract the Error ID from a given error code:                                    */
#define ERROR_ID(EC)                ( (Sl_ErrorIdType)(((EC) & (uint32)0xFF)) )


/* Test a given error code for simple pass/fail:                                    */
#define SL_SUCCESS(EC)              ((Sl_ErrorIdType)EID_SUCCESS == ERROR_ID(EC))


/* General Error IDs:                                                               */
/*   -Group General, SMU and Data:                                                  */
typedef enum _Sl_GeneralErrorId
{
  EID_DO_NOT_USE = 0x00,    /* Value 0 not to be used for MISRA compliance */
  EID_GENERALHWFAILURE = 0x01,     /* Unspecified hardware error       */
  EID_INVPARAMERR = 0x02,          /* Invalid parameter supplied       */
  EID_TIMEOUTERR = 0x03,           /* The operation timed out          */
  EID_CONSISTENCYERR = 0x04,       /* Internal consistency error       */
  EID_DATAMISMATCHERR = 0x05,      /* Data mismatch error              */
  EID_UNEXPTRAPERR = 0x06,         /* An unexpected trap occured       */
  EID_CONFIGERR = 0x07,            /* Invalid configuration setting    */
  EID_ALIGNMENTERR = 0x08,         /* Data not correctly aligned       */
  EID_RESOURCE = 0x09,             /* Acquiring a shared Resource was not successful */
  EID_TESTNOTEXECUTED = 0x0A,      /* Test not yet executed                   */
  EID_TRAPERROR = 0x0B,            /* Trap (un)registration error            */

  /* Group SMU - clubbed to avoid duplicate error ids */
  EID_STATEERR = 0x0C,
  EID_ALMSTSERR= 0x0D,
  EID_GETALMSTSERR = 0x0E,
  EID_CLRALMSTSERR = 0x0F,
  EID_GETALMACTIONERR = 0x10,
  EID_SETALMACTIONERR = 0x11,
  EID_ALMSTSSBE = 0x12,
  EID_ALMSTSDBE = 0x13,
  EID_ALMSTSMBE = 0x14,
  EID_ALMSTSADDR = 0x15,
  EID_ALMSTSECCMON = 0x16,
  EID_ALMSTSEDCCMP = 0x17,

  /* Group Data */
  EID_DATAINCONSISTANT = 0x18,
  EID_DATACORRUPTED = 0x19,  
  
  EID_SUCCESS=0xFFU         /* Success                          */
}Sl_GeneralErrorId;

/*******************************************************************************
**                                MTL Test Ids                                **
*******************************************************************************/
typedef enum
{
  /*   00  --  0x00   */    TEST_ID_GENERIC=0U,
  /*   01  --  0x01   */    TEST_ID_CPU_MPU_TST,
  /*   02  --  0x02   */    TEST_ID_SFR_CMP_TST,
  /*   03  --  0x03   */    TEST_ID_SFR_CRC_TST,
  /*   04  --  0x04   */    TEST_ID_SRI_TST,
  /*   05  --  0x05   */    TEST_ID_OSC_WDG_TST,
  /*   06  --  0x06   */    TEST_ID_BUS_MPU_LFM_TST,
  /*   07  --  0x07   */    TEST_ID_TRAP_TST,
  /*   08  --  0x08   */    TEST_ID_UNUSED_TST1, /* TEST_ID_SBST_TST is obsolete, TEST_ID_UNUSED_TST1 retained to maintain the same numbering for other TEST_IDs*/
  /*   09  --  0x09   */    TEST_ID_REG_ACC_PROT_TST,
  /*   10  --  0x0A   */    TEST_ID_PMU_ECC_EDC_TST,
  /*   11  --  0x0B   */    TEST_ID_CPU_WDG_TST,
  /*   12  --  0x0C   */    TEST_ID_SAFETY_WDG_TST,
  /*   13  --  0x0D   */    TEST_ID_VLTM_TST,
  /*   14  --  0x0E   */    TEST_ID_CLKM_TST,
  /*   15  --  0x0F   */    TEST_ID_CPUSBST_E_TST,
  /*   16  --  0x10   */    TEST_ID_CPUSBST_P_TST,
  /*   17  --  0x11   */    TEST_ID_SMU_TST_RT,
  /*   18  --  0x12   */    TEST_ID_SMU_TST_IRQ,
  /*   19  --  0x13   */    TEST_ID_UNUSED_TST2, /* TEST_ID_SMU_TST_LOCK is obsolete, TEST_ID_UNUSED_TST2 retained to maintain the same numbering for other TEST_IDs*/
  /*   20  --  0x14   */    TEST_ID_SMU_TST_NMI,
  /*   21  --  0x15   */    TEST_ID_SMU_TST_IDLE,
  /*   22  --  0x16   */    TEST_ID_SRAMECC_TST,
  /*   23  --  0x17   */    TEST_ID_IR_TST,
  /*   24  --  0x18   */    TEST_ID_LOCK_STEP_TST,
  /*   25  --  0x19   */    TEST_ID_LMU_REG_ACC_PROT_TST,
  /*   26  --  0x1A   */    TEST_ID_BUS_LMU_MPU_LFM_TST,
  /*   27  --  0x1B   */    TEST_ID_MBIST_TST,
  /*   28  --  0x1C   */    TEST_ID_SPB_TST_RAP,
  /*   29  --  0x1D   */    TEST_ID_SPB_TST_TIMEOUT,
  /*   30  --  0x1E   */    TEST_ID_FCE_TST,
  /*   31  --  0x1F   */    TEST_ID_DMA_CRC_TST,
  /*   32  --  0x20   */    TEST_ID_DMA_TIMESTAMP_TST,
  /*   33  --  0x21   */    TEST_ID_DMA_SAFELINKEDLIST_TST,
  /*   34  --  0x22   */    TEST_ID_IOM_TST,
  /*   35  --  0x23   */    TEST_ID_SMU_TST_RST,
  /*   36  --  0x24   */    TEST_ID_PFLASH_MON_TST,
  /*   37  --  0x25   */    TEST_ID_SFF_TST,
  /*   38  --  0x26   */    TEST_ID_PHLSRAM_TST
} Sl_TstIDType;

/* General Error Codes */
#define TEST_PASS                              (0x1ffU)
#define TEST_FAIL                              (0x101U)


/* CpuMpuTst Error Codes */
#define CPUMPU_SUCCESS                         (0x101ffU)
#define CPUMPU_NOTEXECUTED                     (0x1010aU)
#define CPUMPU_INVPARAMERR                     (0x10102U)
#define CPUMPU_DATAPROTERR                     (0x11001U)
#define CPUMPU_DATACORRUPTION                  (0x11002U)
#define CPUMPU_CONSISTENCYERR                  (0x11003U)

#define ERROR_GRP_DATAPROTECTION       ( (Sl_ErrorGroupIdType)0x10)
#define ERROR_GRP_CODEPROTECTION       ( (Sl_ErrorGroupIdType)0x20)

#define EID_DATARANGE00ERR             (0x4)
#define EID_CODERANGE00ERR             (20)
                                    
#define CPUMPU_DATARANGE_ERR(RGN)       (ERROR_CODE(TEST_ID_CPU_MPU_TST,     \
                                         ERROR_GRP_DATAPROTECTION,        \
                                        (Sl_ErrorIdType)((Sl_ErrorIdType)EID_DATARANGE00ERR + ((Sl_ErrorIdType)(RGN)))))

#define CPUMPU_CODERANGE_ERR(RGN)       (ERROR_CODE(TEST_ID_CPU_MPU_TST,     \
                                         ERROR_GRP_CODEPROTECTION,        \
                                         (Sl_ErrorIdType)((Sl_ErrorIdType)EID_CODERANGE00ERR + ((Sl_ErrorIdType)(RGN)))))


/* CpuMpuBusLfmTst Error Codes */
#define BUSMPULFM_SUCCESS                      (0x601ffU)
#define BUSMPULFM_NOTEXECUTED                  (0x6010aU)
#define BUSMPULFM_INVPARAMERR                  (0x60102U)
#define BUSMPULFM_CONFIGERR                    (0x60107U)
#define BUSMPULFM_SMU_ALMSTSERR                (0x6020dU)
#define BUSMPULFM_SMU_GETALMSTSERR             (0x6020eU)
#define BUSMPULFM_SMU_CLRALMSTSERR             (0x6020fU)
#define BUSMPULFM_SMU_GETALMACTIONERR          (0x60210U)
#define BUSMPULFM_SMU_SETALMACTIONERR          (0x60211U)
#define BUSMPULFM_SMU_STATEERR                 (0x6020cU)
#define BUSMPULFM_ERRINFO_CAUSE                (0x66309U)
#define BUSMPULFM_ERRINFO_MASTERTAG            (0x6630aU)
#define BUSMPULFM_ERRINFO_ADDRESS              (0x6630bU)
#define BUSMPULFM_ERRINFO_PREVERR              (0x6630cU)

#define ERROR_GRP_ACCGRANT              ( (Sl_ErrorGroupIdType)0x61)
#define ERROR_GRP_ACCDENY               ( (Sl_ErrorGroupIdType)0x62)

#define EID_RGN0ERR                     (0x1U)
#define BUSMPULFM_ACCGRANT_ERR(RGN)     (ERROR_CODE(TEST_ID_BUS_MPU_LFM_TST,     \
                                                   ERROR_GRP_ACCGRANT,        \
                                                   (Sl_ErrorIdType)((Sl_ErrorIdType)EID_RGN0ERR + ((Sl_ErrorIdType)(RGN)))))

#define BUSMPULFM_ACCDENY_ERR(RGN)      (ERROR_CODE(TEST_ID_BUS_MPU_LFM_TST,     \
                                                   ERROR_GRP_ACCDENY,         \
                                                   (Sl_ErrorIdType)((Sl_ErrorIdType)EID_RGN0ERR + ((Sl_ErrorIdType)(RGN)))))


/* ClkMTst Error Codes */
#define CLKM_TESTNOTEXECUTED                   (0xe010aU)
#define CLKM_SUCCESS                           (0xe01ffU)
#define CLKM_SMU_STATEERR                      (0xe020cU)
#define CLKM_SMU_GETALMACTION_ERR              (0xe0210U)
#define CLKM_SMU_SETALMACTION_ERR              (0xe0211U)
#define CLKM_SMU_GETALMSTS_ERR                 (0xe020eU)
#define CLKM_SMU_CLRALMSTS_ERR                 (0xe020fU)
#define CLKM_SMU_ALMSTS_ERR                    (0xe020dU)
#define CLKM_TIMEOUT_ALM                       (0xe5001U)

/* VltmTst Error Codes */
#define VLTM_SUCCESS                           (0xd01ffU)
#define VLTM_NOTEXECUTED                       (0xd010aU)
#define VLTM_SMU_STATEERR                      (0xd020cU)
#define VLTM_SMU_GETALMSTSERR                  (0xd020eU)
#define VLTM_SMU_CLRALMSTSERR                  (0xd020fU)
#define VLTM_SMU_ALMSTSERR                     (0xd020dU)
#define VLTM_SMU_SETALMACTIONERR               (0xd0211U)
#define VLTM_SMU_GETALMACTIONERR               (0xd0210U)
#define VLTM_OVER_VEXT                         (0xd3001U)
#define VLTM_OVER_VDDP3                        (0xd3002U)
#define VLTM_OVER_VDD                          (0xd3003U)
#define VLTM_UNDER_VEXT                        (0xd3004U)
#define VLTM_UNDER_VDDP3                       (0xd3005U)
#define VLTM_UNDER_VDD                         (0xd3006U)
#define VLTM_BGPROK_ERROR                      (0xd0107U)
#define VLTM_EVRREG_LOCKED                     (0xd0108U)

/* SBST Error Codes */



#define SBST_E_SUCCESS                         (0xF01ffU)
#define SBST_E_FAILURE                         (0xF8001U)
#define SBST_P_SUCCESS                         (0x1001ffU)
#define SBST_P_FAILURE                         (0x108001U)

/* SriTst Error Codes */
#define SRI_SUCCESS                            (0x401ffU)
#define SRI_NOTEXECUTED                        (0x4010aU)
#define SRI_INVPARAMERR                        (0x40102U)
#define SRI_TRAP_FAILURE                       (0x44006U)
#define SRI_SMU_STATEERR                       (0x4020cU)
#define SRI_SMU_GETALMSTSERR                   (0x4020eU)
#define SRI_SMU_CLRALMSTSERR                   (0x4020fU)
#define SRI_SMU_ALMSTSERR                      (0x4020dU)
#define SRI_SMU_SETALMACTIONERR                (0x40211U)
#define SRI_SMU_GETALMACTIONERR                (0x40210U)
#define SRI_LMU_ECC_DATA                       (0x44207U)
#define SRI_LMU_ECC_ADDRESS                    (0x44208U)
#define SRI_CPU_PMI_ECC_DATA                   (0x44101U)
#define SRI_CPU_PMI_ECC_ADR                    (0x44103U)
#define SRI_CPU_PMI_ECC_MDATA                  (0x44102U)
#define SRI_CPU_DMI_ECC_DATA                   (0x44104U)
#define SRI_CPU_DMI_ECC_ADR                    (0x44106U)
#define SRI_CPU_DMI_ECC_MDATA                  (0x44105U)
#define SRI_PMUDF_ECC_DATA                     (0x44309U)
#define SRI_PMUDF_ECC_ADR                      (0x4430aU)
#define SRI_PMUPF_ECC_ADR                      (0x4430bU)
#define SRI_DMA_ECC_DATA                       (0x4440cU)
#define SRI_INVALID_IDERR                      (0x44015U)
#define SRI_MBIST_CLC_TIMEOUT                  (0x44016U)
#define SRI_UNSUPP_OCERR                       (0x4400dU)
#define SRI_UNMAPPED_ACCERR                    (0x4400eU)
#define SRI_USER1_ACCERR                       (0x4400fU)
#define SRI_USER0_ACCERR                       (0x44010U)
#define SRI_ECC_ADDRESS                        (0x44011U)
#define SRI_ECC_READ                           (0x44012U)
#define SRI_ECC_WRITE                          (0x44013U)
#define SRI_ECC_ADRBTRAP_NG                    (0x44014U)
#define SRI_DMA_CLC_TIMEOUT                    (0x44017U)
#define SRI_MBIST_MC_TIMEOUT                   (0x44018U)
#define SRI_ECC_DATATRAP_NG                    (0x44019U)
#define SRI_LMUSRAM_SRI_INTERFACE_ERROR        (0x4401fU)

/* SfrCmpTst Error Codes */
#define SFR_CMP_SUCCESS                        (0x201ffU)
#define SFR_CMP_NOTEXECUTED                    (0x2010aU)
#define SFR_CMP_INVPARAMERR                    (0x20102U)
#define SFR_CMP_OVERLOAD                       (0x21010U)
#define SFR_CMP_RESGRx_REGyDM(GRP,REG)  (ERROR_CODE(TEST_ID_SFR_CMP_TST, ((GRP) + 0x11U),((REG) + 0x01U)))

/* SfrCrcTst Error Codes */
#define SFR_CRC_SUCCESS                        (0x301ffU)
#define SFR_CRC_NOTEXECUTED                    (0x3010aU)
#define SFR_CRC_INVPARAMERR                    (0x30102U)
#define SFR_CRC_DATAMISSMATCH                  (0x30105U)



/* RegAccTst Error Codes */
#define REGACC_SUCCESS                         (0x901ffU)
#define REGACC_NOTEXECUTED                     (0x9010aU)
#define REGACC_SMU_STATEERR                    (0x9020cU)
#define REGACC_SMU_GETALMSTSERR                (0x9020eU)
#define REGACC_SMU_CLRALMSTSERR                (0x9020fU)
#define REGACC_SMU_ALMSTSERR                   (0x9020dU)
#define REGACC_SMU_SETALMACTIONERR             (0x90211U)
#define REGACC_SMU_GETALMACTIONERR             (0x90210U)
#define REGACC_DENY_NOSMUALRM                  (0x91001U)
#define REGACC_STUCKATFAULT                    (0x91002U)
#define REGACC_ACCBLOCKED                      (0x91003U)
#define REGACC_ACCNOTBLOCKED                   (0x91004U)

/* SpbTst Error Codes */
#define SPBTST_RAP_SUCCESS                     (0x1c01ffU)
#define SPBTST_RAP_NOTEXECUTED                 (0x1c010aU)
#define SPBTST_RAP_INVPARAMERR                 (0x1c0102U)
#define SPBTST_RAP_SMU_STATEERR                (0x1c020cU)
#define SPBTST_RAP_SMU_GETALMSTSERR            (0x1c020eU)
#define SPBTST_RAP_SMU_CLRALMSTSERR            (0x1c020fU)
#define SPBTST_RAP_SMU_ALMSTSERR               (0x1c020dU)
#define SPBTST_RAP_SMU_SETALMACTIONERR         (0x1c0211U)
#define SPBTST_RAP_SMU_GETALMACTIONERR         (0x1c0210U)
#define SPBTST_RAP_DENY_NOSMUALRM              (0x1c1001U)
#define SPBTST_RAP_STUCKATFAULT                (0x1c1002U)
#define SPBTST_RAP_TRAP_FAILURE                (0x1c0107U)
#define SPBTST_TIMEOUT_SUCCESS                 (0x1d01ffU)
#define SPBTST_TIMEOUT_NOTEXECUTED             (0x1d010aU)
#define SPBTST_TIMEOUT_SMU_STATEERR            (0x1d020cU)
#define SPBTST_TIMEOUT_SMU_GETALMSTSERR        (0x1d020eU)
#define SPBTST_TIMEOUT_SMU_CLRALMSTSERR        (0x1d020fU)
#define SPBTST_TIMEOUT_SMU_ALMSTSERR           (0x1d020dU)
#define SPBTST_TIMEOUT_SMU_SETALMACTIONERR     (0x1d0211U)
#define SPBTST_TIMEOUT_SMU_GETALMACTIONERR     (0x1d0210U)
#define SPBTST_TIMEOUT_BUSERROR_TIMEOUT        (0x1d0106U)
#define SPBTST_TIMEOUT_TRAP_FAILURE            (0x1d0108U)

/* LockStepTst Error Codes */
#define LOCKSTEP_SUCCESS                       (0x1801ffU)
#define LOCKSTEP_NOTEXECUTED                   (0x18010aU)
#define LOCKSTEP_INVPARAM                      (0x180102U)
#define LOCKSTEP_NO_SMUALRM                    (0x181001U)
#define LOCKSTEP_DISABLE                       (0x181002U)
#define LOCKSTEP_NON_LOCKSTEP_CORE             (0x181003U)
#define LOCKSTEP_SMU_STATEERR                  (0x18020cU)
#define LOCKSTEP_SMU_GETALMSTSERR              (0x18020eU)
#define LOCKSTEP_SMU_CLRALMSTSERR              (0x18020fU)
#define LOCKSTEP_SMU_ALMSTSERR                 (0x18020dU)
#define LOCKSTEP_SMU_SETALMACTIONERR           (0x180211U)
#define LOCKSTEP_SMU_GETALMACTIONERR           (0x180210U)

/* CpuWdgTst Error Codes */
#define CPU_WDG_SUCCESS                        (0xb01ffU)
#define CPU_WDG_NOTEXECUTED                    (0xb010aU)
#define CPU_WDG_INVPARAMETER                   (0xb0102U)
#define CPU_WDG_SMU_GETALMSTSERR               (0xb020eU)
#define CPU_WDG_SMU_GETALMACTIONERR            (0xb0210U)
#define CPU_WDG_SMU_SETALMACTIONERR            (0xb0211U)
#define CPU_WDG_SMU_ALMSTSERR                  (0xb020dU)
#define CPU_WDG_SMU_CLRALMSTSERR               (0xb020fU)
#define CPU_WDG_SMU_STATEERR                   (0xb020cU)
#define CPU_WDG_SMU_RESOURCELOCKED             (0xb0209U)
#define CPU_WDG_ENDINIT_NOBLOCK                (0xb1001U)
#define CPU_WDG_ENDINIT_NOWRITE                (0xb1002U)
#define CPU_WDG_ENDINIT_NOTIMEOUT              (0xb1003U)
#define CPU_WDG_PF_NOTIMEOUTALERT              (0xb1104U)
#define CPU_WDG_PF_UNEXPERROR                  (0xb1105U)
#define CPU_WDG_PF_TIMEIGNORED                 (0xb1106U)
#define CPU_WDG_PF_UNEXPALARM                  (0xb1107U)

/* SafetyWdgTst Error Codes */
#define SAFETY_WDG_SUCCESS                     (0xc01ffU)
#define SAFETY_WDG_NOTEXECUTED                 (0xc010aU)
#define SAFETY_WDG_INVPARAMETER                (0xc0102U)
#define SAFETY_WDG_SMU_GETALMSTSERR            (0xc020eU)
#define SAFETY_WDG_SMU_GETALMACTIONERR         (0xc0210U)
#define SAFETY_WDG_SMU_SETALMACTIONERR         (0xc0211U)
#define SAFETY_WDG_SMU_ALMSTSERR               (0xc020dU)
#define SAFETY_WDG_SMU_CLRALMSTSERR            (0xc020fU)
#define SAFETY_WDG_SMU_STATEERR                (0xc020cU)
#define SAFETY_WDG_SMU_RESOURCELOCKED          (0xc0209U)
#define SAFETY_WDG_ENDINIT_NOBLOCK             (0xc1001U)
#define SAFETY_WDG_ENDINIT_NOWRITE             (0xc1002U)
#define SAFETY_WDG_ENDINIT_NOTIMEOUT           (0xc1003U)
#define SAFETY_WDG_PF_NOTIMEOUTALERT           (0xc1104U)
#define SAFETY_WDG_PF_UNEXPERROR               (0xc1105U)
#define SAFETY_WDG_PF_TIMEIGNORED              (0xc1106U)
#define SAFETY_WDG_PF_UNEXPALARM               (0xc1107U)

/* TrapTst Error Codes */
#define TRAPTST_SUCCESS                        (0x701ffU)
#define TRAPTST_NOTEXECUTED                    (0x7010aU)
#define TRAPTST_INVPARAM                       (0x70102U)
#define TRAPTST_TIMEOUT_RESOURCE               (0x70109U)
#define TRAPTST_SMU_GETALMACTIONERR            (0x70210U)
#define TRAPTST_SMU_ALMSTSERR                  (0x7020dU)
#define TRAPTST_SMU_GETALMSTSERR               (0x7020eU)
#define TRAPTST_SMU_SETALMACTIONERR            (0x70211U)
#define TRAPTST_SMU_CLRALMSTSERR               (0x7020fU)
#define TRAPTST_SMU_STATEERR                   (0x7020cU)
#define TRAPTST_ERROR_CLASS1                   (0x71001U)
#define TRAPTST_ERROR_CLASS2                   (0x71002U)
#define TRAPTST_ERROR_CLASS3                   (0x71003U)
#define TRAPTST_ERROR_CLASS4                   (0x71004U)
#define TRAPTST_ERROR_CLASS5                   (0x71005U)
#define TRAPTST_ERROR_CLASS6                   (0x71006U)
#define TRAPTST_TRAP_FAILURE                   (0x71008U)
#define TRAPTST_CRCMISMATCH                    (0x71009U)

/* PmuEccEdcTst Error Codes */
#define PMUECCEDC_GENERALHWFAILURE             (0xa0101U)
#define PMUECCEDC_SUCCESS                      (0xa01ffU)
#define PMUECCEDC_NOTEXECUTED                  (0xa010aU)
#define PMUECCEDC_SMU_CLRALMSTSERR             (0xa020fU)
#define PMUECCEDC_SMU_GETALMACTIONERR          (0xa0210U)
#define PMUECCEDC_SMU_SETALMACTIONERR          (0xa0211U)
#define PMUECCEDC_TIMEOUT_SBEALARM             (0xa1002U)
#define PMUECCEDC_TIMEOUT_DBEALARM             (0xa1003U)
#define PMUECCEDC_TIMEOUT_MBEALARM             (0xa1004U)
#define PMUECCEDC_TIMEOUT_ECCMONALARM          (0xa1006U)
#define PMUECCEDC_TIMEOUT_EDCCMPALARM          (0xa1007U)
#define PMUECCEDC_DATACORRUPTION               (0xa1008U)
#define PMUECCEDC_CRCERROR                     (0xa0104U)

/* SramEccTst Error Codes */
#define SRAMECC_SUCCESS                        (0x1601ffU)
#define SRAMECC_NOTEXECUTED                    (0x16010aU)
#define SRAMECC_INVPARAMERR                    (0x160102U)
#define SRAMECC_CONSISTENCYERR                 (0x160104U)
#define SRAMECC_CONFIGERR                      (0x160107U)
#define SRAMECC_SMU_GETALMSTSERR               (0x16020eU)
#define SRAMECC_SMU_CLRALMSTSERR               (0x16020fU)
#define SRAMECC_SMU_ALMSTSERR                  (0x16020dU)
#define SRAMECC_SMU_SETALMACTIONERR            (0x160211U)
#define SRAMECC_SMU_GETALMACTIONERR            (0x160210U)
#define SRAMECC_DATACORRUPTION                 (0x160319U)
#define SRAMECC_MBIST_INITIMEOUT               (0x161001U)
#define SRAMECC_MBIST_CLCTIMEOUT               (0x161003U)
#define SRAMECC_ETR_MISSING                    (0x161104U)
#define SRAMECC_ETR_DUPLICATE                  (0x161105U)
#define SRAMECC_ETR_EOVMISSING                 (0x161106U)
#define SRAMECC_MEM_ECECFG                     (0x161209U)
#define SRAMECC_MBIST_RWOPTIMEOUT              (0x16120bU)
#define SRAMECC_MBIST_RWOPFAIL                 (0x16120cU)

/*******************************************************************************
**                      MTL : PERIPHERAL SRAM TEST                            **
*******************************************************************************/

#define PHLSRAM_SUCCESS             (0x2601ffU)
#define PHLSRAM_NOTEXECUTED         (0x26010aU)
#define PHLSRAM_INVPARAMERR         (0x260102U)
#define PHLSRAM_CONSISTENCYERR      (0x260104U)
#define PHLSRAM_CONFIGERR           (0x260107U)

#define PHLSRAM_SMU_GETALMSTSERR    (0x26020eU)
#define PHLSRAM_SMU_CLRALMSTSERR    (0x26020fU)
#define PHLSRAM_SMU_ALMSTSERR       (0x26020dU)
#define PHLSRAM_SMU_SETALMACTIONERR (0x260211U)
#define PHLSRAM_SMU_GETALMACTIONERR (0x260210U)

#define PHLSRAM_DATACORRUPTION      (0x260319U)

#define PHLSRAM_SFR_LOCK            (0x260410U)


#define PHLSRAM_MBIST_CLCTIMEOUT    (0x261002U)



#define PHLSRAM_MEM_ECECFG          (0x261209U)
#define PHLSRAM_MBIST_RWOPTIMEOUT   (0x26120bU)
#define PHLSRAM_MBIST_RWOPFAIL      (0x26120cU)
/* PflashMonTst Error Codes */
#define PFLASHMON_INVPARAMERR                  (0x240102U)
#define PFLASHMON_CONFIGERR                    (0x240107U)
#define PFLASHMON_DATACONSISTENCY              (0x240104U)
#define PFLASHMON_SUCCESS                      (0x2401ffU)
#define PFLASHMON_NOTEXECUTED                  (0x24010aU)
#define PFLASHMON_SMU_GETALMACTIONERR          (0x240210U)
#define PFLASHMON_SMU_SETALMACTIONERR          (0x240211U)
#define PFLASHMON_SBE_PF0                      (0x241001U)
#define PFLASHMON_SBE_PF1                      (0x241002U)
#define PFLASHMON_SBE_PF2                      (0x241003U)
#define PFLASHMON_SBE_PF3                      (0x241004U)
#define PFLASHMON_DBE_PF0                      (0x241101U)
#define PFLASHMON_DBE_PF1                      (0x241102U)
#define PFLASHMON_DBE_PF2                      (0x241103U)
#define PFLASHMON_DBE_PF3                      (0x241104U)
#define PFLASHMON_MBE_PF0                      (0x241201U)
#define PFLASHMON_MBE_PF1                      (0x241202U)
#define PFLASHMON_MBE_PF2                      (0x241203U)
#define PFLASHMON_MBE_PF3                      (0x241204U)
#define PFLASHMON_CRCERROR                     (0x240105U)
#define PFLASHMON_BUFF_FILL_FAIL_PF0           (0x241301U)
#define PFLASHMON_BUFF_FILL_FAIL_PF1           (0x241302U)
#define PFLASHMON_BUFF_FILL_FAIL_PF2           (0x241303U)
#define PFLASHMON_BUFF_FILL_FAIL_PF3           (0x241304U)
#define PFLASHMON_SMU_CLRALMSTSERR             (0x240212U)

/* SffTst Error Codes */
#define SFF_SUCCESS                            (0x2501ffU)
#define SFF_NOTEXECUTED                        (0x25010aU)
#define SFF_RM_TESTENABLEDERR                  (0x251401U)
#define SFF_RM_TIMEOUTERR                      (0x251402U)
#define SFF_RM_ALARMNOTSETERR                  (0x251403U)

#define SFF_RM_ERRORFLAGERR                    (0x251404U)
#define SFF_RM_SMU_ERROR                       (0x251405U)
#define SFF_RM_SCU_ERROR                       (0x251406U)
#define SFF_RM_SMU_SCU_ERROR                   (0x251407U)
#define SFF_RM_MTU_ERROR                       (0x251408U)
#define SFF_RM_MTU_SMU_ERROR                   (0x251409U)
#define SFF_RM_MTU_SCU_ERROR                   (0x25140aU)
#define SFF_RM_MTU_SCU_SMU_ERROR               (0x25140bU)


#define SFF_SMU_STATEERR                       (0x25020cU)
#define SFF_SMU_ALMSTSERR                      (0x25020dU)
#define SFF_SMU_GETALMSTSERR                   (0x25020eU)
#define SFF_SMU_CLRALMSTSERR                   (0x25020fU)
#define SFF_SMU_GETALMACTIONERR                (0x250210U)
#define SFF_SMU_SETALMACTIONERR                (0x250211U)

/* LMUREGACC Error Codes */
#define LMUREGACC_SUCCESS                      (0x1901ffU)
#define LMUREGACC_NOTEXECUTED                  (0x19010aU)
#define LMUREGACC_SMU_STATEERR                 (0x19020cU)
#define LMUREGACC_SMU_GETALMSTSERR             (0x19020eU)
#define LMUREGACC_SMU_CLRALMSTSERR             (0x19020fU)
#define LMUREGACC_SMU_ALMSTSERR                (0x19020dU)
#define LMUREGACC_SMU_SETALMACTIONERR          (0x190211U)
#define LMUREGACC_SMU_GETALMACTIONERR          (0x190210U)
#define LMUREGACC_STUCKATFAULT                 (0x191002U)
#define LMUREGACC_ACCBLOCKED                   (0x191003U)
#define LMUREGACC_ACCNOTBLOCKED                (0x191004U)
#define LMUREGACC_TRAPERROR                    (0x19100bU)
#define LMUREGACC_RESOURCE_TIMEOUT             (0x190109U)

/* LMUBUSMPULFM Error Codes */


#define LMUBUSMPULFM_SUCCESS                   (0x1a01ffU)
#define LMUBUSMPULFM_NOTEXECUTED               (0x1a010aU)
#define LMUBUSMPULFM_INVPARAMERR               (0x1a0102U)
#define LMUBUSMPULFM_SMU_ALMSTSERR             (0x1a020dU)
#define LMUBUSMPULFM_SMU_GETALMSTSERR          (0x1a020eU)
#define LMUBUSMPULFM_SMU_CLRALMSTSERR          (0x1a020fU)
#define LMUBUSMPULFM_SMU_GETALMACTIONERR       (0x1a0210U)
#define LMUBUSMPULFM_SMU_SETALMACTIONERR       (0x1a0211U)
#define LMUBUSMPULFM_SMU_STATEERR              (0x1a020cU)
#define LMUBUSMPULFM_ACCGRANT_RGNERR           (0x1a6101U)
#define LMUBUSMPULFM_ACCDENY_RGNERR            (0x1a6201U)
#define LMUBUSMPULFM_TRAPERROR                 (0x1a100bU)
#define LMUBUSMPULFM_CLEAR_ERROR               (0x1a1051U)

/* FCETST Error Codes */
#define FCETST_SUCCESS                         (0x1e01ffU)
#define FCETST_FAILURE                         (0x1e0101U)
#define FCETST_CRC_MISMATCH_ERROR              (0x1e1002U)
#define FCETST_NO_CFGREG_MISMATCH_ERROR        (0x1e1003U)
#define FCETST_NO_CHECKREG_MISMATCH_ERROR      (0x1e1004U)
#define FCETST_NO_CRC_MISMATCH_ERROR           (0x1e1005U)
#define FCETST_NO_LENGTH_ERROR                 (0x1e1006U)
#define FCETST_NO_BUS_ERROR                    (0x1e1007U)
#define FCETST_RESOURCE_TIMEOUT                (0x1e0109U)
#define FCETST_INVPARAMERR                     (0x1e0102U)
#define FCETST_RESTORE_FAILURE                 (0x1e0108U)
#define FCETST_INIT_FAILURE                    (0x1e010aU)
#define FCETST_NOCFGREG_MISMAT_INTR_ERR        (0x1e1009U)
#define FCETST_NO_LENGTH_INTR_ERROR            (0x1e100AU)
#define FCETST_NO_BUS_INTR_ERROR               (0x1e100BU)
#define FCETST_NO_CHECKREG_MISMAT_INTR_ERR     (0x1e100CU)
#define FCETST_NO_CRC_MISMATCH_INTR_ERR        (0x1e100DU)

/* IRTST Error Codes */
#define IRTST_SUCCESS                          (0x1701ffU)
#define IRTST_NOTEXECUTED                      (0x17010aU)
#define IRTST_INVPARAM                         (0x170102U)
#define IRTST_SMU_CLRALMSTSERR                 (0x17020fU)
#define IRTST_SMU_GETALMSTSERR                 (0x17020eU)
#define IRTST_SMU_GETALMACTIONERR              (0x170210U)
#define IRTST_SMU_SETALMACTIONERR              (0x170211U)
#define IRTST_SMU_ALMSTSERR                    (0x17020dU)
#define IRTST_SMU_STATEERR                     (0x17020cU)
#define IRTST_NO_SMUALRM                       (0x171001U)
#define IRTST_ERROR_ICU                        (0x171003U)


/* IomTst Error Codes */
#define IOMTST_SUCCESS                         (0x2201ffU)
#define IOMTST_NOTEXECUTED                     (0x22010aU)

#define IOMTST_INVPARAM                        (0x221501U)
#define IOMTST_ALARMNOTSETERR                  (0x221502U)

#define IOMTST_SMU_STATEERR                    (0x22020cU)
#define IOMTST_SMU_ALMSTSERR                   (0x22020dU)
#define IOMTST_SMU_GETALMSTSERR                (0x22020eU)
#define IOMTST_SMU_CLRALMSTSERR                (0x22020fU)
#define IOMTST_SMU_GETALMACTIONERR             (0x220210U)
#define IOMTST_SMU_SETALMACTIONERR             (0x220211U)

/* DMATST Error Codes */
/* All following error codes are required for DMA test. Should not be removed */

#define DMA_CRC_SUCCESS                        (0x1f01ffU)
#define DMA_TIMESTAMP_SUCCESS                  (0x2001ffU)
#define DMA_SAFELINKLST_SUCCESS                (0x2101ffU)
#define DMA_CRC_TEST_NOTEXECUTED               (0x1f010aU)
#define DMA_TIMESTAMP_TEST_NOTEXECUTED         (0x20010aU)
#define DMA_SAFELINKLST_TEST_NOTEXECUTED       (0x21010aU)
#define DMA_CRC_INVALID_PARAMETER              (0x1f0102U)
#define DMA_TIMESTAMP_INVALID_PARAMETER        (0x200102U)
#define DMA_SAFELINKLST_INVALID_PARAMETER      (0x210102U)
#define DMA_CRC_RESOURCE_TIMEOUT_ERROR         (0x1f0109U)
#define DMA_TIMESTAMP_RESOURCE_TIMEOUT_ERROR   (0x200109U)
#define DMA_SAFELINKLSTRESOURCE_TIMEOUT_ERROR  (0x210109U)
#define DMA_CRC_SDCRC_FAIL                     (0x1f1001U)
#define DMA_CRC_RDCRC_FAIL                     (0x1f1002U)
#define DMA_CRC_SDCRC_RDCRC_FAIL               (0x1f1003U)
#define DMA_TIMESTAMP_FAIL                     (0x201004U)
#define DMA_SAFELINKLST_SDCRC                  (0x211005U)

/* SMUTST Error Codes */
#define SMUTST_NMI_SUCCESS                     (0x1401ffU)
#define SMUTST_NMI_NOTEXECUTED                 (0x14010aU)
#define SMUTST_NMI_TRAPERR                     (0x140102U)
#define SMUTST_NMI_TRAPREGERR                  (0x140103U)
#define SMUTST_NMI_TRAPUNREGERR                (0x140104U)
#define SMUTST_NMI_SMU_STATEERR                (0x14020cU)
#define SMUTST_NMI_SMU_ALMSTSERR               (0x14020dU)
#define SMUTST_NMI_SMU_GETALMACTIONERR         (0x140210U)
#define SMUTST_NMI_SMU_SETALMACTIONERR         (0x140211U)
#define SMUTST_NMI_SMU_SETALMSTSERR            (0x140201U)
#define SMUTST_NMI_SMU_GETALMSTSERR            (0x14020eU)
#define SMUTST_NMI_SMU_CLRALMSTSERR            (0x14020fU)
                                               

#define SMUTST_IRQ_SUCCESS                     (0x1201ffU)
#define SMUTST_IRQ_NOTEXECUTED                 (0x12010aU)
#define SMUTST_IRQ_INTNOTSETERR                (0x120102U)
#define SMUTST_IRQ_SMU_STATEERR                (0x12020cU)
#define SMUTST_IRQ_SMU_ALMSTSERR               (0x12020dU)
#define SMUTST_IRQ_SMU_GETALMACTIONERR         (0x120210U) 
#define SMUTST_IRQ_SMU_SETALMACTIONERR         (0x120211U)
#define SMUTST_IRQ_SMU_SETALMSTSERR            (0x120201U)
#define SMUTST_IRQ_SMU_GETALMSTSERR            (0x12020eU)
#define SMUTST_IRQ_SMU_CLRALMSTSERR            (0x12020fU)

#define SMUTST_RT_SUCCESS                      (0x1101ffU)
#define SMUTST_RT_NOTEXECUTED                  (0x11010aU)
#define SMUTST_RT_TIMEOUT_RTRUNERR             (0x110102U)
#define SMUTST_RT_TIMEOUT_ALMNOTSETERR         (0x110103U)
#define SMUTST_RT_STOP_RTRUNERR                (0x110104U)
#define SMUTST_RT_STOP_RTSTOPERR               (0x110105U)
#define SMUTST_RT_STOP_ALMSETERR               (0x110106U)
#define SMUTST_RT_STOP_STOPERR                 (0x110107U)
#define SMUTST_RT_MISSEDEVT_RTRUNERR           (0x110108U)
#define SMUTST_RT_MISSEDEVT_ERR                (0x110109U)
#define SMUTST_RT_MISSEDEVT_RTSTOPERR          (0x11010bU)
#define SMUTST_RT_SMU_STATEERR                 (0x11020cU)
#define SMUTST_RT_SMU_ALMSTSERR                (0x11020dU)
#define SMUTST_RT_SMU_GETALMACTIONERR          (0x110210U)
#define SMUTST_RT_SMU_SETALMACTIONERR          (0x110211U)
#define SMUTST_RT_SMU_SETALMSTSERR             (0x110201U)
#define SMUTST_RT_SMU_GETALMSTSERR             (0x11020eU)
#define SMUTST_RT_SMU_CLRALMSTSERR             (0x11020fU)

                                        
/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/* Error code type definition:                                                      */
typedef uint32              Sl_TstRsltType;

/* Error Test ID, Group ID and Error ID type definitions; these are all uint32 to
   avoid casts when extracting these fields from an error code:
*/
typedef uint32              Sl_ErrorTstTypeIdType;
typedef uint32              Sl_ErrorGroupIdType;
typedef uint32              Sl_ErrorIdType;

typedef uint32 Sl_ParamSetType;


/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* SL_ERRORCODES_H */

