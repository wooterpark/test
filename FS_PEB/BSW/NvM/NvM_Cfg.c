/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



// TRACE[NVM321]
// NvM file containing all configuration parameters which are to be implemented as constants

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "NvM.h"

#include "Rte_NvM.h"

#include "MemIf.h"
// TRACE[NVM089]
// Check version compatibility of included header files
#if (!defined(MEMIF_AR_RELEASE_MAJOR_VERSION) || (MEMIF_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION))
    #error "AUTOSAR major version undefined or mismatched"
#endif

#if (!defined(MEMIF_AR_RELEASE_MINOR_VERSION) || ((MEMIF_AR_RELEASE_MINOR_VERSION != 0) && \
                                                      (MEMIF_AR_RELEASE_MINOR_VERSION != 2)))
# error "AUTOSAR minor version undefined or mismatched"
#endif

#include "NvM_Prv.h"

// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2997]
// Include custumer/user specific declarations

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/

// Explicit sync read callback of NVRAM block Dem_GenericNvData
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_GenericNVDataReadRamBlockFromNvCallback(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_GenericNvData
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_GenericNVDataWriteRamBlockToNvCallback(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_AllEventsStatusByte
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EventStatusByteReadRamBlockFromNvCallback(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_AllEventsStatusByte
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EventStatusByteWriteRamBlockToNvCallback(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory0
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback0(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory0
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback0(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory1
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback1(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory1
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback1(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory2
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback2(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory2
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback2(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory3
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback3(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory3
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback3(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory4
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback4(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory4
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback4(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory5
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback5(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory5
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback5(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory6
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback6(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory6
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback6(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory7
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback7(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory7
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback7(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory8
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback8(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory8
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback8(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory9
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback9(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory9
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback9(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory10
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback10(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory10
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback10(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory11
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback11(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory11
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback11(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory12
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback12(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory12
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback12(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory13
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback13(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory13
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback13(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory14
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback14(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory14
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback14(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory15
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback15(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory15
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback15(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory16
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback16(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory16
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback16(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory17
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback17(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory17
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback17(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory18
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback18(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory18
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback18(void* NvMBuffer);

// Explicit sync read callback of NVRAM block Dem_EvMemEventMemory19
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback19(void* NvMBuffer);

// Explicit sync write callback of NVRAM block Dem_EvMemEventMemory19
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback19(void* NvMBuffer);

// RAM block of NVRAM block NvM_MC_Offset
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 NvM_MC_OffSet[];

// RAM block of NVRAM block NvM_DEM_ExternFF
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 errOderTable[];

// RAM block of NVRAM block DEM_HistoryEventList
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 VAR_DEM_DiagEvtHistList_au8[];

// RAM block of NVRAM block NvM_TLC_Trq
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 VAR_NvM_TLC_TrqReason_au8[];

// RAM block of NVRAM block NvM_EEP_Study
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 VAR_NvM_EEP_Study_au8[];

// RAM block of NVRAM block rba_MemDiag_StrdErr_Blk
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 rba_MemDiag_StrdErr[];

// RAM block of NVRAM block BSW_NVM_SLFnh
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 VAR_NvM_BSW_NVM_SLFnh_au8[];

// RAM block of NVRAM block BSW_NVM_AimOutP
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 VAR_NvM_BSW_NVM_AimOutP_au8[];

// RAM block of NVRAM block EPC_NVMPosAimUpLimt
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 VAR_NvM_EPC_NVMPosAimUpLimt_au8[];

// RAM block of NVRAM block EPC_flgSLWD
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 VAR_NvM_EPC_flgSLWD_au8[];

// RAM block of NVRAM block NvM_UDS_VIN
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 VAR_NvM_UDS_VIN[];

// RAM block of NVRAM block BSW_NVM_OffSet
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 VAR_BSW_NVM_OffSet[];

// RAM block of NVRAM block NvM_UDS_ECUPN_V0
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 VAR_NvM_UDS_ECUPN_V0[];

// RAM block of NVRAM block NvM_UDS_ECUPN_V4
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 VAR_NvM_UDS_ECUPN_V4[];

// RAM block of NVRAM block NvM_UDS_ECUPN_V5
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 VAR_NvM_UDS_ECUPN_V5[];

// RAM block of NVRAM block NvM_SWReset_Env
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 rba_Reset_Env_History[];

// RAM block of NVRAM block NvM_Reset_Info
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 Reset_List_History[];

// Single block callback of NVRAM block ECUM_CFG_NVM_BLOCK
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType EcuM_Rb_NvMSingleBlockCallbackFunction(uint8 ServiceId, NvM_RequestResultType JobResult);

// RAM block of NVRAM block ECUM_CFG_NVM_BLOCK
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 EcuM_Rb_dataShutdownInfo_st[];

// RAM block of NVRAM block NvM_NativeBlock_2
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 Rte_CPim_NvM_SWC_NvM_SWC_BlockNative_1024[];

// RAM block of NVRAM block NvM_NativeBlock_3
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 Rte_CPim_NvM_SWC_NvM_SWC_BlockRedundant_1024[];

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

// Array containing (persistent Id, block Id) couples sorted by ascendant persistent Ids
const NvM_Prv_PersId_BlockId_tst NvM_Prv_PersId_BlockId_acst[NVM_PRV_NR_PERSISTENT_IDS] =
{
    //{PersId, BlockId}
    {1, 2}, // NvMConf_NvMBlockDescriptor_Dem_GenericNvData
    {2, 3}, // NvMConf_NvMBlockDescriptor_Dem_AllEventsStatusByte
    {3, 4}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory0
    {4, 5}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory1
    {5, 6}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory2
    {6, 7}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory3
    {7, 8}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory4
    {8, 9}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory5
    {9, 10}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory6
    {10, 11}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory7
    {11, 12}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory8
    {12, 13}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory9
    {13, 14}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory10
    {14, 15}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory11
    {15, 16}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory12
    {16, 17}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory13
    {17, 18}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory14
    {18, 19}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory15
    {19, 20}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory16
    {20, 21}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory17
    {21, 22}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory18
    {22, 23}, // NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory19
    {23, 24}, // NvMConf_NvMBlockDescriptor_NvM_MC_Offset
    {24, 25}, // NvMConf_NvMBlockDescriptor_NvM_DEM_ExternFF
    {25, 26}, // NvMConf_NvMBlockDescriptor_DEM_HistoryEventList
    {26, 27}, // NvMConf_NvMBlockDescriptor_NvM_TLC_Trq
    {27, 28}, // NvMConf_NvMBlockDescriptor_NvM_EEP_Study
    {28, 29}, // NvMConf_NvMBlockDescriptor_rba_MemDiag_StrdErr_Blk
    {29, 30}, // NvMConf_NvMBlockDescriptor_BSW_NVM_SLFnh
    {30, 31}, // NvMConf_NvMBlockDescriptor_BSW_NVM_AimOutP
    {31, 32}, // NvMConf_NvMBlockDescriptor_EPC_NVMPosAimUpLimt
    {32, 33}, // NvMConf_NvMBlockDescriptor_EPC_flgSLWD
    {33, 34}, // NvMConf_NvMBlockDescriptor_NvM_UDS_VIN
    {34, 35}, // NvMConf_NvMBlockDescriptor_BSW_NVM_OffSet
    {35, 36}, // NvMConf_NvMBlockDescriptor_NvM_UDS_ECUPN_V0
    {36, 37}, // NvMConf_NvMBlockDescriptor_NvM_UDS_ECUPN_V4
    {37, 38}, // NvMConf_NvMBlockDescriptor_NvM_UDS_ECUPN_V5
    {38, 39}, // NvMConf_NvMBlockDescriptor_NvM_SWReset_Env
    {39, 40}, // NvMConf_NvMBlockDescriptor_NvM_Reset_Info
    {41675, 42}, // NvMConf_NvMBlockDescriptor_NvM_NativeBlock_2
    {45890, 43}, // NvMConf_NvMBlockDescriptor_NvM_NativeBlock_3
    {62203, 41}, // NvMConf_NvMBlockDescriptor_ECUM_CFG_NVM_BLOCK
};

// TRACE[NVM028_Conf]
// Structure containing common configuration options
const NvM_Prv_Common_tst NvM_Prv_Common_cst = {NULL_PTR, NULL_PTR, NULL_PTR};

// TRACE[NVM061_Conf]
// Array containing block descriptors
// TRACE[NVM140]
// The block descriptor contents are completely determined by configuration
const NvM_Prv_BlockDescriptor_tst NvM_Prv_BlockDescriptors_acst[NVM_CFG_NR_BLOCKS] =
{
    {
        // Block descriptor of NVRAM block NvM_MultiBlock (NvM block ID: 0):
        0, // MemIf block ID (this block is not stored on any memory device)
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[0]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[0]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        0 // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_ConfigId (NvM block ID: 1):
        0, // MemIf block ID (this block is not stored on any memory device)
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[1]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[1]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        0 // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_GenericNvData (NvM block ID: 2, persistent ID: 1):
        FeeConf_FeeBlockConfiguration_Dem_GenericNvData, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[2]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[2]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_GenericNVDataReadRamBlockFromNvCallback, // Explicit sync read callback
        &Dem_GenericNVDataWriteRamBlockToNvCallback, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_AllEventsStatusByte (NvM block ID: 3, persistent ID: 2):
        FeeConf_FeeBlockConfiguration_Dem_AllEventsStatusByte, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[3]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[3]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EventStatusByteReadRamBlockFromNvCallback, // Explicit sync read callback
        &Dem_EventStatusByteWriteRamBlockToNvCallback, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory0 (NvM block ID: 4, persistent ID: 3):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory0, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[4]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[4]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback0, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback0, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory1 (NvM block ID: 5, persistent ID: 4):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory1, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[5]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[5]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback1, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback1, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory2 (NvM block ID: 6, persistent ID: 5):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory2, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[6]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[6]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback2, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback2, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory3 (NvM block ID: 7, persistent ID: 6):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory3, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[7]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[7]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback3, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback3, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory4 (NvM block ID: 8, persistent ID: 7):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory4, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[8]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[8]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback4, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback4, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory5 (NvM block ID: 9, persistent ID: 8):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory5, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[9]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[9]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback5, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback5, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory6 (NvM block ID: 10, persistent ID: 9):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory6, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[10]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[10]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback6, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback6, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory7 (NvM block ID: 11, persistent ID: 10):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory7, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[11]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[11]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback7, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback7, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory8 (NvM block ID: 12, persistent ID: 11):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory8, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[12]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[12]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback8, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback8, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory9 (NvM block ID: 13, persistent ID: 12):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory9, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[13]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[13]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback9, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback9, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory10 (NvM block ID: 14, persistent ID: 13):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory10, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[14]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[14]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback10, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback10, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory11 (NvM block ID: 15, persistent ID: 14):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory11, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[15]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[15]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback11, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback11, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory12 (NvM block ID: 16, persistent ID: 15):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory12, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[16]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[16]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback12, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback12, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory13 (NvM block ID: 17, persistent ID: 16):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory13, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[17]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[17]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback13, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback13, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory14 (NvM block ID: 18, persistent ID: 17):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory14, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[18]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[18]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback14, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback14, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory15 (NvM block ID: 19, persistent ID: 18):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory15, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[19]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[19]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback15, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback15, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory16 (NvM block ID: 20, persistent ID: 19):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory16, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[20]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[20]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback16, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback16, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory17 (NvM block ID: 21, persistent ID: 20):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory17, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[21]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[21]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback17, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback17, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory18 (NvM block ID: 22, persistent ID: 21):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory18, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[22]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[22]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback18, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback18, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block Dem_EvMemEventMemory19 (NvM block ID: 23, persistent ID: 22):
        FeeConf_FeeBlockConfiguration_Dem_EvMemEventMemory19, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[23]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[23]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback19, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback19, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM | NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL | NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW | NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_MC_Offset (NvM block ID: 24, persistent ID: 23):
        FeeConf_FeeBlockConfiguration_NvM_MC_Offset, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[24]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[24]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_DEM_ExternFF (NvM block ID: 25, persistent ID: 24):
        FeeConf_FeeBlockConfiguration_NvM_DEM_ExternFF, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[25]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[25]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block DEM_HistoryEventList (NvM block ID: 26, persistent ID: 25):
        FeeConf_FeeBlockConfiguration_DEM_HistoryEventList, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[26]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[26]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_TLC_Trq (NvM block ID: 27, persistent ID: 26):
        FeeConf_FeeBlockConfiguration_NvM_TLC_Trq, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[27]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[27]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_EEP_Study (NvM block ID: 28, persistent ID: 27):
        FeeConf_FeeBlockConfiguration_NvM_EEP_Study, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[28]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[28]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block rba_MemDiag_StrdErr_Blk (NvM block ID: 29, persistent ID: 28):
        FeeConf_FeeBlockConfiguration_rba_MemDiag_StrdErr_Blk, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[29]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[29]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block BSW_NVM_SLFnh (NvM block ID: 30, persistent ID: 29):
        FeeConf_FeeBlockConfiguration_BSW_NVM_SLFnh, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[30]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[30]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block BSW_NVM_AimOutP (NvM block ID: 31, persistent ID: 30):
        FeeConf_FeeBlockConfiguration_BSW_NVM_AimOutP, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[31]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[31]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block EPC_NVMPosAimUpLimt (NvM block ID: 32, persistent ID: 31):
        FeeConf_FeeBlockConfiguration_EPC_NVMPosAimUpLimt, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[32]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[32]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block EPC_flgSLWD (NvM block ID: 33, persistent ID: 32):
        FeeConf_FeeBlockConfiguration_EPC_flgSLWD, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[33]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[33]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_UDS_VIN (NvM block ID: 34, persistent ID: 33):
        FeeConf_FeeBlockConfiguration_NvM_UDS_VIN, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[34]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[34]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        0 // Block flags
    },
    {
        // Block descriptor of NVRAM block BSW_NVM_OffSet (NvM block ID: 35, persistent ID: 34):
        FeeConf_FeeBlockConfiguration_BSW_NVM_OffSet, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[35]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[35]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_UDS_ECUPN_V0 (NvM block ID: 36, persistent ID: 35):
        FeeConf_FeeBlockConfiguration_NvM_UDS_ECUPN_V0, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[36]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[36]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        0 // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_UDS_ECUPN_V4 (NvM block ID: 37, persistent ID: 36):
        FeeConf_FeeBlockConfiguration_NvM_UDS_ECUPN_V4, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[37]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[37]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        0 // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_UDS_ECUPN_V5 (NvM block ID: 38, persistent ID: 37):
        FeeConf_FeeBlockConfiguration_NvM_UDS_ECUPN_V5, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[38]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[38]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        0 // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_SWReset_Env (NvM block ID: 39, persistent ID: 38):
        FeeConf_FeeBlockConfiguration_NvM_SWReset_Env, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[39]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[39]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_Reset_Info (NvM block ID: 40, persistent ID: 39):
        FeeConf_FeeBlockConfiguration_NvM_Reset_Info, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[40]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[40]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block ECUM_CFG_NVM_BLOCK (NvM block ID: 41, persistent ID: 62203):
        FeeConf_FeeBlockConfiguration_ECUM_CFG_NVM_BLOCK, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[41]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[41]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        &EcuM_Rb_NvMSingleBlockCallbackFunction, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_NativeBlock_2 (NvM block ID: 42, persistent ID: 41675):
        FeeConf_FeeBlockConfiguration_NvM_NativeBlock_2, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[42]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[42]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
    {
        // Block descriptor of NVRAM block NvM_NativeBlock_3 (NvM block ID: 43, persistent ID: 45890):
        FeeConf_FeeBlockConfiguration_NvM_NativeBlock_3, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[43]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        (void * const *) &(NvM_Prv_RamBlockAdr_acpv[43]), // RAM block data address calculated on compile time
        (const void *) NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL | NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL // Block flags
    },
};

// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3028]
// Runtime Calculation feature disabled
#if (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_OFF)
// Used to calculate the NV block lengths on compile time
// This variable is mapped into the block descriptor NvM_Prv_BlockDescriptors_acst
const uint16 NvM_Prv_BlockLengths_acu16[NVM_CFG_NR_BLOCKS] =
{
    // Block length of NVRAM block NvM_MultiBlock (NvM block ID: 0)
    1,
    // Block length of NVRAM block NvM_ConfigId (NvM block ID: 1)
    2,
    // Block length of NVRAM block Dem_GenericNvData (NvM block ID: 2)
    16,
    // Block length of NVRAM block Dem_AllEventsStatusByte (NvM block ID: 3)
    128,
    // Block length of NVRAM block Dem_EvMemEventMemory0 (NvM block ID: 4)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory1 (NvM block ID: 5)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory2 (NvM block ID: 6)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory3 (NvM block ID: 7)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory4 (NvM block ID: 8)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory5 (NvM block ID: 9)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory6 (NvM block ID: 10)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory7 (NvM block ID: 11)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory8 (NvM block ID: 12)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory9 (NvM block ID: 13)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory10 (NvM block ID: 14)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory11 (NvM block ID: 15)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory12 (NvM block ID: 16)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory13 (NvM block ID: 17)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory14 (NvM block ID: 18)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory15 (NvM block ID: 19)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory16 (NvM block ID: 20)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory17 (NvM block ID: 21)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory18 (NvM block ID: 22)
    40,
    // Block length of NVRAM block Dem_EvMemEventMemory19 (NvM block ID: 23)
    40,
    // Block length of NVRAM block NvM_MC_Offset (NvM block ID: 24)
    4,
    // Block length of NVRAM block NvM_DEM_ExternFF (NvM block ID: 25)
    64,
    // Block length of NVRAM block DEM_HistoryEventList (NvM block ID: 26)
    24,
    // Block length of NVRAM block NvM_TLC_Trq (NvM block ID: 27)
    6,
    // Block length of NVRAM block NvM_EEP_Study (NvM block ID: 28)
    8,
    // Block length of NVRAM block rba_MemDiag_StrdErr_Blk (NvM block ID: 29)
    8,
    // Block length of NVRAM block BSW_NVM_SLFnh (NvM block ID: 30)
    1,
    // Block length of NVRAM block BSW_NVM_AimOutP (NvM block ID: 31)
    8,
    // Block length of NVRAM block EPC_NVMPosAimUpLimt (NvM block ID: 32)
    8,
    // Block length of NVRAM block EPC_flgSLWD (NvM block ID: 33)
    8,
    // Block length of NVRAM block NvM_UDS_VIN (NvM block ID: 34)
    17,
    // Block length of NVRAM block BSW_NVM_OffSet (NvM block ID: 35)
    1,
    // Block length of NVRAM block NvM_UDS_ECUPN_V0 (NvM block ID: 36)
    4,
    // Block length of NVRAM block NvM_UDS_ECUPN_V4 (NvM block ID: 37)
    1,
    // Block length of NVRAM block NvM_UDS_ECUPN_V5 (NvM block ID: 38)
    1,
    // Block length of NVRAM block NvM_SWReset_Env (NvM block ID: 39)
    36,
    // Block length of NVRAM block NvM_Reset_Info (NvM block ID: 40)
    128,
    // Block length of NVRAM block ECUM_CFG_NVM_BLOCK (NvM block ID: 41)
    8,
    // Block length of NVRAM block NvM_NativeBlock_2 (NvM block ID: 42)
    1024,
    // Block length of NVRAM block NvM_NativeBlock_3 (NvM block ID: 43)
    1024,
};
// Used to calculate the RAM block data addresses on compile runtime
// This variable is mapped into the block descriptor NvM_Prv_BlockDescriptors_acst
void * const NvM_Prv_RamBlockAdr_acpv[NVM_CFG_NR_BLOCKS] =
{
    // Permanent RAM address of NVRAM block NvM_MultiBlock (NvM block ID: 0)
    (void *) NULL_PTR,
    // Permanent RAM address of NVRAM block NvM_ConfigId (NvM block ID: 1)
    (void *) NULL_PTR,
    // Permanent RAM address of NVRAM block Dem_GenericNvData (NvM block ID: 2)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_AllEventsStatusByte (NvM block ID: 3)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory0 (NvM block ID: 4)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory1 (NvM block ID: 5)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory2 (NvM block ID: 6)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory3 (NvM block ID: 7)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory4 (NvM block ID: 8)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory5 (NvM block ID: 9)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory6 (NvM block ID: 10)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory7 (NvM block ID: 11)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory8 (NvM block ID: 12)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory9 (NvM block ID: 13)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory10 (NvM block ID: 14)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory11 (NvM block ID: 15)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory12 (NvM block ID: 16)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory13 (NvM block ID: 17)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory14 (NvM block ID: 18)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory15 (NvM block ID: 19)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory16 (NvM block ID: 20)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory17 (NvM block ID: 21)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory18 (NvM block ID: 22)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block Dem_EvMemEventMemory19 (NvM block ID: 23)
    (void *) NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NvM_MC_Offset (NvM block ID: 24)
    (void *) &(NvM_MC_OffSet),
    // Permanent RAM address of NVRAM block NvM_DEM_ExternFF (NvM block ID: 25)
    (void *) &(errOderTable),
    // Permanent RAM address of NVRAM block DEM_HistoryEventList (NvM block ID: 26)
    (void *) &(VAR_DEM_DiagEvtHistList_au8),
    // Permanent RAM address of NVRAM block NvM_TLC_Trq (NvM block ID: 27)
    (void *) &(VAR_NvM_TLC_TrqReason_au8),
    // Permanent RAM address of NVRAM block NvM_EEP_Study (NvM block ID: 28)
    (void *) &(VAR_NvM_EEP_Study_au8),
    // Permanent RAM address of NVRAM block rba_MemDiag_StrdErr_Blk (NvM block ID: 29)
    (void *) &(rba_MemDiag_StrdErr),
    // Permanent RAM address of NVRAM block BSW_NVM_SLFnh (NvM block ID: 30)
    (void *) &(VAR_NvM_BSW_NVM_SLFnh_au8),
    // Permanent RAM address of NVRAM block BSW_NVM_AimOutP (NvM block ID: 31)
    (void *) &(VAR_NvM_BSW_NVM_AimOutP_au8),
    // Permanent RAM address of NVRAM block EPC_NVMPosAimUpLimt (NvM block ID: 32)
    (void *) &(VAR_NvM_EPC_NVMPosAimUpLimt_au8),
    // Permanent RAM address of NVRAM block EPC_flgSLWD (NvM block ID: 33)
    (void *) &(VAR_NvM_EPC_flgSLWD_au8),
    // Permanent RAM address of NVRAM block NvM_UDS_VIN (NvM block ID: 34)
    (void *) &(VAR_NvM_UDS_VIN),
    // Permanent RAM address of NVRAM block BSW_NVM_OffSet (NvM block ID: 35)
    (void *) &(VAR_BSW_NVM_OffSet),
    // Permanent RAM address of NVRAM block NvM_UDS_ECUPN_V0 (NvM block ID: 36)
    (void *) &(VAR_NvM_UDS_ECUPN_V0),
    // Permanent RAM address of NVRAM block NvM_UDS_ECUPN_V4 (NvM block ID: 37)
    (void *) &(VAR_NvM_UDS_ECUPN_V4),
    // Permanent RAM address of NVRAM block NvM_UDS_ECUPN_V5 (NvM block ID: 38)
    (void *) &(VAR_NvM_UDS_ECUPN_V5),
    // Permanent RAM address of NVRAM block NvM_SWReset_Env (NvM block ID: 39)
    (void *) &(rba_Reset_Env_History),
    // Permanent RAM address of NVRAM block NvM_Reset_Info (NvM block ID: 40)
    (void *) &(Reset_List_History),
    // Permanent RAM address of NVRAM block ECUM_CFG_NVM_BLOCK (NvM block ID: 41)
    (void *) &(EcuM_Rb_dataShutdownInfo_st),
    // Permanent RAM address of NVRAM block NvM_NativeBlock_2 (NvM block ID: 42)
    (void *) &(Rte_CPim_NvM_SWC_NvM_SWC_BlockNative_1024),
    // Permanent RAM address of NVRAM block NvM_NativeBlock_3 (NvM block ID: 43)
    (void *) &(Rte_CPim_NvM_SWC_NvM_SWC_BlockRedundant_1024),
};
#endif

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3028]
// Runtime Calculation feature enabled
#if (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON)
# define NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
# include "NvM_MemMap.h"
// Used to calculate the NV block lengths and RAM block data addresses on runtime
// These variables are mapped into the block descriptor NvM_Prv_BlockDescriptors_acst
uint16 NvM_Prv_BlockLengths_au16[NVM_CFG_NR_BLOCKS];
void *NvM_Prv_RamBlockAdr_apv[NVM_CFG_NR_BLOCKS];
# define NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# include "NvM_MemMap.h"
#endif

/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
#if (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON)
# define NvM_START_SEC_CODE
# include "NvM_MemMap.h"
/********************************************************************************************
 * Initialization of NV block length and RAM block data address (permanent RAM address)     *
 *                                                                                          *
 * In this case NvMRbRuntimeRamBlockConfiguration is enabled                                *
 * + NV block length is defined either by NvMRbNvBlockLengthString or NvMNvBlockLength      *
 * + RAM block data address is still defined by NvMRamBlockDataAddress but now              *
 *   NvMRamBlockDataAddress can also contain C expressions                                  *
 *                                                                                          *
 * Furthermore if explicit sync feature is enabled the explicit sync buffer is defined here *
 * by setting the start address and calculating the buffer size                             *
 * Start address and end address is defined by user in common options with the parameters   *
 * + NvMRbRuntimeRamBufferAddressStart                                                      *
 * + NvMRbRuntimeRamBufferAddressEnd                                                        *
 *                                                                                          *
 * ******************************************************************************************
*/
// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3028]
// Runtime Calculation feature enabled
void NvM_Prv_InitRuntimeRamBlockProperties(void)
{
#if (NVM_PRV_HAS_RAM_MIRROR == STD_ON)
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3029] Calculate explicit synchronization RAM buffer
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3030] Calculate explicit synchronization RAM buffer
    // Set explicit synchronization RAM buffer start address
    NvM_Prv_RamMirror_au8        = (uint8 *) (0);
    // Calculate explicit synchronization RAM buffer size
    NvM_Prv_RntRamMirrorSize_u32 = (uint32) (0) - (uint32) (0);
#endif


}
# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h"
#endif
