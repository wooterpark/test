/*
 * This is Ioc.h, auto-generated for:
 *   Project: Os_Config
 *   Target:  TriCoreHighTec
 *   Variant: TC27xC
 *   Version: 5.0.21
 *   [$UKS 1359] [$UKS 1334] [$UKS 1454]
 */
#ifndef OS_IOC_H
#define OS_IOC_H
/* -- Start expansion of <OsIoc.h> -- */
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, IocRead*, IocWrite*, IocSend*, IocRec*) */
#include "Rte_Type.h"

#define IOC_E_OK        RTE_E_OK         /* [$UKS 1360] */
#define IOC_E_NOK       RTE_E_NOK        /* [$UKS 1361] */
#define IOC_E_LIMIT     RTE_E_LIMIT      /* [$UKS 1362] */
#define IOC_E_LOST_DATA RTE_E_LOST_DATA  /* [$UKS 1363] */
#define IOC_E_NO_DATA   RTE_E_NO_DATA    /* [$UKS 1364] */

/* IOC internal data */







/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_CODE_LIB
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
#define IocWrite_Rte_Rx_000045_HSPF_iPhaUOffset(value) (Os_Ioc_Rte_Rx_000045_HSPF_iPhaUOffset = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000045_HSPF_iPhaUOffset(value) (*value = Os_Ioc_Rte_Rx_000045_HSPF_iPhaUOffset, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000046_HSPF_iPhaVOffset(value) (Os_Ioc_Rte_Rx_000046_HSPF_iPhaVOffset = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000046_HSPF_iPhaVOffset(value) (*value = Os_Ioc_Rte_Rx_000046_HSPF_iPhaVOffset, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000047_HSPF_iPhaWOffset(value) (Os_Ioc_Rte_Rx_000047_HSPF_iPhaWOffset = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000047_HSPF_iPhaWOffset(value) (*value = Os_Ioc_Rte_Rx_000047_HSPF_iPhaWOffset, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000049_HSPF_stIphaOffCal(value) (Os_Ioc_Rte_Rx_000049_HSPF_stIphaOffCal = (uint8)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000049_HSPF_stIphaOffCal(value) (*value = Os_Ioc_Rte_Rx_000049_HSPF_stIphaOffCal, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000052_HSPF_tCoolantTempFlt(value) (Os_Ioc_Rte_Rx_000052_HSPF_tCoolantTempFlt = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000052_HSPF_tCoolantTempFlt(value) (*value = Os_Ioc_Rte_Rx_000052_HSPF_tCoolantTempFlt, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000055_HSPF_tDBCTempUFlt(value) (Os_Ioc_Rte_Rx_000055_HSPF_tDBCTempUFlt = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000055_HSPF_tDBCTempUFlt(value) (*value = Os_Ioc_Rte_Rx_000055_HSPF_tDBCTempUFlt, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000057_HSPF_tDBCTempVFlt(value) (Os_Ioc_Rte_Rx_000057_HSPF_tDBCTempVFlt = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000057_HSPF_tDBCTempVFlt(value) (*value = Os_Ioc_Rte_Rx_000057_HSPF_tDBCTempVFlt, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000059_HSPF_tDBCTempWFlt(value) (Os_Ioc_Rte_Rx_000059_HSPF_tDBCTempWFlt = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000059_HSPF_tDBCTempWFlt(value) (*value = Os_Ioc_Rte_Rx_000059_HSPF_tDBCTempWFlt, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000064_HSPF_tStrrTempFlt(value) (Os_Ioc_Rte_Rx_000064_HSPF_tStrrTempFlt = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000064_HSPF_tStrrTempFlt(value) (*value = Os_Ioc_Rte_Rx_000064_HSPF_tStrrTempFlt, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000067_HSPF_uDcLnkSlowFlt(value) (Os_Ioc_Rte_Rx_000067_HSPF_uDcLnkSlowFlt = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000067_HSPF_uDcLnkSlowFlt(value) (*value = Os_Ioc_Rte_Rx_000067_HSPF_uDcLnkSlowFlt, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000077_HvMcu_uDcLnkHvMcu(value) (Os_Ioc_Rte_Rx_000077_HvMcu_uDcLnkHvMcu = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000077_HvMcu_uDcLnkHvMcu(value) (*value = Os_Ioc_Rte_Rx_000077_HvMcu_uDcLnkHvMcu, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000085_MCF_Is(value) (Os_Ioc_Rte_Rx_000085_MCF_Is = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000085_MCF_Is(value) (*value = Os_Ioc_Rte_Rx_000085_MCF_Is, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000087_MCF_VoltModuRate(value) (Os_Ioc_Rte_Rx_000087_MCF_VoltModuRate = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000087_MCF_VoltModuRate(value) (*value = Os_Ioc_Rte_Rx_000087_MCF_VoltModuRate, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000088_MCF_cofFrqPwm(value) (Os_Ioc_Rte_Rx_000088_MCF_cofFrqPwm = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000088_MCF_cofFrqPwm(value) (*value = Os_Ioc_Rte_Rx_000088_MCF_cofFrqPwm, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000089_MCF_dtPwm(value) (Os_Ioc_Rte_Rx_000089_MCF_dtPwm = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000089_MCF_dtPwm(value) (*value = Os_Ioc_Rte_Rx_000089_MCF_dtPwm, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000091_MCF_iU(value) (Os_Ioc_Rte_Rx_000091_MCF_iU = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000091_MCF_iU(value) (*value = Os_Ioc_Rte_Rx_000091_MCF_iU, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000093_MCF_iV(value) (Os_Ioc_Rte_Rx_000093_MCF_iV = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000093_MCF_iV(value) (*value = Os_Ioc_Rte_Rx_000093_MCF_iV, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000095_MCF_iW(value) (Os_Ioc_Rte_Rx_000095_MCF_iW = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000095_MCF_iW(value) (*value = Os_Ioc_Rte_Rx_000095_MCF_iW, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000097_MCF_idDes(value) (Os_Ioc_Rte_Rx_000097_MCF_idDes = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000097_MCF_idDes(value) (*value = Os_Ioc_Rte_Rx_000097_MCF_idDes, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000098_MCF_iqDes(value) (Os_Ioc_Rte_Rx_000098_MCF_iqDes = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000098_MCF_iqDes(value) (*value = Os_Ioc_Rte_Rx_000098_MCF_iqDes, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000099_MCF_isd(value) (Os_Ioc_Rte_Rx_000099_MCF_isd = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000099_MCF_isd(value) (*value = Os_Ioc_Rte_Rx_000099_MCF_isd, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000100_MCF_isq(value) (Os_Ioc_Rte_Rx_000100_MCF_isq = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000100_MCF_isq(value) (*value = Os_Ioc_Rte_Rx_000100_MCF_isq, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000104_MCF_uDcLnk(value) (Os_Ioc_Rte_Rx_000104_MCF_uDcLnk = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000104_MCF_uDcLnk(value) (*value = Os_Ioc_Rte_Rx_000104_MCF_uDcLnk, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000105_MCF_udDes(value) (Os_Ioc_Rte_Rx_000105_MCF_udDes = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000105_MCF_udDes(value) (*value = Os_Ioc_Rte_Rx_000105_MCF_udDes, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000106_MCF_uqDes(value) (Os_Ioc_Rte_Rx_000106_MCF_uqDes = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000106_MCF_uqDes(value) (*value = Os_Ioc_Rte_Rx_000106_MCF_uqDes, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000108_MDF_bFaultEMBlkWarnSt(value) (Os_Ioc_Rte_Rx_000108_MDF_bFaultEMBlkWarnSt = (uint8)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000108_MDF_bFaultEMBlkWarnSt(value) (*value = Os_Ioc_Rte_Rx_000108_MDF_bFaultEMBlkWarnSt, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000110_MPC_CofRandomPwm(value) (Os_Ioc_Rte_Rx_000110_MPC_CofRandomPwm = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000110_MPC_CofRandomPwm(value) (*value = Os_Ioc_Rte_Rx_000110_MPC_CofRandomPwm, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000112_MPC_Ld(value) (Os_Ioc_Rte_Rx_000112_MPC_Ld = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000112_MPC_Ld(value) (*value = Os_Ioc_Rte_Rx_000112_MPC_Ld, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000114_MPC_LdSubLq(value) (Os_Ioc_Rte_Rx_000114_MPC_LdSubLq = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000114_MPC_LdSubLq(value) (*value = Os_Ioc_Rte_Rx_000114_MPC_LdSubLq, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000115_MPC_Lq(value) (Os_Ioc_Rte_Rx_000115_MPC_Lq = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000115_MPC_Lq(value) (*value = Os_Ioc_Rte_Rx_000115_MPC_Lq, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000117_MPC_OmBw(value) (Os_Ioc_Rte_Rx_000117_MPC_OmBw = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000117_MPC_OmBw(value) (*value = Os_Ioc_Rte_Rx_000117_MPC_OmBw, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000118_MPC_Psi(value) (Os_Ioc_Rte_Rx_000118_MPC_Psi = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000118_MPC_Psi(value) (*value = Os_Ioc_Rte_Rx_000118_MPC_Psi, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000120_MPC_Rs(value) (Os_Ioc_Rte_Rx_000120_MPC_Rs = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000120_MPC_Rs(value) (*value = Os_Ioc_Rte_Rx_000120_MPC_Rs, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000122_MPC_Rv(value) (Os_Ioc_Rte_Rx_000122_MPC_Rv = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000122_MPC_Rv(value) (*value = Os_Ioc_Rte_Rx_000122_MPC_Rv, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000124_MPC_TrqMechFlt(value) (Os_Ioc_Rte_Rx_000124_MPC_TrqMechFlt = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000124_MPC_TrqMechFlt(value) (*value = Os_Ioc_Rte_Rx_000124_MPC_TrqMechFlt, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000126_MPC_dtCorFac(value) (Os_Ioc_Rte_Rx_000126_MPC_dtCorFac = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000126_MPC_dtCorFac(value) (*value = Os_Ioc_Rte_Rx_000126_MPC_dtCorFac, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000127_MPC_frqPwmVF(value) (Os_Ioc_Rte_Rx_000127_MPC_frqPwmVF = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000127_MPC_frqPwmVF(value) (*value = Os_Ioc_Rte_Rx_000127_MPC_frqPwmVF, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000128_MPC_isdFF(value) (Os_Ioc_Rte_Rx_000128_MPC_isdFF = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000128_MPC_isdFF(value) (*value = Os_Ioc_Rte_Rx_000128_MPC_isdFF, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000130_MPC_isdMTPA(value) (Os_Ioc_Rte_Rx_000130_MPC_isdMTPA = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000130_MPC_isdMTPA(value) (*value = Os_Ioc_Rte_Rx_000130_MPC_isdMTPA, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000131_MPC_isdMTPV(value) (Os_Ioc_Rte_Rx_000131_MPC_isdMTPV = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000131_MPC_isdMTPV(value) (*value = Os_Ioc_Rte_Rx_000131_MPC_isdMTPV, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000133_NvM_AngAutoClbOffset(value) (Os_Ioc_Rte_Rx_000133_NvM_AngAutoClbOffset = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000133_NvM_AngAutoClbOffset(value) (*value = Os_Ioc_Rte_Rx_000133_NvM_AngAutoClbOffset, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000136_NvM_flgAngAutoClbOffset(value) (Os_Ioc_Rte_Rx_000136_NvM_flgAngAutoClbOffset = (boolean)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000136_NvM_flgAngAutoClbOffset(value) (*value = Os_Ioc_Rte_Rx_000136_NvM_flgAngAutoClbOffset, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000149_PhC_iUNoOff(value) (Os_Ioc_Rte_Rx_000149_PhC_iUNoOff = (uint16)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000149_PhC_iUNoOff(value) (*value = Os_Ioc_Rte_Rx_000149_PhC_iUNoOff, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000151_PhC_iVNoOff(value) (Os_Ioc_Rte_Rx_000151_PhC_iVNoOff = (uint16)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000151_PhC_iVNoOff(value) (*value = Os_Ioc_Rte_Rx_000151_PhC_iVNoOff, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000153_PhC_iWNoOff(value) (Os_Ioc_Rte_Rx_000153_PhC_iWNoOff = (uint16)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000153_PhC_iWNoOff(value) (*value = Os_Ioc_Rte_Rx_000153_PhC_iWNoOff, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000154_PhC_uDcLnkLowMcu(value) (Os_Ioc_Rte_Rx_000154_PhC_uDcLnkLowMcu = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000154_PhC_uDcLnkLowMcu(value) (*value = Os_Ioc_Rte_Rx_000154_PhC_uDcLnkLowMcu, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000157_RCF_UsAlfaScalSet(value) (Os_Ioc_Rte_Rx_000157_RCF_UsAlfaScalSet = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000157_RCF_UsAlfaScalSet(value) (*value = Os_Ioc_Rte_Rx_000157_RCF_UsAlfaScalSet, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000158_RCF_UsBetaScalSet(value) (Os_Ioc_Rte_Rx_000158_RCF_UsBetaScalSet = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000158_RCF_UsBetaScalSet(value) (*value = Os_Ioc_Rte_Rx_000158_RCF_UsBetaScalSet, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000159_RCF_agRtrOffsEstimd(value) (Os_Ioc_Rte_Rx_000159_RCF_agRtrOffsEstimd = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000159_RCF_agRtrOffsEstimd(value) (*value = Os_Ioc_Rte_Rx_000159_RCF_agRtrOffsEstimd, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000163_RCF_flgUseUsSet(value) (Os_Ioc_Rte_Rx_000163_RCF_flgUseUsSet = (boolean)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000163_RCF_flgUseUsSet(value) (*value = Os_Ioc_Rte_Rx_000163_RCF_flgUseUsSet, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000166_Rdc_ArctanAgRtr(value) (Os_Ioc_Rte_Rx_000166_Rdc_ArctanAgRtr = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000166_Rdc_ArctanAgRtr(value) (*value = Os_Ioc_Rte_Rx_000166_Rdc_ArctanAgRtr, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000169_Rdc_nWoFlt(value) (Os_Ioc_Rte_Rx_000169_Rdc_nWoFlt = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000169_Rdc_nWoFlt(value) (*value = Os_Ioc_Rte_Rx_000169_Rdc_nWoFlt, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000170_SCF_FIM_ReqFailrMod(value) (Os_Ioc_Rte_Rx_000170_SCF_FIM_ReqFailrMod = (boolean)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000170_SCF_FIM_ReqFailrMod(value) (*value = Os_Ioc_Rte_Rx_000170_SCF_FIM_ReqFailrMod, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000173_SCF_flgEnDchaToMc(value) (Os_Ioc_Rte_Rx_000173_SCF_flgEnDchaToMc = (boolean)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000173_SCF_flgEnDchaToMc(value) (*value = Os_Ioc_Rte_Rx_000173_SCF_flgEnDchaToMc, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000175_SCF_flginitPI(value) (Os_Ioc_Rte_Rx_000175_SCF_flginitPI = (boolean)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000175_SCF_flginitPI(value) (*value = Os_Ioc_Rte_Rx_000175_SCF_flginitPI, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000179_SCF_stGateDrv(value) (Os_Ioc_Rte_Rx_000179_SCF_stGateDrv = (uint8)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000179_SCF_stGateDrv(value) (*value = Os_Ioc_Rte_Rx_000179_SCF_stGateDrv, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000183_SCF_stPwmMode(value) (Os_Ioc_Rte_Rx_000183_SCF_stPwmMode = (uint8)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000183_SCF_stPwmMode(value) (*value = Os_Ioc_Rte_Rx_000183_SCF_stPwmMode, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000185_BCC_iDcLnkEstFlt(value) (Os_Ioc_Rte_Rx_000185_BCC_iDcLnkEstFlt = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000185_BCC_iDcLnkEstFlt(value) (*value = Os_Ioc_Rte_Rx_000185_BCC_iDcLnkEstFlt, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000187_BCC_tCoolantTj(value) (Os_Ioc_Rte_Rx_000187_BCC_tCoolantTj = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000187_BCC_tCoolantTj(value) (*value = Os_Ioc_Rte_Rx_000187_BCC_tCoolantTj, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000188_BCC_tIgbtTj(value) (Os_Ioc_Rte_Rx_000188_BCC_tIgbtTj = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocRead_Rte_Rx_000188_BCC_tIgbtTj(value) (*value = Os_Ioc_Rte_Rx_000188_BCC_tIgbtTj, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocWrite_Rte_Rx_000225_TDC_TrqDes(value) (Os_Ioc_Rte_Rx_000225_TDC_TrqDes = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000225_TDC_TrqDes(value) (*value = Os_Ioc_Rte_Rx_000225_TDC_TrqDes, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000230_TPC_TDbcTrqMax(value) (Os_Ioc_Rte_Rx_000230_TPC_TDbcTrqMax = (float32)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000230_TPC_TDbcTrqMax(value) (*value = Os_Ioc_Rte_Rx_000230_TPC_TDbcTrqMax, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
#define IocWrite_Rte_Rx_000245_TPC_stMotorMod(value) (Os_Ioc_Rte_Rx_000245_TPC_stMotorMod = (uint8)value, IOC_E_OK) /* Only callable from: OsAppCore0 (Trusted on core 0) */
#define IocRead_Rte_Rx_000245_TPC_stMotorMod(value) (*value = Os_Ioc_Rte_Rx_000245_TPC_stMotorMod, IOC_E_OK) /* Only callable from: OsAppCore2 (Trusted on core 2) */
extern FUNC(void, OS_CODE) Os_ioc_memcpy(void *dest, const void *source, uint32 length);
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_CODE_LIB
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern OS_VOLATILE VAR(Os_Lockable, OS_VAR_NO_INIT) Os_lock_iocaccess;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000045_HSPF_iPhaUOffset;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000046_HSPF_iPhaVOffset;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000047_HSPF_iPhaWOffset;
extern VAR(uint8, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000049_HSPF_stIphaOffCal;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000052_HSPF_tCoolantTempFlt;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000055_HSPF_tDBCTempUFlt;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000057_HSPF_tDBCTempVFlt;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000059_HSPF_tDBCTempWFlt;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000064_HSPF_tStrrTempFlt;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000067_HSPF_uDcLnkSlowFlt;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000077_HvMcu_uDcLnkHvMcu;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000085_MCF_Is;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000087_MCF_VoltModuRate;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000088_MCF_cofFrqPwm;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000089_MCF_dtPwm;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000091_MCF_iU;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000093_MCF_iV;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000095_MCF_iW;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000097_MCF_idDes;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000098_MCF_iqDes;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000099_MCF_isd;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000100_MCF_isq;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000104_MCF_uDcLnk;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000105_MCF_udDes;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000106_MCF_uqDes;
extern VAR(uint8, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000108_MDF_bFaultEMBlkWarnSt;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000110_MPC_CofRandomPwm;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000112_MPC_Ld;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000114_MPC_LdSubLq;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000115_MPC_Lq;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000117_MPC_OmBw;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000118_MPC_Psi;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000120_MPC_Rs;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000122_MPC_Rv;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000124_MPC_TrqMechFlt;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000126_MPC_dtCorFac;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000127_MPC_frqPwmVF;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000128_MPC_isdFF;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000130_MPC_isdMTPA;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000131_MPC_isdMTPV;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000133_NvM_AngAutoClbOffset;
extern VAR(boolean, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000136_NvM_flgAngAutoClbOffset;
extern VAR(uint16, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000149_PhC_iUNoOff;
extern VAR(uint16, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000151_PhC_iVNoOff;
extern VAR(uint16, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000153_PhC_iWNoOff;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000154_PhC_uDcLnkLowMcu;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000157_RCF_UsAlfaScalSet;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000158_RCF_UsBetaScalSet;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000159_RCF_agRtrOffsEstimd;
extern VAR(boolean, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000163_RCF_flgUseUsSet;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000166_Rdc_ArctanAgRtr;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000169_Rdc_nWoFlt;
extern VAR(boolean, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000170_SCF_FIM_ReqFailrMod;
extern VAR(boolean, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000173_SCF_flgEnDchaToMc;
extern VAR(boolean, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000175_SCF_flginitPI;
extern VAR(uint8, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000179_SCF_stGateDrv;
extern VAR(uint8, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000183_SCF_stPwmMode;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000185_BCC_iDcLnkEstFlt;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000187_BCC_tCoolantTj;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000188_BCC_tIgbtTj;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000225_TDC_TrqDes;
extern VAR(float32, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000230_TPC_TDbcTrqMax;
extern VAR(uint8, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000245_TPC_stMotorMod;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */

/* -- End expansion of <OsIoc.h> -- */
#endif /* OS_IOC_H */
