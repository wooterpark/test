/*<RBHead>
 *************************************************************************
 *                                                                       *
 *                      ROBERT BOSCH GMBH                                *
 *                          STUTTGART                                    *
 *                                                                       *
 *          Alle Rechte vorbehalten - All rights reserved                *
 *                                                                       *
 *************************************************************************

 *************************************************************************
 *    Administrative Information (automatically filled in by eASEE)      *
 *************************************************************************
 *
 * $Filename__:$
 *
 * $Author____:$
 *
 * $Function__:$
 *
 *************************************************************************
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
 *************************************************************************
 *
 * $UniqueName:$
 * $Component_:$
 *
 *
 *************************************************************************
 * List Of Changes
 *
 * $History$
 *
 *************************************************************************
 </RBHead>*/

#ifndef RBA_MEMDIAG_PRIV_H_
#define RBA_MEMDIAG_PRIV_H_

#include "rba_MemDiag.h"
#include "rba_MemDiag_dat.h"

#define RBA_MEMDIAG_STERR_WRERR_BP          (0u)
#define RBA_MEMDIAG_STERR_READERR_BP        (1u)
#define RBA_MEMDIAG_STERR_READSNGERR_BP     (2u)

typedef struct
{
    uint16 nrLstWrErr;
    uint16 nrLstReadErr;
    uint16 nrLstReadSngErr;
    uint8 stErr;
} rba_MemDiag_StrdErr_t;


#define RBA_MEMDIAG_START_SEC_VAR_RESET_SAFE_BOOLEAN
#include "rba_MemDiag_MemMap.h"

extern boolean rba_MemDiag_flgSetReadErr; /* Set read error by cyclic process */
extern boolean rba_MemDiag_flgRstReadErr; /* Reset read error by cyclic process */
extern boolean rba_MemDiag_flgSetWrErr; /* Set write error by cyclic process */
extern boolean rba_MemDiag_flgRstWrErr; /* Reset write error by cyclic process */

/* Flags for extended memory diagnosis */
extern boolean rba_MemDiagExtd_flgSetReadSngErr; /* Set read error for single storage blocks by cyclic process */
extern boolean rba_MemDiagExtd_flgRstReadSngErr; /* Reset read error for single storage blocks by cyclic process */

#define RBA_MEMDIAG_STOP_SEC_VAR_RESET_SAFE_BOOLEAN
#include "rba_MemDiag_MemMap.h"


#define RBA_MEMDIAG_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "rba_MemDiag_MemMap.h"

extern rba_MemDiag_StrdErr_t rba_MemDiag_StrdErr;

#define RBA_MEMDIAG_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "rba_MemDiag_MemMap.h"

#endif /* RBA_MEMDIAG_PRIV_H_ */
