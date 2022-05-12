@echo off&&setlocal enabledelayedexpansion
for /f "tokens=*" %%i in (list3.txt) do (
   set var=%%i
   copy G:\zzy\doc\Hightec\FS_PEB_0225\first.bat !%%i!
   ::修改找first.bat
    cd !%%i!
	 call first.bat
	 del first.*
)
