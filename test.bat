REM copy C:\Users\zhaozhongyi\Desktop\zzy\modeladvisor.m C:\A\Model\
REM copy C:\Users\zhaozhongyi\Desktop\zzy\CodeGene.m C:\A\Model\
REM copy C:\Users\zhaozhongyi\Desktop\zzy\SelectedTask.mat C:\A\Model\
REM cd C:\A\Model
REM start /wait matlab -nodesktop -nosplash -minimize -wait -r "modeladvisor([{'\STM\SWC_STM.slx'};{'\SWD\SWC_SWD.slx'}]);exit" -logfile unittestlog.txt set output=%errorlevel% MORE unittestlog.txt EXIT %output%
REM start /wait matlab -nodesktop -nosplash -minimize -wait -r "CodeGene([{'\STM\SWC_STM.slx'};{'\SWD\SWC_SWD.slx'}]);exit" -logfile unittestlog.txt set output=%errorlevel% MORE unittestlog.txt EXIT %output%

copy C:\Users\zhaozhongyi\Desktop\zzy\Hightec.bat C:\A\FS_PEB\
cd C:\A\FS_PEB
call C:\A\FS_PEB\Hightec.bat