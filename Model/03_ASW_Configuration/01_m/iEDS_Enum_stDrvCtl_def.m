classdef iEDS_Enum_stDrvCtl_def < Simulink.IntEnumType
    enumeration
        Drv_Initial  (0)
        Drv_MocSop     (1)
        Drv_SensCalFW (2)
        Drv_Standby  (3)
        Drv_Run  (4)
        Drv_OffsetAcc     (5)
        Drv_OffsetFw (6)
        Drv_Discharge  (7)
        Drv_Failure  (8)
        Drv_TrqCtl (9)
        Drv_nCtlExt (10)
        Drv_inActive (11)
        Drv_nCtlInt  (12)
        Drv_IsCtl  (13)
        Drv_UdcCtl  (14)
        Drv_UdcBatCtl  (15)
        Drv_FrWCtl  (16)
        Drv_IdLe   (17)
        Drv_TestBench (18)
        Drv_OffsetCal(19)
    end
end