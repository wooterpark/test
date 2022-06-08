

#ifndef CAN_H
#define CAN_H

#include "Can_17_MCanP.h"


#define CAN_AR_RELEASE_MAJOR_VERSION	4
#define CAN_AR_RELEASE_MINOR_VERSION	2	/* CIX2SGH */
#define CAN_AR_RELEASE_REVISION_VERSION   3

#define Can_Init(a)								Can_17_MCanP_Init(a)

#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
	#define Can_CheckBaudrate(a,b) 				Can_17_MCanP_CheckBaudrate(a,b)
#else
	#define Can_CheckBaudrate(a,b)     			ERROR_CanChangeBaudrateApi_NOT_SELECTED
#endif /* #if (CAN_CHANGE_BAUDRATE_API == STD_ON) */

#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
	#define CanP_ChangeBaudrate(a,b)      		Can_17_MCanP_ChangeBaudrate(a,b)
#else
	#define CanP_ChangeBaudrate(a,b)      		ERROR_CanChangeBaudrateApi_NOT_SELECTED
#endif /* #if (CAN_CHANGE_BAUDRATE_API == STD_ON) */

#define Can_SetControllerMode(a,b) 				Can_17_MCanP_SetControllerMode(a,b)
#define Can_DisableControllerInterrupts(a) 		Can_17_MCanP_DisableControllerInterrupts(a)
#define Can_EnableControllerInterrupts(a) 		Can_17_MCanP_EnableControllerInterrupts(a)
#define Can_Write(a,b) 							Can_17_MCanP_Write(a,b)
#define Can_MainFunction_Write() 				Can_17_MCanP_MainFunction_Write()
#define Can_MainFunction_Read() 				Can_17_MCanP_MainFunction_Read()
#define Can_MainFunction_BusOff()  				Can_17_MCanP_MainFunction_BusOff()
#define Can_MainFunction_Wakeup()  				Can_17_MCanP_MainFunction_Wakeup()
#define Can_MainFunction_Mode() 				Can_17_MCanP_MainFunction_Mode()
#define Can_CheckWakeup(a)  					Can_17_MCanP_CheckWakeup(a)
#define Can_IsrBusOffHandler(a)  				Can_17_MCanP_IsrBusOffHandler(a)
#define Can_IsrReceiveHandler(a)  				Can_17_MCanP_IsrReceiveHandler(a)
#define Can_IsrTransmitHandler(a) 				Can_17_MCanP_IsrTransmitHandler(a)

#endif /* CAN_H */
