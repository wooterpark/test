

#ifndef BSWM_CFG_SCHM_H_
#define BSWM_CFG_SCHM_H_

#include "SchM_Default.h"
#include "Os.h"
// #include "rba_BswSrv.h"

//typedef uint16 CoreIdType;

#define SchM_Enter_BswM(X) SCHM_ENTER_DEFAULT()
#define SchM_Exit_BswM(X)  SCHM_EXIT_DEFAULT()

/*#define SchM_Enter_BswM(X) RBA_BSWSRV_GET_LOCK_COMMON()
#define SchM_Exit_BswM(X)  RBA_BSWSRV_RELEASE_LOCK_COMMON()*/

#endif /* BSWM_CFG_SCHM_H_ */

/*
<BASDKey>
 **********************************************************************************************************************
 * Administrative Information (automatically filled in)
 * $History___:
 * 
 * P_AR40_14.08.0; 0     01.08.2014 LII2ABT
 *   partial check-in for the first version of MVC_D
 * 
 * $
 **********************************************************************************************************************
</BASDKey>
*/
