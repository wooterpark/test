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
 * $Generator__: Com / AR42.4.0.0                Module Package Version
 * $Editor_____: 9.0                Tool Version
 * $Model______: 2.3.0.4                ECU Parameter Definition Version
 *
 
 </VersionHead>*/
#ifndef COM_PBCFG_INTERNALID_H
#define COM_PBCFG_INTERNALID_H

/*
 * VERY IMP : This file contains internal symbolic names , which are defined as Internal IDs
 *            This file should be generated from Com_Generate_PB action.
 *            This file is generated for both pre-compile & post-build variant.
 *            For pre-compile , Internal ID and External ID would be the same.
 *            No other code should be generated in this file
 *            This file should be only included in COM_PBcfg.c file.
 * COM internal structures and tables (defined in COM_PBcfg.c file) must use internal symolic names, defined in this file
 *
 */

/* ------------------------------------------------------------------------ */
/* Begin section for Tx IPdu internal symbolic names */

#define     ComConf_ComIPdu_Internal_DIAG_01_Can_Network_1_CANNODE_0               0
#define     ComConf_ComIPdu_Internal_PEB_01_Can_Network_0_CANNODE_0               1
#define     ComConf_ComIPdu_Internal_PEB_03_Can_Network_0_CANNODE_0               2
#define     ComConf_ComIPdu_Internal_PEB_04_Can_Network_0_CANNODE_0               3
#define     ComConf_ComIPdu_Internal_PEB_08_Can_Network_0_CANNODE_0               4
#define     ComConf_ComIPdu_Internal_PEB_09_Can_Network_0_CANNODE_0               5
#define     ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0               6
#define     ComConf_ComIPdu_Internal_PEB_05_Can_Network_0_CANNODE_0               7
#define     ComConf_ComIPdu_Internal_PEB_07_Can_Network_0_CANNODE_0               8
#define     ComConf_ComIPdu_Internal_SysBoot_Tx_Can_Network_1_CANNODE_0               9
#define     ComConf_ComIPdu_Internal_PEB_06_Can_Network_0_CANNODE_0               10


/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Rx IPdu internal symbolic names */

#define     ComConf_ComIPdu_Internal_BMS_01_Can_Network_0_CANNODE_0               0
#define     ComConf_ComIPdu_Internal_SysBoot_Rx_Can_Network_1_CANNODE_0               1
#define     ComConf_ComIPdu_Internal_TOOL_01_Can_Network_1_CANNODE_0               2
#define     ComConf_ComIPdu_Internal_VCU_01_Can_Network_0_CANNODE_0               3
#define     ComConf_ComIPdu_Internal_VCU_02_Can_Network_0_CANNODE_0               4
#define     ComConf_ComIPdu_Internal_VCU_03_Can_Network_0_CANNODE_0               5
#define     ComConf_ComIPdu_Internal_VCU_04_Can_Network_0_CANNODE_0               6
#define     ComConf_ComIPdu_Internal_VCU_05_Can_Network_0_CANNODE_0               7
#define     ComConf_ComIPdu_Internal_VCU_06_Can_Network_0_CANNODE_0               8
#define     ComConf_ComIPdu_Internal_VCU_07_Mask_Can_Network_0_CANNODE_0               9


/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Tx signal internal symbolic names */

