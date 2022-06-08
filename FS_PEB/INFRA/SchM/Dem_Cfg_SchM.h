


#ifndef DEM_CFG_SCHM_H
#define DEM_CFG_SCHM_H

#include "SchM_Default.h"

/**
 * \file
 * \ingroup DEM_PRJ_TPL
 * \brief Exclusive area handling for Dem
 *
 * Defines macros to lock critical regions in Dem. They can be adapted to avoid the overhead of locking in deployments
 * where that is not necessary (e.g. if Dem and Dcm are running in the same task, the lock between them can be avoided).
 */


/* This lock is always required, as the monitorings are usually runing in different tasks as DEM and
 * therefore may interrupt the processing of DEM at any time.
 */
#define SchM_Enter_Dem_Monitoring()		do { SCHM_ENTER_DEFAULT(); } while (0)
#define SchM_Exit_Dem_Monitoring()		do { SCHM_EXIT_DEFAULT(); } while (0)

/* This lock is required if DEM and NVM may interrupt each other, e.g. if both components
 * are running in different tasks on a single CPU
 */
#define SchM_Enter_Dem_Nvm()      		do { SCHM_ENTER_DEFAULT(); } while (0)
#define SchM_Exit_Dem_Nvm()       		do { SCHM_EXIT_DEFAULT(); } while (0)

/* This lock is required if DEM and DCM may interrupt each other, e.g. if both components
 * are running in different tasks on a single CPU
 */
#define SchM_Enter_Dem_Dcm()      		do { SCHM_ENTER_DEFAULT(); } while (0)
#define SchM_Exit_Dem_Dcm()       		do { SCHM_EXIT_DEFAULT(); } while (0)


#endif


