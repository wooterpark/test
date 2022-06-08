/*====================================================================================================================*/
/*  
 *  @Copyright (C) 2019, 上海知从科技有限公司       Shanghai ZC Technology Co., Ltd.               All rights reserved.
 *  
 *               This software is copyright protected and proprietary to Shanghai ZC Technology Co., Ltd.
 *               Shanghai ZC Technology Co., Ltd. grants to you only those rights as set out in the license conditions.
 *               All other rights remain with  Shanghai ZC Technology Co., Ltd.
 */               
/**********************************************************************************************************************/
/*
* 版本信息参考: TLF35584ErrHdl_Cfg.h
*/
/*====================================================================================================================*/



/*====================================================================================================================*/
/*                                                     Includes                                                       */
/*====================================================================================================================*/
#include "TLF35584ErrHdl_Cfg.h"

/*====================================================================================================================*/
/*                                                 Macro Definitions                                                  */
/*====================================================================================================================*/



/*====================================================================================================================*/
/*                                                Typedef Definitions                                                 */
/*====================================================================================================================*/



/*====================================================================================================================*/
/*                                              Imported declarations                                                 */
/*====================================================================================================================*/



/*====================================================================================================================*/
/*                                            Private Variable Definitions                                            */
/*====================================================================================================================*/




/*====================================================================================================================*/
/*                                            Global Variable Definitions                                             */
/*====================================================================================================================*/

/* QAC Annotation：No effect */
/* PRQA S 3408 EOF */
const TLF35584ErrHdl_ConfigType TLF35584ErrHdl_Config[] =
{
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
	{TRUE, NULL_PTR},
};

