@echo off
setlocal enabledelayedexpansion

::设置路径区（不同路径须修改）
set name7=G:/zzy/doc/Hightec/FS_PEB_0224/ROM/
::ROM.objectlist原.o文件路径，到rom为止

set name10=G:\zzy\FS_PEB
::设置工程所在路径

set var6=%cd%
set "var6=!var6:G:\zzy\FS_PEB=G:\zzy\FS_PEB\ROM\!"
::工程所在路径添加ROM路径



::设置参数区（一般不需要修改）
set filepath=%%~dpi
set filepath2=%%~fi
set name1=%%.o: 
set name2=%%.c
set name3="^$^(TRICORE_TOOLS)/bin/tricore-gcc" -c 
set name4= -fno-common -O0 -W -Wall -Wcast-qual -Wcast-align -Wnested-externs -Wno-unused-parameter -Wno-return-type -Wno-pointer-to-int-cast -Wfloat-equal -Winline -Wstrict-prototypes -Wmissing-prototypes -Wmissing-noreturn -Wredundant-decls -Wundef -Wpointer-arith -Wbad-function-cast -D_GNU_C_TRICORE_=1 -O2 -gdwarf-2 -fno-builtin -mpragma-data-sections -mcpu=tc27xx -fdata-sections -ffunction-sections -maligned-data-sections -MMD -M222P -MF"^$^(@:%%.o=%%.d)" -MT"^$^(@:%%.o=%%.d)" -o "^$^@" "^$^<^"
set name5=-I"
set name6="

::获取mk里长字符串链接
::for /r %%i in (*.h) do (
::     echo %filepath%>>list_c_h.txt
::)
::for /r %%i in (*.c) do (
::     echo %filepath%>>list_c_h.txt
::)
::for /f "delims=" %%i in (list_c_h.txt) do (
::if not defined %%i set %%i=B&echo %%i>>list_Delete_duplicate.txt)
::
::for /f "delims=" %%i in (list_Delete_duplicate.txt) do (
::	set var1=%%i
::	echo %name5%!var1!%name6%>>list_Splicing.txt
::)
::for /f "delims=" %%i in (list_Splicing.txt) do call set "var=%%var%%%%i"
::echo !var!>>list_one_line.txt
::)

::获取.c并生成mk

for /r %%i in (*.c) do (
	for %%j in (list_excluding_c.txt) do (type %%i |find "%%i">nul && set active=1)
	if active==1	(
	break)
	 echo %filepath2% >>list_c.txt
     echo %filepath%>>list_c_route.txt
)