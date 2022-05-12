@echo off&&setlocal enabledelayedexpansion
set filepath=%%~dpi
set filepath2=%%~fi
for /r %%i in (*.o) do (
	 echo %filepath2% >>list_c.txt
)
for /r %%i in (*.h) do (
	 echo %filepath2% >>list_c.txt
)
for /f "delims=*" %%i in (list_c.txt) do (
	set var3=%%i
	rd /!var3!
	del !var3!
)