/* PRQA S 776 EOF */ /* QAC Annotation：调用不同函数 */

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_If_IntMiss =
{
	1,
	TLF35584_REG_IF,
	7,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Otfail_Com =
{
	2,
	TLF35584_REG_OTFAIL,
	4,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Otwrnsf_Com =
{
	3,
	TLF35584_REG_OTWRNSF,
	4,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf0_Comsg =
{
	4,
	TLF35584_REG_MONSF0,
	4,
	1,
	0
};
	
const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf1_Comov =
{
	5,
	TLF35584_REG_MONSF1,
	4,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf2_Comuv =
{
	6,
	TLF35584_REG_MONSF2,
	4,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Otwrnsf_Vref =
{
	7,
	TLF35584_REG_OTWRNSF,
	5,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf0_Vrefsg =
{
	8,
	TLF35584_REG_MONSF0,
	5,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf2_Vrefuv =
{
	9,
	TLF35584_REG_MONSF2,
	5,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf1_Vrefov =
{
	10,
	TLF35584_REG_MONSF1,
	5,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Otwrnsf_Stdby =
{
	11,
	TLF35584_REG_OTWRNSF,
	2,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf0_Stbysg =
{
	12,
	TLF35584_REG_MONSF0,
	2,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf2_Stbyuv =
{
	13,
	TLF35584_REG_MONSF2,
	2,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf1_Stbyov =
{
	14,
	TLF35584_REG_MONSF1,
	2,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Otwrnsf_Uc =
{
	15,
	TLF35584_REG_OTWRNSF,
	1,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Otfail_Uc =
{
	16,
	TLF35584_REG_OTFAIL,
	1,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf0_Ucsg =
{
	17,
	TLF35584_REG_MONSF0,
	1,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf1_Ucov =
{
	18,
	TLF35584_REG_MONSF1,
	1,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf2_Ucuv =
{
	19,
	TLF35584_REG_MONSF2,
	1,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Otwrnsf_Preg =
{
	20,
	TLF35584_REG_OTWRNSF,
	0,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Otfail_Preg =
{
	21,
	TLF35584_REG_OTFAIL,
	0,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf2_Preguv =
{
	22,
	TLF35584_REG_MONSF2,
	0,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf1_Pregov =
{
	23,
	TLF35584_REG_MONSF1,
	0,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf0_Pregsg =
{
	24,
	TLF35584_REG_MONSF0,
	0,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf0_Trk2sg =
{
	25,
	TLF35584_REG_MONSF0,
	7,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf1_Trk2ov =
{
	26,
	TLF35584_REG_MONSF1,
	7,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf2_Trk2uv =
{
	27,
	TLF35584_REG_MONSF2,
	7,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf0_Trk1sg =
{
	28,
	TLF35584_REG_MONSF0,
	6,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf1_Trk1ov =
{
	29,
	TLF35584_REG_MONSF1,
	6,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf2_Trk1uv =
{
	30,
	TLF35584_REG_MONSF2,
	6,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf3_Bg12ov =
{
	31,
	TLF35584_REG_MONSF3,
	5,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf3_Bg12uv =
{
	32,
	TLF35584_REG_MONSF3,
	4,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Spisf_Lock =
{
	33,
	TLF35584_REG_SPISF,
	4,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Spisf_Dure =
{
	34,
	TLF35584_REG_SPISF,
	3,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Spisf_Addre =
{
	35,
	TLF35584_REG_SPISF,
	2,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Spisf_Lene =
{
	36,
	TLF35584_REG_SPISF,
	1,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Spisf_Pare =
{
	37,
	TLF35584_REG_SPISF,
	0,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf0_Vcoresg =
{
	38,
	TLF35584_REG_MONSF0,
	3,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf1_Vcoreov =
{
	39,
	TLF35584_REG_MONSF1,
	3,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf2_Vcoreuv =
{
	40,
	TLF35584_REG_MONSF2,
	3,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf3_Biashi =
{
	41,
	TLF35584_REG_MONSF3,
	7,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf3_Bisalow =
{
	42,
	TLF35584_REG_MONSF3,
	6,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Monsf3_Vbatov =
{
	43,
	TLF35584_REG_MONSF3,
	0,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Otfail_Mon =
{
	44,
	TLF35584_REG_OTFAIL,
	7,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Sysfail_Voltselrr =
{
	45,
	TLF35584_REG_SYSFAIL,
	0,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Syssf_Errmiss =
{
	46,
	TLF35584_REG_SYSSF,
	3,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Initerr_Errf =
{
	47,
	TLF35584_REG_INITERR,
	5,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Syssf_Fwde =
{
	48,
	TLF35584_REG_SYSSF,
	2,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Initerr_Fwdf =
{
	49,
	TLF35584_REG_INITERR,
	4,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Syssf_Wwde =
{
	50,
	TLF35584_REG_SYSSF,
	1,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Initerr_Wwdf =
{
	51,
	TLF35584_REG_INITERR,
	3,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Syssf_Noop =
{
	52,
	TLF35584_REG_SYSSF,
	5,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Syssf_Trfail =
{
	53,
	TLF35584_REG_SYSSF,
	4,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Initerr_Hardres =
{
	54,
	TLF35584_REG_INITERR,
	7,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Initerr_Softres =
{
	55,
	TLF35584_REG_INITERR,
	6,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Syssf_Cfge =
{
	56,
	TLF35584_REG_SYSSF,
	0,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Sysfail_Initf =
{
	57,
	TLF35584_REG_SYSFAIL,
	7,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_If_Abist =
{
	58,
	TLF35584_REG_IF,
	6,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Sysfail_Abisterr =
{
	59,
	TLF35584_REG_SYSFAIL,
	6,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Wksf_Wkspi =
{
	60,
	TLF35584_REG_WKSF,
	4,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Wksf_Wktim =
{
	61,
	TLF35584_REG_WKSF,
	3,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Wksf_Cmon =
{
	62,
	TLF35584_REG_WKSF,
	2,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Wksf_Ena =
{
	63,
	TLF35584_REG_WKSF,
	1,
	1,
	0
};


const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_Wksf_Wak =
{
	64,
	TLF35584_REG_WKSF,
	0,
	1,
	0
};

const TLF35584ErrHdl_FaultType TLF35584ErrHdl_Fault_If_Sys =
{
	65,
	TLF35584_REG_IF,
	0,
	1,
	0
};


const TLF35584ErrHdl_FaultType* TLF35584ErrHdl_FaultList[] =
{
	&TLF35584ErrHdl_Fault_If_IntMiss,
	&TLF35584ErrHdl_Fault_Otfail_Com,
	&TLF35584ErrHdl_Fault_Otwrnsf_Com,
	&TLF35584ErrHdl_Fault_Monsf0_Comsg,
	&TLF35584ErrHdl_Fault_Monsf1_Comov,
	&TLF35584ErrHdl_Fault_Monsf2_Comuv,
	&TLF35584ErrHdl_Fault_Otwrnsf_Vref,
	&TLF35584ErrHdl_Fault_Monsf0_Vrefsg,
	&TLF35584ErrHdl_Fault_Monsf2_Vrefuv,
	&TLF35584ErrHdl_Fault_Monsf1_Vrefov,
	&TLF35584ErrHdl_Fault_Otwrnsf_Stdby,
	&TLF35584ErrHdl_Fault_Monsf0_Stbysg,
	&TLF35584ErrHdl_Fault_Monsf2_Stbyuv,
	&TLF35584ErrHdl_Fault_Monsf1_Stbyov,
	&TLF35584ErrHdl_Fault_Otwrnsf_Uc,
	&TLF35584ErrHdl_Fault_Otfail_Uc,
	&TLF35584ErrHdl_Fault_Monsf0_Ucsg,
	&TLF35584ErrHdl_Fault_Monsf1_Ucov,
	&TLF35584ErrHdl_Fault_Monsf2_Ucuv,
	&TLF35584ErrHdl_Fault_Otwrnsf_Preg,
	&TLF35584ErrHdl_Fault_Otfail_Preg,
	&TLF35584ErrHdl_Fault_Monsf2_Preguv,
	&TLF35584ErrHdl_Fault_Monsf1_Pregov,
	&TLF35584ErrHdl_Fault_Monsf0_Pregsg,
	&TLF35584ErrHdl_Fault_Monsf0_Trk2sg,
	&TLF35584ErrHdl_Fault_Monsf1_Trk2ov,
	&TLF35584ErrHdl_Fault_Monsf2_Trk2uv,
	&TLF35584ErrHdl_Fault_Monsf0_Trk1sg,
	&TLF35584ErrHdl_Fault_Monsf1_Trk1ov,
	&TLF35584ErrHdl_Fault_Monsf2_Trk1uv,
	&TLF35584ErrHdl_Fault_Monsf3_Bg12ov,
	&TLF35584ErrHdl_Fault_Monsf3_Bg12uv,
	&TLF35584ErrHdl_Fault_Spisf_Lock,
	&TLF35584ErrHdl_Fault_Spisf_Dure,
	&TLF35584ErrHdl_Fault_Spisf_Addre,
	&TLF35584ErrHdl_Fault_Spisf_Lene,
	&TLF35584ErrHdl_Fault_Spisf_Pare,
	&TLF35584ErrHdl_Fault_Monsf0_Vcoresg,
	&TLF35584ErrHdl_Fault_Monsf1_Vcoreov,
	&TLF35584ErrHdl_Fault_Monsf2_Vcoreuv,
	&TLF35584ErrHdl_Fault_Monsf3_Biashi,
	&TLF35584ErrHdl_Fault_Monsf3_Bisalow,
	&TLF35584ErrHdl_Fault_Monsf3_Vbatov,
	&TLF35584ErrHdl_Fault_Otfail_Mon,
	&TLF35584ErrHdl_Fault_Sysfail_Voltselrr,
	&TLF35584ErrHdl_Fault_Syssf_Errmiss,
	&TLF35584ErrHdl_Fault_Initerr_Errf,
	&TLF35584ErrHdl_Fault_Syssf_Fwde,
	&TLF35584ErrHdl_Fault_Initerr_Fwdf,
	&TLF35584ErrHdl_Fault_Syssf_Wwde,
	&TLF35584ErrHdl_Fault_Initerr_Wwdf,
	&TLF35584ErrHdl_Fault_Syssf_Noop,
	&TLF35584ErrHdl_Fault_Syssf_Trfail,
	&TLF35584ErrHdl_Fault_Initerr_Hardres,
	&TLF35584ErrHdl_Fault_Initerr_Softres,
	&TLF35584ErrHdl_Fault_Syssf_Cfge,
	&TLF35584ErrHdl_Fault_Sysfail_Initf,
	&TLF35584ErrHdl_Fault_If_Abist,
	&TLF35584ErrHdl_Fault_Sysfail_Abisterr,
	&TLF35584ErrHdl_Fault_Wksf_Wkspi,
	&TLF35584ErrHdl_Fault_Wksf_Wktim,
	&TLF35584ErrHdl_Fault_Wksf_Cmon,
	&TLF35584ErrHdl_Fault_Wksf_Ena,
	&TLF35584ErrHdl_Fault_Wksf_Wak,
	&TLF35584ErrHdl_Fault_If_Sys,
};

/*====================================================================================================================*/
/*                                            Private Function Declarations                                           */
/*====================================================================================================================*/



/*====================================================================================================================*/
/*                                            Private Function Implementation                                         */
/*====================================================================================================================*/



/*====================================================================================================================*/
/*                                            Global Function Implementation                                          */
/*====================================================================================================================*/



