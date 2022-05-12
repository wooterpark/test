set MATLAB=D:\Program Files\Polyspace\R2020a

cd .

if "%1"=="" ("D:\PROGRA~1\POLYSP~1\R2020a\bin\win64\gmake"  -f SWC_STM.mk all) else ("D:\PROGRA~1\POLYSP~1\R2020a\bin\win64\gmake"  -f SWC_STM.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
