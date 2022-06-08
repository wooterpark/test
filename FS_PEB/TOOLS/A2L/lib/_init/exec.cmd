@echo off

if "%TB_A2LMERGER_VERSION%" equ "%TEXEC_TOOL_VERSION%" goto :run

:init
call tini a2lmerger=%TEXEC_TOOL_VERSION% -gui
if "%errorlevel%" neq "0" exit /b 1

:run
   call "%TB_A2LMERGER_HOME%\a2lmerger.cmd" %*
exit /b %errorlevel%
