@echo off&&setlocal enabledelayedexpansion
for /f "tokens=*" %%i in (subdir1.txt) do (
set var=%%i
set "var=!var:.c=.d \!"
echo !var!>>subdir4.txt
)