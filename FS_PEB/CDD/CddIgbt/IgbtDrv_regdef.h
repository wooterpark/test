/*
 * IgbtDrv_refdef.h
 *
 *  Created on: 2019-10-6
 *      Author: linqiang
 */

#ifndef IGBTDRV_REFDEF_H_
#define IGBTDRV_REFDEF_H_


/* Primary Register Offset Address*/
#define		IGBTDRV_REG_PID			(uint8)0x00
#define 	IGBTDRV_REG_PSTAT 		(uint8)0x01
#define 	IGBTDRV_REG_PSTAT2 		(uint8)0x02
#define 	IGBTDRV_REG_PER 		(uint8)0x03
#define 	IGBTDRV_REG_PCFG 		(uint8)0x04 /*8-bit register*/
#define 	IGBTDRV_REG_PCFG2		(uint8)0x05
#define 	IGBTDRV_REG_PCTRL 		(uint8)0x06 /*8-bit register*/
#define 	IGBTDRV_REG_PCTRL2 		(uint8)0x07 /*8-bit register*/
#define 	IGBTDRV_REG_PSCR 		(uint8)0x08 /*8-bit register*/
#define 	IGBTDRV_REG_PRW 		(uint8)0x09
#define 	IGBTDRV_REG_PPIN 		(uint8)0x0A
#define 	IGBTDRV_REG_PCS 		(uint8)0x0B

/* Secondary Registers Offset Address */
#define 	IGBTDRV_REG_SID 		(uint8)0x10
#define 	IGBTDRV_REG_SSTAT 		(uint8)0x11
#define 	IGBTDRV_REG_SSTAT2 		(uint8)0x12
#define 	IGBTDRV_REG_SER 		(uint8)0x13
#define 	IGBTDRV_REG_SCFG 		(uint8)0x14
#define 	IGBTDRV_REG_SCFG2 		(uint8)0x15
#define 	IGBTDRV_REG_SCTRL 		(uint8)0x16
#define 	IGBTDRV_REG_SSCR 		(uint8)0x17 /*8-bit register*/
#define 	IGBTDRV_REG_SDESAT 		(uint8)0x18
#define 	IGBTDRV_REG_SOCP 		(uint8)0x19
#define 	IGBTDRV_REG_SRTTOF 		(uint8)0x1A
#define 	IGBTDRV_REG_SGM1 		(uint8)0x1C
#define 	IGBTDRV_REG_SGM2 		(uint8)0x1D
#define 	IGBTDRV_REG_SSTTOF 		(uint8)0x1B
#define 	IGBTDRV_REG_SACLT 		(uint8)0x1E
#define 	IGBTDRV_REG_SCS 		(uint8)0x1F



#endif /* IGBTDRV_REFDEF_H_ */
