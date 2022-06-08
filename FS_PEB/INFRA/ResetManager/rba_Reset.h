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
 * $Filename__:rba_Reset.h$
 *
 * $Author____:KUK1COB$
 *
 * $Function__:.$
 *
 ***********************************************************************************************************************
 * $Domain____:SDOM$
 * $User______:PHB1FE$
 * $Date______:12.12.2017$
 * $Class_____:SWHDR$
 * $Name______:rba_Reset$
 * $Variant___:1.32.0$
 * $Revision__:0$
 * $Type______:H$
 * $State_____:AVAILABLE$
 * $Generated_:$
 ***********************************************************************************************************************
 *
 * $UniqueName:$
 * $Component_:$
 *
 ***********************************************************************************************************************
</RBHead>*/


/**
 *********************************************************************************************************************
 * \moduledescription
 *              global header file for reset functions
 *
 * \scope           API
 *********************************************************************************************************************
 */
#ifndef RBA_RESET_H
#define RBA_RESET_H

/* includes */
#include "Std_Types.h"
#include "rba_Reset_Cfg.h"
#include "Rte_Type.h"

/**/
#define RESET_INFOLIST_SIZE 16U

/* Vendor and module identification */
#define RBA_RESET_VENDOR_ID   (6)
#define RBA_RESET_MODULE_ID   (255)
#define RBA_RESET_INSTANCE_ID (0)

/* Autosar version information */
#define RBA_RESET_AR_RELEASE_MAJOR_VERSION    (4)
#define RBA_RESET_AR_RELEASE_MINOR_VERSION    (0)
#define RBA_RESET_AR_RELEASE_REVISION_VERSION (2)

/* short functional reset mode */
#define RESET_SHFCTRST_MODE             0x0uL
/* sw destructive reset mode */
#define RESET_SWDESTRST_MODE            0xABCD1234uL

/* value if loopcondition are true */
#define RESET_LOOPCOND_TRUE    0xDA

/* Defines for Safety End Init Bugfix */
#define BCTL_VERSION_13                 0x000D
#define RESET_SFTY_END_INIT_PATTERN     0xDA0000DAuL

typedef unsigned long long   uint64_reset;

/* typedefs */
/* typedef for reset structure for application */
typedef struct
{
    uint64_reset TiStampCurr_u64;                                             /* timestamp of current SoftwareReset */
    uint32 Loc_u32;                                                       /* location where the reset was triggered */
    uint32 UserValue_u32;                                            /* user defined vaule, free for individual use */
    rba_Reset_Id_ten Id_en;                                                                             /* reset id */
    rba_Reset_Grp_ten  Grp_en;                                                                    /* reset group id */
    uint8  CntrRst_u8;                                       /* count the number of reset since last power on reset */
} rba_Reset_ApplEnv_tst;

/* typedef for reset version, protected RAM initialization, safety switch off */
typedef struct
{
    rba_Reset_RAMClrAreas_ten RAMArea2Clr_en;                 /* RAM area which should be cleared. Used from MemLay */
    uint16 Version_u16;                                       /* reset version of BootCtrl */
    uint16 WDTShutOff_u16;                                    /* marker for switching off ECU within BootCtrl */
    uint16 WDTShutOffCmpl_u16;                                /* complement of WDTShutOff_u16 marker */
    uint32 EndInitSafty_Pattern_u32;                          /* Pattern to check if a reset was triggered via SMU  */
}rba_Reset_AddInfo_tst;

/* typedef for extended reset history buffer */
typedef struct
{
    rba_Reset_Id_ten    ResetId_en;                                                                     /* reset id */
    uint16              Cntr_u16;                                              /* count the number special reset id */
    uint32              Addr_u32;                                             /* location where reset was triggered */
    uint32              SwId_u32_1;                                       /* store SwID */
    uint32              SwId_u32_2;                                       /* store SwID */
}rba_Reset_ExtHistBuf_tst;

/* variables */
/* variable in PORST-RAM-area which stores the last reset causes */
/* reset history buffer */
extern rba_Reset_Id_ten rba_Reset_HistBuf_a[RBA_RESET_HISTBUF_SIZE];
/* extended reset history buffer */
extern rba_Reset_ExtHistBuf_tst rba_Reset_ExtHistBuf_ast[RBA_RESET_EXTHISTBUF_SIZE];

/* pointer to addtional reset information in FIX-RAM */
extern rba_Reset_AddInfo_tst *rba_Reset_AddInfo_pst;


#define RBA_RESET_START_SEC_VAR_CLEARED_32
#include "rba_Reset_MemMap.h"
extern rba_Reset_ApplEnv_tst rba_Reset_ApplEnv_st;             /* includes special environments of the actual reset */
#define RBA_RESET_STOP_SEC_VAR_CLEARED_32
#include "rba_Reset_MemMap.h"


/* Start MemMap for default code */
#define RBA_RESET_START_SEC_DEFAULT_CODE
#include "rba_Reset_MemMap.h"

