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
 *	@file		<TLF35584_Cfg.h>
 *	@brief		<TLF35584模块配置>
 *
 *	<Compiler: HighTec GNU v4.9.4.0    MCU:TC39x>
 *
 *	@author 	<Simple Xie>
 *	@date		<2021-03-28>
 */
/*====================================================================================================================*/


/*====================================================================================================================*/
#ifndef TLF35584_CFG_H_
#define TLF35584_CFG_H_

/*====================================================================================================================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 *
 */
/*====================================================================================================================*/


/*====================================================================================================================*/
/*                                                     Includes                                                       */
/*====================================================================================================================*/

/*====================================================================================================================*/
/*                                          TLF35584Lib Macro Definitions                                             */
/*====================================================================================================================*/
#define     TLF35584LIB_VERSION_MAJOR        		(uint8)0x01U
#define     TLF35584LIB_VERSION_MINOR        		(uint8)0x00U
#define     TLF35584LIB_VERSION_PATCH        		(uint8)0x0AU

#define     TLF35584_MAX_ADDRESS                ((uint8)0x3FU)    /* 寄存器数量最大地址 */
#define     TLF35584_SLEEP_TIME_MIN             ((uint32)0U)      /* TLF35584_SetSleepTime最小值 */
#define     TLF35584_SLEEP_TIME_MAX             ((uint32)2796U)   /* TLF35584_SetSleepTime最大值 */

/*====================================================================================================================*/
/*                                   MUNIU Tool Generate Macro Definitions                                            */
/*====================================================================================================================*/
#define     TLF35584_CLOCK_uC_STM               ((uint32)100)    /* uint:MHz */
#define     TLF35584_MAX_EBBUFF			        		((uint8)30U)      /* SPI Ext.Buff缓存数组 */
#define     TLF35584_MAX_DELAY_TIME		       	  ((uint16)5000U)   /* SPI通信忙超时，Check if QSPI is idle */
#define     TLF35584_SHUT_DOWN_DELAY_TIME       ((uint16)100U)    /* 下电延时值Change TLF35584 mode to Standby */

#define     SpiChannel_TLF35584                 SpiConf_SpiChannel_SpiChannel_TLF35584
#define     SpiSequence_TLF35584                SpiConf_SpiSequence_SpiSequence_TLF35584
#define     TLF35584LIB_DEBUG_LED               (DIO_CHANNEL_23_0)                  
#define     TLF35584_SS1_CHANNEL                (DIO_CHANNEL_32_4)
#define     TLF35584_SS2_CHANNEL                (DIO_CHANNEL_32_4)
#define     TLF35584_WDI_CHANNEL                (DIO_CHANNEL_14_9)
#define     TLF35584_TM_CHANNEL                 (DIO_CHANNEL_34_5)
#define     TLF35584_INH_CHANNEL                (TLF35584LIB_DEBUG_LED)             
#define     TLF35584_RTC_INT_CHANNEL            (TLF35584LIB_DEBUG_LED)            
#define     TLF35584_LOCK_CHANNEL               (TLF35584LIB_DEBUG_LED)            
#define     TLF35584_KL15_CHANNEL               (TLF35584LIB_DEBUG_LED)      
#define     TLF35584_VCU_CHANNEL                (TLF35584LIB_DEBUG_LED)             
#define     TLF35584_AC_CHANNEL                 (TLF35584LIB_DEBUG_LED)             
#define     TLF35584_DC_CHANNEL                 (TLF35584LIB_DEBUG_LED)           

#define     TLF35584_SAFETLIB_USED              (1U)		/* Description:是否使用MCAL SMU的接口 */
#define     TLF35584_SELF_TEST                  (1U)		/* Description:是否使用自检模块 */

#define     TLF35584_ACAN_WAKEUP                (0U)
#define     TLF35584_RTC_WAKEUP                 (0U)
#define     TLF35584_LOCK_MCU                   (0U)
#define     TLF35584_KL15_WAKEUP                (0U)
#define     TLF35584_VCU_WAKEUP                 (0U)
#define     TLF35584_AC_WAKEUP                  (0U)
#define     TLF35584_DC_WAKEUP                  (0U)
#define     TLF35584_DYNAMIC_TEST               (0U)

#define     TLF35584_DIO_USED                   (1U)
#define     TLF35584_MPS_USED                   (1U)

#define     TLF35584_ROT_ERRPIN_SELF_TEST       (1U)

#define     TLF35584_OffFullPath_SELF_TEST      (1U)
#define     TLF35584_OffPath_SELF_TEST          (1U)
#define     TLF35584_IntFullPath_SELF_TEST      (1U)
#define     TLF35584_IntEvent_SELF_TEST         (1U)

#define     TLF35584_WWDInt_SELF_TEST           (1U)        /* 窗口狗初始化自检功能开关配置 */
#define     TLF35584_WWDSafe_SELF_TEST          (1U)

#define     TLF35584_FWDInt_SELF_TEST           (1U)        /* 功能狗初始化自检功能开关配置 */
#define     TLF35584_FWDSafe_SELF_TEST           (1U)

#define     TLF35584_INIT_RETRY_MAX             (3U)        /* 客户指定需求将初始化阶段SBC最大允许失败重配的次数  */
#define     TLF35584_RW_RETRY_MAX               (3U)        /* 客户指定需求将SPI读写数据奇偶校验允许失败重试次数  */


#define     TLF35584_DET_USED                   (0U)        /* Det功能的开关配置  */
#define     TLF35584_MODULE_ID                  (1007U)     /* TLF35584在Det中的故障模块的编号  */
#define     TLF35584_VENDOR                     (1000U)     /* TLF35584在Det中的供应商的编号  */

/*====================================================================================================================*/
/*                                                Typedef Definitions                                                 */
/*====================================================================================================================*/

/*====================================================================================================================*/
/*                                           Global Variable Declarations                                             */
/*====================================================================================================================*/

/*====================================================================================================================*/
/*                                           Global Function Declarations                                             */
/*====================================================================================================================*/

#endif /* TLF35584_CFG_H_ */

