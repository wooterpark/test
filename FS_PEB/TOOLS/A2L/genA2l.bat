

set ROOT=%1
set PRJ=%2

CD "%ROOT%\TOOLS\A2L\tool"

echo "start to show something"
echo %ROOT%
echo %PRJ%

tricore-objcopy --gap-fill 0x00 -O ihex "%ROOT%/ROM/%PRJ%.elf" "%ROOT%/ROM/%PRJ%.hex"



XCOPY ..\..\..\BSW\*.* ..\..\..\ArCfg\BGen\ /y /c /h /r /e 
XCOPY ..\..\..\SWC\A_SWC\*.* ..\..\..\SWC_SRC\APP\ /y /c /h /r /e



ETK_2Cons_BswRteOnly.exe
rd /s/q ..\..\..\ArCfg\
rd /s/q ..\..\..\SWC_SRC\

pause
  
