@echo off
rem init.cmd - initializes 'a2lmerger' for use in a Toolbase Console

set A2LMERGER_HOME=%TB_TOOL_HOME%
set A2LMERGE_HOME=%TB_TOOL_HOME%

DOSKEY a2lmerger=%TB_TOOL_HOME%\a2lmerger.cmd $*
exit /b 0
