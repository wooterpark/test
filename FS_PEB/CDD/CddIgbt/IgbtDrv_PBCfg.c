/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2019 by Jee.		All rights reserved.
** This software is copyright protected and proprietary to Jee.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with Jee.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \Prv\IgbtDrv$
* $Class_____: C$
* $Name______: IgbtDrv.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: LQ$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
** 1EDI2002AS Driver
*******************************************************************************
* $History__:$
* V0.0.0      2019.10.03 		LQ
*  N: new created
*******************************************************************************/

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "IgbtDrv_Cfg.h"


/*******************************************************************************
**                 		  configuration Data           		              **
*******************************************************************************/
/*Status Register Value,Note that the IgbtDrv_RegStatus_st must same with EB seq0 */
static IgbtDrv_RegStatusType IgbtDrv_RegStatus_st[IGBTDRV_NUM_OF_REGSTATUS]=
{
	/**/            /**/     	        /**/
	{BIT16_ACCESS,	IGBTDRV_REG_PSTAT,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS,	IGBTDRV_REG_PSTAT2,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS,	IGBTDRV_REG_PER,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS,	IGBTDRV_REG_SSTAT,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS,	IGBTDRV_REG_SSTAT2,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS,	IGBTDRV_REG_SER,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_SGM1,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_SGM2,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_PCTRL,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_PCTRL2,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_PRW,	 {0,0,0,0,0,0}    },
};

 /* Cfg Register Value,Note that the IgbtDrv_RegConf_st must same with EB seqConf */
static IgbtDrv_RegStatusType IgbtDrv_RegConf_st[IGBTDRV_NUM_OF_REGCONF]=
{
	/**/            /**/     	        /**/
	{BIT16_ACCESS,	IGBTDRV_REG_PCFG,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS,	IGBTDRV_REG_PCFG2,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS,	IGBTDRV_REG_PCTRL,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS,	IGBTDRV_REG_PCTRL2,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS,	IGBTDRV_REG_PSCR,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS,	IGBTDRV_REG_PRW,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_SCFG,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_SCFG2,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_SCTRL,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_SSCR,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_SDESAT,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_SOCP,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_SRTTOF,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_SSTTOF,	 {0,0,0,0,0,0}    },
	{BIT16_ACCESS ,	IGBTDRV_REG_SACLT,	 {0,0,0,0,0,0}    },

};

 /*  For 1ED2002AS configuration */
static const IgbtDrv_RegCfgType IgbtDrv_RegCfg_st[IGBTDRV_NUM_OF_CFGREG]=
{
	/**/            /**/     	    /**/				/**/          			/**/
	{BIT16_ACCESS,	IGBTDRV_REG_SCFG,	IGBTDRV_VALUE_SCFG,    IgbtDrv_WrReg16   },
	{BIT16_ACCESS,	IGBTDRV_REG_SDESAT,	IGBTDRV_VALUE_SDESAT,  IgbtDrv_WrReg16   },
	{BIT16_ACCESS,	IGBTDRV_REG_SSTTOF,	IGBTDRV_VALUE_SSTTOF,  IgbtDrv_WrReg16   },
	{BIT16_ACCESS,	IGBTDRV_REG_SRTTOF,	IGBTDRV_VALUE_SRTTOF,  IgbtDrv_WrReg16   },
	{BIT16_ACCESS,	IGBTDRV_REG_SCFG2,	IGBTDRV_VALUE_SCFG2,   IgbtDrv_WrReg16   },
	{BIT16_ACCESS,	IGBTDRV_REG_SACLT,	IGBTDRV_VALUE_SACLT,   IgbtDrv_WrReg16   },
	{BIT8_ACCESS ,	IGBTDRV_REG_PCFG,	IGBTDRV_VALUE_PCFG  ,  IgbtDrv_WrReg8    },
	{BIT16_ACCESS ,	IGBTDRV_REG_PCFG2,	IGBTDRV_VALUE_PCFG2,  IgbtDrv_WrReg16    },
};

/* IgbtDrv_init parameter */
const IgbtDrv_HWCfgType IgbtDrv_HWCfg_cst =
{

	&IgbtDrv_RegStatus_st[0u],
	&IgbtDrv_RegConf_st[0u],
	&IgbtDrv_RegCfg_st[0u],


};


