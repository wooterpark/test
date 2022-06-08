/*
 * BswM_Appl.h
 *
 *  Created on: 2019Äê12ÔÂ1ÈÕ
 *      Author: zhang
 */

#ifndef INFRA_INTEG_BSWMAPPL_BSWM_APPL_H_
#define INFRA_INTEG_BSWMAPPL_BSWM_APPL_H_


typedef enum
{
	BSWM_MODE_ECUM_STATE_STARTUP_ONE,
	BSWM_MODE_ECUM_STATE_STARTUP_TWO,
	BSWM_MODE_ECUM_STATE_RUN,
	BSWM_MODE_ECUM_STATE_APP_RUN,
	BSWM_MODE_ECUM_STATE_APP_POST_RUN,
	BSWM_MODE_ECUM_STATE_PREP_SHUTDOWN,
	BSWM_MODE_ECUM_STATE_SHUTDOWN
} BswM_ModeState_t;

extern BswM_ModeState_t BswM_ModeState_Run_State;

void BswM_UserCallout_InitTwo(void);
void BswM_UserCallout_ReadAll(void);
void BswM_UserCallout_FullComm(void);
void BswM_UserCallout_Godown(void);
void BswM_UserCallout_Shutdown(void);
void BswM_UserCallout_StopComm(void);
void BswM_UserCallback_ExtDogDeInit(void);
void BswM_UserCallout_SetFlagToSWC(void);


#endif /* INFRA_INTEG_BSWMAPPL_BSWM_APPL_H_ */
