@echo on
setlocal enabledelayedexpansion
E:
cd E:\zzy\QAC
md E:\zzy\QAC\output
cd E:\zzy\QAC\src
set filepath2=%cd%
::需修改
dir /s/b %filepath2%\*.c >>list_c.txt
for /f "delims=" %%i in (list_c.txt) do (
	set var=%%i
	cd E:\zzy\QAC\bin
	qac.exe -via E:\zzy\QAC\examples.via -op E:\zzy\QAC\output !%%i!
)
E:
cd E:\zzy\QAC\src
del list_c.txt