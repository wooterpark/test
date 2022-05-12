@echo off
setlocal enabledelayedexpansion

::生成MK文件
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
     ::echo %filepath2% >>list2-0.txt
     echo %filepath%>>list2-1.txt
)
for /f "delims=" %%i in (list2-1.txt) do (
if not defined %%i set %%i=A&echo %%i>>list2-2.txt
)

for /f "delims=" %%i in (list2-2.txt) do (
       set var1=%%i
       set "var2=!var1:4=4\ROM!"
	   echo !var2!>>list2-3.txt
	   ::5路径最后一个>修改ROM
	   md !var2!
	   
	   echo ################################################################################>>!var2!subdir.mk
	   echo # Automatically-generated file. Do not edit! >>!var2!subdir.mk
	   echo ################################################################################>>!var2!subdir.mk
	   echo # Add inputs and outputs from these tool invocations to the build variables>>!var2!subdir.mk
	   echo #>>!var2!subdir.mk
	   echo C_SRCS += \>>!var2!subdir.mk
	   dir	!var1!*.c /s/b >list2-4.txt
	   dir	!var2!*.mk /s/b >>list2-5.txt
	 for /f "delims=" %%i in (list2-4.txt) do (
		 set var9=%%i
		 set "var9=!var9:.c=.c \!"
		 echo !var9!>>!var2!subdir.mk
		)
	 
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
echo		@echo 'Building file: ^$^<'>>!var2!subdir.mk
echo		@echo 'Invoking: TriCore C Compiler'>>!var2!subdir.mk
echo		%name3%!var8!%name4%>>!var2!subdir.mk
echo		@echo 'Finished building: ^$^<'>>!var2!subdir.mk
echo		@echo ' '>>!var2!subdir.mk
)

::生成makefile文件
set var6=%cd%
set "var6=!var6:4=4\ROM\!"
::5路径最后一个>修改ROM
set name5=-include 

echo ################################################################################>>%var6%makefile
echo # Automatically-generated file. Do not edit! >>%var6%makefile
echo ################################################################################>>%var6%makefile
echo #>>%var6%makefile
echo TRICORE_TOOLS=C:\HIGHTEC\toolchains\tricore\v4.6.6.1>>%var6%makefile
echo #>>%var6%makefile
echo -include ../makefile.init>>%var6%makefile
echo #>>%var6%makefile
echo RM := rm -rf>>%var6%makefile
echo #>>%var6%makefile
echo # All of the sources participating in the build are defined here>>%var6%makefile
echo -include sources.mk>>%var6%makefile
echo -include subdir.mk>>%var6%makefile
echo -include objects.mk>>%var6%makefile
for /f "delims=" %%i in (list2-5.txt) do (
		set var7=%%i
		set "var7=!var7:G:\zzy\doc\Hightec\0224\ROM\=\!"
		::5路径最后一个>修改ROM
		echo	%name5%!var7!>>%var6%makefile
)
echo #>>%var6%makefile
echo ifneq ($(MAKECMDGOALS),clean)>>%var6%makefile
echo ifneq ($(strip $(C_DEPS)),)>>%var6%makefile
echo -include $(C_DEPS)>>%var6%makefile
echo endif>>%var6%makefile
echo endif>>%var6%makefile
echo #>>%var6%makefile
echo -include ../makefile.defs>>%var6%makefile
echo #>>%var6%makefile
echo # Add inputs and outputs from these tool invocations to the build variables >>%var6%makefile
echo #>>%var6%makefile
echo #rebuild target>>%var6%makefile
echo rebuild: clean all>>%var6%makefile
echo #>>%var6%makefile
echo # All Target>>%var6%makefile
echo all: PEB.elf>>%var6%makefile
echo #>>%var6%makefile
echo # Tool invocations>>%var6%makefile
echo PEB.elf: $(OBJS) $(USER_OBJS) $(ASM)>>%var6%makefile
echo		@echo 'Building target: ^$^@'>>%var6%makefile
echo		@echo 'Invoking: TriCore C Linker'>>%var6%makefile
echo		"^$^(TRICORE_TOOLS)/bin/tricore-gcc" -o  "PEB.elf" -nocrt0 -nostdlib -nostartfiles -T"../TOOLS/Linker/LINKER.ld" @ROM.objectlist -mcpu=tc27xx -Wl,--warn-section-align -Wl,--warn-orphan -L"E:\Code\FS_PEB_0224\OS\Output" -L"E:\Code\FS_PEB_0224\TOOLS\Linker" -l:RTAOS.a -l:libgcov.a -l:libgcc.a -l:libdnk_c.a -Wl,-Map="^$^(basename $(notdir ^$^@)).map" -Wl,--relax -Wl,--no-demangle -Wl,--warn-once -nodefaultlibs -Wl,--extmap="a">>%var6%makefile	
echo		@echo 'Finished building target: ^$^@'>>%var6%makefile
echo		@echo ' '>>%var6%makefile
echo		$(MAKE) --no-print-directory post-build>>%var6%makefile
echo #>>%var6%makefile
echo # Other Targets>>%var6%makefile
echo clean:>>%var6%makefile
echo		-^$^(RM) ^$^(OBJS)^$^(CPCP_DEPS)^$^(C_DEPS)^$^(PCP_S)^$^(EXECUTABLES) PEB.elf>>%var6%makefile
echo		@echo ' '>>%var6%makefile
echo #>>%var6%makefile
echo post-build:>>%var6%makefile
echo		-E:\Code\FS_PEB_0224\TOOLS\A2L\genA2l.bat E:\Code\FS_PEB_0224 PEB>>%var6%makefile
echo		@echo ' '>>%var6%makefile
echo #>>%var6%makefile
echo .PHONY: all clean dependents>>%var6%makefile
echo .SECONDARY: post-build>>%var6%makefile
echo #>>%var6%makefile
echo -include ../makefile.targets>>%var6%makefile
echo #>>%var6%makefile
