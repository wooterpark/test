@echo off
setlocal enabledelayedexpansion
E:
cd E:\zzy\QAC\src
set filepath2=%cd%
::需修改
dir /s/b %filepath2%\*.c >>list_c.txt
for /f "delims=" %%i in (list_c.txt) do (
	set var=%%i
	C:
	cd C:\PRQA\QAC-8.1.2-R\bin
	qac.exe -via E:\zzy\QAC\examples.via -op E:\zzy\QAC\output !%%i!
)
E:
cd E:\zzy\QAC\src
del list_c.txt