#define     ComSignal_Internal_Diag_Data0_DIAG_01               0
#define     ComSignal_Internal_Diag_Data1_DIAG_01               1
#define     ComSignal_Internal_Diag_Data2_DIAG_01               2
#define     ComSignal_Internal_Diag_Data3_DIAG_01               3
#define     ComSignal_Internal_Diag_Data4_DIAG_01               4
#define     ComSignal_Internal_Diag_Data5_DIAG_01               5
#define     ComSignal_Internal_Diag_Data6_DIAG_01               6
#define     ComSignal_Internal_Diag_Data7_DIAG_01               7
#define     ComSignal_Internal_PEB01_ctRoll_PEB_01               8
#define     ComSignal_Internal_PEB01_Checksum_PEB_01               9
#define     ComSignal_Internal_PEB01_IsCurr_PEB_01               10
#define     ComSignal_Internal_PEB01_stMode_PEB_01               11
#define     ComSignal_Internal_PEB01_UdcCurr_PEB_01               12
#define     ComSignal_Internal_PEB01_TrqCurr_PEB_01               13
#define     ComSignal_Internal_PEB01_NCurr_PEB_01               14
#define     ComSignal_Internal_PEB03_TempEpp_PEB_03               15
#define     ComSignal_Internal_PEB03_TempCurrStr2_PEB_03               16
#define     ComSignal_Internal_PEB03_TempCurrStr1_PEB_03               17
#define     ComSignal_Internal_PEB03_IGBTTempW_PEB_03               18
#define     ComSignal_Internal_PEB03_IGBTTempV_PEB_03               19
#define     ComSignal_Internal_PEB03_IGBTTempU_PEB_03               20
#define     ComSignal_Internal_PEB03_TempStr_PEB_03               21
#define     ComSignal_Internal_PEB04_TrqCurrWoDmpC_PEB_04               22
#define     ComSignal_Internal_PEB04_stGateDrv_PEB_04               23
#define     ComSignal_Internal_PEB04_bDmpCActv_PEB_04               24
#define     ComSignal_Internal_PEB04_agRtrElecSnsr_PEB_04               25
#define     ComSignal_Internal_PEB04_Isq_PEB_04               26
#define     ComSignal_Internal_PEB04_Isd_PEB_04               27
#define     ComSignal_Internal_PEB04_OfsAl_PEB_04               28
#define     ComSignal_Internal_PEB08_HwVer_PEB_08               29
#define     ComSignal_Internal_PEB08_stDischg_PEB_08               30
#define     ComSignal_Internal_PEB09_stEppFailSt_PEB_09               31
#define     ComSignal_Internal_PEB09_stEppDrvMod_PEB_09               32
#define     ComSignal_Internal_PEB09_stEpp_PEB_09               33
#define     ComSignal_Internal_PEB09_posEpp_PEB_09               34
#define     ComSignal_Internal_PEB09_IsEpp_PEB_09               35
#define     ComSignal_Internal_PEB09_flgParkEn_PEB_09               36
#define     ComSignal_Internal_PEB02_bDernTempIGBT_PEB_02               37
#define     ComSignal_Internal_PEB02_bDernTempCool_PEB_02               38
#define     ComSignal_Internal_PEB02_bDernN_PEB_02               39
#define     ComSignal_Internal_PEB02_TrqAbsMin_PEB_02               40
#define     ComSignal_Internal_PEB02_TrqAbsMax_PEB_02               41
#define     ComSignal_Internal_PEB02_stTrqEmMin_PEB_02               42
#define     ComSignal_Internal_PEB02_stTrqEmMax_PEB_02               43
#define     ComSignal_Internal_PEB02_IdcCurr_PEB_02               44
#define     ComSignal_Internal_PEB02_UT30Curr_PEB_02               45
#define     ComSignal_Internal_PEB02_bReadyHv_PEB_02               46
#define     ComSignal_Internal_PEB02_bDernUndrUdc_PEB_02               47
#define     ComSignal_Internal_PEB02_bDernUndrIdc_PEB_02               48
#define     ComSignal_Internal_PEB02_bDernTrqMin_PEB_02               49
#define     ComSignal_Internal_PEB02_bDernTrqMax_PEB_02               50
#define     ComSignal_Internal_PEB02_bDernStrTemp_PEB_02               51
#define     ComSignal_Internal_PEB02_bDernOvrUdc_PEB_02               52
#define     ComSignal_Internal_PEB02_bDernOvrIdc_PEB_02               53
#define     ComSignal_Internal_PEB02_bDernCAN_PEB_02               54
#define     ComSignal_Internal_PEB05_FailCode8_PEB_05               55
#define     ComSignal_Internal_PEB05_FailCode7_PEB_05               56
#define     ComSignal_Internal_PEB05_FailCode6_PEB_05               57
#define     ComSignal_Internal_PEB05_FailCode5_PEB_05               58
#define     ComSignal_Internal_PEB05_FailCode4_PEB_05               59
#define     ComSignal_Internal_PEB05_FailCode3_PEB_05               60
#define     ComSignal_Internal_PEB05_FailCode2_PEB_05               61
#define     ComSignal_Internal_PEB05_FailCode1_PEB_05               62
#define     ComSignal_Internal_PEB07_MinPredTrq_PEB_07               63
#define     ComSignal_Internal_PEB07_MinDynTrq_PEB_07               64
#define     ComSignal_Internal_PEB07_MaxPredTrq_PEB_07               65
#define     ComSignal_Internal_PEB07_MaxDynTrq_PEB_07               66
#define     ComSignal_Internal_SysBoot_Tx0_SysBoot_Tx               67
#define     ComSignal_Internal_SysBoot_Tx1_SysBoot_Tx               68
#define     ComSignal_Internal_SysBoot_Tx2_SysBoot_Tx               69
#define     ComSignal_Internal_SysBoot_Tx3_SysBoot_Tx               70
#define     ComSignal_Internal_SysBoot_Tx4_SysBoot_Tx               71
#define     ComSignal_Internal_SysBoot_Tx5_SysBoot_Tx               72
#define     ComSignal_Internal_SysBoot_Tx6_SysBoot_Tx               73
#define     ComSignal_Internal_SysBoot_Tx7_SysBoot_Tx               74
#define     ComSignal_Internal_PEB06_HvMcuVer_PEB_06               75
#define     ComSignal_Internal_PEB06_CpldVer_PEB_06               76
#define     ComSignal_Internal_PEB06_DataVer_PEB_06               77
#define     ComSignal_Internal_PEB06_CodeVer_PEB_06               78


