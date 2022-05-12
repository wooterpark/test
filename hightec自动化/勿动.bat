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
    :: echo %filepath2% >>list2-0.txt
     echo %filepath%>>list2-1.txt
)
for /f "delims=" %%i in (list2-1.txt) do (
if not defined %%i set %%i=A&echo %%i>>list2-2.txt)

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
		 set var6=%%i
		 set "var6=!var6:.c=.c \!"
		 echo !var6!>>!var2!subdir.mk
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
		echo	    @echo 'Building file: ^$^<'>>!var2!subdir.mk
		echo	    @echo 'Invoking: TriCore C Compiler'>>!var2!subdir.mk
	    ::echo   		"^$^(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"E:\Code\FS_PEB_0224\BSW" -I"E:\Code\FS_PEB_0224\CDD\CddFS_L2COM\api" -I"E:\Code\FS_PEB_0224\CDD\CddFS_L2COM\src" -I"E:\Code\FS_PEB_0224\CDD\CddFS_L2SOP\api" -I"E:\Code\FS_PEB_0224\CDD\CddFS_L2SOP\src" -I"E:\Code\FS_PEB_0224\CDD\CddFS_EmerDischarge" -I"E:\Code\FS_PEB_0224\CDD\CddFS_L2Sample\api" -I"E:\Code\FS_PEB_0224\CDD\CddFS_QST" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_ADM" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_FRP" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_TRSP" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_TPC" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_FRP" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_STM" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_SWD" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_TCF" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_SWD" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Application" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Application\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Application\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Cfg" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Cfg\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Cfg\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Common" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeTlibCD" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeTlibCD\MicroTestLib" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeTlibCD\MicroTestLib\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeTlibCD\MicroTestLib\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeTlibCD\SMU" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeTlibCD\SMU\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeTlibCD\SMU\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeTlibCD\TestHandler" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeTlibCD\TestHandler\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeTlibCD\TestHandler\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgAscLin" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgAscLin\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgAscLin\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgExtCic" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgExtCic\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgExtCic\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgExtTlf" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgExtTlf\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgExtTlf\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgIf" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgIf\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgIf\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgInt" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgInt\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgInt\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgQspi" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgQspi\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\SafeWdgCD\SafeWdgQspi\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Sft_Common" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Sft_Common\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Sft_Common\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Sft_Config" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Sft_Config\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\Sft_Config\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\UpperLayer" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\UpperLayer\SafeWdgM" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\UpperLayer\SafeWdgM\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\UpperLayer\SafeWdgM\src" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\UpperLayer\TstM" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\UpperLayer\TstM\inc" -I"E:\Code\FS_PEB_0224\CDD\SafeTlib\UpperLayer\TstM\src" -I"E:\Code\FS_PEB_0224\CDD\SBC_35584" -I"E:\Code\FS_PEB_0224\BSW\Bfx" -I"E:\Code\FS_PEB_0224\BSW\Bfx\api" -I"E:\Code\FS_PEB_0224\BSW\Bfx\src" -I"E:\Code\FS_PEB_0224\BSW\BswM" -I"E:\Code\FS_PEB_0224\BSW\BswM\api" -I"E:\Code\FS_PEB_0224\BSW\BswM\src" -I"E:\Code\FS_PEB_0224\BSW\CanIf" -I"E:\Code\FS_PEB_0224\BSW\CanIf\api" -I"E:\Code\FS_PEB_0224\BSW\CanIf\src" -I"E:\Code\FS_PEB_0224\BSW\CanSM" -I"E:\Code\FS_PEB_0224\BSW\CanSM\api" -I"E:\Code\FS_PEB_0224\BSW\CanSM\src" -I"E:\Code\FS_PEB_0224\BSW\CanTp" -I"E:\Code\FS_PEB_0224\BSW\CanTp\api" -I"E:\Code\FS_PEB_0224\BSW\CanTp\src" -I"E:\Code\FS_PEB_0224\BSW\Com" -I"E:\Code\FS_PEB_0224\BSW\Com\api" -I"E:\Code\FS_PEB_0224\BSW\Com\src" -I"E:\Code\FS_PEB_0224\BSW\ComM" -I"E:\Code\FS_PEB_0224\BSW\ComM\api" -I"E:\Code\FS_PEB_0224\BSW\ComM\src" -I"E:\Code\FS_PEB_0224\BSW\ComStack" -I"E:\Code\FS_PEB_0224\BSW\conf_proc_log" -I"E:\Code\FS_PEB_0224\BSW\Crc" -I"E:\Code\FS_PEB_0224\BSW\Dcm" -I"E:\Code\FS_PEB_0224\BSW\Dcm\api" -I"E:\Code\FS_PEB_0224\BSW\Dcm\src" -I"E:\Code\FS_PEB_0224\BSW\Dem" -I"E:\Code\FS_PEB_0224\BSW\Dem\api" -I"E:\Code\FS_PEB_0224\BSW\Dem\src" -I"E:\Code\FS_PEB_0224\BSW\Det" -I"E:\Code\FS_PEB_0224\BSW\Det\api" -I"E:\Code\FS_PEB_0224\BSW\Det\src" -I"E:\Code\FS_PEB_0224\BSW\E2E" -I"E:\Code\FS_PEB_0224\BSW\EcuM" -I"E:\Code\FS_PEB_0224\BSW\EcuM\api" -I"E:\Code\FS_PEB_0224\BSW\EcuM\src" -I"E:\Code\FS_PEB_0224\BSW\Fee" -I"E:\Code\FS_PEB_0224\BSW\Fee\api" -I"E:\Code\FS_PEB_0224\BSW\Fee\src" -I"E:\Code\FS_PEB_0224\BSW\FiM" -I"E:\Code\FS_PEB_0224\BSW\FiM\api" -I"E:\Code\FS_PEB_0224\BSW\FiM\src" -I"E:\Code\FS_PEB_0224\BSW\MemIf" -I"E:\Code\FS_PEB_0224\BSW\MemIf\api" -I"E:\Code\FS_PEB_0224\BSW\MemIf\src" -I"E:\Code\FS_PEB_0224\BSW\NvM" -I"E:\Code\FS_PEB_0224\BSW\NvM\api" -I"E:\Code\FS_PEB_0224\BSW\NvM\src" -I"E:\Code\FS_PEB_0224\BSW\PduR" -I"E:\Code\FS_PEB_0224\BSW\PduR\api" -I"E:\Code\FS_PEB_0224\BSW\PduR\src" -I"E:\Code\FS_PEB_0224\BSW\Platform" -I"E:\Code\FS_PEB_0224\BSW\Rba_DiagLib" -I"E:\Code\FS_PEB_0224\BSW\Rba_DiagLib\api" -I"E:\Code\FS_PEB_0224\BSW\Rba_DiagLib\src" -I"E:\Code\FS_PEB_0224\BSW\Rba_FeeFs1" -I"E:\Code\FS_PEB_0224\BSW\Rba_FeeFs1\src" -I"E:\Code\FS_PEB_0224\BSW\WdgIf" -I"E:\Code\FS_PEB_0224\BSW\WdgIf\api" -I"E:\Code\FS_PEB_0224\BSW\WdgM" -I"E:\Code\FS_PEB_0224\BSW\WdgM\api" -I"E:\Code\FS_PEB_0224\BSW\WdgM\src" -I"E:\Code\FS_PEB_0224\BSW\Xcp" -I"E:\Code\FS_PEB_0224\BSW\Xcp\api" -I"E:\Code\FS_PEB_0224\BSW\Xcp\src" -I"E:\Code\FS_PEB_0224\CDD" -I"E:\Code\FS_PEB_0224\CDD\Cdd_Infra" -I"E:\Code\FS_PEB_0224\CDD\CddCpld" -I"E:\Code\FS_PEB_0224\CDD\CddDPT" -I"E:\Code\FS_PEB_0224\CDD\CddEpark" -I"E:\Code\FS_PEB_0224\CDD\CddHvMcu" -I"E:\Code\FS_PEB_0224\CDD\CddIgbt" -I"E:\Code\FS_PEB_0224\CDD\CddLvPower" -I"E:\Code\FS_PEB_0224\CDD\CddPhC" -I"E:\Code\FS_PEB_0224\CDD\CddPwm3ph" -I"E:\Code\FS_PEB_0224\CDD\CddRdc" -I"E:\Code\FS_PEB_0224\CDD\CddSBL" -I"E:\Code\FS_PEB_0224\CDD\CddSnapshot" -I"E:\Code\FS_PEB_0224\CDD\CddTJA1043" -I"E:\Code\FS_PEB_0224\CDD\CddTJA1145" -I"E:\Code\FS_PEB_0224\CDD\CddTJA1145\inc" -I"E:\Code\FS_PEB_0224\CDD\CddTJA1145\src" -I"E:\Code\FS_PEB_0224\INFRA" -I"E:\Code\FS_PEB_0224\INFRA\api" -I"E:\Code\FS_PEB_0224\INFRA\ComAppl" -I"E:\Code\FS_PEB_0224\INFRA\DcmAppl" -I"E:\Code\FS_PEB_0224\INFRA\Integ" -I"E:\Code\FS_PEB_0224\INFRA\Integ\BswmAppl" -I"E:\Code\FS_PEB_0224\INFRA\Integ\EcumAppl" -I"E:\Code\FS_PEB_0224\INFRA\Integ\McalAppl" -I"E:\Code\FS_PEB_0224\INFRA\Integ\MemAppl" -I"E:\Code\FS_PEB_0224\INFRA\IOHWAB" -I"E:\Code\FS_PEB_0224\INFRA\IOHWAB\api" -I"E:\Code\FS_PEB_0224\INFRA\IOHWAB\arxml" -I"E:\Code\FS_PEB_0224\INFRA\IOHWAB\src" -I"E:\Code\FS_PEB_0224\INFRA\Memmap" -I"E:\Code\FS_PEB_0224\INFRA\ResetManager" -I"E:\Code\FS_PEB_0224\INFRA\RtaBswSrv" -I"E:\Code\FS_PEB_0224\INFRA\SchM" -I"E:\Code\FS_PEB_0224\INFRA\XcpAppl" -I"E:\Code\FS_PEB_0224\MCAL" -I"E:\Code\FS_PEB_0224\MCAL\api" -I"E:\Code\FS_PEB_0224\MCAL\Gen" -I"E:\Code\FS_PEB_0224\MCAL\Gen\inc" -I"E:\Code\FS_PEB_0224\MCAL\Gen\mak" -I"E:\Code\FS_PEB_0224\MCAL\Gen\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Adc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Adc\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Adc\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Can" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Can\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Can\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Dio" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Dio\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Dio\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Dma" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Dma\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Dma\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Dsadc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Dsadc\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Dsadc\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Fls" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Fls\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Fls\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\FlsLoader" -I"E:\Code\FS_PEB_0224\MCAL\Modu\FlsLoader\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\FlsLoader\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Gpt" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Gpt\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Gpt\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Icu" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Icu\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Icu\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Irq" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Irq\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Irq\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Mcu" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Mcu\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Mcu\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Port" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Port\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Port\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Pwm" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Pwm\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Pwm\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Smu" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Smu\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Smu\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Spi" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Spi\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Spi\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Uart" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Uart\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Uart\src" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Wdg" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Wdg\inc" -I"E:\Code\FS_PEB_0224\MCAL\Modu\Wdg\src" -I"E:\Code\FS_PEB_0224\MCAL\Reg" -I"E:\Code\FS_PEB_0224\MCAL\tmp" -I"E:\Code\FS_PEB_0224\OS" -I"E:\Code\FS_PEB_0224\OS\config" -I"E:\Code\FS_PEB_0224\OS\OSApp" -I"E:\Code\FS_PEB_0224\OS\OsShell" -I"E:\Code\FS_PEB_0224\OS\Output" -I"E:\Code\FS_PEB_0224\OS\Output\inc" -I"E:\Code\FS_PEB_0224\RTE" -I"E:\Code\FS_PEB_0224\RTE\Cfg" -I"E:\Code\FS_PEB_0224\RTE\gen" -I"E:\Code\FS_PEB_0224\SWC" -I"E:\Code\FS_PEB_0224\SWC\A_SWC" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\shared" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_BCC" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_CSPF" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_HSPF" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_MCF" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_MDF" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_MPC" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_PCF" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_RCF" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_SCF" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_TDC" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_TPC" -I"E:\Code\FS_PEB_0224\SWC\A_SWC\SWC_VCF" -I"E:\Code\FS_PEB_0224\SWC\B_SWC" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_CPLD" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_Diag" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_DIAGCALIB" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_EPARK" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_HVMCU" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_IGBT" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_LvPower" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_NvM" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_PHC" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_PWM3PH" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_RDC" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_SNAPSHOT" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_Tja1043" -I"E:\Code\FS_PEB_0224\SWC\B_SWC\SWC_WdgM" -I"E:\Code\FS_PEB_0224\TOOLS" -I"E:\Code\FS_PEB_0224\TOOLS\A2L" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\delivery" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\_init" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\input" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\a2lparser" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\addresscalc" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\antlr" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\aom" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\beanshell" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\eclipse" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\emf" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\log4j" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\logLight" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\MSRSWParser" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\saxon" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\ulf" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\libs\xmlbeans" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\log" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\lib\main" -I"E:\Code\FS_PEB_0224\TOOLS\A2L\tool" -I"E:\Code\FS_PEB_0224\TOOLS\Linker" -fno-common -O0 -W -Wall -Wcast-qual -Wcast-align -Wnested-externs -Wno-unused-parameter -Wno-return-type -Wno-pointer-to-int-cast -Wfloat-equal -Winline -Wstrict-prototypes -Wmissing-prototypes -Wmissing-noreturn -Wredundant-decls -Wundef -Wpointer-arith -Wbad-function-cast -D_GNU_C_TRICORE_=1 -O2 -gdwarf-2 -fno-builtin -mpragma-data-sections -mcpu=tc27xx -fdata-sections -ffunction-sections -maligned-data-sections -MMD -MP -MF"^$^(@:%%.o=%%.d)" -MT"^$^(^@:%%.o=%%.d)" -o "^$^@" "^$^<">>!var2!subdir.mk
	echo		%name3%!var8!%name4%>>!var2!subdir.mk		
		echo	    @echo 'Finished building: ^$^<'>>!var2!subdir.mk
		echo	    @echo ' '>>!var2!subdir.mk
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


