@echo off&&setlocal enabledelayedexpansion
set filepath=%%~dpi
set filepath2=%%~fi
for /r %%i in (*.mk) do (
	 set var=%%i
	 echo !var!>>list.txt
	 sed -i.bak ' /^line6/,/^line7/,s/^.\{1\}/&TRICORE_TOOLS=C:\HIGHTEC\toolchains\tricore\v4.6.6.1 !var!
)

