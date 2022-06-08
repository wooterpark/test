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
 * $Filename__:rba_Reset_Prv.h$
 *
 * $Author____:KUK1COB$
 *
 * $Function__:.$
 *
 ***********************************************************************************************************************
 * $Domain____:SDOM$
 * $User______:PHB1FE$
 * $Date______:25.01.2018$
 * $Class_____:SWHDR$
 * $Name______:rba_Reset_Prv$
 * $Variant___:1.32.0$
 * $Revision__:2$
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
 *              header file for reset modul
 *
 * \scope           API
 *********************************************************************************************************************
 */
#ifndef RBA_RESET_PRV_H
#define RBA_RESET_PRV_H

#include "rba_Reset_CB.h"
#include "Mcu.h"
#include "rba_BswSrv.h"


/* defines */

/* Pattern for marker which indicate after watchdog trap the system should be shut off */
#define RBA_RESET_WDT_SHUTOFF     0xED78u

/* pattern for PORST detection */
#define RBA_RESET_PORSTPATTERN  0xABCD1234uL

/* mask for reset config table */
#define RBA_RESET_CONFTABLE_MSK 0xF000uL

/* mask for reset conf id */
#define RBA_RESET_CONFID_MSK    0x0FFFuL

/* macro for configuration access */
#define RBA_RESET_GETCONFIG(conf, table, index) (*((const uint8*)(*((conf)+(table)))+(index)))

/* macro for simple complement */
#define RBA_RESET_STORE_COMPL(word) (~(word))


/* enumerators */
/* enumerator for history buffer handling via application (clearing from history buffer) */
typedef enum
{
    RBA_RESET_HISTBUF_IDLE,
    RBA_RESET_HISTBUF_INIT,
    RBA_RESET_HISTBUF_INITPOLL
}rba_Reset_StateHistBufProc_ten;


/* typedef structs */
/* typedef for extended reset history buffer */
typedef struct
{
    uint32 TiBuffer_u32[RBA_RESET_HISTBUF_SIZE];                                           /* buffer for timestamps */
    uint16 IdBuffer_u16[RBA_RESET_HISTBUF_SIZE];                                            /* buffer for reset ids */
    uint8  Index_u8;                                                                     /* index to the next entry */
    uint32 Addr_u32[RBA_RESET_HISTBUF_SIZE];     /* buffer for addresses. must be last element, because in older SB */
                                                 /* this element is not part of struct                              */
}rba_Reset_ExtHist_tst;


/* extern declarations of variables */
/* pointer to ASW configuration */
extern const rba_Reset_Conf_tst **rba_Reset_CurConf_ppcst;

/* variable for reset history buffer handling */
extern uint32  rba_Reset_PORSTDetected_u32;


extern volatile uint32 rba_Reset_ResetLock_u32;


/* table of different loopconditions */
#define RBA_RESET_START_SEC_CONST_UNSPECIFIED
#include "rba_Reset_MemMap.h"
extern const rba_Reset_LoopCond_tst rba_Reset_LoopCondTable_cst[];
#define RBA_RESET_STOP_SEC_CONST_UNSPECIFIED
#include "rba_Reset_MemMap.h"



/**
 *********************************************************************************************************************
 * rba_Reset_GetResetLock - lock mechanism for rba_Reset. Only one core should trigger the reset
 *                          IFX only: self nesting on same core is required for correct reset via NMI-
 *                          This function will set the rba_Reset corresponding spinlock.
 * \param           none
 * \return          none
 * \seealso
 * \usedresources
 *********************************************************************************************************************
 */
LOCAL_INLINE void rba_Reset_GetResetLock(void)
{
#if (MCU_RB_MACHINE_FAM == MCU_RB_IFX_UC1)
    rba_BswSrv_uint64 CmpSwap_u64;
    uint32            RequestedLock_u32;

    /* suspend all interrupts unconditionally */
#  ifdef __TASKING__
    __disable();
#  else
    asm volatile ("disable":::"memory");
#  endif
    /* try to set lock for current core: Only the first swap instruction receives 0 */
    RequestedLock_u32 = rba_BswSrv_GetPhysCore() + 1uL; /* requested lock value must not be 0 */

    /* The CMPSWAP.W instruction conditionally swaps the data register D[a] and the contents of the memory word.
       If the contents of the memory word is equal to the contents of register D[a+1] then swap the contents of the memory
       word with the register D[a]. Register D[a] is unconditionally updated with the contents of the memory word.
       Register D[a] is stored in the lower 32 bit of the 64bit parameter. */
    CmpSwap_u64 = RequestedLock_u32;
    #ifdef __TASKING__
    __asm volatile("cmpswap.w [%1]0,%0 " : "=e"(CmpSwap_u64) : "a"(&rba_Reset_ResetLock_u32), "0"(CmpSwap_u64): "memory");
    #else
    asm volatile("  cmpswap.w [%1]0,%A0" : "+d"(CmpSwap_u64) : "a"(&rba_Reset_ResetLock_u32): "memory");
    #endif

    /* only the core on which the first call was executed returns. The other cores go into a endless loop until reset */
    if(((uint32)CmpSwap_u64 != 0uL) &&             /* lock was active before and */
       ((uint32)CmpSwap_u64 != RequestedLock_u32)) /* lock was not active for current core. */
    {
        while(1)
        {
            ;
        }
    }


#endif

}

/**
 *********************************************************************************************************************
 * rba_Reset_ClrResetLock - lock mechanism for rba_Reset. Only one core should trigger the reset
 *                          This function will reset the rba_Reset corresponding spinlock.
 * \param           none
 * \return          none
 * \seealso
 * \usedresources
 *********************************************************************************************************************
 */
LOCAL_INLINE void rba_Reset_ClrResetLock(void)
{
    /* clear spinlock variable, only to be sure that the variable is cleared in the next driving cycle */
    /* will normally also be cleared in SB                                                             */
    rba_BswSrv_SyncWrite32(&rba_Reset_ResetLock_u32, 0);
}

#   endif         /* header secure */

/*<RBHead>
 ***********************************************************************************************************************

 * 
 * 1.23.0; 2     12.10.2015 WIP2FE
 *   -
 * 
 * $
 *
 ***********************************************************************************************************************
</RBHead>*/
