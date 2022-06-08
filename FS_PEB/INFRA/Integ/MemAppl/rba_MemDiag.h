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

#ifndef RBA_MEMDIAG_H_
#define RBA_MEMDIAG_H_
#include "Std_Types.h"

#define RBA_MEMDIAG_START_SEC_CODE_SLOW
#include "rba_MemDiag_MemMap.h"

extern void rba_MemDiag_Proc_Ini(void);
extern void rba_MemDiag_Proc_100ms(void);

extern void rba_MemDiag_Shutdown(void);

#define RBA_MEMDIAG_STOP_SEC_CODE_SLOW
#include "rba_MemDiag_MemMap.h"

#endif /* RBA_MEMDIAG_H_ */
