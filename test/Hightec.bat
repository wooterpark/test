@echo off
setlocal enabledelayedexpansion
::####################################################################################################
del log.txt
echo "0">>log.txt
set cur_path=%cd%
set codepath=E:\zzy\Model
::模型编译成代码地址
::####################################################################################################
echo "1">>log.txt
set filepath2=%%~dpi
set name1=%%.o: 
set name2=%%.c
set name3="^$^(TRICORE_TOOLS)/bin/tricore-gcc" -c
set name4= -fno-common -O0 -W -Wall -Wcast-qual -Wcast-align -Wnested-externs -Wno-unused-parameter -Wno-return-type -Wno-pointer-to-int-cast -Wfloat-equal -Winline -Wstrict-prototypes -Wmissing-prototypes -Wmissing-noreturn -Wredundant-decls -Wundef -Wpointer-arith -Wbad-function-cast -D_GNU_C_TRICORE_=1 -O2 -gdwarf-2 -fno-builtin -mpragma-data-sections -mcpu=tc27xx -fdata-sections -ffunction-sections -maligned-data-sections -MMD -MP -MF"^$^(@:%%.o=%%.d)" -MT"^$^(@:%%.o=%%.d)" -o "^$^@" "^$^<"
set name5= -I"
set name6="
set name7=-include
set name8=subdir.mk
::####################################################################################################
echo "2">>log.txt
::拷贝生成的代码至SWC中，注意查看路径
copy !codepath!\output\SWC_ADM_ert_rtw\*.c !cur_path!\SWC\A_SWC\SWC_ADM
copy !codepath!\output\SWC_FRP_ert_rtw\*.c !cur_path!\SWC\A_SWC\SWC_FRP
copy !codepath!\output\SWC_STM_ert_rtw\*.c !cur_path!\SWC\A_SWC\SWC_STM
copy !codepath!\output\SWC_SWD_ert_rtw\*.c !cur_path!\SWC\A_SWC\SWC_SWD
copy !codepath!\output\SWC_TCF_ert_rtw\*.c !cur_path!\SWC\A_SWC\SWC_TCF
copy !codepath!\output\SWC_TRSP_ert_rtw\*.c !cur_path!\SWC\A_SWC\SWC_TRSP

copy !codepath!\output\SWC_ADM_ert_rtw\*.h !cur_path!\SWC\A_SWC\SWC_ADM
copy !codepath!\output\SWC_FRP_ert_rtw\*.h !cur_path!\SWC\A_SWC\SWC_FRP
copy !codepath!\output\SWC_STM_ert_rtw\*.h !cur_path!\SWC\A_SWC\SWC_STM
copy !codepath!\output\SWC_SWD_ert_rtw\*.h !cur_path!\SWC\A_SWC\SWC_SWD
copy !codepath!\output\SWC_TCF_ert_rtw\*.h !cur_path!\SWC\A_SWC\SWC_TCF
copy !codepath!\output\SWC_TRSP_ert_rtw\*.h !cur_path!\SWC\A_SWC\SWC_TRSP

copy !codepath!\output\SWC_ADM_ert_rtw\*.a2l !cur_path!\SWC\A_SWC\SWC_ADM
copy !codepath!\output\SWC_FRP_ert_rtw\*.a2l !cur_path!\SWC\A_SWC\SWC_FRP
copy !codepath!\output\SWC_STM_ert_rtw\*.a2l !cur_path!\SWC\A_SWC\SWC_STM
copy !codepath!\output\SWC_SWD_ert_rtw\*.a2l !cur_path!\SWC\A_SWC\SWC_SWD
copy !codepath!\output\SWC_TCF_ert_rtw\*.a2l !cur_path!\SWC\A_SWC\SWC_TCF
copy !codepath!\output\SWC_TRSP_ert_rtw\*.a2l !cur_path!\SWC\A_SWC\SWC_TRSP
::####################################################################################################
echo "3">>log.txt
::获取mk文件里的最长的那个长链接
for /r %%i in (*.h) do (
	echo %filepath2%>>list_c_h.txt
)
for /r %%i in (*.c) do (
	echo %filepath2%>>list_c_h.txt
)
for /f "delims=" %%i in (list_c_h.txt) do (
if not defined %%i set %%i=B&echo %%i>>list_Delete_duplicate.txt)

