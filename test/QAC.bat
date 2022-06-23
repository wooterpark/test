@echo off
setlocal enabledelayedexpansion
cd C:\PRQA\QAC-8.1.2-R\projects\examples\src
set filepath2=%cd%
::需修改
dir /s/b %filepath2%\*.c >>list_c.txt
for /f "delims=" %%i in (list_c.txt) do (
	set var=%%i
	cd C:\PRQA\QAC-8.1.2-R\bin
	qac.exe -via C:\PRQA\QAC-8.1.2-R\projects\examples\examples.via -op C:\PRQA\QAC-8.1.2-R\projects\examples\output !%%i!
)
cd C:\PRQA\QAC-8.1.2-R\projects\examples\src
del list_c.txt