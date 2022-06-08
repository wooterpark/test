///*
// **********************************************************************************************************************
// *
// * COPYRIGHT RESERVED, 2018 Robert Bosch GmbH. All rights reserved.
// * The reproduction, distribution and utilization of this document as well as the communication of its contents to
// * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
// * All rights reserved in the event of the grant of a patent, utility model or design.
// *
// **********************************************************************************************************************
// */
///*<VersionHead>
// * This File is generated using BCT Tool (automatically filled in) as listed below.
// *
// * $Generator__: rba_ComScl / AR40.21.0.0	Module Package Version
// * $Editor_____: ECU.WorX_2018.1.0 		Tool Version
// * $Model______: 1.0.0.0 					ECU Parameter Definition Version
// *
// </VersionHead>
// */
///*
// **********************************************************************************************************************
// * Includes
// **********************************************************************************************************************
// */
//#include "Dem.h"
//#include "CanIf.h"
//#include "ComStack_Flags.h"
//
///*
// **********************************************************************************************************************
// * Callback for DLC error notification
// **********************************************************************************************************************
// */
//CanIf_DlcErrorReturnType ComAppl_DlcErrorNotification(PduIdType CanRxPduId, uint8 CanDlc)
//{
//    CanIf_DlcErrorReturnType returnValue;
//    returnValue = CANIF_DLC_OK;
//    (void) CanDlc;
//
//    switch (CanRxPduId)
//    {
//        /******************************************************************************/
//        case CanIfConf_CanIfRxPduCfg_Can_Network_CANNODE_0_VCU_DC01: /* BMS_VCU_INV_01 */
//        {
//            /* Report 'Dlc error'. */
//            Dem_ReportErrorStatus(DemConf_DemEventParameter_Event_VCU_DC01_DLC,DEM_EVENT_STATUS_PREFAILED);
//            /* Set DLC error, DLCErrNoTO and RxOnceUnEval flag for the PDU */
//            ComStack_SetBit(ComStack_RxPduFlags_au8[ComConf_ComIPdu_VCU_DC01_Can_Network_CANNODE_0], (ComStack_Flag_DLC | ComStack_Flag_RxOnceUnEval | ComStack_Flag_DLCErrNoTO));
//            returnValue = CANIF_DLC_E_FAILED;
//            break;
//        }
//
//            /******************************************************************************/
//        default:
//        {
//            returnValue = CANIF_DLC_OK;
//            break;
//        }
//    }
//
//
//    return returnValue;
//}