for /f "delims=" %%i in (list_Delete_duplicate.txt) do (
	set var9=%%i
	set var9=!var9:~0,-1!
	echo %name5%!var9!%name6%>>list_Splicing.txt
)
for /f "delims=" %%i in (list_Splicing.txt) do call set "var=%%var%%%%i"
echo !var!>>list_one_line.txt
)
for /f "delims=*" %%j in (list_one_line.txt) do (
set var10=%%j
)
del list_c_h.txt
del list_Delete_duplicate.txt
del list_Splicing.txt
::####################################################################################################
echo "4">>log.txt
::做excluding
findstr	"excluding"	.cproject>>list_excluding.txt
for /f "delims=" %%i in (list_excluding.txt) do (
	set var=%%i
	set "var=!var:						<entry excluding=!"
	::去空格，一般不需要修改
	set var=!var:~2,-69!
	::掐头去尾，一般不需要修改
	set "var=!var:/=\!"
	echo	!var!>>list_excluding_c.txt
)
for /f "delims=" %%i in (list_excluding_c.txt) do (
::str的副本
	set remain=%%i
	:loop
	for /f "tokens=1* delims=|" %%a in ("%remain%") do (
    ::输出第一个分段(令牌)
		echo %%a>>list_division.txt
    rem 将截取剩下的部分赋给变量remain，其实这里可以使用延迟变量开关
		set remain=%%b
)
::如果还有剩余,则继续分割
if defined remain goto :loop
)
del list_excluding.txt
del list_excluding_c.txt
::####################################################################################################
echo "5">>log.txt
::复制所有.c文件至rom下
dir /s/b %cur_path%\*.c >list_c.txt
for /f "delims=" %%i in (list_c.txt) do (
	set var=%%i
	set	"var2=!var:%cur_path%=%cur_path%\ROM!"
	echo f| xcopy !var! !var2! 
)
del list_c.txt
::####################################################################################################
echo "6">>log.txt
::删除excluding不用的
for /f "delims=*" %%i in (list_division.txt) do (
		set var3=%%i
		rd /s/q	!cur_path!\ROM\!var3!
		del /s/q !cur_path!\ROM\!var3!
)
del list_division.txt
::####################################################################################################
echo "7">>log.txt
::删除后，获取所有有用.c文件和路径,并去重复
dir /s/b %cur_path%\ROM\*.c >ROM_c.txt
for /f "delims=" %%i in (ROM_c.txt) do (
   echo %%~dpi>>ROM_c_route.txt
)
for /f "delims=" %%i in (ROM_c_route.txt) do (
if not defined %%i set %%i=B&echo %%i>>mk_filepath.txt)
del ROM_c_route.txt
::####################################################################################################
echo "8">>log.txt
::在去重复的路径下生成mk文件
for /f "delims=" %%i in (mk_filepath.txt) do (
       set var1=%%i
	   echo ################################################################################>>!var1!subdir.mk
	   echo # Automatically-generated file. Do not edit! >>!var1!subdir.mk
	   echo ################################################################################>>!var1!subdir.mk
	   echo # Add inputs and outputs from these tool invocations to the build variables>>!var1!subdir.mk
	   echo #>>!var1!subdir.mk
	   echo C_SRCS += \>>!var1!subdir.mk
	   
	   dir	!var1!\*.c /s/b >c_src_filelist.txt
	for /f "delims=" %%i in (c_src_filelist.txt) do (
		 set var4=%%i
		 set "var4=!var4:%cur_path%\ROM=..!"
		 set "var4=!var4:\=/!"
		 set "var4=!var4:.c=.c \!"
		 echo !var4!>>!var1!subdir.mk
	) 
		echo #>>!var1!subdir.mk
		echo OBJS += \>>!var1!subdir.mk
	for /f "delims=" %%i in (c_src_filelist.txt) do (
		 set var5=%%i
		 set "var5=!var5:%cur_path%\ROM=.!"
		 set "var5=!var5:\=/!"
		 set "var5=!var5:.c=.o \!"
		 echo !var5!>>!var1!subdir.mk
	) 
		echo #>>!var1!subdir.mk
		echo C_DEPS += \>>!var1!subdir.mk
	for /f "delims=" %%i in (c_src_filelist.txt) do (
		 set var6=%%i
		 set "var6=!var6:%cur_path%\ROM=.!"
		 set "var6=!var6:\=/!"
		 set "var6=!var6:.c=.d \!"
		 echo !var6!>>!var1!subdir.mk
	) 
		echo #>>!var1!subdir.mk
		echo # Each subdirectory must supply rules for building sources it contributes>>!var1!subdir.mk
		set "var7=!var1:%cur_path%\ROM\=!"
		set	"var7=!var7:\=/!"
		set "var8=!var1:%cur_path%\ROM\=..\!"
		set	"var8=!var8:\=/!"
		echo !var7!%name1%!var8!%name2%>>!var1!subdir.mk
		echo		@echo 'Building file: ^$^<'>>!var1!subdir.mk
		echo		@echo 'Invoking: TriCore C Compiler'>>!var1!subdir.mk
	echo		%name3%!var10!%name4%>>!var1!subdir.mk
	::打印长链接至mk文件
		echo		@echo 'Finished building: ^$^<'>>!var1!subdir.mk
		echo		@echo ' '>>!var1!subdir.mk
)
::####################################################################################################
echo "9">>log.txt
::生成makefile文件
set var12=%cur_path%\ROM\
echo ################################################################################>>%var12%makefile
echo # Automatically-generated file. Do not edit! >>%var12%makefile
echo ################################################################################>>%var12%makefile
echo #>>%var12%makefile
echo -include ../makefile.init>>%var12%makefile
echo #>>%var12%makefile
echo RM := rm -rf>>%var12%makefile
echo #>>%var12%makefile
echo # All of the sources participating in the build are defined here>>%var12%makefile
echo -include sources.mk>>%var12%makefile
echo -include subdir.mk>>%var12%makefile
echo -include objects.mk>>%var12%makefile
for /f "delims=" %%i in (mk_filepath.txt) do (
	set var11=%%i
	set "var11=!var11:%cur_path%\ROM\= !"
	set "var11=!var11:\=/!"
	::去掉rom路径，与-include整合
	echo	%name7%!var11!%name8%>>%var12%makefile
)
echo #>>%var12%makefile
echo ifneq ($(MAKECMDGOALS),clean)>>%var12%makefile
echo ifneq ($(strip $(C_DEPS)),)>>%var12%makefile
echo -include $(C_DEPS)>>%var12%makefile
echo endif>>%var12%makefile
echo endif>>%var12%makefile
echo #>>%var12%makefile
echo -include ../makefile.defs>>%var12%makefile
echo #>>%var12%makefile
echo # Add inputs and outputs from these tool invocations to the build variables >>%var12%makefile
echo #>>%var12%makefile
echo #rebuild target>>%var12%makefile
echo rebuild: clean all>>%var12%makefile
echo #>>%var12%makefile
echo # All Target>>%var12%makefile
echo all: PEB.elf>>%var12%makefile
echo #>>%var12%makefile
echo # Tool invocations>>%var12%makefile
echo PEB.elf: $(OBJS) $(USER_OBJS) $(ASM)>>%var12%makefile
echo		@echo 'Building target: ^$^@'>>%var12%makefile
echo		@echo 'Invoking: TriCore C Linker'>>%var12%makefile
echo		"$(TRICORE_TOOLS)/bin/tricore-gcc" -o  "PEB.elf" -nocrt0 -nostdlib -nostartfiles -T"../TOOLS/Linker/LINKER.ld" @ROM.objectlist -mcpu=tc27xx -Wl,--warn-section-align -Wl,--warn-orphan -L"!cur_path!\OS\Output" -L"!cur_path!\TOOLS\Linker" -l:RTAOS.a -l:libgcov.a -l:libgcc.a -l:libdnk_c.a -Wl,-Map="$(basename $(notdir $@)).map" -Wl,--relax -Wl,--no-demangle -Wl,--warn-once -nodefaultlibs -Wl,--extmap="a">>%var12%makefile	
echo		@echo 'Finished building target: ^$^@'>>%var12%makefile
echo		@echo ' '>>%var12%makefile
echo		$(MAKE) --no-print-directory post-build>>%var12%makefile
echo #>>%var12%makefile
echo # Other Targets>>%var12%makefile
echo clean:>>%var12%makefile
echo		-^$^(RM) ^$^(OBJS)^$^(CPCP_DEPS)^$^(C_DEPS)^$^(PCP_S)^$^(EXECUTABLES) PEB.elf>>%var12%makefile
echo		@echo ' '>>%var12%makefile
echo #>>%var12%makefile
echo post-build:>>%var12%makefile
echo		-%cur_path%\TOOLS\A2L\genA2l.bat %cur_path% PEB>>%var12%makefile
			::修改TOOL地址，::设置工程所在路径
