@echo off&&setlocal enabledelayedexpansion
set filepath=%%~dpi
set filepath2=%%~fi
for /r %%i in (*.c) do (
     echo %filepath2% >>list0.txt
     echo %filepath% >>list1.txt
)
for /f "delims=" %%i in (list1.txt) do (
if not defined %%i set %%i=A & echo %%i>>list2.txt)

for /f "delims=" %%i in (list2.txt) do (
       set var3=%%i 
       set "var3=!var3:5=5\ROM!"
	   ::5路径最后一个>修改ROM
	   echo !var3!>>list3.txt
   )
for /f "tokens=*" %%i in (list3.txt) do (
     set var4=%%i 
     md !var4!
     set "var5=!var4:5\ROM=5!"
	 ::修改ROM>5路径最后一个
	 copy !var5! !var4!/y
)