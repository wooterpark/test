/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/


   

     

/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: CanSM / AR42.4.0.1           Module Package Version
 * $Editor_____: 9.0             Tool Version
 * $Model______: 2.3.0.4                ECU Parameter Definition Version
 *

 </VersionHead>*/



  /*********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
 #include "CanSM_PBcfg.h"




#define CANSM_START_SEC_CONST_8
#include "CanSM_MemMap.h"

/*LUT for network index*/
CONST(uint8, CANSM_CONST) CanSM_NetworkId_LUT[1][CANSM_NUM_CAN_NETWORKS]=
{
    {0,1}
};

#define CANSM_STOP_SEC_CONST_8
#include "CanSM_MemMap.h"


/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_START_SEC_CONST_8
#include "CanSM_MemMap.h"
/* CanSM Network Index for corresponding CAN Controller ID */
CONST(uint8, CANSM_CONST) CanSM_NetworktoCtrl_Config_acu8[] = 
{
    0,
    1
};


/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_STOP_SEC_CONST_8
#include "CanSM_MemMap.h"

/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_START_SEC_CONST_8
#include "CanSM_MemMap.h"

/* CAN Contollerid for each network */
static CONST(uint8, CANSM_VAR) CanSM_Ctrl_CanSMManagerNetwork_Can_Network_0_Config_au8[] = 
{  
   0

};

static CONST(uint8, CANSM_VAR) CanSM_Ctrl_CanSMManagerNetwork_Can_Network_1_Config_au8[] = 
{  
   1

};




/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_STOP_SEC_CONST_8
#include "CanSM_MemMap.h"

 

/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"



CONST(CanSM_NetworkConf_tst, CANSM_CONST) CanSM_Network_Config_acst[] = 
{
/* ControllerStartIndx        BusOffErrID                                 BorTimeL1    BorTimeL2       BorTimeTxEnsured     Trcv_Handle   SizeOfController   BorCounter_L1_L2            ComMChannelId                   canSMEnableBusOffDelay    PN enabled/disabled for Transceiver*/
{
CanSM_Ctrl_CanSMManagerNetwork_Can_Network_0_Config_au8, DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0,4u,         10u, 20u,255, 
1, 5,                       0,            TRUE,    FALSE,    FALSE },
{
CanSM_Ctrl_CanSMManagerNetwork_Can_Network_1_Config_au8, DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1,4u,         10u, 20u,255, 
1, 5,                       1,            TRUE,    FALSE,    FALSE }

};


/* CanSM Configuration */
CONST(CanSM_ConfigType, CANSM_CONST) CanSM_ConfigSet[] = 
{

    {
        CanSM_Network_Config_acst,
        CanSM_NetworktoCtrl_Config_acu8,
        5, /*CanSMModeRequestRepetitionMax*/
        7, /*CanSMModeRequestRepetitionTime*/
        CANSM_NUM_CAN_NETWORKS,      /*Number of CANSM Networks configured*/
        0 /*Active configSet index*/
    }
};
/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"
