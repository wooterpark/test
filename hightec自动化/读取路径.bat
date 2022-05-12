@echo off&&setlocal enabledelayedexpansion
set filepath=%%~dpi
for /r %%i in (*.c) do (
     echo %filepath% >>list.txt
)