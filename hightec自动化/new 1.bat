@echo off
setlocal enabledelayedexpansion
set name9=G:/zzy/doc/Hightec/FS_PEB_0224/ROM/
for /f "delims=" %%i in (ROM.objectlist) do (
	set var7=%%i
	echo	!var7!
	echo	%name9%
	echo %name9%!var7!>>ROM2.objectlist
)