%Modified at 20171116, Read TRUE and FALSE from EXCEL
clc
clear
close all
dictionaryName = 'SWC_STM_DataDictionary.sldd';
if exist(dictionaryName)
    delete(dictionaryName);
end
dictionaryObj = Simulink.data.dictionary.create(dictionaryName);
GLB_Parameter;
Sin_Table;
%motorParameterTable;%%load the huge table data from M file
% ----------------------------------Signal_Config START_Line----------------------------------
%read signal sheet
[num,str,signal_str] = xlsread( 'SWC_STM_DataDictionary', 'Signal') ;
signal_name = signal_str(2:end,2);
signal_row = signal_str(2:end,3);
signal_column = signal_str(2:end,4);
signal_description = signal_str(2:end,12);
signal_min = signal_str(2:end,5);
signal_max = signal_str(2:end,6);
signal_InitialValue = signal_str(2:end,7);
signal_unit = signal_str(2:end,8);
signal_datatype = signal_str(2:end,9);
signal_csc = signal_str(2:end,10);
signal_complexity = signal_str(2:end,11);
sig_num = size(signal_str ,1)-1;
for ii = 1: sig_num
    if(isnan(signal_name{ii}))
        continue;
    else
        eval([signal_name{ii},'= ASAP2.Signal;']);
    end
    if(isnan(signal_row{ii}) || isnan(signal_column{ii}))
        eval([signal_name{ii},'.Dimensions = -1;']);
    else
        eval([signal_name{ii},'.Dimensions = ','[',num2str(signal_row{ii}),' ',num2str(signal_column{ii}),']',';']);
    end
    if(isnan(signal_description{ii}))
        eval([signal_name{ii},'.Description ='''';']);
    else
        eval([signal_name{ii},'.Description = ''',signal_description{ii},''';']);
    end
    if(isnan(signal_min{ii}))
        eval([signal_name{ii},'.Min =[ ];']);
    else
        eval([signal_name{ii},'.Min =',num2str(signal_min{ii}),';']);
    end
    if(isnan(signal_max{ii}))
        eval([signal_name{ii},'.Max =[ ];']);
    else
        eval([signal_name{ii},'.Max =',num2str(signal_max{ii}),';']);
    end
    if(isnan(signal_InitialValue{ii}))
        eval([signal_name{ii},'.InitialValue = '''';']);
    else
        eval([signal_name{ii},'.InitialValue = ''',num2str(signal_InitialValue{ii}),''';']);
    end
    if(isnan(signal_unit{ii}))
        eval([signal_name{ii},'.DocUnits ='''';']);
    else
        eval([signal_name{ii},'.DocUnits =''',signal_unit{ii},''';']);
    end
    eval([signal_name{ii},'.DataType =''',signal_datatype{ii},''';']);
    eval([signal_name{ii},'.CoderInfo.StorageClass= ''' , signal_csc{ii},''';']);
    eval([signal_name{ii},'.Complexity = ''' , signal_complexity{ii},''';']);
    importFromBaseWorkspace(dictionaryObj,'varList',{signal_name{ii}});
end
% ----------------------------------Signal_Config END_Line----------------------------------

% ----------------------------------Parameter_Config Start_Line----------------------------------
%read parameter sheet
[num,str,parameter_str] = xlsread( 'SWC_STM_DataDictionary','Parameter') ;
parameter_name = parameter_str(2:end,2);
parameter_description = parameter_str(2:end,7);
parameter_min  = parameter_str(2:end,4);
parameter_max  = parameter_str(2:end,5);
parameter_Value = parameter_str(2:end,3);
parameter_units = parameter_str(2:end,7);
parameter_datatypes = parameter_str(2:end,6);
parameter_csc = parameter_str(2:end,8);
parameter_headfile = parameter_str(2:end,10);
% parameter_Complexity = parameter_str(2:end,12);
%get num of paraeters
parameter_num = size(parameter_str ,1)-1;
%create signal object
for ii = 1: parameter_num
    if(isnan(parameter_name{ii}))
        continue;
    else
        if(parameter_name{ii} == logical(0))
            parameter_name{ii} = 'FALSE';
        elseif(parameter_name{ii} == logical(1))
            parameter_name{ii} = 'TRUE';
        end
            eval([parameter_name{ii},'= iEDS_Parameter.Parameter;']);
    end
    if(isnan(parameter_description{ii}))
        eval([parameter_name{ii},'.Description ='''';']); 
    else
        eval([parameter_name{ii},'.Description = ''',parameter_description{ii},''';']); 
    end
    if(isnan(parameter_min{ii}))
        eval([parameter_name{ii},'.Min =[ ];']);
    else
        eval([parameter_name{ii},'.Min =',num2str(parameter_min{ii}),';']);
    end
     if(isnan(parameter_max{ii}))
        eval([parameter_name{ii},'.Max =[ ];']);
     else
        eval([parameter_name{ii},'.Max =',num2str(parameter_max{ii}),';']);
     end
    eval([parameter_name{ii},'.Value = ',num2str(parameter_Value{ii}),';']);
    if(isnan(parameter_units{ii}))
        eval([parameter_name{ii},'.DocUnits ='''';']);
    else
        eval([parameter_name{ii},'.DocUnits =''',parameter_units{ii},''';']);
    end
    eval([parameter_name{ii},'.DataType =''',parameter_datatypes{ii},''';']);
    if(strcmp(parameter_csc{ii},'Auto')||strcmp(parameter_csc{ii},'SimulinkGlobal')||strcmp(parameter_csc{ii},'ExportedGlobal')||strcmp(parameter_csc{ii},'ImportedExtern')||strcmp(parameter_csc{ii},'ImportedExterenPoint'))
        eval([parameter_name{ii},'.CoderInfo.StorageClass= ''' , parameter_csc{ii},''';']);
    else
        eval([parameter_name{ii},'.CoderInfo.StorageClass= ''Custom'';']);
        eval([parameter_name{ii},'.CoderInfo.CustomStorageClass= ''' , parameter_csc{ii},''';']);
        %eval([parameter_name{ii},'.CoderInfo.CustomAttributes.HeaderFile= ''' , parameter_headfile{ii},''';']);
        %eval([parameter_name{ii},'.CoderInfo.StorageClass= ''' , parameter_csc{ii},' (Custom)'';']);
    end
    importFromBaseWorkspace(dictionaryObj,'varList',{parameter_name{ii}});
