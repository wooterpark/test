@echo off&&setlocal enabledelayedexpansion
::QAC
cd C:\PRQA\QAC-8.1.2-R\projects\examples\src
copy C:\A\test\QAC.bat C:\PRQA\QAC-8.1.2-R\projects\examples\src
call QAC.bat

cd C:\Program Files\Razorcat\TESSY_4.3\bin
tessyd –-file C:\Users\yusenlin\Projects\TESSY\yu\tessy\tessy.pdbx
tessycmd connect
tessycmd restore-db -target project
tessycmd exec-test C:\Users\yusenlin\Projects\TESSY\yu\tessy\yu.tbs
tessycmd disconnect

::ModelAdvisor
cd C:\A\Model
copy C:\A\test\modeladvisor.m C:\A\Model
copy C:\A\test\SelectedTask.mat C:\A\Model
start /wait matlab -nodesktop -nosplash -minimize -wait -r "modeladvisor([{'\TCF\SWC_TCF.slx'}]);exit" -logfile unittestlog.txt set output=%errorlevel% MORE unittestlog.txt EXIT %output%

::unittest_1     unittest_2
::前提是MILtest_1.m已运行生成了对应的testcase
cd C:\A\Model
copy C:\A\test\MILtest_2.m C:\A\Model
start /wait matlab -nodesktop -nosplash -minimize -wait -r "MILtest_2([{'\TCF\SWC_TCF.slx'}]);exit" -logfile unittestlog.txt set output=%errorlevel% MORE unittestlog.txt EXIT %output%

::CodeGene
cd C:\A\Model
copy C:\A\test\CodeGene.m C:\A\Model
start /wait matlab -nodesktop -nosplash -minimize -wait -r "CodeGene([{'\TCF\SWC_TCF.slx'}]);exit" -logfile unittestlog.txt set output=%errorlevel% MORE unittestlog.txt EXIT %output%

::Hightec
cd C:\A\FS_PEB
copy C:\A\test\Hightec.bat C:\A\FS_PEB
call Hightec.bat
