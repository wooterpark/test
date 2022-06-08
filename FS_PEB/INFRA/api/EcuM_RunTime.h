

#ifndef ECUM_RUNTIME_H
#define ECUM_RUNTIME_H

#include "Std_Types.h"

/*Integration Hint : Include the necesary headers here for getting the time duration*/
#include "rba_BswSrv.h"

/*No version check added as the used api's are not AR provided.*/
#include "Mcu.h"

#include "rba_Reset.h"
/*
 * *************************************************************************************************
 * Preprocessor includes
 * *************************************************************************************************/


/*Hint : Project should include this header file. If want to measure the init duration for EcuM_AL_DriverInitZero,
 * EcuM_AL_DriverInitOne and EcuM_DeterminePbConfiguration then enable ECUM_STARTUP_DURATION to TRUE.
 * By default this will be FALSE.*/

#define ECUM_STARTUP_DURATION                   FALSE


#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/

/* A sample integration code for MDG1 project is also given below using (rba_BswSrv, Mcu and rba_Reset)*/

/*To get the current Time*/
#define EcuM_GetTicks()                         Mcu_Rb_GetSysTime()

/*To get the time since last Reset.*/
#define EcuM_GetTicksSinceLastReset(Ticks)      MCU_RB_TIM0TICKS_TO_US((uint32)((Ticks) - (rba_Reset_ApplEnv_st.TiStampCurr_u64)))

/*To get the duration of api's*/
#define EcuM_GetDuration(EndTicks,StartTicks)   MCU_RB_TIM0TICKS_TO_US((uint32)((EndTicks)-(StartTicks)))

/*
 * **************************************************************************************************
 * Fix Type declarations
 ***************************************************************************************************/
/* Hint : EcuM_TimeTicks_tu64 should be typedef to corresponding datat type here.
 * As the requirement was for time duration in u64 here u64 datatype is used.
 * But AUTOSAR there is no u64 data type. For MDG1 this is typedef to rba_BswSrv_uint64
 * as given below.*/
typedef rba_BswSrv_uint64  EcuM_TimeTicks_tu64;

/*
 * **************************************************************************************************
 * Extern declarations
 * **************************************************************************************************/

/*Hint : Do not remove the below extern declarations. Or else it will raise in compilation issues.*/

#define ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "EcuM_Cfg_MemMap.h"

/*To store the start and End time EcuM_AL_DriverInitZero, EcuM_AL_DriverInitOne and EcuM_DeterminePbConfiguration
 * respectively*/
extern EcuM_TimeTicks_tu64   EcuM_DriverInitZero_begin_ticks_u64;
extern EcuM_TimeTicks_tu64   EcuM_DriverInitZero_end_ticks_u64;
extern EcuM_TimeTicks_tu64   EcuM_DriverInitOne_begin_ticks_u64;
extern EcuM_TimeTicks_tu64   EcuM_DriverInitOne_end_ticks_u64;
extern EcuM_TimeTicks_tu64   EcuM_DeterminePbConfiguration_begin_ticks_u64;
extern EcuM_TimeTicks_tu64   EcuM_DeterminePbConfiguration_end_ticks_u64;

#define ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "EcuM_Cfg_MemMap.h"


#define ECUM_START_SEC_VAR_CLEARED_32
#include "EcuM_Cfg_MemMap.h"
/*To store the Duration of EcuM_AL_DriverInitZero, EcuM_AL_DriverInitOne and EcuM_DeterminePbConfiguration
 * respectively*/
extern uint32              EcuM_DriverInitZero_delta_us_u32;
extern uint32              EcuM_DriverInitOne_delta_us_u32;
extern uint32              EcuM_DeterminePbConfiguration_delta_us_u32;

/*To store the time since last reset for EcuM_AL_DriverInitZero, EcuM_AL_DriverInitOne and EcuM_DeterminePbConfiguration
 * respectively*/
extern uint32              EcuM_DriverInitZero_LastReset_begin_us_u32;
extern uint32              EcuM_DriverInitOne_LastReset_begin_us_u32;
extern uint32              EcuM_DeterminePbConfiguration_LastReset_begin_us_u32;


#define ECUM_STOP_SEC_VAR_CLEARED_32
#include "EcuM_Cfg_MemMap.h"

#endif /*ECUM_STARTUP_DURATION*/


#endif /*ECUM_RUNTIME_H*/


