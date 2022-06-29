@echo off&&setlocal enabledelayedexpansion
E:
cd E:\zzy
md E:\zzy\testReport
::QAC
E:
cd E:\zzy\QAC\src
copy E:\zzy\test\QAC.bat E:\zzy\QAC\src
call QAC.bat
cd E:\zzy\QAC
ren output QACoutput
move E:\zzy\QAC\QACoutput E:\zzy\testReport

::TESSY
C:
cd C:\Program Files\Razorcat\TESSY_4.3\bin
tessyd –-file E:\zzy\Tessy\tessy\tessy.pdbx
tessycmd connect
tessycmd restore-db -target project
tessycmd exec-test E:\zzy\Tessy\tessy\yu.tbs
tessycmd disconnect
E:
cd E:\zzy\Tessy
ren report TESSYreport
move E:\zzy\Tessy\TESSYreport E:\zzy\testReport

::ModelAdvisor
E:
cd E:\zzy\Model
copy E:\zzy\test\modeladvisor.m E:\zzy\Model
copy E:\zzy\test\SelectedTask.mat E:\zzy\Model
start /wait matlab -nodesktop -nosplash -minimize -wait -r "modeladvisor([{'\TCF\SWC_TCF.slx'};{'\ADM\SWC_ADM.slx'};{'\FRP\SWC_FRP.slx'}]);exit" -logfile unittestlog.txt set output=%errorlevel% MORE unittestlog.txt EXIT %output%
ren report MA_report
move E:\zzy\Model\MA_report E:\zzy\testReport

::unittest_1     unittest_2
::前提是MILtest_1.m已运行生成了对应的testcase
E:
cd E:\zzy\Model
copy E:\zzy\test\MILtest_2.m E:\zzy\Model
start /wait matlab -nodesktop -nosplash -minimize -wait -r "MILtest_2([{'\TCF\SWC_TCF.slx'}]);exit" -logfile unittestlog.txt set output=%errorlevel% MORE unittestlog.txt EXIT %output%
move E:\zzy\Model\UnitTest E:\zzy\testReport

::CodeGene
E:
cd E:\zzy\Model
copy E:\zzy\test\CodeGene.m E:\zzy\Model
start /wait matlab -nodesktop -nosplash -minimize -wait -r "CodeGene([{'\TCF\SWC_TCF.slx'};{'\ADM\SWC_ADM.slx'};{'\FRP\SWC_FRP.slx'}]);exit" -logfile unittestlog.txt set output=%errorlevel% MORE unittestlog.txt EXIT %output%
ren output CodeGene_output
move E:\zzy\Model\CodeGene_output E:\zzy\testReport

::Hightec
E:
cd E:\zzy\FS_PEB
copy E:\zzy\test\Hightec.bat E:\zzy\FS_PEB
call Hightec.bat
cd E:\zzy\FS_PEB
del Hightec.bat
move E:\zzy\FS_PEB\ROM E:\zzy\testReport
