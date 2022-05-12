@echo off&&setlocal enabledelayedexpansion
matlab -nojvm -nodesktop -nodisplay -r "run('G:\zzy\project\config.m')"
::注意修改config.m地址

::taskkill /f  /im matlab.exe
