@echo off
setlocal enabledelayedexpansion

set filepath=%%~dpi
set filepath2=%%~fi
set name=%%.o: 
set name2=%%.c
set name3="^$^(TRICORE_TOOLS)/bin/tricore-gcc" -c 
set name4= -fno-common -O0 -W -Wall -Wcast-qual -Wcast-align -Wnested-externs -Wno-unused-parameter -Wno-return-type -Wno-pointer-to-int-cast -Wfloat-equal -Winline -Wstrict-prototypes -Wmissing-prototypes -Wmissing-noreturn -Wredundant-decls -Wundef -Wpointer-arith -Wbad-function-cast -D_GNU_C_TRICORE_=1 -O2 -gdwarf-2 -fno-builtin -mpragma-data-sections -mcpu=tc27xx -fdata-sections -ffunction-sections -maligned-data-sections -MMD -M222P -MF"^$^(@:%%.o=%%.d)" -MT"^$^(@:%%.o=%%.d)" -o "^$^@" "^$^<^"

for /f "delims=*" %%j in (list.txt) do (
			set var8=%%j
			)

for /r %%i in (*.c) do (
     echo %filepath2% >>list0.txt
     echo %filepath%>>list2-1.txt
)
for /f "delims=" %%i in (list2-1.txt) do (
if not defined %%i set %%i=A&echo %%i>>list2-2.txt)

for /f "delims=" %%i in (list2-2.txt) do (
       set var1=%%i
       set "var2=!var1:3=3\ROM!"
	   echo !var2!>>list2-3.txt
	   ::5路径最后一个>修改ROM
	   md !var2!
	   
	   echo ################################################################################>>!var2!subdir.mk
	   echo # Automatically-generated file. Do not edit! >>!var2!subdir.mk
	   echo ################################################################################>>!var2!subdir.mk
	   echo # Add inputs and outputs from these tool invocations to the build variables>>!var2!subdir.mk
	   echo #>>!var2!subdir.mk
	   echo C_SRCS += \>>!var2!subdir.mk
	   dir	!var1!*.c /s/b >>!var2!subdir.mk
	   dir	!var1!*.c /s/b >list2-4.txt
	   
	   echo #>>!var2!subdir.mk
	   echo OBJS += \>>!var2!subdir.mk
	 for /f "delims=" %%i in (list2-4.txt) do (
		 set var4=%%i
		 set "var4=!var4:.c=.o \!"
		 echo !var4!>>!var2!subdir.mk
		)

	   echo #>>!var2!subdir.mk
	   echo C_DEPS += \>>!var2!subdir.mk
	 for /f "delims=" %%i in (list2-4.txt) do (
		 set var5=%%i
		 set "var5=!var5:.c=.d \!"
		 echo !var5!>>!var2!subdir.mk
		)
	   
		echo #>>!var2!subdir.mk
		echo # Each subdirectory must supply rules for building sources it contributes>>!var2!subdir.mk
		echo %filepath%%name%%filepath%%name2%>>!var2!subdir.mk
		echo	    @echo 'Building file: ^$^<'>>!var2!subdir.mk
		echo	    @echo 'Invoking: TriCore C Compiler'>>!var2!subdir.mk
		echo 		%name3%!var8!%name4%>>!var2!subdir.mk		
		echo	    @echo 'Finished building: ^$^<'>>!var2!subdir.mk
		echo	    @echo ' '>>!var2!subdir.mk
)


