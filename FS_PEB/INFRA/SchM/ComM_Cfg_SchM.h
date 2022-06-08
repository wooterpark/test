


#ifndef COMM_CFG_SCHM_H
#define COMM_CFG_SCHM_H

#include "SchM.h"
#include "SchM_Default.h"
//#include "rba_BswSrv.h"

/* If the RTE code generation is Involved please include the below file */
//#include "SchM_ComM.h"

/* The integrator shall implement the particular services SchM_Enter and SchM_Exit */

/* Since there is currently only one resource used, there is no need to consider the resource name */

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_UserNoNest(void);
LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_UserNoNest(void);

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_ChannelNoNest(void);
LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_ChannelNoNest(void);

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_EIRANoNest(void);
LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_EIRANoNest(void);

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_ERANoNest(void);
LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_ERANoNest(void);

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_PNCNoNest(void);
LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_PNCNoNest(void);

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_PNC1NoNest(void);
LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_PNC1NoNest(void);

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_LimitationNoNest(void);
LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_LimitationNoNest(void);

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_Channel(void);
LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_Channel(void);

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_PNCNoNest(void)
{
    /* This lock is to protect channel parameter,if multiple PNC's are mapped to at least one channel.
     The following resource is protected by this lock:
     ComM_PncRamStructType[].PncRequestCtr_u8
     
       Enable this lock, if 
     1. A channel is associated with multiple PNC's and
     2. PNC main functions can run concurrently  */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_PNCNoNest(void)
{
    SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_EIRANoNest(void)
{
    /* This lock is to protect PNC parameter,if a PNC has multiple EIRA signals configured.
     The following resource is protected by this lock:
     ComM_PncRamStructType[].EIRACnt_u8
     
      Enable this lock only if 
     1. Multiple bus types are configured in ComM and
     2. All the used <Bus>Nm's main functions can run concurrently */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_EIRANoNest(void)
{
    SCHM_EXIT_DEFAULT();
}

/* EIRA signal is per bus type and ERA signal is per channel.
   Currently, all the CUBAS Nm's don't support multiple <Bus>Nm main functions which can 
   be scheduled independently. Hence the scope of ERANoNest lock is limited to <Bus>Nm's main functions 
   running concurrently. If any of the <Bus>Nm's support main functions which can scheduled independently, 
   then the scope of this lock has to be changed to multiple channels running concurrently */
   
LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_ERANoNest(void)
{
    /* This lock is to protect PNC parameters, if a PNC has multiple ERA signals configured.
     The following resource is protected by this lock:
     ComM_PncRamStructType[].ERACnt_u8
    
      Enable this lock only if 
     1. Multiple bus types are configured in ComM and
     2. All the used <Bus>Nm's main functions can run concurrently  */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_ERANoNest(void)
{
    SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_PNC1NoNest(void)
{
    /* This lock is to protect PNC related parameters if COMM_SYNCHRONOUS_WAKE_UP == STD_ON.
     This lock protects the following resources:
     ComM_PncRamStructType[].WakeUpStatus_b
     
     In addition, it also ensures that ComM_PncRamStructType[].WakeUpStatus_b and 
     ComM_PncRamStructType[].PncState_e consistently.
     
      Enable this lock only if 
     1. COMM_SYNCHRONOUS_WAKE_UP == STD_ON and
     2. PNC main function and ComM_EcuM_WakeUpIndication can run concurrently */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_PNC1NoNest(void)
{
    SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_UserNoNest(void)
{
   /* This lock is to protect channel parameter, if there are multiple users assigned to a channel or
      multiple users assigned to a PNC.
      This lock protects the following resources:
      ComM_ChannelVarType[].UserRequestCtr_u8 and 
      ComM_PncRamStructType[].UserRequestCnt_u8
    
    Enable this lock only if 
    1. multiple users are configured in ComM and
    2. User requests can run concurrently */    
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_UserNoNest(void)
{
    SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_ChannelNoNest(void)
{
    /* This lock is to protect the channel related parameters. 
     This lock protects the following resources:
     ComM_ChannelVarType[].NmBusSleepIndicationStatus_b
     ComM_ChannelVarType[].NmPrepareBusSleepIndicationStatus_b
     ComM_ChannelVarType[].NmNetworkModeStatus_b
     ComM_ChannelVarType[].PassiveRequestState_u8
     
     In addition,it also ensures that all the above parameters and 
     ComM_ChannelVarType[].ChannelMode_u8 are updated consistently.
         
       Enable this lock if ComM_EcuM_WakeUpIndication, Nm call backs and ComM
     channel main function can run concurrently. */    
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_ChannelNoNest(void)
{
    SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_LimitationNoNest(void)
{
  /* This lock is to protect, inhibition related parameters:
     This lock protects the following resources:
     ComM_ChannelVarType[].InhibitionReqStatus_u8
     ComM_PncRamStructType[].WakeUpInhibitionCtr_u16
     ComM_PncRamStructType[].LimitToNoComCtr_u16
     ComM_UserVarType[].LimitToNoComCtr_u16
     ComM_UserVarType[].WakeUpInhibitionCtr_u16

     Enable this lock if
     Either of ComMModeLimitationEnabled or ComMWakeupInhibitionEnabled is configured as TRUE and
     If the api's ComM_LimitChannelToNoComMode(), ComM_LimitECUToNoComMode() and ComM_PreventWakeUp()
     can interrupt each other or themselves.
     */
    SCHM_ENTER_DEFAULT();
}
LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_LimitationNoNest(void)
{
    SCHM_EXIT_DEFAULT();
}
LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Enter_ComM_Channel(void)
{
    /* This lock is to protect channel mode counters for users.
     * Following resources are protected by this lock:
     * userRamPtr_ps->numChannelsInNoCom_u8
     * userRamPtr_ps->numChannelsInFullCom_u8
     * userRamPtr_ps->numChannelsInSilentCom_u8
     *
     *
     * Enable this lock if
     * 1. Channel main functions can interrupt each other and
     * 2. If there are common users accross channels
     *
     * Configure this lock as Common lock if,
     * 1. ComMRteEnabled is configured as True and
     * 2. Sender receiver interface ComM_CurrentMode is used
     *
     * otherwise
     *
     * This lock can be configured as a NoNest lock
     */
    SCHM_ENTER_DEFAULT();
}
LOCAL_INLINE FUNC(void, COMM_CODE) SchM_Exit_ComM_Channel(void)
{
    SCHM_EXIT_DEFAULT();
}
#endif /* _COMM_CFG_SCHM_H */


/*<BASDKey>
*********************************************************************************************************
* $History___:
* 
* AR40.17.1.0; 0     15.05.2015 BSH4KOR
*   CSCRM00874858;CSCRM00857403
* 
* AR40.17.0.0; 0     08.04.2015 BSH4KOR
*   CSCRM00824220;CSCRM00788949;CSCRM00835835;CSCRM00797954;CSCRM00823949;CSCRM0
*   0774569;CSCRM00797886;CSCRM00813329;CSCRM00793370
* 
* AR40.16.2.0; 0     13.03.2015 BSH4KOR
*   CSCRM00707991    [ComM 4.0] Pnc issue
*   CSCRM00754309    [ComM 4.0] PN Statemachine redesign
*   CSCRM00788987    [ComStd] [ComM] Porting of all the changes from AR40.16.0.1 to
*    AR40.16.2.0
*   CSCRM00782942    [COM - COMM 40] serialization after preperae action
* 
* AR40.15.2.0; 0     02.12.2014 BSH4KOR
*   CSCRM00676737    [ComM] Support NmVariant=PASSIVE
*   CSCRM00719790    [ComStd Ar40] xxxSm shall not call ComM_BusSM_ModeIndication 
*   during init.
*   CSCRM00708619    [ComM 40] : Redesign of channel state machine
*   CSCRM00733715    [ComM 40] : Redesign of channel state machine
* 
* AR40.14.0.0; 0     01.07.2014 KHS4KOR
*   CSCRM00668774    [ComM AR40]Update OAW scripts to generate correct 
*   configuration within BSWMD file for calibration and measurement data in A2L
*   CSCRM00670185    [ComM AR40] Api ComM_LimitChannelToNoComMode never returns 
*   E_OK
*   CSCRM00682238    [ComStd][ComM] EIRA call back to be made optional
*   CSCRM00687761    [ComM 40]: Static BSWMD file should be provided in tools 
*   folder instead of as template
*   CSCRM00672759    [ComStd]EcuCValues of ComStd development project shall be use 
*   the correct structure according the Coding Guidelines
*   CSCRM00641079    [ComStd 4.0]: Compatibility check for Multiple configurations 
*   in ESB1 project
*   CSCRM00679941    [ComSrv] activation of PlausibilityCheck "BCT Error"
*   CSCRM00679939    [ComSrv] CDG-SMT identification in BAMF
*   CSCRM00679943    [ComSrv Ar40] ARXML files must using the correct encoding.
*   CSCRM00673977    Integration of COMASSO contributed sources(Q2'2014) - having 
*   Hex neutral changes to upcoming CUBAS release_2014.7
*   CSCRM00684184    EcuCValues change short names according to CodingGuidelines
* 
* AR40.10.0.0; 0     26.12.2013 KHS4KOR
*   CSCRM00610318    [ComStd] Remove classification rules from CLF files
*   CSCRM00610949    [ComStd] Double registration of <comp>_Cfg_BSWMD.arxml files
*   CSCRM00594518    [ComM]Update and extend content of _fs.XML documentation of 
*   ComStd components
*   CSCRM00591984    [ComM 4.0] ComM should set the value 1 for the bit 
*   representing PNC which is been requested but not for all PNCs of the channel
*   CSCRM00600642    [ComM] Multi-Core Support
* 
* AR40.7.0.0; 1     25.03.2013 KHS4KOR
*   CSCRM00503699 [ComStd 4.0] Doxygen based API documentation.
*   CSCRM00513873 [ComStd] : provide comstd bug fix for freecubas team in 
*   AR40.7.0.0 package.
*   CSCRM00514078 Fix the defect CSCRM00514007
*   CSCRM00511505 [COMM40] Support multiple EIRA signals for PNC and 
*   Implementation of ComM959
*   CSCRM00502731 [COMM40] Support multiple EIRA signals for PNC and 
*   Implementation of ComM959
*   CSCRM00492395 [ComStd AR40]Update OAW scripts due to discontinuation of 
*   CUBEC compatiblity support
* 
* AR40.7.0.0; 0     01.03.2013 BIJ4KOR
*   
* 
* $
*********************************************************************************************************
</BASDKey>*/
