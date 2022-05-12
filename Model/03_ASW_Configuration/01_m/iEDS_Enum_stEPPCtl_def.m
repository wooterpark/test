classdef iEDS_Enum_stEPPCtl_def < Simulink.IntEnumType
    enumeration
        PcfStm_Halt (0)
        PcfStm_Normal (1)
        PcfStm_Stall (2)
        PcfStm_Selflearn (3)
        PcfStm_Blind (4)
    end
end