/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Rx signal internal symbolic names */

#define     ComSignal_Internal_BMS01_stMainRelay_BMS_01               0
#define     ComSignal_Internal_BMS01_ctRoll_BMS_01               1
#define     ComSignal_Internal_BMS01_Checksum_BMS_01               2
#define     ComSignal_Internal_BMS01_BattVolt_BMS_01               3
#define     ComSignal_Internal_BMS01_BattCurr_BMS_01               4
#define     ComSignal_Internal_SysBoot_Rx0_SysBoot_Rx               5
#define     ComSignal_Internal_SysBoot_Rx1_SysBoot_Rx               6
#define     ComSignal_Internal_SysBoot_Rx2_SysBoot_Rx               7
#define     ComSignal_Internal_SysBoot_Rx3_SysBoot_Rx               8
#define     ComSignal_Internal_SysBoot_Rx4_SysBoot_Rx               9
#define     ComSignal_Internal_SysBoot_Rx5_SysBoot_Rx               10
#define     ComSignal_Internal_SysBoot_Rx6_SysBoot_Rx               11
#define     ComSignal_Internal_SysBoot_Rx7_SysBoot_Rx               12
#define     ComSignal_Internal_Data_Access_TOOL_01               13
#define     ComSignal_Internal_VCU01_ctRoll_VCU_01               14
#define     ComSignal_Internal_VCU01_Checksum_VCU_01               15
#define     ComSignal_Internal_VCU01_stHvbMaiRly_VCU_01               16
#define     ComSignal_Internal_VCU01_UdcMin_VCU_01               17
#define     ComSignal_Internal_VCU01_UdcMax_VCU_01               18
#define     ComSignal_Internal_VCU01_IdcMin_VCU_01               19
#define     ComSignal_Internal_VCU01_IdcMax_VCU_01               20
#define     ComSignal_Internal_VCU02_TrqMinNCtl_VCU_02               21
#define     ComSignal_Internal_VCU02_TrqMaxNCtl_VCU_02               22
#define     ComSignal_Internal_VCU02_NDiffMax_VCU_02               23
#define     ComSignal_Internal_VCU02_KpLowNCtl_VCU_02               24
#define     ComSignal_Internal_VCU02_KpHighNCtl_VCU_02               25
#define     ComSignal_Internal_VCU03_ctRoll_VCU_03               26
#define     ComSignal_Internal_VCU03_Checksum_VCU_03               27
#define     ComSignal_Internal_VCU03_cTrqSlopeMax_VCU_03               28
#define     ComSignal_Internal_VCU03_TrqMin_VCU_03               29
#define     ComSignal_Internal_VCU03_TrqMax_VCU_03               30
#define     ComSignal_Internal_VCU04_MotDir_VCU_04               31
#define     ComSignal_Internal_VCU04_bKL15_VCU_04               32
#define     ComSignal_Internal_VCU04_ctRoll_VCU_04               33
#define     ComSignal_Internal_VCU04_Checksum_VCU_04               34
#define     ComSignal_Internal_VCU04_TrqSetP_VCU_04               35
#define     ComSignal_Internal_VCU04_stModeReq_VCU_04               36
#define     ComSignal_Internal_VCU04_NSetP_VCU_04               37
#define     ComSignal_Internal_VCU05_TrqDmpMax_VCU_05               38
#define     ComSignal_Internal_VCU05_TrqDmpLim_VCU_05               39
#define     ComSignal_Internal_VCU05_stDmpCtlReq_VCU_05               40
#define     ComSignal_Internal_VCU05_kDmp_VCU_05               41
#define     ComSignal_Internal_VCU05_OfsAl_VCU_05               42
#define     ComSignal_Internal_VCU05_bSetOfsAl_VCU_05               43
#define     ComSignal_Internal_VCU06_VehGrad_VCU_06               44
#define     ComSignal_Internal_VCU06_Park_VCU_06               45
#define     ComSignal_Internal_VCU06_stDoor_VCU_06               46
#define     ComSignal_Internal_VCU06_stBreak_VCU_06               47
#define     ComSignal_Internal_VCU06_stBelt_VCU_06               48
#define     ComSignal_Internal_MaskData1_VCU_07_Mask               49


/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Tx signal group internal symbolic names */



/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Rx signal group internal symbolic names */



/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Tx group signal internal symbolic names */



/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Rx group signal internal symbolic names */



/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for mapping IPdu group symbolic names to internal IDs */

/* Currently IPdu group symbolic names are not used in any COM tables.
  Hence it is currently not required to generate Ipdu group internal symbolic names */

/* ------------------------------------------------------------------------ */
/* End section */


#endif /* #ifndef COM_PBCFG_INTERNALID_H */
