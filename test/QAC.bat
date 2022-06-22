@echo off
setlocal enabledelayedexpansion
set filepath2=%%~dpi
cd C:\PRQA\QAC-8.1.2-R\projects\examples\src
::需修改
for /r %%i in (*.c) do (
	echo %filepath2%>>list_c.txt
for /f "delims=" %%i in (list_c.txt) do (
	set var=%%i
	cd C:\PRQA\QAC-8.1.2-R\bin
	qac.exe -via C:\PRQA\QAC-8.1.2-R\projects\examples\examples.via -op C:\PRQA\QAC-8.1.2-R\projects\examples\output !%%i!
	::需修改
)