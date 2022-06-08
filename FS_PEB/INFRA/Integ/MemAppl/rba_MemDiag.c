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



#include "rba_MemDiag_Prv.h"


#define RBA_MEMDIAG_START_SEC_VAR_RESET_SAFE_BOOLEAN
#include "rba_MemDiag_MemMap.h"

boolean rba_MemDiag_flgSetReadErr; /* Set read error by cyclic process */
boolean rba_MemDiag_flgRstReadErr; /* Reset read error by cyclic process */
boolean rba_MemDiag_flgSetWrErr; /* Set write error by cyclic process */
boolean rba_MemDiag_flgRstWrErr; /* Reset write error by cyclic process */

uint16 rba_MemDiagExtd_nrLstReadSngErr;

uint16 rba_MemDiag_nrLstReadErr;

uint16 rba_MemDiag_nrLstWrErr;


boolean rba_MemDiag_flgInhbDiag;

/* Flags for extended memory diagnosis */
boolean rba_MemDiagExtd_flgSetReadSngErr; /* Set read error for single storage blocks by cyclic process */
boolean rba_MemDiagExtd_flgRstReadSngErr; /* Reset read error for single storage blocks by cyclic process */

#define RBA_MEMDIAG_STOP_SEC_VAR_RESET_SAFE_BOOLEAN
#include "rba_MemDiag_MemMap.h"


#define RBA_MEMDIAG_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "rba_MemDiag_MemMap.h"

rba_MemDiag_StrdErr_t rba_MemDiag_StrdErr;

#define RBA_MEMDIAG_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "rba_MemDiag_MemMap.h"
