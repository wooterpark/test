
#ifndef FLS_H
#define FLS_H

#include "Fls_17_Pmu.h"

#if 1

#define Fls_ConfigType		Fls_17_Pmu_ConfigType
#define Fls_Read(a,b,c) 	Fls_17_Pmu_Read(a,b,c)
#define Fls_GetJobResult	Fls_17_Pmu_GetJobResult
#define Fls_Compare(a,b,c) 	Fls_17_Pmu_Compare(a,b,c)
#define Fls_Write(a,b,c)	Fls_17_Pmu_Write(a,b,c)
#define Fls_Erase(a,b)		Fls_17_Pmu_Erase(a,b)
#define Fls_SetMode(Mode)	Fls_17_Pmu_SetMode(Mode)
#define Fls_MainFunction(a)	Fls_17_Pmu_MainFunction(a)
#define Fls_Init(a)			Fls_17_Pmu_Init(a)
#define Fls_ControlTimeoutDet(a)	Fls_17_Pmu_ControlTimeoutDet(a)
#define Fls_GetStatus() 	Fls_17_Pmu_GetStatus()

#else

#define Fls_Read(a,b,c) 	Fls_17_Pmu_Read(a-0xAF000000,b,c)
#define Fls_GetJobResult	Fls_17_Pmu_GetJobResult
#define Fls_Compare(a,b,c) 	Fls_17_Pmu_Compare(a-0xAF000000,b,c)
#define Fls_Write(a,b,c)	Fls_17_Pmu_Write(a-0xAF000000,b,c)
#define Fls_Erase(a,b)		Fls_17_Pmu_Erase(a-0xAF000000,b)
#define Fls_SetMode(Mode)	Fls_17_Pmu_SetMode(Mode)
#define Fls_MainFunction()	Fls_17_Pmu_MainFunction()
#define Fls_Init(a)			Fls_17_Pmu_Init(a)

#endif

/* CIX2SGH */
/* Fls_Mode for FeeFs1 */
#define Fls_Mode Fls_ConfigPtr->FlsStateVarPtr->FlsMode

/* Autosar specification version */
#define FLS_AR_RELEASE_MAJOR_VERSION 4
#define FLS_AR_RELEASE_MINOR_VERSION 2
#define FLS_AR_RELEASE_REVISION_VERSION 2
/* CIX2SGH */

#endif /* FLS_H */