end
% ----------------------------------data type replacement Start_Line----------------------------------
%read simulik sheet
[num,str,AliasType_str] = xlsread( 'SWC_STM_DataDictionary','BaseType') ;
AliasType_name = AliasType_str(2:end,1);
AliasType_datatypes = AliasType_str(2:end,5);
AliasType_csc = AliasType_str(2:end,7);
AliasType_num = size(AliasType_str ,1)-1;
for ii = 1: AliasType_num
   if(isnan(AliasType_name{ii}))
        continue;
   else
        if(AliasType_name{ii} == logical(0))
            AliasType_name{ii} = 'FALSE';
        elseif(AliasType_name{ii} == logical(1))
            AliasType_name{ii} = 'TRUE';
        end
            eval([AliasType_name{ii},'=Simulink.AliasType;']);
    end
   eval([AliasType_name{ii},'.BaseType =''',AliasType_datatypes{ii},''';']);
%     if(strcmp(AliasType_csc{ii},'Auto')||strcmp(AliasType_csc{ii},'SimulinkGlobal'))
%         eval([AliasType_name{ii},'.CoderInfo.StorageClass= ''' , AliasType_csc{ii},''';']);
%     else
%         eval([AliasType_name{ii},'.CoderInfo.StorageClass= ''Custom'';']);
%         eval([AliasType_name{ii},'.CoderInfo.CustomStorageClass= ''' , AliasType_csc{ii},''';']);
%     end
    importFromBaseWorkspace(dictionaryObj,'varList',{AliasType_name{ii}});
end
dictionaryObj.saveChanges
dictionaryObj.close;
%clear