@echo off&&setlocal enabledelayedexpansion
E:
cd E:\zzy
md E:\zzy\testReport
md E:\zzy\testReport\QACoutput
md E:\zzy\testReport\TESSYreport

::QAC
C:
cd C:\PRQA\QAC-8.1.2-R\projects\examples\src
copy E:\zzy\QAC\src\*.c C:\PRQA\QAC-8.1.2-R\projects\examples\src
copy E:\zzy\test\QAC.bat C:\PRQA\QAC-8.1.2-R\projects\examples\src
call QAC.bat
xcopy C:\PRQA\QAC-8.1.2-R\projects\examples\output E:\zzy\testReport\QACoutput /S /E /Y
rd /s/q C:\PRQA\QAC-8.1.2-R\projects\examples\output
cd C:\PRQA\QAC-8.1.2-R\projects\examples\src
del QAC.bat

::TESSY
C:
cd C:\Program Files\Razorcat\TESSY_4.3\bin
tessyd –-file E:\zzy\Tessy\tessy\tessy.pdbx
tessycmd connect
tessycmd restore-db -target project
tessycmd exec-test E:\zzy\Tessy\tessy\yu.tbs
tessycmd disconnect
xcopy C:\Users\yusenlin\Projects\TESSY\yu\report E:\zzy\testReport\TESSYreport
cd C:\Users\yusenlin\Projects\TESSY\yu\report
del /q *.*

::ModelAdvisor
E:
cd E:\zzy\Model
copy E:\zzy\test\modeladvisor.m E:\zzy\Model
copy E:\zzy\test\SelectedTask.mat E:\zzy\Model
start /wait matlab -nodesktop -nosplash -minimize -wait -r "modeladvisor([{'\TCF\SWC_TCF.slx'};{'\ADM\SWC_ADM.slx'};{'\FRP\SWC_FRP.slx'}]);exit" -logfile unittestlog.txt set output=%errorlevel% MORE unittestlog.txt EXIT %output%
ren report MA_report
del modeladvisor.m
del SelectedTask.mat
move E:\zzy\Model\MA_report E:\zzy\testReport

::unittest_1     unittest_2
::前提是MILtest_1.m已运行生成了对应的testcase
E:
cd E:\zzy\Model
copy E:\zzy\test\MILtest_2.m E:\zzy\Model
start /wait matlab -nodesktop -nosplash -minimize -wait -r "MILtest_2([{'\TCF\SWC_TCF.slx'}]);exit" -logfile unittestlog.txt set output=%errorlevel% MORE unittestlog.txt EXIT %output%
move E:\zzy\Model\UnitTest E:\zzy\testReport
del MILtest_2.m

::CodeGene
E:
cd E:\zzy\Model
copy E:\zzy\test\CodeGene.m E:\zzy\Model
start /wait matlab -nodesktop -nosplash -minimize -wait -r "CodeGene([{'\TCF\SWC_TCF.slx'};{'\ADM\SWC_ADM.slx'};{'\FRP\SWC_FRP.slx'}]);exit" -logfile unittestlog.txt set output=%errorlevel% MORE unittestlog.txt EXIT %output%
ren output CodeGene_output
move E:\zzy\Model\CodeGene_output E:\zzy\testReport
del CodeGene.m
del log.txt
del unittestlog.txt

::Hightec
E:
cd E:\zzy\FS_PEB
copy E:\zzy\test\Hightec.bat E:\zzy\FS_PEB
call Hightec.bat
cd E:\zzy\FS_PEB
del Hightec.bat
move E:\zzy\FS_PEB\ROM E:\zzy\testReport
