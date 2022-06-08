/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#include "Fee.h"
#include "Fee_Prv.h"



/* Properties of flash sectors */
#define FEE_START_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"
CONST (Fee_FlashProp_tst, FEE_CONST) Fee_FlashProp_st[FEE_NUM_FLASH_BANKS_AVAILABLE] = {
	{ FEE_PHYS_SEC_START0, FEE_PHYS_SEC_END0, FEE_LOG_SEC_START0, FEE_LOG_SEC_END0 }, /* sector 0 */
	{ FEE_PHYS_SEC_START1, FEE_PHYS_SEC_END1, FEE_LOG_SEC_START1, FEE_LOG_SEC_END1 }, /* sector 1 */
};
#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"

/* Linked functions of the Fee */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
CONST (Fee_LinkedFunctions_tst, FEE_CONST) Fee_LinkedFunctions_cst = 
{
    NULL_PTR
};
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/* Block properties for all Fee blocks
 *
 * Status Flags:
 * Block flags will help to specify a more detailed block configuration. The low Byte of these block flags is also stored
 * in the flash (status byte inside the block header). This information (in Flash) can be used to read/write the layout
 * without configuration (PAV, CB).
 *
 *
 *                                                 |<----- Block Status Byte in Block Header ----->|
 * |<---------------------------------------- Block Flags ---------------------------------------->|
 *    F     E     D     C     B     A     9     8  |  7     6     5     4     3     2     1     0  |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |     |     |Prio-| Job type  |Ign. |No F.| Rob |Surv.|(Inv)| DataFilter| Sec-|
 * |     |     |     |     |     |rity |           |Blk  |back |Attr.|Attr.|     |    Type   | lvl |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 *
 *
 *  0  ... SecurityLevel      => 0...SingleStorage, 1...DoubleStorage
 * 1+2 ... Data Filter Type   => 0...Dynamic:         Anybody can erase this block (e.g. during migration)
 *                               1...Static:          Only certain users (e.g. repair shops) can erase this block
 *                               2...Permanent:       Only very certain users (e.g. OEM) can erase this block
 *                               3...Super Permanent: Block can never be erased
 *  3  ... Invalid            => 0...Block OK, 1...Block is invalid  --> can be changed by function Fee_InvalidateBlock
 *  4  ... Survival Attribute => 0...No survival, 1... Survival (even without being part of the layout)
 *  5  ... Robustness Attribute (Robustness against data modification during write execution)
 *                            => 0...Deactivated:     No additional checksum is used
 *                            => 1...Activated:       Additional checksum is used
 *  6  ... NoFallback         => 0...Deactivated:     A fallback to old copies is allowed
 *                            => 1...Activated:       A fallback to old copies is not allowed
 *  7  ... Ignore Block       => 0...Deactivated:     Block is considered
 *                            => 1...Activated:       Block is ignored
 * 8+9 ... TypeOfBlock        => 0...InternalJob, 1...NvmJob, 2...AdapterJob (e.g. Mx17 Eep adapter)
 *  A  ... Priority           => Job priority:        0...FEE_NORMAL_PRIO_E --> FeeImmediateData = No
 *                                                    1...FEE_HIGH_PRIO_E   --> FeeImmediateData = Yes
 */
