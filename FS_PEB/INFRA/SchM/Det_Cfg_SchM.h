

#ifndef DET_CFG_SCHM_H
#define DET_CFG_SCHM_H

#include "SchM_Default.h"


/* This lock is always required, as the component using the DET are usually runing in different tasks as DET and
 * therefore may interrupt the processing of DET at any time.
 */
#define SchM_Enter_Det_Monitoring()      do { SCHM_ENTER_DEFAULT(); } while (0)
#define SchM_Exit_Det_Monitoring()		do { SCHM_EXIT_DEFAULT(); } while (0)



#endif /* include protection */