/* prototype declaration for functions */
extern void rba_Reset_Init(void);
extern void rba_Reset_SetWdogMarker(void);
extern void rba_Reset_Monitor_Ini(void);
extern void rba_Reset_Monitor_Proc(void);
extern void rba_Reset_Monitor_Shutdown(void);
extern void rba_Reset_Request(rba_Reset_Grp_ten dResetGrp_en,
                              rba_Reset_Id_ten dResetIdentifier_en,
                              uint32 dUserDefined_u32);
extern boolean rba_Reset_SoftResetDetected(void);
extern rba_Reset_Id_ten rba_Reset_GetResetReason(void);
extern rba_Reset_DemEvent_ten rba_Reset_GetDemEvent(void);
extern uint8 rba_Reset_GetResetCounter(void);

extern void IC_NvM_WriteBlock(void);
extern void Reset_NvM_WriteResetInfoList(void);
extern void Reset_NvM_WriteTiStamp(void);


/* Start MemMap for default code */
#define RBA_RESET_STOP_SEC_DEFAULT_CODE
#include "rba_Reset_MemMap.h"
/* ***************************** */


/**
 ***********************************************************************************************************************
 * rba_Reset_ClrRAMInitInfo -
 * This function clears the information about the RAM areas which should be cleared.
 *
 *
 * \param           none
 * \return          none
 * \seealso
 * \usedresources
 ***********************************************************************************************************************
 */
LOCAL_INLINE void rba_Reset_ClrRAMInitInfo(void)
{
   if(rba_Reset_AddInfo_pst != NULL_PTR)
   {
       rba_Reset_AddInfo_pst->RAMArea2Clr_en = RBA_RESET_NOTHING;
   }
}

/**
 ***********************************************************************************************************************
 * rba_Reset_RAMInitInfo -
 * This function returns information about the reset. Due to that parts of RAM can be cleared or not.
 *
 *
 * \param           none
 * \return          rba_Reset_RAMClrAreas_ten
 *                  RBA_RESET_NOTHING:      nothing should be cleared
 *                  RBA_RESET_PORST_AREA:   PORST handling
 *                  RBA_RESET_SWR_AREA:     SWReset handling
 *                  RBA_RESET_TRAPHWR_AREA: Trap/HWReset handling
 *                  RBA_RESET_PORST_SIMU_AREA: PowerOnSimu reset handling
 * \seealso
 * \usedresources
 ***********************************************************************************************************************
 */
LOCAL_INLINE rba_Reset_RAMClrAreas_ten rba_Reset_RAMInitInfo(void)
{
    rba_Reset_RAMClrAreas_ten retVal = RBA_RESET_NOTHING;

    if(rba_Reset_AddInfo_pst != NULL_PTR)
    {
        retVal = rba_Reset_AddInfo_pst->RAMArea2Clr_en;
    }
    return(retVal);
}


/* compatibility define -> in first version of rba_Reset a special function for SoftReset was provided */
#define rba_Reset_SoftReset rba_Reset_Request


#endif

/*<RBHead>
 ***********************************************************************************************************************
 * List of changes
 *
 * $History
 * 
 * 1.32.0; 0     12.12.2017 PHB1FE
 *   -
 * 
 * 1.31.0; 0     25.10.2017 PHB1FE
 *   -
 * 
 * 1.22.0; 1     30.06.2015 WIP2FE
 *   -
 * 
 * 1.22.0; 0     24.06.2015 WIP2FE
 *   .
 * 
 * 1.21.0; 0     10.03.2015 WIP2FE
 *   -
 * 
 * 1.13.0; 0     03.02.2015 SMT6KOR
 *   Bugfix for Ifx HW errata - SMU bus error leads to reset in case of 
 *   application reset
 *   Add rba_Reset_DestroyRstConfPtr() information in fs docu
 *   Bugfix for loopcondition evaluation
 *   Execute a destructive resest in case of FCCU failures
 *   Change NvM handling in shutdown
 *   Support of reconfiguring all kind of reset ids (HW-resets, Traps, 
 *   BootCtrl-resets, ASW software resets and ASW softresets)
 *   Support of DSERAP and NOSERAP
 *   Provide new reset id RBA_RESET_OBD_SVC11_RESET_E for BootCtrl-, CB- and 
 *   ASW-usage
 *   Merge Jdp Dev1 cut1.0 sources
 * 
 * 1.11.0; 0     30.07.2014 PBR4KOR
 *   CSCRM00699499: [rba_Reset]: abort pending DFlash PFlash erase before 
 *   executing the reset
 * 
 * 1.9.0; 1     06.03.2014 PBR4KOR
 *   Transferred from BASD:
 *   COMP : rba_Reset \ AR40.2.0.0; 2 (\Comp\rba_Reset)
 * 
 * 1.9.0; 0     13.01.2014 SMT6KOR
 *   Transferred from BASD:
 *   COMP : rba_Reset \ AR40.2.0.0; 0 (\Comp\rba_Reset)
 * 
 * 1.8.0; 0     20.11.2013 MOR2ABT
 *   Transferred from BASD:
 *   COMP : rba_Reset \ AR40.1.1.0; 7 (\Comp\rba_Reset)
 * 
 * $
 *
 ***********************************************************************************************************************
</RBHead>*/