echo		-@echo ' '>>%var12%makefile
echo #>>%var12%makefile
echo .PHONY: all clean dependents>>%var12%makefile
echo .SECONDARY: post-build>>%var12%makefile
echo #>>%var12%makefile
echo -include ../makefile.targets>>%var12%makefile
echo #>>%var12%makefile
::####################################################################################################
echo "10">>log.txt
::生成objectlist
for /f "delims=" %%i in (ROM_c.txt) do (
	 set var13=%%i
	 set "var13=!var13:.c=.o!"
	 set "var13=!var13:\=/!"
	 echo !var13!>>%var12%ROM.objectlist
)
del c_src_filelist.txt
del list_one_line.txt
del ROM_c.txt
del mk_filepath.txt
::####################################################################################################
echo "11">>log.txt
::生成sources.mk
echo ################################################################################>>%var12%sources.mk
echo # Automatically-generated file. Do not edit! >>%var12%sources.mk
echo ################################################################################>>%var12%sources.mk
echo #>>%var12%sources.mk
echo O_SRCS := >>%var12%sources.mk
echo C_SRCS := >>%var12%sources.mk
echo CPCP_SRCS := >>%var12%sources.mk
echo S_UPPER_SRCS := >>%var12%sources.mk
echo S_SRCS := >>%var12%sources.mk
echo ASM_SRCS := >>%var12%sources.mk
echo MCS_SRCS := >>%var12%sources.mk
echo ASM_UPPER_SRCS := >>%var12%sources.mk
echo OBJS := >>%var12%sources.mk
echo C_DEPS := >>%var12%sources.mk
echo PCP_S := >>%var12%sources.mk
echo EXECUTABLES := >>%var12%sources.mk
echo TRICORE_TOOLS :=C:\HighTec\toolchains\tricore\v4.6.6.1>>%var12%sources.mk
::TRICORE_TOOLS路径需修改
echo #>>%var12%sources.mk
echo # Every subdirectory with source files must be described here>>%var12%sources.mk
echo SUBDIRS := \>>%var12%sources.mk
echo #>>%var12%sources.mk
::####################################################################################################
echo "12">>log.txt
::objects.mk
echo ################################################################################>>%var12%objects.mk
echo # Automatically-generated file. Do not edit! >>%var12%objects.mk
echo ################################################################################>>%var12%objects.mk
echo #>>%var12%objects.mk
echo USER_OBJS :=>>%var12%objects.mk
echo #>>%var12%objects.mk
echo LIBS :=>>%var12%objects.mk

::####################################################################################################
echo "13">>log.txt
::运行make -j8 rebuild
cmd /k "cd /d %cur_path%\ROM\&&make -j8 rebuild"