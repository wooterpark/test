@echo off
setlocal enabledelayedexpansion

set filepath=%%~dpi
set filepath2=%%~fi
set name=-I"
set name2=" 

for /r %%i in (*.h) do (
     echo %filepath%>>list1-1.txt
)
for /r %%i in (*.c) do (
     echo %filepath%>>list1-1.txt
)
for /f "delims=" %%i in (list1.txt) do (
if not defined %%i set %%i=A&echo %%i>>list1-2.txt)

for /f "delims=" %%i in (list1-2.txt) do (
	set var1=%%i
	echo %name%!var1!%name2%>>list1-3.txt
)
for /f "delims=" %%i in (list1-3.txt) do call set "var=%%var%%%%i"
echo "%var%">>list.txt
)