#ifdef FEE_PRV_USE_ROM_TABLE
#define FEE_START_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"
const Fee_BlockPropertiesType_tst Fee_BlockProperties_st[FEE_NUM_BLOCKS] = {
#else
#define FEE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"
Fee_BlockPropertiesType_tst Fee_BlockProperties_st[FEE_NUM_BLOCKS] = {
#endif

	         /* FeeRbBlockPersistentId,  StatusFlags,  BlkLength ,  FeeRbCallbackEnd    ,  FeeRbCallbackError  */
	 /*   0 */{         0x0001         ,   0x0100   ,   0x0010   ,NULL_PTR              ,NULL_PTR               } /* Dem_GenericNvData                        */,
	 /*   1 */{         0x0002         ,   0x0100   ,   0x0080   ,NULL_PTR              ,NULL_PTR               } /* Dem_AllEventsStatusByte                  */,
	 /*   2 */{         0x0003         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory0                    */,
	 /*   3 */{         0x0004         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory1                    */,
	 /*   4 */{         0x0005         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory2                    */,
	 /*   5 */{         0x0006         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory3                    */,
	 /*   6 */{         0x0007         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory4                    */,
	 /*   7 */{         0x0008         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory5                    */,
	 /*   8 */{         0x0009         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory6                    */,
	 /*   9 */{         0x000A         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory7                    */,
	 /*  10 */{         0x000B         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory8                    */,
	 /*  11 */{         0x000C         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory9                    */,
	 /*  12 */{         0x000D         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory10                   */,
	 /*  13 */{         0x000E         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory11                   */,
	 /*  14 */{         0x000F         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory12                   */,
	 /*  15 */{         0x0010         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory13                   */,
	 /*  16 */{         0x0011         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory14                   */,
	 /*  17 */{         0x0012         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory15                   */,
	 /*  18 */{         0x0013         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory16                   */,
	 /*  19 */{         0x0014         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory17                   */,
	 /*  20 */{         0x0015         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory18                   */,
	 /*  21 */{         0x0016         ,   0x0100   ,   0x0028   ,NULL_PTR              ,NULL_PTR               } /* Dem_EvMemEventMemory19                   */,
	 /*  22 */{         0x0017         ,   0x0100   ,   0x0004   ,NULL_PTR              ,NULL_PTR               } /* NvM_MC_Offset                            */,
	 /*  23 */{         0x0018         ,   0x0100   ,   0x0040   ,NULL_PTR              ,NULL_PTR               } /* NvM_DEM_ExternFF                         */,
	 /*  24 */{         0x0019         ,   0x0100   ,   0x0018   ,NULL_PTR              ,NULL_PTR               } /* DEM_HistoryEventList                     */,
	 /*  25 */{         0x001A         ,   0x0100   ,   0x0006   ,NULL_PTR              ,NULL_PTR               } /* NvM_TLC_Trq                              */,
	 /*  26 */{         0x001B         ,   0x0100   ,   0x0008   ,NULL_PTR              ,NULL_PTR               } /* NvM_EEP_Study                            */,
	 /*  27 */{         0x001C         ,   0x0100   ,   0x0008   ,NULL_PTR              ,NULL_PTR               } /* rba_MemDiag_StrdErr_Blk                  */,
	 /*  28 */{         0x001D         ,   0x0100   ,   0x0001   ,NULL_PTR              ,NULL_PTR               } /* BSW_NVM_SLFnh                            */,
	 /*  29 */{         0x001E         ,   0x0100   ,   0x0008   ,NULL_PTR              ,NULL_PTR               } /* BSW_NVM_AimOutP                          */,
	 /*  30 */{         0x001F         ,   0x0100   ,   0x0008   ,NULL_PTR              ,NULL_PTR               } /* EPC_NVMPosAimUpLimt                      */,
	 /*  31 */{         0x0020         ,   0x0100   ,   0x0008   ,NULL_PTR              ,NULL_PTR               } /* EPC_flgSLWD                              */,
	 /*  32 */{         0x0021         ,   0x0100   ,   0x0011   ,NULL_PTR              ,NULL_PTR               } /* NvM_UDS_VIN                              */,
	 /*  33 */{         0x0022         ,   0x0100   ,   0x0001   ,NULL_PTR              ,NULL_PTR               } /* BSW_NVM_OffSet                           */,
	 /*  34 */{         0x0023         ,   0x0100   ,   0x0004   ,NULL_PTR              ,NULL_PTR               } /* NvM_UDS_ECUPN_V0                         */,
	 /*  35 */{         0x0024         ,   0x0100   ,   0x0001   ,NULL_PTR              ,NULL_PTR               } /* NvM_UDS_ECUPN_V4                         */,
	 /*  36 */{         0x0025         ,   0x0100   ,   0x0001   ,NULL_PTR              ,NULL_PTR               } /* NvM_UDS_ECUPN_V5                         */,
	 /*  37 */{         0x0026         ,   0x0100   ,   0x0024   ,NULL_PTR              ,NULL_PTR               } /* NvM_SWReset_Env                          */,
	 /*  38 */{         0x0027         ,   0x0100   ,   0x0080   ,NULL_PTR              ,NULL_PTR               } /* NvM_Reset_Info                           */,
	 /*  39 */{         0xA2CB         ,   0x0100   ,   0x0400   ,NULL_PTR              ,NULL_PTR               } /* NvM_NativeBlock_2                        */,
	 /*  40 */{         0xB342         ,   0x0100   ,   0x0400   ,NULL_PTR              ,NULL_PTR               } /* NvM_NativeBlock_3                        */,
	 /*  41 */{         0xF2FB         ,   0x0100   ,   0x0008   ,NULL_PTR              ,NULL_PTR               } /* ECUM_CFG_NVM_BLOCK                       */,
};

#ifdef FEE_PRV_USE_ROM_TABLE
#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"
#else
#define FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"
#endif

 /* This section is applicable only for FEE 2.0, ignore or dont configure this section for FEE 1.0 */

